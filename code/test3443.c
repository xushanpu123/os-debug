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
memcpy((void*)0x20000000, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "/dev/vcsu#\000", 11);
	res = -1;
res = syz_open_dev(0x20000040, 5, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000080 = r[1];
*(uint32_t*)0x20000084 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint32_t*)0x200000b8 = 0;
*(uint32_t*)0x200000bc = 0;
memcpy((void*)0x200000c0, "\xfd\xd1\x4c\xaf\x56\x35\x15\x9e\x29\x6e\xc7\x99\x37\xa8\x4d\xc4\x40\xd2\x8a\xee\x5d\xbf\xd6\x87\x20\x33\x82\x12\x64\x1b\x2b\xa4\x62\xd7\x8b\x20\xfe\x99\x09\x62\x26\x18\x9d\xaf\x39\x67\x81\x3e\x88\x30\x1b\xcb\x00\xdd\x77\x1f\x23\xcf\x1a\x1f\x7d\x8a\xfb\xfe", 64);
memcpy((void*)0x20000100, "\x05\x1f\x30\x74\x92\xa0\xef\xfb\xca\x23\x22\xc2\xeb\x74\x3c\x36\x36\x56\x21\xdd\xbb\x42\xb3\x83\xfc\xb7\xb8\x4e\x31\xb4\xb2\xcf\xa3\xda\xb4\x43\x5d\x27\x61\xb5\xac\x3d\xac\x3e\x33\x1d\x10\xf8\xb7\xdb\x64\xba\xab\x5f\x8e\x59\x31\x39\x84\x97\x3a\x74\x84\x3c", 64);
memcpy((void*)0x20000140, "\x60\x5f\x70\xe8\x85\x48\x40\xb5\x29\xc8\x58\xba\xbf\x73\xf6\x53\xe8\xb7\x0f\xcf\x18\xa7\x3d\x64\xc5\x59\x74\xb8\x14\x74\xda\x5c", 32);
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
memset((void*)0x20000170, 0, 64);
	syscall(__NR_ioctl, r[0], 0x4c0a, 0x20000080ul);
	return 0;
}
