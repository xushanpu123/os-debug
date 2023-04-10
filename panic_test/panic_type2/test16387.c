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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "vfat\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x60\x1c\x6d\x6b\x64\x6f\x73\x66\xee\x57\x84\x00\x08\x08\x20\x00\x02\x00\x00\x80\x00\xf8\x00\x00\x20\x00\x40\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01", 37);
*(uint64_t*)0x20000208 = 0x25;
*(uint64_t*)0x20000210 = 0;
*(uint8_t*)0x20000040 = 0;
	res = -1;
res = syz_mount_image(0x200000c0, 0x20000100, 0x25, 1, 0x20000200, 0, 0x20000040, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "./file0\000", 8);
	res = syscall(__NR_openat, r[0], 0x20000000ul, 0x88c0ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20000080 = 0x6c;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
memcpy((void*)0x2000008c, "\xb2\x3b\xcf\x4e\x78\x5c\x52\x42\x66\x95\x1d\x77\x80\xb7\x61\x8c\x69\x1c\x65\xc6\xe0\xf7\xd3\x14\xad\x91\x03\x80\x5a\xb4\xf2\x5d\x6e\x9a\x9c\x57\xa2\x8d\x91\x4b\x5d\x26\xb5\x65\x27\x12\xcc\x69\x59\x47\x0e\x3c\xf5\x7e\x9f\x63\x83\x45\xdf\xe6\x7f\x20\x87\x7d\x14\x56\x09\x72\xca\x73\xdf\xa0\x76\xc2\xfc\xa3\x18\x0e\x06\x2a\x8b\xa1\x26\x6b\x4f\x29\xbf\xc9\x9e\x8a\x6f\x5a\x02\x28\x53\xda\xeb\x98\xa0\xb6\x75\x3a\x8f\x60\x4c\xdb\xab\xe0", 108);
	syscall(__NR_ioctl, r[1], 1, 0x20000080ul);
	return 0;
}
