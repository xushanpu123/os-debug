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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0x20000280;
*(uint64_t*)0x20000280 = 0x20000200;
*(uint32_t*)0x20000200 = 0x18;
*(uint16_t*)0x20000204 = 0;
*(uint16_t*)0x20000206 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint8_t*)0x20000210 = 2;
*(uint8_t*)0x20000211 = 0;
*(uint16_t*)0x20000212 = 0;
*(uint16_t*)0x20000214 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000216, 7, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 1, 7, 1);
*(uint64_t*)0x20000288 = 0x18;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200002c0ul, 0ul);
*(uint64_t*)0x20000100 = 0x20ffe000;
*(uint64_t*)0x20000108 = 0x20fff000;
*(uint64_t*)0x20000110 = 0x20fff000;
*(uint64_t*)0x20000118 = 0x20ffa000;
*(uint64_t*)0x20000120 = 0x20ff9000;
*(uint64_t*)0x20000128 = 0x20ffe000;
	syscall(__NR_move_pages, 0, 0x200000000000013aul, 0x20000100ul, 0ul, 0x20000140ul, 0ul);
	return 0;
}