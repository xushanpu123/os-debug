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
memcpy((void*)0x20000000, "!{\000", 3);
	res = syscall(__NR_mq_open, 0x20000000ul, 0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0x9999999999999999;
	syscall(__NR_mq_notify, r[0], 0x20000040ul);
*(uint64_t*)0x200010c0 = 0;
*(uint32_t*)0x200010c8 = 0;
*(uint32_t*)0x200010cc = 0;
*(uint32_t*)0x200010d0 = 0;
	syscall(__NR_mq_notify, r[0], 0x200010c0ul);
	return 0;
}