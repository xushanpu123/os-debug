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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200002c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000080, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000080ul, 0x4802ul, 0ul);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x20000840 = 0x20002240;
memcpy((void*)0x20002240, "\x67\x5d\x17\xfb\x8e\x68\x49\x0c\x6c\x01\x36\xf8\x8c\x71\xb6\x5c\x98\x9f\xcf\x39\x6c\x7c\xc0\x75\x0b\xf9\x74\xf3\x78\x6e\x88\x78\xc5\x1c\x2a\xab\x86\x9f\x97\xb6\xef\x68\xc3\xeb\xca\x4b\xda\x6a\x31\x7d\x87\xcb\xb0\x7c\xb8\x48\xfd\xbb\xb9\x1e\xc1\xfa\x4c\x11\xc1\xe3\x1e\xb0\x08\x8c\x60\x12\xf9\xe5\xcf\xfb\xeb\x22\x4c\xa6\x58\x22\x81\x25\xc7\xc5\x3c\x5d\x55\xfd\x5c\x79\xc1\x3b\x8c\x20\xac\x0a\xf1\xb5\x36\x28\xb8\xf5\x10\x9b\xd3\x85\x88\x4d\x55\xf6\x57\xa3\x07\x0e\xb1\xe1\x37\x7e\x36\x09\x02\x12\x51\x2c\x83\xdd\x70\x37\x20\x3e\xd1\xf6\x71\x13\x9c\x4f\x74\xa5\x86\x6f\x02\xcb\x6e\x10\x66\x26\xd8\x02\xbf\x95\xca\xf5\x1e\x3d\xdb\x05\x70\x1a\x18\x70\xce\xe8\x26\x1a\x58\xfc\x44\x28\xdf\xdf\x10\x44\xa5\x38\x38\xf8\x45\xf9\x02\xd4\x28\x37\xaa\xbe\xc9\x85\xce\x70\xeb\x00\xd9\x4d\xfd\xb7\x9f\x74\xcf\x47\x15\xcd\x37\x58\x4c\x67\xc3\x88\xcc\x25\xf9\x2f\xee\x04\x61\xa7\x70\xea\x12\xc1\x94\x48\xf0\xed\x8c\xc6\x8a\xb0\xf3\x78\x07\xdf\x64\xba\xed\xf9\x6b\x60\x6b\x67\xd7\x7e\xcf\xfb\x17\x4d\x1f\x27\x65\xd4\x02\xb5\xac\x10\x53\xd8\x90\x97\xc8\xa8\x98\x93\x71\xbb\xe6\x66\x4c\x50\x8e\x42\xe1\xcb\xae\x8a\x17\xcf\xbf\x91\x32\x3e\x3a\xd0\x17\x42\x7c\xb1\x91\xe2\x6e\x7b\xed\xcd\xb1\xf4\x45\xa6\xfc\x16\xd3\xb7\xc5\x38\x3c\xcc\x54\x36\xdf\x8d\xf9\x6c\x22\xf6\x9d\x40\xa4\x2e\xe7\xcc\x6d\xf8\x57\xe9\xfc\x12\x67\x9e\x40\x87\x44\x0a\x96\xf3\xa8\x38\x68\xd3\xc0\x9d\x3a\x8e\x9d\x80\x9a\x25\xfc\x70\xb0\xdb\xac\x1a\xda\x5d\xe9\xba\x3d\xc8\xe0\x66\xd6\x16\xdd\xa0\x87\xc0\xba\xfd\x90\xe6\x02\x9c\xe1\x9d\xab\x70\xcc\x24\x0b\xcb\x59\x49\x20\xac\x94\x37\x6b\xc5\x85\x5e\xd1\x13\x87\x6e\x89\x1c\x7e\x32\x1e\x79\x52\x49\x1a\x62\x9d\x95\x6e\xe4\x5b\x8d\x94\xaa\xfd\x9f\x28\xc9\xf3\x42\xe8\xb4\x20\x98\x5c\x8b\xa3\x52\xe1\x26\x5a\x67\x19\x48\x1a\x67\x80\x5a\x95\xc9\x24\x1e\x94\xbf\x0b\x8c\x6e\x11\xc3\xf3\x57\x89\x57\xd5\x1e\x22\x8d\x7b\xad\x8e\x49\x45\x4f\xca\x4d\x73\x4a\xf4\x3d\x65\x1b\x15\x0b\xcc\xed\x3c\x8d\xa0\x67\x7b\x1f\x67\xbb\x6e\x35\xc6\xe1\x71\x3e\xbc\x27\x84\x4e\xe6\x83\x50\x0d\x5e\x8e\x42\x80\x94\x5d\x0c\x76\x89\x92\xf6\x54\x3f\x04\x85", 508);
*(uint64_t*)0x20000848 = 0x1fc;
	syscall(__NR_pwritev, r[0], 0x20000840ul, 1ul, 4, 0);
memcpy((void*)0x20000800, "./file0\000", 8);
	syscall(__NR_unlink, 0x20000800ul);
*(uint64_t*)0x20001200 = 0x20000200;
memcpy((void*)0x20000200, "\x92\x96\xfa\x46\x14\xd1\x6a\xc7\xac\xab\xac\x79\x7b\x27\xcd\x7b\x09\xe3\x75\x56\xaa\x67\x0b\x9d\x57\x8b\x98\xe6\x1a\x7b\xc4\xe6\x88\x39\xea\x8e\xfc\x5c\x7a\x31\xe4\xa6\x6a\x09\x75\x88\xed\x92\x98\xc7\xd3\xc0\xf8\x89\x26\x70\x93\x60\xc2\x88\xfe\x08\xef\x00\xfc\x0d\x9b\x61\xc1\x20\x72\x0a\xd3\xfd\xc9\x02\x8f\xbb\x7a\x4e\xbd\xf2\x9d\x69\xd8\x2b\x0d\x63\xb5\x11\xc5\xe4\x9c\x43\x2c\xde\x0a\x9b\x0f\xd2\x2d\x4d\xae\x49\x05\xcf\x95\x1b\xf9\xb1\x7a\x05\xe0\x73\x7d\x2d\x7d\xa8\x92\xa5\x99\xf8\x4c\xb0\x10\xb2\xe3\x25\xbb\x06\x22\x38\x54\x17\x40\x15\xc8\xd5\x13\x0a\xa9\xd7\x1e\xf9\x0a\x1e\xb7\xe4\x30\xef\x6a\x86\x18\xbf\xe5\x32\x26\x7f\x00\xec\xf2\x32\x5e\xbb\xb0\x4e\x45\x8a\xc3\xe9\x85\x4a\xd4\x80\xc9\x8f\x21\xd8\x9a\x20\x8e\x4e\x56\x1c\x8c\x18\x49\x4c\xbe\x62\x41\x50\x4f\x22\x58\x25\x91\x62\x56\x09\x61\x09\x62\x2f\x36\x2e\x27\x84\x31\x25\x5f\xc9\xdd\x38\xdc\xb9\xf4\xbc\x15\x8d\x8a\x93\x0a\x95\x2b\x43\x20\x04\x35\xf2\x08\xc1\x0b\xae\x90\x2b\x27\x98\xb7\x33\xeb\xcc\x01\x4d\x8a\x04\x42\x39\xef\x0d\x6e\xbb\x00\x63\x83\xef\x85\x15\x5f\x75\xc1\x8b\xca\x03\x3d\xdc\x04\x4d\xe2\x0c\x6a\xe8\xc9\xe8\xc1\xf9\xdf\x67\xbb\x90\xd7\xdd\x45\xcd\xea\x0e\x30\xc0\x76\x20\x0e\xab\x2c\x43\x3c\x35\x73\x29\xdd\x4d\xd9\xf8\xf8\xd1\x85\x31\x0e\x3e\xd7\xe0\xed\x0e\x45\x6d\xa2\x93\x43\x8e\x1e\xd1\x9b\xbf\x3b\xdd\x58\x59\x1b\x60\xa5\x2f\xe9\xb4\xaa\xbd\x90\x7b\x95\x4e\x27\x09\x4b\x87\x14\xfc\x2b\x35\xf9\xe7\xf0\x45\xf8\xb9\xad\x4d\x73\xb3\x01\xcd\x45\x0a\x4e\x56\x0d\x73\x01\x96\xf3\x44\x70\x5e\xdf\x77\x11\xfa\x59\x62\x2c\xea\x05\x78\xdd\x2c\x15\x6c\xd7\x49\x14\xb8\x0b\xf1\xb9\x2e\x19\xd5\xca\xe8\x23\xaf\xc9\x74\xc1\x38\xfc\x6f\xda\x36\x1d\x7a\xbc\x98\xeb\x4a\x18\x81\x81\x3a\x1b\xff\x21\x95\x1f\x10\x49\x3b\xd7\x5b\xa8\x07\x27\x6a\x4e\xe1\x29\xbc\xa5\xcb\x32\xad\x0d\xcb\x45\xc8\x79\xa6\x21\x9c\xe9\x93\xe0\xdf\xc4\xc6\x15\x28\xc3\xd3\x63\x2b\xf8\xe8\x21\x22\x55\x06\x82\x1e\xd6\x40\x6e\x1a\xba\x65\x91\x18\x67\xdb\x16\x78\xc1\x18\xb6\xd6\xf2\x3f\x37\x6a\x29\x1e\x4e\x11\x6f\x03\x43\xf8\xf8\x42\xa4\x0f\x0b\x58\x8e\xc6\x8e\xf3\x90\x9d\x6b\x73\xa3\x41\x5e\x72", 512);
*(uint64_t*)0x20001208 = 0x200;
	syscall(__NR_pwritev2, r[1], 0x20001200ul, 1ul, 0, 0, 0ul);
	return 0;
}
