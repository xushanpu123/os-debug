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
#ifndef __NR_pkey_mprotect
#define __NR_pkey_mprotect 329
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_pkey_mprotect, 0x20ffc000ul, 0x4000ul, 4ul, -1);
	syscall(__NR_mlock2, 0x20fff000ul, 0x1000ul, 0ul);
	syscall(__NR_mremap, 0x20ffe000ul, 0x2000ul, 0x1000ul, 3ul, 0x20ffc000ul);
	return 0;
}
