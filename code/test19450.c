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
memcpy((void*)0x20000000, "ns/time_for_children\000", 21);
	res = -1;
res = syz_open_procfs(0, 0x20000000);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200001c0 = 0;
*(uint64_t*)0x200001c8 = 0;
*(uint16_t*)0x200001d0 = 0;
*(uint16_t*)0x200001d2 = 0;
*(uint32_t*)0x200001d4 = 0;
	syscall(__NR_ioctl, r[0], 0xc0189436, 0x200001c0ul);
	return 0;
}