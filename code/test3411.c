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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe2, 0x20000000ul, 0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000000;
	syscall(__NR_close, r[0]);
*(uint64_t*)0x200000c0 = 0;
	syscall(__NR_signalfd4, -1, 0x200000c0ul, 8ul, 0ul);
memcpy((void*)0x20000100, "/dev/vcsu\000", 10);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0ul, 0ul);
	syscall(__NR_pipe2, 0x20000000ul, 0ul);
*(uint64_t*)0x20000380 = 9;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
*(uint64_t*)0x200003c0 = 0x80;
*(uint64_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0;
*(uint64_t*)0x200003d8 = 0;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0;
*(uint64_t*)0x200003f0 = 0;
*(uint64_t*)0x200003f8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000380ul, 0x200003c0ul, 0ul, 0ul, 0ul);
	return 0;
}
