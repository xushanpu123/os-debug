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
	res = syscall(__NR_pipe2, 0x200000c0ul, 0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200000c0;
r[1] = *(uint32_t*)0x200000c4;
	}
*(uint64_t*)0x20000000 = 0x20000140;
*(uint64_t*)0x20000008 = 0x1000;
	syscall(__NR_readv, r[0], 0x20000000ul, 1ul);
	syscall(__NR_fcntl, r[0], 4ul, 0x40000ul);
*(uint32_t*)0x20000040 = 0x14;
*(uint8_t*)0x20000044 = 0x49;
*(uint16_t*)0x20000045 = 0;
*(uint8_t*)0x20000047 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint64_t*)0x2000004c = 0;
	syscall(__NR_write, r[1], 0x20000040ul, 0xfffffd73ul);
	return 0;
}
