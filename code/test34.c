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

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);

memcpy((void*)0x20000340, "\x71\x66\x0c\xa1\x75\xf5\x92\x81\xfb\xff\x0d\x2c\x0e\x1f\x67\x52\xe4\x7b\x6a\x66\x96\x68\x13\x15\xaa\x11\x67\x68\xbc\x65\x9f\x9e\xbb\xaf\x9c\x2f\x7f\xfa\xa6\x92\xf5\xf6\x2f\xe0\xea\xcb\x2f\xcf\x1a\x01\x1b\x5b\xf8\xdc\x61\x03\x9f\x18\x98\x1b\xfa\xc1\x8e\x80\xf5\x36\x91\x4a\x15\xfa\xa7\x98\xa2\x34\x20\xd2\x81\x47\xd5\x8a\x13\x71\x4b\x88\x20\x5b\xf6\x9c\xed\x08\x2b\x22\x3e\x0e\x45\xa7\x74\x3a\x86\xa7\x49\x4c\x76\x9b\xdd\x16\xbb\xfe\x9b\x92\x23\x12\xd5\xd2\xdc\xd8\xdc\x46\x7d\xb9\xd9\x1d\x45\x95\x7e\xfe\xf8\x58\x8b\xc4\x5c\xd1\xfd\xaa\x92\xcd\x05\xdf\x90\xe8\x35\xf5\x0b\xa2\x86\x1a\xd0\x65\x15\xee\xda\x25\xd8\x7f\x53\x61\x20\x71\x34\x53\xbc\x68\x27\x90\x34\xfe\xcb\x39\x92\xa8\x73\xa6\xc9\x5c\x38\x89\xa6\x41\x64\xac\xd6\x04\xa8\x90\x40\x8f\xe6\x7f\x54\xb1\xc8\x40\xcf\xdb\x0f\x76\x8a\xce\x32\x61\x43\x0e\x99\x41\x2a\xf6\xb7\xb8\xcb\x11\xba\x74\xc7\x2f\x8f\x68\x86\x7c\x2d\x5d\x2e\xac\xb6\x20\x51\x5c\xcd\x79\xd5\x90\x71\x3e\x7c\x49\x01\x30\x7d\x98\xec\x31\x52\x3f\x67\xd4\xf1\x20\xaa\x8a\x27\x9e\x7c\xd8\xa1\x04\x5a\x42\xf4\x97\x59\x6a\xdd\x46\xb3\xa4\x07\xd9\x03\x67\x92\xf6\x9f\x49\xd7\x7d\xb8\x47\x56\x6c\xa0\xd8\xbe\xb1\xa5\xbb\x93\xec\x4d\xf2\x08\x6a\x73\x30\x17\x7d\xf5\xa9\x17\x29\x1f\x93\xa5\xc1\x39\x24\x9d\xaa\x24\x8c\x91\xfb\x25\x77\xb0\x49\x32\x4b\x71\xc9\xf4\x1a\x1e\x03\x37\x23\xb3\xa8\xee\x0f\x56\xfe\x0b\xb9\x2e\xcf\x3b\x94\xd8\x14\xab\x1d\x84\x50\x35\x6a\xba\x4e\x94\x2a\x32\x04\x76\xb3\x99\x5c\xf4\xf3\x8a\x85\x41\x82\x7c\x47\x1b\x1c\x56\x20\xab\x1b\x11\x60\x60\x0b\xd5\xb8\xb3\xcf\xed\xec\xf3\x6a\xb2\xae\x20\xdb\xe7", 385);
	syscall(__NR_prctl, 0x23ul, 0xcul, 0x20000340ul, 0x181ul, 0);
	return 0;
}