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
*(uint64_t*)0x20001480 = 0x20000080;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0x4e20);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint8_t*)0x20000088 = 0xfe;
*(uint8_t*)0x20000089 = 0x80;
memset((void*)0x2000008a, 0, 13);
*(uint8_t*)0x20000097 = 0;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x20001488 = 0x1c;
*(uint64_t*)0x20001490 = 0;
*(uint64_t*)0x20001498 = 0;
*(uint64_t*)0x200014a0 = 0;
*(uint64_t*)0x200014a8 = 0;
*(uint32_t*)0x200014b0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001480ul, 0x20008004ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0x4e21);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 10);
memset((void*)0x20000012, 255, 2);
*(uint32_t*)0x20000014 = htobe32(0);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x80;
memset((void*)0x2000004a, 0, 13);
*(uint8_t*)0x20000057 = 0xbb;
*(uint32_t*)0x20000058 = 6;
	syscall(__NR_connect, r[0], 0x20000040ul, 0x1cul);
*(uint64_t*)0x20005f80 = 0;
*(uint32_t*)0x20005f88 = 0;
*(uint64_t*)0x20005f90 = 0;
*(uint64_t*)0x20005f98 = 0;
*(uint64_t*)0x20005fa0 = 0;
*(uint64_t*)0x20005fa8 = 0;
*(uint32_t*)0x20005fb0 = 0;
*(uint32_t*)0x20005fb8 = 0;
*(uint64_t*)0x20005fc0 = 0;
*(uint32_t*)0x20005fc8 = 0;
*(uint64_t*)0x20005fd0 = 0;
*(uint64_t*)0x20005fd8 = 0;
*(uint64_t*)0x20005fe0 = 0;
*(uint64_t*)0x20005fe8 = 0;
*(uint32_t*)0x20005ff0 = 0;
*(uint32_t*)0x20005ff8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20005f80ul, 2ul, 0ul);
	return 0;
}
