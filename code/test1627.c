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
	res = -1;
res = syz_open_dev(0xc, 4, 4);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000040 = 0x7f;
*(uint8_t*)0x20000041 = 0x45;
*(uint8_t*)0x20000042 = 0x4c;
*(uint8_t*)0x20000043 = 0x46;
*(uint8_t*)0x20000044 = 0;
*(uint8_t*)0x20000045 = 0;
*(uint8_t*)0x20000046 = 0;
*(uint8_t*)0x20000047 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint16_t*)0x20000050 = 0;
*(uint16_t*)0x20000052 = 0;
*(uint32_t*)0x20000054 = 0;
*(uint32_t*)0x20000058 = 0;
*(uint32_t*)0x2000005c = 0x38;
*(uint32_t*)0x20000060 = 0;
*(uint32_t*)0x20000064 = 0;
*(uint16_t*)0x20000068 = 0;
*(uint16_t*)0x2000006a = 0x20;
*(uint16_t*)0x2000006c = 0;
*(uint16_t*)0x2000006e = 0;
*(uint16_t*)0x20000070 = 0;
*(uint16_t*)0x20000072 = 0;
*(uint32_t*)0x20000078 = 0;
*(uint32_t*)0x2000007c = 0;
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
memcpy((void*)0x20000098, "\x36\x1e\x8b\xc6\xca\xdf", 6);
	syscall(__NR_write, r[0], 0x20000040ul, 0x5eul);
	return 0;
}
