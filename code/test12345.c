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
				syscall(__NR_msgrcv, 0, 0ul, 0ul, 0ul, 0ul);
*(uint32_t*)0x200000c0 = 0x798e2635;
*(uint32_t*)0x200000c4 = 0xee00;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0xee00;
*(uint32_t*)0x200000d4 = 0;
*(uint16_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint16_t*)0x20000118 = 0;
*(uint16_t*)0x2000011a = 0;
*(uint16_t*)0x2000011c = 0;
*(uint32_t*)0x20000120 = -1;
*(uint32_t*)0x20000124 = 0;
	syscall(__NR_msgctl, 0, 1ul, 0x200000c0ul);
	return 0;
}