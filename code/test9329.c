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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000240, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000240ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000080ul, 0x4802ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_flock, r[0], 1ul);
*(uint64_t*)0x20000040 = 0x20000000;
memset((void*)0x20000000, 223, 1);
*(uint64_t*)0x20000048 = 0xffffffb7;
	syscall(__NR_pwritev2, r[1], 0x20000040ul, 1ul, 0, 0, 0ul);
	return 0;
}
