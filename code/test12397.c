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
*(uint64_t*)0x20007640 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x20007648 = 0xc;
*(uint64_t*)0x20007650 = 0x20007580;
*(uint64_t*)0x20007580 = 0x20000180;
*(uint32_t*)0x20000180 = 0x20;
*(uint16_t*)0x20000184 = 0x1d;
*(uint16_t*)0x20000186 = 0x801;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint16_t*)0x20000190 = 0xd;
STORE_BY_BITMASK(uint16_t, , 0x20000192, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000193, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000193, 1, 7, 1);
memcpy((void*)0x20000194, "\xcd\xb6\x12\x26\x63\x50\xe2\x68\xd4", 9);
*(uint64_t*)0x20007588 = 0x20;
*(uint64_t*)0x20007590 = 0x20001140;
*(uint32_t*)0x20001140 = 0x18;
*(uint16_t*)0x20001144 = 0x25;
*(uint16_t*)0x20001146 = 1;
*(uint32_t*)0x20001148 = 0;
*(uint32_t*)0x2000114c = 0;
*(uint16_t*)0x20001150 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20001152, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001153, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001153, 0, 7, 1);
*(uint8_t*)0x20001154 = 0xac;
*(uint8_t*)0x20001155 = 0x14;
*(uint8_t*)0x20001156 = 0x14;
*(uint8_t*)0x20001157 = 0xbb;
*(uint64_t*)0x20007598 = 0x18;
*(uint64_t*)0x20007658 = 2;
*(uint64_t*)0x20007660 = 0;
*(uint64_t*)0x20007668 = 0;
*(uint32_t*)0x20007670 = 0;
	syscall(__NR_sendmsg, r[0], 0x20007640ul, 0ul);
	return 0;
}
