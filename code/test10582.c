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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_ioctl, -1, 0x4c82, 0);
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x80000ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x4c81, 0ul);
	syscall(__NR_gettid);
memcpy((void*)0x200006c0, "./file0/file0\000", 14);
	syscall(__NR_lstat, 0x200006c0ul, 0x200000c0ul);
	syscall(__NR_gettid);
syz_open_procfs(0, 0);
	syscall(__NR_socket, 0x10ul, 3ul, 0);
	syscall(__NR_gettid);
	return 0;
}