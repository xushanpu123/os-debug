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
*(uint64_t*)0x20000a80 = 0;
*(uint32_t*)0x20000a88 = 0;
*(uint64_t*)0x20000a90 = 0x20000a40;
*(uint64_t*)0x20000a40 = 0x20000040;
*(uint32_t*)0x20000040 = 0x18;
*(uint8_t*)0x20000044 = 3;
*(uint8_t*)0x20000045 = 1;
*(uint16_t*)0x20000046 = 0x101;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint8_t*)0x20000050 = 0;
*(uint8_t*)0x20000051 = 0;
*(uint16_t*)0x20000052 = htobe16(0);
*(uint16_t*)0x20000054 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000056, 0x19, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 1, 7, 1);
*(uint64_t*)0x20000a48 = 0x18;
*(uint64_t*)0x20000a98 = 1;
*(uint64_t*)0x20000aa0 = 0;
*(uint64_t*)0x20000aa8 = 0;
*(uint32_t*)0x20000ab0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000a80ul, 0ul);
	return 0;
}
