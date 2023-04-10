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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif
#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

static unsigned long long procid;

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

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
memcpy((void*)0x20000040, "/dev/vcs#\000", 10);
	res = -1;
res = syz_open_dev(0x20000040, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200014c0 = 0x20000000;
memcpy((void*)0x20000000, "\x39\xd2\x90\x60\x80\x2c\x4e", 7);
*(uint64_t*)0x200014c8 = 7;
*(uint64_t*)0x200014d0 = 0;
*(uint64_t*)0x200014d8 = 0x20001580;
memcpy((void*)0x20001580, "\x19\xd3\xdf\x51\x8d\x76\xc4\xde\xa0\xff\x9f\x3a\x0d\x43\xb0\x1d\xdf\x02\x60\x3f\x8d\xc2\x52\x2a\xb3\x84\xe1\xb0\x8d\x04\x7a\xa5\x73\xf3\xe9\x45\x2e\xcb\xe0\x9f\xcc\xdd\xcf\xb4\x87\x99\xbb\x8e\x5d\x78\x4d\x97\x99\x12\x18\x05\xe5\xaa\x3c\x60\xb1\x57\x42\xab\x48\xe4\xfd\x6f\x9f\x21\x1e\xea\xc4\x41\x61\xbb\xc3\xb1\x44\x01\x12\xae\x2b\x05\xb8\x94\xce\xa6\x3d\xa9\x3a\xd3\x6a\x88\xe9\xb7\x42\x58\xa6\xf9\x8f\xf8\xe1\xaa\x86\xf1\x2b\xe0\xa8\xed\xb3\xb5\xd3\xa8\x06\xd1\x03\x70\x01\x1b\xdd\x46\x03\x25\x04\x4e\x06\xa3\x53\xc0\x80\x50\xa1\x61\x7e\x9c\xa7\xf9\xbe\xcb\x6c\xec", 142);
*(uint64_t*)0x200014e0 = 0x8e;
*(uint64_t*)0x200014e8 = 7;
*(uint64_t*)0x200014f0 = 0x20000240;
memcpy((void*)0x20000240, "\x88\xf1\x90\xf0\x24\x42\x92\xf7\xe9\x14\x0b\x3b\xf1\x43\x37\x96\xdb\x04\x48\xd4\x4b\xcf\x58\xbf\x95\xcc\xfc\x0e\xa0\x09\x0c\x85\x21\x90\xab\xe9\xad\x69\x84\x16\xc7\x6e\x1b\xd4\x78\x63\x94\x3b\x34\x85\xd6\xe2\x13\x85\xf1\x8e\x65\x6f\xcf\x4b\xd7\x7b\x2f\x01\xe3\x79\xa4\x52\x4d\xec\x82\x76\xad\xde\x39\x0f\x2c\xcd\xc1\xa6\x27\x94\xf9\x73\x65\xba\x94\xfe\xfe\x93\xb2\x2a\x74\x8f\x88\x5d\xbd\x4d\x11\x86\xef\x43\xf6\xfe\xd9\x0a\x4e\x22\x15\x7f\x4b\x1d\x86\x66\xda\x17\xce\x60\x3b\xd6\xc1\x55\x75\x1a\x31\x34\x6e\x0b\x7e\xa7\x93\x10\x98\x87\x20\x1d\xfe\x38\x0c\x1b\x20\x96\x1e\xec\x88\x11\x4c\x52\xc7\xc0\x42\x1c\x4b\x8c\x40\x35\x99\x46\x90\xb0\x37\xd8\xbb\x1a\xec\x25\x40\xda\xb8\xfb\xa3\x61\x41\x3b\xc2\xdc\x8f\x10\xe3\x7c\x13\x95\x89\x22\x59\xbc\x74\x55\xe4\xcb\xb3\x41\x89\x2e\x96\x69\xff\x71\x66\xf3\x76\xf0\x9e\x97\x7b\xf9\x75\x2b\x64\xce\x15\x2e\x36\x37\x85\x0d\x41\x7c\x0b\x83\x21\x92", 222);
*(uint64_t*)0x200014f8 = 0xde;
*(uint64_t*)0x20001500 = 0x591;
syz_mount_image(0, 0, 0x6bc, 3, 0x200014c0, 0x800, 0, 0);
memcpy((void*)0x20000080, "nfs\000", 4);
memcpy((void*)0x200000c0, "./file0\000", 8);
*(uint64_t*)0x20000100 = 0x20001740;
memcpy((void*)0x20001740, "\x2c\xf4\xc0\xc3\x24\xe4\xbb\xe1\xf5\x99\x85\x1c\x93\xce\xd3\x70\xdc\x63\xf4\xcf\x94\x1c\x39\x60\x1d\x80\xf1\xb8\x75\x44\x91\xc8\x1c\xae\x40\x6c\x24\x7b\x7f\x9b\xda\xf3\x2e\x0d\x82\x09\x80\xf0\x1e\x0b\x62\x34\x25\xcb\xa0\xe8\x8d\x23\x4f\x6f\x4a\x14\xd6\xba\x97\x11\xbe\x43\x0a\xa6\xfe\x63\xe8\xfe", 74);
*(uint64_t*)0x20000108 = 0x4a;
*(uint64_t*)0x20000110 = 3;
*(uint64_t*)0x20000118 = 0x20001640;
memcpy((void*)0x20001640, "\xd6\x72\x6b\xdc\x4b\x88\x0f\x2c\xd4\xa6\xbe\xdf\xb6\xd9\xf4\xac\x9c\x7e\x32\x62\x2b\x2e\xe4\x2a\xa9\xda\x6c\x2b\xbc\x51\x9e\x59\x67\x90\xf6\x74\x1b\xf5\x08\x39\x6d\x2b\x90\x7d\x9c\x98\x50\xc3\x59\x99\x66\x35\xce\x48\xaf\x09\x11\x77\x80\xde\xb9\x3a\x67\xc8\x2d\xe2\xa5\xc4\xae\x88\x12\x56\x06\xf6\xec\x2c\xd9\x9e\x71\x89\x7a\x99\x29\xc4\xe2\x55\x80\xe3\x66\xd4\xae\x49\x67\x39\x23\x70\xb6\x98\xd9\x02\x00\xc8\x38\x9f\x6d\x64\xe4\xb2\x28\x04\x8c\x35\x93\x8b\x20\x02\x80\x17\x3e\x03\x53\x2b\x26\xe9\xab\xc2\x79\x28\x7e\xc4\xaf\xd7\xc7\x68\x83\x1f\xd3\x9c\x92\xcb\xf2\x24\xc0\x96\x40\x79\x54\xe3\xc1\x20\x57\x95\x2c\xf9\xe7\xca\x54\x75\xb1\x99\x0b\x9f\x7e\xa8\xf5\xd9\x26\xb6\x4d\x31\x7d\x97\xc8\x09\x4b\xb5\x71\xdf\xee\xca\xce\xe4\xfa\xac\x1d\x4e\x4d\x0c\x8a\xe6\x9b\xde", 192);
*(uint64_t*)0x20000120 = 0xc0;
*(uint64_t*)0x20000128 = 0x55;
memcpy((void*)0x200017c0, "/dev/vcs#\000,)V,/dev/vcs#\000,/dev/vcs#\000,/dev/vcs#\000,mask=^MAY_E", 58);
sprintf((char*)0x200017fa, "%020llu", (long long)0);
memcpy((void*)0x2000180e, ",\000", 2);
syz_mount_image(0x20000080, 0x200000c0, 0x115, 2, 0x20000100, 0x2c4800, 0x200017c0, 0);
	syscall(__NR_close_range, r[0], -1, 0ul);
	return 0;
}
