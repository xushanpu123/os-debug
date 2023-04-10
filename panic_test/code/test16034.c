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

#ifndef __NR_open_tree
#define __NR_open_tree 428
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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = -1;
res = syz_open_dev(0xc, 4, 4);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_io_setup, 4, 0x20000000ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000000;
	syscall(__NR_pwritev, -1, 0ul, 0ul, 0, 0);
memcpy((void*)0x20000000, "/dev/nvram\000", 11);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
syz_open_dev(0xc, 4, 0x15);
	syscall(__NR_ioctl, -1, 0x5410, 0ul);
	syscall(__NR_open_tree, -1, 0ul, 0ul);
	syscall(__NR_pwritev, -1, 0ul, 0ul, 0, 0);
*(uint64_t*)0x20001400 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint16_t*)0x20000110 = 0;
*(uint16_t*)0x20000112 = 0;
*(uint32_t*)0x20000114 = r[0];
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint32_t*)0x2000013c = -1;
	syscall(__NR_io_submit, r[1], 1ul, 0x20001400ul);
	return 0;
}
