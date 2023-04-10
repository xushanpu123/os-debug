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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000050 = 0x1d5;
*(uint64_t*)0x20000058 = 0;
*(uint16_t*)0x20000060 = 0;
*(uint8_t*)0x20000062 = 0;
*(uint8_t*)0x20000063 = 0;
*(uint8_t*)0x20000064 = 0;
	syscall(__NR_ioctl, r[0], 0x8911, 0x20000040ul);
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0xf6c;
*(uint64_t*)0x20000290 = 4;
*(uint64_t*)0x20000298 = 1;
memset((void*)0x200002a0, 0, 992);
	syscall(__NR_ioctl, r[0], 0xc400941d, 0x20000280ul);
memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x80\x00\x00\x00\x06\x00\x00\x00\x6a\x00\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x40\x00\x00\x00\x40\x00\x00\x20\x00\x00\x00\xd5\xf4\x65\x5f\xd6\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd5\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01", 90);
*(uint64_t*)0x20000208 = 0x5a;
*(uint64_t*)0x20000210 = 0x401;
*(uint64_t*)0x20000218 = 0x20010100;
memcpy((void*)0x20010100, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x46\xd2\x94\x25\x51\x4b\x1c\x88\x45\x33\x99\x08\xad\x04\x91", 34);
*(uint64_t*)0x20000220 = 0x22;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x20010400;
memcpy((void*)0x20010400, "\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x6a\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x00\xbc\x0f", 32);
*(uint64_t*)0x20000238 = 0x20;
*(uint64_t*)0x20000240 = 0x800;
*(uint64_t*)0x20000248 = 0x20011600;
memcpy((void*)0x20011600, "\xed\x41\x00\x00\x00\x08\x00\x00\xd5\xf4\x65\x5f\xd5\xf4\x65\x5f\xd5\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x04", 29);
*(uint64_t*)0x20000250 = 0x1d;
*(uint64_t*)0x20000258 = 0x2100;
memcpy((void*)0x20000780, "\x20\x4e\x16\x8d\x91\x5f\x9f\x15\xb7\xe8\x95\x8a\x9c\x5a\x05\x88\xb5\xc7\x07\xbf\xd7\x27\x64\x77\x78\x97\x8c\xe8\x24\x57\xd8\x62\x04\xb2\x8a\x4d\x0e\x93\x19\x00\x49\x92\x98\xbf\x00\x00\x00\x00\x00\x00\x07\x00\x00\x00\x00\x00\x00\x00\x00", 59);
syz_mount_image(0x20000000, 0x20000100, 0x40000, 4, 0x20000200, 0, 0x20000780, 0);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000740, "syzkaller0\000\000\000\000\000\000", 16);
memset((void*)0x20000750, 170, 5);
*(uint8_t*)0x20000755 = 0x15;
	syscall(__NR_ioctl, r[1], 0x8916, 0x20000740ul);
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x200000c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200000d0 = 6;
*(uint64_t*)0x200000d8 = 0;
*(uint16_t*)0x200000e0 = 0;
*(uint8_t*)0x200000e2 = 0;
*(uint8_t*)0x200000e3 = 0;
*(uint8_t*)0x200000e4 = 0;
	syscall(__NR_ioctl, r[2], 0x8914, 0x200000c0ul);
	return 0;
}
