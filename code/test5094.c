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
memcpy((void*)0x200000c0, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x200000c0, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0x200;
*(uint32_t*)0x20000104 = 0;
*(uint32_t*)0x20000108 = 0xbb;
memcpy((void*)0x2000010c, "\xc8\x88\x62\x9c\x05\xa0\xd8\xa0\x44\x21\x46\xc3\x55\xb1\xd7\x47\xa3\xe0\x00\x0c\xfb\xba\x7b\x66\xed\x2b\x1b\xbf\xb8\x86\x82\xb2\x35\xd7\x77\xff\x54\x1d\xc8\x48\x35\x4b\x83\x60\x1e\xf7\x15\x42\x8f\xbd\x90\xa1\xef\x3e\x78\xed\x81\x27\xf5\x51\xe9\x59\xc5\xbe\x6f\xc9\xf3\xfc\x8c\x1a\xcd\x01\xf9\x74\x0c\x8b\xa5\xea\xf6\x58\x39\x9e\x7b\x86\xaa\x93\x90\x3d\x3b\xfa\x40\x4a\x84\xcc\x93\x9f\x34\xdc\x5d\x53\x11\x72\xd7\x29\xa1\xa4\x9f\xd6\xed\x3a\x15\x6e\x5b\x24\xaa\x45\x48\xa4\xe9\x64\x50\xda\x0c\x01\x9c\x11\xd3\x1b\x1c\x77\x80\x5b\xc3\xb0\x6e\xec\xbe\x6f\x4a\xdb\xe5\xe0\x92\x81\x53\x0e\x2d\x20\x10\x37\x3a\x46\x83\x68\xff\x9d\xba\xac\x35\xa9\x6f\x52\xc7\xab\x33\x26\x77\xff\x09\x74\xbe\xd9\xc1\x18\x78\x20\x55\xa6\x1d\xd2\x0a\x7c\xb6\x97\x1a\x65\x13\x4e\x1a\x59\x6e\x99\xf5\xc5\x63\x9c\x6b\x70\xb4\xd7\xf9\xdc\x31\x00\x19\x25\x14\x3c\x1f\xba\x00\x9f\x6b\x8f\x69\xbe\xff\xce\xca\x3b\x9a\xc9\x3a\x5b\x47\xc6\xb6\xe9\xcb\x23\x3a\xdd\x37\x99\x51\x40\x11\x3c\xcf\x95\x70\x0f\x22\x85\x31\x46\xa6\xbc\x55\x52\x46\xa6\x51\x1e\x7b\x6b\xe4\xfa\xa2\xba\x1b\x8f\x92\xb3\x6a\xa1\x3f\x5a\xe6\xd0\x19\x4b\x63\xe2\xa5\xb3\xf6\x15\x45\x36\xde\x16\x75\x90\x67\xa5\xf4\x63\x1f\x16\x5f\x48\xd2\xfc\x4f\xdf\xce\xbc\x02\x1a\x72\x0e\x44\x3b\xe4\xa3\xbc\x79\x8c\xaf\x83\xc3\x60\x88\xe8\x3f\xb1\xae\x75\xd3\xf0\x3f\xb4\xbf\xc2\x80\x88\xa6\x12\x13\xa8\xcf\x1c\x30\x3b\xfb\x1c\x8c\x1a\x84\x6e\x66\x9a\x3c\x8e\x79\xae\x1b\x67\xb3\x9c\xb6\xe1\xc5\x37\xea\x12\x30\xb7\x55\x53\xc5\xb1\x18\x08\xc1\x14\x1d\x99\x15\x0c\xd4\x3b\x5a\x93\xf5\xbc\xd6\xb4\xe9\x47\x00\x3f\x06\xff\xb3\x33\x60\xae\x2d\x2d\xf5\x74\x11\xd4\xa2\xde\xe7\x43\xb1\x76\xbd\x00\x9b\xee\xdc\xd8\xcf\xab\xe3\x7e\x39\x21\x8f\xb9\x72\x4e\xfc\x43\x36\x92\x5a\x14\x84\x5e\x91\x9d\x61\x47\x62\xaa\x8c\x2d\x90\xee\x8e\x9a\x64\x71\x42\x4d\x42\x45\xb0\x15\x46\xd7\x58\x9e\xcc\x9f\x33\x71\xff\xb2\x26\xb6\xf6\x60\x0b\xa1\x80\x93\xa5\x74\x56\xac\xd2\xde\x6a\x9a\xc8\xab\xa0\x9a\xcd\xff\xf0\xbc\xb9\x8c\xb7\x94\x2a\x01\xe8\x8e\x54\x08\x93\x9d\x19\x27\x83\x38\xe5\x50\x3d\x44\x1d\x44\x1f\xc1\xaa\x46\x4b\x83\x22\xf0\x43\x62\x15", 512);
	syscall(__NR_ioctl, r[0], 1, 0x20000100ul);
	return 0;
}
