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
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000340 = 0;
*(uint16_t*)0x20000348 = 2;
*(uint16_t*)0x2000034a = htobe16(0);
*(uint32_t*)0x2000034c = htobe32(-1);
*(uint16_t*)0x20000358 = 2;
*(uint16_t*)0x2000035a = htobe16(0);
*(uint32_t*)0x2000035c = htobe32(0);
*(uint16_t*)0x20000368 = 2;
*(uint16_t*)0x2000036a = htobe16(0);
*(uint32_t*)0x2000036c = htobe32(0x7f000001);
*(uint16_t*)0x20000378 = 4;
*(uint16_t*)0x2000037a = 0;
*(uint64_t*)0x20000380 = 0;
*(uint64_t*)0x20000388 = 0;
*(uint16_t*)0x20000390 = 0;
*(uint64_t*)0x20000398 = 0x20000300;
memcpy((void*)0x20000300, "sit0\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200003a0 = 0;
*(uint64_t*)0x200003a8 = 0;
*(uint16_t*)0x200003b0 = 0;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000340ul);
	return 0;
}
