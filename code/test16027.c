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
*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0x20000280;
*(uint64_t*)0x20000280 = 0x20000000;
*(uint32_t*)0x20000000 = 0x13c;
*(uint16_t*)0x20000004 = 0x1a;
*(uint16_t*)0x20000006 = 1;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0xac;
*(uint8_t*)0x20000011 = 0x1e;
*(uint8_t*)0x20000012 = 0;
*(uint8_t*)0x20000013 = 1;
*(uint8_t*)0x20000020 = 0xac;
*(uint8_t*)0x20000021 = 0x14;
*(uint8_t*)0x20000022 = 0x14;
*(uint8_t*)0x20000023 = 0;
*(uint16_t*)0x20000030 = htobe16(0);
*(uint16_t*)0x20000032 = htobe16(0);
*(uint16_t*)0x20000034 = htobe16(0);
*(uint16_t*)0x20000036 = htobe16(0);
*(uint16_t*)0x20000038 = 0;
*(uint8_t*)0x2000003a = 0;
*(uint8_t*)0x2000003b = 0;
*(uint8_t*)0x2000003c = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x88;
memset((void*)0x2000004a, 0, 12);
*(uint8_t*)0x20000056 = 0;
*(uint8_t*)0x20000057 = 1;
*(uint32_t*)0x20000058 = htobe32(0);
*(uint8_t*)0x2000005c = 0x32;
*(uint8_t*)0x20000060 = 0xfc;
*(uint8_t*)0x20000061 = 2;
memset((void*)0x20000062, 0, 13);
*(uint8_t*)0x2000006f = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint64_t*)0x200000b0 = 0;
*(uint64_t*)0x200000b8 = 0;
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d4 = 0;
*(uint32_t*)0x200000d8 = 0;
*(uint32_t*)0x200000dc = 0;
*(uint32_t*)0x200000e0 = 0;
*(uint16_t*)0x200000e4 = 2;
*(uint8_t*)0x200000e6 = 0;
*(uint8_t*)0x200000e7 = 0;
*(uint8_t*)0x200000e8 = 0;
*(uint16_t*)0x200000f0 = 0x4c;
*(uint16_t*)0x200000f2 = 0x12;
memcpy((void*)0x200000f4, "aegis128-aesni\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x20000134 = 0x4e;
*(uint32_t*)0x20000138 = 0;
*(uint64_t*)0x20000288 = 0x13c;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}