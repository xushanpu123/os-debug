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
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0x8482);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000040 = 0x7f;
*(uint8_t*)0x20000041 = 0x45;
*(uint8_t*)0x20000042 = 0x4c;
*(uint8_t*)0x20000043 = 0x46;
*(uint8_t*)0x20000044 = 0;
*(uint8_t*)0x20000045 = 0;
*(uint8_t*)0x20000046 = 0;
*(uint8_t*)0x20000047 = 7;
*(uint64_t*)0x20000048 = 8;
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
*(uint16_t*)0x20000070 = 0xc61;
*(uint16_t*)0x20000072 = 5;
*(uint32_t*)0x20000078 = 6;
*(uint32_t*)0x2000007c = 3;
*(uint32_t*)0x20000080 = 3;
*(uint32_t*)0x20000084 = 0x300000;
*(uint32_t*)0x20000088 = 0x400;
*(uint32_t*)0x2000008c = 0x80;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
memcpy((void*)0x20000098, "\x5e\x59\x49\xd4\x23\x4b\xbe\x60\x80\x5f\xac\x4d\xef\xb6\xaf\x22\x92\x22\x64\x9c\x07\x43\x74\xec\xbe\xf8\x3f\x88\x56\xf7\x94\x52\x86\xc1\xa1\xfd\x57\xf8\x73\xdc\x9d\x47\x9c\x25\x96\xe7\xb5\xc8\x20\xc5\xd1\x3f\x48\x26\x5e\x59\x4b\xb7\x39\x4e\x3b\x00\x82\xec\x32\xcb\xe4\x4d\x9f\xa5\x0e\x05\x28\x6e\x9b\x17\xd4\x42\xdc\x34\xe5\xb0\x1f\xb3\x22\xb1\x5d\x7c\xbb\x2e\x33\xc2\xcf\xe9\x3c\x21\x40\x27\xaa\xd6\x69\x13\xef\xfe\xf5\xed\x58\x5e\x1e\x96\xa5\x19\xe0\xdc", 114);
memset((void*)0x2000010a, 0, 256);
memset((void*)0x2000020a, 0, 256);
memset((void*)0x2000030a, 0, 256);
memset((void*)0x2000040a, 0, 256);
memset((void*)0x2000050a, 0, 256);
	syscall(__NR_write, r[0], 0x20000040ul, 0x5caul);
	return 0;
}