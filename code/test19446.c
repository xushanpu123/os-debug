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
memcpy((void*)0x200003c0, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x02\x00\x00\x19\x00\x00\x00\x60\x01\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x02\x00\x00\x20\x00\x00\x20\x00\x00\x00\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x00\x00\x08\x00\x00\x00\xd2\x42\x00\x00\x12\x03", 102);
*(uint64_t*)0x20000208 = 0x66;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010100;
memcpy((void*)0x20010100, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xde\xf3\x61\xb1\x16\xdd\x4b\xb6\x81\x39\x19\x64\xcc\xf0\x77\xda\x01\x00\x40", 31);
*(uint64_t*)0x20000220 = 0x1f;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x200001c0;
memset((void*)0x200001c0, 3, 1);
*(uint64_t*)0x20000238 = 1;
*(uint64_t*)0x20000240 = 0x640;
*(uint64_t*)0x20000248 = 0x20010400;
memcpy((void*)0x20010400, "\x03\x00\x00\x00\x04\x00\x00\x00\x05\x00\x00\x00\x16\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x00\x69\x8c", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x800;
*(uint64_t*)0x20000260 = 0x20010e00;
memcpy((void*)0x20010e00, "\xed\x41\x00\x00\x00\x04\x00\x00\xd0\xf4\x65\x5f\xd2\xf4\x65\x5f\xd2\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x20", 29);
*(uint64_t*)0x20000268 = 0x1d;
*(uint64_t*)0x20000270 = 0x1500;
*(uint64_t*)0x20000278 = 0x20011000;
memcpy((void*)0x20011000, "\x80\x81\x00\x00\x00\x18\x00\x00\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\xd0\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x02\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x30\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x32", 73);
*(uint64_t*)0x20000280 = 0x49;
*(uint64_t*)0x20000288 = 0x1600;
*(uint64_t*)0x20000290 = 0x20012700;
memcpy((void*)0x20012700, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06", 21);
*(uint64_t*)0x20000298 = 0x15;
*(uint64_t*)0x200002a0 = 0xc000;
*(uint64_t*)0x200002a8 = 0x20012800;
memset((void*)0x20012800, 2, 1);
*(uint64_t*)0x200002b0 = 1;
*(uint64_t*)0x200002b8 = 0xc400;
*(uint64_t*)0x200002c0 = 0x20000080;
memset((void*)0x20000080, 3, 1);
*(uint64_t*)0x200002c8 = 1;
*(uint64_t*)0x200002d0 = 0xc800;
*(uint64_t*)0x200002d8 = 0x20012a00;
memset((void*)0x20012a00, 4, 1);
*(uint64_t*)0x200002e0 = 1;
*(uint64_t*)0x200002e8 = 0xcc00;
*(uint64_t*)0x200002f0 = 0x20012b00;
memset((void*)0x20012b00, 5, 1);
*(uint64_t*)0x200002f8 = 1;
*(uint64_t*)0x20000300 = 0xd000;
*(uint64_t*)0x20000308 = 0x20012c00;
memcpy((void*)0x20012c00, "\x00\x00\x00\xd2\x4b\x00\x00\x00\x01\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\xf2", 23);
*(uint64_t*)0x20000310 = 0x17;
*(uint64_t*)0x20000318 = 0xd400;
syz_mount_image(0x200003c0, 0x20000100, 0xd417, 0xc, 0x20000200, 0, 0x20000040, 0);
memcpy((void*)0x20000100, "./file0\000", 8);
	res = syscall(__NR_newfstatat, 0xffffffffffffff9cul, 0x20000100ul, 0x200002c0ul, 0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x200002d8;
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_lchown, 0x20000000ul, r[0], 0);
	return 0;
}
