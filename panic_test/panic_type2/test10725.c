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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000000;
r[1] = *(uint32_t*)0x20000004;
	}
	res = syscall(__NR_fstat, r[1], 0x20000540ul);
	if (res != -1)
r[2] = *(uint32_t*)0x20000558;
	syscall(__NR_setuid, r[2]);
	res = -1;
res = syz_clone(0, 0, 0, 0, 0, 0);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x20000280 = 0x20000140;
*(uint64_t*)0x20000288 = 0xd8;
	syscall(__NR_readv, r[0], 0x20000280ul, 1ul);
*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0xfffffff8;
	syscall(__NR_rt_sigqueueinfo, r[3], 0, 0x200000c0ul);
	return 0;
}
