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
*(uint64_t*)0x20000980 = 0;
*(uint32_t*)0x20000988 = 0;
*(uint64_t*)0x20000990 = 0x20000940;
*(uint64_t*)0x20000940 = 0x20000000;
*(uint32_t*)0x20000000 = 0x20;
*(uint16_t*)0x20000004 = 0x1e;
*(uint16_t*)0x20000006 = 0xa1f;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0;
*(uint8_t*)0x20000011 = 0;
*(uint16_t*)0x20000012 = 0;
*(uint16_t*)0x20000014 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000016, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 0, 7, 1);
*(uint16_t*)0x20000018 = 4;
STORE_BY_BITMASK(uint16_t, , 0x2000001a, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000001b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000001b, 0, 7, 1);
*(uint16_t*)0x2000001c = 4;
STORE_BY_BITMASK(uint16_t, , 0x2000001e, 7, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000001f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000001f, 1, 7, 1);
*(uint64_t*)0x20000948 = 0x20;
*(uint64_t*)0x20000998 = 1;
*(uint64_t*)0x200009a0 = 0;
*(uint64_t*)0x200009a8 = 0;
*(uint32_t*)0x200009b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000980ul, 0ul);
	return 0;
}
