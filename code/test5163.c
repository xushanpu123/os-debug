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
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x88;
memset((void*)0x2000004a, 0, 12);
*(uint8_t*)0x20000056 = 0;
*(uint8_t*)0x20000057 = 1;
*(uint32_t*)0x20000058 = 3;
	syscall(__NR_bind, r[0], 0x20000040ul, 0x1cul);
*(uint64_t*)0x20000480 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e21);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x20000488 = 0x1c;
*(uint64_t*)0x20000490 = 0;
*(uint64_t*)0x20000498 = 0;
*(uint64_t*)0x200004a0 = 0x20000680;
*(uint64_t*)0x20000680 = 0x24;
*(uint32_t*)0x20000688 = 0x29;
*(uint32_t*)0x2000068c = 0x32;
*(uint8_t*)0x20000690 = 0xfc;
*(uint8_t*)0x20000691 = 1;
memset((void*)0x20000692, 0, 13);
*(uint8_t*)0x2000069f = 0;
*(uint32_t*)0x200006a0 = 0;
*(uint64_t*)0x200004a8 = 0x28;
*(uint32_t*)0x200004b0 = 0;
*(uint32_t*)0x200004b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000480ul, 1ul, 0ul);
	return 0;
}
