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

*(uint16_t*)0x20000080 = 0;
*(uint16_t*)0x20000082 = 0;
*(uint16_t*)0x20000084 = 0;
*(uint16_t*)0x20000086 = 0;
*(uint16_t*)0x20000088 = 0;
*(uint16_t*)0x2000008a = 0;
	syscall(__NR_semop, 0, 0x20000080ul, 2ul);
	return 0;
}
