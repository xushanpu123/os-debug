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
	res = syscall(__NR_socket, 0x11ul, 2ul, 0x300);
	if (res != -1)
		r[0] = res;
	syscall(__NR_socket, 0x11ul, 2ul, 0x300);
*(uint64_t*)0x20006200 = 0x20000000;
*(uint16_t*)0x20000000 = 0x27;
*(uint32_t*)0x20000004 = 1;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 3;
*(uint8_t*)0x20000010 = 0;
*(uint8_t*)0x20000011 = 0;
memcpy((void*)0x20000012, "\x3b\xb9\x8c\xf5\x14\x92\xd7\x2a\xfd\xd3\xd7\x77\x99\xa4\xbf\x6e\x52\x57\x09\x5d\x7a\x27\x50\x37\xe5\xe1\x6b\x89\xa0\xf7\xaa\xbe\x84\xc7\x23\xba\x98\xd2\x29\xa8\x49\x1e\xef\xdf\x05\xd6\x4c\xc6\x41\x58\xb3\x33\xd2\x65\x9c\xa5\x66\x9e\x38\x8d\xdc\x14\x80", 63);
*(uint64_t*)0x20000058 = 0;
*(uint32_t*)0x20006208 = 0x80;
*(uint64_t*)0x20006210 = 0x20001080;
*(uint64_t*)0x20001080 = 0x20000080;
memset((void*)0x20000080, 233, 1);
*(uint64_t*)0x20001088 = 1;
*(uint64_t*)0x20006218 = 1;
*(uint64_t*)0x20006220 = 0;
*(uint64_t*)0x20006228 = 0;
*(uint32_t*)0x20006230 = 0;
*(uint32_t*)0x20006238 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20006200ul, 1ul, 0ul);
	return 0;
}
