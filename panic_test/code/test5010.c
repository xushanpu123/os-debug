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

*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint32_t*)0x200000d8 = -1;
memset((void*)0x200000dc, 0, 12);
	syscall(__NR_io_uring_setup, 0x2f7f, 0x200000c0ul);
*(uint32_t*)0x200001c4 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint32_t*)0x200001d0 = 0;
*(uint32_t*)0x200001d8 = -1;
memset((void*)0x200001dc, 0, 12);
	syscall(__NR_io_uring_setup, 0x51da, 0x200001c0ul);
	syscall(__NR_eventfd, 1);
memcpy((void*)0x20000440, "/dev/rfkill\000", 12);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000440ul, 0ul, 0ul);
	syscall(__NR_socket, 0x10ul, 3ul, 0xc);
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000100 = 0xff;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
*(uint64_t*)0x20000118 = 0;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint64_t*)0x20000130 = 0;
*(uint64_t*)0x20000138 = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0x989680;
	syscall(__NR_pselect6, 0x40ul, 0x20000040ul, 0ul, 0x20000100ul, 0x20000140ul, 0ul);
	return 0;
}
