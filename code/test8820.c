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
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000340;
*(uint64_t*)0x20000340 = 0x20000000;
*(uint32_t*)0x20000000 = 0x34;
*(uint8_t*)0x20000004 = 1;
*(uint8_t*)0x20000005 = 4;
*(uint16_t*)0x20000006 = 5;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0;
*(uint8_t*)0x20000011 = 0;
*(uint16_t*)0x20000012 = htobe16(0);
*(uint16_t*)0x20000014 = 6;
STORE_BY_BITMASK(uint16_t, , 0x20000016, 6, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 0, 7, 1);
*(uint16_t*)0x20000018 = htobe16(0);
*(uint16_t*)0x2000001c = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000001e, 3, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000001f, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000001f, 0, 7, 1);
*(uint32_t*)0x20000020 = htobe32(0);
*(uint16_t*)0x20000024 = 5;
*(uint16_t*)0x20000026 = 1;
*(uint8_t*)0x20000028 = 1;
*(uint16_t*)0x2000002c = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000002e, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000002f, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000002f, 0, 7, 1);
*(uint32_t*)0x20000030 = htobe32(0);
*(uint64_t*)0x20000348 = 0x34;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000380ul, 0ul);
	return 0;
}