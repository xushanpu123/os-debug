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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000000 = 0xfe;
*(uint8_t*)0x20000001 = 0x88;
memset((void*)0x20000002, 0, 12);
*(uint8_t*)0x2000000e = 0;
*(uint8_t*)0x2000000f = 1;
*(uint32_t*)0x20000010 = 0;
*(uint8_t*)0x20000014 = 0;
*(uint8_t*)0x20000015 = -1;
*(uint16_t*)0x20000016 = 3;
*(uint16_t*)0x20000018 = 0x8000;
*(uint16_t*)0x2000001a = 0xfc01;
*(uint32_t*)0x2000001c = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x20, 0x20000000ul, 0x20ul);
	return 0;
}
