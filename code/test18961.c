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
*(uint64_t*)0x20000940 = 0x200009c0;
*(uint32_t*)0x200009c0 = 0x24;
*(uint16_t*)0x200009c4 = 0x11;
*(uint16_t*)0x200009c6 = 0xa1f;
*(uint32_t*)0x200009c8 = 0;
*(uint32_t*)0x200009cc = 0;
*(uint8_t*)0x200009d0 = 0;
*(uint8_t*)0x200009d1 = 0;
*(uint16_t*)0x200009d2 = 0;
*(uint16_t*)0x200009d4 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200009d6, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200009d7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200009d7, 0, 7, 1);
*(uint32_t*)0x200009d8 = 0;
*(uint16_t*)0x200009dc = 4;
STORE_BY_BITMASK(uint16_t, , 0x200009de, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200009df, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200009df, 1, 7, 1);
*(uint16_t*)0x200009e0 = 4;
STORE_BY_BITMASK(uint16_t, , 0x200009e2, 0x36, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200009e3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200009e3, 1, 7, 1);
*(uint64_t*)0x20000948 = 0x24;
*(uint64_t*)0x20000998 = 1;
*(uint64_t*)0x200009a0 = 0;
*(uint64_t*)0x200009a8 = 0;
*(uint32_t*)0x200009b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000980ul, 0ul);
	return 0;
}
