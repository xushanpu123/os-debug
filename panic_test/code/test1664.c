// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <arpa/inet.h>
#include <endian.h>
#include <errno.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sched.h>
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

uint64_t r[3] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x200001c0 = 0;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint64_t*)0x200001f0 = 0x1f;
*(uint64_t*)0x200001f8 = 0;
*(uint64_t*)0x20000200 = 4;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0x20000000000000;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0xfff;
*(uint64_t*)0x20000230 = 0;
*(uint64_t*)0x20000238 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x200001c0ul, 0x20000200ul, 0ul, 0ul, 0ul);
	syscall(__NR_socketpair, 0x21ul, 2ul, 0x84020000, 0x20000000ul);
memcpy((void*)0x20000300, "\x49\xb1\x33\x0e\x21\xfe\x3d\x3d\x79\x56\x14\x3a\xdb\x02\x08\xea\x7b\x50\xc5\xc9\x84\x0a\x40\x39\x2c\xd8\x89\x24\xc3\x91\xbb\xd0\x1d\x79\xc1\x27\x91\x70\x88\xbd\xdb\xf7\xfd\xbf\x03\xff\x78\xdb\x0b\xe7\x6b\xeb\x51\xef\xc9\x41\x6a\x50\x3e\xc4\xf3\xe2\x7e\xde\x43\x76\x83\x66\xed\x89\x0c\xd0\xfd\x2d\x2a\xe4\xa5\x81\x4f\xcf\xf2\x6c\xcc\x76\x86\xeb\xdf\x7e\x81\x2c\x96\xf5\xa8\x3a\x7e\xe1\xb6\x1d\xcf\x69\x56\x5c\xa0\x00\xf8\x20\xdc\x6f\x7d\x24\xa5\xbd\xa0\x91\x89\x7f\x8f\xa3\x96\xb2\x2c\x11\xee\x17\x17\x21\xa5\x8d\x79\x62\xf8\x79\xf3\x0d\x17\x34\xb5\x3f\xca\x9f\x62\x7f\x75\xb4", 144);
memcpy((void*)0x20000180, "\x0a\x7b\xfd\xc6\x6a\xa7\xeb\x03\x75\x2d\x57\x46\xa6\x83\x06\xbf\x62\xdd\x27\x92\x13\x3e\xa9\x83\x7f\x82\x60\xd9\x0b\x67\x89\xf9\xcd\x29\x5c\x0f\xa0\x66\x3f\xa7\xdc\x68\x11\x29\x7e", 45);
	res = -1;
res = syz_clone(0x42004000, 0x20000300, 0x90, 0x20000080, 0x20000140, 0x20000180);
	if (res != -1)
		r[0] = res;
	syscall(__NR_sched_rr_get_interval, r[0], 0x200003c0ul);
	res = syscall(__NR_socket, 1ul, 1ul, 0);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000180, "nl80211\000", 8);
syz_genetlink_get_family_id(0x20000180, r[2]);
*(uint64_t*)0x20004a40 = 0;
*(uint32_t*)0x20004a48 = 2;
*(uint32_t*)0x20004a4c = r[2];
*(uint32_t*)0x20004a50 = 0x1f;
*(uint32_t*)0x20004a54 = 0;
	syscall(__NR_ioctl, -1, 0x40182103, 0x20004a40ul);
	syscall(__NR_accept, r[1], 0ul, 0ul);
*(uint64_t*)0x20002900 = 0;
*(uint32_t*)0x20002908 = 0;
*(uint64_t*)0x20002910 = 0x200007c0;
*(uint64_t*)0x200007c0 = 0x20000400;
*(uint64_t*)0x200007c8 = 0xf4;
*(uint64_t*)0x200007d0 = 0x20000500;
*(uint64_t*)0x200007d8 = 0xf5;
*(uint64_t*)0x200007e0 = 0x20000600;
*(uint64_t*)0x200007e8 = 0xaf;
*(uint64_t*)0x200007f0 = 0x200006c0;
*(uint64_t*)0x200007f8 = 0x6b;
*(uint64_t*)0x20000800 = 0x20000740;
*(uint64_t*)0x20000808 = 0x5f;
*(uint64_t*)0x20002918 = 5;
*(uint64_t*)0x20002920 = 0x20000840;
memcpy((void*)0x20000840, "\x20\x00\x00\x01\x00\x00\xfe\x57\x93\x4a\xbc\x6f\xcb\xc7\x00\x00", 16);
*(uint32_t*)0x20000850 = -1;
*(uint32_t*)0x20000854 = -1;
*(uint32_t*)0x20000858 = -1;
*(uint32_t*)0x2000085c = -1;
*(uint64_t*)0x20002928 = 0x20;
*(uint32_t*)0x20002930 = 0;
*(uint32_t*)0x20002938 = 0;
*(uint64_t*)0x20002940 = 0x20000f80;
*(uint32_t*)0x20002948 = 0x6e;
*(uint64_t*)0x20002950 = 0x20000a80;
*(uint64_t*)0x20000a80 = 0x20000900;
*(uint64_t*)0x20000a88 = 0x56;
*(uint64_t*)0x20000a90 = 0x20000980;
*(uint64_t*)0x20000a98 = 0xf1;
*(uint64_t*)0x20002958 = 2;
*(uint64_t*)0x20002960 = 0x20000ac0;
*(uint64_t*)0x20002968 = 0x40;
*(uint32_t*)0x20002970 = 0;
*(uint32_t*)0x20002978 = 0;
*(uint64_t*)0x20002980 = 0x20000b00;
*(uint32_t*)0x20002988 = 0x6e;
*(uint64_t*)0x20002990 = 0x20000d80;
*(uint64_t*)0x20000d80 = 0x20000b80;
*(uint64_t*)0x20000d88 = 7;
*(uint64_t*)0x20000d90 = 0x20000bc0;
*(uint64_t*)0x20000d98 = 0x78;
*(uint64_t*)0x20000da0 = 0x20001200;
*(uint64_t*)0x20000da8 = 0xa1;
*(uint64_t*)0x20000db0 = 0x20000d00;
*(uint64_t*)0x20000db8 = 0x5b;
*(uint64_t*)0x20002998 = 4;
*(uint64_t*)0x200029a0 = 0x20000dc0;
*(uint64_t*)0x200029a8 = 0x10;
*(uint32_t*)0x200029b0 = 0;
*(uint32_t*)0x200029b8 = 0;
*(uint64_t*)0x200029c0 = 0x20000e00;
*(uint32_t*)0x200029c8 = 0x6e;
*(uint64_t*)0x200029d0 = 0x20000f40;
*(uint64_t*)0x20000f40 = 0x20000e80;
*(uint64_t*)0x20000f48 = 0xb4;
*(uint64_t*)0x200029d8 = 1;
*(uint64_t*)0x200029e0 = 0;
*(uint64_t*)0x200029e8 = 0;
*(uint32_t*)0x200029f0 = 0;
*(uint32_t*)0x200029f8 = 0;
*(uint64_t*)0x20002a00 = 0x20001380;
*(uint32_t*)0x20002a08 = 0x6e;
*(uint64_t*)0x20002a10 = 0x20002700;
*(uint64_t*)0x20002700 = 0x20001400;
*(uint64_t*)0x20002708 = 0x8a;
*(uint64_t*)0x20002710 = 0x200014c0;
*(uint64_t*)0x20002718 = 0xea;
*(uint64_t*)0x20002720 = 0x200015c0;
*(uint64_t*)0x20002728 = 0x1000;
*(uint64_t*)0x20002730 = 0x200025c0;
*(uint64_t*)0x20002738 = 0xf9;
*(uint64_t*)0x20002740 = 0x20000880;
*(uint64_t*)0x20002748 = 0x11;
*(uint64_t*)0x20002a18 = 5;
*(uint64_t*)0x20002a20 = 0x20002780;
*(uint64_t*)0x20002a28 = 0x148;
*(uint32_t*)0x20002a30 = 0;
*(uint32_t*)0x20002a38 = 0;
	syscall(__NR_recvmmsg, r[1], 0x20002900ul, 5ul, 0x21ul, 0ul);
	syscall(__NR_socketpair, 0x1ful, 4ul, 0x6578, 0x200008c0ul);
*(uint64_t*)0x20000c40 = 1;
*(uint64_t*)0x20000c48 = 0xffffffff00000000;
*(uint64_t*)0x20000c50 = 1;
*(uint64_t*)0x20000c58 = 0xe8;
*(uint64_t*)0x20000c60 = 0xfffffffffffffffe;
*(uint64_t*)0x20000c68 = 6;
*(uint64_t*)0x20000c70 = 0xfffffffffffff38a;
*(uint64_t*)0x20000c78 = 0;
*(uint64_t*)0x20000c80 = 4;
*(uint64_t*)0x20000c88 = 1;
*(uint64_t*)0x20000c90 = 6;
*(uint64_t*)0x20000c98 = 8;
*(uint64_t*)0x20000ca0 = 4;
*(uint64_t*)0x20000ca8 = 0;
*(uint64_t*)0x20000cb0 = 0;
*(uint64_t*)0x20000cb8 = 0xd90;
*(uint64_t*)0x20000cc0 = 0x40;
*(uint64_t*)0x20000cc8 = 0xffffffffffffff68;
*(uint64_t*)0x20000cd0 = 0x100;
*(uint64_t*)0x20000cd8 = 0x1f;
*(uint64_t*)0x20000ce0 = 2;
*(uint64_t*)0x20000ce8 = 0x80000000;
*(uint64_t*)0x20000cf0 = 0;
*(uint64_t*)0x20000cf8 = 9;
*(uint64_t*)0x200012c0 = 0x77359400;
*(uint64_t*)0x200012c8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000c40ul, 0x20000c80ul, 0x20000cc0ul, 0x200012c0ul, 0ul);
	return 0;
}