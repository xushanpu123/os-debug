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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000640 = 0x20000400;
*(uint16_t*)0x20000400 = 2;
*(uint16_t*)0x20000402 = htobe16(0x4e23);
*(uint32_t*)0x20000404 = htobe32(0);
*(uint32_t*)0x20000648 = 0x10;
*(uint64_t*)0x20000650 = 0;
*(uint64_t*)0x20000658 = 0;
*(uint64_t*)0x20000660 = 0;
*(uint64_t*)0x20000668 = 0;
*(uint32_t*)0x20000670 = 0;
*(uint32_t*)0x20000678 = 0;
*(uint64_t*)0x20000680 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e24);
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0xaa;
*(uint32_t*)0x20000688 = 0x10;
*(uint64_t*)0x20000690 = 0;
*(uint64_t*)0x20000698 = 0;
*(uint64_t*)0x200006a0 = 0x20000440;
*(uint64_t*)0x20000440 = 0x18;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 7;
*(uint8_t*)0x20000450 = 0x44;
*(uint8_t*)0x20000451 = 4;
*(uint8_t*)0x20000452 = 0x21;
STORE_BY_BITMASK(uint8_t, , 0x20000453, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000453, 0, 4, 4);
*(uint8_t*)0x20000454 = 0x44;
*(uint8_t*)0x20000455 = 4;
*(uint8_t*)0x20000456 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000457, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000457, 0, 4, 4);
*(uint64_t*)0x200006a8 = 0x18;
*(uint32_t*)0x200006b0 = 0;
*(uint32_t*)0x200006b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000640ul, 2ul, 0ul);
	return 0;
}
