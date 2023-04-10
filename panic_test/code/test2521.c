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
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000050 = 0x20000180;
memcpy((void*)0x20000180, "\x73\x79\x7a\x74\x6e\x6c\x30\x00\x00\xed\xff\xff\xfe\x00\x00\x00", 16);
*(uint32_t*)0x20000190 = 0;
memcpy((void*)0x20000194, "\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x45\x00\xfe\xa7\x00\x00\x00\x00\x00\x00\x90\x78\xe0\x01\xff\xff\xff\xff\x00\x00", 32);
	syscall(__NR_ioctl, r[0], 0x89f1, 0x20000040ul);
memcpy((void*)0x20000140, "syztnl0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000150 = 0x20000080;
memcpy((void*)0x20000080, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000090 = 0;
*(uint16_t*)0x20000094 = htobe16(0);
*(uint16_t*)0x20000096 = htobe16(0);
*(uint32_t*)0x20000098 = htobe32(0);
*(uint32_t*)0x2000009c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000a1, 0, 2, 6);
*(uint16_t*)0x200000a2 = htobe16(0x14);
*(uint16_t*)0x200000a4 = htobe16(0);
*(uint16_t*)0x200000a6 = htobe16(0);
*(uint8_t*)0x200000a8 = 0;
*(uint8_t*)0x200000a9 = 0;
*(uint16_t*)0x200000aa = htobe16(0);
*(uint32_t*)0x200000ac = htobe32(0);
*(uint8_t*)0x200000b0 = 0xac;
*(uint8_t*)0x200000b1 = 0x14;
*(uint8_t*)0x200000b2 = 0x14;
*(uint8_t*)0x200000b3 = 0xaa;
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x200000a0, 20);
*(uint16_t*)0x200000aa = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[0], 0x89f2, 0x20000140ul);
	return 0;
}
