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

#ifndef __NR_pidfd_getfd
#define __NR_pidfd_getfd 438
#endif
#ifndef __NR_pidfd_open
#define __NR_pidfd_open 434
#endif

uint64_t r[3] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_getpgid, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_pidfd_open, r[0], 0ul);
	if (res != -1)
		r[1] = res;
	res = syscall(__NR_pidfd_getfd, r[1], r[1], 0ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_setns, r[2], 0x40000000ul);
	return 0;
}
