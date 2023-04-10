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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

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
	syscall(__NR_ioctl, r[0], 0x540a, 0ul);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[1] = res;
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[2] = res;
*(uint8_t*)0x20000140 = 0x7f;
*(uint8_t*)0x20000141 = 0x45;
*(uint8_t*)0x20000142 = 0x4c;
*(uint8_t*)0x20000143 = 0x46;
*(uint8_t*)0x20000144 = 0;
*(uint8_t*)0x20000145 = 0x80;
*(uint8_t*)0x20000146 = 0;
*(uint8_t*)0x20000147 = 0x30;
*(uint64_t*)0x20000148 = 0;
*(uint16_t*)0x20000150 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint32_t*)0x20000154 = 0;
*(uint32_t*)0x20000158 = 0;
*(uint32_t*)0x2000015c = 0x38;
*(uint32_t*)0x20000160 = 0;
*(uint32_t*)0x20000164 = 0;
*(uint16_t*)0x20000168 = 0;
*(uint16_t*)0x2000016a = 0x20;
*(uint16_t*)0x2000016c = 0;
*(uint16_t*)0x2000016e = 0;
*(uint16_t*)0x20000170 = 0;
*(uint16_t*)0x20000172 = 0xfeff;
*(uint32_t*)0x20000178 = 0;
*(uint32_t*)0x2000017c = 0;
*(uint32_t*)0x20000180 = 0;
*(uint32_t*)0x20000184 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000194 = 0;
	syscall(__NR_write, r[2], 0x20000140ul, 0x58ul);
*(uint32_t*)0x20000100 = r[1];
*(uint16_t*)0x20000104 = 0;
*(uint16_t*)0x20000106 = 0;
	syscall(__NR_poll, 0x20000100ul, 1ul, 0x3f);
	syscall(__NR_ioctl, r[0], 0x540a, 1ul);
	return 0;
}
