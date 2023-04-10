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

uint64_t r[5] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200003c0, "/dev/loop#\000", 11);
syz_open_dev(0x200003c0, 0, 0xa40);
memcpy((void*)0x20000640, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000640, 9, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/full\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x200ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x200003c0, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x200003c0, 0, 0);
	if (res != -1)
		r[2] = res;
	syscall(__NR_ioctl, r[2], 0x4c00, -1);
	syscall(__NR_ioctl, r[2], 0x4c06, r[0]);
	res = syscall(__NR_openat, -1, 0ul, 0ul, 0ul);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x200002c0 = 0x108000100;
*(uint64_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0;
*(uint64_t*)0x200002d8 = 0;
*(uint32_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0x20000140;
*(uint64_t*)0x200002f0 = 0x2e;
*(uint64_t*)0x200002f8 = 0x20000180;
*(uint64_t*)0x20000300 = 0x20000280;
*(uint32_t*)0x20000280 = 0;
*(uint32_t*)0x20000284 = 0;
*(uint32_t*)0x20000288 = -1;
*(uint64_t*)0x20000308 = 3;
*(uint32_t*)0x20000310 = r[3];
syz_clone3(0x200002c0, 0x58);
*(uint64_t*)0x20000040 = 3;
	syscall(__NR_ioctl, r[3], 0x40085400, 0x20000040ul);
memcpy((void*)0x20000080, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000080, 0xfffffffffffffff7, 0x21c240);
	if (res != -1)
		r[4] = res;
	syscall(__NR_ioctl, r[4], 0x4c00, r[1]);
	return 0;
}
