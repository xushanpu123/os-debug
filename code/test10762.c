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
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000500 = 0x20000d00;
memcpy((void*)0x20000d00, "\xd8\x28\x92\x2b\x6d\x04\x36\x85\x87\x04\x71\xe1\xdf\x9b\x4f\xc7\xeb\x31\x65\x13\xbc\xc3\x35\xba\x6a\xb4\xc4\xe2\xa2\x3e\xca\x60\x91\xa2\xf1\x35\x61\x98\x61\xd2\xe5\xb3\x43\x1b\x89\xc8\xd0\x48\x63\xff\x27\xaa\x63\x5b\x90\xda\xb4\x59\x5f\x9e\x0e\xef\x91\x74\x5a\xbc\x04\x23\x07\xf6\xa6\x68\x2f\x2a\x02\xaf\xe1\xdb\x9f\xdc\x10\xfc\x73\xe1\x0b\x57\x87\x2b\xd0\x70\x00\x7b\x7f\x81\xcc\x40\x94\x5c\xe7\xa2\xe8\x0b\x32\xb8\x72\x2f\x50\xb6\x20\xc6\xe0\x01\x0a\xed\x4b\xef\x08\x20\xa0\x26\x39\x46\x61\x04\xb0\x40\xe4\x46\xf8\x0f\xed\xfe\x62\xe0\xd0\x41\x38\x11\xb2\xc2\x58\x27\xf7\x6d\x4f\x3d\x3f\xac\x45\xf7\xa2\xd2\xa1\xf9\x5f\xfc\x65\x3a\x98\x21\xe8\x43\x73\xa9\x6a\xa1\x65\x6d\x40\xb7\x01\x1c\xec\x64\x8a\x4d\xf8\xba\x52\x34\x54\x21\x42\xfb\x90\xcb\xaa\xd3\xdc\xb0\x3f\x07\xb9\xaa\x29\xe3\xbf\xa2\x71\x62\x07\x4d\x12\x3d\xeb\xad\x93\xb1\xcb\xbf\x49\xd2\x85\xa1\xc8\x07\xb5\x30\xf7\x4d\x61\xd6\xc2\x66\x5e\x6d\x83\xfd\xcb\xf0\xb9\xe1\xf7\x5d\x0e\xba\xce\xd8\x80\x31\x0b\x57\x49\x5b\x1e\x28\xe7\x77\xdc\x3b\x67\x0e\x34\x85\x57\xbc\x1b\x11\xa8\xf1\x8d\x36\x52\x38\x09\xad\xad\xd6\x2e\xbf\x28\x2c\x9f\x62\xdb\x02\x0d\x4e\x92\x26\x13\x78\x96\xe7\xaf\x50\xe9\x23\xd2\x3d\x22\x09\xe9\x28\x2b\x50\x1c\xb0\xb8\x01\x00\x00\x00\x00\x00\x00\x00\xb2\xe3\x6c\x32\x66\x04\x56\xe7\x9e\xff\x92\x9e\xa1\x54\x40\xd5\x85\x86\xb7\x79\x1a\xab\x7a\x82\x25\xac\x5e\xed\xee\x74\x6b\x71\x94\x39\xd6\xba\x50\x72\x33\x93\x92\x18\x8a\x0f\x9e\x3f\xbf\x23\x4d\xc3\x89\x3c\x42\x06\x4c\xf6\x40\xe9\x16\xfe\x07\x43\x75\x53\x6c\x4e\xc3\x71\xf6\x6d\x97\xa2\x8a\x7f\x37\xc5\x34\x2c\xc0\x2f\x67\x91\x5e\xb5\xbf\x38\xf7\x6f\x03\x65\x22\x5b\xf7\x1c\xa2\xa7\x56\xab\x13\x5c\x95\x0e\x46\xb8\xe8\x5d\x7d\x3b\x70\x22\x9d\x2a\x88\x6c\x95\xf2\x30\xb8\x17\x16\x7f\xe8\xc2\x04\x2e\x3b\x3e\x48\x02\xd7\xea\xac\x79\xd1\xa7\xfa\xdb\x3c\x3f\x0d\x3c\x43\xed\xc8\xc2\xdc\x46\xb9\x70\x22\xdd\xfc\x7a\xf3\x93\x6b\x4f\xe9\xd4\x33\x70\x85\xab\x6a\x0b\x00\x4f\xba\xca\xe6\xaa\x73\x39\x56\x17\xad\x2c\x45\x3b\x9d\x32\x82\xe1\xa0\x62\x9d\x2d\xe0\x20\x18\x99\x63\xb5\x82\xbf\xeb\x6d\xd9\x3b\x72\x40\x17\xcf\xe9\x1f\xda\x61\x80\xda\x71\x56\xfa\x11\xdf\xb5\xb7\x13\x58\xf4\x83\xd9\x84\x11\x2e\xa9\x09\x17\x6a\x31\xef\x6f\x4c\x41\xa1\xc8\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa2\xb2\xbb\xc8\xca\x3e\x8c\x9a\x12\x5b\x77\xea\x02\x0e\x05\x74\x09\xbe\xe5\xf7\x83\x1b\x49\xcb\xd2\x3e\x05\xf3\x90\xda\x7c\xe8\x55\x20\xa4\x51\x85\x91\xed\x55\xb1\x75\xef\x85\xcf\xbd\xc6\xa5\x94\x9e\x2b\x4c\xf0\x9f\x67\x3c\x64\x11\xa0\xf6\x2b\xb6\x43\x80\x36\xb1\x87\x98\x3d\x3b\x09\xf3\xd4\xe5\xe8\x25\x56\xa3\x42\x79\x2a\x91\xa7\x6a\x2e\x7d\xda\xcb\x58\xd8\x8a\xef\xbc\xe8\xd1\x83\xff\x94\x59\xf4\x9b\x0d\x32\x6d", 656);
*(uint64_t*)0x20000508 = 0x290;
	syscall(__NR_writev, r[0], 0x20000500ul, 1ul);
	return 0;
}
