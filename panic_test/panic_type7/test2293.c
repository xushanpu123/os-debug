// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <arpa/inet.h>
#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/genetlink.h>
#include <linux/if_addr.h>
#include <linux/if_link.h>
#include <linux/in6.h>
#include <linux/loop.h>
#include <linux/neighbour.h>
#include <linux/net.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/veth.h>

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

static unsigned long long procid;

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

#define SIZEOF_IO_URING_SQE 64
#define SIZEOF_IO_URING_CQE 16
#define SQ_HEAD_OFFSET 0
#define SQ_TAIL_OFFSET 64
#define SQ_RING_MASK_OFFSET 256
#define SQ_RING_ENTRIES_OFFSET 264
#define SQ_FLAGS_OFFSET 276
#define SQ_DROPPED_OFFSET 272
#define CQ_HEAD_OFFSET 128
#define CQ_TAIL_OFFSET 192
#define CQ_RING_MASK_OFFSET 260
#define CQ_RING_ENTRIES_OFFSET 268
#define CQ_RING_OVERFLOW_OFFSET 284
#define CQ_FLAGS_OFFSET 280
#define CQ_CQES_OFFSET 320

struct io_uring_cqe {
	uint64_t user_data;
	uint32_t res;
	uint32_t flags;
};

static long syz_io_uring_complete(volatile long a0)
{
	char* ring_ptr = (char*)a0;
	uint32_t cq_ring_mask = *(uint32_t*)(ring_ptr + CQ_RING_MASK_OFFSET);
	uint32_t* cq_head_ptr = (uint32_t*)(ring_ptr + CQ_HEAD_OFFSET);
	uint32_t cq_head = *cq_head_ptr & cq_ring_mask;
	uint32_t cq_head_next = *cq_head_ptr + 1;
	char* cqe_src = ring_ptr + CQ_CQES_OFFSET + cq_head * SIZEOF_IO_URING_CQE;
	struct io_uring_cqe cqe;
	memcpy(&cqe, cqe_src, sizeof(cqe));
	__atomic_store_n(cq_head_ptr, cq_head_next, __ATOMIC_RELEASE);
	return (cqe.user_data == 0x12345 || cqe.user_data == 0x23456) ? (long)cqe.res : (long)-1;
}

static long syz_io_uring_submit(volatile long a0, volatile long a1, volatile long a2, volatile long a3)
{
	char* ring_ptr = (char*)a0;
	char* sqes_ptr = (char*)a1;
	char* sqe = (char*)a2;
	uint32_t sqes_index = (uint32_t)a3;
	uint32_t sq_ring_entries = *(uint32_t*)(ring_ptr + SQ_RING_ENTRIES_OFFSET);
	uint32_t cq_ring_entries = *(uint32_t*)(ring_ptr + CQ_RING_ENTRIES_OFFSET);
	uint32_t sq_array_off = (CQ_CQES_OFFSET + cq_ring_entries * SIZEOF_IO_URING_CQE + 63) & ~63;
	if (sq_ring_entries)
		sqes_index %= sq_ring_entries;
	char* sqe_dest = sqes_ptr + sqes_index * SIZEOF_IO_URING_SQE;
	memcpy(sqe_dest, sqe, SIZEOF_IO_URING_SQE);
	uint32_t sq_ring_mask = *(uint32_t*)(ring_ptr + SQ_RING_MASK_OFFSET);
	uint32_t* sq_tail_ptr = (uint32_t*)(ring_ptr + SQ_TAIL_OFFSET);
	uint32_t sq_tail = *sq_tail_ptr & sq_ring_mask;
	uint32_t sq_tail_next = *sq_tail_ptr + 1;
	uint32_t* sq_array = (uint32_t*)(ring_ptr + sq_array_off);
	*(sq_array + sq_tail) = sqes_index;
	__atomic_store_n(sq_tail_ptr, sq_tail_next, __ATOMIC_RELEASE);
	return 0;
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

struct fs_image_segment {
	void* data;
	uintptr_t size;
	uintptr_t offset;
};
static int setup_loop_device(long unsigned size, long unsigned nsegs, struct fs_image_segment* segs, const char* loopname, int* memfd_p, int* loopfd_p)
{
	int err = 0, loopfd = -1;
	int memfd = syscall(__NR_memfd_create, "syzkaller", 0);
	if (memfd == -1) {
		err = errno;
		goto error;
	}
	if (ftruncate(memfd, size)) {
		err = errno;
		goto error_close_memfd;
	}
	for (size_t i = 0; i < nsegs; i++) {
		if (pwrite(memfd, segs[i].data, segs[i].size, segs[i].offset) < 0) {
		}
	}
	loopfd = open(loopname, O_RDWR);
	if (loopfd == -1) {
		err = errno;
		goto error_close_memfd;
	}
	if (ioctl(loopfd, LOOP_SET_FD, memfd)) {
		if (errno != EBUSY) {
			err = errno;
			goto error_close_loop;
		}
		ioctl(loopfd, LOOP_CLR_FD, 0);
		usleep(1000);
		if (ioctl(loopfd, LOOP_SET_FD, memfd)) {
			err = errno;
			goto error_close_loop;
		}
	}
	*memfd_p = memfd;
	*loopfd_p = loopfd;
	return 0;

error_close_loop:
	close(loopfd);
error_close_memfd:
	close(memfd);
error:
	errno = err;
	return -1;
}

static long syz_mount_image(volatile long fsarg, volatile long dir, volatile unsigned long size, volatile unsigned long nsegs, volatile long segments, volatile long flags, volatile long optsarg, volatile long change_dir)
{
	struct fs_image_segment* segs = (struct fs_image_segment*)segments;
	int res = -1, err = 0, loopfd = -1, memfd = -1, need_loop_device = !!segs;
	char* mount_opts = (char*)optsarg;
	char* target = (char*)dir;
	char* fs = (char*)fsarg;
	char* source = NULL;
	char loopname[64];
	if (need_loop_device) {
		memset(loopname, 0, sizeof(loopname));
		snprintf(loopname, sizeof(loopname), "/dev/loop%llu", procid);
		if (setup_loop_device(size, nsegs, segs, loopname, &memfd, &loopfd) == -1)
			return -1;
		source = loopname;
	}
	mkdir(target, 0777);
	char opts[256];
	memset(opts, 0, sizeof(opts));
	if (strlen(mount_opts) > (sizeof(opts) - 32)) {
	}
	strncpy(opts, mount_opts, sizeof(opts) - 32);
	if (strcmp(fs, "iso9660") == 0) {
		flags |= MS_RDONLY;
	} else if (strncmp(fs, "ext", 3) == 0) {
		if (strstr(opts, "errors=panic") || strstr(opts, "errors=remount-ro") == 0)
			strcat(opts, ",errors=continue");
	} else if (strcmp(fs, "xfs") == 0) {
		strcat(opts, ",nouuid");
	}
	res = mount(source, target, fs, flags, opts);
	if (res == -1) {
		err = errno;
		goto error_clear_loop;
	}
	res = open(target, O_RDONLY | O_DIRECTORY);
	if (res == -1) {
		err = errno;
		goto error_clear_loop;
	}
	if (change_dir) {
		res = chdir(target);
		if (res == -1) {
			err = errno;
		}
	}

error_clear_loop:
	if (need_loop_device) {
		ioctl(loopfd, LOOP_CLR_FD, 0);
		close(loopfd);
		close(memfd);
	}
	errno = err;
	return res;
}

uint64_t r[3] = {0x0, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_mmap, 0x20ffe000ul, 0x2000ul, 0xcul, 0x4010ul, -1, 0x8000000ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_socket, 1ul, 4ul, 9);
	if (res != -1)
		r[1] = res;
*(uint8_t*)0x20000000 = 8;
*(uint8_t*)0x20000001 = 5;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = r[1];
*(uint64_t*)0x20000008 = 5;
*(uint64_t*)0x20000010 = 0;
*(uint32_t*)0x20000018 = 7;
*(uint32_t*)0x2000001c = 1;
*(uint64_t*)0x20000020 = 0;
*(uint16_t*)0x20000028 = 0;
*(uint16_t*)0x2000002a = 0;
memset((void*)0x2000002c, 0, 20);
syz_io_uring_submit(r[0], 0, 0x20000000, 0x10000);
	res = syscall(__NR_mmap, 0x20ffe000ul, 0x1000ul, 0x2000000ul, 0x100010ul, -1, 0x10000000ul);
	if (res != -1)
		r[2] = res;
*(uint8_t*)0x20000600 = 9;
*(uint8_t*)0x20000601 = 1;
*(uint16_t*)0x20000602 = 0;
*(uint32_t*)0x20000604 = r[1];
*(uint64_t*)0x20000608 = 0;
*(uint64_t*)0x20000610 = 0x200005c0;
*(uint64_t*)0x200005c0 = 0x20000040;
*(uint16_t*)0x20000040 = 0x23;
*(uint8_t*)0x20000042 = 2;
*(uint8_t*)0x20000043 = 0x70;
*(uint8_t*)0x20000044 = 0xfa;
memset((void*)0x20000045, 0, 11);
*(uint32_t*)0x200005c8 = 0x80;
*(uint64_t*)0x200005d0 = 0x20000440;
*(uint64_t*)0x20000440 = 0;
*(uint64_t*)0x20000448 = 0;
*(uint64_t*)0x20000450 = 0;
*(uint64_t*)0x20000458 = 0;
*(uint64_t*)0x20000460 = 0;
*(uint64_t*)0x20000468 = 0;
*(uint64_t*)0x20000470 = 0;
*(uint64_t*)0x20000478 = 0;
*(uint64_t*)0x20000480 = 0x20000380;
memcpy((void*)0x20000380, "\x73\xb9\x1c\x68\x16\x6d\x4a\xd3\x24\x74\x34\x4f\x4b\xe7\x5c\x29\x17\x24\xd7\x9e\x9a\x35\xdc\xf2\xed\xae\x57\xcf\x23\x7e\x39\x0c\xf4\x11\x0b\xa5\x55\x9b\xa2\x91\x70\x09\x38\x35\x26\x2d\xd1\x37\x80\xb4\xd5\xb0\x40\x33\xe4\xec\x30\x64\x85\xcd\x53\xe4\x98\xe3\xd1\x56\x8f\xe4\x77\x7e\x2c\xdc\x37\x65\xec\x4b\x53\x49\x32\x43\xbb\x47\x4c\xf5\xdc\xfc\x45\xd8\x77\x53\xe4\x4c\xb0\xac\x96\x34\xb4\x69\x6c\x03\xe7\x2b\x30\x90\xa7\xb0\xc3\xc8\xa8\x7e\x6b\x55\xec\x45\xd0\xe1\xbe\xd6\x49\xaf\x14\x0f\x1e\x99\xa6\x74\xaf\xfd\x82\x45\x97\xf0\x9f\x73\x2d\x49\xc5\xde\x7d\x95\xb5\x03\xd1\x25\x8c\xcb\xaf\xf9\x29\x54\x9d\x46\x81\x94\x2c\xa3\xe4\xeb\xf7\x34\xf1", 161);
*(uint64_t*)0x20000488 = 0xa1;
*(uint64_t*)0x200005d8 = 5;
*(uint64_t*)0x200005e0 = 0;
*(uint64_t*)0x200005e8 = 0;
*(uint32_t*)0x200005f0 = 0;
*(uint32_t*)0x20000618 = 0;
*(uint32_t*)0x2000061c = 0;
*(uint64_t*)0x20000620 = 0;
*(uint16_t*)0x20000628 = 0;
*(uint16_t*)0x2000062a = 0;
memset((void*)0x2000062c, 0, 20);
syz_io_uring_submit(r[0], r[2], 0x20000600, 0);
syz_io_uring_complete(0);
syz_genetlink_get_family_id(0, -1);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	syscall(__NR_kcmp, 0, 0, 7ul, -1, 0ul);
	syscall(__NR_getpeername, -1, 0ul, 0ul);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
memcpy((void*)0x20000b80, "iso9660\000", 8);
memcpy((void*)0x20000bc0, "./file0/file0\000", 14);
*(uint8_t*)0x20001fc0 = 0;
syz_mount_image(0x20000b80, 0x20000bc0, 0, 0, 0x20001f00, 0, 0x20001fc0, 0);
	return 0;
}
