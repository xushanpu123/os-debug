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

static long syz_memcpy_off(volatile long a0, volatile long a1, volatile long a2, volatile long a3, volatile long a4)
{
	char* dest = (char*)a0;
	uint32_t dest_off = (uint32_t)a1;
	char* src = (char*)a2;
	uint32_t src_off = (uint32_t)a3;
	size_t n = (size_t)a4;
	return (long)memcpy(dest + dest_off, src + src_off, n);
}

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_mmap, 0x20ffc000ul, 0x2000ul, 0x1000006ul, 0x831ul, -1, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 0;
syz_memcpy_off(r[0], 0, 0x20000000, 0, 4);
	return 0;
}
