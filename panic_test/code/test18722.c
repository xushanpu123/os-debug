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
*(uint16_t*)0x200000c0 = 0;
*(uint16_t*)0x200000c2 = 0x33;
memcpy((void*)0x200000c4, "\x5d\xeb\x1d\x4a\x41\xb0\x58\xe5", 8);
memcpy((void*)0x200000cc, "\x8d\x02\xd5\xee\xe9\xc3\x5a\xe3\x74\xfa\x00\x7e\x59\x44\x9e\xd4", 16);
memcpy((void*)0x200000dc, "\x17\x07\xdd\xb5", 4);
memcpy((void*)0x200000e0, "\x37\x57\xd8\x25\xc2\x74\xba\x81", 8);
	syscall(__NR_setsockopt, r[0], 6, 2, 0x200000c0ul, 0x28ul);
	return 0;
}
