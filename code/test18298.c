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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20004080 = 0x20000080;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0x4e21);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint8_t*)0x20000088 = -1;
*(uint8_t*)0x20000089 = 1;
memset((void*)0x2000008a, 0, 13);
*(uint8_t*)0x20000097 = 1;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x20004088 = 0x1c;
*(uint64_t*)0x20004090 = 0;
*(uint64_t*)0x20004098 = 0;
*(uint64_t*)0x200040a0 = 0x20000380;
memset((void*)0x20000380, 24, 1);
*(uint64_t*)0x200040a8 = 0x18;
*(uint32_t*)0x200040b0 = 0;
*(uint32_t*)0x200040b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20004080ul, 1ul, 0x24008800ul);
*(uint64_t*)0x20003600 = 0;
*(uint32_t*)0x20003608 = 0;
*(uint64_t*)0x20003610 = 0;
*(uint64_t*)0x20003618 = 0;
*(uint64_t*)0x20003620 = 0;
*(uint64_t*)0x20003628 = 0;
*(uint32_t*)0x20003630 = 0;
*(uint32_t*)0x20003638 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003600ul, 1ul, 0ul);
	return 0;
}
