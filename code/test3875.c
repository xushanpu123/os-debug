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

memcpy((void*)0x20000140, "./file0\000", 8);
	syscall(__NR_mkdir, 0x20000140ul, 0ul);
memcpy((void*)0x20000040, "./file0\000", 8);
memcpy((void*)0x20000080, "system.posix_acl_access\000", 24);
*(uint32_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c4 = 1;
*(uint16_t*)0x200000c6 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint16_t*)0x200000cc = 4;
*(uint16_t*)0x200000ce = 0;
*(uint32_t*)0x200000d0 = 0;
*(uint16_t*)0x200000d4 = 0x10;
*(uint16_t*)0x200000d6 = 4;
*(uint32_t*)0x200000d8 = 0;
*(uint16_t*)0x200000dc = 0x20;
*(uint16_t*)0x200000de = 0;
*(uint32_t*)0x200000e0 = 0;
	syscall(__NR_setxattr, 0x20000040ul, 0x20000080ul, 0x200000c0ul, 0x24ul, 0ul);
	return 0;
}