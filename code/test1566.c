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
*(uint8_t*)0x20000000 = 0;
*(uint8_t*)0x20000001 = 0;
memset((void*)0x20000002, 0, 6);
	syscall(__NR_setsockopt, r[0], 0x29, 0x36, 0x20000000ul, 8ul);
*(uint16_t*)0x20000340 = 0xa;
*(uint16_t*)0x20000342 = 0;
*(uint32_t*)0x20000344 = htobe32(0);
*(uint8_t*)0x20000348 = 0xfe;
*(uint8_t*)0x20000349 = 0x80;
memset((void*)0x2000034a, 0, 13);
*(uint8_t*)0x20000357 = 0xaa;
*(uint32_t*)0x20000358 = 2;
*(uint32_t*)0x2000035c = 0;
	syscall(__NR_connect, r[0], 0x20000340ul, 0x80ul);
*(uint64_t*)0x20000400 = 0;
*(uint32_t*)0x20000408 = 0xffffff93;
*(uint64_t*)0x20000410 = 0x20000040;
*(uint64_t*)0x20000040 = 0;
*(uint64_t*)0x20000048 = 0x5b;
*(uint64_t*)0x20000418 = 1;
*(uint64_t*)0x20000420 = 0;
*(uint64_t*)0x20000428 = 0;
*(uint32_t*)0x20000430 = 0;
	syscall(__NR_sendmsg, r[0], 0x20000400ul, 0ul);
	return 0;
}
