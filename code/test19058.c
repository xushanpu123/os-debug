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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000000;
memcpy((void*)0x20000000, "/dev/vcsa#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_fcntl, r[1], 0ul, r[1]);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000680 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint64_t*)0x20000690 = 0;
*(uint64_t*)0x20000698 = 0;
*(uint64_t*)0x200006a0 = 0x200005c0;
*(uint64_t*)0x200005c0 = 0x14;
*(uint32_t*)0x200005c8 = 1;
*(uint32_t*)0x200005cc = 1;
*(uint32_t*)0x200005d0 = r[2];
*(uint64_t*)0x200006a8 = 0x18;
*(uint32_t*)0x200006b0 = 0;
*(uint32_t*)0x200006b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000680ul, 1ul, 0ul);
	return 0;
}