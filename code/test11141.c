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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 0x73;
*(uint16_t*)0x20000004 = 0;
*(uint16_t*)0x20000006 = 0;
*(uint16_t*)0x20000008 = 2;
*(uint16_t*)0x2000000a = 0x1000;
*(uint16_t*)0x2000000c = 3;
*(uint16_t*)0x2000000e = 0;
*(uint16_t*)0x20000010 = 0x1800;
*(uint16_t*)0x20000012 = 1;
*(uint16_t*)0x20000014 = 0;
*(uint16_t*)0x20000016 = 0x1000;
*(uint16_t*)0x20000018 = 1;
*(uint16_t*)0x2000001a = 0x200;
*(uint16_t*)0x2000001c = 0x800;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
	syscall(__NR_semtimedop, 0, 0x20000000ul, 5ul, 0x20000080ul);
	return 0;
}