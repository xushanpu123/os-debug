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
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0x20002900;
*(uint64_t*)0x20002900 = 0x20002940;
*(uint32_t*)0x20002940 = 0x28;
*(uint16_t*)0x20002944 = 0x1c;
*(uint16_t*)0x20002946 = 1;
*(uint32_t*)0x20002948 = 0;
*(uint32_t*)0x2000294c = 0;
*(uint16_t*)0x20002950 = 0x18;
STORE_BY_BITMASK(uint16_t, , 0x20002952, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20002953, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20002953, 1, 7, 1);
*(uint16_t*)0x20002954 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20002956, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20002957, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20002957, 0, 7, 1);
*(uint32_t*)0x20002958 = htobe32(0);
*(uint16_t*)0x2000295c = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000295e, 0xe, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000295f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000295f, 0, 7, 1);
*(uint64_t*)0x20002960 = 0;
*(uint64_t*)0x20002908 = 0x28;
*(uint64_t*)0x20000058 = 1;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint32_t*)0x20000070 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000040ul, 0ul);
	return 0;
}
