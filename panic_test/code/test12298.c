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
memcpy((void*)0x20000500, "\x2a\xd9\x42\x73\xca\x1c\x13\xad\x44\x2f\xd7\xa8\x55\xaf\x2c\x62\xb1\x2d\xe4\x9f\xdc\x01\x26\xa0\xf8\x29\x9d\x18\x1b\x4b\xe0\xfe\x35\x70\x76\x6a\xd8\x65\x6a\xd1\xf1\xe5\x6c\x91\x99\x8a\x2c\xd7\x5b\x1d\x25\xfa\x23\x97\xe5\x26\x26\x0f\xfb\xf5\x44\xb2\x6d\x6c\x26\x5e\x2a\xba\xa7\xb7\xac\xd7\xdf\x29\xd6\x6d\x68\x42\x75\xb0\x1b\xbb\x5a\xdf\x63\xcf\xf2\x33\x40\x55\x8f\xe3\x10\xc9\x5d\xea\x89\x8f\x9c\xcc\x1b\x38", 102);
	syscall(__NR_write, r[0], 0x20000500ul, 0xffd5ul);
	return 0;
}
