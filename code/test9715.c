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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002780 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint8_t*)0x20000008 = 0xfc;
*(uint8_t*)0x20000009 = 1;
memset((void*)0x2000000a, 0, 13);
*(uint8_t*)0x20000017 = 0;
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x20002788 = 0x1c;
*(uint64_t*)0x20002790 = 0;
*(uint64_t*)0x20002798 = 0;
*(uint64_t*)0x200027a0 = 0;
*(uint64_t*)0x200027a8 = 0;
*(uint32_t*)0x200027b0 = 0;
*(uint32_t*)0x200027b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002780ul, 1ul, 0x20040040ul);
	syscall(__NR_ioctl, r[0], 0x541b, 0x20000040ul);
	return 0;
}
