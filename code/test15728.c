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
*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0x20000240;
*(uint64_t*)0x20000240 = 0x20000440;
*(uint32_t*)0x20000440 = 0x38;
*(uint8_t*)0x20000444 = 1;
*(uint8_t*)0x20000445 = 1;
*(uint16_t*)0x20000446 = 0x101;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint8_t*)0x20000450 = 2;
*(uint8_t*)0x20000451 = 0;
*(uint16_t*)0x20000452 = htobe16(0);
*(uint16_t*)0x20000454 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000456, 0x19, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 1, 7, 1);
*(uint16_t*)0x20000458 = 8;
*(uint16_t*)0x2000045a = 1;
*(uint32_t*)0x2000045c = 0x401;
*(uint16_t*)0x20000460 = 0x18;
STORE_BY_BITMASK(uint16_t, , 0x20000462, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000463, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000463, 1, 7, 1);
*(uint16_t*)0x20000464 = 0x14;
STORE_BY_BITMASK(uint16_t, , 0x20000466, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000467, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000467, 1, 7, 1);
*(uint16_t*)0x20000468 = 8;
*(uint16_t*)0x2000046a = 1;
*(uint32_t*)0x2000046c = htobe32(-1);
*(uint16_t*)0x20000470 = 8;
*(uint16_t*)0x20000472 = 2;
*(uint8_t*)0x20000474 = 0xac;
*(uint8_t*)0x20000475 = 0x14;
*(uint8_t*)0x20000476 = 0x14;
*(uint8_t*)0x20000477 = 0xaa;
*(uint64_t*)0x20000248 = 0x38;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}
