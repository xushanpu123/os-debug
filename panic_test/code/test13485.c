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

#ifndef __NR_fspick
#define __NR_fspick 433
#endif
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

memcpy((void*)0x20000280, "./file0\000", 8);
	syscall(__NR_fspick, 0xffffff9c, 0x20000280ul, 0ul);
memcpy((void*)0x200003c0, "./file0\000", 8);
*(uint64_t*)0x20000800 = 0x20000500;
memcpy((void*)0x20000500, "\x0c\xdd\x7e\xae\xc8\x1d\x02\xfe\x04\xc0\x7c\xd7\x93\x48\xaf\x9b\x6d\x34\x38\xc8\xef\x73\x62\xf6\x47\xb1\xaf\x95\xb1\x04\xcf\x5a\x2f\x15\xc5\x6a\x0c\x0c\x5f\x3e\x82\x4e\x15\xb1\xb3\x36\x09\x0a\x0c\x36\x83\x0e\xaf\x2c\x2c\x56\x5a\x51\xce\x2e\x61\x86\xf5", 63);
*(uint64_t*)0x20000808 = 0x3f;
*(uint64_t*)0x20000810 = 0;
memcpy((void*)0x200008c0, "map=normal", 10);
*(uint8_t*)0x200008ca = 0x2c;
memcpy((void*)0x200008cb, "norock", 6);
*(uint8_t*)0x200008d1 = 0x2c;
memcpy((void*)0x200008d2, "measure", 7);
*(uint8_t*)0x200008d9 = 0x2c;
memcpy((void*)0x200008da, "smackfsfloor", 12);
*(uint8_t*)0x200008e6 = 0x3d;
memcpy((void*)0x200008e7, "&%-\'/\252^^[[,", 11);
*(uint8_t*)0x200008f2 = 0x2c;
*(uint8_t*)0x200008f3 = 0;
syz_mount_image(0, 0x200003c0, 0x3f, 1, 0x20000800, 0, 0x200008c0, 0);
	return 0;
}