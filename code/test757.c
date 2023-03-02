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
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0;
memcpy((void*)0x20000001, "\xf6\xec\xd1\xec\x59\xae\xf6\xfc\xd1\x2d\x48\xfc\xa8\xa9\x5d\xc6\xe9\xc5\x82\xb4\x23\xd5\xae\x92\xd2\x9b\x3f\x24\x61\xcb\x24\x28\x25\x64\xc7\x16\xd1\xfa\xbd\xc2\x0d\x03\x7f\x06\x34\x8e\xb9\xd1\x3e\x69\xc7\x13\xcc\x4e\x37\x28\xaa\x06\xc0\x53\xf0\x88\x3f\x49\x10\x3e\x0b\xcf\x3b\xe6\x72\xd7\xab\x28\xbe\x17\x3a\x35\x20\xa1\xdb\xf8\x05\xbc\x5a\x29\xef\x50\x58\xda\x24\x5f\xdd\x2a\xe2\x54\x61\x40\x2b\x02\x04\xfb\xcd\xaa\xc0\x5e\xa7\x24\x28\x07\x18\xee\x29\x17\x67\x9d\x91\x28\x51\x24\xe4\x81\x6e\x71\xf6\xed\x8a\xdc\x7f\x0a\x33\xcf\x58\x6e\x38\x19\xd6\x52\xb8\x65\x66\x16\xc0\x06\xd0\x9c\x51\xb1\x66\xe5\xc6\xa1\xf5\x5d\x9c\x1e\x25\xf6\x21\x1e\x1d\x69\x15\x77\x6b\xb6\x1c\x01\x79\x81\x9c\x90\xb9\x77\x51\x57\xa7\x62\xa1\x92\xd0\x75\x60\xcc\x12\x1f\x7a\x49\x1e\x0d\xd2\xd3\x7f\xe5\x9e\xcd\x8d\x97\xdd\x5a\x69\x75\x83\x9c\xe2\x48\x60\x30\x06\xd5\x85\xad\x27\x9a\x21\x39\x48\xce\x25\x4a\x26\x8e\x37\x4e\xe0\xeb\xf3\x2e\x7a\xe5\x54\x61\xa3\x52\xad\x47\xfe\xbd\xf1\x6f\xd2\x6d\x35\x79\x02\xe0\x53\x49\x73\xc6\x01\xfc\x5c\x51\xa8\x0d\x7f\xa2\x43\x8c\x17\x1c\x12\xae\xd6\x65\x87\xc3\x7d\x39\x21\xbc\x4c\x8c\x7d\xb6\xe6\x81\xd6\x87\xde\xaa\x41\x06\x97\x6a\x9a\x5a\xa3\xe5\x49\x66\x67\xf4\x9e\x94\x50\x39\xe4\x0f\x31\xe7\x18\xe8\x1d\x32\xa7\xcf\xbc\x29\x17\x0d\xbe\xd7\xdf\x3b\x7c\xa1\xc2\xfd\xfc\x45\xcd\x13\x3a\x9e\x6d\x2d\x18\x53\x51\xbf\xae\x56\x0a\x73\x50\xc0\x5f\xc4\xc2\x2d\x0e\x99\x2d\x17\xeb\x87\x88\x92\xe1\x52\xbd\x75\xbe\x4b\xa6\xcc\xb7\xd9\x82\x83\x42\x4b\x83\x2e\x36\xb8\x81\x7c\x96\xe8\x3d\xe0\x98\xa5\x79\xe6\xd1\x56\xf4\x0b\x7f\x4f\x5c\x61\x6c\x35\xc2\xb2\xbe\x36\x1f\xbf\x84\x10\x00\xfc\xd6\x60\x89\x9b\xde\xc3\xf5\xfb\xa4\x48\x19\x33\x27\x5d\xd0\x21\x2e\x8c\x07\x63\x5d\x02\x41\x3d\x85\x13\x08\x57\xf8\x38\x08\xf3\xf8\x6a\x4a\x3b\xad\xbc\x5c\xee\x55\xff\xdf\x9e\x24\x3b\x76\x76\x9c\xca\x9c\xea\x4a\x9f\xab\x35\xb8\x11\x2a\x51\xdf\xb7\xee\xf7\xd5\x40\xd6\x17\xd5\xa8\x28\x13\xfa\xe6\x9a\x95\xbd\x43\xd4\x35\xe3\xae\x0a\x20\xd7\x0f\x3f\x29\xb6\xb5\x38\x88\x4b\xcd\xcd\xa6\x5e\xe9\x71\x84\x97\xa9\x1b\x68\xfa\x22\x94\x4d\x7c\x8b\x2a\x17\xa8\xf9", 512);
	syscall(__NR_ioctl, r[0], 0x4b49, 0x20000000ul);
	return 0;
}