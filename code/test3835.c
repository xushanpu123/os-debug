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

*(uint32_t*)0x20000140 = 0x798e2635;
*(uint32_t*)0x20000144 = 0;
*(uint32_t*)0x20000148 = 0xee01;
*(uint32_t*)0x2000014c = 0xee00;
*(uint32_t*)0x20000150 = 0;
*(uint32_t*)0x20000154 = 0;
*(uint16_t*)0x20000158 = 0;
*(uint32_t*)0x2000015c = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint32_t*)0x20000178 = 0;
*(uint32_t*)0x2000017c = 0;
*(uint16_t*)0x20000180 = 0;
*(uint16_t*)0x20000182 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
	syscall(__NR_shmctl, 0, 1ul, 0x20000140ul);
	return 0;
}