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

#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
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
memcpy((void*)0x20000000, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x50f640ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20002580, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20002580ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0x4c80, 2ul);
	syscall(__NR_ioctl, r[0], 0xd000943e, 0ul);
	syscall(__NR_ioctl, r[0], 0xd000943e, 0ul);
memcpy((void*)0x20000040, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x202ul, 0ul);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000080 = -1;
	syscall(__NR_io_uring_register, r[2], 4ul, 0x20000080ul, 1ul);
*(uint64_t*)0x200001c0 = 0x20000100;
*(uint16_t*)0x20000100 = 0x10;
*(uint16_t*)0x20000102 = 0;
*(uint32_t*)0x20000104 = 0;
*(uint32_t*)0x20000108 = 0x2000000;
*(uint32_t*)0x200001c8 = 0xc;
*(uint64_t*)0x200001d0 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000140;
*(uint32_t*)0x20000140 = 0x2c;
*(uint16_t*)0x20000144 = 0;
*(uint16_t*)0x20000146 = 0x400;
*(uint32_t*)0x20000148 = 0x70bd27;
*(uint32_t*)0x2000014c = 0x25dfdbfb;
*(uint8_t*)0x20000150 = 1;
*(uint8_t*)0x20000151 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint32_t*)0x20000154 = 0;
*(uint16_t*)0x20000158 = 0x4102;
*(uint16_t*)0x2000015a = 0;
*(uint16_t*)0x2000015c = htobe16(0x10);
*(uint16_t*)0x2000015e = htobe16(0x13);
memcpy((void*)0x20000160, "udp:syz2\000", 9);
*(uint64_t*)0x20000188 = 0x2c;
*(uint64_t*)0x200001d8 = 1;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0x4000000;
	syscall(__NR_sendmsg, r[2], 0x200001c0ul, 1ul);
	syscall(__NR_ioctl, r[0], 0x4c82, 0);
memcpy((void*)0x200000c0, "/dev/vcsu#\000", 11);
syz_open_dev(0x200000c0, 0xe3d0, 0);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	return 0;
}
