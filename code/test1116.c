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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x200000c0ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x200000c0;
r[1] = *(uint32_t*)0x200000c4;
	}
*(uint64_t*)0x200028c0 = 0;
*(uint32_t*)0x200028c8 = 0;
*(uint64_t*)0x200028d0 = 0;
*(uint64_t*)0x200028d8 = 0;
*(uint64_t*)0x200028e0 = 0;
*(uint64_t*)0x200028e8 = 0;
*(uint32_t*)0x200028f0 = 0;
*(uint32_t*)0x200028f8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200028c0ul, 0x4000000000001b1ul, 0ul);
*(uint64_t*)0x20000080 = 0x1ff;
	syscall(__NR_ioctl, r[0], 0x5452, 0x20000080ul);
*(uint32_t*)0x20000140 = r[0];
*(uint16_t*)0x20000144 = 4;
*(uint16_t*)0x20000146 = 0;
*(uint32_t*)0x20000148 = r[1];
*(uint16_t*)0x2000014c = 0xa004;
*(uint16_t*)0x2000014e = 0;
	syscall(__NR_ppoll, 0x20000140ul, 2ul, 0ul, 0ul, 0ul);
	return 0;
}
