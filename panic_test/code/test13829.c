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

#ifndef __NR_io_uring_register
#define __NR_io_uring_register 427
#endif
#ifndef __NR_io_uring_setup
#define __NR_io_uring_setup 425
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000098 = -1;
memset((void*)0x2000009c, 0, 12);
	syscall(__NR_io_uring_setup, 0, 0x20000080ul);
*(uint32_t*)0x20003404 = 0;
*(uint32_t*)0x20003408 = 0;
*(uint32_t*)0x2000340c = 0;
*(uint32_t*)0x20003410 = 0;
*(uint32_t*)0x20003418 = -1;
memset((void*)0x2000341c, 0, 12);
	res = syscall(__NR_io_uring_setup, 0x3a39, 0x20003400ul);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0;
*(uint8_t*)0x20000001 = 0;
*(uint16_t*)0x20000002 = 0;
memset((void*)0x20000004, 0, 12);
	syscall(__NR_io_uring_register, r[0], 8ul, 0x20000000ul, 0x2aul);
	return 0;
}