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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_getpid);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000340 = 0x20000300;
*(uint64_t*)0x20000348 = 5;
*(uint64_t*)0x20000600 = 0x20000380;
*(uint64_t*)0x20000608 = 0xc9;
	syscall(__NR_process_vm_readv, r[0], 0x20000340ul, 1ul, 0x20000600ul, 1ul, 0ul);
memcpy((void*)0x20000040, "\x3c\xb5\x75\x64\x4d\x78\xf3\x52\x73\xbc\x28\xc3\x20\x6c\x72\xda\x43\x03\x3b\x93\x10\xb6\x7a\xe0\xa2\x35\xc9\x98\x55\x3a\x40\x71\xce\x10\xa9\x81\x99\x17\xe5\x35\xcd\xf5\x47\x66\xe7\xcf\x51\xa0\xd8\x6b\x70\x75\x2f\x50\x46\xb4\x35\x5b\x69\x9f\x7e\x39\x96\xc3\x23\x0c\x9a\xb4\xcf\x08\x6a\x49\xd5\x0a\x2d\x36\x13\x50\xa5\x75\x5f\xf8\x8d\xd0\xe3\xd5\x41\x79\x20\xb0\x7e\x98\xb0\xf1\xe9\x64\x19\x63\x92\xa6\x25\x64\xc2\x03\x22\xe3\x2a\x5d\xac\x53\xc1\x45\xcf\x55\x8e\x0e\x6c\x5f\x90\xa1\x5c\xbb\x9b\xec\x4f\x11", 126);
memcpy((void*)0x20000140, "\x18\xef\xb1\x81\xf5\x6a\xe0\x01\xac\x13\xb2\x03\x6c\xad\x78\x26\x98\x5a\x7f\x98\xac\x70\xa2\x20\x8f\xb0\xab\x0d\xb8\x17\x06\x47\x3d\x46\x77\xf8\x0e\xe7\xc3\x89\xe5\xc7\x18\x5e\x44\xe0\x10\x08\x1f\x10\xce\x78\xbb\xf0\xf4\x18\x8f\x73\x1a\x99\x7b\xe0\xf8\x48\xd6\xd7\x48\xd4\xb1\x03\x21\x90\x7b\x39\xf9\x45\xcc\x43\x9b\xdf\xb7\x90\xe5\x6c\xdd\xe0\x74\xc5\x92\x9a\x95\x32\xc8\xcd\x39\x1a\xcd\x34\x32\x33\xf0\xaa\x24\x07\x03\xd9\x74\x29\x02\x7d\xb2\x21\x1e\xaf\x7c\x4e\x41\x73\x4e\xa1\x0f\x63\xb1\x02\xdf\x48\x62\x9f\x66\x84\x90\xd8\xcf\x16\xde\xcf\x1c\xa1\x8f\x97\xc9\xfc\x2e\x6a\xed\x2b\xe9\x82\x30\xb4\x7c\x9b\x11\x00\xcc\x85\x16\x13\x9f\xb5\x9c\x67\x17\x39\x99\x70\x1c\x7a\xc4\x53\xf2\x5a\xf9\x82\xdc\x34\xfd\x63\x08\x31\x2f\x0a\xba\x6f\xb8\x9c\x34\x7b\x13\x41\x11\x44\x0c\xd8\x53\x00\xb6\x26\x70\xf1\x4f\x44\x6c\xe2\x68\xe4\x9a\x02\x08\x04\x65\xb9\x13", 213);
syz_clone(0xc2822000, 0x20000040, 0x7e, 0x200000c0, 0, 0x20000140);
	return 0;
}