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
*(uint64_t*)0x200002c0 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0x20000280;
*(uint64_t*)0x20000280 = 0x20000200;
*(uint32_t*)0x20000200 = 0x40;
*(uint8_t*)0x20000204 = 1;
*(uint8_t*)0x20000205 = 1;
*(uint16_t*)0x20000206 = 0x101;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint8_t*)0x20000210 = 0;
*(uint8_t*)0x20000211 = 0;
*(uint16_t*)0x20000212 = htobe16(0);
*(uint16_t*)0x20000214 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000216, 0x18, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000217, 1, 7, 1);
*(uint16_t*)0x20000218 = 0x18;
STORE_BY_BITMASK(uint16_t, , 0x2000021a, 6, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000021b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000021b, 1, 7, 1);
*(uint16_t*)0x2000021c = 0x14;
*(uint16_t*)0x2000021e = 5;
*(uint8_t*)0x20000220 = 0xfe;
*(uint8_t*)0x20000221 = 0x80;
memset((void*)0x20000222, 0, 13);
*(uint8_t*)0x2000022f = 0xbb;
*(uint16_t*)0x20000230 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20000232, 0x1a, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000233, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000233, 0, 7, 1);
*(uint32_t*)0x20000234 = htobe32(0);
*(uint16_t*)0x20000238 = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000023a, 0xc, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000023b, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000023b, 0, 7, 1);
*(uint32_t*)0x2000023c = htobe32(0);
*(uint64_t*)0x20000288 = 0x40;
*(uint64_t*)0x200002d8 = 1;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}