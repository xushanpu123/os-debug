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
*(uint64_t*)0x200003c0 = 0;
*(uint32_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0;
*(uint64_t*)0x200003d8 = 1;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0;
*(uint32_t*)0x200003f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200003c0ul, 0ul);
memcpy((void*)0x20000000, "/dev/zero\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200001c0 = 0x20000040;
*(uint64_t*)0x200001c8 = 0x7a;
*(uint64_t*)0x200001d0 = 0x20000100;
*(uint64_t*)0x200001d8 = 0x96;
	syscall(__NR_preadv, r[0], 0x200001c0ul, 0x3ful, 0, 0);
	return 0;
}
