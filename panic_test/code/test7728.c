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
*(uint32_t*)0x20000040 = 5;
*(uint32_t*)0x20000044 = 0x80;
*(uint8_t*)0x20000048 = 0;
*(uint8_t*)0x20000049 = 0;
*(uint8_t*)0x2000004a = 0;
*(uint8_t*)0x2000004b = 0;
*(uint32_t*)0x2000004c = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 38, 26);
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 2;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 2;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x2000009c = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint32_t*)0x200000a8 = 0;
*(uint16_t*)0x200000ac = 0;
*(uint16_t*)0x200000ae = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint64_t*)0x200000b8 = 0;
	res = syscall(__NR_perf_event_open, 0x20000040ul, 0, 0ul, -1, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x2401, 0ul);
*(uint32_t*)0x20000140 = 5;
*(uint32_t*)0x20000144 = 0x80;
*(uint8_t*)0x20000148 = 0;
*(uint8_t*)0x20000149 = 0;
*(uint8_t*)0x2000014a = 0;
*(uint8_t*)0x2000014b = 0;
*(uint32_t*)0x2000014c = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000168, 0, 38, 26);
*(uint32_t*)0x20000170 = 0;
*(uint32_t*)0x20000174 = 2;
*(uint64_t*)0x20000178 = 0;
*(uint64_t*)0x20000180 = 4;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint32_t*)0x20000198 = 0;
*(uint32_t*)0x2000019c = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint32_t*)0x200001a8 = 0;
*(uint16_t*)0x200001ac = 0;
*(uint16_t*)0x200001ae = 0;
*(uint32_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b4 = 0;
*(uint64_t*)0x200001b8 = 0;
	syscall(__NR_ioctl, r[0], 0x4008240b, 0x20000140ul);
	return 0;
}
