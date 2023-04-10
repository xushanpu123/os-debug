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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_getrusage, 0ul, 0ul);
	syscall(__NR_getrusage, 0ul, 0ul);
memcpy((void*)0x20000300, "\x13\xb6\xea\x12\xb9\x46\x0c\x3d\x2f\x72\x6e\x20\x99\x8e\xe0\xbc\xe2\x1f\x7a\x1d\xa0\x02\x61\x8f\x4a\x0c\x01\x40\xe3\xbf\x76\xcb\x4f\x1f\xd9\xf5\x84\xa0\xb5\x0c\x48\xbc\x5d\x54\x51\x28\xef\xc9\x98\x4c\x04\x9e\xf9\xb5\x5a\xed\x69\x1b\x0d\x88\x71\x7f\x4a\x12\x20\xdf\xce\x01\x45\x8f\xee", 71);
memcpy((void*)0x200003c0, "\x32\x78\x7d\xb0\x97\x3b\x45\xab\x2c\x7b\x11\xe2\x75\x28\xa3\x2b\xaa\x5a\x07\xf0\x00\xf5\x7a\xd8\xe8\x45\xfe\x74", 28);
syz_clone(0xc0000000, 0x20000300, 0x47, 0x20000140, 0x20000380, 0x200003c0);
	res = syscall(__NR_socket, 9ul, 4ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000540 = 0x20000480;
*(uint16_t*)0x20000480 = 0x10;
*(uint16_t*)0x20000482 = 0;
*(uint32_t*)0x20000484 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint32_t*)0x20000548 = 0xc;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 1;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint32_t*)0x20000570 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000540ul, 0x41ul);
	syscall(__NR_getrusage, 0ul, 0x20000080ul);
	return 0;
}
