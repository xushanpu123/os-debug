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
	syscall(__NR_timer_create, 3ul, 0ul, 0x20000140ul);
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0x3938700;
*(uint64_t*)0x20000190 = 0x77359400;
*(uint64_t*)0x20000198 = 0;
	syscall(__NR_timer_settime, 0, 0ul, 0x20000180ul, 0ul);
	res = syscall(__NR_timer_create, 3ul, 0ul, 0x20000140ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000140;
*(uint64_t*)0x20000040 = 0x77359400;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0x77359400;
*(uint64_t*)0x20000058 = 0;
	syscall(__NR_timer_settime, r[0], 0ul, 0x20000040ul, 0ul);
	return 0;
}
