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

#ifndef __NR_mlock2
#define __NR_mlock2 325
#endif
#ifndef __NR_pkey_alloc
#define __NR_pkey_alloc 330
#endif
#ifndef __NR_pkey_mprotect
#define __NR_pkey_mprotect 329
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	syscall(__NR_mmap, 0x20c7a000ul, 0x4000ul, 0ul, 0x132ul, -1, 0x8000000ul);
	syscall(__NR_mlock2, 0x20c7b000ul, 0x3000ul, 0ul);
	res = syscall(__NR_pkey_alloc, 0ul, 1ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_pkey_mprotect, 0x20c7c000ul, 0x4000ul, 0x1000002ul, r[0]);
	return 0;
}
