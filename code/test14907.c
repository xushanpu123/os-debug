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

#ifndef __NR_seccomp
#define __NR_seccomp 317
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

uint64_t r[3] = {0xffffffffffffffff, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint16_t*)0x20000340 = 1;
*(uint64_t*)0x20000348 = 0x20000300;
*(uint16_t*)0x20000300 = 6;
*(uint8_t*)0x20000302 = 0;
*(uint8_t*)0x20000303 = 0;
*(uint32_t*)0x20000304 = 0x7fc00002;
	res = syscall(__NR_seccomp, 1ul, 8ul, 0x20000340ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
syz_open_dev(0x20000000, 0, 0);
	res = syscall(__NR_ioctl, r[0], 0xc0502100, 0x20000200ul);
	if (res != -1)
r[1] = *(uint64_t*)0x20000200;
*(uint64_t*)0x20000080 = r[1];
*(uint64_t*)0x20000088 = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
	syscall(__NR_ioctl, r[0], 0xc0182101, 0x20000080ul);
	res = syscall(__NR_ioctl, r[0], 0xc0502100, 0x20000100ul);
	if (res != -1)
r[2] = *(uint64_t*)0x20000100;
*(uint64_t*)0x200000c0 = r[2];
*(uint32_t*)0x200000c8 = 1;
*(uint32_t*)0x200000cc = r[0];
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d4 = 0;
	syscall(__NR_ioctl, r[0], 0x40182103, 0x200000c0ul);
*(uint64_t*)0x20000180 = r[2];
*(uint64_t*)0x20000188 = 0;
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000194 = 0;
	syscall(__NR_ioctl, r[0], 0xc0182101, 0x20000180ul);
	return 0;
}
