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
*(uint64_t*)0x200000c0 = 0x200002c0;
*(uint32_t*)0x200002c0 = 0x138;
*(uint16_t*)0x200002c4 = 0x1a;
*(uint16_t*)0x200002c6 = 1;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
*(uint8_t*)0x200002d0 = 0xfc;
*(uint8_t*)0x200002d1 = 1;
memset((void*)0x200002d2, 0, 13);
*(uint8_t*)0x200002df = 0;
*(uint8_t*)0x200002e0 = 0xfe;
*(uint8_t*)0x200002e1 = 0x88;
memset((void*)0x200002e2, 0, 12);
*(uint8_t*)0x200002ee = 0;
*(uint8_t*)0x200002ef = 1;
*(uint16_t*)0x200002f0 = htobe16(0);
*(uint16_t*)0x200002f2 = htobe16(0);
*(uint16_t*)0x200002f4 = htobe16(0);
*(uint16_t*)0x200002f6 = htobe16(0);
*(uint16_t*)0x200002f8 = 0;
*(uint8_t*)0x200002fa = 0;
*(uint8_t*)0x200002fb = 0;
*(uint8_t*)0x200002fc = 0;
*(uint32_t*)0x20000300 = 0;
*(uint32_t*)0x20000304 = 0;
*(uint8_t*)0x20000308 = 0xfe;
*(uint8_t*)0x20000309 = 0x80;
memset((void*)0x2000030a, 0, 13);
*(uint8_t*)0x20000317 = 0xaa;
*(uint32_t*)0x20000318 = htobe32(0);
*(uint8_t*)0x2000031c = 0x3c;
*(uint8_t*)0x20000320 = 0xac;
*(uint8_t*)0x20000321 = 0x14;
*(uint8_t*)0x20000322 = 0x14;
*(uint8_t*)0x20000323 = 0xaa;
*(uint64_t*)0x20000330 = 0;
*(uint64_t*)0x20000338 = 0;
*(uint64_t*)0x20000340 = 0;
*(uint64_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0;
*(uint64_t*)0x20000358 = 0;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint64_t*)0x20000370 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint32_t*)0x20000390 = 0;
*(uint32_t*)0x20000394 = 0;
*(uint32_t*)0x20000398 = 0;
*(uint32_t*)0x2000039c = 0;
*(uint32_t*)0x200003a0 = 0;
*(uint16_t*)0x200003a4 = 0xa;
*(uint8_t*)0x200003a6 = 0;
*(uint8_t*)0x200003a7 = 0;
*(uint8_t*)0x200003a8 = 0;
*(uint16_t*)0x200003b0 = 0x48;
*(uint16_t*)0x200003b2 = 2;
memcpy((void*)0x200003b4, "xts-camellia-aesni\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x200003f4 = 0;
*(uint64_t*)0x200000c8 = 0x138;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000180ul, 0ul);
	return 0;
}
