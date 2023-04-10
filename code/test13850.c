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
*(uint32_t*)0x20000000 = 0x19980330;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000054 = 0;
	syscall(__NR_capset, 0x20000000ul, 0x20000040ul);
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x200004c0 = 0;
memcpy((void*)0x200004c1, "\x32\x68\x64\x89\xfc\x78\x49\x20\x93\x19\x3a\xa2\xc8\x55\x1c\x4a\xe9\x6b\x76\xdb\x76\x19\x1f\x26\x9a\x2c\xef\x77\x1f\x9f\xcd\xa6\x57\xdc\xf3\x32\xb8\xec\xf4\xaf\x8d\x86\xdb\x99\x81\xa1\xf0\xca\xde\x3d\x7a\x5f\x9a\xcc\xb5\x0a\x48\xd0\x40\xfb\x03\x20\x5f\xaf\x53\xa8\x7d\x0e\x13\x01\x9f\x31\x45\xde\x84\x16\x8a\x67\x31\xe6\xef\x96\x01\x4b\x02\xfe\xe8\x9c\x69\x12\xd0\x21\xa0\x82\xb2\xb2\xe6\xbd\x8e\xe8\x48\x3f\xce\x5b\x06\x3e\x87\xcc\x85\x90\x81\xfa\xf3\x29\x3b\xb0\x7e\x16\x82\x21\xb2\xce\x79\xa7\x32\x58\xf6\x9b\x89\x65\x10\xe1\x50\x10\x58\xf0\x1f\x32\xb5\xd6\x0b\xff\x9a\x31\x08\x10\xb2\x66\xfe\xcd\xe6\x47\x15\xe5\x6d\x52\x83\x7a\xa7\xd9\x7d\x03\x52\xd9\x48\x64\x24\xbc\x4e\x12\x33\xfe\x26\x01\xe7\xde\x99\xbc\x23\x96\x93\xf0\x35\xf8\x32\x7e\xff\xa3\xc3\x8e\x66\x01\x0a\x63\x52\xee\x7d\x9a\xe6\xca\xf8\xb6\x0a\x46\x72\xab\x2f\xcb\xba\x4b\xbd\x0f\xa7\x53\x92\xa3\x26\x3c\x91\xce\xca\x8b\xb2\x53\xa4\x45\x91\xb2\xec\xd6\xe1\x22\x41\xb1\x56\xc5\xd2\x1a\x3f\x91\xcb\x90\x4d\xf9\x27\x6b\x29\x49\xaa\xfe\x55\x66\xa1\xce\xc1\xf0\x78\x35\x16\x5f\xc6\x62\x73\x4d\xde\x45\xf9\x56\x2a\x42\x49\x5b\xfd\x5e\x0f\xa1\xd1\x04\x69\x38\x35\x0c\xc4\x0b\xfe\x29\x72\x1e\x1d\xac\xfe\x05\x26\x8f\xac\xcf\x35\x11\x19\xb4\xa7\xa2\x87\x3f\x76\x3f\xa9\xe1\xf6\x74\x53\xb7\x53\x5f\x51\x26\xba\xbb\x2c\x7b\xda\x40\x1c\x1f\x10\xa8\x61\x9a\x96\x4d\x2e\xe6\x14\x37\xe1\x7a\xd7\x54\xa7\xef\x71\xdd\x08\x3a\x56\x02\x8a\x5e\xc0\x6d\xba\x21\xdc\x75\x1e\x25\x7b\xbb\xeb\x84\x43\xc4\x0a\xf7\xfa\xd6\x16\x09\x60\xfd\xe7\xcd\xa5\x8c\x2a\xdc\x97\x1a\xf9\x11\xef\xf1\x15\x7c\x6b\x9f\x7f\x38\xc5\x32\x85\x5c\xd3\xa7\x1b\xc9\x50\x32\x4b\xd8\x84\x64\x51\xb6\x18\x74\x02\xd3\x0a\x6a\x4b\xcf\x4d\x7c\x79\xb6\x71\xdf\x30\x68\x09\x01\xc3\x51\xc9\x45\xe8\x36\xa7\x03\xa6\x05\xe8\x9e\x46\x22\xd9\x85\xa9\x7b\x68\x5d\xdf\x44\x58\x30\x56\xbc\x35\xe4\x9e\x1b\xa6\xf5\xe2\x81\x88\x06\xb1\x91\x49\xb8\xe1\xf0\xe9\x41\xfe\x0d\xf9\xe9\x7e\x8b\xa3\x39\x3d\x5a\xe4\x1b\x83\x8a\xa2\x2c\xfa\xd8\x39\xb5\x70\x55\xbd\x82\xdb\x8f\xe7\xa7\x89\x32\xe1\x8a\x34\x16\xb8\x03\x7d\x63\xe4\x83\x6c\x4b\xe6\x13\xe5\x1b", 512);
	syscall(__NR_ioctl, r[0], 0x4b49, 0x200004c0ul);
	return 0;
}