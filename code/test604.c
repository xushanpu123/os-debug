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

#ifndef __NR_rseq
#define __NR_rseq 334
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint32_t*)0x20000090 = 0;
	syscall(__NR_rseq, 0x20000080ul, 0x20ul, 0ul, 0ul);
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint32_t*)0x20000090 = 0;
	syscall(__NR_rseq, 0x20000080ul, 0x20ul, 0ul, 0ul);
	return 0;
}
