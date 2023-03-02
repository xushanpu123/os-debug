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
*(uint64_t*)0x20000200 = 0x20010180;
memcpy((void*)0x20010180, "\xff\xff\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff", 1020);
*(uint64_t*)0x20000208 = 0x3fc;
*(uint64_t*)0x20000210 = 4;
*(uint64_t*)0x20000218 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x40\x00\x00\x00\x03\x00\x00\x00\x30\x00\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x02\x00\x00\x00\x00\x80\x00\x00\x00\x80\x00\x00\x20\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x00\x02\x00\x00\x28\x02\x00\x00\x02\x84\x01\x00\x1b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x00\x00\x00\x00\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x33\x39\x31\x34\x38\x36\x30\x34\x30\x35\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000220 = 0xc0;
*(uint64_t*)0x20000228 = 0x400;
*(uint64_t*)0x20000230 = 0x200100c0;
memcpy((void*)0x200100c0, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x97\xcc\xac\x2a\x98\x48\x8b\x8d\x64\xe6\xcf\xc4\xd1\xba\xaf\x01\x00\x00\x00\x0c\x00\x00\x00\x00\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000238 = 0x40;
*(uint64_t*)0x20000240 = 0x4e0;
*(uint64_t*)0x20000248 = 0x20000a40;
memcpy((void*)0x20000a40, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd8\x3d\x00\x00\x00\x00\x00\x00\x00\x20\x00\x20\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xb0\xf5\xcd\x8a\x0a\xa7\x45\x86\x58\xad\x6b\xe7\x11\x5d\xd3\x94\x01\x3a\xaf\xe3\x73\xa3\x15\x27\xf6\xa9\x22\x2c\x1f\x54\x6d\x5f\xbc\xe1\x3f\xdb\xfd\x3b\x5c\x70\x4e\xe0\xb3\x88\x8f\x4b\xed\x71\x9e\x5e\x82\x54\x4c\x7a\x17\xff\x70\xef\x04\x3b\x3c\x83\x0a\x04\xf5\x72\x95\xb7\x5b\x92\x67\xe3\x7e\xf7\x8f\x39\x58\x0d\x26\xb2\x70\x27\x2f\x43\x03\x80\xee\xeb\x28\x04\xa7\x1e\x7a\x93\x81\x38\xef\xb3\x8e\x87\x16\x3f\x0d\xda\x11\x58\x62\xda\xd4\x8c\x7b\x03\x0c\x9a\x78\x8f\x07\x59\x3a\x2f\xa4\x75\xb9\xda\xf5\x37\x80\x4e\x7b\x73\xcc\xef\xd5\x00\x2a\xa6\x57\xb7\x16\x4f\x9a\x40\x1b\x17\x12\x8d\x8b\xfb\x18\x1a\x8b\x4b\x6d\x0f\x3d\x28\x49\x8d\x1f\x5c\x46\xbd\xa2\xf2\x08\xb5\x47\xa3\xef\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 233);
*(uint64_t*)0x20000250 = 0xe9;
*(uint64_t*)0x20000258 = 0x540;
*(uint64_t*)0x20000260 = 0x20010140;
memcpy((void*)0x20010140, "\x00\x00\x00\x00\x43\x0e\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000268 = 0x20;
*(uint64_t*)0x20000270 = 0x640;
*(uint64_t*)0x20000278 = 0x20010160;
memcpy((void*)0x20010160, "\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00\x30\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0f\x00\x8e\xc4", 32);
*(uint64_t*)0x20000280 = 0x20;
*(uint64_t*)0x20000288 = 0x1000;
*(uint64_t*)0x20000290 = 0x200121a0;
memcpy((void*)0x200121a0, "\xed\x41\x00\x00\x00\x10\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x04\x00\x08\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000298 = 0x40;
*(uint64_t*)0x200002a0 = 0x4200;
*(uint64_t*)0x200002a8 = 0x20000a00;
memcpy((void*)0x20000a00, "\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x00\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002b0 = 0x20;
*(uint64_t*)0x200002b8 = 0x4280;
*(uint64_t*)0x200002c0 = 0x20012200;
memcpy((void*)0x20012200, "\xc0\x41\x00\x00\x00\x30\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x00\x00\x00\x0a\x00\x00\x00\x0b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x200002c8 = 0x40;
*(uint64_t*)0x200002d0 = 0x5400;
*(uint64_t*)0x200002d8 = 0x20012240;
memcpy((void*)0x20012240, "\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x200002e0 = 0x40;
*(uint64_t*)0x200002e8 = 0x5480;
*(uint64_t*)0x200002f0 = 0x20012280;
memcpy((void*)0x20012280, "\xed\x41\x00\x00\x3c\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x00\x10\x03\x00\x00\x00\x02\x00\x00\x00\x0d\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x30\x00\x00\x00\x0e\x00\x00\x00\x28\x00\x05\x07\x66\x69\x6c\x65\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xa5\x0b\xc6\xd2\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x200002f8 = 0xc0;
*(uint64_t*)0x20000300 = 0x5600;
*(uint64_t*)0x20000308 = 0x20012340;
memcpy((void*)0x20012340, "\xed\x81\x00\x00\x1a\x04\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x08\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x52\x68\x88\xec\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000310 = 0xa0;
*(uint64_t*)0x20000318 = 0x5800;
*(uint64_t*)0x20000320 = 0x200123e0;
memcpy((void*)0x200123e0, "\xff\xa1\x00\x00\x27\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x33\x39\x31\x34\x38\x36\x30\x34\x30\x35\x2f\x66\x69\x6c\x65\x30\x2f\x66\x69\x6c\x65\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x6e\x2b\x38\xd0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00", 160);
*(uint64_t*)0x20000328 = 0xa0;
*(uint64_t*)0x20000330 = 0x5a00;
*(uint64_t*)0x20000338 = 0x20012480;
memcpy((void*)0x20012480, "\xed\x81\x00\x00\x0a\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x10\x01\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x66\xcf\x1a\x9e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x06\x01\x54\x01\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\x06\x01\x4c\x01\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 256);
*(uint64_t*)0x20000340 = 0x100;
*(uint64_t*)0x20000348 = 0x5c00;
*(uint64_t*)0x20000350 = 0x20012580;
memcpy((void*)0x20012580, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x78\x61\x74\x74\x72\x32\x00\x00\x78\x61\x74\x74\x72\x31\x00\x00\xed\x81\x00\x00\x28\x23\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x18\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x0d\x00\x00\x00\x0e\x00\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x5f\xca\x8b\x69\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000358 = 0xc0;
*(uint64_t*)0x20000360 = 0x5de0;
*(uint64_t*)0x20000368 = 0x20012640;
memcpy((void*)0x20012640, "\xed\x81\x00\x00\x64\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x10\x01\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x70\x6c\x26\xd4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x64\x00\x41\x64\x64\x00\x41\x64\x64\x00\x41\x64\x70\x1f\x1f\x63\x64\x00\x41\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\xea\x04\x07\x34\x01\x00\x00\x00\x00\x28\x00\x00\x00\x00\x00\x00\x00\x64\x61\x74\x61\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000370 = 0xc0;
*(uint64_t*)0x20000378 = 0x6000;
*(uint64_t*)0x20000380 = 0x20012700;
memcpy((void*)0x20012700, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000lersyzkallersyzkallersyzkallersyzkallers", 64);
*(uint64_t*)0x20000388 = 0x40;
*(uint64_t*)0x20000390 = 0x61c0;
*(uint64_t*)0x20000398 = 0x20012740;
memcpy((void*)0x20012740, "\x02\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x0b\x00\x00\x00\x14\x00\x0a\x02\x6c\x6f\x73\x74\x2b\x66\x6f\x75\x6e\x64\x00\x00\x0c\x00\x00\x00\x10\x00\x05\x02\x66\x69\x6c\x65\x30\x00\x00\x00\x0f\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x31\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x32\x00\x00\x00\x10\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x33\x00\x00\x00\x11\x00\x00\x00\x94\x0f\x09\x01\x66\x69\x6c\x65\x2e\x63\x6f\x6c\x64\x00\x00\x00", 128);
*(uint64_t*)0x200003a0 = 0x80;
*(uint64_t*)0x200003a8 = 0x8000;
*(uint64_t*)0x200003b0 = 0x200127c0;
memcpy((void*)0x200127c0, "\x0b\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x00\x00\x00\x00\xe8\x0f\x00\x00", 32);
*(uint64_t*)0x200003b8 = 0x20;
*(uint64_t*)0x200003c0 = 0x9000;
*(uint64_t*)0x200003c8 = 0x200127e0;
memcpy((void*)0x200127e0, "\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003d0 = 0x20;
*(uint64_t*)0x200003d8 = 0xa000;
*(uint64_t*)0x200003e0 = 0x20012800;
memcpy((void*)0x20012800, "\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003e8 = 0x20;
*(uint64_t*)0x200003f0 = 0xb004;
*(uint64_t*)0x200003f8 = 0x20000540;
memcpy((void*)0x20000540, "\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x4d\x9a\x49\x74\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x09\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x4d\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x73\x79\x7a\x6b\x61\x6c\x00\x00\x00\x00\x00\x00\x00\xfb\xe8\x10\x5b\x11\x0a\x75\x42\xfe\xa3\x69\xd1\xb5\x9f\x94\xce\x04\xc2\xba\x19\xc3\xc8\x83\xde\x67\xa1\xc0\xc7\xa8\x52\x30\xc3\x4b\x3c\x9d\xde\xe4\x73\xa1\x8e\xab\x35\x75\xb9\x89\x07\xef\x9e\xa6\xf4\x61\x9e\xe3\xcb\x8c\x67\x84\x87\xf3\xc7\x44\x70\x3e\x89\xdf\xa9\xa0\xa5\xca\x60\x16\x1f\x4c\x64\xab\x10\x94\x9e\x24\x9f\xa9\xa6\x14\x47\x9a\xcf\x03\xe1\xca\xc0\x2a\xb0\x4d\xe8\xec\x8e\xd2\xb0\x2b\x9f\xac\x71\x86\xfb\x00\x80\xf9\xdf\x2a\xad\x06\xc2\x87\xd0", 1174);
*(uint64_t*)0x20000400 = 0x496;
*(uint64_t*)0x20000408 = 0xc000;
*(uint8_t*)0x20012c40 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x40000, 0x16, 0x20000200, 0, 0x20012c40, 1);
	return 0;
}