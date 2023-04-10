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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = -1;
res = syz_clone(0, 0, 0x5d, 0, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200001c0 = 0x20000000;
*(uint64_t*)0x200001c8 = 0x32;
*(uint64_t*)0x200001d0 = 0x20000040;
*(uint64_t*)0x200001d8 = 0xf1;
*(uint64_t*)0x200001e0 = 0x20000140;
*(uint64_t*)0x200001e8 = 0x58;
*(uint64_t*)0x20000400 = 0x20000200;
*(uint64_t*)0x20000408 = 0xfffffff2;
*(uint64_t*)0x20000410 = 0x20000240;
*(uint64_t*)0x20000418 = 0x93;
*(uint64_t*)0x20000420 = 0x20000300;
*(uint64_t*)0x20000428 = 0x71;
*(uint64_t*)0x20000430 = 0x20000380;
*(uint64_t*)0x20000438 = 0x46;
	syscall(__NR_process_vm_readv, r[0], 0x200001c0ul, 3ul, 0x20000400ul, 4ul, 0ul);
	return 0;
}