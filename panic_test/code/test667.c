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

const int kInitNetNsFd = 201;

static long syz_init_net_socket(volatile long domain, volatile long type, volatile long proto)
{
	return syscall(__NR_socket, domain, type, proto);
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20001780 = 0;
*(uint32_t*)0x20001784 = 0x80;
*(uint8_t*)0x20001788 = 0;
*(uint8_t*)0x20001789 = 0;
*(uint8_t*)0x2000178a = 0;
*(uint8_t*)0x2000178b = 0;
*(uint32_t*)0x2000178c = 0;
*(uint64_t*)0x20001790 = 0;
*(uint64_t*)0x20001798 = 0;
*(uint64_t*)0x200017a0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 1, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200017a8, 0, 38, 26);
*(uint32_t*)0x200017b0 = 0;
*(uint32_t*)0x200017b4 = 0;
*(uint64_t*)0x200017b8 = 0;
*(uint64_t*)0x200017c0 = 0;
*(uint64_t*)0x200017c8 = 0;
*(uint64_t*)0x200017d0 = 0;
*(uint32_t*)0x200017d8 = 0;
*(uint32_t*)0x200017dc = 0;
*(uint64_t*)0x200017e0 = 0;
*(uint32_t*)0x200017e8 = 0;
*(uint16_t*)0x200017ec = 0;
*(uint16_t*)0x200017ee = 0;
*(uint32_t*)0x200017f0 = 0;
*(uint32_t*)0x200017f4 = 0;
*(uint64_t*)0x200017f8 = 0;
	syscall(__NR_perf_event_open, 0x20001780ul, -1, 0ul, -1, 0ul);
syz_init_net_socket(0x10, 3, 0x10);
	return 0;
}
