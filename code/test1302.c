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
*(uint16_t*)0x20001000 = 0;
*(uint8_t*)0x20001002 = 0;
*(uint8_t*)0x20001003 = 0;
*(uint32_t*)0x20001004 = 0;
*(uint8_t*)0x20001008 = 0xac;
*(uint8_t*)0x20001009 = 0x14;
*(uint8_t*)0x2000100a = 0x14;
*(uint8_t*)0x2000100b = 0xbb;
*(uint8_t*)0x2000100c = 0xac;
*(uint8_t*)0x2000100d = 0x14;
*(uint8_t*)0x2000100e = 0x14;
*(uint8_t*)0x2000100f = 0xaa;
	syscall(__NR_setsockopt, r[0], 0, 0xcb, 0x20001000ul, 0x10ul);
	return 0;
}
