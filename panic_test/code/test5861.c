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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000280, "/dev/autofs\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000280ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_timerfd_create, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_clock_gettime, 0ul, 0x200000c0ul);
	if (res != -1) {
r[2] = *(uint64_t*)0x200000c0;
r[3] = *(uint64_t*)0x200000c8;
	}
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = r[2];
*(uint64_t*)0x20000058 = r[3]+60000000;
	syscall(__NR_timerfd_settime, r[1], 1ul, 0x20000040ul, 0ul);
*(uint32_t*)0x200002c0 = 1;
*(uint32_t*)0x200002c4 = 1;
*(uint32_t*)0x200002c8 = 0x18;
*(uint32_t*)0x200002cc = r[1];
memcpy((void*)0x200002d8, "./file0\000", 8);
	syscall(__NR_ioctl, r[0], 0xc0189375, 0x200002c0ul);
	return 0;
}
