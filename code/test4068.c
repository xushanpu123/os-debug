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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_timer_create, 0xfffffffffffffffdul, 0ul, 0x20000000ul);
	res = syscall(__NR_clock_gettime, 0ul, 0x200000c0ul);
	if (res != -1)
r[0] = *(uint64_t*)0x200000c8;
*(uint64_t*)0x200004c0 = 0x77359400;
*(uint64_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0;
*(uint64_t*)0x200004d8 = r[0]+60000000;
	syscall(__NR_timer_settime, 0, 0ul, 0x200004c0ul, 0ul);
	syscall(__NR_timer_gettime, 0, 0x20000040ul);
	return 0;
}
