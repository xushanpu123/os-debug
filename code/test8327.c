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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000040, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0xfffffcae;
*(uint32_t*)0x20000104 = 0;
*(uint32_t*)0x20000108 = 0;
memcpy((void*)0x2000010c, "\xf1\xbe\xb2\x4b\x06\xd1\x24\x61\xa9\x85\xe1\x6c\x45\x6c\xbb\x82\x99\x7e\xcd\x55\xca\xad\xa5\xa4\xaa\xfa\x17\x5d\xd3\xd6\x31\x34\xdc\x2d\x10\xfa\xeb\x5d\xd4\x3b\xeb\xd3\x40\x64\x97\x00\xc2\xc7\x93\x45\xd6\x72\x48\x76\x92\x0f\xaa\x3a\xaa\xfb\x29", 61);
	syscall(__NR_ioctl, r[0], 1, 0x20000100ul);
	return 0;
}
