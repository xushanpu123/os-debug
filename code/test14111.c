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
	res = syscall(__NR_socket, 2ul, 1ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200006c0, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint16_t*)0x200006d0 = 2;
*(uint16_t*)0x200006d2 = htobe16(0);
*(uint32_t*)0x200006d4 = htobe32(0x64010100);
	syscall(__NR_ioctl, r[0], 0x8916, 0x200006c0ul);
	return 0;
}