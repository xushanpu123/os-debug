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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint64_t*)0x200004d0 = 0x20000480;
*(uint64_t*)0x20000480 = 0x20001880;
*(uint32_t*)0x20001880 = 0xd0;
*(uint16_t*)0x20001884 = 0x13;
*(uint16_t*)0x20001886 = 0x19;
*(uint32_t*)0x20001888 = 0;
*(uint32_t*)0x2000188c = 0;
*(uint8_t*)0x20001890 = 0xac;
*(uint8_t*)0x20001891 = 0x1e;
*(uint8_t*)0x20001892 = 0;
*(uint8_t*)0x20001893 = 1;
*(uint32_t*)0x200018a0 = htobe32(0x7f000001);
*(uint16_t*)0x200018b0 = htobe16(0);
*(uint16_t*)0x200018b2 = htobe16(0);
*(uint16_t*)0x200018b4 = htobe16(0);
*(uint16_t*)0x200018b6 = htobe16(0);
*(uint16_t*)0x200018b8 = 2;
*(uint8_t*)0x200018ba = 0;
*(uint8_t*)0x200018bb = 0;
*(uint8_t*)0x200018bc = 0;
*(uint32_t*)0x200018c0 = 0;
*(uint32_t*)0x200018c4 = 0;
*(uint64_t*)0x200018c8 = 0;
*(uint64_t*)0x200018d0 = 0;
*(uint64_t*)0x200018d8 = 0;
*(uint64_t*)0x200018e0 = 0;
*(uint64_t*)0x200018e8 = 0;
*(uint64_t*)0x200018f0 = 0;
*(uint64_t*)0x200018f8 = 0;
*(uint64_t*)0x20001900 = 0;
*(uint64_t*)0x20001908 = 0;
*(uint64_t*)0x20001910 = 0;
*(uint64_t*)0x20001918 = 0;
*(uint64_t*)0x20001920 = 0;
*(uint32_t*)0x20001928 = 0;
*(uint32_t*)0x2000192c = 0;
*(uint8_t*)0x20001930 = 0;
*(uint8_t*)0x20001931 = 0;
*(uint8_t*)0x20001932 = 0;
*(uint8_t*)0x20001933 = 0;
*(uint16_t*)0x20001938 = 0xa;
*(uint16_t*)0x2000193a = 0x10;
*(uint8_t*)0x2000193c = 1;
*(uint16_t*)0x2000193e = 0;
*(uint8_t*)0x20001940 = 0;
*(uint16_t*)0x20001944 = 0xc;
*(uint16_t*)0x20001946 = 8;
*(uint16_t*)0x20001948 = 8;
*(uint16_t*)0x2000194a = 8;
*(uint8_t*)0x2000194c = 0;
*(uint8_t*)0x2000194d = 0;
*(uint16_t*)0x2000194e = 0;
*(uint64_t*)0x20000488 = 0xd0;
*(uint64_t*)0x200004d8 = 1;
*(uint64_t*)0x200004e0 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint32_t*)0x200004f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200004c0ul, 0ul);
	return 0;
}
