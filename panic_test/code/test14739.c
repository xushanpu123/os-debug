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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000080 = 0x10;
memcpy((void*)0x20000082, "\x5b\xbf\xed\xb2\xce\x14\xa5\xd2\xa5\xd5\xdf\x10\x49\x35\x3a\x4a\x8b\xd1\xd4\xbc\xd7\x7a\x45\x67\x5e\xf7\xfc\xab\x08\xcd\x11\x66\x9c\x28\xa6\x8e\xbf\xc3\xe9\x99\x7b\x4a\x6b\x8c\x7c\x0d\x26\xae\x37\xdf\xaa\xf0\x72\xaa\xf7\xe5\xae\x3c\xc7\xb2\xc7\x2a\x44\x4a\x76\xf8\x6b\x21\xb4\x2b\xb8\xde\x61\xf6\x5a\xfd\xee\xed\x2c\xd0\x35\xa8\x92\x0f\x14\xc0\x9d\x0b\xe9\x64\x73\x65\xe0\x80\x02\x23\xe2\x2d\xff\x71\xf7\xbd\x44\xeb\xdf\x03\x3b\x22\x8a\x9b\xc0\x9c\x29\x20\x67\x9d\x11\x11\xc3\xbc\xf8\x7e\xea\x8f\xe1\xdd", 126);
	syscall(__NR_bind, r[0], 0x20000080ul, 0x80ul);
*(uint16_t*)0x20000140 = 0x11;
*(uint16_t*)0x20000142 = htobe16(0x19);
*(uint32_t*)0x20000144 = 0;
*(uint16_t*)0x20000148 = 1;
*(uint8_t*)0x2000014a = 0x3f;
*(uint8_t*)0x2000014b = 6;
memcpy((void*)0x2000014c, "\x4d\x46\x66\xf7\xf4\x58", 6);
memset((void*)0x20000152, 0, 2);
	syscall(__NR_recvfrom, -1, 0x20000340ul, 0x5aul, 0x12123ul, 0x20000140ul, 0x14ul);
	return 0;
}