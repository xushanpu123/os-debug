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

*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0x20000080;
*(uint64_t*)0x20000290 = 0x200000c0;
*(uint64_t*)0x20000298 = 0x20000100;
*(uint32_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0x20000340;
*(uint64_t*)0x200002b0 = 0xfffffffffffffff4;
*(uint64_t*)0x200002b8 = 0x200001c0;
*(uint64_t*)0x200002c0 = 0x20000300;
*(uint32_t*)0x20000300 = 0;
*(uint32_t*)0x20000304 = -1;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = -1;
*(uint32_t*)0x20000310 = 0;
*(uint64_t*)0x200002c8 = 5;
*(uint32_t*)0x200002d0 = -1;
syz_clone3(0x20000280, 0x58);
	return 0;
}
