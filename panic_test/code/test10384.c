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

#ifndef __NR_process_madvise
#define __NR_process_madvise 440
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x200015c0 = 0;
*(uint64_t*)0x200015c8 = 0;
*(uint64_t*)0x200015d0 = 0;
*(uint64_t*)0x200015d8 = 0;
*(uint64_t*)0x200015e0 = 0;
*(uint64_t*)0x200015e8 = 0;
*(uint64_t*)0x200015f0 = 0;
*(uint64_t*)0x200015f8 = 0;
*(uint64_t*)0x20001600 = 0;
*(uint64_t*)0x20001608 = 0;
*(uint64_t*)0x20001610 = 0;
*(uint64_t*)0x20001618 = 0;
*(uint64_t*)0x20001620 = 0;
*(uint64_t*)0x20001628 = 0;
*(uint64_t*)0x20001630 = 0;
*(uint64_t*)0x20001638 = 0;
*(uint64_t*)0x20001640 = 0;
*(uint64_t*)0x20001648 = 0;
	syscall(__NR_process_madvise, -1, 0x200015c0ul, 9ul, 0ul, 0ul);
	return 0;
}