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
memcpy((void*)0x20001700, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20001700, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000680 = 0x53;
*(uint32_t*)0x20000684 = 0;
*(uint8_t*)0x20000688 = 0x21;
*(uint8_t*)0x20000689 = 9;
*(uint16_t*)0x2000068a = 0;
*(uint32_t*)0x2000068c = 0;
*(uint64_t*)0x20000690 = 0;
*(uint64_t*)0x20000698 = 0x20000480;
memcpy((void*)0x20000480, "\x5b\x03\x17\xb9\xe2\x29\x51\xd0\x76\x12\x53\xe3\xa5\xcf\x60\x3f\x94\x14\x43\x51\xfd\x78\xdc\xbd\x5a\x22\x0b\xc8\x22\x2e\x20\xde\xca", 33);
*(uint64_t*)0x200006a0 = 0x20000580;
*(uint32_t*)0x200006a8 = 0;
*(uint32_t*)0x200006ac = 0;
*(uint32_t*)0x200006b0 = 0;
*(uint64_t*)0x200006b4 = 0;
*(uint8_t*)0x200006bc = 0;
*(uint8_t*)0x200006bd = 0;
*(uint8_t*)0x200006be = 0;
*(uint8_t*)0x200006bf = 0;
*(uint16_t*)0x200006c0 = 0;
*(uint16_t*)0x200006c2 = 0;
*(uint32_t*)0x200006c4 = 0;
*(uint32_t*)0x200006c8 = 0;
*(uint32_t*)0x200006cc = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000680ul);
	return 0;
}
