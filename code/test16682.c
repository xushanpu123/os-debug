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
memcpy((void*)0x20000400, "/dev/ptmx\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000400ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x200001c0 = 6;
	syscall(__NR_ioctl, r[0], 0x5420, 0x200001c0ul);
	syscall(__NR_read, r[0], 0x20000200ul, 0xbful);
*(uint64_t*)0x20000180 = 0x200000c0;
*(uint64_t*)0x20000188 = 0xac;
	syscall(__NR_readv, r[0], 0x20000180ul, 1ul);
*(uint16_t*)0x20000000 = 0;
*(uint16_t*)0x20000002 = 0;
*(uint16_t*)0x20000004 = 0;
*(uint16_t*)0x20000006 = 0;
*(uint8_t*)0x20000008 = 0;
memcpy((void*)0x20000009, "\x30\x87\xe5\xcf\xf0\xf7\x0b\xd3", 8);
	syscall(__NR_ioctl, r[0], 0x5408, 0x20000000ul);
	return 0;
}
