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
	res = syscall(__NR_msgget, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200002c0 = 0x798e2635;
*(uint32_t*)0x200002c4 = -1;
*(uint32_t*)0x200002c8 = 0xee01;
*(uint32_t*)0x200002cc = 0xee01;
*(uint32_t*)0x200002d0 = -1;
*(uint32_t*)0x200002d4 = 0;
*(uint16_t*)0x200002d8 = 0;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint64_t*)0x200002f0 = 0;
*(uint64_t*)0x200002f8 = 0;
*(uint64_t*)0x20000300 = 0;
*(uint64_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0;
*(uint16_t*)0x20000318 = 0;
*(uint16_t*)0x2000031a = 0xfff9;
*(uint16_t*)0x2000031c = 0;
*(uint32_t*)0x20000320 = 0;
*(uint32_t*)0x20000324 = 0;
	syscall(__NR_msgctl, r[0], 1ul, 0x200002c0ul);
	return 0;
}
