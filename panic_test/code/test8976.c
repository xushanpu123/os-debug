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
memcpy((void*)0x20000000, "/proc/sys/net/ipv4/tcp_wmem\000", 28);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 1ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200006c0, "/dev/rfkill\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200006c0ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
	syscall(__NR_dup2, r[0], r[1]);
	return 0;
}
