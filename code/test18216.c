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
*(uint32_t*)0x20001380 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20001380ul, 4ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint16_t*)0x20000180 = 0xa;
*(uint16_t*)0x20000182 = htobe16(0);
*(uint32_t*)0x20000184 = htobe32(0);
*(uint64_t*)0x20000188 = htobe64(0);
*(uint64_t*)0x20000190 = htobe64(1);
*(uint32_t*)0x20000198 = 0;
*(uint8_t*)0x20000200 = 0;
*(uint8_t*)0x20000201 = 0;
*(uint16_t*)0x20000202 = 0x47;
*(uint32_t*)0x20000204 = 0;
memcpy((void*)0x20000208, "\x0e\xff\x9b\x7c\x49\x5d\x82\xc2\x1a\x0c\x28\xa0\x64\x29\x35\xe0\xff\x02\xf9\x89\x55\xf8\x1d\xcf\x3f\x40\x7d\xee\xd1\x86\xe5\x62\xc8\x29\x97\x0c\x15\x18\x18\xb4\xef\x38\x93\x8f\xf2\xca\x6f\xa6\x1a\xe3\xc5\x6d\x6f\xe8\x57\x87\x5b\x49\x35\x3c\x75\x4e\x3b\xbc\x86\x5f\xf5\x62\xce\xcf\x04\x83\x34\x29\xd6\x4e\x61\x77\x47\xb9", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000180ul, 0xd8ul);
*(uint32_t*)0x20000140 = 0;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20000140ul, 4ul);
	return 0;
}
