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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000300, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000300, 0, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 3, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000340 = r[0];
*(uint32_t*)0x20000344 = 0;
*(uint64_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0;
*(uint64_t*)0x20000358 = 0;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0;
*(uint32_t*)0x20000374 = 0;
*(uint32_t*)0x20000378 = 0;
*(uint32_t*)0x2000037c = 0xc;
memcpy((void*)0x20000380, "\xcc\xc2\x51\x8f\x50\x68\x43\x17\x56\x99\xe7\x81\xc7\x5f\x4f\x0c\xea\x50\x34\x0e\x31\xd4\x09\xb4\xdb\x0a\xbd\x43\xce\xf3\x92\x2a\xd3\xff\x1d\x84\x00\xed\x72\x86\x9d\x18\x2a\x32\x5d\x68\x9f\x8b\xb0\xc9\xf0\xf6\x53\xee\xfc\xcc\x17\x04\x51\x5b\x7d\x34\xd5\x1b", 64);
memcpy((void*)0x200003c0, "\xa4\x21\x00\x5a\xee\xc4\xc5\xd3\x19\xeb\x2d\x38\xa6\x07\xb4\x94\xfc\xed\xed\x3b\x2c\x7d\x01\x5d\x66\x6f\x4e\xb9\x54\x05\x64\x6b\x84\x86\xd3\xa5\x16\xb9\x81\xcf\x26\x3f\x00\x4b\x9b\xf5\xb9\xbc\x2e\x99\xb3\x5f\x5d\xc4\xa1\xc3\xab\xc6\x39\x2d\x95\x6c\x74\x69", 64);
memcpy((void*)0x20000400, "\x84\x00\xc9\x56\x0c\x2f\xce\x61\xba\xd8\x8b\xb0\xee\x81\x6d\x69\x82\x31\x8e\x15\x1d\x03\xbf\x13\x0e\x1b\xbf\xef\x23\xc7\xb9\x41", 32);
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
memset((void*)0x20000430, 0, 64);
	syscall(__NR_ioctl, r[1], 0x4c0a, 0x20000340ul);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
	return 0;
}
