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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe2, 0x20000400ul, 0x800ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000400;
r[1] = *(uint32_t*)0x20000404;
	}
*(uint32_t*)0x20000040 = 0x14;
*(uint8_t*)0x20000044 = 0x49;
*(uint16_t*)0x20000045 = 0;
*(uint8_t*)0x20000047 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint64_t*)0x2000004c = 0;
	syscall(__NR_write, r[1], 0x20000040ul, 0xfffffd73ul);
*(uint32_t*)0x20000080 = r[1];
*(uint16_t*)0x20000084 = 0;
*(uint16_t*)0x20000086 = 0;
	syscall(__NR_ppoll, 0x20000080ul, 1ul, 0ul, 0ul, 0ul);
*(uint64_t*)0x20003740 = 0x20001300;
*(uint64_t*)0x20003748 = 0x1000;
	syscall(__NR_readv, r[0], 0x20003740ul, 1ul);
	return 0;
}
