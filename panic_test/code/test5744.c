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

memcpy((void*)0x20000200, "./file0\000", 8);
	syscall(__NR_creat, 0x20000200ul, 0ul);
memcpy((void*)0x20000000, "./file0\000", 8);
memcpy((void*)0x200000c0, "./file0\000", 8);
memcpy((void*)0x20000080, "9p\000", 3);
memcpy((void*)0x20000240, "trans=unix,", 11);
memcpy((void*)0x2000024b, "cache=fscache", 13);
*(uint8_t*)0x20000258 = 0x2c;
*(uint8_t*)0x20000259 = 0;
	syscall(__NR_mount, 0x20000000ul, 0x200000c0ul, 0x20000080ul, 0ul, 0x20000240ul);
	return 0;
}
