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
	res = syscall(__NR_socket, 0xaul, 2ul, 0x88);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002c80 = 0x20000400;
*(uint16_t*)0x20000400 = 0xa;
*(uint16_t*)0x20000402 = htobe16(0x4e20);
*(uint32_t*)0x20000404 = htobe32(0);
*(uint8_t*)0x20000408 = 0xfe;
*(uint8_t*)0x20000409 = 0x80;
memset((void*)0x2000040a, 0, 13);
*(uint8_t*)0x20000417 = 0xbb;
*(uint32_t*)0x20000418 = 1;
*(uint32_t*)0x20002c88 = 0x1c;
*(uint64_t*)0x20002c90 = 0;
*(uint64_t*)0x20002c98 = 0;
*(uint64_t*)0x20002ca0 = 0x20002900;
memcpy((void*)0x20002900, "\x14\x00\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x34\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\xb0\x00\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x36\x00\x00\x00\x3a\x12\x00\x00\x00\x00\x00\x00\x07\x38\x00\x00\x00\x00\x0c\x20\x01\x00\xff\xff\xff\xff\xff\xff\xff\x7f\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x84\xb4\xe0\x75\x00\x00\x00\x00\x09\x00\x00\x00\x00\x00\x00\x00\x00\x80\x00\x00\x00\x00\x00\x00\x05\x02\x00\x06\x05\x02\x00\x68\x05\x02\x00\x09\x04\x01\x00\x07\x38\x00\x00\x00\x00\x0c\x00\x85\x56\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x06\x00\x00\x00\x00\x00\x00\x00\x8a\xa6\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\xf5\x00\x00\x00\x00\x00\x00\x00\xc9\x10\xfe\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xbb\x00\x00\x00\x60\x02\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x37\x00\x00\x00\x32\x48\x00\x00\x00\x00\x00\x00\xff\xfb\xdb\xff\x93\x06\x2a\x71\xa1\xab\x46\x77\x06\x7e\x53\xf9\xeb\x4f\x01\xfa\xff\xad\xa4\xbd\xbc\x38\x50\x97\xad\x99\x72\x23\xd3\x9c\x00\x97\x08\x2b\xf0\xa3\xa1\x94\xf2\xc3\x66\x75\x0c\xeb\x66\xfd\x43\x84\xc2\x05\x00\x00\x00\x76\xd8\x4a\x9e\xb8\x32\xec\xac\x75\x85\x3b\xa2\xcf\x5c\xe7\x8b\x5d\x81\x61\x99\x32\x1e\xd4\xfe\xda\xc5\x58\xab\x66\x08\x4a\xbe\xd0\x40\x49\xd8\xb1\x67\x86\x18\x46\x8c\x80\xdd\x43\xec\x06\x8f\x2b\x12\xc5\x29\xf4\x75\xdd\x1c\x59\x52\x3a\x30\x69\x1d\x31\xbc\xbf\xfc\x1e\x19\x34\x6a\x4d\x96\x1a\x07\x48\x52\xfb\x47\x0a\x11\xf5\xdc\x7e\x7f\x72\xe3\x6e\xe9\x8e\x89\x82\x80\x43\xfd\x5e\xb2\x99\x9b\x26\x2c\x46\xa3\x8d\xfc\x58\xb6\xee\xd5\xe5\x17\x31\xb6\xfc\xa6\xf0\x89\x7a\x58\x77\xac\xb7\x09\x1d\xcd\x47\x44\x0e\x03\x7b\xd0\x14\x36\xbc\x38\xc1\xf2\xf2\x73\xfa\x31\x5a\x84\x0b\x19\xc0\x97\xeb\x0a\x54\xc3\xaa\xeb\x23\x00\x73\x0d\xd9\x1b\x96\x66\x7a\x64\xab\x35\x89\xe9\xf4\xc7\x78\x12\x2f\x67\xae\x34\xfb\x99\x95\x69\x8a\x11\xb6\x52\xe2\x89\x30\xf0\xa9\x05\x17\x9a\xff\x88\x07\x65\x2a\xda\xc2\x04\x00\x00\x14\xf8\x07\x30\x00\x00\x00\x02\x0a\x3f\x52\x00\xff\x0f\x00\x00\x00\x00\x00\x00\x91\x34\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x07\x30\x00\x00\x00\x03\x0a\xdd\x03\x00\xc3\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x00\x09\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x01\x05\x00\x00\x00\x00\x00\x60\x6f\xb3\xac\x6f\xf0\xa9\xda\xcd\x2c\x11\x09\x3f\x21\x03\xfc\x73\x7f\x05\xf9\xd6\x4b\x11\x3f\x61\x6f\xe1\x5d\xff\x51\xc6\xf2\x20\xb1\x47\x08\x58\x74\x45\x4e\xa9\x03\xd9\x93\xd1\x33\x45\x92\xd8\x3b\xa0\x6a\xaa\x10\x71\xeb\xdd\x19\xff\xc2\xf0\x8c\xd6\xc5\x8e\x5c\x7c\x54\x19\x9c\xa8\x48\xaa\x54\xe3\xc8\x87\xe0\x36\x9a\x07\x0c\xdd\x25\xb4\x52\x40\x67\x3a\x9b\xd3\xd0\xd2\xe8\xbd\x47\xde\x47\x80\x5b\xfe\x23\x64\x27\x0d\x13\x4a\x4e\x2c\xc8\xee\x00\x8e\xc9\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x01\x52\x0d\xfa\x39\x2d\x58\x2a\x2b\x62\xfa\xbd\xf3\x68\x33\x35\x6f\xcc\xf0\x9e\xcd\xee\xf7\x41\x48\xfe\x3f\x2b\x19\x12\x0d\xec\x91\xb9\xe0\x75\x23\x74\x3a\x43\x0f\xda\xc3\x5a\x39\x2d\xd5\x03\xcd\x18\x67\x31\xd2\xfd\x77\x98\x04\x00\x3e\x32\x61\xe5\x42\x38\x0d\xc5\x0f\xac\xf0\x53\x12\x58\x24\xff\x04\x12\xba\x02\x3d\x9c\x0b\x85\x68\xdc\x00\x00\x00\x14\x00\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x3e\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x14\x00\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x0b\x00\x00\x00\x00\x00\xd5\x78\x00\x00\x00\x00\x14\x00\x00\x00\x00\x00\x00\x00\x29\x00\x00\x00\x3e", 869);
*(uint64_t*)0x20002ca8 = 0x370;
*(uint32_t*)0x20002cb0 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002c80ul, 0ul);
	return 0;
}
