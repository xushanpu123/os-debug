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
	syscall(__NR_fcntl, r[0], 4ul, 0x2800ul);
*(uint64_t*)0x200001c0 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000100;
*(uint32_t*)0x20000100 = 0x20;
*(uint8_t*)0x20000104 = 3;
*(uint8_t*)0x20000105 = 1;
*(uint16_t*)0x20000106 = 0x101;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint8_t*)0x20000110 = 0;
*(uint8_t*)0x20000111 = 0;
*(uint16_t*)0x20000112 = htobe16(0);
*(uint16_t*)0x20000114 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000116, 0x19, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000117, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000117, 1, 7, 1);
*(uint16_t*)0x20000118 = 8;
*(uint16_t*)0x2000011a = 1;
*(uint32_t*)0x2000011c = 0x800;
*(uint64_t*)0x20000188 = 0x20;
*(uint64_t*)0x200001d8 = 1;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200001c0ul, 0ul);
	return 0;
}