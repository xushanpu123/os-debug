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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

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
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20001240;
*(uint32_t*)0x20001240 = 0xf4;
*(uint16_t*)0x20001244 = 0;
*(uint16_t*)0x20001246 = 0;
*(uint32_t*)0x20001248 = 0;
*(uint32_t*)0x2000124c = 0;
*(uint8_t*)0x20001250 = 0xf;
*(uint8_t*)0x20001251 = 0;
*(uint16_t*)0x20001252 = 0;
*(uint16_t*)0x20001254 = 8;
*(uint16_t*)0x20001256 = 3;
*(uint32_t*)0x20001258 = 0;
*(uint16_t*)0x2000125c = 0xd5;
*(uint16_t*)0x2000125e = 0xe;
STORE_BY_BITMASK(uint8_t, , 0x20001260, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001260, 0, 2, 2);
STORE_BY_BITMASK(uint8_t, , 0x20001260, 8, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 3, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 4, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 5, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001261, 1, 7, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001262, 0, 0, 15);
STORE_BY_BITMASK(uint16_t, , 0x20001263, 0, 7, 1);
*(uint8_t*)0x20001264 = 8;
*(uint8_t*)0x20001265 = 2;
*(uint8_t*)0x20001266 = 0x11;
*(uint8_t*)0x20001267 = 0;
*(uint8_t*)0x20001268 = 0;
*(uint8_t*)0x20001269 = 0;
*(uint8_t*)0x2000126a = 8;
*(uint8_t*)0x2000126b = 2;
*(uint8_t*)0x2000126c = 0x11;
*(uint8_t*)0x2000126d = 0;
*(uint8_t*)0x2000126e = 0;
*(uint8_t*)0x2000126f = 0;
memset((void*)0x20001270, 255, 6);
STORE_BY_BITMASK(uint16_t, , 0x20001276, 0, 0, 4);
STORE_BY_BITMASK(uint16_t, , 0x20001276, 0, 4, 12);
STORE_BY_BITMASK(uint16_t, , 0x20001278, 0, 0, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001278, 0, 1, 15);
STORE_BY_BITMASK(uint8_t, , 0x2000127a, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x2000127a, 0, 2, 2);
STORE_BY_BITMASK(uint8_t, , 0x2000127a, 0, 4, 2);
STORE_BY_BITMASK(uint8_t, , 0x2000127a, 0, 6, 2);
STORE_BY_BITMASK(uint8_t, , 0x2000127b, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000127b, 0, 1, 5);
STORE_BY_BITMASK(uint8_t, , 0x2000127b, 0, 6, 1);
STORE_BY_BITMASK(uint8_t, , 0x2000127b, 0, 7, 1);
*(uint64_t*)0x2000127c = 0;
*(uint16_t*)0x20001284 = 0;
*(uint16_t*)0x20001286 = 0;
*(uint8_t*)0x20001288 = 1;
*(uint8_t*)0x20001289 = 0;
*(uint8_t*)0x2000128a = 3;
*(uint8_t*)0x2000128b = 1;
*(uint8_t*)0x2000128c = 0;
*(uint8_t*)0x2000128d = 0x25;
*(uint8_t*)0x2000128e = 3;
*(uint8_t*)0x2000128f = 0;
*(uint8_t*)0x20001290 = 0;
*(uint8_t*)0x20001291 = 0;
*(uint8_t*)0x20001292 = 0x2a;
*(uint8_t*)0x20001293 = 1;
STORE_BY_BITMASK(uint8_t, , 0x20001294, 0, 0, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001294, 0, 1, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001294, 0, 2, 1);
STORE_BY_BITMASK(uint8_t, , 0x20001294, 0, 3, 5);
*(uint8_t*)0x20001295 = 0x71;
*(uint8_t*)0x20001296 = 7;
*(uint8_t*)0x20001297 = 0;
*(uint8_t*)0x20001298 = 0;
*(uint8_t*)0x20001299 = 0;
*(uint8_t*)0x2000129a = 0;
*(uint8_t*)0x2000129b = 0;
*(uint8_t*)0x2000129c = 0;
*(uint8_t*)0x2000129d = 0;
*(uint8_t*)0x2000129e = 0x76;
*(uint8_t*)0x2000129f = 6;
*(uint8_t*)0x200012a0 = 0;
*(uint8_t*)0x200012a1 = 0;
*(uint16_t*)0x200012a2 = 0;
*(uint16_t*)0x200012a4 = 0;
*(uint8_t*)0x200012a6 = 0xdd;
*(uint8_t*)0x200012a7 = 0x89;
memcpy((void*)0x200012a8, "\x6e\x97\x6b\x8d\x31\xca\x6e\x0f\x81\x46\x07\x45\xd2\x42\x60\x04\xae\x88\xbe\xa8\x07\x50\x01\x4f\xd9\x72\x91\x26\xb3\x90\xa0\x9e\xcb\x91\x50\x11\xf9\x36\xa3\xba\x70\x84\xa0\x91\xcd\x04\x00\x24\x78\xd7\x95\xaa\x10\xb3\x6f\x52\x8b\x20\x18\x65\x77\x25\x0f\x2d\x98\x8b\xfd\x4f\xe1\x95\xea\x9c\x0a\x60\xb4\xde\xd9\x53\x0d\x7c\x6c\xd2\xb4\xd9\x0b\x5e\xcf\x71\xfa\x37\xc6\x60\xe7\x48\xf0\x2e\xdc\x17\x5e\x19\x69\x9f\xa8\x47\xfc\xe1\xec\x96\xda\x0f\x5a\x6b\x20\xd4\x8e\x47\x3f\x3f\x43\x2a\x1c\x58\x63\x77\x5f\x15\xd2\xb1\xee\xe5\xac\x93\xe6\x87\x5a\x1b\x5d", 137);
*(uint64_t*)0x20000108 = 0xf4;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0;
	syscall(__NR_sendmsg, -1, 0x20000140ul, 0ul);
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 7;
*(uint8_t*)0x20000004 = 0x79;
*(uint16_t*)0x20000005 = 0;
	syscall(__NR_write, r[0], 0x20000000ul, 0xff64ul);
	return 0;
}