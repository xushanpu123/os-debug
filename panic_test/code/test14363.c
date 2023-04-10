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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x02\x00\x00\x19\x00\x00\x00\x60\x01\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x02\x00\x00\x20\x00\x00\x20\x00\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x00\x00\x08\x00\x00\x00\xd2\x42\x00\x00\x12\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x00\x00\x00\x00\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x33\x32\x39\x37\x36\x37\x36\x34\x34\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000208 = 0xc0;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010100;
memcpy((void*)0x20010100, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xde\xf3\x61\xb1\x16\xdd\x4b\xb6\x81\x39\x19\x64\xcc\xf0\x77\xda\x01\x00\x40\x00\x0c\x00\x00\x00\x00\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000220 = 0x40;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x20010200;
memcpy((void*)0x20010200, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x20\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x37\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000238 = 0x40;
*(uint64_t*)0x20000240 = 0x540;
*(uint64_t*)0x20000248 = 0x20010300;
memcpy((void*)0x20010300, "\x03\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x640;
*(uint64_t*)0x20000260 = 0x20010400;
memcpy((void*)0x20010400, "\x03\x00\x00\x00\x04\x00\x00\x00\x05\x00\x00\x00\x16\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x00\x69\x8c", 32);
*(uint64_t*)0x20000268 = 0x20;
*(uint64_t*)0x20000270 = 0x800;
*(uint64_t*)0x20000278 = 0x20010500;
memcpy((void*)0x20010500, "\xff\x03\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 2080);
*(uint64_t*)0x20000280 = 0x820;
*(uint64_t*)0x20000288 = 0xc00;
*(uint64_t*)0x20000290 = 0x20010e00;
memcpy((void*)0x20010e00, "\xed\x41\x00\x00\x00\x04\x00\x00\xd0\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x20\x00\x00\x00\x00\x00\x08\x00\x05\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x10\x00\x00\x00", 64);
*(uint64_t*)0x20000298 = 0x40;
*(uint64_t*)0x200002a0 = 0x1500;
*(uint64_t*)0x200002a8 = 0x20010f00;
memcpy((void*)0x20010f00, "\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x00\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002b0 = 0x20;
*(uint64_t*)0x200002b8 = 0x1580;
*(uint64_t*)0x200002c0 = 0x20011000;
memcpy((void*)0x20011000, "\x80\x81\x00\x00\x00\x18\x00\x00\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x02\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x30\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x200002c8 = 0xa0;
*(uint64_t*)0x200002d0 = 0x1600;
*(uint64_t*)0x200002d8 = 0x20011100;
memcpy((void*)0x20011100, "\x80\x81\x00\x00\x00\x18\x00\x00\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x02\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x40\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x42\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x200002e0 = 0xa0;
*(uint64_t*)0x200002e8 = 0x1700;
*(uint64_t*)0x200002f0 = 0x20011200;
memcpy((void*)0x20011200, "\xc0\x41\x00\x00\x00\x30\x00\x00\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x02\x00\x20\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x0c\x00\x00\x00\x20\x00\x00\x00", 64);
*(uint64_t*)0x200002f8 = 0x40;
*(uint64_t*)0x20000300 = 0x1e00;
*(uint64_t*)0x20000308 = 0x20011300;
memcpy((void*)0x20011300, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000310 = 0x20;
*(uint64_t*)0x20000318 = 0x1e80;
*(uint64_t*)0x20000320 = 0x20011400;
memcpy((void*)0x20011400, "\xed\x41\x00\x00\x00\x04\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x02\x00\x20\x00\x00\x00\x00\x00\x08\x00\x03\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x50\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x3f\x81\xd1\xa2\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000328 = 0xa0;
*(uint64_t*)0x20000330 = 0x1f00;
*(uint64_t*)0x20000338 = 0x20011500;
memcpy((void*)0x20011500, "\xed\x81\x00\x00\x1a\x04\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x60\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x9c\xae\xf3\x2e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000340 = 0xa0;
*(uint64_t*)0x20000348 = 0x2000;
*(uint64_t*)0x20000350 = 0x20011600;
memcpy((void*)0x20011600, "\xff\xa1\x00\x00\x26\x00\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x33\x32\x39\x37\x36\x37\x36\x34\x34\x2f\x66\x69\x6c\x65\x30\x2f\x66\x69\x6c\x65\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0a\xe0\xcd\xf1\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000358 = 0xa0;
*(uint64_t*)0x20000360 = 0x2100;
*(uint64_t*)0x20000368 = 0x20011700;
memcpy((void*)0x20011700, "\xed\x81\x00\x00\x0a\x00\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa3\xd3\xad\x5b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x06\x01\x54\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\x06\x01\x4c\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\xed\x81\x00\x00\x28\x23\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x02\x00\x20\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x00\x00\x00\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x2d\x4a\xb0\x6e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00", 416);
*(uint64_t*)0x20000370 = 0x1a0;
*(uint64_t*)0x20000378 = 0x2200;
*(uint64_t*)0x20000380 = 0x20011900;
memcpy((void*)0x20011900, "\xed\x81\x00\x00\x64\x00\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x90\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x88\x80\xd3\x95\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\x10\x0d\xe1\x7a\xd2\xf4\x65\x5f\x10\x0d\xe1\x7a\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000388 = 0xa0;
*(uint64_t*)0x20000390 = 0x2400;
*(uint64_t*)0x20000398 = 0x20011b00;
memcpy((void*)0x20011b00, "\x0b\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\xf4\x03\x02\x02\x2e\x2e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003a0 = 0x20;
*(uint64_t*)0x200003a8 = 0x8000;
*(uint64_t*)0x200003b0 = 0x20011c00;
memcpy((void*)0x20011c00, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003b8 = 0x20;
*(uint64_t*)0x200003c0 = 0x8400;
*(uint64_t*)0x200003c8 = 0x20011d00;
memcpy((void*)0x20011d00, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003d0 = 0x20;
*(uint64_t*)0x200003d8 = 0x8800;
*(uint64_t*)0x200003e0 = 0x20011e00;
memcpy((void*)0x20011e00, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003e8 = 0x20;
*(uint64_t*)0x200003f0 = 0x8c00;
*(uint64_t*)0x200003f8 = 0x20011f00;
memcpy((void*)0x20011f00, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000400 = 0x20;
*(uint64_t*)0x20000408 = 0x9000;
*(uint64_t*)0x20000410 = 0x20012000;
memcpy((void*)0x20012000, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000418 = 0x20;
*(uint64_t*)0x20000420 = 0x9400;
*(uint64_t*)0x20000428 = 0x20012100;
memcpy((void*)0x20012100, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000430 = 0x20;
*(uint64_t*)0x20000438 = 0x9800;
*(uint64_t*)0x20000440 = 0x20012700;
memcpy((void*)0x20012700, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06", 21);
*(uint64_t*)0x20000448 = 0x15;
*(uint64_t*)0x20000450 = 0xc000;
*(uint64_t*)0x20000458 = 0x20012800;
memset((void*)0x20012800, 2, 1);
*(uint64_t*)0x20000460 = 1;
*(uint64_t*)0x20000468 = 0xc400;
*(uint64_t*)0x20000470 = 0x20000080;
memset((void*)0x20000080, 3, 1);
*(uint64_t*)0x20000478 = 1;
*(uint64_t*)0x20000480 = 0xc800;
*(uint64_t*)0x20000488 = 0x20012a00;
memset((void*)0x20012a00, 4, 1);
*(uint64_t*)0x20000490 = 1;
*(uint64_t*)0x20000498 = 0xcc00;
*(uint64_t*)0x200004a0 = 0x20012b00;
memset((void*)0x20012b00, 5, 1);
*(uint64_t*)0x200004a8 = 1;
*(uint64_t*)0x200004b0 = 0xd000;
*(uint64_t*)0x200004b8 = 0x20012c00;
memcpy((void*)0x20012c00, "\x00\x00\x00\xd2\x4b\x00\x00\x00\x01\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\xf2\xbe\x00\x00\x00\x00\x00\x00\x00\x09", 32);
*(uint64_t*)0x200004c0 = 0x20;
*(uint64_t*)0x200004c8 = 0xd400;
*(uint64_t*)0x200004d0 = 0x20012d00;
memcpy((void*)0x20012d00, "\x27\x19\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06", 21);
*(uint64_t*)0x200004d8 = 0x15;
*(uint64_t*)0x200004e0 = 0x10000;
memcpy((void*)0x20000040, "\x00\x52\xc0\x82\x2f\x73\xe8\x22\x7c\x31\x3e\xe7\x83\xaf\x44\xb9\x3b\x0c\xd7\x20\xa0\x6f\x41\x92\xc7\x5f\x93\x2f\xc8\x4a\x1f\x4c\x79\x28\xc9", 35);
syz_mount_image(0x20000000, 0x20000100, 0x10015, 0x1f, 0x20000200, 0, 0x20000040, 0);
memcpy((void*)0x20000100, "./file0\000", 8);
	res = syscall(__NR_newfstatat, 0xffffffffffffff9cul, 0x20000100ul, 0x200002c0ul, 0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x200002d8;
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_lchown, 0x20000000ul, r[0], 0);
	return 0;
}