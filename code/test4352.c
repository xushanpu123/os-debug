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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = htobe32(0xe0000002);
*(uint32_t*)0x20000010 = htobe32(0);
*(uint16_t*)0x20000020 = htobe16(0);
*(uint16_t*)0x20000022 = htobe16(0);
*(uint16_t*)0x20000024 = htobe16(0);
*(uint16_t*)0x20000026 = htobe16(0);
*(uint16_t*)0x20000028 = 0xa;
*(uint8_t*)0x2000002a = 0;
*(uint8_t*)0x2000002b = 0;
*(uint8_t*)0x2000002c = 0;
*(uint32_t*)0x20000030 = 0;
*(uint32_t*)0x20000034 = 0;
*(uint64_t*)0x20000038 = 0;
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x2000009c = 0x6e6bb0;
*(uint8_t*)0x200000a0 = 0;
*(uint8_t*)0x200000a1 = 0;
*(uint8_t*)0x200000a2 = 0;
*(uint8_t*)0x200000a3 = 0;
*(uint8_t*)0x200000a8 = -1;
*(uint8_t*)0x200000a9 = 1;
memset((void*)0x200000aa, 0, 13);
*(uint8_t*)0x200000b7 = 1;
*(uint32_t*)0x200000b8 = htobe32(0);
*(uint8_t*)0x200000bc = 0x6c;
*(uint16_t*)0x200000c0 = 0;
memset((void*)0x200000c4, 0, 10);
memset((void*)0x200000ce, 255, 2);
*(uint8_t*)0x200000d0 = 0xac;
*(uint8_t*)0x200000d1 = 0x14;
*(uint8_t*)0x200000d2 = 0x14;
*(uint8_t*)0x200000d3 = 0xaa;
*(uint32_t*)0x200000d4 = 0;
*(uint8_t*)0x200000d8 = 4;
*(uint8_t*)0x200000d9 = 0;
*(uint8_t*)0x200000da = 0;
*(uint32_t*)0x200000dc = 0;
*(uint32_t*)0x200000e0 = 0;
*(uint32_t*)0x200000e4 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x23, 0x20000000ul, 0xe8ul);
	return 0;
}
