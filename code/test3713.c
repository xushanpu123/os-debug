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

uint64_t r[4] = {0xffffffffffffffff, 0x0, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000800, "./file0\000", 8);
	syscall(__NR_creat, 0x20000800ul, 0ul);
*(uint64_t*)0x20000240 = 0x1ec203000;
*(uint64_t*)0x20000248 = 0x20000000;
*(uint64_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint32_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint64_t*)0x20000270 = 0;
*(uint64_t*)0x20000278 = 0;
*(uint64_t*)0x20000280 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint32_t*)0x20000290 = -1;
syz_clone3(0x20000240, 0x58);
*(uint32_t*)0x20000184 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000198 = -1;
memset((void*)0x2000019c, 0, 12);
	res = -1;
res = syz_io_uring_setup(5, 0x20000180, 0x20ff5000, 0x20ffb000, 0x20000100, 0x20000140);
	if (res != -1) {
		r[0] = res;
r[1] = *(uint64_t*)0x20000100;
r[2] = *(uint64_t*)0x20000140;
	}
*(uint8_t*)0x200003c0 = 6;
*(uint8_t*)0x200003c1 = 0;
*(uint16_t*)0x200003c2 = 0;
*(uint32_t*)0x200003c4 = 4;
*(uint64_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0;
*(uint32_t*)0x200003d8 = 0;
*(uint16_t*)0x200003dc = 0;
*(uint16_t*)0x200003de = 0;
*(uint64_t*)0x200003e0 = 0;
*(uint16_t*)0x200003e8 = 0;
*(uint16_t*)0x200003ea = 0;
memset((void*)0x200003ec, 0, 20);
syz_io_uring_submit(r[1], r[2], 0x200003c0, 0);
	syscall(__NR_io_uring_enter, r[0], 0x7f59, 0, 0ul, 0ul, 0ul);
	res = syscall(__NR_msgget, 0ul, 0ul);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x200002c0 = 3;
memcpy((void*)0x200002c8, "\xee\xa3\x7d\xf3\x12\xcb\xf2\xed\x2a\x1b\x0b\x44\x24\x79\x7d\x43\x7c\x8d\x70\xe5\x08\xa5\x10\x40\x87\xb8\x7f\x11\x86\x31\x1f\x33\xc8\xd5\x69\xff\xa1\x16\xdb\xeb\x44\x74\xd0\x90\x44\xb1\x2c\x8c\xe1\x98\xa1\xcf\x65\xae\x32\x09\xdf\x6b\xff\x8e\x78\x24\xd2\xdb\x98\x88\x7d\x82\x21\x72\xf8\x24\x63\x1a\x3a\xcb\xdd\xb8\xdb\xe3\x62\xe6\x23\xfd\x62\xce\xf1\xe0\xb2\x67\x66\x9d\xa1\x6b\x3d\xb8\x0e\xb4\x80\x74\x47\x82\xbc\xd3\x2a\x5f\x8a\x7f\x48\x8b\xbf\x04\x73\xc5\x37\xc1\x92\xbc\xeb\x0a\x99\x07\xc4\x95\xdc\x79\xd9\xa7\x4c\xc0\x82\x6f\x0b\x44\x11\x0c\x2f\xcf\x12\x26\x93\x25\x8e\xbe\xe6\xc4\x55\x4f\x52\xf3\xb8\xeb\x1b\x9e\x36\xd3\xf5\x32\x25\x67\x7f\x0d\xfa\x2d\xe6\x63\xff\x15\x42\xd6\x04\xad\x34\x8c\xc6\xfa\x0b\xba\x2d\xfc\xa9\xf1\x23\x0a\x64\xc7\x19\x65\x4a\x10\x66\x7a\xb6\x8b\xb0\x6d\x4a\xc4\x64\xfc\x8d\xf8\xbb\xb6\xe0\x69\x83\xbd\xdf\x77\x5c\xed\xcb\x2c\xda\x10\x3e\x1a\xf9\xf3\x3f\x74\x80\xb5\x47\x62\x72\x38\x49\xd1\xf0\xd9\xb7\x65\x12\x99\xfb\x2f\x6f\x43\x5c\x75\xbb\xd5\x6e\x43\x17\x3a\x42\x0a\xef\x99\x59\x19\x66\x25\xbb\xe7\x7c\xcf\xc6\x96\x8a\x0f\xdf\x90\xd4\xeb\x68\xf9\xcf\x19\x1c\x1d\x41\xe6\xb6\x42\xfb\xd9\xcd\xa9\x60\x5a\xdb\x4e\x09\x53\x1a\x52\x5c\x3c\x94\xfe\x36\x71\x83\x96\x24\x5c\x1e\x63\x19\x43\xa5\xa0\xa6\x13\x94\x52\xec\x06\x41\x37\x49\xa2\x8f\x18\x41\x4c\x51\x12\xb2\x1b\x82\xd6\x47\x2e\x59\xb7\x21\x9f\x69\x7f\x4b\xb4\x39\xb2\x49\x91\x99\x0b\xf3\x82\x20\x3c\x38\x12\x93\x3e\x0e\x7d\x70\x52\xb4\x8b\xda\x7e\xbb\x22\x26\xc8\x4e\x2f\x92\xe5\x97\x53\x24\x40\xd3\x56\xcd\xd3\xaa\xd3\x8b\xac\x97\xde\xe9\xec\xb1\x70\x48\x19\x43\x08\x23\xff\x2a\x01\xb5\x92\x13\xe0\xfd\xc7\x0b\xea\xc5\x0a\xc8\x32\xdc\x35\xc3\x76\xab\xe8\x1c\xec\xb9\x31\xb3\x93\xb2\x31\xd2\xd5\x63\xc2\xc3\x8b\xb2\xfa\x82\xd2\x1b\x7a\x9a\xd4\x56\x87\xdb\x8c\x06\x90\xfd\x19\xe6\x2a\x26\x46\x88\xde\x1b\xf4\x38\xcd\x35\xb9\xf7\xf8\x5b\x32\x1f\x07\x3a\x0f\x82\xf9\xb2\x93\x93\xa6\xb0\xce\x84\xdb\x20\x7b\xcc\xa6\x99\x7a\x59\x85\x31\xba\x7f\x66\xec\xee\x32\x5e\x61\x92\xfa\x3b\xe0\x12\xb9\xeb\x35\x07\xe3\xe0\xe8\x7c\xde\xa4\x52\x5d\x7a\x51\x0a\x15\x80\x8d\x36\x23\x13\x72\x08\xbe\x63\xb7\x6e\x8d\xeb\x2f\xb9\xc7\x48\xf7\x19\xd4\xda\x17\xd8\xab\xd3\x8e\xe3\x48\xd1\x69\x33\x65\xe4\x25\xc5\x24\xc5\x78\x11\x36\x89\xee\xed\x61\x34\xee\x3e\x31\x15\xa2\x07\xb2\xca\x67\x1e\x5c\xb8\x2b\xb5\xfe\xc0\x6b\xd4\x3a\xfd\x2f\xec\x7e\x25\xcb\xbf\x2e\x3e\xed\xb5\x18\xa4\x43\x1c\x1f\x59\x58\xfa\x25\x14\x05\xca\x43\xa4\x6d\xf2\xdc\x36\xda\xdc\xcd\x9e\xbf\xe5\x39\x58\xb7\xa5\x5b\x5c\x8b\xf9\x1e\x9e\x2c\x80\x5d\x8b\x11\x81\x8a\x0b\xe0\x38\xbc\x31\xea\xbf\x43\xdb\xa6\xd9\xd5\x61\xb1\x19\x5f\x29\x8d\x3f\x74\x6c\xa8\xbe\xef\x48\x5c\x3c\xdc\x8f\x16\x78\x93\x08\xe9\xe8\xa9\xb6\x56\x08\x09\x6d\xb5\x21\x8c\x04\xd0\xa2\xa3\x72\x43\x8d\xea\xa4\xd5\x59\x27\x90\xe6\xb3\xf9\xa4\x94\x15\x16\x79\xd5\x2f\x34\xa3\x54\xa2\x75\xf2\x19\x98\x23\x3d\x59\x33\xa8\x89\xd6\xfb\x23\x0f\xc2\x63\x27\x78\x71\xa9\x6e\xd2\x47\xe3\x8e\xba\x6f\x8f\xc7\x76\xe2\x02\xf4\x39\xe4\x9d\x16\x88\x5c\xa1\xff\x53\x16\x15\xbc\x12\x95\xe7\x50\x4a\xde\xcd\x2d\xa0\xe7\x44\x17\x7e\xd4\xb5\x3f\xe1\xea\x4a\x7d\x31\x31\x0f\xd5\x45\xdf\x52\xb5\x15\xdd\x0e\xce\xdf\xdd\xb9\x94\x33\x7f\xfe\x3f\xa2\x46\x87\x42\xde\x41\x6f\xb1\xb0\x87\xc1\xd2\x55\x05\x95\x04\xd7\xae\x72\xcf\x5f\x8b\x84\x23\x6f\x38\x8b\x70\x40\x8c\x20\x13\xce\x67\xe2\xa4\x9b\x21\x65\xdc\x62\x63\xff\x2b\x7c\x2d\xe2\x7e\xa6\x95\x58\x4e\x14\x3c\xa0\x68\x2e\xa8\x05\x6d\x64\xd3\x05\xd0\x6a\x6d\x73\x48\xf4\xe1\xa1\x2d\x71\x56\x27\xf7\x22\x94\xdc\x76\x38\xc0\x7e\xb5\x0c\x90\xd4\x91\xd9\x2e\x7c\xd1\x6d\x0b\xc5\x45\xc7\x6e\xd8\x02\x57\x99\x9d\x5c\x9e\x57\x65\xc6\xc7\xfe\x87\x5c\xab\x95\x65\x9c\xdd\x67\x1c\xcc\xba\x67\x5c\x42\xda\xff\x02\xf8\x39\x7a\xf5\xbf\x00\xcf\xa0\xd4\xc6\x59\xaf\xff\x27\x91\xff\xcc\xf5\xd1\x63\xca\xa5\xbb\x05\x6b\x7f\xfd\x84\x62\xc0\x8e\x54\x8a\x0b\x50\x84\xdb\x56\xbc\xd4\x27\xf6\x98\x57\x7a\x63\xc8\xf8\x47\x38\xb2\x12\x85\x68\x2d\x61\x09\xb3\x5f\x77\xc9\x3d\x40\x49\x2a\x09\xd4\xad\x57\xe9\x5c\x2c\xc9\xf6\xb9\x96\xef\xd4\x10\x4f\x93\x5a\x84\xb7\x2b\xa7\xfd\x78\xb2\xc6\xa0\xe3\xb8\x87\x4d\xc5\x9b\xdd\x94\x46\x66\x0a\x1c\x48\xf2\xf1\xd6\x0c\x93\x38", 1017);
	syscall(__NR_msgsnd, r[3], 0x200002c0ul, 0x401ul, 0ul);
	return 0;
}
