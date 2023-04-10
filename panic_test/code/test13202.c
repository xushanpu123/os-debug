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
#ifndef __NR_pwritev2
#define __NR_pwritev2 328
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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x01\x00\x00\x0c\x00\x00\x00\xce\x00\x00\x00\x0f\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x20\x00\x00\x20\x00\x00\x00\xd7\xf4\x65\x5f\xd7\xf4\x65\x5f\x01\x00\xff\xff\x53\xef", 58);
*(uint64_t*)0x20000208 = 0x3a;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010400;
memcpy((void*)0x20010400, "\x03\x00\x00\x00\x13\x00\x00\x00\x23\x00\x00\x00\xce\x00\x0f", 15);
*(uint64_t*)0x20000220 = 0xf;
*(uint64_t*)0x20000228 = 0x800;
*(uint64_t*)0x20000230 = 0x20010500;
memcpy((void*)0x20010500, "\xff\xff\xff\xff\xfc\xff\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff", 1024);
*(uint64_t*)0x20000238 = 0x400;
*(uint64_t*)0x20000240 = 0xc00;
*(uint64_t*)0x20000248 = 0x20011800;
memset((void*)0x20011800, 255, 2);
*(uint64_t*)0x20000250 = 2;
*(uint64_t*)0x20000258 = 0x4c00;
*(uint64_t*)0x20000260 = 0x20000140;
memcpy((void*)0x20000140, "\xed\x41\x00\x00\x00\x44\x00\x00\xd7\xf4\x65\x5f\xd7\x7e\xeb\x3f\x42\xf4\x65\x5f\x00\x08\x00\x00\x00\x00\x02\x0d\x9d", 29);
*(uint64_t*)0x20000268 = 0x1d;
*(uint64_t*)0x20000270 = 0x8c80;
syz_mount_image(0x20000000, 0x20000100, 0x40000, 5, 0x20000200, 0, 0x20013800, 0);
memcpy((void*)0x200000c0, "./file0\000", 8);
	syscall(__NR_chdir, 0x200000c0ul);
memcpy((void*)0x200002c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200025c0 = 0x20000080;
memset((void*)0x20000080, 7, 1);
*(uint64_t*)0x200025c8 = 1;
	syscall(__NR_pwritev, r[0], 0x200025c0ul, 1ul, 0xded2, 0);
*(uint64_t*)0x20000280 = 0x20000180;
memcpy((void*)0x20000180, "\x1b\x75\x64\xe0\x0b\x5b\x02\x69\x09\x5d\x94\x7e\x4f\x0d\x1c\x80\xe8\xbb\xcc\x1c\x75\x9f\x60\xea\xa9\x90\x50\x7e\xa5\x0f\x58\x78\x20\x14\x1b\x46\xe2\x4d\x0b\xc2\xd2\xdf\x79\x30\x1b\x59\x17\xc2\xe4\x60\x9a\x98\x73\x08\xac\x1a\x11\x54\x87\xd2\x77", 61);
*(uint64_t*)0x20000288 = 0x3d;
*(uint64_t*)0x20000290 = 0x20000300;
memcpy((void*)0x20000300, "\xb5\xec\x08\x85\x17\xcb\xa0\xc7\xa7\xf2\x11\x0e\xc7\xcd\x05\xac\x3b\x42\xba\x39\x1b\xfc\x65\x19\xce\x9f\xe3\x22\xa9\x1f\x32\x8a\xc4\xbf\x2c\xc8\x82\x71\x5b\x64\x43\xa5\x89\x4f\x1d\xbb\xd0\x86\xc0\x64\x00\x9a\x23\x0a\xf5\xac\x83\x39\x82\x5e\x11\x28\x16\xca\x58\xda\xa1\x8f\x5f\x01\x1a\x25\x7c\xff\x5c\x89\xa1\xa6\x11\xa2\x42\x34\xd9\xdf\x90\x37\x3f\x6d\x6d\xfa\x3f\xab\x75\xbc\x27\x04\x1a\x11\x6b\xcd\xde\x29\xe9\xb8\x49\x68\x31\x00\x1d\x06\x51\x6b\x2c\x91\x26\x1b\x52\x9b\xa1\x65\x50\x57\x53\xe1\xbd\x7e\x8f\x3e\x97\x6f\xc6\x81\xf5\x9b\x65\x83\xdb\x09\xb6\x61\x93\xc9\xa2\xcf\xf5\xe4\x64\x36\xce\x3f\xac\xe6\xd6\xb7\x7b\xa5\x03\x30\xaa\xb3\xd7\x21\xd6\xc6\xb0\x43\x5f\x9b\xc1\xfd\x1d\x2b\xc0\x7b\x71\xf3\xf5\x50\x71\xb0", 180);
*(uint64_t*)0x20000298 = 0xb4;
*(uint64_t*)0x200002a0 = 0x200003c0;
memcpy((void*)0x200003c0, "\x15\x0a\xc3\x6e\xe8\xa9\xb6\xcc\xa1\xe1\xdb\x7b\x3e\x1c\xec\xb2\xa8\x0f\x0b\xd9\xe7\x32\x55\x7f\xd5\x62\x7b\x87\xfc\x68\xa3\x2c\x37\xe9\x5b\x4a\xf1\xb0\x2a\xa1\x3f\x12\xcb\xdc\x04\xc7\xa2\xde\xb5\xbd\xce\xd7\xf2\x95\x5d\x0d\xf7\x7c\x37\xf4\x88\x9f\x4e\xa8\x40\x6b\x01\xb1\x7f\xc9\x54\x2b\xb3\xfc\x10\x26\x73\x0b\x44\x0f\xc9\x9c\x3a\x1e\x0c\xc0\x95\x0a\x53\x64\x87\xa6\x32\x76\xee\x78\xe7\x9d\x1b\x86\x2a\x16\x93\x03\xda\x01\xcd\x44\xcb\xbe\x3c\x0c\x1d\x85\xa8\x88\x58\x7a\x29\xea\x74\xed\x0b\x86\x5e\x0a\x18\x46\xb1\xc5\x6b\x8f\x2f\x89\xc5\xf6\x8b\xf1\x71\x59\xaf\xdd\xdf\x49\x66\x83\x11\x2f\xbb\xa5\xcf\x72\x32\x82\x32\xdb\x19\x7c\x55\x53\x88\xaf\xe0\xdc\x31\x87\x0e\x83\x6c\x5f\x63\xa4\xac\x00\x2e\xc2\xad\xc2\xdc\x08\xbd\x2b\x83\x44\x3b\xac\x14\x0c\x3e\xb4\xb0\x76\x2f\x5e\xa2\x22\x54\x5a\x50\x4c\xb9\xc3\x0b\x9e\x09\x58\x7f\xf3\x15\xca\xe7\x82\xe6\x3d\x9b\x6f\xe3\xc2\xb4\xbb\xba\xd5\x34\x00\x30\x97\x4b\xdf\x8a\x0d\xe1\xee\xa7\x97\x6a\x32\xc4\x26\x39\xa0\xac\xce\x9b\x96\xde\xbe\x5c\xef\xb0\x06\xea\x08\xb3\xe5\xa4\x7c\xe6\xc6\x6f\x0e\x92\x58\xe3\x76\x5d\x88\xe0\x1b\x5f\x49\xb1\x45\x27\xdd\x18\x4b\x4f\x93\xfc\xdb\x6c\xd4\xe0\x61\x4b\x45\xb9\xbc\xeb\x72\x28\x18\xfb\xcc\x5a\xca\xe1\x7e\xff\x99\xc6\x57\x1e\xe3\x01\xe0\x1e\x68\xbf\x3e\x70\xaa\xe5\x3d\xa9\x1f\x51\x7a\x67\x2f\xae\xd0\xb4\xc6\x41\xcb\x21\xd4\x24\x05\xff\x23\x07\x9c\xbf\x4b\xc7\x14\x5e\x59\x6f\x7b\x27\xdd\x4e\x29\x60\xf1\x32\xcf\x0d\xad\x19\x27\x31\xb9\x6e\x1a\xdc\x15\xf3\x0e\x31\xa4\x1c\xd2\xd6\xd9\x22\x77\xed\x9a\x2b\x39\x6f\x0b\x24\xef\x1d\x13\xa5\x66\xe6\x5f\x09\x19\x67\xf5\x93\x1b\x4c\x08\x63\xa4\x08\x64\x9e\x20\xee\x8d\xd1\xe7\xa0\x04\x02\x37\x36\xe0\x07\xe0\x79\x43\xd0\x8e\xa7\x57\xb6\x59\x58\x41\x55\xf5\xb2\x83\x28\x1e\x8b\xb7\xf2\xe4\x1c\x1d\xfa\x7a\xc0\xee\xa3\xfe\x8d\xba\xbe\xae\x1a\x9d\xbf\xa9\x65\x48\x90\x4d\xa6\xff\xb1\xdc\x5e\x0e\x08\xfa\xd8\xdd\x8f\xaf\x10\x14\xba\xd5\xe7\xf2\x3f\x10\x2b\xd6\x0d\x1e\xc3\xa5\xc2\x13\x4d\x2c\x76\x4e\x4c\x46\x93\x0e\x53\x66\xc7\xbd\x64\x43\x1a\xbc\xef\x59\x7d\x2f\xf3\xd5\x80\x31\x1e\x83\x31\xdc\x70\x4a\xc2\xfb\x65\xa6\x0d\xa6\x0e\x46\x0b\x9a\xe5\x61\x09\xc2\x71\xb8\xe7\xdc\xce\x5c\xc5\x4f\xf7\x70\x2b\x99\xaa\x4f\xa2\xee\xaf\xfb\x6d\xfa\xea\x17\x96\x7e\x30\xf9\x08\xce\x22\x3a\x73\xdb\x9b\x62\x56\xe7\xab\x3d\x98\xf5\x29\x8a\xab\xc4\x6e\x29\xc0\xc5\xe3\x36\x67\x06\x03\x04\xba\xb8\x5c\xc4\x6c\xf0\xe9\x24\x81\x06\x13\x70\xcf\x94\xd9\x03\xf0\xab\xed\xe0\x87\xbc\x3c\x15\xc9\x75\x77\xb0\xb5\xee\x88\xd5\x55\x8b\x82\x47\x02\x26\x47\xc9\xbf\x29\xa4\x9f\x0d\x1e\x81\xb6\xbc\x24\x00\x18\xeb\xc4\x99\xb2\x77\x6f\x96\x2e\x0d\xbf\xff\x0e\xc3\x7d\xc2\xde\x4a\x55\xdb\xae\x1e\xef\xcb\x21\xda\x48\x45\x9b\x1d\xd7\xf0\x5a\x8a\xf0\x29\x44\x85\x9b\x99\x91\x03\xec\xc9\x2f\xf9\xd2\x99\x1f\xcd\x57\x63\xe9\xdc\x18\x06\xec\x4e\x15\x9d\x70\xf4\xf0\x78\x64\x02\xea\x00\x06\xe8\xb0\xc5\xbd\x2d\xe0\x5d\x04\xbb\x16\x00\xea\x05\x37\x01\x67\xbc\x8c\xf3\xe5\x5c\xfc\xb6\x83\xcd\x39\xd5\xfe\x79\xda\xc7\xd3\xfb\x14\x81\x37\xe7\xa8\xf6\xc1\xd9\x25\x64\x17\x7c\x05\x06\xb7\xc8\x7e\x77\x73\x83\xa1\x5c\xb4\xaf\x87\x7e\x08\xec\x63\x81\x86\xe8\xfa\x98\x7e\xc0\x70\x10\x77\x08\x5d\x0c\x24\x5c\x8e\xb4\x8b\xe3\x95\x81\x1d\x4a\xf1\xbe\x13\x69\xea\xae\xcc\x72\x8f\xdf\x20\x0d\x1d\xcf\xb0\x6c\x97\x52\xfe\xbb\x68\x71\x4c\xca\x7c\xe5\x64\x12\xae\x8d\xb8\x53\xec\xed\x00\xe1\x7e\x01\x16\x36\xa3\x3d\x05\xfd\x27\x97\x56\x37\x8a\xe7\xdb\xd4\xe3\xd4\xb3\x97\x8d\xb3\x16\xc0\x2a\xf8\xa7\x5c\xa1\xa6\xaf\xd3\x55\x4e\x3a\x82\xc8\xdf\x9a\x2a\x6c\x0f\xc6\x56\x73\x10\xbf\xc9\x60\xba\x80\x39\x6a\x33\x9a\x9d\xa9\x90\xd6\xf9\x66\x34\xaf\xb2\x6d\xd6\xd2\xda\xfe\x01\xb3\x9d\xa0\x8a\xf0\xe4\xc7\xdb\x6c\x29\xe5\x3c\xfc\xe4\x46\x8e\x7a\x30\x77\x08\x5d\x85\x2b\xa3\x00\xef\xe2\xe6\x81\x1d\xbb\x00\xc0\xeb\xc8\x0e\x1d\x9c\x42\x77\xf3\x6c\xd1\x9e\x32\x25\xac\xc4\x4d\x49\x84\xbf\xa1\x2e\xc3\x37\x90\x44\x57\x2c\x09\x9b\xf5\x35\xb1\x13\x3c\x0a\x38\xbc\x5c\xc2\xb7\x97\x25\xaa\xe6\x7f\xdf\x00\xf3\x15\x1a\x54\xe1\x90\x04\xba\x7f\x7b\xa9\xb1\x2c\x24\x74\x43\x26\x57\xd9\x9f\x99\x4c\x43\x5c\xbf\x9c\x34\x2e\x69\x1a\xc6\xe3\x2b\x78\x04\x78\x20\x58\xd6\x36\xc8\xa9\x7a\x29\x67\x4f\xb2\xe5\x0e\x97\x42\xc1\x48\x01\x2a\xf9\x12\x0d\x07\xc9\xd3\xfd\x9f\xe7\xa9\xa4\x73\xb1\x8b\x63\xdc\x8d\x0b\xf2\xc9\x4c\xb0\x23\xe9\x49\x72\x39\xfd\x33\x41\xc7\xaf\x39\x4e\x60\x0f\xea\x60\xa9\xd0\x9d\xe7\x1b\xe6\xfb\x5f\x60\x7c\xac\x0c\xd4\xa3\x5b\xb1\x5c\xf6\x53\xf3\x82\xd6\x54\x4f\xcb\xa1\x19\x64\x4f\x2e\xc4\x94\x25\x8a\x0a\x05\xc3\x62\x6b\xb1\x12\x27\xe3\x64\x0b\xc7\xb8\x55\xe4\xb6\x11\xe4\xf3\x31\x74\xba\xa3\xc1\x47\xb4\x56\xe2\x9b\x5a\xd5\x68\x29\xe8\x5c\x9c\x24\xf6\xa3\x24\xd0\xd6\x0e\xc0\xd0\xe6\x19\xe3\xb9\xd6\x88\x4d\xa5\xfd\xd0\xe4\x7e\xcb\x2e\xe3\x67\xde\xa0\xfc\x39\x75\x8f\x38\x02\xe0\xd7\x90\x04\x73\x61\x52\x70\xe8\xc0\x53\x6f\x4e\x40\x13\xad\x70\x64\x89\x30\x5d\xb9\x4b\xa6\x52\x71\x07\xe0\x81\xc7\xff\x39\xdd\xb1\x75\x45\x68\x9f\x5a\xb2\x25\xee\x61\xc2\x8e\xc2\xc0\x35\x74\x8f\xb6\x99\x8d\x1b\xc6\x9e\x2e\x2f\xe2\xbe\xf4\xda\xb7\xdb\x18\x57\x3d\x12\x7f\xdb\x97\x3d\x96\xaa\x18\x91\x78\x63\xac\x49\x62\xa1\x8f\x13\x7d\xfc\x3d\x88\xfc\x81\xff\x23\x61\x15\x23\xfb\x7a\xe1\x92\xdf\x79\x97\x8d\x8e\xb9\x59\x43\x0a\x68\xc6\x11\x95\x7c\x0c\x21\x06\x2f\x9b\x43\x99\xf7\xbf\xb2\x9c\xc2\x27\x9e\x2f\x10\x5d\x9f\x9a\xee\x03\x85\x6c\xcc\xbe\xfe\xa5\xcf\x5a\x6a\x31\xdf\x6c\xc0\xe0\x49\x21\xf2\xb4\x52\xe7\x25\x51\x06\xfe\x2d\xe3\x8f\x3d\x7e\x32\x06\x87\x36\x0e\x63\x3b\x70\xa4\x98\xfb\x9d\x1d\xe3\x07\x56\x3e\x85\x32\x38\xba\xd7\xb7\x62\xae\x1c\x71\xfa\x49\xd7\xf1\x27\x55\xc9\xeb\xcd\x36\xb0\xf8\xa6\x10\xf2\xff\x5c\xe0\x2b\x22\x22\x9e\xec\xc2\x18\xeb\x15\xe4\x98\x41\xf4\x7a\x74\x4f\xbe\xac\x61\xd5\xb0\x9f\x05\xae\x0e\xe9\xb4\x89\x37\x06\x2c\x4c\x91\x8e\xf6\x23\x8c\x3f\x80\x0c\x9b\x63\xff\x47\xcc\x84\x16\x05\xf8\xea\xbd\xe4\x5f\x49\x2f\xfa\x9e\x82\xdd\x02\x37\x9c\x27\x8e\x3a\x6a\xbe\x6c\xd9\x57\x36\x06\x08\x76\x74\x6a\x30\x79\x38\xba\x0a\x11\x0b\x39\x04\xb3\x08\x85\x29\x1b\x51\xa1\x0a\xed\xd6\xc5\x8f\x51\xc2\x35\x0e\xc8\x5a\xdb\xeb\x90\x22\xfc\x60\x38\x53\x96\x2e\xda\xc4\x65\x4b\xfb\xf2\x99\x79\x2c\x31\x96\x5c\x95\x65\xa7\xc0\xdf\x32\xaa\x3b\x65\x18\x93\x22\xdc\x38\x93\xc2\xef\x6b\x0a\xce\x8d\x44\x90\x02\x5f\xe3\xbf\xa5\xb7\x82\xc0\x0f\x2a\x23\x40\x97\xbd\x58\x85\x4c\x4a\x35\xbf\xb4\x65\x1e\x91\x54\xed\x85\xb2\xc4\x40\x44\xb2\x4a\x86\xc7\x4c\x35\xed\xf4\x63\xaf\xfe\x31\xd6\xeb\x6c\x20\x56\x31\x13\xad\x6b\xeb\xab\xbe\xf1\xbb\xea\xae\x4c\xc1\xe4\x26\x3f\x5c\xf2\xd3\x1f\xd8\xc7\x2b\x4b\xa8\xe0\x9e\xc6\x2f\xd2\x99\x3d\xcf\x3b\xb6\x9f\x28\x29\x1e\x9b\x1c\x9c\x74\xbd\x75\xba\x3d\x1f\xe7\xff\x5b\xa0\x0a\x8a\x9d\x71\x45\x5f\x33\x42\x4b\x01\xeb\x3a\x63\xd0\xb5\xa1\x33\x4f\xdf\x4f\xb5\x66\xb1\xe7\x44\x08\xb0\x2d\x91\xb5\x0f\xc8\x0e\xfe\x2d\x0b\x7b\xf1\xad\xb5\x16\x6e\xe5\xb0\x35\xc0\x89\x65\x58\xdf\x86\x9c\xa5\x1d\x02\x8b\xad\x0e\x3a\x03\xf7\x2f\x9a\x32\x69\x91\xb7\xf2\xca\xa2\xd8\x65\xd0\x9a\x03\x21\x33\x8d\x0d\xc4\x1f\x28\x8c\xe3\xc6\x99\x07\xd8\xa1\x61\x4e\x23\x77\xa0\x0f\x8b\xea\xbf\x87\x59\x5d\x62\xed\xf3\x5d\xcb\x58\xc0\x8f\xe6\x4f\x63\x5b\x91\x45\x3a\xfe\xa7\x11\xcd\x69\xb4\x22\x99\x44\xcf\x98\x40\xf5\xce\x4a\xf8\x84\xad\xdd\x50\x67\x12\x58\x8f\x94\x2f\x62\xd1\x39\x76\x65\xa6\x26\x94\x98\x46\x7e\x51\xe4\xa6\x0c\x8e\xd6\x01\x54\x75\x4c\x86\xd3\xd6\x9d\xdb\x6f\x58\xbe\xa2\x4a\x4d\x06\x35\x31\xac\x97\x03\x88\x0e\x63\x01\xf1\x0d\x03\xc0\x25\xa7\xfc\x5b\xae\x16\x27\xac\x54\x15\x22\xf9\x42\x7a\xd9\xd2\xcd\x11\x25\xf5\x7c\x18\xab\xe9\x3e\x66\xda\x49\x2e\x29\x7f\x9f\x31\xc9\x50\x44\x16\x04\x3c\x36\x55\x68\x33\x10\xed\x51\xf7\xa4\x3c\x9a\x7a\xcf\xa0\xd8\xeb\x8d\x60\xcb\xdb\x19\xa7\xc2\xb2\x13\xd5\x5d\xca\x6f\xf8\x6c\x34\x87\x61\x2d\x32\xf0\xc9\x96\xc0\x6c\xba\x2b\x99\x52\x5f\xbc\x26\x5f\x98\xe3\x8e\x43\xa0\xea\x9b\xd9\x3e\xe9\x3d\x81\x60\x32\xf5\xaf\xaa\x1f\x98\x91\x53\x04\xe8\xf9\x4f\x84\x69\x61\xb0\x34\x50\x34\x0a\xa8\xd4\x3c\xf3\x94\xa1\xec\x38\x6c\xcf\xec\xa0\xc8\x83\x1f\x98\x42\x3a\xe5\x92\x04\x4c\xbf\x35\x30\xea\x72\xea\xcc\x3f\xd4\x64\xc4\xec\xaf\x57\xf8\xf0\xcc\x0d\x01\xc3\xbd\xbd\xc5\x38\x7f\xe3\x23\x7a\x33\xfb\xc3\x00\x3a\xe6\x8f\x8c\x25\x6f\x83\x00\x7b\xd3\xd2\xb1\xac\x9f\xbf\xa1\x09\x5f\x94\x95\x5d\x4c\x0f\x1b\x7c\x41\x2a\xf4\xa3\x5b\x5f\xd7\xae\xd8\xc5\xdc\x34\xa4\xf5\x16\x16\x7d\x9b\xb2\xd6\x3a\x24\xf6\xb8\xd8\xc4\x29\x01\x53\x17\x79\x9c\x43\x4d\x23\xd2\xb1\x3d\xbd\xbd\xfd\x42\x94\xde\x77\xc9\xdf\x7c\xff\x0c\x91\xa7\xec\x7b\x91\xc2\x55\x53\xd3\x2f\x50\x82\x4e\xa2\xf1\x5f\xd4\xf3\x52\xb4\x43\x12\x89\x7f\x82\xe8\xeb\xd1\x12\x88\xe5\xa7\xac\x51\xd4\x06\xe0\x25\xcd\xc0\xaa\x9e\x21\xad\xae\x07\x7e\xa4\x0e\x9b\x29\x61\xd3\xbb\x05\x4a\x5c\x72\x20\x4e\x97\xff\x26\xc0\x73\x02\x9e\x31\xe1\xf9\x04\x1f\x59\x20\x87\x23\x99\xfa\xb7\x83\x0c\x73\xd6\x00\x47\xfe\x5d\x0a\x1c\x7f\xd5\x17\xfe\x89\x75\xe7\xe0\xf6\x30\x0e\x48\x0b\xf3\x81\x77\xce\x40\x54\x20\xd5\x5e\xca\xba\x7a\xb0\xc1\x41\xcc\xec\xec\x55\x28\x2c\x1f\x24\xb0\x99\x58\x6b\x59\x76\x7a\x43\x45\xeb\x22\xa3\x42\x29\xdb\x7f\xf8\x14\xa9\x6f\x04\x0f\x8d\xd2\x70\x28\xee\x0b\xf7\x16\xbf\x64\x9f\xbc\x0c\xff\xb0\x9f\xd0\x23\x34\xbf\x90\xd0\xf4\xfc\x87\x3d\x85\x33\x97\x07\x37\xb1\x42\x33\x54\x9d\xc2\xa2\xf7\x0c\x9c\x15\xed\xe6\x94\x0b\xbe\x3b\xab\xf1\x91\xf0\xf5\x58\x9b\x23\x9d\x8f\x7c\x6d\x80\x87\xc8\x1b\x85\x6f\xd6\xca\xe8\xf9\xed\x3c\xd3\xab\xc0\x9a\x43\xb6\xa1\xb1\x95\x62\xce\xde\x73\xf8\x45\xc6\x5b\xe8\xe0\xb9\x56\x01\x82\x70\x3d\x46\x2a\x46\xe5\x88\x49\x29\xe0\xfa\x3f\x36\x4b\x26\xc4\x33\xff\x61\x35\x5e\x0d\xce\x7e\x9d\xfe\x22\x3d\xde\xed\xff\xef\x73\x45\x3b\x20\xa9\xa4\xb6\x2e\xc1\x95\xbd\x4c\x49\x03\x2c\x3d\xa7\x75\x4d\x88\xe1\x22\xc0\x78\xb7\x36\xca\x97\x35\xc3\xf8\x13\x63\x2d\x95\x74\x54\x30\x91\xe4\x14\x87\x53\xd5\x9c\x16\xea\x8d\xec\x0e\x07\xdf\x49\xdb\x4b\xb1\xe8\x6c\xd4\x6a\xd5\xc4\x9b\xe2\x5a\x5d\xd3\x2c\x47\x0b\x55\x8b\xcd\x1e\x26\x21\x09\x1b\x84\xfd\x81\xd9\xc1\x6c\xa5\x5a\x66\xcb\x95\xfd\xc4\x53\x9f\x98\xe0\x22\x71\x0a\xe0\x16\x1d\x18\x76\xf3\xe6\xeb\x3d\x5e\x3c\x39\x14\xe8\xa3\x30\x61\x73\x95\x3d\x30\x6b\x2d\x69\x56\x79\x19\xcd\x69\x58\xab\x6d\x1f\x80\xdf\x66\xf2\x44\x1b\x14\x68\xdf\xc4\xf0\xc2\x16\xc6\xc2\xa0\xa8\xcd\xf3\x5e\x04\x64\x4b\x46\xc6\xcd\xef\xfd\xc9\x47\x60\x3c\xdd\x5f\x59\xe3\x30\xb0\x22\xe7\xd6\x69\xc2\xdb\xa7\x21\x4c\x1b\x71\x3e\xda\x44\x02\x29\x02\x4c\xbf\x0d\x7e\x26\x5f\xc2\x24\xa4\x41\x15\x5a\x57\x08\xcf\x73\xd2\x99\x24\x41\xbd\x7b\x5d\xbc\x72\xa7\x43\x99\xd5\x9a\xb6\xc0\xf3\x43\x02\xd4\x28\x49\xa5\xfd\x55\x97\xfe\xc8\xe5\xe2\x11\x05\x2f\x4c\xa4\xa5\x06\x58\x7b\x60\x0a\x53\x2b\x0a\xa3\x46\x0e\x62\x60\xdd\x63\xb0\x7e\x21\x87\x33\x3a\x47\xc5\xeb\x32\x3e\x02\x9e\x7a\xf6\x0f\x90\x9a\x9f\xae\x14\x4f\x9a\xb5\x3f\x02\x03\x3e\xdd\x12\xfe\x77\x3d\xa6\x87\x9c\x7e\x23\x25\x4e\xbe\x56\x64\x6d\xcd\x4c\x47\x32\xe7\x99\x32\x38\x5a\xe6\x6d\x39\x7e\x31\xe5\xfb\x8e\x24\x97\x22\xbf\xe9\x9b\xcb\xaa\xcc\x05\x22\xde\xba\xc2\x7a\xc8\xe9\xd4\x77\x66\x6b\x88\x5d\xeb\x20\x29\x7f\x1a\x3b\xa6\x0e\x1b\xc1\x17\x80\xdd\x0e\xd7\xb2\xc5\xeb\x4a\xec\x28\x43\x52\x9c\xa7\x85\xa9\xfa\x4b\xe9\xb5\x29\x51\x2f\xad\xd7\xc8\xb7\x98\xa0\x95\xf3\xbc\x02\x4b\xd4\x3d\x49\x76\xec\x66\xbd\xf2\xb0\x50\xba\xc4\x68\x7c\x39\x8c\xcf\x08\x8a\x8d\x67\x23\x9f\x39\x86\x79\x67\xb4\x0f\x20\x63\xd0\x64\x98\x17\x0e\xc0\xfe\xb3\xea\x72\x33\x1b\x62\xd5\xbc\xad\xad\xe6\x2d\xd7\x90\x6b\x30\x5e\xd7\x28\x23\x85\xd1\xf8\x45\xa1\x23\x3c\x8c\x68\x63\x19\x08\x5d\x94\x03\x71\x21\x4d\xb2\xe6\x18\x79\xd8\x9c\xd9\x06\x69\x90\x64\xb8\x9d\x80\xe4\x4e\x6c\xe6\x42\x93\x46\xcd\x08\x2f\x2d\x9a\x95\x4e\x91\xec\x59\x1b\x5f\xaf\x50\x02\x85\xc7\x19\xc8\x32\x14\x28\xcf\xbc\xe2\x69\x4f\x8b\x63\xe4\xab\xdc\xb7\x9b\xae\xb5\xa7\x16\xce\x02\xaf\xe2\x24\x50\x46\x72\x6e\x6f\xb9\xcc\x79\xc5\x2a\x3c\x1d\x87\x56\xdc\x91\x1a\xe7\x76\x97\x58\xb5\x24\x1d\xeb\x19\x83\xae\x2d\x3e\xd6\xea\x9d\xac\x41\x2d\xde\x57\x1c\xff\x4d\x01\x99\x46\x04\x1c\xc0\x56\xae\x05\x9d\x33\x6a\x09\x70\x7e\x84\x2c\x53\xc2\xc7\x5b\xc5\xf6\xcd\x5a\xe2\x49\x83\x1c\x9b\x2c\xdf\x2a\x12\xf1\x5d\x58\xc1\x9d\x05\xc8\xc1\x76\x55\xde\xcd\x98\x0c\xc9\xcd\x36\x48\xfc\x3c\xcb\x67\x0b\x1b\xad\x1b\xb5\x4c\xff\x4d\xcd\x6d\xac\xa0\xfa\x88\x66\x3e\xba\x6c\xf2\x5e\x4c\xe2\xbe\xc6\x83\xde\x68\xac\xcc\x20\xf4\x6a\x90\xd3\xed\xd9\xc1\x4c\x51\x56\x35\x42\x08\xa4\x98\xbd\x8f\x2e\x3e\x40\xd5\x6e\x29\x65\x5e\xb9\xaf\x2e\xf5\xc4\x53\x98\x8d\xd5\x18\x3b\xe8\xce\xe5\x72\xd8\x7b\x66\x59\x19\xb6\x07\x31\xdf\xb6\x74\x54\x8e\xd0\x57\x37\xb8\xa6\x89\x49\xd5\xca\x0f\x0f\xc2\x2f\x35\x7e\xb5\x0c\xdf\xbc\xc9\xd6\xae\x45\x8d\xff\x30\xdb\x78\xc6\xcc\xb3\x82\xd1\x83\x0a\xf8\x86\x48\xf6\x56\xfc\xb8\x94\x4d\x2e\x31\xd6\x05\xaa\x0d\x8f\xa8\xd8\xfb\x8e\xf4\x53\xf5\x37\xa0\xe1\x2d\x9f\x4d\xcb\xcc\x28\x56\xa5\x92\x6e\x0c\x00\x6d\x05\x51\x26\xf4\x25\xc0\x53\xfe\x03\xb6\x1f\xf3\x82\x5b\xd1\x2c\xb2\x2f\xe3\x5e\xc4\x99\xcd\x31\xdd\x71\xba\xdb\x85\x93\x26\x56\xc9\xae\x2b\x3f\x29\x34\x12\xb5\x72\x97\xc4\x2e\xb3\x58\x49\xe3\xff\xca\x2e\xa0\x81\x69\x77\x84\x55\x72\x97\x4c\xca\x7e\x28\x15\x22\xf0\xa2\x52\xab\xa3\x8c\xe5\x6a\x7a\xd2\xb0\x37\xf6\x08\xd6\xbe\x25\xd4\x30\x0b\x60\x6a\x0b\x50\xd6\x73\xa5\x16\x44\x2f\x5f\xf6\x3c\x93\x15\x58\x5c\x16\x03\xf3\x1d\x33\xc1\x09\xcf\x39\x87\xda\x4e\xc9\xdf\x48\xc1\x34\xb7\x34\x70\x25\x9b\x8b\xc4\x11\x0e\xc7\xd5\xae\x71\xa1\x05\x25\x97\xa6\xc8\x2c\xff\x02\x0f\x4d\xa8\x5a\x44\x8b\x8d\x50\xbc\x88\xa4\x6b\x18\x56\x79\x14\xfc\xcb\x1f\x60\xa6\x63\xa5\xa4\xac\x5d\xcc\x15\x85\x87\x39\xc9\x69\x9b\xd2\x6e\x59\xa5\x56\xf6\x4a\xbf\x80\xaa\x5e\x23\x67\x8e\x9c\x6b\x53\xaf\xb6\x89\xb0\xbf\x3d\x44\xf9\xa9\x67\x65\x7d\x51\x00\x6d\x6b\xa4\x03\x7e\x32\x81\x53\xf3\x56\x56\xa8\x30\x93\xa1\xf5\xde\xba\xf5\x44\xf4\x00\x58\x82\x8a\x5c\x10\x72\x1c\x26\x82\x7c\xcf\x64\x6c\xa4\x6d\x91\x01\x3a\x9d\xc2\x1c\x50\xa6\x8b\xe5\x00\x28\x6e\x58\x0c\x5c\x8f\xda\x85\x7b\xa3\x5c\x94\x86\x04\x69\x96\x30\x85\x3e\xfd\x97\xc7\x18\x61\x4c\xbc\x61\x1c\xbf\x7c\x87\x86\xcc\xf3\x7a\x65\x15\xfc\xd7\x9c\x36\xa7\x37\x47\x01\x1e\x93\x22\x14\x0b\xa5\x36\x94\x6e\xd3\x70\x02\x1a\xe5\x9f\x32\x5a\x7d\x44\x44\xa3\xff\x5f\x79\x7e\xa2\x06\x31\x90\x4c\x88\x86\xbf\x1b\x87\x61\x92\x65\xae\x53\x87\xfe\x87\x5a\x27\x93\x1f\x22\xe8\x7e\x3a\xa6\xeb\xfa\x0e\x6b\x47\x9f\x7a\x1a\x37\x85\x16\x00\xaf\xc3\x9d\x9a\x0b\xf1\x10\x23\x0a\xac\xb0\x12\x3a\x21\xde\x36\xb6\x70\x36\x0e\x10\x71\x77\xfb\x0b\x0c\x27\x19\x51\xb7\x81\x72\xbe\xe1\x8f\xe0\xd1\x64\x76\xdb\x4c\xa5\x0c\x0f\x96\x15\x2b\xf5\x7f\xc1\xc9\x6b\x13\x9e\x28\x9f\x6d\xd6\xd4\xd9\x24\xd0\x4b\x43\x68\x6a\x71\x54\x8d\xbc\x66\x6f\x25\x1c\xfa\x8b\x2b\x64\x21\x4f\x54\x6f\x12\x66\xd7\x9e\xd6\x64\xc0\x03\x11\xff\x0c\x80\xf8\x2b\x91\x14\x2f\x96\xf4\xba\xee\x70\xf5\xa3\x1e\x89\x26\xb8\x6f\xeb\x43\xe6\xfe\xcd\x8d\x60\x0f\x94\x51\x1f\x5a\x14\x3f\xa7\xad\xde\x72\x9c\x45\x8e\x9b\x49\x24\x82\x35\xd5\xc7\xac\xef\xba\xca\x21\x4b\x1b\x46\xd0\x68\xf2\x42\xbc\xa9\x79\xd0\x20\x10\x9a\x97\xb6\xff\xa4\x9c\x08\x59\x4e\x0e\x81\xb0\x1e\xaa\xdd\xb3\x5b\x03\x1d\xcf\xd9\x33\xa5\x40\x48\x6e\x33\x16\x7c\x25\x41\x09\x86\x37\xcb\x04\x09\x87\xb7\xa7\x6b\x41\x31\xc9\x7e\xa8\x1f\x40\x9f\xbe\x8f\xf8\x75\x90\xda\xa9\x58\xd3\x67\x6b\x73\x7e\x7e\x92\xc3\xbd\x9b\xc0\x4e\xd0\x3a\x7c\x43\xe0\x8c\x19\xcb\x6e\xd3\x59\xe6\xf2\x1a\xf4\xcc\x1c\xf5\x66\xe3\x8b\xa3\x78\x47\x52\x85\x5e\xde\xb2\x12\xa5\x44\x4f\x66\x58\x1a\xde\x6d\x30\xe0\x6c\xac\xf8\xa8\x3f\xf1\x86\x43\xea\xf4\x64\xb9\x1d\x50\x4d\x3f\xbe\x66\x84\xd2\xe5\x0d\xe9\x0e\xb9\x1a\x0e\xda\x9f\x18\x7c\x75\x83\xac\x6e\xc3\x4e\xcd\x3c\x3d\x0a\xa5\x03\xc1\x07\xc8\x86\xef\x31\xf1\x7a\x10\xe8\xdb\x2d\x75\xca\xa0\x29\x38\x72\x59\xab\xce\x41\xdf\x2a\xfa\x43\xf0\x59\xad\x99\xd0\x4b\xca\x50\x7b\xc7\x81\x32\xfe\x7e\x48\x98\xe3\x58\x24\xa8\x99\x40\x25\x67\xb5\xad\x82\x38\xc9\x33\x7c\xa5\x94\xb7\x55\x25\x3d\x5e\xca\x68\x5f\x12\xfb\xc9\xb5\x30\xef\xe4\x6f\xed", 3855);
*(uint64_t*)0x200002a8 = 0xf0f;
	syscall(__NR_pwritev2, r[0], 0x20000280ul, 3ul, 1, 0, 2ul);
	return 0;
}
