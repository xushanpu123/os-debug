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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200001c0, "./file0\000", 8);
	res = syscall(__NR_open, 0x200001c0ul, 0x88140ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000100 = 0x800000000000;
*(uint64_t*)0x20000108 = 1;
*(uint32_t*)0x20000110 = 7;
*(uint32_t*)0x20000114 = 0;
*(uint32_t*)0x20000118 = 0;
	syscall(__NR_ioctl, r[0], 0xc020660b, 0x20000100ul);
	return 0;
}
