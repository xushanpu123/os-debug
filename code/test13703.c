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

#ifndef __NR_fspick
#define __NR_fspick 433
#endif
#ifndef __NR_openat2
#define __NR_openat2 437
#endif
#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20001640, "./file0\000", 8);
*(uint64_t*)0x20001680 = 0x41;
*(uint64_t*)0x20001688 = 0;
*(uint64_t*)0x20001690 = 0;
	res = syscall(__NR_openat2, 0xffffff9c, 0x20001640ul, 0x20001680ul, 0x18ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000380 = 0x20000180;
memset((void*)0x20000180, 112, 1);
*(uint64_t*)0x20000388 = 1;
	syscall(__NR_pwritev2, r[0], 0x20000380ul, 1ul, 0x10000, 0x10001, 0ul);
memcpy((void*)0x200001c0, "./file0\000", 8);
	syscall(__NR_fspick, r[0], 0x200001c0ul, 0ul);
memcpy((void*)0x20000040, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000040, 0, 1);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0x4c00, r[0]);
	return 0;
}
