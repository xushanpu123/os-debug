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
*(uint64_t*)0x20006a00 = 0;
*(uint32_t*)0x20006a08 = 0;
*(uint64_t*)0x20006a10 = 0x20006980;
*(uint64_t*)0x20006980 = 0x20000080;
*(uint32_t*)0x20000080 = 0x14;
*(uint16_t*)0x20000084 = 0x66;
*(uint16_t*)0x20000086 = 0xc01;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint16_t*)0x20000090 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000092, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000093, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000093, 1, 7, 1);
*(uint64_t*)0x20006988 = 0x14;
*(uint64_t*)0x20006a18 = 1;
*(uint64_t*)0x20006a20 = 0;
*(uint64_t*)0x20006a28 = 0;
*(uint32_t*)0x20006a30 = 0;
	syscall(__NR_sendmsg, r[0], 0x20006a00ul, 0ul);
	return 0;
}
