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
*(uint64_t*)0x20003a40 = 0x20000000;
*(uint16_t*)0x20000000 = 2;
*(uint16_t*)0x20000002 = htobe16(0x4e20);
*(uint32_t*)0x20000004 = htobe32(0x7f000001);
*(uint32_t*)0x20003a48 = 0x10;
*(uint64_t*)0x20003a50 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000100;
memcpy((void*)0x20000100, "\xe2\x82\xd4\xf7\xa2\x1d\xe2\x57\xc6\xc0\xd6\x58\x0c\xac\x07\x95\xab\xe1\xc9\x09\x55\x0f\xc8\x3c\x6f\x30\x5e\xfe\x8b\x6d\x97\xff\x59\x26\x1d\xda\xbd\xb6\x22\x03\x3d\xa6\xc8\xde\xe0\xe5\x13\x75\x2f\x0e\x17\xea\xa7\x8f\xea\x30\x0c\x0d\x5f\x05\x24\xf1\x70\x4b\x6f\x2f\xa4\x3c\xcd\x8c\xdd\x78\xa1\xd0\x18\xaf\x55\x41\xa0\xef\xcd\x43\x10\x6b\x13\x85\x89\x48\x96\x16\x6c\xfb\x68\x79\x13\x7e\x42\x28\xde\x38\x70\x66\x8c\x21\xe0\x58", 106);
*(uint64_t*)0x20000088 = 0x6a;
*(uint64_t*)0x20000090 = 0x20000bc0;
memcpy((void*)0x20000bc0, "\xdb\x80\xaf\xaf\x3f\xe7\xed\x9e\xdf\x28\x4c\x00\xc3\xba\x96\x96\x0f\x6a\x0b\xa1\xe6\xe9\x7f\x79\x03\x59\x75\x9c\x56\x98\x10\xa0\x21\x9c\x38\xec\xeb\xd2\xd1\x43\x01\x39\xd3\x5c\xa9\x2d\x86\x54\x5f\x71\xbe\xb6\x66\x44\x9a\x83\x68\xd4\x86\x30\xe6\x1e\xe2\xf8\x48\x5d\xf8\x7a\x7a\xc1\xf4\x02\xb1\xce\xf7\xe8\xd7\xc6\xa6\x6c\x53\x90\xda\x1d\x4e\x80\x77\x1f\x43\xda\x76\xc2\xde\x42\xc9\xdc\x5b\xdc\xd9\xeb\xe9\x30\x26\x6e\x15\xee\xfd\x80\x39\x87\x0e\x34\xaa\xb3\x4f\x24\xd7\x75\x7b\x09\xda\x8c\x01\x42\x64\x28\xaa\x3f\x2a\x0b\x8e\x17\x26\x2b\xa7\xce\x9a\xbb\x20\x0f\x1a\xd6\x35\x9e\x00\x68\x47\x89\xd4\x6e\x22\x11\x17\x82\x46\x2e\xc4\xc0\xcd\xd3\x0f\xb6\x01\xc9\x34\xbd\xc2\x14\xd9\xf4\x67\xa7\xde\x9e\x2c\x7b\x67\x15\x73\xd6\x0b\xd3\x19\x12", 184);
*(uint64_t*)0x20000098 = 0xb8;
*(uint64_t*)0x200000a0 = 0x20000c80;
memcpy((void*)0x20000c80, "\x64\x8e\x3d\x64\xb4\x22\xaf\x70\xdf\x33\x30\xf6\x59\x42\x9c\x32\x8a\x40\x94\xff\xb2\xd9\x6e\x58\x67\x97\xff\x17\xd0\x63\x1e\xe5\x94\x27\x3f\x3c\x87\xa5\x2a\xf9\xbe\x84\x71\x2d\xa1\x9a\x25\x86\x28\x00\xde\x97\x6f\xb1\xb8\xe7\xe1\x5b\x66\xe3\xb7\x93\xd6\xa3\x14\x44\xf6\x1c\x93\x83\xaa\x36\x59\xc1\x23\xbc\x26\xa1\x3f\xd1\x35\x5c\x52\x26\x46\x24\x88\x6e\x20\xe6\x2e\xb6\x64\x4a\x47\x11\x26\xa6\x59\x81\xb7\xf2\x04\x79\xb7\x9a\x9a\x41\x48\x3e\xc5\x9e\xdd\x1d\x7c\x66\x2b\x43\x11\x43\xca\x61\xe7\xb3\x75\xe4\x31\x56\xdb\x7d\x57\xc9\x5a\x46\x1e\xa0\x45\x4e\x42\xeb\x5c\xde\x4d\xbf\xb2\x41\x23\x77\x3a\x8b\x57\x1c\xe2\xca\x13\x01\x63\xff\xda\x23\xa3\x79\x17\xbb\x9f\x40\xa5\x59\xfb\xdc\xfc\x13\x8e\x30\xc0\x83\x0c\x0a\x95\xac\x09\x1e\x86\xf8\x85\x2a\x4a\xdc\x7c\x76\x30\x47\xc6\x69\xfd\x10\xc2\x6e\x1d", 199);
*(uint64_t*)0x200000a8 = 0xc7;
*(uint64_t*)0x20003a58 = 3;
*(uint64_t*)0x20003a60 = 0;
*(uint64_t*)0x20003a68 = 0;
*(uint32_t*)0x20003a70 = 0;
*(uint32_t*)0x20003a78 = 0;
*(uint64_t*)0x20003a80 = 0;
*(uint32_t*)0x20003a88 = 0;
*(uint64_t*)0x20003a90 = 0x20000780;
*(uint64_t*)0x20000780 = 0x20000ac0;
memcpy((void*)0x20000ac0, "\x5d\xb3\xb1\x25\x9b\x9e\x1b\x44\x07\x22\x5f\x51\x3a\xee\x1c\x37\xd7\x84\x4f\x18\xdd\x55\x22\x5a\x68\x6c\x41\x5f\xf2\x50\x08\x60\xf8\xff\x28\x1e\x0c\x06\xb6\x96\x41\xd8\xe0\xd9\x99\x3f\x6f\xfc\x29\x55\xab\x90\x3f\xf4\xf8\x09\xd8\x3f\x84\xe6\x0f\x87\x02\xee\x36\xd4\xf8\x89\x45\xf2\x68\xf1\xff\xe5\x00\x00\x00\x00\x00\x00\x00\x08\x81\x38\x89\x72\x14\x42\x89\x64\xcd\x98\xa8\xb0\x5f\x0c\x7f\xc0\x5c\x77\x46\xf2\x8e\x23\x48\xb6\x6a\x3f\x41\x2b\x1c\xab\x3e\x61\xab\x56\x07\x2a\x58\xc9\xe9\xc3\x88\xb4\x3a\x73\xe1\x80\xc8\x1b\xbe\x3c\xc8\xcc\xe2\x3a\x69\xdb\x9a\x75\x06\x08\x62\x00\x7b\x35\x37\xed\x5e\x6a\xdc\xe9\xa5\x5b\x5f\xb3\x4e\x47\xb9\x63\x8c\xcf\xca\xc0\xce\x21\xcf\xe6\x80\x8f\x48\x5d\x9c\x9e\x36\xb9\x3a\x6d\xd2\x84\x22\xb0\x0e\x40\x54\x3a\x5a\xf9\x17\x5a\x84\xcc\x80\x7f\xfa\xf6\xf3\x09\xb0\xce\x41\x61\xec\xe8\xc0\xb7\xad", 207);
*(uint64_t*)0x20000788 = 0xff8b;
*(uint64_t*)0x20003a98 = 1;
*(uint64_t*)0x20003aa0 = 0;
*(uint64_t*)0x20003aa8 = 0;
*(uint32_t*)0x20003ab0 = 0;
*(uint32_t*)0x20003ab8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003a40ul, 2ul, 0x8080ul);
	return 0;
}