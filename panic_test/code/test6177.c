// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

static long syz_open_procfs(volatile long a0, volatile long a1)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	if (a0 == 0) {
		snprintf(buf, sizeof(buf), "/proc/self/%s", (char*)a1);
	} else if (a0 == -1) {
		snprintf(buf, sizeof(buf), "/proc/thread-self/%s", (char*)a1);
	} else {
		snprintf(buf, sizeof(buf), "/proc/self/task/%d/%s", (int)a0, (char*)a1);
	}
	int fd = open(buf, O_RDWR);
	if (fd == -1)
		fd = open(buf, O_RDONLY);
	return fd;
}

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "/dev/hpet\000", 10);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x200000ul, 0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0xd000943e, 0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0xd000943e, 0ul);
memcpy((void*)0x20000080, "\'\000", 2);
*(uint64_t*)0x200000c0 = 3;
*(uint64_t*)0x200000c8 = 6;
*(uint64_t*)0x200000d0 = 7;
*(uint64_t*)0x200000d8 = 0x29fb;
memset((void*)0x200000e0, 0, 32);
	syscall(__NR_mq_open, 0x20000080ul, 0x8e2ul, 0ul, 0x200000c0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_getpgrp, 0);
	if (res != -1)
		r[3] = res;
syz_open_procfs(r[3], 0);
	syscall(__NR_tkill, r[3], 0xf);
	syscall(__NR_ioctl, r[2], 0xd000943e, 0ul);
	syscall(__NR_ioctl, r[2], 0x8010661b, 0x20000100ul);
	return 0;
}