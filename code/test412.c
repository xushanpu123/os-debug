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
memcpy((void*)0x20000880, "/dev/vcsa\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000880ul, 0x122001ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000500 = 0x20000040;
memset((void*)0x20000040, 143, 1);
*(uint64_t*)0x20000508 = 1;
*(uint64_t*)0x20000510 = 0x20000080;
memcpy((void*)0x20000080, "\xf5\x65\x39\xfc\x05\x00\x8f\xd0\x46\xb7\xcc\x64\x0b\xa9\x7b\x9f\xb6\x06\xec\x16\x6a\x89\x65\xdb\x1b\x21\x99\xa4\xc1\xd5\x4f\x85\x8c\xa2\xbe\x37\xd8\xaa\x9e\x8b\x33\x16\x79\x2b\xb8\x7e\xd2\x00\xc9\x12\xc6\xb8\x0a\x18\x00\x87\xe7\x3b", 58);
*(uint64_t*)0x20000518 = 0x3a;
*(uint64_t*)0x20000520 = 0x20000100;
memcpy((void*)0x20000100, "\x0b\x85\xad\x0a\xa2\xdb\x7f\x41\x5b\x4e\x9e\x12\x16\xc9\x58\x25\x93\x68\x59\xba\x75\xb9\x67\x67\x7a\x67\x8a\x3e\x77\x00\xc1\xf7\x8e\x95\x6b\xf9\x9b\x8d\x48\xc5\x6a\x19\xfd\xac\xe1\xb8\x6d\x20\x06\x6d\x4c\x0d\xcd\xe8\x22\x8e\x09\xd8\x3c\x9b\x6d\xfa\x8f\x75\xad\xbc\xb5\x28\xf3\x33\x16\x04\x24\x6d\xd0\x6e\x89\xe8\x9e", 79);
*(uint64_t*)0x20000528 = 0x4f;
*(uint64_t*)0x20000530 = 0x20000180;
memcpy((void*)0x20000180, "\x15\x7c\x14\x73\x2d\xa4\xee\x32\x76\x65\x4c\x04\x46\x95\xe4\xe9\x16\xcd\xed\x8f\x88\x3b\x01\x8e\x07\x57\x00\xa4\x84\xb0\xc9\x88\x75\x9a\x2b\x61\x2e\x49\x8b\x00\x54\x16\x18\xee\x72\x34\x18\x9b\x15\xbb\xeb\xdb\xd3\x4d\x94\x2b\x47\xb1\xe5\x6d\x5c\xe8\x04\x25\xff\xe3\x59\xda\x24\xec\xa2\xfe\x7f\x09\xaa\xd1\x2e\x25\x49\x49\x7f\x8c\x38\xab\x34\x4c\x6a\xbf\x1d\x3d\x49\x8f\x5a\x9b\x0e\x9a\x1d\x9a\xd9\xd5\x35\x5d\x3e\xce\x07\x5e\x20\xf4\x1e\x84\x13\x0f\x9a\x3d\xd6\xdb\x51\x24\x5c\x35\xb7\x82\xda\xa9\xcb\xd4\x13\x47\x22\x45\x7b\x9a\xa1\x6a\x2f\x3a\x05\x9e\xc9\x87\xbc\x3f", 142);
*(uint64_t*)0x20000538 = 0x8e;
*(uint64_t*)0x20000540 = 0x200008c0;
memcpy((void*)0x200008c0, "\xf0\x7c\x0e\x0e\x4c\x4e\x28\x75\xf2\x25\x96\xf2\xbf\xb9\x05\x34\x85\xb4\x19\xdb\x6d\xb5\x6d\x8b\x65\xc6\x72\xb6\x8a\xb2\xb0\x44\x5e\x58\x5f\xdb\x01\xaf\xd4\x44\x67\xc6\x5d\xd2\x9d\x69\x24\xc7\xd9\x2c\xc5\xec\x8c\xe9\x5e\xbf\xa5\x23\x79\x6d\xd8\xa4\x27\x26\xe0\xe8\x92\x4a\x50\xef\xb7\x08\x0d\x37\x41\x35\xe5\x66\xaa\x03\x61\x39\x38\x51\x95\xe6\x76\xb4\xd5\xf0\x69\xa0\xfc\xf4\xfe\x58\xf9\x42\x84\x52\xf3\xf5\x06\xda\x43\xb3\xd3\x5f\x8c\x19\x18\x69\x4e\xd9\xef\x1a\x78\xc3\xdf\x46\xab\xa1\xcc\xc6\x73\x8d\x78\xd5\x73\x2b\xf7\x7c\xb5\x9b\x61\xc2\x08\xe8\x7a\x2f\x62\xa6\x8d\x9c\xa9\x71\x24\x80\x29\x05\xa1\x45\xeb\x05\xa3\xd1\x39\x38\x6e\xbd\xc8\xd5\xbf\x11\x72\x8b\xa6\xba\x89\xf7\x9d\x50\xd8\x8c\x46\x4f\xd2\xf8\x2d\x14\x26\x1d\x6c\x19\x5e\x73\xd3\xc9\xe9\xa6\x31\x92\x5c\xdf\xe4\x22\xfc\x5e\xfe\x27\x7e\xb3\xfd\x41\x1b\xb4\x94\xc9\xaf\xeb\x10\xbc\x19\xc8\xf1\xef\xa1\x81\xc3\xb8\x6d\x41\x78\xba\x5b\x78\x3b\x09\xbe\x99\x3f\xfe\x43\x16\x3a\x62\xbc\x7a\x1f\x76\xb0\xaf\xf3\xfb\x24\x2a\x61\x43\xdb\x3d\x0c\x85\x8d\x45\xb6\x02\xc4\xdd\xf6\xf8\x9d\xdd\x24\xa0\x3f\x9b\xac\x05\x4c\x10\xc1\x09\xe5\x54\x87\xb7\x89\xec\x04\x2f\x62\x09\x8f\x1f\x58\x9b\xd4\x26\xcd\x29\x75\xef\x2a\xf2\x41\x10\x49\x9c\x9f\x1d\x55\x16\xe6\xc7\x9e\x89\x11\xdd\xad\x02\x78\xe6\x0b\x1f\x25\x9f\xd3\x25\x50\x5f\x64\xd1\xf9\xe0\xec\x93\xaa\xbc\xee\x57\x4e\x47\xb9\xda\xff\x8c\x4f\xce\xb1\x8e\x23\xf0\xef\x12\x45\xf5\x8c\x64\x6e\xfd\xb8\x80\x8b\xab\x26\x3b\xff\x2b\x9b\xea\xf1\xb3\x97\x35\x79\x7f\x21\x14\x61\xf4\x9f\xd8\xf7\xc8\xb7\xd5\x77\x32\xdc\x23\x6b\x11\xc6\x22\x0c\x29\x59\x30\x76\xc6\x61\xf2\x5c\x75\xf9\xf1\x59\xdc\xe7\x32\x4a\x2d\x93\x5f\xf6\x1c\x26\x9f\x3a\x08\xaa\x71\xbe\xf8\x12\x86\x37\x37\xb9\xe9\xeb\x42\x02\x4e\x26\xa3\x73\xc4\xd7\xa6\x85\x7c\x8a\xb1\xf7\x4e\x1b\x4a\xc8\x42\x28\x84\x86\x13\xfd\x94\x41\x6f\x43\x06\x0f\x31\x38\x93\xed\xdb\xa2\x47\x11\x2c\xc3\x77\xbb\xae\xa6\xd0\x0c\x89\x10\x2e\xd4\x64\x74\x82\xfa\x92\x25\x05\xcb\x61\xb6\x3e\x73\x4b\xbd\xa7\xd0\x48\xf0\x45\x05\x73\x81\xf5\xb7\x13\xe5\xbc\xa6\x85\x94\xbe\xee\x56\x16\x32\x88\x6e\x7a\x57\x90\xdb\x61\x8b\x82\x40\x90\x4f\x72\x12\x29\x48\x99\xf5\x89\xb2\x45\x99\x5b\x9f\x02\xe3\x9a\x9c\x5d\x2d\x4b\x10\xc9\xd1\x4f\x95\x8f\x4e\x41\x91\x89\xd4\x21\x49\x09\x42\x79\xf2\x64\x2b\x2e\xf3\xb8\x6f\x00\xa3\x5f\xd2\x2d\xf9\xf9\x9f\x30\x3e\xbb\x23\x30\x64\xb1\x23\x9e\x79\xdb\x35\x3a\xe2\xb9\xfb\xc1\xb4\xea\xfa\xb3\x1b\x47\x96\xda\xff\x72\x64\x0f\x27\x99\x48\x85\x75\x14\x8e\xc2\x0b\xf3\xf0\x09\x5d\xdc\xfe\xdc\x4b\x65\xe2\x38\xdb\xe7\x4b\x1e\x73\x31\x3d\x34\xa4\x86\x93\xf0\x6d\xb6\x01\xb1\x64\x6a\x22\xe8\x29\xc4\x80\x6c\xc0\xcf\xa0\x87\xcb\x0d\x1f\x9b\xd4\x05\x7a\x8d\x8f\xd9\xa0\x4f\xd2\x15\xe5\x19\xd4\x86\x07\x15\xd5\xe2\xd1\x96\x81\x03\xc7\x1a\xdd\x77\xe4\x4f\xad\x25\x34\xd7\x7b\x3e\x90\xd8\x68\xfc\x73\xc0\x70\x89\x4f\xcf\x61\xf7\xd8\x3f\x90\x43\x6f\xb9\xd6\xfe\x7e\xbe\x0f\x03\xea\x44\x21\x24\x0c\xf6\xfb\xe3\x12\x2c\x16\xfe\x8f\x49\x32\x21\x87\xf5\x18\xd9\x99\x7c\x6e\x0d\x85\xb9\x3b\x4d\x2f\xda\x9d\x4c\xc2\x24\x71\xf1\xdc\x4d\xee\xb1\x5c\x39\xb2\xa1\x74\xd2\xda\xbf\x9d\x51\x5f\xed\xbb\x4e\x93\x17\x3f\xac\xf0\xb2\x80\xe8\xa5\xce\x19\x11\x3b\x79\x77\x4d\xb4\x82\x60\xfb\xc1\xa7\x63\xd3\x8e\xa0\xa9\x5d\xfc\x69\xd1\x85\xfc\x11\x82\x9b\xbb\x44\xa1\x78\x40\xc1\xff\x41\x98\xc3\xdb\xe1\x48\x52\xe4\x86\xe3\x5e\x3f\x39\x52\x4d\xa2\x9c\x13\x39\xab\xc3\x3c\xaa\xd1\x6d\xa7\xae\x13\xe7\x3b\xac\x1e\x6c\x6c\xf7\x3d\xb5\x6a\xa0\x77\x9e\x4f\xdb\x61\xd3\x91\x74\xff\x60\x9b\x25\x94\x38\xcd\x3a\x78\x3f\x69\x1d\x0c\x74\xd0\xf7\x10\x42\x34\xc7\xd8\xe3\x32\x7b\x61\x9e\x84\x14\xd8\x44\x91\x15\x66\xea\xe1\x7a\xc7\xeb\xc8\xfb\x40\xe6\xf3\x9a\xfe\x67\xaa\x94\xb1\x86\x32\x7d\x00\x9d\x50\x81\xbf\x38\xce\xf1\x62\x0a\x7e\x9e\x7d\xa2\x00\xb2\x19\x3f\xc1\x74\xd8\x9f\xde\xee\x3d\x72\x48\xb3\x02\x79\xc3\x91\x74\x5e\x63\x1d\x9b\xac\x96\x0e\x52\x96\xcb\x6b\x9a\xd4\x3e\xc0\x6a\x29\x64\xe0\xad\x8d\x91\xe8\x88\x1f\xe6\xab\x89\x7b\x6b\x4b\xe9\x8b\xd7\xc5\xbd\xee\xda\xeb\x60\x72\x5d\xe8\xfb\xb3\xfb\xf6\x9c\x3f\xd3\x1f\x4f\x24\xf2\x38\x0b\xb9\xa2\x62\x98\x4e\x56\x0a\x35\x0e\x75\x60\x67\x61\xa1\x6e\x97\x5c\x6e\xfc\x42\xdf\x4a\x11\x2b\xe5\xf8\x60\x6f\x55\x4b\x39\xd8\xab\x8c\xc4\xaa\xe0\x53\xae\x13\x5f\xc1\x58\xef\xe5\x31\x6c\x3d\x32\xe0\xf4\xea\x63\xd9\x7e\xa1\xfb\xd4\xc7\x80\xf5\x3c\x30\xea\x6a\xe3\xc0\xd9\x3c\x4b\xd8\x0c\x18\x97\x29\xd5\xfa\x57\x6a\xea\x72\x85\xc9\xd2\x2e\x15\xfd\x37\x5d\xdb\xdb\x78\xe9\x51\x45\x15\x7e\xad\x9e\x0b\x4a\x6c\x5c\x29\xf1\xc9\xaf\x2c\xc7\x25\xba\x93\xd0\x8e\xc1\x40\xdc\x5a\xc2\x0d\x6f\x3e\xd9\x1b\xcf\x2e\x2b\x3c\xed\x56\xd2\x04\x4f\xd2\xae\x4e\xdd\xd1\xc3\xc4\x2a\x84\x02\x79\xab\x76\xb3\x91\xac\x9f\x62\x12\xe9\xad\x04\xca\xf6\x2e\xd2\x56\x69\xce\x65\x36\xaf\xf4\x23\xf4\xba\x4f\xf4\x29\x33\x9f\x62\x9a\xa2\xc6\x7d\xc1\xaa\x7f\xd2\xae\x3f\x58\x74\xb2\x23\xea\xf2\x8f\xdc\xe5\xb3\xd8\x5f\x5c\xfc\x74\xce\x2a\xbb\x27\xf3\xe7\x74\xc9\x3d\xe4\xac\xc2\x29\x12\x0c\x17\xe9\x73\xf1\xdf\xa7\x9f\x86\x17\xb0\x73\xca\x47\xe6\x3a\x20\xf9\x46\x11\xb0\xff\x20\xbe\xce\x1c\x2c\xa6\x7a\x9c\xf6\x32\x6c\xfc\x4d\xf5\xf9\xae\xe7\xb3\x5a\x57\x20\x42\xfe\x70\xc7\xc1\x1b\x92\x70\x44\x4d\xac\xde\xfd\x93\x87\xde\xcf\x88\x7c\x6d\xd4\x5e\x20\x0b\xf0\x47\xf6\xe8\x64\x68\x88\x74\xd4\x52\x4b\xf0\x04\x7e\xe8\xa7\x24\x88\x39\xd8\x51\xbf\xf9\x48\x35\xdc\x94\x0c\xd7\x2c\xee\xa3\xa2\x30\x11\xc6\xe4\xaf\x2a\x4c\x36\xcb\x38\x0b\x88\xe6\x74\x9d\xdf\xe7\xf3\x96\xf4\xcc\x7a\x1c\x8b\x6b\xb5\xf1\x16\xe4\x54\x7a\x26\x1c\xe3\x11\x47\x86\x44\x88\xbe\x48\xee\x43\x1f\xf2\x4a\x26\x0f\x38\x14\x2b\x8a\xc6\x18\xf0\x3d\x4a\xef\x6a\x37\x28\xaa\xbd\x08\x08\x5c\x1c\x79\xa5\xa2\x39\x9f\xa7\xd2\x7c\x56\xd2\x0f\xc2\xf2\x9f\xd4\xdc\x76\x92\xff\xcb\x8e\xff\x30\x01\xb8\xa4\x34\x4b\xee\x54\x5e\x80\x6e\x26\x7b\xb9\x6c\x75\xf4\x2a\x70\x7a\x43\x5b\x3b\x92\x8a\xae\x55\x6d\x0c\xa9\xb7\x71\x01\x4a\xe9\x9f\xe7\x30\x64\x21\x62\xd1\xe1\xb2\x4a\xd6\x4e\xe4\xe9\x2d\xa1\xbd\x88\x19\xdf\xd0\x12\x01\xfe\x4b\xc5\x20\x51\xe4\x13\x74\x85\xf1\x34\x41\x08\xa2\xfb\x90\x10\xf3\xe9\x99\x34\xf5\xef\xf7\xf1\xeb\xf0\x49\x64\xd4\x90\x64\xbb\x77\xcb\xa8\xc5\xd9\xb4\x29\x61\x02\x0c\xc2\x42\x51\x97\xf2\xba\xbd\x35\xc6\xc1\x57\x01\xcf\x74\x33\x0a\x4d\xcf\xb4\x31\x7d\xd8\x16\x64\xd6\xbe\xbf\xa1\x70\x79\xdb\x5a\x53\xe4\x1c\xed\x8a\xcd\x3b\x05\xd0\x91\xd1\x01\x40\xfe\x49\xbc\x83\x28\x8c\xf4\x8d\xf6\xb6\xff\x54\xe0\x6e\x26\x8a\xb1\x6f\xa8\x4d\x87\xd1\x15\xcb\xc0\xd9\xde\xe0\xf4\xbe\x58\xff\x57\xc0\xb7\xc5\x69\x60\x1f\xeb\xb1\x45\x22\x88\x34\x31\x7e\x34\x02\x24\x25\x47\xbd\x2e\x0b\xe6\xcf\x00\x86\x1c\x7f\x24\xba\x0c\xfc\x4c\xf3\xca\xdb\x8d\x7d\x84\x7f\xdf\xe3\xb2\x84\x01\x27\x38\x55\x4a\xd7\x42\x87\x7e\x8d\x60\x64\x63\x72\xa5\xb4\xe8\x2a\x43\x18\x4b\x87\x6c\x15\xf7\xee\x8d\x89\xb7\xd8\x83\x2e\x89\x0a\xac\xfa\xf8\xcd\xe4\x89\x73\x95\x11\x0d\x60\xfc\xe2\x8c\x67\x3c\x7c\xd9\xc4\xbc\xcb\x75\xc4\x4f\xb5\xea\x59\x98\x01\x83\x3e\xa3\x0a\x27\xa8\xd8\x1f\x36\xb4\x7c\xdc\xf3\x6a\xeb\xb9\x47\xc2\xbc\x6e\xa6\x12\x91\xb0\xe0\x90\xe8\x87\x8b\x75\x83\xd8\x97\x8f\xc1\x44\xf0\xaf\x2d\xc7\xf2\xfa\x9f\x41\x2d\x3b\x39\x1b\xf3\x56\x34\xe6\x22\xd4\xce\x06\x04\xcd\xcc\x80\x92\x8a\x9e\x5f\x4d\xc6\xa2\x8e\x59\x04\xd5\x9d\x4e\x2e\xcb\xbe\x36\x11\xe1\x99\x0d\xfc\x89\xa8\x4c\x55\xbc\x5c\xb6\x6c\x84\x36\x55\x55\x5f\xfc\x43\x82\x01\x80\xa1\x22\x72\x63\xc1\x81\xd8\x1b\x70\x67\xf3\x4a\x89\x97\x1f\xfe\x6d\xee\xa9\x84\x0f\x0b\x10\xd4\xff\x96\x78\xea\x7d\x54\xfb\x14\x4d\x16\x32\x30\x75\x08\x33\x93\x13\x0e\x66\x72\x1e\x28\x55\x61\xab\xab\xb6\xb9\xfd\x87\xf1\xd3\x99\xdc\x06\x84\x5b\x91\xb4\x8a\x6c\x54\x0e\xad\xbe\x18\x47\xd3\x46\x09\x66\x65\x87\xa4\xf8\x40\x4f\x95\x95\x69\x95\x69\x0d\x09\x79\x57\xde\x55\xa4\xfc\x91\x8f\x6a\x1c\x57\xe3\x12\xd2\x76\xe1\xed\x08\x54\xb7\x05\xd0\xf2\x2c\xb7\x3e\xf1\xfb\xca\xc1\x56\xdf\x1f\x5d\xac\xa7\x81\x48\xf4\x02\x70\x06\xef\x2a\x9c\x26\xbd\xd3\x3d\xb4\x04\x0e\x4e\x66\x95\x93\x92\x6f\x96\xac\xcb\x7d\x0a\x8a\xdd\x87\x7d\x88\x4d\x41\x59\x52\x61\x2e\x3f\xe3\xe8\x59\xd5\x96\x3c\x2f\xe1\x57\x49\x71\x82\xc2\xfc\x72\xcf\xe7\x57\x4b\xdf\x07\xa2\x0c\x5b\x29\x04\x37\x2c\xf4\x96\x50\xcf\x99\xb8\x3c\xac\x62\x2d\x2e\xae\x22\x7f\x69\x0b\x18\x16\x00\x71\x20\x66\xc7\xd7\x15\xd3\x2c\x06\xc7\x1a\x23\x58\xec\x8a\x56\x1f\xbd\x5b\x63\x4d\x3b\xa6\x0d\x44\x0b\xd5\x42\xf0\x12\x08\x9d\x5f\x11\x2f\xd8\xdd\x20\x2b\x43\xba\x98\x0b\x0f\x46\x73\x47\x33\x85\x20\x7d\x18\x3d\x65\xe9\x9f\x2b\xad\xe1\x2d\xb0\xa3\x3e\x29\x3c\x52\x33\xd4\x83\xd7\x67\x35\x88\x44\x2e\x9d\x0b\xa4\xef\xa1\x30\xb2\x27\x0a\x9c\x21\xc7\xe8\x30\xad\xe0\x6c\x4b\xec\x00\x3d\x60\x96\x04\x05\x6c\xee\x0b\xde\xb6\x2c\x4c\xd2\x51\xb6\x63\xb8\x6d\xf8\x0b\x94\x7a\xac\x90\xcf\xa3\xc7\xdc\x5c\x60\x29\xbe\x76\xa2\xdd\x62\xef\x96\x1f\xe9\xab\xdf\x24\x25\x28\x15\x72\x1b\xaa\xe9\x7a\x86\x82\xf4\xda\x44\x7f\x27\x70\x27\xa6\x3c\x90\xd8\x27\xa0\x80\x6f\x06\x5f\x6d\x98\xed\x5c\x34\x26\x2c\x5b\xa4\x9b\x5f\x8b\x79\xcc\xdf\x8c\x17\xb8\xfe\x3d\xa1\x65\xda\x48\x4c\xc2\x27\xcb\x59\x8a\xbc\x12\x6f\x18\x60\x3c\x39\x3f\xcd\x9a\x98\xb8\xb7\xb6\x53\xdb\xd6\x63\xd9\x8a\x63\xa4\xfc\xac\x07\x4e\x56\x9e\x54\xf8\x1b\x71\x66\xde\x55\x76\x1f\xe2\x66\x59\x71\xaa\xd7\x0d\xd3\xb5\x57\x66\xe5\xab\x43\x6a\x14\xb1\x0f\x11\x2e\x7b\x45\x3f\x1e\xbc\xe5\x91\xa6\xc9\x35\x19\x05\xb1\xdc\xab\x8a\x15\x06\x10\xe3\xe4\xfb\x93\xfc\xd8\xe5\x76\xd0\x0e\x93\x2f\x57\xa0\x31\xb1\x47\x22\x95\x82\xaa\x19\x38\x94\x3f\x0e\xc7\x4a\x79\x4c\x18\xbb\xe1\xbc\x96\xc5\xac\xb4\xd0\x8b\x17\xfc\x02\x5a\xc7\x7d\xec\x85\xd8\xe4\x66\xb1\x66\xa0\xc8\xda\x6c\x78\xc3\x3c\xa2\x71\xa0\x53\x6b\xf0\x2f\x4d\xd3\x16\xb0\x13\xa1\x51\x7b\x9a\x62\x84\x2e\x78\xbe\xa8\x34\x7f\xf3\x8a\x2e\xab\x66\x48\x7e\x73\x82\xfb\xa5\xf0\xd5\xda\xae\xc5\xd0\xc4\xa3\x00\xec\x78\xc4\x28\xd6\x7b\x9e\x0b\x20\x14\x23\x64\x8f\xcb\xcf\x02\xef\xcb\xe7\x49\xde\xdd\x01\x4c\x30\xda\x64\x5e\x3b\x0b\x06\x87\xdc\xf5\x69\xbc\x44\x27\x82\x60\xc4\x2f\xf8\x86\x96\x57\xf4\x71\xbd\x6a\xa5\xc4\x22\xbb\x89\xa7\x0a\x58\x16\x88\xa3\x9a\x72\x7b\xff\x5f\x7b\x5c\x7b\x8d\x06\x4f\x51\x19\x88\x00\xbe\xb3\x26\xf4\xbf\x83\x98\x32\x1a\x64\xb5\xa1\xd0\xd5\x89\x72\xd1\x8f\x59\x78\x7e\xc5\xc4\xdd\x37\x0d\xea\x2d\x4d\x21\x4c\xbc\xe8\xdf\xdd\x31\x69\xb9\x49\xf8\x3e\x97\xb9\x72\xf6\x37\x0b\xed\xe7\x47\xcb\x5d\xca\xd7\xe7\x37\x4b\x9d\x61\x15\xfe\xcf\x7f\x18\xbd\xc4\xcb\xa0\x17\xbb\x33\x58\x06\x30\xeb\x4c\x2f\x48\x59\x0c\x4f\x79\x07\xe9\x1d\x14\xff\x43\x41\x1d\xa7\x75\xa6\x90\xaf\x78\x9e\x86\xb6\x6d\xf3\x58\x5c\xd5\x88\xa9\x01\x60\xf1\x2b\x0b\xee\x58\x41\x55\x68\x75\x97\x58\x39\xcc\x3c\x49\x8b\x8a\xc8\x14\xe1\xa4\xb3\x57\xdc\xe6\x40\x00\x39\x87\xbc\x14\x3d\x55\x72\x9c\xa2\x5d\xc8\xcd\xf6\x89\x8f\xf7\x2c\x48\xbb\x87\xa1\xc4\x8c\x57\xf6\x24\xe8\xea\xdc\x1a\x69\x6c\x9f\xf3\x4f\x0e\x84\x98\x7c\x04\x98\xcd\x2f\x31\x3c\xf0\x72\x1e\xc0\x64\x95\x03\x42\x50\xe6\x0a\x87\xa2\xf0\xef\xe6\xbb\x85\x84\xd3\x6e\x49\xc3\xd2\x91\x41\x92\x3c\xa1\xf5\xb5\x6f\x2d\x9d\xac\x14\xf9\x81\x1b\x2b\x88\x82\x0e\x39\xe1\x12\x73\x3b\x0f\x21\x24\x06\xc7\xe8\x16\x24\x90\x76\x56\x03\x22\xb8\x1e\xdd\xa1\x6b\x4a\x12\x10\x0e\xbb\xc7\x07\xa1\x5d\x1c\xf5\x91\xa5\x51\x32\x2b\xac\x4e\xae\x32\xf1\xbf\xbc\x4a\x24\x1d\x7b\x6b\x44\xf5\x97\x86\x5f\xf4\x92\x43\x23\x2c\x43\xae\x38\x79\x08\xf1\x79\x05\x57\xa3\xea\xed\xf3\xaa\x29\x94\x17\xc7\xa8\xce\xb1\xc2\x24\x5d\x59\xd9\xe0\xef\x35\xce\x6f\xe1\x13\x77\xa7\x12\x4c\x54\xe0\xb8\xba\xff\xfe\x14\x92\xf0\x39\xc1\xa1\x78\x9c\x5f\xa5\xd4\x7c\xca\xde\xb8\x21\x0d\xa1\x53\xf3\x13\x18\x89\xd2\x15\x1e\xbe\x91\x67\x26\x56\x53\xcd\xde\xd9\xd6\x5f\x2c\xf9\x6b\x85\xdb\x77\x10\x1a\x11\xf0\x04\x64\x23\xde\x48\x55\x59\x0c\x9c\x71\xcd\xad\xb7\x75\x4b\xdc\xf0\xc9\xe3\xa4\x49\x1d\x40\xe1\x2e\xf9\x8d\xe7\x1d\x6b\x8e\xf6\x52\x2f\xb5\xcc\xfb\x32\xfa\x3a\x04\x43\x6c\x93\xe1\xd3\xa8\x66\x3b\x82\x42\x4e\xcb\x6b\x85\xc0\x1f\x53\xcf\x09\x5f\xba\xeb\xad\x98\xc3\x40\x24\x01\x56\xa7\x2e\xfe\xae\xb1\x06\xc3\x71\x4b\xb8\xbc\x97\x0d\x7d\x50\xe4\xff\xe6\xac\xb6\x3c\x73\x7c\x06\xe3\xbd\xdf\x4c\x51\x5b\xce\x9c\xb6\xf8\xf2\xf8\xdd\x69\xd0\x21\xe7\xf0\xda\x4f\x85\x9a\xd4\x87\x1c\xb7\xcf\xe1\x4f\x92\x26\x14\x8d\x8b\xbc\x87\x8a\xf5\x61\xd5\xcd\xc5\xf6\x49\x8e\x51\x64\x85\x26\x1f\xdf\xcd\x0d\xb5\xff\x91\xa1\xb6\x66\x2d\xe0\x98\x91\x92\xca\xf6\x54\x82\xc9\x4c\x3e\x12\xd4\xe0\xae\xb4\xe9\x4a\x6d\x33\xc1\x7f\xd0\x3e\xd1\x94\x8f\x53\x06\xa8\x0c\x73\x85\x0e\x79\x56\xfa\xc0\x5f\x2f\x14\x76\x0a\xed\xc3\x10\x4d\x3f\x25\xa6\x33\xe2\xc7\xfe\x9e\x02\xab\xbf\x75\x79\x39\x2a\x00\x4a\xac\xbf\xd0\xdf\x18\x36\x5c\x7a\xa1\x99\x3f\x8b\xdb\x2a\x79\x5a\x13\xcc\xc8\x3b\x4d\x76\xea\x3b\x72\x56\xf4\xc4\xe8\xa2\xfb\xa4\xa5\x78\x36\x10\x2c\xeb\x34\x8b\xdb\xc8\x07\x23\x81\x78\xb6\x54\x65\xb9\xa9\x7a\xd3\x5a\xe8\x42\xfb\xdd\x51\x3f\x8c\x64\xf9\x83\xb9\x98\x0a\x81\x4c\x32\x13\x3c\x67\x45\xba\x48\xec\xc0\xfa\xeb\xbd\x59\x88\x35\x27\xc1\x4f\x59\x5f\xa0\x19\x2b\x7b\x53\x47\x53\xbc\x73\x7d\xff\xe7\xa8\xa9\x7c\xa0\xea\xc4\x72\xfb\x35\x38\xbd\xda\x86\x76\x52\x12\x48\x82\x21\x6d\x41\x84\xf2\x81\xb2\x1d\x56\xf0\x07\x6e\x39\x08\xa4\xf1\x89\xd4\x57\x08\xda\xad\x13\xc8\x50\x6a\x93\x50\x63\x47\xe4\xf7\x67\x08\x65\x99\x24\x0e\x52\x9a\x50\xc1\xaa\x60\x5a\xb1\xdf\x1d\x22\x0a\x0c\x3b\x99\x13\x73\xae\xf4\xca\x3a\x6f\x40\x7d\xf9\x2b\xaf\xd7\x99\x7a\xfa\x51\xd1\x5d\xc3\x79\xc0\x8d\x54\xf7\x44\xe0\x43\x62\x11\xf8\x4f\x78\xac\x3d\x09\x1e\xd0\x7e\x4c\x17\x4f\xca\xc3\xcb\x8d\x1e\xd0\x53\x66\x1d\x4f\xaa\x9e\xba\x9b\xd1\x6d\x93\xca\xbf\xed\xbf\x17\xd6\x14\xe1\xee\x86\xf8\x4a\x88\x77\x1f\xc7\x27\x18\x2b\x9b\x9a\x64\x19\x13\x70\xf7\x44\x83\xd5\x4d\x12\x10\xae\x11\x67\x86\x7d\x1a\x96\x46\xf5\xdc\x51\x11\x02\x0b\xc4\x85\x0a\xac\x93\x58\xfb\xd5\x00\x48\xf4\xc6\x57\xc1\x60\xc2\xad\x6b\x7d\x7e\x95\x83\x38\x72\x20\x1b\x03\x96\x1e\x7d\x8e\xb3\x17\xd8\x28\x35\x04\x5d\x1e\xeb\x29\x46\x68\x16\x89\x16\x02\x54\xb4\x4a\x1e\x11\x6b\xbe\x65\xb6\x34\x76\x45\xd8\x99\x51\xc5\x81\x4b\x47\xa6\x2d\xa0\x07\x5b\xc0\x89\x1f\xa0\xc0\x39\x23\x66\xed\x48\xce\xf0\xac\x53\xb3\x31\xb4\x4e\x69\x65\x12\x4e\xda\xa4\x56\x3b\x75\x88\x55\x76\x49\xf0\x6c\x67\xbb\x14\x35\xeb\xa0\x88\x42\x17\xad\xa5\x00\xb5\x96\xde\xfe\x1d\x23\xea\x04\xa7\x7c\xb9\x16\xf9\x6d\xd5\x2e\x1d\x74\x48\xbb\xdc\x0c\x56\x38\x87\xfe\xde\x5a\x99\x13\xac\x34\x04\x98\x93\x5f\x13\x96\x06\xe4\xa2\x7e\x09\xc0\xec\x61\x5f\x71\xd6\x77\xc1\x59\x33\xc7\x7d\xfe\x29\xf4\x5a\xed\x16\xbc\x6b\xd4\xd8\xf0\x21\x28\x4f\x80\x0f\xc9\x3c\x31\xd9\x0c\xb3\xdc\xee\xc0\xb2\xf6\xf7\x36\x24\x63\x79\x7c\x9a\xd7\x61\x0a\xf7\x9b\x1b\x1e\x9a\x29\xd4\xc8\x46\x5f\xfa\xb9\x7a\xc0\xa2\x8c\xab\xbd\x18\x64\x94\x74\xdc\xce\xa6\xf6\x31\x80\xac\x0c\xd7\x14\x33\xa7\x52\x1d\x79\x00\x68\x60\x5b\x63\xa2\xc1\x5b\xca\xa9\xf5\x2c\xe0\x1e\x64\x11\xf8\x28\x33\x81", 3576);
*(uint64_t*)0x20000548 = 0xdf8;
*(uint64_t*)0x20000550 = 0;
*(uint64_t*)0x20000558 = 0;
*(uint64_t*)0x20000560 = 0;
*(uint64_t*)0x20000568 = 0;
*(uint64_t*)0x20000570 = 0;
*(uint64_t*)0x20000578 = 0x49;
*(uint64_t*)0x20000580 = 0;
*(uint64_t*)0x20000588 = 0;
	syscall(__NR_writev, r[0], 0x20000500ul, 9ul);
	return 0;
}
