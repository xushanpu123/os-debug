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
*(uint64_t*)0x20000040 = 0x20000100;
*(uint16_t*)0x20000100 = 0xa;
*(uint16_t*)0x20000102 = htobe16(0x4e21);
*(uint32_t*)0x20000104 = htobe32(0);
*(uint8_t*)0x20000108 = 0xfe;
*(uint8_t*)0x20000109 = 0x80;
memset((void*)0x2000010a, 0, 13);
*(uint8_t*)0x20000117 = 0;
*(uint32_t*)0x20000118 = 0;
*(uint32_t*)0x20000048 = 0x80;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0x20000000;
*(uint64_t*)0x20000000 = 0x14;
*(uint32_t*)0x20000008 = 1;
*(uint32_t*)0x2000000c = 0x24;
*(uint32_t*)0x20000010 = 0;
*(uint64_t*)0x20000018 = 0x14;
*(uint32_t*)0x20000020 = 1;
*(uint32_t*)0x20000024 = 0x25;
*(uint32_t*)0x20000028 = 1;
*(uint64_t*)0x20000068 = 0x30;
*(uint32_t*)0x20000070 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000040ul, 0ul);
	return 0;
}