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
memcpy((void*)0x20000040, "lo\000\000\000\000\000\000\000\000\000\000\000\000\000\000", 16);
*(uint64_t*)0x20000050 = 0x20000100;
*(uint32_t*)0x20000100 = 3;
memcpy((void*)0x20000104, "\x9f\xd8\x09\x2b\x47\x2c\xd9\xe0\xf8\x6c\x13\x29\x5d\xe5\x83\x3d\xff\xee\x1a\xd8\xd2\xf7\xdd\x1d\xf2\x59\x17\xbe\xc0\x38\xfb\x3d", 32);
memcpy((void*)0x20000124, "\xdd\xef\xc1\x47\x7e\x68\xd5\x6a\xb3\x41\xb6\x18\xb9\x55\x48\x98\x73\x58\x94\xa8\x06\x86\x16\x0f\x86\xf7\xee\x42\x74\xa7\x2d\x42", 32);
memcpy((void*)0x20000144, "\xbc\x83\x3e\x6a\x75\xc7\x06\x25\x46\x2a\x8b\xaa\x3e\x2a\xdf\xe5\x85\x75\x1b\xc4\x3c\x0a\x5b\xfe\xfa\x3c\x06\xb5\x66\xd9\x3a\x5a", 32);
memcpy((void*)0x20000164, "\x9a\x36\x22\xf1\x0b\xf4\xc8\x7a\x6d\xb8\xfe\x57\x72\x42\x8d\xcd\x28\x0a\x25\xbd\x6b\x27\x6e\x44\x6c\x4a\x9e\xba\xd9\xc8\x8d\x85", 32);
memcpy((void*)0x20000184, "\x7f\xf5\x53\x09\x5a\x46\x2d\x63\xb1\x5f\xd3\x3c\x5f\xf5\x68\x30\x6f\x75\xc0\x3d\x7f\x72\x04\x3e\x46\x3e\x00\x00\x1e\x00\x00\x00", 32);
memcpy((void*)0x200001a4, "\x02\x94\x64\xa7\x84\xb7\x78\xb7\xb4\xd1\x80\x0c", 12);
*(uint32_t*)0x200001b0 = 0;
*(uint32_t*)0x200001b4 = 0;
*(uint32_t*)0x200001b8 = 0;
*(uint32_t*)0x200001bc = 0;
*(uint32_t*)0x200001c0 = 0;
	syscall(__NR_ioctl, r[0], 0x8946, 0x20000040ul);
	return 0;
}