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
	syscall(__NR_setresuid, 0, 0xee00, -1);
	res = syscall(__NR_geteuid);
	if (res != -1)
		r[0] = res;
	syscall(__NR_setresuid, r[0], 0, 0);
	res = syscall(__NR_getresuid, 0x20000200ul, 0x20000240ul, 0x20000280ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000200;
	syscall(__NR_setresuid, r[0], r[1], 0);
	syscall(__NR_setresuid, 0, 0xee01, 0);
	return 0;
}
