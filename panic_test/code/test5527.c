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

#ifndef __NR_fsconfig
#define __NR_fsconfig 431
#endif
#ifndef __NR_fspick
#define __NR_fspick 433
#endif

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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

syz_open_dev(0, 0, 0);
	syscall(__NR_fsconfig, -1, 2ul, 0ul, 0ul, 0ul);
	syscall(__NR_gettid);
	syscall(__NR_gettid);
	syscall(__NR_sched_rr_get_interval, 0, 0ul);
memcpy((void*)0x20000240, "\xeb\x61\x7d\x63\xa1\xfd\x62\xb6\x18\x58\x3c\x13\x04\xb2\x36\x11\xc8\xb7\xed\x7f\x1c\xd9\x17\x0c\x72\x3e\xc5\x31\xa3\xc4\x77\x7a\x57\xb1\x24\x49\x30\x75\x9e\xdc\x7c\xbf\x49\xa1\x1d\xe9\xb1\xfa\xac\xee\x4c\x47\xe7\xe9\xb9\x5c\x97\x00\xa5\x3d\x1d\x1b\xff\xfd\x4c\xab\x49\x43\x4f\x67\x9b\xb6\x07\x1c\xee\xe8\x92\x58\x58\x56\x1d\xd0\xb4\xc4\xe6\x52\xc4\x6a\x9d\x19\xf8\x1d\x3f\xb3\x97\x19\x9e\xc2\xd9\x8a\x17\xb6\xe1\xca\xc6\xc8\xaa\xe5\x3f\x74\xfe\xc0\x82\x14\x9d\x3b\x26\x59\x1b\xd6\x0f\xb6\x88\x5b\xb0", 125);
memcpy((void*)0x20000340, "\xfe\x28\x75\x7f\x07\xed\x81\xda\x3d\x99\xc1\x6b\x9b\xc2\x16\xcf\x7f\xab\xb8\x9a\xd1\xe9\x8e\xb4\xac\x72\xac\x9c\xf6\x71\xdc\xf6\x0e\x35\xbf\x8f\xeb\x6d\x1a\xa7\x53\xac\x5b\xf5\xf2\xf1\x0d\x42\x44\x03\x8f\xbc\x84\x14\x8a\x51\x19\xab\xfe\x6c\xb3\xe2\x85\x15\x7b\x24\xc5\xd7\x7c\xa8\xcd\xbf\x74\x91\x8e\xa0\x97\x91\x8a\x5d\xab\x02\x84\x5f\x0e\x1a\xa2\x17\x38\xb9\xf1\xe6\xd1\x55\xd9\x9d\xe1\x40\x8a\xa6\xe0", 101);
syz_clone(0xc0000000, 0x20000240, 0x7d, 0, 0x200001c0, 0x20000340);
	syscall(__NR_fspick, -1, 0ul, 0ul);
	syscall(__NR_getresuid, 0ul, 0x20000540ul, 0x20000580ul);
syz_clone(0x20000, 0x200005c0, 0, 0, 0x200006c0, 0x20000700);
syz_open_dev(0, 0, 0);
	syscall(__NR_sendmsg, -1, 0ul, 0ul);
	return 0;
}
