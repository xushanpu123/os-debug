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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_ioctl, -1, 0x80e85411, 0x200001c0ul);
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000000, 1, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_pipe2, 0x20000480ul, 0ul);
	if (res != -1) {
r[1] = *(uint32_t*)0x20000480;
r[2] = *(uint32_t*)0x20000484;
	}
	syscall(__NR_ioctl, r[1], 0x80045200, 0ul);
	syscall(__NR_ioctl, r[1], 0x7002, 0);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
*(uint32_t*)0x20000700 = 0;
*(uint32_t*)0x20000704 = 0xff;
*(uint32_t*)0x20000708 = 9;
	syscall(__NR_ioctl, r[0], 1, 0x20000700ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[3] = res;
	syscall(__NR_sendmsg, r[3], 0ul, 0x240c2820ul);
	syscall(__NR_sendmsg, r[2], 0ul, 0x44001ul);
	return 0;
}
