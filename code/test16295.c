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

#ifndef __NR_seccomp
#define __NR_seccomp 317
#endif

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

*(uint16_t*)0x200000c0 = 9;
*(uint64_t*)0x200000c8 = 0x20000000;
*(uint16_t*)0x20000000 = 0x2d;
*(uint8_t*)0x20000002 = 0;
*(uint8_t*)0x20000003 = 7;
*(uint32_t*)0x20000004 = 0;
*(uint16_t*)0x20000008 = 0;
*(uint8_t*)0x2000000a = 0;
*(uint8_t*)0x2000000b = 0;
*(uint32_t*)0x2000000c = 0;
*(uint16_t*)0x20000010 = 0;
*(uint8_t*)0x20000012 = 0;
*(uint8_t*)0x20000013 = 0;
*(uint32_t*)0x20000014 = 0;
*(uint16_t*)0x20000018 = 0;
*(uint8_t*)0x2000001a = 0;
*(uint8_t*)0x2000001b = 0;
*(uint32_t*)0x2000001c = 0;
*(uint16_t*)0x20000020 = 0;
*(uint8_t*)0x20000022 = 0;
*(uint8_t*)0x20000023 = 0;
*(uint32_t*)0x20000024 = 0;
*(uint16_t*)0x20000028 = 0;
*(uint8_t*)0x2000002a = 0;
*(uint8_t*)0x2000002b = 0;
*(uint32_t*)0x2000002c = 0;
*(uint16_t*)0x20000030 = 0;
*(uint8_t*)0x20000032 = 0;
*(uint8_t*)0x20000033 = 0;
*(uint32_t*)0x20000034 = 0;
*(uint16_t*)0x20000038 = 4;
*(uint8_t*)0x2000003a = 0;
*(uint8_t*)0x2000003b = 0;
*(uint32_t*)0x2000003c = 0;
*(uint16_t*)0x20000040 = 6;
*(uint8_t*)0x20000042 = 0;
*(uint8_t*)0x20000043 = 0;
*(uint32_t*)0x20000044 = 0;
	syscall(__NR_seccomp, 1ul, 0ul, 0x200000c0ul);
	return 0;
}
