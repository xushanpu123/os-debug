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
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0x20000040;
*(uint64_t*)0x20000040 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x24;
*(uint16_t*)0x200000c4 = 0x19;
*(uint16_t*)0x200000c6 = 1;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint8_t*)0x200000d0 = 0xa;
*(uint8_t*)0x200000d1 = 0;
*(uint16_t*)0x200000d2 = 0;
*(uint16_t*)0x200000d4 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000d6, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000d7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000d7, 0, 7, 1);
*(uint32_t*)0x200000d8 = 0;
*(uint16_t*)0x200000dc = 6;
STORE_BY_BITMASK(uint16_t, , 0x200000de, 0x15, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000df, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000df, 1, 7, 1);
memcpy((void*)0x200000e0, "eN", 2);
*(uint64_t*)0x20000048 = 0x24;
*(uint64_t*)0x20000098 = 1;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000080ul, 0ul);
	return 0;
}