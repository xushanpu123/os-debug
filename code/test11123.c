// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/sched.h>

#ifndef __NR_clone3
#define __NR_clone3 435
#endif

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

#define MAX_CLONE_ARGS_BYTES 256
static long syz_clone3(volatile long a0, volatile long a1)
{
	unsigned long copy_size = a1;
	if (copy_size < sizeof(uint64_t) || copy_size > MAX_CLONE_ARGS_BYTES)
		return -1;
	char clone_args[MAX_CLONE_ARGS_BYTES];
	memcpy(&clone_args, (void*)a0, copy_size);
	uint64_t* flags = (uint64_t*)&clone_args;
	*flags &= ~CLONE_VM;
	return handle_clone_ret((long)syscall(__NR_clone3, &clone_args, copy_size));
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20000500 = 0;
*(uint32_t*)0x20000504 = 0x80;
*(uint8_t*)0x20000508 = 0;
*(uint8_t*)0x20000509 = 0;
*(uint8_t*)0x2000050a = 0;
*(uint8_t*)0x2000050b = 0;
*(uint32_t*)0x2000050c = 0;
*(uint64_t*)0x20000510 = 0;
*(uint64_t*)0x20000518 = 0;
*(uint64_t*)0x20000520 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 1, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000528, 0, 38, 26);
*(uint32_t*)0x20000530 = 0;
*(uint32_t*)0x20000534 = 0;
*(uint64_t*)0x20000538 = 0;
*(uint64_t*)0x20000540 = 0;
*(uint64_t*)0x20000548 = 0;
*(uint64_t*)0x20000550 = 0;
*(uint32_t*)0x20000558 = 0;
*(uint32_t*)0x2000055c = 0;
*(uint64_t*)0x20000560 = 0;
*(uint32_t*)0x20000568 = 0;
*(uint16_t*)0x2000056c = 0;
*(uint16_t*)0x2000056e = 0;
*(uint32_t*)0x20000570 = 0;
*(uint32_t*)0x20000574 = 0;
*(uint64_t*)0x20000578 = 0;
	syscall(__NR_perf_event_open, 0x20000500ul, 0, 0ul, -1, 0ul);
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0x80;
*(uint8_t*)0x20000048 = 0;
*(uint8_t*)0x20000049 = 0;
*(uint8_t*)0x2000004a = 0;
*(uint8_t*)0x2000004b = 0;
*(uint32_t*)0x2000004c = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 1, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000068, 0, 38, 26);
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x2000009c = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint32_t*)0x200000a8 = 0;
*(uint16_t*)0x200000ac = 0;
*(uint16_t*)0x200000ae = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint64_t*)0x200000b8 = 0;
	syscall(__NR_perf_event_open, 0x20000040ul, 0, -1ul, -1, 0ul);
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint32_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
*(uint64_t*)0x200003c0 = 0;
*(uint64_t*)0x200003c8 = 0;
*(uint32_t*)0x200003d0 = -1;
syz_clone3(0x20000380, 0x58);
	return 0;
}
