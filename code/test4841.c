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
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000440ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000440;
memcpy((void*)0x20000480, "#! ", 3);
memcpy((void*)0x20000483, "./file0", 7);
*(uint8_t*)0x2000048a = 0xa;
	syscall(__NR_write, r[0], 0x20000480ul, 0xbul);
	return 0;
}
