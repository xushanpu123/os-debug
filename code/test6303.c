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
memcpy((void*)0x20000040, "./file0\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x26e1ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
memset((void*)0x200000d0, 0, 48);
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
memset((void*)0x20000128, 0, 24);
*(uint32_t*)0x20000140 = 0;
*(uint32_t*)0x20000144 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0xffffffffffffff65;
*(uint64_t*)0x20000160 = 0;
memset((void*)0x20000168, 0, 24);
	syscall(__NR_ioctl, r[0], 0xc0c0583b, 0x200000c0ul);
	return 0;
}