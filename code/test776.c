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
memcpy((void*)0x20000001, "\xcc\xc8\x35\xbc\x38\xe3\x41\x39\xe6\x44\xd1\x14\x3a\xcc\x5b\x0b\xb2\xfe\xe0\x19\xe3\x41\x3a\xf1\xda\x6b\x53\x16\xd7\x81\xdf\xe6\xa1\x68\xfb\x2a\xaf\xf9\x16\x05\xbf\x25\x7f\x27\xac\x74\xe2\xa3\x50\xb6\x17\x42\x06\x44\x61\xb5\x48\x16\x78\x14\x78\xe2\x17\x92\xf1\xfc\xe2\xbc\x2a\xc6\x89\x40\x7b\x77\x4c\x45\x88\x9c\x0f\x70\xc5\x5f\x33\x33\xe1\x61\xa9\x15\x64\x2f\x3b\xc5\x5c\x0d\xfc\x3b\x81\x64\xd2\xef\x02\xfa\xf5\x4d\xa0\xb4\xe9\xc3\x2a\x15\x0e\xa0\x38\xa6\x10\x08\x04\x32\xaf\x1c\x3d\x85\xd4\xf3\xcd\x35\xd8\xf5\x89\x36\x32\x96\x24\x5b\xad\xbd\xae\x5f\x06\x03\xb5\x67\x79\xeb\x63\x83\x79\x35\x50\xce\xf1\xb5\x52\x4a\x8e\xbe\x36\x77\xe9\x4d\xc4\x33\x13\xd5\xb7\x8c\x69\x92\xa1\xeb\xba\x30\x44\x8e\xe4\xe5\xeb\xa7\x45\x37\xc7\x43\xa9\x42\xc6\x2b\xc3\x48\x7b\x94\x4c\x98\xa2\x2b\x0b\x8e\xc7\x84\x28\x3a\x8d\xc6\x50\x6f\x5c\x9b\xa2\x6f\x66\xf7\x14\xd5\x1e\xc0\x89\x2b\x47\xb9\x9f\xcb\xe3\x72\xbe\x61\xf7\x31\x72\x29\x32\x1e\x62\xce\xd3\xf1\x57\xa0\x65\xdd\x6d\x40\xf0\xe3\xa8\x20\x7e\x76\x38\xe0\x09\xd3\x5a\xe0\xa6\x46\xc8\xcf\xb3\x28\xd1\xed\x8a\x44\x59\xdc\x45\x90\x43\x4a\x0d\x04\x8f\x34\x7a\xa1\x08\x24\xff\x80\xb9\xae\xc8\x59\x85\x96\x6c\x2e\x4d\xfb\xfd\x0a\x15\x6b\x04\xfe\x29\xa6\x5b\x05\xfa\x78\x25\xf4\x2a\xd0\xd2\xb5\x80\x85\x30\xbd\x50\x3b\x8d\x89\x4b\x80\x5d\x55\xf2\xa3\x6e\x15\x51\x2b\xa0\x4e\xb9\xcd\xc3\x27\xb9\x7b\xba\x6f\xe4\xf1\xb1\x13\xac\x62\x6a\xa1\x4b\xfe\xbe\x29\x82\x3a\xcf\xc8\x8e\xa1\x1a\xd0\x37\x77\x12\x1f\xa8\xd8\x18\xc0\xed\x98\x43\x73\xec\x35\x84\x46\x35\x21\xe1\x82\xe8\x11\xee\x5c\x70\x0c\x1b\xed\x7d\xed\x34\x70\x43\x80\xc2\x5e\x4b\x9e\x1c\xf8\xcf\x1f\x3c\x51\x6e\xac\x93\x03\xef\x43\xa3\xa0\xc0\xaf\x6f\x13\x94\x88\xc9\x57\xb5\x5c\xa9\x3f\x9a\x55\x58\xf4\xbd\xbb\xc7\xcb\x19\xe8\xea\x5a\x47\x57\x48\xfc\x79\xa8\x1e\x68\xb4\x5c\x5c\xa4\x24\x37\x3f\xee\xa0\x8f\xb7\x42\xa3\xb7\xc7\x76\x79\xf5\xa6\x15\x13\x03\x96\x6b\x5d\x1a\xd0\xcd\x75\x89\x68\x86\x67\xf8\x53\x63\x90\x70\xac\x61\x08\x9d\xc8\xf4\x7f\x69\x09\x9d\x47\x7e\xb4\xae\x6b\x98\x5b\x55\xee\xd5\x3f\x6b\xe6\x72\x05\x88\x45\x1d\xb0\xae\xac\xa8\x1e\x4f\xb3\xcb", 512);
	syscall(__NR_ioctl, r[0], 0x4b49, 0x20000000ul);
	return 0;
}