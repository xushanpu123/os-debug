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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 0;
*(uint16_t*)0x200000c8 = 0xa;
*(uint16_t*)0x200000ca = htobe16(0);
*(uint32_t*)0x200000cc = htobe32(0);
*(uint64_t*)0x200000d0 = htobe64(0);
*(uint64_t*)0x200000d8 = htobe64(1);
*(uint32_t*)0x200000e0 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 6;
*(uint16_t*)0x20000150 = 0xa;
*(uint16_t*)0x20000152 = htobe16(0);
*(uint32_t*)0x20000154 = htobe32(0);
*(uint8_t*)0x20000158 = 0xfc;
*(uint8_t*)0x20000159 = 2;
memset((void*)0x2000015a, 0, 13);
*(uint8_t*)0x20000167 = 0;
*(uint32_t*)0x20000168 = 0;
*(uint16_t*)0x200001d0 = 0xa;
*(uint16_t*)0x200001d2 = htobe16(0);
*(uint32_t*)0x200001d4 = htobe32(0);
*(uint64_t*)0x200001d8 = htobe64(0);
*(uint64_t*)0x200001e0 = htobe64(1);
*(uint32_t*)0x200001e8 = 0;
*(uint16_t*)0x20000250 = 0xa;
*(uint16_t*)0x20000252 = htobe16(0);
*(uint32_t*)0x20000254 = htobe32(0);
*(uint8_t*)0x20000258 = 0xfc;
*(uint8_t*)0x20000259 = 1;
memset((void*)0x2000025a, 0, 13);
*(uint8_t*)0x20000267 = 0;
*(uint32_t*)0x20000268 = 0;
*(uint16_t*)0x200002d0 = 0xa;
*(uint16_t*)0x200002d2 = htobe16(0);
*(uint32_t*)0x200002d4 = htobe32(0);
memcpy((void*)0x200002d8, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200002e8 = 0;
*(uint16_t*)0x20000350 = 0xa;
*(uint16_t*)0x20000352 = htobe16(0);
*(uint32_t*)0x20000354 = htobe32(0);
*(uint8_t*)0x20000358 = 0xfe;
*(uint8_t*)0x20000359 = 0x80;
memset((void*)0x2000035a, 0, 13);
*(uint8_t*)0x20000367 = 0;
*(uint32_t*)0x20000368 = 0;
*(uint16_t*)0x200003d0 = 0xa;
*(uint16_t*)0x200003d2 = htobe16(0);
*(uint32_t*)0x200003d4 = htobe32(0);
memcpy((void*)0x200003d8, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\001", 16);
*(uint32_t*)0x200003e8 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x30, 0x200000c0ul, 0xffd8ul);
	return 0;
}