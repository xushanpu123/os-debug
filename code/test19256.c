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
	res = syscall(__NR_socket, 0x10ul, 3ul, 4);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000400 = 0x20000200;
*(uint16_t*)0x20000200 = 0x10;
*(uint16_t*)0x20000202 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint32_t*)0x20000408 = 0xc;
*(uint64_t*)0x20000410 = 0x200003c0;
*(uint64_t*)0x200003c0 = 0;
*(uint64_t*)0x200003c8 = 0;
*(uint64_t*)0x20000418 = 1;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint32_t*)0x20000430 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000400ul, 0ul);
	return 0;
}
