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
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000140 = 0;
*(uint16_t*)0x20000142 = 0;
	syscall(__NR_setsockopt, r[0], 0x107, 0x12, 0x20000140ul, 4ul);
*(uint16_t*)0x20000100 = 0;
*(uint16_t*)0x20000102 = 3;
	syscall(__NR_setsockopt, r[0], 0x107, 0x12, 0x20000100ul, 4ul);
	return 0;
}
