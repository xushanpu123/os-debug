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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_setsockopt, -1, 6, 0, 0ul, 0ul);
memcpy((void*)0x200001c0, "/dev/loop-control\000", 18);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200001c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_ioctl, -1, 0x4c80, 0xaul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_ioctl, r[0], 0x4c80, r[1]);
memcpy((void*)0x20000080, "/dev/loop-control\000", 18);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000080ul, 0ul, 0ul);
	return 0;
}
