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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe, 0x20000080ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000080;
r[1] = *(uint32_t*)0x20000084;
	}
	res = syscall(__NR_io_setup, 2, 0x20000000ul);
	if (res != -1)
r[2] = *(uint64_t*)0x20000000;
*(uint64_t*)0x200001c0 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint16_t*)0x20000110 = 5;
*(uint16_t*)0x20000112 = 0;
*(uint32_t*)0x20000114 = r[0];
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint32_t*)0x2000013c = -1;
	syscall(__NR_io_submit, r[2], 1ul, 0x200001c0ul);
*(uint64_t*)0x200000c0 = 0;
	syscall(__NR_write, r[1], 0x200000c0ul, 8ul);
	return 0;
}
