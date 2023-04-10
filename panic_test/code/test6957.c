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
	res = -1;
res = syz_open_dev(0xc, 4, 0x14);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000440 = 0;
memcpy((void*)0x20000441, "\x76\x64\xc3\xde\xd5\x03\xdf\xae\x54\xd3\xfe\xf2\x07\xc9\x23\x76\x6e\x41\x04\x52\x71\xbd\x80\xe3\x8e\xbf\xa1\xb5\xd9\x2d\x88\x24\xe7\xe9\x4c\xa0\x9d\xf6\xe2\x22\x3a\x9e\xfd\x12\x68\x31\x44\xa3\x28\x08\xb9\x28\xc6\x40\x34\x79\xcb\x91\xfb\x1e\xde\xf6\x18\x1c\xa5\xfe\xe0\x87\x08\x57\xc5\x38\x06\x0b\x8f\x82\xc5\x30\xb9\x7c\xc5\x78\x03\x02\x3f\xce\x11\xd4\x60\xf1\x39\x2d\x1b\x25\x38\x09\x50\xd3\xc8\xe7\x38\xe1\xb6\xe4\x06\x26\x31\xbb\xd4\xbd\x15\xdd\x20\xcf\x45\x1f\x5a\x34\x68\x6e\x9b\xe1\x34\xd7\x57\xf3\xc1\xe3\x97\x8c\x77\x0f\x57\x10\x52\xaa\x24\xd8\x2a\xa1\x68\x26\x9e\x02\x20\xef\x20\xa6\x59\xd4\x13\x84\xd1\xaf\x13\x5a\x7b\x2c\x6e\x53\x3c\x20\xa4\x11\x05\xae\xe2\x15\x9b\x01\xdb\x1d\x15\xc2\x30\x9b\xe6\xeb\xac\x2a\xd2\x5b\xc7\x9a\xd6\x7e\xb0\xdf\x9f\x8b\x27\x32\xaa\xa4\xcf\x5d\x27\x8f\x4c\xc1\x3e\xba\x0b\xde\xfa\xc9\x52\x88\xc7\xab\xfc\x62\xbe\x3e\xfc\xb9\xba\x43\xfe\xe4\x31\x4b\x76\x50\x50\x08\x7c\xbc\xf4\x4f\xdc\xdb\xea\x4f\x96\xdc\xbb\x3c\xda\x3f\xd7\x03\x66\x9c\x43\xff\x8d\x92\x8d\x88\x18\x2d\x54\x32\x1f\x26\x70\x96\xdf\x85\xd6\x21\x98\x16\x07\x64\x91\xa4\xf4\xf1\x6d\x54\xa3\xcd\xdd\xe4\xd4\x68\x82\xb8\x2f\x82\x27\xe3\x43\x52\x20\xe4\x2a\xdf\x5d\xcc\x8b\xb6\x2c\xff\x73\x0c\x07\x0f\xe5\x91\x67\x31\xdb\x8c\x6e\x52\x7d\x86\x9a\x52\xe5\x8b\xc3\x01\xfe\x7b\xd7\x4e\x6b\x29\x92\xf6\xa9\xf9\xb9\x67\xae\xdf\x75\x0f\xe1\x18\xe8\xf1\x46\x87\xa2\xec\xd9\x96\xcd\x35\x7a\xc3\x7c\xcc\xd7\x3f\xb8\x25\xe8\x31\x02\x6f\xd5\x0d\xd9\x4e\x4e\x84\x68\xf5\x9b\x2e\x5a\x25\x38\x77\x2d\xd3\x53\x1c\x8a\x69\x3b\x91\xfd\xc9\x43\x40\x3d\x82\xb3\x5c\x65\x4d\x89\x8e\x51\x35\x95\x9f\x60\x16\x9f\x0a\x28\x6a\x04\xdb\xa5\xde\x04\x0c\xdf\xb7\x8c\x39\xd1\x23\xcc\xef\xb6\x95\x08\x25\x89\x87\xdb\x34\xc3\x70\x91\xb6\xd8\xaf\x5d\x06\x0c\x77\x3c\x44\xa1\x70\x0b\xad\xc0\xed\x38\x95\x8d\xab\xd7\x23\xe3\x9e\xf6\x37\x6a\xb9\x30\x88\x4d\xe0\x2b\x2b\x0a\x45\x9a\x37\xb0\x14\xf7\x62\xd3\xd0\x38\x43\x83\x16\x06\xf8\xbc\xbf\x31\xec\x78\xfd\x57\x1c\xbc\x80\xcd\x74\x0b\x32\x30\xad\x6a\x07\x73\xa5\x07\x44\xf8\xf4\xcd\x6c\xc8\x12\x7b\x26\x91\xfe\xd6\x9a\x8f\xe2\xf6\xf3", 512);
	syscall(__NR_ioctl, r[0], 0x4b48, 0x20000440ul);
	return 0;
}