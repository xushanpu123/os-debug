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
	syscall(__NR_setreuid, 0xee01, 0xee01);
*(uint8_t*)0x20000000 = 0;
memcpy((void*)0x20000001, "\x60\xca\x8f\x85\x30\x7e\x0a\x8d\xed\x5d\x08\xba\xca\xea\x0a\xfe\xd9\xab\x91\xb7\x74\xb5\x22\x58\x5e\xc9\x9b\xca\xb2\x6b\x1e\xbf\x07\x17\x98\x1c\xa4\x85\xce\x39\x05\x25\xeb\x44\x1d\x21\xa5\x30\x8f\x1a\x3e\x3d\xc1\xd3\x62\x4c\xab\xd8\x18\x72\xf3\xfc\x11\xa9\x98\x9b\x93\x98\xc5\x34\xa3\x3f\x6e\xc4\x62\xde\x0f\xfb\x2f\x2f\xf4\x2c\xaf\x5e\xc0\x7e\x0a\xf3\xd6\x43\x09\x6e\xc4\xfb\x3e\xfb\xed\x3f\x75\x74\xfe\x76\x7c\xd8\xc2\xe8\x6a\x96\x68\x01\x74\xbd\x81\x05\xdd\x1e\x9e\xd7\xa6\x36\x25\x7a\xd9\x52\xce\xa4\xce\x6f\xd0\xf0\xcd\xed\xb9\xe5\x4d\xf2\xa5\x83\xe5\x67\x3e\x60\x40\x32\xd7\x98\x2b\xf9\xf9\xb1\x1b\x02\xca\x3d\x14\x5f\xba\x7e\x77\xa2\xa3\x13\x88\x58\xa8\x9b\xa7\xc5\x37\xa5\x88\xe9\x89\x2a\xd8\xb8\x5d\x29\x57\x6f\x74\xdd\x42\x9f\xf9\xb2\xdb\x2c\xfd\x7c\x7f\x52\x0c\x22\x23\x40\x29\x0e\x85\xc9\x0c\xf8\x15\x68\x21\xd6\xa2\x12\x16\xd2\xec\x3d\xfe\xbc\x96\x46\xf0\x64\xf3\x57\xe9\x8c\xa7\xce\xcc\x1b\x6c\x3b\x9d\x3e\x19\x32\x08\xa0\x03\x2f\x1a\xa1\x0b\xd7\xcb\xa6\x53\xc5\x52\xd8\xe2\x0d\xed\xf9\x4a\x90\x6a\xed\xe1\x29\xe5\x22\x89\x37\xa7\x93\xcb\xc4\x07\x45\x15\xf8\xc3\xcf\x33\xdb\x8f\x5c\x1d\xa9\x08\xf8\x5c\xa0\x1b\x39\xf7\xe9\x30\x1f\xe6\x09\xb3\x4c\xa3\x14\xfe\x3e\x55\x1d\xa5\xee\x8d\xf3\xa6\x4a\xb6\x50\xdb\xd6\x76\x07\x45\x9e\x4d\x6d\xc8\x8a\x02\x71\x5a\x72\xc1\xa3\x30\x80\x97\xd0\x56\xc2\x12\xba\xdd\x80\x87\xdf\xde\x1c\xf9\xf8\xf3\x6f\x3c\x0c\x72\x8d\x34\x2f\xec\xe1\x0d\xde\xf9\xec\x76\x67\xf2\x91\xaa\xce\x80\x65\x3e\xd5\x70\xbb\xc7\xd8\x4e\x16\x04\xc7\x0b\x2a\xb3\x79\x93\x6c\x64\x04\xd5\x16\x4f\x25\xa2\x63\xa1\xd9\xf9\x0b\x9f\x06\xcb\x35\xe6\x73\x4a\x41\x06\x3b\xc1\x19\x23\x08\xfa\x2e\xb5\x09\xe4\xc8\xc4\x04\x5c\x18\x62\x58\xda\x91\xdd\xc9\x84\xdf\x01\xf3\x76\x23\xaf\x20\xac\x58\x54\x8b\x10\x3c\xf6\xe7\x4c\x8c\x69\x2d\xfb\x19\x2d\x31\x39\x6c\xf8\x43\xc7\x9f\xf9\xbd\x4e\x7b\x34\xcb\xd3\x7b\x68\x22\xe1\xd7\x7c\xdb\xfb\xb0\x92\x15\xfa\x89\xf5\xf4\xf0\x3d\x3a\xb2\xf1\xa0\x51\xba\x68\x9e\xcb\xe2\x18\x55\x5f\x6b\x43\x18\x89\x2a\xab\x21\xed\x5d\xe2\x4e\x48\xbb\xe0\x73\xf7\xbf\x4f\x37\x73\x75\x72\x86\x68\xf8\x92\x83\x0a\x02", 512);
	syscall(__NR_ioctl, r[0], 0x4b48, 0x20000000ul);
	return 0;
}
