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
memcpy((void*)0x200002c0, "./file0\000", 8);
	syscall(__NR_creat, 0x200002c0ul, 0ul);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_epoll_create, 0x200000);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x200001c0, "./file0\000", 8);
memcpy((void*)0x20000240, "9p\000", 3);
memcpy((void*)0x20000380, "trans=fd,", 9);
memcpy((void*)0x20000389, "rfdno", 5);
*(uint8_t*)0x2000038e = 0x3d;
sprintf((char*)0x2000038f, "0x%016llx", (long long)r[1]);
*(uint8_t*)0x200003a1 = 0x2c;
memcpy((void*)0x200003a2, "wfdno", 5);
*(uint8_t*)0x200003a7 = 0x3d;
sprintf((char*)0x200003a8, "0x%016llx", (long long)r[2]);
*(uint8_t*)0x200003ba = 0x2c;
*(uint8_t*)0x200003bb = 0;
	syscall(__NR_mount, 0ul, 0x200001c0ul, 0x20000240ul, 0ul, 0x20000380ul);
	return 0;
}
