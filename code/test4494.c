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
memcpy((void*)0x20000200, "./file1\000", 8);
memcpy((void*)0x20000240, "cgroup2\000", 8);
memcpy((void*)0x20000280, "nsdelegate", 10);
*(uint8_t*)0x2000028a = 0x2c;
memcpy((void*)0x2000028b, "euid<", 5);
sprintf((char*)0x20000290, "%020llu", (long long)0);
*(uint8_t*)0x200002a4 = 0x2c;
*(uint8_t*)0x200002a5 = 0;
	syscall(__NR_mount, 0ul, 0x20000200ul, 0x20000240ul, 0ul, 0x20000280ul);
	return 0;
}