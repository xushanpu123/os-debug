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
	res = syscall(__NR_socket, 1ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000300, "\x82\xe5\x75\xda\x0d\x2c\x39\x91\x6d\x3a\x0f\xa4\xc9\xb9\x3a\x7c", 16);
*(uint64_t*)0x20000310 = 0;
*(uint64_t*)0x20000318 = 0;
*(uint64_t*)0x20000320 = 0;
*(uint32_t*)0x20000328 = 0;
*(uint64_t*)0x20000330 = 0;
*(uint32_t*)0x20000338 = 0;
*(uint64_t*)0x20000340 = 0;
*(uint64_t*)0x20000348 = 0;
*(uint64_t*)0x20000350 = 0;
*(uint64_t*)0x20000358 = 0;
*(uint64_t*)0x20000360 = 0;
*(uint64_t*)0x20000368 = 0;
*(uint64_t*)0x20000370 = 0;
*(uint64_t*)0x20000378 = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint64_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0;
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint64_t*)0x200003b0 = 0;
*(uint64_t*)0x200003b8 = 0;
*(uint64_t*)0x200003c0 = 0;
	syscall(__NR_ioctl, r[0], 0xc0c89425, 0x20000300ul);
	return 0;
}
