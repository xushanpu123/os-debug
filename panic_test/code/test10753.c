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
*(uint8_t*)0x200000c0 = 0;
*(uint8_t*)0x200000c1 = 0;
*(uint8_t*)0x200000c2 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200000c3, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x200000c3, 0, 1, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000c3, 0, 3, 5);
*(uint32_t*)0x200000c4 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x39, 0x200000c0ul, 8ul);
	return 0;
}
