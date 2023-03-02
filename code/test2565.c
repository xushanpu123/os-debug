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

memcpy((void*)0x20000000, "iso9660\000", 8);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x01\x43\x44\x30\x30\x31\x01\x00\x4c\x49\x4e\x55\x58\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x43\x44\x52\x4f\x4d\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x00\x00\x00\x00\x00\x00\x00\x00\xb7\x00\x00\x00\x00\x00\x00\xb7\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x01\x01\x00\x00\x01\x00\x08\x08\x00\x18\x00\x00\x00\x00\x00\x00\x18\x13\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x15\x00\x00\x00\x00\x22\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x47\x45\x4e\x49\x53\x4f\x49\x4d\x41\x47\x45\x20\x49\x53\x4f\x20\x39\x36\x36\x30\x2f\x48\x46\x53\x20\x46\x49\x4c\x45\x53\x59\x53\x54\x45\x4d\x20\x43\x52\x45\x41\x54\x4f\x52\x20\x28\x43\x29\x20\x31\x39\x39\x33\x20\x45\x2e\x59\x4f\x55\x4e\x47\x44\x41\x4c\x45\x20\x28\x43\x29\x20\x31\x39\x39\x37\x2d\x32\x30\x30\x36\x20\x4a\x2e\x50\x45\x41\x52\x53\x4f\x4e\x2f\x4a\x2e\x53\x43\x48\x49\x4c\x4c\x49\x4e\x47\x20\x28\x43\x29\x20\x32\x30\x30\x36\x2d\x32\x30\x30\x37\x20\x43\x44\x52\x4b\x49\x54\x20\x54\x45\x41\x4d\x20\x20\x66\x69\x6c\x65\x33\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x31\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x32\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x00\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x01\x00\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 1408);
*(uint64_t*)0x20000208 = 0x580;
*(uint64_t*)0x20000210 = 0x8000;
*(uint64_t*)0x20000218 = 0x20010580;
memcpy((void*)0x20010580, "\xff\x43\x44\x30\x30\x31\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000220 = 0x20;
*(uint64_t*)0x20000228 = 0x8800;
*(uint64_t*)0x20000230 = 0x200105a0;
memcpy((void*)0x200105a0, "\x01\x00\x17\x00\x00\x00\x01\x00\x00\x00\x05\x00\x18\x00\x00\x00\x01\x00\x46\x49\x4c\x45\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000238 = 0x20;
*(uint64_t*)0x20000240 = 0x9800;
*(uint64_t*)0x20000248 = 0x200105c0;
memcpy((void*)0x200105c0, "\x01\x00\x00\x00\x00\x17\x00\x01\x00\x00\x05\x00\x00\x00\x00\x18\x00\x01\x46\x49\x4c\x45\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0xa800;
*(uint64_t*)0x20000260 = 0x200105e0;
memcpy((void*)0x200105e0, "\x22\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x22\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x01\x2c\x00\x19\x00\x00\x00\x00\x00\x00\x19\x64\x00\x00\x00\x00\x00\x00\x64\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x0a\x46\x49\x4c\x45\x2e\x43\x4f\x4c\x3b\x31\x00\x26\x00\x18\x00\x00\x00\x00\x00\x00\x18\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x05\x46\x49\x4c\x45\x30\x2a\x00\x1a\x00\x00\x00\x00\x00\x00\x1a\x0a\x00\x00\x00\x00\x00\x00\x0a\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x31\x2e\x3b\x31\x00\x2a\x00\x1b\x00\x00\x00\x00\x00\x00\x1b\x28\x23\x00\x00\x00\x00\x23\x28\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x32\x2e\x3b\x31\x00\x2a\x00\x1b\x00\x00\x00\x00\x00\x00\x1b\x28\x23\x00\x00\x00\x00\x23\x28\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x33\x2e\x3b\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 288);
*(uint64_t*)0x20000268 = 0x120;
*(uint64_t*)0x20000270 = 0xb800;
*(uint64_t*)0x20000278 = 0x20010700;
memcpy((void*)0x20010700, "\x22\x00\x18\x00\x00\x00\x00\x00\x00\x18\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x22\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x01\x2a\x00\x20\x00\x00\x00\x00\x00\x00\x20\x1a\x04\x00\x00\x00\x00\x04\x1a\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x30\x2e\x3b\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 128);
*(uint64_t*)0x20000280 = 0x80;
*(uint64_t*)0x20000288 = 0xc000;
*(uint64_t*)0x20000290 = 0x20010780;
memcpy((void*)0x20010780, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x20000298 = 0x80;
*(uint64_t*)0x200002a0 = 0xc800;
*(uint64_t*)0x200002a8 = 0x20010800;
memcpy((void*)0x20010800, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200002b0 = 0x20;
*(uint64_t*)0x200002b8 = 0xd000;
*(uint64_t*)0x200002c0 = 0x20010820;
memcpy((void*)0x20010820, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkal\000\000\000\000\000\000", 1056);
*(uint64_t*)0x200002c8 = 0x420;
*(uint64_t*)0x200002d0 = 0x10000;
*(uint8_t*)0x20010c40 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x5b800, 9, 0x20000200, 0, 0x20010c40, 1);
	return 0;
}
