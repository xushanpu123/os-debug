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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002f40 = 0x200000c0;
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e23);
*(uint32_t*)0x200000c4 = htobe32(0xe0000001);
*(uint32_t*)0x20002f48 = 0x10;
*(uint64_t*)0x20002f50 = 0;
*(uint64_t*)0x20002f58 = 0;
*(uint64_t*)0x20002f60 = 0x20000600;
*(uint64_t*)0x20000600 = 0x1c;
*(uint32_t*)0x20000608 = 0;
*(uint32_t*)0x2000060c = 8;
*(uint32_t*)0x20000610 = 0;
*(uint32_t*)0x20000614 = htobe32(0x7f000001);
*(uint32_t*)0x20000618 = htobe32(0xe0000002);
*(uint64_t*)0x20002f68 = 0x20;
*(uint32_t*)0x20002f70 = 0;
*(uint32_t*)0x20002f78 = 0;
*(uint64_t*)0x20002f80 = 0x20000640;
*(uint16_t*)0x20000640 = 2;
*(uint16_t*)0x20000642 = htobe16(0x4e22);
*(uint8_t*)0x20000644 = 0xac;
*(uint8_t*)0x20000645 = 0x14;
*(uint8_t*)0x20000646 = 0x14;
*(uint8_t*)0x20000647 = 0xaa;
*(uint32_t*)0x20002f88 = 0x10;
*(uint64_t*)0x20002f90 = 0;
*(uint64_t*)0x20002f98 = 0;
*(uint64_t*)0x20002fa0 = 0x20000040;
*(uint64_t*)0x20000040 = 0x18;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 7;
*(uint8_t*)0x20000050 = 0x94;
*(uint8_t*)0x20000051 = 4;
*(uint16_t*)0x20000052 = 0x8000;
*(uint8_t*)0x20000054 = 7;
*(uint8_t*)0x20000055 = 3;
*(uint8_t*)0x20000056 = 0;
*(uint64_t*)0x20002fa8 = 0x18;
*(uint32_t*)0x20002fb0 = 0;
*(uint32_t*)0x20002fb8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002f40ul, 2ul, 0ul);
	return 0;
}
