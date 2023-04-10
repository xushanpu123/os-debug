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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20000200 = 2;
*(uint32_t*)0x20000204 = 0x80;
*(uint8_t*)0x20000208 = 0x5f;
*(uint8_t*)0x20000209 = 0;
*(uint8_t*)0x2000020a = 0;
*(uint8_t*)0x2000020b = 0;
*(uint32_t*)0x2000020c = 0;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0;
*(uint64_t*)0x20000220 = 0;
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x20000228, 0, 38, 26);
*(uint32_t*)0x20000230 = 0;
*(uint32_t*)0x20000234 = 0;
*(uint64_t*)0x20000238 = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0;
*(uint32_t*)0x20000258 = 0;
*(uint32_t*)0x2000025c = 0;
*(uint64_t*)0x20000260 = 0;
*(uint32_t*)0x20000268 = 0;
*(uint16_t*)0x2000026c = 0;
*(uint16_t*)0x2000026e = 0;
*(uint32_t*)0x20000270 = 0;
*(uint32_t*)0x20000274 = 0;
*(uint64_t*)0x20000278 = 0;
	syscall(__NR_perf_event_open, 0x20000200ul, 0, 0ul, -1, 0ul);
memcpy((void*)0x20000000, "ext4\000", 5);
memcpy((void*)0x20000100, "./file0\000", 8);
*(uint64_t*)0x20000200 = 0x20010000;
memcpy((void*)0x20010000, "\x20\x00\x00\x00\x00\x02\x00\x00\x19\x00\x00\x00\x50\x01\x00\x00\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x02\x00\x00\x20\x00\x00\x20\x00\x00\x00\xde\xf4\x65\x5f\xde\xf4\x65\x5f\x01\x00\xff\xff\x53\xef\x01\x00\x01\x00\x00\x00\xdd\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x0b\x00\x00\x00\x80\x00\x00\x00\x18\x00\x00\x00\xc2\x05\x00\x00\x2b\x02", 102);
*(uint64_t*)0x20000208 = 0x66;
*(uint64_t*)0x20000210 = 0x400;
*(uint64_t*)0x20000218 = 0x20010100;
memcpy((void*)0x20010100, "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe5\x8c\xa1\x2e\x13\xa2\x40\xe2\xb1\xa2\x2f\x8d\x07\xe8\xe5\x5f\x01\x00\x40", 31);
*(uint64_t*)0x20000220 = 0x1f;
*(uint64_t*)0x20000228 = 0x4e0;
*(uint64_t*)0x20000230 = 0x20010200;
memcpy((void*)0x20010200, "\x01\x00\x00\x00\x00\x00\x05\x00\x40", 9);
*(uint64_t*)0x20000238 = 9;
*(uint64_t*)0x20000240 = 0x560;
*(uint64_t*)0x20000248 = 0x20010300;
memcpy((void*)0x20010300, "\x03\x00\x00\x00\x04\x00\x00\x00\x05\x00\x00\x00\x15\x00\x0f", 15);
*(uint64_t*)0x20000250 = 0xf;
*(uint64_t*)0x20000258 = 0x800;
*(uint64_t*)0x20000260 = 0x20010d00;
memcpy((void*)0x20010d00, "\xed\x41\x00\x00\x00\x04\x00\x00\xdd\xf4\x65\x5f\xde\xf4\x65\x5f\xde\xf4\x65\x5f\x00\x00\x00\x00\x00\x00\x04\x00\x20", 29);
*(uint64_t*)0x20000268 = 0x1d;
*(uint64_t*)0x20000270 = 0x1480;
*(uint64_t*)0x20000278 = 0x20012000;
memcpy((void*)0x20012000, "\x50\x4d\x4d\x00\x50\x4d\x4d\xff", 8);
*(uint64_t*)0x20000280 = 8;
*(uint64_t*)0x20000288 = 0x10000;
*(uint8_t*)0x20012b00 = 0;
syz_mount_image(0x20000000, 0x20000100, 0x80000, 6, 0x20000200, 0, 0x20012b00, 0);
	return 0;
}