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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe2, 0x20000040ul, 0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000040;
r[1] = *(uint32_t*)0x20000044;
	}
*(uint32_t*)0x20000080 = 0xf;
*(uint8_t*)0x20000084 = 0x1f;
*(uint16_t*)0x20000085 = 0;
*(uint64_t*)0x20000087 = 0;
	syscall(__NR_write, r[1], 0x20000080ul, 0xful);
*(uint64_t*)0x20000000 = 0;
*(uint64_t*)0x20000008 = 0x63;
*(uint64_t*)0x20000010 = 0x20000100;
memset((void*)0x20000100, 180, 1);
*(uint64_t*)0x20000018 = 1;
	syscall(__NR_vmsplice, r[0], 0x20000000ul, 2ul, 0ul);
	return 0;
}
