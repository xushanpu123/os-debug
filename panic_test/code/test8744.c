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
memcpy((void*)0x20000100, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000100, 0, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 6, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000280 = r[0];
*(uint32_t*)0x20000284 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0;
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
*(uint32_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b4 = 0;
*(uint32_t*)0x200002b8 = 0;
*(uint32_t*)0x200002bc = 0x10;
memcpy((void*)0x200002c0, "\xaa\x89\x7a\x52\x35\xb5\xae\x20\x98\xc1\x64\x46\xb2\xf4\x3d\x80\xf8\xa8\x8d\x8a\x2c\x6c\xdb\x79\xe9\x1e\xb4\xc5\xf8\x94\xc6\x80\x05\x30\x21\xca\x8f\x4c\xdc\x57\xd9\xb3\x2e\xb4\xaa\x2c\xbc\x01\xc0\x7e\x4f\xa8\x7c\x88\x8f\x00\x14\xd1\x18\x54\x0e\x7c\x63\x3e", 64);
memcpy((void*)0x20000300, "\x3d\xe0\x58\x46\x03\x04\xd8\xe6\xa3\xa9\x33\x13\x54\x6b\x3c\x92\xe7\xbe\xde\xd7\xd6\xf8\x50\xbf\x31\x17\x02\x42\xc9\x4f\x14\x38\x10\x02\xcb\x23\xbb\x5d\x24\x87\xde\x1d\x57\x6f\xfc\x6e\x76\x63\x72\xbc\x4d\x44\x5d\xed\x27\xf8\x4f\x78\x89\xe6\xf5\xbf\x22\x0e", 64);
memcpy((void*)0x20000340, "\xb1\x12\x8b\x11\x86\x2d\xe7\xec\x25\xae\x3c\xd6\x2d\x1e\x29\x0e\x0a\x6f\xc0\x7f\x85\xfb\x72\x2a\xa3\xe2\xa2\x04\x6b\x81\x34\x06", 32);
*(uint64_t*)0x20000360 = -1;
*(uint64_t*)0x20000368 = 0;
memset((void*)0x20000370, 0, 64);
	syscall(__NR_ioctl, r[1], 0x4c0a, 0x20000280ul);
	syscall(__NR_getsockopt, -1, 1, 0, 0ul, 0ul);
	return 0;
}