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
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close, r[0]);
	syscall(__NR_socket, 0x11ul, 2ul, 0x300);
*(uint64_t*)0x20005e40 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x20005e48 = 0xc;
*(uint64_t*)0x20005e50 = 0;
*(uint64_t*)0x20005e58 = 0;
*(uint64_t*)0x20005e60 = 0;
*(uint64_t*)0x20005e68 = 0;
*(uint32_t*)0x20005e70 = 0;
	syscall(__NR_sendmsg, r[0], 0x20005e40ul, 0ul);
	return 0;
}
