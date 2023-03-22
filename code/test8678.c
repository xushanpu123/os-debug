// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

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

static long syz_clone(volatile long flags, volatile long stack, volatile long stack_len,
		      volatile long ptid, volatile long ctid, volatile long tls)
{
	long sp = (stack + stack_len) & ~15;
	long ret = (long)syscall(__NR_clone, flags & ~CLONE_VM, sp, ptid, ctid, tls);
	return handle_clone_ret(ret);
}

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000000, "\x3e\x9e\x24\x03\x90\xdb\xa3\x30\xf2\x6b\x6d\x33\x02\x8c\xc3\x75\x9a\xc6\xce\x89\xed\x48\x14\x0e\xcf\x43\x6d\x38\xd7\x94\x52\x9e\x4d\xe5\xa0\x07\xbb\x48\xe3\x02\xbf\xc2\xcf\x97\xad\x0d\xdb\xe9\x85\xa0\x18\x81\xd7\x30\xf8\x2d\x96\x70\xf0\x25\x6a\x88\x69\x69\xfd\x20\x75\x6b\x76\x25\x8b\xed\x8b\x77\x0b\x9d\xf6\x8d\x89\xf0\x48\x24\x9c\xab\x05\x6a\x05\x33\x86\x96\x5c\xad\x9c\x4d\x76\x50\x56\xcb\xd9\x41\xe8\x6c\x61\xe5\x32\x86\x32\x9f\x0e\x89\xa1\xea\xec\xd6\xb0\xa4\xad\x30\x16\x38\x8d\xd3\x8d\xd4\x4c\x65\x92\xbe\xa6\x7f\x11\xfc\x2c\x4f", 134);
memcpy((void*)0x20000140, "\xd3\x1f\x76\xdc\x9a\xab\xac\x3d\x7e\xba\xe1\x06\xe2\xa8\x1e\x5c\x08\x59\x0e\x5e\x40\x26\x8d\xfb\xb1\xab\x9b\x62\x40\xc7\x17\x44\xc8\x37\x6d\x16\x11\x5e\xc2\x3a\x55\x60\x5e\xf0\x13\x8e\x6d\x58\x41\x08\x41\xdd\xa7\x74\xbe\x00\x89\xf8\xf6\x00\x38\x6e\x02\x72\xf7\xe0\xb4\x60\xcd\x5b\xd8\x53\xe9\xf7", 74);
syz_clone(0xc090a100, 0x20000000, 0x86, 0x200000c0, 0x20000100, 0x20000140);
*(uint64_t*)0x200006c0 = 0x20ffa000;
	syscall(__NR_move_pages, 0, 1ul, 0x200006c0ul, 0ul, 0x20000740ul, 0ul);
	return 0;
}