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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "/dev/input/event#\000", 18);
	res = -1;
res = syz_open_dev(0x20000000, 1, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000080 = 0x77359400;
*(uint64_t*)0x20000088 = 0;
*(uint16_t*)0x20000090 = 1;
*(uint16_t*)0x20000092 = 0x73;
*(uint32_t*)0x20000094 = 2;
	syscall(__NR_write, r[0], 0x20000080ul, 0x76ul);
*(uint32_t*)0x200000c0 = r[0];
*(uint16_t*)0x200000c4 = 0;
*(uint16_t*)0x200000c6 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0x3938700;
	syscall(__NR_ppoll, 0x200000c0ul, 1ul, 0x20000100ul, 0ul, 0ul);
	return 0;
}
