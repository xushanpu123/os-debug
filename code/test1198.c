// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

static long syz_open_procfs(volatile long a0, volatile long a1)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	if (a0 == 0) {
		snprintf(buf, sizeof(buf), "/proc/self/%s", (char*)a1);
	} else if (a0 == -1) {
		snprintf(buf, sizeof(buf), "/proc/thread-self/%s", (char*)a1);
	} else {
		snprintf(buf, sizeof(buf), "/proc/self/task/%d/%s", (int)a0, (char*)a1);
	}
	int fd = open(buf, O_RDWR);
	if (fd == -1)
		fd = open(buf, O_RDONLY);
	return fd;
}

uint64_t r[7] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "ns/time_for_children\000", 21);
	res = -1;
res = syz_open_procfs(-1, 0x200000c0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "trusted.overlay.nlink\000", 22);
	syscall(__NR_fsetxattr, r[0], 0x20000080ul, 0ul, 0ul, 0ul);
	res = syscall(__NR_getpid);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000040, "./cgroup/cgroup.procs\000", 22);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 2ul, 8ul);
	if (res != -1)
		r[2] = res;
	res = syscall(__NR_pipe2, 0x20000300ul, 0x80ul);
	if (res != -1) {
r[3] = *(uint32_t*)0x20000300;
r[4] = *(uint32_t*)0x20000304;
	}
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0x1fful);
	if (res != -1)
		r[5] = res;
memset((void*)0x20000080, 1, 4);
	syscall(__NR_write, r[5], 0x20000080ul, 4ul);
	syscall(__NR_read, r[5], 0x200000c0ul, 4ul);
	syscall(__NR_close, r[5]);
	res = syscall(__NR_dup2, r[4], r[5]);
	if (res != -1)
		r[6] = res;
	syscall(__NR_read, r[2], 0x20000080ul, 1ul);
memcpy((void*)0x20000340, "trusted.overlay.origin\000", 23);
memcpy((void*)0x20000380, "y\000", 2);
	syscall(__NR_fsetxattr, r[3], 0x20000340ul, 0x20000380ul, 2ul, 2ul);
sprintf((char*)0x200000c0, "0x%016llx", (long long)r[1]);
	syscall(__NR_write, r[2], 0x200000c0ul, 0x12ul);
*(uint64_t*)0x200003c0 = 5;
*(uint64_t*)0x200003c8 = 4;
*(uint64_t*)0x200003d0 = 4;
*(uint64_t*)0x200003d8 = 6;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0x567c;
*(uint64_t*)0x200003f0 = 0x4000;
*(uint64_t*)0x200003f8 = 0x2bfb;
*(uint64_t*)0x20000400 = 8;
*(uint64_t*)0x20000408 = 5;
*(uint64_t*)0x20000410 = 0x83;
*(uint64_t*)0x20000418 = 7;
*(uint32_t*)0x20000420 = 0xf;
*(uint32_t*)0x20000424 = 1;
*(uint64_t*)0x20000428 = 4;
*(uint64_t*)0x20000430 = 1;
*(uint64_t*)0x20000438 = 1;
*(uint64_t*)0x20000440 = 0x200;
*(uint64_t*)0x20000448 = 0xfff;
*(uint64_t*)0x20000450 = 0x1ff;
*(uint64_t*)0x20000458 = 0xffffffff;
*(uint64_t*)0x20000460 = 1;
*(uint64_t*)0x20000468 = 0;
*(uint64_t*)0x20000470 = 5;
*(uint64_t*)0x20000478 = 0xb0e;
*(uint64_t*)0x20000480 = 0xfffffffffffffffb;
*(uint64_t*)0x20000488 = 3;
*(uint64_t*)0x20000490 = 0x7fffffff;
*(uint64_t*)0x20000498 = 9;
*(uint64_t*)0x200004a0 = -1;
*(uint32_t*)0x200004a8 = 8;
*(uint32_t*)0x200004ac = 0x1c8b;
*(uint64_t*)0x200004b0 = 7;
*(uint64_t*)0x200004b8 = 0x400;
*(uint64_t*)0x200004c0 = 9;
*(uint64_t*)0x200004c8 = 8;
*(uint64_t*)0x200004d0 = 0x1000;
*(uint64_t*)0x200004d8 = 0xfffffffffffffff9;
*(uint64_t*)0x200004e0 = 0x401;
*(uint64_t*)0x200004e8 = 0;
*(uint64_t*)0x200004f0 = 0;
*(uint64_t*)0x200004f8 = 0xffffffffffff3c86;
*(uint64_t*)0x20000500 = 2;
*(uint64_t*)0x20000508 = 9;
*(uint64_t*)0x20000510 = 0x396a;
*(uint64_t*)0x20000518 = 0x40;
*(uint64_t*)0x20000520 = 0;
*(uint64_t*)0x20000528 = 0x1ff;
*(uint32_t*)0x20000530 = 0x3ff;
*(uint32_t*)0x20000534 = 0x400;
*(uint64_t*)0x20000538 = 0xc7d6;
*(uint64_t*)0x20000540 = 3;
*(uint64_t*)0x20000548 = 0xdea6;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0xfffffffffffffffe;
*(uint64_t*)0x20000560 = 0x80000001;
*(uint64_t*)0x20000568 = 8;
*(uint64_t*)0x20000570 = 7;
*(uint64_t*)0x20000578 = 0x2000000000000;
memset((void*)0x20000580, 0, 576);
	syscall(__NR_ioctl, r[6], 0xc4009420, 0x200003c0ul);
*(uint64_t*)0x20000140 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0x400000;
*(uint32_t*)0x20000148 = 0xc;
*(uint64_t*)0x20000150 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20000200;
memcpy((void*)0x20000200, "@\000\000\000", 4);
*(uint16_t*)0x20000204 = 0;
memcpy((void*)0x20000206, "\x10\x00\x2b\xbd\x70\x00\xfe\xdb\xdf\x25\x31\x00\x00\x00\x08\x00\x01\x00\x0e\x00\x00\x00\x08\x00\x52\x00", 26);
*(uint32_t*)0x20000220 = r[1];
memcpy((void*)0x20000224, "\x08\x00\x01\x00\x78\x00\x00\x00\x0c\x00\x99\x00\x4d\xaa\x00\x00\x46\x00\x00\x00\x08\x00\xdb\x00", 24);
*(uint32_t*)0x2000023c = r[2];
memcpy((void*)0x20000240, "\xb9\xdd\x17\x96\x58\x34\xf6\xe0\xa5\xc1\xaa\x74\x82\x98\xd7\x2e\xe5\x6d\x0d\x55\x69\x3b\x41\xad\xc6\x6c\x66\xbc\x7e\x27\xe0\x2f\x46\x49\xf9\xf7\x91\x8a\x66\x74\x5a\xf3\x25\xc5\x02\xe0\xac\x63\x22\xb8\x17\x48\x2c\x6b\x5e\x10\xbe\x3a\xb8\x39\xd3\x3b\x85\xaf\xf1\xfa\x95\x87\x6a\x24\xf1\xc6\xe0\xea\x0c\xe7\x46\x7e\xa0\xbc\x3e\x17\x32\xfb\x48\xb7\x60\xe1\x04\xee\xfe\xe6\xbc\x03\x2e\x99\x60\xce\x46\x4e\xf6\xc1\x21\xd4\x4e\xdb\x27\x1f\x8d\xbd\xdc\xeb\x19\xa4\x03\x1f\x2e\x98\xd1\xf9\x98\x74\x89\xa8\x54\xdb\xa2\x40\x70\xdc\x52\x63\x73\xc9\x88\x27\x50\xb1\xac\xfa\x38\x5b\x72\x7a\x20\xd0\xe9\xd6\x7c\x31\x0d\x79\xb0\x01\x37\x8f\xc7\x54\x68\x00\x08\x7d\x49\x7f\x9c\x87\xae\x6e\xa4\x14\xde\x40", 172);
*(uint64_t*)0x20000108 = 0x40;
*(uint64_t*)0x20000158 = 1;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint32_t*)0x20000170 = 0x37ec34d9;
	syscall(__NR_sendmsg, -1, 0x20000140ul, 0x80ul);
memcpy((void*)0x20000180, "trusted.overlay.redirect\000", 25);
memcpy((void*)0x200001c0, "./cgroup/cgroup.procs\000", 22);
	syscall(__NR_fsetxattr, r[2], 0x20000180ul, 0x200001c0ul, 0x16ul, 1ul);
	return 0;
}
