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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x2000ab00 = 0;
*(uint32_t*)0x2000ab08 = 0;
*(uint64_t*)0x2000ab10 = 0;
*(uint64_t*)0x2000ab18 = 0;
*(uint64_t*)0x2000ab20 = 0;
*(uint64_t*)0x2000ab28 = 0;
*(uint32_t*)0x2000ab30 = 0;
*(uint32_t*)0x2000ab38 = 0;
*(uint64_t*)0x2000ab40 = 0;
*(uint32_t*)0x2000ab48 = 0;
*(uint64_t*)0x2000ab50 = 0;
*(uint64_t*)0x2000ab58 = 0;
*(uint64_t*)0x2000ab60 = 0x20003c00;
*(uint64_t*)0x20003c00 = 0x10;
*(uint32_t*)0x20003c08 = 1;
*(uint32_t*)0x20003c0c = 1;
*(uint64_t*)0x2000ab68 = 0x10;
*(uint32_t*)0x2000ab70 = 0;
*(uint32_t*)0x2000ab78 = 0;
	syscall(__NR_sendmmsg, r[0], 0x2000ab00ul, 2ul, 0ul);
	return 0;
}