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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000300 = -1;
memcpy((void*)0x20000308, "\x69\x89\x7e\x14\x69\x81\xac\xb8\xb4\x40\x5e\xa0\x33\x0f\x66\x5d\xfa\x17\xbf\x98\x2c\x17\x9e\x68\xc3\x19\x42\xc5\xe8\x62\x3e\xad\x1c\x61\xc5\x3d\xe9\x06\xd5\x67\x0c\xf6\x9d\x14\xc5\x30\x54\x30\x76\xcd\xfa\x7c\xb7\xfd\xfe\x2f\xd1\xe8\x41\x7b\xa7\xc0\x79\x65\xb0\x81\x9e\x5a\x1a\x0e\x40\x15\x3c\x0a\xa3\x26\xae\xa0\x4d\x9c\xcb\xde\x32\x69\xc7\xd0\x83\x93\xde\x0c\x08\x56\xb1\x2d\x90\xf8\xc3\x66\x05\x04\xd0\xfe\x51\x5a\x51\x95\x32\xc0\x62\x6e\xa6\xec\x97\x6c\x4a\x53\x37\x34\x91\xdd\x15\x0c\xc5\xcf\x40\x1b\x73\xa9\x6b\xef\xb5\xb2\x0c\x33\x6c\x14\xb6\xd6\x2e\xa4\xc9\x07\x6d\x4d\x42\x7e\xa2\xef\xc3\x72\xd6\x85\x5a\xe3\x18\x00\x14\xcf\x46\xb6\x56\x32\x7d\xb6\x46\xd6\xe4\x2c\x62\x00\x70\xf7\x04\x8b\x91\x5a\xd9\xfa\xe1\xf1\x26\x10\x4e\x27\x19\xae\xd1\xe3\x88\xee\xc0\xc2\x22\xe6\x63\x0e\xb3\xb9\x88\xe6\x1a\xc7\x1c\x3e\x70\x7f\x55\x89\x1a\xad\x6f\x1a\x85\x1a\x2c\xe7\xfc\x49\xbe\xc2\x85\x91\xaa\x33\x2e\x06\x9b\x18\x11\x4e\xe2\x6b\x34\xaf\x64\xaa\x9e\xc7\x51\x79\x5e\x31\x4b\x5c\x2e\xdc\xba\x30\x5f\x06\x7b\xaf\x0a\x01\x69\x3c\x12\x68\x7e\x9f\x7a\x23\x7b\x30\xc8\x7a\xeb\xa6\x67\xa5\x8d\x52\x52\x83\xaf\x8f\x3f\x3f\xf4\x7c\x63\xe7\x83\xff\xf3\xeb\x3c\x19\x87\x0a\x0e\x7f\xae\x97\xd7\x25\x20\xfe\xc0\x96\x64\xdf\x25\x1e\x90\xaa\x26\xfa\xa5\xde\x3f\xb7\x11\x35\x1f\xa8\x5a\x76\x5a\x31\x05\x15\xcd\x6c\xaf\x74\x5f\x14\x76\xad\x48\xf7\x2a\xff\x2d\xaf\x12\x23\x46\xd9\x84\x31\x85\x4e\xaa\xc0\x99\xa8\x0a\xc9\x88\xc1\x74\x4c\xb5\x73\x08\xf0\x88\xd7\x83\xad\xf5\x84\xa4\x26\x8e\x1a\x0e\x3f\x99\xfe\x3e\x41\x8e\xec\x52\x96\x2b\x31\xaa\x64\xff\xab\x47\x41\x57\x10\x6e\x58\x46\xb8\x9e\xd2\xf2\xf3\xc0\x19\xbe\x98\xa2\x8d\x74\x58\x35\x61\xef\x45\x28\x06\x6a\x7a\xa3\xa2\x3c\x9b\x00\xf7\x73\x57\x9a\xf7\x97\xed\x4b\x80\xb6\x8f\x38\xeb\x02\x3f\xb8\xee\x92\xae\xcc\xf2\x81\xe9\xcb\x7e\xcd\xe6\xe0\x6e\xbb\x3a\x03\x63\xc7\x6c\x2d\xce\xbb\xad\x6e\xdc\x6e\xc1\x6e\xbc\x68\xdb\x90\x69\x71\x6e\x7e\x7c\x93\x31\x3f\xe0\x63\x23\xf9\x2c\xc2\xf6\x21\xac\x8e\x68\xfa\x51\xb5\x1f\x3b\x40\x42\x92\x50\xe2\x8a\x8c\xd0\x82\x0c\xbe\xa5\xb3\x3f\x83\xa4\xbe\x1d\xf5\xcd\x8e\x94\x3b\xf2\xff\x1a\x51\x37\xe2\xaa\xd3\xc6\xe0\xd9\x0d\x35\xe0\xb6\x5c\xbf\x26\x2d\xa7\xde\xe7\xd3\x31\xad\x05\xbc\x61\x19\x82\x23\xd0\x47\x7c\xfe\xd6\xfa\x50\x4c\x75\x3e\xbc\x25\x21\x11\x04\x87\x92\x63\x06\x19\x33\x40\x30\x15\x8e\x12\xc4\xe3\x5c\x01\xa9\x48\x3f\x84\xc8\x5f\xbe\xec\xca\xb8\x14\x37\x87\xef\xda\xd0\x9f\x7f\xa0\x53\x07\xd7\x4f\xcf\x54\x09\xab\x07\x29\xac\x8b\x58\xff\x0a\x97\x38\x91\x38\xaf\x5a\x30\xe9\x3a\x8e\x09\x60\xcc\xb7\x71\x27\x82\xd9\x33\xe5\xe1\x8b\xa7\x59\x4b\xf1\xc5\x73\xde\xe6\xe3\xd4\xab\x7c\xd3\x7d\x82\x04\x14\xa8\x9b\xe3\xef\xaa\xf1\x61\xff\x94\x75\x78\x41\xbe\x0f\x0d\x6d\x88\x17\xa1\xe0\x4d\x9a\xb3\x3a\x7f\x6e\x1a\x41\xe8\x8e\x67\x75\x76\x2b\x4f\xcb\x2c\x18\x1b\xf0\x3e\x07\x7a\x33\x61\x3a\x27\x1e\x8a\x76\xf9\x53\xd6\x68\xbc\xc8\xe3\xc6\xa6\xbe\xf2\x63\xac\x1e\x4d\xd2\x7e\xfe\x3f\x2f\x55\x86\x5a\x52\xa6\x4d\xb7\xfe\xa0\xbf\xab\xd0\xba\x33\xac\xae\xdc\xe1\x65\xd3\xca\x46\x1c\x7e\xa1\xeb\x91\x49\x08\x6d\x84\x2c\x2b\x66\x7a\x05\x75\xc4\x9c\x52\xdb\xd0\xd6\x0f\x02\x54\x40\x57\x62\x96\x99\xe1\xbe\x4d\x39\x52\x94\x89\xe0\xa2\x83\x14\xb6\x22\x80\x5f\xe9\x6e\x35\xd4\xf1\x41\x62\x86\x09\xc4\x81\x98\xc3\x61\xfb\xf6\xa3\xd9\x43\x23\x34\xe0\x61\x67\xce\xed\xf8\xca\x44\x2d\xe1\x6f\x0c\x3d\x7e\xb7\x97\x83\xf1\x26\x38\x49\xbe\xfc\x7e\xab\xb2\xbb\x37\xb5\x99\xff\x1e\x2a\x81\x22\x9b\x49\x3e\x76\x6e\x81\x23\x52\x23\xa7\x71\xd0\x24\x8e\x9b\xa6\xfb\x18\x1a\xb2\x36\xf9\xdc\x3a\xdc\x92\x08\xd1\xa7\x51\x72\x4b\x85\xd1\x25\xf2\xcf\x14\x30\xe5\x52\x5c\x1a\xe8\x20\x77\xef\x4f\xad\x4d\x21\x12\x09\x54\xb8\xf3\x8b\xaf\x8d\xe7\xb3\x93\x79\x62\xcc\x79\x4a\xb2\x5c\xd8\xbe\x0c\x02\x64\x55\xa2\xce\x22\x61\x43\xcc\xba\xd0\x03\x98\x04\x68\xbc\x31\x99\x8b\x45\xae\x6d\x83\x6c\x81\xff\xc5\xe9\xd7\x77\x9a\xe1\xe9\x91\x92\x61\x1a\x6d\xbf\xed\xc4\x21\xec\xe8\x73\x37\xe1\xa3\xb2\xb3\x54\x2f\xa7\x69\x2a\xaf\xf6\x0e\x23\xef\xd8\x7a\x8f\x4b\xe2\xf2\x05\x3f\xbc\x31\xa5\x3b\x0a\x9f\x68\xaa\x30\xe9\x93\x54\x31\xa1\x93\xfe\x5d\x26\x57\xe7\x77\x49\xa3\xad\x26\x6d\xc7\x9a\x7a\x08\x61\x3e\x9f\x51\xdf\x91\x30\xb9\x4f\x72\xe8\x27\xce\x67\x02\x7b\xfd\xe8\x1b\x36\x49\x73\xbe\x22\x8f\xb8\xe3\x78\x42\x65\xd6\x52\xd0\x51\xfb\x06\x45\x15\x73\xab\x21\x51\xfa\x96\x90\x3b\x99\xec\xd1\xfd\x40\x1e\x0f\x1d\x34\x77\xa0\xef\x59\x31\x1d\x64\xd1\x33\x43\xb5\x92\xb3\x5c\xf4\x99\x0d\xce\x5b\xed\x3d\x5a\xa4\x65\x2d\xea\x0c\x20\x91\xd5\xa6\x45\x73\x89\x01\x8f\xce\x8d\x3c\x48\x07\x38\xa5\xbd\xc4\xdd\xc1\xa5\x3f\x07\x5b\x6c\x3c\x0f\xb7\x8d\x16\xa7\x8c\x22\x5c\x70\x45\x7a\xc2\xf8\xf4\xbf\x6c\xd9\x92\x97\x9b\xb8\x35\x79\x86\x39\x46\x7c\x32\xd7\xe2\x54\xe8\x97\x54\xb6\x99\xd9\x18\xbe\x1a\xc8\x3b\xc4\xec\x09\x47\x33\x1a\x58\x3f\x86\xee\xb5\xa6\x1a\xf3\xc4\x8e\xf1\xdf\x3e\x2d\x0e\x5d\x82\x06\x4c\x86\x2d\xb5\x61\xbb\xed\x1a\x58\x03\x42\xbf\xde\x68\xa4\xe7\x5d\x84\xa1\x62\x95\x7d\xc2\x8d\x18\x88\x28\x72\x74\x2f\x77\xa4\x78\x22\x23\xcb\x10\x75\x9d\xa9\x27\x53\x2b\x4d\xb5\x2b\xa8\x08\x26\x8b\xe7\x39\x11\x32\x11\x84\xfb\xe8\xd4\x97\xcd\xbe\x5d\x63\xf6\x5e\xc6\x82\xc2\xc1\x46\x4d\xd6\xee\x8e\x13\x9b\x91\xe9\x28\xca\xaa\xe3\x51\x0d\x6b\x93\xe0\xff\x19\x29\xf1\x47\xda\xa7\x47\x09\x95\x49\x49\xcd\x06\xc7\x56\xbd\x7f\x84\x7c\x8a\x03\x18\x0d\x6f\x7c\xae\x5e\x22\x42\x55\xd4\xe9\xb8\x76\x66\x20\xa0\x40\x26\x2b\x7c\x10\xc3\xb5\xa8\x24\x92\xe8\xf2\xaa\x60\x80\x50\x1d\xea\x8e\x3f\x39\x88\xfc\xe1\xde\xba\xee\xef\xab\x4d\x9d\x35\x13\x83\x37\x9c\x7a\x5f\x33\x33\x9e\xee\x3d\xa1\x7b\x52\x87\x19\xa4\xd4\xaa\xda\xf1\x86\x5f\xfb\x62\xac\xb5\x47\xc7\xc9\x59\xf2\x65\x27\x1e\x07\x55\x72\xf8\x52\x4e\xbd\x63\x29\x53\xbe\x7d\xec\x9b\xf8\x26\xc3\xea\x98\xcd\x84\xe3\x7a\x09\xfc\x5a\xbc\x56\xbb\x63\x7d\x6c\xda\xbe\xed\x15\xda\xed\x07\x34\x74\xfc\x1b\x0f\x36\x57\xa3\x92\x34\x50\x70\x9c\xaf\x41\x01\x85\x83\xe8\x87\xf2\xe6\xd6\x90\xf4\x1f\xee\xd4\xd0\x9b\x16\x5f\xd7\x2f\x56\xad\xae\x32\xb0\xa5\xae\xbd\x56\x52\x43\xfc\x62\xe8\x32\x72\xb5\x78\xb8\xba\xa2\x80\x7a\x65\x55\x49\xb4\x08\xc9\x47\x5e\x3e\x7a\xf7\x86\xa5\x15\xc9\x01\x92\x0b\x43\x42\x00\xc4\x4b\xf7\x48\x65\x34\xa1\x6d\x1e\x33\xb8\xb3\x72\x9a\xcd\x8a\x94\xdd\xfd\x45\x9a\x30\x6f\x8b\xcb\x60\xc8\x4c\x01\x94\xa5\x23\x05\x12\x08\xa7\xf1\x26\x17\x03\x4e\x1a\xc2\x56\xf0\x91\xbf\x90\xd8\x14\xdf\xc4\x02\x01\x69\xe1\xbb\x90\xd8\x9c\xf6\x63\xb6\x8c\xf3\x8b\x78\xa9\x68\xf8\xb3\x6b\xa7\xcb\xc1\xc4\xac\x56\xc8\x4d\xf2\x4b\xe2\x0d\xa7\x4e\xe1\xaf\xec\x22\x18\x30\xbb\xcc\xf4\x5a\xe3\x2f\x31\x51\x9c\xda\x4a\x14\xa4\x4e\x8c\x21\x3e\x97\xaf\x54\xc8\x55\x04\x91\x9c\xd2\xba\x65\xd0\x8e\x8b\x98\xdb\x19\xb0\x13\xc5\xce\xa8\x8d\x13\x63\x7a\x56\x81\xa6\x50\xa7\xc3\x0c\xbd\xa9\x6e\x20\xcf\x45\x00\xab\x42\x9b\x57\x3b\x79\xee\x58\x51\x78\x3d\x68\xc1\x69\x84\x7a\x4e\x54\x0d\x28\x34\xe5\xf7\xc1\x2a\xb7\xdc\xa1\x17\xf2\xaa\xeb\xb4\xed\x74\x1f\x35\xb0\xaf\x8f\x50\xa1\x72\xce\x86\x14\x02\xcf\xea\x59\x69\xdb\xbd\xd0\x7c\x41\x70\x02\x71\x56\x86\x75\x0e\x85\x78\x56\x80\x23\x1e\x97\x2c\xc5\xac\x98\xae\x5c\xbc\x9e\xdf\x8a\xc2\xe9\xbe\xea\x3d\xbb\x55\x4a\x78\xaf\xb4\x42\xdc\xaa\x2a\x67\x75\xe4\x92\x4d\x39\x1b\x33\x9b\xcf\xcf\xed\x4e\x45\x7a\x36\x20\xcf\xe0\x1e\xf9\xcb\x62\xda\xab\xc9\x5e\x0b\x3c\x89\x37\x00\x90\x99\x4e\xfa\xac\xa5\x22\x6d\x5a\x8d\x8e\x91\x19\x86\xbc\x3b\x72\xa9\x8e\xf1\x92\x17\xe6\xf6\x02\x62\x50\x92\x3d\x5d\x15\x4a\x67\xcf\x8f\xbb\xeb\xab\x9e\x64\xb8\x85\x0f\x82\x1d\xf0\x9d\x07\x37\x76\x31\xe0\x85\x33\xb3\xfc\x67\x07\xd8\x54\x36\x1a\xde\xa3\xf7\x1d\x23\x5b\x74\xce\x56\xa8\xfe\xbd\x88\xd9\xd1\xed\x33\xb6\xa4\x75\x0d\x3f\x13\xe3\x80\xde\xb3\x7d\x8e\x3b\xa7\xba\x1d\xc0\x64\x37\x6c\x34\x3d\x6e\xf9\x6f\x73\x4b\x02\x42\x34\xc8\x6e\x2e\x82\xe3\xac\x61\xac\xd9\x23\xd4\xe2\xa8\x1f\x78\x69\x82\x4e\x2d\x09\x9d\x67\x93\x64\xf1\x22\xff\x06\xe5\x4f\x12\x7d\x58\xd9\x45\xac\x20\x4c\x82\xc2\x82\xb8\x89\xb1\x0d\xf9\x9c\xd0\x50\xb3\x13\xe5\xfb\x9e\x71\xf8\xb6\x74\x1e\x80\xbd\x0b\x95\x97\x8f\x06\x9d\xf7\x89\xe9\x01\xf7\x57\xd1\x2b\x0e\xc3\x84\x3f\x61\x0b\x27\x8f\x54\x57\x03\xfd\x3e\x85\x98\xc2\x03\xa0\x6c\x64\x1e\x0b\xce\x3d\xd8\xde\x6a\xbb\xa7\x41\x25\xed\x9f\xbd\xfe\xe7\x6c\xc0\xe5\xf2\x9d\x08\xaf\x84\xb7\x10\x01\xa5\xee\x18\xfd\x92\x2f\x4c\xd8\x05\xe6\xbd\x31\x47\x0f\xb9\x14\xda\x20\xb1\xa9\xbd\xf4\x82\xb9\x77\x51\x2f\x05\x38\xc1\x8b\xff\xb3\x4b\x47\x79\x9f\x0d\xc1\x0d\x20\x88\x82\x7f\x24\x8a\xa1\xc5\x10\x42\x2b\x29\xa5\xf1\xf0\xb5\x13\xe8\x21\xdb\x3e\x97\x41\xd5\x3d\x48\x46\x5f\xb2\x7a\x70\xd0\xcb\xc3\x1f\x8a\x32\x3b\x65\x11\xf4\xad\x6d\x8d\xd8\xca\x7c\x2e\x18\xff\xbe\x1b\x47\xa9\x86\xc6\xbe\x40\xaa\x08\x9d\x9f\x2d\x63\x44\xd8\x98\x8a\x42\x8f\x2d\x82\xc9\x43\xcc\x48\x1d\xb7\xcf\x32\xce\xe6\x14\x01\xd8\x9f\xdb\x30\x82\x73\x58\xa1\x93\x4d\xb0\x61\x0e\xe7\x7c\x3b\xba\x4e\xff\xc4\xe9\x01\x33\xdc\xdb\x57\x13\x8c\x71\x2f\xeb\xc5\x68\xf2\x85\x75\x1a\x38\x99\x35\x12\x04\xe1\x2c\xb6\x25\xbc\x09\x0f\x5e\x25\xb5\xcf\x55\xcf\x32\x41\x5e\x5f\x65\x80\x93\x8d\xd0\x39\xa5\xda\xb3\x74\x56\xa6\x68\xdc\xcb\x01\xa2\x50\xee\x30\x10\x43\xc0\x84\xd8\xb3\xb6\x2f\x12\xd4\xeb\x9b\x21\xa2\x6f\xb2\xef\xb9\x8f\x83\xef\xac\x44\xbf\xd6\x4a\x0e\x09\x99\x3b\xf3\xce\xae\x84\xa3\x8e\x2d\x5b\xce\xc0\x49\xdb\x85\xed\x51\xce\xe8\x1a\x7a\xc2\xf7\x20\x30\x7e\x3e\x17\xfb\x66\xa8\xd5\x45\x60\x41\xf2\x16\xd7\xb9\x9c\x07\xc2\xd0\xa5\xf5\x9f\xaa\x21\xf7\xc4\xb9\xd4\x31\x50\x7c\xc0\x69\xa4\x2b\xc2\x24\x77\x44\x09\x84\x89\x62\xab\x98\xe0\xf5\x92\x08\x40\x24\x4d\xb8\xcf\x26\x82\xd0\x92\x98\xdf\x02\xa3\x43\x22\xce\x8a\xbd\xdb\xd9\x86\x61\x90\xd0\x40\xd5\xd2\xe0\xc5\x7c\x52\x96\x1f\xb6\xf8\xfb\xa2\x8f\x25\x9b\x37\x40\xa8\xb2\xd7\x6c\x57\x98\xad\xc3\x7c\x5b\xdc\x1d\x45\xb3\x4e\xe7\xdf\xdc\x15\x12\x0c\x61\x71\x88\x9e\xb5\x44\x27\xd7\x2e\xf3\xde\x26\x93\x37\xe7\xb1\x9a\xdc\x56\xd2\x5e\x61\xa3\x74\x0b\xa5\x77\x75\x05\x94\xef\x86\xd2\x32\xe4\xc4\xea\xdf\xf0\x63\xfb\xc8\xde\x76\x37\x26\x66\xed\x63\x7d\x6f\x10\xb5\xfa\xcb\xf4\x1b\xc3\xe8\x61\xcb\x4a\x9c\xa5\x81\xdc\x22\x11\xed\x6b\x2d\xe3\x85\x23\xd3\x49\x18\x7e\xdd\xb4\xce\xb4\x8c\xde\xa9\x04\x2e\x92\x15\x09\xf6\xa0\xcc\xe4\x1c\x26\xb9\x66\xf2\xe4\xe1\x0f\x96\xe8\xc2\x07\x88\x5a\x64\x4e\xb2\xb9\xf4\x4b\xfe\xb9\x71\x46\x9c\x5a\xc9\xa3\x86\x1c\x13\x9c\x93\xb3\x58\xd2\x55\x64\x38\x40\xcc\x5c\x37\xa2\xd8\x5a\x61\x12\x75\xc6\x8d\x33\x40\x1d\xd3\xc6\x33\x5f\x32\xfd\xef\x35\x9c\x3c\x44\xb0\xaa\xe1\x8c\x37\xb3\xcb\xb7\x5c\xe9\x2a\x5c\xe0\x63\x0f\x8d\x2e\xbb\x88\x80\xdc\x3b\x8c\x2f\xb1\xbe\xef\x4e\xa3\xd6\x29\xa7\x4e\xeb\x77\x67\xb0\x01\x85\x83\x6c\x99\xd9\xe1\x65\xa8\xd6\x66\x8d\x55\x0c\xe1\x91\xb2\xd7\xdb\xf4\xbf\xa8\x71\x03\x9b\xa9\xe4\x69\x0f\x6d\x48\xbc\xc2\x45\x46\x46\x83\x6e\x48\x84\x56\x97\xd5\x7e\xf8\x84\x38\xb4\x8a\x2a\xee\x68\x2b\x82\xf5\x71\xef\xc2\x91\x80\x32\xb9\x5e\x6d\x3a\x4f\x5f\xd7\xbc\x05\x7d\xed\x17\x9e\xa1\x12\xc0\xac\xb8\x01\x3e\xc2\x06\x34\xf7\xb7\x75\x5e\x4b\x1d\xd8\xad\xc2\xdd\x07\x7f\x77\x4f\x52\x58\x87\xf4\xc6\x52\xb4\x9d\xd5\xc5\xc3\x1a\x78\x44\x77\x65\x4f\xc1\x2e\xbe\xe8\x68\xa9\x73\x8c\x77\xe2\x10\xeb\xfd\xe8\x80\x77\xfa\x0c\x1a\x81\x03\xa8\x75\xd1\x62\x64\xc1\x86\x2a\xae\x8d\x99\x91\x28\x5d\xbc\x5e\x8c\xa7\xab\x5f\x7e\x11\x80\xd4\xfb\x60\xd3\x61\x60\xfc\x1e\xf7\x79\x6b\xbf\x4c\xa8\x2d\xbf\x93\x78\x2f\xc0\xf8\xf7\xa9\x83\xc3\x15\xb3\x4d\x77\xa3\xf5\x7e\xdb\x94\xc8\x5a\x29\xcb\xf9\x8f\x4b\x85\x05\x21\x09\xcd\x90\x6b\x8a\x77\x3c\x21\xf9\x13\x5d\x5f\xe1\x69\xbf\x38\x2b\x95\xe3\x02\x73\x5f\x32\x25\x98\xdf\xc6\x8a\xbf\x6f\x41\x17\xf7\x24\x01\x88\xf4\x14\x7f\xcd\x59\xac\xd7\x5b\x6c\x23\x24\x93\x65\xe1\x72\xb7\x92\xb0\x27\x28\x50\x54\x2e\xa1\x3d\x5d\x65\xac\x97\xfb\x30\x37\x3e\xfa\x10\x8f\x1d\xa7\x8c\xa7\x8f\xea\x4b\x65\x93\xe8\x24\xcd\x2b\x6c\x38\xc4\x2c\xc2\xa8\xc2\xeb\xc5\x93\xca\x15\xe8\x4d\x84\x43\x22\x6b\x1b\x8b\xa7\xc4\x60\x5e\x5b\x10\x34\xdd\x41\xc8\x2a\x2d\x53\x35\x4b\xe5\x2c\xe4\x56\x26\xc2\x6c\x82\xfa\x25\x5e\x7b\x82\xe4\x7f\x59\xe3\x61\x1e\xb0\x16\xce\x0d\x31\xaa\x53\xe4\xf9\x71\xd1\x64\x45\xd6\xc7\x90\x96\x78\x01\x8f\x3f\xa7\x38\x7f\xb8\xe0\x05\xd8\xdf\x22\x98\x5d\xc6\xa7\x18\x31\xef\x6c\xe5\x7a\x13\x73\xe7\x06\x8b\xeb\xf9\x6e\x66\x9a\x40\x15\xcb\x25\x24\xa5\x8d\x46\xd9\x06\xc5\x2a\x49\xf3\xf9\x5e\x19\xbb\x81\x33\xd3\xec\x60\x3c\x6f\xd6\x64\xc8\x84\x06\x84\x4f\x95\x74\x58\x45\x3b\xd5\xe4\xde\x36\x9f\xd5\xde\x06\xd7\x72\x23\x8c\x69\xf1\x92\x7f\x8d\xf2\xa9\x73\x69\x92\xbb\xc1\xd6\x20\xbb\xea\x7b\xa0\xb1\xf5\x12\x05\x34\xd5\x60\xbd\x75\xed\xb3\x5a\x5b\x96\x21\xab\xa3\xe6\xf0\xa1\x58\xf6\xa4\x1f\xa6\x1c\xe7\xa7\x77\x5f\x47\x74\x06\xdf\x22\xc1\xab\x78\x8d\xc4\x3b\xa2\xd6\x66\x57\xa3\x8b\x68\xd1\x5e\x16\xe6\x6a\x04\xab\x68\x8f\x61\x35\x32\xbf\xba\xd6\xde\x88\xb1\xe0\x2b\x29\xd9\x4d\x81\xf2\xf4\xda\x4b\xb5\xda\xf0\x19\x04\x69\x50\x94\x6f\x7e\xc7\x6d\xc6\xbf\x7f\xe6\x09\xa2\x60\x11\xf3\xc7\x29\x42\xa0\xf1\x9f\x97\xf7\x2a\xb1\xde\x5f\x28\x0a\x43\x75\xf6\x74\x85\x38\x0f\xda\xc7\x05\xb6\x03\xa5\xc4\x6e\xe9\x3e\xf0\x65\xc1\xa4\x66\xb9\x82\xe6\x0a\xd5\x7b\x87\x2d\x4f\x6a\xbb\x6e\x72\x8d\x0e\x7d\x07\x68\xeb\xf2\xbc\x42\x84\x58\xed\x34\x9b\x86\xb6\x35\x76\xac\x48\xac\x58\x04\x7f\x38\x93\x31\x21\xe6\xf8\x4f\x14\x81\x3b\x7a\x26\x4c\x1f\x63\x90\xe1\xe1\x1c\x3e\xed\xaf\xe7\xf0\x1d\x2e\x9d\x9d\xd5\x6e\xb6\x6d\xee\xe0\x56\x5d\xd2\x96\xfd\xde\x83\x12\xc8\x96\x38\xde\x81\x2f\xc7\xe0\x11\xfc\xbb\xcd\x41\xdf\x8c\xed\x9e\xff\x76\x0a\x5c\x80\xfa\x64\xcf\x6c\x6e\x21\x1b\x22\x43\x54\x5b\x2e\x88\xf8\x5d\xd2\xcd\x2a\x26\xc0\x61\x2e\xb5\xad\xf7\xd2\x69\x0f\xc3\x2a\xc1\x79\xa9\x3f\xc9\x2e\x76\xf3\x82\xc2\xe0\x0f\xee\xb4\x4c\x5b\xc9\x90\x6f\xb7\x03\xd0\x68\x83\x0f\x65\x6d\x1b\x50\xe6\x90\x35\x47\x04\xd8\x45\x33\x1e\x0a\xa6\xf3\x18\x60\xf7\xbd\x0c\x4b\xef\x24\x37\xc0\xce\xe0\xc3\x63\xd8\x10\xff\x1d\xaa\x5e\x99\xc5\xa3\x60\x39\xe4\xf8\x47\x73\x08\x4d\x81\x7d\x30\xbb\xc0\xf2\x34\x76\x4d\xeb\x84\x26\xd0\xbb\xfb\xf9\xe7\x94\xd5\xdb\x0b\xac\xa0\xc0\x80\x23\x1f\x61\x50\xc9\xdb\x8c\xa7\xd6\xca\x9d\xa1\xd3\x17\x38\x77\xbd\xb5\x71\x4d\xa1\x40\x02\x68\x76\x7f\x69\x99\xb8\xdc\x34\x74\xdd\x11\x70\xc8\xe9\x01\x4f\x20\x62\x1d\x54\x55\x8d\xe1\xd3\x3b\x38\x76\xb9\xe4\x93\xfb\x01\xb6\x9e\xa9\xcb\x09\x8d\x97\x85\x93\x7e\x64\xd2\x6e\xa4\x52\xc8\x83\xaa\x83\x60\xe2\xe4\x0d\xd9\x1b\xad\x41\x24\x59\xc4\xec\xfb\xe0\x9d\x99\xc4\x5e\xe6\x42\xd7\xc6\x27\xf1\x40\x3d\x2d\x73\xcb\xf0\xb0\x1b\x4a\x81\xd3\xe9\xbb\x9b\x9a\xc4\x14\xa2\xc3\xdf\xcc\xbb\x5b\x5a\x05\xf7\x47\xef\x1c\x3f\xa0\xdf\xdd\xae\x1e\x2e\x65\x21\x26\xd9\xfd\xbf\x02\x44\x4c\xd2\xec\x16\x72\x66\x5f\xac\x16\x59\x9b\xdb\x24\x5a\x34\x0e\xaa\x91\xba\x98\x74\x42\x57\xb0\xcd\x13\x2f\xc0\x6b\xb9\x6f\x9a\xae\x23\x2f\xe0\x44\x7f\xde\xfa\x9b\x18\x28\x50\x26\xe9\xf4\x79\x77\xa4\xbd\x89\xcd\xd1\xbe\x52\x9b\x57\xfc\xc5\xa9\x8a\x26\x4b\x58\xba\x4e\x88\x27\xdb\xa7\x77\x50\xe2\xc8\xfc\x3f\x2d\x5c\xe2\x29\xf5\xfc\xa9\xe4\x5a\x49\xb4\xf6\x57\x9d\xf1\xc7\x1e\xc7\x2c\x80\x64\x36\x59\x9f\xe2\xc2\x14\xb9\x42\x94\x83\x65\x91\x20\xaf\xaa\x64\x01\x46\xdf\xbc\xf2\x66\x9e\xdf\xd7\x36\x2d\xd1\xaf\xcb\x47\xdd\x67\xca\x96\xc0\x97\x3e\xe1\x6c\xc9\x97\x76\x15\x2f\x97\x52\xdb\x4d\x24\x0c\x15\xd9\x09\x11\x60\x7f\x5c\xe9\x6e\x44\x20\x6c\x95\xa9\x0f\xd1\x2b\x9e\xc7\x8a\x01\x00\x8d\x47\x2e\xa2\x0f\xd3\xc7\x15\x84\x2b\x93\xd5\xac\x00\x6b\x07\x32\x19\x4a\xd1\xfa\x5d\x45\x13\x64\x6d\x75\xcf\xb6\x45\x90\xad\xec\x24\x51\x82\x7b\x04\x04\xcc\x8b\xa0\x4d\x63\x08\x61\xf2\x55\x22\xd2\xd4\x38\xae\x47\x8d\xc9\xcc\xb5\xae\x26\x6c\x63\x30\xb2\x54\x81\x04\x04\xba\xf3\x91\x16\x22\xf1\x63\x0c\x7e\x4d\x3e\x48\x6a\xd7\x0d\x60\x33\xe1\xd9\x82\x24\x38\xca\xe3\xba\xb4\x1b\x56\x9c\x85\x46\x6b\x5b\x48\xcb\x0a\x80\x48\x94\x4c\x57\xfc\x2a\xda\xd7\x56\x4b\xa7\x53\x71\x3b\x72\x9c\xb5\xb3\x2f\x07\x98\xbe\x30\x5e\x5e\x09\x8f\xde\x50\x1b\x11\x10\x36\xa1\x51\x74\xf7\x7a\x9b\x3b\x18\xbc\x22\xd2\xfb\xa6\x6b\x9d\x9b\xca\x8c\x8c\x93\x7a\xe4\xea\x64\xa8\x00\x31\xa7\xd9\xb4\xb2\x58\x94\x4a\xc9\x93\x73\x26\x1d\x58\x6d\xb5\x54\x3f\xfc\xc3\x26\xd0\xa5\xbc\x77\x6a\xa3\x4f\x6f\x5a\xd7\xe1\xf2\xed\xfa\x0e\x75\x23\xce\x58\xb5\x96\x7b\x22\xa4\x72\x1a\xde\x7c\x79\x3a\xd3\xb9\x49\xb0\x24\x76\x76\x04\x4c\xf2\x87\x14\x62\xe5\x13\x4b\xb5\xad\xfe\xb5\xcb\x3e\x31\xfa\xcc\xc0\x54\x83\x60\x1e\xbc\x8a\x9c\x1b\x04\xcf\x79\xb1\x19\x11\x7e\x29\xbb\x83\x33\xe8\x81\xa5\x79\xa2\x56\x44\x34\xec\x48\x08\x31\xbc\x4d\x3a\x62\x19\x5d\xbf\x4b\x3c\x54\xe7\x8e\xcf\x93\x95\x40\xe2\x3d\xc5\xea\x91\x7b\x81\x65\x74\xb5\x37\x50\x5b\x5d\x1b\x5a\x4a\x8e\xf7\x69\xbb\xf2\xc1\xb9\x3e\xd8\x41\x8d\x65\x70\xd8\x71\xbf\xbb\x8a\xb0\x6c\x23\x25\x9e\x3a\x95\x9e\xb0\x76\x8c\xc6\x4e\x07\xa9\x0f\xe6\xd7\xf5\x2b\x07\xcf\x07\x84\x5f\x0e\x35\xec\xe8\x14\x73\x65\xa4\xe6\xc6\x5f\x3d\x54\x93\xdc\x1d\xac\x3d\x5f\x9f\xb6\x7f\x69\x53\x45\x76\xf5\x0d\x2f\xd9\x0d\x80\x48\x38\x99\xc4\x9f\x36\x3c\x8d\x7e\x1a\x98\x2c\xb2", 4088);
	syscall(__NR_ioctl, -1, 0x50009401, 0x20000300ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "nl80211\000", 8);
	res = -1;
res = syz_genetlink_get_family_id(0x20000040, -1);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200003c0 = 0;
*(uint32_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0x20000380;
*(uint64_t*)0x20000380 = 0x200005c0;
memcpy((void*)0x200005c0, "d\000\000\000", 4);
*(uint16_t*)0x200005c4 = r[1];
*(uint64_t*)0x20000388 = 0x64;
*(uint64_t*)0x200003d8 = 1;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0;
*(uint32_t*)0x200003f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200003c0ul, 0ul);
	return 0;
}
