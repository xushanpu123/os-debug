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

*(uint64_t*)0x20002480 = 0;
*(uint64_t*)0x20002488 = 0;
*(uint64_t*)0x20002490 = 0;
*(uint64_t*)0x20002498 = 0;
*(uint64_t*)0x200024a0 = 0;
*(uint64_t*)0x200024a8 = 0;
*(uint64_t*)0x200024b0 = 0;
*(uint64_t*)0x200024b8 = 0;
*(uint64_t*)0x200024c0 = 0;
*(uint64_t*)0x200024c8 = 0;
*(uint64_t*)0x200024d0 = 0;
*(uint64_t*)0x200024d8 = 0;
*(uint64_t*)0x200024e0 = 0;
*(uint64_t*)0x200024e8 = 0;
*(uint64_t*)0x200024f0 = 0;
*(uint64_t*)0x200024f8 = 0;
*(uint64_t*)0x20002500 = 0;
*(uint64_t*)0x20002508 = 0;
	syscall(__NR_process_madvise, -1, 0x20002480ul, 9ul, 0ul, 0ul);
	return 0;
}
