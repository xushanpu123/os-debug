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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200000c0 = 0x20000040;
*(uint16_t*)0x20000040 = 0x10;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x200000c8 = 0xc;
*(uint64_t*)0x200000d0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000100;
*(uint32_t*)0x20000100 = 0x3c;
*(uint16_t*)0x20000104 = 0x3e9;
*(uint16_t*)0x20000106 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint32_t*)0x20000110 = 0;
*(uint32_t*)0x20000114 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x2000011c = 0;
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = 0;
*(uint32_t*)0x20000128 = 0;
*(uint32_t*)0x2000012c = 0;
*(uint32_t*)0x20000130 = 0;
*(uint32_t*)0x20000134 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint64_t*)0x20000088 = 0x26;
*(uint64_t*)0x200000d8 = 1;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0ul);
	return 0;
}