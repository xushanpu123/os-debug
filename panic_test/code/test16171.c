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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0xa;
	syscall(__NR_setsockopt, r[0], 0, 3, 0x20000080ul, 4ul);
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[1] = res;
*(uint16_t*)0x20001680 = 0;
*(uint16_t*)0x20001682 = 0x8000;
	syscall(__NR_setsockopt, r[1], 0x107, 0x12, 0x20001680ul, 4ul);
memcpy((void*)0x20000100, "\x47\x3c\xb9\x36\xcc\x4e\x5a\x18\x6a\x91\x20\xa1\x51\xdf\x31\x36\x51\xf7\xb9\x6f\x5b\xbb\x95\x40\xa2\x01\x3c\x52", 28);
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
	syscall(__NR_sendto, r[0], 0x20000100ul, 0x1cul, 0ul, 0x20000000ul, 0x10ul);
	return 0;
}
