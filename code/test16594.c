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
	res = syscall(__NR_socket, 0xaul, 3ul, 7);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0xfc;
*(uint8_t*)0x20000001 = 2;
memset((void*)0x20000002, 0, 13);
*(uint8_t*)0x2000000f = 0;
memcpy((void*)0x20000010, " \001\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
memset((void*)0x20000020, 0, 16);
*(uint32_t*)0x20000030 = 0;
*(uint16_t*)0x20000034 = 0x40;
*(uint16_t*)0x20000036 = 0;
*(uint32_t*)0x20000038 = 0;
*(uint64_t*)0x20000040 = 0;
*(uint32_t*)0x20000048 = 0x38c0001;
*(uint32_t*)0x2000004c = 0;
	syscall(__NR_ioctl, r[0], 0x890c, 0x20000000ul);
	return 0;
}
