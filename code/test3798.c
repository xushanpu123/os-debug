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
*(uint8_t*)0x20000100 = 0xac;
*(uint8_t*)0x20000101 = 0x14;
*(uint8_t*)0x20000102 = 0x14;
*(uint8_t*)0x20000103 = 0xaa;
memset((void*)0x20000110, 0, 10);
memset((void*)0x2000011a, 255, 2);
*(uint32_t*)0x2000011c = htobe32(0x7f000001);
*(uint16_t*)0x20000120 = htobe16(0);
*(uint16_t*)0x20000122 = htobe16(0);
*(uint16_t*)0x20000124 = htobe16(0);
*(uint16_t*)0x20000126 = htobe16(0);
*(uint16_t*)0x20000128 = 2;
*(uint8_t*)0x2000012a = 0;
*(uint8_t*)0x2000012b = 0;
*(uint8_t*)0x2000012c = 0;
*(uint32_t*)0x20000130 = 0;
*(uint32_t*)0x20000134 = -1;
*(uint64_t*)0x20000138 = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint64_t*)0x20000178 = 0;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint32_t*)0x20000198 = 0;
*(uint32_t*)0x2000019c = 0x6e6bb5;
*(uint8_t*)0x200001a0 = 0;
*(uint8_t*)0x200001a1 = 0;
*(uint8_t*)0x200001a2 = 0;
*(uint8_t*)0x200001a3 = 0;
*(uint8_t*)0x200001a8 = 0xfc;
*(uint8_t*)0x200001a9 = 1;
memset((void*)0x200001aa, 0, 13);
*(uint8_t*)0x200001b7 = 0;
*(uint32_t*)0x200001b8 = htobe32(0);
*(uint8_t*)0x200001bc = 0;
*(uint16_t*)0x200001c0 = 0;
*(uint8_t*)0x200001c4 = 0xac;
*(uint8_t*)0x200001c5 = 0x1e;
*(uint8_t*)0x200001c6 = 0;
*(uint8_t*)0x200001c7 = 1;
*(uint32_t*)0x200001d4 = 0;
*(uint8_t*)0x200001d8 = 0;
*(uint8_t*)0x200001d9 = 0;
*(uint8_t*)0x200001da = 0;
*(uint32_t*)0x200001dc = 0;
*(uint32_t*)0x200001e0 = 0;
*(uint32_t*)0x200001e4 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0x11, 0x20000100ul, 0xe8ul);
	return 0;
}
