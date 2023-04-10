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
#ifndef __NR_pidfd_getfd
#define __NR_pidfd_getfd 438
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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000640, "/sys/kernel/boot_params", 23);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000640ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000540 = 0x1000;
*(uint64_t*)0x20000548 = 0x200002c0;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0;
*(uint32_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint64_t*)0x20000570 = 0;
*(uint64_t*)0x20000578 = 0;
*(uint64_t*)0x20000580 = 0;
*(uint64_t*)0x20000588 = 0;
*(uint32_t*)0x20000590 = -1;
	res = -1;
res = syz_clone3(0x20000540, 0x58);
	if (res != -1)
r[1] = *(uint32_t*)0x200002c0;
	syscall(__NR_pidfd_getfd, r[1], r[0], 0ul);
	return 0;
}
