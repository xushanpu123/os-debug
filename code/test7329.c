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
#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0;
*(uint32_t*)0x200002a0 = 7;
*(uint64_t*)0x200002a8 = 0x20000180;
*(uint64_t*)0x200002b0 = 0x10;
*(uint64_t*)0x200002b8 = 0;
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x200002c8 = 0;
*(uint32_t*)0x200002d0 = -1;
syz_clone3(0x20000280, 0x58);
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fc00002;
	res = syscall(__NR_seccomp, 1ul, 8ul, 0x20000340ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ppoll, 0ul, 0ul, 0ul, 0ul, 0ul);
	res = syscall(__NR_ioctl, r[0], 0xc0502100, 0x20000200ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000200;
*(uint64_t*)0x20000080 = r[1];
*(uint64_t*)0x20000088 = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
	syscall(__NR_ioctl, r[0], 0xc0182101, 0x20000080ul);
	syscall(__NR_ioctl, r[0], 0xc0502100, 0x200005c0ul);
	syscall(__NR_ioctl, -1, 0xc0182101, 0ul);
	syscall(__NR_ioctl, -1, 0x40182103, 0ul);
	return 0;
}
