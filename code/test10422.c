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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20000040;
*(uint32_t*)0x20000040 = 0x38;
*(uint8_t*)0x20000044 = 0;
*(uint8_t*)0x20000045 = 1;
*(uint16_t*)0x20000046 = 5;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint8_t*)0x20000050 = 2;
*(uint8_t*)0x20000051 = 0;
*(uint16_t*)0x20000052 = htobe16(0);
*(uint16_t*)0x20000054 = 0x24;
STORE_BY_BITMASK(uint16_t, , 0x20000056, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 1, 7, 1);
*(uint16_t*)0x20000058 = 0x14;
STORE_BY_BITMASK(uint16_t, , 0x2000005a, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000005b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000005b, 1, 7, 1);
*(uint16_t*)0x2000005c = 8;
*(uint16_t*)0x2000005e = 1;
*(uint8_t*)0x20000060 = 0xac;
*(uint8_t*)0x20000061 = 0x1e;
*(uint8_t*)0x20000062 = 0;
*(uint8_t*)0x20000063 = 1;
*(uint16_t*)0x20000064 = 8;
*(uint16_t*)0x20000066 = 2;
*(uint32_t*)0x20000068 = htobe32(-1);
*(uint16_t*)0x2000006c = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000006e, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000006f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000006f, 1, 7, 1);
*(uint16_t*)0x20000070 = 1;
*(uint16_t*)0x20000072 = 1;
*(uint8_t*)0x20000074 = 0;
*(uint16_t*)0x20000078 = 0;
STORE_BY_BITMASK(uint16_t, , 0x2000007a, 3, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000007b, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000007b, 0, 7, 1);
*(uint16_t*)0x2000007c = htobe16(0);
*(uint64_t*)0x20000108 = 0x38;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0ul);
	return 0;
}