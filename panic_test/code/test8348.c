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
	res = syscall(__NR_socket, 0x10ul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000080 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint64_t*)0x20000090 = 0x20000040;
*(uint64_t*)0x20000040 = 0x200000c0;
*(uint32_t*)0x200000c0 = 0x138;
*(uint16_t*)0x200000c4 = 0x10;
*(uint16_t*)0x200000c6 = 1;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint64_t*)0x200000d0 = htobe64(0);
*(uint64_t*)0x200000d8 = htobe64(1);
*(uint32_t*)0x200000e0 = htobe32(0x7f000001);
*(uint16_t*)0x200000f0 = htobe16(0);
*(uint16_t*)0x200000f2 = htobe16(0);
*(uint16_t*)0x200000f4 = htobe16(0);
*(uint16_t*)0x200000f6 = htobe16(0);
*(uint16_t*)0x200000f8 = 0;
*(uint8_t*)0x200000fa = 0;
*(uint8_t*)0x200000fb = 0;
*(uint8_t*)0x200000fc = 0;
*(uint32_t*)0x20000100 = 0;
*(uint32_t*)0x20000104 = -1;
*(uint8_t*)0x20000108 = 0xfc;
*(uint8_t*)0x20000109 = 1;
memset((void*)0x2000010a, 0, 13);
*(uint8_t*)0x20000117 = 0;
*(uint32_t*)0x20000118 = htobe32(0);
*(uint8_t*)0x2000011c = 0x33;
*(uint8_t*)0x20000120 = -1;
*(uint8_t*)0x20000121 = 2;
memset((void*)0x20000122, 0, 13);
*(uint8_t*)0x2000012f = 1;
*(uint64_t*)0x20000130 = 0;
*(uint64_t*)0x20000138 = 0;
*(uint64_t*)0x20000140 = 0;
*(uint64_t*)0x20000148 = 0;
*(uint64_t*)0x20000150 = 0;
*(uint64_t*)0x20000158 = 0;
*(uint64_t*)0x20000160 = 0;
*(uint64_t*)0x20000168 = 0;
*(uint64_t*)0x20000170 = 0;
*(uint64_t*)0x20000178 = 0;
*(uint64_t*)0x20000180 = 0;
*(uint64_t*)0x20000188 = 0;
*(uint32_t*)0x20000190 = 0;
*(uint32_t*)0x20000194 = 0;
*(uint32_t*)0x20000198 = 0;
*(uint32_t*)0x2000019c = 0;
*(uint32_t*)0x200001a0 = 0;
*(uint16_t*)0x200001a4 = 0xa;
*(uint8_t*)0x200001a6 = 0;
*(uint8_t*)0x200001a7 = 0;
*(uint8_t*)0x200001a8 = 0;
*(uint16_t*)0x200001b0 = 0x48;
*(uint16_t*)0x200001b2 = 1;
memcpy((void*)0x200001b4, "michael_mic-generic\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 64);
*(uint32_t*)0x200001f4 = 0xffffffcf;
*(uint64_t*)0x20000048 = 0x138;
*(uint64_t*)0x20000098 = 1;
*(uint64_t*)0x200000a0 = 0;
*(uint64_t*)0x200000a8 = 0;
*(uint32_t*)0x200000b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000080ul, 0ul);
	return 0;
}
