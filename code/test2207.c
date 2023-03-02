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

*(uint32_t*)0x20000400 = 1;
*(uint32_t*)0x20000404 = 0x80;
*(uint8_t*)0x20000408 = 7;
*(uint8_t*)0x20000409 = 0;
*(uint8_t*)0x2000040a = 0;
*(uint8_t*)0x2000040b = 0;
*(uint32_t*)0x2000040c = 0;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0;
*(uint64_t*)0x20000420 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000428, 0, 38, 26);
*(uint32_t*)0x20000430 = 0;
*(uint32_t*)0x20000434 = 0;
*(uint64_t*)0x20000438 = 0;
*(uint64_t*)0x20000440 = 0;
*(uint64_t*)0x20000448 = 0;
*(uint64_t*)0x20000450 = 0;
*(uint32_t*)0x20000458 = 0;
*(uint32_t*)0x2000045c = 0;
*(uint64_t*)0x20000460 = 0;
*(uint32_t*)0x20000468 = 0;
*(uint16_t*)0x2000046c = 0;
*(uint16_t*)0x2000046e = 0;
*(uint32_t*)0x20000470 = 0;
*(uint32_t*)0x20000474 = 0;
*(uint64_t*)0x20000478 = 0;
	syscall(__NR_perf_event_open, 0x20000400ul, -1, 0ul, -1, 0ul);
	return 0;
}
