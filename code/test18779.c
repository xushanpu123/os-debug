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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = htobe32(0);
*(uint8_t*)0x20000090 = 0xac;
*(uint8_t*)0x20000091 = 0x14;
*(uint8_t*)0x20000092 = 0x14;
*(uint8_t*)0x20000093 = 0xbb;
*(uint16_t*)0x200000a0 = htobe16(0);
*(uint16_t*)0x200000a2 = htobe16(0);
*(uint16_t*)0x200000a4 = htobe16(0);
*(uint16_t*)0x200000a6 = htobe16(0);
*(uint16_t*)0x200000a8 = 2;
*(uint8_t*)0x200000aa = 0;
*(uint8_t*)0x200000ab = 0;
*(uint8_t*)0x200000ac = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint64_t*)0x200000b8 = 0;
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x2000011c = 0;
*(uint8_t*)0x20000120 = 1;
*(uint8_t*)0x20000121 = 0;
*(uint8_t*)0x20000122 = 0;
*(uint8_t*)0x20000123 = 0;
*(uint8_t*)0x20000128 = 0xac;
*(uint8_t*)0x20000129 = 0x14;
*(uint8_t*)0x2000012a = 0x14;
*(uint8_t*)0x2000012b = 0;
*(uint32_t*)0x20000138 = htobe32(0);
*(uint8_t*)0x2000013c = 0x2b;
*(uint16_t*)0x20000140 = 0xa;
memset((void*)0x20000144, 0, 16);
*(uint32_t*)0x20000154 = 0;
*(uint8_t*)0x20000158 = 1;
*(uint8_t*)0x20000159 = 0;
*(uint8_t*)0x2000015a = 0;
*(uint32_t*)0x2000015c = 0;
*(uint32_t*)0x20000160 = 0;
*(uint32_t*)0x20000164 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x23, 0x20000080ul, 0xe8ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 10);
memset((void*)0x20000012, 255, 2);
*(uint32_t*)0x20000014 = htobe32(0);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
	return 0;
}
