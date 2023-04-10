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

#ifndef __NR_epoll_pwait2
#define __NR_epoll_pwait2 441
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

memcpy((void*)0x20000100, "\x8c\x73\x84\x29\xd8\x48\x51\xd1\xd7\xe2\xbe\x95\x59\x25\x02\xb5\x78\xa6\x08\xef\x44\x75\x91\xef\x5d\xd7\xf0\xdb\x06\x47\x84\x17\x16\xa8\x37\x69\xda\x39\xe6\x8f\x69\xb0\xb1\x5d\xaa\x94\xfe\x60\x7c\xa4\x2d\x10\x62\xcb\xe9\x21\x00\xc6\x54\xd0\x1e\x20\x43\xc1\x37\x94\xc4\xa3\xbc\xc0\x4c\x39\x1d\x78\xa4\xb0\x2c\x33\x1a\x46\x6d\x53\xf6\x72\x67\x73\xa6\xe2\xe9\x08\xa2\x87\x6c\xdc\x0e\xc7\xa7\xe6\x9c\x1c\x18\x87\xe0\x7d\x47\x73\xfe\x38", 108);
syz_clone(0xc8280000, 0, 0, 0x20000080, 0x200000c0, 0x20000100);
*(uint64_t*)0x20000340 = 0;
*(uint64_t*)0x20000348 = 0;
	syscall(__NR_epoll_pwait2, -1, 0ul, 0ul, 0x20000340ul, 0ul, 0ul);
	return 0;
}
