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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x200010c0, "/dev/full\000", 10);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x200010c0ul, 0ul, 0ul);
	syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	syscall(__NR_socket, 2ul, 2ul, 0);
	syscall(__NR_socket, 2ul, 2ul, 0);
memcpy((void*)0x200010c0, "/dev/full\000", 10);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x200010c0ul, 0x300003ul, 0ul);
*(uint64_t*)0x20000000 = 0x81;
*(uint64_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0;
*(uint64_t*)0x20000018 = 0;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint64_t*)0x20000030 = 0;
*(uint64_t*)0x20000038 = 0;
*(uint64_t*)0x20000040 = 6;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x200000c0 = 0x77359400;
*(uint64_t*)0x200000c8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000000ul, 0x20000040ul, 0ul, 0x200000c0ul, 0ul);
	return 0;
}
