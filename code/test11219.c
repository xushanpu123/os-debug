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
	res = syscall(__NR_socket, 2ul, 2ul, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000700 = 0x20000080;
*(uint16_t*)0x20000080 = 0x10;
*(uint16_t*)0x20000082 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x20000708 = 0xc;
*(uint64_t*)0x20000710 = 0x200006c0;
*(uint64_t*)0x200006c0 = 0x200000c0;
memset((void*)0x200000c0, 8, 1);
*(uint64_t*)0x200006c8 = 0x5d0;
*(uint64_t*)0x20000718 = 1;
*(uint64_t*)0x20000720 = 0;
*(uint64_t*)0x20000728 = 0;
*(uint32_t*)0x20000730 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000700ul, 0ul);
	return 0;
}
