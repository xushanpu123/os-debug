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
memcpy((void*)0x20000100, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000100ul, 0x42ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000800 = 0x20000000;
memset((void*)0x20000000, 98, 1);
*(uint64_t*)0x20000808 = 1;
	syscall(__NR_pwritev2, r[0], 0x20000800ul, 1ul, 0x200000, 0, 4ul);
	return 0;
}
