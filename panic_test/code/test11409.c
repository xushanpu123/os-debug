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
memcpy((void*)0x20000140, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000150 = 0x200000c0;
memcpy((void*)0x200000c0, "syztnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200000d0 = 0;
*(uint16_t*)0x200000d4 = htobe16(0);
*(uint16_t*)0x200000d6 = htobe16(0);
*(uint32_t*)0x200000d8 = htobe32(0);
*(uint32_t*)0x200000dc = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200000e0, 0x15, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000e0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000e1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000e1, 0, 2, 6);
*(uint16_t*)0x200000e2 = htobe16(0x54);
*(uint16_t*)0x200000e4 = htobe16(0);
*(uint16_t*)0x200000e6 = htobe16(0);
*(uint8_t*)0x200000e8 = 0;
*(uint8_t*)0x200000e9 = 0;
*(uint16_t*)0x200000ea = htobe16(0);
*(uint32_t*)0x200000ec = htobe32(0x7f000001);
*(uint32_t*)0x200000f0 = htobe32(0x7f000001);
*(uint8_t*)0x200000f4 = 0x44;
*(uint8_t*)0x200000f5 = 0x34;
*(uint8_t*)0x200000f6 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200000f7, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000f7, 0, 4, 4);
*(uint8_t*)0x200000f8 = 0xac;
*(uint8_t*)0x200000f9 = 0x14;
*(uint8_t*)0x200000fa = 0x14;
*(uint8_t*)0x200000fb = 0xbb;
*(uint32_t*)0x200000fc = htobe32(0);
*(uint8_t*)0x20000100 = 0xac;
*(uint8_t*)0x20000101 = 0x1e;
*(uint8_t*)0x20000102 = 0;
*(uint8_t*)0x20000103 = 1;
*(uint32_t*)0x20000104 = htobe32(0);
*(uint8_t*)0x20000108 = 0xac;
*(uint8_t*)0x20000109 = 0x14;
*(uint8_t*)0x2000010a = 0x14;
*(uint8_t*)0x2000010b = 0xaa;
*(uint32_t*)0x2000010c = htobe32(0);
*(uint8_t*)0x20000110 = 0xac;
*(uint8_t*)0x20000111 = 0x14;
*(uint8_t*)0x20000112 = 0x14;
*(uint8_t*)0x20000113 = 0xbb;
*(uint32_t*)0x20000114 = htobe32(0);
*(uint8_t*)0x20000118 = 0xac;
*(uint8_t*)0x20000119 = 0x14;
*(uint8_t*)0x2000011a = 0x14;
*(uint8_t*)0x2000011b = 0xaa;
*(uint32_t*)0x2000011c = htobe32(0);
*(uint32_t*)0x20000120 = htobe32(0);
*(uint32_t*)0x20000124 = htobe32(0);
*(uint8_t*)0x20000128 = 0x44;
*(uint8_t*)0x20000129 = 0xc;
*(uint8_t*)0x2000012a = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000012b, 0, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x2000012b, 0, 4, 4);
*(uint32_t*)0x2000012c = htobe32(0);
*(uint32_t*)0x20000130 = htobe32(0);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x200000e0, 84);
*(uint16_t*)0x200000ea = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[0], 0x89f1, 0x20000140ul);
memcpy((void*)0x200002c0, "syztnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200002d0 = 0x20000200;
memcpy((void*)0x20000200, "syztnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000210 = 0;
*(uint16_t*)0x20000214 = htobe16(0);
*(uint16_t*)0x20000216 = htobe16(0);
*(uint32_t*)0x20000218 = htobe32(0);
*(uint32_t*)0x2000021c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x20000220, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000220, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000221, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000221, 0, 2, 6);
*(uint16_t*)0x20000222 = htobe16(0x14);
*(uint16_t*)0x20000224 = htobe16(0);
*(uint16_t*)0x20000226 = htobe16(0);
*(uint8_t*)0x20000228 = 0;
*(uint8_t*)0x20000229 = 0;
*(uint16_t*)0x2000022a = htobe16(0);
*(uint32_t*)0x2000022c = htobe32(0xe0000002);
*(uint32_t*)0x20000230 = htobe32(0x7f000001);
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x20000220, 20);
*(uint16_t*)0x2000022a = csum_inet_digest(&csum_2);
	syscall(__NR_ioctl, r[0], 0x89f2, 0x200002c0ul);
	return 0;
}
