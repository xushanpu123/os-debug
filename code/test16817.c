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
				syscall(__NR_shmat, 0, 0x20ffc000ul, 0x5000ul);
	syscall(__NR_mlock2, 0x20ff5000ul, 0x2000ul, 0ul);
	syscall(__NR_shmat, 0, 0x20000000ul, 0x4000ul);
memcpy((void*)0x20000000, "/dev/snd/timer\000", 15);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0);
	syscall(__NR_madvise, 0x20000000ul, 0x5000ul, 0x15ul);
	return 0;
}
