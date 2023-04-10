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

memcpy((void*)0x20000000, "nfs4\000", 5);
memcpy((void*)0x20000040, "./file0\000", 8);
*(uint64_t*)0x20000400 = 0x20000380;
memset((void*)0x20000380, 227, 1);
*(uint64_t*)0x20000408 = 1;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0x20000240;
memcpy((void*)0x20000240, "\x9d\x85\x92", 3);
*(uint64_t*)0x20000420 = 3;
*(uint64_t*)0x20000428 = 1;
*(uint64_t*)0x20000430 = 0x20000340;
memset((void*)0x20000340, 38, 1);
*(uint64_t*)0x20000438 = 1;
*(uint64_t*)0x20000440 = 4;
*(uint64_t*)0x20000448 = 0x20000280;
memcpy((void*)0x20000280, "\x87\x4e\xd8\xd0\x63\x1c\x78\x58\xca\x44\x21\xae\x97\x0f\x1a\x16\x7c\x6e\xf7\xf5\x97\xd7\x57\xa7\x0b\x35\x4b\xb3\x1c\x37\x48\xac\xfa\x2a\x28\xa7\xed\xe2\x63\x38\xfc\xd9\x18\x1c\x4e\xf1\xd4\xb2\xa5\x22\xe8\xa4\x07\x09\xcb\xc8\xa2\x3f\x8e\x0a\xa9\x86\xbe\xa9\x46\x93\x36\xa9\x3f\xd9\x0e\x15\x72\xd5\xac\x2e\xbf\x48\x45\x0c\xbc\xae\x6c\x29\x3d\x5a\xf3\x13\x91\x78\x79\x67\x73\x1f\x73\x14\xbb\x50\x06\xff\x96\x44", 102);
*(uint64_t*)0x20000450 = 0x66;
*(uint64_t*)0x20000458 = 5;
*(uint64_t*)0x20000460 = 0x20000200;
memcpy((void*)0x20000200, "\xa5\xfa", 2);
*(uint64_t*)0x20000468 = 2;
*(uint64_t*)0x20000470 = 0xff;
*(uint64_t*)0x20000478 = 0x20000100;
memcpy((void*)0x20000100, "\xbf\x16\x31\x02\xca\xdc\x65\x23\x59\x61\x2e\xaf\x10\x85\x8b\x09\xf4\x81\xc1\xee\xb0\x8c\xc9\x2e\xa9\xf5\x3a\xab\x89\x43\x3a\x1a\x67\xe2\x8c\xe4\xed\x95\xa9\xe2\xcd\xc5\x42\xd8\xf6\x8b\x12\x67\xec\x92\x90\x44\x55\x25\xf8\x52\xe7\x88\xf6\x8e\xc2\x44\x76\xf1\x86\xba\xed\x59\xf3\x08\x35\x97\x28\xd8\x49\xe9\x28\x3d\x48\xdf\x76\xe0\x4b\x62\xf9\x79\x7a\x35\xff\xbc\x21\x33\x10\x79\xa1\xef\xf8\x22\x3b\x38\x6a\xbb\xee\x54\xea\x37\x3f\xd2\x80\x60\xb2\x9d\x64\x75\x0f\x01\x39\xc6\xb3\x73\xb0\xa9\xf0\x29\xc3\x5b\x6e\xff\xe4\xc3\x3e\x8b\xd8\x2c\xe9\x15\xef\x4b\xac\xe7\x25\x0e\x6b\xd5\x6e\xdf\xd5\xee\xd4\xb6\x19\x4b\x42\x28\x43\x4f\xa1\x06\xcb\xbf\x70\x22\x4c\x7f\x40\x3f\xc6\xaf\x55\x5f\xe7\xe9\x7f\x66\xc4\x56\x0f\x9c\x2b\xdf\x9f\xd5\x03\x11\x29\xf7\xba\x73\x87\x3e\x2c\xd4\xcb\x1d\xee\x7a\x36\xb6\xed\x75\xab\xe7\x77\xfd\xfb\x73\x63\x8c\xa9\x62\xb6\x42\xb2\xe5\x9b\x83\x53\xa0\x29\xe5\xb7\x0a\xd0\x44\xa2\x19\xeb\xce\x87\x70\x29\x33\xe3\x58\xe9\xf0\x9a\x5b\xc1\x95\xa5\x2a\xec\x92\xc6\xcc\xd3\x95\x74\xcf\x19\x06\xa4\x40", 254);
*(uint64_t*)0x20000480 = 0xfe;
*(uint64_t*)0x20000488 = 0x101;
memcpy((void*)0x200004c0, "\xde\xc8\x5d\xd5\x9f\x98\xcb\x43\x41\x35\x64\xb5\x13\xae\x5a\x98\x19\xd6\x93\x9f\xf9\xc0\x73\x3c\x7b\x00\x6d\x63\xfb\xc3\xa2\xc2\x51\xa0\x7b\xec\x17\x58\x79\xab\x92\xe1\xf1\x14\xc3\xa6\x92\x2c\xef\x19\x88\xae\xcd\x92\x9c\xb3\xad\x95\x67\x81\x66\x00\x34\x99\x25\x96\xd8\x24\x7b\xfe\x65\xd2\x60\xfc\xfa\xcc\x3a\xf0\x03\xbf\x37\x92\x77\x9b\xc5\x1c\x46\x8f\x8b\x3b\x69\xc2\x62\x90\xb0\x68\x21\x0a\x56\xb4\xdc\xee\xf9\x2e\x0f\xd5\xcd\xc6\x9e\x52\x8b\x9c\x9c\x69\xf8\x10\xbe\xd7\xb0\xd2\x65\x04\x23\xa4\x4a\xa3\x74\xad\xba\xeb\xe6\xeb\xc5\x15\xb2\x36\x38\x3c\x39\x82\x12\x7c\x1d\x78\x8f\x73\x92\x48\x9f\x57\x3b\x66\x21\xc4\xcf\x4c\x56\x36\xce\xd8\xb5\x4e\x2b\x90\x95\xdf\x74\xb7\x9b\xaf\xd1\x00\x7c\xfb\xd3\x44\x42\xe0\xa2\x20\xa2\x07\x63\xf4\xbf\xf8\x67\x15\x34\xe1\xa6\x2f\xf8\x58\x93\x30\x01\x7c\x13\xb5\x5b\xe1\xda\x32\x1c\x25\x84\x57\x5c\x52\xbf\x0e", 212);
syz_mount_image(0x20000000, 0x20000040, 0x1ff, 6, 0x20000400, 0x1400, 0x200004c0, 0);
	return 0;
}
