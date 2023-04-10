// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/sched.h>

#ifndef __NR_clone3
#define __NR_clone3 435
#endif

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

#define MAX_CLONE_ARGS_BYTES 256
static long syz_clone3(volatile long a0, volatile long a1)
{
	unsigned long copy_size = a1;
	if (copy_size < sizeof(uint64_t) || copy_size > MAX_CLONE_ARGS_BYTES)
		return -1;
	char clone_args[MAX_CLONE_ARGS_BYTES];
	memcpy(&clone_args, (void*)a0, copy_size);
	uint64_t* flags = (uint64_t*)&clone_args;
	*flags &= ~CLONE_VM;
	return handle_clone_ret((long)syscall(__NR_clone3, &clone_args, copy_size));
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000e00 = 0x20400;
*(uint64_t*)0x20000e08 = 0x20000c00;
*(uint64_t*)0x20000e10 = 0x20000c40;
*(uint64_t*)0x20000e18 = 0x20000c80;
*(uint32_t*)0x20000e20 = 0x1f;
*(uint64_t*)0x20000e28 = 0x20000cc0;
*(uint64_t*)0x20000e30 = 0xa1;
*(uint64_t*)0x20000e38 = 0x20000d80;
*(uint64_t*)0x20000e40 = 0x20000dc0;
*(uint32_t*)0x20000dc0 = 0;
*(uint32_t*)0x20000dc4 = -1;
*(uint64_t*)0x20000e48 = 2;
*(uint32_t*)0x20000e50 = -1;
syz_clone3(0x20000e00, 0x58);
	return 0;
}
