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
*(uint64_t*)0x200030c0 = 0x20000000;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e20);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
*(uint32_t*)0x200030c8 = 0x1c;
*(uint64_t*)0x200030d0 = 0;
*(uint64_t*)0x200030d8 = 0;
*(uint64_t*)0x200030e0 = 0;
*(uint64_t*)0x200030e8 = 0;
*(uint32_t*)0x200030f0 = 0;
*(uint32_t*)0x200030f8 = 0;
*(uint64_t*)0x20003100 = 0x200003c0;
*(uint16_t*)0x200003c0 = 0xa;
*(uint16_t*)0x200003c2 = htobe16(0x4e24);
*(uint32_t*)0x200003c4 = htobe32(0);
*(uint8_t*)0x200003c8 = -1;
*(uint8_t*)0x200003c9 = 2;
memset((void*)0x200003ca, 0, 13);
*(uint8_t*)0x200003d7 = 1;
*(uint32_t*)0x200003d8 = 0;
*(uint32_t*)0x20003108 = 0x1c;
*(uint64_t*)0x20003110 = 0;
*(uint64_t*)0x20003118 = 0;
*(uint64_t*)0x20003120 = 0x20001640;
*(uint64_t*)0x20001640 = 0x14;
*(uint32_t*)0x20001648 = 0x29;
*(uint32_t*)0x2000164c = 0xb;
*(uint32_t*)0x20001650 = htobe32(8);
*(uint64_t*)0x20001658 = 0x14;
*(uint32_t*)0x20001660 = 0x29;
*(uint32_t*)0x20001664 = 0xb;
*(uint32_t*)0x20001668 = htobe32(0xfffffff7);
*(uint64_t*)0x20003128 = 0x30;
*(uint32_t*)0x20003130 = 0;
*(uint32_t*)0x20003138 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200030c0ul, 2ul, 0ul);
	return 0;
}