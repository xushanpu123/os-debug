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
memcpy((void*)0x20000000, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = r[0];
*(uint32_t*)0x200001c4 = 0;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f4 = 0;
*(uint32_t*)0x200001f8 = 0;
*(uint32_t*)0x200001fc = 0;
memcpy((void*)0x20000200, "\x17\xa1\x11\xc1\x7e\xb9\x86\x7e\xd7\x09\xf9\xca\x67\xef\x00\x8e\xc9\x2e\x78\x12\x8f\xdf\xd7\xc7\x89\x77\x89\xfa\x3f\xd1\xb3\xeb\x10\x95\xe2\xa9\xcf\x42\xb0\xf5\x62\x7a\x3e\x24\x39\xc3\xf1\x70\xc8\xaa\x5f\xf9\x2e\x1e\xa6\x18\x30\xe1\x74\xdd\x1b\x34\xc9\xed", 64);
memcpy((void*)0x20000240, "\x9c\xc4\x6a\x63\xfd\xa2\x49\xac\x58\x49\x50\x4d\xc0\x70\x41\x9a\x03\x9d\x09\x8b\x5a\x04\xbf\x1d\xe7\xcb\x87\x16\xea\xe5\xd4\xd3\x84\x56\xf6\x02\x50\xd1\x85\x6d\xb6\xe4\x1e\x87\x1e\x4d\xb7\xfc\x9e\xeb\xc5\xf2\x32\xcc\x38\x56\xdf\x01\x17\x68\x85\xf9\x05\x16", 64);
memcpy((void*)0x20000280, "\x43\xb0\x1f\x9b\x6c\xfc\x2e\xca\x23\x43\xe9\xb4\x75\x64\x4a\xcb\xed\xa0\x4a\x94\x41\x39\x11\x2e\xbb\x4f\x7a\x79\x49\xa3\xa4\x28", 32);
*(uint64_t*)0x200002a0 = 0;
*(uint64_t*)0x200002a8 = 0;
memset((void*)0x200002b0, 0, 64);
	syscall(__NR_ioctl, r[0], 0x4c0a, 0x200001c0ul);
	return 0;
}
