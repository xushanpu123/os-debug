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

#ifndef __NR_io_uring_enter
#define __NR_io_uring_enter 426
#endif
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

static long syz_io_uring_submit(volatile long a0, volatile long a1, volatile long a2, volatile long a3)
{
	char* ring_ptr = (char*)a0;
	char* sqes_ptr = (char*)a1;
	char* sqe = (char*)a2;
	uint32_t sqes_index = (uint32_t)a3;
	uint32_t sq_ring_entries = *(uint32_t*)(ring_ptr + SQ_RING_ENTRIES_OFFSET);
	uint32_t cq_ring_entries = *(uint32_t*)(ring_ptr + CQ_RING_ENTRIES_OFFSET);
	uint32_t sq_array_off = (CQ_CQES_OFFSET + cq_ring_entries * SIZEOF_IO_URING_CQE + 63) & ~63;
	if (sq_ring_entries)
		sqes_index %= sq_ring_entries;
	char* sqe_dest = sqes_ptr + sqes_index * SIZEOF_IO_URING_SQE;
	memcpy(sqe_dest, sqe, SIZEOF_IO_URING_SQE);
	uint32_t sq_ring_mask = *(uint32_t*)(ring_ptr + SQ_RING_MASK_OFFSET);
	uint32_t* sq_tail_ptr = (uint32_t*)(ring_ptr + SQ_TAIL_OFFSET);
	uint32_t sq_tail = *sq_tail_ptr & sq_ring_mask;
	uint32_t sq_tail_next = *sq_tail_ptr + 1;
	uint32_t* sq_array = (uint32_t*)(ring_ptr + sq_array_off);
	*(sq_array + sq_tail) = sqes_index;
	__atomic_store_n(sq_tail_ptr, sq_tail_next, __ATOMIC_RELEASE);
	return 0;
}

uint64_t r[5] = {0xffffffffffffffff, 0x0, 0x0, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = 0;
memset((void*)0x2000009c, 0, 12);
	res = -1;
res = syz_io_uring_setup(0x1203, 0x20000080, 0x200a0000, 0x200b0000, 0x20000100, 0x20000140);
	if (res != -1) {
		r[0] = res;
r[1] = *(uint64_t*)0x20000100;
r[2] = *(uint64_t*)0x20000140;
	}
*(uint8_t*)0x200001c0 = 0x1b;
*(uint8_t*)0x200001c1 = 0;
*(uint16_t*)0x200001c2 = 0;
*(uint32_t*)0x200001c4 = -1;
*(uint64_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0;
*(uint32_t*)0x200001d8 = 0;
*(uint32_t*)0x200001dc = 0;
*(uint64_t*)0x200001e0 = 0;
*(uint16_t*)0x200001e8 = 0;
*(uint16_t*)0x200001ea = 0;
memset((void*)0x200001ec, 0, 20);
syz_io_uring_submit(r[1], r[2], 0x200001c0, 0);
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = -1;
memset((void*)0x2000009c, 0, 12);
	res = -1;
res = syz_io_uring_setup(1, 0x20000080, 0x20ffc000, 0x20ffd000, 0x20000100, 0x20000000);
	if (res != -1)
r[3] = *(uint64_t*)0x20000100;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[4] = res;
*(uint8_t*)0x20000200 = 0x10;
*(uint8_t*)0x20000201 = 0;
*(uint16_t*)0x20000202 = 0;
*(uint32_t*)0x20000204 = r[4];
*(uint32_t*)0x20000208 = 0x80;
*(uint64_t*)0x20000210 = 0x20000000;
*(uint16_t*)0x20000000 = 9;
memset((void*)0x20000002, 204, 14);
*(uint8_t*)0x20000010 = 0x22;
*(uint8_t*)0x20000011 = 0;
*(uint32_t*)0x20000218 = 0;
*(uint32_t*)0x2000021c = 0;
*(uint64_t*)0x20000220 = 0;
*(uint16_t*)0x20000228 = 0;
*(uint16_t*)0x2000022a = 0;
memset((void*)0x2000022c, 0, 20);
syz_io_uring_submit(r[3], r[2], 0x20000200, 0);
	syscall(__NR_io_uring_enter, r[0], 0x42cc, 0, 0ul, 0ul, 0ul);
	return 0;
}
