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

#ifndef __NR_openat2
#define __NR_openat2 437
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "./file0\000", 8);
*(uint64_t*)0x20000100 = 0x189042;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20000110 = 0;
	res = syscall(__NR_openat2, 0xffffff9c, 0x200000c0ul, 0x20000100ul, 0x18ul);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000140 = 0x7f;
*(uint8_t*)0x20000141 = 0x45;
*(uint8_t*)0x20000142 = 0x4c;
*(uint8_t*)0x20000143 = 0x46;
*(uint8_t*)0x20000144 = 0;
*(uint8_t*)0x20000145 = 0;
*(uint8_t*)0x20000146 = 0;
*(uint8_t*)0x20000147 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint16_t*)0x20000150 = 0;
*(uint16_t*)0x20000152 = 0;
*(uint32_t*)0x20000154 = 0;
*(uint32_t*)0x20000158 = 0;
*(uint32_t*)0x2000015c = 0x38;
*(uint32_t*)0x20000160 = 0;
*(uint32_t*)0x20000164 = 0;
*(uint16_t*)0x20000168 = 0;
*(uint16_t*)0x2000016a = 0x20;
*(uint16_t*)0x2000016c = 0;
*(uint16_t*)0x2000016e = 0;
*(uint16_t*)0x20000170 = 0;
*(uint16_t*)0x20000172 = 0;
*(uint32_t*)0x20000178 = 0;
*(uint32_t*)0x2000017c = 0;
*(uint32_t*)0x20000180 = 0;
*(uint32_t*)0x20000184 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000194 = 0;
	syscall(__NR_write, r[0], 0x20000140ul, 0x58ul);
	return 0;
}