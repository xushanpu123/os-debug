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
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000840 = 0x53;
*(uint32_t*)0x20000844 = 0;
*(uint8_t*)0x20000848 = 0;
*(uint8_t*)0x20000849 = 0;
*(uint16_t*)0x2000084a = 0;
*(uint32_t*)0x2000084c = 0;
*(uint64_t*)0x20000850 = 0;
*(uint64_t*)0x20000858 = 0x20000700;
*(uint64_t*)0x20000860 = 0;
*(uint32_t*)0x20000868 = 0;
*(uint32_t*)0x2000086c = 0;
*(uint32_t*)0x20000870 = 0;
*(uint64_t*)0x20000874 = 0;
*(uint8_t*)0x2000087c = 0;
*(uint8_t*)0x2000087d = 0;
*(uint8_t*)0x2000087e = 0;
*(uint8_t*)0x2000087f = 0;
*(uint16_t*)0x20000880 = 0;
*(uint16_t*)0x20000882 = 0;
*(uint32_t*)0x20000884 = 0;
*(uint32_t*)0x20000888 = 0;
*(uint32_t*)0x2000088c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000840ul);
	return 0;
}