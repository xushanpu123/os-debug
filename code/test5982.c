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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0x20000080;
*(uint64_t*)0x20000080 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0xf8;
*(uint16_t*)0x200000c4 = 0x16;
*(uint16_t*)0x200000c6 = 1;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint8_t*)0x200000d0 = 0xfe;
*(uint8_t*)0x200000d1 = 0x80;
memset((void*)0x200000d2, 0, 13);
*(uint8_t*)0x200000df = 0xaa;
*(uint32_t*)0x200000e0 = htobe32(0);
*(uint16_t*)0x200000f0 = htobe16(0);
*(uint16_t*)0x200000f2 = htobe16(0);
*(uint16_t*)0x200000f4 = htobe16(0);
*(uint16_t*)0x200000f6 = htobe16(0);
*(uint16_t*)0x200000f8 = 0;
*(uint8_t*)0x200000fa = 0;
*(uint8_t*)0x200000fb = 0;
*(uint8_t*)0x200000fc = 0;
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = 0xee00;
memset((void*)0x20000108, 0, 10);
memset((void*)0x20000112, 255, 2);
*(uint8_t*)0x20000114 = 0xac;
*(uint8_t*)0x20000115 = 0x14;
*(uint8_t*)0x20000116 = 0x14;
*(uint8_t*)0x20000117 = 0xaa;
*(uint32_t*)0x20000118 = htobe32(0);
*(uint8_t*)0x2000011c = 0x6c;
*(uint8_t*)0x20000120 = 0xac;
*(uint8_t*)0x20000121 = 0x14;
*(uint8_t*)0x20000122 = 0x14;
*(uint8_t*)0x20000123 = 0;
*(uint64_t*)0x20000130 = 0;
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
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000194 = 0;
*(uint32_t*)0x20000198 = 0;
*(uint32_t*)0x2000019c = 0;
*(uint32_t*)0x200001a0 = 0;
*(uint16_t*)0x200001a4 = 0;
*(uint8_t*)0x200001a6 = 0;
*(uint8_t*)0x200001a7 = 0;
*(uint8_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b4 = 0x80000000;
*(uint64_t*)0x20000088 = 0xf8;
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000240ul, 0ul);
	return 0;
}