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
memcpy((void*)0x200001c0, "/dev/vga_arbiter\000", 17);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200001c0ul, 2ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "decodes", 7);
memset((void*)0x20000047, 32, 1);
memcpy((void*)0x20000048, "io+mem", 6);
*(uint8_t*)0x2000004e = 0;
	syscall(__NR_write, r[0], 0x20000040ul, 0xful);
	return 0;
}
