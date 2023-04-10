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

memcpy((void*)0x20000000, "ns/time_for_children\000", 21);
syz_open_procfs(-1, 0x20000000);
memcpy((void*)0x200010c0, "\xc6\xd0\x12\x6b\x07\x2c\xca\xe1\x83\xae\xce\xe0\x21\x66\x99\x59\x19\x81\xfa\x67\xbd\x13\xcb\x83\x25\x43\xfd\x7e\x19\x6c\x84\x7c\x0f\xdc\x9b\x8a\x4c\x6e\x0c\x8e\xf0\xc5\x62\x47\x78\x9b\xb7\xcd\x37\xb5\xeb\x46\x03\x16\x93\x31\xde\xbb\xe1\xfa\x7a\xa7\xc2\x75\xf5\xc9\xa7\x76\x57\x39\x04\x8c\xcd\xee\x85\xb1\x1a\xaf\xfa\x80\xaa\x22\x25\xa6\x41\x0d\x41\xa7\xe7\xd7\x81\x32\x15\x02\x1e\x65\x50\x9f\xda\xc1\x62\x2c\x47\xba\x20\x6d\x7d\xef\x9e\xc9\xbb\x6f\x6a\xac\x2d\x21\x14\xa3\x0e\xf3\x13\x59\x12\xd9\x6b\xe6\x2a\x7c\x3d\x7f\xdb\x21\x4d\x89\x8f\xf8\x4a\x25\x34\x59\xff\xf7\x24\xe2\x33\x9f\x99\xc8\x5d\x4b\x45\xa3\xf7\xc9\xe9\x6a\x61\x7d\x6d\xe4\xb9\x0a\x87\xf3\x0c\xd3\x87\x2b\x75\xb0\x54\x60\x71\x81\xb1\x5e\x62\xe9\x73\xc1\xce\xf5\xc1\xac", 184);
syz_clone(0x44002000, 0, 0, 0x20001040, 0x20001080, 0x200010c0);
	return 0;
}
