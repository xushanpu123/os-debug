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
*(uint64_t*)0x20000280 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0x20000240;
*(uint64_t*)0x20000240 = 0x20000140;
*(uint32_t*)0x20000140 = 0xb8;
*(uint16_t*)0x20000144 = 0x13;
*(uint16_t*)0x20000146 = 1;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0;
*(uint32_t*)0x20000150 = htobe32(-1);
*(uint32_t*)0x20000160 = htobe32(0xe0000001);
*(uint16_t*)0x20000170 = htobe16(0);
*(uint16_t*)0x20000172 = htobe16(0);
*(uint16_t*)0x20000174 = htobe16(0);
*(uint16_t*)0x20000176 = htobe16(0);
*(uint16_t*)0x20000178 = 0xa;
*(uint8_t*)0x2000017a = 0;
*(uint8_t*)0x2000017b = 0;
*(uint8_t*)0x2000017c = 0;
*(uint32_t*)0x20000180 = 0;
*(uint32_t*)0x20000184 = 0xee00;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint64_t*)0x200001b0 = 0;
*(uint64_t*)0x200001b8 = 0;
*(uint64_t*)0x200001c0 = 0;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint32_t*)0x200001e8 = 0;
*(uint32_t*)0x200001ec = 0;
*(uint8_t*)0x200001f0 = 0;
*(uint8_t*)0x200001f1 = 0;
*(uint8_t*)0x200001f2 = 0;
*(uint8_t*)0x200001f3 = 0;
*(uint64_t*)0x20000248 = 0xb8;
*(uint64_t*)0x20000298 = 1;
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
*(uint32_t*)0x200002b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000280ul, 0ul);
	return 0;
}