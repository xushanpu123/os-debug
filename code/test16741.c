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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x200000c0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x200000c0;
*(uint64_t*)0x200028c0 = 0;
*(uint32_t*)0x200028c8 = 0;
*(uint64_t*)0x200028d0 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000040;
memset((void*)0x20000040, 159, 1);
*(uint64_t*)0x20000088 = 0xff52;
*(uint64_t*)0x200028d8 = 0x19d;
*(uint64_t*)0x200028e0 = 0x20001180;
*(uint64_t*)0x20001180 = 0x14;
*(uint32_t*)0x20001188 = 1;
*(uint32_t*)0x2000118c = 1;
*(uint32_t*)0x20001190 = r[0];
*(uint64_t*)0x200028e8 = 0x18;
*(uint32_t*)0x200028f0 = 0;
*(uint32_t*)0x200028f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200028c0ul, 1ul, 0ul);
	return 0;
}
