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

memcpy((void*)0x200004c0, ".\000", 2);
memcpy((void*)0x20000040, "9p\000", 3);
memcpy((void*)0x20000080, "trans=unix,", 11);
memcpy((void*)0x2000008b, "defcontext", 10);
*(uint8_t*)0x20000095 = 0x3d;
memcpy((void*)0x20000096, "staff_u", 7);
*(uint8_t*)0x2000009d = 0x2c;
*(uint8_t*)0x2000009e = 0;
	syscall(__NR_mount, 0ul, 0x200004c0ul, 0x20000040ul, 0ul, 0x20000080ul);
	return 0;
}
