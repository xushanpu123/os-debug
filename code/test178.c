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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000fc0 = 0;
*(uint32_t*)0x20000fc8 = 0;
*(uint64_t*)0x20000fd0 = 0x20000c40;
*(uint64_t*)0x20000c40 = 0x200009c0;
memset((void*)0x200009c0, 161, 1);
*(uint64_t*)0x20000c48 = 1;
*(uint64_t*)0x20000fd8 = 1;
*(uint64_t*)0x20000fe0 = 0x20000f00;
*(uint64_t*)0x20000f00 = 0x10;
*(uint32_t*)0x20000f08 = 1;
*(uint32_t*)0x20000f0c = 1;
*(uint64_t*)0x20000fe8 = 0x10;
*(uint32_t*)0x20000ff0 = 0;
	syscall(__NR_sendmsg, r[1], 0x20000fc0ul, 0ul);
	return 0;
}
