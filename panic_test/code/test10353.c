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

*(uint64_t*)0x20000980 = 0;
*(uint64_t*)0x20000988 = 0;
*(uint64_t*)0x20000990 = 0;
*(uint64_t*)0x20000998 = 0;
*(uint64_t*)0x200009a0 = 0;
*(uint64_t*)0x200009a8 = 0;
*(uint64_t*)0x200009b0 = 0;
*(uint64_t*)0x200009b8 = 0;
*(uint64_t*)0x20000a00 = 0;
*(uint64_t*)0x20000a08 = 0x2710;
	syscall(__NR_select, 0ul, 0ul, 0x20000980ul, 0ul, 0x20000a00ul);
	return 0;
}