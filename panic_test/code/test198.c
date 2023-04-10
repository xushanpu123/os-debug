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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, ".log\000", 5);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000000ul, 0x602002ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0x18;
*(uint8_t*)0x20000044 = 0xf;
*(uint16_t*)0x20000045 = 0;
*(uint8_t*)0x20000047 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint64_t*)0x2000004c = 0;
*(uint32_t*)0x20000054 = 0;
	syscall(__NR_write, r[0], 0x20000040ul, 0x18ul);
memcpy((void*)0x20008000, "ext2\000", 5);
memcpy((void*)0x20008040, "./file0\000", 8);
*(uint64_t*)0x20008380 = 0x20008280;
memcpy((void*)0x20008280, "\x07\x76\x2e\xe6\xe0\xb2\xff\xa6\x9a\x5f\x37\xad\xc7\x71\xef\xe4\x60\xec\x5f\x4b\x2a\xcb\x5a\x15\x70\x83\xab\x5a\x85\x65\x8e\xd6\x31\x70\x31\xc6\xcb\x8b\x38\xac\xd5\x22\xfd\xda\xa8\x35\xba\x62\x61\x49\xd8\xe2\x48\x49\x6e\x6a\x2b\x09\x60\x7c\x74\xcc\x87\xb2\x10\x83\x2a\xc5\x13\x8a\xbb\xe3\x70\xc6\xd5\x0c\x6b\x4c\xdc\x8a\x9e\x03\x14\x42\x62\x0c\xc6\xa7\x9b\xa6\xfc\x8b\xa6\x22\x24\x62\xc2\xc5\x79\x07\x9d\x48\x70\x93\xdb\xeb\x0b\x56\x4d\xc3\x96\x8d\x6e\x10\x2d\xdd\x9a\x59\x06\x88\x61\x64\x9b\x2a\xe3\xd0\xee\x54\x3e\x72\xf4\x9c\x1a\x41\x2d\x8e\x89\x02\x2b\x29\x45\x64\x0f\xcc\x0a\x71\x36\x85\x88\x6d\x0b\x0a\x1f\x1f\xa5\x11\x2a\xbc\x8b\x94\x95\x32\xeb\x33\xc6\xc4\x6a\x2f\xa1\x9d\xcf\x57\xb3\x1a\x2c\xe6\x71\xa4\xc6\x8b\x51\x5e\x23\xfb\x69\xc7\x09\xaa\xdb\x20\x74\x17\xdb\x89\xd6\x7f\xf1\x4d\x1f\xcb\xd6\x97\xc2\xcb\xc1\xdf\x07\x7e\xe1\xd1\xf9\x88\xca\xa0\x44\x85\x37\x84\xe4\x89\x2c\x3e\x0d\xea\x41\xf0\xb5\x03\xab\x7b\x8c\x45\x06\x79\x5c\x2f\x09\x54\x34\x63\xed\x9d\x2e\x13\x81\x67", 246);
*(uint64_t*)0x20008388 = 0xf6;
*(uint64_t*)0x20008390 = 0x2d28;
memcpy((void*)0x20008400, "minixdf", 7);
*(uint8_t*)0x20008407 = 0x2c;
memcpy((void*)0x20008408, "sysvgroups", 10);
*(uint8_t*)0x20008412 = 0x2c;
memcpy((void*)0x20008413, "journal_dev", 11);
*(uint8_t*)0x2000841e = 0x3d;
sprintf((char*)0x2000841f, "0x%016llx", (long long)7);
*(uint8_t*)0x20008431 = 0x2c;
memcpy((void*)0x20008432, "bsddf", 5);
*(uint8_t*)0x20008437 = 0x2c;
memcpy((void*)0x20008438, "errors=remount-ro", 17);
*(uint8_t*)0x20008449 = 0x2c;
memcpy((void*)0x2000844a, "journal_ioprio", 14);
*(uint8_t*)0x20008458 = 0x3d;
sprintf((char*)0x20008459, "0x%016llx", (long long)1);
*(uint8_t*)0x2000846b = 0x2c;
memcpy((void*)0x2000846c, "fowner<", 7);
sprintf((char*)0x20008473, "%020llu", (long long)0xee00);
*(uint8_t*)0x20008487 = 0x2c;
memcpy((void*)0x20008488, "uid", 3);
*(uint8_t*)0x2000848b = 0x3d;
sprintf((char*)0x2000848c, "%020llu", (long long)-1);
*(uint8_t*)0x200084a0 = 0x2c;
memcpy((void*)0x200084a1, "dont_measure", 12);
*(uint8_t*)0x200084ad = 0x2c;
*(uint8_t*)0x200084ae = 0;
syz_mount_image(0x20008000, 0x20008040, 0x2e1e, 1, 0x20008380, 0x200280c, 0x20008400, 0);
	return 0;
}