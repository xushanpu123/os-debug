// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_epoll_create, 0x5f3);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/rfkill\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000000, "/dev/autofs\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000304 = 0;
*(uint32_t*)0x20000308 = 0;
*(uint32_t*)0x2000030c = 0;
*(uint32_t*)0x20000310 = 0;
*(uint32_t*)0x20000318 = -1;
memset((void*)0x2000031c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x36d9, 0x20000300ul);
	if (res != -1)
		r[3] = res;
*(uint32_t*)0x20000080 = 1;
*(uint32_t*)0x20000084 = 1;
*(uint32_t*)0x20000088 = 0x18;
*(uint32_t*)0x2000008c = r[3];
memcpy((void*)0x20000098, "./file0\000", 8);
	syscall(__NR_ioctl, r[2], 0xc0189375, 0x20000080ul);
*(uint32_t*)0x20000040 = 0x20000009;
*(uint64_t*)0x20000044 = 0;
	syscall(__NR_epoll_ctl, r[0], 1ul, r[1], 0x20000040ul);
*(uint32_t*)0x20000080 = 0;
*(uint64_t*)0x20000084 = 0;
	syscall(__NR_epoll_ctl, r[0], 3ul, r[1], 0x20000080ul);
	return 0;
}