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
	res = syscall(__NR_socket, 2ul, 0xaul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000280, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000290 = 0x20000180;
memcpy((void*)0x20000180, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000190 = 0;
*(uint16_t*)0x20000194 = htobe16(0);
*(uint16_t*)0x20000196 = htobe16(0);
*(uint32_t*)0x20000198 = htobe32(0);
*(uint32_t*)0x2000019c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200001a0, 0x35, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200001a0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200001a1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200001a1, 0, 2, 6);
*(uint16_t*)0x200001a2 = htobe16(0xd4);
*(uint16_t*)0x200001a4 = htobe16(0);
*(uint16_t*)0x200001a6 = htobe16(0);
*(uint8_t*)0x200001a8 = 0;
*(uint8_t*)0x200001a9 = 0;
*(uint16_t*)0x200001aa = htobe16(0);
*(uint32_t*)0x200001ac = htobe32(0xe0000001);
*(uint32_t*)0x200001b0 = htobe32(-1);
*(uint8_t*)0x200001b4 = 0x89;
*(uint8_t*)0x200001b5 = 0x17;
*(uint8_t*)0x200001b6 = 0;
*(uint32_t*)0x200001b7 = htobe32(-1);
*(uint32_t*)0x200001bb = htobe32(0xe0000002);
*(uint32_t*)0x200001bf = htobe32(0);
*(uint32_t*)0x200001c3 = htobe32(0);
*(uint32_t*)0x200001c7 = htobe32(0xe0000002);
*(uint8_t*)0x200001cb = 0x44;
*(uint8_t*)0x200001cc = 0x24;
*(uint8_t*)0x200001cd = 0;
STORE_BY_BITMASK(uint8_t, , 0x200001ce, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200001ce, 0, 4, 4);
*(uint32_t*)0x200001cf = htobe32(0x7f000001);
*(uint32_t*)0x200001d3 = htobe32(0);
*(uint32_t*)0x200001d7 = htobe32(0xe0000001);
*(uint32_t*)0x200001db = htobe32(0);
*(uint8_t*)0x200001df = 0xac;
*(uint8_t*)0x200001e0 = 0x14;
*(uint8_t*)0x200001e1 = 0x14;
*(uint8_t*)0x200001e2 = 0;
*(uint32_t*)0x200001e3 = htobe32(0);
*(uint32_t*)0x200001e7 = htobe32(0);
*(uint32_t*)0x200001eb = htobe32(0);
*(uint8_t*)0x200001ef = 0x44;
*(uint8_t*)0x200001f0 = 0x3c;
*(uint8_t*)0x200001f1 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200001f2, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200001f2, 0, 4, 4);
*(uint8_t*)0x200001f3 = 0xac;
*(uint8_t*)0x200001f4 = 0x14;
*(uint8_t*)0x200001f5 = 0x14;
*(uint8_t*)0x200001f6 = 0xaa;
*(uint32_t*)0x200001f7 = htobe32(0);
*(uint8_t*)0x200001fb = 0xac;
*(uint8_t*)0x200001fc = 0x14;
*(uint8_t*)0x200001fd = 0x14;
*(uint8_t*)0x200001fe = 0xbb;
*(uint32_t*)0x200001ff = htobe32(0);
*(uint32_t*)0x20000203 = htobe32(-1);
*(uint32_t*)0x20000207 = htobe32(0);
*(uint32_t*)0x2000020b = htobe32(0xe0000002);
*(uint32_t*)0x2000020f = htobe32(0);
*(uint32_t*)0x20000213 = htobe32(0);
*(uint32_t*)0x20000217 = htobe32(0);
*(uint8_t*)0x2000021b = 0xac;
*(uint8_t*)0x2000021c = 0x14;
*(uint8_t*)0x2000021d = 0x14;
*(uint8_t*)0x2000021e = 0xbb;
*(uint32_t*)0x2000021f = htobe32(0);
*(uint8_t*)0x20000223 = 0xac;
*(uint8_t*)0x20000224 = 0x14;
*(uint8_t*)0x20000225 = 0x14;
*(uint8_t*)0x20000226 = 0xbb;
*(uint32_t*)0x20000227 = htobe32(0);
*(uint8_t*)0x2000022b = 0x83;
*(uint8_t*)0x2000022c = 7;
*(uint8_t*)0x2000022d = 0;
*(uint8_t*)0x2000022e = 0xac;
*(uint8_t*)0x2000022f = 0x14;
*(uint8_t*)0x20000230 = 0x14;
*(uint8_t*)0x20000231 = 0xaa;
*(uint8_t*)0x20000232 = 7;
*(uint8_t*)0x20000233 = 0x27;
*(uint8_t*)0x20000234 = 0;
*(uint8_t*)0x20000235 = 0xac;
*(uint8_t*)0x20000236 = 0x14;
*(uint8_t*)0x20000237 = 0x14;
*(uint8_t*)0x20000238 = 0xbb;
*(uint32_t*)0x20000239 = htobe32(0);
*(uint32_t*)0x2000023d = htobe32(-1);
*(uint32_t*)0x20000241 = htobe32(0);
*(uint8_t*)0x20000245 = 0xac;
*(uint8_t*)0x20000246 = 0x14;
*(uint8_t*)0x20000247 = 0x14;
*(uint8_t*)0x20000248 = 0xaa;
*(uint32_t*)0x20000249 = htobe32(0);
*(uint32_t*)0x2000024d = htobe32(0);
*(uint8_t*)0x20000251 = 0xac;
*(uint8_t*)0x20000252 = 0x14;
*(uint8_t*)0x20000253 = 0x14;
*(uint8_t*)0x20000254 = 0xbb;
*(uint32_t*)0x20000255 = htobe32(0);
*(uint8_t*)0x20000259 = 0x89;
*(uint8_t*)0x2000025a = 0xf;
*(uint8_t*)0x2000025b = 0;
*(uint32_t*)0x2000025c = htobe32(0xe0000002);
*(uint32_t*)0x20000260 = htobe32(0);
*(uint32_t*)0x20000264 = htobe32(0xe0000002);
*(uint8_t*)0x20000268 = 0;
*(uint8_t*)0x20000269 = 9;
memcpy((void*)0x2000026a, "\x83\x39\xf8\xff\x43\x00\xf5", 7);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x200001a0, 212);
*(uint16_t*)0x200001aa = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[0], 0x89f3, 0x20000280ul);
	return 0;
}
