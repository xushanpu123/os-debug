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

#define SIZEOF_IO_URING_SQE 64
#define SIZEOF_IO_URING_CQE 16
#define SQ_HEAD_OFFSET 0
#define SQ_TAIL_OFFSET 64
#define SQ_RING_MASK_OFFSET 256
#define SQ_RING_ENTRIES_OFFSET 264
#define SQ_FLAGS_OFFSET 276
#define SQ_DROPPED_OFFSET 272
#define CQ_HEAD_OFFSET 128
#define CQ_TAIL_OFFSET 192
#define CQ_RING_MASK_OFFSET 260
#define CQ_RING_ENTRIES_OFFSET 268
#define CQ_RING_OVERFLOW_OFFSET 284
#define CQ_FLAGS_OFFSET 280
#define CQ_CQES_OFFSET 320

struct io_uring_cqe {
	uint64_t user_data;
	uint32_t res;
	uint32_t flags;
};

static long syz_io_uring_complete(volatile long a0)
{
	char* ring_ptr = (char*)a0;
	uint32_t cq_ring_mask = *(uint32_t*)(ring_ptr + CQ_RING_MASK_OFFSET);
	uint32_t* cq_head_ptr = (uint32_t*)(ring_ptr + CQ_HEAD_OFFSET);
	uint32_t cq_head = *cq_head_ptr & cq_ring_mask;
	uint32_t cq_head_next = *cq_head_ptr + 1;
	char* cqe_src = ring_ptr + CQ_CQES_OFFSET + cq_head * SIZEOF_IO_URING_CQE;
	struct io_uring_cqe cqe;
	memcpy(&cqe, cqe_src, sizeof(cqe));
	__atomic_store_n(cq_head_ptr, cq_head_next, __ATOMIC_RELEASE);
	return (cqe.user_data == 0x12345 || cqe.user_data == 0x23456) ? (long)cqe.res : (long)-1;
}

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
				syscall(__NR_socketpair, 0ul, 5ul, 0, 0x20000000ul);
syz_io_uring_complete(0);
	syscall(__NR_ioctl, -1, 2, 0);
	syscall(__NR_setuid, 0xee01);
*(uint64_t*)0x20001000 = 0x20000000;
memcpy((void*)0x20000000, "\x6c\x6f\xf7\xe1\x16\xcf\x76\xf4\xe3\x33\x95\xd6\xdb\x63\xbf\xd8\x77\x5a\xff\xe9\xe4\xbe\x8b\x4c\xe2\xbe\x1f\xad\x26\x50\x09\xfc\x9f\x38\x29\xff\x26\x56\xe2\x30\xdf\x72\x3c\x26\x7d\xda\x54\x31\xb6\xf4\xe3\x88\x6a\x68\xa6\x8f\x00\x48\xb6\x3d\x1c\x09\x95\xef\x15\xbe\xed\xa3\x68\x0e\x56\x10\xf1\x62\x81\x1c\x33\x3f\x68\x1a\x95\x23\x84\xc7\xe4\xca\x27\x35\x57\x7e\x0e\xfd\x46\x32\x8d\x5b\xc3\x85\x6d\x34\xf7\xf2\x4c\x83\x46\x4b\xdc\x2c\x7b\x25\x9e\x0a\x43\x14\xd5\x0f\x66\x23\xdc\x0a\x1d\x3f\x70\x7f\x67\xde\x82\x31\x8e\x53\x83\x25\xaa\xda\xbf\xea\x46\xa6\x2b\x29\x66\x36\x69\xf6\xe1\xaf\x01\xfe\xbd\x8f\x91\xe2\xc5\x45\xeb\x29\x62\x63\x2e\x02\x8c\x6a\x05\x99\x89\x53\x28\x46\x29\x33\xbb\x5b\x16\x5a\x92\x27\xc6\x74\x6d\x7d\xce\x5f\x33\x2d\xa4\xa0\x39\xae\x4b\xf4\xe0\x9b\x55\x30\xc9\x46\x5c\xda\x34\x7d\x40\x51\xe7\x91\x5e\x62\x4d\x71\xfd\xfd\xd1\x38\x4f\xd2\x3a\xfb\xce\x77\xb3\x21\xcc\x82\xac\x86\xc3\x44\xa0\xe5\x09\x70\xbe\x35\xfc\x22\xb3\x32\xbd\x27\x32\x7a\x04\xf6\xe2\xf4\xb0\x52\x2c\xd9\x31\xaa\x27\xb9\xab\x2a\x73\x82\x4b\xbf\x96\x8c\x1d\x31\x44\x7d\xcc\x86\x60\x5f\x2d\xbc\xc5\x76\xde\xfa\x64\xe5\xf4\x29\xcb\xdf\xb8\x20\x09\xd9\x0f\xb6\x9e\xac\xb4\x0a\xb4\xb5\xf5\x2b\xbd\x95\x42\x37\xaf\xca\x18\xf4\x85\xb8\xc6\xa5\xa9\x53\xe8\x87\x44\x23\xb9\x07\x82\x84\xb3\xcc\xdd\x65\x54\x82\x2a\x6f\x84\x41\x50\x4a\x8e\x36\x4e\x34\x4b\x2e\x64\xb7\x69\x60\xd1\x82\xfa\xd4\xc6\x18\x5c\x62\x26\xa5\x2c\x1c\x04\x63\x64\xcb\x60\x0a\x64\xca\xf3\x8e\xc1\xab\x44\x73\x3c\x3c\x63\xd1\x60\x43\x85\xa7\xd2\x92\x6c\x36\x4e\xbd\x37\xae\x98\x85\x52\x78\x2c\x67\x87\xb9\x46\x18\x43\x4d\x1b\xc0\xa3\x02\x50\xf6\x57\xdc\xb6\x36\xa2\xc9\x08\xf2\xce\x9d\xe0\x84\x54\x40\xba\x32\x79\x57\xa5\x4e\x43\xba\xde\xf6\xd0\xb4\xad\xf6\xde\x8e\x3d\x57\x0a\xba\xd5\xe9\xfa\xfb\xb2\xdf\x21\x8c\xac\x03\x43\x30\x66\x8b\x08\x4f\x32\x5d\xce\xee\x6e\x4f\xa4\xc4\x1c\xfa\x01\x60\xcb\x18\xc7\xad\xa2\xe9\x97\xb0\x59\x93\x33\xc0\x38\xc8\xa5\x78\xf4\x38\x80\x6d\xf8\x2f\x94\x68\x7b\x90\x55\x70\x03\x2b\x79\xe3\x85\x1e\x69\xaa\xc3\x3a\x43\x4e\x65\xd7\x73\x36\x95\xaa\x2d\xb4\xdf\xbe\xc9\xc3\x7a\xfd\x30\x89\xa7\xf9\x79\x7c\xb8\xf6\x72\x99\xbc\x94\xc1\xa1\x6b\x74\x66\x54\x6d\x12\x9a\x67\x2c\x9c\x23\xb7\xd1\xdc\xf2\x1e\xf2\xe4\xa2\xab\x9e\xa6\xed\x93\x4a\x59\xb9\xd3\x83\x95\xfa\x84\xe5\x1a\x7e\xd8\x4f\x58\x65\x9a\xfb\x25\x0f\xfc\xb7\x18\x79\xf3\x1d\xcb\xc8\xbb\x8d\x03\x05\x40\xf4\xa6\x0a\x87\xb9\x14\xb2\x65\x3b\xe5\xe8\xfb\xf1\xaa\x35\xf6\x9e\xd5\x73\x18\x0a\x60\x2f\xd1\x26\x61\x42\xe7\x52\x70\xc8\xaa\x4b\xf2\x38\x02\x08\xeb\xf4\x7b\xbd\x63\xb4\x45\xc8\xef\x17\xd6\x4c\xe1\x58\x6a\xc3\x46\x38\x03\x09\x89\x43\xab\xfe\xb4\xc2\x4c\xa9\x8b\xe4\xb4\x89\xed\xb7\x08\x6c\x10\xf0\xf1\x22\xed\xa7\x44\x96\xd1\xfd\xc0\x0c\xe6\xe6\x6c\x9b\xa3\xda\x0a\xd7\x5e\x02\xc0\x00\x62\xa1\x87\x80\x23\x4c\x0e\x7b\x2a\x15\x28\x85\x05\x2c\x27\x32\xbb\xf4\x25\xc1\xcb\xb3\xcd\x3f\x42\x1e\xf1\xee\xfe\x63\x68\xd8\x89\x2f\xbf\x55\x05\x95\x4c\x63\x08\x6d\x34\x11\x4b\x59\xc2\x03\x8c\x7a\x68\x3f\x4d\x4a\x56\x00\x25\x0f\x42\x8b\x18\x7d\x7a\x67\x63\xf1\x0b\xae\x5d\x2e\x61\x1d\xfa\x2e\x51\xf8\x0c\x73\x1a\xb6\xee\x55\xdb\x46\xb3\x20\xf6\x15\xc8\xd4\xcd\xa2\x8e\x1e\x9d\x69\x51\x06\x43\x0f\x71\xe5\x8f\x37\xe8\x7a\xfe\xe9\xda\x26\x1d\x1d\xf2\xa4\xbd\x8e\x9c\x2f\x16\xd1\x34\xba\xc3\x2f\xa2\x8f\xda\xb8\x14\x2e\x81\x1a\x1f\x4d\xef\x1b\xc3\x1d\xf2\x7e\xd8\xa1\xbb\x0a\xfe\x7b\x86\x55\x2f\x1b\xbd\xc9\x86\xff\x88\x49\x0e\x8d\x62\xbd\xae\x57\xcd\x24\xe9\x92\x7e\xe9\x00\xc0\x78\x0e\xb9\xdd\x37\xeb\x1b\x60\xb6\xb1\x2d\x97\xfe\x25\xd1\x71\x06\x2d\x36\x27\x02\x7c\xfe\x34\xa1\xd4\xd0\xd6\x0e\xcc\x8b\x46\x36\x11\x1e\x50\x80\xca\x54\xcb\x48\xb8\xa7\x98\xa9\x86\x72\x19\xaa\x70\x85\x84\x59\x0d\xfc\xab\x71\x5f\x48\xfe\xff\xa9\xb3\xdd\x2c\x33\x42\xd8\x7c\x53\x2c\x0f\x97\x81\x66\x53\x0b\x8a\x97\x7f\x74\x32\x73\x37\x36\x7a\xe5\x05\x49\xee\x71\x9d\x4f\xcd\x6c\x25\xd4\xde\x9e\x77\x5f\x22\x27\x08\xce\xa3\x84\x86\xb0\xda\xdc\x34\x79\xf2\x78\x94\xed\xd3\x77\x2f\x31\x61\x24\x9c\x14\x11\xc5\xe9\xf0\x84\x5a\x35\xb2\x25\x0f\x37\xc8\x44\xa7\x7d\xc1\xb4\xea\xc1\xb4\x4d\x55\x99\x74\x82\xa7\x8f\xcb\x5f\x96\x29\x00\x8d\xa2\xee\x18\x34\x59\xb6\x5e\xfe\xbb\xa4\xab\x3d\x28\xb5\xd4\xb0\x61\xb5\x0c\x48\xc8\xc1\x20\x11\x94\x7d\x93\x33\x50\x6e\xf5\xe0\x0f\xc4\x86\xad\xc4\x1b\xca\xa0\xad\x82\x6d\xce\x18\xc1\x18\xed\x06\xd6\xe9\x4d\x8d\x9e\x42\x18\x1e\x52\x6f\xd6\x55\x4a\xd1\x00\x68\xe5\x13\x56\x63\x63\xc8\xa2\x5d\x8c\x22\xba\x9b\x8d\x46\x1f\xb0\x2c\x98\x82\xd3\x49\xa5\xe7\x83\xe2\x00\xa4\xbe\xda\xdf\xf7\x0d\xd5\x65\x5f\xbd\x44\x23\x0d\xea\x63\x37\x8b\xed\xad\x0d\x7c\x19\x8a\x67\x71\x87\x36\x96\x2d\x5d\xb5\x1c\x4a\x72\xce\x03\x72\x8b\x26\xde\x18\xc7\x9d\x54\x9e\x9f\xb6\x06\x7d\xc6\xee\xc9\xf3\x6f\x37\xe5\xdc\xfe\xb1\x9a\xda\x84\x28\x4e\xdd\xb2\x2c\x7d\xc3\x04\x4b\x68\x03\xd6\x20\x80\x7e\x1d\xf8\x63\x89\xd9\x3b\x1c\xca\x71\x6f\x6a\x30\x39\x83\xcc\x22\x5e\xb3\xc9\xac\x33\xcc\x8e\xf0\x73\x92\x70\x1e\x68\x69\xd5\x0b\xee\xfd\x10\xa9\x1e\x42\xc4\xb1\x0f\x53\x78\x45\xa7\x48\xc2\x51\x5b\x29\x11\xba\x98\x00\x44\x14\x8f\x21\xfc\x69\x09\x4e\xe1\xce\x2b\xe2\xf3\x77\x9a\x28\xa6\x9e\x54\x70\xe7\xa5\x46\xa6\xde\x3d\x09\xc3\xc1\xb6\xfc\xb0\xea\xd1\xa4\xdc\xe3\xa1\xf5\x99\x2f\x46\x7f\x67\x9c\xb2\x45\x03\xc5\xa3\x67\xad\xc6\x76\x36\x1a\xb6\xc0\xa0\x42\x25\xcf\x8a\x36\x31\xff\xc6\x89\x3a\x12\x75\xef\xf4\xdc\x06\xba\x3e\x5e\xe7\x1e\xae\x38\xfe\x01\xb2\x84\x10\x2c\xf3\x53\xd0\x6c\xd8\x72\x64\x64\x25\x20\x5a\x3a\xe8\x34\xa7\x4f\xa2\xcf\x92\x86\x91\xbd\x20\xac\x4a\xf6\x10\xab\x70\x2c\xd4\xdd\xca\x2b\x93\x69\x3b\x7f\xe9\xfd\xaa\x40\x4d\x02\x24\xa5\xf5\xee\x00\x94\x3d\x5f\x28\xb4\xc5\xb5\xef\xa8\xcb\xda\x77\xf3\x7d\x5a\xad\x75\x13\x2d\x73\xa8\x71\x7c\xe5\xf5\xf7\x18\x74\x41\x97\xa5\x53\x88\xd2\x1b\x43\xb9\x7a\x89\x9f\x38\x2c\x4f\x56\x80\xa8\xa1\x55\x68\xcc\x21\xd0\x25\xcb\xb6\x0a\x8d\x11\x61\xb5\xbd\x7e\xb9\xbc\x99\x55\x0a\x7d\x7e\xf9\x6f\xf5\x03\xc3\x8c\x95\x76\x90\x38\xdd\x2e\xd5\xea\x1c\x4c\x1b\x58\x25\x1d\x8a\xe9\x7d\x24\x0d\x71\x6e\xe8\x83\x15\x64\xf6\x43\x31\xf1\x60\x61\x79\xbf\xa6\x46\x6a\xe5\xd4\x3f\x90\xd2\xe0\x80\x2d\x0f\x4f\xf7\x45\x64\x97\x95\x28\x13\x17\x1d\xa4\xe1\xb8\x52\x41\x86\xb6\x2d\x3a\x92\x82\xed\x62\x5c\xdd\x7a\x9d\x41\x3b\x76\x9a\xd1\x59\x7b\x81\xa4\x2a\x7d\xc3\xfa\x0a\x4d\xa1\x45\x27\x0a\x07\x3a\x81\x51\x18\x0f\x56\xd9\x2b\x14\x15\x4c\xc8\x56\x0d\x50\x94\xd0\x31\xc9\x3c\x8b\x64\xee\x95\x3c\xdd\xc8\x6e\xe6\xa9\x55\x3a\x11\x0d\x33\x40\x7b\xb3\xa7\x62\xc2\x6b\x0b\x37\x1c\x63\xfb\xfb\x2f\x73\x22\xee\x85\x0d\xb9\xc2\x52\x02\x8b\x99\xb1\x7f\xef\x26\x18\x10\xe2\x0f\x88\x3d\xcd\x1c\xd2\x49\x5f\x5e\xe6\x28\xe7\x21\x39\xed\xe4\x28\xdf\xca\xe2\x32\xdc\x85\xd0\x3f\xa7\x63\x35\xbe\xad\x0b\xf5\x59\x4b\xec\x66\x16\x00\x95\x11\xd0\x93\x79\x22\xbb\x95\xff\x6c\x51\x87\x3c\x0f\x48\xfa\x5a\xf7\x80\xfc\x8b\x6a\x8a\x69\xeb\xcb\xe0\x66\x01\xe0\xda\xbd\x72\xda\x42\xf1\x99\x03\x4b\x8a\x08\x1d\x40\xa5\xb9\xe3\x70\x44\xb2\xf5\xee\xdc\x6b\xb2\x11\xd5\xbb\xb9\xa9\xe3\x88\x07\x23\xa1\x40\x7b\x56\xaf\x3c\x58\xd9\x67\x02\xd9\x28\xec\x52\xba\xb4\x45\xc8\x92\x0d\x76\x0a\xfa\x29\xd4\x3f\xa8\xf1\x5b\x04\x5a\xa3\x9f\xcc\x9e\x9f\x5f\xd7\xc4\x47\xa4\x7d\x87\x40\x92\x86\x43\x9b\x08\x85\x8a\x46\x0d\x99\xcf\x4a\x21\x7e\x86\xdc\x22\x63\x49\x30\x02\x97\x3f\x6c\x81\x94\xe5\xcf\x05\x8b\x02\x95\x3d\x68\xa3\x6d\xe1\x79\xd6\xde\x26\x1b\x77\x93\x64\x42\xc8\xe6\xb1\xdd\xad\x4a\xe6\x58\xbd\x16\x4d\x78\xf4\x98\xf7\xae\x14\xc1\x37\x78\xbf\xae\x36\x03\x12\x5c\x72\x74\x50\x14\x45\xe0\x85\x42\x81\x33\xac\xb1\xe6\x98\x06\xd9\x28\x7e\xa9\x99\x4f\xa0\x2f\x30\xa9\x85\x02\x88\x31\xee\x4e\xfe\xaf\xb7\x8b\xa1\x99\x84\xe4\x0a\x94\xcc\xb3\x98\x00\x5c\xc6\x4c\x4f\xad\x30\xd9\xf8\xbd\xec\xc5\xb0\x7d\xd7\xfd\x62\x51\xb0\xfb\x10\x2b\x2b\xac\xc4\xa1\x9a\xaa\x9f\x16\xe4\x99\xf3\x7c\xc8\xf5\x0e\x31\x9a\x66\xbd\x73\x95\x30\x6c\xc0\xdc\x5a\xf3\x06\x4f\x50\x2f\x7a\x97\xd0\xf4\x94\x01\x1e\xd6\x98\x69\x02\x9c\xcb\xc7\xd0\xf3\x60\xf0\x8f\xaa\xc4\x26\xb3\x15\x0d\x51\x82\xa9\x50\xf9\x6c\xff\x12\x45\x4e\x41\x9a\xb3\x8d\x6c\x79\x96\xae\x9c\xd8\x1c\x30\x6e\xc6\x68\x5d\x51\x22\xbe\xdd\x4e\xd9\x77\x07\xb7\xde\xa0\xa4\x0a\x75\xf1\x48\x81\x32\xdd\x50\x1c\x69\xac\x68\x2a\x59\xf6\x05\xb5\xe8\x86\xdf\x1e\xcb\x58\x1c\x33\xf2\xa9\xae\x2c\x71\xe7\xe1\x59\xd9\x61\x64\x7f\xd1\xcc\xdd\xc1\x3a\x28\x98\x03\xd5\xa7\x5b\x6b\xd8\x4f\xd9\xd7\x32\xdf\x3c\x9a\xa1\x1c\x05\xc9\x58\xa2\xbc\xea\x7b\x03\xda\xd3\xc8\x18\x97\x0c\xce\xa0\x80\x9c\xb6\x64\xf3\x2a\x42\x73\x9d\xb0\xee\x2c\x46\x0a\xbe\x4f\x1b\x33\x69\x6e\x22\x0c\x91\xaa\xe5\xf9\x59\x27\xd3\x67\x7d\xe2\xa5\x83\x76\x93\xe4\x3c\xf3\xa2\x5f\x64\x3d\x25\xea\xd9\x16\x5b\xc0\xc8\x04\x3c\xe8\x92\x7b\xc0\x30\x50\x7c\xdb\xc1\xb2\x97\xe8\x5e\x66\xac\x8b\x90\x3a\x25\x51\x5d\xfb\x15\x05\x88\x34\x11\x8f\xad\xa2\x4d\xfd\x0b\x74\x59\xb4\x6b\x5b\x49\xd5\xfc\x1c\x89\xa8\xeb\x13\xae\x1a\x07\x08\x60\xc0\xfc\xdd\x8d\xdd\x26\x0f\x8d\xac\x21\x76\xbc\xeb\xae\x9f\x64\x6b\xab\x74\xf1\xb3\x11\xe3\x13\x23\x9f\xc6\xfe\x3d\x6b\xb3\x2a\x76\xc6\x44\x17\x83\x86\x2b\x90\x5b\xbb\x05\x27\x64\x78\x50\xe2\x87\x09\x9f\x8d\xd3\xae\xf0\xe3\x29\x23\xcc\x08\xae\xdf\x94\xe6\x33\x7f\x3b\x26\xc3\x93\x57\x4f\xac\x72\x33\x6d\x18\xc3\x94\xa4\x85\x15\x69\x47\x7c\x09\xc9\xb5\xf0\x77\x9c\xc9\xaf\x33\x1d\x2d\x31\x87\x47\xed\x84\x65\x8c\x2b\xb2\xa7\xc2\x22\xda\xf2\x91\x20\x72\xf0\xcb\xe9\xac\xbe\x1e\x13\xcc\x67\x20\x07\xb3\xd9\x7b\x5c\x25\xec\x6c\x9c\x11\x72\x97\xa5\xab\x6c\x4b\xf9\xc4\x83\xc7\x1e\xe9\x24\x95\x90\xdc\xc3\xc4\xa2\xc5\xbd\x46\x45\xae\x52\xf9\x42\x54\x6b\xdd\xad\xf1\x04\xe9\xc6\x82\xe6\x49\x2f\xc4\xda\xfd\x25\x6b\x47\xdd\x59\xe0\x87\x4b\x65\x62\xee\xe8\xd1\x09\xcd\xfa\xd1\xd8\x4e\x63\x80\x99\xb9\x5a\xab\x18\xeb\x2b\x0e\xbc\xa1\x7d\x0b\x3d\xc3\xde\xeb\x19\x48\x4d\x22\x46\x5e\x58\x08\x70\xbe\x7c\x77\x4b\xc5\xbb\x52\x12\x18\x29\x55\x04\xc9\xd8\x3c\x8a\xb2\xab\xb2\xb9\xb5\x9f\xc4\xfb\xb6\x66\xe1\x5c\x76\x06\x60\x64\x4b\x84\x68\xf2\xac\x19\x6f\x0a\x0d\x74\xdb\x38\xdf\xee\x25\x0b\x8d\x7b\x59\x75\x06\xdc\x63\xd0\x5e\x59\xbc\x3e\x93\xb9\x7d\x96\x14\x2d\x48\xfd\xbb\x4c\xa4\x21\x5c\x96\xe5\x9c\x55\x8e\x15\xfd\xed\x22\x3f\xcb\x0f\x4b\x28\x21\x17\x53\xdf\x28\x5c\x18\xcc\x74\xb4\x25\x80\xbc\x7f\xc6\x8c\x52\x84\x2b\xc8\xe1\x8c\x75\x7d\x03\xbf\x0a\xc0\x93\xf7\x20\xd5\xd1\x62\xa9\x3c\xe8\xa0\xef\xfc\x63\x26\xf4\x2e\x0b\x42\x89\xfe\x77\xe8\xca\xa6\x10\xe3\x7d\xeb\x1a\xde\xae\xb4\xfe\x25\x1b\x48\x0c\x5b\xfd\xf6\x2e\x4e\x72\x89\xf2\xcd\x53\x82\xaf\x1d\xb4\xf1\x9d\xc2\xcb\x6f\x96\x76\xb7\x19\x73\xb2\xeb\xc0\xaa\x67\x87\x20\x29\x7e\xec\x2d\x53\x48\x45\x68\x2a\x33\x4a\x2f\x7b\x3b\x47\x53\x6e\x2a\x9d\x3c\xa9\x7c\x9c\xe7\xe9\xb9\xc7\xea\x8a\xd6\x9e\xba\xfd\x0e\x6e\x95\x2e\xad\x3f\x3f\x35\x79\xc2\x84\x04\x89\x13\x35\x75\x13\x7a\xf5\x13\x8e\x5f\xcf\xb3\x62\xa7\x5b\x35\x57\x1f\x2f\x5d\x5a\xf4\x82\x44\x1c\xc1\xd2\x6a\x28\x79\xcd\xe5\x14\xf6\xbd\x27\xb4\xe9\x6a\x28\x10\xb6\xfa\xc5\x5a\x3a\x80\x52\x1f\x8d\xd3\xe9\x1f\xe6\xca\xd6\xa1\x80\x3d\x2f\xb5\xf4\x1e\x50\x69\xa4\xcb\x0a\x05\x75\xb5\xfd\x8f\xdf\x74\x82\x70\xdc\x2e\x4e\xeb\x05\x41\x42\x72\x8a\x57\x81\xbc\x56\x82\x0a\x47\x80\x1e\xb8\xda\x43\x02\x4d\xa9\x75\xb5\x7c\x07\x97\xf5\x66\x29\x8f\xed\x79\x4e\x38\x27\x65\xd4\xf3\x7f\x44\x02\x01\x1a\xa5\x38\x13\x73\x9c\xc7\x24\x50\xb1\x56\x29\xe3\x8d\xcb\xa9\x15\xd7\xe9\x0d\xda\xeb\x18\xc8\x9c\x88\x6e\x0e\xd4\xb3\xf4\x3b\x90\x84\x0c\x1f\xca\xbc\x70\x85\xfe\xfb\xe1\xf0\x56\x5d\x5f\x5c\xda\xaa\x02\x8a\x60\xda\x7f\x34\x3d\x0f\x5b\xfc\xed\x45\xd7\xe1\xbb\x57\xce\x09\x24\x7b\x42\x3c\x9e\xcf\x38\xec\x59\xb1\x33\x76\xd6\x02\x42\xaf\xda\x8b\x4e\xaa\x88\xa0\x8e\xa5\xf5\x93\x62\x7e\x65\xf8\x08\x99\x1e\x40\xe5\x8e\x4a\xb3\x81\xcd\x98\xa0\x87\xb5\x5d\x2b\xbe\xd7\xcf\x45\xe4\x82\xc4\x5d\x38\xe0\x8d\xb3\x46\x46\x4b\x1a\x07\xe6\xf9\x71\xd2\xc4\x23\x1f\x8a\x3a\x20\x3d\xf1\xcf\x19\x32\xc6\x9a\x35\x74\xcf\x73\xc0\xf3\x93\x27\x47\x5c\x34\x96\x13\xa9\x2e\xbe\xcd\x48\xa2\xf4\x31\xa2\xf4\x00\xa0\xef\x90\x15\x85\x56\x31\x46\x63\xf2\x7b\xa5\xd2\x81\xec\x56\xae\x28\x6f\x56\x65\x4d\xbe\x9d\x8f\xeb\x2f\xcc\x7f\xd8\xd2\xe5\x69\xb1\x20\xd0\x44\x17\x2d\xda\x60\x66\x2d\xc2\x85\x53\x55\x6b\xd8\xa4\xe5\x61\xe9\x42\x7c\x42\xb4\x7d\xb2\x6b\x9e\xfb\x9d\x1d\xa3\x42\xac\xcb\x12\x23\x88\x53\xbe\xe2\x96\xc6\x5d\x4b\x9a\xcc\xbb\x13\xd4\x0f\x07\xb4\xe2\xa1\xda\xb2\x34\xa0\x4b\x40\x8f\x2a\xf8\x48\x1c\x3f\x8c\xcc\x50\xeb\xcc\x29\x3c\x8b\x20\x07\x18\x37\x85\x59\x93\x2b\x0d\x60\x5c\x52\x00\x86\x05\x87\xd2\xa9\xfd\x4a\x47\xb4\xa2\x1a\x46\x1d\x00\x66\x95\xd0\x99\xd4\x55\x5c\x55\x9d\x2e\xe9\x16\xdd\xf2\xee\xd8\x4b\x88\x1c\x27\x23\x55\x9a\xa5\x41\x98\x43\xd3\xec\xdf\xa8\x7a\x0d\xd5\x34\xc6\x6a\x5e\xb5\x22\x17\x15\xb5\xc9\xff\xea\x8a\x28\xc2\x6c\x59\x52\xdb\xfd\x0d\xcc\x56\x87\x81\x08\xdf\x82\x25\x03\xc8\x2c\x16\x61\xbb\x60\xad\x5d\xbd\xb6\x38\x8f\x83\x19\x84\x20\xed\xe2\x12\xcf\xe2\xfa\xac\x27\xde\xf0\x70\x30\x32\x60\x29\xc9\xbb\xe4\x1e\x8c\x1b\xd1\x7e\x1d\x80\x68\x6e\xaf\x7b\xc1\xe6\x85\x49\x49\x52\x29\xc1\x10\x82\xbf\x03\xbd\xbd\x14\x4d\x09\xc6\x94\xef\x69\x34\xcf\xc2\x1e\xaf\x8e\x22\x53\xe8\x35\xf8\x3f\xb9\xa0\x60\xc1\x9f\x39\xce\x13\xfd\x1e\x29\x00\x2b\xc4\x56\x40\x1e\x15\xa9\x28\x65\x89\xea\xca\x8d\x47\x68\x14\x16\xf1\x5f\x06\xbe\xda\xb1\xdf\xe9\x7a\x63\x38\x99\xcd\x4b\x7e\x67\x04\xb5\x15\x4b\xea\xd8\x77\x0c\x9d\xe2\xc9\xf9\xef\x20\x62\xbf\x03\x7f\x35\x3a\x9d\x55\x39\xd3\xd8\x54\xee\x11\x35\x04\xf4\xcc\xca\xcf\xd4\x61\xee\x62\xf3\xf9\x40\x08\x8a\x6a\x27\x5a\x00\x9a\xc9\x5a\x6f\x42\xc1\x6e\x3b\x36\xce\x08\x96\x26\x7c\xce\x35\x15\x39\x08\xae\x7e\x3d\x8b\xa1\xeb\x8b\x46\xca\x45\x34\x55\xcc\x04\x0a\x24\x24\x8e\x9e\x1e\x1e\x70\x14\x9b\x21\xff\xd2\x0a\x1a\x36\x80\x0c\x43\x1b\x7e\xc5\xc4\xd6\x54\x4f\x89\x2a\x8d\x25\x85\x9b\x45\xed\x91\x18\xbb\xed\xaa\x9c\x59\x16\x1b\xb4\xde\x05\xa5\xe1\x5f\xdf\xd7\xd4\x98\x02\xae\x84\x21\xee\x64\x6b\x1c\xa0\x09\x7b\xbc\x98\x64\x8f\x44\xcd\x85\x9d\x9b\x5f\xb6\x41\x9d\xb3\x1a\x15\x95\x6a\x2e\x1b\x0f\x81\xc7\x62\x46\x0c\xf1\x56\xa9\x15\x24\xc7\x52\xec\x89\x2e\x33\xee\x36\x26\x5b\x2b\xea\x09\x6b\x76\x32\x9c\xe4\x86\x7d\x04\x96\x60\xd4\x98\xfc\xb2\x61\x9e\x28\xb4\x97\x1f\x3c\x7a\x46\x11\x5f\xb3\x2f\x4f\xc2\x19\x75\x9f\x7d\x27\xc2\xda\x9e\x92\x24\xfe\x91\x6f\xa6\xa6\x22\xfd\x2b\x4b\xdd\xac\xdc\x46\x72\x0f\x71\x47\x04\x0e\x1a\xfa\x2a\xac\x09\x55\xc7\x67\xa6\x06\xe6\x0a\x92\xcd\x58\x0f\x26\xaf\x5d\x3a\x57\xcc\xc0\x14\xa7\xb3\xfd\x17\x5e\x43\x0a\xb7\x20\x19\x00\xce\x84\xbe\xf9\x8f\x10\xf2\xd5\x89\xd5\x66\x81\x01\x47\xb4\x78\xaa\xd6\xda\x68\xe4\x2c\x63\x23\x2f\x1c\x93\xff\x7e\x4e\x23\xc6\xc0\xe0\x5d\x50\x90\x0b\x20\x6b\x0d\x71\x9c\x1c\x21\xd5\x68\xf9\x54\x5b\xeb\x91\x54\x72\x1a\x77\x22\x4b\x2a\xc1\xf2\x08\x53\x57\x2a\x41\x67\x63\xd7\x97\x79\xcf\x1d\x48\xac\xe1\x5c\x00\xb5\x36\x71\xe7\xbb\xcb\x8e\x1e\xee\x45\x88\xc0\x26\xbd\x58\x77\xf8\x77\x9f\x8f\x19\x54\x86\x6d\xa2\xda\xd1\xba\xe1\x03\x88\x17\xe6\x27\x79\x1e\x33\xec\x64\x5f\x39\x0c\x6c\x40\x33\x26\x98\x89\xb3\x0c\xf4\x98\x61\xb6\x63\x55\xac\x95\x02\xb6\x64\xf5\xda\x9e\x1f\x71\xf1\xbc\x0b\xde\xcc\x9d\x31\xf3\x88\x58\x06\x66\x97\x9d\xef\x86\x9c\xa6\x97\x97\x41\x58\xf8\xb3\x32\x94\x03\x3c\x08\x22\xfd\x91\xba\xe0\x0d\x21\x80\x2b\xfc\x9c\xcf\x10\xa5\xc7\x03\xba\x26\x73\xf9\xbf\x2d\xf5\xaf\x36\x9f\xff\xbe\x9f\x49\xda\x8c\xc9\x91\x0a\x22\xc7\xd3\x5d\x33\x5f\x52\x5e\xb7\x16\x45\xeb\x74\x82\x75\x88\x1c\xaa\x53\x2a\xce\x1c\x0d\x78\xd3\x39\x3a\x02\xe9\x2d\xa7\x15\xfb\x2b\x26\xd5\x30\xd6\x55\x81\xa8\xf1\x17\x16\xa2\x62\x4f\x71\x6d\xbd\x16\xcf\x7e\xd2\xbb\x01\x06\xdd\xf2\x33\x73\xec\xef\xdc\x1e\x7e\x12\xe0\x4d\x78\x45\xea\x14\x43\x75\xc7\x42\xa0\x81\x83\x8c\xa8\xf4\x03\x68\x10\xf1\xb9\x63\x4e\x32\x3c\x27\xe3\xd7\x0d\x90\x4d\x27\xc6\x64\xa7\xfd\x80\x71\xcc\x4c\x4e\xfc\x0b\x4f\xcb\x31\xed\x28\x37\x10\xbc\x76\xcf\x8c\x6e\x35\x03\x38\xfe\xa6\x35\x20\x24\x31\x87\xc5\x96\x9b\xf8\x04\x58\xe5\x02\x1b\x2f\xd8\x0a\x24\x83\x1c\xc0\xc0\x5a\xe8\xbe\x1a\xe9\xaf\x89\xb0\x52\xb8\x00\x01\x09\xb6\x73\x55", 3876);
*(uint64_t*)0x20001008 = 0xf24;
*(uint64_t*)0x20001010 = 3;
*(uint64_t*)0x20001018 = 0x20000f40;
memcpy((void*)0x20000f40, "\x8e\x11\x64\x89\x1f\xb4\xce\xa3\x06\x76\xcf\x78\x1c\xae\x35\x93\xd2\xe1\x22\x55\xa6\x66\x5e\x3f\x2a\x27\x27\xf6\xdf\x30\xbc\xae\xb2\xa8\x7e\x5d\xaf\x5e\x5f\xbd\xe4\x9f\xe4\x27\xc5\x11\x7b\x86\x40\xb2\x15\x7f\x1b\x0b\x8c\x22\x1a\x96\xfb\xd2\xf6\x0c\x1b\xf7\x09\x1d\x94\x48\x19\x3f\xcc\x21\xc7\xb0\xb1\x1d\x22\x28\x3a\x44\xcc\x41\xfe\x75\x92\x06\x00\x00\x00\x00\x00\x00\x00\x2f\x38\x88\xe1\x5c", 98);
*(uint64_t*)0x20001020 = 0xfffffffffffffd11;
*(uint64_t*)0x20001028 = 4;
syz_read_part_table(1, 2, 0x20001000);
	return 0;
}