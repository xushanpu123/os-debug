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
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x02\x00\x00\x19\x00\x00\x00\x60\x01\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x05\x00\x00\x00\x00\x00\x04\x00\x00\x40\x00\x00\x20\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x00\x00\x08\x00\x00\x00\xd2\x42\x01\x00\x12\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x00\x00\x00\x00\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x32\x33\x39\x32\x33\x36\x36\x33\x37\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000208 = 0xc0;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x200100c0;
memcpy((void*)0x200100c0, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x31\xdb\xcc\x0e\xdb\x39\x43\x38\xb0\xfc\x27\xa2\x2c\xaa\x9e\x5e\x01\x00\x40\x00\x0c\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000220 = 0x40;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x20010100;
memcpy((void*)0x20010100, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x20\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x46\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000238 = 0x40;
*(uint64_t*)0x20000240 = 0x540;
*(uint64_t*)0x20000248 = 0x20010140;
memcpy((void*)0x20010140, "\x03\x00\x00\x00\x04\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x640;
*(uint64_t*)0x20000260 = 0x20010160;
memcpy((void*)0x20010160, "\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x16\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x00\xc5\xd7", 32);
*(uint64_t*)0x20000268 = 0x20;
*(uint64_t*)0x20000270 = 0x800;
*(uint64_t*)0x20000278 = 0x20010180;
memcpy((void*)0x20010180, "\xff\x03\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 4128);
*(uint64_t*)0x20000280 = 0x1020;
*(uint64_t*)0x20000288 = 0x1000;
*(uint64_t*)0x20000290 = 0x200111a0;
memcpy((void*)0x200111a0, "\xed\x41\x00\x00\x00\x08\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x04\x00\x40\x00\x00\x00\x00\x00\x08\x00\x05\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x10\x00\x00\x00", 64);
*(uint64_t*)0x20000298 = 0x40;
*(uint64_t*)0x200002a0 = 0x2100;
*(uint64_t*)0x200002a8 = 0x200111e0;
memcpy((void*)0x200111e0, "\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002b0 = 0x20;
*(uint64_t*)0x200002b8 = 0x2180;
*(uint64_t*)0x200002c0 = 0x20011200;
memcpy((void*)0x20011200, "\x80\x81\x00\x00\x00\x18\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x30\x00\x00\x00", 64);
*(uint64_t*)0x200002c8 = 0x40;
*(uint64_t*)0x200002d0 = 0x2200;
*(uint64_t*)0x200002d8 = 0x20011240;
memcpy((void*)0x20011240, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002e0 = 0x20;
*(uint64_t*)0x200002e8 = 0x2280;
*(uint64_t*)0x200002f0 = 0x20011260;
memcpy((void*)0x20011260, "\x80\x81\x00\x00\x00\x18\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x40\x00\x00\x00", 64);
*(uint64_t*)0x200002f8 = 0x40;
*(uint64_t*)0x20000300 = 0x2300;
*(uint64_t*)0x20000308 = 0x200112a0;
memcpy((void*)0x200112a0, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000310 = 0x20;
*(uint64_t*)0x20000318 = 0x2380;
*(uint64_t*)0x20000320 = 0x200112c0;
memcpy((void*)0x200112c0, "\xc0\x41\x00\x00\x00\x40\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x40\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x20\x00\x00\x00", 64);
*(uint64_t*)0x20000328 = 0x40;
*(uint64_t*)0x20000330 = 0x2a00;
*(uint64_t*)0x20000338 = 0x20011300;
memcpy((void*)0x20011300, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000340 = 0x20;
*(uint64_t*)0x20000348 = 0x2a80;
*(uint64_t*)0x20000350 = 0x20011320;
memcpy((void*)0x20011320, "\xed\x41\x00\x00\x00\x08\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x40\x00\x00\x00\x00\x00\x08\x00\x03\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x50\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x76\x8e\x54\x85\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000358 = 0xa0;
*(uint64_t*)0x20000360 = 0x2b00;
*(uint64_t*)0x20000368 = 0x200113c0;
memcpy((void*)0x200113c0, "\xed\x81\x00\x00\x1a\x04\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x60\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x6b\x5b\xa5\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000370 = 0xa0;
*(uint64_t*)0x20000378 = 0x2c00;
*(uint64_t*)0x20000380 = 0x20011460;
memcpy((void*)0x20011460, "\xff\xa1\x00\x00\x27\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x32\x33\x39\x32\x33\x36\x36\x33\x37\x30\x2f\x66\x69\x6c\x65\x30\x2f\x66\x69\x6c\x65\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x16\xab\xf3\xf5\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000388 = 0xa0;
*(uint64_t*)0x20000390 = 0x2d00;
*(uint64_t*)0x20000398 = 0x20011500;
memcpy((void*)0x20011500, "\xed\x81\x00\x00\x0a\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x82\x11\xfa\xe9\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x06\x01\x54\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\x06\x01\x4c\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\xed\x81\x00\x00\x28\x23\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x49\x87\xdf\x49\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00", 416);
*(uint64_t*)0x200003a0 = 0x1a0;
*(uint64_t*)0x200003a8 = 0x2e00;
*(uint64_t*)0x200003b0 = 0x200116a0;
memcpy((void*)0x200116a0, "\xed\x81\x00\x00\x64\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x90\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x27\x20\xf0\x66\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\xd8\x78\xaf\x99\xd8\x78\xaf\x99\xd8\x78\xaf\x99\x71\x1f\x1f\x63\xd8\x78\xaf\x99\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x200003b8 = 0xa0;
*(uint64_t*)0x200003c0 = 0x3000;
*(uint64_t*)0x200003c8 = 0x20011740;
memcpy((void*)0x20011740, "\x02\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x0b\x00\x00\x00\x14\x00\x0a\x02\x6c\x6f\x73\x74\x2b\x66\x6f\x75\x6e\x64\x00\x00\x0c\x00\x00\x00\x10\x00\x05\x02\x66\x69\x6c\x65\x30\x00\x00\x00\x0f\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x31\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x32\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x33\x00\x00\x00\x11\x00\x00\x00\x94\x07\x09\x01\x66\x69\x6c\x65\x2e\x63\x6f\x6c\x64\x00\x00\x00", 128);
*(uint64_t*)0x200003d0 = 0x80;
*(uint64_t*)0x200003d8 = 0x8000;
*(uint64_t*)0x200003e0 = 0x200117c0;
memcpy((void*)0x200117c0, "\x0b\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\xf4\x07\x02\x02\x2e\x2e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003e8 = 0x20;
*(uint64_t*)0x200003f0 = 0x10000;
*(uint64_t*)0x200003f8 = 0x200117e0;
memcpy((void*)0x200117e0, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000400 = 0x20;
*(uint64_t*)0x20000408 = 0x10800;
*(uint64_t*)0x20000410 = 0x20011800;
memcpy((void*)0x20011800, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000418 = 0x20;
*(uint64_t*)0x20000420 = 0x11000;
*(uint64_t*)0x20000428 = 0x20011820;
memcpy((void*)0x20011820, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000430 = 0x20;
*(uint64_t*)0x20000438 = 0x11800;
*(uint64_t*)0x20000440 = 0x20011840;
memcpy((void*)0x20011840, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000448 = 0x20;
*(uint64_t*)0x20000450 = 0x12000;
*(uint64_t*)0x20000458 = 0x20011860;
memcpy((void*)0x20011860, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000460 = 0x20;
*(uint64_t*)0x20000468 = 0x12800;
*(uint64_t*)0x20000470 = 0x20011880;
memcpy((void*)0x20011880, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000478 = 0x20;
*(uint64_t*)0x20000480 = 0x13000;
*(uint64_t*)0x20000488 = 0x200118a0;
memcpy((void*)0x200118a0, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000490 = 0x20;
*(uint64_t*)0x20000498 = 0x13800;
*(uint64_t*)0x200004a0 = 0x200118c0;
memcpy((void*)0x200118c0, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00", 32);
*(uint64_t*)0x200004a8 = 0x20;
*(uint64_t*)0x200004b0 = 0x18000;
*(uint64_t*)0x200004b8 = 0x200118e0;
memcpy((void*)0x200118e0, "\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200004c0 = 0x20;
*(uint64_t*)0x200004c8 = 0x18400;
*(uint64_t*)0x200004d0 = 0x20011900;
memcpy((void*)0x20011900, "\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200004d8 = 0x20;
*(uint64_t*)0x200004e0 = 0x18800;
*(uint64_t*)0x200004e8 = 0x20011920;
memcpy((void*)0x20011920, "\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200004f0 = 0x20;
*(uint64_t*)0x200004f8 = 0x18c00;
*(uint64_t*)0x20000500 = 0x20011940;
memcpy((void*)0x20011940, "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000508 = 0x20;
*(uint64_t*)0x20000510 = 0x19000;
*(uint64_t*)0x20000518 = 0x20011960;
memcpy((void*)0x20011960, "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 96);
*(uint64_t*)0x20000520 = 0x60;
*(uint64_t*)0x20000528 = 0x19400;
*(uint64_t*)0x20000530 = 0x200119c0;
memcpy((void*)0x200119c0, "\x27\x19\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00", 32);
*(uint64_t*)0x20000538 = 0x20;
*(uint64_t*)0x20000540 = 0x20000;
*(uint64_t*)0x20000548 = 0x200119e0;
memcpy((void*)0x200119e0, "\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000550 = 0x20;
*(uint64_t*)0x20000558 = 0x20400;
*(uint64_t*)0x20000560 = 0x20011a00;
memcpy((void*)0x20011a00, "\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000568 = 0x20;
*(uint64_t*)0x20000570 = 0x20800;
*(uint64_t*)0x20000578 = 0x20011a20;
memcpy((void*)0x20011a20, "\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000580 = 0x20;
*(uint64_t*)0x20000588 = 0x20c00;
*(uint64_t*)0x20000590 = 0x20011a40;
memcpy((void*)0x20011a40, "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000598 = 0x20;
*(uint64_t*)0x200005a0 = 0x21000;
*(uint64_t*)0x200005a8 = 0x20011a60;
memcpy((void*)0x20011a60, "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 96);
*(uint64_t*)0x200005b0 = 0x60;
*(uint64_t*)0x200005b8 = 0x21400;
*(uint64_t*)0x200005c0 = 0x20011ac0;
memcpy((void*)0x20011ac0, "\x0c\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x0d\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x30\x00\x00\x00\x0e\x00\x00\x00\xd8\x07\x05\x07\x66\x69\x6c\x65\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x200005c8 = 0x40;
*(uint64_t*)0x200005d0 = 0x28000;
*(uint64_t*)0x200005d8 = 0x20011b00;
memcpy((void*)0x20011b00, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkal\000\000\000\000\000\000", 1056);
*(uint64_t*)0x200005e0 = 0x420;
*(uint64_t*)0x200005e8 = 0x30000;
*(uint64_t*)0x200005f0 = 0x20011f20;
memcpy((void*)0x20011f20, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200005f8 = 0x20;
*(uint64_t*)0x20000600 = 0x38000;
*(uint64_t*)0x20000608 = 0x20011f40;
memcpy((void*)0x20011f40, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x20000610 = 0x80;
*(uint64_t*)0x20000618 = 0x48000;
*(uint8_t*)0x20011fc0 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x100000, 0x2c, 0x20000200, 0, 0x20011fc0, 1);
	return 0;
}
