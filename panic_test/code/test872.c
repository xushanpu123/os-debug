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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000180, "./file0\000", 8);
syz_mount_image(0, 0x20000180, 0, 0, 0x20000000, 0, 0, 0);
memcpy((void*)0x200018c0, "/dev/vcs\000", 9);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200018c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0x80;
*(uint8_t*)0x20000088 = 0;
*(uint8_t*)0x20000089 = 0;
*(uint8_t*)0x2000008a = 0;
*(uint8_t*)0x2000008b = 0;
*(uint32_t*)0x2000008c = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000a8, 0, 38, 26);
*(uint32_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b4 = 0;
*(uint64_t*)0x200000b8 = 0;
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d8 = 0;
*(uint32_t*)0x200000dc = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint32_t*)0x200000e8 = 0;
*(uint16_t*)0x200000ec = 0;
*(uint16_t*)0x200000ee = 0;
*(uint32_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f4 = 0;
*(uint64_t*)0x200000f8 = 0;
	res = syscall(__NR_perf_event_open, 0x20000080ul, 0, 0ul, -1, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000280, "./file0\000", 8);
memcpy((void*)0x20001880, "9p\000", 3);
memcpy((void*)0x20001900, "trans=fd,", 9);
memcpy((void*)0x20001909, "rfdno", 5);
*(uint8_t*)0x2000190e = 0x3d;
sprintf((char*)0x2000190f, "0x%016llx", (long long)r[0]);
*(uint8_t*)0x20001921 = 0x2c;
memcpy((void*)0x20001922, "wfdno", 5);
*(uint8_t*)0x20001927 = 0x3d;
sprintf((char*)0x20001928, "0x%016llx", (long long)r[1]);
*(uint8_t*)0x2000193a = 0x2c;
*(uint8_t*)0x2000193b = 0;
	syscall(__NR_mount, 0ul, 0x20000280ul, 0x20001880ul, 0ul, 0x20001900ul);
	return 0;
}
