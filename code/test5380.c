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
	res = syscall(__NR_socket, 0xaul, 3ul, 0x3a);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002700 = 0x20000100;
*(uint16_t*)0x20000100 = 0xa;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = htobe32(0);
*(uint8_t*)0x20000108 = 0xfc;
*(uint8_t*)0x20000109 = 1;
memset((void*)0x2000010a, 0, 13);
*(uint8_t*)0x20000117 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x20002708 = 0x1c;
*(uint64_t*)0x20002710 = 0;
*(uint64_t*)0x20002718 = 0;
*(uint64_t*)0x20002720 = 0;
*(uint64_t*)0x20002728 = 0;
*(uint32_t*)0x20002730 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002700ul, 0ul);
	return 0;
}
