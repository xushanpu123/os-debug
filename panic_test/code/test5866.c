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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200001c0 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x10;
*(uint16_t*)0x200000c2 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200001c8 = 0xc;
*(uint64_t*)0x200001d0 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000140;
*(uint32_t*)0x20000140 = 0x1c;
*(uint16_t*)0x20000144 = 0;
*(uint16_t*)0x20000146 = 0;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 0x25dfdbfe;
*(uint8_t*)0x20000150 = 2;
*(uint8_t*)0x20000151 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint16_t*)0x20000154 = 5;
*(uint16_t*)0x20000156 = 6;
*(uint8_t*)0x20000158 = 2;
*(uint64_t*)0x20000188 = 0xfff3;
*(uint64_t*)0x200001d8 = 1;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200001c0ul, 0ul);
	return 0;
}
