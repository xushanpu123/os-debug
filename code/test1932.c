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

#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x200004c4 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint32_t*)0x200004cc = 0;
*(uint32_t*)0x200004d0 = 0;
*(uint32_t*)0x200004d8 = -1;
memset((void*)0x200004dc, 0, 12);
	syscall(__NR_io_uring_setup, 0x6e54, 0x200004c0ul);
	syscall(__NR_socket, 0xaul, 2ul, 0x88);
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x200000c0 = 0x1f;
*(uint64_t*)0x200000c8 = 0;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint64_t*)0x200000f0 = 0;
*(uint64_t*)0x200000f8 = 0;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0x3938700;
	syscall(__NR_pselect6, 0x40ul, 0x20000040ul, 0ul, 0x200000c0ul, 0x20000100ul, 0ul);
	return 0;
}
