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
memcpy((void*)0x200000c0, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x200000c0, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000800 = 0x53;
*(uint32_t*)0x20000804 = 0;
*(uint8_t*)0x20000808 = 6;
*(uint8_t*)0x20000809 = 0;
*(uint16_t*)0x2000080a = 0;
*(uint32_t*)0x2000080c = 0;
*(uint64_t*)0x20000810 = 0;
*(uint64_t*)0x20000818 = 0x20000740;
memcpy((void*)0x20000740, "\x5f\x97\x43\x6c\xdc\x07", 6);
*(uint64_t*)0x20000820 = 0;
*(uint32_t*)0x20000828 = 8;
*(uint32_t*)0x2000082c = 0;
*(uint32_t*)0x20000830 = 0;
*(uint64_t*)0x20000834 = 0;
*(uint8_t*)0x2000083c = 0;
*(uint8_t*)0x2000083d = 0;
*(uint8_t*)0x2000083e = 0;
*(uint8_t*)0x2000083f = 0;
*(uint16_t*)0x20000840 = 0;
*(uint16_t*)0x20000842 = 0;
*(uint32_t*)0x20000844 = 0;
*(uint32_t*)0x20000848 = 0;
*(uint32_t*)0x2000084c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000800ul);
	return 0;
}
