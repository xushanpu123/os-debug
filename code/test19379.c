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

#ifndef __NR_close_range
#define __NR_close_range 436
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_close_range, -1, -1, 2ul);
memcpy((void*)0x20000000, "/sys/power/reserved_size", 24);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0ul);
*(uint64_t*)0x20000540 = 0;
*(uint64_t*)0x20000548 = 0;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint64_t*)0x20000570 = 0;
*(uint64_t*)0x20000578 = 0;
*(uint64_t*)0x20000580 = 9;
*(uint64_t*)0x20000588 = 0;
*(uint64_t*)0x20000590 = 0;
*(uint64_t*)0x20000598 = 0;
*(uint64_t*)0x200005a0 = 0;
*(uint64_t*)0x200005a8 = 0;
*(uint64_t*)0x200005b0 = 0;
*(uint64_t*)0x200005b8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000540ul, 0x20000580ul, 0ul, 0ul, 0ul);
	return 0;
}
