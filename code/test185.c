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
*(uint64_t*)0x200009c0 = 0x20000080;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint64_t*)0x20000088 = htobe64(0);
*(uint64_t*)0x20000090 = htobe64(1);
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x200009c8 = 0x1c;
*(uint64_t*)0x200009d0 = 0;
*(uint64_t*)0x200009d8 = 0;
*(uint64_t*)0x200009e0 = 0;
*(uint64_t*)0x200009e8 = 0;
*(uint32_t*)0x200009f0 = 0;
*(uint32_t*)0x200009f8 = 0;
*(uint64_t*)0x20000a00 = 0x20000040;
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfc;
*(uint8_t*)0x20000049 = 0;
memset((void*)0x2000004a, 0, 13);
*(uint8_t*)0x20000057 = 0;
*(uint32_t*)0x20000058 = 0;
*(uint32_t*)0x20000a08 = 0x1c;
*(uint64_t*)0x20000a10 = 0;
*(uint64_t*)0x20000a18 = 0;
*(uint64_t*)0x20000a20 = 0x20000140;
*(uint64_t*)0x20000140 = 0x24;
*(uint32_t*)0x20000148 = 0x29;
*(uint32_t*)0x2000014c = 0x32;
memset((void*)0x20000150, 0, 10);
memset((void*)0x2000015a, 255, 2);
*(uint32_t*)0x2000015c = htobe32(-1);
*(uint32_t*)0x20000160 = 0;
*(uint64_t*)0x20000a28 = 0x28;
*(uint32_t*)0x20000a30 = 0;
*(uint32_t*)0x20000a38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x200009c0ul, 2ul, 0ul);
	return 0;
}