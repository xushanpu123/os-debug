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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200019c0 = 0;
*(uint32_t*)0x200019c8 = 0;
*(uint64_t*)0x200019d0 = 0x2000da80;
*(uint64_t*)0x2000da80 = 0x2000b2c0;
*(uint32_t*)0x2000b2c0 = 0x50;
*(uint16_t*)0x2000b2c4 = 0x14;
*(uint16_t*)0x2000b2c6 = 1;
*(uint32_t*)0x2000b2c8 = 0;
*(uint32_t*)0x2000b2cc = 0;
*(uint16_t*)0x2000b2d0 = 0x3d;
STORE_BY_BITMASK(uint16_t, , 0x2000b2d2, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000b2d3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000b2d3, 1, 7, 1);
*(uint16_t*)0x2000b2d4 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000b2d6, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000b2d7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000b2d7, 0, 7, 1);
*(uint64_t*)0x2000b2d8 = 0;
*(uint16_t*)0x2000b2e0 = 5;
STORE_BY_BITMASK(uint16_t, , 0x2000b2e2, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000b2e3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000b2e3, 0, 7, 1);
memset((void*)0x2000b2e4, 0, 1);
memcpy((void*)0x2000b2e8, "\x0c\x74\xc5\x8d\x94\x9e\x9a\x93\xcd\xcd\xf8\xa1\xf2\x40\x5e\x59\xa9\x8d\xad\xaf\x60\xb0\xce\x4b\xd0\x97\x97\x10\x8d\xb1\xc3\xfc\x9b\x8e\x46\xeb\xc4", 37);
*(uint64_t*)0x2000da88 = 0x50;
*(uint64_t*)0x200019d8 = 1;
*(uint64_t*)0x200019e0 = 0;
*(uint64_t*)0x200019e8 = 0;
*(uint32_t*)0x200019f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200019c0ul, 0ul);
	return 0;
}
