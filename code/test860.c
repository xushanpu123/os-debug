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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000580, "/dev/rtc0\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000580ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint32_t*)0x200005c0 = r[0];
*(uint16_t*)0x200005c4 = 0;
*(uint16_t*)0x200005c6 = 0;
*(uint32_t*)0x200005c8 = r[1];
*(uint16_t*)0x200005cc = 0;
*(uint16_t*)0x200005ce = 0;
	syscall(__NR_poll, 0x200005c0ul, 2ul, 0);
	return 0;
}