// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/loop.h>

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

static unsigned long long procid;

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

static long syz_read_part_table(volatile unsigned long size, volatile unsigned long nsegs, volatile long segments)
{
	struct fs_image_segment* segs = (struct fs_image_segment*)segments;
	int err = 0, res = -1, loopfd = -1, memfd = -1;
	char loopname[64];
	snprintf(loopname, sizeof(loopname), "/dev/loop%llu", procid);
	if (setup_loop_device(size, nsegs, segs, loopname, &memfd, &loopfd) == -1)
		return -1;
	struct loop_info64 info;
	if (ioctl(loopfd, LOOP_GET_STATUS64, &info)) {
		err = errno;
		goto error_clear_loop;
	}
	info.lo_flags |= LO_FLAGS_PARTSCAN;
	if (ioctl(loopfd, LOOP_SET_STATUS64, &info)) {
		err = errno;
		goto error_clear_loop;
	}
	res = 0;
	for (unsigned long i = 1, j = 0; i < 8; i++) {
		snprintf(loopname, sizeof(loopname), "/dev/loop%llup%d", procid, (int)i);
		struct stat statbuf;
		if (stat(loopname, &statbuf) == 0) {
			char linkname[64];
			snprintf(linkname, sizeof(linkname), "./file%d", (int)j++);
			if (symlink(loopname, linkname)) {
			}
		}
	}
error_clear_loop:
	ioctl(loopfd, LOOP_CLR_FD, 0);
	close(loopfd);
	close(memfd);
	errno = err;
	return res;
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000b00 = 0;
*(uint32_t*)0x20000b08 = 0;
*(uint64_t*)0x20000b10 = 0x200009c0;
*(uint64_t*)0x200009c0 = 0;
*(uint64_t*)0x200009c8 = 0;
*(uint64_t*)0x200009d0 = 0x20000500;
memset((void*)0x20000500, 161, 1);
*(uint64_t*)0x200009d8 = 1;
*(uint64_t*)0x200009e0 = 0x20000200;
memcpy((void*)0x20000200, "\x05\xef\x46\xb5\xdb\xc0\x40\x34\xd2\x68\x55\x91\xf2\xf5\xe4\x4f\x69\x19\x93\x3f\x27\x68\x65\xa1\x1d\x55\x5d\xe0\x45\xc2\x04\x53\xa1\x73\xec\xbc\x04\xec\xcc\xfe\x3c\x58\x31\x07\x76\xe5\x0d\x15\x96\xbc\x63\x8c\x0c\xb0\xe5\x57\xc4\x4c\x12\x51\xa1\xa3\x99\x16\xd2\xa1\x89\x45\xba\x0f\xf0\x9b\x8a\x04\x74\x5f", 76);
*(uint64_t*)0x200009e8 = 0x4c;
*(uint64_t*)0x20000b18 = 3;
*(uint64_t*)0x20000b20 = 0x20000280;
*(uint64_t*)0x20000280 = 0x14;
*(uint32_t*)0x20000288 = 1;
*(uint32_t*)0x2000028c = 0x24;
*(uint32_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0x14;
*(uint32_t*)0x200002a0 = 1;
*(uint32_t*)0x200002a4 = 0x24;
*(uint32_t*)0x200002a8 = 0;
*(uint64_t*)0x200002b0 = 0x18;
*(uint32_t*)0x200002b8 = 1;
*(uint32_t*)0x200002bc = 0x3d;
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x200002c8 = 0x18;
*(uint32_t*)0x200002d0 = 1;
*(uint32_t*)0x200002d4 = 0x3d;
*(uint64_t*)0x200002d8 = 0;
*(uint64_t*)0x200002e0 = 0x14;
*(uint32_t*)0x200002e8 = 1;
*(uint32_t*)0x200002ec = 0x24;
*(uint32_t*)0x200002f0 = 0;
*(uint64_t*)0x200002f8 = 0x14;
*(uint32_t*)0x20000300 = 1;
*(uint32_t*)0x20000304 = 0x24;
*(uint32_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0xffffffffffffffec;
*(uint32_t*)0x20000318 = 1;
*(uint32_t*)0x2000031c = 0x25;
*(uint32_t*)0x20000320 = 0;
*(uint64_t*)0x20000328 = 0x18;
*(uint32_t*)0x20000330 = 1;
*(uint32_t*)0x20000334 = 0x3d;
*(uint64_t*)0x20000338 = 0;
*(uint64_t*)0x20000b28 = 0xc0;
*(uint32_t*)0x20000b30 = 0;
	syscall(__NR_sendmsg, -1, 0x20000b00ul, 0ul);
*(uint64_t*)0x20000040 = 0x20000080;
memcpy((void*)0x20000080, "\x84\x2b\x51\xb3\x95\xe3\x82\xff\x58\x18\x35\x1b\xc0\x77\x6f\x1c\x23\x5a\x42\x90\x95\xc3\xd2\x31\xa1\x5a\xcf\x52\x76\xa8\xa8\x9c\xaf\xe2\xde\x37\x3c\xff\x8e\xd1\x50\x58\xee\xde\xd9\x27\xaa\x02\x0a\x4a\x68\xbb\xda\xf6\xbb\x76\xd9\x55\x43\xd1\x95\x4e\x7d\x7f\x72\x36\xfa\x8e\xa4\x49\xe3\xf7\xf1\xb4\x68\xd6\x85\xd3\x48\xbe\x9d\x85\x8c\x18\xac\x68\x97\x44\xbc\x91\xcc\x9a\xa6\xc8\x55\xef\xdc\x96\xdb\x54\x3e\x5b\x08\x0e\xc3\x75\x2f\x5f\x33\x91\xc1\x2c\xbf\x3f\x46\xc8\x27\x18\x1a\xfe\x94\x63\x43\x1c\x6e\xcc\x8c\x4a\xef\xc9\x2b\xa3\x6c\x62\x6f\xd8\xc5\x09\xa9\x80\xcc\x57\xa5\x00\x8f\x53\xea\x1c\xf7\x65\x52\x5e\xb7\xff\x78\x44\xdc\xce\x63\x01\x44\x7f\x0f\x46\x63\xf2\xe2\x00\x9d\xc0\xaf\x01\xf5\xb4\xfc\x9a\xb0\x99\xdc\xe4\x09\x59\x94\xa6\x46\x9b\xeb\xe3\xf1\x7d\xbc\x6e\xbd\xea\x88\x9f\x85\x71\xf0\x6d\xf4\xb8\xbb\xfe\x8e\xf3\x13\xbc\x5f\xeb\xa9\xd8\xdb\x90\x93\x58\x06\xb2\x9a\x1c\x65\xff\xb6\x0b\x2f\xfc\x12\x9d\x27\xc7\x4b\x6f\x2f\x05\x34\x21\xba\xb2\x89\x8a\x3d\x18\x8a\xae\xfe\x87\xf2\x5d\x74\x19\xe0\x04\xba", 253);
*(uint64_t*)0x20000048 = 0xfd;
*(uint64_t*)0x20000050 = 2;
syz_read_part_table(0, 0xaaaaaaaaaaaab81, 0x20000040);
	return 0;
}
