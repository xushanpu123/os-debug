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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "/dev/vcsu\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_setsockopt, r[1], 0, 0xd3, 0ul, 0ul);
memcpy((void*)0x20000080, "devlink\000", 8);
	res = -1;
res = syz_genetlink_get_family_id(0x20000080, -1);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000180 = 0x20000040;
*(uint16_t*)0x20000040 = 0x10;
*(uint16_t*)0x20000042 = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0x80000;
*(uint32_t*)0x20000188 = 0xc;
*(uint64_t*)0x20000190 = 0x20000140;
*(uint64_t*)0x20000140 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x50;
*(uint16_t*)0x200000c4 = r[2];
*(uint16_t*)0x200000c6 = 0x200;
*(uint32_t*)0x200000c8 = 0x70bd2c;
*(uint32_t*)0x200000cc = 0x25dfdbff;
*(uint8_t*)0x200000d0 = 1;
*(uint8_t*)0x200000d1 = 0;
*(uint16_t*)0x200000d2 = 0;
*(uint16_t*)0x200000d4 = 8;
*(uint16_t*)0x200000d6 = 1;
memcpy((void*)0x200000d8, "pci\000", 4);
*(uint16_t*)0x200000dc = 0x11;
*(uint16_t*)0x200000de = 2;
memcpy((void*)0x200000e0, "0000:00:10.0\000", 13);
*(uint16_t*)0x200000f0 = 0xe;
*(uint16_t*)0x200000f2 = 1;
memcpy((void*)0x200000f4, "netdevsim\000", 10);
*(uint16_t*)0x20000100 = 0xf;
*(uint16_t*)0x20000102 = 2;
memcpy((void*)0x20000104, "netdevsim", 9);
*(uint8_t*)0x2000010d = 0x30;
*(uint8_t*)0x2000010e = 0;
*(uint64_t*)0x20000148 = 0x50;
*(uint64_t*)0x20000198 = 1;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint32_t*)0x200001b0 = 0x448c5;
	syscall(__NR_sendmsg, r[1], 0x20000180ul, 0x20000040ul);
memcpy((void*)0x20000000, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\001", 16);
*(uint32_t*)0x20000010 = 0x400;
*(uint8_t*)0x20000014 = 0;
*(uint8_t*)0x20000015 = 2;
*(uint16_t*)0x20000016 = 9;
*(uint16_t*)0x20000018 = 0;
*(uint16_t*)0x2000001a = 0x3391;
*(uint32_t*)0x2000001c = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x20, 0x20000000ul, 0x20ul);
	return 0;
}
