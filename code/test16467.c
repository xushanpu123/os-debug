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
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0x20000180;
*(uint64_t*)0x20000180 = 0x200004c0;
*(uint32_t*)0x200004c0 = 0x148;
*(uint16_t*)0x200004c4 = 0x1a;
*(uint16_t*)0x200004c6 = 1;
*(uint32_t*)0x200004c8 = 0;
*(uint32_t*)0x200004cc = 0;
*(uint8_t*)0x200004d0 = -1;
*(uint8_t*)0x200004d1 = 2;
memset((void*)0x200004d2, 0, 13);
*(uint8_t*)0x200004df = 1;
*(uint32_t*)0x200004e0 = htobe32(0);
*(uint16_t*)0x200004f0 = htobe16(0);
*(uint16_t*)0x200004f2 = htobe16(0);
*(uint16_t*)0x200004f4 = htobe16(0);
*(uint16_t*)0x200004f6 = htobe16(0);
*(uint16_t*)0x200004f8 = 0;
*(uint8_t*)0x200004fa = 0;
*(uint8_t*)0x200004fb = 0;
*(uint8_t*)0x200004fc = 0;
*(uint32_t*)0x20000500 = 0;
*(uint32_t*)0x20000504 = 0xee00;
memset((void*)0x20000508, 0, 10);
memset((void*)0x20000512, 255, 2);
*(uint32_t*)0x20000514 = htobe32(0);
*(uint32_t*)0x20000518 = htobe32(0);
*(uint8_t*)0x2000051c = 0x32;
*(uint8_t*)0x20000520 = 0xac;
*(uint8_t*)0x20000521 = 0x14;
*(uint8_t*)0x20000522 = 0x14;
*(uint8_t*)0x20000523 = 0;
*(uint64_t*)0x20000530 = 0;
*(uint64_t*)0x20000538 = 0;
*(uint64_t*)0x20000540 = 0;
*(uint64_t*)0x20000548 = 0;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint64_t*)0x20000570 = 0;
*(uint64_t*)0x20000578 = 0;
*(uint64_t*)0x20000580 = 0;
*(uint64_t*)0x20000588 = 0;
*(uint32_t*)0x20000590 = 0;
*(uint32_t*)0x20000594 = 0;
*(uint32_t*)0x20000598 = 0;
*(uint32_t*)0x2000059c = 0;
*(uint32_t*)0x200005a0 = 0;
*(uint16_t*)0x200005a4 = 2;
*(uint8_t*)0x200005a6 = 0;
*(uint8_t*)0x200005a7 = 0;
*(uint8_t*)0x200005a8 = 0;
*(uint16_t*)0x200005b0 = 0x4c;
*(uint16_t*)0x200005b2 = 0x12;
memcpy((void*)0x200005b4, "rfc7539esp(fpu(pcbc(aes)),sha3-512-generic)\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x200005f4 = 0;
*(uint32_t*)0x200005f8 = 0;
*(uint16_t*)0x200005fc = 0xc;
*(uint16_t*)0x200005fe = 8;
*(uint16_t*)0x20000600 = 8;
*(uint16_t*)0x20000602 = 8;
*(uint8_t*)0x20000604 = 0;
*(uint8_t*)0x20000605 = 0;
*(uint16_t*)0x20000606 = 0xff19;
*(uint64_t*)0x20000188 = 0x148;
*(uint64_t*)0x20000058 = 1;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint32_t*)0x20000070 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000040ul, 0ul);
	return 0;
}
