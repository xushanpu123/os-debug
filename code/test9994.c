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
*(uint64_t*)0x20000010 = 0x20006d40;
*(uint64_t*)0x20006d40 = 0x20000200;
*(uint32_t*)0x20000200 = 0x24;
*(uint16_t*)0x20000204 = 0x2c;
*(uint16_t*)0x20000206 = 0x21;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint16_t*)0x20000210 = 9;
STORE_BY_BITMASK(uint16_t, , 0x20000212, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000213, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000213, 0, 7, 1);
memcpy((void*)0x20000214, "^@[R\000", 5);
memcpy((void*)0x2000021c, "\x98\x47\x18\x0d\x5d", 5);
*(uint64_t*)0x20006d48 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}
