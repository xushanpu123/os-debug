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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_eventfd2, 0, 0x80800ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000444 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint32_t*)0x20000450 = 0;
*(uint32_t*)0x20000458 = -1;
memset((void*)0x2000045c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x32d2, 0x20000440ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x200004c0 = -1;
*(uint32_t*)0x200004c4 = r[0];
	syscall(__NR_io_uring_register, r[1], 2ul, 0x200004c0ul, 2ul);
	return 0;
}