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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20009100 = 0;
*(uint32_t*)0x20009108 = 0;
*(uint64_t*)0x20009110 = 0x20001d80;
*(uint64_t*)0x20001d80 = 0x20000040;
*(uint32_t*)0x20000040 = 0x20;
*(uint16_t*)0x20000044 = 0x1c;
*(uint16_t*)0x20000046 = 0x9355;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint16_t*)0x20000050 = 7;
STORE_BY_BITMASK(uint16_t, , 0x20000052, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000053, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000053, 1, 7, 1);
memcpy((void*)0x20000054, "\x75\x9e\x77", 3);
*(uint16_t*)0x20000058 = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000005a, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000005b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000005b, 0, 7, 1);
*(uint32_t*)0x2000005c = 0;
*(uint64_t*)0x20001d88 = 0x20;
*(uint64_t*)0x20009118 = 1;
*(uint64_t*)0x20009120 = 0;
*(uint64_t*)0x20009128 = 0;
*(uint32_t*)0x20009130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20009100ul, 0ul);
	return 0;
}
