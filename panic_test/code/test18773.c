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

*(uint64_t*)0x20000580 = 0;
*(uint32_t*)0x20000588 = 0;
*(uint64_t*)0x20000590 = 0x20000540;
*(uint64_t*)0x20000540 = 0x200004c0;
*(uint64_t*)0x20000548 = 0x14;
*(uint64_t*)0x20000598 = 1;
*(uint64_t*)0x200005a0 = 0;
*(uint64_t*)0x200005a8 = 0;
*(uint32_t*)0x200005b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000580ul, 0ul);
*(uint64_t*)0x20000380 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0x20000340;
*(uint64_t*)0x20000340 = 0;
*(uint64_t*)0x20000348 = 0;
*(uint64_t*)0x20000398 = 1;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint32_t*)0x200003b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000380ul, 0ul);
*(uint64_t*)0x20000c80 = 0;
*(uint64_t*)0x20000c88 = 0;
*(uint64_t*)0x20000c90 = 0;
*(uint64_t*)0x20000c98 = 0;
*(uint64_t*)0x20000ca0 = 0;
*(uint64_t*)0x20000ca8 = 0;
*(uint64_t*)0x20000cb0 = 0;
*(uint64_t*)0x20000cb8 = 0;
*(uint64_t*)0x20000cc0 = 0;
*(uint64_t*)0x20000cc8 = 0;
*(uint64_t*)0x20000cd0 = 0;
*(uint64_t*)0x20000cd8 = 0;
*(uint64_t*)0x20000ce0 = 0;
*(uint64_t*)0x20000ce8 = 0;
*(uint64_t*)0x20000cf0 = 0;
*(uint64_t*)0x20000cf8 = 0;
*(uint64_t*)0x20000d00 = 0;
*(uint64_t*)0x20000d08 = 0;
*(uint64_t*)0x20000d10 = 0;
*(uint64_t*)0x20000d18 = 0;
*(uint64_t*)0x20000d20 = 0;
*(uint64_t*)0x20000d28 = 0;
*(uint64_t*)0x20000d30 = 0;
*(uint64_t*)0x20000d38 = 0;
*(uint64_t*)0x20000d40 = 0;
*(uint64_t*)0x20000d48 = 0;
*(uint64_t*)0x20000d50 = 0;
*(uint64_t*)0x20000d58 = 0;
*(uint64_t*)0x20000d60 = 0;
*(uint64_t*)0x20000d68 = 0;
*(uint64_t*)0x20000d70 = 0;
*(uint64_t*)0x20000d78 = 0;
*(uint64_t*)0x20000d80 = 0;
*(uint64_t*)0x20000d88 = 0;
*(uint64_t*)0x20000d90 = 0;
*(uint64_t*)0x20000d98 = 0;
*(uint64_t*)0x20000da0 = 0;
*(uint64_t*)0x20000da8 = 0;
*(uint64_t*)0x20000db0 = 0;
*(uint64_t*)0x20000db8 = 0;
*(uint64_t*)0x20000dc0 = 0;
*(uint64_t*)0x20000dc8 = 0;
*(uint64_t*)0x20000dd0 = 0;
*(uint64_t*)0x20000dd8 = 0;
*(uint64_t*)0x20000de0 = 0;
*(uint64_t*)0x20000de8 = 0;
*(uint64_t*)0x20000df0 = 0;
*(uint64_t*)0x20000df8 = 0;
*(uint64_t*)0x20000e00 = 0;
*(uint64_t*)0x20000e08 = 0;
*(uint64_t*)0x20000e10 = 0;
*(uint64_t*)0x20000e18 = 0;
*(uint64_t*)0x20000e20 = 0;
*(uint64_t*)0x20000e28 = 0;
*(uint64_t*)0x20000e30 = 0;
*(uint64_t*)0x20000e38 = 0;
*(uint64_t*)0x20000e40 = 0xfffffffffffffffc;
*(uint64_t*)0x20000e48 = 0x2d52;
*(uint64_t*)0x20000e50 = 0;
*(uint64_t*)0x20000e58 = 0;
*(uint64_t*)0x20000e60 = 0;
*(uint64_t*)0x20000e68 = 0;
*(uint64_t*)0x20000e70 = 0;
*(uint64_t*)0x20000e78 = 0;
*(uint64_t*)0x20000e80 = 0;
*(uint64_t*)0x20000e88 = 0;
*(uint64_t*)0x20000e90 = 0;
*(uint64_t*)0x20000e98 = 0;
*(uint64_t*)0x20000ea0 = 0;
*(uint64_t*)0x20000ea8 = 0;
*(uint64_t*)0x20000eb0 = 0;
*(uint64_t*)0x20000eb8 = 0;
*(uint64_t*)0x20000ec0 = 0;
*(uint64_t*)0x20000ec8 = 0;
*(uint64_t*)0x20000ed0 = 0;
*(uint64_t*)0x20000ed8 = 0;
*(uint64_t*)0x20000ee0 = 0;
*(uint64_t*)0x20000ee8 = 0;
*(uint64_t*)0x20000ef0 = 0;
*(uint64_t*)0x20000ef8 = 0;
*(uint64_t*)0x20000f00 = 0;
*(uint64_t*)0x20000f08 = 0;
*(uint64_t*)0x20000f10 = 0;
*(uint64_t*)0x20000f18 = 0;
*(uint64_t*)0x20000f20 = 0;
*(uint64_t*)0x20000f28 = 0;
*(uint64_t*)0x20000f30 = 0;
*(uint64_t*)0x20000f38 = 0;
*(uint64_t*)0x20000f40 = 0;
*(uint64_t*)0x20000f48 = 0;
*(uint64_t*)0x20000f50 = 0;
*(uint64_t*)0x20000f58 = 0;
*(uint64_t*)0x20000f60 = 0;
*(uint64_t*)0x20000f68 = 0;
*(uint64_t*)0x20000f70 = 0;
*(uint64_t*)0x20000f78 = 0;
*(uint64_t*)0x20000f80 = 0;
*(uint64_t*)0x20000f88 = 0;
*(uint64_t*)0x20000f90 = 0;
*(uint64_t*)0x20000f98 = 0;
*(uint64_t*)0x20000fa0 = 0;
*(uint64_t*)0x20000fa8 = 0;
*(uint64_t*)0x20000fb0 = 0;
*(uint64_t*)0x20000fb8 = 0;
*(uint64_t*)0x20000fc0 = 0;
*(uint64_t*)0x20000fc8 = 0;
*(uint64_t*)0x20000fd0 = 0;
*(uint64_t*)0x20000fd8 = 0;
*(uint64_t*)0x20000fe0 = 0;
*(uint64_t*)0x20000fe8 = 0;
*(uint64_t*)0x20000ff0 = 0;
*(uint64_t*)0x20000ff8 = 0;
*(uint64_t*)0x20001000 = 0;
*(uint64_t*)0x20001008 = 0;
*(uint64_t*)0x20001010 = 0;
*(uint64_t*)0x20001018 = 0;
*(uint64_t*)0x20001020 = 0;
*(uint64_t*)0x20001028 = 0;
*(uint64_t*)0x20001030 = 0;
*(uint64_t*)0x20001038 = 0;
*(uint64_t*)0x20001040 = 0;
*(uint64_t*)0x20001048 = 0;
*(uint64_t*)0x20001050 = 0;
*(uint64_t*)0x20001058 = 0;
*(uint64_t*)0x20001060 = 0;
*(uint64_t*)0x20001068 = 0;
*(uint64_t*)0x20001070 = 0;
*(uint64_t*)0x20001078 = 0;
*(uint64_t*)0x20001080 = 0;
	syscall(__NR_ioctl, -1, 0xc4089434, 0x20000c80ul);
*(uint64_t*)0x200011c0 = 0;
*(uint32_t*)0x200011c8 = 0;
*(uint64_t*)0x200011d0 = 0x20001180;
*(uint64_t*)0x20001180 = 0;
*(uint64_t*)0x20001188 = 0;
*(uint64_t*)0x200011d8 = 1;
*(uint64_t*)0x200011e0 = 0;
*(uint64_t*)0x200011e8 = 0;
*(uint32_t*)0x200011f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200011c0ul, 0ul);
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0x20000000;
memcpy((void*)0x20000000, "\xde\x40\x2c\x92\x65\xf6\x4f\x2d\x11\x96\x9e\xd3\x4c\x71\x8b\xfa\x6e\x4f\x47\xf6\x04\x0f\x5d\xf1\xaa\x5e\x7f\x54\xfb\x88\x71\x2a\x78\xc9\x70\x9d\xea\xe8\xb7\x6a\x47\xc3\x14\xbb\x16\xe0\xbc\x10\xd8\xf3\x20\x39\xaf\xef\x24\x00\x0b\x6b\x07\xd3\xe4\x15\x42\xf1\xe1\xc8\x82\xd6\x57\x74\x99\xbc\xdc\x1b\xa5\xd1\x64\xf8\xe4\x21\x93\xa0\x94\x6c\x1e\xcc\xe0\xb4\x22\x18\x9b\x77\x43\xa4\x78\xdb\x3a\xda\x05\x00\x00\x00\x1c\x90\xd5\xaa\xf1\x98\x46\xcf\x7d\x56\x83\xce\x79\x77\xba\x2f\xaf\x96\x90\x89\x2d\x24\x22\x7d\xc4\x7f\x28\x26\x4f\x03\x8e\xfc\x3d\xc8\xb2\xc6\x7a\x6c\x20\xf1\xcb\xdf\x24\x75\xfb\xe3\x60\x3d\xaf\x47\x21\x9c\x93\x32\x31\x2b\xf8\xe5\xd2\x1f\x92\x63\x90\x39\x56\x92\xcc\x80\x77\x1f\xea\xad\x47\xfe\x9f\x84\xc9\xcf", 180);
*(uint64_t*)0x200000e0 = 0xb4;
*(uint64_t*)0x200000e8 = 0;
syz_read_part_table(0, 0xaaaaaaaaaaaacc3, 0x200000c0);
	return 0;
}