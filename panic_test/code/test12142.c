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
*(uint64_t*)0x20000090 = 0x20001340;
*(uint64_t*)0x20001340 = 0x200008c0;
*(uint32_t*)0x200008c0 = 0x18;
*(uint16_t*)0x200008c4 = 0x12;
*(uint16_t*)0x200008c6 = 1;
*(uint32_t*)0x200008c8 = 0;
*(uint32_t*)0x200008cc = 0;
*(uint16_t*)0x200008d0 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200008d2, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200008d3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200008d3, 0, 7, 1);
*(uint32_t*)0x200008d4 = 0;
*(uint64_t*)0x20001348 = 0x18;
*(uint64_t*)0x20000098 = 1;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000080ul, 0ul);
	return 0;
}
