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
res = syz_open_dev(0x20000040, 0, 0x482);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000280 = 0x53;
*(uint32_t*)0x20000284 = 0;
*(uint8_t*)0x20000288 = 0x21;
*(uint8_t*)0x20000289 = 3;
*(uint16_t*)0x2000028a = 0;
*(uint32_t*)0x2000028c = 0x3b;
*(uint64_t*)0x20000290 = 0x20000000;
*(uint64_t*)0x20000298 = 0x20000080;
memcpy((void*)0x20000080, "\xae\x95\xea\x2f\xbe\x5f\x67\x80\x96\xfc\x79\x5f\xed\xb1\x0c\x96\xd6\xb5\x86\x19\xd4\x7c\xc7\xd6\x6e\x15\xec\xc6\x0e\x8a\xe8\x7d\x9d", 33);
*(uint64_t*)0x200002a0 = 0x20000180;
*(uint32_t*)0x200002a8 = 0xe;
*(uint32_t*)0x200002ac = 0;
*(uint32_t*)0x200002b0 = 0;
*(uint64_t*)0x200002b4 = 0;
*(uint8_t*)0x200002bc = 0;
*(uint8_t*)0x200002bd = 0;
*(uint8_t*)0x200002be = 0;
*(uint8_t*)0x200002bf = 0;
*(uint16_t*)0x200002c0 = 0;
*(uint16_t*)0x200002c2 = 0;
*(uint32_t*)0x200002c4 = 0;
*(uint32_t*)0x200002c8 = 0;
*(uint32_t*)0x200002cc = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000280ul);
	return 0;
}
