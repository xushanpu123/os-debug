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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint64_t*)0x20000480 = 0;
*(uint32_t*)0x20000488 = 0;
*(uint64_t*)0x20000490 = 0;
*(uint64_t*)0x20000498 = 1;
*(uint64_t*)0x200004a0 = 0;
*(uint64_t*)0x200004a8 = 0;
*(uint32_t*)0x200004b0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000480ul, 0ul);
	syscall(__NR_madvise, 0x20ffc000ul, 0x4000ul, 0x10ul);
	syscall(__NR_pkey_mprotect, 0x20fff000ul, 0x1000ul, 0ul, -1);
	syscall(__NR_pkey_mprotect, 0x20ffd000ul, 0x2000ul, 0ul, -1);
	res = syscall(__NR_pkey_alloc, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_pkey_mprotect, 0x20ffb000ul, 0x3000ul, 0ul, r[0]);
	return 0;
}
