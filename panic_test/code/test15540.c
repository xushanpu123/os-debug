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

#ifndef __NR_pkey_alloc
#define __NR_pkey_alloc 330
#endif
#ifndef __NR_pkey_mprotect
#define __NR_pkey_mprotect 329
#endif

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pkey_alloc, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_pkey_mprotect, 0x20000000ul, 0x4000ul, 0xbul, r[0]);
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x20001280 = 0;
	syscall(__NR_getsockopt, r[1], 6, 0x1f, 0ul, 0x20001280ul);
	return 0;
}
