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
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x200005c0;
*(uint32_t*)0x200005c0 = 0x50;
*(uint16_t*)0x200005c4 = 0x15;
*(uint16_t*)0x200005c6 = 0x203;
*(uint32_t*)0x200005c8 = 0;
*(uint32_t*)0x200005cc = 0;
*(uint32_t*)0x200005d0 = htobe32(0);
*(uint8_t*)0x200005e0 = 0xac;
*(uint8_t*)0x200005e1 = 0x14;
*(uint8_t*)0x200005e2 = 0x14;
*(uint8_t*)0x200005e3 = 0xbb;
*(uint16_t*)0x200005f0 = htobe16(0);
*(uint16_t*)0x200005f2 = htobe16(0);
*(uint16_t*)0x200005f4 = htobe16(0);
*(uint16_t*)0x200005f6 = htobe16(0);
*(uint16_t*)0x200005f8 = 0;
*(uint8_t*)0x200005fa = 0;
*(uint8_t*)0x200005fb = 0;
*(uint8_t*)0x200005fc = 0;
*(uint32_t*)0x20000600 = 0;
*(uint32_t*)0x20000604 = 0;
*(uint32_t*)0x20000608 = 0;
*(uint8_t*)0x2000060c = 0;
*(uint64_t*)0x200000c8 = 0x50;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000100ul, 0ul);
	return 0;
}