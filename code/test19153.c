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

uint64_t r[2] = {0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20001780, "./file0\000", 8);
	syscall(__NR_mknodat, 0xffffff9c, 0x20001780ul, 0ul, 0);
memcpy((void*)0x20001c80, "./file0\000", 8);
	res = syscall(__NR_stat, 0x20001c80ul, 0x20001cc0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20001cd8;
	syscall(__NR_setreuid, 0, r[0]);
memcpy((void*)0x20001c80, "./file0\000", 8);
	res = syscall(__NR_stat, 0x20001c80ul, 0x20001cc0ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20001cd8;
	syscall(__NR_setreuid, r[1], r[0]);
	return 0;
}
