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

memcpy((void*)0x20000000, "/dev/sr0\000", 9);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x802ul, 0ul);
*(uint8_t*)0x20000040 = 0xfe;
*(uint8_t*)0x20000041 = 0x80;
memset((void*)0x20000042, 0, 13);
*(uint8_t*)0x2000004f = 0xaa;
*(uint64_t*)0x20000050 = htobe64(0);
*(uint64_t*)0x20000058 = htobe64(1);
	syscall(__NR_ioctl, -1, 0x89e1, 0x20000040ul);
	return 0;
}
