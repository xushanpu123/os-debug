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

#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200002c0, "./file0\000", 8);
	syscall(__NR_creat, 0x200002c0ul, 0ul);
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000080ul, 0x4802ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0x4000;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000100ul);
*(uint64_t*)0x20000c40 = 0x20000940;
memset((void*)0x20000940, 104, 1);
*(uint64_t*)0x20000c48 = 1;
	syscall(__NR_pwritev2, r[0], 0x20000c40ul, 1ul, 0, 0, 0ul);
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000040ul);
*(uint64_t*)0x200000c0 = 0x20000000;
memset((void*)0x20000000, 32, 1);
*(uint64_t*)0x200000c8 = 1;
	syscall(__NR_pwritev2, r[0], 0x200000c0ul, 1ul, 0x10000, 0, 0ul);
	return 0;
}
