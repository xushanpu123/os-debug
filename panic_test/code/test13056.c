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

#ifndef __NR_io_uring_enter
#define __NR_io_uring_enter 426
#endif

uint64_t r[4] = {0xffffffffffffffff, 0x0, 0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000a00, "/sys/power/pm_trace", 19);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000a00ul, 0x1439c2ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_mmap, 0x20ffd000ul, 0x3000ul, 0ul, 0x10ul, r[0], 0x10000000ul);
*(uint32_t*)0x20000040 = 4;
	syscall(__NR_getsockopt, r[0], 6, 0xa, 0x20000000ul, 0x20000040ul);
	syscall(__NR_shmget, 0ul, 0x2000ul, 0x800ul, 0x20ffe000ul);
	syscall(__NR_shmget, 0ul, 0x4000ul, 0x80ul, 0x20ffc000ul);
	res = syscall(__NR_shmget, 0ul, 0x1000ul, 0ul, 0x20ffe000ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_shmat, r[1], 0x20ffe000ul, 0x5800ul);
	res = syscall(__NR_shmget, 0ul, 0x1000ul, 0ul, 0x20ffe000ul);
	if (res != -1)
		r[2] = res;
	syscall(__NR_shmat, r[2], 0x20ffe000ul, 0x5800ul);
memcpy((void*)0x20000a00, "/sys/power/pm_trace", 19);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000a00ul, 0ul, 0ul);
	if (res != -1)
		r[3] = res;
	syscall(__NR_mmap, 0x20ffd000ul, 0x3000ul, 0ul, 0x10ul, r[3], 0x10000000ul);
*(uint64_t*)0x20000200 = 4;
	syscall(__NR_io_uring_enter, r[3], 0x7a1d, 0x4912, 1ul, 0x20000200ul, 8ul);
	syscall(__NR_shmat, r[2], 0x20ffc000ul, 0x4800ul);
	syscall(__NR_munmap, 0x20ffd000ul, 0x1000ul);
	syscall(__NR_madvise, 0x20ffd000ul, 0x3000ul, 9ul);
	return 0;
}
