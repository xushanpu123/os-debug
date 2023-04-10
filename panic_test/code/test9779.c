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
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x01\x00\x00\x0c\x00\x00\x00\xce\x00\x00\x00\x0f\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x20\x00\x00\x20\x00\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x80\x00\x00\x00\x08\x00\x00\x00\x52\x47\x00\x00\x62\x01", 102);
*(uint64_t*)0x20000208 = 0x66;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010200;
memcpy((void*)0x20010200, "\x01\x00\x00\x00\x00\x00\x05\x00\x11", 9);
*(uint64_t*)0x20000220 = 9;
*(uint64_t*)0x20000228 = 0x560;
*(uint64_t*)0x20000230 = 0x20010300;
memset((void*)0x20010300, 3, 1);
*(uint64_t*)0x20000238 = 1;
*(uint64_t*)0x20000240 = 0x640;
*(uint64_t*)0x20000248 = 0x20010400;
memcpy((void*)0x20010400, "\x03\x00\x00\x00\x13\x00\x00\x00\x23", 9);
*(uint64_t*)0x20000250 = 9;
*(uint64_t*)0x20000258 = 0x800;
*(uint64_t*)0x20000260 = 0x20011600;
memcpy((void*)0x20011600, "\x50\x4d\x4d\x00\x50\x4d\x4d\xff", 8);
*(uint64_t*)0x20000268 = 8;
*(uint64_t*)0x20000270 = 0x4400;
*(uint64_t*)0x20000278 = 0x20011700;
memcpy((void*)0x20011700, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\xe4\x89\x45\xa7\x8a\xac\xe9\xa2", 21);
*(uint64_t*)0x20000280 = 0x15;
*(uint64_t*)0x20000288 = 0x4800;
*(uint64_t*)0x20000290 = 0x20012b00;
memcpy((void*)0x20012b00, "\xed\x41\x00\x00\x00\x04\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x02", 29);
*(uint64_t*)0x20000298 = 0x1d;
*(uint64_t*)0x200002a0 = 0x8c80;
*(uint64_t*)0x200002a8 = 0x20012c00;
memcpy((void*)0x20012c00, "\x80\x81\x00\x00\x00\x18\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x0c\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x12\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x18\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x14\x00\x00\x00", 88);
*(uint64_t*)0x200002b0 = 0x58;
*(uint64_t*)0x200002b8 = 0x8d00;
*(uint8_t*)0x20013800 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x40000, 8, 0x20000200, 0, 0x20013800, 0);
	return 0;
}
