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
memcpy((void*)0x200001c0, "./file0\000", 8);
memcpy((void*)0x20000200, "security.selinux\000", 17);
memcpy((void*)0x200002c0, "system_u:object_r:auditd_unit_file_t:s0\000", 40);
	syscall(__NR_setxattr, 0x200001c0ul, 0x20000200ul, 0x200002c0ul, 0x28ul, 3ul);
	return 0;
}
