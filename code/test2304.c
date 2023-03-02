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
memcpy((void*)0x20010000, "\x01\x43\x44\x30\x30\x31\x01\x00\x4c\x49\x4e\x55\x58\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x43\x44\x52\x4f\x4d\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x00\x00\x00\x00\x00\x00\x00\x00\xb8\x00\x00\x00\x00\x00\x00\xb8\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x01\x01\x00\x00\x01\x00\x08\x08\x00\x18\x00\x00\x00\x00\x00\x00\x18\x13\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x15\x00\x00\x00\x00\x22\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x47\x45\x4e\x49\x53\x4f\x49\x4d\x41\x47\x45\x20\x49\x53\x4f\x20\x39\x36\x36\x30\x2f\x48\x46\x53\x20\x46\x49\x4c\x45\x53\x59\x53\x54\x45\x4d\x20\x43\x52\x45\x41\x54\x4f\x52\x20\x28\x43\x29\x20\x31\x39\x39\x33\x20\x45\x2e\x59\x4f\x55\x4e\x47\x44\x41\x4c\x45\x20\x28\x43\x29\x20\x31\x39\x39\x37\x2d\x32\x30\x30\x36\x20\x4a\x2e\x50\x45\x41\x52\x53\x4f\x4e\x2f\x4a\x2e\x53\x43\x48\x49\x4c\x4c\x49\x4e\x47\x20\x28\x43\x29\x20\x32\x30\x30\x36\x2d\x32\x30\x30\x37\x20\x43\x44\x52\x4b\x49\x54\x20\x54\x45\x41\x4d\x20\x20\x66\x69\x6c\x65\x33\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x31\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x32\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x30\x00\x32\x30\x32\x32\x30\x39\x31\x32\x31\x32\x30\x30\x35\x38\x30\x30\x00\x01\x00\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 1408);
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
memcpy((void*)0x200105e0, "\x88\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x53\x50\x07\x01\xbe\x04\x00\x52\x52\x05\x01\x81\x50\x58\x24\x01\x6d\x41\x00\x00\x00\x00\x41\x6d\x03\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x43\x45\x1c\x01\x19\x00\x00\x00\x00\x00\x00\x19\x00\x00\x00\x00\x00\x00\x00\x00\xed\x00\x00\x00\x00\x00\x00\xed\x66\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x01\x52\x52\x05\x01\x81\x50\x58\x24\x01\x6d\x41\x00\x00\x00\x00\x41\x6d\x03\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1a\x00\x00\x00\x00\x00\x00\x1a\x64\x00\x00\x00\x00\x00\x00\x64\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x0a\x46\x49\x4c\x45\x2e\x43\x4f\x4c\x3b\x31\x00\x41\x41\x0e\x02\x54\x45\x58\x54\x75\x6e\x69\x78\x00\x00\x52\x52\x05\x01\x89\x4e\x4d\x0e\x01\x00\x66\x69\x6c\x65\x2e\x63\x6f\x6c\x64\x50\x58\x24\x01\x6d\x81\x00\x00\x00\x00\x81\x6d\x01\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x74\x00\x18\x00\x00\x00\x00\x00\x00\x18\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x05\x46\x49\x4c\x45\x30\x52\x52\x05\x01\x89\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x30\x50\x58\x24\x01\x6d\x41\x00\x00\x00\x00\x41\x6d\x02\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x86\x00\x1b\x00\x00\x00\x00\x00\x00\x1b\x0a\x00\x00\x00\x00\x00\x00\x0a\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x31\x2e\x3b\x31\x00\x41\x41\x0e\x02\x54\x45\x58\x54\x75\x6e\x69\x78\x00\x00\x52\x52\x05\x01\x89\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x31\x50\x58\x24\x01\x6d\x81\x00\x00\x00\x00\x81\x6d\x01\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x86\x00\x1c\x00\x00\x00\x00\x00\x00\x1c\x28\x23\x00\x00\x00\x00\x23\x28\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x32\x2e\x3b\x31\x00\x41\x41\x0e\x02\x54\x45\x58\x54\x75\x6e\x69\x78\x00\x00\x52\x52\x05\x01\x89\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x32\x50\x58\x24\x01\x6d\x81\x00\x00\x00\x00\x81\x6d\x02\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x86\x00\x1c\x00\x00\x00\x00\x00\x00\x1c\x28\x23\x00\x00\x00\x00\x23\x28\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x33\x2e\x3b\x31\x00\x41\x41\x0e\x02\x54\x45\x58\x54\x75\x6e\x69\x78\x00\x00\x52\x52\x05\x01\x89\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x33\x50\x58\x24\x01\x6d\x81\x00\x00\x00\x00\x81\x6d\x02\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00", 891);
*(uint64_t*)0x20000268 = 0x37b;
*(uint64_t*)0x20000270 = 0xb800;
*(uint64_t*)0x20000278 = 0x20010960;
memcpy((void*)0x20010960, "\x66\x00\x18\x00\x00\x00\x00\x00\x00\x18\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x00\x52\x52\x05\x01\x81\x50\x58\x24\x01\x6d\x41\x00\x00\x00\x00\x41\x6d\x02\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x66\x00\x17\x00\x00\x00\x00\x00\x00\x17\x00\x08\x00\x00\x00\x00\x08\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x02\x00\x00\x01\x00\x00\x01\x01\x01\x52\x52\x05\x01\x81\x50\x58\x24\x01\x6d\x41\x00\x00\x00\x00\x41\x6d\x03\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x86\x00\x21\x00\x00\x00\x00\x00\x00\x21\x1a\x04\x00\x00\x00\x00\x04\x1a\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x30\x2e\x3b\x31\x00\x41\x41\x0e\x02\x54\x45\x58\x54\x75\x6e\x69\x78\x00\x00\x52\x52\x05\x01\x89\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x30\x50\x58\x24\x01\x6d\x81\x00\x00\x00\x00\x81\x6d\x01\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\xaa\x00\x22\x00\x00\x00\x00\x00\x00\x22\x00\x00\x00\x00\x00\x00\x00\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x01\x00\x00\x01\x08\x46\x49\x4c\x45\x31\x2e\x3b\x31\x00\x52\x52\x05\x01\x8d\x4e\x4d\x0a\x01\x00\x66\x69\x6c\x65\x31\x50\x58\x24\x01\x6d\xa1\x00\x00\x00\x00\xa1\x6d\x01\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x53\x4c\x32\x01\x00\x08\x00\x00\x03\x74\x6d\x70\x00\x16\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x32\x38\x30\x37\x37\x31\x34\x37\x39\x32\x00\x05\x66\x69\x6c\x65\x30\x00\x05\x66\x69\x6c\x65\x30\x54\x46\x1a\x01\x0e\x7a\x09\x0c\x0c\x00\x1e\x00\x7a\x09\x0c\x0c\x00\x35\x00\x7a\x09\x0c\x0c\x00\x1e\x00\x00\x00\x00\x00\x00", 512);
*(uint64_t*)0x20000280 = 0x200;
*(uint64_t*)0x20000288 = 0xc000;
*(uint64_t*)0x20000290 = 0x20010b60;
memcpy((void*)0x20010b60, "\x45\x52\xed\x01\x0a\x54\x87\x01\x52\x52\x49\x50\x5f\x31\x39\x39\x31\x41\x54\x48\x45\x20\x52\x4f\x43\x4b\x20\x52\x49\x44\x47\x45\x20\x49\x4e\x54\x45\x52\x43\x48\x41\x4e\x47\x45\x20\x50\x52\x4f\x54\x4f\x43\x4f\x4c\x20\x50\x52\x4f\x56\x49\x44\x45\x53\x20\x53\x55\x50\x50\x4f\x52\x54\x20\x46\x4f\x52\x20\x50\x4f\x53\x49\x58\x20\x46\x49\x4c\x45\x20\x53\x59\x53\x54\x45\x4d\x20\x53\x45\x4d\x41\x4e\x54\x49\x43\x53\x50\x4c\x45\x41\x53\x45\x20\x43\x4f\x4e\x54\x41\x43\x54\x20\x44\x49\x53\x43\x20\x50\x55\x42\x4c\x49\x53\x48\x45\x52\x20\x46\x4f\x52\x20\x53\x50\x45\x43\x49\x46\x49\x43\x41\x54\x49\x4f\x4e\x20\x53\x4f\x55\x52\x43\x45\x2e\x20\x20\x53\x45\x45\x20\x50\x55\x42\x4c\x49\x53\x48\x45\x52\x20\x49\x44\x45\x4e\x54\x49\x46\x49\x45\x52\x20\x49\x4e\x20\x50\x52\x49\x4d\x41\x52\x59\x20\x56\x4f\x4c\x55\x4d\x45\x20\x44\x45\x53\x43\x52\x49\x50\x54\x4f\x52\x20\x46\x4f\x52\x20\x43\x4f\x4e\x54\x41\x43\x54\x20\x49\x4e\x46\x4f\x52\x4d\x41\x54\x49\x4f\x4e\x2e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 256);
*(uint64_t*)0x20000298 = 0x100;
*(uint64_t*)0x200002a0 = 0xc800;
*(uint64_t*)0x200002a8 = 0x20010c60;
memcpy((void*)0x20010c60, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x200002b0 = 0x80;
*(uint64_t*)0x200002b8 = 0xd000;
*(uint64_t*)0x200002c0 = 0x20010ce0;
memcpy((void*)0x20010ce0, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x200002c8 = 0x20;
*(uint64_t*)0x200002d0 = 0xd800;
*(uint64_t*)0x200002d8 = 0x20010d00;
memcpy((void*)0x20010d00, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkal\000\000\000\000\000\000", 1056);
*(uint64_t*)0x200002e0 = 0x420;
*(uint64_t*)0x200002e8 = 0x10800;
*(uint8_t*)0x20011120 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x5c000, 0xa, 0x20000200, 0, 0x20011120, 1);
	return 0;
}
