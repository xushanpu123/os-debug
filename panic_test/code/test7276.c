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
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20001280;
*(uint32_t*)0x20001280 = 0x24;
*(uint16_t*)0x20001284 = 0x20;
*(uint16_t*)0x20001286 = 0xa1f;
*(uint32_t*)0x20001288 = 0;
*(uint32_t*)0x2000128c = 0;
*(uint8_t*)0x20001290 = 2;
*(uint8_t*)0x20001291 = 0;
*(uint16_t*)0x20001292 = 0;
*(uint16_t*)0x20001294 = 0x10;
STORE_BY_BITMASK(uint16_t, , 0x20001296, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001297, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001297, 1, 7, 1);
*(uint16_t*)0x20001298 = 4;
STORE_BY_BITMASK(uint16_t, , 0x2000129a, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000129b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000129b, 0, 7, 1);
*(uint16_t*)0x2000129c = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000129e, 0x18, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000129f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000129f, 0, 7, 1);
*(uint32_t*)0x200012a0 = 0x47ffe;
*(uint64_t*)0x20000048 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}
