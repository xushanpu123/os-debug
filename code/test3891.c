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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_close, r[1]);
	syscall(__NR_dup, r[0]);
memcpy((void*)0x20000780, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000790 = 0x20000640;
memcpy((void*)0x20000640, "ip_vti0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000650 = 0;
*(uint16_t*)0x20000654 = htobe16(0);
*(uint16_t*)0x20000656 = htobe16(0);
*(uint32_t*)0x20000658 = htobe32(0);
*(uint32_t*)0x2000065c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x20000660, 0x45, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000660, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000661, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000661, 0, 2, 6);
*(uint16_t*)0x20000662 = htobe16(0x114);
*(uint16_t*)0x20000664 = htobe16(0);
*(uint16_t*)0x20000666 = htobe16(0);
*(uint8_t*)0x20000668 = 0;
*(uint8_t*)0x20000669 = 0;
*(uint16_t*)0x2000066a = htobe16(0);
*(uint8_t*)0x2000066c = 0xac;
*(uint8_t*)0x2000066d = 0x1e;
*(uint8_t*)0x2000066e = 0;
*(uint8_t*)0x2000066f = 1;
*(uint32_t*)0x20000670 = htobe32(0);
*(uint8_t*)0x20000674 = 0x94;
*(uint8_t*)0x20000675 = 4;
*(uint16_t*)0x20000676 = 0;
*(uint8_t*)0x20000678 = 0x44;
*(uint8_t*)0x20000679 = 0x34;
*(uint8_t*)0x2000067a = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000067b, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x2000067b, 0, 4, 4);
*(uint32_t*)0x2000067c = htobe32(0x7f000001);
*(uint32_t*)0x20000680 = htobe32(0);
*(uint8_t*)0x20000684 = 0xac;
*(uint8_t*)0x20000685 = 0x14;
*(uint8_t*)0x20000686 = 0x14;
*(uint8_t*)0x20000687 = 0xaa;
*(uint32_t*)0x20000688 = htobe32(0);
*(uint32_t*)0x2000068c = htobe32(0xe0000001);
*(uint32_t*)0x20000690 = htobe32(0);
*(uint32_t*)0x20000694 = htobe32(-1);
*(uint32_t*)0x20000698 = htobe32(0);
*(uint32_t*)0x2000069c = htobe32(0xe0000001);
*(uint32_t*)0x200006a0 = htobe32(0);
*(uint32_t*)0x200006a4 = htobe32(0xe0000002);
*(uint32_t*)0x200006a8 = htobe32(0);
*(uint8_t*)0x200006ac = 0x89;
*(uint8_t*)0x200006ad = 0x27;
*(uint8_t*)0x200006ae = 0;
*(uint8_t*)0x200006af = 0xac;
*(uint8_t*)0x200006b0 = 0x14;
*(uint8_t*)0x200006b1 = 0x14;
*(uint8_t*)0x200006b2 = 0xaa;
*(uint32_t*)0x200006b3 = htobe32(-1);
*(uint32_t*)0x200006b7 = htobe32(0x7f000001);
*(uint32_t*)0x200006bb = htobe32(0xe0000002);
*(uint32_t*)0x200006bf = htobe32(0xe0000002);
*(uint8_t*)0x200006c3 = 0xac;
*(uint8_t*)0x200006c4 = 0x14;
*(uint8_t*)0x200006c5 = 0x14;
*(uint8_t*)0x200006c6 = 0;
*(uint32_t*)0x200006c7 = htobe32(0);
*(uint32_t*)0x200006cb = htobe32(0x7f000001);
*(uint8_t*)0x200006cf = 0xac;
*(uint8_t*)0x200006d0 = 0x14;
*(uint8_t*)0x200006d1 = 0x14;
*(uint8_t*)0x200006d2 = 0;
*(uint8_t*)0x200006d3 = 0x44;
*(uint8_t*)0x200006d4 = 0x3c;
*(uint8_t*)0x200006d5 = 0;
STORE_BY_BITMASK(uint8_t, , 0x200006d6, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200006d6, 0, 4, 4);
*(uint32_t*)0x200006d7 = htobe32(0);
*(uint32_t*)0x200006db = htobe32(0);
*(uint8_t*)0x200006df = 0xac;
*(uint8_t*)0x200006e0 = 0x1e;
*(uint8_t*)0x200006e1 = 0;
*(uint8_t*)0x200006e2 = 1;
*(uint32_t*)0x200006e3 = htobe32(0);
*(uint32_t*)0x200006e7 = htobe32(0);
*(uint32_t*)0x200006eb = htobe32(0);
*(uint8_t*)0x200006ef = 0xac;
*(uint8_t*)0x200006f0 = 0x14;
*(uint8_t*)0x200006f1 = 0x14;
*(uint8_t*)0x200006f2 = 0xbb;
*(uint32_t*)0x200006f3 = htobe32(0);
*(uint8_t*)0x200006f7 = 0xac;
*(uint8_t*)0x200006f8 = 0x14;
*(uint8_t*)0x200006f9 = 0x14;
*(uint8_t*)0x200006fa = 0xbb;
*(uint32_t*)0x200006fb = htobe32(0);
*(uint32_t*)0x200006ff = htobe32(-1);
*(uint32_t*)0x20000703 = htobe32(0);
*(uint32_t*)0x20000707 = htobe32(0xe0000002);
*(uint32_t*)0x2000070b = htobe32(0);
*(uint8_t*)0x2000070f = 0x83;
*(uint8_t*)0x20000710 = 0xf;
*(uint8_t*)0x20000711 = 0;
*(uint32_t*)0x20000712 = htobe32(0xe0000002);
*(uint8_t*)0x20000716 = 0xac;
*(uint8_t*)0x20000717 = 0x1e;
*(uint8_t*)0x20000718 = 0;
*(uint8_t*)0x20000719 = 1;
*(uint32_t*)0x2000071a = htobe32(0xe0000002);
*(uint8_t*)0x2000071e = 0x44;
*(uint8_t*)0x2000071f = 0x54;
*(uint8_t*)0x20000720 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000721, 1, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000721, 0, 4, 4);
*(uint32_t*)0x20000722 = htobe32(0);
*(uint32_t*)0x20000726 = htobe32(0);
*(uint32_t*)0x2000072a = htobe32(0);
*(uint32_t*)0x2000072e = htobe32(0);
*(uint8_t*)0x20000732 = 0xac;
*(uint8_t*)0x20000733 = 0x14;
*(uint8_t*)0x20000734 = 0x14;
*(uint8_t*)0x20000735 = 0;
*(uint32_t*)0x20000736 = htobe32(0);
*(uint32_t*)0x2000073a = htobe32(0);
*(uint32_t*)0x2000073e = htobe32(0);
*(uint32_t*)0x20000742 = htobe32(0xe0000002);
*(uint32_t*)0x20000746 = htobe32(0);
*(uint32_t*)0x2000074a = htobe32(0x7f000001);
*(uint32_t*)0x2000074e = htobe32(0);
*(uint32_t*)0x20000752 = htobe32(0x7f000001);
*(uint32_t*)0x20000756 = htobe32(0);
*(uint32_t*)0x2000075a = htobe32(0xe0000001);
*(uint32_t*)0x2000075e = htobe32(0);
*(uint32_t*)0x20000762 = htobe32(0);
*(uint32_t*)0x20000766 = htobe32(0);
*(uint8_t*)0x2000076a = 0xac;
*(uint8_t*)0x2000076b = 0x1e;
*(uint8_t*)0x2000076c = 0;
*(uint8_t*)0x2000076d = 1;
*(uint32_t*)0x2000076e = htobe32(0);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x20000660, 276);
*(uint16_t*)0x2000066a = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[1], 0x89f1, 0x20000780ul);
	return 0;
}
