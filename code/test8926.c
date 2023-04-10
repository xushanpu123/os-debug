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

memcpy((void*)0x20000040, "tmpfs\000", 6);
memcpy((void*)0x20000080, "./file0\000", 8);
*(uint64_t*)0x200003c0 = 0x20000280;
memcpy((void*)0x20000280, "\x2b\x82\x1a\x22\x05\x6b\xcf\xdc\xed\x3b\x83", 11);
*(uint64_t*)0x200003c8 = 0xb;
*(uint64_t*)0x200003d0 = 0;
*(uint64_t*)0x200003d8 = 0x20000340;
memcpy((void*)0x20000340, "\x98\xd4\x08\xbe\x16\x73\x1b\xbe\x33\x21\x18\xf7\x28\xdf\xa5\x3f\xaf\x81\x2e\x9c\x2d\x35\x81\x30\xd1\x63\x01\xc2\xa1\xe6\x17\xa3\x1c\x8c\xcb\xd8\xc9\x97\x83\x32\xba\x68\xf1\xae\x04\x6e\x91\x51\x5e\xbd\x8a\x95\x67\xb6\xf7\x06\x71\x73\x8e\x64\xf8\x52\x68\x08\xdd\xd9\x92\x3a\x91\xe9\xee\x32\x06\x18\x51\xae\xe2\x2c\x88\x07\x60\x11\x75\xc7\xd9\xf4\x4b\xbc\xb8\xe4\xd5\x7f\x62\x04\xc2\xfe\xc5\x4d\x57\xde\x72\x8f\x00\xfa\x35\xca\x2e\xc4\xbd\xf0\x5e\xa9", 112);
*(uint64_t*)0x200003e0 = 0x70;
*(uint64_t*)0x200003e8 = 0xb;
*(uint64_t*)0x200003f0 = 0x20000180;
memcpy((void*)0x20000180, "\x41\xef\xbb\x70\x00\x5e\x03\x3c\x14\x9e\xe2\x08\xa6\xd2\x53\xfc\x5a\x83\xaa\xb0\x73\xa2\x80\xe0\xb1\x35\x73\x0c\xc6\x1b\x59\xd2\x46\x39\x5b\x7a\xe4\xb1\x7d\x29\x7e\x99\xaf\x5f\x66\x9e\x65\xa1\x7d\x84\xed\xe0\xef\xb7\x3e\x22\x8b\x69\x87\xac\x2c\x62\xe6\xc5\x6a\x2d\x29\x99\x63\x7f\x27\x23\xab\x0a\xbc\xec\x7e\x72\x13\x0b\x79\x0f\xcb\x2b\x81\x13\x59\x90\x50\xa9\x54\xe8\x0d\x94\x65\xf4\xcc\x1f\x24\xd0\xc3\x5f\xd1\xad\x36\x76\x31\x1c\xa6\x5a\xd4\xc0\xfb\x72\xdc\xd8\xfa\x40\xbe\x76\x43\x55\x06\x61\x16\xb0\xb2\x5b\x29\xdc\x61\x77\x33\x39\xb8\x68\xd8\x2a\x8c\x52\xbe\xe3\x9b\x7c\xde\x31\x9f\x5f\xd4\xbf\x72\x5e\x02\x15\x05\x0e\xd6\x6b\xbf\x13\xdb\x21\xb1\xb6\x51\x9a\xa2\xe5\xcb\x6c\xed\x1c\x81\x2d\x17\x1b\x99\xb4\xef\x21\x90\xf8\xf4\x06\x42\x4f\xd1\xa9\x25\x04\x71\x9f\x8f\x09\xfe\x75\x83\xbf\xfb\x09\x57", 201);
*(uint64_t*)0x200003f8 = 0xc9;
*(uint64_t*)0x20000400 = 0x81;
memcpy((void*)0x200005c0, "huge=never", 10);
*(uint8_t*)0x200005ca = 0x2c;
memcpy((void*)0x200005cb, "mpol", 4);
*(uint8_t*)0x200005cf = 0x3d;
memcpy((void*)0x200005d0, "prefer", 6);
memcpy((void*)0x200005d6, "=relative", 9);
*(uint8_t*)0x200005df = 0x3a;
*(uint8_t*)0x200005e0 = 0;
*(uint8_t*)0x200005e1 = 0;
*(uint8_t*)0x200005e2 = 0x2c;
memcpy((void*)0x200005e3, "size", 4);
*(uint8_t*)0x200005e7 = 0x3d;
*(uint8_t*)0x200005e8 = 0x2c;
memcpy((void*)0x200005e9, "huge=within_size", 16);
*(uint8_t*)0x200005f9 = 0x2c;
memcpy((void*)0x200005fa, "nr_blocks", 9);
*(uint8_t*)0x20000603 = 0x3d;
*(uint8_t*)0x20000604 = 0;
*(uint8_t*)0x20000605 = 0;
*(uint8_t*)0x20000606 = 0;
*(uint8_t*)0x20000607 = 0;
*(uint8_t*)0x20000608 = 0x2c;
memcpy((void*)0x20000609, "nr_inodes", 9);
*(uint8_t*)0x20000612 = 0x3d;
*(uint8_t*)0x20000613 = 0;
*(uint8_t*)0x20000614 = 0x2c;
*(uint8_t*)0x20000615 = 0;
syz_mount_image(0x20000040, 0x20000080, 0x14a, 3, 0x200003c0, 0x2062800, 0x200005c0, 0);
	return 0;
}