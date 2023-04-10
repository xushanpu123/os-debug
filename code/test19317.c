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

#ifndef __NR_close_range
#define __NR_close_range 436
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
*(uint16_t*)0x20000080 = 0;
*(uint16_t*)0x20000082 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
	syscall(__NR_fcntl, r[0], 6ul, 0x20000080ul);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[1] = res;
	syscall(__NR_close_range, -1, -1, 2ul);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[2] = res;
*(uint16_t*)0x20000180 = 0;
*(uint16_t*)0x20000182 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint32_t*)0x20000198 = 0;
	syscall(__NR_fcntl, r[2], 6ul, 0x20000180ul);
*(uint16_t*)0x20000040 = 1;
*(uint16_t*)0x20000042 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint32_t*)0x20000058 = 0;
	syscall(__NR_fcntl, r[2], 7ul, 0x20000040ul);
*(uint16_t*)0x200004c0 = 1;
*(uint16_t*)0x200004c2 = 0;
*(uint64_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0;
*(uint32_t*)0x200004d8 = 0;
	syscall(__NR_fcntl, r[1], 7ul, 0x200004c0ul);
	return 0;
}
