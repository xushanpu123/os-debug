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

#ifndef __NR_mlock2
#define __NR_mlock2 325
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint16_t*)0x20000000 = 0;
	syscall(__NR_semctl, 0, 0ul, 0x11ul, 0x20000000ul);
	syscall(__NR_munmap, 0x20ffd000ul, 0x3000ul);
	syscall(__NR_mlock, 0x20ffb000ul, 0x2000ul);
	syscall(__NR_mlock2, 0x20ff2000ul, 0xe000ul, 1ul);
	return 0;
}
