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
*(uint64_t*)0x20000100 = 0;
*(uint32_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x20000000;
*(uint32_t*)0x20000000 = 0x50;
*(uint16_t*)0x20000004 = 0x14;
*(uint16_t*)0x20000006 = 0x301;
*(uint32_t*)0x20000008 = 0;
*(uint32_t*)0x2000000c = 0;
*(uint32_t*)0x20000010 = htobe32(-1);
*(uint8_t*)0x20000020 = 0xfc;
*(uint8_t*)0x20000021 = 0;
memset((void*)0x20000022, 0, 13);
*(uint8_t*)0x2000002f = 0;
*(uint16_t*)0x20000030 = htobe16(0);
*(uint16_t*)0x20000032 = htobe16(0);
*(uint16_t*)0x20000034 = htobe16(0);
*(uint16_t*)0x20000036 = htobe16(0);
*(uint16_t*)0x20000038 = 0xa;
*(uint8_t*)0x2000003a = 0;
*(uint8_t*)0x2000003b = 0;
*(uint8_t*)0x2000003c = 0;
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = -1;
*(uint32_t*)0x20000048 = 0;
*(uint8_t*)0x2000004c = 0;
*(uint64_t*)0x200000c8 = 0x50;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000100ul, 0ul);
	return 0;
}
