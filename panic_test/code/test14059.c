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
*(uint8_t*)0x20000040 = 0;
*(uint8_t*)0x20000041 = 0;
memset((void*)0x20000042, 0, 6);
	syscall(__NR_setsockopt, r[0], 0x29, 0x3b, 0x20000040ul, 8ul);
*(uint64_t*)0x200002c0 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e21);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x200002c8 = 0x1c;
*(uint64_t*)0x200002d0 = 0x20000240;
*(uint64_t*)0x20000240 = 0x20000080;
memcpy((void*)0x20000080, "\x5d\xaa\x31\x42\xb5\x9d\xde", 7);
*(uint64_t*)0x20000248 = 7;
*(uint64_t*)0x20000250 = 0x20000180;
memset((void*)0x20000180, 242, 1);
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x200002d8 = 2;
*(uint64_t*)0x200002e0 = 0;
*(uint64_t*)0x200002e8 = 0;
*(uint32_t*)0x200002f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200002c0ul, 0ul);
	return 0;
}
