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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xf);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000340 = 0;
*(uint32_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0x20000000;
*(uint64_t*)0x20000000 = 0x20000200;
memcpy((void*)0x20000200, "\x18\x00\x00\x00\x12\x00\x01", 7);
*(uint64_t*)0x20000008 = 0x18;
*(uint64_t*)0x20000010 = 0x20000f00;
*(uint64_t*)0x20000018 = 0x7e4;
*(uint64_t*)0x20000358 = 2;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint32_t*)0x20000370 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000340ul, 0ul);
	return 0;
}
