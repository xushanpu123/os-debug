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
*(uint64_t*)0x20002fc0 = 0;
*(uint32_t*)0x20002fc8 = 0;
*(uint64_t*)0x20002fd0 = 0;
*(uint64_t*)0x20002fd8 = 0;
*(uint64_t*)0x20002fe0 = 0;
*(uint64_t*)0x20002fe8 = 0x28;
*(uint32_t*)0x20002ff0 = 0;
*(uint32_t*)0x20002ff8 = 0;
	syscall(__NR_sendmmsg, -1, 0x20002fc0ul, 1ul, 0ul);
	res = syscall(__NR_socketpair, 1ul, 5ul, 0, 0x20000100ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000104;
*(uint64_t*)0x20000b00 = 0;
*(uint32_t*)0x20000b08 = 0;
*(uint64_t*)0x20000b10 = 0;
*(uint64_t*)0x20000b18 = 0;
*(uint64_t*)0x20000b20 = 0;
*(uint64_t*)0x20000b28 = 0;
*(uint32_t*)0x20000b30 = 0;
*(uint32_t*)0x20000b38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000b00ul, 0x4000000000003a2ul, 0ul);
	return 0;
}
