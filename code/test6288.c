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
*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 9;
*(uint16_t*)0x20000004 = 0;
*(uint16_t*)0x20000006 = 0;
*(uint16_t*)0x20000008 = 0;
*(uint16_t*)0x2000000a = 0;
	syscall(__NR_semtimedop, r[0], 0x20000000ul, 2ul, 0ul);
	syscall(__NR_semctl, r[0], 0ul, 0xeul, 0ul);
	return 0;
}
