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

memcpy((void*)0x20000040, ".\000", 2);
memcpy((void*)0x200000c0, "9p\000", 3);
memcpy((void*)0x20000100, "trans=fd,", 9);
memcpy((void*)0x20000109, "rfdno", 5);
*(uint8_t*)0x2000010e = 0x3d;
sprintf((char*)0x2000010f, "0x%016llx", (long long)-1);
*(uint8_t*)0x20000121 = 0x2c;
memcpy((void*)0x20000122, "wfdno", 5);
*(uint8_t*)0x20000127 = 0x3d;
sprintf((char*)0x20000128, "0x%016llx", (long long)-1);
*(uint8_t*)0x2000013a = 0x2c;
memcpy((void*)0x2000013b, "privport", 8);
*(uint8_t*)0x20000143 = 0x2c;
*(uint8_t*)0x20000144 = 0;
	syscall(__NR_mount, 0ul, 0x20000040ul, 0x200000c0ul, 0ul, 0x20000100ul);
	return 0;
}
