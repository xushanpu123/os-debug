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

*(uint64_t*)0x20000840 = 0;
*(uint64_t*)0x20000848 = 0;
*(uint64_t*)0x20000850 = 0;
*(uint64_t*)0x20000858 = 0;
*(uint64_t*)0x20000860 = 0;
*(uint64_t*)0x20000868 = 0;
*(uint64_t*)0x20000870 = 0;
*(uint64_t*)0x20000878 = 0;
*(uint64_t*)0x20000880 = 0;
*(uint64_t*)0x20000888 = 0;
*(uint64_t*)0x20000890 = 0;
*(uint64_t*)0x20000898 = 0;
*(uint64_t*)0x200008a0 = 0;
*(uint64_t*)0x200008a8 = 0;
*(uint64_t*)0x200008b0 = 0;
*(uint64_t*)0x200008b8 = 0;
*(uint64_t*)0x200008c0 = 0;
*(uint64_t*)0x200008c8 = 0;
*(uint64_t*)0x200008d0 = 0;
*(uint64_t*)0x200008d8 = 0;
*(uint64_t*)0x200008e0 = 0;
*(uint64_t*)0x200008e8 = 0;
*(uint64_t*)0x200008f0 = 0;
*(uint64_t*)0x200008f8 = 0;
*(uint64_t*)0x20000900 = 0;
*(uint64_t*)0x20000908 = 0;
	syscall(__NR_clock_adjtime, 6ul, 0x20000840ul);
	return 0;
}