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

uint64_t r[1] = {0x0};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_msgget, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
sprintf((char*)0x20000240, "%020llu", (long long)-1);
	syscall(__NR_msgsnd, r[0], 0x20000240ul, 0x53ul, 0ul);
*(uint64_t*)0x20001540 = 1;
	syscall(__NR_msgsnd, r[0], 0x20001540ul, 8ul, 0ul);
	syscall(__NR_msgrcv, r[0], 0x20000000ul, 0x9dul, 0ul, 0ul);
	syscall(__NR_msgrcv, r[0], 0x200000c0ul, 0x89ul, 0ul, 0ul);
	return 0;
}