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
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x200000c0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x200000c0;
*(uint64_t*)0x20002c40 = 0;
*(uint32_t*)0x20002c48 = 0;
*(uint64_t*)0x20002c50 = 0;
*(uint64_t*)0x20002c58 = 0;
*(uint64_t*)0x20002c60 = 0;
*(uint64_t*)0x20002c68 = 0;
*(uint32_t*)0x20002c70 = 0;
*(uint32_t*)0x20002c78 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002c40ul, 0x4000000000002d2ul, 0ul);
*(uint16_t*)0x20000440 = 0;
memcpy((void*)0x20000442, "./file0/file0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 108);
	syscall(__NR_connect, r[0], 0x20000440ul, 0x6eul);
	return 0;
}
