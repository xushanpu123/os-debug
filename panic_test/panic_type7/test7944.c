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

uint64_t r[4] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_mmap, 0x20000000ul, 0x2000ul, 0x2000004ul, 0x32ul, -1, 0ul);
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 0;
	syscall(__NR_getsockopt, r[0], 6, 0xd, 0ul, 0x20000100ul);
*(uint32_t*)0x20000080 = 1;
*(uint32_t*)0x20000084 = 1;
*(uint32_t*)0x20000088 = 0x18;
*(uint32_t*)0x2000008c = r[0];
*(uint32_t*)0x20000090 = 9;
memcpy((void*)0x20000098, "./file0\000", 8);
	res = syscall(__NR_ioctl, -1, 0xc0189376, 0x20000080ul);
	if (res != -1)
r[1] = *(uint32_t*)0x2000008c;
	res = -1;
res = syz_clone(0, 0, 0, 0, 0, 0);
	if (res != -1)
		r[2] = res;
	syscall(__NR_ptrace, 0x10ul, r[2], 0, 0);
*(uint64_t*)0x20001800 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x10;
*(uint16_t*)0x200000c2 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0x20;
*(uint32_t*)0x20001808 = 0xc;
*(uint64_t*)0x20001810 = 0x200017c0;
*(uint64_t*)0x200017c0 = 0;
*(uint64_t*)0x200017c8 = 0;
*(uint64_t*)0x20001818 = 1;
*(uint64_t*)0x20001820 = 0;
*(uint64_t*)0x20001828 = 0;
*(uint32_t*)0x20001830 = 0x44000;
	syscall(__NR_sendmsg, r[1], 0x20001800ul, 1ul);
	res = -1;
res = syz_clone(0, 0, 0, 0, 0, 0);
	if (res != -1)
		r[3] = res;
	syscall(__NR_ptrace, 0x10ul, r[3], 0, 0);
	syscall(__NR_ptrace, 0x4208ul, r[3], 0, 0);
	syscall(__NR_ptrace, 4ul, r[3], 0x20001840ul, 0ul);
memcpy((void*)0x20000000, "pim6reg1\000\000\000\000\000\000\000\000", 16);
*(uint32_t*)0x20000010 = 0x10001;
	syscall(__NR_ioctl, -1, 0x8937, 0x20000000ul);
	return 0;
}
