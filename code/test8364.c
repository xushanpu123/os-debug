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
	syscall(__NR_socket, 0xaul, 3ul, 2);
memcpy((void*)0x200005c0, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x200005c0, 0, 0x20800);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0;
*(uint16_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint16_t*)0x20000058 = 0;
*(uint32_t*)0x20000060 = 0;
*(uint32_t*)0x20000064 = 1;
*(uint32_t*)0x20000068 = 0xa;
*(uint32_t*)0x2000006c = 0;
memcpy((void*)0x20000070, "\x42\xcb\x17\x7a\x7f\xc0\x39\xcf\x91\x12\xb4\x35\x4a\x3a\xc9\x43\x2e\x20\x37\xcb\xb8\x67\xc9\xdc\x30\x6a\x6a\x14\xc0\xfe\x4b\x44\xa7\x93\xb3\x0f\x9f\xf3\x2f\xd8\x46\x82\xcc\xa5\x72\x50\x71\x02\x6e\xd1\xf3\xfe\x6b\x34\xaf\x89\x0a\x2e\x37\x14\x68\xc3\xa8\x5c", 64);
memcpy((void*)0x200000b0, "\x76\x73\x59\x6e\x95\x3f\x7d\xc7\x70\xd2\xac\xaa\x8f\x0f\x96\x45\xf4\xa6\x82\xfa\x98\x55\x41\x85\xed\x92\x56\x51\xbe\xbd\x49\xce", 32);
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint32_t*)0x200000e0 = 0;
	syscall(__NR_ioctl, r[0], 0x4c02, 0x20000040ul);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	return 0;
}
