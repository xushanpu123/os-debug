// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

struct csum_inet {
	uint32_t acc;
};

static void csum_inet_init(struct csum_inet* csum)
{
	csum->acc = 0;
}

static void csum_inet_update(struct csum_inet* csum, const uint8_t* data, size_t length)
{
	if (length == 0)
		return;
	size_t i = 0;
	for (; i < length - 1; i += 2)
		csum->acc += *(uint16_t*)&data[i];
	if (length & 1)
		csum->acc += le16toh((uint16_t)data[length - 1]);
	while (csum->acc > 0xffff)
		csum->acc = (csum->acc & 0xffff) + (csum->acc >> 16);
}

static uint16_t csum_inet_digest(struct csum_inet* csum)
{
	return ~csum->acc;
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000380, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000390 = 0x200002c0;
memcpy((void*)0x200002c0, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200002d0 = 0;
*(uint16_t*)0x200002d4 = htobe16(0);
*(uint16_t*)0x200002d6 = htobe16(0);
*(uint32_t*)0x200002d8 = htobe32(0);
*(uint32_t*)0x200002dc = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200002e0, 0x25, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200002e0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200002e1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200002e1, 0, 2, 6);
*(uint16_t*)0x200002e2 = htobe16(0x94);
*(uint16_t*)0x200002e4 = htobe16(0);
*(uint16_t*)0x200002e6 = htobe16(0);
*(uint8_t*)0x200002e8 = 0;
*(uint8_t*)0x200002e9 = 0;
*(uint16_t*)0x200002ea = htobe16(0);
*(uint32_t*)0x200002ec = htobe32(0x7f000001);
*(uint8_t*)0x200002f0 = 0xac;
*(uint8_t*)0x200002f1 = 0x1e;
*(uint8_t*)0x200002f2 = 0;
*(uint8_t*)0x200002f3 = 1;
*(uint8_t*)0x200002f4 = 1;
*(uint8_t*)0x200002f5 = 0x83;
*(uint8_t*)0x200002f6 = 0x1b;
*(uint8_t*)0x200002f7 = 0x89;
*(uint32_t*)0x200002f8 = htobe32(0x7f000001);
*(uint8_t*)0x200002fc = 0xac;
*(uint8_t*)0x200002fd = 0x14;
*(uint8_t*)0x200002fe = 0x14;
*(uint8_t*)0x200002ff = 0xbb;
*(uint8_t*)0x20000300 = 0xac;
*(uint8_t*)0x20000301 = 0x14;
*(uint8_t*)0x20000302 = 0x14;
*(uint8_t*)0x20000303 = 0xaa;
*(uint32_t*)0x20000304 = htobe32(0);
*(uint32_t*)0x20000308 = htobe32(0xe0000002);
*(uint32_t*)0x2000030c = htobe32(0x7f000001);
*(uint8_t*)0x20000310 = 0x44;
*(uint8_t*)0x20000311 = 0x44;
*(uint8_t*)0x20000312 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000313, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000313, 0, 4, 4);
*(uint32_t*)0x20000314 = htobe32(0x64010102);
*(uint32_t*)0x20000318 = htobe32(0xfffffdd3);
*(uint32_t*)0x2000031c = htobe32(0x64010101);
*(uint32_t*)0x20000320 = htobe32(0);
*(uint32_t*)0x20000324 = htobe32(0);
*(uint32_t*)0x20000328 = htobe32(0);
*(uint32_t*)0x2000032c = htobe32(0);
*(uint32_t*)0x20000330 = htobe32(0);
*(uint32_t*)0x20000334 = htobe32(0xe0000001);
*(uint32_t*)0x20000338 = htobe32(0);
*(uint8_t*)0x2000033c = 0xac;
*(uint8_t*)0x2000033d = 0x14;
*(uint8_t*)0x2000033e = 0x14;
*(uint8_t*)0x2000033f = 0;
*(uint32_t*)0x20000340 = htobe32(0);
*(uint32_t*)0x20000344 = htobe32(-1);
*(uint32_t*)0x20000348 = htobe32(5);
*(uint32_t*)0x2000034c = htobe32(0xe0000001);
*(uint32_t*)0x20000350 = htobe32(0);
*(uint8_t*)0x20000354 = 0x83;
*(uint8_t*)0x20000355 = 0x1f;
*(uint8_t*)0x20000356 = 0;
*(uint8_t*)0x20000357 = 0xac;
*(uint8_t*)0x20000358 = 0x14;
*(uint8_t*)0x20000359 = 0x14;
*(uint8_t*)0x2000035a = 0xbb;
*(uint32_t*)0x2000035b = htobe32(0x7f000001);
*(uint32_t*)0x2000035f = htobe32(0xe0000002);
*(uint32_t*)0x20000363 = htobe32(0x7f000001);
*(uint32_t*)0x20000367 = htobe32(0x7f000001);
*(uint32_t*)0x2000036b = htobe32(0x3b13000);
*(uint32_t*)0x2000036f = htobe32(0);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x200002e0, 148);
*(uint16_t*)0x200002ea = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[0], 0x89f1, 0x20000380ul);
memcpy((void*)0x20000100, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000110 = 0x20000080;
memcpy((void*)0x20000080, "syztnl1\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000090 = 0;
*(uint16_t*)0x20000094 = htobe16(0);
*(uint16_t*)0x20000096 = htobe16(0);
*(uint32_t*)0x20000098 = htobe32(0x80000001);
*(uint32_t*)0x2000009c = htobe32(0x80000000);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 9, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 1, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 0, 2, 6);
*(uint16_t*)0x200000a2 = htobe16(0x24);
*(uint16_t*)0x200000a4 = htobe16(0x64);
*(uint16_t*)0x200000a6 = htobe16(0);
*(uint8_t*)0x200000a8 = 3;
*(uint8_t*)0x200000a9 = 0x29;
*(uint16_t*)0x200000aa = htobe16(0);
*(uint32_t*)0x200000ac = htobe32(-1);
*(uint8_t*)0x200000b0 = 0xac;
*(uint8_t*)0x200000b1 = 0x14;
*(uint8_t*)0x200000b2 = 0x14;
*(uint8_t*)0x200000b3 = 0x42;
*(uint8_t*)0x200000b4 = 0x44;
*(uint8_t*)0x200000b5 = 4;
*(uint8_t*)0x200000b6 = 0xd0;
STORE_BY_BITMASK(uint8_t, , 0x200000b7, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000b7, 0xb, 4, 4);
*(uint8_t*)0x200000b8 = 0x86;
*(uint8_t*)0x200000b9 = 9;
*(uint32_t*)0x200000ba = htobe32(2);
*(uint8_t*)0x200000be = 0;
*(uint8_t*)0x200000bf = 3;
memset((void*)0x200000c0, 15, 1);
*(uint8_t*)0x200000c1 = 1;
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x200000a0, 36);
*(uint16_t*)0x200000aa = csum_inet_digest(&csum_2);
	syscall(__NR_ioctl, r[0], 0x89f2, 0x20000100ul);
	return 0;
}
