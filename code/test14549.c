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
*(uint64_t*)0x20000440 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint64_t*)0x20000450 = 0x20000400;
*(uint64_t*)0x20000400 = 0x20000340;
*(uint32_t*)0x20000340 = 0x50;
*(uint8_t*)0x20000344 = 3;
*(uint8_t*)0x20000345 = 1;
*(uint16_t*)0x20000346 = 0x401;
*(uint32_t*)0x20000348 = 0;
*(uint32_t*)0x2000034c = 0;
*(uint8_t*)0x20000350 = 0xa;
*(uint8_t*)0x20000351 = 0;
*(uint16_t*)0x20000352 = htobe16(0);
*(uint16_t*)0x20000354 = 0x3c;
STORE_BY_BITMASK(uint16_t, , 0x20000356, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000357, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000357, 1, 7, 1);
*(uint16_t*)0x20000358 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x2000035a, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000035b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000035b, 1, 7, 1);
*(uint16_t*)0x2000035c = 5;
*(uint16_t*)0x2000035e = 1;
*(uint8_t*)0x20000360 = 6;
*(uint16_t*)0x20000364 = 0x2c;
STORE_BY_BITMASK(uint16_t, , 0x20000366, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000367, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000367, 1, 7, 1);
*(uint16_t*)0x20000368 = 0x14;
*(uint16_t*)0x2000036a = 3;
*(uint8_t*)0x2000036c = 0xfe;
*(uint8_t*)0x2000036d = 0x80;
memset((void*)0x2000036e, 0, 13);
*(uint8_t*)0x2000037b = 0;
*(uint16_t*)0x2000037c = 0x14;
*(uint16_t*)0x2000037e = 4;
memcpy((void*)0x20000380, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\002", 16);
*(uint64_t*)0x20000408 = 0x50;
*(uint64_t*)0x20000458 = 1;
*(uint64_t*)0x20000460 = 0;
*(uint64_t*)0x20000468 = 0;
*(uint32_t*)0x20000470 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000440ul, 0ul);
	return 0;
}
