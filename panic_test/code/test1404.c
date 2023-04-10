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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 1, 0x20000140ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000140;
memcpy((void*)0x200000c0, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x200000c0, 0, 0);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200003c0 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint16_t*)0x20000110 = 5;
*(uint16_t*)0x20000112 = 0;
*(uint32_t*)0x20000114 = r[1];
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint32_t*)0x2000013c = -1;
*(uint64_t*)0x200003c8 = 0x20000000;
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint16_t*)0x20000010 = 0;
*(uint16_t*)0x20000012 = 0x56bb;
*(uint32_t*)0x20000014 = r[1];
*(uint64_t*)0x20000018 = 0;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint64_t*)0x20000030 = 0;
*(uint32_t*)0x20000038 = 2;
*(uint32_t*)0x2000003c = -1;
	syscall(__NR_io_submit, r[0], 2ul, 0x200003c0ul);
	return 0;
}
