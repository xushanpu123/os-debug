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
	syscall(__NR_shmctl, -1, 0xdul, 0x20000000ul);
	syscall(__NR_shmat, -1, 0x20ffa000ul, 0x3000ul);
	syscall(__NR_shmget, 0ul, 0x3000ul, 0ul, 0x20ffd000ul);
	syscall(__NR_shmget, 0x798dd814ul, 0x4000ul, 0x80ul, 0x20ffb000ul);
	res = syscall(__NR_shmget, 0ul, 0x2000ul, 0x20ul, 0x20ffb000ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_shmat, r[0], 0x20ffa000ul, 0x2000ul);
	syscall(__NR_shmat, 0, 0x20000000ul, 0x6000ul);
*(uint32_t*)0x200000c0 = 0;
*(uint64_t*)0x200001c0 = 0x77359400;
*(uint64_t*)0x200001c8 = 0;
	syscall(__NR_futex, 0x200000c0ul, 6ul, 0, 0x200001c0ul, 0ul, 0);
	return 0;
}
