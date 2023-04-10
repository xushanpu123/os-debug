// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/sched.h>

#ifndef __NR_clone3
#define __NR_clone3 435
#endif

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

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
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x5437, 0ul);
	res = syscall(__NR_signalfd, -1, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_read, -1, 0ul, 0ul);
	syscall(__NR_poll, 0ul, 0ul, 0x1ff);
*(uint64_t*)0x20000040 = 0xfffffffffffffff8;
	syscall(__NR_signalfd, r[1], 0x20000040ul, 8ul);
*(uint64_t*)0x20000100 = 0x341000400;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint32_t*)0x20000120 = 0x41;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0xfffffe18;
*(uint64_t*)0x20000138 = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint32_t*)0x20000150 = -1;
syz_clone3(0x20000100, 0x58);
	return 0;
}
