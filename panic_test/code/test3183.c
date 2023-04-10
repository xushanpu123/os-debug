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

*(uint64_t*)0x20001a00 = 0x20000880;
memcpy((void*)0x20000880, "\x90\x03\x93\x4e\x55\xd1\x39\x03\x99\xe5\x11\xad\xb1\x31\x47\x4c\x9c\xbb\x49\x1c\x67\x63\x09\xcf\x13\x45\x80\x95\x3f\x01\xc4\xd8\x87\x03\x65\x04\x44\x65\x75\x37\x6b\xd6\x68\x90\xa1\x79\xc3\x21\x00\x03\x29\x52\x8c\x9f\xc9\x93\x00\x57\x07\xeb\x5b\xa4\x57\xc0\x21\xa1\x92\x5b\x40\xc0\x4d\x94\xa0\x23\xb9\x65\xdc\xfc\xba\xb7\x33\xea\xa7\x41\x60\xc0\xdd\xfc\x49\x49\x88\x08\x7b\xca\xd8\x91\xbe\xe8\x4b\x30\xf1\xb9\xce\x55\x23\x3d\x6b\xbb\xb6\x6d\xee\xbb\xde\x62\x83\x7a\x65\x34\x94\x6b\x00\x43\x41\xc8\x56\x64\x70\x1c\x49\x98\x91\xb8\xb7\x6a\xa8\x0b\x5f\x97\x15\x04\xba\x11\xfd\x6e\x01\x1a\xac\xa4\x70\x3f\x13\x48\xdb\x5b\x5a\x0b\xca\x66\xe2\x07\x6a\x96\x37\x79\x6c\xec\xec\x20\x9b\x6f\xdb\x6f\x83\x64\xbe\x07\x3e\x75\x39\x0c\x31\x4a\xea\x44\xd9\xde\x34\xf6\x33\xff\x46\x9a\xd5\x24\x51\x04\xb5\x62\x37\x49\x5d\xe4\x7b\x25\x7a\xe6\xf4\xa3\xf4\xc5\x4f\x87\x23\xc4\x7f\xbe\x5d\xee\x6f\x6f\x53\x8b\xce\x67\x51\x47\x8a\xe6\x67\xf3\xba\x57\xc7\xf5\x70\xdf\x19\x03\x15\xc8\x5b\x3a\xc5\x1d\xe2\xd1\x54\xdf\x81\x6e\xc9\x27\xbe\x92\xbe\xbb\x2f\xc3\x54\xf7\x7b\x25\xa9\x77\xea\xa2\x53\xc4\xf8\xa9\xbc\x21\xaa\xb9\xa8\x84\x5a\x20\xfb\xea\xa2\xc7\xb0\xe9\x7d\xfd\x52\x5c\xc5\x10\x6c\xc4\xa8\x2e\x02\x01\xa9\x8f\x46\x57\x55\x28\x99\x19\x00\x8d\xa2\x20\xb9\xbe\x19\xdf\x56\x84\x4b\x5b\x1d\x12\xf7\x5f\xbd\x6b\x50\x60\xca\xc8\xdc\x70\x81\xd3\xcb\xa2\x38\xfd\xa5\x86\x5e\xcb\x90\x78\xe0\x21\xf2\x40\xa9\xed\x34\x5e\xbb\xa9\x1f\xba\x54\xbd\x10\x38\xc5\x4f\x6b\x46\xcd\xfa\x82\x03\xae\x71\x35\xa4\x43\xc3\x68\x00\x13\x65\x9c\xb6\x1a\x83\x80\x8e\x73\xc0\x35\x59\x1d\x7e\x6f\x72\x82\xd2\xdc\xb8\xfc\xa3\xd4\x86\xf6\x13\x52\x40\x24\x16\xf5\x93\x0f\x78\x10\x88\xda\xee\x37\x30\xcc\x1b\xf5\xcb\xc6\xb0\xb9\x4f\x94\xe9\xfb\x72\xea\x63\x1f\xdf\x7b\xfc\xff\x02\x33\x4d\x05\x0c\x49\x8b\x33\x45\xdc\x0b\x70\x3d\xc7\xfd\xc2\x8e\x4a\x9e\x6d\x12\xa7\xf7\xb4\x9a\x31\x1d\x9d\x35\x82\xd5\xfd\x90\x08\x90\x57\x2d\x4d\x4c\x97\x8e\x04\xe0\x26\x8a\x67\x81\xa5\x77\xb8\x99\xa2\xc6\x6f\x98\xd3\x0b\xb6\xa8\xf9\x5d\x4d\x85\x4a\xea\x11\xd6\xab\x43\xfb\xf8\xae\x68\x62\xf9\xb5\xc9\x16\x24\xbe\xd7", 512);
*(uint64_t*)0x20001a08 = 0x200;
*(uint64_t*)0x20001a10 = 0;
syz_read_part_table(0, 1, 0x20001a00);
	return 0;
}
