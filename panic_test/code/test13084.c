// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/sched.h>

#ifndef __NR_clone3
#define __NR_clone3 435
#endif
#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
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

#define USLEEP_FORKED_CHILD (3 * 50 *1000)

static long handle_clone_ret(long ret)
{
	if (ret != 0) {
		return ret;
	}
	usleep(USLEEP_FORKED_CHILD);
	syscall(__NR_exit, 0);
	while (1) {
	}
}

#define MAX_CLONE_ARGS_BYTES 256
static long syz_clone3(volatile long a0, volatile long a1)
{
	unsigned long copy_size = a1;
	if (copy_size < sizeof(uint64_t) || copy_size > MAX_CLONE_ARGS_BYTES)
		return -1;
	char clone_args[MAX_CLONE_ARGS_BYTES];
	memcpy(&clone_args, (void*)a0, copy_size);
	uint64_t* flags = (uint64_t*)&clone_args;
	*flags &= ~CLONE_VM;
	return handle_clone_ret((long)syscall(__NR_clone3, &clone_args, copy_size));
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
*(uint64_t*)0x20000298 = 0;
*(uint32_t*)0x200002a0 = 7;
*(uint64_t*)0x200002a8 = 0x20000180;
*(uint64_t*)0x200002b0 = 0x10;
*(uint64_t*)0x200002b8 = 0;
*(uint64_t*)0x200002c0 = 0;
*(uint64_t*)0x200002c8 = 0;
*(uint32_t*)0x200002d0 = -1;
syz_clone3(0x20000280, 0x58);
	syscall(__NR_getpid);
*(uint32_t*)0x20000684 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
*(uint32_t*)0x20000690 = 0;
*(uint32_t*)0x20000698 = -1;
memset((void*)0x2000069c, 0, 12);
	res = -1;
res = syz_io_uring_setup(0x1126, 0x20000680, 0x20ff6000, 0x20ff3000, 0x20000700, 0x20000740);
	if (res != -1)
		r[0] = res;
	syscall(__NR_io_uring_register, r[0], 4ul, 0ul, 1ul);
	return 0;
}
