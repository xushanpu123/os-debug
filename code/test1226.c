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

memcpy((void*)0x20000040, "./file1\000", 8);
	syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
memcpy((void*)0x20000440, "syz\000", 4);
memcpy((void*)0x20000480, "./file1\000", 8);
	syscall(__NR_mount, 0x20000440ul, 0x20000480ul, 0ul, 0x1001000ul, 0ul);
	return 0;
}
