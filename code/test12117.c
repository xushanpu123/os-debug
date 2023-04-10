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

memcpy((void*)0x20000780, "ext4\000", 5);
memcpy((void*)0x200007c0, "./file0\000", 8);
*(uint8_t*)0x20000c00 = 0;
syz_mount_image(0x20000780, 0x200007c0, 0, 0, 0x20000ac0, 0, 0x20000c00, 0);
memcpy((void*)0x20000dc0, "ext2\000", 5);
memcpy((void*)0x200005c0, "./file0\000", 8);
*(uint64_t*)0x20000700 = 0x20000640;
memcpy((void*)0x20000640, "\x65\xa2\x76\xe7\x79\xb3\x9a\xc9\x7c\x6b\x6a\xdc\xc5\x6d\x40\x27\x1a\xea\xc4\x63\x26\xc7\x9b\x12\xd0\x60\x78\xa8\x0a\x50\x3e\x14\xb3\xd1\x66\x40\x53\xaf\x72\x5d\x95\x47\xad\xfb\x05\xcb\x52\x58\xed\x0d\x39\xe5\xfd\x1d\x08\x71\xb6\x10\x79\x3e\x64\xd3\x24\x00\xf6\xe2\xf1\x7b\x17\xf5\xdc\x78\x43\x14\xa6\x81\x10\xef\x85\xb5\xfc\xfb\x39\x63\xa9\x29\x70\x20\x1d\x2d\xdf\xf6\x01\xec\xf5\xf7\x9f\x36\xdf\x36\xdf\x80\x8a\xbe\xec\x52\xe7\x9c\x70\xe9\x30\x94\x94\x78\x4d\x9a\x02\x83\x3f\xc0\x0f\x7d\x74\x3d\xe3\xa4\x98\x19\x96\x96\xaf\xa2\x27\x90\x5f\x58\xbc\xa7\x78\x0e\xbc\xab\xde\x60\xd4\x92\x2a\xec\xfd\xbe\x8c\x19\x93\xca\x2d\xf2\x40\xce\x4e\xac\xce\x66\xe7", 163);
*(uint64_t*)0x20000708 = 0xa3;
*(uint64_t*)0x20000710 = 0xff;
memcpy((void*)0x20000d00, "resgid", 6);
*(uint8_t*)0x20000d06 = 0x3d;
sprintf((char*)0x20000d07, "0x%016llx", (long long)0xee00);
*(uint8_t*)0x20000d19 = 0x2c;
memcpy((void*)0x20000d1a, "test_dummy_encryption", 21);
*(uint8_t*)0x20000d2f = 0x2c;
memcpy((void*)0x20000d30, "sb", 2);
*(uint8_t*)0x20000d32 = 0x3d;
sprintf((char*)0x20000d33, "0x%016llx", (long long)0);
*(uint8_t*)0x20000d45 = 0x2c;
memcpy((void*)0x20000d46, "bh", 2);
*(uint8_t*)0x20000d48 = 0x2c;
memcpy((void*)0x20000d49, "fowner>", 7);
sprintf((char*)0x20000d50, "%020llu", (long long)0);
*(uint8_t*)0x20000d64 = 0x2c;
memcpy((void*)0x20000d65, "defcontext", 10);
*(uint8_t*)0x20000d6f = 0x3d;
memcpy((void*)0x20000d70, "sysadm_u", 8);
*(uint8_t*)0x20000d78 = 0x2c;
*(uint8_t*)0x20000d79 = 0;
syz_mount_image(0x20000dc0, 0x200005c0, 0x1a2, 1, 0x20000700, 0, 0x20000d00, 0);
	return 0;
}