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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001100 = 0;
*(uint32_t*)0x20001108 = 0;
*(uint64_t*)0x20001110 = 0x200010c0;
*(uint64_t*)0x200010c0 = 0x20000080;
*(uint32_t*)0x20000080 = 0xec4;
*(uint16_t*)0x20000084 = 0x464;
*(uint16_t*)0x20000086 = 0;
*(uint32_t*)0x20000088 = 0;
*(uint32_t*)0x2000008c = 0;
memcpy((void*)0x20000090, "\x21\xb0\x0c\xae\x97\xf6\x41\xfe\xd6\x00\x15\xfa\x67\x02\xaa\x4d\x5e\xe7\x8c\x63\xd6\x0e\x45\x3e\xe7\xc8\xc2\x0b\xce\xf0\x73\x2c\xdd\x6a\x52\xe1\x59\x58\x7a\x39\xb6\x4a\x61\x81\x4c\x7e\xd1\xfc\xe7\x83\x6b\x3c\x77\x30\x45\x6f\xf9\x7f\xb2\x50\xc2\x4d\x6d\x47\xf8\xa9\xdb\x4f\xcf\xa5\x95\x48\x52\x42\xb0\x81\x44\xf1\x80\xc8\xde\xe9\x03\xac\x37\xab\x0f\x90\xa2\xd3\xce\x8e\x9f\x10\x3d\x55\xc6\x7c\xf7\xa9\xd6\x96\x0f\x54\xd6\x3c\x0b\x0e\xce\x1d\x10\x10\xdb\x9d\xe0\x14\x55\x86\x59\xc8\xdd\x71\xcc\xdc\x8e\x30\x50\x4f\xe2\x49\xc4\x72\xa7\x5e\x61\x71\x1c\x65\xc6\x96\x7b\x23\xb4\x88\x27\x22\x2b\x8e\x77\xaf\x8a\x39\x61\x0b\xba\x64\x0a\x08\x8c\xc2\x72\xd9\x7a\x12\xcf\x33\x1e\x69\x13\x49\x5f\xac\x0e\xe8\x8c\xc0\xf2\xde\xa6\x8d\xdd\xc4\xa8\xaf\x7e\x5f\x6a\xfc\x41\xdf\xb3\x95\xc2\x96\x50\x5c\x34\xd4\xe5\xa6\x3a\xe2\xba\x20\x36\xc0\x28\x79\xa6\xfc\xf9\x6b\xc8\x6b\xd8\xcd\xc3\x67\x4b\x57\xef\xa3\xf1\x25\x7b\xbb\xd5\xb4\x68\x41\xd4\xe2\xdd\xf6\x61\x04\x72\xde\x42\xdd\x86\x84\xe6\x18\x27\x76\x62\xea\x4d\x85\xa4\x44\x14\x7e\x49\xdb\x17\x73\xb9\x18\x0f\xad\x71\x90\xb3\xa2\xf8\xdd\xd2\x37\x00\xf0\x63\xd3\x10\xfe\x44\xec\x5d\x5b\x3b\x66\xda\x7d\xa9\xf5\x2d\x09\x51\x45\xa1\xf4\x61\xad\xeb\xca\xf6\xfa\x30\xe1\xc7\x8f\xe1\x1f\xc0\xaa\x74\x60\x78\x60\x21\xbb\x82\x3a\x56\x05\xbd\xd3\x70\xe0\x46\xe0\xa9\x81\xde\x59\x4f\x51\xcf\xd0\x85\x25\x3c\x1f\xd0\x6f\xc0\xfd\x6e\xd2\x6c\xb7\x25\x75\xf7\x91\xda\x2a\x13\x63\xc3\xd9\xb0\x9a\x3e\xf7\x7f\x15\xe9\xd7\xbe\x97\x47\x9e\x53\xf8\xd8\x34\xd9\x4d\xae\xcd\xb7\x2b\xd3\x01\xe9\x0c\x7b\x1c\x2d\xbf\xca\xfe\x77\x66\x85\xc3\x0e\xc5\x44\x7c\xae\xca\x23\xab\x35\x80\x82\x41\x83\xff\xbc\x96\x62\x18\x60\x95\xbf\xdd\x7a\x34\xdb\x74\x62\x8a\x8e\x22\xa7\xcb\x49\x9b\xfe\x69\xa5\x8d\x4e\x3d\x3e\xe6\xca\xa1\xfe\xa3\x63\x57\xa8\xa3\xf5\xdd\x06\xe0\x57\x0a\x42\x5a\x44\x8c\xdd\x13\x54\x9f\xcb\x47\x91\x50\xcc\x90\x02\xb3\xcb\xcc\x67\xa7\xff\x20\xba\x9a\xc9\xf4\x97\xef\x36\xab\x41\x89\x7f\x2f\xe2\x0b\xc6\x14\x47\x0b\x29\xe3\x4e\x3f\x05\x78\xcf\x49\xa8\xb4\x48\xe3\xb2\x56\xd6\x17\xdb\x5d\x15\xe7\xeb\x7b\xc2\x21\xa5\x0b\x93\x18\x05\xfd\x98\xeb\x07\xee\xc3\xa4\x11\x30\xf2\xbb\xbe\xcc\x68\x56\xd0\x95\xb3\xf6\x0e\xfe\x32\x9c\x14\xd4\xbc\x60\xfa\xfc\x98\xc2\x0a\xfa\xb2\x3a\x3e\xee\xef\xac\x57\x8d\x2f\x0b\xd8\x66\x10\x44\x95\x44\xe2\xce\x9c\x80\x6c\x2f\xa8\xc9\x3e\xa0\xc0\x0e\xba\xc6\x43\x65\x30\x4d\x47\x39\xc3\x9c\xb5\x60\xbe\x6f\x88\x4a\x9f\x37\xff\x26\x22\x1c\x7e\x8f\x9a\x46\xeb\xc0\x13\x39\x4c\x62\x93\xf2\x20\xcd\xac\x05\xc9\xad\xb6\xfb\x75\x0d\x8b\x41\x2c\xbe\xb0\x21\xc0\x3c\xfe\x14\x05\xc4\x53\xd0\x9f\x80\xa3\x16\x8e\xc7\x24\xb5\x9f\x2b\x2f\x08\x26\x32\x65\x89\x4b\x4a\x8e\xc7\x9a\xff\xbb\xb1\x81\xe2\xa3\xfc\xf3\x54\x35\x3d\xfc\x61\x1b\xe5\xf8\xa2\xc8\x7b\xea\x5f\x4e\x8b\x3c\xf8\x61\xb3\xd8\x70\x5f\xbf\x25\x5c\x3c\x40\x74\x91\xcf\xde\x76\x58\x2b\xa1\x3c\x73\x1b\xed\x4e\x7c\x3c\x91\x1d\xf5\x4d\x3a\xed\xb7\xf8\xcc\x19\x12\xef\x25\x27\x52\x6a\x20\x29\xbd\x28\xa9\x26\x24\x10\x6e\xc2\x98\x6d\x91\xe4\x1b\x1c\x49\xf1\xc4\x92\x61\xf8\x2a\x66\xb4\x54\xfc\x42\xbd\xac\x34\xb7\x0a\x2e\xf2\xa2\xbf\xbb\xb3\x1c\xb0\x4a\xbf\xdd\xd9\x52\x35\x76\xba\xbc\x2c\x69\xa6\x4a\xfa\xc6\x28\x31\x4a\x28\xd0\x09\x32\xcc\x86\xf7\xac\x8b\x76\xaf\xb0\x9e\x42\x04\x7b\x2d\x33\x9b\x71\x61\x2b\xec\x21\xf1\xe7\xcb\xf4\xa5\x6d\x7f\xcf\xf4\xf2\x21\x22\x76\x3e\xbf\x04\x66\x7a\xa6\x17\xbc\xb3\x13\xa3\xe4\x1e\xaf\xc9\x8c\x8b\x00\x6b\xf8\x4a\x0f\x71\x63\x4a\x25\x09\xcd\xb1\x7f\x03\xeb\x41\x4a\x2a\x7d\x57\xc4\xaa\x24\x10\x21\x5a\xa4\xd3\xee\xd2\x25\xb7\xab\xb8\x3e\x31\xc9\xf0\x20\x4d\xe8\xe3\x9d\xe6\x70\x4c\x53\xf7\xc6\x31\xcc\xf0\xf2\x27\x09\xf1\x61\x50\x8b\x34\x37\x59\xc7\x02\x67\x61\x30\x5f\xc2\xf1\x8f\x49\xcb\xcf\x61\x6a\xa5\x6f\xe7\xe5\x60\x13\x8c\xa8\x68\x48\xed\xe7\xc4\xa2\x4f\x4b\x9b\x0b\xe0\x02\x91\x2b\x64\x81\x56\x43\xa6\x05\x0e\x81\x86\x57\x04\xc9\x12\x88\x79\x58\x31\xbb\x43\x61\x6d\x58\x44\xb2\x9a\x73\x22\xe9\x35\xec\xdb\xb2\x89\x4e\xf3\x5f\x2f\xe9\x38\x84\x12\x6e\xe6\x27\xb0\x15\xde\xcb\xc3\x05\x65\xc1\xb8\xe1\xd9\x95\x2e\x1c\xe4\xf2\x50\xe2\x87\xaf\x80\x37\x6e\x6a\xa0\xbe\x39\xe5\x43\xa3\x12\x66\x5d\x9f\x49\xad\x5b\xf4\x7a\x59\xc0\x25\x91\xcf\x30\x1e\x31\x0f\xbf\x46\x2c\xd5\xbe\xec\x5a\xb9\x1c\xc2\x3d\x98\xfd\x1b\xbf\x1d\xd7\x74\x5d\x20\x84\x11\x4a\x3f\xd7\xcd\x09\x88\x54\x6a\x2a\x4e\xbe\xaa\x99\x4b\x4c\x56\xbd\x40\x00\x6a\xd3\x07\x2f\xf8\x00\x02\x19\x61\x4b\xa7\xbb\xbb\xdc\x62\xe3\xdb\x18\xc0\x58\x73\x22\x03\x2e\x3c\x52\x06\x0f\x8f\x5d\xf4\x57\xc1\x2c\xe2\xec\x8d\xd3\xf7\xad\x3e\xe2\xd6\x82\xd4\xa8\x25\x59\x4e\xc6\xe7\x2b\x73\xbd\x12\x1b\xf1\x3f\xe3\x15\x85\x46\x88\x4e\x36\x41\x13\x15\x63\x9f\x57\x28\xf5\x4d\x5e\xaf\x4c\x30\xfc\x8d\x34\x21\xa5\x44\x98\xe2\x08\x0f\x5d\xf1\x78\x6b\x0a\xdf\xe1\xd3\x61\x7e\x91\x5b\x63\x9b\x47\x9e\x5d\x47\x4a\x30\xcd\xdf\x2e\x20\x37\x13\x0a\x70\x22\x79\x5f\x36\x2b\x4b\x90\x61\xd4\xe2\x2b\xe4\xa3\x48\x83\x11\xd8\x96\x3b\x42\xdf\x28\xb4\x47\xe2\x11\xf1\x89\x91\xc5\x21\xba\xd3\xb9\x98\xbb\x33\x55\x25\x5e\xfb\x69\xf9\x5d\xe3\x65\xd0\xf4\xc6\x31\xd3\x0b\xf6\x29\xd9\xc7\x8f\x13\x47\x30\xcf\x6a\xdc\x9a\xa0\x36\x0b\xdd\x4f\x41\x0e\xd4\xe9\x37\xca\x4b\x03\x2c\x67\x5d\xc9\x1c\xa0\xa3\xd2\xc5\x2a\xac\x74\x8b\xa4\xa8\x9d\x20\x54\xcb\x3b\x46\xda\xe2\x48\xfe\x97\x39\x97\xed\xdb\x0c\x99\x96\xf1\x8e\x56\x7a\x6d\x4f\x33\xd8\xfc\xb4\x35\x44\x86\x5a\x59\x36\x59\x86\x4c\x97\xfc\xae\xf4\x6a\xab\x5a\x72\xc8\x43\x0b\xf1\xe0\xf8\xae\x7c\xbc\x95\x6e\xe8\x67\xc2\xf5\x72\x7b\xcd\xaf\xc3\x02\x40\x98\x14\x13\x1c\x4c\x0a\x25\xde\x08\xb3\xe6\x42\x16\x37\xd8\x5a\x7d\x04\xa8\xd9\x0d\x5c\x2f\xf5\xc6\xcb\x43\x7a\xa5\xa2\x81\x09\xbc\x3f\xc3\x4a\xb1\x6a\x6b\x4b\x7c\xcc\xcf\x6e\x4e\x8a\x98\xee\xb8\x35\xa6\x8a\x98\x12\x9e\xca\x59\xc5\x35\xe4\xcb\x53\xb2\x6e\x47\xb0\xd5\x00\x82\x15\x17\x3f\x46\x7a\x41\xd5\x69\x0c\x04\x16\x98\x65\xba\x58\x47\xce\x61\x57\xf3\x11\x22\x9b\x95\xe6\x04\x63\xaf\x0b\x2c\x28\xd2\x9e\xc8\x40\x94\x40\x3f\x42\x78\x46\x41\xe0\xbb\xef\x25\x65\xa0\x80\x55\xc8\xe7\x26\x7e\x07\x3c\x05\xfd\xec\x56\x00\xaa\xbc\xf3\xed\x98\x67\xe6\x11\xd2\x31\x3f\x72\x75\x63\x07\x2b\x20\x0c\x8f\x82\x65\x21\x15\x50\x22\x72\xeb\xbe\x33\xf0\x05\x2b\x20\xf8\xd6\x73\x57\x59\x38\x89\x80\xa3\x91\xfc\x9f\xcb\x47\x40\x10\x1e\xf0\x3d\x63\xcd\xb7\x3c\x32\x24\xb2\x10\xa6\x7b\xb2\xf8\xd4\xfc\xa2\x35\xfd\x29\xac\x02\xb7\x31\xa9\xb6\x1e\xa7\xab\xcf\x05\x58\x63\x5b\xa1\x30\x53\x7c\xf9\x5a\x33\x50\x4b\x31\x64\xb1\x3f\xaf\x5a\x2b\xe5\x61\x4b\xa7\x95\x74\x70\x93\xde\x48\xc8\x6c\x73\x47\x11\x8d\xc0\x2d\xb1\xc0\x33\x81\x24\xe4\x86\x0e\x15\x93\x6f\x0d\x77\xf6\x97\xe8\xfa\x64\xdd\x1c\x8c\xe8\xa8\x45\xe3\xab\x7b\x71\xbc\x95\xb8\x81\xd3\x83\x0c\xa7\x68\xa8\x07\x09\x79\xaf\x13\x67\x1f\x3a\x32\xed\xe1\x20\x85\x60\x3c\xe3\x3b\x7f\x24\x7c\x5c\x9a\xbf\x0f\x8a\xef\x5d\xc7\x0c\xa7\x3c\x57\x13\xed\x58\xe3\x83\x65\x34\x32\x5e\xea\x21\x17\x06\x36\x4e\x9e\x5a\xe2\x66\x47\xb3\xee\x62\xce\xbc\xd2\xfa\x23\xdc\x24\xb1\x82\xcd\x5c\x8a\xba\x68\xe8\x95\x99\xd5\x71\xe7\x51\x06\x79\x5d\xc1\xc9\xf1\xf0\x83\x02\xda\x66\xb4\x74\x4b\x14\x3c\x66\x98\x91\x3e\x2e\x6d\x54\x78\x02\x40\x56\xe0\x64\x6b\x4d\x2d\xaf\xcd\x3d\x7d\x19\x12\x4f\xf5\x57\xd3\xb2\x40\x4c\x47\xb4\x16\x0d\x5f\x66\x61\x17\xb9\xfb\xea\x34\x2f\x6a\x80\xfa\xd0\x2c\xf5\x32\xf5\xd3\x6a\x50\x8f\x54\xa0\x72\xbe\x56\x1d\xbd\x88\x26\x18\xb8\xa1\xdb\xa4\x06\x0f\xed\xc0\x9f\x46\x49\x3b\xcd\xc4\xa1\x99\x68\x16\xc7\xfa\x93\xb7\x54\x49\x34\x17\xdc\xcb\xea\x45\x0b\xbe\xf4\x41\xc3\x6e\xd7\xd9\x7a\x64\x67\xc0\x8c\xb9\x80\xff\x2b\xbc\x76\x56\x3e\x99\x20\x3f\xf8\x95\x85\x4a\xa5\x83\x04\xad\xf1\x5f\xef\xc5\x43\xda\x6f\x79\xe8\xfe\x77\x50\x97\x52\x9b\x94\x17\xe8\x8b\x7f\x85\x51\x4c\xe3\xd8\x31\x34\x13\xdf\x3c\x20\x43\x5d\x85\x08\x85\xb9\xac\x3c\x74\x81\x29\x86\x5d\xb9\xbb\x2d\xf1\x18\xc0\x5e\x18\x40\xff\x9a\x95\x60\xf3\x1c\x63\x9a\xf7\x37\xe6\x22\x26\xa7\xdf\xba\x73\x3c\xc1\xcb\xbc\x78\x0a\x8e\x29\xbb\xe5\x62\x26\x0a\x18\x98\x1c\x50\xc2\x6a\x15\x78\xf2\x4d\x9b\xf5\x53\x5d\x9c\xe5\xb5\xf9\x51\xdf\xf3\xf6\x7a\x64\xff\xf9\x87\xac\xc5\x85\xe1\x66\xf3\x5c\x8a\xdd\x4b\x60\x32\x93\x76\x45\xc4\x8f\x9c\x3c\x2a\xcb\xac\x1b\xde\xca\x86\x30\xb3\xcd\xb4\x44\xd2\x00\xf1\x18\xe4\xab\xb4\x22\x2a\x2d\xe6\xa2\xfa\x02\x9b\x53\xf4\xaa\xbe\x30\x83\x12\x7a\x20\xf0\xec\x61\xc3\x24\xf6\xda\xe9\xc9\x7f\x92\xc1\xf5\xec\x76\x6c\x6a\x77\xb0\x1f\xb6\x42\x7b\xfe\xcb\xd8\xee\xe2\x4f\x90\xc7\xdc\xd7\xcd\x00\x9a\x81\xc8\x45\x5c\x1e\x5d\x51\xc9\x65\x5b\x30\xe7\x1d\x85\xc1\xff\x13\x25\x40\xc7\x9e\x04\xb5\xea\x20\xa0\xa4\x1b\xc5\xe7\xe9\xb8\xfe\x05\x27\x04\x74\x32\xd0\x56\xde\xef\x33\xb3\x39\xd1\xdf\x04\x9a\x71\xf7\x42\xf1\xda\x96\x50\x4d\x2e\x62\x14\x71\x8a\x26\x6a\x18\x8e\x5b\xbd\xfd\xdc\x3d\x36\x71\x03\x80\xc2\xe2\xa6\xb7\xb9\xf8\x1c\x68\x8d\xfa\x20\x52\xd1\x49\x0d\x3d\x8f\x2b\xcc\xff\xdc\xad\x2e\xd7\x49\xdd\x65\xcd\x46\x14\xb7\xb1\x3b\xd8\x54\xe7\x43\x86\x82\xe9\xb8\x5a\xeb\x80\x6e\x12\x1b\x92\x69\x8b\x30\xfe\x47\x9f\xa3\x76\x8e\x80\x59\x82\x8e\xb7\x9b\x17\x73\x98\xbb\x04\x2e\x3e\x04\x8a\x98\x4f\x57\x6c\xa6\x95\xa7\x2f\xfd\x1f\x2b\x65\x55\xd9\x23\xef\xe8\xe5\x84\xef\xb7\x3b\xb8\x71\x9d\xa2\x97\xc3\x9e\x71\xeb\x20\x95\xb1\x09\x7f\x48\x91\x88\xce\x9c\x63\x93\x56\xfa\x74\x99\xb3\xb0\x78\xb2\x71\xbd\xc1\x8b\x08\x90\x57\x5d\xef\x02\x8c\x4d\x8d\xc3\xcf\xc2\x5e\xb8\x24\x8b\xe7\x0c\x35\x17\x85\xc9\x26\x5f\x37\xcd\xb2\xdf\xcc\xd6\x36\xb9\x61\x19\x7b\xd2\x53\xa8\x77\x13\x59\xa8\xa6\x9b\x7a\xb6\x9e\x19\x9d\xf8\x39\xc6\x02\x6a\x88\x9f\xd7\x15\xd4\x3d\xc0\x3f\xe9\xc8\xed\x89\xa6\xc9\xbe\x83\x9c\x5b\x2f\xfa\xd1\x69\x72\x8e\x2f\xfe\xed\x6f\x15\x8a\xd9\x3a\x01\x54\x7c\x21\x2c\x09\x52\xe2\x9a\xed\xde\x22\x35\xd7\x37\xdf\x0f\xd2\xb8\x68\x50\xbc\xe6\xe7\x63\x3e\x56\x94\xcb\xf3\xcd\xc9\x39\xca\xdb\x77\x3d\xc2\x07\x8b\x82\x43\x01\xcc\x65\x00\xde\xc7\xdd\xd7\xe4\x79\x7b\x85\x03\x56\xee\x12\xde\x24\xc8\xf2\x94\x77\x59\x3f\x65\xa4\x5a\xbf\xc2\xec\x39\x5f\xd5\x38\x22\xe3\x21\x48\x10\xc4\x0a\xa2\x33\x22\x70\x8b\x3a\x56\x7b\x1f\x13\xb1\xce\x4c\xab\x47\x0f\xa2\x38\x5a\x16\x3c\xe5\x68\x59\x2c\x8a\xcb\x29\x94\xcc\xea\x49\xfa\x93\x2d\x4a\xe2\x7d\x7d\xdf\xf1\xe3\x12\xa4\x03\xa6\x8e\x9b\xdc\x33\xe4\x6e\x54\x31\x14\x2c\x80\x49\x03\x03\x96\x8a\xec\x02\x2b\x09\x29\xe1\x75\xbf\xc0\x72\x1e\xda\x16\x18\xed\x25\xce\xa5\xdb\xc3\xa3\x22\x40\xa7\xaa\xc8\xce\x36\xf9\xf3\x49\x17\xd7\x34\xab\xe8\x5f\xd5\x97\x64\xa1\x45\x7b\xcc\x18\x28\xab\x7a\x97\xdc\xb7\x7e\xb5\x24\x84\xc3\x3d\x24\x04\x5c\xf8\x82\x9b\x41\x19\xad\xd3\xc3\x05\x3d\x68\xbb\xec\xb2\xb2\xf9\x6e\xc9\xcd\x0d\x76\x0c\xe0\x55\x6b\x20\x5b\x1c\x92\x76\x28\xd5\x85\x27\x34\xfe\xfe\xe5\x9c\xa5\x70\x79\xea\x0a\x95\xe4\xcc\x54\x2c\xf9\x71\x51\x50\xa0\x02\xfa\xc3\x82\x56\x39\xe4\x20\x17\x9c\xfc\x2c\xd4\x3d\x9c\xa7\x71\xcc\xea\x39\xd5\xf5\x14\x0e\xcf\x0e\x96\x9b\x5c\xd6\xea\xbb\x81\xe7\xe3\x7d\xdb\xd3\xda\xaa\xc1\x0c\x7b\x12\x83\x0c\xb5\xc8\xa7\x50\x2b\xa4\x56\x1c\x4a\x1f\xd9\x9a\x65\x9a\x5f\x90\x22\x34\x03\xd6\xcc\x4e\x69\xb2\x1f\xfa\xfb\xaa\x8a\xf1\xa7\x9d\x9a\x06\x04\xa8\x0f\xa9\xe2\x8d\xde\x7b\x9a\x1f\x0c\x9b\x1f\x4e\x38\xc8\x7e\xd4\x03\x78\x4e\x7b\x6e\x09\xb4\xf1\xf2\xb6\x69\xbe\xa2\x8a\x00\x7d\xce\xaa\x64\x6a\x47\x7d\xcb\xb6\xb0\x35\x41\x22\x27\xa8\x46\xd6\xd1\x64\xbc\xe6\xfd\x3f\xc2\x97\x9a\xcc\x9d\x1f\x0f\x1b\x96\xfd\x86\xb5\xb8\x62\x6e\xa3\x58\x4d\x48\xe0\xb0\xc4\x61\x35\xdf\x90\xd7\x6f\xf6\x2d\x71\xfb\x4a\x72\xc2\x59\x9e\x70\x0e\x86\xff\xc7\x43\x11\x34\x5b\x39\x13\x54\xff\x34\x40\x93\xed\x8e\x66\xb5\x04\x6b\xed\x8d\x33\x7b\x15\xdd\x37\xd1\x47\x66\xaf\x05\x2f\x2c\x0e\xeb\x5b\xba\x2c\xf2\x3a\x44\x30\xc1\x4d\x5c\xbe\x30\x01\x92\x57\xb2\xbd\x78\x21\x2d\x8a\x54\x49\xbd\x0d\x3a\xb9\x2e\x0c\xbe\xea\xd5\xb4\xb2\xe3\xeb\x2e\xd9\xbb\x2c\x7f\x9b\xce\xb2\xaf\x5d\x4f\x16\x2d\x3b\x76\x13\x26\x3b\x29\x43\x2e\x86\xbf\xdf\x14\x6f\xc4\x58\x7c\xa6\xe1\x21\xf0\x56\x2f\x22\xc5\x52\x34\x74\x6a\x59\x51\x98\xc0\x70\x8f\x56\x2e\x89\xa1\x61\x3f\x12\x6f\x2f\x92\x62\x1c\x62\x9a\x1c\xf5\x71\xd2\xe4\x87\x0e\xe5\x9b\x22\xe3\xca\x9c\xe4\x10\x6b\x8e\x1f\x0a\xd4\xc5\xa2\x58\xe8\x37\xbb\xbf\x1c\x05\x6d\x48\x5a\x7e\x67\x9f\x8e\x10\x85\x84\xc4\xf2\xfb\x19\xbc\x33\x0d\xfb\xf2\x44\xd0\x6c\x00\xb0\x72\x56\xec\xab\xf2\x06\xa0\x19\x3a\xbb\xea\xdb\x8d\xd1\x02\xd4\xa8\xbe\xbc\xef\x33\x9a\x1a\xc8\xc2\x85\x59\x2c\xa7\x6c\x14\xe2\xcb\x95\x77\x13\x19\x07\xa0\x23\xcc\xda\x28\x52\xcf\xc4\x22\x08\xb4\x2c\x12\x26\xdc\x85\xb3\x75\x55\xbf\x73\xef\x17\x37\xa6\xc6\x3b\x6e\x91\xf0\x75\xcf\x03\x69\x01\x01\x62\xaa\x4c\xa8\x90\x0f\xfc\x41\x0f\x05\xe6\x7f\xb1\xbf\x59\xde\x80\xf7\x9c\xb5\x65\x9e\x1f\x28\xc9\x0c\x7d\x36\x88\xf9\xe2\x4f\x4d\x6b\x0b\x12\x6d\xf8\xf0\xdb\xd4\xee\xf4\x4b\xe1\x63\x10\x7c\x40\x8c\xcf\x58\x73\x84\x47\x33\x58\xd7\x48\xc0\x5c\x0b\xbb\x39\x27\x7d\x38\x94\x4b\x64\x6a\x62\xaa\x32\x09\x5e\x0a\xcf\x62\x0c\x15\x5b\x5d\xac\xb9\x64\xd3\xaf\x75\x96\x73\x03\x5d\x97\xbc\x24\xae\x91\xdd\xbb\x8e\xf2\x54\x51\xef\xa9\x1e\x9c\x96\x93\x24\xe9\xdd\x3f\xe3\x06\x26\x4c\x4e\xb1\xbd\x07\x6c\xe1\x47\x2d\x5f\x8e\x00\x7c\x5d\x42\x09\x28\xf8\x6a\x2f\x4c\x89\x7c\x10\xe8\xce\x3d\xbd\xb6\xae\x6b\x99\xa8\x69\xaf\x43\xe4\x99\x07\x80\x6f\x0c\x5e\xfb\x75\x24\x03\xd6\x28\xf1\x9c\xc9\x3a\x88\x5b\xc2\x17\xc9\xef\x9e\x94\x62\x88\xb6\x2b\x0c\xb2\x58\x01\x8f\xa3\x8b\x88\x1d\x47\xd0\xe7\x58\xde\x3b\x0f\x47\x0e\xb3\xc3\x95\xad\x87\x88\xfd\xb8\x97\xbe\xb6\x37\x92\x0f\x50\xba\x42\xc8\xa4\xfc\x41\x6a\xf4\x67\xdb\x76\x77\xc6\x46\xae\x47\x66\xf4\x07\x35\x4d\x0b\x77\xf0\x1b\x43\xda\x71\xc9\xc0\xcd\x92\xa6\xd3\xaf\xc1\xe3\x89\x5c\x85\xff\xa2\x00\xcd\x93\xd2\xc6\xd2\xd6\x8e\xdf\x29\x3d\x4d\xd8\x6d\x7a\x50\xdd\x18\x56\x5d\x82\x01\xb2\xaa\xcd\xa7\x70\x7f\x2f\x8d\x04\x42\xeb\x3e\x19\x80\x1c\x4e\x55\x6a\xeb\x34\x26\x7d\x5f\xca\x46\x0b\x33\x69\x4b\xd4\x05\x92\xbc\x78\xf4\xfd\x10\xe1\xdf\xea\xc6\x35\xa2\xfa\x73\xb0\xc0\xcc\x27\xe4\x1d\x39\x7e\xa0\xed\xe2\x2b\x30\x54\xee\x34\xde\xbe\x27\xc4\x01\x1a\x41\x90\x5e\xd1\x13\x74\x40\x71\x95\x71\x00\xb8\x99\x13\x43\x63\x25\xd9\xb8\x62\x02\xaa\xb2\xe1\x0d\xf2\x99\xc5\xc4\x9c\xb8\x9f\xae\x4d\xc8\xa4\x7e\x80\xa4\x09\x32\x1e\x4a\x56\x0e\x9c\x0d\x7c\x38\x6d\x73\x9f\xdf\x1c\x07\x22\xa9\xe7\x97\x53\xe5\x05\xa5\xe9\x7a\x96\x3b\xfa\xbd\x82\xf0\xa0\xa1\xdc\x45\x55\xd4\xe9\x4b\x12\x96\x49\x65\xcf\x86\x3a\x99\x71\x89\x4a\x3f\xff\x6c\x20\x23\x89\x19\x9c\xcb\x87\x70\x45\x96\x80\xb5\x52\xdf\xe5\x4e\xd1\x05\x8c\x76\xf9\xfd\xdc\x20\xde\xb8\x60\x3e\x87\x68\xdc\x71\x86\x20\x22\xf2\x28\x10\xa4\xea\x97\xd4\x8c\x2f\x88\x1c\x1a\x1d\x36\x55\x65\xac\x6f\x98\x25\x7b\x5f\xf5\xfb\x80\x4b\x8c\xe8\x06\x30\x9d\xaf\xc7\x52\x53\x78\xc0\x4a\x99\xab\x7a\x00\xd9\x46\x51\x56\x98\xce\xc9\x7d\x16\x97\x57\x77\x43\x73\x6c\xcd\x44\x44\x1d\xbf\x82\x80\xe6\xca\x57\x88\x94\x57\x56\xdd\xaf\x1b\x2b\x05\x41\xbe\xa2\xde\x67\xc2\x38\x42\xb4\xe7\x31\xea\x57\x52\xfc\x4c\xb1\xc5\x68\x83\xf3\xd5\x49\x49\x39\xf3\x99\xda\xf8\x8b\x53\x89\x31\xa5\xe2\x54\x7a\xb1\x86\x37\x9f\x5d\xb6\x4d\xd9\xa1\x39\xec\x2e\x5e\x18\x5a\xec\x3c\xe7\xa2\xee\x45\xd5\x7c\xfd\x7e\x43\xda\xff\x36\xca\xe7\x99\xf3\x4f\xb8\xb0\x93\x6b\xdd\x27\xfb\x0f\x20\xe1\x62\x20\xc1\x99\xad\xd2\x9a\xb1\x50\x15\xbd\xf4\x7b\xeb\x89\xa0\x99\x8a\xad\xea\x90\xb1\xd9\x21\xbe\x0c\x73\x62\xa5\xa2\x92\x8a\x66\x74\x56\x3d\x94\x79\x2f\xd8\x07\x99\x40\xb6\xf5\x4c\x02\xb5\x8f\x38\xae\x47\x85\x65\x9d\x07\xd3\xde\x4e\x4d\x5b\x41\x19\x05\x4a\x80\xbe\x15\xf3\xe1\x21\xf4\x34\xcb\x77\x2c\x17\x3d\x94\x51\x5b\xca\x41\x25\xaf\x30\xf0\x71\x4d\x84\x7a\x87\xdb\x9f\x2d\x97\x0c\xd8\x71\x6e\xbe\x26\x5c\x6b\x21", 3761);
*(uint64_t*)0x200010c8 = 0xec4;
*(uint64_t*)0x20001118 = 1;
*(uint64_t*)0x20001120 = 0;
*(uint64_t*)0x20001128 = 0;
*(uint32_t*)0x20001130 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001100ul, 0ul);
	return 0;
}