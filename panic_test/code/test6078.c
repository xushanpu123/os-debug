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

memcpy((void*)0x20000280, "./file0\000", 8);
	syscall(__NR_creat, 0x20000280ul, 0xf0ul);
memcpy((void*)0x20000040, "./file0\000", 8);
memcpy((void*)0x20000080, "security.ima\000", 13);
*(uint8_t*)0x200000c0 = 4;
*(uint8_t*)0x200000c1 = 0;
memcpy((void*)0x200000c2, "\x25\x1b\x80\x30\xc7\x65\x60\xe3\xee\x56", 10);
	syscall(__NR_lsetxattr, 0x20000040ul, 0x20000080ul, 0x200000c0ul, 0xcul, 0ul);
	return 0;
}