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
*(uint64_t*)0x20000400 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint64_t*)0x20000410 = 0x200003c0;
*(uint64_t*)0x200003c0 = 0x20000440;
*(uint32_t*)0x20000440 = 0xc4;
*(uint16_t*)0x20000444 = 0x19;
*(uint16_t*)0x20000446 = 1;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint8_t*)0x20000450 = 0xac;
*(uint8_t*)0x20000451 = 0x14;
*(uint8_t*)0x20000452 = 0x14;
*(uint8_t*)0x20000453 = 0;
*(uint32_t*)0x20000460 = htobe32(-1);
*(uint16_t*)0x20000470 = htobe16(0);
*(uint16_t*)0x20000472 = htobe16(0);
*(uint16_t*)0x20000474 = htobe16(0);
*(uint16_t*)0x20000476 = htobe16(0);
*(uint16_t*)0x20000478 = 2;
*(uint8_t*)0x2000047a = 0;
*(uint8_t*)0x2000047b = 0;
*(uint8_t*)0x2000047c = 0;
*(uint32_t*)0x20000480 = 0;
*(uint32_t*)0x20000484 = 0;
*(uint64_t*)0x20000488 = 0;
*(uint64_t*)0x20000490 = 0;
*(uint64_t*)0x20000498 = 0;
*(uint64_t*)0x200004a0 = 0;
*(uint64_t*)0x200004a8 = 0;
*(uint64_t*)0x200004b0 = 0;
*(uint64_t*)0x200004b8 = 0;
*(uint64_t*)0x200004c0 = 0;
*(uint64_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0;
*(uint64_t*)0x200004d8 = 0;
*(uint64_t*)0x200004e0 = 0;
*(uint32_t*)0x200004e8 = 0;
*(uint32_t*)0x200004ec = 0;
*(uint8_t*)0x200004f0 = 0;
*(uint8_t*)0x200004f1 = 0;
*(uint8_t*)0x200004f2 = 0;
*(uint8_t*)0x200004f3 = 0;
*(uint16_t*)0x200004f8 = 0xc;
*(uint16_t*)0x200004fa = 8;
*(uint16_t*)0x200004fc = 0x59;
*(uint16_t*)0x200004fe = 8;
*(uint8_t*)0x20000500 = 0;
*(uint8_t*)0x20000501 = 0;
*(uint16_t*)0x20000502 = 0;
*(uint64_t*)0x200003c8 = 0xc4;
*(uint64_t*)0x20000418 = 1;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint32_t*)0x20000430 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000400ul, 0ul);
	return 0;
}