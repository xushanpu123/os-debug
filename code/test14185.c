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

*(uint64_t*)0x20002e80 = 0x20001bc0;
memcpy((void*)0x20001bc0, "\x55\xa5\x39\xde\xea\x37\x58\x13\x0c\x02\x34\x36\xb3\x86\xaa\x01\x9b\x74\x5d\x2d\x7f\x40\xe0\x54\xda\xa5\x71\xd1\xd5\xe8\xe9\xd1\x88\xa6\x4f\x46\xce\x40\x57\x51\x05\x74\xe0\x4b\x0b\x31\xde\x72\x93\xde\x8e\x1d\x9a\x6e\x06\xf0\xc8\x4d\x0e\x69\xf1\x1f\x56\xbd\x75\x59\xff\x0a\x74\x9b\x7b\x70\x66\xef\x70\x69\xf6\xfa\x73\x6f\xa3\x4d\x74\xf7\xa9\x0c\xac\x8c\x9f\xf3\x97\xf8\xed\x9d\x22\x01\x76\xb5\x4d\xaf\x4d\x80\xc3\xe8\x19\xc6\x96\xdc\x6c\xe6\xb7\x93\x23\xc3\xb9\x13\xdc\xc9\x08\xb5\x97\x30\x42\x37\xe1\xf0\x8a\xc9\x15\xae\x7d\x63\x70\x68\x6e\xd8\x20\x09\xe4\x33\x37\x35\xed\xb2\x80\x96\xfe\x8b\x17\xaf\xde\xcc\x83\x5f\x23\x4c\xf6\x22\x46\xd8\xbb\xdb\x2f\xa7\x1e\x78\x76\xa9\x16\x9b\x51\x36\xa4\x73\x43\xae\xf8\x42\x36\x0d\x7b\x91\xd1\xac\xed\x6b\x9b\xad\x27\x14\x7c\x97\xad\x68\x28\xd7\xbf\x20\xe0\xf7\x1e\x3a\xbd\x84\xb5\x71\x7b\x38\x1f\x29\x24\x85\xe8\xca\xe6\x79\xbb\xa6\xb7\x4b\xd2\x04\x47\x42\x8a\x1f\xc6\x19\x7b\x67\x56\x9a\x52\x59\x29\xfd\x55\xf2\x20\x78\xa5\x3d\x9a\x00\xd6\xae\x04\x82\x62\x75\xfc\xb8\x60\xf0\x08\xf7\x1f\x90\x63\xec\x9f\x97\x15\x5c\x18\x43\x9b\x1b\xb6\xd2\xbd\xeb\x21\x02\xa3\x77\x6e\x8c\xca\xce\x3c\x98\x94\x8b\x4d\x65\x94\xf3\xf2\x57\xe3\x4b\xa7\x10\x6a\xff\x56\x0f\x08\xdf\xe5\x43\x70\xca\xb0\xf3\x01\x35\x03\x7e\x7f\x0d\x60\x8d\x97\x56\x30\xb4\x37\x17\xa1\x40\x93\x7a\xfa\x6c\xb2\xdd\x27\x8c\x02\xd4\x2d\x80\x45\x8b\x60\x2b\x46\xa8\x6e\xf3\xd3\x4f\xb9\x99\x0d\xb0\xcd\x70\x52\xe4\x61\xac\xd8\x2d\xe5\x80\xce\xa6\x90\x74\x04\x27\xf9\xb2\x98\x2c\xb0\xf2\xc6\x8a\x45\x46\x42\x50\x3a\xc5\x8a\x24\x7a\x27\x59\xc9\x99\xa8\xb0\x02\x30\x3b\xbb\xe2\xe6\x47\x42\x48\xce\x83\xa8\x62\x6a\x5f\x13\x89\xe3\x44\xe2\x0d\x50\x9a\x11\x02\xc7\xe7\x12\xc8\x59\xb5\xab\x2f\x06\xa4\x46\x8d\x15\xac\xdc\x2a\x93\x0b\x7c\x9d\x79\xf5\xa0\x18\x97\xa7\x5e\x6d\x25\xd0\x4a\x53\x98\x82\x49\xb7\x55\x8c\x8d\x02\x6d\xfc\x0c\x24\xbe\x10\x6f\xd1\xcf\xdb\x0c\x43\x1f\xa0\xd9\x8b\xa0\xa0\xe3\x88\x9b\x4f\x55\xff\xc9\x6d\xae\x13\x0e\x2f\x68\xb6\x17\xab\xb6\x5c\xe8\x34\x5a\xfe\xf3\x7a\x26\xf2\xa1\x27\x88\xfd\xba\x34\xb2\xc8\xac\x93\xa4\x5b\xb4\x34\x80\x66\xe1\xf1\x6a\x68\x96\xe4\x81\x20\xd6\x3d\x62\xb1\x8d\xdd\x77\xee\x7a\xde\x8c\xc4\x30\x7f\xc8\x40\xd4\xbf\xb3\x99\x9a\xa4\xdc\x6f\x0a\xd4\x3e\x51\x3b\xd7\xf0\xb6\x4a\x4e\x5a\xf5\xd6\x65\xe8\xa4\x1b\xe0\x8f\x43\x5d\x7e\x3a\xe5\x59\x31\x3d\xd1\xa2\xc8\x3c\x2c\x46\x58\xbb\xb0\xd5\x1f\x16\x28\xe6\x00\x27\xdf\x4f\x1e\x76\x25\xe2\x53\x4e\x98\xe0\x57\x9f\x30\x9b\x5f\xc2\xd6\x7a\x43\x9d\x9b\x31\x99\x0a\x31\xdf\xc6\x07\xe0\x51\xed\xd0\xc1\x37\x77\x71\xee\x58\xbe\xda\x57\x6d\xc5\xd4\xa9\x4c\x01\x45\xd9\x10\xe3\x84\x20\xd2\xff\x38\x94\xca\x9c\x98\x47\xc4\x1b\x10\x96\x56\x59\x9a\xec\xa7\x28\xc6\x4b\x71\x36\x2c\x84\x2f\xf4\xb1\x33\x67\x25\x40\x1d\xbb\x6a\x6a\x88\x24\x5e\xb5\x49\xfd\xc0\x03\x07\xfc\x3a\x56\xb5\x16\xcd\xad\x55\x3b\xb2\x30\xe6\x80\xad\xa4\xca\xc7\xb6\x0c\xf2\x53\xc7\xa5\xee\x99\x5a\x8f\x78\x34\xbc\xad\xb6\x39\x4f\x15\x6d\x7b\x0e\x9f\x69\xcb\x76\xb2\xa4\x54\x01\x48\x50\xc1\x5a\xa5\x21\xf2\x9d\x04\x49\xf4\x0f\x79\x03\x91\x7f\x83\x8d\x35\xb7\x1f\x2f\xaa\x0d\xbb\x80\x66\xf5\x77\x39\xbc\x0b\x80\x51\x21\x3a\x53\xe2\xce\xd0\xce\xa6\x75\x31\xdd\xc9\x64\xfd\xca\x49\xcf\xf7\xe2\x78\xa8\x17\xff\xe6\xf9\x68\x91\x6f\x8c\x72\xea\x8a\xc6\x0a\x74\x25\x56\xa2\xb6\x4b\xe5\x10\x77\xe7\x7a\x92\x43\x69\x0b\x15\xdc\xfb\x98\x2f\x5a\x26\x1b\x22\x50\xab\x5c\x02\x99\x2d\xf9\x1d\xa8\x72\xc3\xe2\xfa\x0b\xab\xb4\x19\x8d\x3f\x82\x2e\x92\xc3\xc3\x41\xe1\x6a\xe1\x59\x91\x5e\xda\xa2\x79\x9e\xe3\xb8\x87\xd0\x57\x16\x95\xb6\x45\x40\xee\x30\xf6\xb4\xb8\x74\x37\x7b\x79\xa9\x37\x2e\xbe\x9d\xd4\x11\x78\xbe\xaa\x94\x43\x78\xe5\x79\x1d\x26\xcc\x6b\x64\x45\x3c\x0a\x81\x68\xd8\xc4\x2a\xb8\x55\xe1\x2a\x1d\x80\xad\x34\x14\xd3\x35\x3c\x13\x49\xaa\xf8\xd4\x5c\x71\x41\x4a\x8d\x70\x3c\x2d\x3a\xa2\xc0\xb7\x23\x14\x53\x10\x32\xc9\xde\xb3\xac\xb0\xa1\x49\x01\x12\xd8\x7b\xf8\xae\x6e\xe2\x0a\x70\xd1\x78\x4f\x1e\xb8\x62\xee\xfb\x92\xd5\x0a\x59\xc1\x5a\x85\xd4\x9e\x7c\x5f\xe2\xbd\xe5\x19\x51\xea\x35\xdb\xab\xca\x3d\xbe\xe0\x27\xde\x93\x19\xaf\x15\x2b\x11\xd0\xa5\x86\x59\x99\xec\x97\x49\x17\xd4\x6a\xbc\x0f\x81\x06\x26\xe7\x8e\xd7\x1c\xc9\x9e\xa2\x81\x4b\x74\x48\x7f\x79\xe4\x56\x3c\xc2\x25\xad\x83\x8d\xe6\x99\x35\x14\x5c\x9d\xd7\xcc\xd7\x6e\xe9\x65\x4e\xd4\x9e\x03\x9a\xae\x50\x62\xcb\x18\xaf\x38\x04\x36\x1a\x6d\xe2\x05\x8c\x4f\x7f\xfb\x43\xba\x66\xd3\x4e\x94\xc6\x2f\x2d\x56\xec\xc8\x98\x12\x36\xcf\x91\x0d\xd6\xba\x29\xeb\x2b\x01\xe5\x71\xd1\xd2\x7f\x39\xe0\xb7\x01\x8d\xa8\x1f\x10\x49\x99\x4b\xdf\xb4\x40\x5d\x7d\xc5\x21\xe3\xde\xe2\xc7\x43\x29\x22\xd3\xd4\x49\xef\x76\xdf\xfa\x79\xb7\x01\x94\x46\x64\x47\x46\x90\x74\x42\x0a\x70\x6d\xf9\x36\x89\x77\x28\xd1\x15\x1d\x85\xa7\x39\x93\xdc\x25\x4c\x50\xae\x60\xdf\x92\xd3\xdb\x4f\x83\x0e\x70\x86\x44\xd5\x80\x67\x00\xa3\xbd\x1d\x5c\xf5\x26\x84\xf3\x59\xad\xf4\x8d\xd0\x84\x0a\x5c\x2a\x72\x91\xf9\xfb\x3c\xc1\x60\xc1\xb3\x53\x8f\x7b\xd3\x82\x18\x57\x54\xb0\xb3\xd3\x08\x44\x22\x51\x47\xe1\x3a\x53\x33\xf2\x9f\x82\xd8\xff\x5c\xb3\xcc\xa8\x48\xea\x3d\x77\x76\x3c\x46\x69\x57\xa9\xb3\xa5\xc3\xa0\x5f\xe5\x81\x00\x80\xb5\xbc\x1e\xae\x1b\x87\xcd\x22\x6f\xe5\x4e\x55\x36\x80\x79\x80\xc0\xd7\xdc\x77\x82\x07\xd1\x0a\x89\x8e\x9d\xca\xb0\x3c\x15\x88\x78\x79\xeb\x8e\x4b\x46\x43\x20\x1a\x8a\xa2\xaa\x7e\x85\xcb\xfe\x95\x47\x92\xab\x77\x75\x56\x93\x04\x3b\x8b\x63\xfd\xcb\x68\x90\x2b\x94\x7d\x5c\x82\xc0\xdd\x4c\xd2\xbf\x47\x65\x8a\xb2\xe1\x85\x2a\x46\xa4\x9f\xe6\xe4\x95\xaa\xe1\x50\xc7\x4c\x05\x14\x0b\xf5\x40\x31\xca\x79\x22\x65\x66\xcc\x2a\x92\xba\x5d\xc7\xc4\xf6\xe9\xd3\xf8\xe7\x82\x4b\x67\x49\x0c\x3b\x44\x60\x08\x23\xc8\xfb\x02\xde\x1a\x68\xf2\x55\xe5\x1d\x27\xe1\xc2\xeb\x2d\xad\xda\xa9\xbb\xd2\x3a\xd2\xba\x42\x57\x08\x4e\x86\xeb\xa1\x8b\x5b\x50\xd9\x6c\x9d\x32\x2a\x8e\xef\x80\xe4\xe0\xb0\x1b\xba\x91\xdc\x2a\xfa\x81\x40\x68\xed\x02\x40\x6f\xa1\x5a\xbd\xe2\x2c\x00\xd4\x6c\x2b\x81\x33\x68\x3e\xe1\x2b\x1c\x1a\x31\xfc\xa0\x8a\x88\xea\x47\x34\x3b\x17\xd5\xe6\x62\xe2\xe4\xfe\xa4\x11\x74\xb1\x83\x0c\x19\x77\x56\x69\x99\xcf\x69\x03\x79\xcc\x10\xc9\xe7\x2e\x4c\xb1\x7b\x51\x0f\xe5\xb6\x4b\xcb\xf1\x9c\x33\xc6\x51\xe5\xd5\xd0\xf2\x74\xb4\x4e\x83\xb3\x80\xbe\xaf\x41\x1c\xd4\x6b\xfb\xa4\xca\x7c\x65\x2e\x35\x95\x89\xf2\x5a\xc2\x65\x32\xc6\xf6\xcc\x56\x90\xa0\xc3\xf1\xb5\xad\xfb\x79\x9d\x2f\xa6\x1b\x25\x1b\xbb\x57\x7c\x7e\x5d\xec\xb6\xd1\x7a\x8c\xc4\x09\x43\xf4\xb2\x03\x24\xfa\x74\x22\xce\xa4\x83\x60\x84\x42\x25\x81\x81\xce\x18\xed\x89\x10\x29\xdf\x5d\xad\x25\x76\x44\xe5\x67\x91\x5d\x6b\xa7\x8a\x91\x9f\x6e\x43\x1d\xcb\x90\x9b\x56\x58\x74\x45\x6c\x3d\x2e\x96\x78\x9a\xde\x21\x6f\xd1\x1b\x77\x46\x58\xb2\x08\xf9\x82\x2f\x6b\xcd\x14\x05\xd1\x0f\x43\x6f\xce\x29\x35\xa9\xa7\xf8\xea\xd7\xf2\xd4\x7a\x74\x64\xc0\x9f\xc8\xda\x4d\x03\xcd\x40\x2a\x84\x20\xc1\x8f\x13\x4e\xf8\xc6\x89\xe2\xc0\x08\x55\x40\x9d\x48\xe4\x58\xce\x81\x2f\x5c\xf1\x2f\x9e\x6d\x32\xcd\x60\x81\x7b\xb8\x19\xf6\x16\x80\xad\xc8\x68\x96\x53\xe6\xac\x41\x4e\x5f\xd4\x13\xee\xda\x3a\x74\xe4\xba\xa8\xf4\x7d\x75\x1b\x7f\x48\xf3\x21\x89\x99\xdf\x52\xe0\x7e\x6d\x4f\x2d\x71\x56\x0e\xec\x1e\xd6\xd8\xc2\xdf\x77\x5b\x12\x08\xf8\xe8\x54\x5f\x07\xca\xac\xa3\x40\xd6\xfc\xaf\x55\x87\xf1\xb9\x43\x6a\x37\x23\x8a\xa3\xc1\xdb\x98\x1b\x9f\xfd\x13\x59\x24\xc0\x24\x54\x01\xe5\x3a\x92\x59\x34\xe8\xbf\x53\xff\x39\x30\x61\x21\x28\xbd\xd5\x12\x23\xc2\x65\x0d\xfd\xb7\xed\xd8\xc3\xbf\xf2\x09\x17\xf1\x61\x76\x44\x45\x28\xcf\xfc\xb5\x86\xfb\xcc\xd8\xef\xc3\x9b\x9f\xd0\xa5\xce\xf1\x24\xad\x7e\x63\x8c\x1c\xf4\x0e\xb6\xf0\xa3\xbd\x0d\x0b\x1c\xf9\x9d\xcb\xab\x7d\x2b\x35\x74\xdb\x8d\xe8\xf5\xaa\xe0\xde\x62\xe2\x94\xf3\x01\xef\x5f\x7f\xdb\x8c\xd9\xe6\xd5\xef\xbd\x9e\x8c\x67\x78\xcd\xdb\x7b\x16\x77\xc6\xbc\x34\x43\x4a\x1b\x36\xf7\x49\x94\x63\xd4\xa4\xf9\x4c\x19\x9c\xb9\x0e\x78\x92\x8b\x9c\x0d\xd9\xb6\x60\xd5\xad\x1e\xfd\x8c\xef\x12\x7d\x37\x77\x3f\xcd\x51\xcb\x5c\x57\xaa\x85\x8e\x1e\x77\x57\xe0\x08\xf5\x9d\x00\xd9\x4c\xb4\x29\x65\xa8\x3b\x24\x32\xf2\xc5\xa9\x96\xce\x34\x71\xfd\x25\xdf\x9f\xfd\x46\x83\xe7\xe1\x85\x44\x88\xd1\xdd\x74\x8c\x5e\x80\x27\xdf\x93\xc3\x99\xc6\x1e\x1f\x29\x1e\x9a\x7d\x07\x82\xa3\xf6\x5b\x8f\x83\x72\x9e\xd8\x3f\xb0\x7a\xa2\x3e\x0d\x2c\x48\xf9\xe9\x44\x91\xe1\xa7\x61\x2e\xe1\x11\x65\x63\xfd\x9d\x64\x49\xc1\xc1\xfc\x3a\xf5\x3a\x93\xc0\xbb\xdd\x60\x70\x42\x83\x95\x6e\x65\xb8\x63\xf3\x90\xc4\x1c\x07\xbc\xf9\xba\xf5\x85\x24\x95\x91\x80\x83\x18\xa3\xd1\x3a\x5f\x04\xd9\x84\xfc\xda\xbb\xea\x0b\x70\xf2\x10\x2a\xf8\xa8\xc7\xef\xe2\xb6\x92\xe9\x37\x71\x75\x16\x31\x68\xb7\xe0\xdd\x15\x92\xd3\x75\x82\x96\xc4\xb4\x07\x3b\x75\x17\xf0\xdf\x8a\x84\x3d\xf0\x9e\x1a\x97\x52\x6d\xda\xe4\x87\xe3\x17\x71\x5b\x8e\xd0\x7a\x5b\x7b\xed\x99\xff\xa0\x6f\x80\x58\x65\x5a\xd9\x15\x73\xec\xd5\xef\xb5\x66\x21\x25\x76\xa8\xe3\x6a\x87\x99\xe1\x72\x4b\x87\xe1\x15\xfc\x81\x97\x3c\x93\x81\x14\xb1\xc2\xa8\x07\xed\xc9\xc3\x20\x27\xde\xe7\xed\xfe\x1c\xc1\xb4\x82\x9a\x60\x30\x1f\x6e\x5e\xf9\x86\x56\x2e\xed\x16\x79\x78\x22\xa6\x17\xd4\xed\xf3\xc8\x0f\x41\xbf\x3b\xe2\xf9\xc5\x01\xe8\x7f\x77\x39\xba\xcc\x6a\xe8\x0a\x81\xd9\xee\xa8\x61\x60\x89\x3d\x43\x75\xef\xa3\x42\x18\x9c\x25\xf8\xb0\x4f\x7c\x6a\x11\xf1\x11\x9c\xd7\xaf\x84\xd0\xcd\x4e\x51\x14\x3c\x6b\x92\xb1\xf5\x11\xfd\x98\x0f\xe2\xc8\x22\x6b\xd0\xa9\x92\x51\xb2\xc8\x5d\x5f\x72\x0a\xb6\x8c\x06\xf2\xd2\xdb\xaa\x4d\xe6\x21\x45\xaa\x12\x39\xe0\xe7\x92\x5a\x8f\x94\xe7\x2f\xf4\xc9\x9b\x76\xb5\x4c\xda\xb1\xf3\xe0\x1e\x0a\xeb\x2c\xc1\x4c\x64\xa4\x41\xef\x99\x2f\xf5\x97\x33\x2f\xd9\x40\xcd\x89\x0e\xf5\x9e\x98\xeb\xc4\x5c\xe8\x9e\xb9\xd6\xdc\x59\x29\x39\x39\xe1\x48\x1e\x17\x17\x7f\xa0\xb2\xc1\x2e\xee\xfb\x40\x69\x5d\x6a\x90\x70\x82\x8c\x81\x55\x69\xd0\x24\xd8\x1e\xb6\x6d\x4a\xa6\xac\x3a\x7b\x82\x4c\x60\xd6\x0c\x3e\x17\xaa\xac\x92\x9b\x08\xdb\xe5\xfc\xab\xee\xe8\x04\x63\x1a\xce\xec\xd3\x30\x02\x91\xa9\x16\x3a\x6d\xfc\xd8\xd9\xf9\xd2\xa7\xa3\x3f\xe4\xe5\x68\xb1\xfb\x5b\xe8\x10\x25\xb8\x74\x57\xdd\xcb\x83\x7d", 2421);
*(uint64_t*)0x20002e88 = 0x975;
*(uint64_t*)0x20002e90 = 0x68c;
syz_mount_image(0, 0, 0x1001, 1, 0x20002e80, 0, 0, 0);
	return 0;
}