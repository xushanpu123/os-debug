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
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001780 = 0;
*(uint32_t*)0x20001788 = 0;
*(uint64_t*)0x20001790 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000600;
*(uint32_t*)0x20000600 = 0x1d0;
*(uint16_t*)0x20000604 = 0;
*(uint16_t*)0x20000606 = 0;
*(uint32_t*)0x20000608 = 0;
*(uint32_t*)0x2000060c = 0;
*(uint8_t*)0x20000610 = 0x3a;
*(uint8_t*)0x20000611 = 0;
*(uint16_t*)0x20000612 = 0;
*(uint16_t*)0x20000614 = 8;
*(uint16_t*)0x20000616 = 3;
*(uint32_t*)0x20000618 = 0;
*(uint16_t*)0x2000061c = 0xc;
*(uint16_t*)0x2000061e = 0x99;
*(uint32_t*)0x20000620 = 0;
*(uint32_t*)0x20000624 = 0;
*(uint16_t*)0x20000628 = 6;
*(uint16_t*)0x2000062a = 0x65;
*(uint16_t*)0x2000062c = 6;
*(uint16_t*)0x20000630 = 6;
*(uint16_t*)0x20000632 = 0x65;
*(uint16_t*)0x20000634 = 0x7f;
*(uint16_t*)0x20000638 = 0x68;
*(uint16_t*)0x2000063a = 0x5b;
memcpy((void*)0x2000063c, "\x9e\x16\x33\x5d\x1e\x5a\xc1\x9d\x98\x7a\x36\x3e\x80\x29\x51\x43\x58\x50\x6f\xe0\x7a\x06\xa5\x04\xc8\xff\x37\xfb\x26\x62\x65\x08\x48\x16\x93\xd3\xfd\xb7\x60\xf6\xc2\x20\xb4\x14\x5d\x39\xb9\x12\x47\x63\x72\xc3\x2b\x44\xea\x24\x33\x48\xcf\x54\x8f\x0a\xd6\xca\x55\x2a\xb6\x80\x76\x8c\xe3\xf4\x23\x25\x63\x01\x94\xaa\xe1\x67\x27\x66\x77\xd5\x2d\xcd\xca\x10\xc5\xca\x0b\xc4\x43\x56\xdf\x27\xc5\x6b\x8b\x72", 100);
*(uint16_t*)0x200006a0 = 6;
*(uint16_t*)0x200006a2 = 0x65;
*(uint16_t*)0x200006a4 = 3;
*(uint16_t*)0x200006a8 = 6;
*(uint16_t*)0x200006aa = 0x65;
*(uint16_t*)0x200006ac = 3;
*(uint16_t*)0x200006b0 = 0x11f;
*(uint16_t*)0x200006b2 = 0x5b;
memcpy((void*)0x200006b4, "\xe5\x26\x34\x4e\xaf\xc6\x28\x31\x47\x94\x6b\x56\x7f\x2e\x72\xbb\x5f\x70\xa2\xc2\x5b\x4e\x9f\xc7\x81\x67\xea\x8b\xae\x75\xf1\x1e\x61\x09\x61\x04\x9f\x26\x15\x71\x57\x9e\x2e\x43\xd1\x78\xa2\x0d\x5a\x34\x32\x02\x59\xc7\xfc\x3e\x19\xa4\x75\xa3\xcc\x12\x43\xee\x2d\x91\xca\x10\xd8\xc8\xec\xe5\xa4\x9e\x5d\x70\x00\x05\xcf\x53\x84\xba\x92\xed\x8f\xea\x40\x2b\x98\xcb\x27\x63\xd4\x3e\xea\xc1\xd2\xbb\xcb\xcd\xf7\xb2\xfd\x83\x8b\xf8\x7a\x73\xa2\x5c\x82\x8a\xd9\x93\x2c\x07\x59\x3c\x76\x5f\x58\x0b\x8b\xe6\x63\x75\x04\xb5\xd9\x2d\xdf\xa1\xed\xee\x47\x31\x40\xa2\x1e\xe8\x18\x3d\x53\xbe\xf3\x83\x74\xb9\x7c\xf4\x12\x43\x5a\x1a\xa6\x8e\x28\xe8\x2a\x75\x8a\xee\xe5\xf3\xe1\x59\x0b\xaa\x9a\x4e\x48\xa5\x6b\x80\x5d\x71\xed\x38\x6a\x43\xac\x85\x44\x2a\xc0\x8f\xb5\xda\x16\xd5\x6a\xc6\x43\x09\x55\xcc\xe3\x63\x9b\xd3\xac\x40\xc5\xa8\xad\x59\x7c\xce\xa1\xe0\xed\x91\xbf\x64\xbc\x7d\xb3\x22\x40\xb5\x7a\x7c\x5b\x7d\x7b\x06\xc4\x36\x12\x0c\xf3\x07\xb7\xa8\x2d\xd0\xef\x25\x2b\x0c\xa2\x3e\xf2\xb8\x03\x01\xf8\xd7\x7b\x72\x4b\xb8\x37\xe8\x61\xb4\x81\xad\xfa\x35\x6c\xea\x22\x78\x71\xe2\x51\xec\xb8\x2f\x3a\x81\x92\x42\x89\x4d\x28\x10\x27\x1b\x5a\xa6\x31", 283);
*(uint64_t*)0x200000c8 = 0x1d0;
*(uint64_t*)0x20001798 = 1;
*(uint64_t*)0x200017a0 = 0;
*(uint64_t*)0x200017a8 = 0;
*(uint32_t*)0x200017b0 = 0x10000000;
	syscall(__NR_sendmsg, -1, 0x20001780ul, 0x20000000ul);
*(uint32_t*)0x20000000 = 7;
*(uint8_t*)0x20000004 = 0x79;
*(uint16_t*)0x20000005 = 0;
	syscall(__NR_write, r[0], 0x20000000ul, 0xff64ul);
	return 0;
}
