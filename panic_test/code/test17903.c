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

uint64_t r[2] = {0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000000 = 0;
*(uint64_t*)0x20000008 = 0xea60;
*(uint64_t*)0x20000010 = 0x77359400;
*(uint64_t*)0x20000018 = 0;
	syscall(__NR_setitimer, 2ul, 0x20000000ul, 0ul);
	res = syscall(__NR_clock_gettime, 0ul, 0x20000100ul);
	if (res != -1) {
r[0] = *(uint64_t*)0x20000100;
r[1] = *(uint64_t*)0x20000108;
	}
*(uint64_t*)0x20000140 = r[0];
*(uint64_t*)0x20000148 = r[1]/1000+60000;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
	syscall(__NR_setitimer, 2ul, 0x20000140ul, 0x20000180ul);
	syscall(__NR_setitimer, 2ul, 0ul, 0ul);
	return 0;
}