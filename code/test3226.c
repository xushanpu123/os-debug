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
				syscall(__NR_timer_create, 3ul, 0ul, 0x20000240ul);
*(uint64_t*)0x20000400 = 0;
*(uint64_t*)0x20000408 = 0x3938700;
*(uint64_t*)0x20000410 = 0;
*(uint64_t*)0x20000418 = 0;
	syscall(__NR_timer_settime, 0, 0ul, 0x20000400ul, 0ul);
	return 0;
}
