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
*(uint64_t*)0x20000040 = 0x20000200;
*(uint32_t*)0x20000200 = 0x24;
*(uint16_t*)0x20000204 = 0x20;
*(uint16_t*)0x20000206 = 0xa1f;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint8_t*)0x20000210 = 2;
*(uint8_t*)0x20000211 = 0;
*(uint16_t*)0x20000212 = 0;
*(uint16_t*)0x20000214 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000216, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 0, 7, 1);
*(uint32_t*)0x20000218 = 0;
*(uint16_t*)0x2000021c = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000021e, 0xd, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000021f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000021f, 0, 7, 1);
*(uint32_t*)0x20000220 = 0;
*(uint64_t*)0x20000048 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}
