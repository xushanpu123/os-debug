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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002600 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e21);
*(uint32_t*)0x20000004 = htobe32(0x7f000001);
*(uint32_t*)0x20002608 = 0x10;
*(uint64_t*)0x20002610 = 0;
*(uint64_t*)0x20002618 = 0;
*(uint64_t*)0x20002620 = 0;
*(uint64_t*)0x20002628 = 0;
*(uint32_t*)0x20002630 = 0;
*(uint32_t*)0x20002638 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002600ul, 0x29ul, 0x4008d40ul);
*(uint64_t*)0x20003e40 = 0;
*(uint32_t*)0x20003e48 = 0;
*(uint64_t*)0x20003e50 = 0;
*(uint64_t*)0x20003e58 = 0;
*(uint64_t*)0x20003e60 = 0;
*(uint64_t*)0x20003e68 = 0;
*(uint32_t*)0x20003e70 = 0;
*(uint32_t*)0x20003e78 = 0;
*(uint64_t*)0x20003e80 = 0x200007c0;
*(uint16_t*)0x200007c0 = 2;
*(uint16_t*)0x200007c2 = htobe16(0x4e24);
*(uint32_t*)0x200007c4 = htobe32(0xe0000002);
*(uint32_t*)0x20003e88 = 0x10;
*(uint64_t*)0x20003e90 = 0;
*(uint64_t*)0x20003e98 = 0;
*(uint64_t*)0x20003ea0 = 0x20000a80;
*(uint64_t*)0x20000a80 = 0x3c;
*(uint32_t*)0x20000a88 = 0;
*(uint32_t*)0x20000a8c = 7;
*(uint8_t*)0x20000a90 = 7;
*(uint8_t*)0x20000a91 = 7;
*(uint8_t*)0x20000a92 = 0xa2;
*(uint8_t*)0x20000a93 = 0xac;
*(uint8_t*)0x20000a94 = 0x1e;
*(uint8_t*)0x20000a95 = 0;
*(uint8_t*)0x20000a96 = 1;
*(uint8_t*)0x20000a97 = 0x44;
*(uint8_t*)0x20000a98 = 0x1c;
*(uint8_t*)0x20000a99 = 0x72;
STORE_BY_BITMASK(uint8_t, , 0x20000a9a, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000a9a, 0, 4, 4);
*(uint32_t*)0x20000a9b = htobe32(0);
*(uint32_t*)0x20000a9f = htobe32(0);
*(uint8_t*)0x20000aa3 = 0xac;
*(uint8_t*)0x20000aa4 = 0x14;
*(uint8_t*)0x20000aa5 = 0x14;
*(uint8_t*)0x20000aa6 = 0xaa;
*(uint32_t*)0x20000aa7 = htobe32(0);
*(uint8_t*)0x20000aab = 0xac;
*(uint8_t*)0x20000aac = 0x14;
*(uint8_t*)0x20000aad = 0x14;
*(uint8_t*)0x20000aae = 0;
*(uint32_t*)0x20000aaf = htobe32(0);
*(uint8_t*)0x20000ab3 = 0x94;
*(uint8_t*)0x20000ab4 = 4;
*(uint16_t*)0x20000ab5 = 0;
*(uint8_t*)0x20000ab7 = 0x44;
*(uint8_t*)0x20000ab8 = 4;
*(uint8_t*)0x20000ab9 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000aba, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000aba, 0, 4, 4);
*(uint64_t*)0x20003ea8 = 0x40;
*(uint32_t*)0x20003eb0 = 0;
*(uint32_t*)0x20003eb8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003e40ul, 2ul, 0ul);
	return 0;
}
