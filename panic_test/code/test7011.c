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
	res = syscall(__NR_socket, 0xaul, 3ul, 6);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
*(uint8_t*)0x20000008 = 0xfe;
*(uint8_t*)0x20000009 = 0x80;
memset((void*)0x2000000a, 0, 13);
*(uint8_t*)0x20000017 = 0;
*(uint32_t*)0x20000018 = 1;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint64_t*)0x20004340 = 0;
*(uint32_t*)0x20004348 = 0;
*(uint64_t*)0x20004350 = 0;
*(uint64_t*)0x20004358 = 0;
*(uint64_t*)0x20004360 = 0;
*(uint64_t*)0x20004368 = 0;
*(uint32_t*)0x20004370 = 0;
*(uint32_t*)0x20004378 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20004340ul, 1ul, 0x4008004ul);
*(uint64_t*)0x20003240 = 0;
*(uint32_t*)0x20003248 = 0;
*(uint64_t*)0x20003250 = 0x20000480;
*(uint64_t*)0x20000480 = 0x200000c0;
memcpy((void*)0x200000c0, "\x0c\xce\x0f\x6a", 4);
*(uint64_t*)0x20000488 = 4;
*(uint64_t*)0x20003258 = 1;
*(uint64_t*)0x20003260 = 0;
*(uint64_t*)0x20003268 = 0;
*(uint32_t*)0x20003270 = 0;
*(uint32_t*)0x20003278 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003240ul, 1ul, 0ul);
	return 0;
}
