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

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000284 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint32_t*)0x20000290 = 0;
*(uint32_t*)0x20000298 = -1;
memset((void*)0x2000029c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x6fbf, 0x20000280ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close, r[0]);
	return 0;
}
