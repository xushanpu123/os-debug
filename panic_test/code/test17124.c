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

static long syz_clone(volatile long flags, volatile long stack, volatile long stack_len,
		      volatile long ptid, volatile long ctid, volatile long tls)
{
	long sp = (stack + stack_len) & ~15;
	long ret = (long)syscall(__NR_clone, flags & ~CLONE_VM, sp, ptid, ctid, tls);
	return handle_clone_ret(ret);
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 0x80;
*(uint8_t*)0x200000c8 = 0;
*(uint8_t*)0x200000c9 = 0;
*(uint8_t*)0x200000ca = 0;
*(uint8_t*)0x200000cb = 0;
*(uint32_t*)0x200000cc = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 38, 26);
*(uint32_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f4 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x2000011c = 0;
*(uint64_t*)0x20000120 = 0;
*(uint32_t*)0x20000128 = 0;
*(uint16_t*)0x2000012c = 0;
*(uint16_t*)0x2000012e = 0;
*(uint32_t*)0x20000130 = 0;
*(uint32_t*)0x20000134 = 0;
*(uint64_t*)0x20000138 = 0;
	syscall(__NR_perf_event_open, 0x200000c0ul, 0, 0ul, -1, 0ul);
syz_clone(0, 0, 0, 0, 0, 0);
	return 0;
}
