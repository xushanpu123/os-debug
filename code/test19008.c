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
	res = syscall(__NR_io_setup, 8, 0x20000000ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000000;
	res = syscall(__NR_pipe, 0x20000440ul);
	if (res != -1)
r[1] = *(uint32_t*)0x20000440;
*(uint64_t*)0x20000540 = 0x20000080;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint16_t*)0x20000090 = 5;
*(uint16_t*)0x20000092 = 0;
*(uint32_t*)0x20000094 = r[1];
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint64_t*)0x200000b0 = 0;
*(uint32_t*)0x200000b8 = 0;
*(uint32_t*)0x200000bc = -1;
	syscall(__NR_io_submit, r[0], 1ul, 0x20000540ul);
	return 0;
}
