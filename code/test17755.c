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
*(uint64_t*)0x20004d80 = 0;
*(uint32_t*)0x20004d88 = 0;
*(uint64_t*)0x20004d90 = 0x20000280;
*(uint64_t*)0x20000280 = 0x20000cc0;
*(uint32_t*)0x20000cc0 = 0x14;
*(uint16_t*)0x20000cc4 = 0x2c;
*(uint16_t*)0x20000cc6 = 0x511f;
*(uint32_t*)0x20000cc8 = 0;
*(uint32_t*)0x20000ccc = 0;
*(uint16_t*)0x20000cd0 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000cd2, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000cd3, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000cd3, 1, 7, 1);
*(uint64_t*)0x20000288 = 0x14;
*(uint64_t*)0x20004d98 = 1;
*(uint64_t*)0x20004da0 = 0;
*(uint64_t*)0x20004da8 = 0;
*(uint32_t*)0x20004db0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20004d80ul, 0ul);
	return 0;
}
