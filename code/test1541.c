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
memcpy((void*)0x20000280, "./file1\000", 8);
memcpy((void*)0x200002c0, "9p\000", 3);
memcpy((void*)0x20000440, "trans=fd,", 9);
memcpy((void*)0x20000449, "rfdno", 5);
*(uint8_t*)0x2000044e = 0x3d;
sprintf((char*)0x2000044f, "0x%016llx", (long long)-1);
*(uint8_t*)0x20000461 = 0x2c;
memcpy((void*)0x20000462, "wfdno", 5);
*(uint8_t*)0x20000467 = 0x3d;
sprintf((char*)0x20000468, "0x%016llx", (long long)-1);
*(uint8_t*)0x2000047a = 0x2c;
memcpy((void*)0x2000047b, "msize", 5);
*(uint8_t*)0x20000480 = 0x3d;
sprintf((char*)0x20000481, "0x%016llx", (long long)0);
*(uint8_t*)0x20000493 = 0x2c;
*(uint8_t*)0x20000494 = 0;
	syscall(__NR_mount, 0ul, 0x20000280ul, 0x200002c0ul, 0ul, 0x20000440ul);
	return 0;
}
