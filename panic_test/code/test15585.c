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
memcpy((void*)0x20000040, "/dev/cdrom\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x101803ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000080 = 0;
*(uint8_t*)0x20000081 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000082, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000082, 0, 4, 4);
*(uint8_t*)0x20000083 = 4;
*(uint8_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint8_t*)0x2000008c = 0;
*(uint8_t*)0x2000008d = 0;
*(uint8_t*)0x2000008e = 0;
	syscall(__NR_ioctl, r[0], 0x530b, 0x20000080ul);
	return 0;
}