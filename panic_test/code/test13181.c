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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[1] = res;
*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 0x1000;
	syscall(__NR_setsockopt, r[1], 0x107, 0x12, 0x20000000ul, 4ul);
*(uint64_t*)0x20003e00 = 0x20000040;
*(uint16_t*)0x20000040 = 2;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint8_t*)0x20000044 = 0xac;
*(uint8_t*)0x20000045 = 0x14;
*(uint8_t*)0x20000046 = 0x14;
*(uint8_t*)0x20000047 = 0xaa;
*(uint32_t*)0x20003e08 = 0x10;
*(uint64_t*)0x20003e10 = 0;
*(uint64_t*)0x20003e18 = 0;
*(uint64_t*)0x20003e20 = 0;
*(uint64_t*)0x20003e28 = 0;
*(uint32_t*)0x20003e30 = 0;
*(uint32_t*)0x20003e38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003e00ul, 1ul, 0x28040895ul);
	return 0;
}