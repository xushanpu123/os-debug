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
memcpy((void*)0x20000180, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000180, 0x1ff, 0xe8001);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000140 = 0x20000000;
memcpy((void*)0x20000000, "\x83\xb6\x77\x9a\x87\x28\xa7\x3d\xfe\x09\x9f\x92\x78\xc9\xd6\x88\x0f\xfb\x9f\x39\xd7\x5f\x64\x52\x51\xfd\xa8\x30\x20\x4e\x2c\xa9\x1f\x59\xf2\xf0\xeb\x4d\x66\x87\x17\x22\xef\x00\x33\x18\x85\xae\x91\x8d\xf1\x23\x3d\x66\xe5\x71\x43\x59\xe8\xa0\x73\x49\x3a\xa8\xce\xfe\xb0\x7f\x52\x34\xee\x04\xed\x9d\x97\xc7\x31\x98\x41\xe4\x92\x48\x62\xff\x89\x2e\x3b\x27\xdc\x39\x0e\xc5\xf9\xe6\xba\xd4\x8d\xde\x29\xbc\x9f\x9a\x16\xae\x26\xb6\xee\x04\x94\x36\x74\x06\x29\x95\xaf\x2d\x87\xeb\x96\x92\x26\x6c\xd5\x48\x21\xd7\xb9\x47\x3a\x30\xdd\x1c\xeb\x6b\x17\xfb\xd2\x5a\x03\x09\xb2\x0f\x01\x7e\xf9\xbb\x9b\xd8\x11\x3b\x36\x05\xd7\xbf\xe1\x21\xef\x87\x07\x89\x59\xda\xa4\x60\xe5\x87", 166);
*(uint64_t*)0x20000148 = 0xa6;
	syscall(__NR_writev, r[0], 0x20000140ul, 1ul);
	return 0;
}
