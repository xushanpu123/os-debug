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
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001340 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x27;
*(uint32_t*)0x200000c4 = 1;
*(uint32_t*)0x200000c8 = 0;
*(uint32_t*)0x200000cc = 0;
*(uint32_t*)0x20001348 = 0x80;
*(uint64_t*)0x20001350 = 0x20000140;
*(uint64_t*)0x20000140 = 0x20000080;
memcpy((void*)0x20000080, "\x4d\x07\xa3\x2b\x1d\x6f\x8c\x1f\xc8\xcf\x70\x0f\x06\xd7", 14);
*(uint64_t*)0x20000148 = 0xe;
*(uint64_t*)0x20000150 = 0x20000280;
memcpy((void*)0x20000280, "\xa4\xc8\xef\x88\x06\x7a\x6f\x84\x29\x7a\x03\x8a\x3e\x02\x2d\x29\x68\x02\xe6\xce\x33\xa0\x07\x1d\x2d\x7d\x1a\xac\x13\xdd\xb0\x72\x02\x02\x9d\x2d\x24\x5d\xc0\x18\x19\x11\xf8\x2a\xa2\xf3\x16\x3c\x06\x3e\x3b\x8f\x57\xf1\xb7\xc5\xf8\x01\xd5\x69\x44\xee\x8a\xb6\x31\x44\x44\x0e\x1e\xc2\xf7\x64\x8b\x8a\xae\xa4\x44\x33\x26\x8e\xda\x6d\x4e\x78\x48\x21\x23\x61\x9d\xb7\x04\x31\x44\x10\xb8\xce\x02\xa0\x25\xdf\xa6\x4e\x1f\x32\xb2\x3d\x5c\x4d\xb4\x6e\xd6\xbd\xd4\xea\x93\x12\xb9\xf8\x15\xf7\x92\x0a\x16\x95\xee\x7f\xa4\xa1\x51\x9a\x82\xc8\x9a\xde\x37\x8a\xe3\x4c\x57\x10\xbd\x98\x0b\x81\x1c\xbc\xb0\xd3\xfe\x84\xbf\x8b\xc9\xb5\xcf\xa8\xe0\x8d\x26\x1e\xef\x81\xb5\xed\x54\x3a\x5a\xa3\x39\xe6\x6d\xb3\x9f\x84\x27\xc1\x8e\xce\xd2\x81\x29\xb0\x77\xfa\x9d\x13\x52\xe9\xdf\xa3\x4a\xca\xe3\x46\x05\xcb\x36\x64\xb1\x2d\x91\xee\x87\xe6\xd0\xbd\x99\xc7\xe8\x1d\xf2\xbc\x4e\xbe\xf8\x35\x89\x99\x54\xa8\xe3\xd8\x1f\x97\xbf\xfe\xc3\xba\x98\x18\xe2\xd1\xbb\x15\xd2\x7c\xce\xf7\x1d\xc0\x6a\x7e\x6c\x69\x49\x9d\xd1\x71\xfb\x29\x7e\x78\x62\x1b\x47\x7d\xd5\xd6\x92\x86\xc0\x0c\x19\x63\xc9\x5a\x0e\x0e\x80\x18\x9d\x44\xf4\x85\x52\xc3\x1a\xf1\x9a\x89\x06\xd9\x38\x7e\x15\x5a\x91\xb5\x1b\x14\x3d\x55\x9a\x5f\x3d\xe1\xc3\xb3\x13\x12\x1f\xf5\xd1\xe2\xfd\x31\x06\x9c\xff\x37\xc3\x19\x3e\xaa\xed\x81\x2b\xb2\x8a\xa5\xc0\x80\xbb\x86\xbb\xce\x9a\xc2\xc7\x83\xa2\x08\x75\x51\x1c\xe6\x50\xba\xbf\xa5\xb0\x2a\x0e\x0e\x71\x0b\x10\x14\xf5\xd5\xcd\xd0\x5c\x45\x85\x84\x66\x47\x3c\x0b\x39\x37\x8b\xb5\xc2\xfd\xeb\x0a\x12\x30\x6c\x66\x09\x3a\xf9\xdc\xa5\x8d\xe6\x5b\xf4\x25\xaf\x06\xfd\x0f\x1b\x7e\x95\x6f\x66\x05\x84\xb4\xf6\xb7\xb0\x60\x32\x6c\x8a\x83\xf8\x04\x26\x64\xd7\x20\x08\xdd\xcd\x4e\x41\x50\x6c\xb8\x7a\xf4\xf8\x2c\x81\xe1\xac\x35\x5b\xba\x3c\x01\x84\xfe\x6b\x80\x48\x72\x5b\x41\x27\x4e\xec\xaa\xcf\x7f\x65\x81\x98\x07\x57\x5c\x88\x5c\xca\x66\x54\xcd\x03\xf6\x12\x84\x77\xed\x50\xc2\x6f\xfb\xc1\x9f\xbd\x03\xa0\x73\x76\x31\xbf\xa2\x72\x25\x46\xf6\x04\xae\x2e\x85\x19\x51\x42\xf3\xeb\xc2\x70\x32\xc0\x57\xda\xe9\xa3\x47\x4b\xfa\xa7\xd3\x66\x69\xac\x04\x40\x5b\xe2\x58\x02\x8f\x9e\xea\x4f\x66\xd4\x20\x4f\x45\x40\xfd\xe7\x6f\x88\xf7\xd2\x07\x48\x89\x90\x71\xbe\x29\x27\xc5\x13\x37\xbd\x6c\x04\xb9\x98\x77\x1e\xe9\x0d\x11\x31\x71\xe8\x72\x0c\xba\x4a\xf4\x45\xb3\xbe\xb4\x5f\xe3\x37\x49\x18\x70\xf7\xb6\x24\x6f\xba\x72\xc7\x6e\x1c\xef\x87\x5a\xb4\x17\xac\x68\xb0\xd3\x4d\xf5\x30\x9a\x07\x87\x21\xeb\x1e\x07\x74\x53\x27\x56\xdb\xb9\x71\xe8\xff\x6e\x34\x75\x49\x17\x44\xc0\xae\x40\x43\xc6\x20\x20\xae\x37\x88\x75\x96\x4f\x16\x23\xfe\x36\xd3\x43\x14\xb9\x24\x6d\x64\x69\x88\x53\xe4\x9f\x92\x72\x6f\xed\x0d\xaf\x5d\x90\xc3\xca\x53\x12\xee\x9e\xb8\x89\x4e\x0b\x62\xb5\x44\x38\x9e\x73\x70\x4c\x35\x5e\x07\x5a\x1e\x3b\xa5\x3a\x16\x64\xb0\xce\x92\x17\xc6\x1e\xc8\x62\xaa\xb6\x81\x11\x81\x67\xde\x47\x25\xc8\x6c\x40\x4d\xa5\x43\x4a\xed\x5f\xec\x81\x11\x3d\xcd\x6e\x20\x6e\x52\x02\x8f\x46\x81\x9f\xe7\x2c\xcc\x19\xf0\x6f\xc4\x2b\x47\x1c\x6f\x83\x5e\x6a\xc4\x95\x00\x29\x19\x65\x6c\xf4\x64\xc0\x95\x43\x68\x58\xe2\xd8\xfe\x59\x7e\x17\xb2\x30\xbe\x52\x77\x20\x6b\xdf\x59\x18\xd6\x02\x7f\xb5\x78\x40\xda\xa1\xe4\x01\x08\x92\xc9\x00\xe8\xfb\x0e\xc0\x0c\xe5\xeb\xad\x0e\x81\xdd\x29\x51\x2c\xb9\x22\xe7\xfd\xd0\xc7\x3f\xdd\x11\x39\x59\x68\x9a\x1d\xd1\x2c\xd0\x95\x3d\xf5\x8d\xd8\xf2\xa5\x25\x45\x53\xd5\x77\x32\x3f\x06\x07\x00\xce\x7f\x2f\xe0\xa7\x95\x54\x9e\x9d\x28\x8c\xdd\x4b\x1e\xe1\xfa\x03\xb0\x89\xd9\x87\xdf\x85\x8d\xee\x95\x65\x39\xb0\xf2\xd8\x21\x80\xf5\x06\x81\x45\x49\x1e\xaf\x12\x69\xa2\x69\x68\xf4\xde\x07\xd9\xe7\x63\xf5\x1d\x3b\x42\x0e\x7c\xb5\x8e\xe7\x5b\x39\x45\x01\x04\x5e\xb7\xba\xa9\xb4\x11\xc1\xf3\xac\xa9\xa7\xd8\x1a\x4a\x11\x98\xae\x19\x62\x4f\x28\x1d\x9b\x66\x03\x95\x64\x55\x6d\x1e\x13\x4c\x5c\xc8\x86\xe3\x91\xbd\xdc\x1f\xe3\x3b\xd9\xb0\x22\x36\x00\xbf\x59\x42\x0a\x0f\xfc\xe2\xa9\x62\x93\x8c\xc1\x20\x67\x1f\x70\x74\x42\x41\xd4\x2c\x3a\x6e\xbb\xcb\x77\xe7\x4f\x38\x3b\x8d\xab\x4d\xd3\x88\x89\xb0\x7c\x81\x78\x15\xae\x7e\xfc\x48\xdf\x9e\x8c\xd4\x5c\x3c\x89\x23\x27\x2d\xcd\x87\xc1\x3f\x9f\x75\xc2\x3a\x63\x9b\x04\xf3\xc4\x70\x49\x4a\xf7\xe0\xc9\xc6\x9f\x61\xee\x43\x8e\x47\x8e\xbc\xba\xf8\x06\x37\x4b\x65\xf4\x80\x2b\x0b\xf2\x15\x63\x0c\xda\xf9\x82\x37\xdb\x70\xb4\x41\x5f\x9f\x50\x81\x51\x05\x25\x41\x0f\x4a\xfa\x6b\xdc\x64\x50\x2f\xa7\x89\x34\x86\xd9\x89\x84\x89\x3c\xcb\xd4\xbd\x52\x61\x89\x27\xaa\x2b\x09\x18\x92\xcb\x8e\x98\xdd\x69\x04\x0a\xb2\x47\x98\x6b\x9a\xcb\x7b\xe0\x6e\x8b\x20\x51\x10\x73\x1b\xa2\x18\xc8\x14\xf6\x77\x12\x2f\x25\x96\x19\x89\xce\x69\x1a\x35\xde\xc8\x3b\x67\xe5\xf0\x25\x04\x24\x00\x58\xad\x41\xcf\x3b\x46\x7f\x2d\xb9\xa6\xa6\xe4\x70\xeb\xf3\xf8\x65\x9d\x30\x01\xad\x76\x2c\xdb\xa8\x47\xc7\x15\x2d\xac\xd1\x69\x4a\x76\x72\xec\xd0\xc3\x74\xf3\xa9\x57\x75\xb2\x60\x08\x8a\x0f\x63\x63\x81\x90\x65\x3d\xd2\x0a\x9b\xe4\x09\x82\xf2\x1c\xbe\x0a\x84\xcb\x7b\xfc\x30\x15\x7b\x14\x2b\xc4\x63\x41\xce\x59\xe1\x25\x75\x5e\x56\x9a\x13\xb4\xf3\x0f\x6a\x17\x1f\xab\xab\xd1\x81\xcf\xa7\x62\x37\x94\x63\xf0\x0c\xb4\xaf\x05\x0a\xe1\x9a\xe6\x85\x0b\x7e\xa2\x65\x72\x41\xec\xf3\x39\xd0\x65\x18\xa8\x21\xee\xea\x55\x8f\xfb\x1d\x97\x26\x8f\x9c\x11\xc5\xe5\x56\xd6\xcc\xa1\x55\xba\xfb\xd9\xd6\x0b\x50\x28\x23\x77\xa3\x68\x32\x85\x03\xdd\x04\x12\xbd\xd5\xa6\x0e\xac\x85\x1d\xa3\xbd\xb8\x5d\xe7\x5c\x5f\x73\x31\xba\x82\xa4\x5a\x80\x3d\xcd\x24\x3a\x5c\x36\x53\x9d\x6d\xbe\xa2\xbf\x58\x27\xd1\x56\xcb\x9a\x52\x08\x30\x6a\x1f\x17\x4e\x60\xcd\xf6\xf8\x07\xe7\xa6\x90\x6a\xbe\x7b\x7b\xef\x94\x9f\x8f\xca\xae\xd5\x33\xe6\x7b\xb5\x67\x5e\x88\xc9\xfa\xc8\x29\xec\x43\x9c\x4c\x4e\xe4\x38\x28\x12\xf2\xd0\x1b\x59\xa3\xb5\xda\x79\x1b\xc2\xef\x96\x01\x85\xdc\x2a\x26\x1a\xc9\x75\x4a\xe9\xc3\x1a\x76\x30\xde\x23\x3f\xab\x12\x96\x7b\x24\x91\x67\x12\x0f\x41\x02\x41\x17\xc3\x8d\xa2\x93\xbe\xd9\xa0\x1c\x52\x20\xfc\x1c\x3e\x47\x6c\xb2\xd8\x69\x19\xf6\xa2\xcd\x78\x59\xc8\x92\x46\x80\x01\x90\xab\x27\x6c\x0a\x67\x14\x0a\x6a\xed\x1d\x57\x97\x8a\x79\x6f\xbc\xa3\x0f\x96\x2b\x04\xc1\x81\x7e\x76\x5e\x99\xc3\x3e\x2e\x05\xaa\x37\x4e\xc0\x2c\x4f\x45\xb9\x90\x30\xef\x36\x1d\xe7\xcc\xae\x93\x07\x0a\xc7\xd1\xab\xc0\xee\x4f\x0c\xa5\x1e\x75\xa3\xb1\xb3\x89\x72\x00\xd0\x1c\x17\x51\x7f\xd5\x90\x15\x10\xd5\x36\x69\xad\x0c\x76\x5b\x09\x68\xdb\x58\xe5\x1e\x0a\x21\x59\xed\xe4\xc8\x92\xaf\x7d\xc4\x8c\xba\xba\x33\x19\x16\x60\x25\x06\x21\x06\xfc\xbf\x47\x24\x44\x23\x83\x31\x18\xe7\xe2\xd8\xbf\x8c\x5e\x88\x2f\x45\x36\x94\x9b\x00\xdd\x08\x55\x2c\xe3\x30\xba\x4e\x9d\x50\x0b\xb4\x50\xe5\x4d\x5c\x2f\x93\xb4\x64\x5a\x79\xf2\xc7\x20\x90\xf2\xa9\xbf\x8d\x10\x9a\x30\x91\xfc\xfb\xac\x17\xda\xb4\xb6\x5c\x44\xb5\x34\x00\x7e\x0d\x3d\x1d\xc2\xa2\x36\xae\x6e\x95\xd4\x2e\xef\x49\x55\xf7\x35\xb1\xb0\x5a\xbf\x32\xab\x4a\xcd\x41\xcf\x9b\x02\x55\x2b\xfa\x6c\xc7\x14\xd8\x11\xcf\xd7\x96\x02\x7f\x1a\xa4\xf1\x72\xf7\xa0\x50\xba\x62\xac\x7c\x77\xe7\x54\xcd\x85\x1a\x8e\xbd\x3a\x4a\x1a\xd4\xe2\x51\x26\x80\xfc\xc2\xe4\x52\x63\xea\x8b\x96\xe8\xb9\x28\xda\x3d\xf8\xbb\x29\x69\xbd\x70\x91\x21\xdd\x88\xbe\x92\x31\xb6\x41\x40\xf6\xd8\xd1\x2e\x3f\x48\xb5\x58\xbf\x7d\x7b\x9f\x73\xe0\xa4\x67\x44\x6d\xd4\xfc\xc8\xfd\xa3\x17\x40\x69\x23\x9e\xf0\x9e\x30\xb3\x5d\x5d\x50\xf3\x30\xbc\x0c\x98\x7d\xe5\xfc\xfa\x5a\x64\x70\x55\x3e\x44\x98\x90\xb2\xc3\x00\x4f\x75\xea\x55\x11\xbc\x14\x81\x64\x33\x9e\xa7\xb6\xbc\xa7\x9a\xb1\xf4\xdf\xb8\x5c\xc9\xca\x80\xe0\xd4\xe3\xd8\x88\xfb\x99\x1e\x4d\x1e\x50\x25\x97\xec\x91\xa3\x3a\xea\x11\x54\x47\xcd\x09\x70\x8f\x1e\x41\xb2\xa8\x91\xc9\xf4\xec\x85\xba\xc6\x7b\xd8\xef\x8d\x6f\x91\x68\x6a\xca\x2b\xbc\xa0\x1a\xa2\x42\x7a\x96\x19\xd7\x69\x8a\xb4\xb5\xf8\x2d\xa3\x3a\x3a\xdd\x57\x4d\x2b\xdb\xf3\xf6\x8b\xb7\xad\x77\x67\xbf\x4b\x15\x47\x0b\x74\x07\x9c\x4d\x23\xcf\x8e\x7d\x1d\xe8\xe1\x48\x92\x38\x13\x3b\xe3\xe3\x2b\x6e\x28\x53\x51\x2c\x4e\x32\x15\x4b\xa9\xc8\x28\xf0\x33\x55\xb4\x3f\x6f\x78\x6f\x08\x9e\x05\xee\xa0\xc2\xe9\x9d\x2c\x20\x3c\xaa\x67\x9a\x71\xe9\x0b\xb0\x84\xc4\x09\xc0\x57\x6e\x46\xb2\x6a\x93\x23\x07\x52\x13\x49\x00\x09\x23\x5c\xc9\x15\xc9\xaa\x16\x38\xa2\x36\x64\x21\x6d\x1b\x5e\xb3\xb5\x83\x2c\x55\x74\x28\x22\x31\xe3\x3c\x5c\x8e\x8b\xea\xc4\x93\x63\x37\xad\xf3\xa5\xd8\x42\x7b\xb4\xfb\x54\x5a\x12\x2a\xa3\xa8\x41\x95\x15\xa4\xbf\xc7\xa7\xef\x80\x6b\x78\xec\x8f\x0a\x2a\x4f\xaa\x25\xe0\x08\x61\xbe\x56\xf0\x1b\x2a\x93\x4c\x0f\x2c\x94\x9a\x23\x43\x66\x0c\x3c\xda\x6e\x34\xe6\x65\x09\x0b\x8c\x93\x95\xf6\xec\xe6\xbd\xe3\x80\x8b\xcb\x47\xa8\x11\xa4\xda\xff\x32\x3b\x6e\x4e\x75\xff\xd9\x61\xac\xe5\x95\x65\x56\xfe\x59\x33\xe1\x8b\x4d\x55\xd0\xcf\x3a\x51\xd0\x89\x30\xcb\xe5\x77\xbd\x3f\x8d\x76\xeb\xef\x45\xb0\x9c\x90\xc5\x97\x46\xa9\x15\x88\x7e\x0e\x03\x12\x42\x1c\xf3\x3c\x2c\x8c\xbc\x31\xf3\xc1\x50\x27\x2f\xe7\x3e\xc0\x1e\x63\x05\xa3\xfe\x43\xa2\xb9\xaf\x32\x49\xe5\x15\x50\x78\x9c\x76\x0a\x17\x3c\x10\xa2\x02\xc5\xa7\x20\xb2\xae\x48\xd6\xb0\x84\x1a\xa8\x29\x6d\xd6\x5c\x97\x6d\xfb\xcb\x0e\x47\xe7\xdf\xb0\xb4\x7e\x77\x4c\xdf\x44\xc9\x05\xf9\x89\x82\x98\x70\x29\xc7\x0d\x59\xa9\xba\x3f\x85\x10\x46\xcc\xbf\xd4\xa0\x04\xe1\x8d\x39\x0a\x9b\xa2\x2e\x83\x96\xd0\xf2\x9f\xd7\xaf\x65\x40\x3a\xe2\x07\xc9\xa6\x45\xbf\x57\x5d\x47\x22\x06\xc7\xd8\xdb\xd8\xe5\xd2\xb6\x42\x4a\x4d\xfd\x0a\x7a\x62\x07\x25\x83\xe2\x63\x8e\x87\x2a\xcf\x5b\x85\xc7\xe9\x8e\x32\x1a\xbb\xba\xb1\x53\x4a\x8b\x91\x57\xd9\x2c\xcf\x95\x1a\x38\x36\x66\x5e\x21\x74\x23\x66\x68\xc0\x46\x71\xa9\x99\xe7\x89\xf5\x40\xb5\xeb\xb3\xe4\xd7\xed\xde\x0e\xe5\xb0\xfa\xb8\x2b\x83\xdd\x6b\x41\x4a\x35\x95\x98\x9e\xa4\xd5\x9a\x2d\x6a\x1c\x54\x88\x1d\x9c\xff\x24\x77\x64\x9c\x75\xe8\x5a\x59\x33\xbe\xb0\xb6\x0e\xc2\x56\xa3\x40\xa5\x1a\xb9\x92\x2d\x54\xa1\x71\x74\x4b\xaf\xeb\x46\x6e\xff\xee\xae\x2e\xd9\x24\xfb\xa1\x84\x55\xbc\x72\x73\xe5\x49\xa9\x21\xf1\xcf\x09\x30\xd7\x5b\xd9\x88\xcd\x83\xee\x68\x54\xd9\x07\xbe\x90\xbf\x5a\xd9\xaa\x7e\xf7\xc2\xe0\xdc\x1d\x79\x7a\x2d\xcf\x24\xdf\x18\x86\x91\x38\x2d\xe3\x04\x63\x6f\xc8\xc1\x0d\xf7\xa8\xe0\x4a\x8c\x13\x1a\xee\xed\xbb\x1e\xd8\xf4\xf1\x36\xc3\x39\xf2\x61\xc3\xe2\x52\x34\x76\xa4\xfe\xd4\x56\x70\x18\x1f\x48\xa3\x08\x7f\x5e\x6c\x48\x74\x1f\x9c\x6f\xda\xb3\x7c\xc3\x52\xd6\x5d\x79\xbf\xed\x9e\x19\xeb\xb0\x94\xfb\x6c\x44\xe6\x81\x02\x61\x7a\x99\xde\xdb\x67\xa6\x74\xfd\x88\x0f\xc9\x5f\x24\xb2\x88\x8e\x51\x8f\x70\x83\x06\xea\xf3\x47\x03\x2b\x36\xfe\x05\x74\x60\x98\xa6\xd2\xa3\x52\x3a\x7a\x37\x21\xd3\x07\xf6\x33\x6e\x61\x74\x67\xab\x78\xd0\x46\xdb\xf7\x5b\xba\xe5\xfd\x7b\x62\x89\xb1\x93\x9e\xda\x90\xa5\xac\x11\x8b\x08\x46\x6e\xba\xd3\x90\x72\xb3\xbc\x43\x53\x0a\x09\x5f\x02\xec\x86\x0e\x51\x00\x7c\x01\x0e\xad\x6d\xae\xaf\x33\xe0\x6a\x6d\x67\x78\xd4\xfa\x32\x60\x84\xf2\xfd\x7f\x8b\x36\x11\x41\xd7\x66\xf2\x19\x98\xca\x42\x6c\x84\xd6\x66\xf1\x4c\x23\x67\x15\x6b\xe8\x95\x9a\x25\x0a\x19\xe3\xac\x9b\xc4\xf6\xd5\xcc\x4f\xd0\xbd\x45\x9f\x4a\x03\xb7\x48\xb1\xb0\xea\x57\x96\xb6\x4b\x56\xe6\xfb\x60\x04\xf0\x95\xe0\x67\x66\x1c\x62\x7a\xda\x4e\x11\xbd\x88\x4a\x5b\x07\x03\xea\x4e\x58\xf6\xf4\x1c\x4b\x6c\xee\x79\x06\x31\xd0\xc4\xae\xeb\xe7\x37\x87\x17\xe6\xef\xbc\x1e\x92\xdc\x31\xf9\xb0\xd4\xbd\xdf\xff\x66\xaa\xfa\xab\x4f\xdf\xe1\x7b\x73\xd5\x83\x27\x5b\x28\xfb\x4a\xff\x22\x0c\xd7\x69\xb3\x35\x12\x84\xcf\x94\x3c\x90\x60\x0a\xc4\x47\xcb\x57\x19\x74\x9a\x26\x57\x7a\x5c\xbd\x62\xa6\x4d\x4c\x35\x96\xaa\x4c\xe4\xe0\x5c\x8c\x1a\x9e\x8b\x3b\xe0\xa1\x0f\xc7\x26\xab\xd1\xe5\x79\xe4\x3f\x5a\xb1\xfc\x28\xec\x08\xf0\x01\xb5\x02\x8e\xeb\x0b\xe6\xb3\x83\xeb\xac\x78\xea\x9b\xa9\x4c\xc4\xfc\xcf\x92\xfc\xce\x03\x8c\x17\x1b\xb3\xed\xbc\xbe\x9c\x06\xb0\x97\x60\x9c\x73\x36\x85\xfe\x2c\xe0\x17\x34\xab\x83\x44\x84\xc0\xf0\x48\x81\x50\xc1\x9d\x36\xb8\x72\x13\xa0\x9a\x2d\x10\x27\xda\xc7\x5e\xf3\x23\xb7\xbe\x4b\x5b\xaa\x77\x29\x11\x3a\x05\xed\x4f\xca\x07\x5c\x24\x02\xbb\x0a\xba\xe6\x0e\xbe\x51\xcc\xfc\x89\xb9\x3d\xa5\x2a\x22\x1c\x98\x53\x6b\x81\x2a\x83\x89\xc6\x36\xdf\x0b\xfc\x03\xe5\x50\x8b\x8d\x46\x82\x4e\xeb\x15\x81\x3a\x84\xa2\x1d\x8c\x28\x12\x9c\xf8\xab\x68\x15\xdb\x74\x22\x8c\xa0\x1c\x90\xf8\xa2\x94\x6b\x7a\x94\xd0\x38\xb6\x03\xf7\xea\x11\xe1\xff\xae\xf8\x7d\xec\x44\xa8\x8c\xb4\xa5\xd2\x59\x2f\x45\x1d\x46\xd6\xea\x7e\x40\x19\x3b\xd8\xf8\x8b\x31\x9e\xa8\x65\x01\xdc\x20\xa8\xde\xae\xe1\xda\xa1\xeb\x00\xb7\x1e\xc2\xc4\x2a\x25\x94\xc7\x52\x30\x8b\xff\x56\x23\x88\xef\x90\xc5\xd1\x07\x0e\x1a\x43\x60\x54\x97\x69\x0a\x89\xbb\x09\xac\x34\x37\xee\x14\x53\x26\x9e\x3b\xd5\xe8\x37\x86\x7a\x18\x9a\x0d\xbc\xad\xa2\x6a\x83\xc2\x7e\xd6\xc8\xf4\xbb\xfe\xb5\xe2\xc9\xa9\xd9\x6b\x1a\x02\x94\xa3\x5d\xeb\xce\x5a\x25\x78\x59\x01\x63\x41\x7b\xff\xd2\xcb\x8e\xb4\xf8\x49\x07\xf2\xc0\xe3\x99\x3f\x6c\xb0\x4a\xc7\xde\xee\x79\x2d\xac\xa9\x5c\xb6\xf2\x61\x2b\x5b\x08\xb7\x1c\x07\x01\x8d\x5b\xb1\x12\x87\xea\xeb\xf8\xbd\x79\x57\x4a\xb0\xe6\x4f\xbe\x47\xc4\xa3\x11\x1d\x33\xfa\x1b\x22\xca\x8a\x2a\x22\xbc\x32\xac\xf4\x51\x49\xcc\x64\x75\x80\x24\x71\x9e\x0e\x52\x57\x70\x1d\x7e\x22\x92\x87\x8e\x98\xa8\xf3\xe4\x74\x23\xa2\xa5\x85\xa6\x4a\xe7\x09\x5b\xba\x28\x36\xd7\xc2\xe7\x52\x6b\xbd\xb9\xe0\xfe\x40\x02\xc6\xa1\xf6\x1f\xe1\x3c\x70\x29\x2b\xde\x29\x8e\x9e\x07\x59\xd5\xc4\x8a\xa7\x02\xf7\x0d\x83\x09\xcd\x9d\xc6\xcb\xff\x86\xce\xb8\x42\x3a\x08\x2c\xe9\x48\xf2\xc7\x90\x48\x2f\xb0\x2c\x62\x1b\x96\x1f\x7d\x97\x5a\x88\x2f\x6c\x85\xa4\x4b\x33\x1e\x85\x93\x50\x28\x73\x75\xb4\xd1\x9a\x66\x48\x29\xb2\x98\x22\x52\x9c\xeb\x0f\xb5\x79\x10\x81\x0b\x8f\x27\x57\x20\x21\xe0\xbd\x8a\xa4\x52\x0a\xa0\x20\x19\xcb\xa2\x8d\xbb\x5b\x9b\x53\x59\xe2\xb2\xfe\xc8\x80\xa4\xdc\x8e\x59\x57\x6f\x00\x84\xd4\x1f\xbd\x02\x30\x81\xfc\x78\xcc\x35\x46\xb5\xbb\x2f\xaa\x85\xd3\xba\x65\x60\xdc\x75\xf9\xb9\x4d\x95\x76\x6a\x26\x84\x46\xf6\x55\x6f\x77\x7b\x0d\x3b\xab\x2f\x35\xe5\x50\x5e\x49\x35\xd9\x67\xfc\x84\x2b\x64\x96\x85\x25\xe4\xed\x35\x69\xd6\xeb\x0f\x50\xaa\x03\x27\xf7\xd5\xa8\xed\x98\x79\x93\x1b\x2c\xe6\xec\xf3\x28\xf9\xb2\x1f\x69\x4a\x3d\xc4\x94\x26\xaa\x6f\x43\xed\x8f\x19\x0e\x34\xb0\x1d\xb0\xb5\x95\x10\xd6\x3f\x1e\x58\x6c\x3b\xe5\x76\xb0\x3a\x7d\xf4\x03\x9a\xdc\x56\xe4\x88\x38\x32\x0f\x4e\x46\x2b\x9e\x58\x8a\x44\x11\x96\xd9\x2a\x83\xd2\x2b\xff\x3e\x07\x3e\x6d\xba\x98\xb2\x2f\xd3\xbc\x7f\x56\x17\xb7\xb3\x16\x66\x3c\x23\x30\x08\x17\x37\x88\x1f\x02\xe0\x4c\xea\x62\x04\x4c\xed\x9c\xe2\x08\xe4\x5d\x4e\x11\x29\xc1\xc9\x87\x0a\x40\xb4\xc6\x01\x8b\xd5\x28\x72\x01\x2f\x6c\xba\x6a\x4b\x49\x80\xcd\x9c\xc0\xa2\x07\x5d\x91\x68\x3b\x69\x88\x89\x9c\xbe\xab\xcb\x16\x9e\x13\x89\xf6\xee\x55\x3c\x83\xd5\x52\xc4\x35\x1b\xfd\x04\x01\xea\x29\x9b\x9d\x21\x28\x20\x20\xf9\xb4\x8c\x5a\x52\x5a\xdc\x08\x0d\x98\x0a\x2b\xad\xa2\x3c\xb3\xd9\x87\x98\x01\x6e\x67\xa3\x9b\xd9\xd3\x21\xab\xa0\x2e\x59\x7e\xc4\xed\x5a\x96\xfa\xbc\xb3\x9a\x21\x31\x36\x23\xd6\x64\x0e\x58\x67\xad\x5b\x50\x61\x94\x94\xbb\x7d\x78\xbb\x0a\x31\x79\xb5\xd2\xf5\xac\x93\x00\x6b\x9e\x01\x7c\x37\x44\xff\x93\xbe\x9d\xcc\x42\x72\x85\x40\x34\x11\xcb\xbc\x13\xf9\x41\x5c\x07\x12\xc1\xf8\x88\x31\x7e\x40\x92\xe3\x64\x9b\x3b\xe3\x17\xdd\xaa\xbc\xb4\xe7\xe3\xf7\x68\x01\x32\xf4\x17\x30\xaf\x28\x3e\x13\xa1\xd8\x5d\x73\x33\xad\x0a\x1e\x14\xf7\x11\x10\xa9\x0b\xad\x0d\x65\x85\xec\x68\x71\x1d\x16\x34\x70\x4b\x27\x1d\xc2\x77\xb2\x60\xbc\xf8\xa2\xe2\x90\xb9\xb6\xa0\x19\x4e\xf6\x31\x84\x60\x86\xb0\x50\x8e\x28\x58\xb3\x56\x2c\x87\x1e\x6d\x65\xa6\xd5\xfe\x77\xba\x77\x5a\x57\x2b\x23\x39\x02\x12\x49\x25\x9c\x7f\x96\x57\x55\x96\xb9\x01\x58\x89\x09\xce\xec\x20\x7c\x19\x39\xa4\x89\x62\x47\x4e\x8f\x23\x7d\x1c\x56\x76\x52\x0f\x5f\xef\xf2\x94\x68\xd7\xf8\x7b\xcb\x3e\x35\x53\x4f\x8d\xd5\x45\x43\x7d\xbd\xec\xce\xdc\x3f\x0a\xa9\xd8\x2b\xc5\x66\xaf\xb3\x7b\x53\xd4\x22\x56\xda\xc5\x75\xd1\x9e\x94\x2f\xab\x2a\xed\x96\x7b\x58\x5a\xd8\x29\x95\x4b\x47\xa1\x36\x14\xf5\x94\x04\x43\x21\xb6\x49\x2e\xd0\x82\x39\xba\x57\x6b\x7c\x34\xcf\x9b\xde\x22\x10\x21\x79\x1c\x8e\x0c\xdb\x0e\x96\xe5\x08\xbd\x3c\xac\x37\x0b\x00\xd0\xae\xec\x4c\xa3\x49\x35\x8d\xf9\xc7\x9a\x59\xd0\xd6\xf3\xd6\x6a\x1d\xa4\xbd\xa8\xa1\x9c\x51\x10\xa2\x21\x7a\xf9\x68\x96\xcc\x67\xf3\x32\xd9\x4b\x60\xf0\x87\x9a\xb4\x76\x12\x45\xcc\xa7\xee\x80\x70\x13\xdf\xdd\x67\x70\x2a\xcd\x99\xda\x67\x3a\xba\x9e\x5d\xc8\xde\xa7\xed\xd0\x7d\x45\x9e\xa8\x3a\x26\x1f\x54\xc9\xa2\x25\x86\x2c\x4f\xa3\x40\x46\x8f\x5c\x0b\x56\x9a\x5e\x54\x64\xf6\x48\x7b\xcb\xf5\x70\x0c\x0b\xf8\xe0\x88\x4b\xcb\x48\x4d\xe5\xb7\xb1\x8c\x48\x07\xe6\x6f\xc5\xa0\x8c\x6d\x9c\x44\xb6\x22\x0b\xd2\xbf\x76\xc4\xe2\x02\x8b\x50\x45\x42\x65\x49\x91\x68\x8c\xdb\x41\xea\xb8\xa8\x5a\xfb\xdc\x9d\xef\xc4\x91\x7b\x30\xb2\x92\x06\xfe\xd1\x87\xfd\xd3\xfd\xc2\xdd\xbb\x71\x96\x94\xbb\xc2\xd6\xa6\x9a\x87\xe8\xe8\x89\x72\xc4\xbf\x67\x15\xff\xb9\x38\xf8\xcd\x06\x7f\x61\x91\xc4\x9a\x94\x74\xa0\xe4\x43\x7c\x2e\xd9\xe0\x42\xfd\xee\xce\xb5\x5b\xa0\xbe\x85\x5a\x27\xb2\x11\xb4\xa7\x79\x8c\xf9\x3c\x17", 4066);
*(uint64_t*)0x20000158 = 0xfe2;
*(uint64_t*)0x20001358 = 2;
*(uint64_t*)0x20001360 = 0;
*(uint64_t*)0x20001368 = 0;
*(uint32_t*)0x20001370 = 0;
	syscall(__NR_sendmsg, r[0], 0x20001340ul, 0ul);
*(uint64_t*)0x20003540 = 0;
*(uint32_t*)0x20003548 = 0;
*(uint64_t*)0x20003550 = 0x20000240;
*(uint64_t*)0x20000240 = 0x20000180;
*(uint64_t*)0x20000248 = 0x85;
*(uint64_t*)0x20000250 = 0x20001380;
*(uint64_t*)0x20000258 = 0xc6;
*(uint64_t*)0x20003558 = 2;
*(uint64_t*)0x20003560 = 0;
*(uint64_t*)0x20003568 = 0;
*(uint32_t*)0x20003570 = 0;
*(uint32_t*)0x20003578 = 0;
	syscall(__NR_recvmmsg, r[0], 0x20003540ul, 1ul, 0ul, 0ul);
	return 0;
}
