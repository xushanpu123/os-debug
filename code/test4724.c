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
*(uint32_t*)0x20002140 = htobe32(0);
*(uint64_t*)0x20002150 = htobe64(0);
*(uint64_t*)0x20002158 = htobe64(1);
*(uint16_t*)0x20002160 = htobe16(0);
*(uint16_t*)0x20002162 = htobe16(0);
*(uint16_t*)0x20002164 = htobe16(0);
*(uint16_t*)0x20002166 = htobe16(0);
*(uint16_t*)0x20002168 = 0xa;
*(uint8_t*)0x2000216a = 0;
*(uint8_t*)0x2000216b = 0xa0;
*(uint8_t*)0x2000216c = 0;
*(uint32_t*)0x20002170 = 0;
*(uint32_t*)0x20002174 = 0xee01;
*(uint64_t*)0x20002178 = 0;
*(uint64_t*)0x20002180 = 0;
*(uint64_t*)0x20002188 = 0;
*(uint64_t*)0x20002190 = 0;
*(uint64_t*)0x20002198 = 0;
*(uint64_t*)0x200021a0 = 0;
*(uint64_t*)0x200021a8 = 0;
*(uint64_t*)0x200021b0 = 0;
*(uint64_t*)0x200021b8 = 0;
*(uint64_t*)0x200021c0 = 0;
*(uint64_t*)0x200021c8 = 0;
*(uint64_t*)0x200021d0 = 0;
*(uint32_t*)0x200021d8 = 0;
*(uint32_t*)0x200021dc = 0;
*(uint8_t*)0x200021e0 = 0;
*(uint8_t*)0x200021e1 = 0;
*(uint8_t*)0x200021e2 = 0;
*(uint8_t*)0x200021e3 = 0;
memset((void*)0x200021e8, 0, 16);
*(uint32_t*)0x200021f8 = htobe32(0);
*(uint8_t*)0x200021fc = 0;
*(uint16_t*)0x20002200 = 0;
*(uint8_t*)0x20002204 = 0xac;
*(uint8_t*)0x20002205 = 0x1e;
*(uint8_t*)0x20002206 = 0;
*(uint8_t*)0x20002207 = 1;
*(uint32_t*)0x20002214 = 0;
*(uint8_t*)0x20002218 = 0;
*(uint8_t*)0x20002219 = 0;
*(uint8_t*)0x2000221a = 0;
*(uint32_t*)0x2000221c = 0;
*(uint32_t*)0x20002220 = 0;
*(uint32_t*)0x20002224 = 0;
	syscall(__NR_setsockopt, r[0], 0x29, 0x23, 0x20002140ul, 0xe8ul);
	return 0;
}
