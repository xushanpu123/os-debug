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
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000200 = 0;
*(uint16_t*)0x20000208 = 0xa;
*(uint16_t*)0x2000020a = htobe16(0);
*(uint32_t*)0x2000020c = htobe32(0);
*(uint8_t*)0x20000210 = -1;
*(uint8_t*)0x20000211 = 2;
memset((void*)0x20000212, 0, 13);
*(uint8_t*)0x2000021f = 1;
*(uint32_t*)0x20000220 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x30, 0x20000200ul, 0x90ul);
	return 0;
}
