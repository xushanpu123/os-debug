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

*(uint64_t*)0x200000c0 = 0x20ffc000;
*(uint64_t*)0x200000c8 = 0x20ffc000;
*(uint64_t*)0x200000d0 = 0x20ffc000;
*(uint64_t*)0x200000d8 = 0x20ffd000;
*(uint64_t*)0x200000e0 = 0x20ffd000;
*(uint64_t*)0x200000e8 = 0x20ffe000;
*(uint64_t*)0x200000f0 = 0x20ffd000;
*(uint64_t*)0x200000f8 = 0x20ffc000;
*(uint64_t*)0x20000100 = 0x20ffc000;
*(uint64_t*)0x20000108 = 0x20fff000;
*(uint64_t*)0x20000110 = 0x20ffc000;
*(uint64_t*)0x20000118 = 0;
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = -1;
	syscall(__NR_prctl, 0x23ul, 0xeul, 0x200000c0ul, 0x68ul, 0);
	return 0;
}