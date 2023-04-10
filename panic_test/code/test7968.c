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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_utimensat, -1, 0ul, 0ul, 0ul);
memcpy((void*)0x20000000, "msdos\000", 6);
memcpy((void*)0x20000040, "./file0\000", 8);
*(uint64_t*)0x20000280 = 0x200001c0;
memcpy((void*)0x200001c0, "\x7c\x23\x2e\x0a\xd3\xbe\x83\x22\x6a\x70\x18\x1d\x33\xeb\x1c\x36\xbb\xf9\xbe\xb1\x6a\x90\x94\x16\xd1\x49\x2d\x44\xb9\xc7\x88\xe4\x61\x11\x9a\x57\xf1\xdd\x60\x57\xd0\x06\x83\x1a\x23\xe2\x38\x77\x4d\x20\x7e\x1c\xd8\xcb\x39\x5a\xee\xcf\x52\x8e\x72\x78\x11\x88\x7f\x1a\xd9\xf2\x4e\xb7\xea\x57\x18\xb9\x39\x49\xf8\xa5\x38\xce\xff\x43\x94\x10\xfc\xdb\x4e\xba\x19\x4f\xcd\x32\x1c\x55\x8b\xd2\x86\x51\x13\x7c\xd1\x41\xee\x08\x76\x1c\x56\xd1\x99\x78\xc1\x3b", 112);
*(uint64_t*)0x20000288 = 0x70;
*(uint64_t*)0x20000290 = 0x20;
*(uint64_t*)0x20000298 = 0x200000c0;
memcpy((void*)0x200000c0, "\xbd\x3e\x8a\xcf\x27\x19\x83\x08\x5f\x05\xc5\xf3\xfe\x9c\xa4\xda\xba\xde\xd0\x60\x13\x03\x1e\x31\x4a\x0e\xfe\xd3\xda\x1a\xc1\x61\x47\x45\x68\xcc\x39\x54\x15\x84\x9b\xa7\x52\xa8\xc1\x59\xbf\x18\x13\x32\xb9\x68\x86\x44\x78\xd1\x65\xc2\x97\x34\x83\x2e\x8c\xb5\xc8\xc5\xb3\x62\xe8\x70\x05\x16\xc0\x9f\x41\x26\xdb\xc3\x32\x90\xbf\xee\xac\x93\x8d\x46\xbe\x28\x46\xa4\x1e\x24\x57\x5c\x29\xf6\xc8\x25\x18\xf9\x46\x83\xac\x70\x81\xfd\xa6\x85\x93\x82\xcc\xf7\x36\x6b\xb7\x47\xdd\x92\xdd\x31\x1f\x44\xf2\x77\xc1\xed\x38\xef\x1e\x52\x99\xa6\xc8\x4b\x8b\xce\x21\x6f\xa0\x82\x64\x1a\xfb\x06\xee\x52\x23\x59\xac\xfd\xf8\x84\xb6\xb7\x79\x4d\xa0\x2b\xf0\xd0\xab\x06\x91\x14\x93\x24\x35\x96\x44\x8e\x65\xb3\xd8\x2f\x04\xba\x0f\xbe\x90\xf1\xe0\x88\x50\x52\xba\x09\x2b\x4e\x96\xcc\x4b\x2d\xbc\x28\x8f\x01\xc2\x5d\xe6\x37\x5b\x13\x42\xa7\xa0\xc0\xb5\xbd\x4e", 209);
*(uint64_t*)0x200002a0 = 0xd1;
*(uint64_t*)0x200002a8 = 0xbe;
*(uint64_t*)0x200002b0 = 0x20000240;
memcpy((void*)0x20000240, "\xef\x3d\x68\xa2\xd2\x7e\xfc\x14\xec\x5c\x4b\xff\x69\x42\xf6\xb0\x7e\x5e\xd9\x1b", 20);
*(uint64_t*)0x200002b8 = 0x14;
*(uint64_t*)0x200002c0 = 0xa8d;
*(uint64_t*)0x200002c8 = 0x20000080;
memcpy((void*)0x20000080, "\x22\xb5\x13\xf4\xc6\xf1\xb5\xf3", 8);
*(uint64_t*)0x200002d0 = 8;
*(uint64_t*)0x200002d8 = 0x10001;
memcpy((void*)0x20000300, "\x6e\x6f\x64\x6f\x74\x73\x2c\x63\x68\x65\x63\x0a\x00\x6e\x6f\x72\x6d\x61\x6c\x2c\x68\x61\x73\x68\x2c\x66\x73\x6d\x61\x49\xf1\xcc\x67\x69\x63\x3d\x30\x78\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x2c\x70\x65\x72\x6d\x69\x74\x5f\x64\x69\x72\x65\x63\x74\x69", 69);
	res = -1;
res = syz_mount_image(0x20000000, 0x20000040, 0x10009, 4, 0x20000280, 0x40, 0x20000300, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000380, "./file0\000", 8);
memcpy((void*)0x200003c0, "./file0\000", 8);
	syscall(__NR_renameat, r[0], 0x20000380ul, 0xffffff9c, 0x200003c0ul);
*(uint32_t*)0x20000400 = 1;
*(uint32_t*)0x20000404 = 0;
memcpy((void*)0x20000408, "\x3e\xd4\xa7\x87\x99\x6f\x34\x13", 8);
memset((void*)0x20000410, 0, 24);
memset((void*)0x2000042c, 0, 20);
	syscall(__NR_ioctl, -1, 0xc0406619, 0x20000400ul);
memcpy((void*)0x20000440, "./cgroup.net/syz0\000", 18);
	syscall(__NR_mkdirat, 0xffffffffffffff9cul, 0x20000440ul, 0x1fful);
	return 0;
}