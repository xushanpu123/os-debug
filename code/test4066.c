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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 7, 0x20000840ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000840;
	syscall(__NR_io_destroy, r[0]);
	syscall(__NR_io_setup, 0x40, 0x20000080ul);
*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint16_t*)0x200002d0 = 0;
*(uint16_t*)0x200002d2 = 0;
*(uint32_t*)0x200002d4 = -1;
*(uint64_t*)0x200002d8 = 0;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint64_t*)0x200002f0 = 0;
*(uint32_t*)0x200002f8 = 0;
*(uint32_t*)0x200002fc = -1;
	syscall(__NR_io_cancel, r[0], 0x200002c0ul, 0ul);
	return 0;
}
