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
*(uint64_t*)0x200003c0 = 0;
*(uint32_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0x20000380;
*(uint64_t*)0x20000380 = 0x20000000;
*(uint32_t*)0x20000000 = 0xb8;
*(uint16_t*)0x20000004 = 0x13;
*(uint16_t*)0x20000006 = 1;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint8_t*)0x20000010 = 0xac;
*(uint8_t*)0x20000011 = 0x14;
*(uint8_t*)0x20000012 = 0x14;
*(uint8_t*)0x20000013 = 0;
*(uint8_t*)0x20000020 = 0xac;
*(uint8_t*)0x20000021 = 0x14;
*(uint8_t*)0x20000022 = 0x14;
*(uint8_t*)0x20000023 = 0xbb;
*(uint16_t*)0x20000030 = htobe16(0);
*(uint16_t*)0x20000032 = htobe16(0);
*(uint16_t*)0x20000034 = htobe16(0);
*(uint16_t*)0x20000036 = htobe16(0);
*(uint16_t*)0x20000038 = 2;
*(uint8_t*)0x2000003a = 0x20;
*(uint8_t*)0x2000003b = 0;
*(uint8_t*)0x2000003c = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 0xee00;
*(uint64_t*)0x20000048 = 0;
*(uint64_t*)0x20000050 = 0;
*(uint64_t*)0x20000058 = 0;
*(uint64_t*)0x20000060 = 0;
*(uint64_t*)0x20000068 = 0;
*(uint64_t*)0x20000070 = 0;
*(uint64_t*)0x20000078 = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0;
*(uint64_t*)0x20000098 = 0;
*(uint64_t*)0x200000a0 = 0;
*(uint32_t*)0x200000a8 = 0;
*(uint32_t*)0x200000ac = 0;
*(uint8_t*)0x200000b0 = 0;
*(uint8_t*)0x200000b1 = 0;
*(uint8_t*)0x200000b2 = 0;
*(uint8_t*)0x200000b3 = 0;
*(uint64_t*)0x20000388 = 0xb8;
*(uint64_t*)0x200003d8 = 1;
*(uint64_t*)0x200003e0 = 0;
*(uint64_t*)0x200003e8 = 0;
*(uint32_t*)0x200003f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200003c0ul, 0ul);
	return 0;
}
