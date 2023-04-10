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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000380, "\x0e\x6f\x98\x63\x70\xb3\x18\xdf\x38\x15\x05\xfb\xf4\x05\xb4\x76\x32\xc2\xf8\xf8\xaa\x68\x26\xaa\xfc\x01\xb7\x33\xc4\x14\xd9\x75\xfe\xce\xce\xde\xbc\x52\x71\xa1\xa7\xc2\x35\x5f\x42\x92\x3f\x05\xa6\x90\xae\x69\xb9\x5a\x7e\xc8\xa8\xbe\x46\x86\xec\x5c\x74\x8d\xee\x54\xde\xb2\x2c\x14\xe1\x03\xe0\x89\x5a\x39\x33\x31\xdd\x61\x10\xb7\x49\xd5\x1b\x58\x42\x37\xe5\xa5\x3d\x17\xc2\xc0\x68\x58\x38\xb4\xd1\x8f\x1c\xb2\x97\x2a\xc0\xff\x74\x5f\x6b\x8d\xf8\x88\xc3\xc9\xa0\xfc\x14\x43\xc5\x34\x01\xd5\xbb\x51\x0a", 125);
memcpy((void*)0x20000100, "\x75\x6e\xe1\x58\x28\xf9\x16\xd5\xd6\xd1\xd2\xb2\x5a\xe1\x00\x97\x52\x79\xe7\xbd\x48\xa9\x8c\x1d\xe1\x34\x87\x92\x04\x8f\xc7\x91\xd2\x38\x34\xe4\xa7\xde\xe7\xde\xdb\x73\x22\x1a\x12\xcc\xf8\x63\x11\x9d\xf2\x0a\x44\xc2\xc2\xe6\x14\x00\xe5\x96\xc1\xf8\xc2\xb1\xe0\x73\x7c\xf7\xf1\xae\x61\x4f\x87\x9d\xc2\x4f\x8f\x55\x88\xd7\x94\x96\x65\x69\xc4\x7b\xfd\x70\x44\x20\x71\xc0\xac\x51\xba\x4a\xee\xfb\x3e\x20\xfe\x59\x5d\x63\xe6\x3a\xb9\xca\xa8\x20\xf7\x9f\xaa\xc3\x26\x80\xc4", 117);
syz_clone(0x41000400, 0x20000380, 0x7d, 0x20000080, 0x20000000, 0x20000100);
memcpy((void*)0x20000080, "/dev/null\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200000c0, "net_prio.ifpriomap\000", 19);
	syscall(__NR_openat, r[0], 0x200000c0ul, 2ul, 0ul);
*(uint32_t*)0x20000340 = 0xed;
	syscall(__NR_getsockopt, r[0], 6, 0x1f, 0x20000240ul, 0x20000340ul);
	return 0;
}