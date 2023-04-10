// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __NR_mlock2
#define __NR_mlock2 325
#endif

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000000, "/dev/vcsa#\000", 11);
syz_open_dev(0x20000000, 0, 0);
	syscall(__NR_mlock2, 0x20ff9000ul, 0x3000ul, 0ul);
*(uint32_t*)0x200001c0 = 7;
*(uint32_t*)0x200001c4 = 0x80;
*(uint8_t*)0x200001c8 = 0;
*(uint8_t*)0x200001c9 = 0;
*(uint8_t*)0x200001ca = 0;
*(uint8_t*)0x200001cb = 0;
*(uint32_t*)0x200001cc = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200001e8, 0, 38, 26);
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f4 = 0;
*(uint64_t*)0x200001f8 = 0x20000000;
*(uint64_t*)0x20000200 = 0;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0;
*(uint32_t*)0x20000218 = 0;
*(uint32_t*)0x2000021c = 0;
*(uint64_t*)0x20000220 = 0;
*(uint32_t*)0x20000228 = 0;
*(uint16_t*)0x2000022c = 0;
*(uint16_t*)0x2000022e = 0;
*(uint32_t*)0x20000230 = 0;
*(uint32_t*)0x20000234 = 0;
*(uint64_t*)0x20000238 = 0;
	syscall(__NR_perf_event_open, 0x200001c0ul, 0, 0ul, -1, 0ul);
	return 0;
}
