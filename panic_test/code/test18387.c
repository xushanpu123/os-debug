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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 6;
	syscall(__NR_setsockopt, r[0], 1, 0xf, 0x20000040ul, 4ul);
*(uint64_t*)0x200041c0 = 0;
*(uint32_t*)0x200041c8 = 0;
*(uint64_t*)0x200041d0 = 0;
*(uint64_t*)0x200041d8 = 0;
*(uint64_t*)0x200041e0 = 0;
*(uint64_t*)0x200041e8 = 0;
*(uint32_t*)0x200041f0 = 0;
*(uint32_t*)0x200041f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200041c0ul, 1ul, 0ul);
*(uint16_t*)0x20000080 = 0;
memcpy((void*)0x20000082, "./file0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 108);
	syscall(__NR_connect, r[0], 0x20000080ul, 0x6eul);
	return 0;
}
