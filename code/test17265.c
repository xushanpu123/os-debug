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
	res = syscall(__NR_socket, 0x11ul, 2ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000000 = 0x200002c0;
*(uint16_t*)0x200002c0 = 0x1f;
*(uint16_t*)0x200002c2 = 8;
*(uint16_t*)0x200002c4 = 1;
*(uint32_t*)0x20000008 = 0x80;
*(uint64_t*)0x20000010 = 0x20000040;
*(uint64_t*)0x20000040 = 0x20000180;
memcpy((void*)0x20000180, "\x69\x7c\xdf\xce\xd8\x51\xe3\x26\x5c\x51\xe7\x01\xc0\xf5\x5b\x3d\x48\xb6\x4b\xb6\x0a\x25\x1f\xf5\xb4\x60\x24\x72\x09\x8f\xaa\x40\x91\x7f\x68\x0b\x25\x45\xe7\x35\x63\x4e\x77\xd4\x67\x51\x75\x29\xe7\x5b\x9b\xe3\xce\x9c\xc5\x19\xb1\x7a\xa0\x98\x8d\xbd\xd3\xa2\x34\x10\x0b\xdf\xa1\xc9\x4b\xda\x50\x8a\xc1\x3a\x76\xea\x82\xe9\xbe\x8f\x69\xf2\x81\x0f\x1d\x4c\x37\x58\x9c\xdd\xe2\xf9\xab\x61\x15\x22\xed\xc3\xf6\xa9\x23\x55\xba\xea\xe8\x89\x4b\x92\x93\xcd\x86\x40\xb6\x42\x5f\xb4\x93\xfb\xde\x24\x99\x40\xfb\x76\x39\x0f\xd8\xd5\x04\xb7\x18\xa4\x2a\xea\x78\x6b\x1d\x36\xba\xba\x8d\x15\x20\x9d\x31\x08\xaf\x6e\x66\xf4\x04\x0f\xb2\x53\x61\x7e\x1f\x26\xc3\x48\xc9\x9e\x5c\xda\x6c\xfa\xd4\x57\x2a\x3f\x7e\x4a\x8c\x0b\xba\x42\x31\x18\x13\xf3\xce\x41\x11\x77\x16\x16\x2d\xae\x9e\x30\x0d\xcd\xb2\x52\xfb\x6f\x4c\x10\x29\x67\xfe\xfa\x33\x02\x8d\x1e\x05\xba\x7a\xe7\x6f\xb3\x4c\xfc\xa5\x69\xa6\xba\x54\x0b\x18\x0d\x0b\x2f\xfd\xf4\x73\x59\x7c\x15\x44\x48\xad\x40\xda\x71\x58\xaf\x6a\x6d\xec\x40\xb0\xea\xbc\x2d\xe0\xfd\x61\xdc", 252);
*(uint64_t*)0x20000048 = 0xfc;
*(uint64_t*)0x20000050 = 0x20000340;
memcpy((void*)0x20000340, "\x7a\xb2\x52\xf3\x28\x5e\x7d\x86\x68\x0c\x1f\xfd\xe9\x04\x21\xcb\x91\xda\xe6\x68\x11\xd5\x4d\x5e\xae\x26\x05\x24\x18\xaa\x41\x19\xd0\xd4\x2a\xf3\x3e\xb5\x7e\x11\x74\xa5\xd4\xf8\xf0\x9f\xb5\xfd\x33\x7e\xfd\xb3\x75\xc0\xf9\x96\x1d\xd7\x77\xda\xcf\x67\x21\x96\xc0\xf6\xb7\x02\xe5\x82\xd0\x3c\x48\x85\xed\x8e\xd9\x56\x6c\x99\xdf\x1f\xbf\x30\xf1\xea\x40\xcb\x31\xc7\x8e\x56\x0c\xfb\x16\xae\xce\xd5\x23\x7b\xf2\xfd\x9a\x99\x7a\xea\xcd\x8f\x42\x0e\xff\xc7\x93\x15\x37\x66\x01\xae\x58\xf7\xa5\xdd\xa6\xb0\x2d\xac\x14\xc2\xd1\x33\x2d\x9a\xee\x19\xa9\x8d\xf5\x65\x8f\xe5\x7d\x7c\xc0\xaf\x14\x9d\xc3\xf3\xe4\x96\x72\x94\x83\x4f\x5a\xeb\x54\xb9\x72\xdc\x6b\x22\x0c\x54\x6e\xb6\xbd\xdd\x03\x10\x77\xca\xb2\x4f\x24\xa5\xeb\xa8\xc8\x90\x8e\x45\x5e\x21\x49\x33\xfd\xbb\xb3\x44\x65\xe4\x67\xc5\x68\x96\x97\x62\x39\x3a\x5d\xd3\x46\x02\x0c\x68\xec\xb0\x6a\xa4\x38\x02\xa8\x1a\x0c\xbb\x39\x9f\x87\xfd\x04\x82\x5f\x14\x73\x8b\x6f\x19\x75\x76\x3d\x32\x1b\x1a\x64\x75\xf8\xba\x29\xe7\xe7\x22\x51\xf2\x78\x0c\x28\x03\x2b\xb7\x74\x85\x81\xf2\xca\x8f\x54\x95\x09\x07\xac\x00\x82\x70\x48\xce\x59\x20\xb0\xf1\x59\x2e\x2b\x1c\xbf\x3e\x18\x82\xe4\x5c\xa2\xf4\x23\xf3\x57\x4a\xb8\x8c\x8b\xc1\x9d\x62\xaf\x2e\xe3\x30\xa8\xb9\x95\xab\x15\x00\x00\x73\x48\x1b\x06\x67\xf0\x61\xf0\xa0\x89\x40\xdf\x64\x4f\x24\x4c\x8f\xfb\xa8\x40\x1f\xfe\x07\x5f\x04\x6c\x84\x6f\x08\x4c\xec\xe1\x36\x21\x9e\x83\x14\x06\x5e\x41\xfe\x72\x04\x73\x4d\x84\xa6\x13\x8d\x53\x45\x16\xbc\x55\xf9\xb4\xff\xcc\xda\xe7\x41\x85\x12\x22\x0a\xbc\x77\x4d\x91\x12\x5c\xbc\xd0\xc6\x78\x7f\x97\x69\xe0\xdd\x5b\x87\xbe\x6c\xd9\xea\xfc\x75\x23\x8f\xc4\x67\x97\x61\x0a\xca\x7d\xaa\x4e\x89\x83\xf4\x98\x86\x03\x5a\x75\xc0\x92\x16\x71\x39\x36\x74\x6a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 432);
*(uint64_t*)0x20000058 = 0x1b0;
*(uint64_t*)0x20000060 = 0x200000c0;
memcpy((void*)0x200000c0, "\x38\x87\x8d\x8d\xe1\xc9\xac\x56\x09\x05\xe7\x09\x9d\x82\x7b\x9c\xe4\xfa\xf1\x6a\x78\x9d\xe6\xe4\x8d\x43\xd8\xb5\x0d\xaa\xf7\x49\x9f\x18\xdb\x03\xaa\xf7\xf0\x02\xe0\x00\x7e\xcc\x20\x4f\xc6\x53\x0a\x4e\x8e\x76\x9d\xfe\x32\x47\x12\x3a\xda\x20\x12\x64\x2b\x91\x45\xca\x82\x1b\x58\x5d\xac\xa8\x22\x94\x9e\x0e\x44\xe1\x61\x25\xb9\x17\x58\x3d\xfc\xac\xbf\xbd\x28\x19\x06\x5a\x1b\x8c\x30\xe1\xfe\x19\xf8\x9e\x3e\x39\x28\xab\xa9\x42\xb2\xb8\xb7\x1e\x31\x94\xa1\x6b\x71\x6b\xaa\x51\xb0\xc2\xa8\x44\xf0\x8f\x57\xdc\x01\x85\xa3\x82\x92\x78\x1a\x00\xa0\x67\xe8\xd5\x9d\x4b\x8b\x3f\x06\x50\xc3\x6a\x54\x18\x07\x9e\xe2\xab\x1b\x32\x33\x04\xfb\xc2\x3e\x69\x5e\x3c\xb9\x7e\xf8\x1f\x7e\xad\x02", 169);
*(uint64_t*)0x20000068 = 0xa9;
*(uint64_t*)0x20000070 = 0x20003ec0;
memcpy((void*)0x20003ec0, "\x98\x6f\x29\x68\xa5\x1e\xb1\xc2\xe5\x0d\xb8\xfe\xe0\x8a\x2f\x9f\x73\x02\x84\x4d\x04\xc9\xd5\xbf\xe8\x78\xae\xf7\x10\x13\x18\x46\x92\xb3\x32\x87\x84\xb1\x4a\x44\xcc\xfa\x84\xe0\x49\x9a\xe8\xb1\xfb\xbe\xec\xf3\x5c\x3a\x83\xa0\x7e\x2f\x9e\x52\xe3\x53\x6e\x11\xa7\x6e\x79\x44\xf8\x26\x56\x93\x70\x5d\xb4\x02\xca\x60\x08\xca\x23\x2d\x8e\xf3\x4c\xb9\x1f\xb1\xd1\xbb\xf3\x3e\x8c\x3f\xbf\xe7\xfc\x56\xbd\xc5\x45\x6d\x3d\x78\xff\x46\x5d\xa4\x1c\x72\xbb\xed\x15\x79\xe0\xf3\x71\x04\xcb\xab\x5a\x75\x50\x83\x8a\xed\x02\x10\xf4\xed\x70\x54\x2f\x16\x48\x23\x24\xb1\x33\xca\x2d\x31\xe1\xc2\xb2\xdd\x19\xb1\x83\xe4\x09\x1d\x75\x1d\x92\x1c\x4e\x21\xda\x7a\x4b\x1d\xb5\x87\xda\xdc\xdb\x73\xa8\x80\x96\x25\x0b\x64\x26\x4c\x22\xed\x2d\x82\x91\x84\x52\x54\x8e\x94\x20\x77\x33\xc9\xa6\x7c\x7a\xbe\xde\x8d\x8f\x6e\x6d\xdf\xfc\x48\x70\x51\xef\x7b\x00\xce\xa0\x2f\x1d\x88\xc9\x2b\x61\xef\xcb\xcc\x4a\x99\xad\x86\x39\xd4\x10\x41\xad\xec\xba\xac\x50\x99\x5c\xe5\x58\xdb\x5e\x9d\xad\x67\x12\xeb\xab\xe3\x63\xf4\x0e\x91\xd3\x80\x86\xef\x74\x7c\xb5\xab\x31\x83\xdd\x26\xfc\x97\xb6\xba\x31\x57\x94\xc8\xf2\x5b\x39\xd4\x86\xf9\x4b\x11\x42\x52\x98\x64\x14\xd9\x35\x16\x7b\x66\xf3\x3c\xbe\x71\xec\x89\x6e\xcf\x5b\xaf\xa6\x51\x89\x83\x44\x6f\xc2\x3e\x4c\xb6\xcc\xdd\xc8\x9e\x81\x1f\x6f\xbf\x39\x39\x5e\x5a\x0f\x8e\x86\xf3\xae\x8c\xa8\x59\x6d\x01\x9d\x32\xa4\x5f\x4c\x7a\x70\x79\x29\x7e\xe6\x53\x14\x60\x47\xed\x54\x67\x14\xb7\xe8\x4c\x31\x45\x13\xa9\x1a\x1c\xcc\xa3\x25\xb8\x91\xf0\x7a\x24\x30\x76\x80\x8b\x18\xc4\xe5\x14\xd2\x41\x83\xec\x46\xd4\x6a\xd8\x96\x19\x0d\x54\x68\x00\x46\x6f\x35\x7f\x04\x92\x3e\x88\x13\xbb\xbc\x38\x46\xf9\xb6\xd1\x94\x21\x82\xdc\x2b\x0a\xf4\x58\xde\xce\xb9\x46\xdb\x6e\xb8\x17\x6c\xfe\x2e\x00\xa5\xb9\x31\x12\xe0\x86\x01\xe5\x93\x6f\xfe\x9b\x78\xa0\xdc\x94\x4c\xb8\xde\xca\x8c\xeb\x94\xc1\x21\x04\x4f\x32\x65\x86\xec\x28\xbc\xda\xe2\x1b\x75\xea\x24\x89\xd2\xab\x64\x83\x5c\x60\x08\x2c\x52\x67\xd1\x66\xc1\x0e\x37\xd4\x09\x44\xa7\x56\x3d\xc8\x82\x0e\xcb\x79\xca\xcf\x76\x41\x8a\xb0\x66\x3a\x53\xdd\x61\xfc\xb2\x0d\xb6\x9e\x28\xd2\x82\x57\x0d\xa5\xb0\xe8\x41\x33\xfe\x10\x0f\xf5\x3a\xd9\x14\xee\xd8\xe3\x9c\x1c\x9f\x4a\x4a\x3f\xc8\xbf\x88\x22\x51\xcd\x12\x6e\x53\x41\x87\xaf\x84\x52\xdb\xe0\x15\xd8\x42\x23\x51\xb2\x5c\xb3\x18\x6f\x3f\x27\x0f\x36\xee\x77\x28\x0b\xba\x03\x71\xc6\x20\x12\xfc\xda\x34\x06\x17\x06\x2f\xdb\x0e\xa8\xdf\x4e\x41\x04\xb1\xeb\xda\x39\xda\xc6\x43\xe4\x2b\xd2\x7f\xed\x92\xf9\x1d\xd8\x55\xb6\x39\x43\x6b\x40\x03\x08\xe8\x52\xe6\x8b\x72\xc5\x22\x2d\xfa\x0c\x65\xf4\x41\x17\xec\xa4\x48\x97\xf6\x1e\xe6\xa2\x63\x0e\x31\x3f\xe8\x8a\x38\x48\xbd\x12\x3e\x4b\x4b\x69\xc6\x1d\x85\x50\xe7\xca\xb4\xb3\x73\x7e\xcb\x08\x13\x54\xf3\xa3\xaa\xb9\x1f\x83\xc1\xdd\xdb\xf7\x0f\x2a\x4a\xed\x68\x30\x16\x8c\x47\xd8\x6f\x9b\x68\xa9\x5b\xa8\x2f\xc2\x11\xfe\x9b\x46\x0a\xb9\xb8\x4e\xb2\x76\x74\x25\x51\x6c\xc5\xc0\xcd\x90\xc5\xbc\x60\xbe\x0e\x19\x0c\x4c\xff\x3c\x6e\xa8\x5d\x4f\xae\x37\x7d\x2f\x25\xd6\x8b\xb7\xd3\x16\x4f\x32\x9f\x00\xd7\x26\x9a\xc6\x98\xd4\xd8\x8c\x77\x51\x4f\x77\x18\x05\x30\xee\x40\x18\x96\xbb\x21\xc0\x07\xc0\xac\x8c\x2b\x41\x96\x5d\xeb\xc5\x63\x65\x2a\xb2\x57\x09\x65\x3c\xd8\x8e\x81\x5e\x1e\xbe\xf8\x8d\xbb\x34\xf1\xd2\xd5\x6f\xb5\x8f\x94\x62\x4a\xc8\x6e\x34\x66\x0b\xac\x42\x99\x1a\x09\x29\xcd\x57\x2d\xf5\x02\x4d\x16\x83\xc0\x43\xbd\x88\x7e\x24\x82\xf8\x68\xde\x03\xa3\x13\x1c\x7f\xa7\x4d\xc6\xf5\x78\xfb\x20\x77\x9b\x64\xe3\xb7\x0b\x9d\xcd\xab\x79\xed\x5a\x78\xe1\x6e\x29\xf1\xdb\xbf\x72\x9d\xee\xe0\x14\x84\x37\xdb\x4e\xb6\x90\x72\x74\x68\x09\xf8\x7c\x85\x49\xb3\x4e\x2f\xea\x7f\x2b\x9e\xa4\x14\x8a\x02\x34\x64\x28\xde\x0a\x2a\x37\x07\x30\x23\xe1\x5b\x34\x54\xab\x16\x34\x21\x65\xee\x41\x51\x09\x5f\xbb", 906);
*(uint64_t*)0x20000078 = 0x38a;
*(uint64_t*)0x20000080 = 0x20002400;
memcpy((void*)0x20002400, "\x86\xf9\x5a\xff\x98\x92\xd1\xae\x6e\x2b\x33\x6a\x65\xc2\x82\xc3\x57\x33\x92\x30\x70\xcf\x72\xb4\x41\xb3\x4e\xb6\xf9\x02\x70\x3d\x13\x45\xb3\x7b\x3d\x44\x76\x16\x94\x86\x5f\x73\x97\x59\x64\xc1\x31\x0c\xf2\xcf\x3b\xb5\x97\xbf\x05\x8c\xbf\xf5\x81\xc0\xb4\xb2\xad\xa7\x56\x62\x70\x92\x70\x01\x43\x61\xe5\xc5\x84\xe0\xb2\x84\xef\xb8\x04\x35\x1c\x8d\x56\x57\x40\x1b\x80\x4b\x5b\xaa\x27\x79\x0b\x72\x15\xfe\xde\x1f\xfc\xee\xb0\x9d\x94\x9d\x33\x8b\xb7\xbb\x13\x61\x0f\x9c\x1e\x7b\xfb\x06\xbc\x1c\x4e\x45\x39\xbc\x36\x02\x37\xf6\x3b\xd2\x39\x26\xa6\x05\x0f\xe3\x0c\x35\x80\xf9\x2d\xc9\xcd\x63\x33\xe5\xe6\xf9\xc2\xbd\xb4\x98\x21\x84\x23\x87\xd0\x6c\x74\xfd\x6c\x01\xea\xd6\xa9\x0a\xc2\x42\x63\x24\xbc\x14\x22\x78\x11\xb0\xc8\xe2\x9f\x8e\x0b\x32\x9f\x7c\xad\xb7\xbd\xf6\x29\xdb\xc2\x4b\x9a\x69\x04\xe9\x24\xd7\x32\xec\x0d\xef\x2a\xd4\x7d\xae\xd7\xae\x6d\xe8\xac\x80\x5b\xe5\x86\xc4\x73\x87\x00\xe2\xbf\x90\xc8\x47\x6d\xea\xf1\x7a\xf4\x76\xf0\x82\x16\x58\x92\xa1\xbe\xe3\x4e\x7f\xaf\x45\xa7\x71\x8b\xa6\x6a\x45\x80\xd2\x6d\xb7\x2b\x73\x20\x65\xef\x74\x3a\x8f\x90\x3c\x14\x0e\xb2\x04\x4c\xfd\xab\xcd\x78\x5b\x0e\x2a\x89\xeb\x06\x42\x8d\x10\xdf\xe4\x8f\xcb\x10\x73\xbd\x82\x04\xa3\x27\x93\x25\xf4\xc4\x3b\x11\x10\xcc\x62\x02\xc3\x40\xbd\xe1\xcd\x98\xca\xa4\x95\x6d\x75\xf2\x71\xd1\x48\xc0\xfe\x33\x69\x94\xf7\x5c\xe3\xf1\xaf\x83\xac\xf4\x7b\x68\x06\xe2\xa3\x48\x92\xeb\x00\x0b\xf8\xfa\x26\xae\xd6\x17\xb8\x68\xfe\x45\xfc\xcb\xf0\x96\x00\xeb\x2b\x81\x8c\x53\x34\xad\x63\xe1\x96\xdc\x90\x2a\xc7\x47\x66\xfb\x7c\x76\xd2\x61\x8d\xb7\x2b\x5c\x99\x66\xdb\x4e\x4a\x33\xc1\x40\xd3\x34\x78\xeb\xb9\x1a\x0b\xcd\xc3\xb3\x22\xf6\x44\x31\x8d\xed\xfd\x15\x59\xaf\x18\x82\x45\xbe\x73\x12\x62\x3b\xb4\xb5\x9a\x3d\x26\x7e\xb6\xb2\xa7\x93\x58\xea\xe7\x3f\xf2\xfd\xf9\xb7\xb0\xe2\x9b\x80\x49\x81\xec\x66\x60\x88\x9c\x49\xa8\x0d\x8a\xaf\x96\x21\x9c\x80\x02\x34\x2c\x4c\x1d\x3d\xc5\x25\x53\xaf\x60\x38\xaf\x5e\xf3\x37\xb8\xc1\xb5\x2e\x1c\x42\x86\xd5\xfc\xda\x4f\xd7\x5c\x14\x93\x1a\x63\x7a\xfe\xec\xb2\x2b\x0f\xf1\x63\x63\x29\xbe\xa7\x4c\xfb\xd5\xe3\xbb\x88\x6a\x7b\x09\xa4\xff\x93\xec\x5d\xac\x97\x61\x68\x5c\xfc\x3a\x06\x34\x05\xea\x69\xc8\x19\x1c\x0b\x56\x54\x3f\xed\xf4\x3f\x25\xd5\x55\x5b\xbf\xbd\x1c\x3f\xc7\xe3\x48\xdd\x31\x43\xc2\xc2\x60\x7e\x81\xad\x90\x1a\xd9\xc5\xbf\xa4\x2f\x33\xe5\xe1\x25\xbe\x18\x11\x0f\x20\x1d\xe9\x6b\x5d\x6e\x96\x0a\x04\x74\xaa\xa9\xd4\xd0\xea\x0d\x50\x4d\x4d\xe5\xc8\xb8\x57\xa5\x70\xa4\x53\x43\x4e\x43\x70\x1f\xe3\xbb\xf8\x27\x68\x9c\xa3\x91\x83\x93\xdc\xa6\x69\x51\xe2\x40\x7d\x7a\xea\xc2\x9d\x2f\x5d\x21\x06\xcf\x5e\xdf\xc2\x3f\xa1\xea\xa6\x66\x51\xd4\xef\xd5\xde\x43\x85\xaa\x72\x93\x0b\x58\xc1\x01\x4e\x85\xc1\x5b\x97\xe7\x40\x1a\x6e\x77\xd8\x93\x39\x04\xaa\xaf\x9b\xcb\x81\x76\x61\xc9\x4c\xa6\xa2\x20\x5e\xff\x58\xbb\x95\xdd\x07\x26\x71\xf7\x01\x1a\x3f\xea\xd2\x27\x94\x7e\xbf\xd1\x32\xf2\xee\x03\x12\x60\x4b\x65\x12\xf8\x95\xd0\xde\x89\x30\xe7\x16\x89\x9a\xeb\x3f\x58\x5c\x0a\x1d\x27\xce\x11\x1c\xa3\x3d\x1f\x82\x72\x86\xd9\x74\xc7\x5c\x4a\xeb\x33\x71\xd5\x05\xf8\x47\x9b\xcd\xea\xaf\x16\x70\x4f\xa3\x60\x0d\x34\xbe\x55\xd7\x50\xcf\xfb\x9b\x82\x10\x39\xfb\x7c\x65\x61\xcf\x2a\xa9\x7e\xf5\x06\x97\x26\x1e\xac\x27\x8f\x2b\x1c\x10\x43\xb5\x3f\x4c\x25\x6d\x9b\xfb\x79\xe8\xbd\xf2\xfc\x13\x45\x8a\x65\xb6\x74\x5a\x3d\x64\xc5\x27\x2c\x33\xc4\x7f\x30\x3d\x6b\xf4\xed\x34\xcb\xf5\x5e\x8d\x29\x48\x86\xd4\x05\x82\x90\x50\xab\xa1\x0c\x2d\x8e\x20\xae\xda\x57\x15\x40\x2e\x69\xa1\xc2\xdb\xcc\xba\xdc\x1e\xdc\xb1\x75\x00\x50\x14\x1a\x50\xbc\x7a\x08\x79\xc1\x05\x2d\xa8\xcc\xdf\x00\x34\x8f\x57\x5d\xf6\x75\x6c\xe1\x67\xc5\x9f\xc3\xaa\xcd\x1a\x6f\x99\x1f\x34\x79\x30\xc6\xd0\x48\x8b\x5e\x7f\x1f\x33\x00\x48\x99\xf5\x53\xa3\xfe\x51\xb2\xb6\x09\x68\x14\x14\xad\xb7\xab\xdb\x50\x4f\x07\x00\x80\x4b\x33\xd3\x96\x45\xc0\x8f\x00\x7b\x38\x77\x52\x68\x87\x16\xe6\xf9\x25\x18\xa2\xae\x25\xbe\xf3\xb5\x4d\xb2\x9b\x1a\x84\xad\x2e\xd3\x4d\x45\x05\x6b\x6d\xc3\xf2\xb0\x40\xd5\xfd\xa8\x21\xd1\xf3\x7f\x96\xd3\x85\xdf\xa2\x8a\x13\xac\x78\xf4\x12\x46\xb1\xeb\xbe\x9e\x41\xe6\x33\x51\x1a\xa6\xa7\x3d\xde\x67\xa1\x45\x94\x8e\xf7\x39\x8e\x3f\x49\x8c\x96\xbd\xa1\x7c\x79\x21\x6e\xeb\x5f\xa8\x5f\x1e\x12\xa9\x22\x28\xd2\x8a\x57\x15\xa7\x72\xe4\xd3\x8e\x02\x76\x8f\xf3\x6c\xf7\x79\xee\x79\x5f\x18\x80\x0d\x44\xfe\x3f\x88\x84\x8c\x7e\x35\xc4\xd8\xd4\x2a\x9b\xf3\x4c\x60\xe8\xa5\x6f\xd0\x27\xc5\x05\xfb\xb7\x21\x67\xf4\xeb\x9d\x66\xd3\x4d\x75\x1c\x86\xdc\x5a\x50\x07\x05\x05\x3a\x46\x43\xc5\x91\xe0\x88\x78\xf1\xa3\x46\x73\x86\x30\x91\x82\xb3\x0f\xcb\xcb\xd5\xda\x1c\x83\xbe\x12\x9d\xab\xa9\x72\x46\xc1\x6f\xb9\x17\x88\xb5\x3e\x1a\xd1\xfc\x8a\x1a\x4f\x55\xa7\xe4\xd0\x92\xdd\x10\x83\xfc\x0b\xcd\xf4\x74\xb5\x2d\xb2\x52\x34\x29\xfd\xa6\x8c\x83\x0c\x88\xff\x5e\x31\x5b\x7f\xb3\xfa\xde\x57\xea\x22\x50\x1e\x23\x4f\x67\xe6\x29\xbf\xb3\x6b\xb5\x0d\x71\xd0\xa0\x74\xc6\x83\xab\xb7\xbb\x20\x86\xf9\x24\xd7\xea\x8d\x9b\x80\x20\x7c\x0d\x78\xe6\xa6\xec\xdc\xca\x96\xb6\xca\x87\x06\xdd\xe1\x10\xc9\x16\xc1\x62\x85\x39\xe0\x8e\x41\x83\xd6\x8f\x6f\x50\xc8\x30\xc7\x08\x9d\x20\x13\xb7\x0f\x34\xdc\x6b\x60\x73\xdd\x26\xfc\x25\x59\xcf\x78\x68\x56\x31\x23\x66\xa5\x51\x09\xac\xbf\xed\xc6\xa8\x8f\xe9\x02\xdd\xc1\xac\x56\x40\x35\x7f\x99\x38\xa7\xd5\x5a\xc1\xc0\xee\x60\x0a\x47\x1e\x99\x7f\x6d\x43\x1a\x3d\x3d\x25\x38\x1a\x1a\x2a\xed\xc9\x42\xe7\xcf\x07\x62\x93\x5f\x34\x69\x7e\xf7\x7e\x57\xc4\x53\x8b\x57\xae\x50\xeb\xcd\x2f\x27\x9e\x0e\x26\x6a\x75\x1c\x35\xde\x47\xc2\xc1\x5e\x7d\x8c\xe3\x8f\x52\x99\x4b\xde\x6f\x7f\x7e\xb2\xe0\x1e\x0e\x3b\xd8\x46\xbc\xb7\x53\xc7\x09\x66\x77\x54\xa9\x9a\x54\x78\x83\xe6\xb8\xd8\x48\xec\x3e\xc9\x83\xc0\x2c\x0d\xe7\x15\xdf\xf6\x74\x53\xd0\x22\x1b\xe4\x30\x4a\xd2\x38\x9e\x62\xd2\xb3\x6f\x56\xd5\xda\xab\xb6\xcc\x75\x72\xd8\x41\x51\xbb\x29\x5a\xf7\x94\x85\xde\x3a\x6f\x92\x1c\xa0\xe8\xf2\x32\x82\x71\x95\xf2\x94\xc1\x4e\x01\xe6\x8d\x87\x7a\xe2\x54\xb9\x7d\x6f\xa7\x96\xc4\x5d\x4b\xb2\x6f\x15\xc1\x80\xd4\xf4\x99\x1e\xaf\x34\xac\x6d\x2e\xa2\xa2\x88\x68\x31\x20\xd6\x0e\x3f\x27\xa6\x08\xa4\xf9\xe1\x81\x3a\x21\xb2\x86\xec\x11\x59\xee\x14\xc1\xfc\x72\xbe\x49\xd5\x69\xda\x6c\x30\xa0\xa8\x79\xae\x76\xfd\x07\x56\x3f\x99\x53\x8f\x47\x27\xd1\x21\x5b\x51\x04\x87\x80\x69\xb1\x26\x94\x2f\x65\x3a\x6e\x7c\x2f\x14\x32\x82\x73\x6d\xa5\xd1\x54\xdf\x93\x84\x0c\x68\x1e\xea\x7e\x1f\x38\xfe\xbe\xc7\x4b\x66\x92\x5e\xbf\x77\x08\xe6\x7e\xe1\x15\x58\xf9\xb9\xb4\x04\x1a\x72\xed\x8b\x83\x2b\xa4\x87\xdd\x1c\x9e\x09\x17\xe4\x77\x28\x34\x86\xdf\xca\x3d\x03\xd6\x21\xe2\xd7\xff\x04\x4b\xc0\x96\x9c\xb8\xee\xc6\xe0\xf5\x5a\xbc\x90\xc3\xdd\x1b\x26\x2a\x63\xa3\x11\x1a\xda\xc8\xe1\xd9\x95\x6b\x06\x3d\x1f\x2e\x59\x3f\x7d\x27\x37\xef\x1c\xd5\x66\x70\x2b\x8f\x4a\xdf\x01\xaf\xfc\xeb\x67\xba\x46\xda\xbf\x7c\x32\x36\x7a\x39\x1a\x86\x47\x2e\x5f\x03\xb9\x52\x10\xab\x9f\x71\xaf\x7f\x96\x11\x72\x8c\x6d\xa6\xbb\xb7\xbe\x80\x1b\x86\xf4\x3b\x78\xd3\xf8\x72\x23\x1e\x46\x95\xfa\x58\x2c\xaf\x8c\x18\xf8\xfb\x39\xf9\x37\x88\xab\xdb\x36\x59\x52\x2f\x89\x5f\x7e\x2b\xc1\x55\xda\xea\x0f\xf1\x5b\xa5\x8f\x28\x20\x8d\x8b\x99\x7f\x93\x71\x9f\x43\x91\xf5\xf5\x1b\x26\x45\x2b\x58\xc6\x83\x03\x1d\x61\x28\x8e\x7c\x4e\xed\x75\x8c\xbf\x92\xbe\x1d\xbe\x53\xe1\x86\x0f\x1b\xc6\x13\x31\x9b\xbc\xef\x62\xec\xe6\xf4\x2f\xff\xda\xd5\x2e\x2a\xf8\xe6\xad\x2a\xbc\xa4\xad\x6a\x77\x38\x08\x85\x10\xb8\xf3\x35\x77\x23\xf6\x35\xa3\x2b\xbe\x1a\x33\xeb\x34\xb8\x7c\x97\x44\x90\x5f\xf0\x5f\xb3\x00\x19\xe1\x05\x90\x6a\xfb\x03\x95\x74\x92\xd3\x6c\x6f\x40\xcf\x41\x1f\xa8\xe0\x66\x4f\x38\x88\xfb\x37\xda\xaa\xe2\x3e\x53\xb3\xf3\xac\x25\xfe\x30\x56\x19\x4b\xc1\xe3\x88\xa7\x64\x05\xc7\x62\x5d\xa5\x99\x4b\x2e\x31\x28\xb1\x66\xe8\xa6\x65\xae\xb3\xa7\x9d\xea\xa5\x92\xaa\x9f\xc7\x7c\x6a\x98\x23\xaa\x52\x81\x9d\x3b\x9a\x55\x59\x67\x48\x67\x4d\xf2\xbe\xea\x6b\x52\x2d\x59\xfb\x9f\x8a\x46\xba\x37\xa9\x43\x96\xcb\xf2\xca\x4d\xa6\x0f\x28\xfa\x29\xb5\xd1\xfe\x6d\x12\x9e\xdc\xaf\xef\x87\x82\x37\x49\xad\x98\x19\xf4\xb3\x47\x51\xd4\x30\x68\x19\x35\x4a\x64\xaa\xd9\x8e\x86\x56\x43\x78\xf1\xd5\xfe\x64\xa3\x36\x30\x73\x6b\x43\x6c\xbf\x04\x9f\x71\x8c\x31\x46\x2f\xae\xdc\x39\xe7\x61\xa7\x6b\x69\x8a\xd8\x9b\x16\x1c\xd9\x70\x85\x86\x9d\x74\x5e\xae\xb4\x64\xc4\xbb\x72\x7c\x30\x58\xc7\xcf\x96\x9c\x00\x33\x72\x39\xd0\x93\xd3\x01\xcf\xce\x09\x17\xd0\x83\x53\x17\x9c\x57\x2e\xe5\xfd\x26\xf7\x0e\xf8\x96\xa2\x31\xae\x83\x24\x3a\xe8\xdb\xbc\x87\x55\xb8\x82\xe3\x75\x55\x54\xc1\x80\x02\xf9\x1d\xe6\x4e\xc9\x06\xe5\xac\x8c\x53\x26\x57\xa2\xa2\xd2\xcd\x60\xa2\x9c\x1d\x55\x8e\x8a\xd7\x6b\x37\x68\x95\x59\x95\x82\x54\x02\xb8\x16\x57\x0d\x5d\x83\x89\x53\xcf\xdf\x2e\x89\xa5\xaa\xf9\x14\x10\x07\xf7\xb2\x37\x72\x35\xe2\x00\x22\xd7\xa7\x43\x3a\xd4\xf6\x20\x8c\xa7\x1e\xd3\x41\x4c\x3a\xcd\xf9\x34\x2c\x9c\xcb\x21\xc9\x5f\x60\xb3\x9b\x1e\x0c\xba\xfb\x44\x41\x37\xb3\x06\x08\x8f\x10\xc9\xd8\xc6\x3a\x31\xe4\x8a\x3d\xb0\x40\x15\x44\x81\xd3\x3b\x7c\xa0\x61\x06\xa6\xc2\x05\xdd\x3f\xb8\xdd\x26\x43\x12\x23\xd7\xd6\xb3\x5a\x7b\x43\x1a\xfe\xd4\x85\xda\x66\xfe\xff\xd6\xb4\xd5\x6c\x16\xea\x9d\x46\x8c\x40\x70\xfd\x2a\xa2\xf2\xd6\x84\x76\x24\x6d\xfa\x5a\xcc\xbd\x46\x64\x3e\x73\xba\x67\x1b\xc2\x4a\xb5\x10\x04\x57\xa3\x20\x5d\x68\x62\x88\x19\xd3\x30\x30\x2f\xbc\x6b\x32\xf5\x2c\x99\x44\xf4\x2d\x3c\x67\xe7\x9c\xc1\x53\xd5\x30\xa3\x20\x9e\xe4\x89\x57\xc6\x6e\x59\x53\xd6\x73\x3b\x09\x8d\xa3\xe4\x35\x75\x51\x54\xbe\xb3\x8e\xc0\xc4\xce\x4b\xd5\xc8\x41\x2c\x35\x16\x18\x4d\x6f\xc8\x06\xba\xfe\xf6\x22\x30\x08\x30\x1e\x4e\x0d\xe4\xdd\x77\x69\x71\x3a\x3a\xb2\x16\x0d\x5d\xcd\x84\x46\xaf\x67\x10\x2a\x1a", 2321);
*(uint64_t*)0x20000088 = 0x911;
*(uint64_t*)0x20000018 = 5;
*(uint64_t*)0x20000020 = 0;
*(uint64_t*)0x20000028 = 0;
*(uint32_t*)0x20000030 = 0;
*(uint32_t*)0x20000038 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20000000ul, 1ul, 0ul);
	return 0;
}
