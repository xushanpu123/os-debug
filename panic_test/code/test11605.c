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
*(uint64_t*)0x20000280 = 0x20000440;
*(uint32_t*)0x20000440 = 0x184;
*(uint16_t*)0x20000444 = 0x1a;
*(uint16_t*)0x20000446 = 1;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint8_t*)0x20000450 = 0xac;
*(uint8_t*)0x20000451 = 0x1e;
*(uint8_t*)0x20000452 = 0;
*(uint8_t*)0x20000453 = 1;
*(uint8_t*)0x20000460 = 0xac;
*(uint8_t*)0x20000461 = 0x14;
*(uint8_t*)0x20000462 = 0x14;
*(uint8_t*)0x20000463 = 0;
*(uint16_t*)0x20000470 = htobe16(0);
*(uint16_t*)0x20000472 = htobe16(0);
*(uint16_t*)0x20000474 = htobe16(0);
*(uint16_t*)0x20000476 = htobe16(0);
*(uint16_t*)0x20000478 = 0;
*(uint8_t*)0x2000047a = 0;
*(uint8_t*)0x2000047b = 0;
*(uint8_t*)0x2000047c = 0;
*(uint32_t*)0x20000480 = 0;
*(uint32_t*)0x20000484 = 0;
*(uint8_t*)0x20000488 = 0xfe;
*(uint8_t*)0x20000489 = 0x88;
memset((void*)0x2000048a, 0, 12);
*(uint8_t*)0x20000496 = 0;
*(uint8_t*)0x20000497 = 1;
*(uint32_t*)0x20000498 = htobe32(0);
*(uint8_t*)0x2000049c = 0x32;
memcpy((void*)0x200004a0, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint64_t*)0x200004b0 = 0;
*(uint64_t*)0x200004b8 = 0;
*(uint64_t*)0x200004c0 = 0;
*(uint64_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0;
*(uint64_t*)0x200004d8 = 0;
*(uint64_t*)0x200004e0 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint64_t*)0x200004f0 = 0;
*(uint64_t*)0x200004f8 = 0;
*(uint64_t*)0x20000500 = 0;
*(uint64_t*)0x20000508 = 0;
*(uint32_t*)0x20000510 = 0;
*(uint32_t*)0x20000514 = 0;
*(uint32_t*)0x20000518 = 0;
*(uint32_t*)0x2000051c = 0;
*(uint32_t*)0x20000520 = 0;
*(uint16_t*)0x20000524 = 0xa;
*(uint8_t*)0x20000526 = 0;
*(uint8_t*)0x20000527 = 0;
*(uint8_t*)0x20000528 = 0;
*(uint16_t*)0x20000530 = 0x48;
*(uint16_t*)0x20000532 = 1;
memcpy((void*)0x20000534, "sha3-512-ce\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x20000574 = 0;
*(uint16_t*)0x20000578 = 0x4c;
*(uint16_t*)0x2000057a = 0x12;
memcpy((void*)0x2000057c, "aegis128-generic\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x200005bc = 0;
*(uint32_t*)0x200005c0 = 0;
*(uint64_t*)0x20000288 = 0x184;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}
