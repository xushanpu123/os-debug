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
*(uint64_t*)0x20000880 = 0x20000100;
*(uint16_t*)0x20000100 = 2;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = htobe32(0);
*(uint32_t*)0x20000888 = 0x10;
*(uint64_t*)0x20000890 = 0;
*(uint64_t*)0x20000898 = 0;
*(uint64_t*)0x200008a0 = 0x20000640;
*(uint64_t*)0x20000640 = 0x14;
*(uint32_t*)0x20000648 = 0;
*(uint32_t*)0x2000064c = 1;
*(uint32_t*)0x20000650 = 0;
*(uint64_t*)0x200008a8 = 0xff1a;
*(uint32_t*)0x200008b0 = 0;
*(uint32_t*)0x200008b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000880ul, 1ul, 0ul);
	return 0;
}
