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
				syscall(__NR_shmat, 0, 0x20ffd000ul, 0xf000ul);
	syscall(__NR_madvise, 0x20ffc000ul, 0x4000ul, 0xaul);
*(uint64_t*)0x20000200 = 0;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0;
*(uint32_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0;
*(uint64_t*)0x20000230 = 0;
*(uint64_t*)0x20000238 = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000248 = 0;
*(uint32_t*)0x20000250 = -1;
syz_clone3(0x20000200, 0x58);
	return 0;
}
