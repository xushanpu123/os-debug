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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000040, "mounts\000", 7);
syz_open_procfs(-1, 0x20000040);
memcpy((void*)0x20000980, "/dev/snd/seq\000", 13);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000980ul, 0ul, 0);
*(uint64_t*)0x20000000 = 0;
*(uint64_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0;
*(uint64_t*)0x20000018 = 0;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint64_t*)0x20000030 = 0;
*(uint64_t*)0x20000038 = 0;
*(uint64_t*)0x200000c0 = 0x1f;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000000ul, 0ul, 0x200000c0ul, 0ul, 0ul);
memcpy((void*)0x200000c0, "./file1\000", 8);
	syscall(__NR_mknod, 0x200000c0ul, 0ul, 0);
memcpy((void*)0x20000040, "./file1\000", 8);
memcpy((void*)0x20000080, "./file1\000", 8);
	syscall(__NR_mount, 0x20000040ul, 0x20000080ul, 0ul, 0x8014c0ul, 0ul);
	return 0;
}
