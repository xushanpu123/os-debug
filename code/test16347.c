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
memcpy((void*)0x20000040, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000040, 1, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000640 = 0x53;
*(uint32_t*)0x20000644 = 0;
*(uint8_t*)0x20000648 = 7;
*(uint8_t*)0x20000649 = 0;
*(uint16_t*)0x2000064a = 0;
*(uint32_t*)0x2000064c = 0;
*(uint64_t*)0x20000650 = 0;
*(uint64_t*)0x20000658 = 0x200004c0;
memcpy((void*)0x200004c0, "\x01\x0b\x60\x73\x57\xaa\x31", 7);
*(uint64_t*)0x20000660 = 0;
*(uint32_t*)0x20000668 = 0x9ce;
*(uint32_t*)0x2000066c = 0x10002;
*(uint32_t*)0x20000670 = 3;
*(uint64_t*)0x20000674 = 0x20000600;
*(uint8_t*)0x2000067c = 0;
*(uint8_t*)0x2000067d = 0;
*(uint8_t*)0x2000067e = 0;
*(uint8_t*)0x2000067f = 0;
*(uint16_t*)0x20000680 = 0;
*(uint16_t*)0x20000682 = 0;
*(uint32_t*)0x20000684 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000640ul);
	return 0;
}
