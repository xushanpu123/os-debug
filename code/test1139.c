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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0xac;
*(uint8_t*)0x20000001 = 0x14;
*(uint8_t*)0x20000002 = 0x14;
*(uint8_t*)0x20000003 = 0;
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0;
*(uint16_t*)0x20000008 = 0;
memcpy((void*)0x2000000a, "\x07\xc1\xc7\xe6\x5c\x28\x13\xf1\x95\x8b\x98\xd8\xdd\x15\xe6\x2b\x97\xc2\x26\x83\x7a\x47\x6b\xb6\x59\x90\x69\xed\xb5\x3e\x3b\x15", 32);
*(uint32_t*)0x2000002c = 0;
*(uint32_t*)0x20000030 = 0;
*(uint32_t*)0x20000034 = 0;
*(uint32_t*)0x20000038 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xcd, 0x20000000ul, 0x3cul);
	return 0;
}
