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
*(uint32_t*)0x20000200 = 4;
*(uint32_t*)0x20000204 = 0x80;
*(uint8_t*)0x20000208 = 0;
*(uint8_t*)0x20000209 = 0;
*(uint8_t*)0x2000020a = 0;
*(uint8_t*)0x2000020b = 0;
*(uint32_t*)0x2000020c = 0;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0;
*(uint64_t*)0x20000220 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 38, 26);
*(uint32_t*)0x20000230 = 0;
*(uint32_t*)0x20000234 = 0;
*(uint64_t*)0x20000238 = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0;
*(uint32_t*)0x20000258 = 0;
*(uint32_t*)0x2000025c = 0;
*(uint64_t*)0x20000260 = 0;
*(uint32_t*)0x20000268 = 0;
*(uint16_t*)0x2000026c = 0;
*(uint16_t*)0x2000026e = 0;
*(uint32_t*)0x20000270 = 0;
*(uint32_t*)0x20000274 = 0;
*(uint64_t*)0x20000278 = 0;
	syscall(__NR_perf_event_open, 0x20000200ul, -1, 0ul, -1, 0ul);
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20001380 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20001380ul, 4ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint32_t*)0x20000040 = 8;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 2;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 4;
*(uint32_t*)0x20000054 = 0;
*(uint32_t*)0x20000058 = 2;
*(uint32_t*)0x2000005c = 0;
*(uint32_t*)0x20000060 = 4;
*(uint32_t*)0x20000064 = 0;
*(uint32_t*)0x20000068 = 3;
*(uint16_t*)0x2000006c = 0;
*(uint16_t*)0x2000006e = 0;
*(uint32_t*)0x20000070 = 2;
*(uint32_t*)0x20000074 = 0;
*(uint32_t*)0x20000078 = 8;
*(uint32_t*)0x2000007c = 0;
	syscall(__NR_setsockopt, r[0], 6, 0x16, 0x20000040ul, 0x2000000000000247ul);
	return 0;
}
