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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000300 = 0;
*(uint32_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0x200002c0;
*(uint64_t*)0x200002c0 = 0x20000280;
*(uint32_t*)0x20000280 = 0x28;
*(uint8_t*)0x20000284 = 1;
*(uint8_t*)0x20000285 = 1;
*(uint16_t*)0x20000286 = 0x303;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint8_t*)0x20000290 = 0;
*(uint8_t*)0x20000291 = 0;
*(uint16_t*)0x20000292 = htobe16(0);
*(uint16_t*)0x20000294 = 0x14;
STORE_BY_BITMASK(uint16_t, , 0x20000296, 0x19, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000297, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000297, 1, 7, 1);
*(uint16_t*)0x20000298 = 8;
*(uint16_t*)0x2000029a = 2;
*(uint32_t*)0x2000029c = 0;
*(uint16_t*)0x200002a0 = 8;
*(uint16_t*)0x200002a2 = 1;
*(uint32_t*)0x200002a4 = 0x9fd;
*(uint64_t*)0x200002c8 = 0x28;
*(uint64_t*)0x20000318 = 1;
*(uint64_t*)0x20000320 = 0;
*(uint64_t*)0x20000328 = 0;
*(uint32_t*)0x20000330 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000300ul, 0ul);
	return 0;
}
