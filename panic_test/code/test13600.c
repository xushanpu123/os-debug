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
*(uint64_t*)0x20000500 = 0;
*(uint32_t*)0x20000508 = 0;
*(uint64_t*)0x20000510 = 0x200004c0;
*(uint64_t*)0x200004c0 = 0x20000000;
*(uint32_t*)0x20000000 = 0x50;
*(uint8_t*)0x20000004 = 3;
*(uint8_t*)0x20000005 = 1;
*(uint16_t*)0x20000006 = 3;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0xa;
*(uint8_t*)0x20000011 = 0;
*(uint16_t*)0x20000012 = htobe16(0);
*(uint16_t*)0x20000014 = 0x3c;
STORE_BY_BITMASK(uint16_t, , 0x20000016, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000017, 1, 7, 1);
*(uint16_t*)0x20000018 = 0x2c;
STORE_BY_BITMASK(uint16_t, , 0x2000001a, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000001b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000001b, 1, 7, 1);
*(uint16_t*)0x2000001c = 0x14;
*(uint16_t*)0x2000001e = 3;
*(uint8_t*)0x20000020 = 0xfe;
*(uint8_t*)0x20000021 = 0x80;
memset((void*)0x20000022, 0, 13);
*(uint8_t*)0x2000002f = 0xaa;
*(uint16_t*)0x20000030 = 0x14;
*(uint16_t*)0x20000032 = 4;
*(uint8_t*)0x20000034 = 0xfc;
*(uint8_t*)0x20000035 = 2;
memset((void*)0x20000036, 0, 13);
*(uint8_t*)0x20000043 = 0;
*(uint16_t*)0x20000044 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x20000046, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000047, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000047, 1, 7, 1);
*(uint16_t*)0x20000048 = 5;
*(uint16_t*)0x2000004a = 1;
*(uint8_t*)0x2000004c = 1;
*(uint64_t*)0x200004c8 = 0x50;
*(uint64_t*)0x20000518 = 1;
*(uint64_t*)0x20000520 = 0;
*(uint64_t*)0x20000528 = 0;
*(uint32_t*)0x20000530 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000500ul, 0ul);
	return 0;
}
