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

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20001240, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20001240ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_ioctl, -1, 0x4c82, 0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, r[1]);
	syscall(__NR_ioctl, -1, 0x89fa, 0ul);
*(uint64_t*)0x20000100 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0x20;
*(uint32_t*)0x20000108 = 0xc;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000040;
*(uint32_t*)0x20000040 = 0x40;
*(uint16_t*)0x20000044 = 0;
*(uint16_t*)0x20000046 = 0;
*(uint32_t*)0x20000048 = 0x70bd25;
*(uint32_t*)0x2000004c = 0x25dfdbfe;
*(uint8_t*)0x20000050 = 1;
*(uint8_t*)0x20000051 = 0;
*(uint16_t*)0x20000052 = 0;
*(uint16_t*)0x20000054 = 0x1c;
STORE_BY_BITMASK(uint16_t, , 0x20000056, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 1, 7, 1);
*(uint16_t*)0x20000058 = 6;
*(uint16_t*)0x2000005a = 5;
*(uint16_t*)0x2000005c = htobe16(0);
*(uint16_t*)0x20000060 = 5;
*(uint16_t*)0x20000062 = 2;
*(uint8_t*)0x20000064 = 0;
*(uint16_t*)0x20000068 = 5;
*(uint16_t*)0x2000006a = 2;
*(uint8_t*)0x2000006c = 1;
*(uint16_t*)0x20000070 = 8;
*(uint16_t*)0x20000072 = 2;
*(uint32_t*)0x20000074 = 2;
*(uint16_t*)0x20000078 = 8;
*(uint16_t*)0x2000007a = 3;
*(uint32_t*)0x2000007c = 6;
*(uint64_t*)0x200000c8 = 0x40;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0;
	syscall(__NR_sendmsg, -1, 0x20000100ul, 0x8040ul);
	res = syscall(__NR_ioctl, -1, 0x4c82, 0);
	if (res != -1)
		r[2] = res;
	syscall(__NR_ioctl, -1, 0x4c81, r[2]);
	return 0;
}
