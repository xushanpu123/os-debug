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

#ifndef __NR_openat2
#define __NR_openat2 437
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000180, "./file1\000", 8);
*(uint64_t*)0x200001c0 = 0x1019c0;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
	res = syscall(__NR_openat2, 0xffffff9c, 0x20000180ul, 0x200001c0ul, 0x18ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 2;
	syscall(__NR_ioctl, r[0], 0x4004662b, 0x20000080ul);
	return 0;
}
