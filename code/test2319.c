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
memcpy((void*)0x20000040, "./file1\000", 8);
	res = syscall(__NR_openat, 0xffffff9c, 0x20000040ul, 0x42ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_close, r[0]);
	syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20001280ul);
*(uint64_t*)0x20002100 = 0;
*(uint32_t*)0x20002108 = 0;
*(uint64_t*)0x20002110 = 0x20001380;
*(uint64_t*)0x20001380 = 0x20000000;
memcpy((void*)0x20000000, "\x02\xa8\x96\xc8\x7a\xd4\x32\x2e\xb7\xf1\x24\x8e\x73\x8c\x09\x66\xfd\xc4\xf7\xeb\x8e\xbf\xf8", 23);
*(uint64_t*)0x20001388 = 0x17;
*(uint64_t*)0x20001390 = 0x20000100;
memcpy((void*)0x20000100, "\x4f\xa6\xfa\xc9\xe7\x0e\x98\xed\xec\x2c\x13\xae\x8a\xa8", 14);
*(uint64_t*)0x20001398 = 0xe;
*(uint64_t*)0x200013a0 = 0x20000080;
memcpy((void*)0x20000080, "\xaf\xa5\xc1\x43\xab\x03\x8d\x11\xd9\x91\x4d\x4d\xe2\xa1\xa3\xc7\xb4\x86\x07\x00\x00\x00\x5d\x18\xd6\xb4\x44\xc1\x6c\xb1\xd6\x26\x23\x3a\xe2\x8b\xb1\xc5\x46\xc1\x2a\xa1\x59\xb3\x38\x9e\xe0\xcd\x7f\xbf\xcf\x5b\x91\x9f\xb3\xa3\x3d\x3f\x00\x00\x00\x2f\xcd\x16\x5c\xe8\x83\x7c\x39\xde\x47\x94", 72);
*(uint64_t*)0x200013a8 = 0x48;
*(uint64_t*)0x200013b0 = 0x20000180;
memcpy((void*)0x20000180, "\x8f\x5c\xdb\x03\x48\xf9\xf6\x14\x27\x99\x2d\x82\x27\x4b\xeb\x33\x10\x64\x90\xc8\xdc\x00\x78\xe7\xcf\x89\x49\xee\x10\x11\x6d\xc2\xbd\xf8\x89\xcb\xca\x71\x29\x94\x22\xef\x89\x31\x02\x51\x68\x74\x93\xfd\xcc\xfd\x29\xcb\xc7\x3a\x82\x9e\x17\xa0\x4c\x08\x6b\x42\xc1\x9b\x09\x4b\xe6\x59\x52\x85\xd9\x39\xe7\xc9\x97\xf8\x1e\xf0\xa6\x2f\x32\x7d\x9d\x2b\x22\x32\xd2\x9f\xa3\xc6\xd9\xda\x54\x14\xf5\xed\x54\xd8\x62\x5f\xbc\xa5\x37\x7e\x39\x64\x63\x53\x2d\x85\xa4\x9c\xab\xf3\x57\xfb\x60\x44\x1e\x30\x03\x02\xdf\x20\x88\x2e\x52\x66\xf6\xc5\xec\x69\x50\xae\xc0\x73\x72\x9b\x4f\x05\x01\xd6\x7f\x7a\x8c\xdb\x31\x9c\xa6\x3a\xf9\xcd\x5f\x01\xe2\x84\x69\x96\xa2\x21\x38\x31\x66\x89\x10\xeb\xc8\xed\xf0\x3d\x3e\x05\xbd\x29\xa8\x19\x76\x84\xf0\x8f\x63\xc9\xa7\x32\xd7\x23\x1b\x52\xbb\x02\x22\xe7\xe0\xa1\xc8\x41\x0f\x85\x50\x05\xce\x0e\x27\xef\x65\x9f\x0b\xbc\x88\x11\x2f\xf8\xfe\x65\x79\xc6\xe4\xb7\xbf\x5b\x14\xec\x8c\xd8\x45\xcc\x30\x23\xcc\x8e\xd5\xf4\x4e\x93\x6d\x9c\x2a\x74\x2c\x4c\x47\x30\x1d\xce\x36\xd7\x5f\xe1\xcb\x90\x16\x4d\xce\xf0\xfe\x7f\x00\x56\xaf\xf4\x33\x80\xd1\xa9\x62\x26\x8e\xde\x84\xe7\x52\xac\xa4\xbd\x3c\xcc\x74\xf0\xa4\xc3\xdb\x1f\x58\x25\xb3\x84\x9f\xdd\x70\x5a\x66\x59\xae\x05\x6b\x20\x20\x61\xf1\x53\x64\xac\x75\x48\x8b\x31\xe1\xc3\x4b\xe9\x5a\xa6\x1f\xb9\x44\xc1\x3e\x8a\x3c\x86\x0f\xb8\x35\x8c\x54\x23\x8f\xe6\x35\xb6\xaa\xd1\xa0\x86\xcd\x82\x94\xa3\xf7\x8d\x81\x58\xae\x88\x0d\xd7\x00\x89\xdf\xe0\x3d\x4a\x9d\x1a\xc5\xb6\x3c\xc7\x0e\x20\x26\xb9\xe2\x5e\x34\x02\x70\xad\x8b\x88\x34\x02\xb4\xe6\xdd\xd6\x9f\x0a\xf5\xbe\xc8\x70\x5c\xf9\xbe\xf3\x85\x69\x4a\x3d\x63\x0a\xad\x0f\x5d\xc7\x26\x65\x04\xb8\xb5\xfb\x43\xa4\x48\x1b\xae\xeb\x08\x9c\x5a\x5c\xe5\xbb\x8f\xe0\x41\x23\x87\x33\xd1\xe1\x8f\x1f\x6f\x32\x55\x8c\xca\xb7\xab\x5c\x05\x38\xa1\x37\x18\xe1\xe6\x91\x6e\x05\xad\x5d\x3c\xc0\xbb\x7e\xe7\xb6\x29\x5c\xc0\xa3\x8b\xc9\xc4\x7c\x07\x46\xb1\x4d\x15\x07\xb8\xe2\xd5\x42\x73\xb9\x6b\xc1\xc0\x1e\x28\x6c\xa1\xb6\x7f\x02\x01\xc0\xb4\x2b\x1b\xa0\xfc\x7d\x2e\x1a\x11\xdb\x82\xe5\x20\x2e\xbf\x29\xe3\x32\xcb\x62\x56\x50\xc9\x80\xc1\x25\x8d\x4e\x03\xa0\xd9\x50\x97\x1b\x93\x2d\xc2\xee\xa1\xc3\x16\x20\x5c\x1d\x97\xf8\x48\xe8\x65\x48\xe1\x1f\xad\xe4\x58\xec\xcf\x52\xeb\xc0\x94\xf8\x6e\xe7\x69\xd6\x5a\xc1\x3d\x86\x65\x7f\xe6\x0d\xab\xbb\x2b\x0d\x1a\xce\x73\x3d\x0e\xf3\xc7\xd7\xd1\xf6\x87\x14\x8e\x46\x37\x26\x0e\xd2\xf2\x0c\x64\xa4\x65\x94\x85\x67\x4e\x05\x12\x39\x32\x03\x8b\xbf\xb1\xa2\x69\xdc\x42\xe4\xfc\x8b\x67\x6a\xc0\x2f\xe3\xa9\x86\xdc\x9d\xee\xa2\xa9\xf1\xdb\x0a\x34\x23\xec\xbd\xf0\x44\xcd\x13\x79\x1a\x3e\x9e\x0b\x51\x57\x0e\x37\xcb\x4f\x21\xf1\xfa\xf9\x78\x55\xf9\x5e\x97\xd7\xd6\x67\x07\xa1\x5c\x5d\x32\x5b\x6d\x29\xf7\xe8\xbe\x4d\xa4\xcc\xdb\x7a\xab\xf9\x18\xc9\x09\xe7\x01\x0e\x04\x9b\x54\x96\x2a\x21\x55\x96\xb5\xa0\x94\x79\x4d\x8b\xeb\xc2\x5d\xde\x4e\xaa\x65\xa3\x81\x32\xe5\x48\x0d\xaa\xa1\xc0\xa4\x00\x34\x67\x98\x5d\xdd\x4f\x5f\x1f\xf6\xd1\x58\xda\xe3\xe1\x5c\x66\x72\x3f\xb2\x89\xa1\xde\xd3\x8e\xcc\xa4\x9c\x90\x74\x04\xb3\x0b\xcc\xa5\x4c\x26\xf0\x34\x2d\xde\x5c\x10\x24\x29\x42\x20\x30\x0b\xde\x32\x5c\x5a\x66\x14\x6d\x5c\x7f\x10\x9f\x7b\x72\x24\x06\x59\x5f\x25\xb3\xf3\x1d\x93\x50\x46\x8e\x07\x86\x7f\x4e\x35\x67\x79\x24\xca\xdf\xfa\xe5\x3a\x60\x9a\x12\xbc\x16\xd2\x22\x7e\x04\x77\x9a\x10\x2a\x74\xcd\x32\x25\x7c\xf2\x7f\xdb\x34\xf2\xf6\x7c\x1d\x09\x9d\xe0\x68\x3b\xd3\x88\x21\x3d\x25\xda\xfb\xf9\x38\x93\x71\xd9\x4b\xf1\x3f\xcb\xe3\xe8\x15\x6b\x3f\x93\xb1\x88\xba\x92\x7f\x56\x2b\xa0\x29\xe3\xc4\x86\x30\x25\x9c\xb4\x1d\xf5\x10\xb8\x33\x5a\x3b\xb4\xe4\x22\x3a\x86\xa4\x0b\x8b\x6a\xec\x51\x12\xdb\x88\x67\xc2\xa9\x11\xde\x46\x6d\xcd\xfa\x63\x59\xd6\x70\x5c\xcd\xb5\x27\x79\xd2\xc9\x43\x09\x2b\x71\xb9\xff\x8b\x2f\xfc\x96\x3a\x86\x2a\x59\x19\x44\x47\xf1\x7d\xf6\x21\x4b\x63\x9b\xe8\x6f\xe2\x7c\xe1\x2d\x74\x13\x70\x34\xb3\x10\x31\x55\xcb\xb8\x50\xd7\x6a\x95\xb1\xfc\x29\xd6\xee\xd8\xaa\x62\x6d\xb6\x29\x74\x59\x8a\xd6\x88\xdc\x23\x95\x8b\x72\x74\xc3\xa8\xec\xc8\xa7\x41\xad\x11\x6d\x2f\x88\x69\x6a\x4d\x44\xba\x25\xfe\x2a\xeb\x90\x20\x4b\x40\xdb\x1b\x5a\xf7\xa9\xfc\xc6\x04\xe9\x80\x9e\x29\x6b\xc3\xf5\x78\xbc\x68\x06\x10\x4a\x94\x41\x9f\x1f\x35\x7a\xb7\x6c\x0a\xe5\xd2\x01\x72\x2e\x65\x65\x2d\x3c\xf5\x33\xdc\x8f\xd5\x9c\x69\x32\x1e\x81\x0b\x92\x01\x5d\xcb\xd5\x04\x25\xbe\x4c\x3b\x65\xc2\x3f\x09\xb4\x4f\x30\x4e\x26\xa0\x9d\x70\x04\x25\x16\x19\x02\xc7\x1f\x38\x86\xbd\x59\x6f\x53\x9e\x2e\x39\xf3\xe6\x9b\x1b\xeb\x7d\xea\x71\xf9\x7e\xdd\xbe\xc9\xfb\x08\x38\x51\xb6\x3c\x4f\x01\x5c\xe0\x1a\x66\x52\x9a\xbd\x7d\xbd\xa1\x21\x34\xb1\x96\x2c\x64\x20\x00\x8b\x5b\x6b\xcf\xed\x46\x33\x57\xa5\xb2\x27\xf3\x3c\xbc\x10\x3a\x8c\x09\x00\x1b\xbf\x83\x96\x04\xd0\x1e\xde\x91\xda\xdd\x55\xac\xe6\x0a\x4a\x6f\xd0\x99\x03\xd3\x1b\xcd\xd2\x4d\xe1\x70\x05\x92\x9b\x6a\xe8\x83\x9a\xb6\xe1\xbc\x0b\xe1\xfd\x68\x40\x13\x19\x75\x34\xbc\x48\x58\x1d\x65\x7e\xe9\xac\x86\x02\x5d\x70\x51\x75\xd4\x1a\x73\x6d\x3c\x92\xcf\xdd\xf0\xb3\x18\xb0\x9c\x99\xc0\x8b\xe7\x34\x80\xf1\x71\x4e\xea\xcb\x7f\xe0\xb4\xb4\x96\x90\xa2\xe7\x64\x9e\x58\xe9\x02\xf6\x61\x33\x96\xc3\xcc\xd2\xe0\xb7\x18\xc8\x33\xa7\x0a\xe5\x85\x81\xc8\x01\x24\x1a\x22\x2d\xa0\x86\x49\xc3\x7c\xb9\x69\xd2\x03\x19\x45\x4d\xc9\xa2\x7f\x94\x7a\xb6\xf3\x75\xab\xf6\x86\xc1\x04\x5b\xa6\x74\xb6\x96\x36\xd4\xd5\x0f\x30\xb9\x96\xd0\x94\x5e\x51\x7d\x10\xcb\xd0\xbe\x28\x19\x24\x9c\x7f\x3d\x2a\xd7\x1e\xb5\x73\x2a\x5e\x3a\x1a\x35\x24\x1b\x90\xa4\x16\x48\xa4\x9c\x70\x26\x8e\xe3\xd7\xc7\x7f\x71\xfe\xd0\xc9\xb3\xa9\x77\xcb\xd3\x43\x52\x63\xa6\x95\x44\xd2\x5b\x17\x50\xf6\xbf\x44\x2e\x9d\x1b\x7c\xd7\xb0\x3a\x18\x2f\x10\x75\x95\xd0\xc7\xdb\xca\x73\x81\xe7\x74\xc6\x78\x4e\xb1\x9b\x50\xf1\x68\xc2\xb8\x1c\xab\xb2\x56\x68\x05\x7f\x35\xaf\xe8\x2b\x6e\xb8\x40\xc5\xe4\x09\x0e\xdf\x8f\x3f\x04\xa3\x11\x45\x34\x51\xc8\x29\x4d\x11\x5d\x6d\x0f\xcf\x4c\x29\x03\x14\xe7\x50\x38\xd4\xd7\x5b\x3d\x0b\xf8\x27\xdd\x6a\x3d\x25\x0c\x44\x33\x75\xda\x81\xc5\xa5\x20\x4c\x3c\xfb\xf2\x9c\xd4\x07\xb3\x13\x74\xf9\x47\x49\x42\x6f\xdd\xab\x9e\x12\x8d\x46\x85\x8d\x4e\xcd\xa9\xf0\x77\xf2\x18\x76\x57\x24\x3c\x07\x85\x11\x9e\xc2\xbc\xe8\xb4\x1a\x60\xc8\x11\xec\xad\xae\x18\xf0\x67\x12\x44\x32\x53\x7f\x63\xd5\xc0\xa5\x3c\xc2\x35\x85\xd1\x6b\xe6\x14\x5f\x6e\x2d\x35\x3f\x9e\xc6\x0f\xf3\xa2\x11\x43\x79\x03\x22\x31\x32\x5e\x35\x4a\xff\x78\x2c\xb5\x82\x7d\xb3\xb1\xea\x46\x6e\x43\x4d\x15\x8c\x38\xbd\x2d\x31\x94\x4d\x60\xf9\xa4\x8a\xff\x83\x8a\x43\x6c\x59\x70\x82\xe6\x08\x82\x40\x94\x67\x15\xe2\xcc\xde\x2c\x4f\x97\x06\xa7\x1f\xdd\x77\xa3\xf5\x40\x34\x4e\x06\x20\xc4\x61\x89\x7f\xb7\xcb\x1e\x37\xe0\x9e\xcc\x69\xf1\x9c\xfa\x35\x76\x9f\xf0\x88\x3c\x4a\x63\xad\x3b\xd7\xe4\xf1\x90\x92\x08\x62\xca\x2a\x00\x9f\x8e\xab\x3d\x16\x67\x55\x25\x44\x52\x24\xa6\x64\x45\xfd\x92\x02\xf3\x07\xc7\xd6\x19\x87\xa0\x76\xb0\xb5\xfd\x1e\xdf\xea\xbc\x0a\xb7\x36\xcd\x5c\x50\x85\x9c\x72\xdd\x56\xde\xe7\xd1\x2e\x17\x15\xfd\x5e\x13\x64\xe4\x62\x8a\xbc\x10\xe8\x2c\x48\xea\xf9\x41\x45\xa7\xe1\xd2\xb1\x4b\x40\x0d\x28\x12\x79\x5a\xf9\x84\xbd\x85\xa4\x78\xa7\x02\xb1\x32\x7b\xa3\xf9\x56\xb7\x78\xa1\x1c\xf2\x27\x2f\x73\x82\x01\xbb\x2d\x9e\xee\xf5\x97\xd1\xe7\x5b\x23\xc8\xd3\x8f\x8e\x69\x8d\x2c\x86\x7b\xc3\x37\x54\xe8\xff\x1a\x5d\x32\xf7\xa9\x0d\x2b\xb8\x4d\x1d\x34\xe4\xdf\xbe\xfb\x90\x88\xf6\xfa\xad\xae\x1b\xd7\x1a\x19\xb6\x7d\xb0\x1d\xc0\x9e\xc6\xe5\x84\x5c\x48\x1c\xb7\x86\x53\xa5\x1c\xaf\xbc\x79\xa5\x6e\xb3\xca\x78\xf7\x4c\xa6\xcc\x72\xdd\xcf\x55\x1d\x68\x9a\x2e\x4f\x4a\xaa\xd1\x55\x78\xce\x07\xfd\x87\xa7\xf8\xb0\x75\x01\x15\x8f\x35\x2c\xe7\xe8\x29\x9b\x56\x5b\x67\xe3\x19\x9f\x46\x0d\x66\x47\xcc\xfa\x94\x12\xd4\x5a\x7d\x8b\x29\xe7\xdf\x9c\xbe\x17\x6e\xd4\xd5\x4f\xe3\x41\x1a\xf2\x51\xba\xe4\x63\x85\xaa\x41\x4c\xfe\x6c\x52\xee\xab\x21\x96\x77\x49\x40\xa6\x0a\x21\xf1\x6e\x1a\xc6\x66\xa1\x39\x1b\x60\xfb\x95\xfe\xdf\x29\x4d\xe2\x38\x14\x4e\x5e\x77\xc1\x26\xa2\x6f\xd4\xb1\xb8\x67\x31\x26\x10\x34\xbd\xc4\x91\x40\x59\x14\x67\x83\x86\x2d\x30\x45\x19\xa5\x24\xd0\xf6\x9a\x43\xa7\x09\x88\x5f\x9c\x02\x5b\x68\x60\x04\xa9\xa9\xb6\xbd\xa2\x0c\x06\xa8\x71\x77\x87\x15\xbe\x1d\x58\x1c\xeb\xe1\x5c\xb6\xa2\xf9\xda\x55\x25\x6d\x06\xa5\xf9\x6a\xf1\xf5\xb4\x4d\x82\x6c\x0c\xbb\x0f\xd4\x24\x54\x72\x5a\x2d\xaf\xa9\x32\xe9\xe7\x9b\x56\x2e\xba\x7c\xda\xf5\x3a\xb3\x08\xd8\x33\x9f\xaf\xc2\x7e\x4f\xa5\x10\x48\xb1\x55\x0e\xea\xa9\x5c\xfb\xbd\xf5\x7b\xf1\x22\xf4\x90\x21\xea\xb7\x23\x6d\xf3\x33\x1f\xba\xf3\x4f\x4c\xf5\x9b\x7b\x22\xd1\x6a\xfd\x99\xb9\x82\x58\x64\xfb\x30\x2b\x7f\x9a\xee\x5f\x1e\x99\x24\x44\x81\x41\x11\xfe\x84\x9a\x73\x75\x63\x54\xc1\x6e\x93\xc0\xbf\x6a\x57\xd0\xbc\x6f\x18\x34\xb6\xbb\x18\xe8\x70\x0a\x9c\x23\xb0\x2d\x80\x9d\x3e\x2b\x1a\x7c\x1b\xb9\x31\x28\x88\x56\x62\x7b\x93\x38\xb3\xb3\x0e\xf4\x80\x02\x8f\xbc\x2a\xef\xf7\xd2\x3f\xcf\x5b\xe7\xd8\xf8\x81\x16\x9f\x50\x3d\x51\x33\x11\x19\x07\x27\xf4\xfd\xe9\xb2\xc0\x32\xf8\x37\x22\xaf\x06\x6e\xd7\x9f\x6e\x52\x67\xbe\x50\x66\x25\xc3\x5f\xcd\x54\x05\x80\xc6\x32\xd0\x23\xcc\x7c\x63\x40\x43\x9f\x52\xf1\x06\xdb\x58\xd7\x45\xa9\xca\x06\x75\xf1\x13\x98\x60\x1e\x76\xf0\x02\x3e\xf9\x4f\x7d\xf9\x44\xf0\x39\xe8\x36\x3d\xdd\x7f\x28\x4f\x24\x3e\xa6\xcc\x0e\x3f\x80\x8d\xa8\x4e\x35\x15\x68\x72\x9b\x78\x27\xa3\x6a\x5a\x6e\x83\x41\x07\xa0\x08\xc7\x9f\x3e\x9a\x22\xff\x08\x99\x00\x31\xc7\x0f\x3b\xed\xf9\x1c\xc1\xb9\x2d\xb3\x0f\x11\x7d\x12\x63\x7d\x05\x83\x6f\x83\x0e\x34\x85\x99\x63\xab\x24\x52\xc9\x06\x36\x46\x04\x93\x24\x09\x0c\xb5\xf8\x75\xfa\x3f\x08\x2b\xef\x04\xdd\x90\xa6\xc7\x31\x2f\x1d\xa3\x9b\x44\xb0\xa8\x2b\x78\xd8\x98\x62\xf5\x00\x7e\x70\x3e\x74\x79\x88\xe3\x9e\xb6\xab\xaa\x88\xd8\x7e\x31\xe7\xad\x38\xdd\x55\xb6\x6a\x0b\x9f\xa4\x0a\xe5\x8d\x12\x04\x01\xa2\xea\xd0\x84\xa5\xe7\xa8\xbe\x84\xb4\x03\xb4\x19\x25\x5f\x6f\x08\x36\x1c\x54\xe9\x5b\x1e\x41\xb6\x76\x97\xec\xda\x36\x54\x36\xd2\xe7\xa5\x39\x74\x22\x19\x5a\x1e\x37\x10\x56\x10\x38\x88\xe3\x62\x47\x9e\xb3\x4c\xe4\x3e\x0f\xb1\x50\xef\xcd\xbd\x6c\xc2\x1a\x20\x89\x2e\x81\xa2\x55\x44\x47\x94\x83\x15\xaa\xc7\x3e\x1f\x37\xad\x67\x88\x14\x70\x67\xf7\xf3\x7d\x4d\x0d\xec\xfb\x23\xb0\x6d\x63\xe0\xd1\x16\x30\x33\xc3\x30\x3a\xd8\xb1\x27\x4b\x84\x67\x82\xbf\x24\x46\x88\x1d\xe3\xc6\xe9\xe8\x44\x5f\x90\xe2\x54\xf9\xdd\xb2\x02\xa4\x86\x3c\x38\x54\x89\x2b\x88\xa1\xbe\xc6\x6d\x7f\x4c\xd6\x30\x31\xee\xa7\x6e\xb5\xd7\x4e\x84\xd2\x97\x0d\x25\x83\x93\xa8\x51\xbc\x56\x55\xfe\x80\x88\xc5\xe0\x0a\xf7\xb1\xc0\x01\x32\x58\xd7\x43\xf8\xb1\x8b\x5d\x1b\xcd\x94\x36\x96\x3e\xae\x57\x7c\x23\x2a\x53\x65\x1d\x51\xdb\x8f\x22\xc2\x48\x26\xae\x31\x67\x3b\xef\xae\x4a\xe2\xab\x18\xbb\xa0\xe7\x72\xc7\x1d\xe9\x0d\x5c\xf9\x7c\x88\x24\xe8\xd2\x17\x7d\xf1\x6a\x1e\xae\xd1\x71\x42\x89\x58\xa9\x4e\x01\xdd\x4b\x30\x88\x5d\x07\xf3\x29\x06\xd7\x37\x81\xb0\x1b\xce\x48\x8f\x0c\x10\x32\x45\x01\xda\x57\x12\xbd\xc1\xb2\xb4\xc3\x20\x39\x76\x94\xee\x99\xfe\xcc\x6e\x5e\x5f\xb0\xd7\x1a\xdb\x60\x2a\x2b\xad\x76\xd3\x12\x41\xae\xa9\xaa\xb7\xa7\xcd\x85\xa0\x2b\x6d\x62\xc8\x0a\xde\x20\xb3\x13\xa0\x90\x74\x52\x41\x63\x08\x7d\x51\xa7\xbd\x4d\x70\x28\xc0\x50\xc2\x4e\x73\x68\x30\xe1\x26\x6f\xe1\xf7\xc1\x42\x61\xc0\x9b\x18\x50\xf3\x2e\xde\x7d\xf9\x38\x1f\x1d\x72\x24\x37\x20\x95\x77\x91\xbb\x79\x28\x69\x17\xdd\xe1\x95\xec\x36\x34\x91\xc4\x6b\x76\xe4\x48\xcc\x32\x29\xdb\x41\x91\x71\xb7\xf6\x85\x58\x79\xca\x9e\xe1\x69\x5b\xff\xe1\x20\xa5\x2c\xee\xcc\x09\xcb\x7b\x3a\x21\x07\x49\x5d\x81\xd8\xe0\x76\x73\xee\x23\x75\x9f\x84\x55\x66\xbf\x1b\xfc\x11\xe4\x9f\xeb\x13\xa5\x49\xc5\x78\x74\x89\xd2\xb9\x3e\xc3\x27\x18\xd2\x11\xd2\x0a\x98\x46\xdc\x22\xdd\xb9\xea\xc4\x23\xbe\x39\x44\x85\x38\xd4\x38\xfd\xd4\x76\x68\x1a\x8c\x4e\x54\x8f\xb9\x0f\x4a\x12\x6c\x64\x54\xfe\x75\x7b\x70\x3b\xf2\x31\xe1\x2d\x24\x13\x83\xea\xef\xc1\x53\x67\xcb\x7d\xbe\x8f\xc4\xf0\x99\xb7\xbb\x8c\x8d\x1e\xb6\x6b\x72\x74\x50\x68\xe4\x3b\xfa\xfa\x0d\xe9\xb6\x10\x17\x04\xa6\x18\x3a\xb4\x87\x34\x8a\x51\x57\xc3\x91\xaa\x96\xf1\x25\x2d\x20\x19\xf4\x07\xb7\x48\xe8\x29\x45\x2b\x8c\x63\x94\x3e\xd4\x99\x4e\x64\x8d\x67\xc0\xa3\x91\x5a\x48\x50\x12\x18\xc3\xe9\xda\x21\x82\x4f\x0a\xc2\x86\x1e\x9c\xac\xd6\x41\x93\xc2\xbf\x6a\xbe\x4a\x19\x4c\xd0\x73\x4b\xb5\xb6\x2e\xfc\x73\xb8\x7c\xc8\x64\x5b\xa7\xdc\x86\x6d\x32\x83\x10\x40\x66\x9c\xa9\xeb\x1f\x44\x50\x1b\x05\x0c\x53\x3e\xec\x01\x6e\x3c\x72\x5c\x80\x55\x61\x4b\xee\x28\xa8\x53\x5e\xbe\x4e\xaf\xc8\x3b\x25\xab\x57\xab\x1e\x8a\xae\xf4\x9f\xdd\x6a\xb2\xbe\xa3\xd9\x10\x6b\x42\x69\x97\x88\x7c\xee\xd0\x37\x18\x6b\xa4\x3b\xc6\xb5\x1d\x4e\xab\x21\xbf\x82\xb5\x8b\x5f\x08\x48\x16\x00\xad\x21\x55\xab\x89\x0f\xeb\x4c\x5a\x3c\x69\x0a\xfe\xdf\xc3\x9c\x80\x09\x29\x97\x8e\xa5\xbc\x95\xea\x79\x9b\xd9\x40\x1d\x95\x39\x8c\x58\x6a\x22\xaa\xfb\x9c\xb0\xad\x0c\x03\x99\xd4\x68\x8d\xce\x15\xb0\xd6\x1a\xee\x57\xc5\xa3\xde\xbb\x42\xb0\x08\xd8\xda\xe4\xa0\xd5\xa6\xad\x5e\xe3\x61\xe6\xb8\x7c\xa9\xe5\x1a\xf7\x14\x44\xe7\x10\x1d\x39\x14\xe5\xc3\x70\x22\x7d\x9c\x96\x84\xcf\x77\x6c\xa5\xcc\x28\xab\xdd\xec\x85\x57\x28\xb7\x4a\x46\xae\x43\x54\x70\xb7\xd7\xb1\x87\xf0\x6f\xa9\x9f\x21\xcc\x58\x39\x4b\xdb\x52\x80\x2f\xf7\x65\x92\xca\xd5\x5e\xe7\x2d\x4b\x06\x06\xf2\x83\x5b\xc0\x86\xe4\x48\xc7\x79\x2c\x60\xcd\x03\x82\xe1\x98\xac\x93\xc5\xd9\x62\x6b\xd4\x1f\x79\xf8\x07\xca\xf0\xca\xb2\x93\xc5\x22\x50\xce\x81\x8e\x19\xfe\x45\x3a\x0d\xa6\xfd\x7d\xa2\xbc\x6e\x65\x9d\x39\x21\xf5\xa4\x4a\xb6\xfa\x8a\x42\xe9\xeb\xb2\xaf\x7b\xb5\xe3\x6d\x1a\x4c\x2c\x99\xe9\xe9\x2f\x93\x97\x10\xf5\x98\xdf\x4f\x20\xe4\x5e\x7a\x1d\x2b\x04\x30\x8a\x77\x5f\x31\x2a\x3f\x69\xf2\x1e\xce\xba\x3b\xf4\x80\xce\xb8\xb3\x92\x57\xd9\x3e\x3d\x43\xa0\x49\x4c\xca\xab\xa7\xac\xde\x90\x0c\xe1\x5b\x9a\x06\x7f\x8e\xe6\xc6\x10\x38\xcd\x3f\xc7\xd0\xc1\x30\x81\xc4\xeb\xf8\xe2\x32\x68\xf6\xa0\x7d\x16\xf5\x60\xcb\x20\x69\x28\x0c\xce\xc2\x68\x0c\x69\xf8\xd6\xcb\xfe\x10\x61\xa8\x03\x74\x66\x4f\x8e\x75\x5e\x98\xb6\x88\x32\xfa\x04\x7c\xe0\xe6\x69\x92\xe6\xaa\x28\x19\xc4\x88\xe9\x4f\x4e\xd2\xc4\x4a\x45\x31\xb4\x49\x20\x01\xb5\x8d\x8d\x85\x06\x0a\xb9\x8e\xac\x88\x91\xc2\xe6\x9e\x02\x34\x4a\x95\x6e\xa7\x57\xd9\x10\xb2\x82\xef\x06\x64\xc7\xb1\xa9\x15\x62\xfb\xcf\x7f\x83\x7b\x51\x45\x2e\x3f\xcc\x14\x3e\xc4\x39\x58\x30\x16\x6a\xa6\xb0\x2f\x51\xf6\xab\x67\xa1\x84\xfb\xb7\x8c\x0c\x40\xce\xf0\xf5\xb3\xd7\xc3\x8c\x03\xa3\xd8\x8c\x6a\xc6\x17\x89\x8f\x0f\x00\x4e\x17\x06\x39\x29\xca\x50\x0f\x1a\x74\x06\xf0\x80\x01\xe1\xb7\x39\xde\x5c\x05\x56\xb5\x19\x6b\x55\x08\xcc\xb7\x3c\xee\xa3\xcf\xdc\x87\x59\xa5\xf0\x69\xdd\xcd\x90\xe2\x87\xee\xd6\x28\xc0\x4c\xfd\xdf\x42\x4b\x2e\xbd\xde\x86\xe2\x3a\xfb\x48\x57\x80\xeb\x17\x1b\x2e\x59\xe3\x6a\x7c\x16\xca\x02\x45\xc3\x4c\x36\xc9\xf0\x75\x58\xb5\xc3\x91\x19\x6f\xf1\x23\x7d\x42\x70\x2f\x5a\xbb\x34\xe6\x1a\xca\x0d\x7c\xd0\xda\xeb\x0e\x49\x88\x7b\x2c\x25\xac\xb5\x0b\x8b\xe1\x24\xb2\x11\xa7\x09\xb1\x23\x51\x16\x92\xcc\xb2\x13\xa0\x35\x91\x26\x44\x50\x46\x52\x1b\x0b\x22\xcc\x87\xb2\xbb\xc3\x62\x45\x76\x1b\xb7\x7a\xa4\x0e\x7b\xa4\x11\x9a\xfd\xe3\x3e\x5f\xad\x77\x04\x5a\xc3\xf8\xb0\x21\xca\x8b\x08\x29\x14\x9c\x35\x88\x21\x0c\x9f\xe9\xfc\x6f\x27\x70\xd4\x54\x1d\x01\xa4\x5c\x6a\xbf\x8c\x6c\x48\xa2\x8b\xc3\xb8\x43\x16\x36\x7e\x7c\x88\x7b\xcf\x23\xd6\x8c\x3d\x90\x66\x68\x1c\xa4\x9a\x01\x01\x78\x5f\xb5\x18\xfb\xd0\x37\x0c\x51\x91\x02\x1c\x49\x2e\x24\xd9\xe1\xa3\xf4\x9b\xe0\x1f\x43\x81\x94\xd0\x26\x9c\x58\xc6\x84\xe5\xe1\x6f\x08\xb5\x26\xe8\xe7\x09\xf8\xbe\xd4\xa9\x3d\xb7\xbd\x50\xdb\xe9\x94\x26\x26\x94\xcf\xc6\x83\xac\x06\x52\x76\x2e\xfc\x9f\xcb\x2e\xa8\xca\x48\x8f\xfa\x8e\x4e\x14\xdc\x07\x3d\x09\xdb\xff\xa8\xee\x84\x95\x28\xef\xab\x2f\x08\x88\x9c\x56\xfb\xa8\xa3\xee\xc9\xb5\x39\xdc\x2e\xb2\xcf\x59\xa0\xc9\x30\x77\x85\x57\xb3\x42\x08\xff\xcb\x39\x18\x97\xaa\xe0\x07\xbc\x4e\x3f\x9c\x90\xc3\x09\x0f\xb4\x16\xe9\x5d\xb5\x97\xa9\x84\x44\x20\x32\x6e\x36\x5e\x8a\xe8\x6e\xad\xfc\x78\xa2\x4b\xb7\x03\x2f\x71\x74\x24\xa2\x09\xd4\xca\x65\x18\xd8\x5b\x30\xc0\x6f\x4f\x3e\xff\x3e\x40\xf3\x9a\x53\xe4\xad\xa2\xc1\x4b\xf3\xf0\x56\x75\x85\xbe\x6e\x72\x56\x4b\x95\x9a\x2b\xb9\xdd\xfb\x2c\x54\x64\x45\xd6\xf2\x6f\x24\xdc\x34\x57\xa4\xf1\xd6\x21\x7b\xa3\x4d\xc1\x51\x24\x6e\xa0\x5d\x00\x5b\x98\xe9\x84\xae\xa2\xb4\x16\x07\xd3\xaf\x22\xca\xae\xef\x41\x96\x85\x9e\xc6\x8f\x55\x4d\xf2\xf5\x63\xe9\x20\xa1\xb8\x18\x0f\x37\xa0\xa7\x89\x57\x3e\x38\x2f\x3f\x85\x13\x5b\x64\x78\x7d\x4d\x9d\x76\x68\xc8\xee\x2b\x77\x94\x86\xc0\x3f\x4c\x95\x7e\xfc\x2f\x97\xb6\xc0\x8c\xcb\x0e\x5f\x69\x08\x93\xcf\x67\x94\x71\xe2\x89\x7a\xce\x06\xe3\x25\x96\x43\xac\xef\xf2\xc3\x87", 4000);
*(uint64_t*)0x200013b8 = 0xfa0;
*(uint64_t*)0x200013c0 = 0x20001140;
memcpy((void*)0x20001140, "\x77\xd1\xef\x2f\xb7\x09\x54\x97", 8);
*(uint64_t*)0x200013c8 = 8;
*(uint64_t*)0x200013d0 = 0x200012c0;
memcpy((void*)0x200012c0, "\x01\x5a\x4e\x7c\x26\x58\x3d\xa7\x3c\x6e\xc7\xa5\xd6\xd3\x4a\xcf\x5d\x02\x6a\x68\xfc\x6e\x50\x28\x0a\xf6\x27\x64\x3b\x9d\x31\xd5\x3f\x90\xb4\x7a\xba\xce\x53\xef\xdc\x0e\xcf\x2d\x4a\x14\x68\x77\x34\x48\x38\xaa\x4a\x86\xe3\xeb\xc5\xee\x88\xe2\xcb\x02\xa4\x5e\x34\x35\x86\x4d\xb9\x1a\x4a\x9a\x72\xbd\x47\xca\xb9\xe8\x07\xa1\x61\x42\xbd\x8a\x24\xf9\x4e\x54\x3c\x4f\xaa\x61\x12\x4a\x04\x93\xbe\x52\x7f\x05\x0c\x2b\x61\x44\x40\x2b\xc5\xf5\x80\x80\x0a\x45\x52\x89\xdb\x06\x43\x1c\xe7\xe0\x4a\xb6\x62\xe4\xa3\x81\x24\xd3\x87\x64\xfb\xef\x67\x1a\xb2\x90\xf5\x56\x8a\x4c\x29\x9f\x90\x1d\x1f", 145);
*(uint64_t*)0x200013d8 = 0x91;
*(uint64_t*)0x200013e0 = 0x20002140;
memcpy((void*)0x20002140, "\xbc\x92\xa9\x3e\xd1\xb2\x0c\x3e\x90\xb7\x3d\xf4\x25\xe4\xdb\xe2\xae\x33\x22\x69\xc1\x52\x1e\xda\x1b\x19\x13\xd1\x8d\x52\x98\x6c\xc6\x73\x7a\x42\x8c\x31\x11\x60\x07\x01\xeb\xdb\x50\xe6\x1d\x34\x2f\xcb\x1f\x38\x78\x6e\x85\xf0\xc3\x7e\x96\x5f\xcd\x09\xdd\xa0\x21\x73\x4c\x79\x24\x2a\x7f\x09\xcc\x69\xff\x92\xcd\x35\x3b\x17\xdd\x1a\xb4\x06\xce\x20\xa9\xdf\x07\xa6\xbd\xd4\x6e\xf2\x8b\xb4\x30\x47\xc0\x64\x18\xb6\xb2\xc1\x0f\xad\x2f\xcf\x79\xc8\x47\x6c\x76\xac\x79\x6b\x3b\x25\x56\x20\x24\xcf\x51\x3e\xf2\xaa\x4c\xd5\xd5\x02\xea\xa6\x71\xfd\x6a\x9e\xdb\x56\x34\xd5\x45\xc2\xf0\x18\xdf\xd6\xec\xbb\xdd\x74\xb9\xda\x35\x99\xdb\xb6\xa4\x99\x32\x3a\xde\x3c\x07\xcc\xc2\xb7\x4b\x4d\x96\x20\x8f\x77\x16\x79\x97\x07\xa4\x52\x98\xf1\xaa\xe1\x31\x1b\x42\x51\xd8\x16\xef\xbc\x5a\x21\xcf\x37\x3a\x4b\xc4\xad\x9c\xf6\x91\x6b\xd6\x1e\xda\x42\x80\xb6\x10\x64\x70\xa5\x68\x73\xef\x98\xa0\xe3\xad\x1d\xc0\x4f\x9b\xdb\xbf\xdb\xec\xf8\x46\x2a\x84\x5d\xd6\x84\x17\x9f\x22\x12\x33\xaf\xde\xd6\xa8\xf1\x03\xff\xe7\xb7\xa9\x54\x7a\x69\x9c\xf9\x19\x64\x92\x91\x03\x2f\x8a\xa0\xdb\x60\x97\xae\xea\xd5\x34\x98\x50\xfe\xaf\x4d\x3c\xbe\xe9\xb0\x4f\x73\x35\x7a\xa9\xb6\xff\x79\xb7\x11\x07\xde\x7c\xdb\x54\x1e\x23\x6c\x9d\x03\x62\x82\xcc\x8c\x6c\x8c\xe4\xca\xf5\xd5\x9c\xbd\x30\xf3\x79\x3c\xd1\x6e\xc0\x80\x3e\x85\x3d\xa9\x4f\xe6\xc3\xe7\xcf\xe1\x4e\x10\xc2\xaa\x1e\xf8\x83\xf4\x87\x5e\xd5\x5b\x23\x65\xbb\xaf\x97\xea\xfc\x75\xa3\x9f\x69\x60\x26\x6c\x51\xee\x94\x91\x9c\xa0\x56\x15\x65\x7e\xb6\x42\x08\x92\xf5\x20\xbd\x8a\x03\x3f\x92\x66\x92\x0a\x20\xf9\xeb\xc5\xe9\xaf\xe2\x17\x5e\x2a\x36\xe5\xde\x1e\xa0\x43\x22\x2c\xd1\x62\x74\xae\x8c\x00\x42\xf3\xcf\x5f\xd4\x19\x24\x80\xc9\x54\xa1\xbe\x89\x1d\x0d\x47\x99\x2a\xcc\xf4\xe2\x96\x75\x3a\x21\x15\x88\xf6\x35\xff\x86\x4a\xc5\x20\x45\x49\x28\xf7\x47\xa8\xb0\x69\xf0\xb5\x07\x9f\x7f\x75\x41\xc7\xa8\xb3\x36\xc8\x5e\x8f\xe2\xd9\x71\x3d\x39\x81\x7a\x0d\xdf\x77\xb9\x8b\x52\x72\xca\xdb\x3a\x33\x21\x45\xab\x7c\x25\x60\x8c\x7a\x9c\x8f\xd8\x2b\x36\xd2\xb8\xed\xae\x74\xc9\x56\xa9\x12\xca\xc9\x06\x16\x58\xce\x71\x3e\xfb\x4c\xe7\x5a\xbc\x7e\x35\xc1\xc1\x6d\xe0\x8c\xe1\xb3\xba\x4d\xb3\xae\x9e\x23\x47\xd3\x7f\xdc\x2b\x76\xec\xd2\x6b\x94\x48\x9f\x50\x4c\x17\xf2\x22\x75\xf7\xfd\xa2\x79\x0e\x93\x12\x61\xbe\x3a\x0e\x67\x09\x7e\x7e\xc4\x3c\x68\x23\xbd\x07\x19\x13\xa4\xec\xa8\x48\xb4\x0b\xa8\x92\xb0\xa9\xcc\xaa\x40\x8b\xfe\xa2\xd3\x74\x9e\x10\x59\xd2\xbb\x70\xa5\x9f\xef\x39\x45\x3c\x4e\x34\xf8\x80\xde\x2d\xe2\x00\xed\xa7\x3f\x87\x30\x9c\xa6\x0e\x2f\xa3\x4b\x66\xd4\xde\x22\x5a\x7f\x81\x17\x94\x48\xd6\x13\x40\xb3\x6c\xb8\xba\x69\xe7\xf3\xd1\x4f\xae\xcf\x06\x70\x63\x4a\xbb\x15\xa0\x9a\x68\x7d\xe5\x71\xdf\x08\xf9\x19\x7b\x01\x50\xd7\x99\xbb\xd6\xa1\x9c\x37\xa3\xf0\x36\xaf\x03\x96\x21\xd8\x7a\x66\x1e\x4e\x68\xa0\x82\x23\x12\x97\x8a\xdd\xd5\x66\x37\xc2\x4e\x67\x4a\x75\xd3\xe9\x3c\x33\x0f\x90\x08\x14\xab\x66\x47\x47\xaf\xde\xd7\xf8\x0b\x37\xa4\x77\x77\x29\x32\x37\x21\x7d\x4c\xf9\xe1\x7d\xed\xff\xd4\x5a\x98\xb0\xce\xd4\x84\xbd\x13\x0e\x83\x65\xb3\x51\x74\x23\x2a\x2d\xc9\xfe\xb1\x80\xf5\x11\x5e\x8a\x53\x11\x1c\x69\xef\x56\x69\x0d\xc4\x11\x88\x5c\x87\xe0\xaf\xa8\x92\xb1\xdf\x8d\x80\x52\x63\xee\xef\x00\xb5\x11\xc5\x7e\x62\x60\xd1\xcd\xb2\x6c\x4e\x11\xa7\x24\x04\x92\x63\xa2\x6b\xf9\x45\x16\x0b\xb9\x27\xef\x23\x88\xc8\xfc\x00\x1f\xbe\x2b\x8f\x97\xa8\x33\xd9\x68\xa3\x0a\xec\xfe\x2c\xb2\x44\x6b\x57\xce\xb6\xa4\x59\x3e\x9f\x29\x60\x69\xe8\x8b\x77\xe9\x28\x04\x47\x6a\xc7\x3f\x57\x70\x86\x52\xbd\xae\x3f\x73\xb5\x4b\x27\xee\x08\xac\x52\xec\x20\x02\x36\xa3\x1f\xc3\xe6\x18\xae\xcb\xa7\x6b\xb4\x62\x7b\x51\xeb\x56\x8d\xc4\xef\x86\x57\x5e\xa3\xd9\xc6\x10\x8b\xdd\x9b\x11\x90\x89\xf6\x11\x24\x2a\x31\x64\x1f\x0a\xbb\x1c\xec\xb4\x7f\x3d\xdc\x93\x99\xfb\x46\xff\x07\xeb\x08\x1a\xd7\x39\xeb\xa6\xf2\x1d\x8e\x37\xc2\xcb\xe8\x13\xbf\x69\x9d\x25\xb1\x5f\xe1\xc1\xe8\xb9\xa3\x8a\xf4\xf7\x34\x9d\xcb\xd9\xfe\x00\x8b\x7f\x99\xb6\x36\xf4\x3e\xfb\xd2\x89\xb1\xe2\xf9\xe7\x15\x29\xff\xa1\xb2\xc5\xd2\x10\xa6\xa1\x86\x04\xd1\xb3\x1e\x69\x5e\x9d\x42\xc4\x71\x63\xee\x1c\xe7\x03\x95\xab\x23\x17\x62\xcb\x1d\x74\x9d\xba\xdd\x9f\x36\xf9\x6b\xa0\x0e\xc5\x58\x83\xb0\x48\x3c\x4e\xae\x92\x53\x53\x3e\x7e\x2e\x6c\xd2\xec\x3c\xe8\x5d\xd1\xec\xdf\x47\xe6\x27\x11\x53\xbc\xdf\x36\xf2\x58\xd1\x24\xd7\xa9\x49\xab\x97\x9f\x6a\xa5\xc6\xcc\x1e\xe1\xd6\x13\x95\x5b\x1f\x85\xd9\x06\xb3\xe6\x6c\xd5\xdf\xa4\x7a\xbf\x23\xea\x30\xe1\x7a\x75\xfb\x93\xd8\x3b\x52\xdf\x71\x3a\x14\xce\x94\x65\xe2\x40\x99\xc4\x29\x62\x85\xfd\x59\x06\x43\x80\xfb\x03\x50\x6a\xf2\x67\x7f\x41\x5a\xe8\x27\x23\x50\x2e\xc5\x83\xbe\x8d\x31\x48\xbf\x9e\x3a\x21\x26\x6f\x99\xda\x9d\xa6\xd0\x9a\xbf\xa0\xdf\x62\x19\x0b\x95\x51\xad\xf7\x6b\xf7\xb8\xcb\x54\x9e\xc6\xe3\x53\x2f\x3d\xfd\x19\x69\xbf\x62\x13\xd4\x77\x94\x5c\x1a\xd6\xcc\xf1\x19\xce\x2b\x44\x44\x09\x0c\xb2\x03\xd0\xf7\x5c\x12\xed\x85\x5f\x44\x3b\xd2\xfd\xa9\xbe\x7d\xb8\xe7\x93\xbe\x62\x62\xc3\x2e\x27\xfb\x10\x25\x62\xf3\x61\x1d\x04\xdf\x42\xe2\xaf\x8f\xf9\x2b\xba\x90\x9e\x43\xcc\x6f\x25\x65\xd5\x6a\xa1\xf3\x35\xb8\x0b\xd3\x44\xa9\x9c\xf1\x95\x66\xa0\xcf\x92\xe6\x95\x83\x15\x80\xdf\xad\x12\xe9\x4f\x8d\xc8\xbe\x04\xc6\x1b\x27\x35\x50\x6c\xe8\x35\x62\x05\xe6\x82\xbd\xd3\x39\x6d\xba\xac\x41\xab\x13\x4e\x39\x8f\x8d\x79\x88\x2c\x77\xd2\x19\xe9\xbf\x72\xc1\x29\xdd\x30\x14\xe5\x65\x2f\x20\x54\x86\x5d\x30\xbb\x28\x12\x56\x76\x2f\x25\xfe\x23\x26\x7d\xa2\x36\xa9\x1c\xe2\xe1\xee\x23\x0e\xc9\x9d\xdd\xe8\x4a\x6b\xda\xb8\x90\x83\x5a\xf3\xdf\x72\xb6\x82\xba\xf0\x92\xf2\xb2\xfe\x25\xd7\x3b\xa5\x04\xa4\xa3\xc4\x91\x8a\xbc\x47\xf0\xcf\xc5\x67\xe0\xb0\xcf\xd2\x96\x03\xd2\xee\x74\x0e\x59\xe0\xe6\xf3\x28\x8e\xb4\x2f\xf8\x72\xb9\xe3\x30\x49\xe9\xdc\x35\x15\xad\x27\xe4\x90\x5a\xe4\xb4\x0e\xaf\xe2\x45\x2a\x02\xfd\x7c\x08\xa0\x15\xb0\xcb\x59\x07\x51\x3c\x94\x5e\x4e\xad\x16\x29\x23\x47\x63\xfd\xd1\x9f\x4b\xf7\x39\x2a\xfc\x46\x1c\x04\xcd\x6b\xa3\x2e\x39\xb6\x58\x76\xf6\x52\x82\xb7\xb6\xbb\x2e\x31\x11\xf9\x6e\x97\x37\xb3\x82\x74\xd7\x1d\xf3\x7a\x45\xb3\xf5\xe6\x6b\xc0\x94\xe6\xaa\x83\x65\xfa\xd1\x46\xbf\xf6\x3d\x10\xbe\x09\x89\xb8\x41\xbd\x33\x9a\xe5\x87\xf0\xaa\x16\xf5\xa1\x70\x48\xeb\x75\x60\x48\x3c\x05\xc6\x41\x01\xe4\x68\xd3\xcd\x56\xb5\x70\x5c\xec\x7e\x9b\x15\xc0\xf1\x14\x79\xa8\x58\xe9\x56\x79\xd0\xd8\xdc\x00\x06\xce\x27\x6d\xfa\x1f\xf7\x2d\xee\xf9\x41\x26\x70\x5e\x1e\x19\x8e\x03\x93\xcc\xf2\xc3\x83\x84\xad\x25\xf7\x51\xd0\x1a\x75\x3f\x0c\x77\x5f\xd1\x6e\x0f\xb8\xef\xe0\x03\x4d\x6e\x73\x5a\xba\xca\xc4\x1c\x48\x40\xcc\xa0\xa9\x2b\x4f\x55\x55\x12\x7b\x7f\x23\xb2\x94\x72\xb8\xb9\xc4\xeb\xe0\x16\xfe\xcf\xf3\x4f\x78\x68\x7d\x2d\x93\x22\xf0\xe9\xfe\x93\xc1\xc3\x7e\x5b\xec\xee\x41\xf3\x51\x56\xe5\xdd\xfa\xc6\x1e\x3c\x97\x53\x1c\x98\x2d\xa4\x82\xe2\x19\xd4\x9b\x1f\xad\x9d\xc6\x29\x1b\xe6\x86\x54\xcf\x1c\x03\x8e\xc7\xe8\x54\x82\xfc\xe2\xcc\x09\xbb\xa3\xf0\x40\xd4\x94\x89\xe8\xf9\x10\x6e\xd2\x5c\xad\x1b\xd5\xd4\xb5\x8a\xe8\xcc\xb2\x8f\xf1\x27\xe9\x68\x08\x94\x82\x77\xcb\x65\x05\x2e\x37\xd3\xef\x25\xa8\xa2\x02\x27\x71\xe7\xaf\x35\xb9\xa8\xe1\xe8\xba\x02\xf8\x10\xa4\x56\x55\x61\x28\x33\x1b\xf6\x41\xb4\xbc\x97\xbb\x2d\x9c\x6c\x23\x8e\xc0\x09\x67\x65\x80\x6a\x23\x45\x5c\xea\x52\x55\x48\xea\x08\x2a\x01\x41\x84\x96\x5c\xf9\x7e\x39\xb6\x2d\xa8\x30\x5f\x61\xd2\x5c\xc0\xed\xf5\xa4\x57\xdb\x92\x32\x1b\xb3\x93\x18\x12\x5f\xc2\x22\x60\xbd\x76\xf7\x27\xad\x77\x73\xbe\xe4\x2b\xe6\x00\x37\x4d\x91\xc3\x93\xc5\x31\x8a\x30\x28\x47\xf3\x3e\x13\x5c\x34\x88\x8e\x63\xfd\x5c\x70\xb2\x23\xc6\x1e\x7e\x13\x22\xf1\xf2\x67\x76\x36\xef\xdf\xe0\xff\xad\x18\xdd\x41\x53\x61\x8b\xd2\x98\xb3\x0e\x43\xed\xa0\x5f\x47\x31\xc9\x20\x79\xb2\x93\x7b\xdc\x1d\x13\x17\x42\x9a\x4b\xe8\xe4\xde\xa0\xee\x26\xf1\xc6\x98\xbc\xa3\x2d\xbc\x32\x15\xbe\xd8\xa6\x70\x29\x78\x8c\x0c\x49\xef\xf5\x2d\x06\xd8\x01\x66\x13\x80\xc2\x0d\x0f\xab\x84\x6b\xb8\xa8\xa3\xf6\x5e\x5f\xab\xf5\x70\x4b\xcb\x45\xab\xc0\xec\xa7\xbd\x1d\x2f\x71\xb1\xfd\xf1\xb2\xd6\xb2\xf1\x5f\xe4\x2d\x37\xe4\x73\x34\x74\x9b\xc7\x73\xfb\x9f\x7b\xca\x5f\x65\x4f\x5f\x19\xfa\xac\xf1\x30\xec\x71\x55\x53\x83\xb1\xa5\xb0\xf9\x64\x47\xdf\xab\x15\xd4\x00\xcd\xd7\xc1\x13\x1d\xb0\x5c\x07\x57\xda\xd7\xc3\x6d\xd8\xd9\x5b\x74\xe5\x28\x5a\x8e\x33\x8b\x77\xd5\x5b\xff\x87\x9c\x99\x71\xa6\x6a\x10\xe1\x97\x25\x8c\x3d\x11\x08\x7a\x31\x35\x7d\x4c\xae\x27\xe6\xb3\x97\x98\x1e\x53\x24\x89\xe7\x93\x2d\x99\xc9\x31\xf0\x58\xa4\x76\x7c\x65\xa0\xc7\x63\x1c\x2f\x5a\xaf\x52\x88\x85\x9e\x6a\x4a\xd4\x41\x91\xd3\x1c\xce\x55\xae\xab\xa9\x21\x4f\x91\xb1\x5f\x70\x99\xf6\x1e\xb9\x52\x58\x7a\x6f\xb4\xf0\x2b\xfa\x8d\xb3\x34\x51\x6d\xf3\x91\x17\x1b\x3f\x1a\xa4\x4d\x09\x4d\x0e\x28\x2a\x18\x92\x63\xb0\x62\xab\x50\x27\x1d\x05\x73\x59\xdf\x26\xbc\x35\x59\x28\x4e\x23\x6b\x2f\x6c\x3b\x74\x08\x23\xde\x9a\x21\x0b\x7d\xd1\x55\xee\xec\xf3\x42\xa1\x19\x10\x52\xd8\xc0\xe6\x54\xdf\xc0\xda\xe2\x13\x8b\xda\x4c\xa3\xc2\x6c\x73\x63\xed\xfc\x10\xba\x6f\xe7\x46\xfe\x20\x4d\x40\x72\x8b\xe0\x94\x7c\x1e\x63\x73\x4c\xbb\xf5\x11\x69\xb8\x19\x75\xba\x8c\x93\x0c\x11\x4c\x6a\x18\xf6\x12\x72\x42\xec\x31\x20\xa4\x46\x48\x6a\xaa\x24\xd0\x0d\x4d\xe3\x42\x28\xc3\x13\x30\xf0\x28\x32\x9d\xbb\x48\x63\xe2\x21\xdd\x78\x07\xde\x1f\x2d\x65\xa7\xaa\x68\x8e\xa0\x77\x18\xa0\xdf\x33\xc7\xae\x02\xa5\x50\xba\xdb\xe7\xb9\xd0\x09\xa4\x1d\x03\xf2\xa9\xf4\x2c\xa8\x77\x77\x74\xef\x42\xe2\xb5\x87\x5a\xa1\x64\xba\x2a\x8c\xd9\x45\x3a\xf4\xf8\xda\xa8\x94\x5e\x9a\xbf\x23\x4f\x06\xeb\x08\x34\x7b\xd9\x76\xa5\xbe\x81\x87\x5c\xb8\x0b\x5f\x5f\x93\x9e\xf8\x68\xc4\x47\xc9\x1f\x1e\x68\xc7\x38\x4a\xcb\x64\x13\x58\x33\x71\x3f\xa0\x62\x5b\x79\x97\xe6\x35\x44\x02\x70\xa5\xec\x5e\xde\xe7\x4c\xdf\xfb\xdd\xbd\x84\xdf\xc2\xb9\xbd\xfa\xda\xd7\x35\x87\xe5\xe0\x08\x7d\x3c\x75\x1d\x93\x59\xa0\xd5\x76\x9d\xcb\x42\x04\x3c\xd0\x5b\x78\xf3\x36\x0c\x22\x99\x45\xcb\x74\xe1\x06\x8c\xfa\xda\x4f\x4d\x6c\x87\x11\x46\xcb\xec\xe3\x33\x9b\xb5\x9a\x51\x58\x06\x36\x63\xd2\x8d\x3c\x7d\xb7\xd6\x66\x4b\x9b\x83\x01\x07\xd9\x92\xf3\x1c\x0f\x6a\xa1\xef\xd8\xa9\x14\x74\x8f\x39\x82\x6b\x10\x33\xab\x62\x4e\xbc\x34\x0f\x2c\x20\x72\x38\xf8\x71\xbe\x72\xc4\xff\x1e\x54\xa9\x20\xac\xa6\xba\xd5\x02\xbe\x5d\x2c\x8a\xfe\xfe\x93\xd2\x30\x85\x5a\x2f\xcb\x6c\x8d\x2b\x26\x0b\x98\x4b\xc1\xd3\xe6\x9f\xe6\x55\x7f\x46\x45\xaf\x01\xd9\x0e\xe4\xc1\xef\xef\x6b\xcc\x6d\x35\xe5\xf7\x2f\xcc\xba\x2a\x2b\x9b\xaf\x22\x9c\x0c\x97\xdb\x6b\xa4\x60\x04\xfc\xb0\x4b\x32\x84\x15\xb5\x64\x0a\xaa\xb0\xc6\x23\x9d\x5a\x74\x69\x27\xc5\xf5\xd4\x15\x6c\x87\xd8\x48\x2d\x5f\x00\x74\x0d\xae\xef\x97\x56\x73\xf3\xc3\xe9\x1f\x3d\x4a\xb2\xdd\x38\x20\xed\x2f\xca\x29\x6f\x26\x38\x55\x1d\x53\x3e\x0a\xa9\x73\xf9\x36\x9c\x09\xdc\x3d\xcf\xc4\xcf\x90\x25\xa3\x28\x81\x31\x0c\xcc\xb3\x86\x8a\xb5\x07\xca\x72\xad\x1a\x5d\x70\x2c\x88\xf7\x4f\x8d\xb7\xef\xdd\x74\xe2\x11\x1d\xd4\xc2\x38\x2b\x10\x55\x81\x35\x0c\xc6\xbb\x14\xd4\x94\x71\xb7\xe2\x88\x69\xa4\x37\x95\x74\xf4\x94\x74\xd2\xf4\x59\xd6\xd4\x86\xb5\x75\x26\x24\x33\x8e\x11\x98\x44\x9a\x21\xad\x19\xe5\x63\x99\x41\x92\xde\x45\xd7\xe9\xe2\x09\x65\xa7\xfd\xc8\xac\xf5\xcf\x10\x51\xd6\xff\x8b\xae\xfb\x95\x8d\xc7\x45\x89\x03\xfc\xb9\x0a\x18\xc3\xb8\xc1\x98\x87\x90\x93\x3a\x4b\x3e\xc5\xff\x1f\xe0\x5f\x54\x3e\x78\xab\x51\x51\xe4\x2e\xf9\x58\x47\xa3\xcd\x8b\xdc\x12\xf5\x4a\x0a\xe2\x3b\xc7\xac\x0a\x7b\x65\x28\x1e\x72\x4d\x71\x6d\x86\x9e\x7e\xff\xcb\x7f\x9f\xa1\x93\xc0\x81\xf9\xe1\x5a\x92\xe8\x71\x6d\x4d\x72\xd1\xbd\x00\xa9\xda\xb4\xb4\x33\x06\x45\x6f\x3e\x46\x0b\xbf\x18\xcd\x86\x10\x58\x53\xd0\x7d\x0e\x19\x1d\x72\x6a\xd8\xc6\x90\x26\x01\xce\x23\xa1\xc2\x39\x65\x8a\x8b\x95\x0e\x6e\x0e\x5f\x7e\x39\x3c\x94\x26\x2b\x70\x87\xc4\x87\x3d\x9e\x18\xca\xf3\x2e\x3c\x26\xcc\x40\x1a\xc2\xba\xbc\x58\x4e\x52\xd6\x74\x91\xfd\xc6\xaf\x6d\xbd\x32\x72\xd2\x57\x75\x9e\x87\x56\xe4\xc4\xf6\x9f\xcd\x73\xad\x29\x96\xd2\x75\x5d\xb5\x43\x2b\xfb\x7a\xf7\xea\x80\xf9\x07\xbb\xc2\x2b\x57\x15\xd0\x95\xc8\xab\xe8\xb8\x1d\x77\x6f\xb7\x93\xe6\x88\x32\xfb\x5d\xb5\xb1\xe6\x3d\x61\xd2\x56\x1c\xcd\x70\xee\xe7\xc8\x38\xd5\x8d\xdc\xb9\xdb\x3e\xf1\x13\xc1\x9e\x0c\xd1\x80\xda\x3a\x7d\x67\x00\x51\x39\xa7\xf5\x9a\x44\x00\x1a\xa7\x9c\xb2\x37\xcb\xa3\xb5\xd0\x2f\xe8\x60\x84\xba\x4d\x8b\xb8\x89\xcd\x4b\xb0\xd7\xc1\x36\xe0\x75\x95\x45\x81\xff\x21\x8f\x12\xab\xee\x3a\x56\x8d\xdb\x8b\xcc\x64\x95\xc4\x31\xfb\x0c\x42\x79\xa5\x1f\xb3\x59\xb1\xdd\x4c\xbe\x7e\x47\xc4\xce\xb4\x13\x57\xc9\xf5\x29\xe6\xc0\x7d\x8d\x1f\xb2\x40\xde\x38\xb6\x5a\xef\x05\x48\xd3\xd1\x39\x01\x00\xd3\x59\x32\x95\xb0\xd0\xec\x9b\xd0\x33\x3c\xfc\xe6\xfd\x87\xf4\x3d\xce\x34\x55\x3c\x03\x71\x68\x16\x72\x90\xb1\x7e\x03\x31\xd6\x40\x4b\x0f\x76\xa7\x7a\x9d\xba\xbf\xd7\x47\x6c\x97\x24\xbd\xb1\x00\xcc\xb7\x74\xf2\xbf\xc0\xb9\x57\x01\x9b\x99\x34\x6a\x17\x84\xfe\x67\x0c\xcb\x56\xdc\x43\xce\x82\x4e\x19\xa4\x02\x13\xfe\x16\xbb\xab\xe7\x30\xef\xa1\x50\x7d\x1e\x91\x9f\xbd\x98\x76\xd2\x0a\xc9\xca\x4d\x3d\xfc\xd6\xa2\x83\x06\x30\xf7\x7a\xb5\x82\xd8\xb8\xd4\x46\x99\x99\xfb\x0f\xb8\x95\x22\x3f\xed\xbe\x95\x65\x8e\x94\x0a\x58\xb6\x16\x45\xa2\x76\x9b\x80\x0e\x90\x6b\x32\xa0\xb2\x23\xd2\xe4\xd9\x96\xd6\x9e\x15\x07\x8a\x41\x7c\x54\x23\x8d\x42\x26\xd2\xe1\x48\x86\x13\x55\xe4\x1b\x2f\xe2\x85\x6d\x9d\xf7\x24\x02\xbc\xae\x74\xcc\x05\xc0\x31\xaa\xa2\x0f\x72\xc7\xc1\xf9\x22\x64\x53\x9b\x05\x5e\xe6\xd8\x3d\xf9\x9d\x5e\xa8\x8d\x4b\x05\x77\xc0\x2c\x42\x6c\xec\x3c\x51\x59\x56\x93\x92\x47\xf5\x33\x57\xdf\x8d\x22\x4f\x80\x61\xd8\x67\xb8\x8b\xd2\xe0\xc8\x2e\x1a\x46\xd7\x8d\x40\xef\xe5\x03\x18\x69\x72\xe8\x99\x77\xf1\x0a\x87\x07\x2b\x97\x66\x70\x29\x18\xe7\xdc\x01\x62\x50\xbf\x16\x99\xaa\xd0\xc5\xb0\xfc\x68\xe6\xf9\xda\x3a\xd4\xe9\x55\xdb\x4b\xff\xb5\xa7\x96\x0e\x85\xd0\x08\x80\x93\x02\x02\x90\x48\x76\xc6\xce\x29\x29\x54\x83\xbb\x6e\x45\x68\xbd\x4a\x47\x29\x97\xd2\xcd\x91\x77\x79\x60\x84\x5e\x0a\x48\x1c\x9c\x11\x31\x0e\x2b\xc4\x87\x39\x18\x34\x36\x96\x24\x9f\xfb\xcd\x4c\x50\xbd\x9e\x61\x6a\xbf\x86\xf1\x74\xe5\xbc\x17\x65\x85\x9c\xe4\x23\xa8\x95\xec\x5d\xd7\xaa\x7c\xb1\x43\x59\x1b\x22\x1d\x1e\xba\x0a\xef\xbf\xf5\x71\x08\xbe\x0b\xdb\x84\xa7\xdb\x75\x09\xd2\xff\x86\x9b\x4d\xa3\x90\x4d\x4c\x3c\xcf\xa2\x22\xba\x36\xc9\x3d\xda\xcd\xdf\x15\xb3\x4a\x02\xbe\xa8\x59\x6c\xf3\x3e\x95\x9f\x95\xee\x24\xf1\xec\x7c\x1c\x3e\x43\x04\x91\x4b\x74\x99\xa5\x39\xbe\x24\x9a\xac\xc9\xdf\x25\x82\x53\xe1\x4b\x20\xba\xd4\x32\x0c\x29\x10\x30\xbb\xab\xa2\x8c\x8f\x6c\xce\x7d\xbb\x4d\xbb\x68\x6c\x9b\x27\x92\xc0\xf5\x16\x15\xce\x5f\x20\x31\x8e\xa9\xbc\x8a\xf8\x1d\xd3\x79\xb2\x2b\xac\xaf\x60\xb8\xe4\x1b\x1f\x17\x63\xaf\x2c\x39\x3c\x17\x59\xcb\x4d\x71\xed\x9a\xaf\xf4\x80\x54\xf4\x40\x40\x1e\xaa\x0d\x04\xb7\xe8\xb4\x1e\x8d\xbd\xbf\xd2\xcf\x4d\x37\x9f\x11\x78\x6c\x97\x4e\xee\x08\x49\xe3\xe5\x5a\xa8\x86\xe6\xdc\xde\x7b\x3f\x5c\x39\xf5\x79\x68\x86\x39\x3a\x0b\x35\x71\x99\x52\x34\x9e\x44\xc5\xfe\x0f\xd2\xc1\x1b\xe6\x82\x83\xda\x32\xcf\x7a\xec\x8d\x2d\x8c\xff\x5b\x81\x60\xc7\xf6\x78\x37", 3611);
*(uint64_t*)0x200013e8 = 0xe1b;
*(uint64_t*)0x20002118 = 7;
*(uint64_t*)0x20002120 = 0;
*(uint64_t*)0x20002128 = 0;
*(uint32_t*)0x20002130 = 0;
*(uint32_t*)0x20002138 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002100ul, 1ul, 0ul);
	return 0;
}