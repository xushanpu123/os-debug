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
*(uint32_t*)0x20000d80 = htobe32(-1);
*(uint32_t*)0x20000d84 = htobe32(0xe0000001);
*(uint16_t*)0x20000d88 = 0;
memcpy((void*)0x20000d8a, "\x2c\x01\x26\x43\xbb\x1f\x97\x0d\xb3\x8f\x5c\x22\xb0\xcd\x8f\xce\x6a\xf2\x6b\xf4\x42\x5f\x6b\xfa\x0a\x85\x88\x58\xc5\x41\xf5\x6d", 32);
*(uint32_t*)0x20000dac = 0;
*(uint32_t*)0x20000db0 = 0;
*(uint32_t*)0x20000db4 = 0;
*(uint32_t*)0x20000db8 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xcc, 0x20000d80ul, 0x3cul);
	return 0;
}
