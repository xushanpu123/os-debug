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
	res = syscall(__NR_socket, 2ul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20001780, "nat\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 32);
*(uint32_t*)0x200017a0 = 0;
*(uint32_t*)0x200017a4 = 0;
*(uint32_t*)0x200017a8 = 0;
*(uint32_t*)0x200017ac = 0;
*(uint32_t*)0x200017b0 = 0;
*(uint32_t*)0x200017b4 = 0;
memset((void*)0x200017b8, 0, 20);
*(uint32_t*)0x200017cc = 0;
*(uint32_t*)0x200017d0 = 0;
*(uint32_t*)0x20001800 = 0x54;
	syscall(__NR_getsockopt, r[0], 0, 0x40, 0x20001780ul, 0x20001800ul);
	return 0;
}
