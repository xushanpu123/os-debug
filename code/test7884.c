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
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000300;
*(uint64_t*)0x20000300 = 0x20000580;
*(uint32_t*)0x20000580 = 0x1c;
*(uint16_t*)0x20000584 = 0x1a;
*(uint16_t*)0x20000586 = 0x70b;
*(uint32_t*)0x20000588 = 0;
*(uint32_t*)0x2000058c = 0;
*(uint16_t*)0x20000590 = 0xa;
STORE_BY_BITMASK(uint16_t, , 0x20000592, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000593, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000593, 1, 7, 1);
memcpy((void*)0x20000594, "\xfb\x99\xd0\xe1\xe1\x7d", 6);
*(uint64_t*)0x20000308 = 0x1c;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000380ul, 0ul);
	return 0;
}