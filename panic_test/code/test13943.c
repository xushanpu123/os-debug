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

*(uint64_t*)0x20000240 = 0;
*(uint32_t*)0x20000248 = 0;
*(uint64_t*)0x20000250 = 0x20000200;
*(uint64_t*)0x20000200 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0x1c;
*(uint16_t*)0x200001c4 = 0;
*(uint16_t*)0x200001c6 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint8_t*)0x200001d0 = 0x30;
*(uint8_t*)0x200001d1 = 0;
*(uint16_t*)0x200001d2 = 0;
*(uint16_t*)0x200001d4 = 5;
*(uint16_t*)0x200001d6 = 0x33;
*(uint8_t*)0x200001d8 = 0;
*(uint64_t*)0x20000208 = 0x1c;
*(uint64_t*)0x20000258 = 1;
*(uint64_t*)0x20000260 = 0;
*(uint64_t*)0x20000268 = 0;
*(uint32_t*)0x20000270 = 0;
	syscall(__NR_sendmsg, -1, 0x20000240ul, 0ul);
*(uint64_t*)0x20000340 = 0x20001440;
*(uint64_t*)0x20000348 = 0xdd;
*(uint64_t*)0x20000350 = 0;
*(uint64_t*)0x20000358 = 0;
	syscall(__NR_process_vm_readv, 0, 0x20000140ul, 0x10000000000000e9ul, 0x20000340ul, 2ul, 0ul);
	return 0;
}