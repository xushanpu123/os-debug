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
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000a00 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x2a;
*(uint32_t*)0x200000c4 = 2;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x20000a08 = 0x80;
*(uint64_t*)0x20000a10 = 0;
*(uint64_t*)0x20000a18 = 0;
*(uint64_t*)0x20000a20 = 0;
*(uint64_t*)0x20000a28 = 0;
*(uint32_t*)0x20000a30 = 0;
*(uint32_t*)0x20000a38 = 0;
*(uint64_t*)0x20000a40 = 0x20000780;
*(uint16_t*)0x20000780 = 0x2a;
*(uint32_t*)0x20000784 = 1;
*(uint32_t*)0x20000788 = 0;
*(uint32_t*)0x20000a48 = 0x80;
*(uint64_t*)0x20000a50 = 0;
*(uint64_t*)0x20000a58 = 0;
*(uint64_t*)0x20000a60 = 0x20000800;
*(uint64_t*)0x20000800 = 0x10;
*(uint32_t*)0x20000808 = 0;
*(uint32_t*)0x2000080c = 0;
*(uint64_t*)0x20000810 = 0;
*(uint32_t*)0x20000818 = 0;
*(uint32_t*)0x2000081c = 0;
*(uint64_t*)0x20000a68 = 0x20;
*(uint32_t*)0x20000a70 = 0;
*(uint32_t*)0x20000a78 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000a00ul, 2ul, 0ul);
	return 0;
}