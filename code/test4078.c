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

memcpy((void*)0x20000000, "vfat\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000040 = 0x20010000;
memcpy((void*)0x20010000, "\xeb\x3c\x90\x6d\x6b\x66\xcd\x73\x2e\x66\x61\x74\x00\x02\x01\x01\x00\x02\x40\x00\x80\x00\xf8\x01\x00\x10\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x00\x29\x1d\x03\x98\xf6\x53\x59\x5a\x4b\x41\x4c\x4c\x45\x52\x20\x20\x46\x41\x3c\x00\x00\x00\x20\x20\x0e\x1f\xbe\x5b\x7c\xac\x22\xc0\x74\x0b\x56\xb4\x0e\xbb\x07\x00\xcd\x10\x5e\xeb\xf0\x32\xe4\xcd\x16\xcd\x19\xeb\xfe\x54\x68\x69\x73\x20\x69\x73\x20\x6e\x6f\x74\x20\x61\x20\x62\x6f\x6f\x74\x61\x62\x6c\x65\x20\x64\x69\x73\x6b\x2e\x20\x20\x50\x6c\x65\x61\x73\x65\x20\x69\x6e\x73\x65\x72\x74\x20\x61\x20\x62\x6f\x6f\x2b\x61\x62\x6c\x65\x20\x66\x6c\x6f\x70\x70\x79\x20\x61\x6e\x64\x0d\x0a\x70\x72\x65\x73\x73\x20\x61\x6e\x79\x20\x6b\x65\x79\x20\x74\x6f\x20\x74\xae\x79\x20\x61\x67\x61\x69\x6e\x20\x2e\x2e\x2e\x20\x0d\x0a", 192);
*(uint64_t*)0x20000048 = 0xc0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0x20010120;
memcpy((void*)0x20010120, "\xf8\xff\xff\x00\xf0\xff\x05\x60\x00\xff\xff\xff\x09\xa0\x00\x0b\xc0\x00\x0d\xe0\x00\x0f\x00\x01\x11\x20\x01\x13\x40\x01\x15\x60\x01\x17\x80\x01\x19\xf0\xff\xff\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000060 = 0x40;
*(uint64_t*)0x20000068 = 0x400;
*(uint64_t*)0x20000070 = 0x20010160;
memcpy((void*)0x20010160, "\x53\x59\x5a\x4b\x41\x4c\x4c\x45\x52\x20\x20\x08\x00\x00\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x00\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x30\x00\x0f\x00\xfc\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x30\x20\x20\x20\x20\x20\x20\x10\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x03\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x31\x00\x0f\x00\x10\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x31\x20\x20\x20\x20\x20\x20\x20\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x07\x00\x0a\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x32\x00\x0f\x00\x14\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x32\x20\x20\x20\x20\x20\x20\x20\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x08\x00\x28\x23\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x2e\x00\x0f\x00\xd2\x63\x00\x6f\x00\x6c\x00\x64\x00\x00\x00\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x7e\x31\x20\x20\x43\x4f\x4c\x20\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x1a\x00\x64\x00\x00\x00", 288);
*(uint64_t*)0x20000078 = 0x120;
*(uint64_t*)0x20000080 = 0x600;
*(uint64_t*)0x20000088 = 0x20010280;
memcpy((void*)0x20010280, "\x2e\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x10\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x03\x00\x00\x00\x00\x00\x2e\x2e\x20\x20\x20\x20\x20\x20\x20\x20\x20\x10\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x00\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x30\x00\x0f\x00\xfc\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x30\x20\x20\x20\x20\x20\x20\x20\x00\xa3\x14\x60\x2c\x55\x2c\x55\x00\x00\x14\x60\x2c\x55\x04\x00\x1a\x04\x00\x00", 128);
*(uint64_t*)0x20000090 = 0x80;
*(uint64_t*)0x20000098 = 0xfff;
*(uint64_t*)0x200000a0 = 0x20010300;
memcpy((void*)0x20010300, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkal\000\000\000\000\000\000", 1056);
*(uint64_t*)0x200000a8 = 0x420;
*(uint64_t*)0x200000b0 = 0x1200;
*(uint64_t*)0x200000b8 = 0x20010720;
memcpy((void*)0x20010720, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200000c0 = 0x20;
*(uint64_t*)0x200000c8 = 0x1800;
*(uint64_t*)0x200000d0 = 0x20010740;
memcpy((void*)0x20010740, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x200000d8 = 0x80;
*(uint64_t*)0x200000e0 = 0x3e00;
*(uint8_t*)0x200107c0 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x10000, 7, 0x20000040, 0, 0x200107c0, 1);
	return 0;
}
