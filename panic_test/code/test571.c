// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint8_t*)0x20000700 = 9;
*(uint8_t*)0x20000701 = 0;
*(uint16_t*)0x20000702 = 0;
*(uint32_t*)0x20000704 = -1;
*(uint64_t*)0x20000708 = 0;
*(uint64_t*)0x20000710 = 0x200006c0;
*(uint64_t*)0x200006c0 = 0;
*(uint32_t*)0x200006c8 = 0;
*(uint64_t*)0x200006d0 = 0x20000440;
*(uint64_t*)0x20000440 = 0x20000140;
memset((void*)0x20000140, 87, 1);
*(uint64_t*)0x20000448 = 1;
*(uint64_t*)0x200006d8 = 1;
*(uint64_t*)0x200006e0 = 0;
*(uint64_t*)0x200006e8 = 0x1d8;
*(uint32_t*)0x200006f0 = 0;
*(uint32_t*)0x20000718 = 0;
*(uint32_t*)0x2000071c = 0;
*(uint64_t*)0x20000720 = 0;
*(uint16_t*)0x20000728 = 0;
*(uint16_t*)0x2000072a = 0;
memset((void*)0x2000072c, 0, 20);
syz_io_uring_submit(0, 0, 0x20000700, 0);
*(uint32_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c4 = 0xd7;
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
	syscall(__NR_perf_event_open, 0x200000c0ul, 0, 0ul, -1, 0ul);
	return 0;
}
