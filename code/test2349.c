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

uint64_t r[2] = {0x0, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 3, 0x200028c0ul);
	if (res != -1)
r[0] = *(uint64_t*)0x200028c0;
memcpy((void*)0x20000040, "/dev/rfkill\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200003c0 = 0x20000180;
*(uint64_t*)0x20000180 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint16_t*)0x20000190 = 1;
*(uint16_t*)0x20000192 = 0;
*(uint32_t*)0x20000194 = r[1];
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint64_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b8 = 0;
*(uint32_t*)0x200001bc = -1;
	syscall(__NR_io_submit, r[0], 1ul, 0x200003c0ul);
	return 0;
}
