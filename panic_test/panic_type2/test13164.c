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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000fc0 = 0;
*(uint32_t*)0x20000fc8 = 0;
*(uint64_t*)0x20000fd0 = 0x20000740;
*(uint64_t*)0x20000740 = 0x20000040;
*(uint32_t*)0x20000040 = 0xf8;
*(uint16_t*)0x20000044 = 0x18;
*(uint16_t*)0x20000046 = 1;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
memcpy((void*)0x20000050, "\x00\x87\x28\xb7\x42\x7a\x99\xc5\x42\xde\x44\x51\x2f\xd9\x14\x63\x10\xa9\x4a\xa4\x69", 21);
*(uint16_t*)0x20000065 = 0x14;
STORE_BY_BITMASK(uint16_t, , 0x20000067, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000068, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000068, 0, 7, 1);
*(uint8_t*)0x20000069 = 0xfe;
*(uint8_t*)0x2000006a = 0x80;
memset((void*)0x2000006b, 0, 13);
*(uint8_t*)0x20000078 = 0xaa;
*(uint16_t*)0x20000079 = 8;
STORE_BY_BITMASK(uint16_t, , 0x2000007b, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000007c, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000007c, 0, 7, 1);
*(uint32_t*)0x2000007d = -1;
*(uint16_t*)0x20000081 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000083, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000084, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000084, 0, 7, 1);
*(uint16_t*)0x20000085 = 0x16;
STORE_BY_BITMASK(uint16_t, , 0x20000087, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000088, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000088, 0, 7, 1);
memcpy((void*)0x20000089, "/dev/loop-control\000", 18);
*(uint16_t*)0x2000009d = 0x95;
STORE_BY_BITMASK(uint16_t, , 0x2000009f, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000a0, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000a0, 1, 7, 1);
*(uint16_t*)0x200000a1 = 6;
STORE_BY_BITMASK(uint16_t, , 0x200000a3, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000a4, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000a4, 0, 7, 1);
memcpy((void*)0x200000a5, "[\000", 2);
*(uint16_t*)0x200000a9 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000ab, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000ac, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000ac, 0, 7, 1);
*(uint8_t*)0x200000ad = 0xac;
*(uint8_t*)0x200000ae = 0x14;
*(uint8_t*)0x200000af = 0x14;
*(uint8_t*)0x200000b0 = 0;
*(uint16_t*)0x200000b1 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000b3, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000b4, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000b4, 0, 7, 1);
*(uint32_t*)0x200000b5 = -1;
memcpy((void*)0x200000b9, "\x4a\x85\x10\x17\xa7\x20\x1e\x15\x0c\xa8\x6b\x4d\x3b\xe6\x6b\x97\x1f\x5d\xdd\xd5\x9e\xe6\x2f\xc2\x3b\x8e\x69\x79\xe5\xa5\x53\xed\x36\x37\xab\x51\x98\xee\x8b\x03\xa5\x81\x0a\x2e\x33\xfa\xee\x36\x0a\x7e\x1b\x91\xe7\xe6\x81\x35\xa4\x4a\xf5\xb2\x7f\x5e\xf6\xc9\x59\x32\x43\xbc\xe0\x36\x76\x42\xd0\xea\xf1\xbe\xb5\xcf\xbf\x41\x41\xb0\xe9\x8d\x16\x59\xaf\x72\xd1\x36\x91\xdd\x07\x5e\x46\x62\x52", 97);
*(uint16_t*)0x2000011a = 0x15;
STORE_BY_BITMASK(uint16_t, , 0x2000011c, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000011d, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000011d, 0, 7, 1);
memcpy((void*)0x2000011e, "\xc9\x3e\x3f\xa2\xed\x6a\xc3\x2f\x20\x81\x3c\x9a\xe9\x87\x7d\xb0\x43", 17);
*(uint64_t*)0x20000748 = 0xf8;
*(uint64_t*)0x20000fd8 = 1;
*(uint64_t*)0x20000fe0 = 0;
*(uint64_t*)0x20000fe8 = 0;
*(uint32_t*)0x20000ff0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000fc0ul, 0ul);
	return 0;
}