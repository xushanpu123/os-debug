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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001d00 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e23);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint32_t*)0x20001d08 = 0x10;
*(uint64_t*)0x20001d10 = 0;
*(uint64_t*)0x20001d18 = 0;
*(uint64_t*)0x20001d20 = 0x20000140;
*(uint64_t*)0x20000140 = 0x14;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 7;
*(uint8_t*)0x20000150 = 0x89;
*(uint8_t*)0x20000151 = 3;
*(uint8_t*)0x20000152 = 0;
*(uint64_t*)0x20001d28 = 0x18;
*(uint32_t*)0x20001d30 = 0;
*(uint32_t*)0x20001d38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001d00ul, 1ul, 0ul);
	return 0;
}
