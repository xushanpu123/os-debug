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

*(uint32_t*)0x200002c0 = 2;
*(uint32_t*)0x200002c4 = 0x80;
*(uint8_t*)0x200002c8 = 0x98;
*(uint8_t*)0x200002c9 = 0;
*(uint8_t*)0x200002ca = 0;
*(uint8_t*)0x200002cb = 0;
*(uint32_t*)0x200002cc = 0;
*(uint64_t*)0x200002d0 = 0;
*(uint64_t*)0x200002d8 = 0;
*(uint64_t*)0x200002e0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200002e8, 0, 38, 26);
*(uint32_t*)0x200002f0 = 0;
*(uint32_t*)0x200002f4 = 0;
*(uint64_t*)0x200002f8 = 0;
*(uint64_t*)0x20000300 = 0;
*(uint64_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0;
*(uint32_t*)0x20000318 = 0;
*(uint32_t*)0x2000031c = 6;
*(uint64_t*)0x20000320 = 0;
*(uint32_t*)0x20000328 = 0;
*(uint16_t*)0x2000032c = 0;
*(uint16_t*)0x2000032e = 0;
*(uint32_t*)0x20000330 = 0;
*(uint32_t*)0x20000334 = 0;
*(uint64_t*)0x20000338 = 0;
	syscall(__NR_perf_event_open, 0x200002c0ul, 0, 0ul, -1, 0ul);
	syscall(__NR_msgget, 0x798e2635ul, 0ul);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	return 0;
}
