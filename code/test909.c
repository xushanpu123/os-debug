// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <arpa/inet.h>
#include <endian.h>
#include <errno.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/genetlink.h>
#include <linux/if_addr.h>
#include <linux/if_link.h>
#include <linux/in6.h>
#include <linux/neighbour.h>
#include <linux/net.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/veth.h>

#ifndef __NR_renameat2
#define __NR_renameat2 316
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

struct nlmsg {
	char* pos;
	int nesting;
	struct nlattr* nested[8];
	char buf[4096];
};

static void netlink_init(struct nlmsg* nlmsg, int typ, int flags,
			 const void* data, int size)
{
	memset(nlmsg, 0, sizeof(*nlmsg));
	struct nlmsghdr* hdr = (struct nlmsghdr*)nlmsg->buf;
	hdr->nlmsg_type = typ;
	hdr->nlmsg_flags = NLM_F_REQUEST | NLM_F_ACK | flags;
	memcpy(hdr + 1, data, size);
	nlmsg->pos = (char*)(hdr + 1) + NLMSG_ALIGN(size);
}

static void netlink_attr(struct nlmsg* nlmsg, int typ,
			 const void* data, int size)
{
	struct nlattr* attr = (struct nlattr*)nlmsg->pos;
	attr->nla_len = sizeof(*attr) + size;
	attr->nla_type = typ;
	if (size > 0)
		memcpy(attr + 1, data, size);
	nlmsg->pos += NLMSG_ALIGN(attr->nla_len);
}

static int netlink_send_ext(struct nlmsg* nlmsg, int sock,
			    uint16_t reply_type, int* reply_len, bool dofail)
{
	if (nlmsg->pos > nlmsg->buf + sizeof(nlmsg->buf) || nlmsg->nesting)
	exit(1);
	struct nlmsghdr* hdr = (struct nlmsghdr*)nlmsg->buf;
	hdr->nlmsg_len = nlmsg->pos - nlmsg->buf;
	struct sockaddr_nl addr;
	memset(&addr, 0, sizeof(addr));
	addr.nl_family = AF_NETLINK;
	ssize_t n = sendto(sock, nlmsg->buf, hdr->nlmsg_len, 0, (struct sockaddr*)&addr, sizeof(addr));
	if (n != (ssize_t)hdr->nlmsg_len) {
		if (dofail)
	exit(1);
		return -1;
	}
	n = recv(sock, nlmsg->buf, sizeof(nlmsg->buf), 0);
	if (reply_len)
		*reply_len = 0;
	if (n < 0) {
		if (dofail)
	exit(1);
		return -1;
	}
	if (n < (ssize_t)sizeof(struct nlmsghdr)) {
		errno = EINVAL;
		if (dofail)
	exit(1);
		return -1;
	}
	if (hdr->nlmsg_type == NLMSG_DONE)
		return 0;
	if (reply_len && hdr->nlmsg_type == reply_type) {
		*reply_len = n;
		return 0;
	}
	if (n < (ssize_t)(sizeof(struct nlmsghdr) + sizeof(struct nlmsgerr))) {
		errno = EINVAL;
		if (dofail)
	exit(1);
		return -1;
	}
	if (hdr->nlmsg_type != NLMSG_ERROR) {
		errno = EINVAL;
		if (dofail)
	exit(1);
		return -1;
	}
	errno = -((struct nlmsgerr*)(hdr + 1))->error;
	return -errno;
}

static int netlink_query_family_id(struct nlmsg* nlmsg, int sock, const char* family_name, bool dofail)
{
	struct genlmsghdr genlhdr;
	memset(&genlhdr, 0, sizeof(genlhdr));
	genlhdr.cmd = CTRL_CMD_GETFAMILY;
	netlink_init(nlmsg, GENL_ID_CTRL, 0, &genlhdr, sizeof(genlhdr));
	netlink_attr(nlmsg, CTRL_ATTR_FAMILY_NAME, family_name, strnlen(family_name, GENL_NAMSIZ - 1) + 1);
	int n = 0;
	int err = netlink_send_ext(nlmsg, sock, GENL_ID_CTRL, &n, dofail);
	if (err < 0) {
		return -1;
	}
	uint16_t id = 0;
	struct nlattr* attr = (struct nlattr*)(nlmsg->buf + NLMSG_HDRLEN + NLMSG_ALIGN(sizeof(genlhdr)));
	for (; (char*)attr < nlmsg->buf + n; attr = (struct nlattr*)((char*)attr + NLMSG_ALIGN(attr->nla_len))) {
		if (attr->nla_type == CTRL_ATTR_FAMILY_ID) {
			id = *(uint16_t*)(attr + 1);
			break;
		}
	}
	if (!id) {
		errno = EINVAL;
		return -1;
	}
	recv(sock, nlmsg->buf, sizeof(nlmsg->buf), 0);
	return id;
}

static long syz_genetlink_get_family_id(volatile long name, volatile long sock_arg)
{
	int fd = sock_arg;
	if (fd < 0) {
		fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_GENERIC);
		if (fd == -1) {
			return -1;
		}
	}
	struct nlmsg nlmsg_tmp;
	int ret = netlink_query_family_id(&nlmsg_tmp, fd, (char*)name, false);
	if ((int)sock_arg < 0)
		close(fd);
	if (ret < 0) {
		return -1;
	}
	return ret;
}

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200006c0, "./file0\000", 8);
	syscall(__NR_renameat2, -1, 0x200006c0ul, -1, 0ul, 2ul);
	res = -1;
res = syz_genetlink_get_family_id(0, -1);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200001c0 = 0x20000100;
*(uint16_t*)0x20000100 = 0x10;
*(uint16_t*)0x20000102 = 0;
*(uint32_t*)0x20000104 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x200001c8 = 0xc;
*(uint64_t*)0x200001d0 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000b80;
memcpy((void*)0x20000b80, "\x41\xfc\xb6\xf8\x60\x47\x27\x58\x8f\x7e\xec\x6d\xe6\x9c\xe9\x7e\xb3\x5d\x73\x24\x75\xa9\x62\x0e\xa4\x0c\xc6\xe1\x16\x18\x6a\xd2\x15\x5c\x01\x49\xcb\x8b\xc1\x8c\x20", 41);
*(uint16_t*)0x20000ba9 = r[0];
memcpy((void*)0x20000bab, "\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0e\x00\x00\x00\x20\x00\x01\x80\x08\x00\x03\x00\x00\x00\x00\x00\x14\x00\x02\x00\x77\x67\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 46);
*(uint64_t*)0x20000188 = 0x34;
*(uint64_t*)0x200001d8 = 1;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
	syscall(__NR_sendmsg, r[1], 0x200001c0ul, 0ul);
*(uint64_t*)0x20000800 = 0x20000740;
*(uint16_t*)0x20000740 = 0x10;
*(uint16_t*)0x20000742 = 0;
*(uint32_t*)0x20000744 = 0;
*(uint32_t*)0x20000748 = 0x20000000;
*(uint32_t*)0x20000808 = 0xc;
*(uint64_t*)0x20000810 = 0x200007c0;
*(uint64_t*)0x200007c0 = 0x20000780;
*(uint32_t*)0x20000780 = 0x1c;
*(uint16_t*)0x20000784 = 0;
*(uint16_t*)0x20000786 = 0x20;
*(uint32_t*)0x20000788 = 0x70bd26;
*(uint32_t*)0x2000078c = 0x25dfdbfe;
*(uint8_t*)0x20000790 = 8;
*(uint8_t*)0x20000791 = 0;
*(uint16_t*)0x20000792 = 0;
*(uint16_t*)0x20000794 = 8;
*(uint16_t*)0x20000796 = 0x3c;
*(uint32_t*)0x20000798 = 0;
*(uint64_t*)0x200007c8 = 0x1c;
*(uint64_t*)0x20000818 = 1;
*(uint64_t*)0x20000820 = 0;
*(uint64_t*)0x20000828 = 0;
*(uint32_t*)0x20000830 = 0x44054;
	syscall(__NR_sendmsg, r[1], 0x20000800ul, 0x20ul);
memcpy((void*)0x200008c0, "ip_vti0\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200008d0 = 0x20000840;
memcpy((void*)0x20000840, "ip_vti0\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000850 = 0;
*(uint16_t*)0x20000854 = htobe16(0x40);
*(uint16_t*)0x20000856 = htobe16(0x10);
*(uint32_t*)0x20000858 = htobe32(6);
*(uint32_t*)0x2000085c = htobe32(3);
STORE_BY_BITMASK(uint8_t, , 0x20000860, 0xc, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000860, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000861, 3, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000861, 2, 2, 6);
*(uint16_t*)0x20000862 = htobe16(0x30);
*(uint16_t*)0x20000864 = htobe16(0x68);
*(uint16_t*)0x20000866 = htobe16(0);
*(uint8_t*)0x20000868 = 0;
*(uint8_t*)0x20000869 = 0x29;
*(uint16_t*)0x2000086a = htobe16(0);
*(uint32_t*)0x2000086c = htobe32(0x64010100);
*(uint8_t*)0x20000870 = 0xac;
*(uint8_t*)0x20000871 = 0x1e;
*(uint8_t*)0x20000872 = 0;
*(uint8_t*)0x20000873 = 1;
*(uint8_t*)0x20000874 = 0x44;
*(uint8_t*)0x20000875 = 0x1c;
*(uint8_t*)0x20000876 = 0x59;
STORE_BY_BITMASK(uint8_t, , 0x20000877, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000877, 0, 4, 4);
*(uint8_t*)0x20000878 = 0xac;
*(uint8_t*)0x20000879 = 0x14;
*(uint8_t*)0x2000087a = 0x14;
*(uint8_t*)0x2000087b = 0x2e;
*(uint32_t*)0x2000087c = htobe32(0);
*(uint8_t*)0x20000880 = 0xac;
*(uint8_t*)0x20000881 = 0x14;
*(uint8_t*)0x20000882 = 0x14;
*(uint8_t*)0x20000883 = 0xbb;
*(uint32_t*)0x20000884 = htobe32(0);
*(uint32_t*)0x20000888 = htobe32(0x7f000001);
*(uint32_t*)0x2000088c = htobe32(6);
	struct csum_inet csum_1;
	csum_inet_init(&csum_1);
csum_inet_update(&csum_1, (const uint8_t*)0x20000860, 48);
*(uint16_t*)0x2000086a = csum_inet_digest(&csum_1);
	syscall(__NR_ioctl, -1, 0x89f1, 0x200008c0ul);
memcpy((void*)0x20000140, "gre0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000150 = 0x200000c0;
memcpy((void*)0x200000c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200000d0 = 0;
*(uint16_t*)0x200000d4 = htobe16(0);
*(uint16_t*)0x200000d6 = htobe16(1);
*(uint32_t*)0x200000d8 = htobe32(0);
*(uint32_t*)0x200000dc = htobe32(0);
STORE_BY_BITMASK(uint8_t, , 0x200000e0, 9, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000e0, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x200000e1, 0, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x200000e1, 0, 2, 6);
*(uint16_t*)0x200000e2 = htobe16(0x24);
*(uint16_t*)0x200000e4 = htobe16(0);
*(uint16_t*)0x200000e6 = htobe16(0);
*(uint8_t*)0x200000e8 = 6;
*(uint8_t*)0x200000e9 = 0x29;
*(uint16_t*)0x200000ea = htobe16(0);
*(uint8_t*)0x200000ec = 0xac;
*(uint8_t*)0x200000ed = 0x14;
*(uint8_t*)0x200000ee = 0x14;
*(uint8_t*)0x200000ef = 0xaa;
*(uint32_t*)0x200000f0 = htobe32(-1);
*(uint8_t*)0x200000f4 = 0x83;
*(uint8_t*)0x200000f5 = 9;
memcpy((void*)0x200000f6, "\x00\x7f\x00\x00\x00\x00\x00", 7);
*(uint8_t*)0x200000fd = 0x94;
*(uint8_t*)0x200000fe = 4;
*(uint16_t*)0x200000ff = 1;
*(uint8_t*)0x20000101 = 1;
	struct csum_inet csum_2;
	csum_inet_init(&csum_2);
csum_inet_update(&csum_2, (const uint8_t*)0x200000e0, 36);
*(uint16_t*)0x200000ea = csum_inet_digest(&csum_2);
	res = syscall(__NR_ioctl, -1, 0x89f0, 0x20000140ul);
	if (res != -1)
r[2] = *(uint32_t*)0x200000d0;
*(uint64_t*)0x20000540 = 0x20000480;
*(uint16_t*)0x20000480 = 0x10;
*(uint16_t*)0x20000482 = 0;
*(uint32_t*)0x20000484 = 0;
*(uint32_t*)0x20000488 = 0x20010;
*(uint32_t*)0x20000548 = 0xc;
*(uint64_t*)0x20000550 = 0x20000500;
*(uint64_t*)0x20000500 = 0x200004c0;
*(uint32_t*)0x200004c0 = 0x1c;
*(uint16_t*)0x200004c4 = 0;
*(uint16_t*)0x200004c6 = 0x200;
*(uint32_t*)0x200004c8 = 0x70bd27;
*(uint32_t*)0x200004cc = 0x25dfdbfc;
*(uint8_t*)0x200004d0 = 1;
*(uint8_t*)0x200004d1 = 0;
*(uint16_t*)0x200004d2 = 0;
*(uint16_t*)0x200004d4 = 6;
*(uint16_t*)0x200004d6 = 1;
*(uint16_t*)0x200004d8 = htobe16(0x4e22);
*(uint64_t*)0x20000508 = 0x1c;
*(uint64_t*)0x20000558 = 1;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint32_t*)0x20000570 = 1;
	syscall(__NR_sendmsg, r[1], 0x20000540ul, 0x8008800ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[3] = res;
memcpy((void*)0x20000980, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000990 = 0x20000900;
memcpy((void*)0x20000900, "syztnl2\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000910 = r[2];
*(uint16_t*)0x20000914 = htobe16(0x40);
*(uint16_t*)0x20000916 = htobe16(0x80);
*(uint32_t*)0x20000918 = htobe32(9);
*(uint32_t*)0x2000091c = htobe32(0x3ff);
STORE_BY_BITMASK(uint8_t, , 0x20000920, 0xc, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000920, 4, 4, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000921, 3, 0, 2);
STORE_BY_BITMASK(uint8_t, , 0x20000921, 1, 2, 6);
*(uint16_t*)0x20000922 = htobe16(0x30);
*(uint16_t*)0x20000924 = htobe16(0x65);
*(uint16_t*)0x20000926 = htobe16(0);
*(uint8_t*)0x20000928 = 9;
*(uint8_t*)0x20000929 = 0x2f;
*(uint16_t*)0x2000092a = htobe16(0);
*(uint32_t*)0x2000092c = htobe32(0xe0000001);
*(uint8_t*)0x20000930 = 0xac;
*(uint8_t*)0x20000931 = 0x14;
*(uint8_t*)0x20000932 = 0x14;
*(uint8_t*)0x20000933 = 0xbb;
*(uint8_t*)0x20000934 = 0x83;
*(uint8_t*)0x20000935 = 0xc;
memcpy((void*)0x20000936, "\xec\x61\xf7\xeb\xf8\x4b\xab\x37\x42\x0a", 10);
*(uint8_t*)0x20000940 = 0x44;
*(uint8_t*)0x20000941 = 0xc;
*(uint8_t*)0x20000942 = 0x81;
STORE_BY_BITMASK(uint8_t, , 0x20000943, 3, 0, 4);
STORE_BY_BITMASK(uint8_t, , 0x20000943, 0xc, 4, 4);
*(uint8_t*)0x20000944 = 0xac;
*(uint8_t*)0x20000945 = 0x14;
*(uint8_t*)0x20000946 = 0x14;
*(uint8_t*)0x20000947 = 0xaa;
*(uint32_t*)0x20000948 = htobe32(0x684);
*(uint8_t*)0x2000094c = 1;
	struct csum_inet csum_3;
	csum_inet_init(&csum_3);
csum_inet_update(&csum_3, (const uint8_t*)0x20000920, 48);
*(uint16_t*)0x2000092a = csum_inet_digest(&csum_3);
	syscall(__NR_ioctl, r[3], 0x89f2, 0x20000980ul);
	syscall(__NR_socket, 2ul, 2ul, 0x88);
	return 0;
}