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

#ifndef __NR_rseq
#define __NR_rseq 334
#endif

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

uint64_t r[11] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
	syscall(__NR_setsockopt, r[0], 0, 0xd, 0ul, 0ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000940, "team0\000\000\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, r[1], 0x8933, 0x20000940ul);
*(uint32_t*)0x20000380 = 1;
memcpy((void*)0x20000384, "macvlan1\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 24);
*(uint32_t*)0x2000039c = 0;
*(uint16_t*)0x200003b4 = 0x412;
	syscall(__NR_ioctl, r[0], 0x8983, 0x20000380ul);
memcpy((void*)0x20000500, "/dev/nvram\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000500ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_accept, r[2], 0ul, 0ul);
	if (res != -1)
		r[3] = res;
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[4] = res;
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[5] = res;
	syscall(__NR_ioctl, r[5], 0x8907, 0ul);
*(uint64_t*)0x20000080 = 0;
	syscall(__NR_ioctl, r[5], 0x40089416, 0x20000080ul);
memcpy((void*)0x20000940, "team0\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[4], 0x8933, 0x20000940ul);
	if (res != -1)
r[6] = *(uint32_t*)0x20000950;
memcpy((void*)0x200001c0, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200001d0 = 0x20000100;
memcpy((void*)0x20000100, "\x69\x70\x5f\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00", 16);
*(uint32_t*)0x20000110 = r[6];
memcpy((void*)0x20000114, "\x00\x20\x80\x00\x00\x00\x00\x00\x00\x00\x00\x01\x4b\x14\x00\x6c\x00\x66\x00\x00\x7f\x04\x90\x78\x64\x01\x01\x02\xff\xff\xff\xff\x44\x14\x54\x33\x7f\x00\x00\x01\x00\x00\x00\x03\x64\x01\x01\x01\x00\x00\x00\x06\x44\x44\x42\x03\xe0\x00\x00\x02\x00\x00\x00\x08\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x0a\x01\x01\x02\x00\x00\x00\x01\xe0\x00\x00\x01\x00\x00\x00\x00\xe0\x00\x00\x02\x00\x00\x00\x33\x7f\x00\x00\x01\x00\x00\x00\x00\x64\x01\x01\x00\x00\x00\x03\xff", 120);
	res = syscall(__NR_ioctl, r[2], 0x89f1, 0x200001c0ul);
	if (res != -1)
r[7] = *(uint32_t*)0x20000110;
memcpy((void*)0x20000200, "vcan0\000\000\000\000\000\000\000\000\000\000\000", 16);
	res = syscall(__NR_ioctl, r[4], 0x8933, 0x20000200ul);
	if (res != -1)
r[8] = *(uint32_t*)0x20000210;
memcpy((void*)0x200002c0, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200002d0 = 0x20000240;
memcpy((void*)0x20000240, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000250 = r[6];
*(uint16_t*)0x20000254 = htobe16(1);
*(uint16_t*)0x20000256 = htobe16(0x20);
*(uint32_t*)0x20000258 = htobe32(7);
*(uint32_t*)0x2000025c = htobe32(3);
STORE_BY_BITMASK(uint8_t, , 0x20000260, 9, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000260, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000261, 3, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000261, 0x31, 2, 6);
*(uint16_t*)0x20000262 = htobe16(0x24);
*(uint16_t*)0x20000264 = htobe16(0x67);
*(uint16_t*)0x20000266 = htobe16(0);
*(uint8_t*)0x20000268 = 0;
*(uint8_t*)0x20000269 = 0x29;
*(uint16_t*)0x2000026a = htobe16(0);
*(uint32_t*)0x2000026c = htobe32(0x7f000001);
*(uint32_t*)0x20000270 = htobe32(0xe0000002);
*(uint8_t*)0x20000274 = 0;
*(uint8_t*)0x20000275 = 7;
*(uint8_t*)0x20000276 = 0xb;
*(uint8_t*)0x20000277 = 0x6c;
*(uint32_t*)0x20000278 = htobe32(0x7f000001);
*(uint32_t*)0x2000027c = htobe32(0xe0000001);
*(uint8_t*)0x20000280 = 1;
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x20000260, 36);
*(uint16_t*)0x2000026a = csum_inet_digest(&csum_1);
	res = syscall(__NR_ioctl, r[3], 0x89f2, 0x200002c0ul);
	if (res != -1)
r[9] = *(uint32_t*)0x20000250;
*(uint64_t*)0x20000340 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x10;
*(uint16_t*)0x200000c2 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0x80000;
*(uint32_t*)0x20000348 = 0xc;
*(uint64_t*)0x20000350 = 0x20000300;
*(uint64_t*)0x20000300 = 0x20000540;
*(uint32_t*)0x20000540 = 0x33c;
*(uint16_t*)0x20000544 = 0;
*(uint16_t*)0x20000546 = 0x200;
*(uint32_t*)0x20000548 = 0x70bd29;
*(uint32_t*)0x2000054c = 0x25dfdbfb;
*(uint8_t*)0x20000550 = 3;
*(uint8_t*)0x20000551 = 0;
*(uint16_t*)0x20000552 = 0;
*(uint16_t*)0x20000554 = 8;
*(uint16_t*)0x20000556 = 1;
*(uint32_t*)0x20000558 = r[7];
*(uint16_t*)0x2000055c = 0xb8;
STORE_BY_BITMASK(uint16_t, , 0x2000055e, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000055f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000055f, 1, 7, 1);
*(uint16_t*)0x20000560 = 0x38;
*(uint16_t*)0x20000562 = 1;
*(uint16_t*)0x20000564 = 0x24;
*(uint16_t*)0x20000566 = 1;
memcpy((void*)0x20000568, "mcast_rejoin_count\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x20000588 = 5;
*(uint16_t*)0x2000058a = 3;
*(uint8_t*)0x2000058c = 3;
*(uint16_t*)0x20000590 = 8;
*(uint16_t*)0x20000592 = 4;
*(uint32_t*)0x20000594 = 0xff;
*(uint16_t*)0x20000598 = 0x3c;
*(uint16_t*)0x2000059a = 1;
*(uint16_t*)0x2000059c = 0x24;
*(uint16_t*)0x2000059e = 1;
memcpy((void*)0x200005a0, "lb_tx_method\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200005c0 = 5;
*(uint16_t*)0x200005c2 = 3;
*(uint8_t*)0x200005c4 = 5;
*(uint16_t*)0x200005c8 = 9;
*(uint16_t*)0x200005ca = 4;
memcpy((void*)0x200005cc, "hash\000", 5);
*(uint16_t*)0x200005d4 = 0x40;
*(uint16_t*)0x200005d6 = 1;
*(uint16_t*)0x200005d8 = 0x24;
*(uint16_t*)0x200005da = 1;
memcpy((void*)0x200005dc, "lb_port_stats\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200005fc = 5;
*(uint16_t*)0x200005fe = 3;
*(uint8_t*)0x20000600 = 0xb;
*(uint16_t*)0x20000604 = 8;
*(uint16_t*)0x20000606 = 4;
*(uint32_t*)0x20000608 = 0x7fffffff;
*(uint16_t*)0x2000060c = 8;
*(uint16_t*)0x2000060e = 6;
*(uint32_t*)0x20000610 = 0;
*(uint16_t*)0x20000614 = 8;
*(uint16_t*)0x20000616 = 1;
*(uint32_t*)0x20000618 = r[6];
*(uint16_t*)0x2000061c = 0x260;
STORE_BY_BITMASK(uint16_t, , 0x2000061e, 2, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000061f, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000061f, 1, 7, 1);
*(uint16_t*)0x20000620 = 0x3c;
*(uint16_t*)0x20000622 = 1;
*(uint16_t*)0x20000624 = 0x24;
*(uint16_t*)0x20000626 = 1;
memcpy((void*)0x20000628, "user_linkup_enabled\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x20000648 = 5;
*(uint16_t*)0x2000064a = 3;
*(uint8_t*)0x2000064c = 6;
*(uint16_t*)0x20000650 = 4;
*(uint16_t*)0x20000652 = 4;
*(uint16_t*)0x20000654 = 8;
*(uint16_t*)0x20000656 = 6;
*(uint32_t*)0x20000658 = r[6];
*(uint16_t*)0x2000065c = 0x38;
*(uint16_t*)0x2000065e = 1;
*(uint16_t*)0x20000660 = 0x24;
*(uint16_t*)0x20000662 = 1;
memcpy((void*)0x20000664, "lb_stats_refresh_interval\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x20000684 = 5;
*(uint16_t*)0x20000686 = 3;
*(uint8_t*)0x20000688 = 3;
*(uint16_t*)0x2000068c = 8;
*(uint16_t*)0x2000068e = 4;
*(uint32_t*)0x20000690 = 0;
*(uint16_t*)0x20000694 = 0x40;
*(uint16_t*)0x20000696 = 1;
*(uint16_t*)0x20000698 = 0x24;
*(uint16_t*)0x2000069a = 1;
memcpy((void*)0x2000069c, "queue_id\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200006bc = 5;
*(uint16_t*)0x200006be = 3;
*(uint8_t*)0x200006c0 = 3;
*(uint16_t*)0x200006c4 = 8;
*(uint16_t*)0x200006c6 = 4;
*(uint32_t*)0x200006c8 = 3;
*(uint16_t*)0x200006cc = 8;
*(uint16_t*)0x200006ce = 6;
*(uint32_t*)0x200006d0 = r[6];
*(uint16_t*)0x200006d4 = 0x40;
*(uint16_t*)0x200006d6 = 1;
*(uint16_t*)0x200006d8 = 0x24;
*(uint16_t*)0x200006da = 1;
memcpy((void*)0x200006dc, "lb_port_stats\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200006fc = 5;
*(uint16_t*)0x200006fe = 3;
*(uint8_t*)0x20000700 = 0xb;
*(uint16_t*)0x20000704 = 8;
*(uint16_t*)0x20000706 = 4;
*(uint32_t*)0x20000708 = 0x8001;
*(uint16_t*)0x2000070c = 8;
*(uint16_t*)0x2000070e = 6;
*(uint32_t*)0x20000710 = r[8];
*(uint16_t*)0x20000714 = 0x40;
*(uint16_t*)0x20000716 = 1;
*(uint16_t*)0x20000718 = 0x24;
*(uint16_t*)0x2000071a = 1;
memcpy((void*)0x2000071c, "lb_port_stats\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x2000073c = 5;
*(uint16_t*)0x2000073e = 3;
*(uint8_t*)0x20000740 = 0xb;
*(uint16_t*)0x20000744 = 8;
*(uint16_t*)0x20000746 = 4;
*(uint32_t*)0x20000748 = 1;
*(uint16_t*)0x2000074c = 8;
*(uint16_t*)0x2000074e = 6;
*(uint32_t*)0x20000750 = r[6];
*(uint16_t*)0x20000754 = 0x38;
*(uint16_t*)0x20000756 = 1;
*(uint16_t*)0x20000758 = 0x24;
*(uint16_t*)0x2000075a = 1;
memcpy((void*)0x2000075c, "notify_peers_interval\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x2000077c = 5;
*(uint16_t*)0x2000077e = 3;
*(uint8_t*)0x20000780 = 3;
*(uint16_t*)0x20000784 = 8;
*(uint16_t*)0x20000786 = 4;
*(uint32_t*)0x20000788 = 7;
*(uint16_t*)0x2000078c = 0x3c;
*(uint16_t*)0x2000078e = 1;
*(uint16_t*)0x20000790 = 0x24;
*(uint16_t*)0x20000792 = 1;
memcpy((void*)0x20000794, "enabled\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200007b4 = 5;
*(uint16_t*)0x200007b6 = 3;
*(uint8_t*)0x200007b8 = 6;
*(uint16_t*)0x200007bc = 4;
*(uint16_t*)0x200007be = 4;
*(uint16_t*)0x200007c0 = 8;
*(uint16_t*)0x200007c2 = 6;
*(uint32_t*)0x200007c4 = r[9];
*(uint16_t*)0x200007c8 = 0x3c;
*(uint16_t*)0x200007ca = 1;
*(uint16_t*)0x200007cc = 0x24;
*(uint16_t*)0x200007ce = 1;
memcpy((void*)0x200007d0, "lb_tx_method\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x200007f0 = 5;
*(uint16_t*)0x200007f2 = 3;
*(uint8_t*)0x200007f4 = 5;
*(uint16_t*)0x200007f8 = 9;
*(uint16_t*)0x200007fa = 4;
memcpy((void*)0x200007fc, "hash\000", 5);
*(uint16_t*)0x20000804 = 0x40;
*(uint16_t*)0x20000806 = 1;
*(uint16_t*)0x20000808 = 0x24;
*(uint16_t*)0x2000080a = 1;
memcpy((void*)0x2000080c, "lb_hash_stats\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x2000082c = 5;
*(uint16_t*)0x2000082e = 3;
*(uint8_t*)0x20000830 = 0xb;
*(uint16_t*)0x20000834 = 8;
*(uint16_t*)0x20000836 = 4;
*(uint32_t*)0x20000838 = 2;
*(uint16_t*)0x2000083c = 8;
*(uint16_t*)0x2000083e = 7;
*(uint32_t*)0x20000840 = 0;
*(uint16_t*)0x20000844 = 0x38;
*(uint16_t*)0x20000846 = 1;
*(uint16_t*)0x20000848 = 0x24;
*(uint16_t*)0x2000084a = 1;
memcpy((void*)0x2000084c, "activeport\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint16_t*)0x2000086c = 5;
*(uint16_t*)0x2000086e = 3;
*(uint8_t*)0x20000870 = 3;
*(uint16_t*)0x20000874 = 8;
*(uint16_t*)0x20000876 = 4;
*(uint32_t*)0x20000878 = r[6];
*(uint64_t*)0x20000308 = 0x33c;
*(uint64_t*)0x20000358 = 1;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0x880c;
	syscall(__NR_sendmsg, r[2], 0x20000340ul, 0x20048800ul);
*(uint32_t*)0x20000000 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint64_t*)0x20000008 = 0;
*(uint32_t*)0x20000010 = 0;
	syscall(__NR_rseq, 0x20000000ul, 0x20ul, 0ul, 0ul);
memcpy((void*)0x200002c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[10] = res;
	syscall(__NR_fsync, r[10]);
memcpy((void*)0x20000040, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000050 = 0x20000000;
memcpy((void*)0x20000000, "erspan0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000010 = r[6];
*(uint16_t*)0x20000014 = htobe16(0x700);
*(uint16_t*)0x20000016 = htobe16(0x8000);
*(uint32_t*)0x20000018 = htobe32(0x100);
*(uint32_t*)0x2000001c = htobe32(7);
STORE_BY_BITMASK(uint8_t, , 0x20000020, 5, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000020, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000021, 1, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000021, 0x33, 2, 6);
*(uint16_t*)0x20000022 = htobe16(0x14);
*(uint16_t*)0x20000024 = htobe16(0x65);
*(uint16_t*)0x20000026 = htobe16(0);
*(uint8_t*)0x20000028 = 4;
*(uint8_t*)0x20000029 = 0x29;
*(uint16_t*)0x2000002a = htobe16(0);
*(uint32_t*)0x2000002c = htobe32(0xe0000002);
*(uint8_t*)0x20000030 = 0xac;
*(uint8_t*)0x20000031 = 0x14;
*(uint8_t*)0x20000032 = 0x14;
*(uint8_t*)0x20000033 = 0xaa;
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x20000020, 20);
*(uint16_t*)0x2000002a = csum_inet_digest(&csum_2);
	syscall(__NR_ioctl, r[1], 0x89f1, 0x20000040ul);
	return 0;
}