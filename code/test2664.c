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

#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000140, "./file0\000", 8);
	syscall(__NR_creat, 0x20000140ul, 0ul);
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000080ul, 0x4802ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000800, "./file0\000", 8);
	syscall(__NR_unlink, 0x20000800ul);
*(uint64_t*)0x20001200 = 0x20000200;
memcpy((void*)0x20000200, "\x92\x96\xfa\x46\x14\xd1\x6a\xc7\xac\xab\xac\x79\x7b\x27\xcd\x7b\x09\xe3\x75\x56\xaa\x67\x0b\x9d\x57\x8b\x98\xe6\x1a\x7b\xc4\xe6\x88\x39\xea\x8e\xfc\x5c\x7a\x31\xe4\xa6\x6a\x09\x75\x88\xed\x92\x98\xc7\xd3\xc0\xf8\x89\x26\x70\x93\x60\xc2\x88\xfe\x08\xef\x00\xfc\x0d\x9b\x61\xc1\x20\x72\x0a\xd3\xfd\xc9\x02\x8f\xbb\x7a\x4e\xbd\xf2\x9d\x69\xd8\x2b\x0d\x63\xb5\x11\xc5\xe4\x9c\x43\x2c\xde\x0a\x9b\x0f\xd2\x2d\x4d\xae\x49\x05\xcf\x95\x1b\xf9\xb1\x7a\x05\xe0\x73\x7d\x2d\x7d\xa8\x92\xa5\x99\xf8\x4c\xb0\x10\xb2\xe3\x25\xbb\x06\x22\x38\x54\x17\x40\x15\xc8\xd5\x13\x0a\xa9\xd7\x1e\xf9\x0a\x1e\xb7\xe4\x30\xef\x6a\x86\x18\xbf\xe5\x32\x26\x7f\x00\xec\xf2\x32\x5e\xbb\xb0\x4e\x45\x8a\xc3\xe9\x85\x4a\xd4\x80\xc9\x8f\x21\xd8\x9a\x20\x8e\x4e\x56\x1c\x8c\x18\x49\x4c\xbe\x62\x41\x50\x4f\x22\x58\x25\x91\x62\x56\x09\x61\x09\x62\x2f\x36\x2e\x27\x84\x31\x25\x5f\xc9\xdd\x38\xdc\xb9\xf4\xbc\x15\x8d\x8a\x93\x0a\x95\x2b\x43\x20\x04\x35\xf2\x08\xc1\x0b\xae\x90\x2b\x27\x98\xb7\x33\xeb\xcc\x01\x4d\x8a\x04\x42\x39\xef\x0d\x6e\xbb\x00\x63\x83\xef\x85\x15\x5f\x75\xc1\x8b\xca\x03\x3d\xdc\x04\x4d\xe2\x0c\x6a\xe8\xc9\xe8\xc1\xf9\xdf\x67\xbb\x90\xd7\xdd\x45\xcd\xea\x0e\x30\xc0\x76\x20\x0e\xab\x2c\x43\x3c\x35\x73\x29\xdd\x4d\xd9\xf8\xf8\xd1\x85\x31\x0e\x3e\xd7\xe0\xed\x0e\x45\x6d\xa2\x93\x43\x8e\x1e\xd1\x9b\xbf\x3b\xdd\x58\x59\x1b\x60\xa5\x2f\xe9\xb4\xaa\xbd\x90\x7b\x95\x4e\x27\x09\x4b\x87\x14\xfc\x2b\x35\xf9\xe7\xf0\x45\xf8\xb9\xad\x4d\x73\xb3\x01\xcd\x45\x0a\x4e\x56\x0d\x73\x01\x96\xf3\x44\x70\x5e\xdf\x77\x11\xfa\x59\x62\x2c\xea\x05\x78\xdd\x2c\x15\x6c\xd7\x49\x14\xb8\x0b\xf1\xb9\x2e\x19\xd5\xca\xe8\x23\xaf\xc9\x74\xc1\x38\xfc\x6f\xda\x36\x1d\x7a\xbc\x98\xeb\x4a\x18\x81\x81\x3a\x1b\xff\x21\x95\x1f\x10\x49\x3b\xd7\x5b\xa8\x07\x27\x6a\x4e\xe1\x29\xbc\xa5\xcb\x32\xad\x0d\xcb\x45\xc8\x79\xa6\x21\x9c\xe9\x93\xe0\xdf\xc4\xc6\x15\x28\xc3\xd3\x63\x2b\xf8\xe8\x21\x22\x55\x06\x82\x1e\xd6\x40\x6e\x1a\xba\x65\x91\x18\x67\xdb\x16\x78\xc1\x18\xb6\xd6\xf2\x3f\x37\x6a\x29\x1e\x4e\x11\x6f\x03\x43\xf8\xf8\x42\xa4\x0f\x0b\x58\x8e\xc6\x8e\xf3\x90\x9d\x6b\x73\xa3\x41\x5e\x72", 512);
*(uint64_t*)0x20001208 = 0x200;
	syscall(__NR_pwritev2, r[0], 0x20001200ul, 1ul, 0, 0, 0ul);
	return 0;
}
