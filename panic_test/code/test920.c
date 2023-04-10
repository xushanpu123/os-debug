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
	syscall(__NR_sendmsg, -1, 0ul, 0x8008800ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000980, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000990 = 0x20000900;
memcpy((void*)0x20000900, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000910 = 0;
*(uint16_t*)0x20000914 = htobe16(0);
*(uint16_t*)0x20000916 = htobe16(0);
*(uint32_t*)0x20000918 = htobe32(0);
*(uint32_t*)0x2000091c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x20000920, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000920, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000921, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000921, 0, 2, 6);
*(uint16_t*)0x20000922 = htobe16(0x14);
*(uint16_t*)0x20000924 = htobe16(0);
*(uint16_t*)0x20000926 = htobe16(0);
*(uint8_t*)0x20000928 = 0;
*(uint8_t*)0x20000929 = 0x2f;
*(uint16_t*)0x2000092a = htobe16(0);
*(uint32_t*)0x2000092c = htobe32(0xe0000001);
*(uint8_t*)0x20000930 = 0xac;
*(uint8_t*)0x20000931 = 0x14;
*(uint8_t*)0x20000932 = 0x14;
*(uint8_t*)0x20000933 = 0xbb;
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x20000920, 20);
*(uint16_t*)0x2000092a = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, r[0], 0x89f2, 0x20000980ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000080, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000090 = 0x20000000;
memcpy((void*)0x20000000, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000010 = 0;
*(uint16_t*)0x20000014 = htobe16(0);
*(uint16_t*)0x20000016 = htobe16(0);
*(uint32_t*)0x20000018 = htobe32(0);
*(uint32_t*)0x2000001c = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x20000020, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000020, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000021, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000021, 0, 2, 6);
*(uint16_t*)0x20000022 = htobe16(0x14);
*(uint16_t*)0x20000024 = htobe16(0);
*(uint16_t*)0x20000026 = htobe16(0);
*(uint8_t*)0x20000028 = 0;
*(uint8_t*)0x20000029 = 0;
*(uint16_t*)0x2000002a = htobe16(0);
*(uint8_t*)0x2000002c = 0xac;
*(uint8_t*)0x2000002d = 0x14;
*(uint8_t*)0x2000002e = 0x14;
*(uint8_t*)0x2000002f = 0;
*(uint32_t*)0x20000030 = htobe32(0);
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x20000020, 20);
*(uint16_t*)0x2000002a = csum_inet_digest(&csum_2);
	syscall(__NR_ioctl, r[1], 0x89f1, 0x20000080ul);
	return 0;
}
