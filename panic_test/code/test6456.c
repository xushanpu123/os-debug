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
memcpy((void*)0x20000100, "./cgroup/syz1\000", 14);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000100ul, 0x200002ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000140, "cgroup.procs\000", 13);
	res = syscall(__NR_openat, r[0], 0x20000140ul, 2ul, 0ul);
	if (res != -1)
		r[1] = res;
sprintf((char*)0x20000040, "0x%016llx", (long long)0);
	syscall(__NR_write, r[1], 0x20000040ul, 0xffffff1ful);
	return 0;
}
