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
	res = syscall(__NR_socket, 0xaul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x200003c0 = 0xfe;
*(uint8_t*)0x200003c1 = 0x80;
memset((void*)0x200003c2, 0, 13);
*(uint8_t*)0x200003cf = 0;
memset((void*)0x200003d0, 0, 10);
memset((void*)0x200003da, 255, 2);
*(uint8_t*)0x200003dc = 0xac;
*(uint8_t*)0x200003dd = 0x1e;
*(uint8_t*)0x200003de = 0;
*(uint8_t*)0x200003df = 1;
*(uint64_t*)0x200003e0 = htobe64(0);
*(uint64_t*)0x200003e8 = htobe64(1);
*(uint32_t*)0x200003f0 = 0;
*(uint16_t*)0x200003f4 = 0x24f;
*(uint16_t*)0x200003f6 = 0;
*(uint32_t*)0x200003f8 = 0;
*(uint64_t*)0x20000400 = 0;
*(uint32_t*)0x20000408 = 0x1140164;
*(uint32_t*)0x2000040c = 0;
	syscall(__NR_ioctl, r[0], 0x890c, 0x200003c0ul);
	return 0;
}
