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
*(uint64_t*)0x200024c0 = 0;
*(uint32_t*)0x200024c8 = 0;
*(uint64_t*)0x200024d0 = 0x200017c0;
*(uint64_t*)0x200017c0 = 0x20000700;
*(uint32_t*)0x20000700 = 0x14;
*(uint16_t*)0x20000704 = 0;
*(uint16_t*)0x20000706 = 0;
*(uint32_t*)0x20000708 = 0;
*(uint32_t*)0x2000070c = 0;
*(uint16_t*)0x20000710 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000712, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000713, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000713, 0, 7, 1);
*(uint64_t*)0x200017c8 = 0x14;
*(uint64_t*)0x200017d0 = 0x20000440;
*(uint32_t*)0x20000440 = 0x24;
*(uint16_t*)0x20000444 = 0;
*(uint16_t*)0x20000446 = 0;
*(uint32_t*)0x20000448 = 0;
*(uint32_t*)0x2000044c = 0;
*(uint16_t*)0x20000450 = 0x11;
STORE_BY_BITMASK(uint16_t, , 0x20000452, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000453, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000453, 1, 7, 1);
*(uint16_t*)0x20000454 = 0;
STORE_BY_BITMASK(uint16_t, , 0x20000456, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 0, 7, 1);
memcpy((void*)0x20000458, "\x17\x61\xc4\x0c\x57\x50\x7b\x5c\xdb\x18\xe8\xa5\x25\x1e\x17\x11\xe4\x8c\x8b\xdd\xc7\x1b\x96\xc9\xa9\x38\x64\x04\x97\x6d\xaa\x71\xbf\xfa\x05\xf6\x67\x6a\x10\x6b\xac\xf3\xc2\xd1\x3f\xd3\x4c\x9f\xf7\x59\x67\x8a\xe0\x25\xad\xbb\x0d\xd9\xc8\x86\x69", 61);
*(uint64_t*)0x200017d8 = 0x24;
*(uint64_t*)0x200017e0 = 0x20000380;
*(uint32_t*)0x20000380 = 0x1c;
*(uint16_t*)0x20000384 = 0x1e;
*(uint16_t*)0x20000386 = 1;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x2000038c = 0;
*(uint64_t*)0x200017e8 = 0x1c;
*(uint64_t*)0x200017f0 = 0x20000580;
*(uint32_t*)0x20000580 = 0x24;
*(uint16_t*)0x20000584 = 0;
*(uint16_t*)0x20000586 = 0;
*(uint32_t*)0x20000588 = 0;
*(uint32_t*)0x2000058c = 0;
*(uint16_t*)0x20000590 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000592, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000593, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000593, 0, 7, 1);
memcpy((void*)0x20000594, "\x2a\xf3\x18\xa0\x7f\xd1\xa3\x5c\x1c\x52\x5a\x6c\x92", 13);
*(uint64_t*)0x200017f8 = 0x24;
*(uint64_t*)0x200024d8 = 0x22;
*(uint64_t*)0x200024e0 = 0;
*(uint64_t*)0x200024e8 = 0;
*(uint32_t*)0x200024f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200024c0ul, 0ul);
	return 0;
}
