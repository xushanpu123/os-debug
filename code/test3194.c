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

memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010e20;
memcpy((void*)0x20010e20, "\x00\x00\x02\xea\x01\x00\x00\x00\x01\x00\x00\x00\x27\x0f\x24\x0c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x06\x01\xf8\x03\x00\x00\x00\x00\x06\x00\x00\x00\x77\x9b\x53\x97\x78\x61\x74\x74\x72\x31\x00\x00\x06\x01\xf0\x03\x00\x00\x00\x00\x06\x00\x00\x00\x74\x98\x53\x97\x78\x61\x74\x74\x72\x32\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 96);
*(uint64_t*)0x20000208 = 0x60;
*(uint64_t*)0x20000210 = 1;
*(uint64_t*)0x20000218 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x01\x00\x00\x0c\x00\x00\x00\xce\x00\x00\x00\x0f\x00\x00\x02\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x20\x00\x00\x20\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x80\x00\x00\x00\x08\x00\x52\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x73\x79\x7a\x6b\x61\x6c\x6c\x65\x72\x00\x00\x00\x00\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x32\x34\x31\x39\x32\x30\x34\x35\x32\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 192);
*(uint64_t*)0x20000220 = 0xc0;
*(uint64_t*)0x20000228 = 0x400;
*(uint64_t*)0x20000230 = 0x200100c0;
memcpy((void*)0x200100c0, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x3b\x34\x66\xcc\x1e\xa2\x44\x15\x8e\x33\x25\x80\xde\x23\x58\x9c\x01\x00\x00\x00\x0c\x00\x00\x00\x00\x00\x00\x00\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x20000238 = 0x40;
*(uint64_t*)0x20000240 = 0x4e0;
*(uint64_t*)0x20000248 = 0x20010100;
memcpy((void*)0x20010100, "\x01\x00\x00\x00\x00\x00\x05\x00\x11\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x3c\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000250 = 0x20;
*(uint64_t*)0x20000258 = 0x560;
*(uint64_t*)0x20000260 = 0x20000600;
memcpy((void*)0x20000600, "\x03\x00\x00\x00\x04\x00\x00\x00\x09\x00\x00\x00\x00\x00\x00\x00\xe9\xff\xff\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00\x00\x00\x00\x06\x21\x7f\xa1\x71\x33\xdd\x0f\x09\x7d\xfe\xe0\x52\x8f\xe4\xb1\x7c\x19\x46\x13\xd6\x9f\x94\x7b\xff\x22\xc6\xfe\x86\xf8\xc0\x31\x46\x53\x78\xe3\xf5\xeb\x8e\x3c\x97\x49\xf2\x32\xd6\x0e\x4a\x2e\x56\x62\x50\x91\x0b\xef\x2f\x31\x38\x3f\x75\x08\xfe\xd9\x0d\x26\xc3\xc8\xa8\x9e\x7a\x8c\xd6\x14\x11\x2a\xad\xba\x5a\x86\x71\x98\xde\x24\x43\x87\x3c\xe4\x1a\x00\xf3\x67\xa2\x36\x8b\x69\x89\xfb\x9c\x3f\x78\x1b\x96\xac\xfb\x1d\x5f\x9b\x4e\x64\xec\xd3\x4b\x3c\x83\xf7\x11\x60\xc4\x89\x8f\x3c\x1e\xcf\xbc\x5d\x1c\x5d\x4e\x5b\x8f\x8b\xef\xf0\x03\x2d\x09\x0a\x71\x60\x57\x4e\xff\x72\xee\x53\x0a\xbc\x75\x4a\xe5\xe2\x28\xfc\xb9\xb7\x9f\x9a\x5e\xb1\x5e\x36\x58\x70\x44\xd5\x42\xb9\x0a\x19\x3e\x04\xe4\x50\xa9\xf7\x81\x90\x72\x4d\x78\xfd\x69\xaf\x4a\xc5\x99\x1d\x71\x23\x32\x23\x46\x4d\x0d\xc9\x2f\x0b\xd4\x9c\x35\x9f\x72\x5d\x95\xb8\x63\xa2\x1d\x3d\x77\x37", 242);
*(uint64_t*)0x20000268 = 0xf2;
*(uint64_t*)0x20000270 = 0x640;
*(uint64_t*)0x20000278 = 0x20010140;
memcpy((void*)0x20010140, "\x03\x00\x00\x00\x13\x00\x00\x00\x23\x00\x00\x00\xce\x00\x0f\x00\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000280 = 0x20;
*(uint64_t*)0x20000288 = 0x800;
*(uint64_t*)0x20000290 = 0x20010160;
memcpy((void*)0x20010160, "\xff\xff\xff\xff\xfc\xff\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff", 389);
*(uint64_t*)0x20000298 = 0x185;
*(uint64_t*)0x200002a0 = 0xc00;
*(uint64_t*)0x200002a8 = 0x20010660;
memcpy((void*)0x20010660, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002b0 = 0x20;
*(uint64_t*)0x200002b8 = 0xd85;
*(uint64_t*)0x200002c0 = 0x200105e0;
memcpy((void*)0x200105e0, "\x0b\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\xf4\x03\x02\x02\x2e\x2e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002c8 = 0x20;
*(uint64_t*)0x200002d0 = 0x1400;
*(uint64_t*)0x200002d8 = 0x20010600;
memcpy((void*)0x20010600, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002e0 = 0x20;
*(uint64_t*)0x200002e8 = 0x1800;
*(uint64_t*)0x200002f0 = 0x20010640;
memcpy((void*)0x20010640, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200002f8 = 0x20;
*(uint64_t*)0x20000300 = 0x2000;
*(uint64_t*)0x20000308 = 0x20010680;
memcpy((void*)0x20010680, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000310 = 0x20;
*(uint64_t*)0x20000318 = 0x2800;
*(uint64_t*)0x20000320 = 0x20000040;
memcpy((void*)0x20000040, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000328 = 0x20;
*(uint64_t*)0x20000330 = 0x2c00;
*(uint64_t*)0x20000338 = 0x200106c0;
memcpy((void*)0x200106c0, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000340 = 0x20;
*(uint64_t*)0x20000348 = 0x3000;
*(uint64_t*)0x20000350 = 0x200106e0;
memcpy((void*)0x200106e0, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000358 = 0x20;
*(uint64_t*)0x20000360 = 0x3400;
*(uint64_t*)0x20000368 = 0x20010700;
memcpy((void*)0x20010700, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000370 = 0x20;
*(uint64_t*)0x20000378 = 0x3800;
*(uint64_t*)0x20000380 = 0x20010720;
memcpy((void*)0x20010720, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000388 = 0x20;
*(uint64_t*)0x20000390 = 0x3c00;
*(uint64_t*)0x20000398 = 0x20010740;
memcpy((void*)0x20010740, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200003a0 = 0x20;
*(uint64_t*)0x200003a8 = 0x4000;
*(uint64_t*)0x200003b0 = 0x20000840;
memcpy((void*)0x20000840, "\x50\x4d\x4d\x00\x50\x4d\x4d\xff\x70\x1f\x1f\x63\x00\x00\x00\x00\x68\x72\x75\x74\x76\x69\x6b\x2e\x63\x2e\x67\x6f\x6f\x67\xbc\x44\x0f\x38\x2e\x63\x6f\x6d\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x6c\x6f\x6f\x70\x32\x00\x6e\x75\x78\x2f\x74\x65\x73\x74\x2f\x73\x79\x7a\x5f\x6d\x6f\x75\x6e\x74\x5f\x69\x6d\x61\x67\x65\x5f\x65\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x79\x67\x4d\x2f\xab\x9a\xc4\xac\xa0\xd3\xc6\xe0\x62\x2f\x29\xa7\x9d\xb3\x94\x27\xb2\xde\x24\x2e\x6b\xdc\x27\xf2\x3f\x54\x34\xc9\xe5\x75\x03\x63\x84\x3c\x6b\xea\x05\xea\x3e\x0e\x39\x10\xe3\x3c\x68\x14\x19\xe3\xb2\x22\xed\x5f\x60\xb4\x5b\xf5\xc2\x38\xca\xab\x4f\x9a\xe9\xb9\x95", 197);
*(uint64_t*)0x200003b8 = 0xc5;
*(uint64_t*)0x200003c0 = 0x4400;
*(uint64_t*)0x200003c8 = 0x20000700;
memcpy((void*)0x20000700, "\x11\x1f\xc0\xd9\x01\x00\x00\x00\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x02\x00\x05\x00\x00\x00\x63\x5b\x21\x3b\xad\xaf\xad\x1a\x0c\xe7\xc2\x50\x26\x82\xb6\xbc\x52\x9b\xe9\x33\xe0\xab\x9b\x93\x7a\x07\xef\x16\xf5\x29\x21\x10\x7c\xec\x57\x02\x30\x7d\x6c\xd1\x36\x63\x1f\x39\x54\x53\xe8\xa8\xc5\x78\x69\x9a\x40\x62\x9d\xe3\x7f\x91\x0e\x85\x15\x84\xc2\xe0\xc0\xa2\x19\x14\x1d\xef\x36\xf1\x09\x52\x15\x99\xe8\x70\x65\x50\x9c\x6f\x0f\xff\x73\xf7\x78\xf1\x92\xa7\x1b\x92\x3d\x5f\x66\x5a\x02\x17\xa9\x1d\xa3\x09\x25\x11\xda\x06\xc5\x71\x18\x07\x25\x2b\x60\xc3\x6e\x4a\x2a\xdc\x56\x4c\xb0\x4f\x87\xb8\x30\x30\xd6\x17\xd2\xed\x73\xfe\xbf\x6e\x93\xda\x18\xf0\xe2\xda\x06\xa6\xea\xc9\xfb\xff\x42\x09\x75\xe8\x2a\x23\x23\xa8\xb8\x7f\xed\x8c\x6c\x15\xe1\x19\x88\x36\x86\x51\xb4\x82\x78\xee\x23\x00\xca\x9b\x62\x99\xc5\xe7\xfe\x09\x84\x8e\x5e\x76\x08\xa8\x5e\x9f\xba\xaf\x6e\xa6\x1f\xe9\x84\xac\x82\x65\x69\xff\x9c\x05\xb6\x1e\x3d\x56\x9c\x89\xa0\xee\x12\xd5\x3c\x83\x01\x53\xec\x88\x1c\xf4\xe2\x82\x07\xa0\x2d\x66\x85\xe4\xde\xe5\x2c\xaa\x53\xa2\x36\x8f\x38\x40\x9e\xa7\xb3\x5c\x48\x39\x7b\x49\xc1\x76\x9a\xcb\xd3\xe6\xe8\x47", 285);
*(uint64_t*)0x200003d0 = 0x11d;
*(uint64_t*)0x200003d8 = 0x4800;
*(uint64_t*)0x200003e0 = 0x20010800;
memcpy((void*)0x20010800, "\xff\xff\x01\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 1056);
*(uint64_t*)0x200003e8 = 0x420;
*(uint64_t*)0x200003f0 = 0x4c00;
*(uint64_t*)0x200003f8 = 0x20010c20;
memcpy((void*)0x20010c20, "\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000400 = 0x20;
*(uint64_t*)0x20000408 = 0x5400;
*(uint64_t*)0x20000410 = 0x20010c40;
memcpy((void*)0x20010c40, "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000418 = 0x20;
*(uint64_t*)0x20000420 = 0x5800;
*(uint64_t*)0x20000428 = 0x20010c60;
memcpy((void*)0x20010c60, "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xf4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 96);
*(uint64_t*)0x20000430 = 0x60;
*(uint64_t*)0x20000438 = 0x5c00;
*(uint64_t*)0x20000440 = 0x20010cc0;
memcpy((void*)0x20010cc0, "\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000448 = 0x20;
*(uint64_t*)0x20000450 = 0x6000;
*(uint64_t*)0x20000458 = 0x20010ce0;
memcpy((void*)0x20010ce0, "\x27\x19\xc0\xd9\x01\x00\x00\x00\x80\x3a\x09\x00\x80\x3a\x09\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00", 32);
*(uint64_t*)0x20000460 = 0x20;
*(uint64_t*)0x20000468 = 0x6400;
*(uint64_t*)0x20000470 = 0x20010d00;
memcpy((void*)0x20010d00, "\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000478 = 0x20;
*(uint64_t*)0x20000480 = 0x6800;
*(uint64_t*)0x20000488 = 0x20010d20;
memcpy((void*)0x20010d20, "\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000490 = 0x20;
*(uint64_t*)0x20000498 = 0x6c00;
*(uint64_t*)0x200004a0 = 0x20010d40;
memcpy((void*)0x20010d40, "\x05\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200004a8 = 0x20;
*(uint64_t*)0x200004b0 = 0x7000;
*(uint64_t*)0x200004b8 = 0x20010d60;
memcpy((void*)0x20010d60, "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 96);
*(uint64_t*)0x200004c0 = 0x60;
*(uint64_t*)0x200004c8 = 0x7400;
*(uint64_t*)0x200004d0 = 0x20010dc0;
memcpy((void*)0x20010dc0, "\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200004d8 = 0x20;
*(uint64_t*)0x200004e0 = 0x7800;
*(uint64_t*)0x200004e8 = 0x20010de0;
memcpy((void*)0x20010de0, "\x0c\x00\x00\x00\x0c\x00\x01\x02\x2e\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x02\x02\x2e\x2e\x00\x00\x0d\x00\x00\x00\x10\x00\x05\x01\x66\x69\x6c\x65\x30\x00\x00\x00\x0e\x00\x00\x00\xd8\x03\x05\x07\x66\x69\x6c\x65\x31\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 64);
*(uint64_t*)0x200004f0 = 0x40;
*(uint64_t*)0x200004f8 = 0x7c00;
*(uint64_t*)0x20000500 = 0x20010e80;
memcpy((void*)0x20010e80, "\000\000\000\000\000\000\000\000\000\000xattr1\000\000", 18);
*(uint64_t*)0x20000508 = 0x12;
*(uint64_t*)0x20000510 = 0x83e0;
*(uint64_t*)0x20000518 = 0x20010ea0;
memcpy((void*)0x20010ea0, "\x00\x00\x00\x00\x00\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x20000520 = 0x20;
*(uint64_t*)0x20000528 = 0x8c00;
*(uint64_t*)0x20000530 = 0x20010ec0;
memcpy((void*)0x20010ec0, "\xed\x41\x00\x00\x00\x04\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x04\x00\x02\x00\x00\x00\x00\x00\x08\x00\x05\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x04\x00\x00\x00", 64);
*(uint64_t*)0x20000538 = 0x40;
*(uint64_t*)0x20000540 = 0x8c80;
*(uint64_t*)0x20000548 = 0x20010f00;
memcpy((void*)0x20010f00, "\x80\x81\x00\x00\x00\x18\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x0c\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x12\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x18\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x14\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x81\x00\x00\x00\x18\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x0c\x00\x00\x00\x10\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x03\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x19\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x1e\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x1a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 224);
*(uint64_t*)0x20000550 = 0xe0;
*(uint64_t*)0x20000558 = 0x8d00;
*(uint64_t*)0x20000560 = 0x20010fe0;
memcpy((void*)0x20010fe0, "\xc0\x41\x00\x00\x00\x30\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x18\x00\x00\x00\x00\x00\x08\x00\x00\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0c\x00\x00\x00\x05\x00\x00\x00", 64);
*(uint64_t*)0x20000568 = 0x40;
*(uint64_t*)0x20000570 = 0x9100;
*(uint64_t*)0x20000578 = 0x20011020;
memcpy((void*)0x20011020, "\xed\x41\x00\x00\x00\x04\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x02\x00\x00\x00\x00\x00\x08\x00\x03\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x1f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x8d\xe4\x93\xfd\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xed\x81\x00\x00\x1a\x04\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x04\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x27\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x05\x04\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xa1\x00\x00\x27\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x2f\x74\x6d\x70\x2f\x73\x79\x7a\x2d\x69\x6d\x61\x67\x65\x67\x65\x6e\x32\x34\x31\x39\x32\x30\x34\x35\x32\x30\x2f\x66\x69\x6c\x65\x30\x2f\x66\x69\x6c\x65\x30\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xc4\x69\x48\x22\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xed\x81\x00\x00\x0a\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x04\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x29\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x49\xea\xda\xcb\x20\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xed\x81\x00\x00\x28\x23\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x02\x00\x12\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x00\x00\x00\x2a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x6b\x2d\xd0\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xed\x81\x00\x00\x64\x00\x00\x00\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x70\x1f\x1f\x63\x00\x00\x00\x00\x00\x00\x01\x00\x02\x00\x00\x00\x00\x00\x08\x00\x01\x00\x00\x00\x0a\xf3\x01\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x33\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xc2\x34\x16\x6d\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 768);
*(uint64_t*)0x20000580 = 0x300;
*(uint64_t*)0x20000588 = 0x9180;
*(uint64_t*)0x20000590 = 0x20011740;
memcpy((void*)0x20011740, "syzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint64_t*)0x20000598 = 0x20;
*(uint64_t*)0x200005a0 = 0xa400;
*(uint64_t*)0x200005a8 = 0x20000080;
memcpy((void*)0x20000080, "syzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallersyzkallers\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 128);
*(uint64_t*)0x200005b0 = 0x80;
*(uint64_t*)0x200005b8 = 0xcc00;
*(uint64_t*)0x200005c0 = 0x20000140;
memcpy((void*)0x20000140, "\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 32);
*(uint64_t*)0x200005c8 = 0x20;
*(uint64_t*)0x200005d0 = 0xffff;
syz_mount_image(0x20000000, 0x20000100, 0x40000, 0x29, 0x20000200, 0, 0x200117e0, 1);
	return 0;
}
