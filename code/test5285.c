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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 2;
*(uint16_t*)0x20000048 = 2;
*(uint16_t*)0x2000004a = htobe16(0);
*(uint32_t*)0x2000004c = htobe32(0xe0000002);
*(uint16_t*)0x200000c8 = 2;
*(uint16_t*)0x200000ca = htobe16(0);
*(uint32_t*)0x200000cc = htobe32(0);
	syscall(__NR_setsockopt, r[0], 0, 0x2f, 0x20000040ul, 0x108ul);
	return 0;
}
