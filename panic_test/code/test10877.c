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

memcpy((void*)0x20000400, "./file0\000", 8);
	syscall(__NR_mknod, 0x20000400ul, 0ul, 0x701);
memcpy((void*)0x20002540, "./file0\000", 8);
memcpy((void*)0x20002580, "security.capability\000", 20);
*(uint32_t*)0x200025c0 = 0x2000000;
*(uint32_t*)0x200025c4 = 0;
*(uint32_t*)0x200025c8 = 0;
*(uint32_t*)0x200025cc = 0;
*(uint32_t*)0x200025d0 = 0;
	syscall(__NR_setxattr, 0x20002540ul, 0x20002580ul, 0x200025c0ul, 0x14ul, 0ul);
memcpy((void*)0x20000000, "./file0\000", 8);
	syscall(__NR_creat, 0x20000000ul, 0ul);
	return 0;
}