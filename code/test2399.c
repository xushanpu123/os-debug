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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x11ul, 2ul, 0x300);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000000, "lo\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[1], 0x8933, 0x20000000ul);
	if (res != -1)
r[2] = *(uint32_t*)0x20000010;
*(uint32_t*)0x20000100 = r[2];
*(uint16_t*)0x20000104 = 1;
*(uint16_t*)0x20000106 = 6;
memset((void*)0x20000108, 170, 5);
*(uint8_t*)0x2000010d = 0xaa;
memset((void*)0x2000010e, 0, 2);
	syscall(__NR_setsockopt, r[0], 0x107, 1, 0x20000100ul, 0x10ul);
*(uint32_t*)0x200000c0 = r[2];
*(uint16_t*)0x200000c4 = 1;
*(uint16_t*)0x200000c6 = 6;
memcpy((void*)0x200000c8, "\x97\xf5\x3b\x39\x99\x11", 6);
memset((void*)0x200000ce, 0, 2);
	syscall(__NR_setsockopt, r[0], 0x107, 2, 0x200000c0ul, 0x10ul);
	return 0;
}
