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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200000c0 = htobe32(0);
*(uint32_t*)0x200000c4 = htobe32(0);
*(uint16_t*)0x200000c8 = 0;
memcpy((void*)0x200000ca, "\x6d\x24\x74\xf0\xef\x91\x5a\x8c\xc9\x98\xbd\x86\x49\xed\x14\xde\x31\x1c\x59\x02\xfe\x84\xa3\xd3\x96\x6f\x7c\x07\xde\xe5\x68\x09", 32);
*(uint32_t*)0x200000ec = 0;
*(uint32_t*)0x200000f0 = 0;
*(uint32_t*)0x200000f4 = 0;
*(uint32_t*)0x200000f8 = 0;
	syscall(__NR_setsockopt, r[0], 0, 0xd2, 0x200000c0ul, 0x3cul);
	return 0;
}