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

#ifndef __NR_preadv2
#define __NR_preadv2 327
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000980, "/dev/sr0\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000980ul, 0x4800ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_dup2, r[0], r[0]);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000200 = 0x20000000;
*(uint64_t*)0x20000208 = 0x95;
	syscall(__NR_preadv2, r[1], 0x20000200ul, 1ul, 0, 0, 0xcul);
	return 0;
}
