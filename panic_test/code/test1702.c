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

static long syz_clone(volatile long flags, volatile long stack, volatile long stack_len,
		      volatile long ptid, volatile long ctid, volatile long tls)
{
	long sp = (stack + stack_len) & ~15;
	long ret = (long)syscall(__NR_clone, flags & ~CLONE_VM, sp, ptid, ctid, tls);
	return handle_clone_ret(ret);
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

memcpy((void*)0x200001c0, "\x43\xa4\x2f\x7d\x99\x73\xed\x9a\x55\x7b\xe7\x2f\xcc\x9c\x04\xaa\xc3\x98\xeb\xcf\x55\x4b\x1d\x00\x1e\x79\x66\xc5\x23\x53", 30);
syz_clone(0, 0, 0, 0x20000140, 0, 0x200001c0);
*(uint64_t*)0x20001bc0 = 0x40000000;
*(uint64_t*)0x20001bc8 = 0;
*(uint64_t*)0x20001bd0 = 0;
*(uint64_t*)0x20001bd8 = 0x20000a40;
*(uint32_t*)0x20001be0 = 3;
*(uint64_t*)0x20001be8 = 0;
*(uint64_t*)0x20001bf0 = 0;
*(uint64_t*)0x20001bf8 = 0;
*(uint64_t*)0x20001c00 = 0x20001b80;
*(uint32_t*)0x20001b80 = 0;
*(uint64_t*)0x20001c08 = 1;
*(uint32_t*)0x20001c10 = -1;
syz_clone3(0x20001bc0, 0x58);
	return 0;
}