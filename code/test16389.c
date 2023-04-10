// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

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
syz_open_dev(0, 0, 0x400202);
	syscall(__NR_gettid);
	res = syscall(__NR_getpid);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 0x80;
*(uint8_t*)0x200000c8 = 0;
*(uint8_t*)0x200000c9 = 0;
*(uint8_t*)0x200000ca = 0;
*(uint8_t*)0x200000cb = 0;
*(uint32_t*)0x200000cc = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 0, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 1, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 2, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 3, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 4, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 5, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 6, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 7, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 8, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 9, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 10, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 11, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 12, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 13, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 14, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 15, 2);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 17, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 18, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 19, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 20, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 21, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 22, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 23, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 24, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 25, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 26, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 27, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 28, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 29, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 30, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 31, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 32, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 33, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 34, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 35, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 36, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 37, 1);
STORE_BY_BITMASK(uint64_t, , 0x200000e8, 0, 38, 26);
*(uint32_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f4 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x2000011c = 0;
*(uint64_t*)0x20000120 = 0;
*(uint32_t*)0x20000128 = 0;
*(uint16_t*)0x2000012c = 0;
*(uint16_t*)0x2000012e = 0;
*(uint32_t*)0x20000130 = 0;
*(uint32_t*)0x20000134 = 0;
*(uint64_t*)0x20000138 = 0;
	syscall(__NR_perf_event_open, 0x200000c0ul, r[0], 0ul, -1, 0ul);
	syscall(__NR_getpid);
	syscall(__NR_perf_event_open, 0ul, 0, 0ul, -1, 0ul);
*(uint32_t*)0x20000684 = 0;
*(uint32_t*)0x20000688 = 0;
*(uint32_t*)0x2000068c = 0;
*(uint32_t*)0x20000690 = 0;
*(uint32_t*)0x20000698 = -1;
memset((void*)0x2000069c, 0, 12);
	res = -1;
res = syz_io_uring_setup(0x1126, 0x20000680, 0x20ff6000, 0x20ff3000, 0x20000700, 0x20000740);
	if (res != -1)
		r[1] = res;
	syscall(__NR_io_uring_register, r[1], 4ul, 0ul, 1ul);
	return 0;
}
