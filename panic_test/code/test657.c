// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __NR_fsconfig
#define __NR_fsconfig 431
#endif
#ifndef __NR_fspick
#define __NR_fspick 433
#endif

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

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

static long syz_clone(volatile long flags, volatile long stack, volatile long stack_len,
		      volatile long ptid, volatile long ctid, volatile long tls)
{
	long sp = (stack + stack_len) & ~15;
	long ret = (long)syscall(__NR_clone, flags & ~CLONE_VM, sp, ptid, ctid, tls);
	return handle_clone_ret(ret);
}

uint64_t r[6] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_ioctl, -1, 0x5429, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000000;
	syscall(__NR_ptrace, 6ul, r[0], 2ul, 0xfffffffffffffff9ul);
	syscall(__NR_ioctl, -1, 0x5429, 0x20000040ul);
	syscall(__NR_getpid);
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000180 = 0xf3;
*(uint64_t*)0x20000188 = 0x20000080;
memcpy((void*)0x20000080, "\x54\xbb\xcc\xcf\x46\x34\xf4\x6b\xf3\xbf\xdb\x3c\x94\x70\x03\x71\xe5\x23\xe7\x5d\xf4\xd0\x89\x62\x83\xbc\xfc\x5d\xb1\x9c\x5f\xa5\x62\xd4\xe9\x3f\x6b\x8c\x52\xae\x36\x70\x16\x5c\x31\x03\x2e\x4d\x43\x27\x11\xeb\x3a\xf9\x2b\xf2\x6a\x7d\xc1\xbb\x6b\xd6\x3d\x98\x8a\xd0\xf1\xb7\x33\x5a\xf3\x37\xb9\x6d\x82\x6d\xe0\x23\x3e\x56\x52\x2a\x99\xb3\xee\xfd\x03\x14\x25\x68\x1b\x07\x5e\x5f\x42\xd0\xa6\xfa\x97\xcf\xda\xde\xa5\xbf\x9d\x64\x7d\xcb\x83\x13\x1b\x97\x41\x8a\x33\x04\x0d\xbe\x6c\x4a\x60\x11\x50\x19\x8a\x41\x9c\x57\x4d\x8f\xbb\x68\xc5\xa0\xd2\xc3\xd2\x08\xc6\x1f\x5c\xd0\x1a\xd1\x2b\x51\x95\x33\x16\x7d\x46\x9a\x5c\xf3\xd4\x57\x55\xce\x4f\x36\x9f\xe3\x5a\x1a\x8d\x6d\x8e\xb2\x95\x28\x5b\xa3\x98\xab\xfc\x09\x0c\x80\xb4\x54\xbd\x2f\x15\x08\x78\x6d\x92\xa8\xd7\x1a\xe7\x37\xa3\xdd\xce\xc1\xd6\x18\x42\x50\x65\x26\x01\x2e\x41\x18\x41\x97\x56\x3e\xe9\x5e\xaf\x49\x31\xa3\xcc\x32\xdd\x10\x8b\x21\x66\x0d\xce\x7e\xee\x81\x1c\xd3\x79\xbf\xd0\x7d\x69\x7a\xdd\x0e\x61\x1f\x8d\x7e\x4b", 243);
	syscall(__NR_ioctl, -1, 0x8912, 0x20000180ul);
	syscall(__NR_ioctl, r[1], 0x5413, 0x200001c0ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[2] = res;
*(uint32_t*)0x20000240 = 0xc;
	syscall(__NR_getsockopt, r[2], 0, 0x481, 0x20000200ul, 0x20000240ul);
memcpy((void*)0x20000280, "./file0\000", 8);
	res = syscall(__NR_fspick, -1, 0x20000280ul, 1ul);
	if (res != -1)
		r[3] = res;
memcpy((void*)0x200002c0, "&[,\000", 4);
memcpy((void*)0x20000300, "{{/", 3);
	syscall(__NR_fsconfig, r[3], 1ul, 0x200002c0ul, 0x20000300ul, 0ul);
memset((void*)0x20000340, 0, 1);
memcpy((void*)0x20000380, "\'\'^\000", 4);
	syscall(__NR_init_module, 0x20000340ul, 1ul, 0x20000380ul);
	res = syscall(__NR_socketpair, 0x15ul, 0xaul, 0, 0x200003c0ul);
	if (res != -1)
r[4] = *(uint32_t*)0x200003c4;
*(uint64_t*)0x20000580 = 0x20000400;
*(uint16_t*)0x20000400 = 0x10;
*(uint16_t*)0x20000402 = 0;
*(uint32_t*)0x20000404 = 0;
*(uint32_t*)0x20000408 = 0x10;
*(uint32_t*)0x20000588 = 0xc;
*(uint64_t*)0x20000590 = 0x20000540;
*(uint64_t*)0x20000540 = 0x20000440;
*(uint32_t*)0x20000440 = 0xec;
*(uint16_t*)0x20000444 = 0;
*(uint16_t*)0x20000446 = 0x400;
*(uint32_t*)0x20000448 = 0x70bd2c;
*(uint32_t*)0x2000044c = 0x25dfdbfd;
*(uint8_t*)0x20000450 = 0x11;
*(uint8_t*)0x20000451 = 0;
*(uint16_t*)0x20000452 = 0;
*(uint16_t*)0x20000454 = 0x60;
STORE_BY_BITMASK(uint16_t, , 0x20000456, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000457, 1, 7, 1);
*(uint16_t*)0x20000458 = 0x14;
*(uint16_t*)0x2000045a = 2;
memcpy((void*)0x2000045c, "syzkaller1\000\000\000\000\000\000", 16);
*(uint16_t*)0x2000046c = 0x14;
*(uint16_t*)0x2000046e = 2;
memcpy((void*)0x20000470, "virt_wifi0\000\000\000\000\000\000", 16);
*(uint16_t*)0x20000480 = 8;
*(uint16_t*)0x20000482 = 1;
*(uint32_t*)0x20000484 = 0;
*(uint16_t*)0x20000488 = 8;
*(uint16_t*)0x2000048a = 1;
*(uint32_t*)0x2000048c = 0;
*(uint16_t*)0x20000490 = 8;
*(uint16_t*)0x20000492 = 3;
*(uint32_t*)0x20000494 = 0;
*(uint16_t*)0x20000498 = 8;
*(uint16_t*)0x2000049a = 3;
*(uint32_t*)0x2000049c = 0;
*(uint16_t*)0x200004a0 = 0x14;
*(uint16_t*)0x200004a2 = 2;
memcpy((void*)0x200004a4, "veth0_vlan\000\000\000\000\000\000", 16);
*(uint16_t*)0x200004b4 = 0x20;
STORE_BY_BITMASK(uint16_t, , 0x200004b6, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200004b7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200004b7, 1, 7, 1);
*(uint16_t*)0x200004b8 = 8;
*(uint16_t*)0x200004ba = 1;
*(uint32_t*)0x200004bc = 0;
*(uint16_t*)0x200004c0 = 0x14;
*(uint16_t*)0x200004c2 = 2;
memcpy((void*)0x200004c4, "virt_wifi0\000\000\000\000\000\000", 16);
*(uint16_t*)0x200004d4 = 0x58;
STORE_BY_BITMASK(uint16_t, , 0x200004d6, 1, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200004d7, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200004d7, 1, 7, 1);
*(uint16_t*)0x200004d8 = 0x14;
*(uint16_t*)0x200004da = 2;
memcpy((void*)0x200004dc, "team_slave_0\000\000\000\000", 16);
*(uint16_t*)0x200004ec = 0x14;
*(uint16_t*)0x200004ee = 2;
memcpy((void*)0x200004f0, "vlan1\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint16_t*)0x20000500 = 8;
*(uint16_t*)0x20000502 = 1;
*(uint32_t*)0x20000504 = 0;
*(uint16_t*)0x20000508 = 8;
*(uint16_t*)0x2000050a = 1;
*(uint32_t*)0x2000050c = 0;
*(uint16_t*)0x20000510 = 0x14;
*(uint16_t*)0x20000512 = 2;
memcpy((void*)0x20000514, "dvmrp0\000\000\000\000\000\000\000\000\000\000", 16);
*(uint16_t*)0x20000524 = 8;
*(uint16_t*)0x20000526 = 1;
*(uint32_t*)0x20000528 = 0;
*(uint64_t*)0x20000548 = 0xec;
*(uint64_t*)0x20000598 = 1;
*(uint64_t*)0x200005a0 = 0;
*(uint64_t*)0x200005a8 = 0;
*(uint32_t*)0x200005b0 = 0;
	syscall(__NR_sendmsg, r[4], 0x20000580ul, 4ul);
*(uint64_t*)0x200006c0 = 0x200005c0;
*(uint16_t*)0x200005c0 = 0x10;
*(uint16_t*)0x200005c2 = 0;
*(uint32_t*)0x200005c4 = 0;
*(uint32_t*)0x200005c8 = 0x20000000;
*(uint32_t*)0x200006c8 = 0xc;
*(uint64_t*)0x200006d0 = 0x20000680;
*(uint64_t*)0x20000680 = 0x20000600;
*(uint32_t*)0x20000600 = 0x4c;
*(uint16_t*)0x20000604 = 0;
*(uint16_t*)0x20000606 = 0x200;
*(uint32_t*)0x20000608 = 0x70bd2a;
*(uint32_t*)0x2000060c = 0x25dfdbfc;
*(uint8_t*)0x20000610 = 0x6b;
*(uint8_t*)0x20000611 = 0;
*(uint16_t*)0x20000612 = 0;
*(uint16_t*)0x20000614 = 8;
*(uint16_t*)0x20000616 = 3;
*(uint32_t*)0x20000618 = 0;
*(uint16_t*)0x2000061c = 0xa;
*(uint16_t*)0x2000061e = 6;
*(uint8_t*)0x20000620 = 8;
*(uint8_t*)0x20000621 = 2;
*(uint8_t*)0x20000622 = 0x11;
*(uint8_t*)0x20000623 = 0;
*(uint8_t*)0x20000624 = 0;
*(uint8_t*)0x20000625 = 0;
*(uint16_t*)0x20000628 = 0xa;
*(uint16_t*)0x2000062a = 0x1a;
memset((void*)0x2000062c, 255, 6);
*(uint16_t*)0x20000634 = 0xa;
*(uint16_t*)0x20000636 = 0x1a;
memset((void*)0x20000638, 255, 6);
*(uint16_t*)0x20000640 = 0xa;
*(uint16_t*)0x20000642 = 0x1a;
*(uint8_t*)0x20000644 = 8;
*(uint8_t*)0x20000645 = 2;
*(uint8_t*)0x20000646 = 0x11;
*(uint8_t*)0x20000647 = 0;
*(uint8_t*)0x20000648 = 0;
*(uint8_t*)0x20000649 = 1;
*(uint64_t*)0x20000688 = 0x4c;
*(uint64_t*)0x200006d8 = 1;
*(uint64_t*)0x200006e0 = 0;
*(uint64_t*)0x200006e8 = 0;
*(uint32_t*)0x200006f0 = 0x44045;
	syscall(__NR_sendmsg, r[4], 0x200006c0ul, 0x10ul);
	syscall(__NR_ioctl, r[1], 0x5413, 0x20000700ul);
	res = syscall(__NR_socket, 0xaul, 0x80809ul, 0x6d4d);
	if (res != -1)
		r[5] = res;
*(uint16_t*)0x20000740 = -1;
*(uint8_t*)0x20000742 = 0;
*(uint8_t*)0x20000743 = 0x7f;
*(uint32_t*)0x20000744 = 0;
*(uint32_t*)0x20000748 = 0x3ad;
	syscall(__NR_setsockopt, r[5], 0x29, 0xcb, 0x20000740ul, 0xcul);
memcpy((void*)0x20000780, "\xeb\xd8\x8a\xce\x3d\xa6\x17\xa9\x3f\x69\x8f\x23\x96\x51\x74\x23\x64\x6d\x63\xe0\x73\x6c\x77\x9a\xdf\x14\xdb\x95\x4c\x1e\x3c\xb2\x08\x09\xff\x5b\x7c\x91\x2e\x9c\xaa\x63\x59\xf1\x5c\x63\x02\x91\xbb\x1c\x55\xf5\x27\xf3\x24\x64\x03\x55\xf7\x52\x5e\xdd\x46\x2f\x28\x15\x3b\x59\x55\xab\xb1\xcf\x72\xa7\xa3\xf1\x7c\x1c\xca\x8c\x9e\x00\x20\x03\xb5\xb1\x3d\xd4\x5d\x39\x66\x1f\x31\x4f\xec\xce\x22\x58", 98);
memcpy((void*)0x20000880, "\x30\x9e\x4d\xce\xa3\xf3\xdc\x03\x77\x10\x13\x06\x57\xa0\xbf\xae\x23\x54\x23\xba\x2f\x7b\x9f\x12\x2c\x48\x6f\xc6\xfa\x80\x78\x7c\x65\x7b\xb9\x1b\x5f\xa0\xd2\x47\x3d\x79\x45\x00\x95\x7d\xdd\xc8\xc7\x51\x8d\xb7\xdf\xf2\xbf\x15\x0f\xb7\xb1\xf4\xe7\x08\x04\x95\xa1\xd1\xdd", 67);
syz_clone(0x40001000, 0x20000780, 0x62, 0x20000800, 0x20000840, 0x20000880);
memcpy((void*)0x20000900, "{{/", 3);
memcpy((void*)0x20000940, "team_slave_0\000", 13);
	syscall(__NR_fsconfig, r[3], 1ul, 0x20000900ul, 0x20000940ul, 0ul);
	return 0;
}