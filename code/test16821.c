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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "./file0\000", 8);
	res = syscall(__NR_open, 0x200000c0ul, 0x4242ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 6, 0x20000040ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000040;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0x20000140;
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0;
*(uint16_t*)0x20000150 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint32_t*)0x20000154 = -1;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint32_t*)0x20000178 = 0;
*(uint32_t*)0x2000017c = -1;
	syscall(__NR_io_submit, 0ul, 2ul, 0x20000180ul);
*(uint64_t*)0x20000480 = 0x20000280;
*(uint64_t*)0x20000280 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint16_t*)0x20000290 = 8;
*(uint16_t*)0x20000292 = 0;
*(uint32_t*)0x20000294 = r[0];
*(uint64_t*)0x20000298 = 0x20000180;
memset((void*)0x20000180, 0, 1);
*(uint64_t*)0x200002a0 = 1;
*(uint64_t*)0x200002a8 = 0;
*(uint64_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b8 = 0;
*(uint32_t*)0x200002bc = -1;
	syscall(__NR_io_submit, r[1], 1ul, 0x20000480ul);
	return 0;
}
