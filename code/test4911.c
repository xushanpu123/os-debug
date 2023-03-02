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
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x02\x00\x00\x19\x00\x00\x00\x90\x01\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x05\x00\x00\x00\x00\x00\x04\x00\x00\x40\x00\x00\x20\x00\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x00\x00\x18\x00\x00\x00\xc2\x85\x00\x00\x2b\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x00\x00\x00\x00\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x31\x32\x30\x30\x30\x38\x30\x31\x37\x36\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000208 = 0xc0;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x200100c0;
memcpy((void*)0x200100c0, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x40\x62\x73\x87\x23\xb8\x4f\x25\xbf\xab\xe4\x86\x19\xdd\xb7\xb1\x01\x00\x40\x00\x0c\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000220 = 0x40;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x20010100;
memcpy((void*)0x20010100, "\x00\xf0\x44\x72\xb0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x20\x00\x01\x00\x00\x00\x00\x00\x05\x00\x40\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x43\x00\x00\x00", 64);
*(uint64_t*)0x20000238 = 0x40;
*(uint64_t*)0x20000240 = 0x540;
*(uint64_t*)0x20000248 = 0x20010160;
memcpy((void*)0x20010160, "\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x19\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x800;
*(uint64_t*)0x20000260 = 0x200008c0;
memcpy((void*)0x200008c0, "\x7f\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xbf\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xe7\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x04\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfc\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x01\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x82\x28\xb5\x0e\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x63\x3f\x06\xc3\xe5\x4b\xd5\x50\x4e\x54\x82\xb1\x4d\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfd\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xf7\xee\xe2\x2f\x41\xf4\x30\x79\xe0\xdc\x77\x30\x93\x15\x03\xc5\x54\xec\x2e\xd4\xf9\x25\x6a\xd5\xf0\x61\x16\x4a\x9a\x86\xa7\x94\x6d\xd6\x25\x8c\x22\x85\xa0\xa0\xe1\x28\xe9\xf9\xc1\xab\xb0\x9e\x37\x9c\x46\x65\x52\x3c\x38\xc3\x6b\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\xcf\x37\x86\xd4\xc7\xc3\x5f\x6c\x2a\xfa\xfc\x70\x05\x5f\x00\x00\x00\x00", 4214);
*(uint64_t*)0x20000268 = 0x1076;
*(uint64_t*)0x20000270 = 0x1000;
*(uint64_t*)0x20000278 = 0x200111a0;
memcpy((void*)0x200111a0, "\xed\x41\x00\x00\x00\x08\x00\x00\x71\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x04\x00\x40\x00\x00\x00\x00\x00\x08\x00\x05\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x10\x00\x00\x00", 64);
*(uint64_t*)0x20000280 = 0x40;
*(uint64_t*)0x20000288 = 0x2100;
*(uint64_t*)0x20000290 = 0x200111e0;
memcpy((void*)0x200111e0, "\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000298 = 0x20;
*(uint64_t*)0x200002a0 = 0x2180;
*(uint64_t*)0x200002a8 = 0x20011200;
memcpy((void*)0x20011200, "\x80\x81\x00\x00\x00\x60\x10\x20\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x200002b0 = 0xa0;
*(uint64_t*)0x200002b8 = 0x2600;
*(uint64_t*)0x200002c0 = 0x20001940;
memcpy((void*)0x20001940, "\xc0\x41\x00\x00\x00\x38\x00\x00\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x71\x1f\x1f\x63\x00\x00\x1f\x00\x00\x00\x00\x00\x40\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x1b\x4c\x96\xcb\xef\x21\x43\x23\x45\xb1\xe7\x47\x62\x81\x0a\xf3\x01\x00\x04\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x07\x00\x00\x00\x20\x00\x00\x00\xf2\xe1\x72\xbf\x88\x0e\xe1\x14\x03\xc4\x23\x3b\x19\x79\xd7\xa1\x31\x12\x17\xbf\x6b\x22\x09\x39\xe8\x1d\xa1\x49\xbc\x26\xbc\xac\x74\xb4\xa0\x49\x0a\xb2\x00\x4b\xfd\x51\xe6\x51\x9f\x2b\xf3\xc8\x60\x1a", 128);
*(uint64_t*)0x200002c8 = 0x80;
*(uint64_t*)0x200002d0 = 0x2a00;
*(uint64_t*)0x200002d8 = 0x200112e0;
memcpy((void*)0x200112e0, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x71\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x200002e0 = 0x40;
*(uint64_t*)0x200002e8 = 0x2a80;
*(uint64_t*)0x200002f0 = 0x20011320;
memcpy((void*)0x20011320, "\xed\x41\x00\x00\x3c\x00\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x10\x03\x00\x00\x00\x02\x00\x00\x00\x0d\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x30\x00\x00\x00\x0e\x00\x00\x00\x28\x00\x05\x07\x66\x69\x6c\x65\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x6a\x25\x5d\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x200002f8 = 0xc0;
*(uint64_t*)0x20000300 = 0x2b00;
*(uint64_t*)0x20000308 = 0x200113e0;
memcpy((void*)0x200113e0, "\xed\x81\x00\x00\x1a\x04\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x50\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x36\xca\xd9\xae\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000310 = 0xa0;
*(uint64_t*)0x20000318 = 0x2c04;
*(uint64_t*)0x20000320 = 0x20011480;
memcpy((void*)0x20011480, "\xff\xa1\x00\x00\x27\x00\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x31\x32\x30\x30\x30\x38\x30\x31\x37\x36\x2f\x66\x69\x6c\x65\x30\x2f\x66\x69\x6c\x65\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xf2\xa9\x95\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000328 = 0xa0;
*(uint64_t*)0x20000330 = 0x2d00;
*(uint64_t*)0x20000338 = 0x20011520;
memcpy((void*)0x20011520, "\xed\x81\x00\x00\x0a\x00\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x10\x01\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xcf\xef\x42\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x06\x01\x54\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\x06\x01\x4c\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\xed\x81\x00\x00\x28\x23\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x40\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x60\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x46\x45\x50\xe4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00", 416);
*(uint64_t*)0x20000340 = 0x1a0;
*(uint64_t*)0x20000348 = 0x2dfd;
*(uint64_t*)0x20000350 = 0x200116c0;
memcpy((void*)0x200116c0, "\xed\x81\x00\x00\x64\x00\x00\x00\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x73\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x10\x01\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x10\x04\x95\x47\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x04\xed\x65\xde\x04\xed\x65\xde\x04\xed\x65\xde\x73\x1f\x1f\x63\x04\xed\x65\xde\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x34\x00\x00\x00\x00\x00\x28\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73", 256);
*(uint64_t*)0x20000358 = 0x100;
*(uint64_t*)0x20000360 = 0x3000;
*(uint64_t*)0x20000368 = 0x200117c0;
memcpy((void*)0x200117c0, "\x02\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x0b\x00\x00\x00\x14\x00\x0a\x02\x6c\x6f\x73\x74\x2b\x66\x6f\x75\x6e\x64\x00\x00\x0c\x00\x00\x00\x10\x00\x05\x02\x66\x69\x6c\x65\x30\x00\x00\x00\x0f\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x31\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x32\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x33\x00\x00\x00\x11\x00\x00\x00\x94\x07\x09\x01\x66\x69\x6c\x65\x2e\x63\x6f\x6c\x64\x00\x00\x00", 128);
*(uint64_t*)0x20000370 = 0x80;
*(uint64_t*)0x20000378 = 0x8000;
*(uint64_t*)0x20000380 = 0x20011840;
memcpy((void*)0x20011840, "\x0b\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x00\x00\x00\x00\xe8\x07\x00\x00", 32);
*(uint64_t*)0x20000388 = 0x20;
*(uint64_t*)0x20000390 = 0x10000;
*(uint64_t*)0x20000398 = 0x20011860;
memcpy((void*)0x20011860, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200003a0 = 0x20;
*(uint64_t*)0x200003a8 = 0x10800;
*(uint64_t*)0x200003b0 = 0x20011880;
memcpy((void*)0x20011880, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200003b8 = 0x20;
*(uint64_t*)0x200003c0 = 0x11000;
*(uint64_t*)0x200003c8 = 0x200118a0;
memcpy((void*)0x200118a0, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200003d0 = 0x20;
*(uint64_t*)0x200003d8 = 0x11800;
*(uint64_t*)0x200003e0 = 0x200118c0;
memcpy((void*)0x200118c0, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200003e8 = 0x20;
*(uint64_t*)0x200003f0 = 0x12000;
*(uint64_t*)0x200003f8 = 0x200118e0;
memcpy((void*)0x200118e0, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000400 = 0x20;
*(uint64_t*)0x20000408 = 0x12800;
*(uint64_t*)0x20000410 = 0x20011900;
memcpy((void*)0x20011900, "\000\000\000\000\000\b\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000418 = 0x20;
*(uint64_t*)0x20000420 = 0x13000;
*(uint64_t*)0x20000428 = 0x20000140;
memcpy((void*)0x20000140, "\x50\x4d\x4d\x00\x50\x4d\x4d\xff\x73\x00\x00\x63\x00\x00\x00\x00\x68\x72\x75\x74\x76\x69\x6b\x2e\x63\x2e\x67\x6f\x6f\x67\x6c\x65\x72\x73\x2e\x63\x6f\x6d\x00\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x39\x1f\x4a\xfc\x4e\xa1\xfb\x20\xce\x8f\xad\x05\x00\x6c\x6f\x6f\x70\x31\x36\x00\x75\x78\x2f\x74\x65\x73\x74\x2f\x73\x79\x7a\x5f\x6d\x6f\x75\x6e\x74\x5f\x69\x6d\x61\x67\x65\x5f\x65\x05\x00\x00\x3f\x14\x7e\x5f\xe7\xf3\x87\x1c\x33\x00", 137);
*(uint64_t*)0x20000430 = 0x89;
*(uint64_t*)0x20000438 = 0x20000;
*(uint64_t*)0x20000440 = 0x20000480;
memcpy((void*)0x20000480, "\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x4b\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x04\x00\xf0\xdb\xa2\x9c\x2e\x25\xa0\xd3\x89\x31\xe9\xff\x37\x61\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x53\xee\x84\x48\x03\x45\x8b\x67\x99\x2b\x7f\xe3\x6e\x10\xbf\x1d\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61", 1065);
*(uint64_t*)0x20000448 = 0x429;
*(uint64_t*)0x20000450 = 0x28000;
*(uint8_t*)0x20011dc0 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x100000, 0x19, 0x20000200, 0, 0x20011dc0, 1);
	return 0;
}
