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
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x200000c0ul, 4ul);
*(uint16_t*)0x20000100 = 2;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = htobe32(0xe0000001);
*(uint8_t*)0x20000180 = 0;
*(uint8_t*)0x20000181 = 0;
*(uint16_t*)0x20000182 = 0x4c;
*(uint32_t*)0x20000184 = 0;
memcpy((void*)0x20000188, "\xcc\xb2\x9d\x7b\x37\xa0\xa6\x00\x4a\x27\x07\xfc\x23\x75\x56\x42\x6d\x88\x48\xf1\x4b\xa4\xfb\xa2\x29\xa9\xf3\x38\x2e\x21\x18\x56\xf4\x7b\x84\x54\x28\x44\xec\x34\x15\x46\x2a\xb3\x25\x78\x84\x44\xb1\x8c\xb5\x2d\x6d\xe0\x65\x8a\x61\x60\xa2\xff\x5e\xd5\x3c\x53\xe4\x5e\x66\xcd\x3a\x07\xd8\xb0\x9c\x7d\x4f\x79\xa8\x18\xbe\xf8", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000100ul, 0xd8ul);
*(uint16_t*)0x20000400 = 2;
*(uint16_t*)0x20000402 = 0;
*(uint32_t*)0x20000404 = htobe32(0x7f000001);
*(uint32_t*)0x20000408 = 0;
*(uint32_t*)0x2000040c = 0;
	syscall(__NR_connect, r[0], 0x20000400ul, 0x80ul);
	return 0;
}
