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
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint8_t*)0x20000100 = 0xfe;
*(uint8_t*)0x20000101 = 0x80;
memset((void*)0x20000102, 0, 13);
*(uint8_t*)0x2000010f = 0;
*(uint8_t*)0x20000110 = 0xfe;
*(uint8_t*)0x20000111 = 0x80;
memset((void*)0x20000112, 0, 13);
*(uint8_t*)0x2000011f = 0;
*(uint64_t*)0x20000120 = htobe64(0);
*(uint64_t*)0x20000128 = htobe64(1);
*(uint32_t*)0x20000130 = 0;
*(uint16_t*)0x20000134 = 0x7f;
*(uint16_t*)0x20000136 = 0;
*(uint32_t*)0x20000138 = 0;
*(uint64_t*)0x20000140 = 0;
*(uint32_t*)0x20000148 = 0x1000038;
*(uint32_t*)0x2000014c = 0;
	syscall(__NR_ioctl, r[0], 0x890c, 0x20000100ul);
	return 0;
}
