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
memcpy((void*)0x20000180, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000180, 0, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000040 = r[1];
*(uint32_t*)0x20000044 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint32_t*)0x20000070 = 0;
*(uint32_t*)0x20000074 = 0;
*(uint32_t*)0x20000078 = 0;
*(uint32_t*)0x2000007c = 0;
memcpy((void*)0x20000080, "\x97\xb3\xb2\xe6\x97\x9a\x49\x3f\x2b\x85\xa0\xef\x02\xe3\xff\x87\x3a\x27\xef\xf5\x89\x26\x89\x9f\xb5\xb9\x92\x4b\x6d\xb4\x9a\x21\xf2\x63\x70\x3b\xb9\xaa\x2a\x0c\x83\x94\x18\xc1\x5c\xb1\xdc\x44\x74\xfc\x73\x56\xc3\xe5\xfc\xda\x2a\x0b\x8f\x5a\xdf\xfe\x18\x3d", 64);
memcpy((void*)0x200000c0, "\x7e\x57\x61\x80\xb7\x11\x79\xfe\x38\x2c\x16\x52\x64\xb9\xc1\xff\x03\x04\x58\x9d\xf6\x28\xee\x7d\x8d\x95\x85\x23\x43\xe1\xaa\x88\xb6\xa6\x1a\xf7\x9e\x69\xb4\x7e\x54\xbd\xfc\x84\x32\xb8\xde\xc6\x35\x7a\xe1\xec\x98\x2d\xc6\x22\x76\x61\x98\x79\xaa\xa6\xc3\x39", 64);
memcpy((void*)0x20000100, "\x9d\xd0\x74\xa3\x5c\x63\xd6\x41\x07\xcb\x0f\x27\x53\x66\xd8\x22\xc3\xa4\x2f\x60\xf5\xff\xff\xa2\x76\x35\x21\x98\x45\x14\x8d\xc3", 32);
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
memset((void*)0x20000130, 0, 64);
	syscall(__NR_ioctl, r[0], 0x4c0a, 0x20000040ul);
	return 0;
}