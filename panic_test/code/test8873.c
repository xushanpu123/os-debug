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
memcpy((void*)0x20000400, "\x23\x21\xc6\x87\xf7\xda\x29\x2a\xfe\xd7\xdd\xc0\xa7\xd5\x20\x2e\x2f\x66\x69\x71\x65\x30\x0a\x5a\xbf\xce\x8e\x53\xcb\xe5\xd5\xeb\xd0\xd5\xa3\x24\x0c\x6f\x61\x07\x98\xae\x97\xcf\x5d\xed\xc0\x17\xc9\xd4\x6b\x42\xa8\xe5\xb3\xa1\x9b\x4d\x14\x5f\xfb\xa7\x00\x5a\x04\x48\x45\xfe\xc5\x42\x73\x7b\x08\x24\x81\x06\xd3\x73\x8f\x36\xff\xa3\xb8\x3e\xa0\x20\x99\x26\x58\xc2\xc7\xda\x92\x8c\x78\x6a\xb1\x83\x66\x14\x26\x5b\xbb\x7d\xb2\x27\x96\x36\xac\x52\x5f\x6b\xa6\x6f\xfb\xc3\x01\x4e\xba\x10\xe2\x9f\x62\xd6\x9e\x12\x90\xd0\xa4\xd4\x63\x8c\x4c\xf4\xc9\x76\xe9\xa0\xc4\x84\xb6\x7c\xf0\x57\x97\x96\x65\x3d\xd1\xc1\xf9\x0e\x32\x41\x03\x74\x68\xd1\x18\xbb\x52\xee\xde\xa3\x01\x26\x96\xf8\x93\x27\x63\x08\x3c\x09\x00\x8e\x42\x7a\x8c\x09\x63\x44\x40\x88\x6d\x70\x8d\x7e\x01\x1e\xfd\x18\xb8\x71\x35\x21\x68\x64\xef\xcb\x70\x56\x2c\x32\x79\xd3\xb4\x00\xd9\x8b\x9e\x42\x78\x5d\x3c\x72\x66\xab\x1b\x38\xfb\x44\x38\xa3\x3a\x93\x62\x09\x36\xac\xc1\x5e\x47\x4f\x95\x81\x58\x95\x54\x9b\x31\x4b", 242);
	syscall(__NR_write, r[0], 0x20000400ul, 0x29eul);
	return 0;
}
