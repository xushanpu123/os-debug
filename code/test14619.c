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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[1] = res;
*(uint16_t*)0x20000140 = 0;
*(uint16_t*)0x20000142 = 4;
	syscall(__NR_setsockopt, r[1], 0x107, 0x12, 0x20000140ul, 4ul);
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x200002c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[2], 0x8933, 0x200002c0ul);
	if (res != -1)
r[3] = *(uint32_t*)0x200002d0;
*(uint16_t*)0x20000100 = 0x11;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = r[3];
*(uint16_t*)0x20000108 = 1;
*(uint8_t*)0x2000010a = 0;
*(uint8_t*)0x2000010b = 6;
*(uint8_t*)0x2000010c = 1;
*(uint8_t*)0x2000010d = 0x80;
*(uint8_t*)0x2000010e = 0xc2;
*(uint8_t*)0x2000010f = 0;
*(uint8_t*)0x20000110 = 0;
*(uint8_t*)0x20000111 = 0;
memset((void*)0x20000112, 0, 2);
	syscall(__NR_sendto, r[0], 0ul, 0ul, 0ul, 0x20000100ul, 0x14ul);
	return 0;
}