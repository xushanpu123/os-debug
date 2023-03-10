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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000980 = 0;
*(uint32_t*)0x20000984 = 0x80;
*(uint8_t*)0x20000988 = 0;
*(uint8_t*)0x20000989 = 0;
*(uint8_t*)0x2000098a = 0;
*(uint8_t*)0x2000098b = 0;
*(uint32_t*)0x2000098c = 0;
*(uint64_t*)0x20000990 = 0;
*(uint64_t*)0x20000998 = 0;
*(uint64_t*)0x200009a0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 1, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 1, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200009a8, 0, 38, 26);
*(uint32_t*)0x200009b0 = 0;
*(uint32_t*)0x200009b4 = 0;
*(uint64_t*)0x200009b8 = 0;
*(uint64_t*)0x200009c0 = 0;
*(uint64_t*)0x200009c8 = 0;
*(uint64_t*)0x200009d0 = 0;
*(uint32_t*)0x200009d8 = 0;
*(uint32_t*)0x200009dc = 0;
*(uint64_t*)0x200009e0 = 0;
*(uint32_t*)0x200009e8 = 0;
*(uint16_t*)0x200009ec = 0;
*(uint16_t*)0x200009ee = 0;
*(uint32_t*)0x200009f0 = 0;
*(uint32_t*)0x200009f4 = 0;
*(uint64_t*)0x200009f8 = 0;
	res = syscall(__NR_perf_event_open, 0x20000980ul, -1, 0ul, -1, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_mmap, 0x20ffd000ul, 0x2000ul, 0ul, 0x10ul, r[0], 8ul);
	syscall(__NR_pipe2, 0ul, 0ul);
	syscall(__NR_socket, 0x10ul, 3ul, 4);
*(uint64_t*)0x20000a00 = 0;
*(uint64_t*)0x20000a08 = 0x20;
*(uint64_t*)0x20000a10 = 2;
*(uint64_t*)0x20000a18 = 1;
memset((void*)0x20000a20, 0, 992);
	res = syscall(__NR_ioctl, -1, 0xc400941b, 0x20000a00ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000a00;
*(uint64_t*)0x20000e00 = r[1];
*(uint64_t*)0x20000e08 = 0x1000;
*(uint64_t*)0x20000e10 = 0;
*(uint64_t*)0x20000e18 = 0;
memset((void*)0x20000e20, 0, 992);
	syscall(__NR_ioctl, -1, 0xc400941b, 0x20000e00ul);
	syscall(__NR_io_setup, 3, 0x200028c0ul);
	return 0;
}
