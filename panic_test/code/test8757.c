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
*(uint64_t*)0x20000fc0 = 0;
*(uint32_t*)0x20000fc8 = 0;
*(uint64_t*)0x20000fd0 = 0x20000400;
*(uint64_t*)0x20000400 = 0x20000440;
*(uint32_t*)0x20000440 = 0x24;
*(uint16_t*)0x20000444 = 0x11;
*(uint16_t*)0x20000446 = 0xc39;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint16_t*)0x20000450 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000452, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000453, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000453, 0, 7, 1);
*(uint32_t*)0x20000454 = 9;
*(uint16_t*)0x20000458 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000045a, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000045b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000045b, 1, 7, 1);
*(uint16_t*)0x2000045c = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000045e, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000045f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000045f, 0, 7, 1);
*(uint32_t*)0x20000460 = htobe32(0xe0000001);
*(uint64_t*)0x20000408 = 0x24;
*(uint64_t*)0x20000fd8 = 1;
*(uint64_t*)0x20000fe0 = 0;
*(uint64_t*)0x20000fe8 = 0;
*(uint32_t*)0x20000ff0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000fc0ul, 0ul);
	return 0;
}
