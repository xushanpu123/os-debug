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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint16_t*)0x20000280 = 1;
*(uint64_t*)0x20000288 = 0x20000240;
*(uint16_t*)0x20000240 = 6;
*(uint8_t*)0x20000242 = 0;
*(uint8_t*)0x20000243 = 0;
*(uint32_t*)0x20000244 = 0;
	syscall(__NR_seccomp, 1ul, 8ul, 0x20000280ul);
	syscall(__NR_socket, 0ul, 0ul, 0);
*(uint64_t*)0x20000300 = 0;
*(uint64_t*)0x20000308 = 0;
*(uint64_t*)0x20000310 = 0;
*(uint64_t*)0x20000318 = 0;
*(uint64_t*)0x20000320 = 0;
*(uint64_t*)0x20000328 = 0;
*(uint64_t*)0x20000330 = 0;
*(uint64_t*)0x20000338 = 0;
*(uint64_t*)0x20000380 = 9;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000300ul, 0ul, 0x20000380ul, 0ul, 0ul);
	return 0;
}
