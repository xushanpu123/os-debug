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
memcpy((void*)0x20001140, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20001140, 1, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20001180 = 0x5e;
*(uint32_t*)0x20001184 = 0x1000;
*(uint32_t*)0x20001188 = 0x3f;
memcpy((void*)0x2000118c, "\x0a\xd9\xde\x91\x1a\xa6\xe9\xcd\xe0\x63\x4c\x50\xf7\x96\x69\x42\x5f\x6d\x7d\xa0\xd4\x48\x9a\x53\x3d\xb2\x41\x9c\xc4\x12\xa9\xee\x0f\xb7\x52\x74\x41\x97\xa3\x63\x2e\x94\xc1\xae\x76\xc2\x8b\x11\xd8\xb6\x84\x73\xec\xc0\x3c\xd4\xdd\x87\x02\xea\xc4\xa0\xa2\x68\x1d\xaa\xac\xe1\x30\xc5\x70\xff\xb2\x9b\x67\x8b\xfa\x3e\x57\xe7\xc3\xf4\x74\xcb\xd2\xc7\x0b\xe1\xaf\x95\x9b\x34\xf6\x76", 94);
	syscall(__NR_ioctl, r[0], 1, 0x20001180ul);
	return 0;
}
