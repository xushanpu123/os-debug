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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				syscall(__NR_socket, 0x11ul, 3ul, 0x300);
memcpy((void*)0x20000040, "/proc/tty/ldiscs\000", 17);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000040ul, 0ul, 0ul);
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint64_t*)0x20000190 = 0;
*(uint64_t*)0x20000198 = 0;
*(uint64_t*)0x200001a0 = 0;
*(uint64_t*)0x200001a8 = 0;
*(uint64_t*)0x200001b0 = 0;
*(uint64_t*)0x200001b8 = 0;
*(uint64_t*)0x20000200 = 4;
*(uint64_t*)0x20000208 = 0;
*(uint64_t*)0x20000210 = 0;
*(uint64_t*)0x20000218 = 0;
*(uint64_t*)0x20000220 = 0;
*(uint64_t*)0x20000228 = 0;
*(uint64_t*)0x20000230 = 0;
*(uint64_t*)0x20000238 = 0;
*(uint64_t*)0x20000240 = 0x1f;
*(uint64_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0;
*(uint64_t*)0x20000258 = 0;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint64_t*)0x20000270 = 0;
*(uint64_t*)0x20000278 = 0;
	syscall(__NR_pselect6, 0x40ul, 0x20000180ul, 0x20000200ul, 0x20000240ul, 0ul, 0ul);
	return 0;
}