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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000000 = 0;
*(uint32_t*)0x20000008 = 0;
*(uint64_t*)0x20000010 = 0x20000040;
*(uint64_t*)0x20000040 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0x24;
*(uint16_t*)0x200001c4 = 0x26;
*(uint16_t*)0x200001c6 = 0x333;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
memcpy((void*)0x200001d0, "\xa3\x9e\x9c\xad\xf2\x84\x99\x2b\x9f\xa3\x24\xa4\xf9\x94\x8c\xfd\x17", 17);
*(uint64_t*)0x20000048 = 0x24;
*(uint64_t*)0x20000018 = 1;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000000ul, 0ul);
	return 0;
}