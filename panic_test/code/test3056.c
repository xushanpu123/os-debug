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

uint64_t r[5] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000100 = 0;
*(uint16_t*)0x20000108 = 2;
*(uint16_t*)0x2000010a = 0;
*(uint32_t*)0x2000010c = htobe32(0);
*(uint32_t*)0x20000110 = 0;
*(uint32_t*)0x20000114 = 0;
*(uint16_t*)0x20000118 = 2;
*(uint16_t*)0x2000011a = 0;
*(uint32_t*)0x2000011c = htobe32(0x7f000001);
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = 0;
*(uint16_t*)0x20000128 = 0;
*(uint16_t*)0x2000012a = 0;
*(uint32_t*)0x2000012c = 0;
*(uint32_t*)0x20000130 = 0;
*(uint16_t*)0x20000138 = 0;
*(uint16_t*)0x2000013a = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint16_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint16_t*)0x20000170 = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000100ul);
memcpy((void*)0x20000000, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x80100ul, 0ul);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_socketpair, 0x28ul, 5ul, 1, 0x200001c0ul);
	if (res != -1)
r[2] = *(uint32_t*)0x200001c0;
memcpy((void*)0x20000240, "fou\000", 4);
	res = -1;
res = syz_genetlink_get_family_id(0x20000240, r[1]);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x20000340 = 0x20000200;
*(uint16_t*)0x20000200 = 0x10;
*(uint16_t*)0x20000202 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0x20;
*(uint32_t*)0x20000348 = 0xc;
*(uint64_t*)0x20000350 = 0x20000300;
*(uint64_t*)0x20000300 = 0x200004c0;
memcpy((void*)0x200004c0, "\xc2\x26\x00\xc5\x80\x8c\x34\x55\x17", 9);
*(uint16_t*)0x200004c9 = r[3];
memcpy((void*)0x200004cb, "\x20\x00\x00\x00\x00\x00\xfe\xdb\xdf\x25\x01\x00\x00\x00\x08\x00\x06\x00\xac\x14\x14\xbb\x14\x00\x09\x00\xfc\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x04\x00\x05\x00\x05\x00\x03\x00\x67\x00\x00\x00\x14\x00\x09\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x08\x00\xac\x14\x14\x0a\x06\x00\x0a\x00\x4e\x21\x00\x00\x53\xce\x35\x12\x68\xdc\xd4\xe2\xe0\x72\x10\xc7\x0d\x1b\xde\x97\xca\x95\x78\xe1\x4c\xb7\x3b\x48\x9a\xee\xba\x1d\x3d\x80\xac\xb1\xd4\x26\x8c\x32\x7f\xcf\xc6\x11\x28\x9e\xb9\x59\x53\x36\xa1\x1f\x75\xaf\x43\xa4\x67\x19\x08\x2a\x79\x88\xb8\x12\x48\xe7\x80\x8f\x1f\x25\x92\x87\x97\xc2\x5c\xce\x84\xd5\x1a\x4a\xbb\x51\xe6\xce\x4a\xe1\xd7\x4c\xa3\xfc\xf9\x60\xa6\x1e\xc4\x93\x11\x39\xae\x4b\x25\x47\x7b\x08\x59\x8d\x83\x7e\xdc\x77\x8e\xf7\x82\x18\x21\x79\xab\x50\x7c\xcf\x98\x37\x03\x8a\xc7\xae\xa7\x16\x96\x93\xd7\x3c\xf4\xcb\x62\x7f\xbf\xf5\xf1\xb0\xab\x28\xbf\xa6\xae\xec\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x34\xcd\xb7\x75\x61\x72\xf5\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 269);
*(uint64_t*)0x20000308 = 0x60;
*(uint64_t*)0x20000358 = 1;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0x4000000;
	syscall(__NR_sendmsg, r[2], 0x20000340ul, 0x811ul);
*(uint64_t*)0x20000040 = 0;
*(uint16_t*)0x20000048 = 0x27;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000054 = 4;
*(uint16_t*)0x20000058 = 0x10;
*(uint16_t*)0x2000005a = 0;
*(uint32_t*)0x2000005c = 0x25dfdbfc;
*(uint32_t*)0x20000060 = 0x10;
*(uint16_t*)0x20000068 = 0x27;
memcpy((void*)0x2000006a, "\xf0\x0e\x15\x4a\xb0\x62\x77\x05\x74\x28\xdb\xbc\x42\x99", 14);
*(uint16_t*)0x20000078 = 0x8000;
*(uint16_t*)0x2000007a = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint16_t*)0x20000090 = 6;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0x1000;
*(uint64_t*)0x200000a8 = 8;
*(uint16_t*)0x200000b0 = 2;
	syscall(__NR_ioctl, r[1], 0x890b, 0x20000040ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[4] = res;
*(uint32_t*)0x20000180 = 0x28;
*(uint64_t*)0x20000188 = 0x200000c0;
memcpy((void*)0x200000c0, "geneve1\000\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x200000d0 = 7;
	syscall(__NR_ioctl, r[4], 0x8912, 0x20000180ul);
	return 0;
}