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
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000000;
*(uint64_t*)0x20000000 = 0x20001700;
*(uint32_t*)0x20001700 = 0x30;
*(uint16_t*)0x20001704 = 0x26;
*(uint16_t*)0x20001706 = 0x9683;
*(uint32_t*)0x20001708 = 0;
*(uint32_t*)0x2000170c = 0;
*(uint16_t*)0x20001710 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20001712, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001713, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001713, 0, 7, 1);
*(uint64_t*)0x20001714 = 0;
*(uint16_t*)0x2000171c = 4;
STORE_BY_BITMASK(uint16_t, , 0x2000171e, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000171f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000171f, 1, 7, 1);
*(uint16_t*)0x20001720 = 0xd;
STORE_BY_BITMASK(uint16_t, , 0x20001722, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001723, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001723, 1, 7, 1);
*(uint16_t*)0x20001724 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20001726, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001727, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001727, 0, 7, 1);
*(uint32_t*)0x20001728 = -1;
memset((void*)0x2000172c, 238, 1);
*(uint64_t*)0x20000008 = 0x30;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 0ul);
	return 0;
}