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

uint64_t r[2] = {0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000400ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000400;
	res = syscall(__NR_getpgid, 0);
	if (res != -1)
		r[1] = res;
	syscall(__NR_setregid, 0xee00, 0);
*(uint64_t*)0x20002380 = 0;
*(uint32_t*)0x20002388 = 0;
*(uint64_t*)0x20002390 = 0;
*(uint64_t*)0x20002398 = 0;
*(uint64_t*)0x200023a0 = 0x20001780;
*(uint64_t*)0x20001780 = 0x1c;
*(uint32_t*)0x20001788 = 1;
*(uint32_t*)0x2000178c = 2;
*(uint32_t*)0x20001790 = r[1];
*(uint32_t*)0x20001794 = 0;
*(uint32_t*)0x20001798 = 0;
*(uint64_t*)0x200017a0 = 0x1c;
*(uint32_t*)0x200017a8 = 1;
*(uint32_t*)0x200017ac = 2;
*(uint32_t*)0x200017b0 = r[1];
*(uint32_t*)0x200017b4 = 0;
*(uint32_t*)0x200017b8 = 0;
*(uint64_t*)0x200023a8 = 0x40;
*(uint32_t*)0x200023b0 = 0;
*(uint32_t*)0x200023b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002380ul, 1ul, 0ul);
	return 0;
}
