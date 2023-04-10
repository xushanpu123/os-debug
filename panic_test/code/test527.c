// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000040 = 0x20000280;
memcpy((void*)0x20000280, "\x20\x00\x00\x00\x80\x00\x00\x00\x06\x00\x00\x00\x6a\x00\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x40\x00\x00\x00\x40\x00\x00\x20\x00\x00\x00\xd5\xf4\x65\x5f\xd6\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd5\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x4a\x6d\xdb\x3c\x33\xdc\xcc\x0a\x01\xa3\xc6", 101);
*(uint64_t*)0x20000048 = 0x65;
*(uint64_t*)0x20000050 = 0x400;
*(uint64_t*)0x20000058 = 0x20000340;
memcpy((void*)0x20000340, "\x00\x00\x00\x00\x00\x00\x00\x6e\x2a\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe4\x19\x3a\xdf\xdc\x0e\x46\xd2\x94\x25\x04\x4b\x1c\x88\xbf\x6c\xe3\x89\x37\x0d\x87\xd6\x91\xb1\x3e\x33\x2f\x93\xa1\xf1\x62\x8a\x37\x95\x13\x93\x40\x7b\x54\xe1\xff\x00\x93\xac\xc3\xba\xe2\xb8\xa2\x5a\x50\xec\x23\x0c\xba\x54\xeb\x6e\xd2\x4b\x22\xfa\x15\xe1\xb4\xde\x3a\xe6\x8d\x79\x16\xda\x19\xaa\x4b\xa0\x24\x47\x92\x9a\x48\xae\xdf\xf8\xcc\xc9\x09\xda\xf0\x44\xd9\xdf\x54\x66\x6e\x6b\xd4\x5f\x15\xe5\xac\xee\x69\xb7\x70\x55\xee\x51\x5e", 127);
*(uint64_t*)0x20000060 = 0x7f;
*(uint64_t*)0x20000068 = 0x4e0;
syz_mount_image(0x20000000, 0x20000100, 0x55f, 2, 0x20000040, 0, 0x20000140, 0);
	return 0;
}
