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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_gettid);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20002040 = 0;
*(uint32_t*)0x20002048 = 0;
*(uint64_t*)0x20002050 = 0;
*(uint64_t*)0x20002058 = 0;
*(uint64_t*)0x20002060 = 0x20001f40;
*(uint64_t*)0x20001f40 = 0x1c;
*(uint32_t*)0x20001f48 = 1;
*(uint32_t*)0x20001f4c = 2;
*(uint32_t*)0x20001f50 = r[1];
*(uint32_t*)0x20001f54 = 0;
*(uint32_t*)0x20001f58 = 0xee01;
*(uint64_t*)0x20002068 = 0x20;
*(uint32_t*)0x20002070 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002040ul, 0ul);
	return 0;
}