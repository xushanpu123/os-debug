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
				syscall(__NR_getuid);
memcpy((void*)0x20000000, "nfs4\000", 5);
memcpy((void*)0x20000040, "./file0\000", 8);
*(uint64_t*)0x20001480 = 0x20001080;
memset((void*)0x20001080, 42, 1);
*(uint64_t*)0x20001488 = 1;
*(uint64_t*)0x20001490 = 0;
*(uint64_t*)0x20001498 = 0x20000080;
memcpy((void*)0x20000080, "\xde\x68\x54\x2e\x15\x4f\x56\xbf\xab\x5d\x62\xbe\xfb\x04\xfd\x2c\xab\x12\x7b\x21\x97\x2b\x4c\x95\x8f\x51\xb4\x76\x61\xe4\x84\xa2\x80\xcd\xe7\xbe\x80\xa9\x2f\xa7\x25\xe2\xc8\x30\xbd\x06\x1e\x1b\x82\xcd\x41\xbe\x0a\x0c\xdc\x8a\x01\xc9\x76\x13\x22\x6b\xa3\x89\xba\x06\x07\x53\x1e\x10\xfb\x95\xad\x64\x5f\xb7\x4a\x9e\x15\x65\xc9\xbe\xf5\x4b\x0c\x77\xb2\x46\x86\x6a\x22\x3e\x00\xc2\xb4\x51\xef\xc2\x02\x5f\x09\x98\xf1\x5d\xe7\x89\x7b\xbb\x01\x7b\x99\xf3\xf4\x51\xb8\xc6\xb7\x30\xd5\xca\xad\xae\x8a\x62\xea\x14\x18\xec\xcf\x78\xa5\xf3\x76\xd4\xf0\x7b\xb5\x5a\xe1\x53\xa6\xa4\xe6\xeb\xca\xc8\xe1\x99\x84\x7b\x22\x4a\xd3\x27\x4e\x07\x79\x4a\x75\x24\x4b\xf3\x3f\x64\xa4\x07\x0a\x64\x6b\x3d\x33\x5b\xf9\x0c\x6e\xea\xf9\x26\x21\x87\x81\x99\x25\x3a\x81\xa3\x08\x53\xe1\x1b\x31\x5d\x3d\xc6\xc6\xf7\x62\x78\x37\x54\x63\x45\x66\xfa\xc6\x5b\x44\xe7\x69\xfe\x80\x59\xae\x08\xc9\x0b\xc6\xed\x10\x02\x10\x3e\x45\xb3\xf3\x22\x00\xc3\xab\x71\xb8\xb5\xab\x46\xb7\xc4\xc5\xc2\xa5\x11\xc4\x1b\x5d\x8a\x56\x6b\x49\xa4\x66\xc0\xc5\xc9\x91\xab\x10\x73\x4d\xba\x59\x43\x81\x76\x3b\xc7\xaf\xc0\x80\x69\xe0\x59\x18\x8a\xc0\xe1\xaf\x91\x61\x9b\x79\x7d\x88\x32\x1a\xfc\xdd\x4c\xff\xba\x3d\x4d\x8b\xa1\x28\x71\x61\x98\x42\xf8\x08\xe4\x3b\xb9\xe0\xe3\x9a\x84\x6a\x42\xa5\x9b\xd7\xe6\x41\x82\xc6\x94\x0c\x78\xae\x5c\x8f\x9c\xdc\xa7\xcb\x9c\x8e\xeb\x73\x4a\xb3\x9c\x4b\x3f\x2a\x09\x08\xf4\x8e\xfd\x6e\x64\x53\x8f\xcb\xea\x40\x3a\x7b\xa4\x86\x17\x53\x88\xc5\xa8\x0b\xdd\x5d\x29\x07\x94\x84\x0a\x3b\xfe\xf7\x89\xba\xb1\xbf\x19\xfe\x6d\xde\xff\xb3\x72\x1c\xb4\x1b\xe1\x64\xdf\x6b\x44\x63\x3a\xbe\xcc\xd8\xfd\x78\x4d\xb4\x1d\xac\xb3\x65\xcc\xd4\x66\xe8\xab\xa9\x29\xc7\xbc\x05\x77\x75\x0f\x46\xd4\x49\x6a\x3c\x39\x13\xd3\x4e\x89\xb1\x82\xf4\xd7\xb4\x25\x97\xe7\x39\x7e\x98\x50\xa3\xe4\x76\x48\xef\x04\x78\xbc\xf5\x6c\xd0\x55\x3d\xf5\x83\xd5\x60\x94\xf7\x6d\xa9\x61\x06\xb7\xf9\x30\x08\xab\xb6\x74\x82\xa9\xae\x35\x37\x00\x06\x4a\xc9\x15\x3d\x5e\x9c\xd2\x3d\xed\xb9\x70\x26\x6b\xe7\x38\x27\x19\xd1\x3a\x94\x4c\x22\x76\xe9\x66\xc9\xa9\x74\xd4\xea\xf4\xed\x00\x98\x39\x94\x4b\x63\x12\x9e\x75\x93\xd6\x47\x37\x29\x77\xb8\xa5\xee\x6d\xba\x6a\xd4\x41\xd7\x21\xbe\x26\xf9\xbf\x5d\x16\x08\x24\x3d\xb6\xaa\x8e\x3f\x65\x52\x7c\xd4\x66\x12\xd9\xa4\xe1\xf4\xf9\x88\x90\x42\x13\x5e\xad\xc9\xba\x91\x24\x52\x64\x15\x76\x40\x89\x0a\xad\xc8\x2b\x08\x85\x53\xa0\xf3\x61\x09\xe4\xec\x0b\x04\xeb\x53\x04\x0a\xbb\x89\xf1\x9e\x15\xee\xef\xe1\x1a\x11\x80\xe7\xe9\x30\x91\xf1\x3d\x5f\xb5\xcc\x08\x72\x5d\x23\xa4\x4d\xc4\x24\xfe\xec\x2e\xa9\x3c\x3f\x78\xd0\x31\x2a\xcf\xa9\x5d\xd4\x57\x73\xec\x7b\xbb\x0a\xe6\xef\xbf\xa1\x77\x57\xa2\x6f\x40\xc2\x2e\x15\x04\xe1\x7b\xa2\xd9\xba\x3a\xfd\xe7\xad\xac\x02\x6d\x46\x9a\x57\xd9\xc7\xee\x61\xd7\x89\x50\x3c\x20\xd3\xdb\xb9\x07\xbc\xa4\xbf\x75\x21\x65\x2e\xbf\xae\x5c\x3a\x13\x28\x31\x85\x20\x4a\x01\xd0\x37\xed\x17\x16\xb4\xe7\x4b\x38\x28\x41\x9a\xb0\xac\x7c\x67\xa6\xd6\x8d\xf4\x77\xf6\xe7\x6a\x49\x32\x47\x3b\x9b\x17\xc5\xcc\x37\x56\x10\x91\x19\xe3\x45\x20\x97\x85\xec\x28\x9d\x24\x09\x27\x7b\xbb\xa5\xab\x69\xe3\x02\x83\xbd\x08\xb5\x9a\x0a\xab\xe7\x0a\x83\xfb\x40\x1f\x41\x0d\x96\x98\x9b\x34\x59\x09\x0e\x19\xdb\xf5\x58\x58\x3d\xcb\x94\x8e\x57\xd2\xfc\x97\x9b\xb5\x5e\xc9\xd0\x4f\xb1\x3a\x48\xf6\xc1\x9b\x85\x05\x9f\x15\xe8\x85\x1d\x5c\x38\x95\x6b\x6b\x6a\xa3\xb0\x71\xe9\x84\x4d\xbb\x7b\x54\xc0\xc1\xe1\x6e\xec\xba\xe6\x98\x92\x52\x52\xa4\x61\xbc\xdd\x91\xe8\xfd\xd5\xce\x2c\xec\xd0\xc2\x72\x8d\xee\xad\x97\x17\xbc\x51\xec\x5f\x4f\x35\xaf\x6a\xab\x19\xcd\x9c\x67\x9a\x64\xec\xcf\x48\x32\x62\x91\x4c\x48\x97\xa9\xb1\xfa\xd2\x97\x77\x40\x8c\xea\x21\xee\x84\x3f\xc6\x42\xad\x31\x07\x2b\x87\x88\x3e\x33\x0e\x7f\xb5\x70\xd1\xcf\x35\xf0\xb6\xe4\x84\xa0\x46\xa0\xd0\xa3\x3b\xfc\xc1\xe4\x15\xdb\x9a\x14\x57\x86\xa8\x10\xae\x51\x69\x96\x8c\x83\x89\x54\xce\x0a\xd5\x85\xca\x23\x7a\x8a\xad\x17\xb3\x59\x44\x15\x61\xd8\x27\x6b\x0f\x33\x8b\x5f\x62\x9f\xaa\x63\x34\x73\x8d\x9b\xed\xda\x90\xfe\xa7\x2b\xd7\xcb\x71\x22\x51\xb3\xdf\xd5\xf2\xda\x01\xb3\xaf\x1a\x5b\x67\x59\x49\xa9\xa9\x93\xd8\x4b\x4a\xb4\x76\xaa\x75\x59\xe3\x9d\xc9\xb0\xa4\xc4\xaf\xc5\x97\xab\xed\x6b\xeb\xd4\xd3\x46\x4e\xd0\xe4\x81\x33\x1a\xbb\xaf\xb8\x4c\xed\xfa\x41\xc9\x6e\x58\x34\x98\x8c\x78\xd3\xf5\x45\xd9\xf5\xd0\x17\x34\x85\xfd\xed\x84\x62\xca\xf9\xd1\x15\x33\x38\x64\xe4\x95\xc7\x7f\x6d\xfb\x49\x55\x36\x7a\xb1\xb8\xf2\x42\x27\xca\x47\x3b\x79\x21\xbf\x96\xba\x55\x5d\x3e\xdf\x35\x81\xa8\x01\x4d\x43\x27\x71\x07\x2b\xa1\xc0\xa7\xf9\x08\x87\xbd\xf5\x7b\xe4\xb5\xc9\x3b\x0a\x2b\x66\x52\x65\xd3\xf2\xc3\xce\xc4\x25\x64\x0d\xd6\xa0\x8c\x22\x2b\xee\x03\x88\x15\xd7\x08\xda\x9e\xd8\x65\x83\xa1\xde\x3f\xbb\x23\x12\xc9\x07\x90\x79\x99\x71\x85\x4d\x53\x40\x3a\x37\xe9\xf4\x14\xf3\xfd\xfa\x92\x65\x33\xc0\xca\x3e\x73\x1a\x89\x34\x52\xf9\xc4\x33\xd1\x1a\x86\x48\x0f\xbf\xfb\x64\xad\xaf\xa8\xcc\xf3\x70\x97\x9d\x05\xa6\xd0\x20\xe0\x85\x68\x5b\x91\x63\x9a\xa0\xf0\x7e\x85\x7c\x65\xa3\x66\x4f\xf1\xbe\xb6\x5c\x15\xb8\xea\x62\xe4\xbc\xcc\xa1\x38\x06\x25\xec\x90\x0d\x20\xb9\x09\x9e\xde\x22\x34\x66\x9d\x5c\x44\x4b\xae\xe8\x72\x94\xa7\x92\xd6\x57\x11\x11\x54\x57\x2c\x95\x4a\x42\x76\xdd\x2f\x5f\x48\xd5\xeb\x82\x64\xcd\xd5\x32\xf7\x61\x78\x18\xbc\xf4\x3b\x76\x91\x9f\x06\x9c\x38\x15\xd3\xcb\xc0\x47\xa5\xdb\x8f\xeb\x0e\x45\x05\xe6\x61\xda\x69\x0c\xf2\x5f\x16\x2b\xc6\xea\xb9\x5a\x04\xd0\x79\x8f\xe9\xa9\x2d\x25\x2d\xf9\x58\xce\x35\xa9\x6a\xec\x08\xa1\x86\xc5\x8d\x29\x1f\xce\x2d\xc7\x0e\xbb\x09\x13\x0e\x22\x6e\xd1\xc1\x4a\x0c\x26\x6d\xea\xdf\xc1\x65\x49\x5c\xbb\xc4\x7c\xd8\xfa\x84\xe0\xea\x8c\x04\xd1\x01\x30\x27\xa2\x35\x4d\xa7\xb1\x7d\x04\xc8\xdd\x36\x88\x7b\x4e\x64\x70\x64\x34\x74\x6c\x41\xc9\x4a\x1c\x0c\x90\xb9\xf3\x65\xa8\x9d\x23\xbd\xe0\x4c\xcc\x59\x65\x89\x43\x23\x95\x9a\x01\x08\xa6\x7d\x54\xa3\xa9\x30\x25\x3f\x25\xe4\x04\xdc\x28\xfe\xc5\x2a\xbe\x84\xa5\x6f\x68\xb4\xbe\xdc\x00\x52\xee\xa6\x62\xd1\xc5\x6d\x2d\x95\x0e\xd7\x56\x1b\xcf\xef\x54\x75\xfb\x90\xbd\xd6\x3a\x9e\x55\x64\x0b\x2d\xe8\x89\x65\xf6\x06\xd0\x4a\x30\x81\x28\x2e\xcb\x34\x04\xdc\x4e\xcd\xaf\xc7\x34\xb3\x97\x88\x67\x68\x57\xe8\x4f\x62\xa2\x70\xa6\xed\x8f\xbc\x45\xec\x2e\x3d\x3e\x27\xe4\x91\x27\x1d\x56\x42\xe5\x53\xcd\x16\x1a\xe4\xd9\x28\x79\x2b\x33\x1d\xf8\xe2\xb5\x90\x53\xee\x79\x60\x1d\x11\xf2\x87\xe6\xf0\xe6\x9a\xd4\xcd\x64\x61\xb6\x80\xb6\x47\x22\x92\x7a\x06\x9a\x0b\x2a\xb3\xb3\xec\x6f\x18\xe0\x22\x20\xcc\x47\x9f\x1f\x99\xa5\x68\x86\x0b\x3e\x9e\x7f\x80\xfb\x04\x05\x57\xe9\x60\x86\xdb\x9b\xeb\xb1\x3b\x5d\x0c\xfa\x20\xd3\x5a\x82\xe5\xc3\xc6\x53\x62\xea\x30\x6f\x20\x01\x6b\x19\xe1\x3d\xb9\x31\x63\xf7\xac\xec\x1e\x76\x86\xfa\xd2\xbd\x19\xd7\x4a\xad\x3a\x1d\xa3\x0a\x94\x61\x5a\x2d\x9f\x9c\x9a\x44\x50\xbe\xfb\x71\xf1\x10\x8e\x81\x40\x3e\xf5\xd7\xbd\x23\x10\x7e\x4c\x65\x98\xf5\x61\x22\xf9\xce\x0b\xc2\x1c\x31\x3f\xc8\x1d\xd7\xfa\x70\x1d\x90\xb9\x2a\xa2\x03\xd4\x16\x42\x36\x65\xbd\x64\x48\x44\x20\x9f\x13\x3a\x64\x85\x82\x7e\x05\x19\x86\x85\x2a\x4b\x08\x51\x30\x8b\xd1\x11\x28\x5b\xb8\xe5\x88\x0f\xe3\x22\x47\x86\x8f\xa8\x38\xc0\x75\x29\xbb\xef\xc1\xb3\x23\x39\x20\xf5\xcb\xac\xdb\x2a\x78\x8f\xf9\x30\x70\x9f\x3d\xff\xe0\x6f\x23\x96\x04\xca\x0c\x0b\xf0\x28\xef\x18\xd5\x3f\x40\xce\x25\x1d\xd6\xbb\xa9\x92\x1f\x38\x57\xb7\x64\xa4\xe8\x22\x22\x79\xac\xf8\x7b\xb1\x42\x6e\xc5\x79\x17\x1b\x75\xb7\x6d\x53\x5f\x29\xa4\xd4\x8d\x26\xdb\xdc\xe9\xeb\x53\x4c\x2d\x59\x94\x4a\x80\xfe\x96\x5a\xe2\x77\x54\x80\x3a\xc4\x4c\xe9\xde\x1b\x24\x1c\x96\x14\x50\x31\x62\xb0\xc3\x15\x16\x97\xa8\x3b\xba\x18\x28\x46\xb9\xd8\xac\x3f\x53\xaf\x07\x65\x2e\x72\x05\x1d\xdc\x40\x4f\xb4\x3f\x5b\xf5\x2d\x6e\x72\x43\xc3\x4d\xb1\x64\x27\xb6\x1e\x9c\xf9\xc2\xf3\x25\x9c\x37\xd6\xb2\xd3\xee\xd7\x9e\x10\x42\xb6\xd1\xee\x57\x32\x22\x7d\xbe\x7d\x22\x32\xe8\x91\xe4\x97\x92\x52\x15\xad\x8e\x18\xda\x67\x40\x8f\x79\x05\xa6\x36\xb0\xd4\x27\x38\xdb\xc9\xe9\x86\x10\xb7\x84\xc1\x67\x50\x35\xab\x45\xbe\x67\x2b\x0a\x8d\xe5\xd7\xac\x49\xe2\xbf\x69\xe8\xec\x04\xc2\x7f\xd9\x99\xcd\x39\xc4\x71\xa5\xd8\x8d\x42\x8b\x2a\x4f\x27\x05\x85\xe8\x70\xf6\x28\x02\x5b\x79\x8a\xf9\x70\x11\x2e\x1c\x0a\x81\x58\x2e\x06\x5e\xd0\x0d\x35\xe9\x50\xed\x1a\xaa\xc3\xd4\xf3\x19\x9c\xf5\xe9\x95\xfc\xb8\x0c\xcf\x30\xca\xd9\xe8\x31\x55\x78\x4e\x36\x70\x45\xfd\xc9\x04\xc6\x42\x04\x04\xbd\x97\x0d\x71\x89\x5f\x93\xd1\x20\x3e\x15\x65\x24\xd2\x02\x46\xd4\x80\xd3\x51\xa4\xde\xc6\x1f\x18\x62\xc4\x23\x74\x68\x53\x5b\x4c\x77\xaf\x9b\x5b\x88\xee\x71\x91\x86\x5d\xa8\xd4\x24\x34\x91\x63\x61\x79\x31\x4e\xf6\x80\x35\xb7\xbf\x8a\x51\x51\x49\xc7\xdc\x0b\xa6\x20\xb4\x3f\xa1\x9b\xb7\x8d\xe3\x59\xd0\x2d\x9d\xb8\x99\xba\x98\x12\x77\xb9\x08\x4f\x29\x49\xd5\x6d\x32\xe8\x15\xeb\x67\x37\x40\x2e\x83\x85\xb5\xeb\x70\xaa\x57\x69\x99\x19\x84\x6e\x59\xa2\x8f\x3b\xa5\x02\x41\xb7\x15\x2f\x7e\xba\x0a\xb4\x7a\x0b\x8c\x1d\x71\x87\xa0\x52\x39\x54\x91\xf8\xfd\xf4\x80\xd1\x38\xbc\x89\xe8\x30\xd6\x1f\x57\xa9\xc5\xba\xb2\x1f\x5d\x4c\xad\xb1\x7f\xcf\xc7\x9b\xb7\xa4\x26\xb6\xab\xd8\x2c\x8f\xc4\x2a\x70\x62\xac\xa2\x36\xfd\xc4\x5d\x30\xcc\x19\x18\xea\x11\xce\x53\x39\x39\x97\x79\x51\xdf\x6b\x53\x05\xe6\xff\x38\x0a\xfc\xc4\xe5\xb1\x90\x1c\x5e\x87\x14\x49\x44\x26\x72\xb3\xc0\x06\x13\x00\xbd\x64\xb5\xa6\x29\x95\x0a\x56\x7e\xdb\x06\xf3\x4a\x3e\x95\xe0\x10\x4b\x2a\xc1\x0e\x10\x2a\x29\x0f\x3a\x8c\x0f\xfd\x18\xe2\x64\x08\x7a\x28\x00\x70\x93\xf7\xc0\x2b\xc6\x96\xdf\xf0\x9b\xe8\x00\x9d\x1a\x09\x79\x6a\xc1\x22\xe0\x51\x91\x28\x73\xce\x36\xa6\xc1\x93\x6b\x3e\x58\x87\x70\x1f\x89\x24\x81\x30\xaf\xd7\x48\x74\x1b\xa9\xab\x84\x4b\x75\xa2\xd3\x06\x58\xd3\x1c\xfd\x18\x2d\x80\x48\x10\xcb\x0e\x44\x29\x5c\x10\x3c\xa4\xaa\xdd\xf0\xb0\xa6\x56\xfc\x8a\x31\xc0\x6c\x5e\xe1\xd6\xb2\x2b\xa4\x67\x91\xb3\x8c\xcc\x23\x27\xf5\x4a\x73\x74\x43\x4c\xb8\x4b\xce\x70\x6c\xf3\x11\x6c\xf7\xe7\xdf\xe0\x91\x9d\xaa\xa5\x06\xa8\x9a\xa0\x2a\xa2\xdd\xfe\xb6\x92\x3d\xed\x11\x94\x34\x7e\x79\x26\xf8\x4f\x6f\x11\xaa\x7a\xff\xb8\xa1\x0f\x5d\x83\xe0\x9d\xab\x4c\xec\x3c\x17\x70\xb5\x15\x93\x08\xd1\x02\x9a\x6c\x4c\xfd\x47\x6d\xc7\x93\x63\xde\xe2\xf8\xd9\x35\xf8\xed\x04\x2f\xd6\x2c\xca\x2a\xaa\x43\x93\xeb\x28\xe1\xcf\x20\x1f\x9d\xd1\x1e\xe6\xf9\x4a\x75\xc1\x57\x82\x37\xb5\xe4\xd3\xc2\x79\xd5\x71\x6d\x2c\x24\xce\x42\xf1\x16\x29\xb6\x0a\xf9\x54\xf6\x08\x2f\x4e\x99\x81\xba\xfc\xda\x29\xbe\x04\x06\xd6\xb3\xa2\x18\x97\xcb\xf6\x36\xa3\x9b\xb1\x8c\x2f\xb0\x2d\x2b\x26\x08\x7f\x67\x20\x03\xaf\x83\x75\x60\x60\xd5\x54\xf8\xf4\x3a\x08\xa6\xc8\x3b\xb5\xc4\x0a\xbf\xd9\x7b\xe3\xc4\xee\x46\x6f\x79\xbd\xd5\xad\x71\x43\xf2\x96\xbb\xf5\xec\x71\x07\x57\x17\x11\xe3\xc4\x5e\xa9\x1d\x0c\xf5\x38\xc9\x98\x9e\x3c\x94\xa6\xda\x5e\xb6\x36\x18\x82\x50\x93\xfc\x71\x66\x20\x66\xa8\xfa\x71\x70\x12\xe7\xad\x2a\x38\x54\xdf\xfc\xd8\x1e\x12\x8e\x66\xb5\xf2\xe0\x4e\x36\xad\x70\x5b\xc3\xcd\x36\xc5\x2a\xf5\xef\x47\x3c\x8a\x38\x39\xb2\xf2\xa1\x32\x48\xf9\xf7\x90\x47\xf5\x16\x9d\x5d\x29\x95\x90\x85\x56\xd6\x8f\x6b\x4f\x33\x3c\xde\x15\x59\x41\x62\x30\x89\x12\xbc\x29\x3b\xa6\x8b\xb6\x72\x7f\x75\xf5\xae\xb0\xc7\x1d\x78\x84\x26\xd0\x35\xcb\x50\x01\x69\xec\x69\x29\x00\x52\xeb\xed\x87\xf3\xa4\x53\x0e\xe5\xc1\xa5\x8a\x9c\x55\x05\x5f\x74\x00\x76\x17\xbc\xad\xb3\x50\x2b\xc1\x4b\xe4\x55\x3c\x6f\x05\xaf\x4f\xdf\x95\xb4\x3e\x43\x91\x7a\xe8\xa4\x8d\xf7\x73\xae\x21\x9e\x4c\xb7\x78\x6d\xb2\xb6\x6f\xef\x88\x3c\x84\x62\x8f\xdf\xb3\xc4\x21\x7c\x46\xa7\x22\xb4\xfe\x7a\x25\x2e\xc4\xb8\x36\xca\x57\xd9\x54\x83\xee\x78\xb7\x25\x33\xff\x4f\xca\x17\x9b\xbd\xd2\x5a\x40\xd7\x43\xda\x89\x5a\xbb\xeb\x32\xef\xc9\xcd\xa6\xe5\x80\x39\xbd\x90\xa1\x6d\x11\xde\x4b\xd7\xf9\x02\x75\x4c\x3d\x5b\x9f\x45\xcf\xe9\xaa\xee\x7e\x7a\x76\x81\xba\x5e\x01\x60\x51\x1d\xcf\x3f\x31\x98\x7a\x0b\xd7\x17\xf7\xc5\x1b\x0d\xd3\xb3\x1f\xce\xd4\xee\x1d\x18\x9a\x9a\x24\x9d\x4b\x16\x28\xce\x7b\x55\x0a\x82\x91\x49\x75\xe2\x86\x80\x6d\x2a\xca\x12\x32\xb3\x7c\xdf\x6c\x6c\x15\xd2\xb9\x2c\x4b\xd1\xd0\xe9\x1e\xae\x0e\x75\xcc\x46\xa0\x87\x4c\xd5\x41\xd9\x65\xfe\x07\x6f\x58\xb3\x35\x9d\x86\x52\x7e\x01\x67\x7f\x3b\x1f\x8e\xd8\x6d\xd8\xfa\x71\x7f\x3b\xef\x9b\xa9\xdf\xb2\x1b\xb2\x15\x7e\x2e\xa1\x3f\x3c\x71\x4b\x72\x99\xfb\x9c\xdc\x85\x32\x52\x5a\xa4\x0d\x29\x2a\x7d\xcc\xbf\xfd\x11\x6e\xc7\xce\x3f\xdc\x2b\xf7\x53\x7f\x3b\x80\x70\x77\x35\xdb\x0c\x18\xfe\xdf\xa1\xbe\xab\x43\x70\xe2\x0b\xcd\x1a\xaa\x37\x0b\xa2\xdd\x82\xff\xe2\x76\xad\x4a\xf0\x0a\x37\x92\x3c\xf9\x23\xb8\xd6\xb6\x21\x2c\xf2\x27\x47\x97\x9c\x26\x89\x18\x2d\xb5\x28\x90\x98\x9a\x07\x42\x2d\x8b\xff\xb1\x5d\x93\xb7\x5c\x37\x47\x06\x4b\x28\xc9\x31\x05\x33\x11\xc5\xa1\xe7\xe7\xcc\x5b\xb0\xfe\x69\xf8\x3d\xcf\x46\x72\xea\x9c\x84\xea\x1b\xd7\xc6\xb1\x3b\x8b\x0b\x51\x8d\x9b\xeb\x8c\xde\xca\xaf\x7f\xe8\x24\xa5\xc7\xc2", 3073);
*(uint64_t*)0x200014a0 = 0xc01;
*(uint64_t*)0x200014a8 = 0x400;
*(uint8_t*)0x20001540 = 0x2c;
memcpy((void*)0x20001541, "-[:!#:\002@", 8);
*(uint8_t*)0x20001549 = 0x2c;
memset((void*)0x2000154a, 40, 1);
*(uint8_t*)0x2000154b = 0x2c;
memcpy((void*)0x2000154c, "obj_type", 8);
*(uint8_t*)0x20001554 = 0x3d;
memcpy((void*)0x20001555, "\',,,Z\'@+)@", 10);
*(uint8_t*)0x2000155f = 0x2c;
*(uint8_t*)0x20001560 = 0;
syz_mount_image(0x20000000, 0x20000040, 0x1001, 2, 0x20001480, 0x1000006, 0x20001540, 0);
*(uint32_t*)0x20001680 = 0;
	syscall(__NR_accept4, -1, 0ul, 0x20001680ul, 0x800ul);
	syscall(__NR_getuid);
	return 0;
}