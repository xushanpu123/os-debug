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
	res = syscall(__NR_timerfd_create, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
	syscall(__NR_timerfd_settime, r[0], 3ul, 0x20000040ul, 0ul);
*(uint64_t*)0x200000c0 = 0;
*(uint64_t*)0x200000c8 = 0x989680;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
	syscall(__NR_timerfd_settime, r[0], 3ul, 0x200000c0ul, 0ul);
	return 0;
}
