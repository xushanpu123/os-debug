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
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0x20080522;
*(uint32_t*)0x20000044 = 0;
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
	syscall(__NR_capset, 0x20000040ul, 0x20000080ul);
memset((void*)0x200000c0, 0, 16);
*(uint32_t*)0x200000d0 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x1b, 0x200000c0ul, 0x14ul);
	return 0;
}
