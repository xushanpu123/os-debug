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
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200005c0 = 0x200000c0;
memset((void*)0x200000c0, 185, 1);
*(uint64_t*)0x200005c8 = 1;
	syscall(__NR_pwritev2, r[0], 0x200005c0ul, 1ul, 0, 0, 0ul);
*(uint16_t*)0x20000040 = 0;
*(uint16_t*)0x20000042 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0x3ac7b8da;
*(uint32_t*)0x20000058 = 0;
*(uint32_t*)0x2000005c = 0;
memset((void*)0x20000060, 0, 16);
	syscall(__NR_ioctl, r[0], 0x40305828, 0x20000040ul);
	syscall(__NR_fallocate, r[0], 0x10ul, 0ul, 0x83f8ul);
	return 0;
}
