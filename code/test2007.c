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

*(uint16_t*)0x20000040 = 0;
*(uint16_t*)0x20000042 = 0;
*(uint16_t*)0x20000044 = 0;
	syscall(__NR_semtimedop, 0, 0x20000040ul, 1ul, 0ul);
*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 9;
*(uint16_t*)0x20000004 = 9;
	syscall(__NR_semctl, 0, 0ul, 0x11ul, 0x20000000ul);
	return 0;
}
