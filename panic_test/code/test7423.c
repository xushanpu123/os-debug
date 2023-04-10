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

*(uint32_t*)0x20000000 = 0x400;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0;
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 0, 1);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 1, 2);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 3, 1);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 4, 1);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 5, 1);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 6, 1);
STORE_BY_BITMASK(uint32_t, , 0x2000000c, 0, 7, 1);
	syscall(__NR_modify_ldt, 0x11ul, 0x20000000ul, 0x10ul);
*(uint64_t*)0x20000b80 = 0;
*(uint64_t*)0x20000b88 = 0;
*(uint64_t*)0x20000b90 = 0;
*(uint64_t*)0x20000b98 = 0;
*(uint32_t*)0x20000ba0 = 0;
*(uint64_t*)0x20000ba8 = 0;
*(uint64_t*)0x20000bb0 = 0;
*(uint64_t*)0x20000bb8 = 0;
*(uint64_t*)0x20000bc0 = 0;
*(uint64_t*)0x20000bc8 = 0;
*(uint32_t*)0x20000bd0 = -1;
syz_clone3(0x20000b80, 0x58);
	return 0;
}