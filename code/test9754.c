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
memcpy((void*)0x20000000, "/sys/power/disk", 15);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x2001ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000100 = 8;
*(uint8_t*)0x20000104 = 0x35;
*(uint16_t*)0x20000105 = 0;
*(uint8_t*)0x20000107 = 0;
	syscall(__NR_write, r[0], 0x20000100ul, 8ul);
	return 0;
}
