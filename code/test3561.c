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

*(uint64_t*)0x20000680 = 0;
*(uint64_t*)0x20000688 = 0;
*(uint64_t*)0x20000690 = 0;
*(uint64_t*)0x20000698 = 0;
*(uint64_t*)0x200006a0 = 0;
*(uint64_t*)0x200006a8 = 0;
*(uint64_t*)0x200006b0 = 0;
*(uint64_t*)0x200006b8 = 0;
*(uint64_t*)0x200006c0 = 0;
*(uint64_t*)0x200006c8 = 0;
*(uint64_t*)0x200006d0 = 0;
*(uint64_t*)0x200006d8 = 0;
*(uint64_t*)0x200006e0 = 0;
*(uint64_t*)0x200006e8 = 0;
*(uint64_t*)0x200006f0 = 0;
*(uint64_t*)0x200006f8 = 0;
*(uint64_t*)0x20000700 = 0;
*(uint64_t*)0x20000708 = 0;
	syscall(__NR_process_vm_writev, 0, 0x20000680ul, 9ul, 0ul, 0ul, 0ul);
	return 0;
}
