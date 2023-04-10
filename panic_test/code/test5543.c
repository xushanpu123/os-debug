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

*(uint64_t*)0x20005c80 = 0;
*(uint32_t*)0x20005c88 = 0;
*(uint64_t*)0x20005c90 = 0;
*(uint64_t*)0x20005c98 = 0;
*(uint64_t*)0x20005ca0 = 0x20003a40;
*(uint64_t*)0x20003a40 = 0x1c;
*(uint32_t*)0x20003a48 = 1;
*(uint32_t*)0x20003a4c = 2;
*(uint32_t*)0x20003a50 = -1;
*(uint32_t*)0x20003a54 = 0;
*(uint32_t*)0x20003a58 = 0xee01;
*(uint64_t*)0x20003a60 = 0x1c;
*(uint32_t*)0x20003a68 = 1;
*(uint32_t*)0x20003a6c = 2;
*(uint32_t*)0x20003a70 = 0;
*(uint32_t*)0x20003a74 = 0xee00;
*(uint32_t*)0x20003a78 = 0;
*(uint64_t*)0x20003a80 = 0x1c;
*(uint32_t*)0x20003a88 = 1;
*(uint32_t*)0x20003a8c = 1;
*(uint32_t*)0x20003a90 = -1;
*(uint32_t*)0x20003a94 = -1;
*(uint32_t*)0x20003a98 = -1;
*(uint64_t*)0x20005ca8 = 0x60;
*(uint32_t*)0x20005cb0 = 0;
*(uint32_t*)0x20005cb8 = 0;
	syscall(__NR_sendmmsg, -1, 0x20005c80ul, 1ul, 0ul);
memcpy((void*)0x200002c0, "nfs\000", 4);
memcpy((void*)0x20000300, "./file0\000", 8);
*(uint64_t*)0x20000400 = 0x20000340;
memcpy((void*)0x20000340, "\x1c\xa6\xb3\x9d\x33\x83\x4a\x84\x92\x61\x13\x14\x18\xa8\xd7\x15\x3b\x0f\xd8\xd2\x75\x80\x35\x17\xf5\x17\xac\x95\xe9\x02\x57\x1b\x2b\xc6\x59\xa4\x9b\x02\xe0\xd0\x95\x6b\x18\x8d\xee\x6d\xac\xca\xb4\x7f\x83\xa2\x27\x25\x17\xec\x2f\x9d\xc0\x54\x3a\x1a\x38\x23\x58\x72\x0d\x7b\xe2\x96\x9e\x93\xd1\xd7\xd7\xa8\xf2\x5b\x6b\xcd\xcb\xeb\x60\x4e\x94\x61\x97\x64\x7b\x34\x36\xf1\x45\x68\xcd\x89\x20\x00\xbf\xf9\x28\x67\xba\x9a\x4b\x12\x6c\x27\x5c\x64\xed\x68\xfc\xa7\x29\x43\x2c\x50\xdc\x83\xa7\x08\x8c\xcc\xb5\xa4\x28\xc7\xff\x4d\x28\xba\xb8\x23\x49\x39\x50\x7e\x1e\x0b\x1c\x73\x15\x8b\xc4\x4c\x45\x33\xb9\x3a\xd3\x82\x2f\x43\x40\x76\x96\x5c\x83\x33\x70\x12\x1c\x3f\xc0\xda\x17\x04\xaf\x91", 170);
*(uint64_t*)0x20000408 = 0xaa;
*(uint64_t*)0x20000410 = 0x81;
memset((void*)0x200005c0, 33, 1);
*(uint8_t*)0x200005c1 = 0x2c;
memcpy((void*)0x200005c2, "tmpfs\000", 6);
*(uint8_t*)0x200005c8 = 0x2c;
memcpy((void*)0x200005c9, "uid", 3);
*(uint8_t*)0x200005cc = 0x3d;
sprintf((char*)0x200005cd, "%020llu", (long long)0);
*(uint8_t*)0x200005e1 = 0x2c;
memcpy((void*)0x200005e2, "rootcontext", 11);
*(uint8_t*)0x200005ed = 0x3d;
memcpy((void*)0x200005ee, "root", 4);
*(uint8_t*)0x200005f2 = 0x2c;
memcpy((void*)0x200005f3, "fsmagic", 7);
*(uint8_t*)0x200005fa = 0x3d;
sprintf((char*)0x200005fb, "0x%016llx", (long long)0);
*(uint8_t*)0x2000060d = 0x2c;
*(uint8_t*)0x2000060e = 0;
syz_mount_image(0x200002c0, 0x20000300, 0x12b, 1, 0x20000400, 0x840, 0x200005c0, 0);
	return 0;
}
