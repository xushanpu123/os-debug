// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

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
memcpy((void*)0x20001480, "\x44\xd5\xa4\xea\xd8\x47\x5e\x61\x0f\xd4\x32\xfb\x8b\x8d\xc9\x19\x0f\x01\x8a\xc3\x50\x00\xe5\x2f\x3d\xa7\x5e\x50\x3c\x8f\x79\x7e\xa6\xba\xcd\x9f\x32\x52\x34\xc3\xf5\xfe\xc2\xc4\x8f\x1b\x34\x00\xd6\x7f\x9c\xd5\x8d\x06\x45\x80\x9f\x68\x9f\x6c\x46\x4e\xd9\xda\x1f\x27\x2a\xbd\xac\x78\x66\x45\xec\x99\x43\x91\x3b\x4e\x8d\xfb\xad\x21\xcc\xa4\x35\xdc\x64\xfd\x01\xa9\x8c\x8c\xe4\xb6\x1a\x0d\xb9\x63\x44\x87\x20\x29\x8f\x98\xe4\x8d\x15\x48\x5e\x23\x18\x16\xc6\xf5\x7d\xd9\x10\x16\xa5\xb6\x8a\x09\x8a\x1b\x3d", 125);
syz_clone(0, 0, 0, 0, 0, 0x20001480);
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 7;
*(uint8_t*)0x20000004 = 0x79;
*(uint16_t*)0x20000005 = 0;
	syscall(__NR_write, r[0], 0x20000000ul, 0xff64ul);
	return 0;
}