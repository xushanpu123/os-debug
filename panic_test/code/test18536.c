// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000144 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0;
*(uint32_t*)0x20000150 = 0;
*(uint32_t*)0x20000158 = -1;
memset((void*)0x2000015c, 0, 12);
syz_io_uring_setup(0x689f, 0x20000140, 0x20ffa000, 0x20ffa000, 0, 0);
	res = syscall(__NR_pipe, 0x20000340ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000344;
*(uint64_t*)0x20000140 = 0x20000000;
memcpy((void*)0x20000000, "\x46\x7e\x87\x0e\x27\x36\xb5\x0d\x05\x6b\x14\x96\xab\x7c\x49\x7d\xdd\xdc\x15\x7c\x5c\x80\xc3\xdb\xb8\x5f\xa9\x3c\x45\xa3\x42\xde\x32\xc1\xc7\x1e\xb4\x47\xf0\xcb\x7c\x50\x63\xb0\x0d\x95\x83\x21\x74\xfe\xb6\x55\xd4\xe4\x22\xbc\xa4\x6d\x53\xdc\x6a\xb3\xc2\xa9\x88\x5d\x49\x32\x28\xba\x0e\xd9\x02\x8a\x90\x70\x0d\xa3\xd3\xd3\x9a\x6e\x8c\x1d\x8c\xbb\xd7\xbb\x42", 89);
*(uint64_t*)0x20000148 = 0x59;
*(uint64_t*)0x20000150 = 0x20000080;
memcpy((void*)0x20000080, "\x4a\x48\xeb\xa0\x1e\x7c\xc8\x61\x86\x47\x38\xbd\xdb\x42\x35\x43\x7c\x45\x8a\xcd\xc9\x22\xe8\x3b\x2e\x33\xda\x91\xcc\xda\x32\x61\x37\x39\x73\x79\x35\x62\x1b\x35\xfc\x49\xb3\x7c\x44\x87\xbe\xac\x3b\xb8\x83\xf3\x34\x49\x1e\xe6\x81\x48\x07\xdc\xc2\x17\x80\x27\x2e\x7f\x11\x84\xee\x0c\xd8\x46\x9b\x5a\xe0\x14\xa0\x9e\xb9\xab\xa7\x70\x98\x9d\x0f\xa8\xeb\x3b\x96\xe3\x7b\x0b\xc8\xd8\x65\x0c\x13\x4a\x5d\x0e\xb2\xd2\x09\x84\xb6\xd8\x17\x47\xb5\x30\x8a\x75\x89\x7d\xf2\x36\xbd\x4a\x03\x3e\x6c\x6d\x7e\x92\xf2\xb4", 126);
*(uint64_t*)0x20000158 = 0x7e;
*(uint64_t*)0x20000160 = 0x20000100;
memcpy((void*)0x20000100, "\xc7\xc1\x9d\xb7\xdb\x5c\xff\xd9\x7c\x19\x7d\x41\x10\xea\xdb\xd6\xb0\x94\x5b\xda\x45\xc2\x27\x04\x24\x5e", 26);
*(uint64_t*)0x20000168 = 0x1a;
	syscall(__NR_vmsplice, r[0], 0x20000140ul, 0x100000000000024ful, 2ul);
	return 0;
}