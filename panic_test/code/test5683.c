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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000040 = 0xfc;
*(uint8_t*)0x20000041 = 0;
memset((void*)0x20000042, 0, 13);
*(uint8_t*)0x2000004f = 0;
*(uint32_t*)0x20000050 = 0;
*(uint8_t*)0x20000054 = 0;
*(uint8_t*)0x20000055 = -1;
*(uint16_t*)0x20000056 = 9;
*(uint16_t*)0x20000058 = 0;
*(uint16_t*)0x2000005a = 0;
*(uint32_t*)0x2000005c = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x20, 0x20000040ul, 0x20ul);
*(uint8_t*)0x200000c0 = 0xfe;
*(uint8_t*)0x200000c1 = 0x80;
memset((void*)0x200000c2, 0, 13);
*(uint8_t*)0x200000cf = 0xaa;
*(uint32_t*)0x200000d0 = 0;
*(uint8_t*)0x200000d4 = 0;
*(uint8_t*)0x200000d5 = 1;
*(uint16_t*)0x200000d6 = 1;
*(uint16_t*)0x200000d8 = 0;
*(uint16_t*)0x200000da = 0;
*(uint32_t*)0x200000dc = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x20, 0x200000c0ul, 0x20ul);
	res = syscall(__NR_dup2, r[0], r[0]);
	if (res != -1)
		r[1] = res;
*(uint8_t*)0x20000000 = 0xfe;
*(uint8_t*)0x20000001 = 0x80;
memset((void*)0x20000002, 0, 13);
*(uint8_t*)0x2000000f = 0;
*(uint32_t*)0x20000010 = 0;
*(uint8_t*)0x20000014 = 2;
*(uint8_t*)0x20000015 = 0;
*(uint16_t*)0x20000016 = 0;
*(uint16_t*)0x20000018 = 0;
*(uint16_t*)0x2000001a = 0;
*(uint32_t*)0x2000001c = 0;
	syscall(__NR_setsockopt, r[1], 0x29, 0x20, 0x20000000ul, 0x20ul);
	return 0;
}
