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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000000, "lo\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint16_t*)0x20000010 = 2;
*(uint16_t*)0x20000012 = htobe16(0);
*(uint8_t*)0x20000014 = 0xac;
*(uint8_t*)0x20000015 = 0x1e;
*(uint8_t*)0x20000016 = 0;
*(uint8_t*)0x20000017 = 1;
	syscall(__NR_ioctl, r[0], 0x8918, 0x20000000ul);
	return 0;
}
