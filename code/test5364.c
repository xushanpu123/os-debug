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

memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_creat, 0x20000000ul, 0ul);
memcpy((void*)0x200000c0, "./file0\000", 8);
memcpy((void*)0x20000100, "cgroup\000", 7);
memcpy((void*)0x20000140, "all", 3);
*(uint8_t*)0x20000143 = 0x2c;
memcpy((void*)0x20000144, "xattr", 5);
*(uint8_t*)0x20000149 = 0x2c;
memcpy((void*)0x2000014a, "cpuset_v2_mode", 14);
*(uint8_t*)0x20000158 = 0x2c;
memcpy((void*)0x20000159, "noprefix", 8);
*(uint8_t*)0x20000161 = 0x2c;
*(uint8_t*)0x20000162 = 0;
	syscall(__NR_mount, 0ul, 0x200000c0ul, 0x20000100ul, 0ul, 0x20000140ul);
	return 0;
}