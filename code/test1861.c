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
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d8 = -1;
memset((void*)0x200000dc, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x534e, 0x200000c0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_fstat, r[0], 0x20000200ul);
	return 0;
}
