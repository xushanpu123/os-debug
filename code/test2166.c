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
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20000240;
*(uint32_t*)0x20000240 = 0x30;
*(uint8_t*)0x20000244 = 2;
*(uint8_t*)0x20000245 = 1;
*(uint16_t*)0x20000246 = 3;
*(uint32_t*)0x20000248 = 0;
*(uint32_t*)0x2000024c = 0;
*(uint8_t*)0x20000250 = 0;
*(uint8_t*)0x20000251 = 0;
*(uint16_t*)0x20000252 = htobe16(0);
*(uint16_t*)0x20000254 = 0x1c;
STORE_BY_BITMASK(uint16_t, , 0x20000256, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000257, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000257, 1, 7, 1);
*(uint16_t*)0x20000258 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000025a, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000025b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000025b, 1, 7, 1);
*(uint16_t*)0x2000025c = 5;
*(uint16_t*)0x2000025e = 1;
*(uint8_t*)0x20000260 = 0;
*(uint16_t*)0x20000264 = 6;
STORE_BY_BITMASK(uint16_t, , 0x20000266, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000267, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000267, 1, 7, 1);
*(uint16_t*)0x20000268 = 5;
*(uint16_t*)0x2000026a = 1;
*(uint8_t*)0x2000026c = 0;
*(uint64_t*)0x20000048 = 0x30;
*(uint64_t*)0x20000098 = 1;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000080ul, 0ul);
	return 0;
}
