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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000300, "/dev/full\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000300ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000204 = 0xd4c0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint32_t*)0x20000210 = 0;
*(uint32_t*)0x20000218 = -1;
memset((void*)0x2000021c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x41d3, 0x20000200ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_dup2, r[0], r[1]);
	res = syscall(__NR_eventfd, 0);
	if (res != -1)
		r[2] = res;
	syscall(__NR_read, r[2], 0x200000c0ul, 8ul);
*(uint64_t*)0x20000080 = 0x81;
	syscall(__NR_write, r[2], 0x20000080ul, 8ul);
	return 0;
}
