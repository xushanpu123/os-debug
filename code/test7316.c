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
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 1;
*(uint16_t*)0x200001c8 = 0xa;
*(uint16_t*)0x200001ca = htobe16(0);
*(uint32_t*)0x200001cc = htobe32(0);
*(uint8_t*)0x200001d0 = -1;
*(uint8_t*)0x200001d1 = 2;
memset((void*)0x200001d2, 0, 13);
*(uint8_t*)0x200001df = 1;
*(uint32_t*)0x200001e0 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x2a, 0x200001c0ul, 0x88ul);
*(uint32_t*)0x20000280 = 0;
*(uint16_t*)0x20000288 = 0xa;
*(uint16_t*)0x2000028a = htobe16(0);
*(uint32_t*)0x2000028c = htobe32(0);
*(uint8_t*)0x20000290 = -1;
*(uint8_t*)0x20000291 = 1;
memset((void*)0x20000292, 0, 13);
*(uint8_t*)0x2000029f = 1;
*(uint32_t*)0x200002a0 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x2d, 0x20000280ul, 0x88ul);
	return 0;
}
