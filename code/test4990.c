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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000240 = 0;
*(uint64_t*)0x20000250 = 0;
	syscall(__NR_rt_sigaction, 0x33, 0x20000140ul, 0x20000240ul, 8ul, 0x20000280ul);
	return 0;
}
