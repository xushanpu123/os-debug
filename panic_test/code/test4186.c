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
memcpy((void*)0x20000780, "./file0\000", 8);
	res = syscall(__NR_open, 0x20000780ul, 0xa8dc2ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200002c0 = 0x200007c0;
memcpy((void*)0x200007c0, "\xbc\xf9\x6c\xf0\xad\xe3\xe4\xd3\x3d\x86\xd2\xed\x32\x55\x69\xcb\xc3\x35\xc4\x5a\xbb\xa9\x84\x87\x29\x1e\xb2\xcd\x0b\x7f\xf6\xb4\xe9\xc1\xcb\x91\xda\x33\x41\x91\xc7\xb6\xc3\x40\xc3\xe0\x27\xc5\xb5\xac\x71\x45\x78\xb7\x43\xa1\xf8\xd9\xba\x27\x65\x69\xfb\x45\xdc\xe5\xf7\x55\x42\x9a\x2c\x42\x5d\x89\x67\x69\xd4\x16\x93\x6b\x24\xc4\x54\xad\x6f\x75\x5c\x53\xad\x90\x3a\x54\xad\x5c\xe8\xe2\xa1\x14\x7d\x4d\x16\xd4\x33\x2e\xcd\xca\xa0\x94\x05\xc2\xb3\xd2\xea\x03\x29\xa7\x67\x1d\x53\x75\x46\x8e\x84\x07\xee\x39\x2b\x29\x77\x91\x94\x53\x3f\xaa\xb7\xaf\xf3\x1a\x14\x7f\x0b\x6b\x20\xd3\x08\xbd\x4e\x01\xc2\xed\xa7\xd8\x5c\x57\x5d\x91\x7a\x35\xef\xdf\x6b\xda\xf1\x24\xb9\xd9\x10\x99\x43\xf0\x0a\x35\xf5\xfd\x34\x27\xce\x7e\x48\x1a\x25\x00\xa1\x3d\x27\xc2\x78\x3f\x27\x1b\x17\x86\xf5\xf5\x67\xaf\x0e\x82\x90\x9c\xa0\xff\x73\x32\x73\x0c\x9d\xa6\x01\xf8\x08\xe8\x00\xc6\x1f\x26\x7c\x68\x7f\x9d\x50\xbe\x68\xb2\x79\x66\xee\xce\x5c\xa7\x13\xb6\x35\x5c\xb0\x9f\x5b\x08\x23\xab\xb4\x87\x58\xcf\x49\xab\xa3\x40\x6e\x8a\x90\x67\x96\xac\xb9\x6b\x28\x40\x0a\x63\x08\xbb\xaa\x24\xec\x7c\x28\xd2\x50\xd3\x0f\x57\x88\x49\x15\xda\x6e\xa5\x66\xeb\x43\xed\xc3\xa7\xad\xe7\xa2\x57\x58\xe1\x29\x3a\xe1\x73\xd6\x0b\x6c\x61\xea\x30\x5e\x35\x3d\xb2\xae\xb1\x0e\x85\x6e\x15\xdc\xc5\x49\x77\x3a\x2d\x65\x10\xd9\xdc\xaf\xe0\x72\x29\x27\xfc\x93\x23\xd7\x80\x7c\x39\x36\xb8\xb0\x1c\x7b\xf6\x3b\xf2\x20\xda\x86\x5e\x8e\xab\x42\x8a\xc2\xd5\xe5\xb3\xd8\x37\x77\xe0\xf5\x36\xda\x95\x7b\x02\x2b\x5d\x6d\x32\x58\xe4\xbe\x91\x5d\x1a\xe0\x57\xf7\x03\x2d\x42\x53\x0d\x07\x07\xd5\x6f\x79\xef\x3d\x48\xb7\xf3\x25\x66\x91\xb3\x6d\x81\x25\x91\x05\x7d\x4f\xd9\x46\x0f\xce\x74\x04\x92\x7b\xf2\x19\x0d\x3e\x60\xa0\x77\x4e\x4b\x54\x69\xef\x30\xa1\xc9\x3d\x74\x55\x5f\xd1\xca\x3b\xd7\x33\x12\x55\x44\xcd\x7a\x4d\x94\xd0\xac\x45\xd4\xe4\x41\x7b\x86\x0e\xf3\xfd\xf7\xb5\xab\xb0\x48\x37\x7c\xc4\xce\x0b\xad\xf9\xf2\x1d\x3d\x04\x8c\x38\x2a\x5c\xfb\x46\x81\xc0\xc4\x8d\x73\x27\xc9\x62\x2e\x4a\xd5\xad\x67\xdf\xbf\x3f\xde\xfb\x00\xba\xe4\xd9\x2b\x3b\xd1\x58\xae\x38\xde\xf0\xfe\x6c\xcf\x26\xca\x1e\x0b\x96\x87\xab\x83\x93\xdd\xec\x96\x29\x0d\x30\x63\x53\xae\x98\x73\x64\x3f\x46\xf3\x4f\x28\xa2\x14\xeb\x08\xa7\x63\x6f\xf7\x6a\x42\x67\xa2\x9f\x8b\x3d\x71\xe7\x7b\x95\x1a\xa6\xe1\x81\xba\xd1\xca\xde\x6a\x9e\x89\x00\x0f\xe1\x7e\x83\x23\xc4\xe5\x2c\x66\x22\x2d\x50\xbe\x95\xee\xc4\x47\xbc\xc1\xc4\xb9\x6f\xdc\x53\x8e\x75\x3c\x47\xad\x6a\xc5\x26\xee\x91\x6d\x18\x53\x00\x25\x98\x90\xcb\x59\xa2\x6c\x15\xe8\xe7\xe9\xd5\x05\xad\xc3\xe4\x60\x99\x75\xdf\x2c\xa1\xa9\xe9\x9d\x91\x32\x8a\x7a\xbd\x03\xb4\x2d\xcf\x36\xdc\x63\xe7\x42\xa5\x8a\x23\x38\x4e\x21\xe9\xbf\xb9\xf1\x82\x17\xed\x2f\xcc\x8a\x1c\xea\x35\xb5\x00\xfa\x95\x1e\x40\x4b\xdb\xd3\xeb\x21\xd7\xe2\x62\x47\x2e\x89\xaa\xfb\xb6\x62\x1c\xe2\x5b\xee\x24\xd1\xcb\xc4\x3b\xa2\xf8\xc3\xdf\x4c\x84\x4e\x5a\x77\xc8\x02\xbb\xb9\xad\xdd\xeb\xb1\x60\x6c\x18\x00\xa9\x1b\x5e\x71\x41\x4a\x96\x97\x14\x66\x8a\x38\x9b\x65\x14\x09\x20\xf7\xd6\xbc\x84\xb3\x08\x37\xd7\x71\x83\xb1\x91\x44\x37\xf0\xd9\x50\x15\x5b\x00\xcb\x2f\xad\x47\x30\x86\xb1\x2f\x0d\xc2\x55\x3f\x3b\x16\x9d\x70\x75\x36\xa9\xc3\x45\x06\x2d\xf5\x12\x87\x49\x77\x33\xef\x76\x05\x1c\xc7\x52\x32\x64\x05\xf3\x9e\xb9\xde\x8d\xd3\x51\xd0\xa8\xa3\x7b\xc9\xaf\xf9\x59\x34\xad\xa2\x5e\xaa\x32\xb1\x8c\x08\x1a\x96\xe2\x04\x07\xe9\x69\x9b\xa8\x73\x3d\x38\x07\xa1\x12\x82\x25\x7e\xd2\x78\x39\x7d\x58\xd1\x8d\x57\x5d\xb6\xf4\x34\xb8\x7f\x75\x84\x88\x6f\x46\xd8\x05\x45\xed\xbd\x0d\xf2\x60\x02\x33\x44\x00\x44\xea\x3a\x2f\xa8\x70\xed\x74\x29\x2f\xaa\x3c\x92\x05\xcf\x29\xf8\xe8\x64\xda\xb0\x2b\xb6\x2b\xc2\x55\x8e\x3b\xf0\xf1\xb1\xa7\x08\x46\x5c\x82\x84\xf9\x8b\x12\xd7\x72\xa6\x60\x85\x2a\x65\x9e\x5d\x2e\x6b\x19\x16\x95\xf3\xb4\x10\x92\x4e\x2a\xe6\x32\x37\xf3\x1e\xe8\x27\xc7\x0b\x7c\x6b\x8f\x13\x5d\xb2\x93\x1e\x6c\x9f\xbc\x85\x12\x8b\x9b\x3d\x53\xd9\x9e\x39\x4f\x64\x30\x59\x44\x0d\x5e\x6d\x1e\xc3\x09\x84\xa4\xfc\xb3\x83\xed\xfa\xb9\xe2\xff\x51\x85\xd5\x35\x34\x14\x9e\x6b\x6f\x49\xcc\x40\xc3\x10\x04\xd7\x5d\xb2\x7f\x48\x51\x6b\x07\x8d\x55\xc7\x81\x52\x59\x3a\x6f\xb1\xab\x44\x3d\xaa\x44\x0e\xb4\x27\x4a\xca\xc1\x60\xb8\x3b\x82\x55\x42\x2f\x68\x3f\x2c\xd0\x24\x95\x7b\xdb\x1b\x1f\x3d\x63\x1f\x7d\xaf\x6c\xfd\x41\x40\x72\x80\xf7\x57\x5b\x71\xc3\x8c\xd5\xdd\x48\xe0\x34\x4a\xe9\x5e\x43\xd9\x41\x57\x03\xeb\x53\x65\x8e\xd5\x0b\xce\x94\x77\xae\x28\xc2\xa1\x17\x97\x39\x3a\xdb\x88\x07\x2e\xf7\x0d\xc9\xde\x23\x56\x2b\xd1\x4c\x97\xe6\x7d\x21\xa5\x17\xc7\xe1\xf1\x7e\x26\x38\xb7\x52\x65\xb9\x2a\x2a\x3b\x90\x3b\xa6\xf3\xa0\x88\xa6\x3f\xa2\x93\x05\xcd\x84\x89\xd9\xcb\xa9\xa3\x1c\x6d\x32\x97\x98\xae\xdc\x5d\x9e\x6f\xee\x64\x3d\x9d\xcb\x44\x95\x44\x39\x68\x3e\x21\x63\x2b\xcb\x7d\x50\xb6\xf3\x9d\xaa\xd0\x24\x56\x96\xd2\x33\x62\xda\x11\x3b\xed\x22\x82\x8c\x21\xb8\xf1\x29\x84\x49\x0f\x91\x05\x80\x5c\xbc\xd8\xab\x84\xb7\xfb\xcc\x53\x12\xe3\x55\x0e\x8a\x81\x93\x24\x6f\x74\x76\x41\x92\x7e\xa5\xcb\xca\xe7\x1f\x92\x37\x4d\x50\x6b\x2e\x08\x53\x3b\xc0\x88\x0e\x54\x11\xf4\x3d\xa5\xa7\xd4\x4d\x4b\x64\xb3\x6d\x41\x8d\xe6\x0e\x68\xb7\xbc\x96\x2c\x21\xbc\xb2\x99\x1c\x56\x44\xf5\x92\x82\x1a\x62\xac\xcf\xbd\xc8\xe0\xc9\x6d\x78\x1d\xf6\x24\x77\x8b\x7c\x81\x4d\xee\x59\xaf\xfd\x87\x17\x28\xcb\x1c\xf0\x17\x6e\x78\x54\x6b\x5b\x6f\x9e\x9e\x38\x9e\x1d\x8c\x10\xf7\x95\x60\x38\x74\x9e\xfa\x6b\xc1\xb2\x79\xf5\x77\x6e\xb9\xfb\xed\x4f\x6c\xa8\xb7\xc7\x8a\xc4\x36\xf0\x3c\xb9\x21\x7e\xe1\x81\x72\xa9\x63\x79\xf3\x69\x00\x5c\x85\x86\xab\xc7\x52\x47\x7f\xe6\xff\x34\x25\xc8\x28\x7d\x71\xcb\x61\x57\x43\x52\x0e\x95\x0e\xd0\x9d\x5b\x58\xfd\xc6\xf3\x40\x76\xe4\x52\xdd\x7e\x61\xf4\x5d\xe2\x7b\x97\x6b\xe6\x1f\x3c\xc3\xd9\xb2\xda\xe2\x17\x8d\xc3\x06\xf5\xc6\x69\xd3\x78\x27\x93\xa9\x37\x77\x6d\x3d\xdb\x3a\x13\x77\x8b\x57\xf7\xa3\x9b\x07\x9b\x47\xfe\xf5\x21\x4d\x54\xff\x20\x26\x6b\x14\x34\x19\xf9\x2a\x31\xd5\xb1\x71\x36\xd9\xbc\x51\x05\xdb\x13\x8e\x94\xbe\xaf\xda\xe9\xd8\xad\x25\xe2\x04\xbe\x93\x19\x74\xc6\x35\xc2\x1d\x99\x41\xc5\xee\x2c\x55\x46\x28\x56\x53\x74\xbc\xc2\xcc\xe0\x62\xea\x6a\xc1\x28\xe1\x5e\xcf\xb6\x49\x8b\x20\xb1\x2a\x1c\x5a\xbf\x7e\xfe\x16\x16\x4a\x44\x03\xa5\xe5\xad\xee\x31\xcf\xcf\x5d\x3e\x80\x18\x00\x8c\x6f\xed\xe1\x21\x34\x8a\x4f\x28\xcb\xb0\xb2\x49\xf8\x05\x24\xd0\x44\x48\xdf\x06\xb1\xe7\xc8\xf1\x34\x84\x9a\x62\xb3\x8b\xe8\x2e\x15\x6c\x5a\xf8\x6c\x83\x99\xa2\xc4\x08\x6f\xc9\xb6\xa7\xc8\xb8\x9b\xb4\xb4\xac\xfd\xa5\xbc\xe1\x96\x95\x9b\x91\x14\xbc\x62\x98\xb3\x4d\xc1\x03\xff\xca\xad\xa3\xcd\x99\x59\xbe\xb5\x74\xf8\x8b\x9a\xc8\x0d\x4d\xee\x39\x6a\xd0\x4d\x89\xff\xfe\x2a\xfb\x45\xc2\x3a\xcb\x37\x31\xf0\x05\xfd\x8c\x8d\x9b\x26\x7e\xef\x89\x89\x36\xac\x4d\xb6\x9a\x73\xbb\x4d\xc1\xde\xf5\x33\xd7\x33\x18\xe5\x31\xa4\x96\x62\x01\x49\x7c\xa3\x34\xcf\x62\x72\xef\xc7\x58\xe3\xc9\x98\xb7\xfb\xba\x16\x62\x76\x21\x49\xce\x07\xc1\xd7\x63\x7b\xf8\x38\x0c\x82\x3c\xd2\x52\xe9\x3b\x3a\x2d\x6e\x8f\xdd\xd5\xe2\x23\x4f\x2c\xed\x2f\x16\x33\x22\x77\x52\x3c\x60\xcb\x00\x77\x4b\xd6\xec\x79\x52\x28\x57\xe3\x8a\xbd\x2e\x79\x48\xbe\xe9\xeb\x6b\x25\x7f\xa0\xc6\x6a\xab\xfe\x36\xad\x7a\x94\xb9\x4b\xf7\x64\xeb\x69\x0a\x99\x88\xde\xc0\x04\x2f\xd2\x5b\x31\xbb\x44\x9f\x88\x36\x05\xbd\x25\x98\x38\xf4\x6b\xee\x4b\x7d\xa8\x6d\x10\xb3\x1b\xa8\xe7\x3b\xa0\xdb\xd5\xd8\x47\x87\x00\x6d\xbd\xf1\xe0\xcb\xa2\xd1\xf1\xb6\xf4\x37\xf1\xb3\x39\x0a\xac\xe4\xa4\x5b\x36\x01\xf3\xd2\x78\xe3\x28\x9e\xed\x91\x33\x7a\xec\x60\xa9\xfa\xdb\xf5\x31\x30\xb4\xf9\xfc\x8b\xed\x30\xb9\xd3\x04\xd0\xcc\x5c\xaa\x89\x3e\xb6\x1c\xca\x90\xf2\x59\x53\xd2\xf2\x07\x46\x49\x03\xdc\x1f\xfb\xcb\xca\x50\x70\xe4\xee\x24\xbb\x7c\x46\xbf\x23\xde\x4f\x51\x37\x8e\x5a\x38\x6a\x86\xd6\x2d\xb8\xa6\xe2\xee\x44\xad\x77\x8a\xa7\x7c\x93\xb0\x93\x7b\x35\xb8\x07\x2e\xc9\xa8\x7d\xb2\x95\xf7\x44\xf5\xe4\xa5\x4a\xec\xef\x38\x91\x47\x5d\xb8\x73\x56\x6c\x4b\xd2\x13\x51\xf3\x57\x0f\x57\x79\xb8\x36\x9f\x21\x1f\xcf\x1b\xa7\x8f\xe2\xa8\xff\x88\xf3\xb5\xdc\x95\x44\xf8\x93\xf2\x31\x81\xb4\x40\x63\xd7\x7e\xbe\xb8\x4a\x8f\x19\xd2\xd0\x3b\x6e\x52\x37\xb7\x5a\x46\xad\x85\xa7\x70\x3f\x3d\xab\x41\xf2\x14\xae\x95\x5e\x92\xf3\xb8\xc2\xbb\x3e\x56\xd1\x89\x4b\x40\x6c\x38\xc6\xe5\x2e\xde\x25\xae\x44\xd8\x59\x82\xde\xf7\x6e\x04\x2b\x73\xe3\x67\x31\x72\x8a\x0e\x22\xe0\x77\xd7\x63\x18\xd4\x7b\xbb\x29\x53\xd5\x56\x4b\x3b\xcf\x35\xfb\xdf\x72\xec\x37\x15\x91\x59\x5f\xb1\xc2\x66\x3b\xe4\xf1\x5a\x59\x72\x79\x97\x26\xde\x23\x9b\x8e\x01\x7b\xa1\xbb\xb4\x7a\x7f\x17\x98\xf8\xf6\x84\xcd\xae\xd1\xe1\xa7\xc2\xf5\x78\xc7\xe2\xfe\xce\x29\x51\xf4\x41\x06\xf0\x3d\xb9\x40\x0c\xe5\x46\xb6\x59\x11\x12\xc8\xb2\xd4\x78\x50\x6b\xfe\x21\x2a\x8c\xda\xa8\xa0\x55\x00\x61\xcd\x35\xd7\x07\x42\x03\xc2\xd6\xa4\x88\x83\xf5\x1f\x87\x3a\xb7\x32\x91\x19\x78\x73\xe4\x48\xf6\x72\x6d\xd6\x54\x76\x07\xd3\xa3\x17\x71\x37\xbd\xf5\xa9\xdb\x66\x88\xa6\x61\x02\x73\xd5\x91\xff\x0b\x8c\xe7\xb8\x51\xa9\xf3\xd2\x17\x47\x68\x3c\xbf\xfc\x90\x98\x59\xf6\xe9\x94\xf4\x72\xdd\xf3\x54\x05\x6b\x29\xad\x6b\xc6\x9f\xb4\x5a\x0f\x21\x27\x5c\x03\x38\x7b\xde\x84\x8f\xa0\x1a\x7c\x70\x0d\xd5\xe2\xee\x46\x65\x91\x82\x93\xf1\x5c\x7c\xfa\x02\x9e\xa3\xb5\xef\xa9\x50\x8c\xa6\x5f\x6b\x62\xec\x42\xc0\x40\x90\xf3\xfa\x3c\x41\xe3\xfa\x8a\x6c\x20\xe8\x48\x85\xc8\x77\x78\x24\x5d\x58\x1d\x40\xa0\x4e\x2d\x80\x10\xcf\xab\xb5\xac\x86\xc1\xef\x46\xfb\xd3\x14\x99\x40\x6e\x8f\x4e\xf9\x7a\xa5\x3e\x94\xed\x82\x46\x2f\x63\xb3\xa9\xb6\x01\x0f\xb6\xe9\x97\xe2\xb3\x2c\x2d\x5f\x1f\x61\xe8\x0e\x88\x1f\x59\x8c\xe3\x96\xc0\x7d\xc2\xde\x86\xbb\xdd\xd3\xac\x9a\xd1\x7a\xb1\x9b\x51\x14\xd6\xc0\x64\x8c\x26\xd9\xf9\x1f\xdd\x03\xa3\xf4\xba\x7a\x28\x65\x9a\xf2\xb9\x5a\x63\x30\xec\x98\x56\x07\x11\xf9\x70\xd8\x4b\x6f\x74\x84\xac\x6d\x7d\xbc\x17\x37\xaa\x01\xa7\x3f\x66\x9c\xe8\xa6\x8e\x3b\x3f\xf6\x51\x87\x90\xa1\x3c\xa2\x0e\x1f\x8e\x42\x70\x7f\xc8\x84\x53\x26\xc7\x10\x3e\x2f\xee\x23\x45\x53\x83\x20\xc9\xec\x52\xa8\x6f\xca\x27\xee\xea\xfc\x42\x05\x02\x6b\x38\xe2\x09\x84\x61\x64\x9b\x92\x32\x27\xcf\x8d\x8a\xf8\xbc\xa1\x8b\x56\x7a\xbf\x2e\xc2\xd1\xa7\xf3\xdc\xc6\x20\x8a\xb3\x4a\xbb\x87\xfc\xb8\x27\xf6\x31\x24\x66\xf4\x77\xbb\x36\x83\xa2\x7e\xcb\x9d\x6d\x1b\x27\x17\xca\x2f\xbc\x1e\xfa\x52\xe7\xf6\xe3\x03\x9a\x95\x29\x54\xd5\x2f\x0a\x7b\x03\xf8\x8e\xb2\x32\x1e\xeb\xa8\xb0\x7e\x55\x4e\xdd\x1e\xf7\xe4\x86\xb6\x25\x35\x3e\xe7\x2b\x7a\x74\x42\xe8\x25\x94\x3f\xb5\xd1\x9a\x8a\xc9\x17\xb4\x68\x74\xba\x59\x84\xcc\xa1\x2f\x9e\xc6\x5d\x3b\x68\x69\xef\xce\xef\x88\xf1\x2f\x85\x67\x23\x40\x2b\xfc\x5a\x7f\xf8\xc5\x00\x04\xe8\xae\x43\xc3\x88\xd2\x4b\x24\x3b\xce\x9a\x0d\x73\xda\xe4\xc6\xd2\x27\x4b\x34\x61\x4c\xa1\x91\x2b\x1e\x10\xb5\x96\x48\x77\x1c\x2a\x7e\x24\x1c\xbb\x1d\xd4\x17\xf9\x05\x9e\x8a\x3b\x6b\xb1\x53\xa2\xbb\xfb\x11\xf8\xe5\xee\x0c\xcd\xcc\x65\x43\x68\x86\x10\x64\x6f\xba\x20\xe5\x75\x2c\x01\x9e\x45\xcb\xd0\xe7\x3d\xb2\xb7\xf6\xaa\x97\x39\xbc\xd1\xbf\xfb\x9a\x69\xf5\x76\x23\xe7\xac\xe0\x02\x1a\xd4\xc9\xec\x42\x2a\xd1\x72\xfb\x6a\x40\x07\xa0\x46\x28\xd7\x27\xe5\xa8\x12\x01\x54\x01\x70\xae\x48\x20\x36\xac\x25\xbc\x14\x4d\x37\x46\x09\x5b\x76\x9b\x4a\x91\x46\xab\x52\xec\x44\x3a\x98\x40\x5f\x70\x0c\x0c\x8a\x78\xa5\x4c\x09\x6a\x71\xfc\xf4\x3e\x93\x56\x62\xba\x8c\xbf\x49\xd3\x5c\xaf\x7a\x27\x44\xee\x2f\x2f\xee\xc8\x9c\x1b\xf2\xaf\xe5\x64\x8e\x95\xed\x1f\xa5\xc4\xf2\x9e\x69\x58\x2e\xa0\xf8\x44\x70\x90\xdc\x7c\x91\x0d\xef\xd9\x8a\x8d\xbe\xbe\x06\xa4\xfa\x5a\x71\x27\x66\x25\x87\x34\xa3\x83\x47\xbd\x8f\x35\xd0\xbf\x6f\xe7\x1f\xdc\x79\x99\xaa\xde\x7e\x06\x50\x69\xcc\x0e\x77\x96\xe1\xb5\x88\x05\x1d\x0d\x23\x56\xfd\x55\xe5\xda\xfc\xa4\xd1\x77\x37\x95\x16\xe9\xb7\x32\x88\x79\x54\x81\x96\x69\xb6\xf4\x91\xfe\xcf\x69\xe8\x3d\xad\x11\x7e\x8f\xdb\x9e\x67\xd5\x21\x08\xb6\x22\xd6\xa0\x82\x35\xea\x17\xf3\x95\x88\xda\xf3\xa0\x94\x5d\xcb\xcc\x51\x9c\xcb\xed\x80\xcd\xa6\x8b\x60\x7a\x81\x67\x85\x68\x3c\xfc\x6a\xa1\x47\xdf\x68\xb1\x0c\x61\x53\xc6\xaf\xb6\x74\x18\x19\x70\x22\xf5\x2b\x15\x99\x81\xf8\xf8\xfd\x46\x5c\x14\x9f\x05\x33\xb6\x92\x49\xb4\x55\xbc\x17\x2b\xd4\xfd\xdf\xc5\x7f\x8c\x9d\xeb\x4e\x7b\x88\x94\x3e\xa7\x32\x60\xf6\x67\xe1\x9a\x66\x05\xda\xcb\xd9\x63\x8d\x2a\xba\x9c\x63\x68\xa2\x84\x66\x98\xbe\x13\x1c\x5e\x30\xb7\xe1\xa6\xe5\x10\xcf\x3d\xb3\x28\x0e\x03\x7c\xe4\x99\xe7\x9e\xd6\xa8\xf4\x31\x07\xe1\x8b\xff\xbc\xf8\x8c\x95\x7b\x36\x64\x81\x49\xce\x30\xc9\x9b\xe1\x02\xa0\xee\x54\x2c\x5e\x1e\x11\x0e\xf0\x9e\x12\x79\xd2\xb7\x36\x05\xb7\x46\x94\xae\xee\xe0\x6f\x5b\x99\xd8\xdb\x4e\xf5\xf1\x41\x18\x23\x40\x17\xa8\x18\x18\xb6\x7a\xa7\x30\x51\xd5\x31\x55\x28\xf6\x2e\x27\x80\x4a\x67\x48\x43\x7f\x8c\x47\x6b\x9f\x46\xd2\xab\xbe\x10\xd3\xf6\xc1\x87\xec\x6e\x8d\x43\x33\x4f\xd1\xb0\x1c\xe7\x3d\xdf\x75\xf8\xa8\xcc\xd1\xdf\xa8\x6b\x0c\x61\xe9\xec\x19\xc1\xae\x8c\x71\xe3\x34\xc8\x88\xa2\x9d\x41\x7d\x25\xb7\xc6\x5b\xa4\xf5\x05\x45\x00\xd4\xa5\xbd\x4c\x82\x2b\x65\xbf\xc5\x16\x74\x9f\xe8\x8e\x20\x52\xf2\xa8\x09\x09\x17\x24\x51\x1d\x3e\xfb\x8c\x47\x2a\xe1\xf4\xca\x69\x50\x56\x0d\x59\x6b\x81\xd1\xc4\x87\x0b\x65\x0b\x8b\x59\x19\xc7\xb4\x9e\x22\x5b\xdc\xf8\xf4\x40\x50\x51\x68\x1b\x06\x6b\xd8\x2b\x22\xe6\xc7\x51\x67\x18\xdf\xea\x46\x81\xda\x28\xe1\x6a\x45\x56\xe2\xaa\x0a\xc1\x08\x09\x98\x5d\xab\x38\xad\xd1\xeb\x31\xd2\x93\xee\x08\xc1\xd6\xdc\xd2\x49\x7b\x36\x87\x68\xc8\xab\x0b\x0a\x77\xfd\x2d\xcd\x3d\x44\xa5\xe3\xe3\x45\x2b\xdb\x9f\x24\xf0\xdb\xc6\xfa\x26\x7b\xd2\xa4\x70\x96\xa4\x8f\x9a\xfc\x57\xae\xe7\x68\xd9\x8f\xb0\x4f\x00\x51\xc4\x73\x9f\xa2\xc5\x05\x21\x0a\x41\x34\x7d\x03\x86\x03\xba\x20\xf1\xf3\x14\xe9\x80\xff\x56\x3c\x64\x6c\x50\xc3\x3b\x18\xb5\x64\xf5\x4e\x76\x98\x86\x37\xec\x6a\x10\x84\x51\x40\x58\x78\x26\x87\xb3\xba\xc9\x7a\x7d\x5f\x93\x67\x2a\x1b\xbe\xde\xbe\xaa\xfd\x0c\x4b\x91\x3e\xfb\xf6\x4c\xd2\x02\xfe\x02\x26\xb0\x50\x89\x89\x7f\xf3\x19\xb4\x5f\x46\x09\x06\xe2\xa3\x67\x96\x12\x24\x00\x80\xa1\xaf\x7d\xf1\xc5\x68\xaa\xce\x9d\x65\xfc\x70\xf2\x87\x8e\x46\x97\x9c\xef\x4c\x1e\xeb\xe2\xd8\x99\x89\x8c\xbd\x63\xdb\x8d\x0c\xf1\x12\x84\x9b\x3f\xb0\x1e\x7d\x67\x95\x71\xbb\xbe\xb6\x80\x9f\xf8\xda\xda\x23\x5b\x08\xaf\x9e\x28\x37\xd9\xa4\x66\xf5\x27\x84\x91\x00\x98\xba\x7b\xba\x93\xde\x60\x0c\xf0\x82\x7d\xa9\x30\x20\x2a\x45\xe1\x31\xee\x62\xd0\xf7\xf6\xa4\xd3\xae\x4c\x2a\x9c\xea\x28\x08\x9a\x14\xd5\x5e\x75\x70\xb0\xbb\x5e\xe6\xea\x3f\x76\xd7\x13\xa5\xd5\x86\xdd\x79\xde\x39\x31\x65\xb3\x39\x18\x56\x45\xbe\x40\x7e\x19\x28\xe4\xe8\x94\xca\x1c\x72\xbb\xc0\xeb\x15\x47\x3d\x5f\x3a\xd1\xf9\x7d\xc6\x24\xd4\x9c\x6b\x4c\xef\x65\xff\x59\x32\x65\xed\x25\xec\x60\xa7\xc5\xd1\x54\x8d\xad\xe8\x65\x2c\x9b\x9d\x7b\xd9\x58\xb1\x47\xd5\x25\xfc\x88\xec\xdc\x9b\x82\xde\x51\xdc\x1d\xae\x1b\xad\xb0\x4c\xe8\xa2\xda\xa3\xfd\x2a\x64\xe0\x9a\x48\x6c\x46\x9c\x34\x87\x67\xc4\xeb\x15\x79\x14\x01\x36\xda\x40\x17\xfd\x30\xa8\xeb\xd1\x5c\x09\x5e\x50\x5f\xb6\xb1\x39\x15\x22\x2b\x46\xdb\x7b\x5a\xda\xdd\xf9\xed\xc0\x57\x2b\x61\x44\xc1\x5e\x7a\x28\x92\x6c\xec\x6b\x95\x4c\xc1\x4c\x77\x52\x56\x77\x81\x80\x9a\x59\x7c\xfd\x73\xe3\x06\x80\xcd\x0f\xb4\x0e\x14\x89\xa8\x02\x35\x77\xe9\x71\x21\xa2\x46\xe1\x10\xff\x1a\xd3\xf4\x06\xa6\x5b\x1a\x53\x5d\xb1\xcb\x6e\xeb\x6e\x2e\x50\x5e\x56\xf8\xa8\x2d\x43\xc4\xd3\x47\xab\x8b\x3f\x42\x45\x8f\x13\x20\xdf\xa6\x76\x45\x9d\x93\x91\xf2\xea\x85\xd3\x3d\x68\x1f\x50\x43\x41\xb9\x0b\x20\x46\x72\x9e\x4f\xfd\xa7\x8d\x92\x57\xd5\x3d\xf6\x78\x79\x6b\x99\xac\xc7\x4f\xe7\xcd\xb1\x88\x74\x46\x04\x90\x03\xae\x06\xef\xf4\x57\x9a\x29\x31\xe3\xd0\x12\x24\xa3\xc0\x2d\xfb\xcf\x04\x90\x26\xb0\xb1\x40\x11\x42\xa1\x33\x4a\xf4\x1f\x24\x35\x39\x6f\x5f\x0d\x70\x23\x36\x53\x7b\x21\x4a\xe5\xe2\x2a\x40\x75\x96\x6e\xd5\x2d\x50\xc1\x4b\x45\xd8\x6b\x6d\x3b\xcf\xa6\x3b\x9a\xe3\x90\x93\x70\xee\xa4\xa7\x14\x36\x04\xea\xf5\xa6\x10\x2e\x5b\x7f\xca\xa4\x44\xb4\x2e\xaf\x66\x2a\x52\x35\x19\x15\x94\xae\xe5\x1b\xfa\x57\x31\x1d\xdf\xee\x50\x2a\xe2\x60\x63\x06\xe8\xdb\xf0\x3f\x0e\x27\xb2\xad\xe4\x87\x94\xd5\x37\x85\xce\xb3\xb7\x46\xb8\x38\x46\x61\x89\x16\x74\xef\xb9\x7b\x1e\x1f\xdf\xfe\x04\x2e\xf5\xd4\x2f\xe7\x48\x7c\x7e\x6b\x1b\xa6\x55\x6d\x6b\xec\x88\x25\xb8\xc8\x16\x91\x8f\x36\xe4\x8f\xa8\xf2\x96\xfa\x1a\xf3\xeb\xde\x94\x05\x4f\x6d\x01\xcf\x8a\xe9\x31\xb2\xec\x9f\x01\xda\x48\x3b\x1b\xd9\xb2\xb3\xb0\xa4\x67\x66\xe4\x9b\xad\xc2\xbb\xbd\x70\x2d\x53\x84\x07\x48\x32\xb7\xc3\xb7\xed\xfb\x0b\xd1\x49\x49\x28\x33\x7b\xb7\xf2\xcb\x76\xc6\x3e\x43\x0e\xe4\xaf\xed\x7d\x0c\x05\x85\x4c\xb4\x33\x41\x99\x66\xde\x0e\x8d\x9c\x1b\x92\x70\x6a\xf1\x5f\xca\xb4\xdc\x54\xf9\xa5\x9e\xd9\xd4\x83\x0d\x61\xa7\xf2\xae\x99\x01\xbf\x6c\xbd\x70\x94\x4f\x75\x03\x54\x3f\xd8\xc1\xc2\xcb\xf8\x07\xa0\x35\xf9\xb8\xaa\x42\xb1\xd8\xcc\xbe\x5b\xc7\x28\x54\x2c\x14\xb8\xb7\x18\x8f\x2e\x9b\x69\x17\x85\x69\x83\x1a\xdd\xd8\xce\x13\x24\xe3\x99\x72\x17\x79\xc9\xe6\x59\xad\xca\xe3\xab\x7f\x62\x9a\x81\xce\xcf\x09\x47\x02\x49\x7c\x9a\x14\x7d\xc9\x2e\xd8\x76\xe1\x95\x98\x21\xe9\x02\xf5\xac\xc8\x8e\x0e\x3a\xc9\xe3\x31\x07", 4096);
*(uint64_t*)0x200002c8 = 0x1000;
*(uint64_t*)0x200002d0 = 0x200027c0;
memcpy((void*)0x200027c0, "\x0f\x9e\x6e\x7c\x19\xbf\x49\xa7\xa8\x84\x37\xa3\x53\x27\xdf\xa5\x0e\x81\xe5\x12\xd1\xac\x80\x36\xdf\x4b\x9f\x08\x45\xf4\xa1\x9e\x73\xfd\x27\x91\x4d\x48\x6b\xc3\xf3\x45\xdc\x87\xf0\x0a\x90\x57\x0d\x39\x25\x99\x2d\x87\xc8\x57\xa2\x56\x0e\xc7\x2c\x22\xe2\x2c\xf6\x2c\xd8\xa3\x2b\x2b\xdc\x7a\xfd\xbe\x05\x08\x65\xf2\x95\x3b\x2a\xad\x18\xcd\xba\x92\x1d\x84\x48\xa8\x60\x2a\xa8\xf1\xcd\x13\xc7\xd6\xdc\xea\x43\xe1\x3f\x75\x8a\xbb\xa8\x7e\xc8\x58\xb5\xc9\xc9\xa6\xac\xdf\x56\x24\xd9\x67\xa1\x1d\x0a\x95\xa0\x86\xd1\x2f\x73\x4b\x10\x1f\xba\x41\x81\xc7\xb6\x6e\x4b\x1b\xb9\x94\x61\x3e\xdc\x43\xcf\xdd\xc7\x80\xaf\x3f\x62\x74\x81\x6a\x0c\x32\xbe\xba\x82\xb0\x13\xf9\xfb\x8b\xa0\xf2\xf8\xd0\xd5\x43\x0c\xf0\xf9\x67\x9a\x01\x34\x67\x97\x21\x8e\x94\x82\x1e\x50\xd6\xec\xd7\xae\x16\x7b\x97\x4b\x3b\x34\x9c\x5d\x9f\xfb\xc3\xe7\x78\x98\x6d\xce\xc3\xd7\x5f\x02\xcc\xea\x66\xbf\x13\xfc\xdb\xf0\x1a\xcf\x47\x8c\x8f\x7c\x46\x39\x67\x60\x97\x97\xe2\x21\x10\xe7\x3c\x83\x10\xa1\x70\xc3\x27\xa4\x71\x33\x2d\x4d\xac\x39\x20\x8a\x5b\xd3\x45\xe5\x25\xbe\xd1\x9a\x43\x06\xee\x69\xc2\x58\x2e\xe8\x08\x66\x40\xd8\x06\x14\x80\xc2\xa5\xd0\x95\xe0\x94\x8d\x8b\xaf\x77\x19\xea\x96\xb4\xd3\x5f\x42\x30\x57\xa9\x17\xee\x71\xae\xf1\xdb\xa3\x29\x84\x34\x0f\x62\xa1\xce\xa6\x84\x4c\x56\xb8\x9a\x56\x0a\xe2\x70\xd5\x35\x9b\xc2\x67\xd4\xff\x57\xd9\xfd\x71\xb7\xea\xbc\xad\x47\x1d\x3a\x5d\x14\x0b\xc6\xf3\x56\x0e\x3d\xdd\x04\xa6\xe1\xf8\xa4\x00\xbc\xee\xd7\x91\x9f\x61\x90\xca\xa3\x52\xfc\x60\xa7\xe3\xe1\x38\x2e\x9c\xdd\x4a\xcc\xa4\xbe\x00\x5f\x55\x89\xbf\xd7\x74\x9c\x87\x9d\x11\x45\x25\x18\xfb\xfd\x79\x46\xd2\x8e\xa6\x30\x4e\x68\x9c\x63\xbe\xaa\x30\xa0\xc7\xad\xd7\x7b\xe2\xaa\x5a\x29\xaf\xbf\xe4\xcf\x40\xac\xcd\xb9\x0f\x7a\x6c\x4e\x41\x3c\xbc\xbc\x86\xe5\xe4\x71\x6b\x26\x18\x79\xde\x96\x39\x62\xad\xb6\x41\x02\x97\x90\xf7\x42\x9a\x52\xc5\xec\x55\x93\x2c\x60\xdd\xcb\x47\x84\x52\xa4\xc9\x79\x8c\x41\xd5\x8f\x4a\x19\x4b\x4b\x1d\x08\xc8\x6c\xc5\x4d\xa1\x0f\x5d\x3e\x3e\x10\x5a\x87\x82\x52\x83\x67\xcd\x50\xe4\x83\x23\xe1\x88\x22\xe4\x13\x3c\xe4\xa5\xf9\x89\x14\xbe\x80\x3d\x42\x7d\x5e\xe1\x57\x76\x19\x75\x88\x6c\x26\x6e\xfc\xec\x82\x63\x73\x7a\xdf\xdd\x69\x13\x4c\x1b\xd3\xad\xc5\x8a\x81\x83\x15\x1d\x1e\xf8\xf1\x96\x43\x1b\x2b\xbd\x55\xff\x63\xaf\x6a\x63\x7e\x8a\x3d\xcd\x30\x27\xeb\xd8\x0c\x17\xb1\x57\xe1\xd1\x1d\x2e\x53\x75\x24\xf8\x54\x3d\x57\x64\xeb\x4b\x40\x99\xc9\x20\xe6\x72\xcc\xeb\x77\x09\xf6\x1e\x9e\xb7\x13\x9c\x8e\x66\x14\xc7\x55\xe8\xf2\x25\x53\x4e\x2c\xd9\xcc\x90\x25\x85\x3d\xfe\xb7\xc2\x14\xa8\xfa\x09\xd8\x4a\x0f\x3d\xd3\xea\x63\x4b\xe2\xc6\xa9\xee\xf1\x05\xa5\x9b\x84\x80\xab\x2b\xc3\x6f\x97\x14\x10\x81\xf4\xa4\x31\x10\xb0\xe2\x05\xf3\x95\xd6\x36\xde\x53\xa0\xc3\x55\x1c\x9c\xe0\x55\xd2\x53\x31\x95\x93\x90\x97\x4e\x5c\xcc\xa4\x27\xd5\x39\xe8\xb2\xbf\x1c\x44\xfa\x0e\x7c\x58\x79\x88\x4b\x2d\xfe\xb5\xf6\xa1\x67\x65\xae\x53\xf8\xac\x48\x48\x11\x5b\x5b\x1e\x0c\xc4\x1e\x56\x34\x09\x5b\x4c\x5a\xc0\xe9\x47\x32\x1b\x10\x2e\xfa\xce\x7e\xe7\x61\xe8\x0a\x23\xd3\x3d\xc4\x9d\x60\x90\xd1\xcb\xe1\x02\xba\x69\x23\x82\x00\x27\x8b\x7d\x52\x2c\x1c\x05\x91\x09\xc6\xe4\xc6\x04\xd1\xd9\x82\xa3\x3e\xa5\x91\x9c\x1c\xdf\x9f\xdc\xd6\x9d\xc9\x5f\x57\xca\x70\x37\xaa\x17\x60\x15\xbf\x0e\x3a\x03\x1c\xee\x44\xbf\xd2\xd9\x5a\x11\x8a\xf5\x76\x29\xa5\x48\xe8\x79\x73\xa9\x88\x71\xf9\x1c\x82\xeb\xe2\xcf\x51\x98\x10\x06\x92\x7c\x69\xfb\x3f\xa0\x85\x32\xc5\x17\xcc\x49\x76\x60\x52\x39\xa3\xaf\x94\x79\xf2\xb8\x59\xb1\x64\x17\x95\xbb\x7b\xe1\xc8\x98\x18\x98\xed\xd2\xea\xaa\x42\x46\x12\xd1\x9d\xc7\xc8\xb9\xe1\xbe\x02\x06\x51\xbe\x42\xb0\x5d\x4f\x32\xfe\x5a\x62\xac\x9b\x71\x61\xba\x66\xd1\x8b\x42\x71\x8c\xc1\xe5\xa0\x8d\x1e\x6e\x80\x04\x42\x0d\x63\xd0\x38\x58\xe0\xcc\xa8\xcf\x20\xb8\x8f\x0d\xcc\x92\x15\x1c\x61\x66\x39\x8e\xfa\x3c\xf3\x21\xb7\x3a\x8e\x57\x3e\x0a\xdd\xaa\x79\xc1\xc6\xd3\x87\x9d\x03\x1a\x70\x6b\xf2\xa7\x9b\x5d\x41\xb2\xda\xe1\x04\xda\xe0\xca\xab\x64\x1c\x01\xe8\xe5\x0e\xf8\xda\x18\x16\xd0\x50\xb1\x57\x48\x4a\x46\xe6\x81\x94\x89\x92\x15\xb6\x19\x5b\x7d\x62\x4d\xde\x2e\xa8\xa5\xe2\xe9\x6b\x05\x0e\x5f\x2d\x19\x8a\x75\xcd\x5c\x24\x17\xaf\x50\xa7\x87\x92\xe8\xf5\x3d\x27\x3e\xa9\x47\xc4\xad\x15\x93\xd3\x41\xe4\xf6\xcb\x29\x20\xe6\x2b\x80\xfe\x58\x07\x21\x83\xc0\x58\xbe\x67\x15\xaa\xcc\xa9\x16\xfa\x76\xd9\x3f\x84\x53\x0b\x62\xee\x5b\x67\x79\x44\x6a\x25\x02\x14\xa1\x67\x64\xf9\xba\x8c\x43\x24\x7d\x23\x8b\x16\x36\x4b\xb9\xef\x62\x34\xc5\x90\xb1\x51\xde\xbf\x69\x23\xfb\x3f\x0e\x8f\xa8\x6a\x8d\x14\xcf\xec\x62\x0c\xf0\x69\xb6\xe8\xf9\x55\x6c\x5a\x74\x8e\x1d\x48\xa8\x1e\x8d\xb1\x39\x97\xf3\xe1\x76\x76\x13\xf2\xfb\x3d\x20\x85\xbe\x5b\xce\xd7\x2c\xa5\xb9\x8c\xb0\x7b\x31\xdc\x05\xfd\x91\xb0\xcb\xdb\x3f\xc5\xc5\x7a\x6e\x2b\xf0\xf0\xa6\xc8\xc7\x2f\xb7\xb9\xca\x81\xf6\xa5\xef\x16\xff\xb2\xd0\xb4\x09\x46\x8c\x1b\xf3\x64\x45\xa2\x56\x86\x34\x42\xcd\xc7\x74\xf6\xe6\x71\xb7\xdd\x56\xb5\x2b\x86\x1f\x01\xc7\x27\x6b\x2a\xae\x58\x2d\x0f\x51\xa7\x6b\x10\x8e\x89\x1b\xbb\x7a\xc2\x57\x68\x9d\x45\xbf\x38\xc0\xe3\x7f\xb0\x91\xa3\x19\x83\xdb\xd3\x83\xaf\x2b\x3f\xbc\xcf\x71\x44\xbc\xdf\xbf\xbe\x42\xb6\xfd\xe4\xce\xc6\x91\xad\x58\xf9\x2a\x29\xc6\x9b\x50\x22\x94\x5e\x8e\x10\xae\x99\x77\xc0\xa2\xe3\x62\xff\xf1\x6e\xa6\x12\xae\xb2\xf7\x6b\xe0\xe5\x3a\x17\x29\x36\x51\x09\xcc\x65\x7e\x81\xad\x5f\xd4\xaf\x17\x3c\xf3\x73\x24\xa3\xa8\x32\x59\x7f\xb3\x4f\xa9\x89\xe8\x6f\xac\xb7\x14\x5d\xf2\xde\x04\x72\x18\x83\x9d\x5e\xda\x88\x14\xbd\x3a\xb5\x27\x62\x8b\x9c\x40\x12\x43\x9c\x35\xe2\xe1\x1b\x74\x4d\x48\x50\x61\x4f\xb3\x97\xdc\x8a\xbb\x43\x37\x80\xfa\xd5\xd3\xde\xe7\xf5\xa1\x4d\x6c\x2a\x95\x3a\x74\x54\xf9\x95\xf1\x34\xe6\x73\x0c\xf4\x8e\x8a\xf2\x88\x3a\x14\x6b\xf3\xe6\x72\x7d\xe5\x7c\xa9\xce\x9e\xf9\xd6\x8c\xd2\x00\x36\x41\x3d\x73\x03\x1b\xa0\xb0\x86\xb7\x43\x82\x26\xa5\xd6\x24\xee\x76\x04\x59\x54\x4d\x39\xe2\x48\x66\x50\xfa\x41\x88\xb6\xce\x59\xab\x20\xb5\x09\x21\x7b\xd8\xb4\x2e\xcc\xfc\x46\x15\x5c\x7f\x30\xca\x88\xde\x38\x5b\xb0\x38\x98\x59\x62\x83\xef\xd8\xae\x0a\xd0\x76\x44\x87\x15\x31\x61\x47\xd9\xf9\x08\xf2\x76\x11\x0e\xcd\x54\xad\xbd\xcf\xd0\x39\x78\x0b\xad\xc1\xb1\xcb\x4a\xe1\x30\x9a\x7b\x49\x51\x3c\xd3\x15\xa5\x45\xc0\x73\x10\xcd\x9a\xbf\xc0\x12\x7e\xa7\x8d\x17\x17\x9f\x0e\x5f\xcc\x04\x87\x55\x9e\x7a\xea\x0e\x46\x8b\x2d\xd5\xde\x1c\xd0\x51\xb0\xc8\xe8\x28\xcf\xfe\xad\xc1\x0c\x79\xb2\x34\x79\x9a\x4b\xb5\x11\xdb\x4c\xd8\xe2\xb3\x86\x78\x03\xe3\xad\x6a\x59\x62\x77\x0b\x39\xcc\x19\x25\xd8\x81\x1d\x7e\xc0\x48\x29\xd0\x65\xa6\xf2\xd3\x2e\x55\x2e\x4c\x9e\xef\x07\x95\x1e\xcd\x96\xe5\xeb\x3c\x08\x31\xba\xa0\x24\x21\x2d\x71\xeb\xc9\x5a\x9d\xb9\x6a\x92\x07\xf9\xcb\xc5\xf4\xd0\xe2\x49\x45\xf1\xbe\x1a\x33\x02\x08\xe4\x95\x8d\xa8\x15\xc3\xdd\xc1\xcb\x6e\x52\x56\x15\x38\xcc\x5c\x1a\x19\xb1\x8d\xa5\xdb\x21\x9f\x5b\x34\x09\x82\xb0\xed\xab\x77\x3a\x7d\xe0\xd3\xd8\x11\x48\xe2\x63\xfb\x8e\xe7\xa2\x9d\xa5\x37\x2e\x90\x5e\xc5\x2d\xaa\x42\x5a\xb9\x72\x5e\xc6\x87\x22\x3c\x95\x0a\xa5\x2b\xf9\x4b\x6b\x61\x8f\x08\xd1\x31\x21\x5b\x6e\x7b\x0c\x17\x16\x11\xe4\x8e\x9d\x27\x22\x69\xa1\x89\xeb\x9c\x78\x73\xa6\x6b\xe9\x94\x47\x2c\x79\xd0\xd8\x97\xe2\xd3\xeb\x2b\x55\x35\xa0\x56\xec\x5d\x07\x01\x66\xa9\x83\x23\x52\x17\x0b\x5f\x04\x79\x98\x0f\x96\xff\xf3\x79\xd8\xb1\xa1\x71\x12\xa8\x60\x51\x35\x13\xd2\x32\x78\x05\xbc\x44\x73\x44\xc4\xd6\xe0\x4c\xdb\x05\xe3\xed\x30\x6e\x9e\xd3\x51\x2c\x94\x78\x7e\x3c\x10\x32\xc8\x65\xfc\xb6\xb4\xf5\xe0\xe4\xf8\xbc\xda\x76\x41\x55\xde\x50\x54\x2d\x1d\x07\x3c\x50\x35\x14\x0e\x0c\x7a\x78\x91\x97\x1b\x73\x69\xf7\xb4\x74\x51\x84\xdc\x3d\x4a\x8f\xe8\xf8\x58\xe1\xa8\xf3\x61\x3b\xa0\x08\xe8\x12\x1c\xa3\xd6\xa2\xf5\xe7\xdb\xa4\x97\x19\x31\x5c\xba\x1d\xb8\x79\x49\xcb\x19\xdf\x54\x17\xe4\xc4\x11\xd3\xeb\xba\xc8\x43\xcb\x18\x44\xff\x64\xac\xab\x2f\xe7\x0b\x7f\x96\xfa\x8b\x80\xb2\x83\xb5\x44\x69\x3d\xc0\x51\xb7\x50\xe6\x6e\x16\x84\xaf\x94\xeb\x1c\x05\xa3\x01\x21\x39\x5c\xef\x7e\x91\x3a\x39\x7b\x9b\x33\x8a\x09\x52\xc2\x92\x9e\x0e\x8e\x39\xaa\x6e\x00\x3c\xa1\x2b\x3f\xd3\x88\x18\x49\x04\xac\x0d\x7d\x0c\x92\x0e\x50\x4e\xe9\x81\xcb\x5a\xbc\x90\xdf\x79\x0a\xe0\x41\x0c\xaf\xfb\x33\x66\x6b\x96\xb0\x67\x11\xfd\x4c\xfc\x84\xf1\x82\x2b\xb2\x14\xf1\xdb\x9e\x56\x90\x5e\xe6\x24\x50\x66\x3e\x15\xca\x72\xa6\x64\x69\xe2\x09\x2d\x68\xc9\x39\xbb\xf7\x9c\xe4\xbf\x45\xe9\xd0\x28\xf9\x77\x05\x82\x64\x5d\xcd\xe5\x49\x78\x47\x59\xc9\xd3\xf3\x29\x28\xe0\x02\x0c\x72\xea\x1d\xf3\xad\x50\xb9\xeb\x10\x70\x8b\xd9\x32\x60\x7c\xa6\x8e\xc1\x26\x8b\x1e\xd6\x6b\xab\x8e\x17\x68\x56\xea\x1a\x02\x3e\xa9\x84\xcb\xe5\x57\x28\xbe\xf1\xc5\xcc\xed\x53\x63\xac\xa4\x01\xea\xed\xd8\x75\xc9\x41\xc1\xcf\xbd\x45\xc3\x72\xc8\xb6\xef\xb3\x48\xf0\x48\x67\x29\x21\xfe\xbe\x9f\xb5\x92\x18\xa1\xba\x72\x09\xc8\xb8\x1f\x87\x21\x7b\x6f\xdb\x2a\x4b\x86\x55\x8e\xa5\x60\xbd\x89\x8f\xfc\xd5\x4a\x9b\x7b\xe2\xc8\x7c\xe7\xe2\x71\xd3\xe0\x64\x6d\xfd\xbd\x65\x64\xf9\x10\x40\xf8\x83\x12\x9b\x92\xf8\x9a\xde\x38\xea\x0c\xe5\x2c\x50\xa2\x09\xd9\x76\x8f\xd2\x03\xec\xd7\xcc\xd8\x64\x50\xc2\xf7\x77\x30\x76\x67\xa9\x8d\x6e\x99\xcf\x58\x48\x32\x19\x76\x46\x5b\xf4\x4d\x3e\x33\xaf\x66\x1c\x59\xc9\x97\x3e\xe4\xa9\x65\x90\x12\x15\xca\xa0\xde\x60\x55\xd7\xff\x0f\x69\x1c\x83\xd3\x3e\x51\x1e\x87\x8e\xce\xbe\x02\xd7\x1d\x4e\x89\x7c\xa3\x63\x0c\x82\x2a\xaf\xd9\xa1\x5f\x13\x21\x87\xe6\x1d\x74\x8c\x8b\x02\x08\x99\x64\x04\x24\x3e\x4f\x5d\xac\xd6\xa2\xf3\x51\x85\xa7\xd3\x9f\xf7\xc9\x19\xbc\xca\x8e\x01\xa0\xa2\x42\x87\xc0\xff\x28\xbe\xfa\x68\x73\x10\x42\xc4\xb2\xba\x59\xdc\xc5\x5a\x49\x3c\x71\x87\x7e\x02\x33\x04\x92\xde\x57\x12\x32\xd9\x2c\x63\x1d\xfd\xf5\x19\x34\x2d\x10\x20\x65\x02\xe5\x7b\x67\xaf\x4b\x29\xd6\x46\x58\x74\x49\xda\xb8\x43\x5e\x29\x24\x9b\x49\xef\x40\x6a\x6f\x0b\xa9\x7a\x83\xfc\x6f\x74\xbc\xba\x99\x81\x5f\xb7\xd5\x1b\x28\x07\x24\xc6\x1a\x23\xc1\x6c\xe6\x65\x72\x02\x64\x8b\x72\x64\x7d\xc0\x55\xf7\xf8\x26\xbe\x5b\x72\xa8\x04\x54\xa8\x87\x96\x88\x56\x0b\x5c\x73\x3e\x84\xdc\xb9\x42\x58\x56\x58\x09\xd1\xc5\x32\xc5\x00\xfe\x6c\xa9\x4d\xf3\x7a\x72\x06\x8a\xb9\x89\x1b\x2e\x0f\xfc\xef\x4f\x53\x8a\x6e\xe8\x23\x77\xdf\x8b\x02\x32\x58\x38\xc6\x64\x27\x77\xd4\xc0\x77\x6c\x65\xce\x1a\x25\x5d\x43\x4d\x24\x87\xcb\x2b\x12\x66\xea\x93\xbf\x12\x74\xd4\xa1\x56\x17\x73\x78\xf0\x44\x84\x5f\x81\xaf\xc1\xa9\x8f\x76\xc1\x75\xd0\xc5\x6b\xd5\x6e\xfa\x9a\xe9\xcf\x07\x88\x83\xbb\x5b\x48\xe0\x85\x0f\xe9\x46\x33\xd2\x38\x10\x8e\x7f\x11\x26\x2b\xd0\x13\xfd\x4e\x92\xb3\xc1\x1f\x98\x10\xbf\x16\x0c\x5a\x5c\xf6\xa3\x33\xcc\x88\x08\x1b\xd6\xdf\x94\x7c\xc4\x7a\x5b\xb8\x41\xce\xc5\xca\x48\x9a\x94\xae\xf3\x91\x70\x41\xca\x83\x7b\x8a\x47\xed\x1b\x23\x05\xbf\x69\x55\x0f\x2b\xc5\xdf\xec\xd9\x98\x7c\x4f\x2f\x89\x84\x61\x83\xc4\x47\xcb\x07\x01\x74\x8e\x54\xff\x59\x7e\x76\x5e\x7a\xcd\x58\x21\xcc\x19\x2e\x33\x03\xae\x21\xad\x05\xd2\x55\x27\x1d\x6f\x0d\x6b\x71\xe9\xb8\x70\xf1\x70\x07\x48\x69\x46\xe8\xbc\x16\x84\x6c\x75\x88\xdf\xb6\x1d\x34\x7a\x0f\xe4\x0d\xd1\x11\x26\xd1\x76\xe3\x8d\x3e\xbe\xd3\xe1\x23\x4f\x17\x1d\x84\x44\x95\xc6\x1d\x36\x1c\xbc\xfe\x71\xb1\x8a\x95\xb4\xe1\x3f\x23\xdb\x04\x77\x34\x1d\x22\x46\x5c\x35\x71\xd7\xc7\xeb\xeb\x45\x1f\x16\x34\x3b\x41\xc4\xd0\x7c\xfc\xe3\xe4\xfe\xaf\x37\x3f\x9b\xf1\x98\x0a\x21\x35\x7e\x40\x94\x4a\xf9\xf3\x38\x6d\xf0\x2f\xf4\x48\x98\xe8\xd5\xa9\x44\x70\xe3\x98\xdc\xca\xe8\x88\xb5\xa2\x63\xbf\xdd\x5a\x8e\x56\x9c\x1d\x3d\xfa\xe4\x4b\xd1\xa9\xf2\x5c\x3e\x15\x25\xa3\xa0\xb6\xb9\xf8\xe3\x61\xfe\xcd\x09\xd9\xd3\xd4\xdb\xec\xb4\xd3\x5e\x65\x21\x56\x15\xe1\xec\x32\x0b\x9e\x11\x75\xdf\x41\x09\x9e\x5c\x47\x7a\xa6\xdc\x00\x4d\x91\x77\xe1\x42\xd9\x8c\x52\xb6\x50\x43\xe1\x66\x7c\xef\x25\x74\xa0\x76\xd2\x61\x6d\xdf\xec\xca\x56\x98\x66\xa8\xa8\xf0\x6b\xae\x02\xfa\x8c\xc4\x9d\xc2\xcd\xa8\xcf\x7b\xe9\xe1\x08\x96\x87\xa3\x98\xa7\x69\x42\xf9\x5c\xc2\x2c\x28\xd0\xe8\x97\x83\x0a\xaa\x65\x3f\x93\x8d\x76\x96\xed\x63\x5e\xa2\xb5\xae\xd8\x79\x2e\xc4\xbf\x6a\xb3\xda\xd7\x4e\x19\x76\x1e\x8e\x1f\xb6\x1f\x0f\xb0\xae\xf8\xa9\xb7\x99\xb0\x6a\x6f\xbb\x7a\x89\xac\x6e\xd1\xdd\x48\x3a\xe3\x29\xf2\x8f\xbb\xf8\x11\x17\x12\x64\xf0\x7d\xe3\xa9\xbd\xba\xa2\xdc\xd0\xd6\x3d\x83\x44\x2d\xa4\xa9\x97\xac\x99\x9e\xcb\x08\x28\x48\xf7\xe2\x09\xfe\xbb\xf7\x67\x3a\x2e\x9c\xcf\x66\x11\x86\xc7\xa4\x7d\x80\x42\x6f\xe8\xb4\x94\xd3\xee\xd4\xc3\x23\x87\x51\x17\x0c\xec\x23\x76\x52\x63\x5c\x5d\x7e\x6f\x94\x38\xe3\xcc\x07\xaf\x77\xb4\x8e\x64\xe9\x56\xb3\xa3\x0b\x90\xd9\xfd\xec\xf8\x7a\x21\x33\xd5\x44\xfb\xf3\x27\x40\x79\x20\xb3\xe4\xaf\xa5\xef\x03\x2d\xaa\x4c\xcf\x16\x9c\xaa\x31\x8f\x98\xa9\x2a\x6f\x43\x13\x11\x70\xfa\xbd\x58\x2c\x5e\x43\xc3\x10\x2b\xb2\xe9\x67\x53\xae\x4d\xa7\x51\x5a\x83\x73\xd2\xec\x4c\xa7\xd7\xb8\x82\xa5\xbd\xf4\x00\x88\x18\xbc\x8a\x48\x2d\x6c\x4c\x65\x2a\x25\xe5\x38\x7e\xf0\x67\x16\xb9\x25\xd5\x53\x10\x2f\x89\x7b\x41\x17\x0e\x37\x6e\x14\xc6\xda\xa9\x9d\xe4\x5c\xcb\x26\x45\x88\x04\x17\x5b\x6e\xf0\xf2\xdc\xbb\x75\xd1\xb8\xf8\xc1\x0b\x82\xee\xfd\x3c\xce\x37\x2a\x37\xcc\xca\xfe\x4f\x53\xa3\x83\xf1\x49\x5a\x01\xd5\x81\x37\xe0\x94\x05\xa3\x53\xe7\x78\x55\x33\x07\x5a\x45\xe4\x59\x67\x51\xb3\xbe\xa3\x40\x69\xea\x81\x1c\x2b\xf4\xb7\xa8\x95\xac\xb2\x2e\x3b\x32\x58\x65\xa9\x08\xdf\x68\x54\x75\x60\x46\x9b\xe8\x52\x00\xa8\xf1\x88\xc1\xa3\x50\x5e\x2a\x3d\xdd\xc2\xa3\x03\x24\x64\x04\xbb\x6a\xe4\x36\x5c\x4c\xa6\x04\xb7\x03\x8e\x4c\x8e\x58\x9d\xa9\x3a\xd8\xfb\x3e\x38\x96\xed\x87\x8a\xd8\x2e\x9c\x50\xea\x72\x41\x38\xab\x66\x07\x35\x40\x66\x32\x5a\x5f\x34\x6e\x83\x4f\xe6\x77\xc6\x21\x8a\xda\x91\x9b\x03\xa6\x82\x6d\x9a\x48\x6a\x28\xc7\xf6\xba\xeb\x6a\x2c\xab\xc8\x8a\x25\x3b\x17\x03\x45\xf0\x54\xd0\x06\xf6\x02\x24\x74\x05\x71\x38\xba\x5b\xbc\xc1\x66\xca\xda\x6d\xfa\xeb\x3f\xf7\xf5\x6e\xa9\xf4\x98\xc8\x4f\xdb\xcd\x31\x61\x31\x2a\xfc\x9e\xa8\x41\xe0\xbf\x4b\xb3\x68\x1b\x84\x34\x7d\x80\xfc\xf3\x88\x56\xd0\xca\x70\xa0\x72\x2c\xab\xec\x4a\xa7\xf4\x81\xc1\x02\x75\x79\xd5\xb3\xe7\x63\x18\x32\x92\x26\x55\x2c\x1b\xf7\xd0\x06\x1a\xcf\x12\x94\xe3\x82\x71\xb8\x37\xb8\xdb\x19\xe7\x69\x39\xb2\x83\xd2\xde\x0f\xc6\x14\xe3\x2d\xd7\x03\x14\x21\x4b\x44\xb7\x75\x13\x2a\x84\x5d\x41\xe0\x92\x2d\x2f\xd6\xa7\x9a\x9e\xe3\x3c\xfe\x26\x06\x09\xa6\x1a\x26\x48\xe6\x35\x1f\xd2\xb1\xde\x4b\x01\x10\x42\x1f\x6c\xa6\x3a\xf5\xaf\x1f\xdf\xf8\x9c\x87\x24\x7e\x8e\xbb\xc4\xc2\xd6\xf1\x0d\x12\x4b\xd9\xc4\x17\xa2\x89\x17\x84\x80\xd6\x0b\x53\x56\xc7\x55\x30\xc7\xf5\x18\xa1\x3b\x65\x59\xb1\xfd\xde\x33\x7f\x2a\x4e\xe9\x37\x23\xf5\x1d\x2e\x22\x1c\x6c\x44\x77\xad\x59\xe8\xd1\xa4\xf6\xd2\x46\x58\xf7\x46\x52\xb7\x49\xbf\xbb\x50\x8a\x72\x8f\x8f\xfa\xc4\xfc\x5f\x43\x71\x72\x98\x5f\x01\x33\x8f\x34\x80\xc4\x66\xaa\x67\xd8\x87\xea\xaf\x12\x44\xdf\x16\xc2\x65\xc1\xc2\x14\xb2\x24\x8e\xd2\x89\xe1\x32\x7e\x3d\x73\x8c\x23\x37\x18\x7c\xca\xc9\xf2\x85\xb3\xa7\xa3\x10\x51\x94\x54\x9f\x9d\x91\x82\x3d\x57\x03\xe2\x91\x1f\x46\xfb\x25\xad\x5a\x3d\xc6\x9a\x15\xf6\x03\x4e\x20\xf5\x6e\x24\x34\x09\x1b\xbe\x8f\xc5\x56\x7d\xe9\xeb\x03\x78\x04\xa0\xb5\x9c\x65\x53\xec\x66\x6a\x5a\xd8\x30\x67\xf2\x78\xa6\x7f\xff\xb7\x79\xb5\xdd\xc4\xb5\xee\xd6\x46\x67\x14\x1a\x2b\x3f\x0c\x51\x3c\xaf\xcf\xfb\xfb\xc8\x06\xcb\xd1\xd1\x8d\x61\xd1\x7a\x30\x6a\x4a\x88\xb6\x19\x24\xaa\xeb\xd9\xcd\xe9\x75\x6a\x14\xb3\x9c\x19\xcb\x28\xbf\x9a\x7c\x3b\xd2\xbf\x83\x1b\xba\xee\x8e\x1c\xc2\xcb\xf0\x7a\x59\x15\xbe\x9a\x13\xc8\xec\x82\x70\x25\x08\xf9\x16\x43\x1f\x52\x7b\x45\x24\x81\xa0\x9f\x80\xec\x7f\xad\xa1\x7d\x4b\xc3\xc5\x0a\x0d\xe4\x47\x06\x9f\xc5\xe6\xbb\xaa\x0d\xd7\x1d\x54\x17\xa9\xd4\x4a\xe6\x61\xfb\x3d\x3b\xda\xe8\xde\x73\x39\x23\x7e\x36\x61\x8c\x56\xfc\x77\x73\x07\x76\xd4\x96\x2b\x6b\xfd\x29\x3a\x8f\x78\xef\x72\x4c\xae\xef\xe7\x63\xfc\xed\xf6\x82\xe2\xd8\x38\x98\xda\x2c\x50\xd5\xa4\xb8\x0d\x80\xb2\x02\xdb\x80\xbd\x42\x67\xb7\x09\x92\x16\x65\xad\x53\x15\x69\x44\x1b\x7d\xd0\xa5\xf8\x70\xff\xca\x92\x89\x8d\x6f\x7f\x0d\x96\x11\x36\x5e\x10\x13\xbb\x02\x5f\xe0\x0d\x3d\x7f\xd1\xac\xa2\x7e\xc7\xe1\xd6\x3d\xe8\x44\x8c\x44\x48\xc3\x79\xa6\x2f\x94\x31\xaa\x24\x3d\x60\x36\x80\xde\xdf\xbb\xf9\x15\xa6\xa2\xa4\x63\x29\xb8\x8c\x4d\x38\xd5\x55\x2f\x23\xcd\x2a\xdb\xd8\x7d\x56\x31\x57\xbf\x2b\xdf\x26\x6a\x16\xed\xab\xf0\x37\x72\xd5\x71\x9e\x2a\x80\xc8\x44\x41\x53\x54\x11\x21\xae\xb6\x46\xd4\x78\x1e\xd7\xc9\xfa\x68\xfd\xfb\xce\x2c\x0a\x12\x5a\xef\xb5\xfd\xf0\xd1\x9e\x58\x27\x6c\xd6\xc0\x72\xcb\x3b\xde\x23\x3d\x8b\xf7\xd4\xac\xe4\x23\x2f\x53\x81\x86\x90\x33\xc3\x42\x03\x26\xe4\x22\x0d\x7f\x6b\xeb\xb6\x0b\x99\xf3\x9c\x40\x37\x9d\xdd\x98\xb4\xd7\x89\x33\x20\x3d\x69\x0a\xd8\x33\x70\x51\x8c\xb1\x44\x60\xa6\xf2\xe2\x10\xf8\x68\x51\xe4\x7d\x5c\xcf\xd5\x91\x34\x5f\x35\xa9\xd6\x04\x20\x8e\xfc\x99\x20\x77\xd9\x0f\xe4\x7d\xdf\x3d\xa4\x7e\x47\xc1\x76\xce\x28\x51\x52\x77\xe4\xd8\x4a\xd8\xa3\x64\x30\x3e\x97\xce\x6b\xe9\x35\x13\x66\xf2\xb7\xb2\xb9\x58\xd3\xe5\x4a\xe4\xb3\xf0\x68\x77\x2e\xd0\x92\x01\x88\x0d\x2f\xd7\x84\x98\x98\x7e\xfe\xaa\xb7\xa0\x12\xac\xc6\x67\x23\x4f\xfc\xfa\xf4\xe1", 4096);
*(uint64_t*)0x200002d8 = 0x1000;
*(uint64_t*)0x200002e0 = 0x20000000;
memset((void*)0x20000000, 176, 1);
*(uint64_t*)0x200002e8 = 1;
	syscall(__NR_pwritev, r[0], 0x200002c0ul, 3ul, 0, 0);
	syscall(__NR_ioctl, r[0], 0x6611, 0);
	return 0;
}