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
	res = syscall(__NR_socket, 0x10ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20003140 = 0;
*(uint32_t*)0x20003148 = 0;
*(uint64_t*)0x20003150 = 0;
*(uint64_t*)0x20003158 = 0;
*(uint64_t*)0x20003160 = 0x200030c0;
*(uint64_t*)0x200030c0 = 0x1c;
*(uint32_t*)0x200030c8 = 1;
*(uint32_t*)0x200030cc = 2;
*(uint32_t*)0x200030d0 = 0;
*(uint32_t*)0x200030d4 = -1;
*(uint32_t*)0x200030d8 = 0;
*(uint64_t*)0x20003168 = 0x20;
*(uint32_t*)0x20003170 = 0;
	syscall(__NR_sendmsg, r[0], 0x20003140ul, 0ul);
	return 0;
}
