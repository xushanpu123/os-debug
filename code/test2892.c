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
	res = syscall(__NR_socket, 0xaul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000a80 = 0x20000040;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0x4e23);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x80;
memset((void*)0x2000004a, 0, 13);
*(uint8_t*)0x20000057 = 0xaa;
*(uint32_t*)0x20000058 = 4;
*(uint32_t*)0x20000a88 = 0x1c;
*(uint64_t*)0x20000a90 = 0;
*(uint64_t*)0x20000a98 = 0;
*(uint64_t*)0x20000aa0 = 0x20000880;
*(uint64_t*)0x20000880 = 0x24;
*(uint32_t*)0x20000888 = 0x29;
*(uint32_t*)0x2000088c = 0x32;
*(uint8_t*)0x20000890 = 0xfe;
*(uint8_t*)0x20000891 = 0x80;
memset((void*)0x20000892, 0, 13);
*(uint8_t*)0x2000089f = 0;
*(uint32_t*)0x200008a0 = 0;
*(uint64_t*)0x20000aa8 = 0x28;
*(uint32_t*)0x20000ab0 = 0;
*(uint32_t*)0x20000ab8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000a80ul, 1ul, 0ul);
	return 0;
}
