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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000100;
*(uint32_t*)0x20000100 = 0x1c;
*(uint16_t*)0x20000104 = 0x1d;
*(uint16_t*)0x20000106 = 0x289;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
memcpy((void*)0x20000110, "\x07\xa8\x67\x14\x55\xf4\x40\x95\x2e", 9);
*(uint64_t*)0x20000088 = 0x1c;
*(uint64_t*)0x20000358 = 1;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000340ul, 0ul);
	return 0;
}