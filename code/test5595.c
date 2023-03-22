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

#ifndef __NR_pkey_mprotect
#define __NR_pkey_mprotect 329
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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x200025c0 = 0;
*(uint64_t*)0x200025c8 = 0;
	syscall(__NR_pwritev, -1, 0x200025c0ul, 1ul, 0, 0);
syz_clone(0, 0, 0, 0, 0, 0);
*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200002c0ul, 0ul);
	syscall(__NR_pkey_mprotect, 0x20001000ul, 0x2000ul, 0ul, -1);
	syscall(__NR_madvise, 0x20000000ul, 0x4000ul, 0x15ul);
	return 0;
}
