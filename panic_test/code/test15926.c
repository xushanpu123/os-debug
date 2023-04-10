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

uint64_t r[3] = {0x0, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_msgget, 0ul, 0x7fful);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200002c0 = 3;
memcpy((void*)0x200002c8, "\xee\xa3\x7d\xf3\x12\xcb\xf2\xed\x2a\x1b\x0b\x44\x24\x79\x7d\x43\x7c\x8d\x70\xe5\x08\xa5\x10\x40\x87\xb8\x7f\x11\x86\x31\x1f\x33\xc8\xd5\x69\xff\xa1\x16\xdb\xeb\x44\x74\xd0\x90\x44\xb1\x2c\x8c\xe1\x98\xa1\xcf\x65\xae\x32\x09\xdf\x6b\xff\x8e\x78\x24\xd2\xdb\x98\x88\x7d\x82\x21\x72\xf8\x24\x63\x1a\x3a\xcb\xdd\xb8\xdb\xe3\x62\xe6\x23\xfd\x62\xce\xf1\xe0\xb2\x67\x66\x9d\xa1\x6b\x3d\xb8\x0e\xb4\x80\x74\x47\x82\xbc\xd3\x2a\x5f\x8a\x7f\x48\x8b\xbf\x04\x73\xc5\x37\xc1\x92\xbc\xeb\x0a\x99\x07\xc4\x95\xdc\x79\xd9\xa7\x4c\xc0\x82\x6f\x0b\x44\x11\x0c\x2f\xcf\x12\x26\x93\x25\x8e\xbe\xe6\xc4\x55\x4f\x52\xf3\xb8\xeb\x1b\x9e\x36\xd3\xf5\x32\x25\x67\x7f\x0d\xfa\x2d\xe6\x63\xff\x15\x42\xd6\x04\xad\x34\x8c\xc6\xfa\x0b\xba\x2d\xfc\xa9\xf1\x23\x0a\x64\xc7\x19\x65\x4a\x10\x66\x7a\xb6\x8b\xb0\x6d\x4a\xc4\x64\xfc\x8d\xf8\xbb\xb6\xe0\x69\x83\xbd\xdf\x77\x5c\xed\xcb\x2c\xda\x10\x3e\x1a\xf9\xf3\x3f\x74\x80\xb5\x47\x62\x72\x38\x49\xd1\xf0\xd9\xb7\x65\x12\x99\xfb\x2f\x6f\x43\x5c\x75\xbb\xd5\x6e\x43\x17\x3a\x42\x0a\xef\x99\x59\x19\x66\x25\xbb\xe7\x7c\xcf\xc6\x96\x8a\x0f\xdf\x90\xd4\xeb\x68\xf9\xcf\x19\x1c\x1d\x41\xe6\xb6\x42\xfb\xd9\xcd\xa9\x60\x5a\xdb\x4e\x09\x53\x1a\x52\x5c\x3c\x94\xfe\x36\x71\x83\x96\x24\x5c\x1e\x63\x19\x43\xa5\xa0\xa6\x13\x94\x52\xec\x06\x41\x37\x49\xa2\x8f\x18\x41\x4c\x51\x12\xb2\x1b\x82\xd6\x47\x2e\x59\xb7\x21\x9f\x69\x7f\x4b\xb4\x39\xb2\x49\x91\x99\x0b\xf3\x82\x20\x3c\x38\x12\x93\x3e\x0e\x7d\x70\x52\xb4\x8b\xda\x7e\xbb\x22\x26\xc8\x4e\x2f\x92\xe5\x97\x53\x24\x40\xd3\x56\xcd\xd3\xaa\xd3\x8b\xac\x97\xde\xe9\xec\xb1\x70\x48\x19\x43\x08\x23\xff\x2a\x01\xb5\x92\x13\xe0\xfd\xc7\x0b\xea\xc5\x0a\xc8\x32\xdc\x35\xc3\x76\xab\xe8\x1c\xec\xb9\x31\xb3\x93\xb2\x31\xd2\xd5\x63\xc2\xc3\x8b\xb2\xfa\x82\xd2\x1b\x7a\x9a\xd4\x56\x87\xdb\x8c\x06\x90\xfd\x19\xe6\x2a\x26\x46\x88\xde\x1b\xf4\x38\xcd\x35\xb9\xf7\xf8\x5b\x32\x1f\x07\x3a\x0f\x82\xf9\xb2\x93\x93\xa6\xb0\xce\x84\xdb\x20\x7b\xcc\xa6\x99\x7a\x59\x85\x31\xba\x7f\x66\xec\xee\x32\x5e\x61\x92\xfa\x3b\xe0\x12\xb9\xeb\x35\x07\xe3\xe0\xe8\x7c\xde\xa4\x52\x5d\x7a\x51\x0a\x15\x80\x8d\x36\x23\x13\x72\x08\xbe\x63\xb7\x6e\x8d\xeb\x2f\xb9\xc7\x48\xf7\x19\xd4\xda\x17\xd8\xab\xd3\x8e\xe3\x48\xd1\x69\x33\x65\xe4\x25\xc5\x24\xc5\x78\x11\x36\x89\xee\xed\x61\x34\xee\x3e\x31\x15\xa2\x07\xb2\xca\x67\x1e\x5c\xb8\x2b\xb5\xfe\xc0\x6b\xd4\x3a\xfd\x2f\xec\x7e\x25\xcb\xbf\x2e\x3e\xed\xb5\x18\xa4\x43\x1c\x1f\x59\x58\xfa\x25\x14\x05\xca\x43\xa4\x6d\xf2\xdc\x36\xda\xdc\xcd\x9e\xbf\xe5\x39\x58\xb7\xa5\x5b\x5c\x8b\xf9\x1e\x9e\x2c\x80\x5d\x8b\x11\x81\x8a\x0b\xe0\x38\xbc\x31\xea\xbf\x43\xdb\xa6\xd9\xd5\x61\xb1\x19\x5f\x29\x8d\x3f\x74\x6c\xa8\xbe\xef\x48\x5c\x3c\xdc\x8f\x16\x78\x93\x08\xe9\xe8\xa9\xb6\x56\x08\x09\x6d\xb5\x21\x8c\x04\xd0\xa2\xa3\x72\x43\x8d\xea\xa4\xd5\x59\x27\x90\xe6\xb3\xf9\xa4\x94\x15\x16\x79\xd5\x2f\x34\xa3\x54\xa2\x75\xf2\x19\x98\x23\x3d\x59\x33\xa8\x89\xd6\xfb\x23\x0f\xc2\x63\x27\x78\x71\xa9\x6e\xd2\x47\xe3\x8e\xba\x6f\x8f\xc7\x76\xe2\x02\xf4\x39\xe4\x9d\x16\x88\x5c\xa1\xff\x53\x16\x15\xbc\x12\x95\xe7\x50\x4a\xde\xcd\x2d\xa0\xe7\x44\x17\x7e\xd4\xb5\x3f\xe1\xea\x4a\x7d\x31\x31\x0f\xd5\x45\xdf\x52\xb5\x15\xdd\x0e\xce\xdf\xdd\xb9\x94\x33\x7f\xfe\x3f\xa2\x46\x87\x42\xde\x41\x6f\xb1\xb0\x87\xc1\xd2\x55\x05\x95\x04\xd7\xae\x72\xcf\x5f\x8b\x84\x23\x6f\x38\x8b\x70\x40\x8c\x20\x13\xce\x67\xe2\xa4\x9b\x21\x65\xdc\x62\x63\xff\x2b\x7c\x2d\xe2\x7e\xa6\x95\x58\x4e\x14\x3c\xa0\x68\x2e\xa8\x05\x6d\x64\xd3\x05\xd0\x6a\x6d\x73\x48\xf4\xe1\xa1\x2d\x71\x56\x27\xf7\x22\x94\xdc\x76\x38\xc0\x7e\xb5\x0c\x90\xd4\x91\xd9\x2e\x7c\xd1\x6d\x0b\xc5\x45\xc7\x6e\xd8\x02\x57\x99\x9d\x5c\x9e\x57\x65\xc6\xc7\xfe\x87\x5c\xab\x95\x65\x9c\xdd\x67\x1c\xcc\xba\x67\x5c\x42\xda\xff\x02\xf8\x39\x7a\xf5\xbf\x00\xcf\xa0\xd4\xc6\x59\xaf\xff\x27\x91\xff\xcc\xf5\xd1\x63\xca\xa5\xbb\x05\x6b\x7f\xfd\x84\x62\xc0\x8e\x54\x8a\x0b\x50\x84\xdb\x56\xbc\xd4\x27\xf6\x98\x57\x7a\x63\xc8\xf8\x47\x38\xb2\x12\x85\x68\x2d\x61\x09\xb3\x5f\x77\xc9\x3d\x40\x49\x2a\x09\xd4\xad\x57\xe9\x5c\x2c\xc9\xf6\xb9\x96\xef\xd4\x10\x4f\x93\x5a\x84\xb7\x2b\xa7\xfd\x78\xb2\xc6\xa0\xe3\xb8\x87\x4d\xc5\x9b\xdd\x94\x46\x66\x0a\x1c\x48\xf2\xf1\xd6\x0c\x93\x38", 1017);
	syscall(__NR_msgsnd, r[0], 0x200002c0ul, 0x401ul, 0ul);
*(uint32_t*)0x200000c0 = 0x798e2636;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0xee01;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d4 = 0;
*(uint16_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint16_t*)0x20000118 = 0;
*(uint16_t*)0x2000011a = 0;
*(uint16_t*)0x2000011c = 0;
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = 0;
	syscall(__NR_msgctl, r[0], 1ul, 0x200000c0ul);
*(uint64_t*)0x200002c0 = 3;
memcpy((void*)0x200002c8, "\xee\xa3\x7d\xf3\x12\xcb\xf2\xed\x2a\x1b\x0b\x44\x24\x79\x7d\x43\x7c\x8d\x70\xe5\x08\xa5\x10\x40\x87\xb8\x7f\x11\x86\x31\x1f\x33\xc8\xd5\x69\xff\xa1\x16\xdb\xeb\x44\x74\xd0\x90\x44\xb1\x2c\x8c\xe1\x98\xa1\xcf\x65\xae\x32\x09\xdf\x6b\xff\x8e\x78\x24\xd2\xdb\x98\x88\x7d\x82\x21\x72\xf8\x24\x63\x1a\x3a\xcb\xdd\xb8\xdb\xe3\x62\xe6\x23\xfd\x62\xce\xf1\xe0\xb2\x67\x66\x9d\xa1\x6b\x3d\xb8\x0e\xb4\x80\x74\x47\x82\xbc\xd3\x2a\x5f\x8a\x7f\x48\x8b\xbf\x04\x73\xc5\x37\xc1\x92\xbc\xeb\x0a\x99\x07\xc4\x95\xdc\x79\xd9\xa7\x4c\xc0\x82\x6f\x0b\x44\x11\x0c\x2f\xcf\x12\x26\x93\x25\x8e\xbe\xe6\xc4\x55\x4f\x52\xf3\xb8\xeb\x1b\x9e\x36\xd3\xf5\x32\x25\x67\x7f\x0d\xfa\x2d\xe6\x63\xff\x15\x42\xd6\x04\xad\x34\x8c\xc6\xfa\x0b\xba\x2d\xfc\xa9\xf1\x23\x0a\x64\xc7\x19\x65\x4a\x10\x66\x7a\xb6\x8b\xb0\x6d\x4a\xc4\x64\xfc\x8d\xf8\xbb\xb6\xe0\x69\x83\xbd\xdf\x77\x5c\xed\xcb\x2c\xda\x10\x3e\x1a\xf9\xf3\x3f\x74\x80\xb5\x47\x62\x72\x38\x49\xd1\xf0\xd9\xb7\x65\x12\x99\xfb\x2f\x6f\x43\x5c\x75\xbb\xd5\x6e\x43\x17\x3a\x42\x0a\xef\x99\x59\x19\x66\x25\xbb\xe7\x7c\xcf\xc6\x96\x8a\x0f\xdf\x90\xd4\xeb\x68\xf9\xcf\x19\x1c\x1d\x41\xe6\xb6\x42\xfb\xd9\xcd\xa9\x60\x5a\xdb\x4e\x09\x53\x1a\x52\x5c\x3c\x94\xfe\x36\x71\x83\x96\x24\x5c\x1e\x63\x19\x43\xa5\xa0\xa6\x13\x94\x52\xec\x06\x41\x37\x49\xa2\x8f\x18\x41\x4c\x51\x12\xb2\x1b\x82\xd6\x47\x2e\x59\xb7\x21\x9f\x69\x7f\x4b\xb4\x39\xb2\x49\x91\x99\x0b\xf3\x82\x20\x3c\x38\x12\x93\x3e\x0e\x7d\x70\x52\xb4\x8b\xda\x7e\xbb\x22\x26\xc8\x4e\x2f\x92\xe5\x97\x53\x24\x40\xd3\x56\xcd\xd3\xaa\xd3\x8b\xac\x97\xde\xe9\xec\xb1\x70\x48\x19\x43\x08\x23\xff\x2a\x01\xb5\x92\x13\xe0\xfd\xc7\x0b\xea\xc5\x0a\xc8\x32\xdc\x35\xc3\x76\xab\xe8\x1c\xec\xb9\x31\xb3\x93\xb2\x31\xd2\xd5\x63\xc2\xc3\x8b\xb2\xfa\x82\xd2\x1b\x7a\x9a\xd4\x56\x87\xdb\x8c\x06\x90\xfd\x19\xe6\x2a\x26\x46\x88\xde\x1b\xf4\x38\xcd\x35\xb9\xf7\xf8\x5b\x32\x1f\x07\x3a\x0f\x82\xf9\xb2\x93\x93\xa6\xb0\xce\x84\xdb\x20\x7b\xcc\xa6\x99\x7a\x59\x85\x31\xba\x7f\x66\xec\xee\x32\x5e\x61\x92\xfa\x3b\xe0\x12\xb9\xeb\x35\x07\xe3\xe0\xe8\x7c\xde\xa4\x52\x5d\x7a\x51\x0a\x15\x80\x8d\x36\x23\x13\x72\x08\xbe\x63\xb7\x6e\x8d\xeb\x2f\xb9\xc7\x48\xf7\x19\xd4\xda\x17\xd8\xab\xd3\x8e\xe3\x48\xd1\x69\x33\x65\xe4\x25\xc5\x24\xc5\x78\x11\x36\x89\xee\xed\x61\x34\xee\x3e\x31\x15\xa2\x07\xb2\xca\x67\x1e\x5c\xb8\x2b\xb5\xfe\xc0\x6b\xd4\x3a\xfd\x2f\xec\x7e\x25\xcb\xbf\x2e\x3e\xed\xb5\x18\xa4\x43\x1c\x1f\x59\x58\xfa\x25\x14\x05\xca\x43\xa4\x6d\xf2\xdc\x36\xda\xdc\xcd\x9e\xbf\xe5\x39\x58\xb7\xa5\x5b\x5c\x8b\xf9\x1e\x9e\x2c\x80\x5d\x8b\x11\x81\x8a\x0b\xe0\x38\xbc\x31\xea\xbf\x43\xdb\xa6\xd9\xd5\x61\xb1\x19\x5f\x29\x8d\x3f\x74\x6c\xa8\xbe\xef\x48\x5c\x3c\xdc\x8f\x16\x78\x93\x08\xe9\xe8\xa9\xb6\x56\x08\x09\x6d\xb5\x21\x8c\x04\xd0\xa2\xa3\x72\x43\x8d\xea\xa4\xd5\x59\x27\x90\xe6\xb3\xf9\xa4\x94\x15\x16\x79\xd5\x2f\x34\xa3\x54\xa2\x75\xf2\x19\x98\x23\x3d\x59\x33\xa8\x89\xd6\xfb\x23\x0f\xc2\x63\x27\x78\x71\xa9\x6e\xd2\x47\xe3\x8e\xba\x6f\x8f\xc7\x76\xe2\x02\xf4\x39\xe4\x9d\x16\x88\x5c\xa1\xff\x53\x16\x15\xbc\x12\x95\xe7\x50\x4a\xde\xcd\x2d\xa0\xe7\x44\x17\x7e\xd4\xb5\x3f\xe1\xea\x4a\x7d\x31\x31\x0f\xd5\x45\xdf\x52\xb5\x15\xdd\x0e\xce\xdf\xdd\xb9\x94\x33\x7f\xfe\x3f\xa2\x46\x87\x42\xde\x41\x6f\xb1\xb0\x87\xc1\xd2\x55\x05\x95\x04\xd7\xae\x72\xcf\x5f\x8b\x84\x23\x6f\x38\x8b\x70\x40\x8c\x20\x13\xce\x67\xe2\xa4\x9b\x21\x65\xdc\x62\x63\xff\x2b\x7c\x2d\xe2\x7e\xa6\x95\x58\x4e\x14\x3c\xa0\x68\x2e\xa8\x05\x6d\x64\xd3\x05\xd0\x6a\x6d\x73\x48\xf4\xe1\xa1\x2d\x71\x56\x27\xf7\x22\x94\xdc\x76\x38\xc0\x7e\xb5\x0c\x90\xd4\x91\xd9\x2e\x7c\xd1\x6d\x0b\xc5\x45\xc7\x6e\xd8\x02\x57\x99\x9d\x5c\x9e\x57\x65\xc6\xc7\xfe\x87\x5c\xab\x95\x65\x9c\xdd\x67\x1c\xcc\xba\x67\x5c\x42\xda\xff\x02\xf8\x39\x7a\xf5\xbf\x00\xcf\xa0\xd4\xc6\x59\xaf\xff\x27\x91\xff\xcc\xf5\xd1\x63\xca\xa5\xbb\x05\x6b\x7f\xfd\x84\x62\xc0\x8e\x54\x8a\x0b\x50\x84\xdb\x56\xbc\xd4\x27\xf6\x98\x57\x7a\x63\xc8\xf8\x47\x38\xb2\x12\x85\x68\x2d\x61\x09\xb3\x5f\x77\xc9\x3d\x40\x49\x2a\x09\xd4\xad\x57\xe9\x5c\x2c\xc9\xf6\xb9\x96\xef\xd4\x10\x4f\x93\x5a\x84\xb7\x2b\xa7\xfd\x78\xb2\xc6\xa0\xe3\xb8\x87\x4d\xc5\x9b\xdd\x94\x46\x66\x0a\x1c\x48\xf2\xf1\xd6\x0c\x93\x38", 1017);
	syscall(__NR_msgsnd, 0, 0x200002c0ul, 0x401ul, 0ul);
*(uint32_t*)0x200000c0 = 0x798e2636;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0xee01;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d4 = 0;
*(uint16_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint16_t*)0x20000118 = 0;
*(uint16_t*)0x2000011a = 0;
*(uint16_t*)0x2000011c = 0;
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = 0;
	syscall(__NR_msgctl, 0, 1ul, 0x200000c0ul);
	syscall(__NR_msgrcv, 0, 0x200008c0ul, 0x63ul, 2ul, 0x1000ul);
	syscall(__NR_msgget, 0x798e2634ul, 4ul);
	syscall(__NR_msgctl, r[0], 0ul, 0);
memcpy((void*)0x20000040, "tmpfs\000", 6);
memcpy((void*)0x20000100, "./file0\000", 8);
syz_mount_image(0x20000040, 0x20000100, 0, 0, 0x20000000, 0, 0x20000340, 0);
memcpy((void*)0x200006c0, "msdos\000", 6);
memcpy((void*)0x20000700, "./file0\000", 8);
*(uint64_t*)0x20000000 = 0x20000080;
memset((void*)0x20000080, 79, 1);
*(uint64_t*)0x20000008 = 1;
*(uint64_t*)0x20000010 = 0;
*(uint8_t*)0x20000a00 = 0;
syz_mount_image(0x200006c0, 0x20000700, 1, 1, 0x20000000, 0x410, 0x20000a00, 0);
	syscall(__NR_msgrcv, r[0], 0x20000880ul, 0x16ul, 1ul, 0ul);
memcpy((void*)0x20000100, "./file0\000", 8);
	res = syscall(__NR_newfstatat, 0xffffffffffffff9cul, 0x20000100ul, 0x200002c0ul, 0ul);
	if (res != -1)
r[1] = *(uint32_t*)0x200002d8;
	res = syscall(__NR_msgget, 0ul, 0x7fful);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x200002c0 = 3;
memcpy((void*)0x200002c8, "\xee\xa3\x7d\xf3\x12\xcb\xf2\xed\x2a\x1b\x0b\x44\x24\x79\x7d\x43\x7c\x8d\x70\xe5\x08\xa5\x10\x40\x87\xb8\x7f\x11\x86\x31\x1f\x33\xc8\xd5\x69\xff\xa1\x16\xdb\xeb\x44\x74\xd0\x90\x44\xb1\x2c\x8c\xe1\x98\xa1\xcf\x65\xae\x32\x09\xdf\x6b\xff\x8e\x78\x24\xd2\xdb\x98\x88\x7d\x82\x21\x72\xf8\x24\x63\x1a\x3a\xcb\xdd\xb8\xdb\xe3\x62\xe6\x23\xfd\x62\xce\xf1\xe0\xb2\x67\x66\x9d\xa1\x6b\x3d\xb8\x0e\xb4\x80\x74\x47\x82\xbc\xd3\x2a\x5f\x8a\x7f\x48\x8b\xbf\x04\x73\xc5\x37\xc1\x92\xbc\xeb\x0a\x99\x07\xc4\x95\xdc\x79\xd9\xa7\x4c\xc0\x82\x6f\x0b\x44\x11\x0c\x2f\xcf\x12\x26\x93\x25\x8e\xbe\xe6\xc4\x55\x4f\x52\xf3\xb8\xeb\x1b\x9e\x36\xd3\xf5\x32\x25\x67\x7f\x0d\xfa\x2d\xe6\x63\xff\x15\x42\xd6\x04\xad\x34\x8c\xc6\xfa\x0b\xba\x2d\xfc\xa9\xf1\x23\x0a\x64\xc7\x19\x65\x4a\x10\x66\x7a\xb6\x8b\xb0\x6d\x4a\xc4\x64\xfc\x8d\xf8\xbb\xb6\xe0\x69\x83\xbd\xdf\x77\x5c\xed\xcb\x2c\xda\x10\x3e\x1a\xf9\xf3\x3f\x74\x80\xb5\x47\x62\x72\x38\x49\xd1\xf0\xd9\xb7\x65\x12\x99\xfb\x2f\x6f\x43\x5c\x75\xbb\xd5\x6e\x43\x17\x3a\x42\x0a\xef\x99\x59\x19\x66\x25\xbb\xe7\x7c\xcf\xc6\x96\x8a\x0f\xdf\x90\xd4\xeb\x68\xf9\xcf\x19\x1c\x1d\x41\xe6\xb6\x42\xfb\xd9\xcd\xa9\x60\x5a\xdb\x4e\x09\x53\x1a\x52\x5c\x3c\x94\xfe\x36\x71\x83\x96\x24\x5c\x1e\x63\x19\x43\xa5\xa0\xa6\x13\x94\x52\xec\x06\x41\x37\x49\xa2\x8f\x18\x41\x4c\x51\x12\xb2\x1b\x82\xd6\x47\x2e\x59\xb7\x21\x9f\x69\x7f\x4b\xb4\x39\xb2\x49\x91\x99\x0b\xf3\x82\x20\x3c\x38\x12\x93\x3e\x0e\x7d\x70\x52\xb4\x8b\xda\x7e\xbb\x22\x26\xc8\x4e\x2f\x92\xe5\x97\x53\x24\x40\xd3\x56\xcd\xd3\xaa\xd3\x8b\xac\x97\xde\xe9\xec\xb1\x70\x48\x19\x43\x08\x23\xff\x2a\x01\xb5\x92\x13\xe0\xfd\xc7\x0b\xea\xc5\x0a\xc8\x32\xdc\x35\xc3\x76\xab\xe8\x1c\xec\xb9\x31\xb3\x93\xb2\x31\xd2\xd5\x63\xc2\xc3\x8b\xb2\xfa\x82\xd2\x1b\x7a\x9a\xd4\x56\x87\xdb\x8c\x06\x90\xfd\x19\xe6\x2a\x26\x46\x88\xde\x1b\xf4\x38\xcd\x35\xb9\xf7\xf8\x5b\x32\x1f\x07\x3a\x0f\x82\xf9\xb2\x93\x93\xa6\xb0\xce\x84\xdb\x20\x7b\xcc\xa6\x99\x7a\x59\x85\x31\xba\x7f\x66\xec\xee\x32\x5e\x61\x92\xfa\x3b\xe0\x12\xb9\xeb\x35\x07\xe3\xe0\xe8\x7c\xde\xa4\x52\x5d\x7a\x51\x0a\x15\x80\x8d\x36\x23\x13\x72\x08\xbe\x63\xb7\x6e\x8d\xeb\x2f\xb9\xc7\x48\xf7\x19\xd4\xda\x17\xd8\xab\xd3\x8e\xe3\x48\xd1\x69\x33\x65\xe4\x25\xc5\x24\xc5\x78\x11\x36\x89\xee\xed\x61\x34\xee\x3e\x31\x15\xa2\x07\xb2\xca\x67\x1e\x5c\xb8\x2b\xb5\xfe\xc0\x6b\xd4\x3a\xfd\x2f\xec\x7e\x25\xcb\xbf\x2e\x3e\xed\xb5\x18\xa4\x43\x1c\x1f\x59\x58\xfa\x25\x14\x05\xca\x43\xa4\x6d\xf2\xdc\x36\xda\xdc\xcd\x9e\xbf\xe5\x39\x58\xb7\xa5\x5b\x5c\x8b\xf9\x1e\x9e\x2c\x80\x5d\x8b\x11\x81\x8a\x0b\xe0\x38\xbc\x31\xea\xbf\x43\xdb\xa6\xd9\xd5\x61\xb1\x19\x5f\x29\x8d\x3f\x74\x6c\xa8\xbe\xef\x48\x5c\x3c\xdc\x8f\x16\x78\x93\x08\xe9\xe8\xa9\xb6\x56\x08\x09\x6d\xb5\x21\x8c\x04\xd0\xa2\xa3\x72\x43\x8d\xea\xa4\xd5\x59\x27\x90\xe6\xb3\xf9\xa4\x94\x15\x16\x79\xd5\x2f\x34\xa3\x54\xa2\x75\xf2\x19\x98\x23\x3d\x59\x33\xa8\x89\xd6\xfb\x23\x0f\xc2\x63\x27\x78\x71\xa9\x6e\xd2\x47\xe3\x8e\xba\x6f\x8f\xc7\x76\xe2\x02\xf4\x39\xe4\x9d\x16\x88\x5c\xa1\xff\x53\x16\x15\xbc\x12\x95\xe7\x50\x4a\xde\xcd\x2d\xa0\xe7\x44\x17\x7e\xd4\xb5\x3f\xe1\xea\x4a\x7d\x31\x31\x0f\xd5\x45\xdf\x52\xb5\x15\xdd\x0e\xce\xdf\xdd\xb9\x94\x33\x7f\xfe\x3f\xa2\x46\x87\x42\xde\x41\x6f\xb1\xb0\x87\xc1\xd2\x55\x05\x95\x04\xd7\xae\x72\xcf\x5f\x8b\x84\x23\x6f\x38\x8b\x70\x40\x8c\x20\x13\xce\x67\xe2\xa4\x9b\x21\x65\xdc\x62\x63\xff\x2b\x7c\x2d\xe2\x7e\xa6\x95\x58\x4e\x14\x3c\xa0\x68\x2e\xa8\x05\x6d\x64\xd3\x05\xd0\x6a\x6d\x73\x48\xf4\xe1\xa1\x2d\x71\x56\x27\xf7\x22\x94\xdc\x76\x38\xc0\x7e\xb5\x0c\x90\xd4\x91\xd9\x2e\x7c\xd1\x6d\x0b\xc5\x45\xc7\x6e\xd8\x02\x57\x99\x9d\x5c\x9e\x57\x65\xc6\xc7\xfe\x87\x5c\xab\x95\x65\x9c\xdd\x67\x1c\xcc\xba\x67\x5c\x42\xda\xff\x02\xf8\x39\x7a\xf5\xbf\x00\xcf\xa0\xd4\xc6\x59\xaf\xff\x27\x91\xff\xcc\xf5\xd1\x63\xca\xa5\xbb\x05\x6b\x7f\xfd\x84\x62\xc0\x8e\x54\x8a\x0b\x50\x84\xdb\x56\xbc\xd4\x27\xf6\x98\x57\x7a\x63\xc8\xf8\x47\x38\xb2\x12\x85\x68\x2d\x61\x09\xb3\x5f\x77\xc9\x3d\x40\x49\x2a\x09\xd4\xad\x57\xe9\x5c\x2c\xc9\xf6\xb9\x96\xef\xd4\x10\x4f\x93\x5a\x84\xb7\x2b\xa7\xfd\x78\xb2\xc6\xa0\xe3\xb8\x87\x4d\xc5\x9b\xdd\x94\x46\x66\x0a\x1c\x48\xf2\xf1\xd6\x0c\x93\x38", 1017);
	syscall(__NR_msgsnd, r[2], 0x200002c0ul, 0x401ul, 0ul);
*(uint32_t*)0x200000c0 = 0x798e2636;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0xee01;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d4 = 0;
*(uint16_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint16_t*)0x20000118 = 0;
*(uint16_t*)0x2000011a = 0;
*(uint16_t*)0x2000011c = 0;
*(uint32_t*)0x20000120 = 0;
*(uint32_t*)0x20000124 = 0;
	syscall(__NR_msgctl, r[2], 1ul, 0x200000c0ul);
*(uint64_t*)0x20000740 = 1;
memcpy((void*)0x20000748, "\xcc\xa3\xcb\x91\x71\x80\x7d\x04\x3a\x8f\x6f\xbc\x8b\xe3\x6e\x70\x29\x0b\x44\x70\x29\xd9\x3f\x28\xb0\xfe\x07\xfd\x79\xbe\xa1\x6e\x3e\xd1\xa8\x6b\xe1\xc4\xc4\x8b\x84\xfb\x27\xc3\x40\x57\x0d\x48\x31\x75\x69\x9a\x92\xac\xfc\x41\x87\xb4\x5d\x09\x70\xc5\xdc\xf8\xc7\xa6\x2a\x89\x63\x66\x67\x45\x50\xe4\x0e\xf2\x79\xd2\x15\x80\xd9\x26\xe8\x77\x3a\xd5\x14\xed\xe8\x59\xad\xcb\x81\xf0\x57\xd3\x86\x26\xbf\x93\x72\xc9\x17\xe3\xca\x31\xfd\xb5\x3e\xc4\x2d\x07\x46\xd1\xa5\x04\x0b\x73\x73\x89\x7e\x4c\x3e\x26\x87\xad\xdd\x2e\xa9\xba\xa0\x4d\x14\x7c\xc1\x7e\x38", 137);
	syscall(__NR_msgsnd, r[2], 0x20000740ul, 0x91ul, 0x800ul);
	syscall(__NR_msgrcv, r[0], 0x20000800ul, 0x7eul, 0ul, 0x3400ul);
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_lchown, 0x20000000ul, r[1], 0);
memcpy((void*)0x20000300, "./file0\000", 8);
memcpy((void*)0x20000340, "security.capability\000", 20);
*(uint32_t*)0x20000380 = 0x3000000;
*(uint32_t*)0x20000384 = 7;
*(uint32_t*)0x20000388 = 0x57;
*(uint32_t*)0x2000038c = 6;
*(uint32_t*)0x20000390 = 0x10001;
*(uint32_t*)0x20000394 = r[1];
	syscall(__NR_lsetxattr, 0x20000300ul, 0x20000340ul, 0x20000380ul, 0x18ul, 2ul);
memcpy((void*)0x200000c0, "tmpfs\000", 6);
memcpy((void*)0x20000140, "./file0\000", 8);
*(uint64_t*)0x200001c0 = 0x20000180;
memcpy((void*)0x20000180, "\x24\xae\xa1\x49\xd1\xb7\x9e\x69\x88\x74\x44\x10\x87\xa5\x46\xb8\xc6\x78\xf0\x98\x56\x80\x54\xb5\x98\x88\xea\x60\xde\x9d\x17\xea\xf3\x7f\x51\x3d\x2a\x72\x29", 39);
*(uint64_t*)0x200001c8 = 0x27;
*(uint64_t*)0x200001d0 = 0x813;
memcpy((void*)0x20000200, "huge=never", 10);
*(uint8_t*)0x2000020a = 0x2c;
memcpy((void*)0x2000020b, "nr_blocks", 9);
*(uint8_t*)0x20000214 = 0x3d;
*(uint8_t*)0x20000215 = 0x67;
*(uint8_t*)0x20000216 = 0x78;
*(uint8_t*)0x20000217 = 0x2d;
*(uint8_t*)0x20000218 = 0x2c;
memcpy((void*)0x20000219, "huge=advise", 11);
*(uint8_t*)0x20000224 = 0x2c;
memcpy((void*)0x20000225, "pcr", 3);
*(uint8_t*)0x20000228 = 0x3d;
sprintf((char*)0x20000229, "%020llu", (long long)0x10);
*(uint8_t*)0x2000023d = 0x2c;
memcpy((void*)0x2000023e, "fsuuid", 6);
*(uint8_t*)0x20000244 = 0x3d;
*(uint8_t*)0x20000245 = 0x66;
*(uint8_t*)0x20000246 = 0x36;
*(uint8_t*)0x20000247 = 0x35;
*(uint8_t*)0x20000248 = 0x32;
*(uint8_t*)0x20000249 = 0x31;
*(uint8_t*)0x2000024a = 0x62;
*(uint8_t*)0x2000024b = 0x34;
*(uint8_t*)0x2000024c = 0x34;
*(uint8_t*)0x2000024d = 0x2d;
*(uint8_t*)0x2000024e = 0x37;
*(uint8_t*)0x2000024f = 0x39;
*(uint8_t*)0x20000250 = 6;
*(uint8_t*)0x20000251 = 0x61;
*(uint8_t*)0x20000252 = 0x2d;
*(uint8_t*)0x20000253 = 0;
*(uint8_t*)0x20000254 = 0x33;
*(uint8_t*)0x20000255 = 0x31;
*(uint8_t*)0x20000256 = 0x63;
*(uint8_t*)0x20000257 = 0x2d;
*(uint8_t*)0x20000258 = 0x39;
*(uint8_t*)0x20000259 = 0x36;
*(uint8_t*)0x2000025a = 0x30;
*(uint8_t*)0x2000025b = 0x34;
*(uint8_t*)0x2000025c = 0x2d;
*(uint8_t*)0x2000025d = 0x39;
*(uint8_t*)0x2000025e = 0x36;
*(uint8_t*)0x2000025f = 0x37;
*(uint8_t*)0x20000260 = 0x32;
*(uint8_t*)0x20000261 = 0x62;
*(uint8_t*)0x20000262 = 0x36;
*(uint8_t*)0x20000263 = 0x31;
*(uint8_t*)0x20000264 = 0x62;
*(uint8_t*)0x20000265 = 0x2c;
memcpy((void*)0x20000266, "audit", 5);
*(uint8_t*)0x2000026b = 0x2c;
memcpy((void*)0x2000026c, "smackfshat", 10);
*(uint8_t*)0x20000276 = 0x3d;
memcpy((void*)0x20000277, "%*#", 3);
*(uint8_t*)0x2000027a = 0x2c;
memcpy((void*)0x2000027b, "subj_role", 9);
*(uint8_t*)0x20000284 = 0x3d;
memcpy((void*)0x20000285, "^)(\222", 4);
*(uint8_t*)0x20000289 = 0x2c;
memcpy((void*)0x2000028a, "measure", 7);
*(uint8_t*)0x20000291 = 0x2c;
memcpy((void*)0x20000292, "smackfsfloor", 12);
*(uint8_t*)0x2000029e = 0x3d;
memcpy((void*)0x2000029f, "tmpfs\000", 6);
*(uint8_t*)0x200002a5 = 0x2c;
memcpy((void*)0x200002a6, "fowner>", 7);
sprintf((char*)0x200002ad, "%020llu", (long long)-1);
*(uint8_t*)0x200002c1 = 0x2c;
*(uint8_t*)0x200002c2 = 0;
syz_mount_image(0x200000c0, 0x20000140, 0x8100000, 1, 0x200001c0, 0xc000, 0x20000200, 0);
	return 0;
}