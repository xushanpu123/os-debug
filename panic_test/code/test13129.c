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
	res = syscall(__NR_semget, 0ul, 4ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000080 = 0;
*(uint16_t*)0x20000082 = 1;
*(uint16_t*)0x20000084 = 0;
*(uint16_t*)0x20000086 = 0;
*(uint16_t*)0x20000088 = 0;
*(uint16_t*)0x2000008a = 0;
	syscall(__NR_semtimedop, r[0], 0x20000080ul, 2ul, 0ul);
*(uint16_t*)0x20000040 = 3;
*(uint16_t*)0x20000042 = 0xfff7;
*(uint16_t*)0x20000044 = 0;
*(uint16_t*)0x20000046 = 3;
*(uint16_t*)0x20000048 = 0;
*(uint16_t*)0x2000004a = 0;
*(uint64_t*)0x200010c0 = 0;
*(uint64_t*)0x200010c8 = 0;
	syscall(__NR_semtimedop, r[0], 0x20000040ul, 2ul, 0x200010c0ul);
	return 0;
}
