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
*(uint64_t*)0x20000040 = 0x20000ac0;
*(uint32_t*)0x20000ac0 = 0x24;
*(uint16_t*)0x20000ac4 = 0x18;
*(uint16_t*)0x20000ac6 = 1;
*(uint32_t*)0x20000ac8 = 0;
*(uint32_t*)0x20000acc = 0;
*(uint8_t*)0x20000ad0 = 0xa;
*(uint8_t*)0x20000ad1 = 0;
*(uint16_t*)0x20000ad2 = 0;
*(uint16_t*)0x20000ad4 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000ad6, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000ad7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000ad7, 0, 7, 1);
*(uint32_t*)0x20000ad8 = 0;
*(uint16_t*)0x20000adc = 5;
STORE_BY_BITMASK(uint16_t, , 0x20000ade, 0x14, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000adf, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000adf, 1, 7, 1);
memset((void*)0x20000ae0, 73, 1);
*(uint64_t*)0x20000048 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}