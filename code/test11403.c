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

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200002c0, "/dev/autofs\000", 12);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x200002c0ul, 0ul, 0ul);
	syscall(__NR_setsockopt, -1, 6, 0x21, 0ul, 0ul);
memcpy((void*)0x20000100, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
	syscall(__NR_ioctl, r[0], 0x4c81, 0ul);
	syscall(__NR_pipe2, 0ul, 0ul);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0ul, 0ul, 0ul);
memcpy((void*)0x20000000, "/proc/sysvipc/msg\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[1], 0xc0189377, 0ul);
*(uint32_t*)0x20000484 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint32_t*)0x2000048c = 0;
*(uint32_t*)0x20000490 = 0;
*(uint32_t*)0x20000498 = -1;
memset((void*)0x2000049c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0xacc, 0x20000480ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_mmap, 0x20ffb000ul, 0x1000ul, 0xcul, 0x10ul, r[2], 0x8000000ul);
	return 0;
}