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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_close_range, -1, -1, 2ul);
	res = syscall(__NR_pipe, 0x20000080ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000080;
*(uint32_t*)0x200000c0 = 0xc;
*(uint32_t*)0x200000c4 = 3;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
	syscall(__NR_open_by_handle_at, r[0], 0x200000c0ul, 0ul);
	return 0;
}
