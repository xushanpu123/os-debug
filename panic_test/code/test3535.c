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
memcpy((void*)0x200063c0, "batadv0\000\000\000\000\000\000\000\000\000", 16);
	syscall(__NR_ioctl, -1, 0x8933, 0x200063c0ul);
*(uint64_t*)0x200001c0 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint64_t*)0x200001d0 = 0x20000180;
*(uint64_t*)0x20000180 = 0x20000140;
*(uint64_t*)0x20000188 = 0x24;
*(uint64_t*)0x200001d8 = 1;
*(uint64_t*)0x200001e0 = 0;
*(uint64_t*)0x200001e8 = 0;
*(uint32_t*)0x200001f0 = 0;
	syscall(__NR_sendmsg, -1, 0x200001c0ul, 0x8801ul);
memcpy((void*)0x20000000, "/dev/snd/seq\000", 13);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000080 = 0;
*(uint32_t*)0x20000084 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
*(uint32_t*)0x20000090 = 0;
*(uint32_t*)0x20000094 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x2000009c = 0;
memset((void*)0x200000a0, 0, 64);
	syscall(__NR_ioctl, r[0], 0xc0605345, 0x20000080ul);
	return 0;
}