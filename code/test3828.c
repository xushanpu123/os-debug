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
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0x20000280;
*(uint64_t*)0x20000280 = 0x200002c0;
*(uint32_t*)0x200002c0 = 0x1b;
*(uint16_t*)0x200002c4 = 0;
*(uint16_t*)0x200002c6 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint8_t*)0x200002d0 = 0x6b;
*(uint8_t*)0x200002d1 = 0;
*(uint16_t*)0x200002d2 = 0;
*(uint16_t*)0x200002d4 = 8;
*(uint16_t*)0x200002d6 = 3;
*(uint32_t*)0x200002d8 = 0;
*(uint16_t*)0x200002dc = 0xa;
*(uint16_t*)0x200002de = 6;
*(uint8_t*)0x200002e0 = 8;
*(uint8_t*)0x200002e1 = 2;
*(uint8_t*)0x200002e2 = 0x11;
*(uint8_t*)0x200002e3 = 0;
*(uint8_t*)0x200002e4 = 0;
*(uint8_t*)0x200002e5 = 0;
*(uint64_t*)0x20000288 = 0x28;
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000240ul, 0ul);
	return 0;
}
