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
*(uint64_t*)0x20007680 = 0x200000c0;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e21);
*(uint8_t*)0x200000c4 = 0xac;
*(uint8_t*)0x200000c5 = 0x14;
*(uint8_t*)0x200000c6 = 0x14;
*(uint8_t*)0x200000c7 = 0xbb;
*(uint32_t*)0x20007688 = 0x10;
*(uint64_t*)0x20007690 = 0;
*(uint64_t*)0x20007698 = 0;
*(uint64_t*)0x200076a0 = 0;
*(uint64_t*)0x200076a8 = 0;
*(uint32_t*)0x200076b0 = 0;
*(uint32_t*)0x200076b8 = 0;
*(uint64_t*)0x200076c0 = 0x20001040;
*(uint16_t*)0x20001040 = 2;
*(uint16_t*)0x20001042 = htobe16(0x4e21);
*(uint32_t*)0x20001044 = htobe32(0);
*(uint32_t*)0x200076c8 = 0x10;
*(uint64_t*)0x200076d0 = 0;
*(uint64_t*)0x200076d8 = 0;
*(uint64_t*)0x200076e0 = 0x200011c0;
*(uint64_t*)0x200011c0 = 0x14;
*(uint32_t*)0x200011c8 = 0;
*(uint32_t*)0x200011cc = 7;
*(uint8_t*)0x200011d0 = 0x94;
*(uint8_t*)0x200011d1 = 2;
*(uint64_t*)0x200076e8 = 0x18;
*(uint32_t*)0x200076f0 = 0;
*(uint32_t*)0x200076f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20007680ul, 2ul, 0ul);
	return 0;
}