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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000040, "/dev/rfkill\000", 12);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0x801ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0;
*(uint8_t*)0x20000084 = 0;
*(uint8_t*)0x20000085 = 0;
*(uint8_t*)0x20000086 = 0;
*(uint8_t*)0x20000087 = 0;
	syscall(__NR_write, r[0], 0x20000080ul, 0xfffffffffffffdd5ul);
	return 0;
}
