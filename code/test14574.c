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

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200002c0, "./file0\000", 8);
	res = syscall(__NR_creat, 0x200002c0ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000040ul);
	res = syscall(__NR_dup, r[0]);
	if (res != -1)
		r[1] = res;
*(uint64_t*)0x200025c0 = 0x20000080;
memcpy((void*)0x20000080, "\x07\x39\xc0\x0d\xca\xaf\x01\x0f\x62\xa9\xa9\x2e\x0d\xd5\xa3\x89\x15\x5f\x2e\x1e\x6a\xd9\x93\x3f\xfc\x6d\xe7\xb2\xe0\x22\xc3\x3f\x90\x4e\x33\xfc\x6c\x89\xa8\x38\x4a\xe8\xc8\xc1\x90\xf2\xc1\x90\xfc\x4b\xcf\x1d\x09\x76\xcc\x67\x96\x48\x9f\xba\x41\x78\x37\xb0\xab\x00\xac\x80\x51\x9f\x3f\x61\xd4\xd5\xfe\x7b\x0b\xe5\x60\x1f\x3e\x5f\xc0\x8d\xde\x0e\x77\xcb\x80\x86\xda\x92\x3f\x5f\xa5\xfc\x93\x9e\xd7\x6f\xb5\x15\x46\x25\xe1\x23\xce\x6e\x75\x44\x15\x23\x2f\x7c\xf5\xd9\xb3\x75\x1f\x49\xcd\x67\xb6\x2c\xf3\x16\x2f\x20\x07\x17\x41\x5b\xf2\x76\x2a\x82\xc7\x84\xeb\x98\x95\x44\xf5\xe7\xde\xfa\x62\xa7\x5c\x5d\xff\x03\x92\x02\x5f\xd5\x8a\x4b\x32\xdf\x25\xa4\x09\x6e\x47\xe9\xa3\xf3\xaa\xba\x41\xf6\x8b\x6a\x4d\x14\x6b\x72\xaf\x9b\x56\x36\x42\x90\xb6\x28\xe7\xfe\x63\x79\xdb\x8c\xa8\xb0\xce\x71\xe2\x01\xd8\xe5\xe0\x46", 202);
*(uint64_t*)0x200025c8 = 0xca;
*(uint64_t*)0x200025d0 = 0x20000180;
memcpy((void*)0x20000180, "\x1d\xda\xec\xe9\xd9\xda\xb6\x8c\x2c\x42\x33\x2c\x6b\xc6\x58\x20\x33\x30\x78\xba\x21\x3c\x82\xe5\xb7\xa2\xfe\x24\x5c\x05\x49\x6d\x91\xdb\xf5\x43\xdc\x4b\xd8\x2b\xcd\xb5\x05\xa6\xb4\xca\xd2\x02\x7d\xe6\x7f\x45\xbe\x2d\x3f\x4b\xd6\x3c\x1f\x00\xac\x82\x64\x57\xe8\xff\xeb\x82\x31\x15\x8f\x47\x90\x42\x16\xff\x44\xd3\xaf\x53\x19\xdf\x91\x12\x43\xa0\xe1\xc2\xf4\x8e\x65\x6a\xa6\xb4\xa5\x07\xb4\xb6\xf3\x57\xdb\x70\x21\x6d\x78\x83\xf3\x63\xe5\x9a\x78\x87\xdc\x37\xd7\x30\x41\xb6\x77\x6b\xaf\x66\x14\x26\xfa\x9b\xb6\x69\x32\x7d", 130);
*(uint64_t*)0x200025d8 = 0x82;
*(uint64_t*)0x200025e0 = 0x20000300;
memcpy((void*)0x20000300, "\x3f\x2b\x67\x60\x5b\xe7\x61\xaa\x07\x99\xd2\xb7\xf0\x11\x8d\x48\x04\xa2\x29\x9b\x89\x51\xdd\xff\x68\x51\xd0\x7e\x3e\x62\x56\x2c\xe7\x10\xb3\x27\x36\xcd\x7d\xd2\x71\xfb\x78\x9e\x17\x87\x00\x0e\x6e\x47\x2a\x75\x5a\xb0\x1a\x1e\x89\x28\xf4\x62\x85\x67\xcc\x7b\x06\xb5\x23\x83\xb9\x0e\x94\x6e\x6f\xbf\xef\x10\xef\x30\x54\x89\xbb\x97\x0a\xd4\xf0\x8d\x94\x76\x1b\xfe\x43\xb5\x7d\x70\x47\x1b\xc6\x9e\x51\x8a\x35\x3c\xdb\xad\x78\x51\x2d\x98\xf9\xc8\xe7\x4c\xe4\x3f\x67\xd2\x78\x44\x6c\x6d\x64\xc6\x3b\x86\xeb\x14\x9f\x96\x51\x85\xe8\x0a\xc6\xe6\x3a\x3d\xec\x34\x30\x16\x07\xc4\x8a\x30\x2a\x6d\x1a\xdf\xbf\xc7\x5d\x03\x5b\xcb\x03\xe1\x75\x82\x2e\x76\x59\x94\x1f\xe3\x7a\x05\x1b\x94\x09\x35\x38\x1d\xf4\x95\x34\x55\xb9\xb4\xe5\xcd\xa3\xde\x01\x62\x39\x20\x1c\x24\x37\x8c\x57\xfb\x5f\x7d\x1d\xeb\x4b\xa4\xaa\x29\x4c\x10\x1e\x04\xd9\x97\x95\xdb\x98\x17\x0e\x60\x9e\xb2\x27\x0c\xdc\x8d\x20\xdc\x64\x3c\x01\x0e\xc7\xb3\x6a\x5b\x77\xb3\xf2\xde\x9c\xa9", 234);
*(uint64_t*)0x200025e8 = 0xea;
*(uint64_t*)0x200025f0 = 0x20000240;
memcpy((void*)0x20000240, "\xf7\xa2\x9c\x10\xa4\xf3\xb1\xd4\x74\x90\x33\x1f\xc8\x9c\x7d\x87\xf7\xb7\x99\xb9\x21\x90\xfa\xa5\x29\xfe\x8c\xe6\xbc\x42\x6c\xfc\x84\x6f\x40\xf8\x0a\xdb\x68\x6f\xbd\x90\x0b\xd9\x15\x6e\x76\x40\x05\x71\xbb\x67\x6e\x7c\xbd\xdb\x86\xbe\xc4\xb2\x49\x73\x93\xbd\xcf\xb0\x89\x28\x54\x99\x5b\x60\x80\xb5\x46\x94\x01\xed\x3a\x2f\x13\xd3\xd0\x2b\x77\xbe\xf6\xdd\xf1\xf8\xba\xd8\xcb\xa0\x2c\x13\x30\x67\x78\xfc\x58\x54\x63\xe4\x8e\xe4\x93\xea\x7a", 109);
*(uint64_t*)0x200025f8 = 0x6d;
*(uint64_t*)0x20002600 = 0x20000400;
memcpy((void*)0x20000400, "\x2d\x90\x14\x16\x99\xa5\x82\xa0\x71\x14\x6e\x09\x5b\x5d\xe8\xb1\x11\x0f\x1f\x8b\x7b\xb3\x98\xb0\x17\x60\xa9\x1c\xed\x95\x43\xbc\x28\x44\xdd\x26\x98\xb4\x87\x1c\x46\xac\x22\x9a\x57\xdd\x6b\xa6\xf2\x2c\xe1\xf2\x44\xfc\x12\x8c\x8d\x6a\x25\xd5\x82\x78\x25\xfe\xe5\xbe\xed\xd7\x86\xca\x1a\xe3\x52\xc9\xbc\xd8\xe6\x17\x35\xc0\x9a\x27\x38\xe5\xa0\x7e\xc3\xd7\x25\xbf\x5d\x8a\x95\x9f\x86\x31\x5f\x07\xe4\xf1\x10\xea\x28\x5e\x59\x06\xe8\x61\x9d\x99\xf8\xb0\xe0\x3c\x25\x6c\x42\x7e\xf6\xd1\x2c\xea\xd0\x27\xcf\x2e\xf9\xf1\xc3\x71\x70\x91\x25\x43\x50\x93\xcb\x1d\xed\x65\xfc\xc1\x51\x55\x1e\x5e\x3d\x91\xad\x6b\x0d\x5a\x9c\x10\xf7\x28\x0a\x3a\x58\x47\xb0\xd3\xee\x75\x3c\x72\xa8\xb7\x7a\x29\x5b\x06\x21\x45\x82\xfc\xcd\xb6\xe5\xd8\x05\xf7\xcd\x19\xa6\xd6\x81\xf1\x3d\xa4\x41\x57\x7f\xb5\x84\xd0\x3f\x9a\x1d\x7f\x6e\x01\x64\xba\x2d\x2e\x4d\x08\x53\x48\x11\x9d\x29\x63\x0a\x23\x45\x2d\x72\x6a\xba\xfe\x2a\x87\x15\xaa\x21\xab\x96\xcd\x1d\x4f\xc3\x66\x50\xbf\x1b\xde\x25\x12\x5f\x55\x89\x47\x97\x27\x24\x0b\x03\xeb\x94\x71\x41\xfd\x1e\x62\x93\x1b\xa7\xa4\x63\xb8\xb0\x4b\x46\x39\xeb\x2c\xbc\x32\x96\x61\xbe\x76\x94\xb7\x40\x35\x2f\xd3\x7d\x71\x7d\xc0\xd9\xd9\x9b\x4a\x08\x3d\xf7\x30\x3e\xa3\xe9\x65\x2e\xe9\xd1\xa5\x95\x8c\xad\xca\xbc\x37\xb3\x24\x51\x0e\x0f\x38\x37\x64\x35\x4a\x8e\xba\x62\xd2\x73\x6e\x32\x96\x16\xc7\xb5\x21\x20\xfc\xda\xe5\xc5\x92\x68\x56\x52\x6f\x79\x84\xe1\x5b\xbb\xa7\x77\xc8\xe4\xba\x1b\x9b\x95\xa6\x08\xb6\xed\xd7\x37\x2b\xb3\xff\xb2\xd2\x37\xaf\xb8\x2d\x99\x4f\x18\xac\xec\x23\x59\xe2\x63\x6c\xca\xc6\x6b\xae\x9c\x23\x85\x0c\x50\x76\x8e\xaa\x54\x4c\x44\xdc\x0c\x69\xd6\x04\x57\xe6\x35\xbd\x7b\xf4\x9b\xdd\xab\x04\x02\x17\xf1\xce\x79\xb8\x68\xde\x36\xd3\x84\x95\xb7\xd2\xb0\x90\xe6\x12\x76\x30\x19\x2c\x61\x28\x2e\xed\x7b\x05\x8d\xa2\x5a\x09\x15\x87\xb8\xdd\x62\x7b\x22\x45\x7c\x0f\x53\xc8\x16\x62\xf6\xf1\x43\x71\xc4\xcf\x23\x91\x10\x41\x7e\xd9\xec\x5a\x4e\x9b\xdf\x9f\x38\xcf\xa6\x7a\xdd\xf2\xda\x0a\x92\x8a\x09\x61\x10\xc5\x08\x85\xda\xbe\x15\x24\xca\x1b\xe7\x0b\x6b\x21\x2a\xb1\xbb\xc5\x9e\x47\xa2\x91\xdf\xf6\x85\x18\x5b\x98\x65\x1d\xc9\xf8\x0f\xaa\xd8\x91\xcd\x4e\x09\x90\xd1\x50\xb3\xae\xfa\xa2\xd1\xd4\x13\xb1\x7f\xcb\x27\x6d\xdc\x51\x12\x00\x9b\x32\x72\x9b\xd2\x79\xde\x03\x33\xfe\x10\xb6\x91\x42\x23\xc6\x33\x6d\x97\x6b\xfb\x92\x66\x4b\xca\x99\x03\x6a\x1b\x75\x7e\xd3\x93\xcf\xbb\xc0\x9e\x8c\x62\x2b\xe2\x48\xeb\x00\x31\xf1\x3d\x00\xeb\xbb\xcd\x92\x3a\xeb\x6a\x8a\xeb\x79\xac\x43\x05\xb3\xe6\x54\x8b\x14\xc3\x95\xe7\x67\x86\x12\x2a\x64\xfb\x2c\xbb\xe6\xd2\x40\x18\x04\x4d\xa6\xb5\x27\x41\x69\x8a\xcf\xdc\xcb\x60\x5c\xee\x25\x44\xfb\xe9\xc2\x94\xf6\xd3\x85\xd7\xe0\xff\xaa\x18\xed\x61\xc3\x8c\x08\xca\x78\x38\x32\x69\xd2\xa6\x67\xd8\xd2\x47\x32\x3f\x58\x7d\x7c\xe5\x1b\x7b\x69\xcb\x22\xa7\xc5\xe7\x54\xe0\xae\xa6\x60\xcf\x9e\x9f\xd1\xfa\xbc\x7a\x58\x50\x74\x68\x0b\xd1\xd3\xbb\xae\xcc\xe7\x59\x8d\xf5\x5f\xf7\x9d\x8d\x82\x67\x6f\x8e\xa1\x3e\x00\x15\x1b\xf6\x5c\x4b\x78\x34\x59\xe0\xec\xc3\x6f\x5b\x94\xf6\xf3\xc0\x0a\x32\x42\x4a\x5c\xec\x73\xde\x30\x33\x03\xed\x93\xe0\xda\xb4\x2c\x5f\xb1\xe9\x46\xf2\xbd\x31\x15\xdf\x77\xcf\x0d\x4d\xd4\x56\x40\x52\x1c\xf4\x18\x26\xf7\x38\x47\xff\x1c\xbb\x3a\xfd\xa6\x5e\xdd\x95\x32\xd4\xaf\xd1\x14\xa2\xa5\xab\x73\x25\x8a\x82\x0f\xf5\xf5\x05\x7a\x58\x56\xa5\x53\x4b\x9c\x4a\x95\x6f\x40\x0b\x3f\x2e\xe9\x3b\xc6\xe4\xe4\x17\x07\x66\x3e\x21\x56\xe3\x04\xad\xdd\xc5\x5d\xf4\xac\x15\x1c\x3d\xfc\x19\xe7\xe8\xc6\xd0\x6c\x34\x9a\xb2\xb8\xe1\x1b\x16\x27\xd4\xf9\x52\x07\x53\xee\xeb\xc5\x63\x7e\xfe\x09\x1d\x61\xae\xe2\x90\xce\x42\x9b\xc4\xf2\x7c\xf0\xe0\xa2\x87\x21\x76\x81\x0c\x7c\x1f\xc7\x48\x5a\x37\x79\x9e\x38\xa6\xac\x19\xb4\x4f\x55\xe4\xac\x58\x7f\x0c\x74\x35\x0a\xb4\x31\x02\x83\xb1\xf1\xc6\xa6\xf9\x47\x1a\x24\x93\xe7\x19\x36\x0e\x4e\x38\xef\x7d\xee\xdb\x3e\xe6\x6b\xc8\x7f\x99\x5c\x89\xf9\xce\x21\x17\x04\xeb\xe5\xd2\x37\x8b\xf4\xee\xad\x7d\x62\x6c\x5f\x1d\xc5\x68\xc2\xfb\x64\x45\xa7\x87\xe8\x94\xb2\x83\x04\x73\x1a\xde\x09\x82\x73\xdc\x65\x37\x72\x39\xe2\x83\x50\x80\xf1\xef\x32\x36\xf9\x50\xdb\x23\x9b\x28\x47\xd3\xd9\x23\x89\xa5\x25\xc8\xcf\xd8\x32\x99\x4d\xd9\xf6\xc7\xae\x36\xe6\x3a\x97\x78\xe1\x47\x25\xd2\x67\x4b\x49\xb8\xea\xff\xe3\x46\xa1\x19\xa3\x4e\x17\x28\x55\xa8\xe9\x3a\xae\xfc\x84\x2e\xce\x21\x81\xba\x81\x01\x4e\xcf\xb8\xfa\x1d\xb5\x1f\xeb\xda\xed\xe8\xfb\xea\x11\xc7\x05\xe5\x17\x6f\x43\x48\x1c\x92\x50\x74\xce\xf2\xd5\xa6\xf1\x84\xf3\x84\x6b\xf0\x10\x4d\x33\xe6\x49\xc1\x73\x44\x28\xf5\xa9\x20\x8c\x41\xfd\x37\x7b\xad\x20\x95\xe9\x30\x7e\x1f\x5e\xd1\xe2\xdc\x44\xbb\x79\xc8\xbd\x55\x85\x90\x32\x17\xd6\xab\x14\x25\xd2\xac\x8a\x1f\x56\x5d\x7f\xbd\x16\x16\x2c\xf9\xac\xef\x35\xc1\x93\x0f\x99\x69\x09\xa1\x43\x8f\xf1\x7b\xd5\xf9\xbd\x48\xfb\xea\x7f\x52\xc5\x59\x11\xc8\xbc\xc1\xfe\xd9\x19\xb1\x1f\x4a\xe7\x4a\xf8\x22\x19\x0f\xde\x51\x80\x33\x05\x95\x53\x6d\xb2\x65\x32\x5c\x72\xfd\x6d\x7e\xe7\x4a\x27\x4b\x4e\x24\xaa\x4b\x81\x15\x2a\x51\xf5\xb4\xf8\x45\xa0\x8e\xad\xb4\x76\xa3\x19\xaf\x7b\xba\x9f\x11\x07\x19\x11\x79\x8f\x28\x45\xef\x05\x81\xc7\x48\x0b\xfa\xcf\xc9\x52\x1f\x81\x5f\xcf\xd4\x77\xcd\x2e\xc7\x6f\xc6\x27\xcb\x68\x0c\x67\x5a\x31\x7f\x9b\x08\x20\x97\xbc\xdc\xe4\xee\x13\x61\x79\x3c\xab\xca\xf1\x7e\xf7\x10\x01\x17\x8b\x17\xca\xbf\x11\x43\x18\x02\x09\xe1\x5d\x60\x35\x28\xd3\x78\xc7\x1b\xe8\x57\xbc\xfa\xa0\xc1\xf9\x69\x17\xb6\x22\xf9\x28\x63\x97\x07\x96\x56\x12\x23\x2e\x19\x1f\x48\x04\x69\xbd\x5d\x59\x39\x1e\xcb\x3b\xe2\x37\x39\x61\x30\x44\xf2\xb4\xc8\x55\x72\x04\x3a\x3b\xdd\x9c\x83\xb7\x19\x4f\xc1\x19\xd0\xb4\x27\x88\x59\x83\xf0\x27\xe7\x12\xa8\x72\x5d\x8b\x1b\xb3\xda\x35\x6c\xb9\xcc\x44\xc8\x82\x76\xd6\x3c\x4c\x73\x37\x85\xc8\x1b\x24\x43\xd7\x34\x02\xba\xfc\xe3\x6e\xc7\x4a\xaa\x5a\xe5\x3a\x74\x52\x36\x92\x7b\xe8\x01\xcc\x0c\x0c\x32\x73\x04\x45\xdb\x15\xdf\xab\xe4\xff\x78\xe1\x4f\xce\x20\x64\x11\xc0\xa2\x2d\x13\xf2\xe6\x91\xe7\xaf\xf4\xcd\x69\x9f\xc4\x37\x0e\x5d\x35\x67\x24\x46\x11\x0a\x02\xd6\xaf\xbd\xb4\xcd\xb7\x4e\x34\x88\xc9\x8c\x07\x55\xc4\x04\xc1\x6d\xd3\x10\x8a\xca\x4d\x2e\xc8\xac\x2f\xf7\xba\x1f\x38\x4f\xbd\x37\x1d\x7f\x8e\x57\xfd\xc4\x8f\x30\x87\x36\xbe\xd9\x50\x73\x49\xf3\x2e\x60\xeb\x9c\x1f\x35\x16\x9e\xef\xa7\x27\x48\x5e\x93\xb7\x6a\x84\x05\x79\x50\xe0\xb9\x36\x6c\x21\x12\x83\x31\xfb\x41\x4a\xb5\xa9\x56\x58\x86\x39\xcb\xbf\x2c\xfa\xcc\x41\xbb\x45\x26\x7a\x78\xc6\x31\x19\x1c\x76\xfc\x9d\xf7\x9d\x38\x06\xb0\x87\x44\xca\xbf\x53\xee\x3c\x3b\xc3\x80\x2d\xff\x44\xe3\x34\x73\x7c\x6e\x8b\xd1\x01\x03\xab\xd6\x74\x6c\xcd\xc9\x4c\x06\xb1\x69\x9f\x39\xf4\x9b\xf3\x56\xa9\x15\x41\x66\x63\x29\x0b\x12\x84\xb9\xea\x17\x7d\x98\x2d\xa5\x9e\x88\x15\xd3\x64\x32\xee\x00\x89\x59\x91\xb1\xfc\x4c\x5a\xc0\xcf\x3a\xe0\xd2\x12\x8c\xb9\xfe\xa4\xbe\x01\xf2\x5d\xc1\x61\xb5\x7f\x77\x7e\xfa\x04\x0a\x6e\xf5\xf2\x06\xc9\x69\xf3\xfc\xd2\x52\xb8\xda\xe7\xbd\x5b\xb0\x46\x95\x6c\xad\x40\x5a\x69\xa5\xd6\xc4\x05\x94\x1d\x80\xda\x24\x48\xaa\x36\x60\x08\x64\x17\xd5\x0f\xc5\x15\x36\x17\xe1\xd8\x55\xe8\x97\xd6\x33\x7f\x28\x8e\x1e\x2a\xa2\xed\xff\x88\xf4\xb6\x2d\xbb\x06\x4a\x01\x8b\xcc\x83\xca\x93\x04\x42\x45\x00\xcf\x24\xe0\x9c\xef\x5f\xb3\xe0\xe4\x5b\x1e\xed\x90\x26\xa1\xf7\x46\xda\xb7\xe2\xf1\x8b\xc9\xb9\xa2\x58\x5e\x7b\xac\x70\x09\x2d\xf7\x82\xd8\x2c\x72\xb6\x11\x9e\xa9\x84\x12\xaf\xef\x5f\xc5\xb5\xd0\x54\x61\x85\x3a\xa0\x49\x62\x6e\x72\x08\xea\xb7\x0b\x0f\xa4\x4d\x6c\x9b\x9f\x7d\x85\x80\x9e\x7a\x29\x95\xdd\xf5\xa5\x7d\x31\x84\x4c\xd5\x56\x4b\xc2\xf5\xb4\x8a\xc7\x09\x25\x7b\xa7\xbc\x35\x25\x77\x57\x96\xaf\x40\x1f\xc2\x00\xd4\xf2\x05\x43\xf4\xbd\x02\x0b\x8b\x28\xce\x0d\x35\x53\xf5\xdc\x3d\x5f\x49\xce\x31\x72\x46\x3a\x94\x98\x31\x59\x6d\x0c\x9b\x1e\xd4\xfc\xbc\x8a\x12\x86\xf9\x30\x7a\xc4\xa2\x48\xbe\x4e\xaa\x68\x0f\x8d\x99\x45\x30\xb5\x52\xd4\xe5\xa7\x4a\xf1\x09\x6a\xb6\xf2\xe7\x25\x1f\xd3\x88\xea\x22\x38\x8e\x0d\x2d\x7a\xf8\x0e\xd6\xb8\x14\x57\xea\xc4\x4d\x86\x0d\xd5\x0d\x28\x39\x88\x14\x3a\x0b\x33\x26\x50\x55\x0b\x70\x83\x16\xca\xf5\x94\x11\x76\xd9\x5e\x62\x09\xb0\xdc\xaa\x10\x00\xe2\x30\xa0\x38\xf4\x74\x09\xc4\x07\x14\x2f\xec\x70\x59\x00\xed\xfc\x49\xc0\x54\x36\xe1\x03\x4b\xb1\x69\xeb\xe1\x5b\x63\xf2\x24\x63\xd5\xc5\x41\x2a\x65\x41\xcf\x65\x25\xcf\xa4\xb7\xcd\x4e\x00\x25\xb3\xc8\x1a\xce\x3a\x82\x29\xd3\x06\x16\x77\xd6\x07\xee\x5d\x32\xae\x29\xba\xdf\xfc\xbd\x06\x6a\x74\x9e\xa1\xd1\x40\xcb\x7b\x90\x6e\x3e\xb7\x24\x05\x3f\x64\x9d\xa2\x85\x58\x79\xdf\x19\x8f\x23\xfd\xc4\x2e\x89\xc8\xaa\x81\xb2\x53\x64\x44\x21\xc5\x9f\x85\xc3\x5d\xd9\xd6\x35\x27\xa6\xd3\x4a\x84\x60\xe8\xfc\xa5\x68\xbf\xf2\xab\xf9\x31\x7c\xcd\x10\x6b\xfa\x45\x72\xc2\xe4\x88\xb3\xd2\xa4\x81\xc5\x56\xff\x8d\x55\x88\x90\x93\x0b\xf4\x02\x53\xf1\xdf\x13\xf2\x18\xa9\x7b\xcf\xf6\x56\x94\xe7\xac\x46\xc2\x65\xc3\x1f\x12\x2c\x7c\xa7\xb5\xab\xb4\x8a\x68\x4e\xe6\xd4\x7e\x52\x15\x11\x4c\x51\xb8\x5d\x74\x91\xe4\x04\x04\x75\x25\xe0\xd6\xbe\xb3\x62\xa6\xb1\xef\xcb\x82\xdf\x51\xa2\x90\xaf\x81\xb1\x3a\x13\x5b\x0f\x4b\x6a\x4f\x37\xd3\xf1\x61\xee\x74\x7c\x62\x8a\x15\x5b\x95\x9b\xc1\xf2\xda\x9e\x59\x2e\xeb\xf2\xb4\x74\xff\xcf\x1a\xa6\xff\x20\xb2\xea\x7a\xf3\x00\xa7\x95\x2f\xc3\x76\xdf\xa1\xde\x81\x48\x98\x16\xb5\x94\xd3\x26\xf4\xfd\x63\x56\xb8\x11\x7b\x47\x31\x29\x3a\xcd\xce\x5c\x4d\x0e\x34\x86\xc2\x4c\xa3\xc7\xac\x43\x11\xe2\x69\xa3\x5e\xda\xcf\xb0\x1f\x57\x47\x99\xce\x18\xcb\x77\x0a\x86\x29\xe8\xe3\x0e\x78\x60\x64\xa7\x30\x6a\x2e\x6f\xbc\x4d\x9b\x0c\x82\x7a\xb3\x88\x4e\x02\x8a\x33\x1d\x0f\xce\x8b\x73\xb1\x97\x56\x02\x93\x72\x47\x94\xa0\xbc\xdc\x73\xe3\xc5\x31\xa4\x83\x1c\xcc\x19\x18\x18\xb3\xf1\xea\x90\x13\xab\x0c\x7f\xd7\x2f\xd8\x26\x08\xe4\x85\x93\x81\xb9\x73\x25\x86\x5a\xb3\x2f\xdf\x7e\xd5\x8d\xcc\x0a\xb7\x39\x86\xb1\x14\x6e\x58\xd9\x24\x9c\x9e\xd1\x3e\x91\xf8\xbd\xff\x9b\x03\x9d\x83\x71\x44\x67\x27\x39\x18\x1d\xa3\xf2\xb2\xb6\x94\xe3\x47\x7a\x2f\xb5\x70\x3f\xb8\x02\x5a\xb4\x31\x7a\x71\xd2\xc3\x60\x98\x17\x46\x33\x31\x35\x29\xe3\x78\x7c\xb1\x73\xf8\x92\x43\xd1\x9e\x8d\xb3\xc0\x53\xd9\xb8\x8e\x3c\x2e\x06\x51\x66\x6f\x97\xcc\x29\x47\x62\x31\x1f\x71\x64\x91\x84\x73\xb6\x7d\x07\x18\x11\x57\xf6\x77\x06\xe0\x27\xb5\xe3\x51\xba\xc2\xd4\xe4\x8d\x08\xe2\xfc\x87\x73\xd0\xb2\x9b\xf7\x8d\xd3\x48\xfb\x8b\xa5\xb9\x85\x19\xe2\x64\x3e\x95\x49\x66\xe4\xda\x2c\x86\x6c\x3b\x23\xb1\xfe\xeb\xea\x9a\x3c\x1d\x17\xfd\x68\x19\x48\xa0\x36\x9b\x1a\xb9\x13\x5c\x05\x5d\x6a\x7a\x88\x2c\x94\x99\x05\xb8\x1f\x97\x07\x5e\x68\x77\x79\x6b\x02\x09\x38\x34\x92\x53\xcc\xf5\x68\x20\x82\x7a\x09\x3f\xb2\xd9\xa2\x89\xd6\x3d\x05\x92\x73\xde\x4b\x67\x5e\x9b\xee\xb3\x1b\xeb\x7d\xc2\x0c\x4e\x3a\x32\x3f\xbb\xfc\xcd\xb1\x84\x52\x4b\x53\xc6\x7d\x75\xa3\x07\x8e\xdc\xce\xa7\x8d\x07\x75\x41\x30\xee\xdd\x59\xdd\x56\x2b\x5f\x78\xd0\xdb\x23\x8f\xfc\x27\x27\x2d\x97\x4d\xad\x50\xf4\xf5\x4f\x5a\x61\xca\xa6\xb6\x85\xc4\xea\xfe\xb8\xe0\xf3\x65\xad\xd2\x75\xc3\x4e\xc2\x3e\x70\x12\x0a\x0c\x89\x2c\x3d\x53\x28\xa3\xc3\xd6\xe1\x0a\xad\x91\x92\xfc\xbd\x82\xd6\xb3\x58\x12\xd1\x42\xd9\x36\x22\x93\x1d\x47\x7b\x7a\xd1\xff\x34\x2f\x9c\x36\xce\x3f\xed\x06\x7c\xba\x89\xcb\x74\x21\x1a\x33\xea\x3e\x3d\x02\x1b\x5a\xc4\x2b\x4d\x1f\x2b\x51\x21\xb6\xb9\x24\x0a\xf1\x5d\x23\x29\xd5\xb8\xba\xaf\x05\x70\x85\x86\xc7\xa7\x5d\x1b\x0b\x2a\x01\x72\x47\xfc\x37\xbb\x9d\x8f\x97\x7c\x28\x97\x03\x9f\x35\x5e\xa3\x3d\x1f\x85\x3c\x04\x46\x73\xa7\xc6\x4e\xa0\xb7\x05\xd7\xd2\x40\xd8\xd0\x79\x4d\x6a\x59\x00\x0d\x5c\x2b\xef\x85\x58\xaf\xda\xb6\x1d\x1c\x6f\xb9\x8e\x18\x9a\xfa\xdb\x4a\xf6\x29\x05\x7e\xac\x3d\x30\x5b\xdc\x77\xa1\x11\xfc\x90\xce\x7a\x2c\xa3\x20\x5b\x52\x17\xc4\x30\xf4\x2a\xe8\x06\x52\x9b\x10\x0f\x20\xa3\x2c\xf4\xb9\xa6\xda\x49\x1f\x06\x01\x7c\x71\x15\xbc\xcd\xaf\xf6\xb1\xa4\x48\xee\x11\x71\xbf\x6f\xa4\xf3\x44\xbb\x02\x2e\xf6\xec\x52\x20\xa8\xa1\xd4\xb2\xfc\x66\x54\x32\xa3\x7b\xea\x9e\xe9\xdf\xe5\x8e\xc8\xad\x0a\xfd\xae\x73\xf8\x47\xe8\xa6\x9b\x99\x82\x50\x0f\x11\xa5\xc5\x0e\xb4\x9b\x26\xb9\x89\xd0\x87\xf4\x51\x92\x47\x65\xb2\x40\x2f\xf6\xef\xe1\xf0\x85\x92\xda\x36\xef\x07\x68\x0c\x9f\xfb\x74\xd2\xf3\xe5\x7f\x36\xb9\xa6\x3b\x51\x14\xae\xc9\xd6\x9a\xee\x67\x4a\xfc\x61\x55\x84\x43\xa1\x6b\x4c\x1f\xa2\x82\xb5\x84\xc7\xb1\x56\xa9\xf4\xc6\x48\xba\xab\x9a\x08\xa1\x02\xee\x24\xea\x24\xc4\xee\x17\x89\xb3\x9e\x4f\xea\xbe\xfc\x90\xb2\xaf\x77\x23\xa6\xf4\xfb\xa7\x9b\x19\x1f\xe2\xe9\x1d\x8e\x29\x79\x7a\x5e\xf2\xff\x52\xa4\x30\x27\xb8\x3c\xf0\xbe\xf7\x44\xc9\xf6\x99\x6a\xc6\xff\xce\x76\xea\x70\x51\xba\x66\xe8\xbe\xef\x59\x3a\x46\x33\xfb\xd6\x75\x5f\xf4\x98\x23\x53\x05\xf9\x96\x2e\x13\xae\x91\x5e\x1d\x25\xd9\x22\x19\x4f\x3b\xe0\x1e\x1f\x9c\x0e\xb0\x59\x52\x0f\x3b\x5c\x75\x24\x43\x11\x83\x92\x5b\xf2\xcb\xbf\x65\xb3\x07\x35\x85\x1d\xe2\xc5\xe8\x76\xcc\xeb\xb7\xbc\x4f\x4e\x26\xb5\xc8\xa5\xbd\x0f\x58\xf8\x3b\x23\xaf\x04\xe1\x2d\x02\xde\x51\xe0\x7e\xad\xe1\x9c\x3f\x84\x0c\x29\x6e\x28\x89\xed\x93\x7b\x56\x1d\xe7\x0a\x48\x58\x7e\x12\x1b\x5d\xdf\x91\xff\x5a\xeb\xc2\x12\xf2\xfd\x52\x57\x5e\xf9\xcb\xb6\x42\x31\x41\xc6\xc4\x3c\x51\xc7\x1e\x13\x8c\x8f\xc2\xea\x48\x4f\xe5\xf2\xa1\xb8\x2d\x68\x1c\xee\x52\xed\x81\xfa\x80\x9d\xbe\xf1\x03\x3d\x1b\x23\xc4\x4d\xd6\x03\xa1\x8b\xba\x58\xf3\xc2\xf1\x47\x96\xed\x0e\x12\x88\x4e\xc9\x59\x8a\xf0\xf9\xc5\x78\x48\x45\xa1\x27\xc0\xce\x54\x1e\xc5\xfa\x49\x46\xc9\xb0\x4d\xd1\x75\x01\x4a\x9f\x43\x21\xa9\x85\x51\x50\x8e\x65\xed\xed\xdc\xca\x17\x29\x9c\xe9\xff\x76\xed\x12\x29\x2e\x0f\x9a\xbe\x39\xa3\x61\xf9\x1d\x9e\x6a\x71\xfa\x29\x8f\x7a\xb0\x8b\xe6\xfb\x50\x12\x4a\x11\x23\xe7\x09\x5e\xda\xcf\x0d\x06\x73\xbe\x9a\xf6\xce\x99\x63\x36\x9c\xb6\xd7\x76\xcd\x74\xef\xb3\x33\x11\x74\x6d\x31\x71\x38\xd8\x91\xba\xb8\xc3\x71\x73\x31\x4a\xb7\xe5\xcd\xd2\x9c\x50\x7b\x48\x03\xf7\xd1\x0a\xeb\xe5\x8f\xa5\x22\xd6\x58\xb6\x6d\x1a\x66\x5d\xe7\x6b\x3f\x48\x3f\x2f\xeb\x8a\x47\xe7\xfc\xb6\xa7\x6a\xe4\xc0\x20\xe5\x6d\xb3\xd1\x32\x2b\x63\x16\x9c\xc7\x6d\xcd\x7d\x8f\x4f\x31\xc8\xb5\x70\x19\x5e\xe1\x3a\x5f\x09\x40\x66\xd6\x5d\xbc\x52\x5d\xa1\x7b\xe3\xfd\x40\x24\xe7\x6e\xc5\x4d\x47\xed\x89\xf5\x95\xae\x6e\xf7\xd5\x81\xa2\xfc\xeb\xb9\x3c\x3f\x95\x1e\xad\xa9\x76\xbe\xfb\xaa\x6d\x1a\x48\x18\x5f\x4d\x61\xe7\xc2\x40\x81\x49\x68\xc4\x91\x6f\xeb\xf3\x1d\x2a\x42\x24\xe9\x9e\x48\x9e\x25\x43\x6f\xaf\x2f\xb1\x72\xe2\x0e\x67\x7f\x50\x04\xfa\x8d\xde\xdb\x00\x94\x96\xa4\x44\xfd\x41\x40\xb6\x03\x38\x67\x43\x6a\xd5\x87\x8d\x25\x52\x42\x4f\x9a\xb8\x15\x3c\xc4\x60\x93\xcc\x97\xd9\xc1\xf3\x97\x83\xb6\xe6\xc5\xfc\xab\x7a\x0c\x45\xa2\x20\xac\x52\x9f\x1d\xfa\x0e\x19\x7d\xd9\x84\x08\xc7\x48\x19\x35\x77\xa7\x5e\x34\x17\x33\xec\x02\x1e\xa0\x2b\xa1\x65\xe1\x8f\x5f\x54\xbc\x96\x3f\x79\x95\x0d\x85\x3d\x8d\xa1\x7b\x3b\x5a\x26\x16\x40\x50\x7a\x95\x4b\xba\xe0\x91\x7d\x20\x30\x78\x0e\xf8\x54\x35\x00\x98\x57\x55\x35\x27\xef\x1a\x6d\x57\x13\x5b\x31\x2e\xda\x6a\x95\x44\xf5\x42\x45\x76\xef\x9f\x11\xf0\xec\xd4\x03\x1d\xce\x9c\x50\xb7\xa8\x6c\x6d\x0b\x8d\x0f\x24\x7b\x38\xfd\x27\x2f\x53\x3e\x81\x66\x7d\xa6\x38\x5b\xaa\x91\x36\x27\x19\xb9\xf0\x1b\xbd\x50\xe3\xfa\x68\xa4\xf2\xef\x43\xca\xec\x09\x76\x12\xf4\x10\x4d\x0d\x9a\x9f\x84\xfb\x37\xde\x6c\xac\xdc\x5b\x01\x1c\xdc\x33\x98\xc7\x17\x5d\x83\x49\xff\x19\xd8\xc0\xf1\x8a\x30\x74\x6d\xbb\x50\x6c\x44\x74\x1b\x3b\x90\x6f\x5e\x35\xc8\x96\x25\xd6\x98\x66\x86\x02\x29\x8d\x7f\x50\xd9\x41\xa4\xe7\x40\x73\xcd\x20\x1f\x08\x93\x05\x68\x4c\x2a\x3a\x65\xc7\x7b\xd8\x9e\xd9\xfc\xd0\xa1\xe2\xd6\x6e\xec\x05\xd6\x36\x59\x13\xb0\xf4\x84\xd5\xfd\x9c\x2b\x78\x15\x2a\x65\x95\xc1\x34\x81\x59\xdc\x95\x74\x91\x61\x7d\x52\x8e\x8c\x7f\xa7\x58\x26\x9c\xac\x3b\xe7\x68\xa8\x87\x7e\x29\x13\x96\xfb\x97\x8f\xa1\xa6\xd3\x3c\xdb\xeb\x11\x56\x99\xfc\x48\x56\x9d\x4c\xba\xc1\x32\xff\x51\xf6\x09\x7b\x83\xef\x2c\xb3\xb3\xef\x2e\x3a\x1a\x4f\x4e\x81\x0e\x87\xbe\x36\x35\x45\x0c\xe1\xbf\x41\x35\xa3\x6d\xdf\xf1\x9d\x4c\x0a\x4c\x04\x80\xd4\x9f\xc9\xb5\xc9\x5f\x86\xb9\x23\xed\x74\x22\x6d\x5f\xc3\xd9\x1a\xe3\x44\x25\x84\x60\x3d\x74\x29\xce\xe8\x57\x3c\x62\x14\x59\x10\x0b\x1a\x7b\x4f\xb3\xa8\xb5\x97\xa1\xc9\xf3\x7d\x91\xf2\x97\x6d\xfe\x4b\x46\x04\x9b\xee\xee\x34\x4f\x00\xe1\xdd\xd5\x12\x82\x07\x03\x9b\x09\x6d\x23\x2d\x31\xbe\x14\x6b\xa0\x7c\x83\xa9\xfc\x8e\x5d\x7c\xa7\x5d\xac\xf5\x1b\xdf\x37\xef\xff\x44\x3b\xd6\x3d\xb6\xc8\x41\x90\xc1\xff\x09\xf0\x7d\x84\x77\xe9\xa7\xe6\x85\x18\x08\x30\xb9\x1b\xff\xb5\xa2\x4d\x23\xeb\xdf\x00\xfb\xb1\x54\xcb\xe8\x9a\xc8\x51\x3a\xae\x03\x4d\x70\xf7\x0a\x0f\xa0\x0b\x0a\x5a\x58\x5a\xd1\xae\x5a\x7e\x11\xd4\x6b\x3e\xa9\xe6\x8d\xc2\x69\xf6\xbb\x9b\x1a\x20\xb7\x10\xa8\x23\xb5\xd9\x8e\xcb\xcb\x08\x81\xa8\xc9\x05\x77\xf9\x87\xe5\xb5\x54\xc0\x83\x43\x6b\xaa\x40\x55\x86\x02\x8f\xd9\x79\xdc\x9f\xef\x73\x41\xe8\xd9\x70\x05\x70\xcc\x56\x54\x9b\xa5\xa8\x6c\x38\x80\x99\xe0\x2e\xc7\xe9\x42\xeb\x0b\x9d\x84\x39\xa7\x64\xc8\xa7\xa2\x47\x48\x9f\x0e\x00\xe6\x8d\xad\xbf\x80\x31\x6d\x69\xb6\x27\x96\x7e\x85\x24\xd5\x0f\x33\xda\x01\x86\xd0\xfe\x21\x1e\x84\xa2\xc9\x70\x04\xb9\xb2\x91\xe4\x8e\x02\xeb\x45\xd0", 4096);
*(uint64_t*)0x20002608 = 0x1000;
*(uint64_t*)0x20002610 = 0x20001400;
memcpy((void*)0x20001400, "\x0f\x01\xa7\x66\x75\x8c\x92\x1c\x7b\x78\x41\xb2\x9e\xec\x0b\x6e\x9e\x95\xb5\x1b\x87\x03\x00\x8b\x28\x65\x33\xfa\x3c\xac\x7f\x5c\xdf\x12\xfd\x72\x2e\xe0\x43\x88\x8a\x16\x30\x24\x0e\x7a\x86\xa1\x2a\xb1\x2e\x3e\xaf\xe5\x4b\x9b\xbd\x66\x90\xa2\x38\x7c\xaa\x01\xc2\x59\x2d\xc9\x16\x6a\xa1\xc8\x6c\x9e\x16\x54\xa1\xb8\xae\xd5\x37\x16\x8b\x5f\xd5\x79\x34\x75\x34\xda\xe7\x2e\xa3\x9c\x44\xae\x90\x9b\x59\xa7\x26\xf1\xe5\xf4\x34\xf5\xa9\x94\x41\x2e\xe1\x4a\x52\xf3\x24\xb4\xa0\x92\x17\x5c\xa6\x42\x8b\xf3\x02\x54\xb9\x6c\xf8\xfe\xe6\x47\xd8\x9b\xfd\xfe\xe4\xd5\xf6\x63\xce\x6d\xc6\xbf\xa8\x8b\xac\x73\xef\x3a\xe1\xc5\xfa\x6f\x45\x52\xbd\xb8\xf6\x53\x50\xd7\xc0\x80\x39\x23\x8d\xe4\xa4\xc8\x73\x32\xf9\x79\xe4\xb4\xd8\x52\xf9\xc9\xdc\xbe\xd4\xda\x09\x75\x1d\x1d\x27\x66\x71\xe0\x62\xa2", 194);
*(uint64_t*)0x20002618 = 0xc2;
*(uint64_t*)0x20002620 = 0x20001500;
memcpy((void*)0x20001500, "\x39\xb3\xb1\xaa\x58\x0d\xc9\x21\xbb\xc4\xb0\x00\x3d\xe8\xe5\x0a\x68\x2d\xb1\xbd\xc4\xa9\x76\x80\x09\x49\x47\x9e\x15\x8e\x4c\x1e\xd5\x68\x13\x96\x82\x32\x94\x7e\xce\x98\xe2\xcc\x52\xfb\x14\x47\x59\x57\x68\x10\x6f\x75\x18\x31\x7c\x74\xad\x10\x21\x71\xc9\x2b\x55\x5f\xcc\xcb\xf7\xab\x73\xc4\xf9\x5d\xda\xbd\xa7\x91\x49\x0d\x49\xc9\x6d\x08\x8c\xcf\xda\xaf\xe7\x43\xa9\xba\x58\x57\xe7\x1b\xd9\xf9\x09\x06\xac\x55\x5f\xad\xef\x9c\xad\x97\xfa\x62\x4b\xf3\x3c\x68\x02\xbf\xc0\x5c\x3c\x06\xce\xbb\xbc\x44\x97\x90\x20\xdb\xfc\xf0\x98\xa0\x3d\x3a\x2f\x6c\xee\x46\x09\x88\x7c\x7d\x1a\x3e\x38\xd7\x00\x8b\x46\xb9\xfa\x98\xc7\x3d\x0e\x12\xac\x40\x59\x48\x2c\xb5\x97\x8a\x8e\xeb\xf3\x48\x1e\xec\xf7\x57\x45\x33\xfa\x71\x19\x6e\x77\xe7\xcc\x63\xa7\xdf\x88\x32\x7c\x38\x41\x28\x73\xb4", 192);
*(uint64_t*)0x20002628 = 0xc0;
*(uint64_t*)0x20002630 = 0x200015c0;
memcpy((void*)0x200015c0, "\x6e\x28\x49\x8f\x8f\x0c\xc1\xdd\x9a\x29\xbd\xfb\xb3\x79\x18\x81\xa8\xe1\x63\x53\xe0\x75\xca\x73\xb5\xc3\x6b\xe3\x62\xef\x7f\x1c\x9b\x37\x26\x0e\x93\x4e\x79\xf5\x5c\x41\x55\x45\xf8\x22\xca\x74\x69\xbd\xd1\xa3\xeb\x15\x78\x9a\x57\x25\x76\xe5\xa8\xdd\xb9\x85\x2f\xd5\x5e\xb7\xe5\x78\xa1\x20\xe3\xb0\x12\x10\x0a\xcf\xd9\xbe\xbc\x04\xb1\x68\x9b\xd0\x16\x43\xc2\xd4\xa9\x27\x8f\xf0\xf6\xef\x1a\xb4\x80\x45\x90\xa0\xc1\x59\xef\xc1\xcb\x68\xda\xe9\xa1\x70\x95\x3f\x4b\x37\x0c\x77\x55\x7e\x97\x21\x13\x7e\x57\xb2\x04\x98\xbe\x96\x72\x04\xf1\xaa\x58\x13\x9c\x83\x62\x59\xa3\x9b\x5a\xd0\x99\x21\x4b\x46\x18\x6c\x66\x96\x5b\x56\x87\xbf\x10\xf6\x8b\xb5\x78\xa5\x10\x08\x81\x13\xaf\xea\x4b\x01\xa0\xf7\xf5\x1b\xc0\x87\xb7\xc6\x2d\x87\xcc\x17\xa6\xc4\x43\x16\x80\x87\x21\x03\x70\x42\x03\x45\x90\x5b\x5e\x25\x52\x5e\x85\xb5\x9b\x4a\xd2\x6d\xe0\x7e\x9b\x8b\x83\x0b\x7a\xb0\xb0\x55\x0a\x2f\xe2\xf3\xa7\xd1\x55\x53\x79\xcd\xf8\x57\xe7\xa3\x35\xdb\xa4\xc7\xc8\xc7\x5d\x48\xb8\xde\xfc\xbd\x88\x27\xa0\xc8\x7b\xcc\x0a\x54\xb7\x61\xdb\xb4\xa1\xf9\x8d\x18\xf0\x72\x22\x66\x29\x5c\x2d\x67\x7f\xd7\x58\x00\x1d\x2c\x54\xfe\xcb\x82\x0b\x39\x0d\x83\x37\xc8\xf3\xd3\x65\x55\x41\x85\x1f\xbf\x35\x05\x0c\x8f\x4b\x02\x8a\x40\x23\x40\x5d\x97\x64\xb3\xf6\x83\x66\xc9\xab\xd7\xfc\x09\x91\xb6\xe9\x7b\x36\xdd\x17\xff\x6a\x12\x51\x13\xd2\xcd\x5f\xcb\x8d\x7b\xd9\x16\x77\xc0\x39\x5f\xc7\xba\xc8\x60\x0c\x9f\xe5\x99\x1f\xca\xf8\xeb\xac\x08\xce\xbd\x94\xb2\x68\x7f\xd5\x61\x8f\xbf\xcf\x6f\x47\x99\x62\x70\xb6\xf0\x5f\x60\x06\x3d\xfd\x87\xf4\x11\x31\xaf\x42\x04\x8b\x68\xcd\x46\x39\x08\x71\x45\xb1\xf0\x2c\x2e\xd0\x91\xeb\xf0\x3c\x2c\x8d\x0d\x0d\xdb\xb4\x9a\x6b\x63\x8b\xbb\xb6\xb5\x84\x22\x92\x56\x4d\x04\x28\xa7\xeb\x6d\x02\xdd\x1c\x66\xd3\x43\x3c\x91\x28\x3e\xa8\x48\x79\x22\x1c\x90\x12\xcb\x5b\x4e\x00\xda\x4d\xbf\xcd\x5d\x2f\x57\x09\xe9\x5b\xab\x55\x65\xf9\x73\x16\x3e\x2a\xc7\xe0\x79\x6c\x80\xb2\x79\x5e\xc1\xd7\xd3\xd3\x63\x7f\xf6\x7e\xc7\x9f\x32\x39\xac\x75\x46\xff\x47\x05\xd8\x8b\x6d\xfc\x9c\x78\xef\x3c\x70\x3f\x5e\xdf\x48\xa7\xa8\x3f\x2a\x4d\xf0\x34\xfb\xaf\xe4\xa1\x56\x51\xbf\x8a\x52\x1d\x36\x16\x3c\x75\x13\xc6\x6d\xa0\xab\x9e\x43\xb6\x61\xb9\xea\x55\xf7\x40\xde\x22\x6e\xf4\xbe\x87\x5b\xd3\x49\x99\xbd\x6a\x8f\x2e\x38\x70\x51\x42\x95\xff\xb4\xe3\x32\x0c\x3d\x56\xcd\xcb\xd8\xb9\xcd\xcc\x4a\x9d\x5e\xaf\xca\x9a\x6b\x6d\x12\x2e\xef\x41\xe1\x76\xaf\xe8\x97\xcf\x53\x4f\xc5\xb1\x5a\x95\xa4\x54\xfe\xcb\xcd\xba\x31\x9b\x04\x49\x98\x0c\xb6\xee\x8e\x99\xe7\xae\xa8\x88\x11\x49\x57\x6c\xcd\x7c\x80\xc3\xdc\xc5\xab\x64\xc5\x89\x76\x9f\xf8\x05\x49\xf4\x9f\xd4\x44\x83\x3a\x52\xaa\x88\xe1\x8c\x51\x28\x85\x6e\x9a\x8c\x77\x7d\x51\x52\x87\xf4\x3a\x27\x56\xdd\x37\x03\x0a\xac\x5d\x5a\x29\x8b\x83\x53\x46\x76\x94\xcd\xf5\xb1\xbc\xe3\x6b\x93\x9a\x13\x0c\x83\x6f\x6b\xc8\xc6\x8f\xf2\x6c\x15\x09\x09\xd9\x0f\x86\x3e\x19\x21\xdf\x3a\x7c\x6b\xcb\x82\x1f\x2d\xc3\xfd\xf9\x67\xad\x31\xd4\x25\x4a\x10\xcb\x42\x28\xa8\x6e\xce\xc4\x96\x54\x20\x67\x22\xab\xe4\x91\x95\x2a\xbd\x82\x7a\xe4\x11\x2a\x17\x25\x7e\x4f\x6c\x30\xe6\x6f\xe6\xe1\x50\x21\x62\xfa\x02\xd2\xcd\xc1\x8d\x17\xb3\x6b\x6e\xe6\xc4\x84\x5c\x88\xe6\xc7\x26\xb8\x03\xf0\x51\x29\xbc\xef\x14\x98\xf1\xd5\xf2\xa5\x00\x61\xde\x09\x85\xb7\xd9\xe9\x4d\xbd\x00\xb9\x2a\x46\xf4\xc1\xae\x0e\x85\xba\xa7\x49\x45\xb3\x1d\x92\x3c\xa8\x23\x8f\x08\x5a\xc8\xb4\xc7\x34\x49\xed\x9a\xa8\xe8\x21\xa7\x4d\xc4\xe2\xa7\x8a\x03\x61\x91\xcf\x9a\xc4\x30\xa0\x71\x02\x26\x41\x25\x77\x91\xf7\xb4\x25\xf1\x2b\xac\xca\x08\x17\x77\x64\x63\xda\xa8\x06\x27\x8c\x0e\x36\x9d\xe2\x17\xbc\x40\xdc\x97\xc5\x61\x76\x00\x8c\x8d\x47\x8e\xb6\x13\x02\xa7\x54\x93\x54\x90\x7a\x51\xb3\x48\xb7\xaf\x2b\x01\xa6\x4b\xa9\x35\xd4\xfd\x12\xd8\x40\xa1\x5e\x85\xa6\x7b\xb0\x41\xed\x94\x83\xd5\x8f\x4f\x19\x71\x88\x81\x0e\x07\x3b\x03\x2b\x18\x3e\x55\x47\x4a\x55\x1d\x7f\x2a\xba\xf5\x19\xfe\x2c\x5d\xee\x54\x07\x55\x79\x76\xab\xcc\x9f\x39\xf9\xa5\xa2\x39\x63\xb4\x73\x97\xc0\x2a\xaa\xbb\x71\x59\xe4\xe8\xcd\xd8\xf0\x4e\x82\x15\xcd\x3b\x38\x10\x8d\x24\x03\x37\x65\x34\x26\xe6\x57\xfa\x52\xd0\xce\x91\x76\xb5\x07\xcd\x07\x9a\xd1\x58\x4f\xd9\xb4\x22\x80\x1a\xf9\xae\x08\xf2\x1e\x06\xcb\xbf\xe9\xb3\xf7\xeb\x9d\x25\x6b\x04\xe3\x77\xaf\xff\x2a\x7a\xb9\x2e\x8f\xf5\xd0\xd1\x41\x2a\x01\x15\x84\xc7\x8f\x10\x9f\xda\x20\x81\x64\xf5\x17\x3d\x14\x73\x3f\x94\xbf\x02\x2f\xb8\xe7\xf2\xe1\x63\x2f\x4f\x47\x30\x17\xf8\x54\x0e\xd4\x3a\x1b\x8f\x38\x33\x05\x0a\x1c\x86\xf0\xf6\xbb\x9e\xa1\x57\xa7\x8c\x02\x60\x3d\x7a\x48\x35\x9f\x80\x73\x8f\xa4\xe9\x3d\xd1\xe3\xfb\x42\xc0\x71\x18\x42\x6d\x6f\xcb\xbe\xf2\x5a\x3d\xd5\x5c\x33\x4e\x05\xe4\x7b\x7d\xc9\x00\x1f\x53\xed\x78\x2a\x47\x48\xb1\xc5\xcf\xc5\x98\x56\xcd\x6c\xb4\x80\xbb\xba\x33\x56\x34\x87\xe8\x61\x90\x27\x73\x7e\x92\xd6\x8c\x04\xa6\xd3\x10\x51\x67\x2c\xe9\xbb\x69\x58\x73\x16\x81\xef\xa1\xca\x5c\x76\x9e\x51\x29\x1f\x12\xe8\xc3\x70\xdc\xd5\x64\x4c\x3e\x37\xb1\x41\xdc\xd0\xd4\xb8\x96\x98\xcf\x6d\x3d\x20\x15\x04\x86\xb9\x84\x73\x52\x02\xcf\xed\xba\xf7\xd5\x03\xb0\xde\x8a\xc0\x03\x39\x6d\xb5\x79\x68\x7f\xfe\x0f\x18\x39\x20\x37\xc9\xa2\xc1\xbb\x4e\x84\xbd\x12\x5b\x2b\xa0\x2c\x9e\xae\xc8\x8a\x38\x13\x93\x9d\xc3\xdc\xb1\x77\x39\xde\xef\x8d\xf7\x24\x6e\xae\xb9\x12\x7a\x64\xf4\xfb\xe3\xd2\x2c\xfb\x99\x14\xe7\xef\x60\xc4\xd5\x8a\x9a\x66\xd3\xf5\x37\x66\x57\x65\xec\xfa\xf7\x4f\x8d\xb9\x08\x04\x89\x40\x6c\xa9\x16\xaf\x0c\xbe\x95\xcc\x97\xa4\xf5\x52\x0d\x99\x42\xcd\xb3\x38\x1a\x62\x4d\xe0\xb6\x68\x3d\x2e\xd1\xf4\x4e\x3c\x13\x48\x86\xda\x33\xd8\xc6\x41\xb5\xd7\x89\xb9\x4c\x46\xa6\x5d\xb1\x55\x76\x4d\x6d\x60\xdc\x9d\xef\xc2\xb9\xa2\x8e\xd5\x2e\xfe\x08\x60\xe8\x0b\xef\x5a\x53\x28\x45\xc6\xb8\xab\x22\xfa\xc4\x61\x69\x6c\x29\x5e\xe0\x57\xe4\x30\x30\x7a\x5c\x94\x2c\x0f\x6a\x33\x57\xb3\x4e\xdd\x54\xa6\xa2\x71\x3b\x0a\x60\xd4\x55\x7f\x3f\xa0\x12\x1f\xd1\x13\xf7\x62\x56\xe6\x3c\xe2\xb0\x15\x58\x5c\xbc\x6c\x2c\x7e\x75\x25\x4e\x20\xd5\x33\x0f\xb7\xed\x1d\xfa\x27\x0e\xdb\xb2\x90\x13\xcd\x82\xb8\xc4\xc9\xbb\x17\xc6\x0e\xb4\x9b\x88\xa0\x6d\x63\xb5\x9c\x15\x1c\x85\xd6\xfb\x45\xa5\xcf\x6d\x50\x54\xdc\x55\xe1\x1e\x7e\xe5\xea\x52\x8e\x5d\x35\x49\xad\xe9\x06\x57\x33\x1e\x15\x94\xb3\xbe\x69\xc2\x1f\x2e\x2a\x11\xbf\x84\xc9\x6c\x9d\xa0\xd3\x93\x8e\x25\x1c\x98\x02\xa6\x51\x6e\x8b\x43\x4b\x5f\xc7\x62\xac\x0f\x4c\x5d\xc0\x7f\x75\xe1\x1a\xa6\x35\x7a\xb6\xf8\x0e\x30\xf9\x8e\xaf\xf0\xfc\xd1\x59\x59\x88\x69\xef\x45\xd9\x3b\x81\x57\x3a\x9f\xcc\x9b\xda\x9f\xbb\x19\x60\x92\xb8\x7a\x37\x74\x7a\x5e\x6d\x29\x3a\x81\x06\xfd\x8e\xd4\x63\x07\xcf\xb4\x82\x77\x11\xd0\xa7\x01\xd9\x1f\x71\x5c\xa0\xb0\x84\xf9\xb4\xe4\xd9\xc2\x56\xd6\xe5\xa1\xd5\xb3\xe8\xfb\x46\x5b\xaf\x85\x91\xab\x6b\x4d\x72\x1d\x9a\x08\x6e\x38\x0a\x86\x48\xa2\xd2\x3a\x69\xa1\xb9\x4f\xe7\x2c\x97\x55\xb9\xdc\x31\x85\x54\x3d\xca\x8d\x47\xbb\xc1\xd5\xe4\xe3\xce\x61\x40\x9c\xf4\xca\x24\xc4\xf0\x7d\x8b\x4d\x14\x01\x4b\x97\x86\x02\x96\x0e\x6b\x9f\xf6\x80\x10\x45\x7c\x63\x8d\xb3\x44\xaa\x2f\xa6\xc2\x09\xb3\x00\xf8\x3d\xe4\x6f\xb3\x75\x95\xd7\x05\xa1\xcc\xff\xe9\xb4\xf2\x0a\x12\x05\xf2\xb3\x30\xdd\x6b\x40\x50\x48\x22\x5b\xd2\xc0\xdc\xf5\x99\x25\xee\x65\xcc\xf3\x30\x19\x52\xa0\x8d\xb7\xa2\x14\x40\x63\xcd\x88\xc0\x14\x6a\x67\xc3\x1d\xc0\x90\xd6\x9c\xd8\xb2\x3c\x1e\xda\x77\xbe\xc6\x71\x21\x67\x98\x2d\xbf\x22\xbb\x67\xc3\x0f\xd0\xef\x09\xea\x93\x69\x32\x9a\x4b\x5b\x3f\x6b\x2f\x09\x2c\x77\x45\xb7\x14\x8f\x14\xde\x67\x19\xb0\xac\x06\x9a\x5e\x51\x28\x2d\x95\x37\x0b\x7a\xea\x13\x72\x9a\xcb\xfc\x95\xe9\x7d\x02\x01\xf3\xcc\xbe\x14\x50\x5d\x6c\x9f\x23\x64\xfb\x85\x90\xa7\x55\x46\x03\x59\x9e\xcb\x32\x99\xb3\xef\x43\xda\x35\x35\xac\xf1\xe6\x4d\xdd\x32\x9e\xba\x73\x12\xd0\x59\xed\x95\x0a\xaf\x94\x84\xb3\x51\x58\x50\x4c\x2d\xa8\xa9\x67\x62\x9d\xeb\x3c\xba\xcb\xe1\x85\xa7\xe0\xe4\x95\x5b\x43\x9e\xe6\x56\x81\xf5\xe7\xd8\xf0\x90\x40\xd4\x90\x70\x72\x43\x99\x22\xc8\x22\xa9\xbe\xd8\x28\x99\x41\x6c\x69\xe9\xef\x1b\x21\xd5\x6e\x82\x9a\xc9\x5b\x17\xb1\x96\x07\x7b\xa3\xea\xd5\x80\x8c\x02\x1e\x4e\x80\x9b\x50\x15\x94\x1d\x60\x36\x6e\xd4\xac\x55\xcd\x09\xca\x91\xc2\x0a\xeb\x64\x99\x21\x7c\x14\x23\xe6\x51\xf0\xba\xf6\x86\xfe\x88\xa3\x94\xdf\x65\x8a\xd7\xee\x43\x08\x1a\x50\xd8\xbd\x9d\xd5\x2b\xa2\xcd\xa9\xbc\x72\x81\x3b\x29\xa4\x0c\x26\x14\x81\x82\x92\xdb\x5d\x64\x70\x05\xef\x6b\x0b\x49\xb6\xb1\x9f\xd7\xe9\x95\x69\xea\xa6\x64\x30\xe0\x62\xe9\x94\x3a\x08\x22\x5b\xbd\x27\xd4\x1f\xcd\xde\xd4\xc5\xac\x34\x48\x09\x88\x98\x43\xe0\xa6\xf6\x07\x8d\x91\x41\x76\xfe\xeb\x53\x38\xb1\xc1\xf0\x40\x00\xce\xda\x9d\xc8\x79\xf0\xb9\x1e\x10\xbb\x36\x74\x6d\xae\x04\x90\x7c\xb0\x49\x57\x64\xc7\x76\x21\xde\xb3\x68\x63\xec\x54\x82\x29\xf4\x5e\xfe\x46\x73\xf6\x56\x82\x10\x19\x43\x66\xbe\x09\x23\x88\xc9\xdd\xf1\x1d\x7d\x5b\xe1\x7a\x09\xc9\x3a\x17\x03\xe5\xdf\xd8\xef\x28\xfe\x55\x1b\xb9\xb5\xf8\xb7\xbe\xe0\xe1\x74\xd0\xcd\x32\x66\xd3\xdd\x23\x1e\x5b\xac\x1b\x36\x49\x7a\xd2\x81\x78\x39\x3e\x1d\xc4\x32\xe3\xbf\x92\x02\x4c\x21\x78\xbd\x2b\x1a\x74\x4c\x8a\xd3\xd5\x52\x9d\x00\x96\x24\x1c\x46\x51\xd4\xc2\x73\x66\x77\xc4\x7e\x29\xa5\x23\x04\x11\xda\x2c\xbf\xb3\x70\x26\xed\xff\x8a\x86\x05\x85\xb6\x03\x27\x42\xf1\x27\xfb\x36\xf2\x14\x1f\x6a\x1a\x08\x04\x53\x9b\x76\xfc\x10\x7d\x08\xff\xa2\x8f\xb5\x1e\xa9\x2e\xf3\xc3\xf5\x5f\x27\xb8\xd7\x8b\xc0\x77\xbb\x44\xb4\x1f\xc8\x5d\x58\x1a\x65\x04\x59\x97\x00\x86\xb0\x78\x1d\xb3\x1d\x30\xf4\xc8\xd1\x16\x91\x0d\xcf\xa6\xdc\xa9\xfb\xf7\x08\x85\x79\x76\xe9\xad\x31\xb0\x1c\x65\xf8\xf7\x9e\xeb\x0e\x5f\x86\x24\xf2\x47\x3b\x01\x5f\x40\x2c\xdb\x4a\xb4\xa5\xe3\x75\x91\xac\x1e\xfc\xfc\x92\xaa\x48\xd2\x59\x27\xe5\xf9\xd1\x91\xbf\x20\x46\x25\xf8\x8e\xb7\x8a\x65\xee\x34\xa7\x91\xf9\x92\x42\x5a\xab\xc7\x5e\x4a\xb4\xd0\x7b\x8d\x51\x91\x1b\xb1\x1b\x81\x87\x07\xf7\x7a\x8c\x1a\x9f\x0b\x2e\xf9\xe8\xba\xcf\x1f\xae\x0b\x24\x16\xa5\xcc\x81\x07\x75\x8e\xf8\x2c\x72\x5c\x46\x24\xb8\xc8\xb7\x21\xe6\x38\xd3\x67\x8e\x48\x9d\xf4\x68\x04\x06\x66\x6f\xcb\x65\xbb\x92\x15\x0f\x09\x0f\x09\x08\xd9\xac\x51\xe7\x50\xbe\xea\x58\x42\x05\xb4\x4b\x7c\xc5\x4e\x37\x4e\x8f\x7a\x31\xd2\x07\x23\x8d\x88\xdd\xc9\xcd\x03\x2f\x73\x13\x17\xbd\x6c\x88\x41\xe1\xda\xcc\x5a\xc9\x37\x38\x21\xa0\xa5\x05\x32\x37\x90\xf9\xfe\x10\x9a\x1c\x89\xc0\x43\x67\xc1\x7f\x3d\x4c\xb8\x2e\xaf\xed\x19\xa0\x12\x7f\xac\xf2\xdc\xbb\x9a\xf4\x03\xff\x76\x4b\xa3\x39\xf2\xf7\xf2\xf7\x56\xf9\x8f\xe2\x63\x45\x8f\x1c\x71\x8d\xe5\xbd\x82\xd1\x76\xaf\xb4\x5a\xb8\x28\xad\x9d\x0f\xe3\x7e\x2e\x89\xe7\x9f\x22\xf2\x18\x38\x47\x7f\x99\x56\x07\x05\x75\x55\xd4\x35\xe0\x8e\x6b\xf6\xf2\x3e\x18\x57\x3f\xf4\x4e\x23\x3e\x7a\x3b\x7a\xae\x28\x03\xe3\x02\x85\x2f\xdc\x9a\x47\xd8\x99\x2b\xbb\x56\xc6\x2a\x63\xee\x48\x84\x49\x00\x69\x9a\x61\x05\x16\xe2\x83\x05\x70\x2e\x52\x87\xc6\x7b\x4e\x31\xa1\x82\x4f\x9d\x9b\xdd\x9e\xe7\x71\xc6\x82\xee\x5d\x03\x48\x49\x17\xd3\xa8\x01\x65\x70\x53\x76\xe6\xfb\x06\x57\x7f\xb2\x67\x69\xe0\x0f\xc6\x23\xc2\x67\xeb\x21\xbd\xda\x9d\xfd\x82\xd0\xd1\x4b\xed\xd6\x09\x9f\xb8\x6e\x9e\x23\x7a\xea\xd8\x65\x2e\xc7\xa2\x74\x1e\xea\x94\x58\xce\x49\x6c\xce\x06\xcc\x80\x57\x28\xe9\x75\x77\xc9\x89\x7c\xb7\x14\x9a\x85\x89\xf6\xa8\x4c\x17\x34\x0b\x36\xf5\x6d\x18\x38\xd0\x47\x77\x2b\xac\x8d\xc1\xa4\xc9\x5e\xa6\x9e\xa1\x20\x2f\x8b\x0c\x52\xfb\xdc\xf4\xaf\x89\x06\x9d\xc2\x55\xd5\x23\x03\x4f\x3b\x07\x7f\x7e\xf5\x5b\x36\xe6\x14\xb8\xc5\x92\xd3\x48\xa0\x25\xdc\x92\x4c\x6f\xb3\x8b\x0c\xd3\x0c\x74\x4d\x2e\xb6\xf5\x6d\xae\x3d\x12\x2e\x42\x1d\x3a\x7e\x87\xf9\x84\xfa\x3f\x19\xce\xb6\xbb\xfc\xd8\x92\x1a\xef\x47\xdf\x83\xbd\x19\xf5\x93\xf5\x05\x2e\x7a\x9b\x13\x15\xd4\x62\xa7\xd3\xac\xeb\xb0\xfd\x1e\xd8\xec\xb7\xa5\x86\x56\x92\x8b\x7a\xdb\x8b\x38\x07\xd1\x5d\x1e\xed\x74\x0b\x6c\x5e\x5e\x69\x2b\x43\xce\xd7\xf0\xaa\x38\x80\xeb\x02\x27\xbf\x91\xb9\xf1\x07\x8c\xee\xb1\xb6\xee\xe2\x3a\x7a\x09\xfb\x05\x44\x1d\xba\x2a\x62\x6f\xfd\xe8\x0a\xca\xc5\x53\x0e\x76\xf3\x6c\xe4\xbf\xb2\x44\x66\x6d\xf3\x2f\xf4\x40\x6c\x5f\x98\x58\xfa\x50\xcf\x90\x49\x91\xae\x97\x20\x70\xdb\xdf\xf2\xa4\x43\x8d\x11\xed\x8e\xd3\x57\x02\x24\x21\xa7\x18\xfc\x07\x8e\x43\xe1\xf8\x62\x7d\x69\xea\xd2\x9c\x4a\x01\x41\xf8\x4a\x5f\xe3\xa9\xf7\xed\xe7\xe9\x9a\x17\x78\x4c\xe2\x34\x38\xa1\x76\x97\xc5\x13\x99\x82\x95\x3d\xd5\x13\x3d\x4d\x33\xa1\xeb\x16\xa5\xa7\xc3\xcd\x9f\x3c\x03\xb1\x82\x87\xb8\x43\xff\x40\x60\xe6\x7c\xac\x6f\xb0\xed\x75\x4c\x6b\x23\x27\xa4\x1a\x05\x7f\x6e\x39\x3b\xd3\x41\xcf\x54\xe4\x3b\x0e\xf6\x6b\xde\x84\xa5\x73\xe6\xf9\x62\x9d\x55\xe0\x1d\x80\x24\xe9\x58\xa9\x34\xe5\x9a\x26\x1b\x04\x73\x5c\x91\xf6\xcc\x8f\x33\x6b\x41\xea\x74\x8b\x4a\x7c\xd1\x97\x6c\x51\x8e\x1c\x12\x82\x1c\xe2\x9b\xba\xea\x70\xeb\xa9\xd7\x5b\xd0\x21\x64\x97\xe5\x50\x5c\x2d\x3e\x50\x1b\x41\x19\x47\x0b\xf3\xa0\xd2\xbd\x85\xcc\x86\xdf\x1b\x53\x79\x24\xc3\xa2\x4a\xb9\x29\xc9\xa4\xd9\x1a\x51\x09\x11\xc9\x30\xa5\x61\x62\x5e\xdf\x77\xe6\x07\xc9\xe7\x9d\x2f\xd6\xe5\x92\x0a\x23\xd7\x49\x0d\x78\x1a\xd4\x6e\x38\xbf\x59\xea\x2e\x64\xb3\x2d\xf1\xbb\xca\x0e\xe0\x9d\x87\xcf\xa9\xec\xb8\x6b\x46\xbe\x72\x06\x3a\xc6\xb7\xb9\xbb\x41\x28\x0f\x83\xac\x63\x51\xd7\x71\x52\x8f\xc3\xdf\x6d\xcf\x29\xd2\x9a\x1e\x04\xe2\xd5\xa7\xc8\xbd\xee\x88\xd6\xac\xf0\x2e\xe0\x77\x6d\x43\x5f\xf6\xd7\xc7\x2a\xf8\xcb\x17\xcb\xef\xe8\x7e\xce\x06\xb2\x27\x9d\xe7\xaa\x25\x46\x1f\x88\x6b\xea\xb5\x14\x29\x80\x1b\xa9\x67\xf8\x86\x23\x16\xe1\xcc\xac\x10\x7d\x15\xa3\xbd\x86\x18\xd2\x11\xac\xff\x42\x80\x06\xa5\xe4\xc0\x48\xaa\x7a\xaa\xeb\x62\x1d\xc0\x1a\xaa\xf2\x81\xbe\xc0\x3a\x41\x2d\xc7\x5d\x89\xa3\xa3\xe8\x23\x13\x39\x70\x96\xf7\x59\x5a\xf8\x8b\xc3\xad\xce\x11\x42\xec\xc6\xe2\xf4\x7e\xc9\x93\xf7\xed\x73\xd5\x61\x49\x80\x1f\xb0\x11\xac\xbf\x74\xc6\x01\x03\x85\xa0\x83\x79\xba\xbb\x03\x76\x28\x5e\x59\x10\x1a\xed\xc3\xb1\x24\x3c\x11\x26\xc6\x3d\x6c\xc8\x9e\x86\xe5\xd6\xbe\x27\xed\xbb\x73\x60\x7d\x7a\x57\x9a\xbf\x0f\xa3\x42", 3338);
*(uint64_t*)0x20002638 = 0xd0a;
	syscall(__NR_pwritev, r[0], 0x200025c0ul, 8ul, 0xded2, 0);
	syscall(__NR_fallocate, r[1], 3ul, 0x10000ul, 0x80000000ul);
	return 0;
}
