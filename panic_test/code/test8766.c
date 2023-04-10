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

*(uint32_t*)0x20000340 = 0;
*(uint32_t*)0x20000344 = 0x80;
*(uint8_t*)0x20000348 = 0;
*(uint8_t*)0x20000349 = 0;
*(uint8_t*)0x2000034a = 0;
*(uint8_t*)0x2000034b = 0;
*(uint32_t*)0x2000034c = 0;
*(uint64_t*)0x20000350 = 0;
*(uint64_t*)0x20000358 = 0x130;
*(uint64_t*)0x20000360 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 1, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 1, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 1, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000368, 0, 38, 26);
*(uint32_t*)0x20000370 = 0;
*(uint32_t*)0x20000374 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint32_t*)0x20000398 = 0;
*(uint32_t*)0x2000039c = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint32_t*)0x200003a8 = 0;
*(uint16_t*)0x200003ac = 0xff;
*(uint16_t*)0x200003ae = 0;
*(uint32_t*)0x200003b0 = 0;
*(uint32_t*)0x200003b4 = 0;
*(uint64_t*)0x200003b8 = 0;
	syscall(__NR_perf_event_open, 0x20000340ul, -1, 0ul, -1, 0ul);
	return 0;
}
