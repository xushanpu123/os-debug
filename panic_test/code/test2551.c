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
	res = syscall(__NR_socket, 0x11ul, 2ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20005980 = 0x20000000;
*(uint16_t*)0x20000000 = 0x27;
*(uint32_t*)0x20000004 = 1;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint32_t*)0x20005988 = 0x80;
*(uint64_t*)0x20005990 = 0;
*(uint64_t*)0x20005998 = 0;
*(uint64_t*)0x200059a0 = 0x20005b80;
*(uint64_t*)0x20005b80 = 0x10;
*(uint32_t*)0x20005b88 = 1;
*(uint32_t*)0x20005b8c = 1;
*(uint64_t*)0x200059a8 = 0x10;
*(uint32_t*)0x200059b0 = 0;
*(uint32_t*)0x200059b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20005980ul, 1ul, 0ul);
	return 0;
}