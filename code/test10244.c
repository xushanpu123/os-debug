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

#ifndef __NR_fsconfig
#define __NR_fsconfig 431
#endif
#ifndef __NR_fspick
#define __NR_fspick 433
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
syz_open_dev(0, 0x81, 0);
	syscall(__NR_io_setup, 9, 0x200000c0ul);
	syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20002c40 = -1;
	syscall(__NR_ioctl, r[0], 0x5412, 0x20002c40ul);
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = -1;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
	syscall(__NR_ioctl, -1, 0x40182103, 0x20000080ul);
memcpy((void*)0x200000c0, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x200000c0, 0, 0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, -1, 0x1276, 0ul);
	syscall(__NR_fspick, 0xffffff9c, 0ul, 0ul);
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[2] = res;
	syscall(__NR_fsconfig, -1, 5ul, 0ul, 0ul, r[2]);
	syscall(__NR_ptrace, 0x4209ul, 0, 0ul, 0ul);
memset((void*)0x20000240, 0, 32);
*(uint16_t*)0x20000260 = 0x1f;
*(uint32_t*)0x20000264 = 0xed;
*(uint32_t*)0x20000268 = 0x10000;
*(uint64_t*)0x20000270 = 0xfffffffffffffff4;
*(uint64_t*)0x20000278 = 0x80000003;
*(uint32_t*)0x20000280 = 0;
	syscall(__NR_ioctl, r[1], 0xc0481273, 0x20000240ul);
	return 0;
}