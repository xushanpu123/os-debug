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
				syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
*(uint64_t*)0x20000400 = 8;
*(uint64_t*)0x20000408 = 0;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint64_t*)0x20000430 = 0;
*(uint64_t*)0x20000438 = 0;
*(uint64_t*)0x20000480 = 0;
*(uint64_t*)0x20000488 = 0;
	syscall(__NR_select, 0x40ul, 0x20000380ul, 0ul, 0x20000400ul, 0x20000480ul);
	return 0;
}