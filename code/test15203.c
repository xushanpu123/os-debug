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
memcpy((void*)0x20000080, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 0;
*(uint32_t*)0x200001c4 = 0;
STORE_BY_BITMASK(uint32_t, , 0x200001c8, 0, 0, 1);
memcpy((void*)0x200001c9, "queue1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x2000020c = 0;
memset((void*)0x20000210, 0, 60);
	syscall(__NR_ioctl, r[0], 0xc08c5332, 0x200001c0ul);
*(uint8_t*)0x20000040 = 0;
*(uint8_t*)0x20000041 = -1;
*(uint8_t*)0x20000042 = 0;
*(uint8_t*)0x20000043 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 8;
*(uint8_t*)0x2000004c = 0;
*(uint8_t*)0x2000004d = 0;
*(uint8_t*)0x2000004e = 0;
*(uint8_t*)0x2000004f = 0;
*(uint8_t*)0x20000050 = 2;
*(uint32_t*)0x20000054 = 0;
*(uint32_t*)0x20000058 = 0;
*(uint8_t*)0x2000005c = 0;
*(uint8_t*)0x2000005d = 0x81;
*(uint8_t*)0x2000005e = 0;
*(uint8_t*)0x2000005f = 0;
*(uint32_t*)0x20000060 = 0;
*(uint8_t*)0x20000068 = 0;
*(uint8_t*)0x20000069 = 0;
*(uint8_t*)0x2000006a = 0;
*(uint8_t*)0x2000006b = 0;
*(uint32_t*)0x2000006c = 0;
*(uint32_t*)0x20000070 = 0;
	syscall(__NR_write, r[0], 0x20000040ul, 0x38ul);
	return 0;
}
