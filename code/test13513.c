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
*(uint64_t*)0x20001500 = 0x200015c0;
memcpy((void*)0x200015c0, "\xe0\x54\x33\x99\x28\x6c\xce\xf8\xd0\x72\x51\xd9\x49\xf4\x1d\x93\x62\x2e\x00\xef\x25\x0c\x75\x9a\x3b\x2f\x34\x28\x3b\x4f\xc3\x01\x48\x13\x7d\x84\x41\x40\x4b\xa2\x1a\x22\xef\xe1\xc4\x18\xcb\x1b\xdd\x28\x1a\xe6\xd0\xd0\xe1\xcf\x79\x1c\x32\x63\x96\xb1\x11\xd5\x7d\x9d\x53\x3a\x9c\x27\x9b\xe3\xee\x5a\x0f\x69\x7b\x3e\xd8\x92\x3e\x09\x8a\x17\xa1\xa5\xbf\xa6\xb6\x83\xad\x98\x7d\x37\x14\x66\xb1\x4c\x39\x62\x29\x60\xcd\xd1\x3c\xd6\xff\x97\x06\x88\x07\x70\x5d\x6d\x61\x1b\xb1\x65\x4f\x8b\xa5\x8e\xa2\xb6\x23\x20\x1b\xc5\x01\xf5\xee\x98\x7b\xc2\xaf\xfd\xd3\xb7\x10\x66\x41\x1d\x38\xdb\xaf\xb4\x5d\xb3\xe4\x5b\x6e\xe1\x9e\x3f\x28\xc5\xe4\x5c\x5b\x6d\x37\xe9\xce\x51\x26\x6f\x2b\xac\x8c\x62\x93\x92\x3f\x0d\xd0\xd9\x71\x85\x6c\xd4\xb1\xcf\x0b\xf1\x71\xf1\x60\xa8\xf6\x40\x44\xbb\x54\xa2\xe7\xd2\x66\xb2\x41\x39\x10\x8e\xa5\x43\xe7\x9e\xe7\x13\x93\xaf\x32\xff\xab\xb8\xc6\x0e\x1e\xb9\xee\x5e\x5b\x6a\x2a\x92\x02\xf7\xfd\xb0\x4e\xfc\x6a\xd4\x17\x86\x58\x2e\xac\x27\xde\x35\xfb\x19\x8a\xe8\x3c\xdc\x85\x82\x6e\xf0\x80\x51\xa5\xb3\x95\x59\xbe\xe2\xb7\x07\x31\xe2\x4c\xa3\xf8\x79\x2a\xfe\xb9\xa0\xab\xba\x14\x2a\xb1\xd7\xe6\x7f\x99\x2f\xb0\xdc\x65\x31\x5c\xbb\x67\x40\x3f\xdb\xdf\xa4\x33\x79\xc5\x99\x28\x56\xed\x1c\x35\x88\x9d\xb1\x4c\xc9\x41\xa0\x7b\x72\x5b\x1f\xdc\x6d\xb5\xa1\x26\xe6\xcf\x14\xbb\x30\x87\xe8\x68\x8d\x21\x7b\xd6\x85\x18\x12\xc9\x90\xec\x30\xe2\xc1\xa3\xce\xd5\xda\xcb\xbd\xb4\x25\x6f\x41\x4b\x96\x5f\xa1\xa6\x2f\xcc\xa2\x1b\xa9\xbb\x15\x57\xae\xfd\x37\x6b\xca\x37\x54\xd5\x77\xfc\x3a\xd7\x73\x92\x18\x21\xa6\xfc\x14\x33\xff\x95\x4b\xe4\x5f\xea\xe2\xf4\x8c\xb3\x5d\x69\x08\x85\x13\xe7\x7b\xcf\x0a\x63\x1c\xdd\x36\xd7\x10\xbe\xd8\x43\xc0\x5f\x7c\x73\x11\x63\xad\x04\xeb\xb4\x8e\x03\xd8\x02\x8c\xbf\x46\x4d\xd4\x16\x2b\xe2\x29\x1c\x6e\xa1\x57\x08\x00\xfc\x68\xc9\x37\x2e\xa6\x55\x04\xbf\x2b\x34\xec\xdf\xb6\x40\x1b\xfb\x47\x5e\xbe\x60\x9a\xb1\x7b\x76\x71\xcb\xed\xc0\x99\x6e\x78\x2c\x52\x1b\xbd\x94\xbb\xa7\x1b\xd0\xa0\x8e\x9d\x93\xda\xbf\x9b\x86\x6c\xee\x3d\xcd\x0c\x2d\x30\x9b\x35\x0b\x67", 498);
*(uint64_t*)0x20001508 = 0x1f2;
	syscall(__NR_writev, r[0], 0x20001500ul, 1ul);
	return 0;
}
