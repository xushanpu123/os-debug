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

memcpy((void*)0x20000080, "iso9660\000", 8);
memcpy((void*)0x200000c0, "./file0\000", 8);
*(uint64_t*)0x200001c0 = 0x20001380;
memset((void*)0x20001380, 64, 1);
*(uint64_t*)0x200001c8 = 1;
*(uint64_t*)0x200001d0 = 0;
*(uint64_t*)0x200001d8 = 0x20000280;
memcpy((void*)0x20000280, "\x31\x9e\x20\x21\x9f\x10\xbe\x86\x2c\xb4\xdd\xa2\xd9\x9c\xe0\xb0\xa9\xc0\xfe\xd8\x28\x48\x80\xce\xb0\x77\x2b\xeb\x36\x03\x5d\xa9\x51\x17\x73\x6c\xd0\x67\xd9\x7a\x8c\x17\x00\x99\x13\x7c\xe1\x68\xb0\x04\xc4\x27\xda\xfe\xb8\x3a\xb2\x2b\x9d\x2c\x57\x11\x60\xde\xde\xd7\xbf\xb9\x9d\xb1\x7d\x98\xb1\x8b\x00\xa4\x17\xc4\x2e\x93\xc1\x62\xa1\x64\xb0\x78\x08\x11\x55\xe1\x36\x8b\xb4\xcf\x8a\x4c\xea\x35\x29\x69\x2c\x24\xa8\xac\xbc\xe5\x7f\xbe\x43\xc8\x23\x69\xef\x7a\xc6\xed\x3b\xe0\x24\x2e\xda\x0f\x63\x68\x6d\x28\xb0\x97\x5d\x2d\x29\xc0\x25\x00\xf4\xba\x5f\x10\xb5\xdf\x2b\x38\x3a\xc9\x67\x1c\x2c\x89\xda\x17\xc6\x84\xc6\xf9\x84\x1f\x04\xb7\x97\x92\x66\x02\x1e\xa5\x3f\xac\x74\xad\xf3\x42\x3c\xfc\x0e\x5c\x09\xca\x7c\x31\x43\x11\xdd\x10\xe3\xeb\x09\x65\xcb\x3c\x00\xd7\x2a\x2e\xa6\xdb\x2a\x59\x95\x62\x37\x7a\x36\x93\x86\x39\xff\x6e\xb6\xaa\x16\xf4\xc3\x09\xf1\xf6\xd8\x03\x3c\x05\x2c\x88\x07\x83\xcb\x6c\x11\xd3\x80\x50\xe2\x37\x1a\xb8\x3f\xd9\x7d\xc0\xb5\xee\xb7\x8f\x67\x40\xaf\x91\x6f\xdc\xe8\xe9\xd3\xd6\xc2\xb7\x4c\x64\xf6\xcc\x10\x95\x20\x29\xdc\xd3\xb3\x39\xce\xea\xac\x31\x9a\xe3\x14\xab\xa9\xf0\xee\x6a\x6a\xd1\x8f\xf1\x3b\x67\x60\x62\x88\x14\x74\xc3\x87\xb2\xee\xb0\x42\x3e\x6d\x81\x31\xd1\x4a\xa9\xd1\x13\xb7\x81\x94\x63\xbf\xf0\x3e\xa2\xea\x66\xc0\x1b\x91\x2f\x5d\x43\xa4\x17\xf9\xf7\x7d\x04\x5d\xe6\x90\x2e\x35\x2e\xba\x51\x49\x97\x25\x2d\x4e\x26\xc7\x85\x8a\x91\x44\x3f\xe4\x7a\x31\xcc\x06\x7f\x49\xf5\x1a\x5c\xec\xc8\xb6\x06\xee\xdb\x8b\xb8\x2a\xbc\x55\x56\x7d\xbe\x33\xd1\x8d\xe0\xae\x53\x74\xc5\x11\x50\x81\x99\xd0\x6f\x61\x17\x3b\x74\x94\x29\x6a\xbf\xf4\x90\x00\x49\x76\xae\xd6\xdf\xf8\x6d\xc9\x24\x1d\xba\x61\xd7\x9c\xf3\x97\x30\x6b\x5c\x2e\xcf\x3b\xd9\xf2\x47\x6d\x62\x62\x25\x67\xba\xea\xce\xf6\xb5\x6c\xb3\x37\x24\xf4\x0a\x57\x24\x1a\xca\xee\xf2\xe4\x74\xd4\xa8\x31\x5f\xe2\x4c\x2a\x46\x56\x9f\x47\x67\xe2\x4b\xb7\x31\x6b\x57\x2f\x6b\x80\x67\xf0\xa2\xf4\xb6\x0f\x25\xd7\x95\x5c\x2e\xe0\xbf\x16\x64\xfa\x85\x69\xfa\x65\xa2\x72\x70\x77\x13\xd7\xc7\x23\x0e\x58\x12\x14\xbe\xf3\x7e\xae\x79\xa9\x13\x4c\x0c\x60\x5d\xaf\x78\xc7\x93\x21\x62\x27\x07\x30\x80\xa2\xe9\xdf\x0e\x35\x1c\xbd\x89\x75\xe1\xe6\x29\x54\x77\x7d\x99\xa1\xbe\x29\x57\xa6\x25\x4c\x74\x69\x6e\x27\xc2\x7e\xdd\xa8\xd3\xba\x1f\x77\xfd\x8d\x17\xe9\x7f\x1a\x19\x97\xd6\x85\xfe\xb1\x40\x7c\x6a\xd6\xc6\x20\x05\x0d\xd4\x1a\x67\x0b\x08\x75\x21\x01\x3c\xd4\x53\x02\x57\x6b\x03\x37\x83\xff\x24\xb5\x43\x61\x52\x9e\x97\x68\xd9\xc9\x7c\x4e\x46\xe3\x13\xab\xde\x67\x57\xcc\x6e\x48\x67\x95\x49\x17\x70\xf3\xc1\x1c\x0a\x68\xe6\x2f\xf2\xb6\x18\x34\x14\x11\x36\xd4\x9f\x53\xb6\xa3\x60\xc0\xb3\x00\xcf\xd5\xa6\x3e\x5e\x47\x88\xcd\x01\xdc\x12\xe9\x94\x15\xb1\xd7\x11\x1b\xff\x9c\x6e\x27\x23\xfa\xa7\xbb\x9d\x76\xcd\xbf\x37\xbe\xd7\x45\x89\xdd\xba\x6b\xde\x6f\x4d\x7f\x97\xd5\x83\x20\x5d\x63\xfc\x3b\x93\xac\x1d\xdb\x6a\x37\xbd\x9b\x20\x5a\xab\x85\xf7\x00\x21\x5a\x1e\x73\x83\x49\xc3\x77\xab\xd7\x63\x33\x18\x71\x54\xc8\xd1\xc6\xf0\x33\x91\x80\x6b\x96\xbc\x5a\x1a\x9a\xd8\x80\xe0\x03\xde\x95\x1a\x63\x1a\xb6\x04\xe0\x36\xa6\x11\x0e\x0c\xf8\x51\x2e\x61\xa2\x95\x84\x40\xba\x39\xf4\x3e\x0d\x5b\xe6\x28\xc5\xf0\xa5\x7a\xc1\x12\x23\xed\x26\x1d\xc1\x40\x4e\x9d\x5a\xbd\xd4\xd0\x5e\x9d\x94\x6a\x18\x0d\x90\x86\xd4\xe9\x74\x00\x58\xbd\x61\xa0\x0f\x8c\x05\x7f\xd1\x13\xfb\xd9\x38\x5f\xeb\x2d\x5f\x4b\xe3\x20\x18\x3e\xb7\x41\xe7\x99\xc9\x92\x22\xb4\x03\xb9\xa0\xf0\x02\xe6\x86\xa9\xaa\x06\x4f\x93\x77\x96\x23\x16\x9f\x9d\xc5\xc3\xc2\xd1\xf6\x73\x49\x25\xb3\x70\x19\xbc\x3d\xd6\x2e\x2e\xbb\x84\xe7\xf6\xf0\xc5\xd9\x81\x7b\x7a\x6a\x1c\x12\x98\x66\xfb\x77\x7d\xf7\xbf\x89\x11\x47\xba\xd9\xb2\x38\x25\x3a\x52\xd8\x54\x23\xa5\x1f\xdc\xaa\xb7\xa4\xa4\xc9\x76\x52\x7e\xb8\x06\x71\x9d\x60\x75\x74\x77\x34\x94\x32\x95\x97\x7d\x01\x31\xee\x8d\x1d\x6d\x41\x47\xd8\xb9\xc9\xd1\x08\x99\x04\xf9\x55\xb8\x51\x2f\xd5\x76\xef\xc0\x64\xe4\x65\x0c\xfe\x0c\x0f\x68\x4c\xb0\x1d\x53\xc7\xb1\x63\xdb\x02\x69\x53\x7d\x58\x28\x5c\x62\x24\xca\x46\xc2\x75\xc6\xdd\xb0\x01\x02\xb5\x34\xf3\xe8\xfe\x21\xd6\xbe\x88\x88\xfb\x58\xfc\x04\x87\xd2\x6c\x04\x46\x5a\x1a\x9e\x51\x74\xfb\x96\x06\xd1\xc9\x71\xb7\x79\x4d\xcd\x03\xb2\xd4\xc4\xf1\x53\xf8\x77\x67\x11\x6d\x3c\xdb\x33\x2a\x20\xa9\x0f\xf8\xe6\x66\x22\xf3\xdf\x0d\x03\x10\x53\xdc\xfc\x15\x99\x84\x18\x37\x3e\xb8\x15\x0f\xa6\xb5\x22\x45\x8c\x1d\xb7\x1d\x89\xe3\xea\x09\x5f\x75\x72\xd2\x8b\x1b\xdf\x58\x88\x29\xe2\x08\x00\x2f\xfa\x35\xe1\x39\xd2\x6f\x94\x8e\xcb\xed\x76\xb0\xdd\xa5\x82\x38\x1d\xe4\x59\x0a\x41\xa5\xfa\x7b\x27\xc7\xf9\x03\x17\xa5\x79\x27\x59\x7f\xf8\xa7\xc4\xa2\x84\x74\x4f\x16\x8d\x57\xe3\x34\x1e\x7a\x79\xa5\x56\x59\xf9\xcb\x72\xf3\xeb\xb8\x31\x66\xce\x20\x45\x3d\x57\x1b\x1d\x39\x93\x74\xb9\xbd\xb3\x6f\xe1\xec\x1e\x82\x07\xee\xef\x8d\x93\xd1\xb0\x23\xc8\x6a\xc2\xd3\x3e\xbe\xb7\xb3\x30\xb6\x56\xe4\x45\xe1\x29\x45\xd8\x0c\x7e\x71\x7a\xdc\x80\x7f\xa9\xb6\x34\xd2\x6b\xd1\x03\x89\x5a\x91\x55\xf0\x41\x6b\x8d\xfd\x2a\x23\xa7\x30\x6c\xd2\x1f\x35\x9f\x76\xb8\x8a\x9a\x9e\xcc\x3b\x31\x7a\x46\x73\xa5\xb1\x63\x21\x11\x15\xe4\xbb\xcc\xc2\x32\x5c\x09\x96\x8d\x3c\x6e\x98\xf9\x69\x99\x79\x19\x27\x9d\x63\x01\xd2\x8b\xdb\x31\x46\x45\xa9\xa4\xc0\x64\x9a\xe5\xed\x12\xb6\x5f\xe4\x88\x04\xe2\xc9\x42\xc1\x4c\x1b\xb7\x34\x7c\x9e\x88\xa8\x76\x50\x93\x56\xe1\x6d\x40\xa3\x61\xa0\x77\x0e\x3c\x94\x8e\x9a\x3f\x30\x66\xb4\x55\x2d\xd3\x51\x9d\xdf\x8f\x00\x67\xaf\x95\x4a\xdc\x1d\x6f\xb7\xf7\x9c\x80\x01\x30\xc0\xe6\x09\xe9\x3b\xb7\xe1\xe6\x88\xe3\x79\x17\x7c\x8a\xcb\x0b\x2f\x2c\xa6\xb5\xb8\xd9\x68\x2d\xc1\x9d\x1a\x92\x15\xec\xe5\x19\x09\x15\xa6\x9c\xd7\xe5\xc7\xde\x3f\x47\x17\xbd\x5e\x9f\x92\xfe\x7f\xb2\x55\x62\x50\x8d\xe9\xa8\x91\x67\x8c\x4a\x46\xa5\x15\x69\x05\xf1\x21\xcf\x0c\xeb\x5e\xb5\x81\xc8\x88\x92\x86\x35\xdc\x2e\xe2\x3f\x73\x4c\xa9\x19\xd1\x76\x5b\x25\xc5\x0e\x6a\x16\xf6\x72\xf3\x5f\xe7\x1d\xff\x52\x01\x04\x5c\x39\x49\xd5\x89\x56\x25\xf4\x64\x27\x82\x0a\xb3\xd6\x25\x45\x60\x5d\x36\x05\xea\x5c\xdb\x05\x40\xe4\x76\xd2\x41\x33\x4c\xd3\xf3\xc9\xce\x69\xa4\xec\x27\x0e\xda\xb7\x88\x4c\xda\xd8\x37\x5c\x53\xd7\xac\x9f\x21\x9a\x89\xe5\xb7\x9c\x9b\xee\x36\x81\x5a\x28\xdd\x83\xec\x54\xf9\xac\xca\xec\xb6\xf9\x65\x39\x89\xdb\xa9\x6d\xe9\x00\xad\x5f\x03\x8f\xed\x50\x00\xda\x36\xd9\x8e\x9c\x14\x97\x96\x04\x21\x72\xae\x48\x77\x98\x32\xdd\xd1\xdb\x2c\xc6\xcc\x7f\x30\xed\x21\x08\xdb\x1e\xfb\x13\x7c\xf1\x2d\x23\x3d\x03\x6c\x0d\x82\x4e\xa0\x65\x49\xba\xf0\xc1\xb5\x68\x28\x72\x17\x96\xf7\xed\xbd\x89\x8e\x11\xb7\x51\x9e\x97\x60\x55\x55\xdd\x17\xb1\x98\x00\x10\x11\x58\xb6\x19\x73\x3f\x89\xb8\xbb\x3f\x06\xed\xc2\x8a\x4d\xea\xcf\x3e\x94\xb6\xcd\xfe\xc6\xa1\x35\xfd\x6f\x26\x70\x52\xb6\xfa\xc4\x50\xef\x57\x07\x3f\xde\x90\x70\x27\x14\xd8\xb3\x19\xf2\xfe\xe8\x57\x10\xa4\xc4\xc1\x86\xde\x8d\xb6\x66\xb5\x2c\x89\xff\x42\x16\x7f\xc3\x89\xff\xbb\x25\x0f\xba\x14\x67\x5b\x2a\xa2\x7b\x3e\x65\xb2\x92\xf2\xfc\xa8\xae\xb9\xfe\x1f\xcc\xd4\xd2\xfb\xd9\x76\x8a\x20\xfa\xef\xa4\xe9\x65\x07\x81\x2b\xd4\x93\xaf\x2f\xa7\x87\x95\x56\x2e\x2f\x93\x98\xcb\xee\xe0\x4f\x49\x03\xb6\xed\xca\xbf\x87\xb7\xb6\xfe\x91\x21\x7e\x89\xb5\x33\x8d\x5f\x99\x17\x80\xf1\x6e\x42\x74\xbf\xfe\xe5\xf2\x81\xcd\xa3\x41\x7e\x40\xa7\x57\xa1\x91\x2e\xc7\xbc\x5b\x2d\xfd\x9e\x75\x4f\x0a\xcf\x22\xa0\xdc\x2f\xcc\x73\x79\xe7\xca\x5d\xed\xb4\x20\xbc\x39\x77\x48\x92\x5c\x9d\x9f\x56\x92\xa4\xe5\xb8\x32\x29\x0c\x59\xa8\x54\x6b\x1c\x94\x41\x4c\x38\xf4\xdd\x7f\x4c\x00\xf2\xc4\x33\xc2\x1d\x97\x53\xc9\xaa\x54\x94\x51\x75\xae\x3e\x30\xb2\xf2\xa9\xb8\xbe\xdb\xd0\xa8\x3f\xfd\x94\x14\x0a\xfa\x1d\x11\xd2\xcb\x4c\xe4\x3e\xda\xc8\x53\xf6\x53\x16\xcb\x7f\x50\x4b\x07\x30\xd9\x6f\x7d\x7b\x7a\xb3\x6a\x8c\xeb\x42\x9f\xfb\xc3\x17\xff\xed\x52\xa0\x2d\x19\xa3\x21\x6e\xd6\xef\xb1\x08\xd7\x77\x1a\x1a\x7e\xd5\xb2\x9c\xf7\xcf\xe6\xa2\x4a\x51\xa5\xbe\x2f\xfa\x68\xe0\x56\x9f\xac\xbb\xa2\x72\xf3\x49\x59\xb3\x3e\x85\xe4\xf5\x62\xa1\x15\xde\xf4\x65\xfb\x00\x09\xa7\x6f\xfa\x0e\x1b\x44\x8a\x2f\x7b\x0c\x18\xa3\x4f\x1e\x3c\x10\x2b\x5f\xb8\x7c\x2e\x1c\xbd\x07\xd7\xdb\x60\xb3\xd7\xa5\x3d\xff\xbd\x77\x91\x1d\x35\xe7\xd5\xbd\xf3\x7b\xad\x1d\x03\xba\x5b\x8e\x6f\xee\x9f\x53\xb5\xcd\xc2\x92\x17\x7d\x44\x42\x9f\xd6\xed\x5f\x7f\x31\x4b\xd2\xfd\x5c\x14\xfa\x26\x6f\xaa\x84\x40\x78\xbd\x4e\x99\x49\x79\x00\xc9\xa9\x9b\x2c\xc8\x31\xf4\x19\x4c\x5a\x4f\xb7\x02\x7d\x67\xa0\x99\xde\xb3\xce\x20\x5d\x86\x93\x4f\x5d\xd1\x27\xfd\x16\x79\xa2\xfd\xd0\x0d\xbf\xc1\x15\x36\x2b\x6f\x10\x9c\x8d\xf3\xba\xd4\xa5\x40\xef\x80\xea\xf9\x17\xa0\xde\x9b\xdc\xa1\x3e\x10\x5d\x10\xb5\xdd\xe0\x04\x8e\x26\xb8\x7b\x11\x0d\x9b\x54\xf3\xa7\xa0\x56\xf3\xb6\xec\xfe\x93\xf5\xcc\x4e\xe0\xe0\x39\x19\x03\xae\x2c\x2b\x51\x8d\xc1\xd5\xe7\xd4\x0b\x38\x04\xd6\xc0\xe7\x48\xb2\x54\xa4\xb3\x1a\x5a\x6c\xa1\x4b\xe2\x67\xb3\xfd\x19\x90\x12\x49\x6f\xae\x5d\xf1\xe7\x73\x5b\x4a\xdd\xbf\x2e\xcc\xf3\xe5\x23\x51\x5b\xf7\xf7\x8d\x26\xd2\x8a\x96\x0b\xab\xf8\xef\xa0\x64\xdc\x68\xf0\xea\xb7\xee\x78\x20\xbb\x1e\x48\x7f\x12\xc4\x52\x9a\x60\xb0\xd3\xe8\xc4\xf6\xd7\x82\x8d\xc2\xf7\x6b\xbc\x0b\x17\x94\x00\x19\xb8\xc7\xb0\x27\x8f\x84\x13\xe8\x36\x4c\x1f\x90\x11\xa8\x8a\xfa\xfa\x9e\x4c\x33\xfc\x1b\x84\xa8\x0d\xd9\xcf\xda\x47\xf7\xf4\xfa\x81\xc7\x80\x74\x3c\x26\xb4\x4e\x63\xa2\xc2\xf6\xb7\xd3\x4d\x8d\x57\x46\xaf\xf7\x79\x8f\x48\x70\xa4\x34\xaa\xf7\xcc\x60\xec\xa1\x95\xb1\x0f\x5c\xfd\x17\x39\x09\xe0\x84\x11\xdf\x6b\x1a\x39\x8c\xfe\xfb\x0c\xf3\xc5\x52\x4a\xe6\xc6\x51\xc1\xee\x1f\x56\x29\x2e\x8d\x9d\x62\x8f\x3d\xc8\x19\xd5\xa1\x89\x5b\x26\xff\x8d\x78\xae\x93\x6d\xa7\xd1\x90\x68\xd8\xae\xa2\x64\x80\x2f\x26\xfe\x67\x4c\x7b\x71\x8a\xa3\xd2\x10\xff\x73\xae\x4a\x2d\x3e\x34\xf3\x21\x2f\x7e\xa0\x84\x74\xdc\xc6\xf6\x0f\xf4\x5b\xbc\x8f\x4e\x42\xab\x95\x38\xcf\x1e\xaf\x11\x19\xfc\x32\x6b\x1c\x58\xb0\x02\xd9\xf6\x33\x7a\x9f\xa4\x39\x58\x1e\xc3\x9b\xf5\xc7\x72\x7b\x1e\x53\x44\xe5\x52\xab\x37\x57\xff\x13\x9e\xcb\x57\x3b\x0f\x08\x69\x36\x25\x53\x95\xa7\xa2\x3b\x71\x33\x74\x4e\x0e\x10\x81\x4b\x64\x47\xae\xce\xa5\xef\x49\x6d\x3c\x65\x02\x3d\x89\xb5\x64\xb7\xcb\x71\x0d\x1b\x65\x85\xfe\xc2\xe9\x96\x32\x8d\xe9\x95\x64\x50\x9f\x1b\xee\x56\x04\xea\xb4\x44\x46\x22\x89\xbe\x9c\x66\xe8\x38\x86\xca\xfe\x8c\x05\xfb\x66\xab\xeb\xa6\x84\x01\x3b\xd7\x79\x38\x34\x32\x16\x60\xe9\xac\xa6\x23\xab\x16\x35\x02\x7d\xbf\x76\xc7\xa9\x2d\x99\x3e\x4b\x26\x86\xb0\x6e\xa5\x07\x0a\xee\x10\x5e\x64\x69\xaa\x1d\xa7\x40\x96\xcc\x93\xec\xdc\x30\x5e\x4f\x99\x9a\xa6\xf7\xd5\x07\x5b\x9b\xa3\xcd\x54\xe6\x2d\x92\x46\x22\x84\xd3\x2f\x1b\x7b\x45\x99\x45\x7b\x2a\x28\xb0\xcc\x2a\x26\x47\x7a\x29\x66\x2b\x1f\x13\xa0\xbf\xaa\xd2\x49\x65\xfb\xbb\x94\x83\xbf\x8c\x15\x81\x8d\xfc\x67\x4e\xe6\x22\x75\x94\x23\x80\x56\xf3\xe4\x03\x57\x1d\x85\x7d\x99\x97\x4e\x6f\xe6\xb7\xcd\x36\x6f\x1d\x32\x8b\xa5\xfb\x82\x8c\x6b\xa9\x7f\x69\x2e\x10\x09\x8e\x28\x04\x0d\xa7\x16\xdf\x05\x44\x28\xfc\xd8\x69\xfc\x63\xdf\x3a\x59\xb9\xfe\x6b\xb5\x81\x2a\xd7\x0c\xad\x1d\x9c\x75\x46\x18\xe0\xd8\xd2\x21\x37\x82\x18\xab\x47\xff\xba\xf7\xec\x26\xd8\xea\x0c\xb5\x6b\x36\xd7\xeb\xa9\xa7\x46\x82\x63\x4b\x85\x83\x3f\x00\x59\x2c\xc9\x20\x1e\x1c\xa0\x57\xee\x4f\x25\x99\xa5\x35\x6c\xd0\x5a\xcf\x8b\x6a\x96\x9d\xd0\xce\x1f\x39\x46\xb7\x13\xbf\x97\xd0\x6a\x3d\xc6\xed\x6b\x24\x38\xe7\xcd\x42\xfb\xb7\x04\x0e\xb0\xe8\x6d\x6c\x25\x50\x64\x02\xc8\x98\x13\x6d\x3a\x63\xed\x4d\x1f\x46\xf1\x61\xc0\x69\xa4\x6c\x1d\x58\x84\x72\x57\xe1\x3a\xcd\xf6\x35\xad\x41\xae\x76\xae\x17\x2c\x86\x96\x8a\x28\x02\x15\xfe\xd0\x29\xc3\x4f\x89\x00\xd4\xb0\xff\xc9\x5b\xf0\x90\x05\x8c\xa3\x15\x7a\x9f\x28\xca\x0c\xa4\xb1\x3a\xf8\xef\xc0\x23\x4c\xcb\x5c\xd8\xfa\x15\xc9\x92\x42\x15\xe4\xd8\xa5\x76\x40\x37\x92\xae\x27\x43\x34\x75\x37\xff\x16\x54\x71\x5d\x1f\x19\x95\x68\x40\x1e\x0e\x70\x19\x49\x1f\x37\x45\xb5\x44\xe8\xcf\x1b\x54\xad\xfd\xdd\x9c\x04\xdd\x93\x25\x8b\x9d\xdc\xcf\xb7\x0a\x27\x13\x4b\xa7\xaa\x6d\xfd\xf1\xd6\x17\xf3\x2f\x12\xf6\xc0\x35\x0f\x8b\x66\xb5\x72\x2f\x81\x5b\xef\x55\x79\xc5\xfb\xc6\x6d\x08\x33\xd1\xc6\x5e\x68\xa6\xc4\x7c\xb5\xdc\xe2\x14\x25\x6b\x43\xf9\xd9\x6a\x7a\x55\xef\x2d\xdd\x1f\xc7\x82\x3c\x52\x51\x5d\x81\x80\xf8\xc2\x70\x45\x9b\xbe\x36\xd7\x5d\xbb\x00\x99\x74\x0b\xdf\xcb\xd6\xc4\x23\xe8\xbf\x61\x49\x35\x0f\x4d\x87\x85\xaf\x6c\x5e\x4b\xed\x27\x1f\x44\x49\xb7\x4f\x68\x02\xc6\xeb\xe4\x1a\x99\x77\xc6\x02\x9a\xd9\xeb\xf0\x6c\xde\x5a\x6c\x5f\x05\x38\x69\x8a\x78\x7c\xcd\x1f\xee\x32\x0f\x04\x22\x4f\xb3\xc5\xa7\x35\x58\xcd\x38\xed\xec\xa9\x15\xdd\x9e\x5e\x81\x93\x95\x00\x72\x41\xb5\x08\xb4\xcc\x27\x2a\x61\xa1\x4e\x76\x32\xf8\x73\x37\xf7\x12\x2d\x79\x88\x39\xa1\xfb\x10\x27\xc5\xff\x94\x02\xb7\xac\xe5\xed\x51\x74\xcb\xed\x20\x60\xda\x44\x49\xd2\xc5\x9f\x38\x3b\x8e\xb3\x45\x2b\x7b\x39\x84\xf5\xbc\x89\xf8\xb7\x03\x5c\xfb\x50\xa0\x0b\x7b\x4a\x17\xef\x06\x5f\xec\xdd\xb6\x59\x3d\x79\x37\xf3\xf7\x75\xde\xfd\x9f\xf7\x5e\x65\xbc\xee\xf1\x8d\xb3\x77\x24\x38\x2f\x95\xaa\x1e\xef\x05\x77\x5b\xea\x79\x91\xca\x78\x35\x3c\xe3\xbe\x25\x44\xd4\xa5\xbf\x66\xc3\xb7\x18\xfb\x91\x9b\x90\x37\xf9\x9c\xc6\x5e\x2e\x71\x05\xce\x55\x06\x91\xdd\x23\xfc\xab\x81\x36\xcf\xa3\x2c\x27\xe5\x81\xa9\xf3\x7b\x98\xa8\xce\xa2\x80\x11\x38\x9b\x6f\x29\xa7\xf9\x3f\x60\x27\x50\x9c\xca\x83\x50\x5e\x75\xba\x66\x40\xa9\x6e\xe2\xfe\x1a\x90\x11\xe0\x2b\x53\x8c\x6d\x46\x7b\xee\x8c\x3e\x70\x8e\x6c\x36\x80\x44\x8d\x16\xd0\x6a\xd8\x5e\x14\x5b\x2f\x9c\x8f\x71\xa3\x74\xea\x00\x88\x40\xac\x97\x8a\xc2\xbc\xc5\x57\x9a\x9c\xc3\x4e\xd2\xaf\xb7\x75\x60\x36\x85\xbe\x33\x3e\x80\x3c\xbb\x81\x36\xbf\x7b\x87\x17\xda\x58\xe7\xee\x2e\x05\x1f\xfb\x7f\x21\x01\x75\x7e\x70\x50\xf4\x9b\x60\xdd\x5e\xda\xbf\x5e\x20\x90\x5e\x55\x60\xa3\x1c\x4d\xc3\x07\xd6\xbb\x47\x8d\xc8\xff\xa1\x8d\xaf\xfd\x48\xa7\x72\xe8\xb2\x23\xe7\x5c\xcf\xff\x40\x7e\x9a\x51\x12\x89\x5b\x99\x2f\x1b\x18\xdf\x52\xfa\xba\x33\x0b\x5e\x8b\xf3\xb5\x0e\xc3\x8f\xa6\xbf\x58\xa9\xd7\x17\xfe\xf5\xbe\xbc\xba\x45\x78\x99\xa3\x9b\x61\x5d\x41\x26\xab\xac\x8f\xeb\xbb\xe5\x69\xa6\x8c\x0a\x84\x35\x81\x87\x68\xd1\xed\xc1\xb7\x77\xc7\xad\x38\x04\x45\xa9\xe8\x4a\xf5\x07\x61\x76\x1d\xa7\x45\x17\x5e\x06\xf0\x63\xd6\x7e\xcc\x95\x80\x89\x0f\x83\x75\xd4\x8b\xb0\x59\xc9\x3c\xb1\xaa\x37\xd4\xe8\x46\x05\xe7\xb4\xb8\x21\x58\x71\xe3\x81\x4d\x23\x14\x89\x47\xff\x16\x11\x34\x9a\xa6\x18\xe8\xeb\x9f\x49\x7e\x51\xb4\x11\x76\x14\x94\x0e\x25\x2e\x38\xcf\x61\xe4\x83\x00\x57\x43\x10\x61\x78\x0a\x12\x65\x37\xbb\x4e\x29\x44\x62\x85\x39\xaa\x00\x83\xfe\xa5\x9e\xf7\x9c\x35\xb6\xbc\x97\x2c\x5a\x2d\xd8\xda\x57\xf6\x09\x97\xa5\x75\x3a\x48\x69\x2f\x05\x29\x4c\x66\xa5\xd0\xea\xc2\xdd\x95\x9c\xb8\x4d\x04\xa6\xa3\x3e\x56\x4c\x40\x70\x91\xd1\x9a\x3d\x02\x2e\x82\xec\xcc\xb2\x99\x8f\xbe\x4c\xea\x06\xb8\x70\x8a\x00\xcc\x4c\x43\x94\x38\xb4\xfc\xaa\x13\x6e\x28\x47\xe3\xd0\xfd\xbd\xa1\x4d\xca\x3b\x91\x0d\xbe\x26\x23\x49\x54\xb3\xe4\xbc\x26\x27\xc4\x4b\x41\x4b\xd4\xa3\x90\xc5\xb7\x3b\x5f\x46\xb7\x03\xdb\x8a\x05\x28\xb9\x1d\x4e\x27\xe3\x74\x49\x6e\xf8\xb3\x94\xe3\xc0\xee\xfc\xaf\x38\xbc\x9c\xf6\x08\x58\xaa\x93\xf5\x30\xfe\x70\x4d\x2c\x65\xca\xc6\xc2\xfe\x90\x9d\xdd\xa5\x03\x22\xb3\xf7\x97\x1f\x15\x44\x26\x31\x92\xae\x2d\xd0\x81\xc4\x6e\x24\xac\x9b\x89\x78\x11\x96\x08\xab\xd0\x4b\xaa\x49\xe3\x47\x7e\x53\xec\xb9\x35\x8e\x52\xb7\x51\x8a\x3c\x13\x07\x3a\x78\x30\x87\x01\xfa\xd5\xb7\xfb\xc2\x26\xda\x47\x32\xe3\x9d\x0e\xf6\x9b\x8f\x64\xdb\xf6\x2c\x21\xb3\x81\xa5\x64\xd2\x00\x25\x27\x5a\x8f\x0c\x24\xcf\xde\x28\x70\xa3\x17\xed\x70\x7e\x88\xb6\xf9\xb1\x05\x9d\xc8\x42\x26\x9c\x17\xb6\x20\xdf\xcd\xc9\x7e\x33\x4c\xe9\xb9\x7c\x5c\x21\xff\x09\x2e\xf5\x04\x74\xf3\xfd\x2e\x13\xd9\xb9\x43\xad\x91\xfc\x7b\x06\x7e\xdc\x8b\x41\x98\xf1\xd3\xf1\x38\xd1\x86\x3b\x85\x02\x15\xf9\x91\xbb\x1d\xf6\xc4\x09\xe9\xcf\x2a\xf3\x9c\xcc\x06\xa7\xb0\x3b\x40\x7d\x3c\x1c\xbe\x93\xcd\xf8\x05\x25\xfc\x04\xc7\xd8\x92\xf6\xe0\x18\x6d\x02\xcc\x87\x21\x4f\x85\x67\x82\x72\x82\x84\x77\x80\x5f\x6e\x60\x16\x37\xcb\xc4\xd2\xb9\x55\xb0\xe5\x06\x19\x0b\x7f\x58\xea\x75\x97\xfa\xf8\xc1\x35\xda\x15\x83\xeb\x7a\xe0\x83\x73\x85\x11\x4a\x81\xaf\xd0\xf8\xa6\x0f\xd2\xa3\x4f\x8d\xf4\x32\xb5\xe5\x35\x6c\x6d\xff\x2c\x57\xfd\xd4\x67\x33\x69\xf1\x16\xc1\x5c\xc6\xae\xcf\x82\x17\x8a\xc9\xd5\x4b\xe4\x6b\x6d\x03\xc4\x40\xa7\x95\x68\xbc\xb7\x0f\xe4\xb6\x95\x89\xa0\x81\x04\xed\xbe\xfd\xad\x13\xd4\xab\xc6\x24\xc3\xaf\x9e\xa4\x04\x16\x53\xdd\xde\xdf\x6f\x43\x52\xe1\x5e\x11\xe2\xe5\xea\x1e\x38\x6d\xef\x43\xbc\x3f\x4d\x50\x9f\x5e\x87\x37\x89\x59\x8e\x49\x9d\xe1\x57\x74\xce\x81\x83\x37\xa5\xe9\x02\x2c\xcc\xa4\xed\xe7\xde\xd1\x56\xba\x5d\xd4\x24\xd2\x58\xee\x0d\xf5\xd1\xf4\xa5\x5e\x3e\xc9\x63\xa3\xb8\xa6\xfc\x1a\xe4\x4b\xa0\x68\xdc\x4c\xf3\x07\xd7\x99\x13\x46\x98\xd3\xaa\x40\x03\xdd\x4a\x7a\xda\xb2\xe6\x35\x32\x2a\x27\x2e\xdf\x20\x8f\x90\xc5\xdb\xa1\x53\xcd\x8b\x79\x09\x20\xbd\x25\x84\x03\x53\xc9\x0b\x08\xd0\xb1\x05\xe9\x37\x22\x9f\x8b\xd8\x20\xcd\x5e\xea\xc1\x9d\xb9\x87\x4e\x81\xf6\x4e\x1b\x21\x49\x88\x82\x3e\x71\xd8\x15\xf5\x86\xb6\x64", 4092);
*(uint64_t*)0x200001e0 = 0xffc;
*(uint64_t*)0x200001e8 = 7;
memcpy((void*)0x200015c0, "dmode", 5);
*(uint8_t*)0x200015c5 = 0x3d;
sprintf((char*)0x200015c6, "0x%016llx", (long long)7);
*(uint8_t*)0x200015d8 = 0x2c;
memcpy((void*)0x200015d9, "uid", 3);
*(uint8_t*)0x200015dc = 0x3d;
sprintf((char*)0x200015dd, "0x%016llx", (long long)0);
*(uint8_t*)0x200015ef = 0x2c;
memcpy((void*)0x200015f0, "hide", 4);
*(uint8_t*)0x200015f4 = 0x2c;
*(uint8_t*)0x200015f5 = 0;
syz_mount_image(0x20000080, 0x200000c0, 0x8100000, 2, 0x200001c0, 0xe2, 0x200015c0, 0);
	return 0;
}
