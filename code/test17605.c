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
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0x78000000;
	syscall(__NR_ioctl, r[0], 0x2275, 0x20000080ul);
*(uint32_t*)0x20000200 = 0x53;
*(uint32_t*)0x20000204 = 0;
*(uint8_t*)0x20000208 = 6;
*(uint8_t*)0x20000209 = 0;
*(uint16_t*)0x2000020a = 0;
*(uint32_t*)0x2000020c = 0xfd8b;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0x20000280;
memcpy((void*)0x20000280, "\x33\xcc\x06\xe0\x92\x62\xe1\x0a\x76\xa9\xb0\x47\x76\xd5\x28\xb1\xae\xa2\x3a\xbf\x1a\x76\xb9\xaf\x4e\xe4\x11\xc6\x7c\x53\xee\x6e\x8e\x2e\x51\x3f\x35\xf3\xe1\x1a\x4f\xa8\xb6\x2d\xa1\x52\x5f\x9e\xc0\xf7\x0d\x5c\x70\x66\x8c\x4b\xd6\xde\x7d\xb7\xc0\x2d\xbf\x1c\x78\xdd\x83\x9c\x15\x92\x53\x9f\x0f\x9c\x4a\x81\xd3\xf7\x88\xaf\x5b\x8a\xb8\xaf\x1d\x95\x13\xc2\xc0\x8b\xb9\x50\x54\xd1\x3d\xe7\xf2\x8a\x7b\x68\x6d\xa6\x26\xaa\x44\x18\x71\xb7", 108);
*(uint64_t*)0x20000220 = 0x20003f40;
*(uint32_t*)0x20000228 = 0;
*(uint32_t*)0x2000022c = 0;
*(uint32_t*)0x20000230 = 0;
*(uint64_t*)0x20000234 = 0;
*(uint8_t*)0x2000023c = 0;
*(uint8_t*)0x2000023d = 0;
*(uint8_t*)0x2000023e = 0;
*(uint8_t*)0x2000023f = 0;
*(uint16_t*)0x20000240 = 0;
*(uint16_t*)0x20000242 = 0;
*(uint32_t*)0x20000244 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint32_t*)0x2000024c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000200ul);
	return 0;
}