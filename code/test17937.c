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

*(uint64_t*)0x20001480 = 0x20001240;
memset((void*)0x20001240, 76, 1);
*(uint64_t*)0x20001488 = 1;
*(uint64_t*)0x20001490 = 0;
*(uint64_t*)0x20001498 = 0x20000240;
memcpy((void*)0x20000240, "\xc8\xab\x9e\x66\x28\xa3\xa9\x4a\xe1\x2c\x37\x8f\x0e\x9c\x0a\xbc\x9d\x77\x70\xe6\x28\xcc\xac\x25\xfd\x40\x4a\xf0\xdc\x7a\xfc\xce\xfc\xd2\xbc\x18\x80\x6c\x1c\x14\x9c\x6a\x8e\x0a\x11\xbd\x33\xce\x08\xf0\x5e\x1a\xa1\x33\xcf\x17\x6b\x01\x14\x2a\xdc\x6b\xdb\x47\xfe\xa2\x5c\x8d\x7e\x9f\x9c\x52\x09\xd8\x26\x19\x47\xbe\x44\xd9\x86\xd9\xbf\x3c\xd8\x2c\x71\x73\xf6\x61\x2c\x04\x55\x6b\xec\xc2\x78\xed\x3c\x02\xae\x0e\xbc\x08\xbc\xea\x9d\x3e\x7c\xb2\x03\xe8\x7c\xb4\x47\x0f\x0a\xcc\xb3\x3c\x77\x9d\x69\xe9\x5c\x01\x95\x04\xa2\xa7\x0c\x0c\x5f\x61\x84\xa1\xd3\x8a\xfe\xc4\x8f\x0c\xf7\x61\xf8\xa7\xd1\x2b\x54\xa4\x4e\x05\xf4\xc9\x2a\x16\x73\x2f\x49\x59\x00\x63\x8d\xa0\x12\xfc\x06\x7d\x2f\xa5\x8d\x32\xc7\xdc\xbc\x19\xcb\x03\x58\x92\x0c\x7a\xa7\x57\x65\x45\x2f\xf7\x2e\xaf\x5c\xf2\x75\xb0\xe5\xd3\xc8\x00\xe1\xcb\x7c\x07\x95\x9f\x5d\x97\x04\xb3\x04\xe1\x63\x88\xfd\xdd\x72\x75\xb4\x5e\x49\x25\x60\xd2\xab\x56\xcc\x93\x2e\xa3\xf5\x94\x12\x44\xd1\xfc\x6d\x8b\x51\x0b\xe7\x80\xa8\xf2\x1e\x42\xaa\x4f\x25\xbc\x9a\x0d\x64\x1d\x67\xe1\x3f\xb7\x06\xa8\x74\xd5\x09\x1f\x53\x51\x0d\x31\x23\x8f\xa3\x3e\xa1\xf7\x6b\x77\x28\x67\x40\x6f\xbe\xcb\x9f\xee\x64\xf6\xb0\x28\x44\x09\x25\xd8\x2a\x2d\x0f\xcc\x00\xd4\xad\x42\x2a\xd9\xf2\x7e\x80\x5b\x3c\x76\xdb\x67\x75\xd9\x5f\xeb\x77\xcd\x09\x75\xca\x1e\xe9\x6a\x6a\x30\x5f\xcb\xd2\x07\xa3\x74\x34\xed\xd2\x53\x1a\xc2\x7b\xde\xd6\x44\x6e\x5f\xd5\x9d\x3d\xa6\xe6\xf5\xc2\x4f\xfb\x77\x66\x7d\x09\x6a\x86\x48\x65\x5c\xfd\xb1\xef\x5c\x33\x46\xde\x55\x40\x3f\x6b\x00\x9b\xde\xb3\x32\xc5\x02\x2f\xbc\x59\x89\x2e\x6a\x42\x6d\x6c\x13\xe8\xc0\xc9\xb3\xfc\x02\x4a\xa3\xb2\xa5\x40\x37\x77\xd6\x90\x32\x97\x3c\x47\x72\xf3\x68\x07\xd9\xee\xd4\xc4\xd5\x45\x3b\x49\xaf\x80\x97\xe5\xdb\x4a\x03\x72\x9f\xc3\x1b\xf0\x21\xd0\xbf\xe5\x07\xad\xb0\xd0\x4c\x69\x3a\xac\xdd\xbd\x08\x9b\xc2\x75\x7a\x25\x1a\x0f\x57\xf6\x34\x95\xbd\x62\x25\xd5\xc3\x76\xec\xd1\xb3\x7a\x03\xfb\x30\x09\x2c\x9f\x4d\xce\x0c\x46\xab\xe4\x9f\x6d\xa5\x35\x74\x0c\x83\xab\x85\xa6\xff\x2f\x82\x7a\x03\x6a\x12\x2c\x01\xd3\xcb\x60\x98\xbe\x16\x42\xe0\x56\x6f\x21\x0a\x8a\x54\x7b\xcc\xf4\x49\x8a\x26\x6b\xed\x44\xc6\xb3\xca\x42\xc1\xb8\x31\x14\x85\xbe\x0c\x3d\x3a\x90\x17\xeb\xf4\xbc\xa7\x77\xe0\x9b\x99\xdc\xf4\x2b\x3d\xa5\xfa\x6b\x8a\x6f\xf4\x91\xbf\x63\x3f\x11\x39\x24\x0c\x41\x1d\x43\xa5\x26\x2a\x23\xf8\xea\x82\x76\xea\xdb\x55\x23\xcc\x46\xa7\x8b\x8a\x54\x51\x5a\xc5\x13\x4d\xf9\x70\xc8\xef\xd9\xb2\xeb\x06\x65\xee\xf5\x5e\x49\xe5\x44\xde\x64\xe8\x1c\x47\x5e\x43\x89\x74\xab\x97\x02\x7f\xe7\x1e\xd2\x1d\x85\xd0\xec\x06\x34\x03\xf5\x7a\x51\xae\x14\x11\x82\xfb\xf2\x39\x4d\x0f\xc0\xda\x24\x3d\x12\x27\x19\x1c\x4a\xcf\x46\x61\x6c\xbd\xc7\x6a\x46\x62\x38\x4a\x5d\xcb\x2d\x89\xf3\x99\xcb\x67\x03\x5e\xcd\x8f\x11\x1b\x7f\x76\x79\xec\xbf\x15\xdc\xe4\xc5\xfc\x40\x2d\xf3\x35\x93\x08\xae\xcb\x15\x08\xeb\x58\xc3\x57\x4f\x40\x64\x9e\xa4\x19\x87\xdd\xe3\x48\xad\x21\x0a\x5b\xbe\x8c\x55\x26\x24\x49\x1c\x3a\xbb\x9e\xaa\xf2\x2f\x6c\x2a\x19\x23\xaa\x70\x0d\x5a\xcb\x0f\x32\xc5\x0c\xf0\x73\x5b\x87\x10\x5b\x91\x8d\xce\x72\xd7\xcd\xd1\xd5\xb8\xdc\x01\x66\x4c\x07\xa0\x61\x27\xfa\x8a\x9b\xc8\x59\x98\xed\x32\xb3\x6c\x2d\x65\x61\x6b\x72\x95\xc4\x93\x72\x85\xe4\xa2\xe9\xe7\x47\x6d\x47\xcf\x4d\xdc\x96\xa0\x12\x44\xaa\x0c\xe3\xc1\x71\x71\x14\x23\x8a\x35\xa3\xe0\x06\x3b\x71\xe2\x68\xfc\x52\x46\xd4\x77\xa0\x4d\xe1\xd5\x8e\xc6\xa3\xd8\xdd\xff\x24\x52\xdb\xe4\xc4\x12\xbc\x90\xf1\xa0\x6f\xc0\x38\x39\x38\x6f\xf4\xf4\x58\x0e\xc7\xf6\xc2\xd5\xcc\xbf\x64\xea\x36\xd9\x7a\x0e\xf5\xd2\x77\x6a\x61\x52\x07\xa6\xdf\x5a\x60\xdb\x6f\x0d\x49\xaf\x57\x16\x67\x6d\x07\x26\xbe\x3f\xca\xbb\xb2\xdc\xeb\x07\xc1\x4b\x86\x0d\x37\x14\x36\xf9\x30\x0f\x59\xdb\x1f\xa8\x61\x7a\x15\xe6\x2f\x3e\x1d\x13\x40\x8e\x41\x36\x60\xb3\xed\x8f\x8f\xf5\xa9\xbb\xbe\x2f\x75\x33\x92\x89\x2f\xcd\xa3\x7a\xbd\x96\x00\x91\x97\x0d\xff\x55\xd5\xb2\xe8\x51\x8d\xfa\x55\xba\xe8\x4b\x95\xb3\x19\x8a\xac\xf2\x03\x7d\xef\xac\xf9\x86\xb8\x36\x9b\x50\x50\xb5\xc1\x08\x3f\x9d\x97\xe5\x82\x6f\xc8\x1c\x4e\x49\x49\x00\xbd\x8d\x84\x8f\x84\xe2\x7d\xd2\x4b\xa4\xfd\x0c\x17\x05\x17\x2c\xf3\xcd\x1f\xac\xbb\xb1\x0c\x71\x4f\x6a\x3c\xe2\x81\xa6\xf3\xc4\x57\xcd\x84\xf6\xd5\x4c\xc5\xa1\x96\xaa\xfd\x18\x4a\x15\xcd\x9e\x85\x3c\x71\xfd\xfc\x3a\x8b\x75\x89\x0e\x02\x73\x51\x35\x12\x12\x3c\xbf\xfe\xff\x3f\x50\x43\xed\x3d\xac\x5d\xc1\x92\x62\xde\xa4\xd3\xcb\x36\xd0\xa6\xcf\xe2\xa6\x37\x5e\x42\xc8\x9e\x8e\x31\xd3\xe9\x32\xda\xbe\xb1\x74\x43\xfd\x2b\x74\xe5\x45\x82\x56\xe2\x11\x71\x28\x7e\xdc\x2e\xa7\xcc\xde\x4e\xd7\x3e\xbe\x64\xbc\x01\x08\x7e\x4e\x7b\x19\xc6\x64\x16\x62\x98\x1b\x72\x8e\xca\x16\x49\x8b\x55\x23\x1e\x41\xc2\xbf\x15\x38\x23\x93\x67\x8c\x64\xec\x98\x9b\x6b\x86\xf9\x3e\x6b\xfe\x8e\x48\x09\xa1\x03\xb3\x6a\x07\x61\xac\x47\x76\x77\xb5\xdd\x46\x70\x76\x25\x6f\x1e\x3d\x50\x76\x1e\xc4\xcf\x8b\x9d\x0d\xd1\xb2\xb4\x07\xee\x95\xb2\x0d\x7d\x08\x3f\x77\xe4\xe1\x50\x6f\xce\x0b\x29\xe6\xfb\x81\x63\xe2\xb9\xa9\xe0\xab\x8c\x5e\xda\x7c\x51\xde\xb9\xbe\xcf\x2f\xb0\xd1\x83\xca\x65\x7f\x4e\x14\x9a\x38\x5d\xc9\x77\xd4\x69\xf5\xe0\xfd\x7c\x32\x87\x49\x65\x62\x37\xbc\xfb\x78\xeb\xa7\xa6\x5d\x93\x05\x2e\x76\x62\x65\x4a\x8c\xd4\xe6\xfb\x42\xaa\xe8\x19\xad\xdd\x47\x6a\xe2\x33\xa0\x20\x8c\x98\x87\xb0\x19\x7e\x9c\x83\x6a\xe9\xb2\x5c\x6e\x66\x09\xa0\x3b\x93\x81\x37\x03\x40\xfb\x35\x9f\x59\xc8\x2d\x52\x00\x26\x62\xdc\x8c\xb2\x62\x9b\xdf\xa5\xfd\x66\xf2\x4b\x21\x73\x3f\x6e\xd1\xc8\x14\x25\x23\x89\x6c\x7d\xa8\xdc\x56\x4f\xf0\xff\x8c\xf8\xc8\x7d\x3c\x43\x2b\x72\xde\x15\x6c\x43\x4f\xb6\x24\x25\x9e\x8c\x64\x77\x00\x4d\x96\x7e\x46\x18\xb6\x07\x75\x4c\x92\x8a\xf6\x43\x39\x6c\xb3\x1a\xa5\x88\x40\xba\x11\x02\x43\x6c\x24\xc5\x28\x73\x9d\x43\xe1\xee\x9e\xab\x06\x00\x4a\xe0\x89\xb9\x5d\x17\xf3\xe0\x2b\x68\x67\xc8\x4d\xa5\x81\x87\xa9\x38\xb6\xf2\xc2\x07\xcd\x9e\xd6\xdd\x69\x61\x3b\xbd\x45\x63\xc0\xa9\xee\xe5\x88\xf8\xce\x04\x84\x25\x75\x9c\x08\xb8\x2a\x35\x89\xe2\xff\x0f\xdd\xc0\x36\x57\xfe\x07\xfb\x92\x02\x29\xc1\x7b\xfe\xb0\x6b\x7f\xcd\xe2\xf2\x75\x51\x5e\xef\x45\x41\x46\x76\x8a\x38\x03\x27\x43\x3c\x19\x85\x50\xb9\xd6\x0d\x32\x93\xb9\x4b\xc1\xe4\x8e\x6e\x7a\x8c\x36\xa7\x51\x86\x10\x60\x21\x45\x94\xde\xad\xce\x99\x04\x3a\xd8\x9b\xdb\xe9\xc4\x7b\x48\x67\xfa\x18\x8c\x2b\x36\xe7\x94\xf3\xb9\x1c\x06\xf2\x5b\xf4\x48\x92\x16\x71\x76\x3c\x72\x49\x7a\x80\xc2\x27\x79\x33\x32\xb7\x9a\x98\xdd\x86\xcc\x67\xed\x10\x64\x3f\x6d\x44\xba\xfb\xbc\xba\xc6\x3f\x73\x3a\x80\x2f\xa8\x2e\x25\x11\xff\xc9\xa3\x51\xdc\x23\xe5\xcb\x4f\xfa\x81\x61\x14\xc5\x83\x40\x94\x6a\x73\xfc\xfb\x55\x58\x99\x08\xa1\x5c\xb7\x22\xa5\xe8\x6e\x55\x07\x2c\x7f\xc6\xe8\x2a\xf7\xf4\x38\xe4\x2d\x7f\xa9\x26\xd1\x5c\x17\xe9\xf6\x5a\xe9\x6e\xd6\x9a\x5b\x20\xdc\xc3\xb3\x20\xc0\x61\x60\x29\x7c\x80\xab\x69\xb0\x55\x31\xfe\xca\xc9\x14\x75\x95\xa1\x37\xd7\x64\x33\x9c\x42\x21\x3f\xe1\x98\x44\xac\xa7\xa1\x1c\x1b\x3c\xbc\xc6\xab\x61\x39\x0e\x97\x30\x4c\xb8\xe5\xec\x00\x54\x80\xf3\xdb\xb7\xd0\xb1\x9c\x1b\xd6\x7e\xbb\x70\xd7\xa6\xef\x71\x3b\x6b\x0a\x40\x2d\x03\x02\xa4\x43\xd5\x97\x79\x0c\xc8\xa1\x63\xcb\xdf\xc8\xb5\xa5\x7a\x21\xc1\xf6\x19\x8c\x5a\x97\x70\x3f\x36\x96\x16\x6d\x48\x98\x6f\xa0\xb1\x05\x57\x7e\x99\x1d\x9f\x8f\x8c\x30\xd4\xb5\xf0\xd6\xb3\x14\x79\x30\x21\x02\x55\x62\xe8\x41\xd9\x82\xee\xe2\xef\xc7\xfd\xc6\x3d\x67\xb6\x0b\x04\x1d\xec\xd6\x55\xb0\xf7\x60\xaa\x74\x62\x88\x19\x19\xae\x20\x7b\xc1\xe9\xf5\x11\xfb\xf8\x94\xea\xd3\xab\x64\x16\x9e\x3f\x58\x72\xbd\xd5\x2b\x34\x29\xa2\xd3\x05\x91\x0c\x33\xec\x76\x96\x45\x9b\x97\x9d\xe1\xe8\x0a\xd3\xc3\x09\x10\x56\xf2\x23\x09\xea\x0f\xe9\x24\x89\x2b\xa1\x44\x87\x12\x08\xb4\x14\xe0\xe0\x44\x3a\xa1\x27\xbf\xa7\xcb\xb2\xb7\xf7\xd0\xbe\x89\xd0\x3c\x53\xdc\xb2\x89\x75\x65\xff\xed\x53\x50\x89\xa8\x4c\x0c\x5e\x70\xda\x11\x73\xd4\x67\x98\x69\x5c\x83\x3f\xc3\x20\x8a\x32\xed\x6a\xa5\xda\xda\x57\x55\x7b\x1c\x7c\x4d\x12\x62\x87\x8b\x59\x0c\x5d\xcc\x4c\x34\xd6\xfc\x30\xbb\x5f\x97\x08\xe1\xa5\xa9\x2d\x48\xc1\x66\xab\xac\x5f\x40\x21\x03\xf7\x92\x1b\xa7\x35\x84\x43\xe8\xa5\x64\x81\x76\x45\xb9\xfc\x35\xa3\x25\x7a\x1f\x80\x40\x2e\xd0\xfe\x32\x99\x1c\x96\x71\x78\x4d\xf2\x82\xfb\x31\xae\x43\xac\xe0\x1d\xa7\x2d\x84\x8f\xa8\x7c\x4f\x34\xc6\x29\xf3\x52\x65\xf9\x87\x68\xbf\x6d\xfd\x19\xd6\x3a\x21\x2a\x9c\x4d\x89\xf7\x98\xb0\x00\x38\xed\x57\x86\xde\x28\xd2\xd4\x92\x52\x94\xfd\x72\x8c\xce\x40\x15\x50\x37\x76\x84\xc2\xfe\x50\xcd\xc9\xd2\x50\xf3\x67\x14\x3c\x99\xce\xf6\x92\xeb\x94\xe7\x1d\xfb\xb4\x15\xe7\x4f\x5e\xb2\x70\xf4\x8b\x42\xda\x2a\x1e\x2b\x2d\x68\xc2\xf3\xee\x6d\xe5\x48\xc2\xf1\xa5\x5c\x14\xca\x90\x75\xe5\x19\x67\x4d\xaf\xf2\x8d\xdb\x9f\x3e\xc6\xa6\xc1\x58\x2a\x29\x05\x17\x6e\x1e\xb1\x24\x4a\x19\x71\x78\x38\xb7\xe8\x98\xde\x83\x29\xc3\x04\x3d\x20\x70\xd7\x83\xfc\x7b\xda\xf9\xd0\x66\xd8\x0f\x53\x9b\x85\xce\xbd\xe9\x2b\xb3\xd2\x62\x52\xc5\x52\xee\xfb\xbf\xe0\x80\xaf\x7b\xca\xbc\xda\x03\xa7\xf6\x4d\x61\xdd\xdb\xc1\x78\xfd\xa9\xca\xc7\xf9\xbe\xdc\x44\xf8\x2d\xde\xdf\x5a\x09\xff\x84\xa1\x2e\x7b\x16\xb6\xb4\x63\xaf\x3e\xd8\xac\xc6\xcd\x96\xea\xc1\xb4\xfc\xf4\x01\x7c\xdd\xa1\xfe\x85\xe1\xc9\x07\x07\x64\x81\xe5\x0a\x71\x4d\x9a\x47\x27\xfb\x6c\x6d\xdf\x99\x9c\x66\xa4\xc4\x62\x23\x06\x00\x3d\x64\x15\xda\x29\x9c\xa7\x98\x8e\xb9\xf9\x5a\x24\x98\x0d\x54\xe2\x25\xae\x2e\xee\x16\x91\x72\xd8\x2c\x4e\x59\xbc\xf2\xe4\xd6\xfd\x01\x57\x86\x02\x3c\xa9\xa8\xa1\x05\x42\xc5\x7e\xdb\x3d\x46\xd9\x0a\x4f\xa3\xfa\xe9\x0f\xd0\x1d\xa3\x3f\xc4\x15\xd3\x29\x12\x46\x6f\xb4\x43\x3d\x6a\x5b\xec\xce\xf3\xe7\x5c\x68\xee\xc1\x08\x34\xdc\x90\x20\x6a\x16\xe1\xdd\xa3\x8d\x0c\xf7\x5c\x88\x80\xc7\x93\xdd\x9d\xf5\xd8\xd3\x31\xeb\xa4\xcf\x35\xc2\x8f\x6a\x63\xff\xd9\x61\x36\x06\x55\xe8\x74\xf6\xfd\xdb\xae\xe8\x30\x05\x72\x49\x3c\x03\x9f\xc9\x41\xf0\x19\x6f\xe8\xa8\x17\xbb\x12\x6a\xde\x99\x5d\x01\xa0\xeb\x47\xdf\xae\xdf\xee\xc2\xec\xb5\xca\x5a\x7f\x73\xfc\x9e\xca\xe4\x39\x0c\x16\x95\x89\x19\x4b\x27\xc2\x04\x65\x97\x7d\x62\xa7\xbc\xd7\x17\xe8\x00\x91\x1d\xc5\xac\xd1\xea\x14\xaa\x51\x4e\xcf\x4e\xe7\x37\x94\x6c\xe3\xa6\x79\x72\x5f\x5a\xe6\xb3\x9d\x8b\x03\xcf\x33\x37\x1b\x37\xc9\xef\x44\x2e\x88\xb0\x42\x73\x02\x29\xbf\x68\x77\x8f\x1f\x1c\xe7\x68\xf5\x55\x91\x8d\x66\xb3\xec\xd1\x3b\x67\x71\x3b\xd8\xbe\x7c\x90\x7d\xc9\x81\xd3\x5d\xc2\xd6\x42\x94\x34\x5a\xdc\x48\xf1\x0d\x71\xcd\x3c\x2e\xbf\xa6\x46\xc3\x5e\xee\x47\xc8\x94\x42\x81\x72\xe5\x0f\x75\x76\xa1\xe6\x20\xb6\x69\xb1\x07\x3b\x4c\xe2\xdd\xa7\xae\x28\x7f\x14\x1b\x89\xed\xb7\xa3\xaa\x84\xce\xc4\xa2\x54\x54\x01\x45\x64\xc8\x75\x6d\x59\xee\x0f\x8e\x93\x8b\x9f\x4e\x91\x46\x62\x5c\x3b\xf9\xb8\xf8\xa4\x32\xc6\xaf\xe3\x14\x3b\x9d\xf5\x09\x65\x64\x5f\xaa\x5b\x70\xbd\x3a\xe3\x20\x3c\x01\x88\xbe\x0f\x61\x33\x35\x88\x47\x90\x4e\xaa\xba\xe6\x43\x96\x7c\x41\x93\x9e\xe9\xbd\xa5\x6f\xe4\xba\x07\xb0\x88\xd0\xf9\xe7\x07\x8d\xd6\xcb\x7c\xdb\x04\x80\xbc\xc3\x57\x06\x47\xae\x8f\x6e\x0a\x56\x40\x50\xe5\x6c\x6a\x16\x0b\xdf\x34\xb1\xea\x50\x68\xb5\x28\xe1\xae\xa4\x72\xda\x56\xd3\xd2\xc6\x0e\x94\x5b\x4b\xfd\x7d\x54\x2d\x98\x59\x70\xb4\x38\x77\x54\x2b\xc7\x58\x85\xeb\x48\xf0\x7f\xc9\xbd\x45\x15\x5b\xae\x3a\x92\xea\x52\x62\x59\x44\xdc\xab\xee\x26\xfe\x3a\x2e\x3c\xd0\xa2\x77\x76\xc8\x04\x64\xc1\xd5\x1c\x40\xab\x6f\xd3\x1f\x61\xcd\xc8\x57\x4b\xb4\x80\x93\x72\x00\x43\x65\xf3\x6a\x18\xed\x4d\x41\x04\xa9\x2c\x12\x35\x70\xd5\xfd\xef\x39\xd4\x8e\x9e\x11\x6a\x8c\x3d\xa9\x01\x82\xd8\x8c\x93\x1d\x97\xdc\x51\x29\xaa\xcf\xe8\x32\x46\x3a\xd7\x89\x6e\x3f\x82\x3b\x33\x3f\xf5\x73\x21\xdc\x7b\xe5\x93\x16\xa5\x1c\xfd\xd7\x6b\xcc\x60\x46\x14\xf8\xa9\xab\x3d\x99\xea\x33\x10\x10\x8a\x69\x95\x44\xa9\x09\xb0\x8e\xaa\x5c\xb8\x82\x2b\x6e\x39\xc3\x08\xa1\x16\x0b\xfb\x01\x6b\x39\xeb\xf7\xea\x27\xbf\x5f\x00\xb8\x36\x08\x47\xa0\xd9\x80\xbb\xd3\x2b\xaf\x02\xbf\x89\xf8\xb7\xaf\x52\xe2\xe9\x12\x0f\x52\x93\xfb\x96\x3c\xaf\x8c\xf2\x7a\x2b\x67\x4c\xab\x12\x6d\x46\xd3\x26\xe9\x35\xa4\x2b\x83\x23\x4b\x21\x00\xe1\xbb\xd8\x73\xf4\xd1\x17\x5d\xf4\x6f\xbb\x9f\x19\x53\xe6\xd5\x9e\x75\xfc\xf2\xcc\xd9\x66\x42\x0e\x43\xcc\xc9\xd3\x04\xcd\xe8\x69\x8d\x7a\x71\xd2\xcc\x0a\xbe\x52\x31\x7e\xd1\xb3\x5c\x53\x8d\xa2\x72\xf8\x40\xd5\x50\x86\x18\x3c\x28\xa5\x76\xc7\xe2\xb8\x2a\xa0\xb9\xbb\xf2\x9d\xd9\xf4\xbf\xba\x20\xc4\x44\xdf\x40\x04\x33\x8e\x65\xf9\x0e\x1d\x9b\x07\x95\xe6\xe2\x46\xf7\xe3\x0d\x56\x10\x26\x06\x05\xac\x1d\xfc\xee\x8b\x5e\x95\x0c\x17\x98\x22\xd6\xbf\xb0\x1e\x5e\x57\x39\x50\x7b\x88\xf4\x32\x39\x75\x03\x09\x0e\xc3\x90\x97\x17\x92\xd4\x07\x22\xd5\x1f\xbc\xd6\x17\x5e\x27\xbe\xac\xd4\x27\x5c\xe2\x04\xcf\x70\xbe\x0d\x51\x48\x5a\x92\xa0\x20\x8b\x26\xfa\x43\x51\x6e\x6b\x5b\x2d\x3c\x11\x21\xaa\x6e\x43\x59\x19\x1f\x27\x96\xd3\x44\xf0\x66\x30\xe0\x11\xa1\x92\x2a\x77\x9a\xc3\xfc\x5c\xa5\xfd\xb6\xe4\xe2\x6e\x0a\x3b\xda\x81\x03\xfe\xcb\xfb\x9a\x4a\x35\x4a\x65\xd8\x4a\x5c\x46\x5c\xc5\x27\x56\x7e\x06\x46\x7c\x94\xf6\x8f\x68\x6d\xc2\x3c\x46\x11\xbe\x77\x36\x2b\xdf\xd8\x66\xbc\x94\xf1\x4e\x5b\x35\x71\xa2\x45\x64\x2f\xa1\x0e\x03\x18\x1e\xef\x56\x97\x3b\x0a\x76\x7b\x3e\x36\xea\x8f\x4b\x99\xb8\x7b\xee\xf0\x4a\x6b\xfe\x93\x1f\xa9\xa3\x57\xcc\xf7\x99\xd1\x4c\x8a\x07\x64\x25\xdf\x06\x07\x76\x5b\x4c\x74\xa8\x2c\x73\x2f\x75\x8b\x23\x4c\xae\xb7\x72\x5b\x8a\x19\x20\x85\x67\x07\x18\x43\xaa\xfd\x48\x89\xb6\x8f\xbd\x17\xe4\x25\x01\xfa\xce\x14\x5b\x82\xea\x68\xb2\x71\xb3\xa3\xfa\x2a\xb0\xc0\x3c\x96\x24\x45\x00\xa2\x98\x0b\x7b\x3d\xf5\x67\x18\x73\xdb\x58\x7b\x53\x4c\x5c\x03\xc2\x41\x08\xfb\x76\x6e\xbb\xd4\xff\xaa\x93\xfe\x38\xec\xdf\xe9\x5e\x31\x6b\x1a\xfc\x1b\xdb\xac\x67\xe8\xd5\xf9\xa8\x6a\xb1\xca\x2e\xd0\x66\x49\x7b\xdf\x08\x12\x9e\xc5\x67\xeb\x7b\x6b\x11\xa9\x48\x7a\x20\x05\x18\x03\x07\xd0\x2a\xcd\xaa\xed\x4a\x22\xeb\xd2\x09\x69\x25\xf0\xe7\xd0\x5f\x91\x1a\xdb\x2e\x4c\x9d\xde\xe9\x01\xba\xf8\xd9\xad\x91\x28\xd9\x38\x37\x5b\x7f\x1e\x2e\x52\xa6\x3b\x57\x8a\xcf\x34\xd2\x59\x94\x37\x8b\x72\x81\x80\x75\xc8\x18\x2b\x05\x81\xa4\x88\x2d\x67\xcc\x26\xb6\x02\xf4\x2b\x2f\x8f\x0b\x61\x2d\x07\x75\x86\xfe\xcf\x2a\xcf\x5e\xe0\xe4\x19\xc2\xf6\x52\x8e\xdc\x47\xdc\xaf\xd1\x89\xf4\x38\x62\x54\xde\x1c\xdf\xde\x4f\x62\xb1\x1e\x8e\x82\xb4\x34\xff\xa1\xec\x99\x20\xd8\xf6\xb8\x15\xfe\x85\x5c\xc1\x1c\x05\xfb\x45\x6c\x6a\xcd\x0b\xa0\x8e\x7f\x8b\x57\x99\x8a\x82\x92\x4f\x05\xfe\x60\xc1\xdb\xa2\x0a\x4e\x33\x32\x24\x2b\xde\xc7\x6d\x0c\x5f\xbd\x0a\x06\x56\x21\x55\xd0\x12\x59\x82\x44\xab\xf7\xa9\x5b\xf6\xfc\x62\xe3\x01\x19\xc9\x2d\x7d\xf1\x5f\x7c\x82\xcb\x24\x8a\xe4\xa7\x74\x12\x88\xa4\x2f\xf8\x36\x3e\x99\xe6\x78\x36\x80\x77\x2f\xc1\x41\x7e\xb6\xea\x9c\x48\x1c\x20\x60\xd0\xab\xaa\x95\x75\xe8\x41\x87\xde\xbe\xfc\xc5\x7d\x0a\xa0\x3c\x3d\xec\xd3\xdd\x12\x3c\xf1\x2c\x33\x80\x25\xfe\x9e\x1f\x32\x93\x82\x58\x71\x20\x05\x6e\x7d\xe1\x07\x5d\x7f\x88\xb0\xbf\x4a\x51\xae\x7c\x09\x86\xff\x27\x20\xa2\xd7\xc0\xb3\x8c\x33\x41\x05\xf8\x29\x19\x8f\x2b\xf5\x94\xee\x5c\x80\xa6\x39\xc4\x59\xb4\x76\x0b\xd8\x79\xa9\xf8\x0b\xe9\x61\x29\xb4\xc0\x4f\xb1\x57\xa4\x56\xb0\x49\x1b\x1a\x67\x4b\x65\x2e\x9b\x59\x61\x92\x3d\x56\x8c\x26\x3f\xe9\xb1\x55\xcb\xe4\x0f\x6c\x9b\x97\x75\x10\x45\x74\x89\x21\xab\x81\xb8\x2d\x6f\xc9\x4f\x3e\x95\x2a\x8b\x1d\xf6\x3a\x6c\x65\x96\xe7\xf5\x66\x04\x45\xa5\xcd\xe5\x9e\x93\x35\xf0\xbe\x72\x09\xc6\xfd\x75\x1a\xeb\x28\xb1\xeb\xe4\x84\x5b\xa3\x5c\xb2\x78\xbc\x14\xc9\x80\xf6\x0b\x51\x50\x61\x1e\xb6\xc6\x14\x67\x65\xb6\xd5\x0a\x5d\xdf\x06\x17\x89\xdf\x6e\x6c\x23\xfe\x22\xb3\xc9\xc6\x6a\x5e\x04\x03\x45\x84\x01\xfd\xad\x19\x40\x77\xf9\x67\xba\xff\xb3\x67\x86\x5d\xc9\xe6\x00\xf3\x32\x07\xd9\x5e\x3f\x50\xb4\xbd\xc9\x8b\x18\xf8\x71\xbc\x6e\xf6\xe3\x3b\x94\xbb\x2b\xfc\xfb\xf0\xcf\x10\xe6\x71\x80\x9a\xa6\x57\x36\xc9\xb7\xda\x03\x5e\x44\x74\x90\x4f\xd5\x5b\xce\xf7\x43\x2d\x5b\x9c\x12\xf8\xde\x82\x2c\x85\x22\xe3\xe7\x3a\x35\x5c\x93\xa1\xf9\x09\x10\x59\x82\x20\xcc\xb3\x7a\xb4\x7e\xeb\x0b\xe2\xd4\xa8\x68\xa7\x91\xc7\x9a\x16\xad\xf6\xc0\xed\xe9\xb9\xf7\x46\x7b\x67\x40\x94\x7e\x2f\x3c\x07\xd9\x8f\x44\xc7\x39\x31\x14\x06\x99\xb0\x68\xed\x06\x14\xa5\x72\xb1\x39\x9e\xd5\x3d\x44\x94\xa5\x14\xe7\x95\xc9\x12\x8a\xb9\xf8\x1b\x08\x6e\x84\x81\xb0\x65\x95\x47\x54\x78\xcc\x60\xc1\x4d\x0e\xa8\x68\x36\x6f\xba\x0a\xb7\x6e\xce\xeb\xe0\x97\x69\x41\x62\x5a\x67\x5f\x5c\x2a\x14\xa7\xa8\x15\x40\x29\xe1\x59\x71\x59\xd8\xbb\xd4\x23\x6e\x1f\x8f\xc1\xa2\xf8\x2c\x1f\xdd\x05\x41\x1d\xb1\x63\x42\x64\xae\x61\x51\xcc\xa9\xed\x44\xbc\xe8\x77\x57\x05\xdb\x18\x24\xca\xa3\xc1\x96\x6d\x09\x24\x73\x1e\x76\x17\x20\xab\xf2\x43\xf7\x70\x18\x03\x11\xd3\x66\x04\xe6\xb3\xae\xcc\x4d\x08\x17\xe4\xaa\x1c\x55\x46\xa5\xe0\xb2\x16\x0d\xf6\x35\x10\x6d\x1e\x93\xd9\x45\x09\x61\x65\x86\x14\xe0\x7e\x1b\xff\x94\x1e\xa0\xfa\x36\x35\x09\xca\xbb\x4e\xe7\xd9\x14\x76\xb8\xb3\x63\x4d\x09\x9f\x5b\xba\x7b\x87\x47\x69\x9a\x68\x03\xd0\x9f\xa5\xb7\xf7\xa5\x59\xe5\x51\x92\x77\x99\xbb\x2e\x9d\xc9\xda\x57\x01\x38\x61\xf3\x34\x4e\xae\x94\x86\x07\x67\x8f\xde\xe4\x91\x53\x90\x04\xdc\x0a\x2a\x23\xaf\x9d", 4088);
*(uint64_t*)0x200014a0 = 0xff8;
*(uint64_t*)0x200014a8 = 9;
syz_mount_image(0, 0, 0x1001, 2, 0x20001480, 0, 0, 0);
	return 0;
}