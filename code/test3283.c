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

#ifndef __NR_epoll_pwait2
#define __NR_epoll_pwait2 441
#endif

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_read, -1, 0ul, 0ul);
	res = syscall(__NR_clock_gettime, 0ul, 0x200000c0ul);
	if (res != -1)
r[1] = *(uint64_t*)0x200000c8;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = r[1]+60000000;
*(uint64_t*)0x20000180 = 0;
	syscall(__NR_epoll_pwait2, r[0], 0x20000040ul, 1ul, 0x20000140ul, 0x20000180ul, 8ul);
	return 0;
}
