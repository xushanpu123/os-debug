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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000000ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000000;
*(uint64_t*)0x20002a00 = 0;
*(uint32_t*)0x20002a08 = 0;
*(uint64_t*)0x20002a10 = 0x20001040;
*(uint64_t*)0x20001040 = 0x20001100;
memcpy((void*)0x20001100, "\xd6\xd3\x3d\x9b\x4e\x16\xbf\xfc\xb2\x26\xf9\x30\xca\x59\xd4\xb6\x04\x0d\xf5\x22\xd8\xeb\xa3\x4f\xf6\xed\xbe\x67\xeb\x71\xd2\xf6\x05\xdb\x3c\x7b\x29\x17\x93\x1a\x88\xf9\xd4\xa9\x85\x11\xa2\x8a\x08\x4b\x88\x05\xfd\xe0\xa0\x74\xd0\x86\x10\x4b\xea\x9c\x95\x5a\x1d\x9d\x07\x3c\xd0\x7c\x93\x74\x0a\x7a\xc5\x8c\xe8\x3f\x1b\xa5\xb0\x0b\x72\x97\x97\x5b\x7d\x7c\x05\x03\xae\x57\x66\x88\x58\xcb\x40\xd0\x99\xc4\x51\xee\x84\x7d\xb5\xf8\x77\xc6\x9c\xfe\xb0\x87\x89\xdc\x4a\x03\xd8\x72\x6e\x90\xf7\xce\xc0\xc9\xc0\xd4\x4d\x25\x14\xde\xfe\x88\x4e\x79\x61\xf3\x6f\x35\x4d\x87\x0d\x70\xe3\x93\x9c\x76\x06\x8e\x01\x55\xd7\x20\x0f\x85\x55\x1b\x86\xf8\xe3\x6e\x51\x64\xaa\xb5\xbf\x45\x52\x94\x3c\x5e\x07\x9d\xed\xcb\x98\xd9\xc2\x5d\x59\x4c\x51\x01\x67\x51\xc1\x4c\x12\x79\x82\x24\xf8\x56\x6b\x28\xcf\xf1\xa1\x15\xaf\xb6\x33\x9f\xee\x5e\xb4\xa1\xca\x8d\x23\x96\x93\xeb\x57\xec\xb2\xd8\x90\xa7\xd5\x07\x15\x2b\xdc\x26\xcb\x3b\xcd\x55\xa0\xe2\xaf\x64\x02\x96\x24\x81\x31\x12\x0e\xec\x3b\x5c\xfc\x3e\x69\x1c\x17\x50\x21\xa4\xf5\x99\xa8\x5b\x57\xb3\x54\xb7\x4f\x51\x26\x8c\x3a\x9b\x3e\xff\xae\x35\x08\x1e\x6c\x60\xe9\x6d\x94\x73\xdd\x98\xb5\xb8\xf0\x64\x7c\x97\x79\x0f\x05\x7b\xc5\xf8\x2d\x10\xb6\x5e\x53\xa4\x8e\xe2\xa7\x56\x1d\xbb\xc0\x76\x99\x87\x52\x3b\x1d\x14\xc1\xdd\x05\x3b\xd2\x54\x65\x7a\x8d\x86\x85\x81\xaa\x35\x1b\x27\x3b\x39\xbf\x95\x2a\x71\xd1\xc7\x86\x14\xff\x15\xf3\xf2\xa5\xca\x12\xda\x5e\xe1\xba\xfd\x45\xec\x67\x80\x97\x60\x6b\xdb\x3f\x0c\xc8\xb4\xe3\x2b\x35\x57\x70\x69\x46\xcd\x91\xc1\x72\x0c\x67\x9f\x7a\xdf\x91\x93\x29\xe2\xa8\x76\x08\x0b\x9f\xfa\xc0\xee\xb9\xa6\x32\x54\xa1\x3e\xc1\x66\xcf\x3a\x0b\x47\x2c\xf0\x2d\x95\x05\x31\xc4\x81\x85\x98\x29\xbd\xf5\xfb\x66\x00\xfd\xc1\x18\xa9\x56\xed\x32\x9f\x8f\xd4\x53\x19\xf0\x75\x67\x53\x16\xda\xd8\xf6\xcd\xcd\x4d\xc3\x87\x8a\x1b\x98\xcc\x83\x3a\x1c\x6e\xe5\xac\x6a\x66\x3a\x2b\x6a\x22\x1e\x6e\x1c\x48\x7b\x02\x40\x16\x89\x4f\xe9\xe2\x18\xe2\x46\xf4\xc8\x0e\x88\x18\x50\x40\x7b\x1b\x8d\x42\x46\x9a\xd4\x5d\x09\x23\xba\x33\x56\xb1\xf6\x44\x4c\x01\x61\xb1\x23\x1b\x43\x27\x0a\x66\x03\x8e\x69\x0e\x5f\xd1\xdc\xa6\x35\xd3\x8b\xce\xdf\x0d\x61\xf0\xea\xf7\xdf\xbc\x26\xfe\x40\xfb\xa9\xfb\xbf\xaf\x4c\x88\x1b\x53\x89\x6e\xc2\xca\xb9\x73\x5d\xfb\x70\xc3\x93\xa4\xd1\x39\xe1\xad\xcf\x21\xeb\xf9\xf7\x5f\xc2\xde\x87\xd9\x71\x67\x8d\x04\x82\xce\x55\x73\x5e\x8b\x33\x30\x80\x11\x6d\x9f\x27\x82\xe0\x2e\xdc\xad\x7b\x3f\x29\xe6\x8f\xbb\xe5\xc7\x37\x7c\xab\x57\x24\x58\x6d\x1b\xdf\x7d\x0d\xb6\x56\x0f\x5c\xe8\x3d\xb0\x41\x08\x65\xc7\xc5\x00\x57\x11\x84\x57\x1a\xa3\x6c\x8d\x8d\x82\x44\xc6\xe2\x5c\xbe\xa2\xa2\x93\x21\xc9\x42\x60\x4c\xa8\xcd\x3c\x9c\x24\xfb\xb9\x02\xd8\x65\x3c\xae\xf3\x4a\x00\x11\x57\x28\xff\xbd\xce\x5a\x1b\x02\xdb\xb2\x89\xac\x02\x65\x94\x29\xe5\x33\x2d\xfe\x11\x99\xa6\xce\xfb\x4b\x24\x11\xfd\x11\xa1\x16\x0c\x70\x58\xaf\x05\xd3\x69\x37\xa3\x3d\x2b\xba\xa1\x48\x40\xa8\x24\xb0\x9f\x2a\xe4\x51\x4a\x02\xbc\xff\x51\xb8\x96\x7c\x0a\xc3\xf9\xb8\xe9\x85\xdc\xd5\xcb\x22\x38\xe2\xe7\x2e\xf1\x95\xa0\x16\x1f\x14\x12\x9e\x63\x44\x0b\x51\x7c\x42\x50\x1b\xf8\xfb\xe3\xdd\xf1\x21\x1c\x43\x9c\x71\xf4\x6d\x8f\x78\xd6\xb9\x4e\x95\x64\x95\xb0\xac\x16\x71\x69\x6d\xd8\x63\x69\x6e\xa1\x7b\x35\xa7\x39\x94\x39\xff\x81\x24\x8d\x35\x30\xce\xad\x02\x63\x7a\x04\xb5\x7d\x6a\x69\xca\x9b\x9c\xd5\x5e\x03\xbc\xba\x41\xe8\x22\x64\x94\x46\x97\xf4\x8f\x5b\x1b\x7f\x56\xa9\xca\x89\x83\xd7\x37\x17\xd5\x1d\x2b\xfd\xac\xdc\x7a\x53\x16\xf2\x07\x18\xf2\xd6\xa5\x70\x99\x20\x6b\xdd\x0e\xab\x09\x43\x9a\x31\x50\x81\xa3\x15\xe8\x84\x3e\x42\x0f\x9d\x16\x88\xa2\x38\x91\xbf\x96\x6d\xc9\x14\x86\x2c\x23\xb7\xf9\xca\x7c\xb0\x8e\xda\xbe\x1d\xb7\x29\x7c\xef\x8a\x93\x5c\x95\x68\x64\xba\x9e\x38\xa2\x19\x87\xeb\xa1\x49\xf9\xb1\xdc\x89\xb9\xf9\xd4\xfb\x09\x5a\xb0\xe5\xd8\xbe\x3e\xab\xb9\xa2\x29\x80\xd0\x86\x92\x02\x5d\x1b\xe4\x09\x94\xda\x97\x05\x23\x5b\x74\x89\x7a\x94\x3e\xd8\x25\xd2\xc9\x24\x73\x04\xb0\xb5\x48\x6a\xfe\x64\x91\x39\x76\x77\x4b\x98\xbc\xcd\x88\x4d\x63\xd9\x95\x9b\x23\xe8\x15\xd2\x69\x97\xbc\x06\xc9\x5f\x31\xdb\x95\xe5\xe1\xf9\x2e\x9e\x88\xaa\xbd\xb9\xa7\xa3\x2c\x0e\x2a\x6d\x61\xfa\x49\xb7\x69\xfc\xdc\xcc\x07\x4d\xaa\x17\xcf\x27\xc5\x91\xea\xa5\x00\x46\x17\x5f\xfc\xe1\x9e\x0a\xca\x72\x30\xcf\x11\x83\x41\xe3\x92\xc6\x2f\xb6\xe9\x7b\x70\x89\xa2\xe4\x3e\xb6\x30\x5f\xee\x84\x06\x6e\xff\x6f\xc4\xa7\x79\xe6\x6a\xe8\x5f\xb8\xa0\x53\xec\x1c\x1e\xab\xf5\x06\xf6\x93\xf4\xb8\xb4\x7d\xb5\xb7\xa5\xf8\x85\xc9\xc9\x01\x73\xa5\x0f\x61\x24\x36\xd5\xf5\xef\xdd\x60\xcd\x84\xbc\xd9\x88\x2d\x5b\x21\x1f\x8c\xae\xcf\xf7\xbe\x7a\x21\x59\x0b\xa7\x5c\xe5\x04\x42\x76\xc6\xa0\xb0\x9a\x7a\xe8\x50\xfc\x21\x3a\x78\x82\xd2\x0f\x83\x7e\x3d\xb9\x99\xd6\x37\xee\xc1\xac\x12\x20\xdb\x8c\xde\x3f\x9f\x81\xb2\x69\x8d\x0f\x55\x5f\x13\xa0\xca\x87\x4a\x68\xe8\x82\xf3\x1e\x74\xf0\x3e\x2b\x05\xc6\xa7\x9b\x56\x41\x14\xa7\x84\xe4\x0c\x0a\xcb\x67\x74\x22\x8c\x3a\xdf\xc1\x86\x3a\x7d\xd4\xa0\x31\xe4\x66\x98\xbd\x0f\xad\xb5\x3f\x3d\x76\xaf\xb9\x14\x12\xda\xb2\x83\xe5\x62\xd1\xef\x1a\x2e\x37\x90\xe9\x73\x5b\xc2\x3a\x9f\x84\xa2\xd1\x1e\xc7\xf9\xbc\x12\x7b\x19\x8c\x2a\xef\xf6\xfa\x5e\xde\x84\x34\xbe\x9f\xa6\x33\xe0\x01\x82\x61\x09\x40\xd2\x94\xd4\x43\x2f\xaf\xe0\xd2\xbd\x76\x75\xfe\x47\x11\x05\x1f\xeb\xa6\x4c\x1d\xfd\x26\xc2\x00\x34\x4c\xbb\xb1\x75\xf6\xc1\xdd\x0e\xb7\xfd\x57\xb8\x75\x09\x51\xf7\xba\xd0\x46\x9a\x06\xb4\xc1\x6d\x9d\x33\x0e\x70\x5e\x0d\x2c\x10\xb3\x87\x36\x88\xb9\xed\x5e\x3f\x3c\x9d\xeb\x09\x33\xbd\x60\x63\x6b\x46\xbd\x2a\xdb\xd8\x36\xd4\x4a\x0f\x41\x96\x1c\x15\xa8\x06\x57\x17\xc1\xc1\x09\x21\x3b\xd6\xe5\xc2\xfd\x56\x82\x01\x83\x41\x79\x72\x67\xe3\x4a\xef\x46\x5a\x76\x27\x1e\x92\xf1\xd2\xcb\xa2\x1f\x39\x64\x96\xde\x8a\xc7\xac\x23\x91\x8c\x3d\xd6\xaf\xc6\x22\xd4\x27\xaf\x19\x1f\xa9\x23\x9e\xf2\x87\x87\x8d\xee\xe7\x07\x54\x35\xab\x96\xf2\x7d\x67\x54\x08\xfd\xf0\x73\x85\x36\x76\x41\xc4\xa8\x8f\xac\x09\xdd\x2a\x4d\x5e\x81\x7f\xbd\x9f\x1f\x1c\x21\xcc\xb9\x7e\x1c\xb8\xae\xb4\x48\x18\xb9\x18\x1e\x05\x77\xe7\xda\x13\x7d\x66\x26\x6b\x2f\x43\x29\x4f\x66\x59\xde\x74\xf4\x04\xae\x46\xb1\xe6\x46\xff\xd4\xe4\x79\xce\x9b\x3e\xfe\x69\x7c\xb0\xdf\x82\x7d\xf4\xed\x55\x48\x12\xf0\x4b\x4c\xce\xfc\x19\x0b\x36\xd9\x65\x32\x5e\x2b\x02\x05\x2d\x74\xe9\xa7\xd7\xe8\x98\x7e\x08\xb9\xa9\x00\xe4\xc6\xda\x41\x9f\xb5\xfa\x75\xbd\x55\x14\xb5\x42\xe2\x30\xd8\x5b\x7f\x93\x21\xa8\x0a\x42\x47\x1b\xd5\x97\x91\x64\x9a\x25\x07\x15\xe0\x24\x79\xa6\x77\x25\x79\xb6\x62\xe8\xf2\xec\x80\x9d\x8f\x76\x9d\xce\xe7\x69\x8d\x56\x08\xc1\x1b\x24\x42\xc8\xa4\xe9\x16\x7c\xe6\x67\x63\x4e\xd2\x40\x38\x6a\x3b\x74\xb4\xf1\x77\x07\x07\x97\x55\xe7\x97\x3d\xd2\x7f\x8c\xb3\x0c\x1e\x63\x24\x62\x52\x1e\x26\x3e\x87\x52\xf3\xc7\x3b\x1c\xfc\x22\xfa\x38\x20\x0b\x4e\xb3\xaa\x41\x78\x67\x8c\xd3\xd8\x20\xa5\xde\x08\x0e\x62\x5c\x6e\x87\x5d\xef\x95\xf6\xcd\x0f\xce\x1b\x22\x01\x51\xe5\x50\x95\x31\x0b\x33\xe0\x50\x6d\x0c\xc5\x42\x49\xe8\x8d\x7e\x21\xe2\xa0\xbb\xd2\xea\x62\x3c\xea\x03\x31\x1e\x0a\x71\x95\x83\xe7\x5b\xac\x17\xb9\x97\x6c\x0c\xd7\x62\xe6\x26\xe7\xaf\xda\xdf\xbf\xab\xcb\xf1\xc3\x77\xf9\x3d\x11\xba\x5c\xa4\xfd\xbe\x5a\x94\xcb\x18\x98\x74\x8d\x66\xb7\x22\x8d\x6a\xbc\xac\x21\x75\xdd\x5d\xb1\xae\x9d\x85\x7d\xa0\xa7\xf3\x12\xf4\xbf\x05\xad\xda\xde\x7f\x1c\xe5\x3d\xef\xd7\xdd\x08\x8d\x1f\xd0\x5d\x58\x33\xcf\xc1\x1b\x8e\xfb\x75\x04\x6a\xf8\x05\xc7\x58\x46\x41\x1c\x6d\x8b\xe3\xf3\x63\xe5\x7c\xdc\x35\x3a\xc4\x88\x61\x7b\x1d\x8a\x9b\xa6\xa2\xbc\xac\x72\x51\x90\xe5\x17\x98\xf6\x42\xdb\xbd\x1d\x1d\xf9\x9e\xbb\xfa\x63\x54\xb5\x54\x3e\xa6\xc9\x98\xd5\x68\xb1\xc5\xfd\x58\x34\x07\xb9\xe6\x3c\xaf\x0a\x90\x2a\xf9\xd7\x60\x87\xb5\xe7\x45\x4f\xe2\xe2\x6e\xd8\xca\x18\xff\x48\x71\xa4\x21\x66\x14\x7c\x99\xeb\x54\x87\xae\xee\x7d\x05\xde\x66\xed\xb7\x28\x79\xcb\xaa\xb1\x33\xe0\x63\x58\xae\x0e\xcf\x9b\x35\x48\x2f\x02\x7f\x39\x73\xb5\x97\x03\x89\x18\xc5\x1e\xfa\x45\x48\x2c\x28\xf9\x70\x0c\x2f\x15\x3c\x15\x3a\x72\x0f\xf5\xbd\xe6\xa8\x82\x54\x0d\x4b\x6b\x06\x2b\x34\x0e\x45\xb3\x01\x78\xc9\x5e\xbb\x28\xa3\xe1\x10\x52\x8a\x7e\xaa\x93\xca\xe8\xf7\xd3\x94\xab\x6c\x5e\x25\xd9\x16\xe1\x07\xc7\x18\x84\x6a\x9d\x26\x8a\x21\x7b\xb7\xfc\x1d\xbd\x5c\x4e\x06\x42\xcc\xb2\x8a\x4e\xea\x2a\x28\x0e\xd8\xc8\xd9\x66\x7f\x36\x8a\xfb\x30\x44\x92\x3b\x6c\x9c\x3d\x7f\xd6\xcc\xb1\x08\xaf\x33\xa9\x03\xcb\x45\xb9\x02\xd2\x30\x14\x92\x24\x5b\x67\xfd\xbd\xf6\x20\x5f\x15\xf6\x5e\xaa\xe5\x7e\x83\xe7\xe5\xb7\x6c\x2f\xde\xd7\xf1\x6f\xe1\x38\xaf\xc7\x2e\x83\x86\xb1\xb4\x7c\xa1\x5e\xfb\x34\x8c\x91\x5b\xda\x3e\xf8\xfa\x43\x5b\xa6\xf4\xcb\x8a\xca\x83\xe4\x7a\x1b\x97\xc0\x5b\xb8\x03\x76\x2c\x17\x6c\xda\xbc\xa9\x58\x5c\x1b\x63\x1b\x6b\xd9\xe5\xd1\xa9\x41\x93\xef\xdb\x88\x20\xb5\x7f\xc2\x17\x63\x6a\xe0\x1e\x18\x9b\xdb\x0d\x95\x57\x6d\xc0\x07\x5e\x9d\x80\xc3\x58\x9c\x8b\x6e\xbc\x90\xf3\x40\xe8\x26\x9f\x96\x24\x6a\x91\x4f\x2e\x36\xb7\x86\x49\xfd\x98\x00\x0f\xf7\xf9\x70\x95\xa1\x42\x42\x98\x7b\x88\x5f\xc4\xee\xf3\x15\xdc\xbf\x55\x7b\x35\x9c\x5c\xa8\x84\x83\x27\xa7\x3c\xbc\xc8\x2c\xb1\xb9\x7f\x02\x31\x27\x53\x57\x05\xba\x23\x88\x8c\xdc\x25\x4a\xf7\x55\x94\x46\xb6\xa7\x7a\xe0\x25\x86\x4d\xba\x98\xcd\xb1\xf6\xf8\xfb\x23\x6d\xc4\x5f\xa9\xe1\xce\xf6\x1d\x07\x1e\x12\x1b\xfe\x5f\x25\x61\xf5\x13\x03\x01\x00\x38\x90\xb8\x51\xd1\xcb\x99\xe2\x43\xcf\xf5\xde\x02\x2c\x0e\x50\x2e\x0e\xf9\xd5\x48\x19\xbd\x04\xa5\xd7\xa7\x82\xa1\x37\xdb\xe0\x81\xda\xc3\x46\xa0\x7c\x8d\xed\xe3\x92\xf3\x51\x97\xc1\x27\x24\xad\xe5\x75\xd5\xbd\x93\x50\x7d\x27\x8c\x85\x07\x2e\x8b\xa3\x47\x71\xa2\x76\x64\x7d\xeb\x90\xbe\x48\x9e\x93\x17\x8e\xb2\xd1\x2e\x8c\x03\xa0\x8b\xa6\x7d\xc4\xc2\x6e\xd8\x46\x5c\xb9\x8f\x21\x5c\x74\x72\xb3\x86\x60\xfa\x7d\x34\x5e\x87\x37\xec\xf9\xc2\xd7\xcc\x45\x5e\xe1\x36\xa3\x1d\x1f\x2a\x61\x99\xc1\x57\x33\x3a\x9b\x7f\x01\xa8\xc9\xbd\xae\xb1\xcf\xb3\xc0\x38\xe1\x54\x85\x41\xde\xa5\x5e\xdf\xe4\x89\x11\xa0\xa2\x66\xdc\x99\x89\x2e\x93\x42\x90\xe3\xa9\xd4\x79\xc0\xa9\x80\x19\x54\xbb\x06\xb0\x3a\x3d\xc6\x26\x3e\xc1\x80\xc7\x9d\x9e\xe2\xf3\xdb\xdb\xcd\x14\x17\x69\x34\x5d\x3c\xa6\xec\x30\xdd\x9e\x6b\xb8\x8c\xeb\x45\x70\x1b\x79\x8d\xd0\x63\x61\x6a\xc0\xd6\xb2\xcc\xe6\xc2\x04\x12\x41\x35\xea\x77\x77\x35\x39\x73\x92\xee\xa1\x8c\x25\x96\xee\x18\xbc\xa9\xc3\x50\x93\xcf\x67\xd3\x74\xcb\xc0\x77\x34\x9e\xad\x21\x75\xef\x17\x75\x92\x89\x44\x27\xa5\x2b\xd6\xba\x47\x63\x2e\x62\xa5\x9b\x69\xc8\x9b\x04\x89\x50\x55\xd7\x4b\x16\x13\xc6\x0b\x3d\x40\x01\x0d\x17\x69\x23\x8a\xa0\x1e\xee\x93\x2f\xc2\x40\x59\xb3\x23\x12\x88\xcd\x6c\xea\x26\x34\xdb\x3b\x10\xfe\x38\xb6\x90\xc4\xa2\x46\xdc\x15\x6b\xbb\xee\x96\xdd\x48\x69\x69\xff\xae\xa2\x00\xa2\x67\x0f\xf6\xa3\x28\xb2\x0e\xc9\x00\x85\xf8\xa3\x8d\xdb\x05\xfb\xe2\x1d\xd0\x7f\x83\xb8\xdb\xee\xca\xb3\xb4\x55\x8d\x9b\xd5\x57\x7d\xe6\xb5\xc0\x65\xef\xaf\xdf\x4f\xc3\xe0\xd1\x4a\xe5\x66\x37\x6b\x95\xfc\x8d\x1c\x86\x48\x31\x11\x4b\x36\x42\x7a\x91\x5e\x56\xb7\x77\x93\x50\x91\xdd\xab\x8e\x47\x41\x96\x97\x87\x20\xef\x17\xb9\x45\xf4\x22\x16\x54\x26\x0d\x68\x0f\xc2\x55\x1e\x08\x3b\x94\xbe\xba\x24\x9e\x6b\x22\xa2\xce\xbc\x1c\x50\x75\xe4\xdf\x86\x8a\x94\xb4\x58\x5e\xe7\x9a\x7a\x83\x3d\xc9\xb5\x4f\xce\x97\x85\x26\x71\x32\xcc\x4f\xc8\x16\x8b\xbe\xda\x1f\x32\x5b\x93\x15\x0b\xfb\xf0\xdd\x90\xf1\x3a\x44\x80\x83\x5c\xb2\xc0\x62\x3d\x30\xc5\x19\xa0\xd2\x6a\x3b\xd0\xd2\xc5\xe2\x4f\x7e\x95\xcc\x0d\xbc\x8d\xaf\xe0\x14\x54\x9f\xc1\x05\x1e\x5a\xbe\xc8\x58\x78\x44\x95\xa7\x91\x0a\x90\x59\xb8\x2a\x04\xcd\x86\x6a\x1a\xca\xcf\x23\x22\x83\xdd\xda\x37\xc6\x70\x20\x88\xb1\xf8\x92\x93\x14\x43\xc5\x80\x8b\x40\x71\x29\x61\x6e\x6f\xde\xae\x29\xab\xcb\xb8\x79\xba\x95\xee\xf9\xd9\xba\x03\xad\x91\x70\x73\xef\x74\x09\xc1\xf4\x31\xb1\xb4\x32\x66\xa5\x85\xf6\x3a\xb1\x0b\x9d\xfb\x5b\x84\x67\x5f\xd4\x04\xf6\xb5\x6a\x11\xf6\xdc\xb8\x6b\x5f\x9b\xcc\x1f\xdb\xe7\x5c\xd1\xe4\xfd\x0f\x2b\x20\xad\x92\xb2\xb0\x36\xe4\x70\xb9\xfb\x64\x43\x57\xf8\xb4\xc2\x95\x41\x3f\xb2\xf6\x80\xcc\x51\xcd\xb4\xdc\xd8\xb8\xce\x2d\xbd\x21\x3b\x02\xfb\x1e\xee\xa5\x9b\xb3\x69\x07\x16\x66\x85\x43\x1b\xda\xc1\x34\x53\x0f\x0c\x33\xd1\x54\xe0\x26\xb3\x07\xa5\x6c\x16\x22\xaf\x19\xf5\xb1\xb4\xe5\xd4\x84\xc3\xf7\x4e\x97\x4e\x4e\xdc\x81\x13\xde\xd5\x28\x2f\xb6\x9a\x84\xd3\x6c\x17\x72\x83\x56\x8c\x25\xa4\x45\x7b\xb1\x27\x5a\xe9\xdf\xb1\x67\x59\xdc\x59\xab\xce\x4c\x51\x71\xdf\x49\x6d\x8c\xef\xe5\x1b\xcc\xf6\x5f\x80\x31\xbb\x35\x4f\x1a\x29\x09\x94\xfd\x54\x27\x3f\xd6\xba\xf3\xad\xe3\x63\x4e\xe5\xa4\x4b\x85\x8c\xd0\x97\xe9\x87\x14\x6d\xc8\xec\xa7\x3b\x93\x61\x42\xcd\xbc\xf8\xa1\xbb\x34\x53\x12\xaa\xbe\xfb\x3e\xed\x96\x5e\x16\x35\xaa\x25\xd5\xd3\x56\xba\x69\x93\x9f\x57\x68\x08\x2a\xd2\x8b\x49\x87\xab\x5f\x79\xd6\x47\xd7\xc2\xc0\x2a\xe9\xa1\x97\xa8\xe2\x70\x9c\xca\x37\xf0\x4f\x67\xd3\x51\x98\xbc\x2a\x4d\xd2\x14\x65\xe4\x3f\xaf\xec\x3e\x5f\xa1\x53\x27\xa3\x4a\xdb\x38\x0f\x3b\x61\x57\x37\x74\xb5\xa2\xe8\x95\xc1\x79\x9f\x60\x7e\x05\x16\x80\x2d\x0e\x42\xab\xb1\xe0\xe5\xe6\x24\x9c\xd3\xf2\x15\x79\x4f\xab\x4d\xb1\xa0\x44\x65\xa7\xb1\x13\xae\x88\x56\xe0\xc5\x21\xac\xbc\x76\x1b\xed\x06\x7e\x05\x07\x5e\x79\x7e\x1f\x95\xe3\x99\x78\x10\xd2\xdf\x44\x87\x57\xa5\x4a\x55\x6a\xa9\x7d\x75\x7b\xe7\x44\x8c\xd0\xfe\x53\x95\x04\xd6\x5e\x30\xe6\x22\x96\x24\x76\xeb\x9a\xdb\x8a\x07\xbf\x64\x68\x3b\x61\x20\x99\x4e\xcc\x7e\x03\x0e\x41\x70\xc3\xbd\x24\xec\x0f\x87\xe4\x69\x39\xa3\x82\x08\x80\xe4\xa9\xab\xec\x77\x8d\xfc\x5d\x9c\x64\x70\x0f\xbe\x11\x54\xec\xfc\x5f\x29\xfd\x00\x27\x8a\x03\x24\x77\x06\x0b\xe4\xaf\xa5\x74\x54\xd2\x8a\x75\x27\x91\x19\x56\x52\x73\x2f\x7a\x6b\x78\xae\xd2\x82\xce\x70\x87\x73\x07\xa2\xdd\x45\x7c\xc9\x0e\x9e\x02\x7d\x44\x06\x22\x2d\xdb\xc6\x0a\x85\xad\xf0\x89\xcc\xd9\x38\x1c\xf1\xc8\x8e\xb6\xac\xea\xd4\x10\xca\x57\x30\x67\x6b\xc6\x64\x83\x7c\xe7\x59\x42\x6e\x52\x0e\xa6\x3a\x6b\xc2\xb7\x07\x0c\xf1\x62\x92\x94\x24\x71\x69\x6d\xc5\xbf\x1b\x60\x04\xfe\x0c\xf5\x82\x32\xac\x10\xc9\x0f\xd8\x33\xbf\xa3\x07\x08\x64\x82\xf5\x48\xe5\x32\x34\xa4\x93\x62\x14\x08\xe8\xc1\x52\x3e\x85\xc6\x0b\x19\x9f\x54\xd6\x26\xef\x26\x9f\x31\x25\xa0\xd6\xc0\xf4\xa6\x65\x72\x65\x0e\xfc\x53\x84\xe8\x2e\x5a\x77\x5c\x6c\xfd\xdf\x61\x46\x01\xa7\x62\x10\xe3\x72\xb2\x1d\x30\x65\x8f\xf6\xc7\x73\x36\xb9\x12\xac\xe5\xc4\x1b\xda\xd3\x2a\x1b\x70\xda\x9f\x0c\xbf\x05\x1f\x59\x61\x5f\xe8\x86\x71\xc4\xfc\xf8\x30\x99\x20\xb4\xe0\xbe\xbb\x01\xca\x20\xa5\x50\x97\x98\x2d\x8d\x3b\x3e\xa3\xd5\x22\x36\xc6\x64\xf0\x46\x81\x40\x99\x4f\x81\x22\xb9\x3d\xf1\x3d\xdd\x3c\xc0\x42\xf2\x72\xb0\xc5\xa2\x20\xab\xa7\x0a\x65\x32\x98\x10\x06\x6b\x87\x75\x43\x55\x70\xc7\xbe\x94\x7d\x0c\x0c\x5b\x5c\x58\x04\x9d\xba\x12\x8a\x1b\xbb\x96\x03\xec\x7f\x27\xdc\x77\xed\xdb\x15\x6b\x7e\x12\xb9\xc6\x8a\x53\x95\xac\x45\xb0\xa3\xbe\x3c\x61\x18\xe9\xe0\x80\x22\x59\x09\x69\xaa\x68\xa8\x8c\xed\x65\x6e\x8d\xa1\xf1\x26\xb6\x92\xc7\xbf\x15\xe0\x28\x8c\x33\x42\x9c\xb9\x3d\x4c\x33\x62\x26\xe4\xb4\x38\x1d\xa9\x5d\x97\x5c\xa3\xa3\x8e\x92\x01\x8e\xc1\x00\x9f\x46\xf5\xe3\x09\x16\xb5\xf3\x51\x90\xb3\x49\x8b\x13\x79\xbe\xb5\x18\x2b\x56\x2a\x51\xa5\xef\xb7\x44\xc3\x3d\xb8\x94\xa0\x07\xe1\x71\x22\x3a\xf2\x79\x4a\xb3\x0e\x97\x25\x95\x3f\x2f\x9e\xb8\xf6\xbc\xde\x50\xc2\xb1\xe9\xb9\xd0\x00\x50\x96\x3c\x7e\x27\x32\x8f\xf8\x9e\xea\x2c\xcb\x9e\xf7\x42\x94\x5d\x4c\x47\x34\x98\x99\x64\x8c\x5e\xb5\x87\x18\x02\x6f\x15\x7b\x34\x27\x15\x8a\xe0\xb6\xf6\xc1\xfd\x2a\x15\x35\x82\x53\xe4\x8f\x42\xf5\x54\xc7\x98\xf9\xc1\xde\xee\x9d\xf1\xf1\x0b\x3a\xdc\x4a\x00\x99\xc7\xe3\x58\xd5\xbc\x35\x1f\xa0\x42\xe6\xde\x2e\x7f\xa4\x4a\x86\x35\xe5\x4e\xba\xd0\x0c\xa2\xec\x55\xc5\x9c\x10\xc0\xbc\xf6\x45\x3b\xb6\x3f\x62\x87\x55\x49\x3e\xb2\xf3\x8b\xec\x92\xbd\xd8\xe3\x65\x71\x15\x05\xeb\xbf\x3c\xb4\x54\x8e\x92\xd1\xa1\x11\x32\xbb\x89\xea\xc0\x50\x37\x00\x07\x56\x72\x8d\xf3\x3f\x8b\x44\xb3\x4f\xfc\xae\xb9\x4a\x90\xbd\xd5\xcc\xc3\x58\x6a\x69\x9d\xb2\x46\x20\xcb\x52\x8d\x63\x88\xa3\x3e\xb3\x15\x96\xdf\x36\x89\x4a\x02\xd2\xfe\xb1\xb0\x37\x0b\x7e\xc4\x1e\x3e\xdd\x28\xb3\xbe\x46\xc0\x30\x43\x57\x18\x12\xcb\x58\x09\x0b\xa7\x1f\x84\x29\x75\xfa\xf5\x02\xc1\x7c\xfa\x39\xae\x71\xc8\xc4\x53\x91\x8a\xbd\x95\x2f\xd5\x30\x13\x9a\xb1\x7c\x3b\xb2\xe0\x0a\xd1\x06\x17\xaf\x74\x65\x35\x4c\x09\x91\xcd\xbc\xf8\xa9\xff\xd8\xe7\xdc\x4e\x5a\x7e\x66\xc7\x8c\x01\x06\x93\x22\x35\xde\x16\x21\xbf\x15\xc0\x8f\xf3\x3c\xc2\x07\x9d\x49\x6f\x8a\xc5\x24\x1c\x10\x54\x9a\x90\x5e\x13\xa2\x98\x5c\x58\x3c\xb6\xca\x46\x75\x55\x6d\x8e\xba\xd7\xa5\x76\x1d\xe0\xb7\x1c\x5e\x6f\x13\xea\x9a\x55\x5f\x3f\x1e\x1e\x43\xa5\x23\x14\x09\x00\x6e\x66\xed\xcf\xe7\xce\x14\x3c\x22\x17\xac\x10\x9c\x3f\xa6\xff\x39\x48\x66\xd2\x10\xb9\x07\xce\x9d\x5d\x3b\x9a\x7c\x83\xac\xcc\x37\x8d\xb1\xca\xb4\x7f\x55\x0a\x85\x2b\x2c\x07\x88\x30\x2d\xfe\x4e\x62\x24\x27\xa2\x30\x1d\x69\xce\x63\x65\x8c\x9f\x7c\xdd\x02\xbf\xd2\x75\xed\x72\x30\x00\xb1\x4c\xbf\x2b\xf1\x56\xf1\xf0\x77\x8b\xb4\xe0\xf6\x87\x97\x9f\x83\xff\xc8\x32\xe3\x61\x67\xea\x15\x60\x9f\x00\xcb\xd0\x56\x25\x4d\xe6\x12\xa8\xc4", 4097);
*(uint64_t*)0x20001048 = 0x1001;
*(uint64_t*)0x20002a18 = 1;
*(uint64_t*)0x20002a20 = 0;
*(uint64_t*)0x20002a28 = 0;
*(uint32_t*)0x20002a30 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002a00ul, 0ul);
	return 0;
}
