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

#ifndef __NR_memfd_secret
#define __NR_memfd_secret 447
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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_msgget, 0ul, 0ul);
	res = syscall(__NR_memfd_secret, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_read, -1, 0ul, 0ul);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0x801ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_write, r[1], 0ul, 0ul);
	syscall(__NR_ioctl, -1, 0xc0189377, 0ul);
memcpy((void*)0x20005340, "\xac\x0d\x1c\x08\x61\xf2\x17\xfb\xa9\x45\x99\x31\xdb", 13);
syz_clone(0x40800000, 0, 0, 0x200052c0, 0x20005300, 0x20005340);
*(uint32_t*)0x20009a00 = 0xe8;
	syscall(__NR_getsockopt, r[0], 0, 0x11, 0x20009900ul, 0x20009a00ul);
	return 0;
}
