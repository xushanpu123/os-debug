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
*(uint16_t*)0x20000100 = 0xa;
*(uint16_t*)0x20000102 = htobe16(0);
*(uint32_t*)0x20000104 = htobe32(0);
*(uint64_t*)0x20000108 = htobe64(0);
*(uint64_t*)0x20000110 = htobe64(1);
*(uint32_t*)0x20000118 = 0;
*(uint8_t*)0x20000180 = 0;
*(uint8_t*)0x20000181 = 0;
*(uint16_t*)0x20000182 = 0x2e;
*(uint32_t*)0x20000184 = 0;
memcpy((void*)0x20000188, "\x3f\x1a\xa8\xa3\x7c\xb9\xca\x72\xbc\x3f\xc6\x45\x80\xbf\xc2\x4c\xae\xad\x92\xac\xf2\x43\x3d\xc0\x85\xd1\xc0\xb0\x68\xd2\x6b\xed\x98\x24\x14\xa4\xa2\x52\x1f\xb4\x44\x92\x4d\x11\x15\xf7\x97\xab\x57\x31\x17\xee\x3d\x8f\x20\x56\x5b\xfd\x6c\x47\xfe\x50\xd3\x82\xe0\x1c\x42\xb1\x67\x2c\x51\x25\x69\x03\xa9\xbb\x49\xb8\x74\xe3", 80);
	syscall(__NR_setsockopt, r[0], 6, 0xe, 0x20000100ul, 0xd8ul);
*(uint64_t*)0x200000c0 = 0x20000240;
*(uint16_t*)0x20000240 = 0xa;
*(uint16_t*)0x20000242 = 0;
*(uint32_t*)0x20000244 = htobe32(0);
*(uint64_t*)0x20000248 = htobe64(0);
*(uint64_t*)0x20000250 = htobe64(1);
*(uint32_t*)0x20000258 = 0;
*(uint32_t*)0x2000025c = 0;
*(uint32_t*)0x200000c8 = 0x80;
*(uint64_t*)0x200000d0 = 0;
*(uint64_t*)0x200000d8 = 0;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0x24040040ul);
	syscall(__NR_ioctl, r[0], 0x5411, 0x20000040ul);
	return 0;
}