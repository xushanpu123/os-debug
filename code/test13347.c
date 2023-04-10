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

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

uint64_t r[5] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 0x98f6, 0x20000040ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000040;
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[1] = res;
	syscall(__NR_io_submit, r[0], 0ul, 0ul);
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[2] = res;
	res = -1;
res = syz_io_uring_setup(0x2b94, 0, 0x20ffc000, 0x20ffb000, 0x200011c0, 0);
	if (res != -1)
		r[3] = res;
*(uint32_t*)0x20001244 = 0xc81f;
*(uint32_t*)0x20001248 = 2;
*(uint32_t*)0x2000124c = 1;
*(uint32_t*)0x20001250 = 0x9c;
*(uint32_t*)0x20001258 = r[3];
memset((void*)0x2000125c, 0, 12);
syz_io_uring_setup(0x6dd5, 0x20001240, 0x20ffd000, 0x20ffc000, 0x200012c0, 0x20001300);
*(uint64_t*)0x20000380 = 0x20000000;
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint16_t*)0x20000010 = 0;
*(uint16_t*)0x20000012 = 0x3f;
*(uint32_t*)0x20000014 = r[2];
*(uint64_t*)0x20000018 = 0x20000140;
memcpy((void*)0x20000140, "\x58\x66\x80\x81\xf0\xbf\x66\xae\xa2\x8d\x2f\x07\xd9\xb7\x47\x50\xc2\xa8\x00\x6a\x9e\x06\xc7\x09\xee\xa8\xbf\xb2\x76\x30\x37\x91\x9b\x3f\x27\x9a\xc8\x3e\x55\x10\xf4\xcf\x8e\xdb\xb8\x62\xe9\x6f\x95\x6a\x9b\x64\x40\xbd\x61\xa1\xd9\xbb\xd5\xca\x04\x0a\xf2\xb7\x0d\xeb\xa7\x94\x34\x3c\xe8\x8e\xdd\xc9\x9f\xaf\x80\xf2\x78\x1f\x8d\xa2\x6f\x30\x11\xa2\x2e\x9e\x52\x8f\x94\xb2\x0a\xd6\xd2\x19\x82\xd4\x94\x37\x30\x08\xb9\x3c\xcc\x69\xe3\xf1\x72\x5e\xef\x56\x23\xfd\x01\x86\x6f\x65\x22\x1d\x87\x20\x78\x89\x49\xb7\xd1\x99\x79\x79\xe8\x3f\x92\x6f\xe1\xce\xf3\xaa\xa1\xd9\x03\x51\x6d\xf6\xa8", 145);
*(uint64_t*)0x20000020 = 0x91;
*(uint64_t*)0x20000028 = 0xc231;
*(uint64_t*)0x20000030 = 0;
*(uint32_t*)0x20000038 = 0;
*(uint32_t*)0x2000003c = -1;
*(uint64_t*)0x20000388 = 0x20000080;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint16_t*)0x20000090 = 1;
*(uint16_t*)0x20000092 = 8;
*(uint32_t*)0x20000094 = r[1];
*(uint64_t*)0x20000098 = 0x20000b40;
memcpy((void*)0x20000b40, "\x14\x10\x61\x8f\xb8\x2d\x8e\xaf\xd4\xf5\xc2\x20\x90\xb5\xf4\x3d\xed\xe3\x95\x03\x1b\x92\xd7\xef\x56\x3b\xf9\x3f\x49\x02\x5a\x0e\xba\x3b\xe2\xd1\x6f\x34\xa8\x98\xf8\xa0\xc0\x65\xab\x0e\x4a\xf3\xa2\x2d\x34\x62\x4b\x2e\xd5\x2a\xb0\x59\x06\x76\xe8\x8d\x00\x6b\xe2\xd5\xd2\x8a\xc0\xf4\xef\x5b\x07\x56\xfa\x6a\x1b\x0f\xec\x6e\xd7\x36\x4e\x88\x4e\x38\x16\x06\xa2\xa5\xa0\xa0\x20\x01\x0c\xf9\xab\x2a\x35\xf5\x1d\x16\x27\x66\x33\xf8\x8b\x31\xdd\xcd\x88\x6d\x24\x21\x5e\x3f\x59\x1e\x6f\x21\xd3\xfe\xbb\x6c\x57\x75\x35\xa1\x26\x9d\xec\x35\xaa\x8e\x56\x24\x2b\xdb\x7b\xe7\x37\xcd\xca\x07\x7e\xe4\x5f\xae\x44\x37\xac\x73\x65\xdb\x5a\x93\xf3\x9a\x5a\x6e\xfc\x1b\xa8\x56\x82\x5e\xd6\xdc\x24\x50\x4d\x7d\x75\xa9\xaa\xc7\xfe\x1a\xa7\x2b\x6a\xdc\x0e\x8a\x46\x6e\xfe\xf5\x77\xe3\xe5\x2a\x22\x26\xa5\x0b\x9f\x69\x7f\x6e\x31\xf8\xf4\xe9\x86\x4c\x6f\x57\x53\x35\x31\xde\x1f\x4e\x74\x47\x89\x77\x44\x65\xcf\xd9\x1e\x61\xa6\xc5\x85\x1a\x57\x7b\x74\x48\x79\x57\xe0\x59\x24\x63\x01\x98\x74\xf0\xb5\x21\x2b\xc2\xaa\xe8\xb3\x4c\x6a\xc6\x8d\x08\xad\x7c\x9c\xf2\x7b\x5e\x86\x03\xd0\xbc\x7c\xcd\x46\xa3\x10\xff\x4b\xcc\x46\xdb\xd1\xb5\x34\x9e\x7b\xb6\xf5\xf3\x32\x7a\x0f\xd3\xa3\x1a\x1a\x98\x19\xc8\xa9\xe2\xc3\x16\xf1\x66\x28\x14\xe4\x67\x2a\xf9\xc0\x93\xc9\x60\x39\xa1\xaf\x51\xdc\xda\xbf\x79\xf2\x28\x7c\xa1\x39\x25\xad\x09\x47\x3b\x5f\xc8\xe5\xf0\x2d\xcd\xcb\x55\xfd\x08\xf7\x84\x46\x0b\xd2\xce\x46\x1e\x19\xc6\xad\x0d\xbb\x3a\x12\xc5\x53\x1b\x03\x8d\x3a\x05\xf1\x5e\xc2\x5d\x36\x03\x48\xeb\x5d\x27\xc0\x74\x5a\x6a\x12\x28\xdb\xa6\xf8\x56\x3a\x5d\x9d\x55\xe4\x8e\x49\xd2\x91\x5f\x25\x27\x53\x6f\xaa\x38\x87\x08\x49\xd3\x1a\x4d\x18\x4a\xf4\x60\x98\xee\x34\xaf\x8b\xab\x5d\x6c\xa6\x9e\x7b\x6d\x95\xae\xec\x39\x66\x8b\x88\x6f\x1b\x66\x46\xf8\x9a\xbb\xa4\x49\x16\xbc\xcd\x1e\x87\xb9\xef\x71\x1b\x4b\xeb\x16\xbc\xca\xba\x9f\x96\x8c\xf6\x60\x8e\x54\x4b\xa4\xf4\xe1\xd2\x3f\xb2\xd8\x84\xbe\xe5\xf8\xf1\xaa\x15\x91\x21\x8d\x5a\xd9\x8c\x29\x26\x6f\xdb\x4c\x20\xf2\xe4\xb1\xd1\x98\x6e\x02\xea\xf9\xa8\x55\x08\xfd\x78\x71\xf0\x3b\x77\x90\xf1\x2a\x94\xf7\x1c\x0e\x8e\x11\x61\xde\x9f\xce\x01\x57\xe2\x27\x80\x1b\x19\xce\xe5\xb5\xd2\xda\x2c\xaf\x26\x35\x9d\x15\x7c\xc5\x15\x57\x9c\x49\x36\x65\x0c\xd8\x13\xf2\xce\x3f\x77\xe7\xb5\xd4\x07\xa1\x95\x23\x7d\x11\x1f\xbc\xf4\x69\x37\xc9\xd5\x42\x2b\x1b\xc3\x15\x94\x1e\x8d\x17\x0f\xeb\x0f\x20\xd1\x28\xe9\xb5\x68\x1a\xcc\xfe\x94\xc3\x53\x6a\xff\x69\x31\x43\x0a\x3a\xcf\x6d\x16\x9f\xf7\x24\xfe\xce\x22\xb3\xc2\x12\x4c\x1e\x51\x12\x18\x59\x14\xff\x39\x60\x7d\x1b\x13\xdb\xe7\x3e\xc2\xaf\x78\x00\xa9\xe8\x1e\x1e\x1f\x11\xf4\x48\x9a\xbc\x9c\x80\x05\xa2\xf9\x18\x63\xa2\x45\xc9\x9e\xba\xc0\xd4\x47\xb8\xbb\xe5\x6b\xe7\x48\x87\xbb\x7d\x35\xdc\x8d\xfb\x52\x04\xc9\xb0\xaf\x70\x95\x4a\x3f\xfc\x22\xea\xd4\xb5\x55\x87\x49\x3c\x05\x85\x15\x78\x7b\x92\x0c\x52\xa3\xe3\x37\x3a\x72\x7c\x92\x2a\x15\xbc\x07\x66\xfa\xa7\xb4\x50\x73\x4b\xb1\xeb\x35\xae\x20\x23\x6a\xa7\x7d\xc9\xe3\x44\x37\xdf\xc0\xf5\xcb\x4f\x7e\xfd\x76\x1e\xa2\xb0\x4e\x2a\xb4\xe8\x7a\xab\x5b\xd2\x2d\x9b\x38\x6c\xb6\x4c\x69\xd6\xc0\xc4\xf6\xf1\x76\x59\x31\x7f\xa1\x29\xe9\x7e\x0b\xd3\xdd\x44\x8c\x9c\xf0\x62\x6b\x75\x8c\x98\x91\xf9\xef\xc7\x07\xb8\x47\x6a\x8c\x03\xba\x0c\xa5\x9d\xe9\xa9\x83\x4c\x03\x8f\xa5\x60\x3c\xe4\xaa\x49\xbd\x11\xda\x49\x5b\x42\x20\x1b\x2e\x95\xc6\xce\x42\x2b\x4f\x93\x25\x83\x49\x22\x74\xa8\xc6\xd5\x23\x7c\xe9\x1f\x9b\xc2\x77\xee\x96\x13\xca\xde\x8e\x5b\x5d\x83\x96\x38\x5d\x0e\x75\x6d\x70\x33\x4f\x11\xb9\x45\x18\x9e\xd7\x94\xdd\x76\xe7\x48\x0f\xbe\x31\x8c\x72\xdf\xc0\xa7\x2d\x4b\xcc\x9c\xa2\xc7\xe1\x7b\x9b\x68\x57\xd3\x12\x98\xeb\x97\xee\xe9\x0f\x49\x9d\xb4\x17\x73\x0f\x46\x56\xf7\x11\x65\xca\x92\x99\xc2\xb0\xc7\x00\xe3\x28\xe6\xaf\xc2\xd0\x81\xe8\x2f\x9c\xba\xab\x2c\x03\x7f\x6b\x4d\x0c\x9c\xaf\x06\x32\xae\x0e\xe8\x89\x82\xac\x69\x87\x7c\x18\xed\xc3\x38\xf4\xf6\x7e\x7b\xc6\x93\x52\x36\x81\x69\xf6\xa6\x83\x9b\xa6\x63\x03\xb3\x92\xd1\xb2\x8e\x58\x5f\x6e\xa7\x71\x71\x3f\x63\xdb\x54\x88\x4b\xbf\x4f\x51\x57\xcf\x74\xc4\xcd\xb5\xc3\x13\x11\x55\x18\x79\xa4\x04\x1a\x1e\xc7\xd2\x80\xb1\x51\x54\xf1\x77\xd2\x6c\x20\x57\x2a\xb8\x98\xfd\xce\x35\x93\xf5\x50\x33\xc5\x89\x6d\x1b\x41\xf8\xc6\x42\x67\x62\x72\x5e\x0b\x07\x1d\xb9\x07\xb4\x71\xed\x27\x39\x23\x3d\x27\x57\x95\xab\x82\x31\x5a\xb7\x18\xb3\xdf\x39\x23\x04\x32\x80\x48\xcd\x75\xab\x3c\x29\xdf\x09\x11\xa0\x4f\x33\x99\x42\x0f\x24\x5d\x22\x42\xcf\xc0\x41\x4d\xec\x35\xad\x50\x22\x21\xa8\xce\x54\x75\x02\x00\xd0\x69\x15\x59\x5a\x97\x6e\x91\x7e\xd4\x18\x44\x17\x80\xec\x0f\x84\xba\x19\x06\xec\x4e\xad\x2a\x2f\x79\x1d\x03\x7e\xd2\x12\xee\xe0\xbb\x9d\xfb\xc6\x57\xaf\xf7\x45\xcc\xfd\xe2\x98\x5d\x3c\x98\x14\x5d\xbc\xa9\x10\xe2\xf4\x3f\x10\x18\xe0\xa8\x40\x6a\xc5\xe1\xd7\x63\x7f\xa4\xbe\x16\xea\x33\xd8\x94\x85\x2e\x03\x4a\x60\x49\x2f\xa0\xd5\xc4\xdd\x74\xdc\x95\x01\xb5\xfd\xbe\xae\xe0\xa2\xb9\x58\x85\x70\x14\x47\xcf\x7e\xff\x11\x5f\x07\xae\x70\x64\xf1\x18\x23\x58\xef\xc3\x08\x7e\xa1\x16\xbb\xe6\xeb\xb7\x09\xcb\x9a\x17\xa5\x6b\x90\x96\x68\x2f\x07\x01\xb7\xb9\x3e\xea\xf1\x55\x81\x2b\x8f\x01\x47\x8c\xc5\x90\x82\x34\xab\x75\x10\x25\xcc\xc5\xf1\x4b\x6f\x32\x17\x0a\x97\x54\x7d\xd4\xe6\x9c\xd1\x35\x8a\x70\x01\x67\x4f\x8d\xfe\xe6\x2e\xe2\xec\xc9\xd7\x36\xd1\x07\x9b\x4e\xe2\x3c\xcb\x58\x7e\xca\x05\x88\x4d\xd3\xa9\x20\xc7\x0e\x3e\xbe\xf9\x6f\xc5\x02\xef\x3f\x57\x2b\x84\x47\x9c\x02\xe4\x41\x8a\x37\xce\x0c\xe5\x1f\xcd\xe3\x46\xed\xc7\xd3\x02\xa3\xca\x81\xfc\x63\x8d\x04\x54\x6c\x32\xf5\x2e\x88\x0f\x16\x6e\xd6\x4a\x90\x3a\xd8\x45\x9d\xee\x2b\x93\x6e\xe8\x25\xa1\x63\x9c\x8b\xf7\x69\x93\x4b\x67\x79\x5a\x01\xe9\xb6\x82\x43\x15\x7a\x65\x5c\x19\xa5\xe0\x08\xe2\x58\x84\x11\x53\xaa\x00\xdb\x15\xb4\xe3\x77\xe3\xaa\x07\x39\xde\xb8\x8b\xc9\x64\x20\x47\xca\xe6\x55\x57\x82\xb1\xa7\x2c\x56\x6e\x17\xe1\x70\x9f\xdc\xc5\x3e\x77\xbb\x0e\x53\x43\x30\x3c\x65\xee\x0e\x03\x4c\x0c\x45\x79\xe2\x92\xd4\x52\x74\x56\xfc\x1c\x99\x5d\x2a\x27\xbe\xfc\x32\x47\x73\xad\x39\xa4\x77\x22\x6e\xf1\xfd\xf2\x5b\xff\x71\x23\x47\xa8\x25\x46\x65\x48\x21\x1d\x38\x3b\xe2\x43\xb1\xc0\x50\xa3\xbb\x60\xab\x46\x82\x91\x57\x4e\x42\x8a\x1b\x63\x85\xaf\x93\x54\x9f\xdf\x06\xe4\x1e\x74\xc6\x00\x94\xe1\x02\xbb\x4c\xbe\x29\xc4\xf8\x54\xc6\x74\xaa\x1a\x5b\x38\xe1\xa6\xb4\xf4\x8d\x06\x1a\x5e\x1a\x8a\x03\xa1\x89\x71\x95\xa3\x04\xe3\x98\x58\x8a\xe9\xfb\xf7\x85\x63\x46\xcf\xb0\x01\xcb\x2c\x4f\x82\x61\xe1\x34\x73\x4c\xc1\x74\x71\x88\x23\xf3\x37\xac\xd3\x59\xdf\xf1\x4d\x51\xcf\x33\xa9\x60\xb0\x97\x8e\x5f\x9b\x24\x4e\xa4\x90\xdc\x8f\x9d\x81\xa9\xed\x83\xa6\x59\xfe\x1c\xec\x7c\x47\xcf\x9c\x1a\x2b\x5f\x85\x06\xbd\x86\xe6\xa6\x5a\x7c\x37\xc5\x01\x02\x28\x37\xa6\x7b\x31\xe4\x7b\xc6\x34\x72\x93\xbd\xa5\x94\x51\x3a\xd0\xf6\xbd\xc5\x85\x62\x1e\xa2\xbe\x37\xb4\x03\xa2\x9f\x80\x56\xcc\x37\x9d\x8e\xda\xb6\x6b\x0a\xc3\xb3\xba\x4f\xd8\xe8\xaa\x63\xf3\xd4\xae\x8a\xf4\xb5\xa8\x6e\x32\xe8\x19\x1a\xef\x99\x91\xd5\x05\x4f\x98\x3d\xd7\x23\xbd\x8c\x12\x72\x8f\x9a\xdc\xb6\x21\x98\xa5\x3f\x66\xbe\x78\x19\xa5\x66\xdd\xe8\x73\x11\xa9\x6b\xb8\x6e\x7c\x09\xa9\xe2\xe5\x40\xc5\xe8\x81\xf5\x9e\xdc\xb3\xc2\x7b\xa1\x40\x04\xec\xd2\x16\x9d\x6c\xea\x9e\x58\x1c\x8b\x32\x45\x03\xb6\x95\x78\x7b\x58\x0f\x7d\xfa\xb4\x9d\x54\xeb\x57\x9b\x72\xff\x8f\xad\x50\xfc\x3b\xe9\x2e\x37\x13\xb6\xca\x39\xbd\xb3\xf9\xf4\x03\xdf\x42\x4c\xea\xec\x93\xed\xa2\x6d\x31\x5b\x76\x60\x17\x19\xe7\xc2\x48\x6e\x4d\x13\x76\x2e\xa6\xea\x08\x03\xb2\xe9\x78\x44\x13\x68\xd5\xb1\x7b\xe3\xd8\xbe\x00\x04\x04\x5c\x8a\x96\xec\x83\x35\x1a\x1c\x78\x86\x9f\x03\xe2\x29\xa4\x78\x89\xdb\xac\x75\x97\xc4\xaf\x61\x1c\xdc\x53\x16\xc0\x6e\xf1\x32\xcb\x3a\xd5\xac\x49\x1a\x69\x82\x28\xfe\xcf\x99\xb4\x84\xd7\x24\x2e\xe5\xb9\xbd\xb1\xd1\x3f\x9d\x81\x7a\xed\x83\xec\xeb\x68\xd3\x6f\x31\xb2\x08\xcc\x9c\x50\x0b\x74\x72\xd3\xaf\xae\x80\x4e\x81\x46\x3d\xde\x6c\xa2\x90\xf8\xc9\x65\x83\xc8\x75\xa1\x76\xcd\x42\x7e\x51\x05\x86\xe0\x0a\x8e\x9b\x44\x83\xae\xa8\x99\xb1\xf7\x8a\x87\xbd\xf2\xa2\x6a\xa6\xc7\x80\xd9\x03\xf6\x27\xaa\xd7\xf6\x42\xff\x88\xf0\x39\x29\xcb\xad\x4a\xec\x87\x68\x6a\x92\xa6\xb2\xb4\xd6\x2b\x25\xd4\x1f\xb5\xe3\x0c\xb8\xc0\xc0\x61\xd0\x27\xa9\xf3\x62\xd8\x6d\xc2\x10\x99\x77\x5f\x61\x2d\xf3\x38\xeb\xc5\xc4\x97\xa9\x82\x54\x97\x6c\x82\xdb\x1f\xbc\x78\x9b\x7b\xbe\xb4\xb4\x84\xae\x73\x0d\xe3\xed\x2f\x0c\x03\x8f\x5c\xc9\xae\x59\xbf\xf3\x15\x10\xf9\xaa\xde\xa2\x3c\xf5\x9b\x5e\x00\x87\xf5\x74\xb1\xf5\x49\x9e\x8c\x31\x0a\xf6\x11\x9d\x3d\x6c\x73\xa9\xe8\xc6\x35\x15\x1a\x6b\x00\xed\x82\x85\x0b\xe5\xb4\xa4\x6e\xbe\x37\xbd\xd7\xcb\x30\x6d\x4b\xd3\x06\xb0\x80\xf5\xab\x87\x71\xcc\x86\x94\x1e\xab\x4a\x87\xee\xe1\xe5\x2f\x0e\x51\x7e\xa2\x28\x1a\xf4\xa3\xc1\x2f\x89\x97\xfe\xa1\xac\x0a\x79\xc7\x6a\xad\xdb\x06\x17\x0f\x15\x35\x65\xdd\xe5\x95\x0e\x8e\xef\xcf\x5e\x0f\x2e\x19\x2e\xb4\x3e\x88\x79\xae\x9f\x7b\x5c\xc1\x95\x6a\x98\x28\x6a\x76\xe4\x09\x50\x31\x38\x84\x71\xfd\xdf\x58\x4f\xfd\x32\x3f\xe7\xbe\x94\x24\x20\x09\x72\x74\x7d\xea\xb1\xc6\x82\x81\x46\x1b\x34\xb6\x71\xd5\x51\x0d\x5b\xa1\x1a\x75\x54\x2a\x70\xe7\x1d\x39\xc5\x2d\x9b\x2c\x3f\x0b\xf6\xa7\x73\x3a\x3a\x72\x06\xc0\xf3\xe0\x5f\x09\xb4\xad\x91\x7d\x51\xbe\x36\x4d\xf2\x3c\x52\x03\x54\xc5\x1d\x6b\xe4\x30\xc6\x18\x46\x71\x7b\xc0\x77\x0e\xef\xab\xa1\xd2\x3e\x22\xde\x04\x8e\x5e\x5e\xf6\x04\x77\xed\x19\xdd\xd0\x15\xee\x3b\xe3\x5f\x43\xae\x79\x7f\xe6\x81\x6b\xfe\xfb\x60\x57\x8a\xa9\xb1\x2d\x44\xe9\xf0\x9c\xce\x9f\x9d\x0c\x9f\xb8\xf2\x7e\xa5\x41\x66\x80\x87\x3b\x6c\x32\x82\xaf\xec\xb0\xcb\x77\x48\x7b\x5b\x5a\xd7\x19\x2d\x5c\x52\x99\x69\x5a\x48\xf7\xea\x79\x73\x1a\x46\x1f\x52\xb3\x6e\xd1\x47\x2a\xb4\xf7\x1e\xc2\x69\x24\xc6\x0f\xd1\x86\xba\x0b\x2a\x21\x5b\x30\xe7\xbb\xa0\x90\xd6\xbd\x46\xf8\x70\x04\x96\xee\xc6\x3b\x31\x73\x97\xa1\x22\x60\xe1\x74\xdd\x5e\x4d\xba\x8b\x57\x52\x08\x59\x8b\x69\x46\x4b\xf8\x96\xb0\xea\xbb\x13\x55\x99\x6f\xf3\xba\x7c\x46\x91\xdc\x3d\xfd\xae\xf5\x50\x38\x3e\xab\x23\xa4\x48\xd5\x9e\x47\x8b\x2b\x97\x17\xbf\x6f\x2a\x6a\x1b\x14\x0b\x43\x35\xe5\x0e\x54\x8e\xc2\x1a\x5d\x81\x15\x73\x6b\x76\xb9\xdf\xeb\xa1\xbe\xc8\x99\x93\x4d\x21\xf3\x81\x76\x75\xe3\x9e\x23\x6f\x4b\x77\xe0\xc7\x84\xd9\x96\x77\xc6\xbf\x6f\x94\xf2\x0f\x1c\x09\x5e\xe1\x20\x04\x64\x3a\xdb\x60\x31\xec\x0c\xb2\xa4\x42\x6d\xce\xe3\xf6\xa0\x16\x64\xed\x83\x70\x3f\x1a\x8e\x8c\x5d\x77\xc6\x99\xcd\x1a\x65\x7f\x48\x5f\x83\x4f\xe7\x63\x08\x07\xb9\x10\x24\x9a\xb3\xc3\x55\xd1\xd0\xdc\xaf\xfc\x8b\x57\xf8\xa8\x79\x15\x98\x9c\xe3\x7c\x11\x3b\x39\x00\x3d\xd8\x24\xd5\xa4\xc2\xe1\x31\x8d\xa0\xd8\xd8\x1c\xe0\x33\x9b\x56\x8f\xd7\x36\x6a\x66\x3d\x6b\x2d\xaa\xd1\x12\x2d\xee\x21\x08\xad\xd5\xc1\xcf\x80\x5a\x54\x34\x1b\x1a\x39\xea\x55\x06\x45\xfc\x41\xc8\x0b\x08\x83\xf0\xd3\x7b\x73\x13\x8a\x9e\x34\x96\xdf\xd4\x37\x4b\xb5\x2f\xeb\xff\xe5\xcb\x49\x22\x35\xc9\xde\xd6\xe0\xde\x5b\xc8\x83\x7e\x06\xc9\x49\x88\xcd\xcd\x44\x48\x85\x2e\x47\x83\x90\x4b\x01\x03\x1d\x69\x79\xbd\x4e\x42\x81\xcb\x03\xfe\xa3\x2a\xf5\x78\x56\xef\xa7\x4d\x27\x28\x87\xfe\x82\x35\x29\xcf\x96\xb1\x91\xc9\xc0\x82\xb9\xda\x05\xdc\xac\x69\x5a\x61\x20\xa0\xce\xb5\xd6\xff\x9e\xc8\x40\x65\xd5\xf2\x8c\xe0\x92\xd7\x53\x90\x58\xdb\x7c\xa3\xff\x8d\x8f\x66\xf1\x0e\x9e\xd3\xd4\x8e\x62\xee\x51\x31\x92\xee\xce\xfe\xfa\x3e\xdf\x90\x79\x29\x87\x5b\x8c\x15\x2d\x62\xbe\x2c\x85\x55\xaf\x3e\xf2\x02\x3e\x36\x37\x12\x20\xa8\x7d\x12\xd9\x56\xbd\xf3\x81\x76\x4a\xcc\xac\xe4\xb2\xec\x46\xd2\x4e\xe8\x5e\x80\x4f\x98\x69\x8c\xbf\x9d\x5f\x85\x2d\xf1\x3b\x6f\xf1\xbd\xdc\x6d\x01\xad\xe5\x89\x4d\xd5\x45\xdb\x0c\x89\x15\x63\x2d\x72\xf6\x25\x50\xb5\xc8\xe0\xc6\xb2\xda\xc5\x38\x0f\xbc\x1c\x31\xe0\x74\x77\x12\x97\xdc\x65\xb5\xc1\x90\x96\x55\x86\x69\x9a\x32\xf1\xd2\xa4\x81\x13\x88\x6e\xbb\x03\x89\x99\x8e\x02\xd9\x46\x34\x92\x84\x6d\x4d\xcf\xbf\x2c\xfc\x27\x72\x3e\xf9\x3d\x78\xb3\x64\x3b\x00\xb8\xb5\x24\xe5\x54\x06\xc1\xb7\x57\x72\xce\x4d\xad\x15\xc5\x56\xa2\x49\xb0\x90\x43\x8a\x8f\x7d\x77\x67\x1f\xba\x7b\xa5\x7f\x7c\x67\x67\x3c\x71\x84\x6f\x8b\xef\x4d\x54\x80\xb5\xb7\xb0\xf6\x70\x40\x17\x78\x4b\x99\xc4\xd3\x94\x68\x6f\xdd\x1d\x9d\x67\xfd\x73\xec\x62\xcf\x62\xc2\x93\x47\x7a\x3a\x6d\x54\x7d\x53\x84\x8d\xd0\x54\x32\xe5\x48\xc9\xab\x8c\x97\xb7\x94\x7b\xbd\x50\x88\x89\x55\x67\xd5\x5c\x0e\x39\xd6\xda\x88\x7b\xa6\xcd\x09\xc7\x27\xfa\xfe\xdd\x85\x74\x6a\xed\xb4\xab\x9a\xf5\x25\xdc\xe7\xee\x57\x98\x7c\x8a\x85\x7e\xe8\xb5\x52\x34\x2a\xe9\x1d\x41\xd7\xd3\xa7\x09\x9f\xbb\xdb\x7b\xa6\xe7\x7d\x9d\x25\xe3\x7f\x0c\xb1\x67\x33\xa9\xaa\xf0\x16\x2c\x1d\xec\x91\x5e\xd8\xef\x19\x97\xfb\x9a\x60\x11\x03\xbc\x02\x65\x0b\xd5\x02\x78\x7c\x4a\x26\xeb\xba\xd4\x02\x3f\xdf\xcf\xee\x78\x23\xc9\x28\x70\x45\x90\x53\xed\x50\x99\x3c\xc4\xe9\xbd\xe4\xc0\x4a\xba\xef\xe3\xbb\x39\xa7\x58\x13\x20\x56\x0d\x41\xa6\x63\x1f\x49\x80\xa7\x23\x8f\x74\x8c\xf5\x9c\xce\x87\xb5\x62\x11\xbf\x10\xa0\xe6\xe6\x82\x9c\x56\xb3\xf4\x81\x22\xa5\xb8\xe2\x6c\xd1\x55\xd6\x79\x3c\x20\xc2\x26\x01\x4e\x0e\x48\x90\x14\x37\x8b\x10\xae\xcd\x5e\x69\x9e\x5e\x9b\xd4\x83\x09\x86\xae\x52\x9e\x7a\x77\xee\x73\x71\x75\x17\x30\x55\x4f\x83\x00\xed\x17\xfc\x0f\x53\x9e\xd2\xa3\xae\xef\x9c\x35\xc0\x60\x82\x6e\xd6\xc0\x5d\xcb\x31\x10\x98\xd3\xa0\xcd\xe0\xee\xcd\x52\xc4\xe3\x62\x99\xa8\xc6\x7e\xf5\xe5\xc0\x36\x3e\x07\x5a\x05\xd9\xa1\xea\x5c\x28\xbb\xd9\x86\x83\x1e\xe5\x2e\x95\xf5\xae\xcd\x81\x73\x52\x9e\x2e\xe4\x52\xd8\xe5\xdb\x26\x57\xc1\xa4\xa7\xcd\xc3\x2c\xfb\x50\x4b\xb8\x46\xff\xe0\xa2\xde\xe3\xaa\x03\xee\x1b\xc1\x29\xdb\x8a\x19\x4d\x10\xd2\x79\x2c\xcc\x10\xdd\xd9\x33\xad\x1e\x46\x11\x6e\x84\x38\xd3\x60\x3e\x95\x55\xab\xc4\x29\x07\x7f\x44\xa0\xad\x7f\x1c\x0a\xa8\x49\xb8\x56\x92\xf3\xde\x1d\x3f\x6a\xc6\x6d\x28\x53\x76\xdd\xb5\x03\x49\x91\xcb\xfd\xe4\xa1\x4b\x51\xd8\x89\xd9\x0c\x05\x94\x2e\xae\xce\xe9\xb7\x03\x5a\xa2\x99\xcc\xeb\xdf\x03\x7d\xfb\xfb\xf0\x6f\x13\x93\xfe\x3c\xbd\x2e\x19\xf3\x4b\xc7\x00\x91\x33\x30\x64\xfe\x9a\xe5\x95\x94\x4d\x54\x08\x42\x60\xd3\xc7\xeb\xb7\xe5\x36\xb2\xaa\x29\x9c\x5f\x83\x45\x07\xca\x48\xef\x63\x73\xdf\x82\x25\xe4\x1a\xb6\xde\x23\x4e\x81\xfc\xce\xaf\x16\xb2\x3c\xbb\x87\x3a\x88\x41\xd8\x8e\x93\x11\x43\x64\x96\xab\x91\xa0\x3a\x67\x22\xca\xb1\x11\x54\x53\x29\x32\x06\xae\x85\xdb\xb9\x1d\x32\xde\xe9\xa0\x91\x66\x26\x41\x5f\xb1\x79\x35\xc4\xc3\x39\xc8\xa3\x69\x45\xcb\x19\x01\xcf\xc4\xcf\xc7\x40\x1e\xe7\x0a\xca\x78\x48\x9e\x99\x61\x7b\xa3\xda\x39\xc6\xf8\xf5\x5f\xcd\xd3\x27\x4e\xff\x22\x7e\x5d\x22\x36\x13\x62\x6f\xbd\x12\x6c\x16\xed\x3b\xee\xf7\x1d\xab\x4b\xba\x15\x56\x60\x95\xe3\xb0\xf2\xfc\x4d\x78\xe4\xab\x47\xbc\xf9\x5d\x78\x2b\x3c\xa2\xb7\x3f\x6b\x5d\xf9\xdf\xc6\x42\x88\x8c\x3a\x73\xa2\xdc\xef\x5f\x57\x58\x14\xa0\x01\x9c\x9a\x95\xfc\x54\x8c\x06\x45\x87\x5e\x01\x37\x5c\xe1\x9b\xfb\x02\xf0\x36\x09\x71\x71\x7e\xa5\xc7\x8f\x69\xce\x66\x99\xe6\x37\xcf\x34\x50\x4e\x75\xba\x3a\x77\xb4\x7f\x80\xa9\x7e\x97\x71\x2e\xc0\x77\x31\xa5\x82\x1f\xb3\x2c\xb6\x9e\x09\x38\x84\x8b\xb7\x0e\xc3\xb2\xaa\x87\x9b\xb7\xcb\xea\xb9\x7b\x7b\xda\xe2\x11\x99\x00\xfc\x2f\x34\x3a\xde\x21\x7b\x2b\xb8\xd1\x26\xf3\x25\x43\x21\xda\x5c\x6e\x28\xfc\xba\xa2\x38\x17\xb5\xff\x9f\xd7\x00\x90\x2e\xb5\x03\xc3\x65\xb2\xbf\x52\x14\x5d\x3d\x7f\x07\x94\x93\x12\x4f\xbb\x00\xb0\xee\x00\xa4\x45\x1f\x48\x8b\x93\x7e\x76\xcc\x7c\x0c\xee\xbf\xb1\xf7\x48\xa8\xc8\x2d\xd0\x5b\xd5\xfa\x4d\xc2\x7a\x3a\x7a\x78\x87\xa5\xe7\x41\xfb\x60\xa1\x07\x0d\x27\xe1\x4e\xcf\xe9\xb8\x45\x5b\x6e\x5b\x4c\xb1\x9c\x6e\xd7\x48\x01\xf0\x89\x66\x20\x36\x19\x13\x08\x5d\xd6\x25\x72\x2a\x70\x39\xa3\x65\x56\x91\x33\x51\xdd\xae\xfc\x52\xc0\xf9\xd5\x11\xaa\x85\xd7\x86\xed\x68\xbb\x99\xed\x29\x05\xf3\x2d\xfe\xea\x8d\xb8\x05\x50\x32\x18\x71\x52\x7e\xbc\x4e\xa5\x09\x13\xee\x09\xf6\x4b\xcb\x09\x83\xa5\x0c\xbd\x21\xdd\x42\x5f\xeb\x4e\x0a\x2f\x58\x62\x13\x2d\x67\xb2\x5d\xed\x42\xeb\xf9\xc2\x51\xd6\xda\x10\x24\x2a\xb5\xf3\xf6\xe6\x29\x62\x0e\x4e\xa0\x1f\x1a\x5c\x4a\x57\x5a\xcc\x1f\x51\x0d\x75\x33\x5c\x12\x32\x20\x80\x09\x94\x75\x9a\xdc\x56\x98\x29\x83\x97\x9a\x58\x9a\x09\x4b\x90\x7e\xb5\x55\x99\xdf\xf9\xc7\x7c\xe3\x6b\x31\xaa\xfd\x1f\x32\x37\xe2\x5a\xfc\xf6\x60\x40\x64\x40\xa5\xe1\x62\x56\x39\xae\x7c\x4c\x3f\xe2\x28\xda\xd1\xbd\xab\xb0\x44\x32\x8f\x0a\x8e\x03\xb0\xe4\x05\xb1\xbe\xec\xca\xe2\xb3\xe3\x40\x23\x51\x69\xb7\x8f\x0f\xc9\xfa\xe0\x6d\x20\xfd\x14\x40\xd9\xa9\x2e\x60\xfe\x2f\xbf\x7e\xab\xea\xf0\x14\x58\xb2\x47\xc8\x50\xac\x90\xc0\xc8\xd3\xef\x50\xe5\x28\xac\xa6\x62\x13\x65\xef\x22\x4e\x55\x04\xdb\x0d\x42\x64\x3e\x8b\x1e\xf3\xa5\x89\x3e\x66\x90\x6d\xe9\x18\x18\xd8\x1c\xb8\x3b\xf1\x81\x30\xcb\x53\x4d\xfb\x97\x83\xed\x58\x16\x36\xe8\x55\xce\x90\x97\x5e\x67\x4b\xb8\x03\x4a\xe6\xca\xed\x3c\xc4\xf2\x18\x15\x1f\x1c\x71\x0b\x2a\x64\xd3\xb7\xdd\x34\x73\x44\x74\xb7\x20\x07\xef\x94\xbe\x65\x10\xce\x17\xb7\xc9\x68\xdd\x35\x8b\x47\x5f\xb7\xea\xd5\x2c\xef\xd9\xba\x1b\x93\x4a\xa1\x8d\x17\x88\x9a\x26\xe0\xf9\x4d\xca\xad\x09\x92\x29\x0b\x23\xc6\x80\x31\x15\x90\xeb\x1b\x41\xaf\xf8\x11\x24\x87\x9a\x73\x05\x62\xfd", 4093);
*(uint64_t*)0x200000a0 = 0xffd;
*(uint64_t*)0x200000a8 = 0;
*(uint64_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b8 = 0;
*(uint32_t*)0x200000bc = -1;
*(uint64_t*)0x20000390 = 0x20000200;
*(uint64_t*)0x20000200 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x2000020c = 0;
*(uint16_t*)0x20000210 = 5;
*(uint16_t*)0x20000212 = 9;
*(uint32_t*)0x20000214 = r[3];
*(uint64_t*)0x20000218 = 0;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0xebf8;
*(uint64_t*)0x20000230 = 0;
*(uint32_t*)0x20000238 = 6;
*(uint32_t*)0x2000023c = -1;
*(uint64_t*)0x20000398 = 0x20000280;
*(uint64_t*)0x20000280 = 0;
*(uint32_t*)0x20000288 = 0;
*(uint32_t*)0x2000028c = 0;
*(uint16_t*)0x20000290 = 8;
*(uint16_t*)0x20000292 = 0;
*(uint32_t*)0x20000294 = r[1];
*(uint64_t*)0x20000298 = 0x20000240;
memcpy((void*)0x20000240, "\x64\x4a\x5d\xa7\x55\x22\xad\x76\x7e\x32\x7d\x30\x21", 13);
*(uint64_t*)0x200002a0 = 0xd;
*(uint64_t*)0x200002a8 = 4;
*(uint64_t*)0x200002b0 = 0;
*(uint32_t*)0x200002b8 = 3;
*(uint32_t*)0x200002bc = -1;
*(uint64_t*)0x200003a0 = 0x20000340;
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint32_t*)0x2000034c = 0;
*(uint16_t*)0x20000350 = 5;
*(uint16_t*)0x20000352 = 0;
*(uint32_t*)0x20000354 = r[1];
*(uint64_t*)0x20000358 = 0;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 2;
*(uint64_t*)0x20000370 = 0;
*(uint32_t*)0x20000378 = 0;
*(uint32_t*)0x2000037c = -1;
	syscall(__NR_io_submit, r[0], 5ul, 0x20000380ul);
*(uint32_t*)0x20001144 = 0x963e;
*(uint32_t*)0x20001148 = 2;
*(uint32_t*)0x2000114c = 2;
*(uint32_t*)0x20001150 = 0;
*(uint32_t*)0x20001158 = -1;
memset((void*)0x2000115c, 0, 12);
	res = -1;
res = syz_io_uring_setup(0x2b93, 0x20001140, 0x20ffc000, 0x20ffb000, 0x200011c0, 0x20001200);
	if (res != -1)
		r[4] = res;
*(uint32_t*)0x20001244 = 0xc81f;
*(uint32_t*)0x20001248 = 2;
*(uint32_t*)0x2000124c = 0;
*(uint32_t*)0x20001250 = 0x9c;
*(uint32_t*)0x20001258 = r[4];
memset((void*)0x2000125c, 0, 12);
syz_io_uring_setup(0, 0x20001240, 0x20ffd000, 0x20ffc000, 0x200012c0, 0x20001300);
*(uint32_t*)0x20000444 = 0x4733;
*(uint32_t*)0x20000448 = 2;
*(uint32_t*)0x2000044c = 2;
*(uint32_t*)0x20000450 = 0x286;
*(uint32_t*)0x20000458 = r[4];
memset((void*)0x2000045c, 0, 12);
syz_io_uring_setup(0x73f8, 0x20000440, 0x20ffd000, 0x20ffc000, 0x200004c0, 0x20000500);
*(uint64_t*)0x20000680 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint32_t*)0x2000010c = 0;
*(uint16_t*)0x20000110 = 0;
*(uint16_t*)0x20000112 = 0;
*(uint32_t*)0x20000114 = r[1];
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint32_t*)0x2000013c = -1;
*(uint64_t*)0x20000688 = 0;
*(uint64_t*)0x20000690 = 0;
	syscall(__NR_io_submit, r[0], 3ul, 0x20000680ul);
	return 0;
}