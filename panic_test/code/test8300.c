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
	res = syscall(__NR_socket, 2ul, 3ul, 0xff);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20003240 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint32_t*)0x20003248 = 0x10;
*(uint64_t*)0x20003250 = 0x20000540;
*(uint64_t*)0x20000540 = 0x200000c0;
memcpy((void*)0x200000c0, "\x3c\x0c\xf7\xb2\xa3\x59\x76\x68\xf9\x84\x2f\x01\x00\x00\xdb\xd0\xb3\xa9\xcc\xd5\x39\x95\xdc\x15\xb7\x35\xc6\xaf", 28);
*(uint64_t*)0x20000548 = 0x30;
*(uint64_t*)0x20003258 = 1;
*(uint64_t*)0x20003260 = 0x20000e00;
*(uint64_t*)0x20000e00 = 0x14;
*(uint32_t*)0x20000e08 = 0;
*(uint32_t*)0x20000e0c = 1;
*(uint32_t*)0x20000e10 = 0;
*(uint64_t*)0x20003268 = 0x18;
*(uint32_t*)0x20003270 = 0;
*(uint32_t*)0x20003278 = 0;
*(uint64_t*)0x20003280 = 0x20000700;
*(uint16_t*)0x20000700 = 2;
*(uint16_t*)0x20000702 = htobe16(0);
*(uint8_t*)0x20000704 = 0xac;
*(uint8_t*)0x20000705 = 0x14;
*(uint8_t*)0x20000706 = 0x14;
*(uint8_t*)0x20000707 = 0xbb;
*(uint32_t*)0x20003288 = 0x10;
*(uint64_t*)0x20003290 = 0x20001b40;
*(uint64_t*)0x20001b40 = 0x20000740;
memcpy((void*)0x20000740, "\xae\x7c\x81\x5b\x26\xb5\x5b\xdf\x2a\xff\xbd\x2d\x25\xcf\x27\x2f\x95\x61\xd2\xb4\x3f\xb4\xf6\xfb\xde\x8e\xc3\xc8\x48\xf4\x9b\x0f\x06\x37\x63\x8a\xec\x86\x51\x07\x31\x31\x0c\xbd\xbd\xe1\x7b\x2e\x48\xf9\xdd\x83\xed\x78\xf1\x07", 56);
*(uint64_t*)0x20001b48 = 0xffffffc0;
*(uint64_t*)0x20003298 = 1;
*(uint64_t*)0x200032a0 = 0;
*(uint64_t*)0x200032a8 = 0;
*(uint32_t*)0x200032b0 = 0;
*(uint32_t*)0x200032b8 = 0;
*(uint64_t*)0x200032c0 = 0x20001bc0;
*(uint16_t*)0x20001bc0 = 2;
*(uint16_t*)0x20001bc2 = htobe16(0);
*(uint32_t*)0x20001bc4 = htobe32(0);
*(uint32_t*)0x200032c8 = 0x10;
*(uint64_t*)0x200032d0 = 0x20000dc0;
*(uint64_t*)0x20000dc0 = 0x20001c00;
memcpy((void*)0x20001c00, "\xf3\x5d\x3e\x10\xdc\x77\xac\xa6\xeb\x3f\xc2\xbb\x1f\xb2\x71\xc6\xb3\x5c\x48\x44", 20);
*(uint64_t*)0x20000dc8 = 0x14;
*(uint64_t*)0x200032d8 = 1;
*(uint64_t*)0x200032e0 = 0;
*(uint64_t*)0x200032e8 = 0;
*(uint32_t*)0x200032f0 = 0;
*(uint32_t*)0x200032f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003240ul, 3ul, 0ul);
	return 0;
}
