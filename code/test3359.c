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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint32_t*)0x20000240 = 0x798e2635;
*(uint32_t*)0x20000244 = 0;
*(uint32_t*)0x20000248 = -1;
*(uint32_t*)0x2000024c = -1;
*(uint32_t*)0x20000250 = 0xee01;
*(uint32_t*)0x20000254 = 0;
*(uint16_t*)0x20000258 = 0;
*(uint32_t*)0x2000025c = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint64_t*)0x20000270 = 0;
*(uint32_t*)0x20000278 = 0;
*(uint32_t*)0x2000027c = 0;
*(uint16_t*)0x20000280 = 0;
*(uint16_t*)0x20000282 = 0;
*(uint64_t*)0x20000288 = 0;
*(uint64_t*)0x20000290 = 0;
	syscall(__NR_shmctl, 0, 1ul, 0x20000240ul);
	return 0;
}
