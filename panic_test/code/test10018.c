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
memcpy((void*)0x200010c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200010c0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000780 = 0;
*(uint64_t*)0x20000788 = 0;
*(uint16_t*)0x20000790 = 0;
*(uint16_t*)0x20000792 = 0;
*(uint32_t*)0x20000794 = 0;
	syscall(__NR_write, r[0], 0x20000780ul, 0x18ul);
sprintf((char*)0x20000080, "%023llo", (long long)0);
*(uint8_t*)0x20000097 = 0x20;
sprintf((char*)0x20000098, "%023llo", (long long)0);
*(uint8_t*)0x200000af = 0x20;
sprintf((char*)0x200000b0, "%023llo", (long long)0);
*(uint8_t*)0x200000c7 = 0;
	syscall(__NR_write, r[0], 0x20000080ul, 0xfffffeb2ul);
	return 0;
}
