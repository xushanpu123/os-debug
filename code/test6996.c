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

uint64_t r[6] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20001e40, "/dev/hpet\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20001e40ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_ioctl, r[2], 0x4008240b, 0ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[3] = res;
memcpy((void*)0x20000380, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000390 = 0x200002c0;
memcpy((void*)0x200002c0, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200002d0 = 0;
*(uint16_t*)0x200002d4 = htobe16(0);
*(uint16_t*)0x200002d6 = htobe16(0);
*(uint32_t*)0x200002d8 = htobe32(0);
*(uint32_t*)0x200002dc = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200002e0, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200002e0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200002e1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200002e1, 0, 2, 6);
*(uint16_t*)0x200002e2 = htobe16(0x14);
*(uint16_t*)0x200002e4 = htobe16(0xfffc);
*(uint16_t*)0x200002e6 = htobe16(0);
*(uint8_t*)0x200002e8 = 0xef;
*(uint8_t*)0x200002e9 = 0;
*(uint16_t*)0x200002ea = htobe16(0);
*(uint32_t*)0x200002ec = htobe32(-1);
*(uint8_t*)0x200002f0 = 0xac;
*(uint8_t*)0x200002f1 = 0x1e;
*(uint8_t*)0x200002f2 = 0;
*(uint8_t*)0x200002f3 = 1;
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x200002e0, 20);
*(uint16_t*)0x200002ea = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[3], 0x89f1, 0x20000380ul);
memcpy((void*)0x20001e40, "/dev/hpet\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20001e40ul, 0ul, 0ul);
	if (res != -1)
		r[4] = res;
	syscall(__NR_ioctl, r[4], 0x4008240b, 0ul);
memcpy((void*)0x20000000, "batadv_slave_0\000\000", 16);
	res = syscall(__NR_ioctl, r[3], 0x8933, 0x20000000ul);
	if (res != -1)
r[5] = *(uint32_t*)0x20000010;
memcpy((void*)0x20000040, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000050 = 0x20000140;
memcpy((void*)0x20000140, "ip_vti0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000150 = r[5];
*(uint16_t*)0x20000154 = htobe16(0x7800);
*(uint16_t*)0x20000156 = htobe16(1);
*(uint32_t*)0x20000158 = htobe32(2);
*(uint32_t*)0x2000015c = htobe32(0xff);
STORE_BY_BITMASK(uint8_t, , 0x20000160, 0x11, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000160, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000161, 3, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000161, 0xe, 2, 6);
*(uint16_t*)0x20000162 = htobe16(0x44);
*(uint16_t*)0x20000164 = htobe16(0x65);
*(uint16_t*)0x20000166 = htobe16(0);
*(uint8_t*)0x20000168 = 0x91;
*(uint8_t*)0x20000169 = 0x2f;
*(uint16_t*)0x2000016a = htobe16(0);
*(uint32_t*)0x2000016c = htobe32(0xe0000002);
*(uint32_t*)0x20000170 = htobe32(0);
*(uint8_t*)0x20000174 = 0;
*(uint8_t*)0x20000175 = 0x44;
*(uint8_t*)0x20000176 = 0x24;
*(uint8_t*)0x20000177 = 0xe0;
STORE_BY_BITMASK(uint8_t, , 0x20000178, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000178, 1, 4, 4);
*(uint32_t*)0x20000179 = htobe32(5);
*(uint32_t*)0x2000017d = htobe32(0x10001);
*(uint32_t*)0x20000181 = htobe32(8);
*(uint32_t*)0x20000185 = htobe32(0x80);
*(uint32_t*)0x20000189 = htobe32(0x80000000);
*(uint32_t*)0x2000018d = htobe32(2);
*(uint32_t*)0x20000191 = htobe32(7);
*(uint32_t*)0x20000195 = htobe32(7);
*(uint8_t*)0x20000199 = 7;
*(uint8_t*)0x2000019a = 2;
*(uint8_t*)0x2000019b = 7;
*(uint8_t*)0x2000019c = 7;
*(uint8_t*)0x2000019d = 0xdd;
*(uint8_t*)0x2000019e = 0xac;
*(uint8_t*)0x2000019f = 0x14;
*(uint8_t*)0x200001a0 = 0x14;
*(uint8_t*)0x200001a1 = 0xaa;
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x20000160, 68);
*(uint16_t*)0x2000016a = csum_inet_digest(&csum_2);
	syscall(__NR_ioctl, -1, 0x89f1, 0x20000040ul);
memcpy((void*)0x200000c0, "erspan0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200000d0 = 0x20000080;
memcpy((void*)0x20000080, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000090 = r[5];
*(uint16_t*)0x20000094 = htobe16(0x8000);
*(uint16_t*)0x20000096 = htobe16(0x10);
*(uint32_t*)0x20000098 = htobe32(2);
*(uint32_t*)0x2000009c = htobe32(0x1ff);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 6, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 2, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 0x38, 2, 6);
*(uint16_t*)0x200000a2 = htobe16(0x18);
*(uint16_t*)0x200000a4 = htobe16(0x66);
*(uint16_t*)0x200000a6 = htobe16(0);
*(uint8_t*)0x200000a8 = 2;
*(uint8_t*)0x200000a9 = 0x2f;
*(uint16_t*)0x200000aa = htobe16(0);
*(uint8_t*)0x200000ac = 0xac;
*(uint8_t*)0x200000ad = 0x14;
*(uint8_t*)0x200000ae = 0x14;
*(uint8_t*)0x200000af = 0xaa;
*(uint8_t*)0x200000b0 = 0xac;
*(uint8_t*)0x200000b1 = 0x14;
*(uint8_t*)0x200000b2 = 0x14;
*(uint8_t*)0x200000b3 = 0xaa;
*(uint8_t*)0x200000b4 = 0;
	struct csum_inet csum_3;
	csum_inet_init(&csum_3);
csum_inet_update(&csum_3, (const uint8_t*)0x200000a0, 24);
*(uint16_t*)0x200000aa = csum_inet_digest(&csum_3);
	syscall(__NR_ioctl, r[2], 0x89f1, 0x200000c0ul);
memcpy((void*)0x20000380, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000390 = 0x200002c0;
*(uint16_t*)0x200002c0 = r[0];
*(uint32_t*)0x200002c2 = 0;
memcpy((void*)0x200002c6, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x45\x00\x00\x14\xff\xfc\x00\x00\xef\x00\x03\xff\xff", 25);
	syscall(__NR_ioctl, r[1], 0x89f1, 0x20000380ul);
	return 0;
}