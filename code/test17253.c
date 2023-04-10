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

uint64_t r[5] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000180, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000180, 1, 0);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ioctl, r[0], 0x1274, 0ul);
memcpy((void*)0x20000000, "/dev/vcsa#\000", 11);
syz_open_dev(0x20000000, 0x81, 0x88341);
memcpy((void*)0x20000400, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000400, 0, 0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_sendmsg, r[1], 0ul, 0ul);
*(uint64_t*)0x200000c0 = 2;
	syscall(__NR_ioctl, r[1], 0x1277, 0x200000c0ul);
memcpy((void*)0x20000400, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000400, 0, 0);
	if (res != -1)
		r[2] = res;
	syscall(__NR_sendmsg, r[2], 0ul, 0ul);
memcpy((void*)0x20000040, "/dev/vcsa#\000", 11);
syz_open_dev(0x20000040, 0x400, 0x60102);
memcpy((void*)0x20000080, "/dev/vcsa#\000", 11);
syz_open_dev(0x20000080, 4, 0xc0000);
memcpy((void*)0x20000400, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000400, 0, 0);
	if (res != -1)
		r[3] = res;
	syscall(__NR_sendmsg, r[3], 0ul, 0ul);
memcpy((void*)0x20000400, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000400, 0, 0);
	if (res != -1)
		r[4] = res;
	syscall(__NR_sendmsg, r[4], 0ul, 0ul);
	syscall(__NR_ioctl, r[4], 0x1275, 0ul);
	syscall(__NR_ioctl, r[0], 0x1276, 0ul);
	return 0;
}
