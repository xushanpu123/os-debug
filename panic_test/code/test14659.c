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

uint64_t r[4] = {0x0, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_io_setup, 0x7f, 0x20000100ul);
	if (res != -1)
r[0] = *(uint64_t*)0x20000100;
memcpy((void*)0x20000280, "/proc/meminfo\000", 14);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000280ul, 0ul, 0ul);
	if (res != -1)
		r[1] = res;
memcpy((void*)0x20000280, "/proc/meminfo\000", 14);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000280ul, 0ul, 0ul);
	if (res != -1)
		r[2] = res;
memcpy((void*)0x20000480, "/proc/meminfo\000", 14);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000480ul, 0ul, 0ul);
	if (res != -1)
		r[3] = res;
*(uint64_t*)0x20000500 = 0x20000240;
*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint32_t*)0x2000024c = 0;
*(uint16_t*)0x20000250 = 0;
*(uint16_t*)0x20000252 = 0;
*(uint32_t*)0x20000254 = r[1];
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint64_t*)0x20000270 = 0;
*(uint32_t*)0x20000278 = 0;
*(uint32_t*)0x2000027c = -1;
*(uint64_t*)0x20000508 = 0x200004c0;
*(uint64_t*)0x200004c0 = 0;
*(uint32_t*)0x200004c8 = 0;
*(uint32_t*)0x200004cc = 0;
*(uint16_t*)0x200004d0 = 0;
*(uint16_t*)0x200004d2 = 0;
*(uint32_t*)0x200004d4 = r[2];
*(uint64_t*)0x200004d8 = 0;
*(uint64_t*)0x200004e0 = 0;
*(uint64_t*)0x200004e8 = 0;
*(uint64_t*)0x200004f0 = 0;
*(uint32_t*)0x200004f8 = 1;
*(uint32_t*)0x200004fc = r[3];
	syscall(__NR_io_submit, r[0], 2ul, 0x20000500ul);
	return 0;
}
