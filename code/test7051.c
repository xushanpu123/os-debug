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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000100 = 0;
*(uint16_t*)0x20000108 = 2;
*(uint16_t*)0x2000010a = htobe16(0);
*(uint8_t*)0x2000010c = 0xac;
*(uint8_t*)0x2000010d = 0x14;
*(uint8_t*)0x2000010e = 0x14;
*(uint8_t*)0x2000010f = 0;
*(uint16_t*)0x20000118 = 2;
*(uint16_t*)0x2000011a = htobe16(0);
*(uint32_t*)0x2000011c = htobe32(0x7f000001);
*(uint16_t*)0x20000128 = 2;
*(uint16_t*)0x2000012a = htobe16(0);
*(uint32_t*)0x2000012c = htobe32(-1);
*(uint16_t*)0x20000138 = 0;
*(uint16_t*)0x2000013a = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint16_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint16_t*)0x20000170 = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000100ul);
	res = syscall(__NR_socket, 2ul, 0x800ul, 0x101);
	if (res != -1)
		r[1] = res;
*(uint8_t*)0x20000000 = 0xfe;
*(uint8_t*)0x20000001 = 0x80;
memset((void*)0x20000002, 0, 13);
*(uint8_t*)0x2000000f = 0xbb;
*(uint8_t*)0x20000010 = 0xfc;
*(uint8_t*)0x20000011 = 1;
memset((void*)0x20000012, 0, 13);
*(uint8_t*)0x2000001f = 0;
	syscall(__NR_ioctl, r[1], 0x89e1, 0x20000000ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_setsockopt, r[2], 0, 0xcf, 0x20000040ul, 4ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[3] = res;
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_setsockopt, r[3], 0, 0xcf, 0x20000040ul, 4ul);
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = htobe32(0);
*(uint8_t*)0x20000088 = 0xac;
*(uint8_t*)0x20000089 = 0x14;
*(uint8_t*)0x2000008a = 0x14;
*(uint8_t*)0x2000008b = 0xbb;
	syscall(__NR_setsockopt, r[3], 0, 8, 0x20000080ul, 0xcul);
memcpy((void*)0x20000040, "wg1\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, r[2], 0x8933, 0x20000040ul);
	return 0;
}
