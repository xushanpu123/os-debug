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
	res = syscall(__NR_socket, 0xaul, 3ul, 4);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20003bc0 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x2000001c = 0;
*(uint32_t*)0x20003bc8 = 0x80;
*(uint64_t*)0x20003bd0 = 0;
*(uint64_t*)0x20003bd8 = 0;
*(uint64_t*)0x20003be0 = 0;
*(uint64_t*)0x20003be8 = 0;
*(uint32_t*)0x20003bf0 = 0;
*(uint32_t*)0x20003bf8 = 0;
*(uint64_t*)0x20003c00 = 0x20000100;
*(uint16_t*)0x20000100 = 0xa;
*(uint16_t*)0x20000102 = 0;
*(uint32_t*)0x20000104 = htobe32(0);
*(uint8_t*)0x20000108 = -1;
*(uint8_t*)0x20000109 = 2;
memset((void*)0x2000010a, 0, 13);
*(uint8_t*)0x20000117 = 1;
*(uint32_t*)0x20000118 = 0xffffff7f;
*(uint32_t*)0x2000011c = 0;
*(uint32_t*)0x20003c08 = 0x80;
*(uint64_t*)0x20003c10 = 0;
*(uint64_t*)0x20003c18 = 0;
*(uint64_t*)0x20003c20 = 0x20005640;
*(uint64_t*)0x20005640 = 0x10;
*(uint32_t*)0x20005648 = 1;
*(uint32_t*)0x2000564c = 0;
*(uint64_t*)0x20003c28 = 0x10;
*(uint32_t*)0x20003c30 = 0;
*(uint32_t*)0x20003c38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003bc0ul, 2ul, 0ul);
	return 0;
}
