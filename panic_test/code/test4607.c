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
	res = syscall(__NR_socketpair, 1ul, 5ul, 0, 0x20000040ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000040;
r[1] = *(uint32_t*)0x20000044;
	}
*(uint64_t*)0x200067c0 = 0;
*(uint32_t*)0x200067c8 = 0;
*(uint64_t*)0x200067d0 = 0;
*(uint64_t*)0x200067d8 = 0;
*(uint64_t*)0x200067e0 = 0;
*(uint64_t*)0x200067e8 = 0;
*(uint32_t*)0x200067f0 = 0;
*(uint32_t*)0x200067f8 = 0;
	syscall(__NR_sendmmsg, r[1], 0x200067c0ul, 1ul, 0ul);
*(uint64_t*)0x20002f00 = 0x20000100;
*(uint32_t*)0x20002f08 = 0x6e;
*(uint64_t*)0x20002f10 = 0x20000000;
*(uint64_t*)0x20000000 = 0x20000180;
*(uint64_t*)0x20000008 = 0x1000;
*(uint64_t*)0x20002f18 = 1;
*(uint64_t*)0x20002f20 = 0x20001200;
*(uint64_t*)0x20002f28 = 0;
*(uint32_t*)0x20002f30 = 0;
*(uint32_t*)0x20002f38 = 0;
*(uint64_t*)0x20002f40 = 0;
*(uint32_t*)0x20002f48 = 0;
*(uint64_t*)0x20002f50 = 0x200028c0;
*(uint64_t*)0x200028c0 = 0;
*(uint64_t*)0x200028c8 = 0;
*(uint64_t*)0x200028d0 = 0;
*(uint64_t*)0x200028d8 = 0;
*(uint64_t*)0x200028e0 = 0;
*(uint64_t*)0x200028e8 = 0;
*(uint64_t*)0x200028f0 = 0;
*(uint64_t*)0x200028f8 = 0;
*(uint64_t*)0x20002900 = 0;
*(uint64_t*)0x20002908 = 0;
*(uint64_t*)0x20002910 = 0;
*(uint64_t*)0x20002918 = 0;
*(uint64_t*)0x20002920 = 0;
*(uint64_t*)0x20002928 = 0;
*(uint64_t*)0x20002930 = 0;
*(uint64_t*)0x20002938 = 0;
*(uint64_t*)0x20002940 = 0;
*(uint64_t*)0x20002948 = 0;
*(uint64_t*)0x20002f58 = 9;
*(uint64_t*)0x20002f60 = 0;
*(uint64_t*)0x20002f68 = 0;
*(uint32_t*)0x20002f70 = 0;
*(uint32_t*)0x20002f78 = 0;
*(uint64_t*)0x20002fc0 = 0x77359400;
*(uint64_t*)0x20002fc8 = 0;
	syscall(__NR_recvmmsg, r[0], 0x20002f00ul, 0x4000000000001bcul, 0x40002002ul, 0x20002fc0ul);
	return 0;
}
