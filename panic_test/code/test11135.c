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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000280 = 0x64dbd5b3;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0;
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
*(uint64_t*)0x200002b0 = 0;
*(uint64_t*)0x200002b8 = 0;
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0xfffffffffffffffe;
*(uint64_t*)0x200002d8 = 0;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint64_t*)0x200002f0 = 0;
*(uint64_t*)0x200002f8 = 0;
*(uint64_t*)0x20000300 = 0;
*(uint64_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0;
*(uint64_t*)0x20000318 = 0;
*(uint64_t*)0x20000320 = 0;
*(uint64_t*)0x20000328 = 0;
*(uint64_t*)0x20000330 = 0;
*(uint64_t*)0x20000338 = 0;
*(uint64_t*)0x20000340 = 0;
*(uint64_t*)0x20000348 = 0;
	syscall(__NR_clock_adjtime, 0ul, 0x20000280ul);
	return 0;
}