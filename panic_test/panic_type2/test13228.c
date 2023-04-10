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
memcpy((void*)0x200001c0, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200001d0 = 0x20000100;
memcpy((void*)0x20000100, "ip_vti0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000110 = 0;
*(uint16_t*)0x20000114 = htobe16(0);
*(uint16_t*)0x20000116 = htobe16(0);
*(uint32_t*)0x20000118 = htobe32(0);
*(uint32_t*)0x2000011c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x20000120, 0x17, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000120, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000121, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000121, 0, 2, 6);
*(uint16_t*)0x20000122 = htobe16(0x5c);
*(uint16_t*)0x20000124 = htobe16(0);
*(uint16_t*)0x20000126 = htobe16(0);
*(uint8_t*)0x20000128 = 0;
*(uint8_t*)0x20000129 = 0;
*(uint16_t*)0x2000012a = htobe16(0);
*(uint32_t*)0x2000012c = htobe32(0);
*(uint32_t*)0x20000130 = htobe32(-1);
*(uint8_t*)0x20000134 = 0x44;
*(uint8_t*)0x20000135 = 0x14;
*(uint8_t*)0x20000136 = 0;
STORE_BY_BITMASK(uint8_t, , 0x20000137, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000137, 0, 4, 4);
*(uint32_t*)0x20000138 = htobe32(0x7f000001);
*(uint32_t*)0x2000013c = htobe32(0);
*(uint32_t*)0x20000140 = htobe32(0);
*(uint32_t*)0x20000144 = htobe32(0);
*(uint8_t*)0x20000148 = 0x44;
*(uint8_t*)0x20000149 = 0x34;
*(uint8_t*)0x2000014a = 0;
STORE_BY_BITMASK(uint8_t, , 0x2000014b, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x2000014b, 0, 4, 4);
*(uint32_t*)0x2000014c = htobe32(0);
*(uint32_t*)0x20000150 = htobe32(0);
*(uint32_t*)0x20000154 = htobe32(-1);
*(uint32_t*)0x20000158 = htobe32(0);
*(uint32_t*)0x2000015c = htobe32(0);
*(uint32_t*)0x20000160 = htobe32(0);
*(uint32_t*)0x20000164 = htobe32(0);
*(uint32_t*)0x20000168 = htobe32(0);
*(uint32_t*)0x2000016c = htobe32(0xe0000001);
*(uint32_t*)0x20000170 = htobe32(0x8000);
*(uint32_t*)0x20000174 = htobe32(0xe0000002);
*(uint32_t*)0x20000178 = htobe32(0x33);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x20000120, 92);
*(uint16_t*)0x2000012a = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, -1, 0x89f1, 0x200001c0ul);
memcpy((void*)0x20000140, "syztnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000150 = 0x20000080;
memcpy((void*)0x20000080, "erspan0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000090 = 0;
memcpy((void*)0x20000094, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x4f\x00\x00\x7c\x00\x00\x00\x00\x00\x00\x90\x78\xe0\x00\x00\x01\xff\xff\xff\xff\x00\x44\x34\x00\x01\xac\x1e\x00\x01\x00\x00\x00\x00\xe0\x00\x00\x02\x00\x00\x00\x00\xac\x14\x14\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xac\x14\x14\x00\x00\x00\x00\x00\xe0\x00\x00\x01\x00\x00\x00\x00\x44\x14\x00\x03\xac\x14\x14\xbb\x00\x00\x00\x00\xe0\x00\x00\x02\x00\x00\x00\x00\x83\x0b\x00\xac\x14\x14\xaa\xac\x14\x14\xaa\x83\x07\x00\x00\x00\x00\x00\x44\x0c\x00\x03\x64\x01", 129);
	syscall(__NR_ioctl, -1, 0x89f1, 0x20000140ul);
	syscall(__NR_setsockopt, r[0], 0, 0x40, 0x200000c0ul, 0ul);
	return 0;
}
