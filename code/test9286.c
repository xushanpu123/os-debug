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

memcpy((void*)0x20001fc0, "./file1\000", 8);
	syscall(__NR_creat, 0x20001fc0ul, 0ul);
memcpy((void*)0x20000180, "./file1\000", 8);
memcpy((void*)0x200001c0, "cgroup\000", 7);
memcpy((void*)0x20000200, "none", 4);
*(uint8_t*)0x20000204 = 0x2c;
memcpy((void*)0x20000205, "all", 3);
*(uint8_t*)0x20000208 = 0x2c;
memcpy((void*)0x20000209, "name", 4);
*(uint8_t*)0x2000020d = 0x3d;
memset((void*)0x2000020e, 255, 6);
*(uint8_t*)0x20000214 = 0x2c;
memcpy((void*)0x20000215, "name", 4);
*(uint8_t*)0x20000219 = 0x3d;
memcpy((void*)0x2000021a, "security.", 9);
*(uint8_t*)0x20000223 = 0x2c;
*(uint8_t*)0x20000224 = 0;
	syscall(__NR_mount, 0ul, 0x20000180ul, 0x200001c0ul, 0ul, 0x20000200ul);
	return 0;
}
