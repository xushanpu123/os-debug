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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000180, "/dev/sr0\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000180ul, 0x200000ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_fstat, r[0], 0x20000640ul);
*(uint64_t*)0x20000140 = 0x20000040;
*(uint16_t*)0x20000040 = 0x10;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0x1000000;
*(uint32_t*)0x20000148 = 0xc;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20000080;
*(uint32_t*)0x20000080 = 0x5c;
*(uint8_t*)0x20000084 = 1;
*(uint8_t*)0x20000085 = 4;
*(uint16_t*)0x20000086 = 0x101;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint8_t*)0x20000090 = 3;
*(uint8_t*)0x20000091 = 0;
*(uint16_t*)0x20000092 = htobe16(4);
*(uint16_t*)0x20000094 = 0xa;
*(uint16_t*)0x20000096 = 2;
*(uint32_t*)0x20000098 = htobe32(8);
*(uint8_t*)0x2000009c = 0;
*(uint8_t*)0x2000009d = 0;
*(uint16_t*)0x200000a0 = 0xa;
*(uint16_t*)0x200000a2 = 2;
*(uint32_t*)0x200000a4 = htobe32(2);
*(uint8_t*)0x200000a8 = 2;
*(uint8_t*)0x200000a9 = 0;
*(uint16_t*)0x200000ac = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000ae, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000af, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000af, 0, 7, 1);
*(uint32_t*)0x200000b0 = htobe32(0x10000);
*(uint16_t*)0x200000b4 = 6;
STORE_BY_BITMASK(uint16_t, , 0x200000b6, 6, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000b7, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000b7, 0, 7, 1);
*(uint16_t*)0x200000b8 = htobe16(0);
*(uint16_t*)0x200000bc = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000be, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000bf, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000bf, 0, 7, 1);
*(uint32_t*)0x200000c0 = htobe32(0xea8);
*(uint16_t*)0x200000c4 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000c6, 4, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000c7, 1, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000c7, 0, 7, 1);
*(uint32_t*)0x200000c8 = htobe32(0x17);
*(uint16_t*)0x200000cc = 5;
*(uint16_t*)0x200000ce = 1;
*(uint8_t*)0x200000d0 = 2;
*(uint16_t*)0x200000d4 = 5;
*(uint16_t*)0x200000d6 = 1;
*(uint8_t*)0x200000d8 = 3;
*(uint64_t*)0x20000108 = 0x5c;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0x4000040;
	syscall(__NR_sendmsg, r[0], 0x20000140ul, 1ul);
syz_clone(0x49005000, 0, 0, 0, 0, 0);
	return 0;
}
