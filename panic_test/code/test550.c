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

memcpy((void*)0x20001180, "./file0\000", 8);
	syscall(__NR_mkdir, 0x20001180ul, 0ul);
memcpy((void*)0x200003c0, "./file0\000", 8);
memcpy((void*)0x20000400, "security.selinux\000", 17);
memcpy((void*)0x20000000, "system_u:object_r:hald_dccm_exec_t:s0\000", 38);
	syscall(__NR_lsetxattr, 0x200003c0ul, 0x20000400ul, 0x20000000ul, 0x26ul, 0ul);
memcpy((void*)0x20000080, "./file0/file0\000", 14);
	syscall(__NR_mkdir, 0x20000080ul, 0ul);
	return 0;
}
