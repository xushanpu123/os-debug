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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000100;
*(uint32_t*)0x20000100 = 0x14;
*(uint8_t*)0x20000104 = 4;
*(uint8_t*)0x20000105 = 1;
*(uint16_t*)0x20000106 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint8_t*)0x20000110 = 0;
*(uint8_t*)0x20000111 = 0;
*(uint16_t*)0x20000112 = htobe16(0);
*(uint64_t*)0x20000148 = 0x14;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
