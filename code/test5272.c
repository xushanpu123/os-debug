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
	res = syscall(__NR_socket, 2ul, 3ul, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002bc0 = 0x20000080;
*(uint16_t*)0x20000080 = 2;
*(uint16_t*)0x20000082 = htobe16(0);
*(uint8_t*)0x20000084 = 0xac;
*(uint8_t*)0x20000085 = 0x14;
*(uint8_t*)0x20000086 = 0x14;
*(uint8_t*)0x20000087 = 0xbb;
*(uint32_t*)0x20002bc8 = 0x10;
*(uint64_t*)0x20002bd0 = 0x20000280;
*(uint64_t*)0x20000280 = 0x200000c0;
memcpy((void*)0x200000c0, "nl", 2);
*(uint64_t*)0x20000288 = 0xff07;
*(uint64_t*)0x20000290 = 0x20000100;
memcpy((void*)0x20000100, "\xe2\xbc\x73\x3a\x1a\xdf\x00\x54\x87\xfe\xc4\xfd\x4e\x1b\x2d\x2e\x4d\x38\xf3\xf4\xcb\xc0\x8d\x45\x5b\x8b\x80\x92\x59\xcf\x96\x15\xe1\x2a\x8a\x8d\xd0\xde\x42\x6b\x52\x14\xa5\x29\x49\xad\xa3\xd8\x4c\x79\x52\x40\x7c\x37\x8e\x55\x43\x32\x62\x26\x8c\xbb\x2d\x4e\x98\xf8\x8d\x32\x86\x93\x61\x87\x7d\xbd\xd5\xf5\x5b\x71\x7f\x49\xe6\x23\xb2\x0c\x62\x22\x55\x97\xd4\x95\xbb\xdb\x18\x40\x4d\x81\x5a\xa4\xdd\x16\xc0\x72\x9c\x65\x20\x46\xb5\x29\xb2\x57\x15\xe0\xf8\xb7\xc4\x24\x67\x07\xbe\x1f\x66\x96\xf5\x05\xbb\x6f\x46\x34\x8e\xce\x2c\x8e\xb2\x45\xbb\x03\x64\x52\x6f\xb9\x71\x76\x74\x5f\xca\xea\xd0\x69\x70\x28\xf7\xf8\x27\x11\xb7\xcb\x7c\x9a\xe3\xff\xf5\x01\x0e\x86\x52\x04\x5d\x3e\xb2\xc5\x4e\x2b\x4a\x4f\x6c\x30\x19\x1e\xb6\x5b\x74\xa7\xfd\x77\x35\x7f\x21\x95\x9c\x1d\x7a", 191);
*(uint64_t*)0x20000298 = 0;
*(uint64_t*)0x200002a0 = 0x20000000;
memcpy((void*)0x20000000, "\x7a\x29\xb4\x7e\xe2\x36\x70\x99\x1e\xc4\xbe\x8d\x9d\xc9\x8a\x53\xe9\x41\x78\x2b\xca\xf4\x3b\x0f\x2f\x02\x40\x18\x34\x72\x7d\x81\xab\x1a\x92\x14\x61\xa4\xe4\x27\xff\xfe\x53\x2c\xfb\x1f\x92\xe2\x9d\xdd\xb2\x99\x67\x11\x1c\x44\xa3\x62\xcd\xb0\x62\xec\xbf\x0a\x34\xff\x32\x59", 68);
*(uint64_t*)0x200002a8 = 0;
*(uint64_t*)0x200002b0 = 0x200001c0;
memcpy((void*)0x200001c0, "\x52\x3b\xee\xab\x29\xa8\x01\x0d\x14\xb8\x14\x8c\x28\xce\x0b\x09\x5d\x82\xc6\x7c\xa8\x37\x88\xa7\xcf\x4b\xc7\x0b\x5e\x82\x57\x02\x78\x3a\xb9\xeb\xfa\x50\x23\x00\xab\x2e\xf8\x66\x68\xd2\x8d\x38", 48);
*(uint64_t*)0x200002b8 = 0;
*(uint64_t*)0x200002c0 = 0x20000300;
memcpy((void*)0x20000300, "\x3b\x17\x32\xa0\x66\x6c\x0d\x84\xbf\x9b\xd1\xb3\x84\x47\xde\xee\x3a\x3a\x2e\x26\x2b\xf1\xaf\xb3\xe1\x4c\x3a\x68\xd3\x7b\x71\x84\xb1", 33);
*(uint64_t*)0x200002c8 = 0;
*(uint64_t*)0x200002d0 = 0x20000240;
memcpy((void*)0x20000240, "\xb0\x1f\xf8\x27\xe3\x50\x6f\x59\xd7\x08\x04\xb6\x76\x11\xb1\xe1\xd7\xfd", 18);
*(uint64_t*)0x200002d8 = 0;
*(uint64_t*)0x20002bd8 = 1;
*(uint64_t*)0x20002be0 = 0;
*(uint64_t*)0x20002be8 = 0;
*(uint32_t*)0x20002bf0 = 0;
*(uint32_t*)0x20002bf8 = 0;
*(uint64_t*)0x20002c00 = 0x20002580;
*(uint16_t*)0x20002580 = 2;
*(uint16_t*)0x20002582 = htobe16(0);
*(uint8_t*)0x20002584 = 0xac;
*(uint8_t*)0x20002585 = 0x14;
*(uint8_t*)0x20002586 = 0x14;
*(uint8_t*)0x20002587 = 0;
*(uint32_t*)0x20002c08 = 2;
*(uint64_t*)0x20002c10 = 0x200027c0;
*(uint64_t*)0x200027c0 = 0x200025c0;
memset((void*)0x200025c0, 19, 1);
*(uint64_t*)0x200027c8 = 1;
*(uint64_t*)0x20002c18 = 1;
*(uint64_t*)0x20002c20 = 0;
*(uint64_t*)0x20002c28 = 0;
*(uint32_t*)0x20002c30 = 0;
*(uint32_t*)0x20002c38 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002bc0ul, 2ul, 0x4000000ul);
	return 0;
}
