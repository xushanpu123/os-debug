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
memcpy((void*)0x20000000, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000000ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000040, "\xdb\xd5\xec\xf5\xbc\x76\xdf\xb4\x6e\x09\x3b\x5f\x41\x62\x9d\x60\x98\xd6\x2f\xd1\xf7\xf6\x10\x55\xd4\xb4\x4f\xcd\xdd\xcc\xb2\x0e\x16\xbb\xb7\x44\x46\x72\xdc\xb3\x9e\xcf\x20\xcd\x05\x80\x81\x6c\x4d\x0f\xfe\xf9\x32\x7a\xbe\xf7\xff\xf3\x79\xed\x2f\x08\x21\xfa\xe5\xc8\x40\x18\xf0\xf4\xe0\x57\xef\x6d\x3c\x62\x26\x63\x90\x6e\x51\xb8\x25\x80\x38\x8a\xbe\x95\x7e\x90\x2a\x37\xd9\xfc\xcd\x99\x36\x52\x4f\x5f\x74\xed\xae\x96\xd7\x02\x62\xb9\x4c\x05\x8d\xc8\x82\x01\x6c\x5a\xaa\xd1\x5b\xf5\x37\xee\x64\xad\xb0\x58\x65\xca\x56\x6f\x16\x47\x07\x30\xf7\xc8\xe5\xb6\x9c\x28\xaa\xf1\xed\x60\x62\x73\xb3\xc0\xa8\x3f\x20\x6e\x0d\x84\xdf\xff\x01\x4e\xaf\x45\xf6\x04\xe9\x31\x9c\x1f\xf3\x87\x2f\x73\xa0\x21\xc8\x97\x56\x04\x4d\x63\x07\xa3\x03\x9c\xbb\x75\x1a\x44\xcf\x63\x55\xc2\x84\x57\x5b\xdd\xb5\xa1\x90\xce\x06\x3d\x8f\x78\x97\xb8\xad\xfe\x06\x56\x8c\xdc\x5d\x4d\xd6\x15\xc8\x2c\x6a\x22\x29\x34\x7c\x96\x8c\x34\xf1\xe3\x65\xbf\xd8\x5b\x8b\x01\x1e\xd3\x88\x95\x00\x40\x95\xe5\x35\xe0\x90\x98\xf7\xd5\x75\x92\x24\xd7\x05\x68\x16\x62\x4e\x23\x51\xb2\xc4\x9f\x2f\x12\xf8\xed\x04\xde\xfb\x3f\xd6\x50\x43\xc6\xe9\x67\xaa\x27\xff\x6e\x66\x78\x45\xbf\x5c\x75\xf9\x96\xe4\x39\xc9\xd4\xcd\x62\x83\xcf\xf0\x62\xa5\x22\x2e\x2d\xf1\x37\x37\x2e\x2d\xaa\x1d\x33\x39\x18\x6f\xbf\xff\x55\x57\x2c\x06\xe9\x9e\x14\x06\xb0\x78\x1a\x87\x07\x38\x3b\xaf\x42\xbb\x0c\x6a\x7a\xb4\x4a\x02\xfb\x4d\x97\xb8\x3a\x0b\x84\x35\x1e\x86\x6d\x85\x53\x8e\x32\x25\xde\xa1\x26\x08\xb3\x84\xe5\x7a\xf5\x3a\x7a\xeb\x60\x3a\x25\xff\xb7\x24\x44\x25\x5d\x34\xd0\x00\x70\xe7\xc3\x0a\xb2\xfd\x05\xd3\x31\x29\x64\x28\x5e\x6d\xab\xc0\x04\x51\x56\x80\x2b\xb7\x66\x7e\x6c\xf8\x05\xac\x11\x9d\x28\xb4\xd9\xc6\x35\xcb\x23\x32\xe3\x76\xd3\x08\xec\x69\x87\x36\x51\x9b\x37\x1e\x54\x2b\x26\x2e\x36\xac\x03\x85\xce\xee\xdd\x19\x7e\xec\x2a\x62\x6f\x78\x27\xa4\xac\x1d\x60\x5c\x8e\x16\x24\xef\x34\xf8\x25\xe5\x3a\x60\x66\xd2\x7b\x65\xee\x8f\x6e\x3e\x96\xee\x60\x47\x53\xd5\x95\x87\x18\x6c\x79\x2f\x4c\x9a\xde\x3a\x21\xd7\x94\x13\xa5\x8d\x2b\x91\x4b\x4c\x20\x1c\xa9\xd8\x4d\xf3\x98\x38\x9e\xc2\x48\x1d\x76\x4b\xc0\x25\xb6\x30\xe3\x83\x89\x2b\x1b\xb9\x90\x3e\xa0\x95\x1c\xbc\x4f\xab\x22\x65\x11\xc5\x25\x20\x08\x6f\xa8\x36\x9d\x5e\x60\xae\x8c\xf6\x6b\x02\xd2\xec\x5f\x8e\x99\x2e\x32\xaa\xd6\x3d\x44\x9c\xb1\xcb\x5e\x13\xa9\x2f\x35\x9c\xf5\xdd\x28\x4e\xdb\xa6\x2b\xde\x6f\x47\xc2\x4a\x50\xfc\xb1\x1e\xf7\xb1\x22\x4b\x96\x34\x21\xe7\x4c\xb8\x83\x01\xcf\x3a\xd8\x91\xe2\xe2\x6d\xd9\xea\x52\x8c\xe2\x62\x53\x8f\x1f\xef\xf0\x0a\x0d\x98\xee\x7a\x8e\x71\x7d\xc8\xd0\x23\xb3\x26\x09\x54\xb0\x99\x1c\x18\x09\x59\x9a\xca\xc2\x18\x47\x9d\x6f\x50\xe0\xb6\xfb\x6b\xb7\x02\x10\xd2\xa0\x21\x3e\xec\x44\x8b\x1e\x4b\x14\xd1\x2b\x5c\xdf\xe6\x55\x6c\x9e\x39\xf2\x80\x5e\xa1\x25\x9c\x2f\xbe\x84\xe9\xf9\x8c\x68\x8c\x95\xf0\x3c\xed\x98\x5b\x92\x84\x9c\x9c\x53\x41\x76\x28\x1c\xb4\xe1\xc5\x6e\xf8\x51\xf9\xbf\x64\x89\xfc\x62\xfa\xbb\x9d\x74\xf1\x81\x4e\xe4\xaf\x75\x05\xef\x27\xad\x8a\xbb\x06\x60\x71\x1a\x26\x23\x5c\xd3\x96\x92\xc6\x31\x29\xeb\x7b\x35\x97\x9e\x35\x5f\xd3\x17\xe3\x7c\x7f\x87\x75\x78\xcf\xec\xe2\x0c\x42\x1e\x5a\x90\xe5\x18\xf3\xa4\x8f\x79\x40\x91\x42\x24\x05\xdb\x74\x6d\xe7\x1f\x67\x12\x63\x6a\xe6\x0e\xa1\xc4\x73\x19\x38\x87\x87\x25\xe7\x90\xd3\xd5\x0d\x04\xeb\xde\x40\xa6\x06\xff\x1b\xb3\x55\xf3\x26\x46\xfe\x20\xce\x56\x0c\x5f\xb4\xe2\x83\x47\x60\x20\xc3\x74\x56\xc6\x98\x54\xd4\x0a\xba\xda\x28\xe5\xbd\x41\x79\x69\x08\x90\x28\xf7\xfc\xfb\xd7\x71\xa6\x6b\x73\x54\x7d\xa2\xdb\xe9\xf4\x87\x94\x89\xd5\xf9\x51\xfe\x4a\x84\x36\x70\x09\x35\xc5\x6f\x6a\xea\x89\xd0\xe7\x4c\xd4\x2a\x29\xdc\x26\x29\x3c\xf7\xca\x16\xef\x78\x74\x10\x34\x39\xea\xe7\x77\x5f\xb4\x5c\x7c\xfb\xd6\xb6\x33\x68\x0d\x7a\xaf\x7c\xc8\xf7\xb4\x50\x7e\xcb\x9c\xfb\xfe\xea\x35\x83\x26\xc1\x10\x28\xf8\x4d\x44\xd5\xe2\xa0\x25\xfb\x8d\xec\xb2\x63\x17\x21\x04\xaf\x5a\x46\x5c\xfb\x13\xec\x27\x98\x7d\x56\x3d\x23\x05\x11\x9e\xaa\x1c\x5d\xc1\x41\x27\x8e\xb7\x63\x3e\xc2\x5c\xf5\xfb\x0e\x97\xa9\x1c\x40\x5a\x58\x8c\x1e\xbf\x1b\xae\x41\x88\x57\xf0\x6e\x74\x62\x69\x11\xee\x61\x73\x0a\xc2\x58\xd7\xee\xe4\x64\xce\x1c\xdb\x2a\x74\xb2\x54\xc1\x4a\x2d\xb0\x95\xe3\x80\xe2\xa8\x3b\x5e\x13\xad\xdd\x19\x48\xa3\xb9\x58\xee\xa2\xf5\xce\x76\xca\x54\xab\x2b\x1d\x37\x47\xd0\xb5\xa7\x76\x3d\x46\xaa\xd4\xca\x52\x86\x66\x0b\x92\x75\xd3\xe2\x0d\xb3\x4d\xe1\xd4\x76\xc7\x9d\xac\x14\x1c\x89\xf9\xba\x48\x65\x52\xb1\xbc\x0c\xf5\x8f\x89\xf1\xec\xe1\x87\x8d\x52\xf5\x63\xde\x24\xcb\x2e\x11\xcf\xe2\x3e\x5a\xe4\x4c\xeb\xd9\x3d\xe2\xff\x9b\x05\x26\x48\x02\x66\x19\xc6\x5d\xa0\xc9\xc7\xba\x44\x19\x4d\xbd\x66\x91\x29\x85\x61\x26\x64\x14\x0f\x40\x25\xc7\x76\x8f\x6e\xbb\x9a\x2f\x59\xd6\x1a\xfb\xea\x8f\x72\x5a\x32\x07\x85\xab\x35\xd8\xb5\xd3\x91\x2b\x0f\xe4\x29\xa5\x89\xa7\xa7\xbb\x0a\x77\x2e\x83\x28\x2a\x13\x70\x26\x2b\x0c\x53\x29\x45\x35\xc9\x8b\x23\xf3\xd5\x23\x97\x40\x16\xec\xf8\xaf\x09\x2c\x34\x49\x0d\xa7\x5c\x1a\x35\x90\x8d\x66\xa1\xf4\x36\x66\x7e\x95\x46\x85\xfb\xef\x01\xe6\x28\xbf\x4e\xa3\x0c\x16\x88\x87\x64\xd5\x12\x7f\x9f\x0f\x28\xe5\x2e\xe4\xf5\x4e\x97\x0b\x13\xd7\xdf\x75\xfe\x55\xa9\x62\x6c\x34\x87\xf8\xc7\xdd\xff\x76\x17\x19\xf8\x8a\x68\xc2\x0f\x96\xa0\x55\x56\x7a\x80\xbe\x1f\x94\x84\x33\xcd\xca\xb9\x3a\xbb\x14\x1c\xf5\x11\xf6\xe7\xe7\x5d\x6f\x1a\xcd\x7a\x6f\x11\xc8\xf4\x03\xe9\xcb\xb1\xa3\x35\x3d\xf4\x8a\xf5\x36\x45\x9f\xe7\x08\x8d\xf1\x8c\x2f\x99\xca\x74\x0b\x00\x39\xa9\xa4\x90\x67\xc6\x78\xe8\x59\x76\x24\x48\xe7\xfd\xda\xfa\x6b\x90\x7c\x28\x0e\xc6\x3a\x3f\xe5\xcc\x51\xdb\x2c\x84\xda\xa8\x87\x2a\x27\x28\x27\x4b\xb5\x9e\x71\xcf\x75\xea\x53\x9d\x9a\x1b\xf4\xdc\x24\x5c\xb4\x75\x31\x03\xcc\xe2\x71\x78\xdb\x96\x68\x6d\x08\x41\x8e\x33\x44\xbf\x31\xd9\x1d\xaf\xff\x5c\x5e\x2b\x04\x43\xbe\xe8\xad\x89\xfc\xa0\x14\xfa\xd4\x7b\x7b\x4d\xfc\x41\x36\x59\xf1\xcd\x51\xdd\xb6\xb8\x58\x53\xd5\xdc\xb7\x94\x8d\x98\x57\xd8\x8b\x2f\xa7\x9d\xfb\x4f\x3f\xfb\x8f\x15\x31\x09\xac\x0e\xe8\x54\xe9\x8f\x33\x9c\x7b\x20\x42\x30\xa0\xfd\xca\x5f\x49\x78\x15\xe3\xf1\xd6\xec\x36\x9d\xb5\x0a\x43\x5f\xa5\xa6\x9f\x6b\x01\x96\x9c\x66\x64\xa0\x51\x08\x66\x2d\xd1\xd0\x19\x2a\xc3\x4e\xe9\x8a\x9b\xd6\x2d\x78\x00\xd8\xe6\x46\xb8\x8a\xf6\x9f\x44\xe3\x41\x71\x49\x6e\xc2\x47\x40\xec\xf0\xae\xd2\x71\x59\x20\x84\x06\xc4\x64\xd8\xfd\x60\x4c\x9d\x1f\x4c\x78\xeb\x07\xe4\xe4\x2b\x38\x1a\xa6\xba\xac\x81\x37\x97\xe5\xec\xbe\xe9\x15\x5b\x79\xf0\x25\xe2\x0f\x7f\xda\xc5\x58\xf1\x7f\x80\xb0\x73\x11\x61\xab\x0c\xd9\x32\xec\xa1\x33\x4d\x52\x2b\x41\xad\x7f\xb2\xa9\x31\xe6\x88\x26\xe8\x34\x27\xae\x7b\x31\xfc\x80\xd6\x3b\xda\x51\x6b\x65\x86\xbc\xf2\xc0\x32\xd1\x5a\x74\xe1\xf6\x2a\xa1\x65\xb4\x98\x20\x13\x25\x59\x34\x70\x8c\x08\x0d\xcf\x64\x85\x5f\x62\x7c\x8a\x17\x18\xa4\xac\x8b\x3c\x10\xc3\x52\xef\xb0\x60\xa0\x4f\x3a\x14\xb2\x27\x20\x52\xd4\xaf\x18\xdd\x0b\xe0\xba\xab\xcb\xc3\x4e\xf1\x91\x0d\x0f\xab\x0c\xd9\xba\x85\x85\x59\x9e\x18\x29\x0d\xb5\x1c\xe1\xcd\xfe\xb9\x4d\x2b\xe9\x7a\xbf\x3e\xbf\x3d\x45\xab\x48\x38\xba\xdc\x60\xbc\xaa\x27\xba\xca\x89\x8c\xea\xe6\x29\x7d\xde\x8e\xb1\x36\x2f\xf5\x11\x4e\x6e\xaf\xed\xd3\x66\x42\xdb\x86\x49\xee\xba\x30\xf1\x73\xfd\x76\x0a\x56\xeb\xfb\x77\xc2\x7d\x81\xd2\xcd\x61\x40\xcf\xc5\xd7\xb1\x97\x50\xf3\x13\xab\x3a\x6d\xb2\x7c\x05\xf2\xe0\x96\xe0\x15\x9a\x7f\xff\xd2\x01\xa7\x7f\xa1\x51\x2f\xb8\x7a\xc7\x6f\xf6\xb1\x98\x74\x7a\x16\x71\x86\x22\xb9\x39\xf5\x65\x2f\x44\x1b\x47\xdb\x50\xd1\xad\x69\x79\xd1\x68\x5a\x1f\x47\x22\x19\x75\xb8\x9e\xbc\x9b\xf0\x12\xff\xcc\xdd\x6b\xe7\xad\xeb\xfb\x83\x39\x3e\xc8\xee\x26\x08\x62\x29\x2e\x03\xfe\x20\xbf\x9b\xf6\x90\x90\x02\x27\xca\xf8\xb4\x0a\x2d\xc7\x2a\x96\x57\xe1\x1f\xdd\xb9\xdf\x4f\x03\xe8\xaa\x3e\xc8\x73\xbc\x64\x43\xe5\xd1\x7a\xa7\xc1\xdf\x06\x7a\x11\x55\xb7\x05\x28\x3f\x9b\x30\xe6\xb6\x81\xa9\xaa\x16\xfb\x0d\xb6\xa3\x8b\x59\x82\x7c\xe1\x2c\x79\x63\x4b\x48\x3c\xbb\x4d\xe2\xa0\x16\x32\x47\x08\xf2\xd6\xb9\xee\x92\xdb\x6a\xae\x7c\x9c\x2c\x53\x0e\x58\xbd\x6d\x73\xa6\x32\x94\x25\x3a\x73\x3a\x79\x0a\xe9\xa6\x78\x69\x37\xae\x93\x20\xd9\x57\x0f\xd9\x06\xf8\x0d\x52\xd9\x61\xd5\x56\x10\xa2\xe6\x8a\x74\xdc\xb7\x7a\xbe\x23\x0d\x79\xfa\xd7\x9e\x03\xdf\x26\x3e\x01\x1b\xea\xf6\x5f\x4f\x07\x8c\xcd\x98\x63\x19\x90\xfd\xe3\x32\x93\x97\x1c\xf9\x35\x49\x4a\x18\x5c\xf6\xb7\xbb\x5e\xb8\xe0\xe7\x9b\x8b\xbd\x52\xfd\x4e\x1b\x5d\x81\x05\x1e\xc9\x7f\xe9\x2e\xaa\xcb\x03\x8d\x42\x8e\x34\x9a\x7f\x78\xee\xb9\xa1\xc9\x26\x9d\xce\x51\xe7\x7b\x30\x67\x61\xc2\x27\xd5\x58\x4b\x9a\x28\xa8\x17\x92\x92\xc8\x52\x5a\x36\xbf\xc5\x78\xbc\x31\x2a\xcd\x27\xbd\xe4\x07\x2f\xdc\xab\xb9\xc5\xee\xc1\x85\x76\x4f\x3b\x23\xff\x91\x64\x08\x33\x0b\x3d\xb7\xc7\x15\xbe\xd2\x22\xc9\x64\xc4\x53\x80\x63\x02\x15\x4a\xb7\xaa\xb6\x3a\x3b\x73\xd1\x73\x71\x38\xbb\xfc\x4b\x1a\xb7\xd8\x68\xc8\x3a\x3f\x61\xbf\xa3\xb4\xdc\xe6\x0a\x8b\x65\x92\x09\xdd\x2e\xed\xb5\x5e\xd2\xfa\xfa\xac\x34\xbe\xd7\xee\x9c\x0e\x2b\x5a\x1a\xfb\x11\xfb\x9a\xcf\xf9\x0a\x8c\x90\x68\xe4\x4a\x01\xfd\x91\xa0\x8a\xc5\xf6\x55\x15\xed\x3a\x83\xd3\x64\x84\x72\x49\xa0\x55\x6b\x97\xc4\xc2\xf2\xd4\x65\xd0\x53\x02\x89\x8a\xb9\xee\x49\xe2\x0d\xe6\x90\x9f\xf9\xf6\x6b\xcb\x1c\x78\xd3\xdd\x18\xa4\xbe\xc2\x3e\x0b\xa7\xfa\x1a\x1d\x66\x86\x4a\xed\xdd\x63\xe0\x06\x6b\xe9\xd6\x59\x41\x91\xd6\xc7\xb9\x05\x37\xe8\x61\x56\xce\xd6\x9f\xa2\x6a\x25\x0b\x12\x76\x28\xdf\xa1\x47\x7b\xf6\x9c\xdd\x9e\xdd\x5e\x5b\x6a\xea\xc7\x56\x5a\xc4\x69\xcf\x71\x41\xe3\x12\x7e\xff\xc5\x98\x72\x6f\xde\x1b\x1a\x16\xcf\x31\x07\x43\x3e\x27\xee\xe7\x11\xaf\xd6\x7b\x49\x11\xfa\x3b\x22\x15\x73\x6b\x53\xb2\x87\xb5\x7b\x64\x59\xbf\x18\x98\xf1\x1c\xe6\xa6\xb9\x4a\x15\x7c\x7e\xd4\x6d\x4f\x9c\x49\xf1\xf0\xb6\xec\xba\xa7\x35\x23\x12\xb8\x5b\xca\xac\x5d\x7e\x87\x26\x2f\x91\x4a\x4d\x01\xd2\x73\xf3\xa4\x0f\x42\xa0\xbe\xb9\xbd\xb9\xf6\x55\xb3\x37\x63\xe3\xc4\x26\x82\x0b\x82\xb6\x9b\xe6\x63\x31\x02\xab\x69\x82\x0c\xe6\xb3\xd1\x6d\xd1\x3c\x71\x11\x5d\x2e\x69\x84\x7d\x06\x7f\x04\xad\x94\x74\x04\x37\xfb\x63\xfd\x76\x10\xcf\xd3\x8a\x99\xb6\x48\x25\xd1\xd6\xba\x7a\x79\x13\x07\x05\xf7\x95\x34\xd8\x98\xe7\x31\x95\xf3\x92\x13\x4d\x00\x1d\x51\x3b\x81\x55\x86\x57\x3d\xb7\x32\x38\xde\x91\x4b\x9c\xe0\xf7\x36\x8a\x75\x7d\xa1\x42\xd8\x4e\x7a\x92\xca\xfc\x47\x1e\x31\x2f\xb3\x87\x8d\x52\x7e\x00\x70\x7d\x20\xd3\x7d\xfb\x1c\xb4\xd5\xa4\x78\xc0\xb5\x52\x10\x15\x2b\x1d\x29\xd6\x46\x60\xdf\xc1\x33\xe5\x4c\x22\xa1\x7e\x4c\x24\xa9\x5a\x1c\x69\x2f\x6a\x48\xa5\x8f\x8d\x34\x46\x8f\xba\x8f\x12\x54\x32\xb0\xa0\x39\x64\x10\x84\xd1\x72\x83\x95\xde\x25\x40\x61\x43\x6a\xe1\x38\xa8\xef\x76\x33\x58\x57\xd4\x71\x79\x67\xeb\x6e\xf3\x77\xa4\x88\x17\xe6\x25\xb1\x63\xc4\xc8\x29\x94\x9e\x57\x8b\xf4\x13\xc1\x18\x53\x91\x92\xb4\xa2\xa0\x71\xc4\xa9\xc7\xa4\x65\x8a\x80\x00\x37\xb7\x2e\x47\x0f\x15\xf1\x66\x85\xe5\x94\x0a\x4c\xac\xa3\x76\x05\xee\x04\xf9\x54\xe6\x87\xfe\x5a\xcc\xa2\x84\xb1\x97\x68\x16\x81\xbc\xa2\x9d\x6f\x13\xd0\xe2\x4d\xee\x57\x39\x6e\x43\x6c\xd9\x2d\x0a\x61\xf4\xd4\xf2\xfe\xe7\x03\x48\x25\x58\xd8\x03\xb5\x1c\x35\x8e\xcb\x63\xff\x99\x8f\xcb\x48\x1d\xf4\xe2\x40\xaf\x31\x4c\x2c\x6b\x78\x7b\x34\x13\xa6\x1d\xc2\x65\xd1\x55\x4a\xda\xd4\xd9\x47\xb6\x35\xdf\xed\x85\xb7\xcb\xcf\x1b\xb6\x68\x57\xa2\xfc\xac\x85\x16\x56\x94\x28\x98\xb7\xc8\x07\x76\xbc\xc8\x58\xcb\xaf\xf0\xed\x34\x29\xac\x03\x74\x48\xc0\x71\xca\xd7\x3d\x45\xf6\xb5\x34\x85\x1e\x30\x8f\x50\xfb\x60\x1d\x69\xe6\x5f\x4d\x79\xad\xa5\x3b\xf7\xc1\x1a\x0a\x48\x0e\xf0\xa0\x8a\xbc\x4f\x21\x0a\x20\xb8\xad\x92\xba\x91\x61\xdd\x52\xd3\x70\x12\x18\xf7\x94\x3a\x5e\x2c\x2e\x81\xee\xa1\xb4\xe8\xfa\xfb\x25\xf9\x08\x82\x8f\xf4\xe3\xa7\x35\x39\x2a\xf2\x52\x5a\x66\xde\x58\x14\x35\xd8\x1b\xab\x2c\x60\xe3\xb4\x16\xc1\x94\x35\xf5\x96\x62\x7c\x6c\x93\x85\x52\xf4\x3e\x65\x82\xeb\xf7\xec\x90\x9b\x39\x1d\x0a\xba\x6b\x65\x11\x91\x2c\xfb\x22\x6f\x22\x68\x31\x56\x0d\xc5\x7d\xd6\x20\xef\x84\x07\xd1\xfc\xf7\xd4\x94\xcc\x25\x6e\x70\x5c\x50\x4c\x3c\xee\xce\xb5\x7b\x15\xb8\xe9\x00\x82\xf9\x1a\x7f\xf9\x6e\x38\xe8\xbc\x9a\x80\xc8\x6f\x5a\xbf\xe3\x90\x85\x81\xc2\xa7\x5d\x96\x00\x51\x75\x91\x59\xe0\x44\x80\xbc\xe8\xaa\x4f\x57\x57\xa7\x1b\xe0\x17\x75\xbf\xaa\x6f\x67\x4a\x0a\x49\x38\x6c\xe9\x2b\x14\x3a\x0e\xaa\xce\xfb\x56\x67\x6f\x3e\x24\xd3\x45\xe0\x70\x25\xa4\xe9\x94\x63\x9f\x98\xdb\xa6\x4d\x3a\x5a\x44\x21\x8e\x43\x71\x88\x89\x11\x0b\x1b\x8f\x06\xe0\x70\xab\x99\x61\x17\xdf\x34\x9e\x2c\x39\x79\x67\x32\xda\xd7\x95\xa4\xbf\xa2\xfb\xe8\x74\x86\xa6\xee\xda\x4e\x55\x44\xc4\xfb\x63\xc8\xfa\x23\x67\x8a\xb4\xf8\xd7\x2d\x39\xba\xea\xe6\x2f\xf5\xca\x0c\xce\x7c\x94\x84\x5b\x16\xf6\x97\x1f\xf0\x28\xb9\xf1\x51\x4d\xa1\x25\xce\xdf\x61\xfa\xa3\x0f\xf1\x67\x9f\x4e\xd2\xf1\x91\x65\x0d\x13\x3a\x3e\x94\xdf\x31\x85\x9a\x76\xa9\xc4\x67\x42\x5e\x3a\xff\x36\x71\x11\x84\x89\x1a\x66\xe5\x67\xb4\xd8\x8c\x29\x4d\x33\x61\xb0\x32\x76\x69\xd9\x6e\x57\x18\xce\x7c\xa8\xb0\x6f\x1e\x15\xab\xe2\xcb\xb9\x20\x76\xe8\x5c\xbf\x88\x07\x8f\x0f\x6b\xad\x96\x2a\x8d\xb7\xc7\xf7\xbf\x8b\x54\x55\x37\x65\x33\x43\xb7\xb7\x72\x35\x5c\xe5\x19\x9e\x97\xf2\x06\x3a\x75\x8d\x9d\x32\x38\x97\xb4\xbd\xa7\x60\x33\xdb\x50\xee\xf1\x73\xd5\x24\x56\xb0\x12\x25\x50\x87\x40\xe5\x95\xf3\x49\x4a\xeb\x3c\xfc\xed\x8b\x46\x89\x52\x72\x33\xd5\x12\x70\x8b\x4a\xc1\x1b\x01\x6f\xbf\x45\xa1\xf6\xbf\xe1\x26\x95\x92\x1a\x5e\x29\xd3\x6e\x11\xa9\x44\x5b\x57\x72\x71\x5c\x55\x73\x37\x78\xba\xcd\xdf\xca\xf1\x47\x6d\x45\xfa\x08\xae\x5d\x63\xef\xd8\xca\x58\xf2\x71\x90\x5f\xe0\xc3\x80\x4f\x87\x68\x33\xea\xd1\xa0\x6d\x54\x15\xc7\x37\xe6\x52\x91\x51\x6b\xe8\xf7\x0c\x24\x6f\x22\xa1\x95\x78\x40\xcf\xc4\xe2\xbd\x8f\x04\x75\x10\x27\xce\x41\x75\x57\x7a\x31\xd1\xbb\x3c\xfe\x8e\x04\xc4\xba\x09\x3c\x80\x42\xad\x6a\x1a\x3b\x26\xe6\x11\x4d\x88\x48\xca\xb6\x9e\xd6\x63\xf8\xb9\xf6\x77\x18\xc3\xab\x86\xae\x30\xf7\x19\x81\xe2\x7f\x99\x37\xbf\x3e\xb2\xdd\x9f\xa2\x50\x72\xb4\xef\xba\x1d\x77\xe3\x58\x30\xc5\xc2\x0c\xe5\xa7\x83\x4d\x44\xb4\x2d\x86\x31\x64\x44\xf5\x7b\xbb\x7a\x84\x5a\x79\xf8\x14\x67\xef\x86\xc9\x68\x1d\xb1\xd0\x3d\x43\xa8\x0b\xf3\xe6\xfa\x75\xb6\x1d\x41\xee\x3c\x9a\x2e\x84\xcc\x42\xa0\xc2\xf3\xe4\x84\x5c\xd7\xc6\x5a\x16\xeb\xec\xf1\x9c\x28\xaf\x3f\x7f\x7d\xef\x07\x3c\x12\x91\x39\xca\x92\x1c\x4c\xca\x7f\x3c\x95\x29\x71\xb3\x6a\x5d\x06\x5a\x77\x4a\xef\x77\xa7\x3c\x7e\x2d\x75\x30\x2d\x66\x54\xa6\xa7\x61\xfe\x1c\x73\x84\x75\xe1\x56\x3e\x44\xc7\x99\x0f\x3f\xf2\x21\x5e\x44\x4d\x73\xf2\xb7\xb6\xba\x61\xb7\x88\xcf\x85\x23\xbb\x4e\x97\x12\x11\xd3\x87\x29\x45\x55\xf6\x31\x92\x3a\xc7\x4d\x03\xda\x03\x07\xc6\xc2\x78\x09\x1d\x46\x80\x5d\x4b\x1a\x9a\xcf\x26\x5f\x32\x38\x11\xa8\x68\xac\xb4\xa6\xba\x4a\xbd\xab\x6c\x6e\x52\xc6\x69\x07\x10\x15\x57\x5e\x57\x2f\xb8\x5b\x0e\x7e\xa4\x55\x09\xd2\x8d\x8c\x8a\x5b\xdd\x80\x65\xf2\x15\xbb\x38\xeb\x56\x76\xa4\xd0\x62\x2e\x9c\xa0\x61\x57\x77\xda\x86\xcf\xf8\x5e\xac\xaf\x6f\x23\x59\xa3\xd7\xd1\x96\x0f\x82\xfc\x59\xd0\xd5\xab\xb7\xf0\xe5\xff\x16\x63\xd2\xf1\x17\x86\x3e\x3c\x32\xa8\xb2\x39\x83\x8e\x7d\x9e\xc7\xf8\xb3\xb5\x80\x40\xde\x7c\x97\x50\x77\x05\xbc\xd4\xbc\x07\x2f\x9a\x5d\x7b\xfc\x71\x13\x71\x10\x3f\xd6\x9b\x50\x11\x18\x04\x90\xa9\x78\x1a\xb5\xbf\xd6\x9e\x1c\xa5\xa3\xaf\x03\xd8\x62\x14\x05\xef\x33\x7f\xa1\xa7\x41\xbf\x0a\xd6\x7f\xf3\x78\x7f\xfb\x06\x9b\x2e\x9d\x74\x26\xec\x27\x0e\x39\x33\xc9\x99\xe4\xd5\x6e\xf0\xeb\x1e\x62\x17\xc5\x7d\xfd\xfd\xf5\xa6\x6e\x97\xc9\xcb\x39\xda\xaf\x0a\xe7\x69\x04\x23\x89\x08\x37\x4d\xec\x19\x89\x26\xdd\xad\x37\x70\x6a\xca\x09\xaf\x02\x98\x1d\x35\x03\x52\xed\x65\x76\x57\x54\xa2\xfb\x04\xe5\x27\x13\x9b\xd3\x00\x4f\x7b\xd6\xc0\x99\x48\xec\xc9\x4b\xa8\x87\x45\xd1\xa5\x89\xd1\x81\x81\x2b\x3a\x23\x28\x30\xb3\x1a\xeb\x13\xff\x49\x02\xdc\x73\xa6\x95\x06\xd6\xcb\x14\xeb\x79\xc2\x64\x1b\x9b\x82\xc7\x17\x45\x95\x7f\xc7\x6e\xdd\x12\x0c\x0b\xfd\xcf\xf7\x7d\xf3\xea\x49\x17\x85\xe1\xec\xb6\xfe\x4d\x2d\xe4\xfe\xfc\xb7\x32\xf4\x9d\x6b\xcf\x89\x18\xb6\x48\xbd\x11\x16\x5c\x36\x4b\xfd\xc4\x46\x4f\xa4\xde\xc2\x69\xee\x0c\x8f\x32\xa4\xa8\x2b\x40\x05\x80\xe1\x22\x6a\xae\xe6\x9c\xe2\x9d\x42\x76\x50\x81\x4b\xc9\xfe\x3b\xf5\x61\xde\xc7\x20\xf2\x08\x48\x70\x3a\x2e\xcb\x6e\xc3\xdd\x4e\x81\x53\xd3\x12\x81\x49\xc0\xf9\xd3\x4b\x0c\xf3\x54\x67\xb8\x7d\xb3\xc0\xdc\x2b\x7a\xfc\x81\x61\x5e\xa0\x4d\x5b\x60\x17\xf0\x19\xb7\x8f\x94\x93\xbe\x67\x5b\x89\x87\x92\x0c\x1e\x70\x15\xfe\x3b\xde\x01\xfd\xbd\xb4\x1f\x95\xc9\xf1\xaf\xf5\x56\x4b\x14\x58\x7f\x1c\xed\xd1\x46\x19\x70\x1d\x31\x1a\x23\x1d\x71\x50\xc7\x5b\xba\xf8\xb8\x78\x7a\x00\xe8\x90\xdd\x33\x29\x60\x78\x72\x04\x1a\xd4\x60\xcd\xb1\x43\x41\xd3\x13\xfe\xdc\xfa\xef\x25\xac\x04\xf9\x8e\x7c\x44\x39\xdf\x28\xe8\xd7\x49\x3c\x3d\xb1\x6b\x8e\xe8\xf6\x82\x50\xc2\xdb\x53\x7d\x3f\x82\x12\xd2\x2b\x81\xb6\x5b\x67\xf5\x52\xc4\x0d\x3b\xb2\x43\x34\xec\x88\x41\x7d\xa0\x7b\xa2\x91\x92\x4f\x7e\x77\x78\x0d\xa0\x0d\xea\xac\x7e\x2c\x12\x08\xec\x46\xd9\xfc\xf2\xc0\x0b\xdf\xde\xa5\xbe\xb9\x8f\x3c\x56\x59\x7f\xf0\x87\xad\x37\x55\xa1\xd2\xe7\x0b\x05\xa8\x04\x95\x60\x3e\xb8\x85\x26\xfc\x88", 4096);
	syscall(__NR_write, r[0], 0x20000040ul, 0x1000ul);
	return 0;
}