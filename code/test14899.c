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
memcpy((void*)0x20000000, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x101ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
STORE_BY_BITMASK(uint32_t, , 0x20000088, 0, 0, 1);
memcpy((void*)0x20000089, "queue1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x200000cc = 0;
memset((void*)0x200000d0, 0, 60);
	syscall(__NR_ioctl, r[0], 0xc08c5332, 0x20000080ul);
*(uint8_t*)0x20000340 = 0;
*(uint8_t*)0x20000341 = 0;
*(uint8_t*)0x20000342 = 0;
*(uint8_t*)0x20000343 = 0;
*(uint32_t*)0x20000344 = 0;
*(uint8_t*)0x2000034c = 0;
*(uint8_t*)0x2000034d = 0;
*(uint8_t*)0x2000034e = 0;
*(uint8_t*)0x2000034f = 0;
*(uint8_t*)0x20000350 = 0x40;
*(uint8_t*)0x20000351 = 0;
*(uint8_t*)0x20000352 = 0;
*(uint8_t*)0x20000353 = 0;
*(uint32_t*)0x20000354 = 0;
*(uint8_t*)0x2000035c = 0x20;
*(uint8_t*)0x2000035d = 0;
*(uint8_t*)0x2000035e = 0;
*(uint8_t*)0x2000035f = 9;
*(uint32_t*)0x20000360 = 0;
*(uint8_t*)0x20000368 = 0;
*(uint8_t*)0x20000369 = 0;
*(uint8_t*)0x2000036a = 0;
*(uint8_t*)0x2000036b = 0;
*(uint8_t*)0x2000036c = 0;
*(uint32_t*)0x20000370 = 0;
*(uint32_t*)0x20000374 = 0;
	syscall(__NR_write, r[0], 0x20000340ul, 0x38ul);
	return 0;
}
