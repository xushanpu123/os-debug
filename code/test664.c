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
memcpy((void*)0x20000080, "/proc/self/exe\000", 15);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000080ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x200000c0, "\x2a\x83\xe3\xe8\x42\xa2\xbf\x75\xd7\x97\x92\xef\xee\x5b\x95\x5e\x67\xb5\x9e\x46\xf0\xe3\x03\x85\x89\x8f\x71\x05\xa2\x86\xaf\x1c\x13\xb9\x46\x3f\x4b\xc8\xd2\x0d\xa2\x3e\xb2\x7e\xb2\x04\x2d\x08\xc8\x7a\xcd\x0b\x56\x1e\xa3\x89\x14\x59\x15\xc7\x90\xbc\xa6\x87\x05\x46\x2e\xf5\x45\x9d\xf7\xce\xfa\x99\x01\x01\x9c\x74\x93\xe1\x3e\x30\x28\x79\x02\xfd\x11\x2f\xa4\x12\xb6\xf7\x34\xf8\x33\x50\x23\xc1\xcc\x05\xc8\x48\x92\xb5\x4f\x74\xc2\xeb\x78\x70\x41\x60\x4d\x66\xa1\x27\x79\xf4\x14\xa9\x71\xfc\xad\x8e\x60\xee\x0f\x25\x54\x79\x4c\x17\xee\xa9\x38\x15\xa5\x88\x3b\x69\x17\xac\x54\x71\x95\x57\xd4\xed\x22\xb1\x7a\xb2\x3e\xa5\xe4\xed\x05\x48\x52\x2c\x5d\x3c\x2f\xe0\x4e\xba\xca\x07\x96\xb6\xbe\xa7\xd8\x20\x3a\xa6\xf4\x41\xef\xc3\x1f\x46\xaa\x1e\x42\xf8\x0e\x95\x34\x58\xb0\x3f\x8b\x4c\x59\x1e\xdd\xc2\x8a\xf5\x3a\x67\xff\xa5\x55\xc8\x18\x27\x9b\xb4\xa5\x2c\x43\x0a\x2e\x51\x34\x3b\x37\x21\x14\x72\xba\x6a\x38\xdf\x5b\xdc\xdd\xa0\x95\xea\x3e\x9b\xd6\x5b\x00\x73\x56\x6b\x90\xb7\xe0\x75\xd0\xeb\x71\x18\xb6\x65\xf0\x21\xcc\x6e\x7e\x9f", 256);
	syscall(__NR_ioctl, r[0], 0x41009432, 0x200000c0ul);
	return 0;
}
