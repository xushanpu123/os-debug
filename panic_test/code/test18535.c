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
memcpy((void*)0x20000000, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = 0;
STORE_BY_BITMASK(uint32_t, , 0x20000108, 0, 0, 1);
memcpy((void*)0x20000109, "queue0\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x2000014c = 0;
memset((void*)0x20000150, 0, 60);
	syscall(__NR_ioctl, r[0], 0xc08c5332, 0x20000100ul);
*(uint32_t*)0x20000200 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0;
memset((void*)0x2000020c, 0, 64);
	syscall(__NR_ioctl, r[0], 0xc04c5349, 0x20000200ul);
	return 0;
}
