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

#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
#endif
#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0x10;
*(uint32_t*)0x2000000c = 0;
*(uint32_t*)0x20000010 = 0;
*(uint32_t*)0x20000018 = -1;
memset((void*)0x2000001c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0xfffffffd, 0x20000000ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_uring_register, r[0], 9ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_io_uring_register, r[0], 0xaul, 0ul, 0);
	syscall(__NR_io_uring_register, r[0], 0xaul, 0ul, r[1]);
	return 0;
}
