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

memcpy((void*)0x20000140, "asymmetric\000", 11);
memcpy((void*)0x20000040, "syz", 3);
*(uint8_t*)0x20000043 = 0x22;
*(uint8_t*)0x20000044 = 0;
	syscall(__NR_request_key, 0x20000140ul, 0x20000040ul, 0ul, 0xfffffffe);
	return 0;
}
