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
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x60\x1c\x6d\x6b\x64\x6f\x73\x66\xf7\x42\xdd\x00\x08\x40\x01\x00\x04\x40\x00\x00\x02\xf8\x01\x00\x10\x00\x02\x00\x03\x00\x00\x00\x00\x00\x00\x00\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000208 = 0x40;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0x20010040;
memcpy((void*)0x20010040, "\xf8\xff\xff\x00\xf0\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000220 = 0x20;
*(uint64_t*)0x20000228 = 0x800;
*(uint64_t*)0x20000230 = 0x20010060;
memcpy((void*)0x20010060, "\xf8\xff\xff\x00\xf0\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000238 = 0x20;
*(uint64_t*)0x20000240 = 0x1000;
*(uint64_t*)0x20000248 = 0x20010080;
memcpy((void*)0x20010080, "\xf8\xff\xff\x00\xf0\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x1800;
*(uint64_t*)0x20000260 = 0x200100a0;
memcpy((void*)0x200100a0, "\xf8\xff\xff\x00\xf0\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000268 = 0x20;
*(uint64_t*)0x20000270 = 0x2000;
*(uint64_t*)0x20000278 = 0x200100c0;
memcpy((void*)0x200100c0, "\x53\x59\x5a\x4b\x41\x4c\x4c\x45\x52\x20\x20\x08\x00\x00\x16\x60\x2c\x55\x2c\x55\x00\x00\x16\x60\x2c\x55\x00\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x30\x00\x0f\x00\xfc\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x30\x20\x20\x20\x20\x20\x20\x10\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x03\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x31\x00\x0f\x00\x10\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x31\x20\x20\x20\x20\x20\x20\x20\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x05\x00\x0a\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x32\x00\x0f\x00\x14\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x32\x20\x20\x20\x20\x20\x20\x20\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x06\x00\x28\x23\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x2e\x00\x0f\x00\xd2\x63\x00\x6f\x00\x6c\x00\x64\x00\x00\x00\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x7e\x31\x20\x20\x43\x4f\x4c\x20\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x07\x00\x64\x00\x00\x00", 288);
*(uint64_t*)0x20000280 = 0x120;
*(uint64_t*)0x20000288 = 0x2800;
*(uint64_t*)0x20000290 = 0x200101e0;
memcpy((void*)0x200101e0, "\x2e\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x10\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x03\x00\x00\x00\x00\x00\x2e\x2e\x20\x20\x20\x20\x20\x20\x20\x20\x20\x10\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x00\x00\x00\x00\x00\x00\x41\x66\x00\x69\x00\x6c\x00\x65\x00\x30\x00\x0f\x00\xfc\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\x46\x49\x4c\x45\x30\x20\x20\x20\x20\x20\x20\x20\x00\x03\x17\x60\x2c\x55\x2c\x55\x00\x00\x17\x60\x2c\x55\x04\x00\x1a\x04\x00\x00", 128);
*(uint64_t*)0x20000298 = 0x80;
*(uint64_t*)0x200002a0 = 0x23000;
*(uint64_t*)0x200002a8 = 0x20010260;
memcpy((void*)0x20010260, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkal\000\000\000\000\000\000", 1056);
*(uint64_t*)0x200002b0 = 0x420;
*(uint64_t*)0x200002b8 = 0x43000;
*(uint64_t*)0x200002c0 = 0x20010680;
memcpy((void*)0x20010680, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200002c8 = 0x20;
*(uint64_t*)0x200002d0 = 0x63000;
*(uint64_t*)0x200002d8 = 0x200106a0;
memcpy((void*)0x200106a0, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x200002e0 = 0x80;
*(uint64_t*)0x200002e8 = 0xa3000;
*(uint8_t*)0x20010720 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x100000, 0xa, 0x20000200, 0, 0x20010720, 1);
	return 0;
}
