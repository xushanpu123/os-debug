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
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = htobe32(0xe0000001);
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0xaa;
	syscall(__NR_setsockopt, r[0], 0, 0x23, 0x20000000ul, 8ul);
*(uint32_t*)0x20000000 = htobe32(0xe0000001);
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0xaa;
*(uint8_t*)0x20000008 = 0xac;
*(uint8_t*)0x20000009 = 0x14;
*(uint8_t*)0x2000000a = 0x14;
*(uint8_t*)0x2000000b = 0;
	syscall(__NR_setsockopt, r[0], 0, 0x25, 0x20000000ul, 0xcul);
	return 0;
}
