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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x01\x00\x00\x0c\x00\x00\x00\xce\x00\x00\x00\x0f\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x20\x00\x00\x20\x00\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x80\x00\x00\x00\x08\x00\x00\x00\x52\x47\x00\x00\x62\x01", 102);
*(uint64_t*)0x20000208 = 0x66;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010200;
memcpy((void*)0x20010200, "\x01\x00\x00\x00\x00\x00\x05\x00\x11", 9);
*(uint64_t*)0x20000220 = 9;
*(uint64_t*)0x20000228 = 0x560;
*(uint64_t*)0x20000230 = 0x20010300;
memset((void*)0x20010300, 3, 1);
*(uint64_t*)0x20000238 = 1;
*(uint64_t*)0x20000240 = 0x640;
*(uint64_t*)0x20000248 = 0x20010400;
memcpy((void*)0x20010400, "\x03\x00\x00\x00\x13\x00\x00\x00\x23\x00\x00\x00\xce\x00\x0f", 15);
*(uint64_t*)0x20000250 = 0xf;
*(uint64_t*)0x20000258 = 0x800;
*(uint64_t*)0x20000260 = 0x20010500;
memcpy((void*)0x20010500, "\xff\xff\xff\xff\xfc\xff\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff", 1024);
*(uint64_t*)0x20000268 = 0x400;
*(uint64_t*)0x20000270 = 0xc00;
*(uint64_t*)0x20000278 = 0x20011600;
memcpy((void*)0x20011600, "\x50\x4d\x4d\x00\x50\x4d\x4d\xff", 8);
*(uint64_t*)0x20000280 = 8;
*(uint64_t*)0x20000288 = 0x4400;
*(uint64_t*)0x20000290 = 0x20011700;
memcpy((void*)0x20011700, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06", 21);
*(uint64_t*)0x20000298 = 0x15;
*(uint64_t*)0x200002a0 = 0x4800;
*(uint64_t*)0x200002a8 = 0x200003c0;
memset((void*)0x200003c0, 255, 2);
*(uint64_t*)0x200002b0 = 2;
*(uint64_t*)0x200002b8 = 0x4c00;
*(uint64_t*)0x200002c0 = 0x20012b00;
memcpy((void*)0x20012b00, "\xed\x41\x00\x00\x00\x04\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x02", 29);
*(uint64_t*)0x200002c8 = 0x1d;
*(uint64_t*)0x200002d0 = 0x8c80;
*(uint64_t*)0x200002d8 = 0x20012c00;
memcpy((void*)0x20012c00, "\x80\x81\x00\x00\x00\x18\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x01\x00\x0c\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x12\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x18\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x14", 85);
*(uint64_t*)0x200002e0 = 0x55;
*(uint64_t*)0x200002e8 = 0x8d00;
*(uint8_t*)0x20013800 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x40000, 0xa, 0x20000200, 0, 0x20013800, 0);
memcpy((void*)0x20000040, "./file0\000", 8);
memcpy((void*)0x20000080, "trusted.overlay.upper\000", 22);
*(uint8_t*)0x20000600 = 0;
*(uint8_t*)0x20000601 = 0xfb;
*(uint8_t*)0x20000602 = 0x81;
*(uint8_t*)0x20000603 = 0;
*(uint8_t*)0x20000604 = 0;
memcpy((void*)0x20000605, "\x14\xa4\x4e\x3e\x7e\x95\x71\x4d\xfb\x3a\x5f\xd2\x10\x3f\xc8\x4a", 16);
memcpy((void*)0x20000615, "\x8a\x15\x0e\x8b\x1c\x7d\x01\x8b\xa3\xd5\xbd\xc8\x6b\x88\x22\x10\xef\x0d\xac\x40\x16\x3e\x85\xf6\xbe\xaf\xa9\x43\xab\xa8\x32\x2f\x1b\xd4\xaf\x88\x61\x07\x45\x96\x16\xd8\xbe\x9d\x47\x8a\xee\x27\xfd\x2b\x9e\xfc\xc0\xb8\xf1\x1c\x6a\x3b\x79\xa7\xc7\x93\xc2\x72\x66\x9f\x74\x3e\x9b\xe3\x6b\x8f\x0f\x6c\x4f\x9a\x18\x0a\x90\xbe\x07\xc3\xc4\x48\xa1\xec\x96\xad\xec\x37\x33\x80\x31\xe6\xb6\xe9\x49\x43\xf2\x29\x4b\xc5\x71\x11\x52\x09\x28\x25\x7e\xe9\xd1\x41\x29\x8b\x6a\x69\x97\xac\x66\xd4\x02\xff\x20\x9d\xbc\x4c\x40\x2b\x64\xa4\x64\x63\x88\xe0\xe5\x01\x52\x28\xd7\xcf\xc8\xbd\xc9\xe0\xec\x5d\x03\x60\x45\x34\xab\x3c\xc4\x3e\x5f\x4b\xb3\x20\xcf\x07\xcf\x15\xc0\xc8\x3e\xfc\x42\x37\x99\x8c\x58\x57\xda\xb1\xee\x15\x15\xf4\xa0\xe3\x34\xe9\xdf\x69\xe4\x78\x84\xe9\xaa\xc4\x1d\x68\x31\xd1\x66\x39\xf0\x87\x00\x5c\x67\x78\x83\xfb\x0b\x0e\x4d\x60\xa7\x38\xcf\x11\xcc\xfb\x71\xc6\xe7\xd9\xcb\xf1\xa0\x08\x38\x25\x76\xb2\x77\x95\x93\x36\x0f\x79\xb7\x75\x3f\xce\x74\x94\x68\x58\xb2\xc3\x55\x57\x14\xbd\x3f\x9f\x72\xd0\x79\x49\x6d\xaa\xeb\x93\x0a\x1f\x15\xa2\x90\x14\xa8\x74\x2c\x6f\x5d\x34\x95\x90\xee\x0a\x4c\x7a\x3b\x40\xf5\x05\x74\x7c\xdd\x6e\xed\xad\xc4\x33\x51\xe4\x0d\xb8\xfa\xa0\x7b\x60\x6c\x13\x0f\x85\x0e\x2c\x71\x57\xa0\x3a\xfc\xaf\xbd\x60\x6a\x3b\x00\x32\x7f\x52\x1e\x48\x58\x48\x94\x1b\xdf\x3b\x33\x91\xf2\x9f\x2a\x0c\xc6\x2f\x4b\x94\x23\x77\x00\x0c\x0d\xf5\x3e\xcb\x5c\xf6\x6a\xd5\x0c\x9d\x53\x83\xd5\x4d\xed\x72\x51\xc7\x01\x5b\xa9\xeb\x1a\xea\xb5\x30\x57\xfb\x9c\x04\x09\x56\x9f\x95\xa6\x32\x4a\x09\x01\x1a\x97\xe3\x59\xac\xe1\x72\x2d\x94\x09\x0e\x8a\x5e\x62\xc4\x4c\x75\xbd\x3f\xfb\xe7\x97\xd2\x07\xae\xe3\x99\xdc\x65\xc5\x0d\x47\xe9\x2c\x65\x1a\x02\x50\x82\x32\xf4\x37\xca\x96\x41\xdb\xb4\xff\x82\x33\x2e\x9b\xda\x6e\x45\x54\x52\x2a\x7e\xb9\xd1\x6f\xfa\x26\x41\xff\x8c\x3d\xee\x84\x38\x5a\x5f\x21\x79\xa4\xb0\x8c\xbd\x4b\x42\x2a\x30\xaf\xa6\x08\x37\x72\xa9\x83\xec\x4c\x7f\xad\x56\x79\xaa\xb2\x5a\x53\xf2\xff\x22\x7f\x35\x50\x9c\xc9\x43\x7f\xee\xf4\xdd\xaf\x57\x73\x47\xe5\x5a\x85\x11\xf6\x73\x27\xd8\xdd\x65\x01\xe6\x2f\xb5\xaa\xfe\x4b\xf7\x5f\xdb\xce\xbd\xfa\xfd\xef\x7f\x63\x1a\x48\xe9\xc6\x0f\x90\x7b\x5f\xd3\xe8\x8f\xbe\x44\x11\x87\x91\xcb\x13\x19\x06\xf7\x6e\x6a\xd1\x3e\xa9\xda\xfb\x98\xb1\xb3\xcb\x81\x80\xf7\x41\xb1\xcc\x34\x49\xff\xe5\xe6\x0e\x56\x47\x57\x2e\xac\x38\x68\x33\x83\xd5\xa6\xff\xd8\x51\xaa\x78\x4c\x86\x2a\xae\xde\xb3\x2c\xa2\x18\xc7\x6d\xed\xe2\x59\x5e\xd1\xa4\xdf\xed\xd9\x8a\xde\xd7\x6f\x14\xdf\xe8\xef\x8a\x22\x1c\x81\x5b\x49\x5e\x81\x0d\xab\xca\x66\xbf\x0c\xf7\x5d\xdc\x7f\xfd\x08\x17\x99\x2e\xe2\xd9\x99\x5e\x74\x03\xa3\xce\x33\x25\x2b\x4e\x1d\x08\x39\x90\xa0\x17\xf2\x56\x80\xa1\x36\xd0\x99\x2b\xc0\xa8\x0b\x4a\x16\x54\xe1\xb7\xb0\x37\xe7\xc3\x7b\x5a\x45\x6d\x4d\x58\xd8\x78\x48\x31\x9c\x57\x55\x7c\x00\x33\x0d\xe1\x40\x39\xb7\xfb\x12\x38\x2e\x72\x61\xeb\xba\x67\xae\xcd\xc0\x24\x2e\x9e\x95\x1c\xa7\x05\x96\xe1\x0b\x79\x4a\x27\xb2\xbc\xd8\x56\x7a\x83\xea\x8c\xe3\x3c\x5d\xf3\x92\x4e\x42\x4a\xcd\x6c\xf2\x48\x63\xd7\x4e\xe8\x50\xd5\x60\x92\x58\xcc\xd2\x89\x2a\x1c\xaf\xc9\x03\x6b\x93\x53\xfc\x0f\x78\x2a\x2b\xb8\x1c\x0e\xa2\x26\x67\xb5\x62\x54\x26\xb6\x3c\x66\xd5\x20\x9c\x9a\x72\x87\x0c\x85\xb0\x39\x0d\x75\xd0\x6f\xa1\x2e\xe6\xce\xe8\x48\x92\xcc\xd3\x70\xd3\xad\xe3\x91\xa4\x4f\xc8\xae\xcc\x12\xe3\xf9\x43\x97\x15\x11\x05\xbb\xcb\x78\x77\x79\xec\xc7\x94\x23\x79\xb2\x5b\x4b\xe9\xe2\xba\x05\x59\xc0\xb1\x5d\x7b\xa1\x8c\x56\xd1\xe6\x21\x77\x37\xa7\x17\x3d\xff\xb1\x9c\xa6\x01\x8c\x09\xc5\xc9\x20\xaf\x2c\x76\x10\xc2\xb3\x00\xf7\x01\x6f\x00\x62\xb9\x88\x62\x06\xf9\x3b\x0b\x05", 876);
	syscall(__NR_setxattr, 0x20000040ul, 0x20000080ul, 0x20000600ul, 0x381ul, 0ul);
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_newfstatat, 0xffffffffffffff9cul, 0x20000080ul, 0x20000140ul, 0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000158;
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_lchown, 0x20000000ul, r[0], 0);
	return 0;
}
