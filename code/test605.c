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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
*(uint16_t*)0x20000080 = 2;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint16_t*)0x20000090 = 0;
memset((void*)0x20000092, 170, 5);
*(uint8_t*)0x20000097 = 0;
*(uint32_t*)0x200000a0 = 0;
*(uint16_t*)0x200000a4 = 2;
*(uint16_t*)0x200000a6 = htobe16(0);
*(uint8_t*)0x200000a8 = 0xac;
*(uint8_t*)0x200000a9 = 0x14;
*(uint8_t*)0x200000aa = 0x14;
*(uint8_t*)0x200000ab = 0;
memcpy((void*)0x200000b4, "veth1_to_team\000\000\000", 16);
	syscall(__NR_ioctl, r[0], 0x8953, 0x20000080ul);
	return 0;
}
