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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000000 = 0;
	res = syscall(__NR_signalfd, -1, 0x20000000ul, 8ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_read, r[1], 0x20000380ul, 0xb5ul);
	res = syscall(__NR_gettid);
	if (res != -1)
		r[2] = res;
*(uint64_t*)0x20000340 = 0x200002c0;
*(uint64_t*)0x20000348 = 0x76;
	syscall(__NR_readv, r[0], 0x20000340ul, 1ul);
*(uint32_t*)0x20000000 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 0xfffff801;
	syscall(__NR_rt_sigqueueinfo, r[2], 0xb, 0x20000000ul);
	return 0;
}
