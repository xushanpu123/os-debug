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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000100 = 1;
*(uint32_t*)0x20000104 = 0x80;
*(uint8_t*)0x20000108 = 0;
*(uint8_t*)0x20000109 = 0;
*(uint8_t*)0x2000010a = 0;
*(uint8_t*)0x2000010b = 0;
*(uint32_t*)0x2000010c = 0;
*(uint64_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 1;
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000128, 0, 38, 26);
*(uint32_t*)0x20000130 = 0xfffffffe;
*(uint32_t*)0x20000134 = 0;
*(uint64_t*)0x20000138 = 6;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint32_t*)0x20000158 = 0;
*(uint32_t*)0x2000015c = 0;
*(uint64_t*)0x20000160 = 0;
*(uint32_t*)0x20000168 = 0;
*(uint16_t*)0x2000016c = 0;
*(uint16_t*)0x2000016e = 0;
*(uint32_t*)0x20000170 = 0;
*(uint32_t*)0x20000174 = 0;
*(uint64_t*)0x20000178 = 0;
	res = syscall(__NR_perf_event_open, 0x20000100ul, 0, 0ul, -1, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_mmap, 0x20ffc000ul, 0x4000ul, 0x2000001ul, 0x4010ul, r[0], 0xffful);
memcpy((void*)0x20000080, "blkio.bfq.sectors\000", 18);
	res = syscall(__NR_openat, r[0], 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x200000c0, "/dev/zero\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200000c0ul, 0x80000ul, 0ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_ioctl, r[1], 0x2405, r[2]);
memcpy((void*)0x20000280, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000280ul, 0ul, 0ul);
	if (res != -1)
		r[3] = res;
	syscall(__NR_ioctl, r[3], 0x4c82, 0);
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x101000ul, 0ul);
	return 0;
}
