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

#ifndef __NR_fsconfig
#define __NR_fsconfig 431
#endif
#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20001404 = 0;
*(uint32_t*)0x20001408 = 0;
*(uint32_t*)0x2000140c = 0;
*(uint32_t*)0x20001410 = 0;
*(uint32_t*)0x20001418 = -1;
memset((void*)0x2000141c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x1616, 0x20001400ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "/dev/hwrng\000", 11);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x200080ul, 0ul);
	if (res != -1)
		r[1] = res;
memset((void*)0x20000040, 0, 1);
	syscall(__NR_fsconfig, r[1], 5ul, 0x20000040ul, 0ul, r[0]);
	return 0;
}
