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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000000;
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_dup3, r[0], r[1], 0ul);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x200002c0 = 0x20000200;
*(uint16_t*)0x20000200 = 0x10;
*(uint16_t*)0x20000202 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x200002c8 = 0xc;
*(uint64_t*)0x200002d0 = 0x20000280;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0x34;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[2], 0x200002c0ul, 0ul);
	return 0;
}
