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

*(uint64_t*)0x20000b80 = 0;
*(uint32_t*)0x20000b88 = 0;
*(uint64_t*)0x20000b90 = 0x20000b40;
*(uint64_t*)0x20000b40 = 0x20000040;
memcpy((void*)0x20000040, "\xa0\x19\x01\x41\x5f\xf5\xe4\x63\x14\x5c\xe3\x07\x69\x13\xf1\x00\x00\x00\x58\x64\x49\x11\x84\xbf\x25\xc2\x7a\x93\x47\x97\x00\x00", 32);
*(uint16_t*)0x20000060 = -1;
memcpy((void*)0x20000062, "\x06\xfa\xb5\x68\x2f\x47\x77\x8d\x68\x53\x68\x4f\x8f\x7e\xbe\xf7\xd8\xd4\x1a\xe2\xed\x8a\x41\x1d\xf0\xa1\x28\xd9\x80\x7a\x25\x5f\xff\x3d\x67\x9d\xbf\x02\x55\x14\x4e\xdd\x7c\xe3\x89\x14\xb2\xb8\x4d\x19\x52\xdf\xca\xe0\x73\x36\x9a\x11\x7b\xd3\x48\x73\x4b\xca\xee\x4c\x86\x54\x45\x83\x59\x00\xa5\xbc\x73\x90\x39\x02\x9f\xaa\x93\x08\xcd\x59\xaf\x88\x09\x06\x52\x65\x4e\x3c\x40\xcc\x90\x7e\x3c\x1c\x83\x06\xf1\xf5\x74\xcf\xd4\x1c\xda\xa3\x8e\xf0\x6d\x73\xa6\x08\x16\xf3\x6c\x82\xc0\xcc\x9a\xc0\x9e\x35\xe0\x56\x10\x9a\x5d\xe6\x44\x7b\x50\x22\x84\xae\x4d\x8d\x65\x6c\x71\x63\x74\x84\xb4\xad\x91\x79\x91\x4b\xf8\xe6\x85\xd0\x60\x8c\x89\xc2\x42\x4e\x25\x61\x51\xa8\x77\xe7\x5f\x8b\xf3\xb5\x87\x44\x37\x78\xdc\x19\x27\xd8\xe0\xe0\xf9\xda\x45\x55\x06\x61\xc5\xf7\x39\x4c\x90\x06\x95\x08\x94\x88\x25\xa0\x64\xca\xcd\x32\xf0\xa9\x07\xe1\x4f\xf2\x37\xeb\x75\x8b\xce\xfd\xa7\x7e\x50\x03\xcf\xfb\x9b\x6e\x8c\x8e\x33\xe1\x11\x5a\x01\x22\xc8\x3b\xb1\x3c\x3e\xfe\xa9\x4e\x82\xfc\x2f\x2f", 242);
*(uint64_t*)0x20000b48 = 0x14;
*(uint64_t*)0x20000b98 = 1;
*(uint64_t*)0x20000ba0 = 0;
*(uint64_t*)0x20000ba8 = 0;
*(uint32_t*)0x20000bb0 = 0;
	syscall(__NR_sendmsg, -1, 0x20000b80ul, 0ul);
memcpy((void*)0x20000140, "/sys/module/pcmcia", 18);
	syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000140ul, 0ul, 0ul);
	return 0;
}
