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
	syscall(__NR_setsockopt, r[0], 0x29, 0x3b, 0x20000ec0ul, 0xf8ul);
*(uint64_t*)0x20001a40 = 0x20000080;
*(uint16_t*)0x20000080 = 0xa;
*(uint16_t*)0x20000082 = htobe16(0x4e25);
*(uint32_t*)0x20000084 = htobe32(0);
*(uint8_t*)0x20000088 = 0xfe;
*(uint8_t*)0x20000089 = 0x80;
memset((void*)0x2000008a, 0, 13);
*(uint8_t*)0x20000097 = 0xaa;
*(uint32_t*)0x20000098 = 0;
*(uint32_t*)0x20001a48 = 0x1c;
*(uint64_t*)0x20001a50 = 0;
*(uint64_t*)0x20001a58 = 0;
*(uint64_t*)0x20001a60 = 0;
*(uint64_t*)0x20001a68 = 0;
*(uint32_t*)0x20001a70 = 0;
*(uint32_t*)0x20001a78 = 0;
*(uint64_t*)0x20001a80 = 0;
*(uint32_t*)0x20001a88 = 0;
*(uint64_t*)0x20001a90 = 0x20000dc0;
*(uint64_t*)0x20000dc0 = 0x20000200;
memcpy((void*)0x20000200, "\xf1\xe9\xc9\xe3\x80\xfc\xb0\x15\x6f\xc9\x3a\xf7\x84\x0a\x3a\xcf\x1c\x93\x36\x77\x01\x2e\xc9\x0b\xc9\x65\x7f\x52\x68\x44\x69\x30\x53\x75\xda\xec\x0a\x0f\x1b\x4d\x33\xb7\xc3\x6c\x08\x74\x00\x1e\xda\xae\x40\xcc\x05\x12\x64\xac\x77\x30\x56\x75\xf4\x2e\x25\xe2\x99\xcf\xf7\x83\xf3\x86\x6c\x9e\x36\xe9\xa1\xa3\x97\xd7\x7e\x24\x7f\x52\x6b\xb0\xb6\x65\x0b\x87\xb1\x1e\x31\xad\x99\xa2\x96\xa4\xdd\x85\x0a\x23\x9d\xe2\x5f\x11\x1f\xe9\xf7\xc5\x1a\xa6\x5c\xec\x6c\x12\xcd\xba\x4d\x87\x8a\xe8\x43\x64\x49\xc2\x0e\xdf\xfc\xc4\x8d\x37\xc7\x6e\x58\x12\x33\xb4\xea\xf6\xd9\x0b\xf6\x7e\x52\x56\x1c\xbc\x7d\xf3\xea\x85\x8a\xed\x61\x2c\x54\x57\xa7\xfd\xba\xe9\x66\x59\x41\xca\xf7\x00\xaa\xb1\xa3\x02\x1c\x94\x5a\xc9\x7c\xdd\x7c\xe7\x67\x85\x04\x13\x43\xc8\xe8\x70\x35\x70\xec\xf6\x78\xaa\xd5\xd6\x7d\xbf\x4d\xc4\xec\x77\x37\x14\x53\xf0\x86\xbe\xab\x42\x19\x62\x1f", 211);
*(uint64_t*)0x20000dc8 = 0xd3;
*(uint64_t*)0x20000dd0 = 0x20000000;
memcpy((void*)0x20000000, "\x97\xec\x91\xbc\xcb\x42\x06\xc1\x7f\xe0\xe3\xbb\xc9\x14\xfb\xee\x24\x86\x23\xac\xed\x0c\x1e\xf6\x83\x87\xde", 27);
*(uint64_t*)0x20000dd8 = 0x1b;
*(uint64_t*)0x20000de0 = 0x20000300;
memcpy((void*)0x20000300, "\x1e\xb1\x1e\x58\xf2\x62\xda\x24\xc1\xec\xb3\x3d\xf4\x60\xc8\xff\x1b\x06\x59\x28\xe4\x32\xaf\xf5\x3c\xef\x27\x16\x9c\xd1\x17\xf3\x82\x3c\x0f\xec\x45\xc1\xc4\x25\x01\x41\x2d\x90\xa2\xb5\x36\xe3\x4e\xeb\xec\x16\x19\xf7\xe6\xf4\x98\x12\x2e\xf9\xce\x1e\x88\xa8\x29\x57\x9d\x97\x5d\x70\x59\x8e\x6d\x38\x89\x05\x4b\x1b\xa5\x44\xf4\xa2\xe6\xc7\x17\x65\x2f\xb2\xa2\x12\xb5\xc7\xc3\xe4\x02\x84\x7c\x41\x94\x77\x7a\x09\x06\xe7\xa7\x94\x65\xab\x20\xb8\xe7\x50\xb1\xb4\xa4\xf2\x2f\x8d\xdb\x89\xd3\x41\xce\x3f\x18\x3a\x3f\xf6\x25\x70\x15\x48\x1b\xc8\xe2\x0f\x43\x62\xf9\x36\xcd\x29\x76\x0d\xd0\x7b\x28\xfe\xd7\x02\x0b\xdd\x8e\xae\x45\xb3\xa6\x6c\xab\xf2\x1e\xb2\x2b\x0d\xb3\x26\xd6\xeb\x2b\xf1\xbb\x8b\x38\x61\xd6\xa1\x3a\x32\x9c\x59\x34\x01\x3d\x70\x97\x70\x39\x64\x39\xe5\x08\xdc\xe6\xf9\xf3\xbe\x46\x67\x8a\x7b\x35\xdb\x13\x76\x66\x96\x72\x6f\x10\x44\x82", 211);
*(uint64_t*)0x20000de8 = 0xd3;
*(uint64_t*)0x20000df0 = 0x20000540;
memcpy((void*)0x20000540, "\xa3\x9a\x3c\x0e\xd9\xff\x8b\x89\x6c\x1c\x4f\x3a\xde\xce\x19\xb9\x4d\x33\x74\x51\x1c\x5b\xf1\x00\xab\x05\xbc\xc2\x3c\x4e\x2d\x0e\xcf\x19\xb6\x76\xff\x1e\x25\x46\x50\x6b\x42\x6c\x2c\x7a\xb8\x49\x2e\x50\x8c\x72\xf6\xcb\x17\xb2\xe7\x44\x7b\x85\xd2\xc9\xf4\xc7\x16\x35\xdb\x37\x23\xce\xd2\xa2\x60\x6c\xb7\xde\x83\x70\x2c\x5c\x18\xaa\xac\xfd\xa0\x43\xd6\xa0\x20\xd7\x04\xc4\xa9\x2a\x6a\xf5\x5f\xb7\x9e\x54\x69\x01\xe8\x4c\xb8\x9f\x0d\x62\x7e\xca\x27\x49\xb7\xde\xb1\xc2\xe6\x5c\x06\x00\x00\x00\x00\x00\x00\x00\x8d\xe9\x2a\x45\x2f\x23\xdd\x9a\x07\x86\xb1\x63\xa2\xb2\xa1\xed\xbd\xeb\x96\xf1\x0a\x48\xe5\xa6\xb0\x8d\xc8\x82\x80\x2c\x56\x03", 158);
*(uint64_t*)0x20000df8 = 0x9e;
*(uint64_t*)0x20001a98 = 4;
*(uint64_t*)0x20001aa0 = 0;
*(uint64_t*)0x20001aa8 = 0;
*(uint32_t*)0x20001ab0 = 0;
*(uint32_t*)0x20001ab8 = 0;
*(uint64_t*)0x20001ac0 = 0;
*(uint32_t*)0x20001ac8 = 0;
*(uint64_t*)0x20001ad0 = 0x20000100;
*(uint64_t*)0x20000100 = 0x20000600;
memcpy((void*)0x20000600, "\x06\x46\xba\x4e\x78\x65\xaf\xd6\x13\x2e\x15\x16\xea\x44\x08\xa5\xbf\x46\x0b\x12\xa7\x3d\x2c\xa4\x22\x92\xc7\x80\x88\x33\x50\xc0\xf6\x9a\x2c\xc6\xcb\x48\x61\xb2\x79\x39\xd2\x67\x37\x53\xf8\xc5\x2f\x83\xef\xc9\xc4\xf3\xc5\x44\xb1\xc7\xa7\x39\x17\x6f\xf3\x96\x8a\x46\xaf\x9d\x7a\x81\x66\x77\x16\x71\x60\x66\x77\x67\x10\x48\x6c\xec\x1d\xcf\x7c\xd5\xde\x89\x19\x09\x4f\x73\xb3\x7f\x37\xec\x58\xbf\x4d\xbb\x3a\x2a\x38\x03\x2b\x53\xe2\xf9\xa5\x50\x61\xad\x31\xa4\x56\xbb\x85\x7f\x4c\x9f\x68\x57\x40\xb9\xa5\xf6\xec\x22\xf3\x9c\xb0\x3b\xe7\x35\x38\x66\x79\x1e\x35\x4c\xbc\xb1\x60\xb4\x8d\x31\xe9\xa1\x76\x14\x56\xd6\xd4\x35\x49\xc5\x96\x29\x40\xea\xc5\xa6\x0c\xfd\x57\x68\x0e\xeb\x31\xe3\x61\xd1\xfb\xcf\x86\xcd\x6a\xfb\xdb\x86\x1f\x6c\xe1\xd3\xe0\x31\x5f\x82\x78\xc7\x81\x4a\xbf\x90\x18\x9c\xc5\x04\xda\x02\xcc\x1e\x73\x06\x37\x75\x39\x7e\xd4\x6c\x91\xd9\x65\x3e\xa3\x78\x56\xfc\x36\x40\x40\x3d\x9b\x50\xa1\xa3\xd8\x1b\xb9\x59\x6d\xa2\x23\x0c\x49\xcd\xef\x89\x53\xea\x1e\x07\xfc\x3f\x05\x5d\xe0\x1a\x12\xc1\x7b\x53\xc3\x85\x22\x6c\xe0\x0d\x02\xcb\x6c\xfd\x3d\x70\x01\x28\x55\x35\xf3\xc6\xf5\xc4\x40\xab\x38\xe9\xdb\x53\xef\x82\x17\xe1\x6e\x2d\x51\x29\x3a\x2e\x16\xd4\x8e\x26\xda\x89\x4d\x70\x07\x1b\xc8\x95\xa9\xfe\x40\x20\x3c\x1e\x99\x04\xc9\xd7\x26\xef\x60\xbf\xec\x79\xd4\xe3\x45\x16\x77\x5a\x90\xa3\xef\x9b\xde\xf0\x35\x6d\x53\xe0\x9b\xee\x11\x2e\xc9\x27\x9f\xe4\x9f\xb8\xf1\xfe\xe8\x50\xd5\x9a\x4b\x7f\x44\xf7\x42\x5f\xab\x64\x36\x06\x51\x13\x64\x2c\x7f\xb5\x09\x26\xee\x48\x30\xdb\x26\x4c\x59\xdd\xc5\x74\x11\x05\x53\x6e\x82\x11\x6d\xb1\xe8\x10\x72\x6f\x75\xd2\xb2\xc1\xf0\x85\xb3\x31\xba\x51\xfb\xa8\xe4\x30\xea\xde\x49\xb7\x4f\xef\xdc\x78\x3c\x5a\x93\x0d\x1d\xa3\x20\xb9\xab\xa2\xeb\xa5\x65\xe3\x48\xcb\x00\x61\x77\x7e\x6d\xbc\x70\x97\x6f\x01\xc4\x6d\x9d\xe9\x23\x54\xb1\x33\x74\x5b\x3c\x3d\xab\xee\x6c\x07\xe2\x37\x17\x8e\xd1\x81\x75\x35\x22\x98\x9f\x85\x0f\x69\xbb\x82\x92\x25\xbc\x78\x56\x35\x20\x5b\x52\xf0\x14\x46\xe1\x52\x36\xb8\x23\x1c\x1c\x54\x3a\x3d\xe9\x1a\xad\x0c\x51\x23\x03\xac\x98\x66\x05\xe4\x9f\x9c\xc5\x01\xa7\x50\x53\xa1\xed\xf5\x9c\xbf\xf4\xba\x2b\x9b\x4e\xeb\x63\xf7\x67\x2b\xe1\x8b\x08\xa3\x98\x37\x11", 531);
*(uint64_t*)0x20000108 = 0x213;
*(uint64_t*)0x20001ad8 = 1;
*(uint64_t*)0x20001ae0 = 0x20000480;
*(uint64_t*)0x20001ae8 = 0x18;
*(uint32_t*)0x20001af0 = 0;
*(uint32_t*)0x20001af8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20001a40ul, 3ul, 0x2000c000ul);
*(uint64_t*)0x20003900 = 0;
*(uint32_t*)0x20003908 = 0;
*(uint64_t*)0x20003910 = 0x200004c0;
*(uint64_t*)0x200004c0 = 0x20000140;
memcpy((void*)0x20000140, "\xaf\x2d\x28\x8b\x0f\xef\x3c\x87\x04\x90\x59\x2d\x5d\x28\x1d\xda\x6c\x05\x98\x01\x0e\x7c\xd0\xba\x39\xee\x70\x09\x70\x73\x3d\xa8\xfb\x84\x9e\x3b\xd0\x62\x41", 39);
*(uint64_t*)0x200004c8 = 0x27;
*(uint64_t*)0x200004d0 = 0x20000400;
memcpy((void*)0x20000400, "\x56\xdf\x36\x19\xcd\x56\x82\x7e\xf8\x1d\x24\x2f\x95\xf4\x3c\x27\x4d\xe2\xcd\x9b\xc2\xa1\xe2\x53\x82\x61\xa5\xf7\xe5\xb1\x99\x13\x45\xfb\xef\x90\xf9\xc2\xfa\xc0\x02\x7f\x5f\xe1\xf7\x8f\xb0\xc1\x46\x66\x6c\x48\x3e\xbc\x25\x9b\xf0\x76\xc8\x23\x6b\x1e\x60\x5c\x9e\x80\x5f\x34\x48\x48\xbe\xfd\x2c\xe8\x4e\x1c\x37\x35\xe3\xa4\xb0\x29\x64\x5d\xba\x0f\x15\x21\x34\x0e\x2d\x74\x49\xdb\x33\xd5\x86\xe3\x6f\x0c\x24\xde\xbb\x0f\x07\x05\x9e\x8d\xb5\x9b\x57\xd8\xdb\x10\xf6\x07\x6b\xc1\xaa\x08\x84\x63\xbb\xf5\x94\x2e\x06\xc8\xc0\x1a\x8d\x44\x5c\x1f\xb9\x22\x27\x99\xbe\x69\x00\xb7\x48\xa4\x1c\x32\x79\x15\x7f\xae\xb4\x17\x29\x3e\x3b\xee\xf1\xae\x25\x09\x78\x89\xc2\xfc\x99\x58\xc6\x76\x1c\xb2\x47\x63\x77\x5d\x30\xca\x40\x75\xe9\x0c\x0a\x2b\xb8\xa0\x3c\x82\xf0\xd1\xdd\xc9\xfe", 191);
*(uint64_t*)0x200004d8 = 0xbf;
*(uint64_t*)0x200004e0 = 0x20000180;
memcpy((void*)0x20000180, "\xd6\x43\xfd\x4d\x2a\xbd\x4b\x32\xf1\x07\xc2\x61\xa2\xf4\x59", 15);
*(uint64_t*)0x200004e8 = 0xf;
*(uint64_t*)0x200004f0 = 0x200000c0;
memcpy((void*)0x200000c0, "\x5b\x74\xde\x89\x99\x8e\x59\x2a\xb0\x2a\xd7\xb4\x94\xf2\x7f\x4c\xc5\x4a\x6b\x97\x93\xe9\x4a\xaa\x59\xae\xc4\xa1\xfd\x16\xf8\x6e\x32\x76\x0e\xc0\x90\x21\x4d\xc1\xa7\xcc", 42);
*(uint64_t*)0x200004f8 = 0x2a;
*(uint64_t*)0x20003918 = 4;
*(uint64_t*)0x20003920 = 0;
*(uint64_t*)0x20003928 = 0;
*(uint32_t*)0x20003930 = 0;
*(uint32_t*)0x20003938 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20003900ul, 1ul, 0ul);
	return 0;
}