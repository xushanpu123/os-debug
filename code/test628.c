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
memcpy((void*)0x20000340, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000340, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200003c0 = 0x53;
*(uint32_t*)0x200003c4 = 0;
*(uint8_t*)0x200003c8 = 6;
*(uint8_t*)0x200003c9 = 0;
*(uint16_t*)0x200003ca = 0;
*(uint32_t*)0x200003cc = 0;
*(uint64_t*)0x200003d0 = 0;
*(uint64_t*)0x200003d8 = 0x20000200;
memcpy((void*)0x20000200, "\x1a\xe6\x17\x1c\xb5\x42", 6);
*(uint64_t*)0x200003e0 = 0;
*(uint32_t*)0x200003e8 = 0;
*(uint32_t*)0x200003ec = 0;
*(uint32_t*)0x200003f0 = 0;
*(uint64_t*)0x200003f4 = 0;
*(uint8_t*)0x200003fc = 0;
*(uint8_t*)0x200003fd = 0;
*(uint8_t*)0x200003fe = 0;
*(uint8_t*)0x200003ff = 0;
*(uint16_t*)0x20000400 = 0;
*(uint16_t*)0x20000402 = 0;
*(uint32_t*)0x20000404 = 0;
*(uint32_t*)0x20000408 = 0;
*(uint32_t*)0x2000040c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x200003c0ul);
	return 0;
}