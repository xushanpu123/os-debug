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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe, 0x20000000ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000000;
r[1] = *(uint32_t*)0x20000004;
	}
	res = syscall(__NR_pipe, 0x20000000ul);
	if (res != -1) {
r[2] = *(uint32_t*)0x20000000;
r[3] = *(uint32_t*)0x20000004;
	}
	syscall(__NR_write, r[1], 0x20000480ul, 0x58ul);
*(uint64_t*)0x20000d00 = 0x200000c0;
memset((void*)0x200000c0, 20, 1);
*(uint64_t*)0x20000d08 = 1;
	syscall(__NR_vmsplice, r[2], 0x20000d00ul, 1ul, 0ul);
	syscall(__NR_splice, r[0], 0ul, r[3], 0ul, 0x1eul, 0ul);
	return 0;
}
