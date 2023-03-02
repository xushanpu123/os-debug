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
memcpy((void*)0x20000000, "/dev/loop#\000", 11);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
	syscall(__NR_fdatasync, r[0]);
	syscall(__NR_ioctl, r[0], 0x4c03, 0x20000040ul);
	syscall(__NR_prctl, 0x23ul, 5ul, 0x20ff3000ul, 0, 0);
*(uint64_t*)0x20000100 = 0x20ff3000;
*(uint32_t*)0x20000108 = 0x4000;
*(uint64_t*)0x20000118 = 0x20000140;
*(uint32_t*)0x20000120 = 0x1e;
*(uint32_t*)0x20000124 = 1;
*(uint64_t*)0x20000128 = 0x200001c0;
*(uint64_t*)0x20000130 = 0xd9;
*(uint32_t*)0x2000013c = 0;
*(uint32_t*)0x200002c0 = 0x40;
	syscall(__NR_getsockopt, -1, 6, 0x23, 0x20000100ul, 0x200002c0ul);
	syscall(__NR_msync, 0x20ffb000ul, 0x4000ul, 2ul);
	syscall(__NR_ioctl, r[0], 0x84009422, 0x20000500ul);
	syscall(__NR_shmget, 0x798dd815ul, 0x1000ul, 0x54000000ul, 0x20ff4000ul);
*(uint64_t*)0x200004c0 = 0x20000180;
*(uint16_t*)0x20000180 = 0x10;
*(uint16_t*)0x20000182 = 0;
*(uint32_t*)0x20000184 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x200004c8 = 0xc;
*(uint64_t*)0x200004d0 = 0x20000480;
*(uint64_t*)0x20000480 = 0x20000300;
*(uint32_t*)0x20000300 = 0x84;
*(uint16_t*)0x20000304 = 0;
*(uint16_t*)0x20000306 = 0x800;
*(uint32_t*)0x20000308 = 0x70bd28;
*(uint32_t*)0x2000030c = 0x25dfdbfc;
*(uint8_t*)0x20000310 = 1;
*(uint8_t*)0x20000311 = 0;
*(uint16_t*)0x20000312 = 0;
*(uint16_t*)0x20000314 = 4;
STORE_BY_BITMASK(uint16_t, , 0x20000316, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000317, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000317, 1, 7, 1);
*(uint16_t*)0x20000318 = 8;
*(uint16_t*)0x2000031a = 5;
*(uint32_t*)0x2000031c = 6;
*(uint16_t*)0x20000320 = 8;
*(uint16_t*)0x20000322 = 4;
*(uint32_t*)0x20000324 = 8;
*(uint16_t*)0x20000328 = 0x5c;
STORE_BY_BITMASK(uint16_t, , 0x2000032a, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000032b, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000032b, 1, 7, 1);
*(uint16_t*)0x2000032c = 8;
*(uint16_t*)0x2000032e = 6;
memcpy((void*)0x20000330, "wrr\000", 4);
*(uint16_t*)0x20000334 = 8;
*(uint16_t*)0x20000336 = 5;
*(uint32_t*)0x20000338 = 4;
*(uint16_t*)0x2000033c = 6;
*(uint16_t*)0x2000033e = 2;
*(uint16_t*)0x20000340 = 8;
*(uint16_t*)0x20000344 = 6;
*(uint16_t*)0x20000346 = 4;
*(uint16_t*)0x20000348 = htobe16(0x4e23);
*(uint16_t*)0x2000034c = 7;
*(uint16_t*)0x2000034e = 6;
memcpy((void*)0x20000350, "dh\000", 3);
*(uint16_t*)0x20000354 = 8;
*(uint16_t*)0x20000356 = 9;
*(uint32_t*)0x20000358 = 0x2a;
*(uint16_t*)0x2000035c = 0x14;
*(uint16_t*)0x2000035e = 3;
memset((void*)0x20000360, 0, 10);
memset((void*)0x2000036a, 255, 2);
*(uint32_t*)0x2000036c = htobe32(-1);
*(uint16_t*)0x20000370 = 0xc;
*(uint16_t*)0x20000372 = 7;
*(uint32_t*)0x20000374 = 2;
*(uint32_t*)0x20000378 = 0x18;
*(uint16_t*)0x2000037c = 8;
*(uint16_t*)0x2000037e = 8;
*(uint32_t*)0x20000380 = 0x100;
*(uint64_t*)0x20000488 = 0x84;
*(uint64_t*)0x200004d8 = 1;
*(uint64_t*)0x200004e0 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint32_t*)0x200004f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200004c0ul, 0ul);
	return 0;
}
