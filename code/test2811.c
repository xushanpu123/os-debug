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

#ifndef __NR_pwritev2
#define __NR_pwritev2 328
#endif

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
*(uint64_t*)0x20000000 = 0x200000c0;
memcpy((void*)0x200000c0, "\x54\xb6\x39\xdd\xb4\x37\xdc\xf1\xa4\x62\x9c\x43\xbc\x26\x68\xf6\x1a\x1d\x3f\xb9\x57\xc2\x86\x2e\xd0\x90\xdb\x93\x29\x1c\xeb\xc1\x9f\xf6\xa4\x7b\x4c\xc1\xb5\x13\xc6\x86\x8d\x16\x43\x6c\x34\x81\x7c\x14\xdc\x64\xc3\x53\xdd\x60\xf5\xcd\x2e\xef\x32\xfd\xf2\x7f\x2a\x69\xc1\x27\xf5\xc9\xde\x42\x9e\x17\xfc\xc3\x51\x6f\xbf\xb6\x5b\x4a\x1f\x43\x5b\x6b\xa9\x08\x41\xea\x99\xf8\x41\x3a\x6a\xf3\x91\xb3\x99\x1f\x9d\x1f\xb6\x97\xbe\x12\x5b\x80\xf4\xa6\x4e\xe6\xb8\x8d\x4d\x74\x96\x34\x95\xb3\x19\x19\x9f\xa4\xad\xff\x36\x41\xe1\xe9\xa1\xf6\x3b\x2b\x0a\xae\x4c\xe1\x86\x66\x11\x93\x08\x11\x05\x9a\xef\x79", 148);
*(uint64_t*)0x20000008 = 0x94;
*(uint64_t*)0x20000010 = 0x20000180;
memcpy((void*)0x20000180, "\xc7\xdd\xc3\x26\x8f\x03\x6d\x49\xfd\xb0\xe9\xdb\xf5\x98\x26\x58\x62\x43\xa7\x36\x75\x19\xf9\x6a\xeb\xd1\xc6\x80\xb3\xf0\x32\xf8\xf2\x5e\xc7\xe3\xc6\x5a\x80\xcd\xb5\xf2\x08\xcf\xab\x38\x3b\xac\xa4\xff\x35\xbb\x00\x22\x9c\xf1\xfb\x17\x7c\xfb\x16\x9d\xf4\x40\xff\xc7\x5b\x71\xaa\xce\xc9\xa3\xe5\xda\x96\x48\xa8\x3c\x20\xb1\xc1\x2b\xf1\x0f\xa6\x78\x11\x51\xb5\xe2\xf6\x60\x4b\x49\xb0\x02\x87\x0e\x29\x86\xe4\x65\x6e\xca\x5c\x43\x88\x7b\xee\x5f\x25\x9a\x39\xf5\x5e\x8a\xcf\xbd\xc4\x56\xfd\x58\x35\x4f\x18\xd2\x86\xb1\xc3\xc7\xca\x5c\xf0\xeb\xeb\xeb\xbf\xc3\x8c\x49\xfe\xaa\x10\x5e\x48\x22\xd6\xc3\xe3\x84\x57\xd3\xe6\x52\xef\x51\x20\x10\x88\xb6\x07\xec\x5f\x11\x05\xd5\xe5\xab\x9d\xaa\x27\x02\xa3\xfb\xce\xc4\xda\xa6\xfe\x73\x08\x04\x2c\x53\xf1\x2b\x14\x8d\xdd\x1e\xc0\xfc\x10\x81\x24\x2a\x7f\xc6\xd1\xc9\xc3\xd7\xff\x1f\xbd\xd2\x46\x12\x2d\x86\xd0\x76\x9c\x24\x33\x38\x4c\xf0\xf1\x42\x83\xb1\x53\x2c\x08\x6e\x55\x07\xf7\xb1\xa1\xcd\xcd\xd3\x18\xce\x49\x09\xb8\xa7\x52\x14\x19\x26\x49\x86\x00\x90\x02\x90\x48\x8b\xe1\x6f\x7d\x26\x65\x14\x8f\x34\x06\xb0\x2d\xfc\x7e\x9e\x3d\x15\x84\x7b\x90\x1c\xaf\xe0\x35\x4e\x38\xb4\xb3\xa2\xa9\x77\x64\x57\x5c\xa7\xe0\x74\x9f\x9a\x4e\x27\x8f\xf0\xda\xdc\x6c\xf1\x84\x55\x75\x9e\x08\xf1\xfb\xcc\x5f\x51\xe6\x71\x8a\x70\x57\xeb\x1c\x17\xdf\x17\x6b\x44\x00\x35\xac\x63\xe5\xe6\xc8\xa6\xe0\x65\xab\xc8\xf2\x52\xdd\x0a\x9f\x65\xe0\x00\xad\x2e\xc2\x8f\x23\x0c\xaa\x0f\x1d\xdd\xb0\xcf\x2c\x49\xa9\x8f\x1a\x49\x23\xa5\x00\x19\xcd\xb6\xfb\xd6\xa2\xf2\xd3\x62\x9a\x03\x68\xc9\xfe\x14\x99\xd8\x29\xda\xb0\xab\x7c\xa5\x8c\xdb\xc4\x09\x44\xc2\xf6\xe4\x72\x67\xb0\x85\xc4\x8a\x75\xba\x9c\x6d\x54\x2a\x99\x8d\x0b\x20\x13\xda\xe6\x9a\x2d\x0b\xf9\xff\x31\x85\xd2\xf6\x45\x64\x33\x9d\x69\xf4\x18\x02\xfd\x50\x49\x12\xe9\xbe\x50\x13\xad\x1e\x75\xd0\xe2\x96\x91\xbf\x5d\xed\x75\xc7\x09\x6b\xa7\xf0\x67\x22\x25\xc1\xa8\xa7\x64\xf1\x42\x15\xfa\xb2\xa0\x73\x1e\x68\xe6\xa5\x2e\xc8\xe3\xe0\x16\xb9\x77\x7f\x59\x74\xe2\xbd\x61\x63\x9f\xb9\x0f\xf5\xd7\x42\x95\x6c\x8f\x45\x66\x67\xf2\x8f\xfb\x6b\x4b\x63\xe6\x23\x4a\xe1\xaf\x7d\x91\x9c\xe7\x18\x9d\x20\x42\x09\x59\x46\x79\x80\xba\x6c\x52\x70\x80\xab\x4d\xc0\xc4\x7c\x10\x53\x85\x76\x70\xe3\x58\xc9\xbe\x80\x71\xef\x25\x98\x5e\x99\x7a\x2d\x90\x73\x1e\xa7\x34\x5c\x11\x84\xf4\x7c\x5e\x78\x33\xb2\xf5\xcf\x1b\x35\x3e\xc0\x94\xfa\x3e\xf9\xec\xa9\x33\xbc\x0b\x15\x6b\x04\xff\xe6\xa7\xcb\x52\x41\x8d\x12\x52\x0b\x21\x1a\x90\xe2\xbb\x12\x74\x79\xee\xda\xac\x7b\x55\x24\xfd\x01\x1b\xa4\xe8\x63\x8b\x6f\x04\x1b\x78\xbf\x40\x0d\xe8\xa0\xa8\x44\x35\x12\x13\xd4\x80\x1f\xa8\x14\xb4\x0f\x77\xc6\x99\x80\xa7\x2d\xcf\x94\x50\x9a\x46\x60\x5e\xe8\x96\xb3\x06\xa1\xa8\xd5\x13\xeb\x58\x21\xa4\xc2\x96\xc5\x2c\xe0\xb3\xf1\xfc\xee\x63\xc6\x22\xb9\xcb\x74\x82\xf7\xde\xfe\xf9\x63\x31\xf1\xfa\xaa\x23\x8e\xd7\x4d\xbd\xbb\x2a\x23\x95\x79\x6f\x57\xb5\xe9\x80\x5f\x55\x64\x4b\xae\x53\xd0\x20\x12\x44\x34\x78\x1c\xe8\xd1\x13\x6a\x12\x7f\x1f\x83\x87\xaf\xbd\x67\xf6\x77\xae\x2b\x79\x23\x19\xdd\xf7\x7d\xc4\xc8\xc6\xbd\x79\x6b\xd0\x0e\x53\xd1\x90\xee\x8c\x70\x2a\x15\x64\x88\xde\xa2\x97\xb8\x81\x45\xe7\xf6\x8c\xf6\x48\xc6\x94\xb5\x7d\x17\xfc\x6d\x54\x52\xa0\x01\x41\x30\x0e\x83\xcd\x72\xe4\x52\x79\x60\x60\xc1\xbf\x9b\x93\x4b\x0d\x86\x9a\x6a\xac\xcf\xf9\x2f\x8e\x40\xa7\x5d\x42\xe8\xa6\x8f\x19\x57\x3f\x33\xba\x58\xe9\x7c\x52\xb7\x01\x53\x1f\x2e\x0f\x17\x51\xc3\xab\x6b\x98\x25\x9f\x95\x35\x48\xa8\x66\xe7\x88\xb9\xec\x81\xbd\x03\x0c\x93\xad\xc8\x87\x02\xa4\x51\x86\xd0\x24\x3b\xb4\x8b\x00\x76\xaa\x5c\x9b\xcc\x6e\x82\xd0\x31\x86\x2e\x1f\x17\xc2\xc3\xa1\x76\x6c\x79\xe9\x90\xd9\xa0\x8d\x1e\xca\x85\x1d\xb2\xc4\x23\xb8\xbe\x22\x37\xa5\x64\x45\x47\x89\xb9\xd4\xad\x62\xfb\x10\x0f\x83\xf0\x20\x00\xfb\x1c\x0e\x1e\xaf\x1f\xca\x60\xb0\xec\x2c\xd1\xe8\x59\xed\x9f\x22\xb8\x88\xec\x7f\x30\x59\x56\x51\x25\x7c\xab\xf4\x87\x94\x57\xa7\xb7\x56\x19\x00\xc4\x6b\xda\x63\xf8\x8c\x2d\xbc\xf2\x54\xfe\xa5\xba\x41\x6b\x87\x1d\xea\x05\xd3\xb2\xaf\xc3\x93\xfc\xb6\x02\x4e\x16\x50\x3a\xed\xa0\x26\x33\xbb\x16\xad\xfe\x77\x30\x82\xaa\x3d\x45\xc3\x2b\x9b\x28\x14\x8b\x81\x71\x3a\x39\xa4\x10\xeb\x8b\xca\x62\xbc\x07\x3a\x83\x63\x2b\xcd\x96\x69\x9c\x5e\xf2\xa4\xc9\x72\x0a\x57\x21\x5d\x87\x10\x27\x69\xaf\xc7\xaa\x1b\x94\xf5\xea\x60\xc8\x91\x06\xc7\x2a\xe5\x2b\xa4\x65\x4e\x1f\xb6\x00\xf0\x1a\x5f\x31\x41\x40\xee\x28\x6a\x2d\x66\x8b\xfa\x6d\x32\x47\x42\x12\x10\xc1\x3c\x44\x88\xf3\x47\xd1\x60\x51\x8d\x35\x47\x20\x22\x14\xd1\x11\x60\xfb\xac\x2c\xe4\x10\x81\x91\xae\xd0\x61\xb9\x83\xad\x2d\x92\x2e\xda\x9c\xaf\x9b\xf5\xe2\xf4\x04\x50\x67\xe0\x4d\xee\x43\x2b\x5a\x23\xea\xbc\xee\xa6\x13\x2d\x94\xfb\x05\x81\x31\x16\xae\x0b\x4d\x19\xcf\x90\xf5\x03\x3f\x73\x9d\x38\x33\x84\xce\x36\x37\x69\x02\xc8\xc5\x26\x7c\x64\xff\x4a\x42\x37\x42\x60\xf2\x7f\x49\x29\x59\xc1\xa5\x01\xec\x86\xa2\x31\x17\x45\x4e\x44\x84\x1a\x3e\xf5\x08\xb8\x52\x6b\x2a\xdf\xcb\xb5\xec\x13\x79\xb3\xac\x2e\x2d\x35\x0b\x93\x0e\x99\xc0\x3b\x11\x63\x9a\xf6\x9a\xcf\x33\x0f\xac\xcc\xb4\x57\x34\xa4\xac\xce\x65\xd2\xfc\xa8\xa6\x7c\x32\x61\xe6\x45\x62\x85\xa1\x9a\x30\xbe\x86\xf2\x5b\xc3\x77\xa2\x73\x7d\x9c\xce\xbd\x7e\x09\x81\xf1\xc1\x79\x1b\x74\x95\x94\x2b\x37\x24\x53\x13\x59\xaf\x84\xbc\xcc\xd6\x21\x46\x9e\x1b\xed\x96\x0c\xda\xee\x91\x85\x75\xd3\xaf\x05\x5b\x0a\xcc\x90\xcc\xcd\x4f\xec\x4f\xec\x01\xe2\xa5\xdf\x19\xb2\x33\xbc\xe3\x1e\x1e\x60\x05\x14\x55\x40\xc4\x14\x40\x59\x97\x4b\xf8\x70\xd9\xde\x6a\x08\x88\x13\x5b\x2c\xdf\x51\xc4\xc8\x9d\xe5\xd2\x23\xdd\x39\x26\xe6\x56\x61\x20\x09\x8d\x86\x05\x0b\x46\x6c\xb3\xa1\x6f\xa4\x5e\xc5\x35\xad\x92\x3e\xe6\x76\xe8\xda\x4e\xc3\x9d\x92\xc7\x79\xa5\x5d\x57\x01\x49\x42\xe3\x10\x46\xd7\x0a\x03\xee\x96\xe4\x35\x34\x5e\xeb\xae\xbf\xd2\x95\xa4\xbb\x84\xab\x7b\x89\x39\x5e\x3a\x1a\x96\x70\x2d\x00\x10\xdd\x9a\x8e\xc0\x2d\xd2\xde\xa9\xcf\x8c\xf5\x77\x67\x3f\x26\x1f\xb3\xbc\xb9\xca\x18\x46\xab\x74\x16\x9c\x06\xe2\xae\xf8\x18\x1e\xde\x5e\xa2\x6a\x0c\xe9\x75\x3f\x8f\xb2\xd4\x49\x5b\xd7\x31\xe2\xc6\xf8\xac\x09\xd8\x3b\x4f\x1b\x80\x40\xec\x89\x24\x0f\x47\xfb\x9c\xb7\xdb\xc4\x95\xc8\xe0\x52\xd4\x27\x3c\x6c\x06\x48\x1c\xa0\x85\x6d\x42\x76\xff\x2a\xca\x80\x2a\xf6\xb4\x66\xc8\xb4\xd7\xc6\x2b\x8d\xeb\x3e\x76\x47\x92\xb9\x96\x02\xdf\xb3\x97\xa2\x6f\x99\xab\xed\x6d\x9e\xd4\xe2\xa2\xad\xa6\xec\x5d\xef\x81\xcb\x5a\xdd\xdb\xff\xd9\xdf\xdd\x13\x1d\xfb\x9e\xf2\x93\xa2\x81\xed\xb4\x91\x45\xab\x85\x39\x3e\x89\x68\x53\x96\xf9\x4c\xbe\x22\x4d\x92\x09\x2d\x6d\x69\xc2\xc9\x1e\x86\xe6\x6c\xa6\xb1\x1b\x16\x07\x63\x6b\x90\xff\x01\xe0\x7f\xcb\x06\x0f\x1d\xd7\x55\x9b\x8a\x33\x51\xa0\xef\x0a\xec\xec\xdc\x28\x67\x43\x5d\x17\xde\x36\xd1\xe1\x2c\x83\xc6\x95\xc0\x88\x6e\x71\x3a\x4a\x0a\x0b\x03\x51\x6a\xff\x20\x9d\x95\x08\xd4\x70\xea\x76\x2d\x4c\x5a\x71\x95\x39\x53\x42\x61\x12\xd3\xe9\xd7\x70\xbc\x36\xa8\x54\xe4\x03\xec\x34\x4f\x06\x0d\xf1\x14\xd6\x93\xe3\xee\xd9\xe2\x15\x33\xcb\x6d\x61\xd8\x82\x3d\xc2\x4c\x22\x23\x81\x08\xff\x33\x2f\x36\x04\xd4\x15\x99\x7b\x10\x38\x7f\xaf\x69\xe5\xae\x29\xc7\x3d\x23\xe7\xfe\xbf\x66\x5b\x25\xab\x4c\xb9\xfb\x52\x06\x01\xcb\x6a\x44\xdf\x1a\xb5\x97\x49\x1b\x5c\x3d\xea\xe2\x69\xf7\x7f\x4f\x7c\xaf\x7c\x46\x6d\xba\x3a\xbe\x53\x49\xb5\x87\x6b\xba\x98\x07\x53\xf0\x0c\x5a\xc1\x3a\x3d\x7f\x86\xa2\x4e\x32\x69\xf3\x63\x29\x15\xc2\x61\x39\x14\x59\x47\xfd\x00\x20\xed\x33\xed\x2b\xfc\xea\xc3\xd0\xdc\x51\x23\x38\xb1\xe1\x64\xa1\x63\x40\xd8\xc8\xb3\xae\x57\x9a\xb9\x66\x11\x9c\xb0\xf8\x8f\xe8\x6f\x0e\x73\x9f\x18\x25\x81\x96\x94\x8c\x62\xd5\x90\x99\x80\x46\x9c\xdf\x2a\xe6\x0d\xef\x3b\x4f\x3f\xa0\xc9\xf0\x83\x34\xd7\x6b\xb3\x0e\x03\xf3\x88\xa5\x78\x42\x2f\x1d\x53\x8f\x93\xa4\x31\x28\x0f\x08\x83\xd2\x40\x44\x21\x84\xb3\x6c\x80\xd2\xae\x86\x64\xf9\x9f\x8e\xa9\xb9\xb2\x4a\xae\xe1\x79\x04\x74\x43\xab\xd0\xbe\x08\x3c\x69\x6f\x8e\xca\x7c\x06\xda\xd6\xd8\x53\x3e\xb9\xeb\x21\x7f\x3b\xe7\xed\x22\x1d\x33\x10\x6a\x78\xd1\x9a\x4e\xa8\x83\x26\x27\x14\x42\x6f\xbc\xb5\xa6\x82\x32\x4f\x0b\x75\x48\xaa\x32\xec\x43\xd9\x9e\x31\xc9\xc1\xfc\xc0\x4f\x5a\xb2\xc3\xc3\xf9\x8c\xcb\x48\x52\x2e\x69\xee\xbc\xa0\xa2\xd3\x95\xca\x0a\xc3\x2c\xba\xf7\xaf\x67\x89\xb7\xa9\x4b\xbc\x8e\xb7\xc8\x44\x56\xc0\xb0\x9d\x08\xbb\x93\x90\x05\x56\xf4\x98\xb0\xa0\x78\x3e\x06\x63\x57\x1c\xb0\x01\xf8\x6e\x8d\xe4\x80\xb8\xad\xb7\xc9\x12\xb6\x9a\xbb\x4b\x9c\xed\xd7\x76\xb5\x3e\x98\x41\xd6\xe0\xe5\x83\xc2\x00\x61\x5c\x33\x43\x5c\x18\x4b\xaf\x9e\xd8\x40\xb1\xc9\x44\xe7\x0c\x71\x66\xdb\x5f\xc2\x58\x3f\xd6\xa1\x3c\x79\x76\xa5\x25\xac\xfb\x6a\x94\xa7\x5c\x4e\x6d\x18\x14\x18\xce\x2f\x98\x86\x42\x8a\x21\xe3\xac\x94\x47\xc3\x34\xa3\x3b\x80\x6b\xf9\xa8\xd2\x00\x93\xaa\xf2\x30\x1f\xee\x89\x13\xde\x54\xb0\x8d\x19\x32\x04\xa5\x68\x7d\xc8\x4a\x60\x65\x57\xf2\x85\x4b\x85\x41\x3b\x7b\x21\xe3\xb4\xf6\xfe\x2c\x4f\x1f\x95\xad\xdc\x65\x74\xee\xea\x0e\xe1\xa3\xee\x4b\x2c\x8b\x62\x64\xd2\x7e\x6b\xbd\xd7\xae\xe9\xa0\x75\x1b\x85\x61\xf7\x3d\x15\x69\x8e\x75\xa8\xf9\xf7\x1d\x13\x00\x26\x94\xfa\xa1\xd0\xc2\x19\x8e\xe9\xfe\xb1\x0c\xa8\x04\x9f\xb6\x1c\x93\xe8\xa2\xb1\x13\x14\x25\x28\xf4\xc1\x3a\xc3\xc4\xc4\x59\x88\xea\x96\xa8\x9a\x4b\x22\xf7\x2f\xc6\x7a\x5a\x30\x04\x5a\xd7\x2d\x90\x84\xa4\xef\x7c\x52\x60\x09\xda\x9d\xdb\x28\x06\xaa\xad\xd7\xe6\x34\x09\xe3\xc9\x50\xff\x83\xd7\x73\x2e\xd6\x98\x16\x00\x4c\x02\x97\x99\x22\xc2\x71\xf2\x92\x03\x4d\x3b\xfe\x48\x7d\xb3\x8d\xad\x8d\x0c\x70\x49\x31\x87\x94\xdb\x5d\x67\xc7\x96\xec\x79\x24\x2b\xeb\x38\xd8\x7e\x98\xbe\x10\x59\x7f\xb4\x71\xc7\x78\xda\xb4\xfb\x1d\x3d\x10\x9a\xdb\xe3\xac\x42\xc7\x75\x77\xdc\xfb\x28\xb0\x88\xaa\x43\x32\x1c\xb2\x94\x5b\x15\x5e\x41\xa2\x0b\x80\x59\x91\x5a\xbc\xf6\x16\xc6\xd1\x91\x3e\xb7\x65\x97\x63\x94\x7e\xab\xde\xf4\xfd\xc5\xdf\x37\xf5\x4a\xcf\x2f\xee\x3b\x42\xd4\x5b\x05\x03\x93\x3b\xd0\x2a\x78\xd3\x6d\x20\xf2\x06\x42\x7e\xc6\x50\x7a\x6c\x19\xff\xb0\x7a\xc9\x6a\x4e\x98\x44\x1e\x81\x35\x49\x12\x17\xcd\x44\x1b\x66\xd7\x63\xce\xb3\x5f\x6e\x76\x90\x14\xcc\x88\xa3\x75\xf2\x3f\x9e\x43\xbc\x74\xd1\x72\x45\x1e\x84\xe2\x59\x44\x7e\x2d\xd7\xf1\x16\xfb\x78\x84\xb2\x48\xb8\x5c\xb5\xe8\x32\x6d\x52\xa0\xf0\x85\x7e\xd5\xa8\x2e\xcc\x9d\xed\xf1\x3a\xb1\x21\x46\xcf\xd3\x70\x22\x7b\x47\xe3\x3c\x23\x2e\xac\xc7\x02\x7e\xe4\x48\x78\xc6\x09\xbd\x44\x2f\xfe\x44\xc1\x85\xd9\x7f\x2d\xa4\xde\xe6\xd3\xdc\xa1\xd4\x30\x74\xad\x85\x8e\xca\x79\x69\x67\x57\x2e\xe0\x81\x86\x2a\x24\xed\xf4\x04\x49\x8b\xe7\x70\xfa\x91\x61\xe6\x02\x8f\xd2\xe7\x50\x40\x1c\x49\xea\x86\x34\x02\xc0\x02\xe2\x81\x7a\xcc\xbf\x02\xf5\x37\x3f\x5d\x8c\x0a\x25\xc5\xa5\x1e\x63\x87\xe5\x46\x2b\xe7\xee\xe4\xc5\xa3\xc6\xea\xed\x7a\x47\x3c\x55\x13\x9b\x0e\xa5\xbe\xbe\x4a\xf8\x07\x49\x43\x6c\x64\xeb\x13\x32\x05\x93\xc4\x6c\x06\x48\x5a\xe1\x3b\xd8\x46\x25\x60\x6b\x52\xd9\x52\xac\xf9\x98\x97\xbe\x13\x13\xc7\xc8\xc9\x00\xcc\x9c\xe6\x50\x11\x4c\x47\xbd\x94\x8e\xb9\x10\x7b\x25\xcd\xc0\x85\x6e\x86\x7d\x19\xb4\x41\x89\xc5\x93\x9d\x2c\x5e\xbc\x2f\x86\x6c\xa2\xa5\x1a\xbf\x77\x19\xbf\x54\x26\x70\x17\x56\x28\x2d\xa6\xd7\x1b\xbf\xbe\xaf\xc0\xb8\x3c\x7a\x3f\x85\xfa\x7f\xc0\x1c\x21\x78\x83\x8e\x5f\x43\x64\x0f\xe6\xff\x13\x23\x4a\xd8\x04\x38\x05\x15\x81\x9e\xf0\xdb\x02\x17\x7e\xc0\x81\xe3\x46\x1a\x66\x0d\xc5\x27\x0d\x0d\x43\x01\x65\x72\xf7\x09\x6d\x4e\xc9\x36\x0d\x85\xbe\x22\x38\x76\x7b\xec\x9c\x67\xb3\x88\x66\x21\xa7\x96\x03\xd2\xd0\x0a\x12\x3b\xf0\x69\xf3\x2a\x1b\xb4\x54\xea\xd0\x91\x62\x17\x40\xf1\x96\x57\xdb\x8e\x7f\x5b\xef\x61\x03\xcb\x6d\x89\x16\x14\x04\x72\x72\x60\x85\x6a\x2e\x07\x16\x81\xcb\xf4\xb0\x0d\x93\x32\x89\x99\x7c\xa2\x95\x01\x9d\x1e\x23\xba\x89\x02\x54\x30\x6e\x12\x7a\xf6\x3c\x83\xc7\xa7\xda\x02\xb7\x55\xab\x8f\x82\x61\x54\xbc\xd1\x9f\x1f\xd5\x23\xbd\x5f\x12\xd7\xb0\x8c\xde\x61\x18\x04\xcf\xc5\x8a\x55\x70\x42\xff\xc1\x72\xf4\xd9\xc7\xa1\x14\x48\x06\xcc\x1b\xe0\x92\xc1\xab\x48\x06\xe0\xc6\x04\xa0\x6b\x1d\x53\x2d\x6b\x49\x72\x9c\x6a\x9a\x56\x06\x39\xa6\x25\xa4\x2f\x5c\x44\x4e\x5c\xa5\x5e\x33\x63\x7c\x3c\x8a\x70\x73\xa9\xcd\x67\x37\xa8\x3a\x36\x26\x40\x39\xe0\x4e\xf5\xf4\x68\x3c\xa7\x03\xa3\x38\x08\x41\x68\x71\x4d\xe2\x19\x82\x16\xe7\x28\xa2\x69\x98\x58\x8d\xca\xea\x83\x42\x05\x19\xbe\xcb\x3f\x08\x51\x12\xf9\x70\x56\x4c\xcc\x11\xff\xd4\x86\x10\xe7\x23\xdd\xee\x42\x03\xe3\xc4\xf2\x5a\x40\x22\xd3\x68\xf4\x50\xc3\x73\x4b\xe1\x05\xaa\xba\x91\xac\x5c\x1a\x87\x87\x00\xcc\x6a\x8b\xd3\x94\x7c\xd2\x8b\xf6\xb9\xe7\x17\x34\x84\xa5\xca\xdc\xa4\x6d\xc0\x8e\x04\x6a\xab\xce\xee\x3e\x85\x76\x4a\x63\x41\x47\x9a\x26\x07\x79\x0c\x68\x1c\x5b\x52\x98\xa6\x44\x63\xd5\x5d\x5e\x76\x79\xb0\x20\x0c\xac\x33\xe0\x77\xfe\x44\xf2\x3b\x5f\xcc\x60\x27\x5a\x93\xf2\xbc\xcf\xf7\x9b\xff\xa0\x9d\xde\xda\x31\x1f\x7a\xd3\x2e\xc4\xdb\xd0\x70\x8f\x46\x35\xd0\xe6\x90\x53\x9d\xbf\x42\xf9\xbb\x68\x0f\x1f\xa1\x0b\x75\x9a\xdb\x8e\xc7\x23\xda\x95\x51\xcc\xc4\xb4\x0a\x91\x3b\xb4\xab\xe0\x01\x8b\xe7\xa6\xce\x48\x2e\xf2\xac\x9f\x23\x80\x47\x9c\x19\xc7\xbb\xa5\x5d\xd3\xee\x3d\x15\x71\xf3\xa8\xae\xd7\xd8\xc7\x17\x44\xbc\xb4\x07\xd9\x62\x6d\x0a\x74\x7f\xeb\x15\x23\xc5\x3c\x9c\x5d\xe3\x8c\xe8\x4f\x73\x22\x4b\x7c\x97\xeb\x61\x83\xb6\x58\x61\x8e\x93\x0a\xfd\x92\x27\xb0\x6e\x7c\x8e\xf4\xe9\x03\x99\x26\xfa\xf1\xfb\xab\x82\x4b\xae\xcc\x5c\x61\x14\x1f\x15\xda\x54\x2f\xeb\xc4\x7a\x94\x65\x10\x0f\xe4\xae\x57\xf2\x10\x77\x38\xa1\xe9\xd1\x0c\x83\x1d\x14\x96\x11\xcc\x70\x6c\x61\xf8\x6f\x25\xac\xd7\x92\x9d\xd5\x6e\x7f\x0d\xe3\x58\xd6\x7a\xce\xdd\x27\x8d\x6a\xcb\x3d\x58\xbd\x0a\x18\x49\x0d\xf4\xa2\x71\x84\x4a\x4b\xad\x3c\x26\xb1\x67\xd0\x3d\x40\x61\x2b\x7d\xe6\x9c\x63\x1d\x80\x47\x40\xe4\xeb\x54\xe9\xbe\x45\x92\x6b\xdb\xc4\xd5\xfa\x6a\x6c\x88\xf2\x68\x30\x7e\x9d\x70\xaa\x7d\x69\xea\xdf\xfd\x66\x54\xb2\x37\x8b\x6d\xb4\xc4\xbe\x19\xaa\xff\x01\x86\xd9\x6e\x6b\x5c\xf8\x64\xb4\xd8\x65\xe9\xc9\xd6\xaa\x64\x99\x54\x58\xf1\x4f\x1a\x60\x42\x83\xf9\xf5\x67\xdd\x67\xe9\x63\x24\xa7\xd1\x7d\xea\x24\x5b\x3a\x3b\x55\x60\x5f\x6b\x6c\xf0\xdf\x63\xcc\x2c\xa8\xa8\x52\x34\x66\x80\x9c\xb8\x77\x4e\x8b\xa2\xfb\xab\x41\xbb\x8e\x77\x17\xce\x2b\x96\xc8\x68\x0e\x77\xc9\x39\x90\x5d\x87\xba\xb8\x07\xf5\x45\xcd\xfa\x93\x51\x1a\x98\xec\x23\x1a\x54\x59\xaa\x8d\x3c\x26\xc6\x18\xda\x1b\xe7\x2c\xe0\x45\xe0\xa4\x20\x13\x41\x21\xa0\x55\x4a\x73\x5b\x66\xe5\x3f\xf0\xab\x0f\xcd\x57\xb2\x05\xdf\xbf\x8e\xb5\x5c\xf8\x72\xed\x9b\x06\x43\xb2\x4f\x66\x8e\x5e\x1e\x0c\x5c\x25\xf5\xa0\x58\xcf\x56\xe1\xcd\xc2\xd1\x5a\x82\x81\x18\xf2\x48\x17\xb1\xdf\xc6\x8d\x00\x68\xc8\x6c\x71\x3c\x6f\x00\xd3\xe8\x9e\x83\xe0\x98\x56\xa5\xf9\xd4\x7d\xa8\xb5\x34\x23\x92\xb6\xc8\xc3\xd1\x8f\xc9\x11\xcf\xe1\x90\xc6\x4b\x81\xbb\x5b\xd6\xbb\xf3\x9b\x32\x73\x50\xa6\xbe\x0a\xf5\x9b\x28\xc3\xa4\x30\x96\xa4\x68\xa2\x26\xd1\x59\x39\x54\x42\xa1\xb5\xcf\x45\x66\xf2\xec\xab\xf9\xd7\x59\xaf\x8b\xd6\x2d\x23\xd9\xdd\x93\x7e\xe5\x5d\x3b\xa3\x70\xb2\x35\xb8\xe1\x46\xfe\x60\x21\xd9\xa0\x32\xff\xcd\xf1\x65\x41\xff\xd9\xca\xf0\xab\x91\x4c\x01\xfd\x5b\x50\x2e\x76\xf8\xc5\xb1\xde\x1f\xcb\xee\x52\xe7\x34\xed\x53\xb2\x4c\xa4\x6b\x42\xf7\x85\x63\x31\xc4\x56\x97\xa8\xf9\x06\xb0\xd0\xc5\x3d\xc2\x42\xa5\x59\xc9\x5f\xe0\x99\x61\x14\xb6\xbb\x40\xc7\x01\xc8\x0c\x68\x15\x21\x6a\xd3\x9d\x22\x32\xc8\x09\xab\x56\xa4\x6b\xb0\xd8\x5a\xe8\x7c\xe2\xc5\xb6\x5c\x40\xc8\x22\x00\x29\x40\xc0\xd9\x96\x53\x65\xf5\x4c\x46\x67\x24\x50\xb6\xc2\xba\xa7\x69\xba\x3a\x72\xe0\x05\xd5\xab\xe6\x85\x28\x06\x46\xe6\xcb\xd7\x52\xdd\x16\x85\xa4\xb2\x7e\xe3\x0f\xfd\xf9\x12\x3a\xa9\x41\x63\x17\xa0\x8c\x7c\x00\x52\xc6\xbb\x34\xfe\xbd\xb8\x9d\x8b\x0a\xe9\xa7\x25\x3e\x64\xf7\x00\x03\x08\x6c\xdc\xed\x7b\x23\x71\x8c\x51\x17\xe0\x93\x87\xec\x97\xbe\x49\x21\x39\x38\xf9\xe4\x38\x03\xd2\x0f\xcf\x66\xa3\xa0\x21\xaa\xb2\xc7\x6a\xb6\xc3\x03\xcb\x8d\x13\x11\xf9\x4d\x17\xbc\xea\xda\x09\x75\x86\xa2\x3b\x6a\x38\x9e\x5b\xab\x38\xa8\x52\x88\x89\xb5\xdf\xdb\xc7\xbb\x2b\x46\xd8\x5f\xb6\x4c\xe0\x11\xd6\x5e\x4d\xa4\x68\xfc\x05\x87\x1d\x73\x02\x91\x59\xeb\x76\xd6\xbc\xd7\x09\x80\x97\x3f\xa0\x84\x1f\x9e\xbb\x6a\x3a\x22\xae\x26\xa2\x3f\x76\xb0\x8c\xad\x15\xf1\xa1\x13\x62\x8a\x41\x5f\x86\xce\x14\x12\x5c\xe3\x31\x25\x60\xaf\xda\xa7\xd1\xf2\x32\xe6\x1e\x28\x68\x41\x3c\x62\xf1\xeb\x24\x2c\x87\x15\x45\x6a\xb1\x2d\x3a\xb0\x1c\xbf\xa8\xfa\x0b\x00\xeb\x4d\x4e\x25\xd3\xd0\x66\x40\xc8\x88\xa1\x7a\xd4\x72\x1a\xcf\x88\x75\x87\x1c\x91\xe0\x56\xba\x3d\xbf\x08\xc9\xaa\x03\xdd\x25\x49\xaf\x52\xa8\xa6\x89\xea\x8c", 3945);
*(uint64_t*)0x20000018 = 0xf69;
	syscall(__NR_pwritev2, r[0], 0x20000000ul, 2ul, 4, 0, 0ul);
	syscall(__NR_ioctl, r[0], 0x660c, 0);
	return 0;
}