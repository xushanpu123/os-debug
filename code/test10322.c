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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000000ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200000c0, "ns/ipc\000", 7);
	res = -1;
res = syz_open_procfs(-1, 0x200000c0);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000040, "./file0\000", 8);
memcpy((void*)0x20000080, "9p\000", 3);
memcpy((void*)0x20000100, "trans=fd,", 9);
memcpy((void*)0x20000109, "rfdno", 5);
*(uint8_t*)0x2000010e = 0x3d;
sprintf((char*)0x2000010f, "0x%016llx", (long long)r[0]);
*(uint8_t*)0x20000121 = 0x2c;
memcpy((void*)0x20000122, "wfdno", 5);
*(uint8_t*)0x20000127 = 0x3d;
sprintf((char*)0x20000128, "0x%016llx", (long long)r[1]);
*(uint8_t*)0x2000013a = 0x2c;
*(uint8_t*)0x2000013b = 0;
	syscall(__NR_mount, 0ul, 0x20000040ul, 0x20000080ul, 0ul, 0x20000100ul);
	return 0;
}
