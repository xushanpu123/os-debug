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

#ifndef __NR_rseq
#define __NR_rseq 334
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint32_t*)0x20000050 = 0;
	syscall(__NR_rseq, 0x20000040ul, 0x20ul, 0ul, 0ul);
*(uint32_t*)0x20000080 = 1;
*(uint32_t*)0x20000084 = 1;
*(uint32_t*)0x20000088 = 0x18;
*(uint32_t*)0x2000008c = -1;
*(uint32_t*)0x20000090 = 0xc;
memcpy((void*)0x20000098, "./file0\000", 8);
	syscall(__NR_ioctl, -1, 0xc0189372, 0x20000080ul);
memcpy((void*)0x200000c0, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, 0ul);
	return 0;
}
