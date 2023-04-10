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
#ifndef __NR_pidfd_open
#define __NR_pidfd_open 434
#endif
#ifndef __NR_pidfd_send_signal
#define __NR_pidfd_send_signal 424
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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000700 = 0;
*(uint64_t*)0x20000708 = 0;
*(uint64_t*)0x20000710 = 0;
*(uint64_t*)0x20000718 = 0;
*(uint32_t*)0x20000720 = 0;
*(uint64_t*)0x20000728 = 0;
*(uint64_t*)0x20000730 = 0;
*(uint64_t*)0x20000738 = 0;
*(uint64_t*)0x20000740 = 0;
*(uint64_t*)0x20000748 = 0;
*(uint32_t*)0x20000750 = -1;
	res = -1;
res = syz_clone3(0x20000700, 0x58);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_pidfd_open, r[0], 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_pidfd_send_signal, r[1], 6, 0ul, 0ul);
	return 0;
}
