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

*(uint32_t*)0x20000900 = 0x798e2633;
*(uint32_t*)0x20000904 = -1;
*(uint32_t*)0x20000908 = 0;
*(uint32_t*)0x2000090c = 0;
*(uint32_t*)0x20000910 = 0;
*(uint32_t*)0x20000914 = 0;
*(uint16_t*)0x20000918 = 0;
*(uint32_t*)0x2000091c = 0;
*(uint64_t*)0x20000920 = 0;
*(uint64_t*)0x20000928 = 0;
*(uint64_t*)0x20000930 = 0;
*(uint32_t*)0x20000938 = 0;
*(uint32_t*)0x2000093c = 0;
*(uint16_t*)0x20000940 = 0;
*(uint16_t*)0x20000942 = 0;
*(uint64_t*)0x20000948 = 0;
*(uint64_t*)0x20000950 = 0;
	syscall(__NR_shmctl, 0, 1ul, 0x20000900ul);
	return 0;
}
