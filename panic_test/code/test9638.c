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
*(uint64_t*)0x200024c0 = 0;
*(uint32_t*)0x200024c8 = 0;
*(uint64_t*)0x200024d0 = 0x200017c0;
*(uint64_t*)0x200017c0 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x24;
*(uint16_t*)0x200000c4 = 0x2e;
*(uint16_t*)0x200000c6 = 0x401;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint16_t*)0x200000d0 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000d2, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000d3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000d3, 0, 7, 1);
*(uint32_t*)0x200000d4 = 3;
memcpy((void*)0x200000d8, "\x2a\xf3\x18\xa0\x7f\xd1\x01\xdd\xad\x77\x5a", 11);
*(uint64_t*)0x200017c8 = 0x24;
*(uint64_t*)0x200024d8 = 1;
*(uint64_t*)0x200024e0 = 0;
*(uint64_t*)0x200024e8 = 0;
*(uint32_t*)0x200024f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200024c0ul, 0ul);
	return 0;
}
