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

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_pipe, 0x20000000ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000000;
r[1] = *(uint32_t*)0x20000004;
	}
	res = syscall(__NR_pipe, 0x20000000ul);
	if (res != -1)
r[2] = *(uint32_t*)0x20000004;
*(uint8_t*)0x20000480 = 0x7f;
*(uint8_t*)0x20000481 = 0x45;
*(uint8_t*)0x20000482 = 0x4c;
*(uint8_t*)0x20000483 = 0x46;
*(uint8_t*)0x20000484 = 0;
*(uint8_t*)0x20000485 = 0;
*(uint8_t*)0x20000486 = 0;
*(uint8_t*)0x20000487 = 0;
*(uint64_t*)0x20000488 = 0;
*(uint16_t*)0x20000490 = 0;
*(uint16_t*)0x20000492 = 0;
*(uint32_t*)0x20000494 = 0;
*(uint32_t*)0x20000498 = 0;
*(uint32_t*)0x2000049c = 0x38;
*(uint32_t*)0x200004a0 = 0;
*(uint32_t*)0x200004a4 = 0;
*(uint16_t*)0x200004a8 = 0;
*(uint16_t*)0x200004aa = 0x20;
*(uint16_t*)0x200004ac = 0;
*(uint16_t*)0x200004ae = 0;
*(uint16_t*)0x200004b0 = 0;
*(uint16_t*)0x200004b2 = 0;
*(uint32_t*)0x200004b8 = 0;
*(uint32_t*)0x200004bc = 0;
*(uint32_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c4 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint32_t*)0x200004cc = 0;
*(uint32_t*)0x200004d0 = 0;
*(uint32_t*)0x200004d4 = 0;
	syscall(__NR_write, r[1], 0x20000480ul, 0x58ul);
*(uint64_t*)0x20000040 = 0x401;
	syscall(__NR_ioctl, r[0], 0x5421, 0x20000040ul);
	syscall(__NR_splice, r[0], 0ul, r[2], 0ul, 0x1eul, 0ul);
	return 0;
}