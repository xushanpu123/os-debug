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
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0xfc;
*(uint16_t*)0x200001c4 = 0x1a;
*(uint16_t*)0x200001c6 = 1;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint8_t*)0x200001d0 = 0xfe;
*(uint8_t*)0x200001d1 = 0x80;
memset((void*)0x200001d2, 0, 13);
*(uint8_t*)0x200001df = 0xaa;
memset((void*)0x200001e0, 0, 10);
memset((void*)0x200001ea, 255, 2);
*(uint32_t*)0x200001ec = htobe32(0);
*(uint16_t*)0x200001f0 = htobe16(0);
*(uint16_t*)0x200001f2 = htobe16(0);
*(uint16_t*)0x200001f4 = htobe16(0);
*(uint16_t*)0x200001f6 = htobe16(0);
*(uint16_t*)0x200001f8 = 0;
*(uint8_t*)0x200001fa = 0;
*(uint8_t*)0x200001fb = 0;
*(uint8_t*)0x200001fc = 0;
*(uint32_t*)0x20000200 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint8_t*)0x20000208 = 0xfe;
*(uint8_t*)0x20000209 = 0x80;
memset((void*)0x2000020a, 0, 13);
*(uint8_t*)0x20000217 = 0xaa;
*(uint32_t*)0x20000218 = htobe32(0);
*(uint8_t*)0x2000021c = 0x2b;
*(uint8_t*)0x20000220 = 0xac;
*(uint8_t*)0x20000221 = 0x14;
*(uint8_t*)0x20000222 = 0x14;
*(uint8_t*)0x20000223 = 0xaa;
*(uint64_t*)0x20000230 = 0;
*(uint64_t*)0x20000238 = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint64_t*)0x20000270 = 0;
*(uint64_t*)0x20000278 = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint32_t*)0x20000290 = 0;
*(uint32_t*)0x20000294 = 0;
*(uint32_t*)0x20000298 = 0;
*(uint32_t*)0x2000029c = 0;
*(uint32_t*)0x200002a0 = 0;
*(uint16_t*)0x200002a4 = 2;
*(uint8_t*)0x200002a6 = 0;
*(uint8_t*)0x200002a7 = 0;
*(uint8_t*)0x200002a8 = 0;
*(uint16_t*)0x200002b0 = 0xc;
*(uint16_t*)0x200002b2 = 8;
*(uint16_t*)0x200002b4 = 8;
*(uint16_t*)0x200002b6 = 8;
*(uint8_t*)0x200002b8 = 0;
*(uint8_t*)0x200002b9 = 0;
*(uint16_t*)0x200002ba = 0;
*(uint64_t*)0x200000c8 = 0xfc;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
