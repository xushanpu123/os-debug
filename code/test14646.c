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
*(uint8_t*)0x200004c0 = 0x7f;
*(uint8_t*)0x200004c1 = 0x45;
*(uint8_t*)0x200004c2 = 0x4c;
*(uint8_t*)0x200004c3 = 0x46;
*(uint8_t*)0x200004c4 = 2;
*(uint8_t*)0x200004c5 = 4;
*(uint8_t*)0x200004c6 = 0;
*(uint8_t*)0x200004c7 = 0;
*(uint64_t*)0x200004c8 = 0;
*(uint16_t*)0x200004d0 = 0;
*(uint16_t*)0x200004d2 = 0;
*(uint32_t*)0x200004d4 = 0;
*(uint32_t*)0x200004d8 = 0;
*(uint32_t*)0x200004dc = 0x38;
*(uint32_t*)0x200004e0 = 0x66;
*(uint32_t*)0x200004e4 = 4;
*(uint16_t*)0x200004e8 = 0;
*(uint16_t*)0x200004ea = 0x20;
*(uint16_t*)0x200004ec = 0;
*(uint16_t*)0x200004ee = 0;
*(uint16_t*)0x200004f0 = 0;
*(uint16_t*)0x200004f2 = 0;
*(uint32_t*)0x200004f8 = 0;
*(uint32_t*)0x200004fc = 0;
*(uint32_t*)0x20000500 = 0;
*(uint32_t*)0x20000504 = 0;
*(uint32_t*)0x20000508 = 0;
*(uint32_t*)0x2000050c = 0;
*(uint32_t*)0x20000510 = 0;
*(uint32_t*)0x20000514 = 0;
	syscall(__NR_write, r[0], 0x200004c0ul, 0x58ul);
*(uint32_t*)0x20000040 = 0x10;
*(uint32_t*)0x20000044 = 4;
*(uint32_t*)0x20000048 = htobe32(0x5fc);
*(uint32_t*)0x2000004c = htobe32(0x101);
*(uint32_t*)0x20000050 = htobe32(6);
*(uint32_t*)0x20000054 = htobe32(6);
	syscall(__NR_open_by_handle_at, r[0], 0x20000040ul, 0x20880ul);
	return 0;
}
