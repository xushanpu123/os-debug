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

*(uint64_t*)0x20007600 = 0x64101000;
*(uint64_t*)0x20007608 = 0;
*(uint64_t*)0x20007610 = 0;
*(uint64_t*)0x20007618 = 0x20007400;
*(uint32_t*)0x20007620 = 0;
*(uint64_t*)0x20007628 = 0;
*(uint64_t*)0x20007630 = 0;
*(uint64_t*)0x20007638 = 0;
*(uint64_t*)0x20007640 = 0x200075c0;
*(uint32_t*)0x200075c0 = 0;
*(uint32_t*)0x200075c4 = 0;
*(uint64_t*)0x20007648 = 2;
*(uint32_t*)0x20007650 = -1;
syz_clone3(0x20007600, 0x58);
	syscall(__NR_ioctl, -1, 0x5760, 0ul);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
syz_clone(0, 0, 0, 0, 0x20009e80, 0);
	return 0;
}
