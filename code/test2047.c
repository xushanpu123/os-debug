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

memcpy((void*)0x200000c0, "tmpfs\000", 6);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint8_t*)0x20003780 = 0;
syz_mount_image(0x200000c0, 0x20000100, 0, 0, 0x20000000, 0, 0x20003780, 0);
memcpy((void*)0x20000000, "tmpfs\000", 6);
memcpy((void*)0x20000040, "./file0\000", 8);
*(uint64_t*)0x20000080 = 0x20000140;
memcpy((void*)0x20000140, "\x87\xf0\xac\x56\xbf\x34\xb7\xce\x0a\x68\xb1\xca\xba\xe6\x1e\x49\x20\x39\x37\xd5\xbc\xd6\x97\x42\xcf\x9b\x5a\xe4\x1f\x50\x31\x14\x61\xd1\x6b\x1d\x7f\x80\xc3\x5e\xa8\x77\x68\x8e\x89\x89\x60\x11\x4b\xec\x88\x09\xbc\x5b\x37\xd2\x98\x82\xcc\xa8\x6e\x0c\x16\x86\x4b\x95\xff\xfc\xf7\xd2\x39\x2f\x31\x7d\x35\xd5\xd2\xa4\x5f\x4e\x06\xa7\xe5\x9c\x41\xee\xf6\x17\xee\xd2\xbf\x3a\xd9\xdf\x70\x8b\xd0\xd7\x97\x4a\xf6\x8d\x11\x3d\xa9\x50\x84\xb5\x9e\x81\x05\xa1\x78\xa4\x01\x4e\xd9\x35\x3e\x43\xc9\x28\xbb\x04\x8f\x3e\xb4\xe0\x7d\x37\xd0\x10\x29\x1c\x90\xa0\x7a\x02\x67\x2d\xe9\xad\xa4\x10\x47\x44\x33\x72\x8b\xeb\xdd\x7b\xb9\x0a\x8d\x92\x73\x35\x32\x95\x1c\x10\xe9\x3c", 164);
*(uint64_t*)0x20000088 = 0xa4;
*(uint64_t*)0x20000090 = 2;
memcpy((void*)0x20000200, "huge=never", 10);
*(uint8_t*)0x2000020a = 0x2c;
memcpy((void*)0x2000020b, "huge=advise", 11);
*(uint8_t*)0x20000216 = 0x2c;
memcpy((void*)0x20000217, "mpol", 4);
*(uint8_t*)0x2000021b = 0x3d;
memcpy((void*)0x2000021c, "default", 7);
*(uint8_t*)0x20000223 = 0x3a;
*(uint8_t*)0x20000224 = 0;
*(uint8_t*)0x20000225 = 0;
*(uint8_t*)0x20000226 = 0;
*(uint8_t*)0x20000227 = 0;
*(uint8_t*)0x20000228 = 0;
*(uint8_t*)0x20000229 = 0;
*(uint8_t*)0x2000022a = 0x2c;
memcpy((void*)0x2000022b, "size", 4);
*(uint8_t*)0x2000022f = 0x3d;
*(uint8_t*)0x20000230 = 0;
*(uint8_t*)0x20000231 = 0;
*(uint8_t*)0x20000232 = 0;
*(uint8_t*)0x20000233 = 0;
*(uint8_t*)0x20000234 = 0x2c;
memcpy((void*)0x20000235, "nr_blocks", 9);
*(uint8_t*)0x2000023e = 0x3d;
*(uint8_t*)0x2000023f = 0;
*(uint8_t*)0x20000240 = 0;
*(uint8_t*)0x20000241 = 0;
*(uint8_t*)0x20000242 = 0;
*(uint8_t*)0x20000243 = 0;
*(uint8_t*)0x20000244 = 0x2c;
memcpy((void*)0x20000245, "size", 4);
*(uint8_t*)0x20000249 = 0x3d;
*(uint8_t*)0x2000024a = 0;
*(uint8_t*)0x2000024b = 0;
*(uint8_t*)0x2000024c = 0;
*(uint8_t*)0x2000024d = 0;
*(uint8_t*)0x2000024e = 0x2c;
memcpy((void*)0x2000024f, "mask", 4);
*(uint8_t*)0x20000253 = 0x3d;
memcpy((void*)0x20000254, "MAY_EXEC", 8);
*(uint8_t*)0x2000025c = 0x2c;
memcpy((void*)0x2000025d, "smackfshat", 10);
*(uint8_t*)0x20000267 = 0x3d;
memset((void*)0x20000268, 64, 1);
*(uint8_t*)0x20000269 = 0x2c;
*(uint8_t*)0x2000026a = 0;
syz_mount_image(0x20000000, 0x20000040, 0xa6, 1, 0x20000080, 0x2060, 0x20000200, 0);
	return 0;
}