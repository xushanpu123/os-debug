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

#ifndef __NR_io_uring_enter
#define __NR_io_uring_enter 426
#endif
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
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 1;
*(uint32_t*)0x2000020c = 0;
*(uint32_t*)0x20000210 = 0;
*(uint32_t*)0x20000218 = -1;
memset((void*)0x2000021c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0xf5, 0x20000200ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_io_uring_enter, r[0], 0, 0, 3ul, 0ul, 0ul);
	return 0;
}