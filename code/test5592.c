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
memcpy((void*)0x20000040, "/proc/sys/net/ipv4/tcp_rmem\000", 28);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 1ul, 0ul);
	if (res != -1)
		r[0] = res;
sprintf((char*)0x20000100, "%023llo", (long long)0);
*(uint8_t*)0x20000117 = 0x20;
sprintf((char*)0x20000118, "%023llo", (long long)0);
*(uint8_t*)0x2000012f = 0x20;
sprintf((char*)0x20000130, "%023llo", (long long)0);
*(uint8_t*)0x20000147 = 0;
	syscall(__NR_write, r[0], 0x20000100ul, 0xaul);
	return 0;
}
