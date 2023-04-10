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

*(uint32_t*)0x20000240 = 0;
*(uint32_t*)0x20000244 = 0x80;
*(uint8_t*)0x20000248 = 0;
*(uint8_t*)0x20000249 = 0;
*(uint8_t*)0x2000024a = 0;
*(uint8_t*)0x2000024b = 0;
*(uint32_t*)0x2000024c = 0;
*(uint64_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 1, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000268, 0, 38, 26);
*(uint32_t*)0x20000270 = 0;
*(uint32_t*)0x20000274 = 0;
*(uint64_t*)0x20000278 = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint32_t*)0x20000298 = 0;
*(uint32_t*)0x2000029c = 0;
*(uint64_t*)0x200002a0 = 0;
*(uint32_t*)0x200002a8 = 0;
*(uint16_t*)0x200002ac = 0;
*(uint16_t*)0x200002ae = 0;
*(uint32_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b4 = 0;
*(uint64_t*)0x200002b8 = 0;
	syscall(__NR_perf_event_open, 0x20000240ul, -1, 0ul, -1, 0ul);
	return 0;
}
