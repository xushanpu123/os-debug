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
*(uint64_t*)0x200038c0 = 0;
*(uint32_t*)0x200038c8 = 0;
*(uint64_t*)0x200038d0 = 0x20003840;
*(uint64_t*)0x20003840 = 0x20003240;
*(uint32_t*)0x20003240 = 0x90;
*(uint16_t*)0x20003244 = 0x19;
*(uint16_t*)0x20003246 = 1;
*(uint32_t*)0x20003248 = 0;
*(uint32_t*)0x2000324c = 0;
*(uint16_t*)0x20003250 = 0x80;
STORE_BY_BITMASK(uint16_t, , 0x20003252, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20003253, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20003253, 1, 7, 1);
*(uint16_t*)0x20003254 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20003256, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20003257, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20003257, 0, 7, 1);
*(uint32_t*)0x20003258 = 0;
memcpy((void*)0x2000325c, "\x1e\x92\x15\x13\xf1\x13\x14\x7c\xa4\x9a\x3b\x44\x39\xb2\x41\xb4\x48\xad\xc9\xd6\xe7\x19\xd1\x6f\xcc\xe4\xaa\x15\x1c\x98\xeb\x3f\xed\x69\x87\x96\x99\x49\x73\xce\xb9\xc8\x97\xb3\x9c\x34\x13\x37\x89\xb6\x5c\x59\xbd\xcc\xc9\xea\x93\x8c\x11\xa6\xfb\x08\x16\xcb\xf8\xa2\x2f\xa4\x97\x74\x36\xaf\x79\xc5\xfb\x11\xe3\x65\x78", 79);
memcpy((void*)0x200032ab, "\xc2\x5e\x1f\x58\x59\xe2\xcf\x4a\x7c\x5f\x7b\x21\x8f\x29\x57\x69\x79\x67\xbd\x14\x43\xc5\x54\x25\x2d\xf4\xa0\x30\xfa\x38\x33\xd2\x81\x36\x5d\x09\x9e", 37);
*(uint64_t*)0x20003848 = 0x90;
*(uint64_t*)0x200038d8 = 1;
*(uint64_t*)0x200038e0 = 0;
*(uint64_t*)0x200038e8 = 0;
*(uint32_t*)0x200038f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200038c0ul, 0ul);
	return 0;
}
