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
	res = syscall(__NR_pipe, 0x200002c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200002c0;
r[1] = *(uint32_t*)0x200002c4;
	}
*(uint64_t*)0x200000c0 = 0x20000180;
memset((void*)0x20000180, 142, 1);
*(uint64_t*)0x200000c8 = 1;
	syscall(__NR_vmsplice, r[1], 0x200000c0ul, 1ul, 0ul);
	res = syscall(__NR_pipe, 0x200002c0ul);
	if (res != -1) {
r[2] = *(uint32_t*)0x200002c0;
r[3] = *(uint32_t*)0x200002c4;
	}
*(uint64_t*)0x20000000 = 0x200001c0;
memset((void*)0x200001c0, 18, 1);
*(uint64_t*)0x20000008 = 1;
	syscall(__NR_vmsplice, r[2], 0x20000000ul, 1ul, 0ul);
	syscall(__NR_tee, r[0], r[3], 3ul, 0ul);
	return 0;
}
