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

*(uint64_t*)0x20000200 = 0x20001300;
memcpy((void*)0x20001300, "\x55\x63\x0f\x2c\x0e\x16\x5f\xc2\x5e\xcb\x9b\xea\xe5\xb7\xa1\xf2\xb7\xbe\xe4\x52\x9e\xd0\x47\xeb\xa9\x21\x64\x55\x4d\x44\x55\x99\x80\x66\x1d\xb1\xe9\x46\x07\xfb\xa7\xf2\xdb\xa2\x91\xc9\x45\x70\x64\x37\x10\x4c\xb0\x20\xe8\x96\xb1\xb4\x2a\x32\x1e\xb7\x40\xf8\xbe\x05\xa7\x04\xbe\x45\xff\xa7\xc0\xcc\x25\xf5\xce\xb9\xed\xdf\xe8\x81\x6a\xd9\xfd\x47\xa0\xbd\xef\xd6\x1a\x06\xec\x7f\x00\x7c\x2b\x90\xf1\xce\xea\x7f\x8e\xd7\xab\xf7\x0f\xc1\x7f\x11\x4c\x1f\xc9\x9d\xe6\xe4\xdc\xae\x5c\x27\x87\xda\x9e\xe6\xba\x30\xbf\xf9\xe4\x9d\x13\x93\xfc\x45\x44\x67\x6d\xf9\x3c\x0a\x35\x86\x8f\x91\xc4\x38\xe6\x67\x9c\xd7\xdc\x5f\xdc\x20\x98\xf8\x5f\x88\x9f\xfb\x31\x7f\x1a\xed\xdc\x67\xf7\x21\xeb\xd1\x8b\x42\x30\x15\x2f\x16\xb3\x97\x61\x7c\xf0\x55\x2a\x68\x39\xc5\x22\x88\x6a\x1c\x8b\x65\x5b\x17\x13\x59\x5d\x94\x25\x01\x36\x86\xe1\x78\x3c\xa3\x56\x7d\xe9\x6b\x21\x85\x38\xc2\xa8\x00\x5e\x9e\xd6\x5e\xd6\x3c\xee\xc1\x45\x9e\x4d\xf9\x67\x59\x9d\xfe\x1b\xdd\x72\x3b\x5c\x9c\x16\xd9\x1b\xcc\x2b\x8f\x59\x62\xa7\x21\xcd\x97\x8d\xa7\xfc\xd9\xd9\xad\xa1\xd6\xa4\xc2\x6d\x87\xe8\x7d\xcd\x46\x15\xec\xc7\x48\x9f\x29\x69\x0d\x45\x4a\x13\xd0\x99\x10\xd7\x22\x8c\x6a\xec\x1a\x76\x72\xb2\x2d\x2a\x9e\x71\x30\x45\xc9\x23\x2f\xe4\x56\xbc\x57\x9d\x46\xdd\xcc\x74\xf0\x9b\x36\x79\xcf\xa8\x7b\x70\x8b\xb6\x63\x71\xa1\x8b\xda\x56\x8c\xed\x26\xa7\xc8\x19\x7d\x3a\x7b\x95\x1f\xf5\x25\x49\x30\xc0\x48\xd8\xb3\x8e\xfd\x12\x28\xd2\x15\x06\xf6\x6b\x95\x68\x0d\xd8\xae\xf4\x5b\x1d\xca\xa9\x65\x4b\x12\x7b\x8b\x3a\x26\xd6\x11\xa6\x38\x55\x1d\xb3\xd1\xe8\xe7\xae\x4e\x33\x7c\x55\x18\xd3\x87\xab\x41\x85\x55\xf1\x56\x9c\x2d\x47\xcb\x10\x62\xb7\x91\xdc\x2c\x30\xb7\xa8\x68\xb2\x0a\xe5\x10\x79\xb1\xa6\xf0\x2f\x21\x12\xe5\x18\xd5\xc7\x51\x6d\xdb\x4f\x53\xbb\x9c\x79\xd0\xfd\x03\xf6\xac\x41\xdb\x48\xa1\x24\xf6\x67\xdf\x80\xeb\x70\x87\xaf\x57\x57\x59\xaf\xf9\x2e\x7f\xe7\x6f\xb0\x37\x87\xff\x94\x06\x27\xff\x61\x39\xed\xdc\xdd\x86\x4c\x60\x64\xd6\xc3\x76\x17\x82\xde\xed\xda\xb2\x86\x75\x23\x80\xac\xf3\xdf\x51\xd2\xb7\xb4\x3f\x86\x53\xba\xf2\x62\xc5\x1b\xc9\x37\x88\x25\xa7\xa8\xc5\x97\x08\x09\xee\xd4\xad\xb7\xc0\x12\x85\xbc\xc5\x6c\x03\x9a\x63\x4f\x15\x91\xe0\x54\xf8\xb1\xb1\xab\xc0\x1e\xa5\x60\x25\xdb\x4f\xea\xdc\xb1\xf8\x80\x80\xf7\xd7\x08\xb5\x03\x33\xd5\x12\x07\x98\x0c\xcb\x4f\x09\x26\x49\xb4\x4b\xca\xd6\x4b\x7e\x7a\x2a\x42\x0a\x47\xe7\xc5\xd8\x15\x96\x31\x33\x29\x8a\x95\xbb\xb3\x64\x4d\x05\xa8\xf0\xfe\xbd\xe4\x9e\xf1\x1b\x66\x7d\xfd\x0a\xd8\x6a\xdd\x3c\x11\xe2\xde\x4b\x89\x59\x5c\xcf\x5e\x37\x76\xec\xc8\xae\x13\xb7\xcd\xa7\xe9\x22\x53\x4d\x5f\x77\x7e\x3c\x47\xc6\xec\x0e\xba\x98\x57\xd1\x25\xbb\x8d\xf3\xc3\x90\x7e\x5c\x19\x5a\xc3\xc4\x89\x40\x18\x79\xed\xb9\x50\xe4\xd4\x5c\x61\x6e\xec\xa3\x0a\xc7\x5f\x65\x82\x50\x5a\x75\x96\x83\x31\xee\xfd\xa8\x0f\x72\xd7\x0b\x05\x47\x6a\x93\xd0\x18\xa2\x7c\xbf\x16\x1d\x67\x0f\x5c\xb1\x6a\x59\xa8\x1b\x7a\x4c\x29\x94\xe8\x7b\x2b\x5a\xd7\x78\xd0\xee\x76\xa0\xff\xfc\xbd\xa6\x78\xf4\x3d\x3e\x8c\xa7\x8a\xa6\x6f\x4a\x4e\x1d\x42\x2f\x54\xff\x0b\x9d\x75\xcd\xea\x21\x22\xed\xba\x5a\xa0\xe1\xf8\xfc\xa7\x14\xa2\x26\xc1\x1a\x22\x4d\xff\xdf\x88\x14\x78\x49\x32\x40\x53\x3a\xb8\xd2\xd5\xdf\x3e\x2c\x12\xea\x22\x59\xb1\xea\xd8\xdb\xc6\x1f\xbd\x86\x35\x29\xa8\x16\x3d\xee\xf5\x8b\x8f\x8b\x04\x7f\xdb\x7b\xed\xf8\x67\x51\x0e\x46\xd1\xc1\x54\x2c\x42\x9e\x17\xf3\x41\x5a\x9b\x64\xa1\x06\x30\x9a\xb1\xb5\x61\xd1\xab\x70\xde\xd5\xfb\x8c\x95\xa7\x74\x42\x1b\xa5\x68\xd4\x67\x5c\xed\x66\x9e\xa7\x5d\xc0\xe0\xa4\x41\x25\x8b\x95\xd1\xac\x62\x52\x40\x0c\x4a\xdf\x81\x9e\x9f\x93\x89\x61\x5e\xa2\x4e\xfb\xcb\x50\xed\x57\xa4\x84\xb0\x0b\x48\x58\xcf\xa4\x70\xa0\xf7\x47\x4d\x0f\x54\x19\xff\xd1\x44\x1a\x9c\x50\x7e\xeb\xd1\xa8\xc3\x06\x6a\xf6\xd0\x64\x77\xef\xf4\x17\x03\x87\x01\xe4\x5e\xc7\xf7\x2c\xc1\xd6\x34\x50\x3f\xa3\x89\x1a\x78\x93\xa6\x70\xc1\x82\x09\x36\x06\x20\x45\x42\xf5\x84\x78\x76\xa4\xa6\x57\xcb\x09\xa2\x8b\xa5\x22\x9b\xa9\x21\x0b\x3e\xd6\x29\x38\x25\x7b\x2b\xb4\x72\x3b\x32\xb9\xc1\xfc\x7c\xd5\x34\x55\xa1\x23\x3a\x3a\x20\xd0\x49\x0d\xa8\x61\xb7\x9c\xc5\xd4\x7b\x52\xd5\x7a\x00\xa0\x7f\xc3\xe2\x99\xe1\x43\x9c\x92\x19\x2d\xa4\xe6\xe5\xdb\x38\xcd\x2d\x76\x53\xd3\x2c\xd3\xca\xd3\x52\x87\xe9\x2c\xc8\x27\x87\x3f\x97\xe1\x74\xba\xda\x2f\xdc\xd0\x14\xc3\x02\x3d\x57\x31\x64\x13\xb0\x28\xdf\x51\x09\x52\x01\xd9\x9d\x5a\x5f\x8a\x1e\x76\x17\x35\x2f\x58\x27\xfe\xad\x9e\x2c\x12\x8e\x20\x0b\xa7\xda\xdc\x26\xe5\x43\x2f\x94\x92\x32\x26\x2b\xef\xb9\xb5\x9a\xd1\x2e\x34\x4e\xeb\x17\x29\xb0\x47\xa5\x95\xb3\xa4\x63\x25\x1d\x5b\x4e\x47\x87\x0a\x39\x5e\xe4\xdc\xf0\xfa\x0f\x04\xb2\xfd\xa6\xb0\x4c\x94\x8d\x5c\x01\x38\x11\x51\x96\x18\x66\xed\xa4\x5c\x5f\x70\x62\xf2\x98\x45\x3a\x0c\x1f\xc1\xf4\x5b\xf0\x2b\x3d\x42\x80\x36\xa9\x8c\xc9\x50\xa6\xac\x25\xa3\x2b\x1d\x5f\x17\xed\x26\xca\x21\x4e\x40\xe5\x04\xc9\xb6\xa8\xf3\x41\x81\x94\x38\xdb\xab\x5e\xb4\xcc\x2c\x99\xb9\x34\x0e\xe9\x5c\xb3\xdf\x26\x23\x39\xf8\x30\xa2\x47\xff\x17\x84\xc2\xd6\x3f\x80\x13\x0e\x70\xfe\x81\x54\xd7\x63\xc3\xff\xfd\x02\x27\x2a\x41\x18\x78\x6d\xd1\xae\x61\xef\xb2\x27\xf8\x7c\x86\x85\xf2\xa9\xf1\xb9\x01\x1e\xc7\x7b\x95\xd4\xa6\x5a\x10\x2e\x17\xfd\xcb\x9f\x2d\x62\x68\x6c\x26\x41\xdd\xdd\x4d\x68\x0b\x25\x5e\xd4\xfd\xe1\x31\xce\x3c\xeb\x0a\xfc\xf8\x9c\x7e\xff\x5c\x7c\x5e\x6a\xbc\x2a\x1e\x63\x46\x03\xdf\xcf\x1b\xbd\x1b\xba\x44\x6b\xa3\x46\x55\xb5\x48\x84\x17\x8c\x99\x36\x78\x30\x3d\x4f\x66\xeb\x19\xe0\x3f\x0a\xff\x57\x21\xf7\xc8\xa2\xd8\x9a\x18\x06\x03\x13\xb4\x55\xc2\xd7\xe2\xce\x6d\xf7\xed\x4a\x55\xbe\x75\x0a\xb3\x78\x52\xf3\xd0\x65\x52\x82\x4c\x8c\xc7\x0c\xe8\xb5\x5c\xae\x73\x55\xf6\x68\x0d\x64\x29\x90\xcf\xb9\x0d\xfd\xd6\xa3\x78\x58\x13\x20\x1c\x67\x48\x66\x71\xcf\xfe\x49\xab\xf9\xdc\x8e\xc4\xc6\x6e\xd2\xca\xb7\x04\x17\x76\xff\x47\x21\xa7\xf1\xf1\x24\x37\xda\x5d\x5a\x5a\xe9\x54\x80\xde\xe1\x15\x20\x9e\x8f\x43\x30\x83\xda\xd1\x0e\x2d\xcf\x81\x41\x5d\xdb\x05\xfc\xc9\xd0\xf5\xc2\x21\x57\xb7\xf6\xb5\x27\x20\x6e\x1e\x7c\x5b\x9e\x6e\xfb\xd7\x82\x09\x1f\x95\x71\x6d\xbf\x44\xca\xdf\x95\xbf\x06\x20\x33\x6d\x18\x7a\xcf\x41\xdb\x88\x78\xe3\x64\x24\x3a\x4c\x64\xfc\xc8\xa2\x05\x04\xe3\xac\x1c\xce\xa1\x73\xc7\x21\x89\x66\x87\xc2\xea\xad\x33\x34\xcc\xc3\x49\xfb\x71\x57\x9a\x6c\xf7\x24\xf8\xee\x2c\xf3\x85\xc8\xbd\x5d\x98\x30\xfc\x5c\x92\x96\x59\x24\x3e\xa0\x76\x81\x81\x67\x67\xe1\x9f\xcc\xce\x96\x80\xea\x68\xd4\x5d\x31\x4d\xf1\x7d\x14\xf4\xa4\x02\xd3\x2a\x74\x5f\xb5\xc3\x85\xe2\xad\x01\xda\x59\x93\x44\xf3\x6a\xe6\xcf\xfb\xc8\xf0\x7b\x3e\xd8\x88\x16\x0b\xac\x86\xde\x73\xa1\x26\x39\xb0\x88\x18\xa8\xb9\xd8\x94\x8e\x77\x53\xec\xed\x80\x04\xb3\x34\x19\xa4\x70\xc4\x11\x0a\x8a\x07\x78\xfa\xa4\x5b\xe5\xeb\x46\x7f\x6a\x23\x39\x7e\x56\x16\x60\x19\x94\xd2\xe2\x25\xd6\xfb\x94\x8d\x49\x82\x1f\x03\xbf\xac\x89\x22\xc1\xd9\xe1\xd0\x89\x78\x34\xcc\x8f\x28\xb8\x7a\x21\x00\x22\x48\x53\x3b\x19\xe2\x3c\x85\x08\xfa\x0f\x2b\x15\x23\x9e\x74\x34\x36\x12\xfd\xcb\x12\xb7\x84\x40\x9d\x19\xe9\x12\x10\x07\x41\x0f\x57\x44\xdd\x01\xb2\x0f\x1f\xf9\x44\xf8\x31\x88\x03\x70\xb8\xa1\x2c\xf5\x13\x1e\x70\x9e\x3f\x00\xef\x86\x04\x4a\x0e\x77\x6a\xa2\x20\xf8\x7e\x33\x56\xb4\x22\xcd\x6e\xf8\x55\x1c\x76\xae\x25\xf3\xc4\x8f\xcd\x89\xdc\xc1\xda\x20\xc2\x85\x03\x25\x18\x96\x3c\x8f\x39\x0a\x23\x3b\xad\x6f\x75\x6c\x75\x4e\x98\x6a\x4c\xa7\xc6\x9f\xaf\x10\x78\x55\x82\x0d\xa9\x4e\xc5\x27\xff\x8e\xae\x78\xb8\x31\xca\xd8\x51\x39\x95\xea\xf7\x52\x64\x0a\x45\xef\x4a\x39\x4b\x62\xd9\x6e\xb2\x23\xae\x67\xf8\x24\x8e\xa4\xd5\x01\xfe\x77\x45\x5c\xb2\xa1\xc9\xe0\xd8\xf3\xa1\x05\xfb\x54\xb6\x78\x2d\x31\x57\x90\x0e\xf0\x8d\x81\x8c\xc1\x79\xf0\xd9\x78\xec\x82\xf2\x99\x06\x54\x1d\xea\xb2\x06\x97\x0d\x8a\x9f\xf2\xd8\xdd\xeb\x80\x14\xdf\x1a\x71\x6c\xc4\xbc\xf8\x13\xde\xd8\xb1\x15\x4a\x73\xad\xaf\x1c\x06\x82\xa3\xf6\xf9\x01\xd7\x44\x56\x02\xaa\x88\x87\x7f\x82\x35\xe5\x7b\xd7\xaf\x8c\x26\x90\x79\x42\xea\x42\x92\x07\x36\x90\x59\xe3\x01\x53\xfe\x29\x48\xbb\xa3\x58\x73\xd7\x8f\x80\xd9\x72\xea\xa3\xfa\xe3\x6c\x41\x1c\xf6\xf1\xdb\xcb\xd1\xf2\xf9\x83\x1b\x8b\xbe\x89\xf4\x87\x07\x7e\x8a\x0a\x78\x10\x03\x6b\x6b\x5e\x9d\xce\x4d\xf8\x0d\xa1\x8c\x75\x08\x05\x88\x07\xa9\x22\xc2\x58\xbc\x7e\xb5\x78\xd0\x6e\x6c\x32\x91\xbb\xa6\x49\x56\xf7\xd4\x49\x57\x23\x63\x7e\xae\xbd\x44\xa1\x28\x7f\xda\xd1\x86\x6e\x55\x64\x97\x55\x17\xe5\xe8\xc6\xa7\xe6\x37\x1b\xc3\x74\x43\x63\xe4\x3b\x38\x35\xcb\xd3\x6a\x8e\xfe\x0d\xbb\x9d\x44\xed\xb6\xac\x73\x70\x49\x70\x97\x94\x72\x32\xd0\x0c\x78\xc3\xd0\x6e\x34\x45\x7c\xea\x4d\xe6\xb4\x08\x4c\xe1\x71\xcf\x06\x57\xb7\x97\x2f\xea\xdb\xae\x51\x5a\x7e\xd0\xf2\xe9\x81\x65\x8a\xef\x70\x07\xf3\xc9\x10\x4d\x62\x73\x0e\xfe\xb8\xa6\xad\x8d\xf4\xc2\x43\x78\xc2\x76\x3f\xde\xb5\xf4\x42\x3e\x41\x25\x5a\x45\xd6\xbd\xea\x48\x74\xe5\xe3\xa6\xea\x88\x32\x47\xa2\xb3\x6f\x64\x30\x3d\x87\xfb\x85\x6f\x37\x0f\xbf\xb4\x55\x9b\xf3\xd3\x2c\x9d\x97\xe0\xac\x6e\x31\x00\xb3\x47\x0b\xe0\x6a\xf8\xff\xb7\xeb\x9e\x03\xab\x6e\xca\x62\x60\x4c\x0d\x62\x2f\x37\xc0\xd5\x6a\xf4\x7f\x91\x77\x48\x3d\xb2\x32\x0d\x45\x0e\x18\x70\xef\xae\xd9\xdd\x9c\xe9\xe2\xdc\x09\xfb\xef\x37\x39\xb2\x07\x79\x1a\x4e\xcf\x59\xc1\x21\xaa\x25\xf4\x6f\x42\xb6\x0b\x8d\xa5\x93\x36\x84\x99\xe2\xed\x6a\xd0\x89\xe2\x34\x3c\xea\xc2\x75\xfd\xe8\xe1\xcb\xef\xc6\x62\x70\x9c\x93\xd1\x89\xc9\x26\x81\x05\x45\xa1\x76\x51\xb1\x3e\xf6\xaa\xc5\x88\x36\x71\x0e\x71\xf6\x49\x79\x6b\xb7\xba\xc7\xa0\x81\x27\x31\x79\xea\xfd\x9c\x91\xf3\xd8\xcc\x8c\x29\xe2\xb4\xd8\x5f\x6b\x77\xb9\xdd\x5d\x55\x74\xec\x7c\x48\x8c\x10\xb1\x6c\x41\x0d\x2d\xb4\xe2\x3d\x1f\x3e\xaf\xe4\x28\xeb\x9c\x8d\xa8\x90\xa2\x6e\x4c\x79\xb3\x56\x73\x7e\x54\xf3\x54\xef\x07\xac\x86\x80\x38\x26\xf2\xd4\xc6\xaf\xed\x4b\x60\x89\xd4\x45\x1e\x0d\x9d\x7b\xc5\x42\x3f\xaa\xb2\xf6\x0a\x19\xe2\xa7\x89\xf2\xad\x18\x22\xf3\x54\x1c\x02\x61\x37\x92\x10\x2d\xc3\xe7\xa5\x54\xa4\x52\xb7\x96\xa7\x68\xee\x24\x82\x11\x47\x03\x94\x5b\x5f\x1b\x52\x0a\x99\xdc\x48\x5a\x5b\x82\xa2\x91\x41\x74\xba\x71\x5a\x21\x8e\xc3\x4d\x16\x82\x93\x96\xbb\x6f\x51\x44\x32\xff\x2a\x8d\x67\x93\x0c\xc1\xe0\x8f\xdf\x40\x09\xa6\xc2\x80\xda\x8e\x7e\x64\xf2\x3e\x28\x4d\x57\xf7\xb6\xf8\x81\x50\xc1\x29\x34\x24\xa7\x4b\x63\x36\x5b\xa1\xb5\x70\xeb\x27\x89\xd4\xb5\xe7\xe6\x70\x4b\x18\xcc\x79\xe5\xde\x0b\xc7\x6d\xa0\xf9\x5b\x3b\x3f\xe3\xef\x66\x28\x94\x27\x36\x2d\x7e\x9a\xb9\x31\xc1\xd3\x34\x6a\xbb\xbc\x6d\xf7\x5b\x78\xbf\x91\x57\x15\x57\xdc\xb3\x86\xd5\x64\x91\xff\xb6\xdb\xe8\x47\xf4\x75\x7b\xfa\xfa\x99\x03\x38\x5f\xc5\xf2\xe7\xe4\xe1\xec\x74\x4f\x23\xfc\xe4\x96\x73\x02\xfc\x4b\xdc\xf7\x1f\xad\x7f\x97\x56\x80\xb0\xea\x33\x63\x69\xe3\x88\xbc\x49\xc9\xb4\x11\xba\xca\x41\x9a\xb2\x3d\xe1\x49\x13\xb5\xbc\x8b\x5f\xe2\x96\x6b\x63\xde\x63\x6d\xfb\x15\xc2\x33\x2a\xf2\xc2\x09\x4e\x48\xc8\xab\x16\xb8\x6e\xb6\x6a\xcb\x21\x61\xa5\xcc\xa6\x4d\x1d\x42\xaf\xf8\xdf\xeb\x2a\x07\xd4\x45\x62\xfd\x5e\x03\x1e\xf6\x59\xef\x55\x1a\xdd\x55\xc5\x18\xa7\x20\x01\x0f\xba\x47\x4f\xed\x3e\x84\x9d\x0c\x57\x3c\xe9\x16\x85\x87\xa3\x20\x2b\xbf\x92\xb6\x57\xc4\xed\xe1\x42\x13\x24\x9e\xec\x0a\xab\x4e\xb1\x12\x19\xd2\x7c\x1c\x23\x0b\xcb\xd8\xf1\x80\xad\xce\x7b\x0c\x83\x07\xc3\x63\x1b\x55\x7f\x61\x9e\x9b\x66\x4b\xb2\x6e\x6d\x84\xa1\x83\x81\x69\x39\xc0\xb9\x43\x72\xa6\x31\x7f\x4d\xa8\x9c\xcd\x73\xe3\xca\xc5\xa6\x0c\xda\x0f\x2f\x7e\xaa\xd9\x0e\x11\x19\xa0\x29\xae\x84\x59\x25\x1f\xf6\x2f\x00\x6d\x68\x6c\xb9\x0b\xa8\x5f\x4e\x4c\x68\x8d\x3c\xf2\x2b\xfb\x47\x92\x8c\x26\xed\x19\x1c\x9e\x65\x9f\x8b\x35\x94\xb7\xc8\x1e\x9c\x2f\x1b\x4d\x2a\x85\xd7\xa7\xce\x25\xf0\x39\x08\x71\xd6\x0e\xce\x4b\xd7\xf6\xcd\x53\x17\xe3\xdd\x76\x0d\x34\x4f\xfc\x2b\x9a\xeb\x5a\x06\xc3\x1e\x7d\xbe\x05\x40\x99\xf6\x6c\x8d\x93\x02\xad\x52\x12\xce\xda\x1a\x93\xd7\x9e\x33\xf3\xc6\xbd\xf9\x33\x8b\x29\x0f\xa3\xab\x0c\x89\x78\xa0\x52\xe6\xa6\x86\x45\x54\x85\x64\x9b\xb1\x04\x55\xb4\x1f\x3a\x0b\x6d\xf9\xb2\x29\x34\x18\xbf\x3e\x11\x25\x82\x70\x28\x7e\x0a\x4c\x49\x92\x1f\xb6\xa3\xe9\xaf\x36\x88\xc4\x6b\x14\x0d\xbc\xac\xa4\xcd\x75\x17\xe0\x7c\x4b\xce\xdb\xd2\x63\x6a\x66\x76\x84\xe9\x2e\x2e\xc4\x9c\x85\x6e\x2c\xee\x69\xc6\xf7\xf4\xc9\x92\xa7\x28\xf6\xef\x9a\xdf\x16\x06\x35\xab\xb8\x42\xd0\x49\xc0\xab\x1e\x24\x31\x9d\x22\x78\xc1\x06\x1d\xdd\xa5\xf7\x51\xea\xe6\x8e\xfc\x72\x11\xba\xb7\x36\xfd\xce\x7c\xfd\xfd\x09\x54\x4b\xb4\x88\x3f\x06\x8b\x70\xe5\xd8\x16\x92\x96\xfc\xa7\x5e\x98\x16\xf9\xe9\x16\xf5\x10\x8b\xf1\xf5\xf4\x12\xc8\x3b\x68\x3a\x2b\x81\x88\x43\xb6\x56\x6b\x75\x23\xcb\x40\xc5\xce\xdf\x90\x50\x50\x8e\x31\xb5\x82\x3c\x9f\x3f\x1b\xbd\x9e\xad\xbf\x3b\x1c\xb8\x63\xda\x9e\x4e\x07\x7d\xf8\x5c\xa7\x0b\x62\x0b\x10\x22\x35\x2d\x11\xda\x57\x68\xa5\x21\x3b\xd0\x29\x1f\xe7\x19\x6d\x2d\x18\x22\x71\x05\xa7\x79\xab\x3e\x3f\x3f\x6c\xb1\x2b\xf4\x1b\xc0\x48\x44\x67\x64\x40\xe5\xce\xe6\xeb\x5e\xff\x9b\xd4\x35\x50\x7d\xf9\x2a\x42\x79\x48\xfc\x58\xb5\x4d\x08\x5f\x07\x28\x31\x79\xb5\xa0\x83\x84\x88\x62\x3d\x64\x9f\xd0\x7d\x05\x6c\x7c\xea\xd6\x54\x3b\x3f\x84\xf9\xf9\xcb\x30\x19\x35\xa4\x71\x31\x12\xee\x27\xff\xa4\x20\xfe\x9a\xd1\x94\x24\x62\xa0\xc0\x4c\x8f\x6a\x93\x9b\x09\x5c\xb6\x20\x1a\xec\xc5\xf8\xef\x10\x0e\xb1\xfd\xd4\x2a\x45\x00\xe0\x96\x9c\xa4\x04\x18\xb4\x65\x32\x41\xe3\x80\x28\xe5\x50\xc2\x5a\xcc\xa4\x5a\x61\xc5\xa7\x6a\x5c\x20\xe2\x5d\xe8\x64\x4e\xfd\x57\xcf\xfa\x3e\xff\x2a\x76\x40\x85\xd6\x6a\xc9\xc5\xdf\x49\xcd\xd5\x85\xe2\x7c\xf1\xba\xd4\x5e\x70\x6f\xbd\xd6\x2c\x57\xbd\xd2\x17\xda\x5f\x19\x64\x5b\xa9\x40\x16\x45\xb7\x34\xc6\x54\x17\x34\x08\xfe\x9a\x81\x2d\x7e\x70\xba\x16\x3c\x4b\x84\xac\x4c\xd6\xb5\x1c\xaa\x4d\x4f\x20\x74\x4e\x62\xa4\x1d\x87\x3c\x9d\xbc\xe2\xf1\xeb\x5c\x29\x42\x0f\xdf\x84\xfe\x49\x23\x46\xde\x20\xb9\x02\x3f\x9d\xba\x54\xc9\x25\x51\xbc\x74\x01\x99\xe0\x28\x74\x9b\xcc\xc9\x66\xa7\xd3\x42\x5a\xa4\x11\x41\xef\xae\xb3\xf3\xe4\x8d\x26\x48\x3c\x48\xa0\x1b\xdf\xb5\x8a\xc4\xdf\x68\xed\xf1\x0b\x51\x13\x11\xef\x48\xb2\xcf\xd0\xf9\xf1\x77\x45\x39\xab\x68\x28\x11\x28\x7b\x78\x40\xbd\xcf\xa0\x36\x15\x75\x54\xb2\xa8\xea\x3d\xbc\xe8\x42\xd3\x3d\xb2\xa0\xd6\x8c\xc2\x3b\x46\x9e\xa3\xf5\xa5\x84\x5c\xad\x62\x0a\x8b\x5c\xef\xc6\x1e\x47\xfc\x12\x1a\x7e\x66\x61\xeb\x53\x9a\x8f\x7b\x05\x5d\xf0\x11\xe3\x68\xe0\x59\x42\xfb\xf8\x26\x9d\xb7\xaf\xc9\xee\xf5\x07\x59\xcf\x8d\x44\x02\x77\xbb\xcd\x5d\xd1\x2a\xef\x39\x48\xb0\x8d\x91\x55\xb7\x18\xe8\x6a\xc6\x7d\x6a\xb4\x5e\x0b\xd1\xfa\x0f\x80\xff\xb2\xd8\x55\xd2\x0b\x91\x00\x24\x8c\x0f\x7d\x52\x6a\x67\x7d\x34\xc3\x8a\x17\xf6\x21\x6c\xaf\x8f\x80\x56\x9a\xf1\xf7\x89\xad\x67\x79\x2c\xe5\x87\x9e\x52\x78\x25\x99\xa4\x7b\x44\xc5\x90\xe8\x45\xd7\x6e\xdb\xe1\x3d\xa3\xf2\x42\x80\xfa\x00\xf3\x64\x13\xd5\xa7\x66\xaa\xb0\x1b\x62\x8b\xe2\xf8\x8e\xf7\xec\xf4\x0d\xfa\x3f\x99\x7f\x00\xc7\x95\x49\x43\xbb\x99\x88\xe9\x3c\x46\x0f\xd1\x0b\x52\x95\xb8\x00\x5a\x43\xad\x9d\xb6\x00\x49\xf1\x06\x08\x52\x64\x57\x47\xe4\xe6\x72\xf6\xbb\x0b\x97\x73\x27\xfe\xbe\xcd\x2b\x71\x9a\x21\xcd\xe0\xa4\xa8\x05\xad\xc8\x8f\x82\x68\xc9\x29\x5f\x96\x0b\xf6\x39\x02\x33\x2e\xb7\xd9\x30\xa4\x62\x40\xd7\xe4\x85\x53\x35\x90\xb6\x60\xf7\x49\x15\xe8\x4d\x44\x34\xdb\x1b\x5b\x1d\xa7\xb4\x0d\xd1\xfb\xbd\x0b\xf6\x4d\xdf\x1d\x6f\xe4\x18\x09\x09\x7b\xae\xfd\x0b\x6f\xbe\x8a\x0f\x13\xb2\x75\xd0\xd4\x10\x32\xd5\x9a\x05\x5d\x87\x69\xc3\x46\x72\x81\x22\x34\x97\x01\xf4\xbb\xea\x2b\xd6\xfd\x41\x68\x7c\x2d\x78\x4b\x75\x20\xc8\xf9\x29\x12\xea\x4e\xbc\xa6\xd8\xec\x4b\x2a\xa8\x34\x82\xfe\x54\xaf\x77\x9c\x85\x14\x2c\x61\xd3\xbc\x85\x64\x55\x9d\xd1\xa6\xf4\xe3\x05\xca\xc5\x3f\x99\x35\x56\x49\x87\xe5\xfa\xb8\x00\xc8\xad\x0d\x17\x23\xfe\x8c\xe0\xd5\x83\xd6\xa6\x61\xb4\x07\xb8\xec\x36\x76\xb5\xdd\xbc\x82\x9d\x77\x87\xdd\xe3\x5b\xc8\x98\x78\x06\x2f\x41\x1f\x48\xde\x45\x4d\x77\x18\x52\x5b\x0a\x22\xf4\xb4\x9c\x4d\x9f\x5b\x55\x29\xbb\x40\x03\x87\x8c\x0d\x04\xc7\xd9\xdf\x4f\x5d\xf2\x2b\xf4\x38\x71\x7f\x1e\x56\x6b\x90\x5b\x29\x8d\x89\x6f\x0d\xcb\xb8\x37\xca\xa5\x6a\xc2\x05\x76\xd6\x86\x9b\x6b\x6f\xce\xda\xa9\x0b\x6a\x64\xfb\xa5\x6d\x8d\x9c\x1b\x38\x4b\xd2\x40\xa0\x72\xc1\x80\xeb\x4b\x9c\x2b\xb0\x5d\x19\x65\x51\xf4\xdb\x62\xe5\x3a\xd0\xb7\xea\x9e\xae\xf8\xb0\x13\xc1\x3f\xd1\xea\x99\xcb\x1c\x00\x8b\x82\xe6\xc3\x09\x51\x7e\xb4\xfd\x3f\x18\x02\x18\x28\xea\xff\x88\xa5\x41\xac\xd9\x1c\xb5\xa7\xb2\x24\x32\xa6\xc2\x16\x45\xc5\x43\x27\x73\xae\x1a\xbd\x9d\xac\xbf\x62\xa2\x18\x35\x5c\xee\xbd\x71\xef\xf0\xe7\x60\x5f\xe5\xc6\x75\x5b\xcf\x97\x86\x92\x11\x7c\x4a\xd1\xc5\xb4\xdc\xa3\x1b\x37\xec\xd0\xa5\x3f\xa0\xc7\xed\x61\x86\xc9\xca\x48\xff\xc3\x10\x58\x80\xd7\x89\xe6\x90\x76\x56\x3c\x07\x4f\x4e\x29\x48\x50\x73\x00\x76\xb1\x2b\xe9\xb2\x4b\x34\xb1\x80\x3f\xf4\x91\xe4\x87\x96\x47\x71\xc8\xed\x46\xe6\x0b\x9b\x58\x28\x12\x74\x14\x10\x6f\x49\xb5\xdc\x18\xa2\x59\xdb\xa5\x70\x9b\xff\x64\xab\xe5\x15\x51\x2a\xbb\x89\x55\x9e\x28\x26\x69\xa3\xf5\x69\x89\xd0\xd6\x6f\x9b\x04\x90\x01\xbc\x22\x87\x8d\xa8\x13\xa8\x1e\x99\x6b\xd5\x29\x6d\x18\x58\x5a\x98\x9f\x05\xeb\x66\xef\xcc\xb0\x5d\x92\x72\x6c\x34\x09", 4092);
*(uint64_t*)0x20000208 = 0xffc;
*(uint64_t*)0x20000210 = 5;
syz_mount_image(0, 0, 0x1001, 1, 0x20000200, 0, 0, 0);
	return 0;
}