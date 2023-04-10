// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

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

struct io_sqring_offsets {
	uint32_t head;
	uint32_t tail;
	uint32_t ring_mask;
	uint32_t ring_entries;
	uint32_t flags;
	uint32_t dropped;
	uint32_t array;
	uint32_t resv1;
	uint64_t resv2;
};

struct io_cqring_offsets {
	uint32_t head;
	uint32_t tail;
	uint32_t ring_mask;
	uint32_t ring_entries;
	uint32_t overflow;
	uint32_t cqes;
	uint64_t resv[2];
};

struct io_uring_params {
	uint32_t sq_entries;
	uint32_t cq_entries;
	uint32_t flags;
	uint32_t sq_thread_cpu;
	uint32_t sq_thread_idle;
	uint32_t features;
	uint32_t resv[4];
	struct io_sqring_offsets sq_off;
	struct io_cqring_offsets cq_off;
};

#define IORING_OFF_SQ_RING 0
#define IORING_OFF_SQES 0x10000000ULL

static long syz_io_uring_setup(volatile long a0, volatile long a1, volatile long a2, volatile long a3, volatile long a4, volatile long a5)
{
	uint32_t entries = (uint32_t)a0;
	struct io_uring_params* setup_params = (struct io_uring_params*)a1;
	void* vma1 = (void*)a2;
	void* vma2 = (void*)a3;
	void** ring_ptr_out = (void**)a4;
	void** sqes_ptr_out = (void**)a5;
	uint32_t fd_io_uring = syscall(__NR_io_uring_setup, entries, setup_params);
	uint32_t sq_ring_sz = setup_params->sq_off.array + setup_params->sq_entries * sizeof(uint32_t);
	uint32_t cq_ring_sz = setup_params->cq_off.cqes + setup_params->cq_entries * SIZEOF_IO_URING_CQE;
	uint32_t ring_sz = sq_ring_sz > cq_ring_sz ? sq_ring_sz : cq_ring_sz;
	*ring_ptr_out = mmap(vma1, ring_sz, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_POPULATE | MAP_FIXED, fd_io_uring, IORING_OFF_SQ_RING);
	uint32_t sqes_sz = setup_params->sq_entries * SIZEOF_IO_URING_SQE;
	*sqes_ptr_out = mmap(vma2, sqes_sz, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_POPULATE | MAP_FIXED, fd_io_uring, IORING_OFF_SQES);
	return fd_io_uring;
}

static long syz_open_procfs(volatile long a0, volatile long a1)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	if (a0 == 0) {
		snprintf(buf, sizeof(buf), "/proc/self/%s", (char*)a1);
	} else if (a0 == -1) {
		snprintf(buf, sizeof(buf), "/proc/thread-self/%s", (char*)a1);
	} else {
		snprintf(buf, sizeof(buf), "/proc/self/task/%d/%s", (int)a0, (char*)a1);
	}
	int fd = open(buf, O_RDWR);
	if (fd == -1)
		fd = open(buf, O_RDONLY);
	return fd;
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
*(uint32_t*)0x20000058 = -1;
memset((void*)0x2000005c, 0, 12);
	res = -1;
res = syz_io_uring_setup(0x10a0, 0x20000040, 0x20003000, 0x20001000, 0x200005c0, 0x200003c0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000b80 = -1;
*(uint64_t*)0x20000b88 = 0;
*(uint64_t*)0x20000b90 = 0;
*(uint64_t*)0x20000b98 = 0;
*(uint64_t*)0x20000ba0 = 0;
*(uint64_t*)0x20000ba8 = 0;
*(uint64_t*)0x20000bb0 = 0;
memcpy((void*)0x20000bb8, "\x1a\xd9\x36\x04\x46\xe4\x21\xfb\x45\x94\x33\x73\xf0\x78\xd3\x34\x99\xf7\xa4\x9a\x90\x69\xde\x97\x02\xb1\xd7\x0e\x36\x9b\x23\xad\xa7\xf2\x33\x75\x5f\x9c\x5a\xd4\xe6\x31\xf5\x71\x4e\x6f\x0c\x82\xd5\x9a\x98\xf5\x37\x69\xa7\x32\x7c\xe7\x51\xc0\x7e\x63\xbe\xc2\xf1\x8d\xf2\xb8\xf1\x5f\xa4\x81\x82\x99\x82\x90\x1b\xb8\xde\x28\xa1\x79\x63\xb5\x6c\x0b\x92\xd7\x5e\x5e\x30\xf1\x4c\x6a\x41\xfd\x61\x6b\xde\x3b\x02\x7a\xbc\x61\xd5\x85\xa4\x47\x1e\x97\x42\x80\xfc\x0d\x9f\x6d\x3d\x2c\xd2\xc2\x47\x1b\x1c\x13\x9e\x18\xf4\x5f\x44\xac\xe7\x11\xd5\x68\x2d\x15\x97\x0b\x1e\x4e\xb3\x36\xb6\x40\x36\xa0\x83\x7e\xec\xc2\x24\x7d\xff\xf5\x8b\x94\x3d\xc6\x2c\x66\x11\x74\x17\x34\xb5\x07\xcc\x59\x65\x2d\xe0\xd0\x97\xad\x8f\xa7\x51\x61\xeb\x9f\xd1\x56\x4e\xae\xb6\x07\x59\xc7\x97\x18\xb6\x65\xe4\xc4\x72\xe8\xde\x98\xfb\xc0\x34\x42\xe5\xd8\xb7\xf6\x07\x60\x9c\x8a\x06\x28\x33\x81\x96\x28\xf4\x65\xcd\xb6\xe8\x08\x23\x72\x64\xaa\xff\x45\x7f\x8c\xd7\xbe\x11\xf3\x66\xcf\xb2\xa8\xc4\xf1\x96\x65\x7d\x38\x29\x23\x39\xc0\x8d\x74\xa0\x85\xe0\xda\xa5\xff\xf5\xf6\x80\x00\xc6\x01\xb3\x9e\x43\xe0\x50\x6e\x56\x42\xee\x5e\x38\xf3\x06\x1a\x21\x34\x99\x86\xe9\x06\xd3\x34\x5d\x5e\xba\xf4\x34\xba\x91\xf5\xf5\x42\x10\xa1\x14\x4c\xbb\xd9\x11\xf3\x7c\x24\x8b\x16\x69\x03\x02\xed\x82\x4f\xf6\x4f\xd1\x8d\x56\x34\x36\x32\xdc\x6f\x1b\xf5\x34\x56\x72\x0d\xfb\x48\x2c\x41\x4a\xf7\x50\x71\x9a\x17\xf1\x98\xd9\x82\xd5\x5d\x60\x24\x7e\x80\x61\x9f\x82\x0a\xd7\x0d\x57\x40\xba\x4f\x85\xdf\x73\x1a\xd9\x98\x66\x46\xa7\x47\x67\x12\x21\xb0\x98\x74\xbe\x72\x5b\x97\x2a\x32\x2c\x38\xcd\x24\xd1\xd9\xb7\x82\xd6\x75\x40\x68\xb2\x84\x2b\xb8\x31\xb4\x3a\x5f\xa4\xc3\x77\xf5\x78\x4e\x0b\xc7\x00\x8e\x64\x5b\xe2\x82\xa1\x71\x3d\x1f\x9b\xa4\xb1\x3a\xd1\xa6\x61\x33\x5c\xe0\x22\x8a\xdd\x76\xe3\x73\xb3\x01\xda\xcd\xd3\xbd\xf4\x0d\x46\xae\x27\x9f\xa2\xa5\x17\xf9\x80\xa1\x7f\x72\xd5\x97\x86\x15\xd6\x41\xfd\xf1\xde\x76\x80\x7e\x36\x49\x12\xc8\xc1\x2b\x9f\x9d\x81\xa6\x80\xd6\xe4\x8f\x6e\xb1\xf4\xda\xe6\xa7\x3b\x7e\x40\x34\x60\xf6\xd2\x63\x4a\xc1\x49\xf5\xdc\x59\xec\xc4\x01\x09\x32\x9e\x9e\xf1\x3b\x64\x84\xac\x6b\x2c\x15\x18\x55\xc1\x55\xa6\x04\x10\x61\xd4\xf7\xc1\x57\x7e\x47\x8b\x52\x7a\x9f\x0e\x08\x4c\x4e\xd8\x50\xd6\x53\x85\x66\xa8\x0b\xd8\x5d\x29\x8a\x91\xda\x1c\xd4\x7b\x95\x3e\x9a\xbf\x41\xb6\x93\x9e\x49\xae\x30\x98\xfe\x5a\xc7\xce\xdf\x4f\x8e\x82\xc9\x30\xad\x69\x6a\x9f\x30\xeb\xa9\xdf\xf9\x3a\x85\x08\x6c\xc6\x64\x8b\x20\x20\x3e\x8f\xfb\x22\x66\x99\x87\x53\x56\x50\x43\x0b\xc1\x6a\x4a\xd0\x1b\x38\x7c\xfa\x7d\x1a\xf2\x94\x97\x6e\xf8\x34\xd4\x1c\x02\x7b\xa8\xe8\xaa\x99\xe7\x87\x90\x4a\x28\x10\x33\x89\xf4\x4f\x3a\x9b\x87\x80\x4d\xf2\x48\xa5\xa3\x51\x08\x78\xa2\x39\xba\xa2\xbe\x69\xce\xee\xeb\x7e\xa8\xbc\x50\x04\x45\xa9\x1b\xef\x77\x2b\xed\x96\x7c\x69\x54\x1c\xcf\x8d\x60\x83\x1e\x7f\x14\xc1\xaa\x43\xea\xa0\xd5\x07\xb0\x44\x11\x2f\x04\x91\x25\xa9\x4b\x63\x88\x3f\xe2\xc2\xae\xb5\x7b\x97\x2e\xa8\x42\x99\x55\x64\x45\x69\x20\x9f\xb2\xb6\x67\xbe\xcd\x51\x35\x1d\xb2\xa2\x28\x74\x59\xf1\x50\x22\x22\x68\x90\x0b\xb2\x40\xdd\x58\x36\xbd\xec\x34\xdc\x37\x16\x1b\x2f\xf1\x30\xe0\x9d\x0b\x25\x3b\x73\xcc\xc9\x9d\xbd\xfe\xc9\x5b\x35\x61\x29\x92\x60\xb9\x1e\x67\x36\x12\x6f\x36\x9e\xca\x0c\xd6\x0d\x57\xcc\xe7\x6f\xa4\x6f\x0b\xad\x5e\xd7\xf9\xed\xad\x27\x3c\x43\xb9\x73\x30\x13\x9a\xcf\x3d\x8e\x34\xb1\x08\xcd\x5b\xe6\x02\x32\x11\x01\x90\xab\x21\xba\xcf\x82\xa2\x31\x7e\x47\xbd\x32\xa5\x60\x93\xe4\xc8\x3b\x07\x57\x10\x4e\x2d\x9e\x92\xf8\x53\x74\x5f\x96\x2b\xa1\x93\xc3\x6a\xac\x37\x53\x99\xbf\x65\xe3\x11\xc6\x5a\x82\xa0\x21\x04\x91\xae\xc1\xa9\x7a\xd7\xc1\xac\x92\x32\x6a\xfa\x5d\x51\xeb\x3d\x6d\x15\x81\x66\x20\xc6\xc9\xf5\xcc\xb3\x29\x09\xd6\x93\x70\x9d\x2b\xba\x3b\xfb\xd3\x4c\x24\x39\x03\xb0\xae\x7f\x65\xa3\x9e\x89\x6d\xd0\x41\x3f\xf4\x74\xde\x5f\xac\xd9\x6b\x97\x12\xd9\x5f\x03\x45\x5d\x8c\xa3\x05\x7c\x45\x8f\xa0\x6c\x60\x11\x43\xde\x2f\x55\xeb\x2a\x7a\x30\xb1\xde\x03\x80\x1f\x96\xcc\x82\x50\x41\xe1\x90\x56\x36\x24\x85\x49\xde\x2a\x8b\xf0\xf2\xaa\xf0\x51\x03\x72\x46\x29\x39\x09\x8a\x3f\x6c\xcb\x82\x9d\x12\x8e\xf1\x79\x69\x39\x3d\x33\x0e\xba\xe7\xa1\xdd\x5b\x59\x29\x93\x51\xf5\xe5\x9a\x5d\x08\x5a\xbd\x08\xdd\xe7\x9a\x19\xcf\xb7\x7e\xa8\x53\x3b\xcb\x96\xe1\x1a\x6e\xb2\x86\x6e\xd0\xac\xeb\x28\x9b\x75\xad\xcf\xe9\x62\x04\x5f\x34\x76\x12\x75\x7c\xc0\x96\xd5\x41\x6f\x23\xd0\x8e\xf8\x4c\x5a\x44\x3b\xf5\x20\x83\x9f\xd4\xea\xcb\x23\xa7\xbb\x79\x03\x86\xf8\xd4\xc6\x6e\xdb\x10\xda\x32\xde\xb1\xea\x55\xb4\x26\xeb\xe8\x38\xe6\x9f\xfa\x03\xe2\x99\x03\xe1\x92\x7f\x7c\x9a\x3d\xec\xd1\x8d\x3d\x10\x89\xae\xed\x1f\xd9\xf6\x7d\x00\xdf\x8c\xac\x44\xf7\x54\x19\x10\xb0\x47\xb5\x6e\xb6\x27\x3b\x8f\x0d\xe5\xd4\x1b\xc0\x13\x9a\xfa\x0f\x82\xca\xae\x15\x32\xf8\xda\x75\xd3\xbb\x7b\x75\xce\x47\x32\x55\xe1\xb6\x05\x64\xb5\x0e\x69\xbd\xa8\x20\x42\xa0\x36\x29\x14\x02\xca\xb3\x9c\xb2\xbc\xcc\xe0\x5b\xe8\xd0\x43\xcf\x75\x17\xb0\x3b\x79\x7a\x7d\x4b\x25\x11\x64\x8b\xb8\x51\x69\x5a\x26\xac\xf7\x13\xf6\x5c\xcc\x88\x9a\x62\xd6\xab\xe2\x5e\x17\xab\x4f\x68\x44\x6d\xc4\x48\x4d\xfb\xb5\xf3\xb3\xce\xfd\xf8\x2a\x8b\x29\x3d\xbd\xb4\xd0\x72\xee\x5d\x15\xe4\x42\xe4\x8b\xd8\x83\xc0\x39\x72\xde\xad\xdb\x48\xe5\x6e\xbb\x58\xb5\x4d\x5a\x48\x58\x24\xbc\xdb\xca\x0a\xeb\xe6\x86\x77\x49\xa0\xbf\x3e\x8c\x61\x03\xb2\x25\x29\x4a\x68\x60\x06\x1a\x2d\x91\x62\xc1\x93\xf4\x10\xd2\x47\x26\x2c\x9d\xb7\x18\x93\x79\xf7\x4e\xb0\xda\x57\x6f\x7d\x9f\xdd\x9b\x8e\xdc\xb8\xac\xca\xe1\x06\x00\xf6\xe1\x22\xda\x37\x4c\xc6\x9e\x8f\x61\xed\x98\x48\xf8\xf9\xc6\x3b\xed\x45\x10\x4b\x85\xb5\xc7\xd5\x2d\xfd\x2c\xc7\x45\xb7\x69\xf4\xcd\x1a\x47\xe4\x07\x89\xf4\x5d\x22\x13\xc7\xcc\x80\x56\x02\xab\xee\xb4\xdd\xc4\xcf\x4d\x8a\xab\xa4\x47\x9c\x1e\x23\xbd\xa3\x02\x53\x0e\x36\x58\x93\xb3\x9b\xc4\x24\xbe\x0f\x1f\xae\x5b\x64\x4e\x77\xd3\xc7\x59\x04\x2f\x5b\xe2\xd7\x89\x44\x34\xd3\x7b\x70\x19\xfb\x0c\x86\xd4\x4b\x26\x97\x89\x16\xb4\xf8\x13\x35\x4c\x22\xe7\xb3\xc9\x50\x8d\xe9\x7d\xa8\x8e\x39\x63\x30\x68\x46\x94\x05\x31\x2b\x76\x86\x89\x63\x07\x3a\x21\x4e\x04\xd4\x38\xe0\x61\x5c\xeb\x6b\xe6\x2c\xd9\x55\xfb\x08\xe7\x55\x71\xeb\xb8\x09\x5e\xbb\x04\x5d\x34\xfc\xcd\x9c\x84\xc1\xd0\xcf\x65\x33\x8e\x3e\x1a\xae\xde\xfd\x8a\x62\x6e\x96\x55\x46\x65\x39\x91\x01\xf4\xac\xf2\x0d\xc3\x63\xa8\x88\x2a\x62\xf1\x91\x7b\xb1\xd3\x22\xba\xa7\x92\x47\x26\xf0\xc8\x26\xb9\x4c\x9e\x82\x48\x7f\xd0\x86\x31\x76\x27\xe3\xa9\xb2\x02\x1d\xbb\xb6\xee\xdc\xa0\x5a\xfb\x47\x64\x87\x3a\xc4\x5d\xe4\x12\xd5\xd5\xa0\x29\x7d\x4a\xb1\xe7\x96\x42\x1f\x69\xea\xf9\xa0\x2b\x5b\xe2\xc3\xc8\x17\xa4\x19\x1c\x25\x78\x4c\x7f\x19\x8f\xe7\x5a\x8c\x13\x75\x7f\xd4\x59\x76\x03\xcb\xf4\xa2\x21\x8d\x17\x31\xd3\xe0\x6d\x54\xdf\x73\xcf\xb3\x15\x98\x46\x96\xfc\x35\x12\x47\x08\xe6\xde\xc6\x22\xf7\xa6\xe4\x90\xe4\x73\xb8\xa8\xf2\x77\x59\xbd\x9e\x3f\xc8\x2f\x81\x00\xbe\x19\xc4\x5d\xb5\xf9\xff\x13\x26\x23\x9c\x2f\xa5\xed\xf8\xd7\xba\x45\x42\xaf\xf3\x99\x26\x87\xf6\x32\x4c\xca\xe0\xfd\x04\x22\x51\xb2\x99\x1f\x67\xb1\x2d\x5b\x6e\xaf\x33\x72\xbd\x83\x0c\x37\x83\x1a\x97\x91\x17\x16\xdf\xa1\x63\x4e\x07\x3d\x5e\x76\xbb\xb9\x17\xe8\x50\x4f\x42\x3c\x11\x06\x11\xb7\x22\xcb\x80\xb7\x20\x4a\xd2\x96\xb9\x42\xef\x07\x9c\xec\xf8\x51\xbb\x47\x9a\x69\x95\x02\xf7\xd8\x3c\x99\xcd\x3b\x57\x95\x79\x30\xef\x77\x43\x6a\xcc\xf3\x26\xb1\x1b\x38\xf2\xf3\x28\x17\x9c\xa5\xaa\xa5\x0f\xcd\x7f\x5b\x67\x04\x45\x9d\xa7\x69\xbe\xee\x1f\x4b\x78\xcc\xf9\xd8\x08\x41\xb6\x2b\x4e\xa0\x05\xcd\xa4\xab\xb1\xa8\x19\x90\x13\x72\x4a\x79\x5b\x76\x2c\x53\xba\x10\x8a\xb9\x55\x94\x61\x35\x67\x06\x57\x20\x0d\x1f\x44\x94\x5f\x3c\x2e\x78\x2c\xe1\x0b\xff\x61\xca\x67\x3a\xff\x82\x5a\x85\xa0\x34\x4e\x2d\xde\x2c\x04\xde\xa2\xfd\x3b\xf6\x52\xf5\x65\x0b\xe6\x08\xd7\xcf\xdc\x42\xa3\xe4\x37\x31\x5b\x9f\x63\x62\xea\x52\x6b\xeb\xc2\x4d\x56\xbe\x35\xe3\x1f\x7a\x09\xbd\x38\x14\x1c\xb3\x74\x27\x5e\xf7\xa6\x3b\x18\xb8\x25\xec\x4e\x95\x5e\xfd\x24\x5d\x6b\x06\x59\xcc\xcf\xc8\x3a\x3d\x1d\x63\xbd\x5e\xb9\x6a\xe4\xa5\x63\xb6\xef\xe0\x35\x00\x5b\xe8\xf5\x43\x7c\x5a\xc5\x52\x8e\x3a\xa8\xba\xd5\x14\xcd\x06\x7d\xd1\x7f\xa8\xd3\x31\x1f\x7e\x79\xde\xd6\xd0\xa5\xfa\x76\xb6\x94\x3a\xfb\xb1\xe1\x2e\x4a\x4a\xe7\x17\xe8\x19\xc2\xcd\x56\x40\x12\xd6\x8a\xe8\x21\x5f\x00\xb4\x07\x73\x0d\xe6\x3f\x65\x14\x47\x10\xb6\x7e\x1c\x7b\x44\x08\xe1\xb5\x68\x9e\x54\x55\x13\xbf\xc0\xab\xc0\x76\xf6\x4c\x6d\x8c\x3b\x0d\x0f\x14\x3d\x54\x53\xa2\x00\x05\x3b\x9d\xda\xf4\xe3\xa7\x1e\xc4\x50\x85\x14\xda\xdc\xe1\xed\x32\x93\x22\xb7\x5c\xb9\xbe\x98\x6d\x8b\x31\xad\x9a\xea\x65\xa5\xd5\xdb\xd3\x34\xf9\x57\x45\x8b\x64\x2e\x01\x62\xb8\x10\x92\xdd\x81\x6f\x8c\x1c\x59\xa0\xeb\x47\x2e\x35\xb1\x75\x14\xe8\xee\x51\x62\xfd\xb9\x28\xd7\x27\x85\x40\xad\x82\xaf\x0d\x1a\x2b\x02\x8f\x50\xa2\x55\xa7\x2f\xa1\xcc\x00\x76\x06\x77\xad\xf8\xb1\xd5\x67\x56\x67\xd0\x34\x78\xed\xca\x74\xaf\x0d\x9d\x2d\x2e\xc7\x97\x03\xfc\xef\x83\xba\x79\xda\x6f\xea\x93\x60\x79\x4f\x95\x74\x4f\x73\x7a\xec\xd2\xfc\x1a\x63\xb9\x7f\x78\xa3\xed\x38\x85\x42\x0a\x7b\x11\xb9\xe2\xa3\x37\x00\x7d\xf4\x3f\x44\xc7\x56\x00\xf9\xf8\x2a\xab\xfe\x06\x35\x08\xd6\x7b\xde\xe3\x31\x24\x7c\x45\xd6\x3b\xc1\x13\xd0\x68\xc9\x9d\xf3\x5e\x90\x47\x30\x5b\x36\xd2\x06\xe7\xad\x74\xd2\xb1\xf2\x77\x87\x47\xb7\xc4\x10\xda\x0b\xe3\xed\x03\x5c\x94\x5b\x5d\xf3\x58\xc5\xbf\x2e\xbe\x9f\xc0\xda\x91\x1c\x8b\xf4\x80\xdb\x05\x0c\xe9\xe0\x78\xc4\x11\xbc\x6c\x0c\xf9\x66\x89\xb0\x77\xb6\xa3\x77\xf3\x35\x89\x4a\x90\xa9\x01\xc5\xdc\x4b\x46\x0c\x8a\x8b\xbd\x7a\x18\x9d\x1f\x25\x5a\x74\xc1\x42\x99\xc3\x02\xd5\x72\xc2\xbe\xaa\x11\x77\xfd\x3e\xb0\xdc\x67\x64\xb6\x3e\x2a\xe9\x2a\x90\x0a\xdd\x70\x73\xa1\x0e\xe7\xaf\xc8\x43\xb3\xab\xa2\x88\x71\x56\x93\xf3\x7e\xcc\xed\xff\xce\x53\x35\x9d\x4f\xb1\x61\x4d\x25\x1c\xd8\x21\x1e\x50\x79\x27\xe0\xfc\x71\x09\x0a\x8e\x18\xdd\xc9\xa6\x68\x86\x1b\xfe\xd8\xa1\x78\xa0\x76\xd7\x25\xb7\xd0\xad\x34\x5f\x70\xd4\x02\x97\xa6\x11\x9d\x1d\x70\x35\x9c\x17\xfd\x4d\x33\x50\x3f\xd9\x75\x2e\x18\x18\x15\xb5\xda\x42\xd9\xe0\x6f\xb1\x93\x10\x61\xcd\x34\xd5\x51\x9b\x3d\x4e\x71\x04\x08\xea\x09\xb1\xa8\xe1\xf2\x2a\x1c\x27\x82\xfe\x14\xd7\xdf\x1b\xb1\xb1\x24\x16\x7b\x72\x83\x4a\xde\x36\x83\xd7\x79\xe0\x79\x15\x83\xde\x26\xfd\x09\x4e\xfb\x41\x2b\x5b\xcb\xe0\xea\xc9\x39\xfc\x4b\x21\x18\xde\xa6\x4b\x01\xc4\x68\x01\x56\x48\xe2\xb2\x1c\x1e\x83\x28\xc4\x1d\x91\x94\x4c\xba\xb0\xaf\x9b\x63\x6a\x39\x38\x38\x03\x89\x29\x1c\x15\xba\x47\xac\x88\xb6\xc2\xe4\x8c\x2a\xa6\x1a\xa7\x61\xe5\xc6\x31\x9e\x3f\xc3\x6a\xa2\x4b\x5c\x6a\x74\x72\x5b\xed\x2f\x66\xe4\x99\x6c\xfa\x20\xd1\xb8\x88\x18\x85\x39\x63\xd6\xd9\xa9\x52\xc4\xde\x0a\x33\x91\xac\x37\x1c\x99\x04\x30\x45\x67\x3c\x0f\x7a\x97\x0f\x6e\x73\xa0\xd9\x5c\xc2\xe4\x56\x98\xf6\x2a\x32\x0c\x7f\x3d\xbf\xb5\x79\x2c\x3d\x70\x27\xa8\x82\xf5\x96\x08\xa9\xc7\xf3\xb2\x3e\xef\x72\x0f\x38\x87\xad\xa3\x67\x6c\xa8\x8a\xb1\x0e\x71\x0d\x0d\x9c\x12\x24\x8e\xab\x8b\x86\x37\xf5\x3a\xc5\x5c\xac\x8e\x1d\x18\x66\x81\x5c\x69\xc3\x1d\x9d\xf2\xfd\xb4\x51\xb4\x07\xa4\x03\x41\x56\x17\xcc\x8d\xc1\x2f\x13\x9c\xcf\xcb\x0a\x1f\x02\xbd\xd3\x29\x07\x84\x38\x30\xbb\xba\x7c\x46\x16\x17\x93\x52\x6b\xbe\xf1\x20\x20\x2c\xbb\x6e\x1f\x1c\x80\xd0\xef\xc3\x86\xec\xf7\x3c\x6c\xaf\x62\x0a\xc9\x51\xa2\x68\x2f\x80\xc3\xe5\xfa\x47\xb3\x40\x74\xb8\xd0\x1a\xb3\xec\xaa\x36\xf9\xde\xf0\x8e\x71\xc7\x58\x45\x7c\x64\xda\x82\x74\x2e\xf5\xd0\x7b\xee\x87\xf7\x67\xc3\xe3\x24\x14\xce\x2a\x05\x7a\x9e\xd7\xeb\xea\xa9\x5c\x01\xb1\x92\xd3\x9c\x3e\x09\x63\x90\x66\x1d\x6a\x2f\x13\x06\x57\x72\xbe\x7b\x0d\x05\x3a\xd5\xf8\x5d\x7e\xac\x06\xaa\x02\x28\x54\x81\xa6\x13\x9f\x8c\x90\xc4\x37\xd4\x48\x9a\xe6\x81\x2e\x8d\x8e\xf1\xb8\x32\x28\xf1\x7a\xb4\x01\x36\x97\x13\x2f\x49\xcf\x48\xe0\x6f\x35\xdd\xc1\x57\xc6\x96\x8f\xfd\xab\x18\xf4\xef\xe1\xaa\xdf\x3c\x28\x54\x3f\x6b\x0e\xf2\x6c\x61\xcb\x66\x99\x8b\x81\x84\x16\x72\x87\x46\xbe\x00\x00\x18\xc5\xc1\x63\x0c\xb5\x35\x39\x65\xef\x02\x90\x6e\x33\x77\x6a\x69\xe2\x67\x66\x45\xc2\xd2\x3e\x4c\x69\x31\x84\xd6\xf7\x1b\xfc\x99\xcb\x16\x2a\xc2\xae\xd0\xe6\xfa\xf8\x37\xd3\x89\x5f\x81\x01\xe0\xd7\x11\x92\xd4\x66\x01\xcd\x79\x59\x62\x6a\x8f\xde\xf0\xcf\x94\x4b\x34\x87\x40\x2f\xd0\x17\xc3\x64\x13\x7e\xb6\xc1\x8a\x2e\x29\xbc\xfa\x03\x05\x1e\xba\x88\xd0\x7b\xb4\x66\x45\xb4\xb9\xe3\x0e\xf8\x42\x4b\x0b\xe7\x47\xfd\x7c\x41\xf9\xce\x14\x05\xd5\x05\x12\x17\xe8\x25\xc8\x29\x44\xe1\xcf\xf7\x9b\x0b\xb1\x18\x61\x74\xd4\x29\xa5\x1d\x4a\x92\xbb\xd4\x17\x4f\x26\x2a\x88\xc4\xa6\x79\xcd\xa3\xb3\xf8\xa3\x47\x0e\xe5\x30\xc9\xca\xd0\x48\x33\x94\xb8\x25\x2f\xf7\x39\x4f\xf0\x73\x29\x38\x1b\x60\x0a\x9b\x9c\x84\x44\x20\xfc\x8e\xad\x8e\xa0\x68\x43\xeb\xe6\x73\x23\x6f\x9f\x23\x80\xad\x59\x42\x3b\xb5\x2f\xdd\x24\xe2\xa1\x69\x04\x85\x3a\x9c\x95\xde\xc0\x78\x00\xa3\x66\xc6\x6b\xf7\xc7\x8a\x3d\xd9\x4b\x07\x98\xc5\xb6\xc6\x9e\x98\x69\x78\x2b\x82\x64\xff\xf3\x5e\xa2\xde\xe8\x5a\xe2\x4a\xad\x5b\xb3\x57\x59\x1a\xe2\x18\x40\xb2\x7e\x5b\x81\xc8\x3a\x18\xe9\x81\x28\x7e\x18\xab\x2b\x31\x19\xe9\x2b\x84\x31\x9f\x58\x88\x2c\x05\x57\x12\x9f\xad\xd7\x4b\xef\xc0\xd5\x17\x11\xd6\x63\x02\x38\x1f\xce\xda\x57\x78\xb0\x40\x0b\x2d\x28\xbb\xf9\x06\xcc\x5c\xc3\x62\xde\x47\xd5\x17\x3f\x5f\x74\xe2\x03\xf6\x91\x6f\x53\x77\xeb\xef\x97\x4b\x57\x65\x6f\x84\x94\x77\x0e\x1c\xb0\x84\x0e\x77\x72\xf8\x68\xd8\x52\x0c\x5a\x6c\xbc\x45\xa9\x74\xc9\x1e\x9c\xcb\x33\x8a\xb3\xc1\x22\xf4\x78\x05\x65\x75\xb7\xc1\xc7\x80\x20\x1d\xd1\xf6\x97\x6d\x7f\xf3\xb7\x07\x55\x7b\xa3\x23\xed\x6c\x93\x74\x52\xe8\xe5\xc7\x36\xde\x84\x48\x4f\x13\x55\x1c\xa2\xcb\xeb\xf5\x33\xde\x79\xa6\x58\xa3\xe2\x59\x46\x2c\x46\x97\xcf\x80\x51\xdc\xe3\xb3\x5d\xc4\x54\xfb\x48\x5d\x1c\x3c\x06\x25\xb4\xd9\x51\xeb\x66\x59\x6c\x70\x44\x19\xfb\xa1\x4d\x02\xd8\x08\x33\xa7\x2a\xc5\xdf\x50\xf6\xcf\xe9\x06\xd1\xe0\xbb\xd7\xb0\x14\xdc\x51\xc8\x0c\x2f\xe5\xeb\x29\xbc\x14\x71\x13\x30\x5d\xcb\xb6\x01\x6f\x61\x34\xa7\xf6\x73\xe2\xb5\xf3\xee\x2f\x4e\x20\xfe\x60\xd5\xc2\xcb\x30\x64\x76\x84\x53\x22\x87\x84\x16\x92\xc6\xfa\xe1\xe8\x4c\xea\x49\x67\x17\x8a\xc7\x5e\xb1\x8c\xa0\x93\x4e\xb7\xb9\x31\x79\x26\xb8\xc5\xef\x2c\x2b\xa6\x6c\x2d\xd2\x44\xb9\x75\xbc\x49\x69\x73\xa0\x23\x12\x87\x85\xa0\x2e\x9f\x90\x7d\x18\xb1\x50\xcc\x13\x0d\xfb\x15\x68\x68\x9e\x23\x38\xe8\xe5\x1d\xcc\x85\xee\x51\x89\x03\x78\x74\xb7\x51\xc0\xf1\xb4\x53\x68\xb4\xb4\x4e\x12\xe8\xfe\xd0\x1f\xdd\x84\x7b\x18\xd0\x6e\xd8\xf7\xca\x52\x77\x0f\x35\x76\x46\x71\x83\x27\x2e\xa1\x3d\x41\x0e\xea\xdb\xef\xbd\x14\xde\xab\x85\x03\x11\xf5\x5d\xf1\x0e\x8b\x26\xfd\xdc\x5c\x91\xb3\x5a\x92\x96\x4b\xdf\x7f\xc6\x7e\x68\x77\x2a\x8a\x91\xb4\xfd\xa4\x03\xc5\x7e\x26\x49\xb9\xea\xb2\x40\x90\x41\xef\xd7\x2e\x04\x24\xb0\xee\x00\x73\x36\x62\xae\x90\x6a\xbd\xb7\x61\x0f\x08\xb7\x74\xc1\x8c\x7b\x55\xe1\x02\x6e\xe5\x94\xcf\xb0\xaf\xa2\xd0\xf5\xea\x34\xad\x1b\x9c\xf6\x4d\xa1\x69\xed\x86\x12\xca\xb6\x52\xd7\xdd\x1a\x4b\x90\x50\x8d\x09\x94\xd7\x9f\xe0\xa2\xdc\x91\xd3\x38\x25\xe8\x05\xf6\xe5\x56\xc1\xa1\xbf\x41\x0b\x3b\x9b\x9b\xf5\x04\x45\x84\xa4\x23\x59\xd7\xef\x04\x58\x12\x7f\xbd\xbf\x77\x82\xb5\xb7\x85\x05\xba\x05\x80\x55\xea\xae\x8b\x3d\xe8\x8f\xb2\x2e\x4b\x3e\x01\xe4\xda\x97\xd8\x07\x7f\xce\xb2\x44\x25\xaf\x10\x32\x71\x38\x66\x8a\xbc\x61\x6e\xf5\xcd\x50\x0e\x48\xd5\x31\x57\x7f\x56\x0a\x9b\x09\xe2\x73\x43\x89\xd9\xf2\x7d\x67\xb8\xdc\x69\xc8\x20\x49\x16\x82\xd9\xab\x93\x7f\xe0\x94\x20\x88\x37\xdb\x43\xc0\xab\x6e\x49\x34\xd3\xb0\xd4\x28\x0f\xab\xdb\xd4\xcc\x94\x1b\x32\x10\xcf\xdb\x22\x17\xba\xa1\x06\x02\x93\xc4\xfb\x9f\xf2\xe0\xf6\xd7\xa9\xae\x8d\xfe\x73\x77\xdb\x3a\xcd\x4f\x15\x8d\xfd\xaa\xb0\x07\xce\xeb\x41\xad\xbd\x23\xdf\xcf\xb4\x69\xbe\xcc\x31\x2a\x04\x18\x8a\xb9\x27\xef\x5a\xae\xbe\xc6\x9b\x95\xa8\xd7\x9f\x6d\x95\xab\x8e\x14\x57\x3d\x69\x16\xe0\x05\x42\x18\xb0\x14\xd5\x66\xe6\x4a\xb4\xa9\xbe\x66\x72\x6c\x9e\x3a\x01\x9d\xc4\x2a\x74\xa6\xb9\x7d\x80\x92\x5d\x58\xae\xdf\x94\xc4\x91\xda\x0d\xd5\x15\x25\x5a\x92\xbd\x6a\x54\xca\xec\x92\x8e\xbb\x20\x5c\xa4\x8e\x68\x45\x5a\x75\xc4\x49\xae\xc0\xe2\x39\x73\xd0\xcb\xb6\x24\x28\xf1\xef\xe7\xef\xdb\xf1\xd4\xfb\x29\xc3\xd0\x68\xfa\x63\x24\x65\x81\xc8\xe1\x8c\xd4\xc5\xd5\x81\x07\x0c\x35\xb3\x58\x54\x5b\xdc\xda\xfb\x7e\xa8\x69\x90\xd6\xf0\x20\x5f\xed\xc5\x2e\xc7\x87\xde\x35\x91\x8a\x37\x7f\xe6\x2c\xaa\xba\xe7\xce\xd7\x69\xd4\x83\x24\xe0\x87\xc1\x47\x4e\x89\x2f\x96\xeb\x47\x59\x1f\x8a\x65\x7f\x5b\x06\x8f\x23\x35\x57\x7a\xfc\x3e\x8a\x6a\xb7\x6b\x8f\xe6\x6c\x97\x07\xfd\x68\x29\xf6\x0c\xe1\xb3\x3e\x22\x18\xd2\x02\x1c\xa4\x9e\xc9\xa2\x3d\xa1\x93\xba\x33\x7e\x3b\xc8\x5e\xef\x6d\x5c\x67\x75\x5f\xe2\xd3\xec\x41\x49\x01\xdb\xdd\xa9\xce\x32\xa9\xff\xf1\xcd\xe4\xac\x55\xb3\x20\x12\x21\x2d\x22\x85\xfe\x60\xdb\xfb\xee\xa5\x0a\x16\x5c\x01\xd3\xe1\xf8\x3d\xc3\x26\x8c\x7d\xf3\xec", 4040);
	syscall(__NR_ioctl, -1, 0x50009418, 0x20000b80ul);
	syscall(__NR_mmap, 0x20000000ul, 0x4000ul, 1ul, 0x11ul, r[0], 0x10000000ul);
memcpy((void*)0x20000100, "ns/net\000", 7);
syz_open_procfs(0, 0x20000100);
	return 0;
}
