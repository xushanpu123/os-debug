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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000800 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e22);
*(uint8_t*)0x20000004 = 0xac;
*(uint8_t*)0x20000005 = 0x14;
*(uint8_t*)0x20000006 = 0x14;
*(uint8_t*)0x20000007 = 0xbb;
*(uint32_t*)0x20000808 = 0x80;
*(uint64_t*)0x20000810 = 0;
*(uint64_t*)0x20000818 = 0;
*(uint64_t*)0x20000820 = 0;
*(uint64_t*)0x20000828 = 0;
*(uint32_t*)0x20000830 = 0;
*(uint32_t*)0x20000838 = 0;
*(uint64_t*)0x20000840 = 0x20000080;
*(uint16_t*)0x20000080 = 2;
*(uint16_t*)0x20000082 = htobe16(0x4e21);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint32_t*)0x20000848 = 0x80;
*(uint64_t*)0x20000850 = 0;
*(uint64_t*)0x20000858 = 0;
*(uint64_t*)0x20000860 = 0x200003c0;
*(uint64_t*)0x200003c0 = 0x10;
*(uint32_t*)0x200003c8 = 0;
*(uint32_t*)0x200003cc = 1;
*(uint64_t*)0x20000868 = 0x10;
*(uint32_t*)0x20000870 = 0;
*(uint32_t*)0x20000878 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000800ul, 2ul, 0ul);
	return 0;
}
