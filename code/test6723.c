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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200002c0 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 10);
memset((void*)0x20000012, 255, 2);
*(uint32_t*)0x20000014 = htobe32(0);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x200002c8 = 0x1c;
*(uint64_t*)0x200002d0 = 0x20000240;
*(uint64_t*)0x200002d8 = 0x2a5;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0xfffffffffffffda4;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}