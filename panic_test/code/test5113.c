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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe, 0x200002c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200002c0;
r[1] = *(uint32_t*)0x200002c4;
	}
	res = syscall(__NR_pipe, 0x200002c0ul);
	if (res != -1) {
r[2] = *(uint32_t*)0x200002c0;
r[3] = *(uint32_t*)0x200002c4;
	}
*(uint32_t*)0x20000200 = r[2];
*(uint16_t*)0x20000204 = 0;
*(uint16_t*)0x20000206 = 0;
	syscall(__NR_poll, 0x20000200ul, 1ul, 0x100);
	syscall(__NR_tee, r[0], r[3], 3ul, 0ul);
	syscall(__NR_close_range, r[1], -1, 0ul);
	return 0;
}