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

memcpy((void*)0x20000300, "./file0\000", 8);
	syscall(__NR_mkdir, 0x20000300ul, 0ul);
memcpy((void*)0x200000c0, "./file0\000", 8);
memcpy((void*)0x200001c0, "tmpfs\000", 6);
memcpy((void*)0x20000000, "mpol", 4);
*(uint8_t*)0x20000004 = 0x3d;
memcpy((void*)0x20000005, "default", 7);
memcpy((void*)0x2000000c, "=relative", 9);
*(uint8_t*)0x20000015 = 0x2c;
*(uint8_t*)0x20000016 = 0;
	syscall(__NR_mount, 0ul, 0x200000c0ul, 0x200001c0ul, 0ul, 0x20000000ul);
	return 0;
}
