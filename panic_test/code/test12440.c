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
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0x20000300;
*(uint64_t*)0x20000300 = 0x20000480;
*(uint32_t*)0x20000480 = 0x20;
*(uint8_t*)0x20000484 = 3;
*(uint8_t*)0x20000485 = 1;
*(uint16_t*)0x20000486 = 0x101;
*(uint32_t*)0x20000488 = 0;
*(uint32_t*)0x2000048c = 0;
*(uint8_t*)0x20000490 = 0;
*(uint8_t*)0x20000491 = 0;
*(uint16_t*)0x20000492 = htobe16(0);
*(uint16_t*)0x20000494 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000496, 0x19, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000497, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000497, 1, 7, 1);
*(uint16_t*)0x20000498 = 8;
*(uint16_t*)0x2000049a = 2;
*(uint32_t*)0x2000049c = 0x800;
*(uint64_t*)0x20000308 = 0x20;
*(uint64_t*)0x20000358 = 1;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000340ul, 0ul);
	return 0;
}
