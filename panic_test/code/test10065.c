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

*(uint64_t*)0x20000c00 = 0;
*(uint32_t*)0x20000c08 = 0;
*(uint64_t*)0x20000c10 = 0x20000bc0;
*(uint64_t*)0x20000bc0 = 0x20003d00;
memcpy((void*)0x20003d00, "4\n\000\000", 4);
*(uint16_t*)0x20003d04 = -1;
memcpy((void*)0x20003d06, "\x00\x02\x29\xbd\xdf\x25\x0f\x00\x00\x00\x0c\x00\x99\x00\x06\x00\x00\x00\x2b\x00\x00\x00\xeb\x06\x0e\x00\x80\x3c\x00\x00\x08\x02\x11\x00\x00\x00\xff\xff\xff\xff\xff\xff\x50\x50\x50", 45);
*(uint64_t*)0x20000bc8 = 0xa34;
*(uint64_t*)0x20000c18 = 1;
*(uint64_t*)0x20000c20 = 0;
*(uint64_t*)0x20000c28 = 0;
*(uint32_t*)0x20000c30 = 0;
	syscall(__NR_sendmsg, -1, 0x20000c00ul, 0ul);
memcpy((void*)0x20000180, "nfs4\000", 5);
memcpy((void*)0x200001c0, "./file0\000", 8);
*(uint64_t*)0x20000500 = 0x20000340;
memcpy((void*)0x20000340, "\xe1\x61\x10\x1f\x19\x7e\x39\x9e\x19\xbe\xf7\x43\x21\x94\x82\x33\xc8\xeb\xca\xce\x3d\x01\xcd\x0f\x3d\x85\x38\x45\x08\xc5\x8a\xcc\x5f\x6c\xc8\xe5\x02\x42\xa5\xf4\x2a\x89\xfb\x6b\x50\x8f\x94\x58\xa1\xef\x83\x27\x18\xa3\x0f\x79\x04\x16\xdb\x0c\x36\x2e\x2e\x68\x90\xd9\xa6\x07\xa7\xd8\xdc\xb0\x70\x5a\x2d\xb2\xe5\x92\xdd\x0f\xd6\x0c\x71\x34\xcc", 85);
*(uint64_t*)0x20000508 = 0x55;
*(uint64_t*)0x20000510 = 8;
*(uint64_t*)0x20000518 = 0x200003c0;
memcpy((void*)0x200003c0, "\xe7\x8a\x03\x7b\x30\xcb\xb5\xd8\x82\x7b\xa4\xc9\x8e\xbe\x06\x02\x0b\x29\xe2\xdb\xdc\xde\x5d\x59\xa8\xde\xa9", 27);
*(uint64_t*)0x20000520 = 0x1b;
*(uint64_t*)0x20000528 = 0x81;
*(uint64_t*)0x20000530 = 0x20000280;
memcpy((void*)0x20000280, "\x43\x0f\xbd\x41\xdd\xe7\xf6\x94\x03\x65\x96\xd1\xd2\xd8\x97\x75\x51\xe6\x9a\x73\x21\xae\x65\xdf\x94\x22\x51\x61\x9c\xce\x48\x09\x69\x03\xf8\x10\x88\xeb\xba\xc5\xc5\xb5\x43\xda\xfa\x43\xba\x98\x18\x45\xb5\x78\x80\x9c\x75\xcf\x3c\x52\x34\x65\x92\xaa\x03\xee\xe1\x8c\x41\xdd\x2a\x1a\xf2\x98\xef\x7b\xd8\xcf\xb1\x79\x30\x61\x56\x7b\x78\x73\xe1\x18\x14\x11\x35\xeb\x97\x29\xbf\x96\xf4\x35\x8a\x31\xc1\x8b\x65\x6a\x50\x53\xd1\xf8\xdc\x80\xcc\x73\x9b\xec\xc8\x60\xfb\x07\xe1\xd3\xca\xf7\x96\xb4\x0c\xae\xd2\x4b\x68\xfe\xa2\x61\x87\x07\x25\x86\x19\x55\x2f\xa5\xc1\x6c\x02\x05\x2b\xc1", 144);
*(uint64_t*)0x20000538 = 0x90;
*(uint64_t*)0x20000540 = 0x62bd;
*(uint64_t*)0x20000548 = 0x20000200;
memcpy((void*)0x20000200, "\x57\x3c\x45\xab\xdf\xd6\x75\x88\xcd\x65\xaf\x51\x9e\x32\x8d\x6b\xd0\x76\x88\x9c\x00\x2a\x56\x05\x2d\x25\x98\xa9\x93\x82\x6e\x9a\x47\x14\xb7\x2f\x80\x7a\xd9\x71\xe8\x01\xc8\xfe\x7d\x5f\xab\x46\xee\x23\x49\x0e\xb5\x37\x7a\x80\x61\xd0\xf4\xd1\x91\x3a\x5c\x97\x39\x07\x5f\xcc\xe5\x74\xa4\x70\x7d\x85\x76\x08\xe8\x10\x20\xde\x0f\x07\xbb\xd7\x78\x03\x1e\x6c\x6a\x18\x7e\xac\x08\x02\xd2\xf8\x90\x9d\xbd\xc5", 100);
*(uint64_t*)0x20000550 = 0x64;
*(uint64_t*)0x20000558 = 0xe185;
*(uint64_t*)0x20000560 = 0x20000400;
memcpy((void*)0x20000400, "\xb7\xd2\xcb\xe7\x7e\x5b\x53\x9d\xc6\x1d\x01\x6f\x77\x58\x16\xdd\xb6\x2f\x5e\x58\x89\xf2\xc2\x1c\x10\xcc\x60\x98\x38\xd8\xa6\x8d\x3a\x0b\x76\x0f\x46\x9f\x55\x25\x99\xb2\x5c\x8d\x15\xf0\xc2\x43\x72\x4e\x29\x3b\xa8\xd1\xb4\x37\xce\xa3\xcb\xed\x25\x96\x96\x66\xe5\xe6\x0f\x69\xbe\x66\xc4\x7d\x2c\x12\x81\x41\xc4\xea\x1f\x9d\x1e\xa2\x49\x36\xf2\x0b\x03\x76\x54\xde\xca\x26\x39\xbd\xcb\xe6\x3f\x74\x39\xa8\x84\x20\x13\x70\xdb\xf4\x7f\xae\x1b\x65\xbe\x50\xf0\xe0\xfb\x94\x84\x00\xbf\x4a\xf0\xbc\xcd\xb3\x51\x90\x7b\x40\x9d\x0f\x85\x29\x41\x5e\xbc\xea\xce\x2e\x62\x3c\xbb\xe0\x99\x4e\x2e\xa2\xd1\x30\x88\xda\xa4\xa4\x75\xc8\x7b\x14\x87\xdf\xa5\xf2\xf2\x01\x64\x3d\xc8\x65\xf3\x65\x4c\xf6\x68\xe6\x7a\xef\xa3\x6d\x0c\x96\x35\xb6\xd1\xd7\x99\x9b\x89\x6e\x36\xf7\x81\x08\x26\x4a\xa9\xf2\x4c\x1c\x90\x1f\xff\x1c\x06\x37\xaf\x87\xf1\x49\x97\xcd\xb5\xcd\x3c\xa8\x42\xd3\x51", 215);
*(uint64_t*)0x20000568 = 0xd7;
*(uint64_t*)0x20000570 = 0xffff;
memcpy((void*)0x20000740, "\x2d\xe8\x2d\x26\x23\x00\x2c\x2d\xe8\x2d\x26\x23\x00\x2c\x5d\x3f\x00\x2c\x2d\x23\x28\x23\x2c\x2d\xe8\x2d\x26\x23\x00\x2c\x2c\x2d\xe8\x2d\x26\x23\x00\x2c\x64\x65\x66\x63\x6f\x6e\x74\x65\x78\x74\x3d\x73\x74\x61\x66\x66\x5f\x75\x2c\x6f\x74\x63\x6f\x6e\x74\x65\x78\x74\x3d\x73\x74\x61\x66\x66\x5f\x75\x2c\x53\xe0\x7f\xd7\x33\x76\xea\x73\x6d\x61\x63\x6b\x66\x73\x72\x6f\x6f\x74\x3d\x2d\xe8\x2d\x26\x23\x00\x2c\x00", 102);
syz_mount_image(0x20000180, 0x200001c0, 0x100d6, 5, 0x20000500, 0x804, 0x20000740, 0);
	return 0;
}