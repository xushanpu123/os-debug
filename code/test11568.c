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
memcpy((void*)0x20000140, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000140ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20001500 = 0x20000040;
memcpy((void*)0x20000040, "\x7f\x38\xfb\xdb\x85\xe5\x1d\x4f\x62\xcf\x44\xf1\xbd\x04\x34\xdf\x82\xea\x2e\x40\xc1\x72\x59\x10\xec\x13\xe8\xb9\x69\xe9", 30);
*(uint64_t*)0x20001508 = 0x1e;
*(uint64_t*)0x20001510 = 0x20000080;
memcpy((void*)0x20000080, "\x6f\x8a\x1c\xd5\xcd\x06\xff\x93\x30\xfd\x11\xc4\xae\xf8\x9c\x9a\x87\x94\xcc\xa5\xf5\xbb\xcc\x77\x79\x90\xa4\x6a\xc9\xa8\x74\xcb\xc7\x63\xa5\xeb\x8c\x0c\x96\x76\x83\x07\xa6\xb4\x9b\x53\xaf\x83\xae\x5f\x31\xd3\xa1\x76\xbe\x80\xe0\x11\xbe\xf9\x97\xfb\x9d\x64\x93\x64\x00\xec\x55\x3c\xa0\xc0\x93\x7c\x1b\x06\x9f\xf2\x65\x02\x2d\x14\x57\xf3\x4d\x26\xd3\x50\x17\xa8\x4e\x9e\x76\xa3\x1c\x59\x22\x30\x98\xd4\x99\x8d\xd4\x10", 104);
*(uint64_t*)0x20001518 = 0x68;
*(uint64_t*)0x20001520 = 0x200001c0;
memcpy((void*)0x200001c0, "\xa2\x3f\xc1\x96\x11\x35\x54\x54\x9a\xa6\xce\x7d\xed\x74\xa2\x93\xdc\x09\xbc\x20\xe9\x5c\x4d\xf7\xf9\xb5\xcc\x77\x1f\x39\x71\xb5\x8e\x94\xc0\xef\x53\xe7\x7c\x50\x80\xf2\xec\x65\xc6\xd0\x9f\xe2\x69\xb7\xa9\x56\xe1\x8f\xff\x6c\x7d\xe8\xe0\x0f\x8c\x56\xb5\x12\x3f\x04\xd3\xbf\x1f\x94\xc9\x08\xf5\x02\xea\x50\x85\x8c\xde\x5e\x48\x8f\xc9\xbe\x48\xf4\x27\xab\xba\x06\xc2\x51\x87\xac\xb0\xde\x1a\xef\x7e\xe2\xeb\x06\x2f\x68\x73\xdd\x4a\x0a\xb4\xfa\x5b\x1e\xbf\x58\x94\x6e\xf2\x85\x9d\xd5\x2a\x75\xd5\xaa\xfc\x81\x8d\xb1\x73\xf7\x15\xeb\xe3\x00\x44\xfa\x0c\x48\xca\x5c\x9b\xb2\x43\xba\x70\x2f\x88\xbf\x58\xb1\x08\xd8\x70\x01\xd8\xcb\x15\xb8\xb5\x28\xf3\x72\x63\x81\x52\x68\x97\xd0\xcd\xd8\x92\x8d\xa5\x9b\xaf\x39\xff\xe5\x78\x4d\xe4\x82\x63\x78\xb1\x88\x07\x56\xcb\x33\x18\x65\xe6\x94\xdd\xd6\x74\xc8\xd4\x87\xc7\xd5\x67\xc6\x6d\x0b\x19\x7a\x70\xbf\xc5\x82\x77\x50\xba\x0a\x7d\x01\xad\xec\xde\x36\xe3\x9f\x03\x3d\x8c\x9d\x86\xa3\xea\xa8\x8f\xff\x52\xce\xcf\x86\xcd", 239);
*(uint64_t*)0x20001528 = 0xef;
*(uint64_t*)0x20001530 = 0x20000300;
memcpy((void*)0x20000300, "\x6a\x4f\x2e\x69\x57\xcf\xeb\x71\xc1\x72\x84\x41\x42\xdf\xca\x94\xda\x71\x77\xa5\x4c\x6c\x2b\x14\x59\x87\xf9\xa5\xc7\xc7\xc3\x8f\x0a\x0d\x59\x48\xd1\x09\xe1\x17\x31\xa5\x52\xb8\xee\xe2\x8c\xb1\xae\xd1\x4b\xd9\xc2\x48\xaa\xfb\xb6\x81\xf9\xa1\x0e\x5f\xae\xfb\x82\xf4\xba\xe5\xb4\x55\xcd\xb0\x0d\x31\xe5\xc0\x86\xc6\x37\x28\xa2\x3c\x00\xd5\xdc\xf8\x07\xd9\x24\x7e\xbd\xda\x61\x03\xb1\x07\x79\x6c\x52\x93\x62\x4d\xbb\x7d\xfc\xe4\xf0\xab\x49\x02\xac\x87\x95\x4c\xec\xe1\x25\xbc\x3d\x22\x02\x77\x5b\xa8\x52\x01\xf7\x2d\x80\xb9\x5a\xd9\x6d\xa0\x8f\x83\x92\x18\x0f\x99\x5b\xa3\xde\xc8\x16\x28\x38\x87\xd1\x87\xef\x7d\x98\xeb\xfe\xe8\x47\x6a\x43\x59\x88\x65\xcf\xb9\xb9\xfe\x4d\x85", 168);
*(uint64_t*)0x20001538 = 0xa8;
*(uint64_t*)0x20001540 = 0x20000100;
memcpy((void*)0x20000100, "\x26\x2b\xf4\x45\x27\xb0\xa8\xcc", 8);
*(uint64_t*)0x20001548 = 8;
*(uint64_t*)0x20001550 = 0x20000440;
memcpy((void*)0x20000440, "\x16\x48\x42\xf4\x6e\xbd\x28\x3f\x89\x87\xc2\x86\x0d\x00\xe2\x57\x54\x4d\x84\x89\x7d\x4a\x10\x76\x36\xcd\x21\x32\x5d\xde\xe7\xd7\x43\x25\xb7\xcd\x49\x46\x3a\x98\xad\x59\xb2\x5c\x0f\x70\xa4\x5a\x6d\xe5\x25\xca\x96\xb1\xfc\xd6\x7e\xa5\x9e\x47\x6d\xa5\x91\x7c\x7c\xd6\x12\x99\xff\xc7\xf0\x4d\x89\xca\xca\xf5\x0d\x11\xc0\xc0\x76\x96\xfe\xe6\xff\xcc\x97\x91\xb0\xc0\x44\x05\xd6\xc3\x35\xfc\xc5\xa6\x3d\x39\xeb\x15\xe6\xad\xa8\x73\x08\xa6\x38\xda\x4b\x37\xf8\x37\xaa\xd0\x0b\x01\x4c\x7b\x63\x16\x3e\x8e\xbb\xb9\x79\xa5\xab\x57\xd6\xb2\x86\x63\x76\xe8\x79\x88\x4f\x12\x65\xb0\xd9\xaf\x9e\xe7\x9b\x76\x15\x76\xbd\x14\xff\xa0\x61\x84\x22\xce\x3d\xa8\xa3\xf4\x84\x5d\x48\x8d\x0f\x25\x3d\xda\x44\xfc\x5e\x30\x6d\xb1\x92\x94\xad\x35\xc5\x8f\xca\x04\x43\x73\x9d\x8a\xa1\xa7\xe8\xfc\xf3\x89\xfa\xea\x59\x92\x3f\x26\x0c\x68\xa7\x7f\xa9\x39\xd8\x1f\x71\x09\x9a\x21\xb0\xcd\x5d\xe1\x95\xb7\x1d\xd4\xa0\xd6\x2a\xee\x93\x7c\xe9\x59\xe8\xae\x7b\xc4\x5b\x87\x1f\xf7\xb8\x38\xf3\x4f\x6f\xd0\x8d\x24\x41\xb4\xfb\x87\x6e\x17\x18\xa8\xfa\x99\xc1\xaf\x01\x38\xd6\x19\x40\xe7\x85\x73\x83\x0e\xe5\xf8\x9c\xf4\xba\x9d\x49\xd9\x99\xca\xa0\x1f\x9c\x43\x2e\x07\x69\xad\x8c\x3d\x69\x55\x35\x9e\x57\x38\x84\xd8\x69\xcf\xce\xcb\x3c\x13\xb8\xfb\xb4\x11\x4d\x19\xd0\xb4\x4f\xd6\xf8\xad\x90\xc3\x45\x96\x5d\x53\x6a\xb0\xa3\x38\x41\xc0\x7d\xd9\x6c\x6c\x06\x07\x65\xf6\xf8\x75\x7d\x01\x7d\x55\xa2\x27\x52\xb5\xf0\xe3\xc0\xec\x4b\x1c\x5d\xa4\xe2\x8d\x99\x09\x23\xa4\x81\xae\x05\x97\x76\x28\x0e\x29\x87\x3a\x3b\xe7\x84\xcc\xfc\x09\x6c\x04\x7b\xcc\x42\x85\x4a\x7d\x6f\x0c\x62\x12\x0d\x60\xfe\x18\xdb\x24\x7c\xbd\x3a\x29\x99\xb5\xdf\x76\xc4\xf7\xa6\x59\x44\xb4\xe8\x6a\x03\x79\x25\x06\x25\xd5\xb6\x50\x59\x69\xae\xf1\xb5\x6a\xfc\xe2\x77\x84\xbd\x6a\xf0\x90\xee\x79\x9e\x28\x19\x64\x66\x08\x9f\x8b\x6c\xda\xb9\x18\x4c\xbb\xa1\xaa\x9d\x98\xc6\xec\x1c\xa7\xdb\x8d\x57\x8d\x93\x4e\x80\xf7\xd2\x72\xb0\xc9\x14\x25\x2f\x4c\xa2\x47\x75\xcb\xd7\xba\x3a\xf3\x58\x6c\x82\x83\x1a\x27\x8b\x94\xc3\xbe\x2c\x0c\xdc\x18\xac\xd8\xb9\x55\x2c\xf7\x9e\xa0\xad\xce\x1a\x6f\x75\xb3\xec\xfe\xc4\x20\xcc\x94\x31\xfa\x28\x93\x4e\x4a\xff\xa3\xb7\xad\x8e\xe7\x83\x6a\x3b\x5d\xe6\x7d\x2c\xfd\x1d\xc6\xc5\x8a\xea\x31\xfb\x19\x5b\xd2\xda\xc2\xb0\xf7\xc0\x4c\x51\xf5\x72\xf2\x20\x93\x70\xaf\xc0\xc4\x87\xfa\xdd\xf9\xd9\xc8\xb7\x66\xd1\xdf\x7c\x48\x98\xe4\xf3\x75\x9a\x89\x82\xa3\x8e\xe5\x04\xce\x9d\x96\x41\x3c\x06\x18\x29\x15\x50\x16\x52\xb8\x36\x37\xec\x4a\xe7\xa8\xcd\xb1\x93\xb6\xb0\x31\x05\xdb\xb8\x94\x4a\xc0\x49\x10\xe5\x7a\xf4\x79\x6a\x82\x72\x59\x1d\x40\xfc\x36\xda\x1d\x92\xa1\xee\x91\x25\x3b\x65\x98\x5b\x6c\x07\x6f\x12\x7f\x0d\x3c\x99\x46\x50\xa7\x9d\x29\x26\xf5\xe2\x59\xed\x13\x66\xcf\xf7\x32\x2b\x95\xc9\xd7\xfb\xfa\x62\xd9\x71\x06\x5a\x71\xf2\x40\xcd\xb8\xf3\x43\x7c\xd8\xb7\x8c\x44\xf0\xfb\x33\xe6\x76\x10\xcf\xff\xad\xd7\xb4\x36\x94\x74\x27\x44\x02\x6f\xc6\x53\x24\x76\x63\xce\x57\x9d\x52\x1e\x85\x38\x15\x4e\xc2\xbe\x84\x96\xec\xe2\x96\xd0\x70\xbd\x27\xa8\x27\x08\xbb\xa4\xd1\xdc\x3c\xb0\x4c\x18\x5b\x21\xea\xd7\xb5\xb0\x19\x2f\xee\x53\x26\xcd\x9f\xa4\x32\x1b\x21\x6a\xb6\x9e\xa0\x0a\x80\xd3\x2c\xad\x3d\x9d\xcf\xa6\xf6\xfd\xcf\xec\x22\xfe\xf6\x5b\x2a\x94\xb2\x8d\x30\xfa\x22\x51\x3a\x46\xc3\x8f\xd5\xc8\x13\xda\xc9\xa7\xfa\x20\x2c\x72\x24\x11\x24\x5a\xda\x07\x27\xe8\x76\x59\x04\xb0\xf7\x9a\xa2\x98\x05\x0c\xb3\xe1\x21\x01\x5b\x6d\x01\xc2\xd0\xd3\xb6\x4a\x8e\x84\x61\x9b\xb1\xe8\x71\x75\xc2\x21\xa0\x15\x4c\xa3\xd8\xd0\xb7\xdc\xab\xad\x8e\xd8\xf1\x74\x1c\x0a\x46\x82\x98\x1d\xb0\x53\x1f\xc0\x23\xae\x12\xc6\x53\xf0\x0c\x50\x2c\x32\x6d\x1c\x51\xc0\x79\xaf\x4d\x26\xbf\x78\x02\x6e\xe4\x8a\xea\x30\x81\xbd\x23\x81\xd4\x2f\xff\x96\x86\x95\x31\xd5\x32\x55\x16\x7a\x58\x61\xf4\x06\xa1\xab\x14\x67\xbc\x80\x5f\x98\xdd\xf0\xe8\x1d\x49\x55\x2d\xec\x6b\x8c\x3f\xad\x57\xc3\x0a\x07\x39\xf3\xa8\x6f\x36\x44\x02\x02\xc7\xd0\x6a\x7c\xd8\x72\x70\x96\x6f\xe0\x45\xf9\x6c\xbc\x77\x78\x8f\x0d\x59\xd8\xc8\x04\xaa\xd8\x23\x51\x59\x63\x3c\x2b\xea\x50\x52\x2b\xf7\x01\x8e\x0b\xfb\x2f\xcb\x60\x09\x56\x99\x52\x7b\x9b\x98\x40\x2d\x91\xf8\xfe\xef\xf7\xcf\x89\x98\x4c\x25\xe4\x43\xe5\x3d\x87\xbc\xb2\x74\x43\xbe\xb4\x65\x9e\xc0\x1f\xb3\x93\x55\xf5\x79\xfb\x84\xef\xfd\x9c\xca\x12\x1f\x20\x9a\x83\x81\x04\x90\x96\x9d\xcd\x8b\x48\x45\x1f\x16\x33\x52\x2b\x9d\x81\xc8\x04\x4e\xca\xda\xec\x9b\xcd\xef\xd2\x0c\xb0\xab\x7d\xa3\xa1\x31\x57\x3b\x49\xa1\x23\x44\x97\xc2\xed\x6e\x00\x36\x74\x8a\xbd\xce\xd0\x88\xb2\xd4\x96\xf1\x71\x8e\x36\xfc\x49\x8d\xef\x31\xc0\xef\xdc\xb0\xce\xf7\x66\x3e\xb6\xc7\xa9\x86\x11\x23\x90\x3c\x0f\x8a\xff\x8f\xd6\x94\xd8\xa8\x40\xde\x88\x01\x84\xc2\x66\x09\xe9\x39\x45\xac\x97\xd7\x89\xfc\x81\x95\x8f\xf3\x51\x0d\xd3\x16\xb6\x1d\x9f\x17\x6a\x1c\x4b\x89\x10\xd6\xb7\x39\x4e\xbf\xd9\xfd\xdd\x51\x14\x2e\xd3\x42\x99\xb7\xf9\x73\x7f\x6f\xf9\x8d\x99\x27\xf6\xf7\xa0\xf9\xd8\xfa\x17\x46\x9d\xe9\x60\x0f\x44\x9d\xab\x8d\x7f\x5e\x85\x5c\x45\x15\x80\xdc\x56\xff\x10\xfa\x41\xf3\x84\xdb\x51\x3c\xe8\xd8\xb8\xb2\xf9\xd6\x46\x34\x6d\xbd\x31\xe0\x80\xc5\xbf\xed\xe6\x27\xf9\xeb\xe8\x2a\x99\xd4\xff\xdf\xc7\x6b\xc5\x40\xeb\x88\x78\x90\x83\xab\xbe\x33\x66\x13\x0e\x19\x37\xc9\x12\xb1\xb0\xf3\xc2\x78\x70\x7d\xf1\x2d\x40\xf7\xc7\xf6\x22\x22\x64\x53\x70\x48\x1f\x47\x1d\x56\x44\xe2\x2d\xa5\xb5\x10\x77\xa7\xa8\x1a\x99\xd7\x40\xd7\x45\xf1\xad\xe2\xfb\x00\xcc\x9c\x78\xea\xd4\x57\x2e\xf7\xa9\x49\x92\x06\x63\x20\xaf\xbf\xa8\xee\x6d\xd0\xa5\x49\x22\xba\xdd\x52\x11\x89\x5e\x82\x87\xaf\x85\xa3\x7d\x6d\xd2\x25\xcb\xa9\xed\xfb\x0c\x25\xdd\xd4\x91\xaf\x1d\x0e\x58\xd7\xec\x24\xa3\xed\xbd\x24\xae\x7f\x74\x3a\x23\x8d\xaf\xa1\xb2\xe7\x2d\xf9\xb1\x94\x1b\x89\xed\x6b\xc6\x0d\x35\xb4\x96\x95\xa9\x10\x1a\xec\x66\xa4\x3d\x8d\xc0\xd0\xb6\x29\xe2\x87\xa2\x18\xd6\x4d\xd6\x41\xd3\x91\x34\x66\xd8\x0a\xfb\x9a\x20\xdb\x70\x97\x1a\x39\x84\x2c\x1b\x67\x14\x39\xba\x02\x21\x57\x3d\xf2\xf8\xb9\x94\xbc\xc1\x9c\xce\xb1\x07\x5f\xbd\x57\xa3\x34\x68\xe1\xe4\xf5\x31\x1b\x2d\xae\x74\x99\xcf\x70\xb0\xb5\xa6\xc4\xd4\x76\xda\xd4\x2b\x4e\xe3\x2d\x26\x9d\x0e\xd9\x7b\x06\x39\x2f\xee\x1c\x53\x00\x06\x92\x1f\xb6\x48\x6d\x8e\xa8\x52\x68\xff\x1f\x96\xbe\x37\xdb\xa1\xbc\xca\xb0\x47\x7d\x10\x67\xfc\x29\xea\x7f\xb1\x2f\x06\xd4\x11\x1d\x82\x3f\x99\x4c\x7c\x7e\x31\x2f\xbf\x26\xef\xe6\x72\xa6\xf6\x28\xb2\x2f\xfa\x05\x21\xae\xe4\xfc\xbd\x9f\x85\x04\x02\xce\x2f\x16\xcb\xd3\x89\xb5\x4a\x22\x0f\xed\xc1\xc0\xba\xa0\x15\x4c\x80\x57\xed\xa1\x87\x55\x4f\xb9\x67\x52\x4a\x85\xaa\xff\xaa\xa5\xbf\xc9\x43\x37\x94\x59\xe1\xfa\x9c\xbe\xfd\x65\xaf\xbb\xba\xd8\xb9\xce\xda\xfb\xe2\x75\x36\x78\xeb\x51\xb6\xef\x7a\x86\x9f\x7d\x72\x06\x06\x1e\x4a\xb0\xed\xd2\x39\x94\xe2\x8f\x49\xd5\x6e\xd2\x73\xf7\x97\x0b\xd8\x36\x43\xb2\x9e\xaa\x04\x63\x37\xbf\x58\xc2\xc1\xd3\x82\xb0\x7b\xb5\x24\xb2\x26\xba\xf7\x0f\x53\x54\xca\xc9\xe8\xd4\xad\x9c\xb4\x6a\xf3\x07\x67\xad\x6c\x84\x18\xb5\x93\x52\xc3\x53\xf1\x77\x73\x2b\xcc\x7d\x07\xfc\x4f\x93\x5c\x0e\x49\x70\xcd\x8e\xc4\x42\xfb\xeb\xef\xc6\x0e\x51\xf4\x93\xe6\x73\xee\x42\x46\x83\xed\x81\x8b\xaa\x61\xd6\x57\x23\x95\x5a\xfc\x11\x68\xf6\x18\xc2\x57\x3d\x39\x73\x29\xa6\x05\x88\x5d\xe7\xa3\x5d\x77\x5f\x96\x92\x58\xcc\x67\x6b\x4a\xa6\xb0\x04\x03\xba\xc5\x7e\x0f\xa4\x0e\xda\xa8\xd6\xd3\xe7\x85\xf8\xc5\x9e\xf2\x10\xf6\x4d\xf8\x86\x9b\x7b\xb9\xa8\x01\x5c\xab\xe3\xa9\x95\xe0\xe3\xf2\x30\x9e\x00\x61\xab\x44\x78\x36\x39\x45\x55\x79\x48\x75\x5d\x0f\x4f\xf6\xb6\x44\xa2\xb5\x31\x8d\x80\x61\x66\xc4\x65\xd8\x13\x9e\x95\xfe\x43\xc2\xb3\xf1\x1c\x10\x71\x8e\x03\xd4\x09\xc3\x07\xf5\x28\x5d\x46\x2c\x00\x1d\xac\x8f\x6d\x7d\x49\xa4\x50\x7d\xe4\x5a\xa9\xdf\x72\x10\x85\x0a\x2e\xc0\x0c\xe9\x65\xa6\x5b\xf1\x63\x78\xbd\xd4\xf2\xa2\xcb\x7f\x8b\xef\xa5\xed\xa6\xf6\xdd\x7f\xf7\xe7\x42\x7c\xc2\x9f\xd6\x59\x77\x67\x6a\xf8\x0a\x29\x7e\x76\x0f\x35\xfe\xe5\xe5\x7a\x1c\x12\x31\xe3\x19\x0e\x89\xa4\x4b\x8d\xff\x64\x04\x5b\xd0\xac\x95\x2b\xb0\xa8\x25\xff\xb7\xb8\x8a\xdb\xa6\xce\xfc\x42\x38\x9a\x8d\x1e\xd0\x57\x92\xbd\x05\x90\xc6\x30\xf3\x33\x9e\x58\x10\xc0\x96\x79\xbd\x21\x60\x26\xd9\xa3\xe5\xd0\xe0\x43\x7a\x1c\xa2\x48\xba\xb3\x67\x2f\xb8\x10\x9e\x46\x83\x8b\x17\x20\x96\x15\xa1\x29\x74\x7c\x9e\x15\xa7\x34\x4f\x42\x1d\x31\xca\x0e\x92\xa6\x11\x06\x33\xae\xbd\xe2\x76\x01\xea\x76\xbc\xb2\x40\x6e\x45\x75\x4e\xad\x6d\xd4\x2b\x5e\x9c\xd2\x22\xb0\xab\x9f\x24\x95\x36\x15\x2a\xde\x93\x06\xc4\x3d\xe8\x21\x40\xfb\xe6\xf6\x2f\x02\xee\x07\x8c\x43\x5c\x17\x87\x59\x09\xbc\x69\x3b\x4d\xca\x49\xc5\xd7\x26\xd0\x1b\x8f\x59\xb8\x11\x06\xaa\xf6\x0a\x1f\x0d\x4a\xd4\xea\x23\x22\x05\x27\xd0\xdc\xce\x9c\x59\xdc\x6d\xfd\x95\xc7\x30\xf1\x96\x05\xd5\xe2\x6a\x3a\x8a\x9e\x1a\xe0\x6b\xd4\x28\x5a\xc6\x2d\x03\xff\x02\xf7\xb1\x65\x2a\xa0\xd4\x79\x72\x8f\xcf\x2e\x13\x61\x7e\xf0\x8f\x92\xc4\xa3\x7b\x3c\x8b\x1b\x94\x65\x81\xe1\x4a\xeb\x64\xcb\x1a\x54\xfb\x7a\x91\x10\x54\xd2\xa2\xb3\x7c\x04\xfc\xe9\x11\xac\xd8\x6a\xaa\xe3\x2c\xb1\x8c\x07\xf8\xea\x3e\x31\xaf\x4a\x4b\x66\x3d\x67\xbe\x99\x86\x32\xd2\x75\xdc\xee\xd1\x37\xff\x0f\xa9\x1b\x9a\xef\xcd\xbf\x0a\x89\x1f\x9b\x75\xb5\xf0\x8a\x62\x89\xd4\xfc\x06\x75\x89\x01\x45\x8d\x0b\xa8\x56\x47\xb5\xab\x7a\xd3\x1b\xcb\x17\xc7\xb5\xc4\x6d\x0e\x33\x60\x6d\x85\x74\x19\xb5\xb2\x4d\x90\x99\xe0\xc6\x8c\x9e\x73\x6b\xae\x49\x4a\xe7\xc3\xd7\x79\x59\xd6\x75\xab\x25\xf8\x54\x3a\x59\x5b\x0a\x39\x2c\x85\x1f\xd8\x5c\x8f\xe6\xb4\xcf\x63\x28\xd5\x7e\x69\x97\xe2\x40\xcb\xf6\x01\x98\x38\xa2\x9f\xe4\x47\x56\x2a\x1a\xda\x1f\xff\x3f\xfc\x32\xdf\xa6\xe3\xb9\xa2\xd5\x02\xaf\x2d\xae\x30\x91\xef\x7a\xdc\xa3\xf1\x30\x4e\x0f\x30\xde\xa2\x32\xbb\xe0\x13\x8d\xd0\xa7\xc6\x5a\x2d\xce\x3f\x92\x73\xcc\x93\x2c\x3b\xac\xaf\x7f\x68\x07\xb0\xa8\x4c\x49\xba\xb4\x5d\xf4\x37\x48\x18\x42\x09\xe1\x71\xb7\x5b\x45\x40\x96\xa5\xe0\x7e\xb8\x3e\x22\x10\x97\xdf\x7f\x5d\xe5\x1e\xa7\xbe\xb3\x9f\x7a\xbc\x9f\xb2\xc1\xd6\x83\x7e\x0f\x53\x73\xc1\x5f\xb2\x61\xe0\x9b\xd4\x0b\xfb\xdd\xc0\x92\x04\x64\x0a\xc3\x90\x30\x41\xa2\xa8\x6d\xd0\x86\x88\xfa\xf3\x77\x18\x37\x7b\xc7\x1a\x9a\xfb\x2d\xd3\x5f\xc9\x87\xba\x54\xbb\xb4\x61\x10\xbc\xf2\x34\x59\x0d\x91\x77\x66\x5b\x14\x4d\x06\x03\x7b\x76\xc5\x59\xd2\x2c\xe1\xde\x81\xba\xa0\xa4\x1e\x8d\xcc\xf4\xef\xc5\xf6\x67\x19\x68\x47\x37\x7b\x77\xc8\x86\x01\x78\xa6\x33\x33\x02\x85\xd6\x3f\x9d\xed\xf6\x95\xbb\xa2\x71\x3e\x1c\x2f\x65\x19\x5c\xde\xe4\x95\xa9\x18\x9b\x97\xc8\xad\xab\x11\xa9\xa5\xac\xfc\x0f\xfa\xd6\x4a\x4b\xc7\x32\x49\x05\x6c\xa0\x5c\xcd\x1d\x54\xf2\x12\xe6\xe5\xe0\xfb\x81", 2525);
*(uint64_t*)0x20001558 = 0x9dd;
	syscall(__NR_pwritev, r[0], 0x20001500ul, 6ul, 0x3ff, 0);
*(uint16_t*)0x200003c0 = 0;
*(uint16_t*)0x200003c2 = 0;
*(uint64_t*)0x200003c8 = 0;
*(uint64_t*)0x200003d0 = 0x5e23;
*(uint32_t*)0x200003d8 = 0;
*(uint32_t*)0x200003dc = 0;
memset((void*)0x200003e0, 0, 16);
	syscall(__NR_ioctl, r[0], 0x40305828, 0x200003c0ul);
	syscall(__NR_lseek, r[0], 0ul, 4ul);
	return 0;
}
