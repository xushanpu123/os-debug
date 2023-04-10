// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
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

static long syz_read_part_table(volatile unsigned long size, volatile unsigned long nsegs, volatile long segments)
{
	struct fs_image_segment* segs = (struct fs_image_segment*)segments;
	int err = 0, res = -1, loopfd = -1, memfd = -1;
	char loopname[64];
	snprintf(loopname, sizeof(loopname), "/dev/loop%llu", procid);
	if (setup_loop_device(size, nsegs, segs, loopname, &memfd, &loopfd) == -1)
		return -1;
	struct loop_info64 info;
	if (ioctl(loopfd, LOOP_GET_STATUS64, &info)) {
		err = errno;
		goto error_clear_loop;
	}
	info.lo_flags |= LO_FLAGS_PARTSCAN;
	if (ioctl(loopfd, LOOP_SET_STATUS64, &info)) {
		err = errno;
		goto error_clear_loop;
	}
	res = 0;
	for (unsigned long i = 1, j = 0; i < 8; i++) {
		snprintf(loopname, sizeof(loopname), "/dev/loop%llup%d", procid, (int)i);
		struct stat statbuf;
		if (stat(loopname, &statbuf) == 0) {
			char linkname[64];
			snprintf(linkname, sizeof(linkname), "./file%d", (int)j++);
			if (symlink(loopname, linkname)) {
			}
		}
	}
error_clear_loop:
	ioctl(loopfd, LOOP_CLR_FD, 0);
	close(loopfd);
	close(memfd);
	errno = err;
	return res;
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20001640 = 0x20000140;
memcpy((void*)0x20000140, "\x9c\xf9\x88\x73\x65\xe6\x24\xb0\x69\x12\xc7\xd7\x23\x3b\x20\xbd\x75\xc8\xd3\xd2\x1c\xe4\x9d\xf8\x2f\x67\xd6\x6b\x1d\x0e\x3d\x09\xd8\x67\x23\xe4\x28\x74\x5b\x9f\x74\xf7\xbc\x3f\x50\xe0\xae\xde\x75\x30\xdc\xe0\x54\xc5\x40\x49\x94\xa0\x7f\x79\x93\x73", 62);
*(uint64_t*)0x20001648 = 0x3e;
*(uint64_t*)0x20001650 = 0xfffffffffffffff9;
*(uint64_t*)0x20001658 = 0x200001c0;
memcpy((void*)0x200001c0, "\xa1\x32\x8c\x80\x6d\xfe\x89\xf7\xc8\x43\xef\x2b\x9e\x76\x2a\xe8\xb5\x4b\xc6\x12\x42\x19\xba\x15\x7f\xe3\xf0\xfd\x5d\x82\xe8\xc7\x82\xfd\x7c\xad\xb7\x94\x07\x48\xa7\xbb\xdf\xf1\x47\x00\xf6\x17\x25\x15\x05\x19\x42\x59\xbb\xf2\xbf\x84\xf1\x0e\xbc\xb7\xd3\xb4\x8b\xbd\xe6\x85\x58\x93\x84\x0c\x1e\x76\xf4\xa5\xbd\x79\xde\x9b\x6d\xc8\xe2\xb7\x11\x92\xab\x2e\x7f\x1e\x13\xe3\x99\x47\xd6\x80\x5b\xd8\x98\x28\x14\x8e\x61\xea\x8d\xc6\x22\xd0\xb0\x38\xa6\xe8\x19\xbe\x99\x22\x05\x08\x60\x92\x20\xa9\x49\xc9\x29\xa3\x9f\xbd\x10\x91\xcb\x6b\xd2\x74\x35\x47\xdf\xee\xd1\x6c\xed\x9a\x01\x0e\x71\xa1\x1e\x1c\xbf\x97\xe3\x1a\x86\x01\x3b\xc3\xff\x7d\xab\xcf\x97\xd3\xb2\x2f\x9b\xb5\x2c\x7c\x51\x6d\x29\x90\x08\x30\x4c\x52\x2f\xac\xda\xc3\x1e\xf3\xd2\xfd\xd3\xc2\x67\x09\x93\x93\x49\xa2\x1c\x80\x97\xcb\x21\xb7\x0c\x40\x85\xee\x20\x17\x77\x7b\x79\xdc\x79\xa1\xa9\xbc\xe1\x53\xc4\x84\x14\x15\xfc\x9b\xd4\x03\xa1\xb9\xee", 225);
*(uint64_t*)0x20001660 = 0xe1;
*(uint64_t*)0x20001668 = 0x20;
*(uint64_t*)0x20001670 = 0x20000380;
memcpy((void*)0x20000380, "\xc7\x4f\xec\x3f\x11\x25\xe8\x45\x86\x93\x39\x23\x93\xab\x8b\xaa\x42\x8d\x74\x57\x45\x60\x5d\x6f\x92\xbf\x32\xe1\xd4\x21\xe8\xc6\xa7\x54\xc8\x1b\xe9\x4b\xc3\x80\x41\xfc\x53\xb4\xc5\x9c\x8c\x58\xd6\x92\xfe\x2e\x1e\xcf\xa7\x04\x45\xd7\xb9\x3d\x12\x8a\x61\xf3\x41\x6b\xbc\x10\x00\xee\xdf\xc3\x9d\x52\x13\xce\xa8\x2a\xe7\xbf\x35\xd2\x71\x64\xa7\xd6\xbd\x9d\x8c\x61\xb6\x58\xe8\x53\xc7\x80\x5c\xb0\xd8\x7b\x56\x85\xbe\xe1\x81\x68\x30\xf2\x1e\x1d\x9b\x45\x5c\x13\x33\xf3\xc2\x26\xfc\x08\x3b\xeb\x34\x57\x9f\x66\xde\x61\xe1\x95\x2d\xbd\xd1\xcc\xad\xea\xe0\x13\xa6\xbf\x08\xac\x68\x6c\xe1\x17\xa7\x5e\x63\x0c\x8b\x2a\xd9\x10\x79\x40\xed\xf9\x10\xcd\xca\xa7\xa9\xc5\x2b\x13\x10\xcc\xc3\x9e\xd2\xe7\x04\x6f\xd1\x92\xb4\x36\xee\xcc\x39\x5d\xae\x70\xed\xe9\xdf\x26\x62\x37\xe3\xc7\x76\xef\x49\x22\x1b\xfa\xac\xb2\x3c\x98\x92\x00\xc3\xfe\xc6\x33\x0f\x93\xc8\x96\x11\x32\xe9\xb9\xf9\x87\xe1\x97\x19\x76\xfe\x06\x3a\xa7\x15\xb0\x7b\xe8\x7c\xff\x37\xd6\x58\x38\xb6\x2f\x6e\xaf\xb8\xb2\xda\xa0\x33\xdb\x3c\x69\xb9\x91\x2a\x00\xd7\x5c\xd3\x64\x1b\x33\x94\x4c\x9a\x85\xec\xe5\x18\xb0\x6e\x7d\x08\x61\x50\x66\xee\x6d\x0c\x66\x1d\xad\x93\xb0\x28\x3d\xa5\xcc\xce\xc2\x2a\xa9\xbd\x26\x27\xbb\x2e\xc6\xbb\x35\x07\xbb\xd4\xc0\x42\xbe\xaf\xae\xe9\x78\x05\x01\xc1\xd1\x64\x82\x19\x64\x02\x5c\x15\x58\xbc\x35\xa1\xa0\xbb\xa2\xcd\xdb\xdf\x38\xd0\xb1\xa9\x2d\x73\x5a\x6a\x4f\xc4\xae\x58\x57\x12\x0f\x60\x81\xe1\xba\x11\xaa\xb2\xc2\xb0\xe9\xfa\xf9\xd2\xef\x0f\x77\x6e\x90\x4f\xbb\xfc\x6b\x84\x65\xa5\x35\xaa\xed\xb8\x08\xc8\xa9\xb5\x6a\xbc\x45\x87\x23\xc4\x1b\xf0\x5e\xad\x66\xa7\xc6\x3c\x64\x42\x7c\xa0\x06\x0d\xec\x64\xe0\xeb\xcd\x81\xf8\x0c\xa9\x37\xad\x45\x4f\x94\x9c\xf5\xf9\x83\x8c\xc1\x7e\x68\x7d\xeb\xab\xff\x1d\xfa\xf3\xb1\xca\x22\x61\xea\x5f\x18\xb7\xcd\xde\xda\x49\x5b\x98\x3a\xd9\x88\xbe\x00\xaf\x32\x69\x1d\x07\x50\x77\x1c\x33\x73\x7c\x58\x51\x10\xa4\x09\xcb\x71\x50\xd4\x3d\xe9\xc2\x1f\x32\x1e\x92\x9c\x29\x50\x09\xbc\x4b\xf9\x6d\xba\x19\xaf\x3e\xc3\xf6\x90\xe7\xbd\x3e\x0c\x06\x8d\x7c\x10\x7c\x5f\xd4\x33\x5f\xda\x1c\x1d\xb9\x83\x1d\x94\xee\xb3\x56\x6d\x91\xa3\x2d\x5b\x1d\x98\xb9\x75\xb7\xc6\xb9\x4f\xa3\x30\x6c\xc5\x57\x49\xb0\x0c\x33\xf4\xad\x58\x1a\x35\x04\x0a\x1a\xea\x75\x7b\xf8\x81\xb8\x90\x0e\x53\x56\x99\x8c\xdf\x08\x4e\xa7\x9d\x06\x4b\xf1\x0b\xd4\x62\xec\xb8\x48\xb4\x2f\x81\xe4\xd6\xab\x69\xbb\x88\x36\x97\x70\x41\x89\xb5\xc9\x18\x15\x85\xdd\x6b\xc0\x80\x6c\x70\xf5\x82\xe1\x0d\x37\x67\x8c\x03\xf5\x0e\x0a\x4e\xb9\x35\xfe\x5f\x62\x54\x31\x9f\xb1\xed\x6a\x7d\xfa\x54\xe6\x15\x1b\xde\xa5\x55\x3e\x6d\xf3\x76\x6e\x50\x18\x4f\x6d\xe6\x01\x50\x82\x9d\xd0\x8d\x6d\x2c\x4d\x89\x73\x08\xa1\x53\x8c\x29\xf6\x67\x0f\xfa\x4c\xc0\x50\x73\xc7\xf0\xab\x94\xc6\x96\xe4\x69\x88\x54\x59\x44\x1f\x77\xc5\xd3\x2d\x38\x3e\x09\x0d\x97\x17\x70\xe3\xa1\xa7\x6b\x9e\x24\x6b\x4c\xf7\x51\xda\xe2\x93\x81\xbd\xba\x87\x54\x67\x22\x0b\xb5\xb1\xdf\x75\x67\xa5\x5a\x31\xce\x19\x7a\xbc\x42\xb9\xb0\x1e\xcc\xce\xaf\x7a\x1b\x83\x6b\xde\x5a\x6f\x85\x93\x3d\x45\xfc\xa9\x31\x50\xb2\xb5\xd2\x16\x80\xf1\xfe\xcb\x7c\x7d\x3d\xf6\xc9\xc4\xf7\x62\xda\x9c\x30\x56\x9c\x27\x02\x1c\x11\x96\x4e\x85\x47\x7b\x75\x21\x49\x29\x7b\xdc\x25\x05\x2f\x2e\x85\x47\xbc\x66\xd5\xb8\xc5\x3f\x23\x58\x64\x4a\xe9\xd1\x17\x23\x27\xb3\xa3\x2e\xca\x92\xa3\xa8\x1f\xc0\x9f\x55\x56\x10\xa7\x04\xcc\x71\x9d\x9d\x1b\xae\x73\x41\x2c\x91\x4b\x59\xa4\x65\x89\x82\x45\xd8\x90\x2f\x3f\xb7\x7c\x4a\xf8\x46\x7b\x78\x9c\x33\x31\x30\x2f\xb8\xbb\x2e\xe4\x20\xeb\xf6\xe5\x4f\x22\x1b\x2a\xe8\xa5\x55\x7e\x3e\x6e\x96\xc0\x57\xc9\x43\x59\x9e\x15\xa2\x84\x02\x11\xef\xda\x26\xbb\xbd\x37\x3e\x60\xaf\xc9\x42\x9e\xab\x18\x0a\x17\x10\xab\x7d\x23\xba\xe8\xad\x67\x80\xe7\x2b\x19\x9e\x2a\x7e\xde\x0b\xa3\xee\xbc\x25\x43\xdf\x8f\x3c\x1b\x15\xc5\x8f\x74\xca\x73\xb8\x0f\x43\x5a\x6a\x6c\x0f\xa5\x7c\x86\x15\x68\xab\x4d\x62\xa2\x75\x1c\x39\x39\xfd\x87\xb7\x79\xe1\x15\x98\xdb\x91\x95\x1c\x1c\xf7\x98\x52\x9d\xb3\x52\x1d\x60\xd5\x54\x46\xf0\x24\xc9\xf2\x0b\xf0\x4e\x0a\x42\x51\xd3\xa7\x70\x5a\xe6\x8a\x62\x20\xad\x23\xda\x83\x84\x36\x01\xc9\xdc\x75\x39\xbd\x2c\x5c\xe0\xc3\x4a\xa7\x43\x9c\xec\x25\x99\x4a\x31\x60\x8a\x1d\x1e\x34\xae\xde\xbf\xb7\x9f\x44\x1b\x11\x1a\x32\xf0\x4c\x51\xb9\xe0\x42\x19\x1c\x01\x9c\x44\xfd\x10\xc3\x61\x71\xe6\x31\xda\x8e\xd8\x16\x08\x56\x26\x80\x9e\x6a\x07\x0e\x06\xbd\x16\x07\x22\xe3\x46\x74\xd0\x81\x7e\x5d\x4e\x6f\x75\x37\x58\xad\xfa\x3b\xe3\x78\xe5\x08\x82\xbf\x88\x74\xa2\x44\x2e\x1c\x7a\x5a\xe8\x15\x1b\x2e\x5a\xdb\xcf\x0e\x50\x35\x4d\x47\xc1\x52\xdf\x1e\xab\x4f\x33\xdb\x1f\x2b\xa5\x56\x94\xb9\xed\xb4\x4e\xc3\xa6\x6f\x84\x52\xb1\x8f\x24\x41\x6d\xba\xd5\x9f\xa0\x6b\x0e\xce\xe2\x9e\x02\x85\xaf\x13\xf4\x66\xd2\x09\x4f\xdc\x1c\x47\xf4\xe5\x41\xa5\x33\xb2\x37\xe2\x67\x5a\x51\xf2\x02\xb1\x97\xf6\x19\xf9\x24\xc1\xc1\x34\x9f\x73\x54\x4a\x17\xd2\xe6\xde\xae\x60\xf0\x79\x99\x25\xe0\xcb\x16\x26\xac\x5d\x9e\x7b\x58\x8c\xdf\xf8\x95\x7a\x03\xda\xd6\xdc\x04\x28\x5e\x94\x4c\xd0\x38\x50\x58\xb0\x80\x6b\xf3\x6f\xfc\xe6\x1a\xce\x13\xb4\x4a\xc9\xfb\x12\x16\x70\xde\xad\x6e\x7b\x59\xa8\x5b\xcd\xc9\xcb\xb5\x41\x3c\x19\x5f\xf2\xf1\x9e\x8d\xdf\x21\x60\x14\x9d\xa7\x70\xfd\x6b\xc1\x01\xaf\x04\x7a\xeb\x46\xfc\x16\x9d\xc6\xad\x85\x1c\x08\x75\x89\xe0\x8b\xad\x25\x40\x7e\xdd\x6a\xa9\x25\x5d\x4b\x57\x73\xb8\xeb\x57\xce\x0f\x27\xbc\xb8\x85\xd0\x15\xb8\x9e\xb0\x32\x1c\xfc\xb0\x83\x59\xff\x84\x65\x2b\x83\x7c\x9b\xe3\xba\x03\x3f\xbc\x62\x87\xf4\x99\x18\x26\x49\xc7\xb6\xdb\xe3\xd6\xd1\x5d\x62\xf7\x3b\x60\xd8\xcd\xd3\x03\xb2\x7d\x54\x56\x2c\x8c\x96\x2d\xb7\x1e\x02\xb0\x87\x40\x1f\xc1\x6b\x13\x43\x1e\xe0\x78\xf5\xca\x8b\x32\x6b\x35\x53\x52\x5f\xdd\x10\xd7\x26\x99\x21\x70\x7d\x05\x9b\x08\xca\x5b\xc3\xe7\x73\xfc\x0b\x2a\x7b\x27\x4a\x91\xd4\xe8\x89\x8c\x57\x8c\xec\xc3\xc7\x1f\xb1\xfd\xac\x31\xa6\x2d\xce\xd3\x93\xbc\x28\x19\xf6\xe0\xe8\xb8\x92\x82\x5c\x53\xa7\xf4\x63\x73\xb3\xb4\xf6\x58\x8c\x34\xdc\xcf\xa9\x29\x63\x78\x3d\x7e\x97\xba\xd0\xc2\xb4\x06\x17\x0f\xde\x18\xab\xa8\x7d\x45\xcc\xc1\xfc\x76\xcf\x79\xc9\x63\xfe\xe2\x5e\x36\x04\x11\xc4\x32\x9f\x20\x5e\xc7\x73\x36\xd0\xd2\x4a\x40\x32\xd6\x3b\x29\x2b\xad\x5d\x96\xe3\x11\xb1\x60\x62\xd4\x12\x23\xc1\xee\x01\x68\x56\x29\xc1\x28\x43\xf9\xe3\x69\xdf\xbf\x1b\x25\x02\xe0\xad\xc4\xd0\xbf\xb0\x9c\x30\xb2\x6d\xff\x72\x35\x34\xb9\xbe\x47\xd4\x56\xb2\x0b\xbb\x19\x4c\xc2\xee\xc8\x56\xd8\x2b\x56\xa8\xe6\x5f\x3e\x05\x95\xe4\x8a\x3b\xf6\x27\xe8\x08\xd4\x08\x4f\x67\x62\xc5\x70\x0a\xa2\x31\xea\x0c\xe4\xa1\x56\xe6\xee\xbb\x74\xa7\x0a\xc7\xb6\xff\x2a\xed\xf6\xca\x45\x65\x5f\x69\x85\x61\x78\x1e\x4f\x28\x13\xa4\x2c\x15\xa1\x02\x2e\x3e\x25\x42\xe2\xa4\x75\xba\xf8\x9d\xfd\xae\xb4\xe0\x4a\xab\xca\xdc\x96\xde\xba\x4f\xcb\x5b\x30\xdb\x9e\x03\x90\x70\x9a\x59\x38\xe4\xa7\x34\x08\x7a\x50\x62\x22\x3e\x81\xbd\x57\x74\xaf\x49\x93\x0d\xf1\x2e\x4b\xfa\x2e\xef\x82\x02\xc8\x40\x83\x49\x2d\xd8\x48\xb8\x0a\x0a\xb4\xda\x5c\x38\xff\x77\x5e\xf7\xe8\x15\x1e\x13\xd7\x55\x53\x44\x9d\xbc\x3b\x0e\x04\x32\xec\x6b\x72\x6f\xd5\x4f\x3f\x43\xc2\x04\x2c\xa5\xd3\xf6\x2f\xae\xc7\xd5\xb2\xab\x19\x9e\xc3\x5f\x26\x57\x6e\xf3\xcc\x5e\xa1\xbf\x1b\x2c\xcf\xf6\x5b\xe6\x3d\xe3\x8a\x4f\x68\x03\x6a\xf0\x2c\x18\xa2\x13\x4a\xe2\xb2\x14\xc4\x99\x7c\x86\xad\xee\x91\x35\x18\x17\xe1\x5c\xdd\xe4\x3f\xfe\x3d\x62\xa4\x62\x14\x6b\x09\x3d\xbb\x12\xc2\x29\x8a\xc8\x35\x7d\x8e\x11\xb5\x50\xbe\x6e\x7b\x15\x7c\x7a\xd2\xa4\x9b\xd6\xd6\x49\x8d\x51\xe8\x58\xff\x14\x2d\x4e\x39\x4b\xaf\x2c\x8e\x10\xe4\x78\xe1\x0f\xbe\x00\xa6\x30\xdb\xd6\x13\xda\xce\x3b\xeb\xaf\xb2\x9e\xef\x40\xf0\xe4\x1b\xeb\x78\x2d\x14\xd0\x41\xc9\xb2\xfe\xff\xb3\xd7\x99\xe2\x92\x00\x4d\xad\x65\x46\x97\xa7\xd7\x5f\x3e\x8a\x9e\x3a\x43\xd0\x21\x6a\x35\x65\xf3\x0a\x95\x24\x29\x41\xf2\xc2\x27\x1e\x36\xb3\xae\x23\x6e\x51\x9a\xfb\x76\x7a\x68\x58\xd9\x3e\x96\x02\x3e\x94\x82\x35\x89\x5f\xf3\x18\xe8\x61\x6f\x18\x48\x0f\x4a\x8b\x54\xe0\x57\xb8\x61\x79\xd4\xc7\x4e\xc2\xfe\x59\x3a\x2f\xb2\x88\x4f\x6f\x78\x23\xe5\x13\x54\x39\x49\xb9\xa4\x24\x59\x1b\x8a\x3a\x40\xf3\x6b\xe3\x82\xae\x5f\xeb\x7c\xcb\xb5\x24\x74\xac\x4c\xca\xf5\x58\x03\xcc\xde\xdb\xfc\x7a\x18\x76\x0b\x4b\xea\x65\x9f\xda\x72\xaf\xf8\x57\x7e\x04\xb1\x06\x06\xd4\x61\xf6\x23\x28\x1e\x39\xcb\x2a\x82\x1a\x56\x67\xc9\x69\xcb\x3a\x42\x77\x61\xcb\x43\x6f\xc9\x3a\x17\x3b\x2b\xcb\x89\xa2\x29\xc5\xd4\xb9\x78\xb0\x86\xa8\x80\xc2\x96\x7d\x8d\xd6\x49\xc8\x9a\x74\x35\x03\xd2\x48\xb3\xb1\xf1\x59\xfc\xef\x48\x48\xd8\xe6\xe4\x75\x3b\x67\x09\x60\xef\x4e\x50\xc5\xbb\x67\xce\x4c\x93\xc1\x24\xf8\x18\x71\x5c\xd2\x4d\x19\x07\x1a\x4c\x56\xe1\x72\x63\x52\x4b\x0f\xe1\xcc\xaf\x6e\xab\xeb\x17\xe0\x90\x4b\xe7\x63\xb1\x11\x3c\x05\x7c\x98\x82\x92\xc4\x4f\x50\xa2\xc5\xf6\x3f\xac\x66\x2f\x7c\x27\x6a\x8a\xdb\x42\xf8\x96\x40\x79\xa2\xad\x25\x50\x8d\x12\x0a\x67\x66\x88\xfc\x6e\x3d\x0c\x3a\xb5\x05\x56\x23\xf4\xad\xc7\x60\x47\x30\xe5\x5b\x3f\x85\x15\xe7\x8c\x8b\xd9\x79\x16\x38\xfa\x39\x7b\x10\x4d\xe3\x15\x34\xbd\xeb\x46\x69\x8a\x85\xf0\xc2\xb9\x88\xf3\x04\xa0\x03\x54\xf3\xec\xe1\x3b\xce\x13\x2c\x09\x83\x9c\x7e\x4d\xed\xeb\x50\x04\x74\x17\xe8\xb9\xf5\xd9\x9b\x03\x62\x7d\x4c\xee\xe5\xb9\xc5\x5c\x49\xc8\x5f\x83\xd6\x0f\x58\x3c\xa6\xfc\xe8\x2b\x7f\x95\x6e\x1f\x76\x28\x60\xd4\x12\x53\x98\x3a\x0b\xd8\x18\x1c\x07\x7c\xe6\x43\x9d\x83\x82\xa6\xb7\x72\xa8\xe1\x26\xf0\x87\xc4\x2c\xd6\xa6\x6c\xbc\x2b\x2a\xfa\x76\x7d\x49\x46\xe9\xcb\x32\x0c\xbe\x8c\xa4\x39\x14\xfc\x7a\xd4\xef\xf2\x98\x64\xca\x01\x00\x21\xad\xea\xd8\x8b\x87\xdb\xfb\xc5\x5f\x52\xb8\x9c\xdb\x7c\xb4\x06\xe6\xa5\xd9\x21\x88\xf7\x73\xf6\x85\xa2\xc2\x3e\x77\x87\xae\xb9\x28\xe6\x80\xa7\x23\x4f\x74\xa7\x34\xaf\x34\x2c\xee\x52\xdc\x51\xc8\x0f\xcc\x43\x10\x30\xa3\x56\x83\x50\xc0\xd2\x9e\x7c\xf5\x5e\x5a\xc3\x7f\xc3\x33\x44\x68\x9e\x8d\x7e\xdc\x1c\x7b\xc9\xf3\x99\xe3\x60\xd8\x80\xd0\x26\xf4\xb2\xb6\x30\x00\x7c\x68\x79\xf1\xa6\xb1\x32\xbf\x58\xd0\x09\x4c\x90\x37\x10\x29\x3a\xcc\x08\xe5\xaf\x02\x3d\x5f\x46\xfc\x8f\xf5\x92\xb4\x19\x83\x72\x2e\xf8\x76\x8d\xd6\x40\xc9\xd3\x20\x94\xd3\xe8\x33\xbc\xb4\x4f\x2a\x12\xc8\x74\x67\xbf\xff\x81\x04\x75\xae\xcf\x62\x54\x03\xb2\x05\x92\xfa\x52\xa5\x02\xa0\xb7\x2c\x8d\xce\x74\x3b\x1c\xc0\x91\x4f\x1b\x43\x56\xac\x2b\x76\xef\x3f\xb7\xe8\x0a\x24\x2b\x3f\x8e\x0d\xf7\xa1\x76\x30\xd8\x7c\xec\x7b\x80\x7c\x0d\xa6\x44\x60\xf3\x37\x1d\x77\x50\x83\x59\xd4\x05\x22\xb5\xbd\xe3\x0a\x9b\xb2\x8b\x52\xf4\x39\x87\x34\x4f\x8b\x30\xce\xf2\x63\xda\x5e\x18\xec\x7d\xa8\x74\xb2\x85\x1e\x66\x05\x58\xf5\x0c\x9b\xa2\x1d\x5b\x90\x9d\x7f\x33\x85\xd6\x30\x18\xa7\x2f\x74\x55\xef\xe5\xb7\x71\xa0\xf8\x4f\x47\xcc", 2552);
*(uint64_t*)0x20001678 = 0x9f8;
*(uint64_t*)0x20001680 = 5;
syz_read_part_table(0, 3, 0x20001640);
	return 0;
}
