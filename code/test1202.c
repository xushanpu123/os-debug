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
	res = syscall(__NR_socket, 2ul, 3ul, 2);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000040 = 0;
*(uint16_t*)0x20000048 = 2;
*(uint16_t*)0x2000004a = htobe16(0x4e21);
*(uint32_t*)0x2000004c = htobe32(0);
*(uint16_t*)0x20000058 = 2;
*(uint16_t*)0x2000005a = htobe16(0x4e24);
*(uint8_t*)0x2000005c = 0xac;
*(uint8_t*)0x2000005d = 0x14;
*(uint8_t*)0x2000005e = 0x14;
*(uint8_t*)0x2000005f = 0x1a;
*(uint16_t*)0x20000068 = 2;
*(uint16_t*)0x2000006a = htobe16(0x4e21);
*(uint32_t*)0x2000006c = htobe32(-1);
*(uint16_t*)0x20000078 = 0x2a0;
*(uint16_t*)0x2000007a = 0;
*(uint64_t*)0x20000080 = 0;
*(uint64_t*)0x20000088 = 0;
*(uint16_t*)0x20000090 = 2;
*(uint64_t*)0x20000098 = 0x20000000;
memcpy((void*)0x20000000, "syz_tun\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x200000a0 = 0xffff;
*(uint64_t*)0x200000a8 = 8;
*(uint16_t*)0x200000b0 = 0x200;
	syscall(__NR_ioctl, r[0], 0x890b, 0x20000040ul);
	return 0;
}