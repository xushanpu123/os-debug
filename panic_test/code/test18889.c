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

#ifndef __NR_pkey_mprotect
#define __NR_pkey_mprotect 329
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_mmap, 0x20ff7000ul, 0x9000ul, 0ul, 0xc2cdd74793cbd231ul, -1, 0x10000000ul);
	syscall(__NR_pkey_mprotect, 0x20ffb000ul, 0x3000ul, 0xbul, -1);
*(uint64_t*)0x20000080 = 0xfffffffffffffff7;
	syscall(__NR_mbind, 0x20ff3000ul, 0xd000ul, 2ul, 0x20000080ul, 5ul, 0ul);
	return 0;
}
