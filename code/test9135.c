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

#ifndef __NR_seccomp
#define __NR_seccomp 317
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

uint64_t r[2] = {0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fffffff;
	syscall(__NR_seccomp, 1ul, 0ul, 0x20000340ul);
	res = -1;
res = syz_clone(0, 0, 0, 0, 0, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_getpid);
	if (res != -1)
		r[1] = res;
	syscall(__NR_kcmp, r[1], r[0], 4ul, -1, -1);
	return 0;
}
