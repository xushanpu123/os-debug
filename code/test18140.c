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
*(uint16_t*)0x20000040 = 0xa;
*(uint16_t*)0x20000042 = htobe16(0);
*(uint32_t*)0x20000044 = htobe32(0);
*(uint8_t*)0x20000048 = 0xfe;
*(uint8_t*)0x20000049 = 0x88;
memset((void*)0x2000004a, 0, 12);
*(uint8_t*)0x20000056 = 0;
*(uint8_t*)0x20000057 = 1;
*(uint32_t*)0x20000058 = 0;
*(uint8_t*)0x200000c0 = 0;
*(uint8_t*)0x200000c1 = 0;
*(uint16_t*)0x200000c2 = 5;
*(uint32_t*)0x200000c4 = 0;
memcpy((void*)0x200000c8, "\x6c\x6a\xe5\x1d\x1c\x92\xb4\x5b\x97\xad\x3e\x19\xf5\x3b\xec\x3c\x80\x93\xad\x54\xf5\x07\xde\xb4\x74\x28\x09\xe3\x51\x4f\xdf\xf5\xf9\xbf\xd6\x9a\x85\xe1\x5e\xe7\xed\x93\xd4\xf3\x42\xec\x2f\x6f\x2d\x30\xf8\x54\x7a\x45\x32\x65\x2c\x55\x58\xc7\x03\x18\x41\xe9\x17\xdf\xb9\x00\x07\xd4\x7b\x9d\xa6\xef\x63\x05\x37\xea\xd2\x20", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000040ul, 0xd8ul);
*(uint16_t*)0x20000140 = 0xa;
*(uint16_t*)0x20000142 = htobe16(0);
*(uint32_t*)0x20000144 = htobe32(0);
*(uint8_t*)0x20000148 = 0xfc;
*(uint8_t*)0x20000149 = 0;
memset((void*)0x2000014a, 0, 13);
*(uint8_t*)0x20000157 = 0;
*(uint32_t*)0x20000158 = 0;
*(uint8_t*)0x200001c0 = 0;
*(uint8_t*)0x200001c1 = 0;
*(uint16_t*)0x200001c2 = 0x29;
*(uint32_t*)0x200001c4 = 0;
memcpy((void*)0x200001c8, "\xb4\x1a\x6b\xf9\x33\x52\x7c\x18\x73\x28\xd3\xfd\x52\x80\x2e\x2b\x81\xc1\x0b\xcd\xe5\xe6\x72\x72\x0a\x7f\x03\x0b\xbd\x7a\x2b\xdd\x36\x73\x8c\x0b\xaf\x9e\x69\xbe\x51\x21\x4a\xaa\x2c\xfb\x8a\xb6\x47\xfb\x9d\x0c\x85\x6d\x7b\x0d\xd6\x2a\xf7\xf9\x09\x3b\x75\x26\x4a\x12\xbb\xe9\x11\xbd\xde\x7d\x5f\xca\xb0\x47\x5e\x1f\x50\x9a", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000140ul, 0xd8ul);
	syscall(__NR_close, r[0]);
	return 0;
}
