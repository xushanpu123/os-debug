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
memcpy((void*)0x20000180, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20000180ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000040 = 0;
	syscall(__NR_ioctl, r[0], 0x40086602, 0x20000040ul);
*(uint64_t*)0x20001840 = 0x200001c0;
memcpy((void*)0x200001c0, "\x43\x57\x2b\x34\x52\xf4\x68\x96\xae\xb2\x73\xac\xd6\x2f\xd4\xb7\xd1\x9d\x22\x51\xe7\xb2\xe7\x61\x32\x10\xc6\x59\x07\x0f\xaa\xec\x37\xdf\x25\x92\xb5\x5b\xbc\x49\x18\x81\xf9\x3a\x11\xfa\x1b\x1f\xbe\x5b\x91\xcf\x5c\xb2\x1b\xd8\xd2\x3c\x63\x49\xfb\x4e\xbd\xf2\x5d\x10\xcb\x32\xcd\x16\xbf\xc8\x49\xdf\x72\x92\x3a\x22\x55\xc8\x6c\x4e\x5b\x95\x01\xd0\x17\x92\x97\xae\x90\x0d\x7b\x9b\x63\x93\xc0\xbb\x32\x62\xb8\x98\x57\x9f\xf5\xb1\x78\x39\x45\x04\xf6\xe8\x4d\xaf\xcf\x35\x0e\x27\xed\x53\xe7\xa3\x80\x02\xc7\xc4\xfd\xf7\xfd\xc7\x50\xd6\x5e\x5b\xea\x85\x29\x7b\x7c\xa3\x6f\x2e\xcc\xca\xe2\xaf\xaf\xf2\x4e\xa6\x86\x92\x63\x8a\xac\x5b\x25\x38\xd1\xd1\x09\x79\x5d\xab\xd2\xc0\xd9\xff\xa4\x44\xff\x61\xd9\x48\x2c\x57\x55\x5c\xf0\x8d\x93\xb8\x21\x10\xbb\xd8\x83\x4e\x2d\x31\xf2\x0c\x05\x71\x83\x99\x99\x75\xc6\x65\x0b\x28\x3d", 203);
*(uint64_t*)0x20001848 = 0xcb;
*(uint64_t*)0x20001850 = 0x200002c0;
memcpy((void*)0x200002c0, "\x1a\x32\x3b\xb8\xcf\xe2\xc1\xff\xe7\x10\xec\x05\x34\x53\xf1\xfd\x75\x96\x66\xcb\x29\x4d\x7c\x76\x0f\x61\xce\x2b\x18\xb0\x3e\x3b\x38\x51\xf4\x2a\x52\xcd\xd1\xe9\x71\xce\x44\xe7\xfd\xa9\xc7\x4f\x42\x86\x2f\x3b\xf9\xe9\x25\xde\x85\x19\xe2\xd7\x9a\x57\xe4\xc8\xcc\x49\xe2\xb4\xfa\x6f\xfc\x10\x58\x1d\xf0\x39\xb8\xec\xa9\xdb\x23\x3a\xa5\x4d\xe9\x06\x47\x3b\xa2\x83\x90\xbf\x29\xcd\xde\x93\x8f\x85\x24\x44\xdc\x7b\xb0\xd1\x2f\x75\xc3\x02\x8d\x5a\x56\x71\x75\x64\xa4\x3e\x71\x80\x1c\x07\x17\x87\x7d\xd1\x45\x3d\xb9\x73\x52\x5f\x7b\xa7\xa5\x46\x91\xa0\xaf\xa7\x1a\x56\x47\xdc\x5f\x5b\x7e\x25\x4b\xda\xda\x1a\x91\xb0\x40\xf4\x53\x9f\xc5\xfb\xad\x35\x97\x70\x5d\xa1\x81\x7b\x1e\x92\x67\x47\x47\xc2\xeb\x13\xd7\x51\xfa\xf1\xd1\xff\xaa\x1d\xca\x1f\x13\xe2\xf9\xa1\xf5\x3b\xf2\xb9\xf2\xb5\xb2\x85\x6b\xb9\xdf\xf3\xb0\x97\xbc\x25\x96\x73\x11\x82\xa5\x6b\x8b\xf5\xc2\xa7\x09\x62\xd1\xf8\x34\xe0\xed\x91", 222);
*(uint64_t*)0x20001858 = 0xde;
*(uint64_t*)0x20001860 = 0x200003c0;
memcpy((void*)0x200003c0, "\x7e\xf6\x9e\xf5\x40\x78\x97\xc6\x73\xa4\xb9\x87\x4a\x0a\x9c\x30\x4e\xe8\x04\x18\x14\x0f\x11\x6f\x02\xa6\xcb\xdc\x4f\x6e\x27\xaa\x0c\xcf\x1d\x48\xb0\xfa\x99\x75\x4c\xc5\x3c\x33\xb7\x9d\x01\x97\xdc\x8b\x16\xf0\x79\x2f\xef\x39\x42\x04\xcc\x30\x85\x22\xa8\x3a\x48\xb5\xa6\xcf\x49\x82\x94\xc7\x8d\xe7\x29\x42\x07\x87\xad\xa5\x73\xf5\xf6\x44\x8d\x23\xff\x29\xd5\x37\x1c\x33\xda\xdb\x54\x31\x88\xf9\x48\x50\x81\x56\x6d\x48\x4b\x9c\x2b\x38\xb2\x3f\xff\xde\xca\x1f\x01\x75\x35\x02\x1c\xa6\x09\x1e\xed\x93\x00\x11\x52\x37\xe0\xd1\x08\xd8\xb2\xc2\x60\xbf\xb7\x8a\x22\x28\x20\x48\xff\x9b\xf6\x06\x54\x1f\x4e\x49\xb1\xf1\x3d\xee\xbc\x9a\x1b\xd1\x7a\xf4\xef\x64\x06\xdb\x79\x88\xda\x62\x1b\xba\xb3\x38\xd3\x4e\x09\x3e\x95\xb6\xa6\xdc\xf7\x3a\xfa\x36\x5d\x5a\x8e\x03\x1d\x0b\x33\x12\x4f\xc3\x6e\x2b\xc1\xcd\x78\x11\x73\x04\x1a\xf9\xcc\x0b\x57\x22\xcf\x4f\x83\x34\x36\xd6\xda\xdc\x80\xc8\x41\xfd\xfd\x0e\xf2\x70\xb8\x4c\x63\xcf\x06\xd0\xe6\xf7\xe6\x1f\x5c\xeb\xf1\x8a\xb0\xab\x4f\xc5\x7d\xb7\x38\xcf\x9f\xbc\xfa\x77\x2f\xb7\xd0\x96\x67\x4a\x11\xb9\xe7\x8b\xc4\x77\x21\xf4\x69\xa7\xc4\xed\x68\x2d\xf6\x41\x51\x3a\x28\x00\xad\xd9\xd0\x36\xbb\x24\x1c\xf2\xcc\x4f\x00\x84\x7e\xfe\xb7\x39\x27\x3c\xfd\x64\x56\xa6\x27\xce\xa4\x13\x6b\x1e\xa8\xd3\x20\xf4\xa7\x0b\xe4\x1f\x9f\xc7\x41\xdf\xa3\xe5\x69\xcc\x7a\x8b\x3a\x09\x3e\x1f\xb5\x81\x9d\xcd\xb0\x27\x56\xbe\xf3\x79\x44\xc2\x13\x52\xa2\x0a\x5b\x93\x6c\xd1\xe6\x8a\x1b\x4f\xb3\x05\xfb\xcf\xe5\x83\xd8\x46\x44\x10\xe4\xae\xba\x6a\x61\x0c\xce\x61\x36\xfa\x7d\xe1\xe9\xf7\x1d\xd2\x54\x74\xda\xd2\xb2\x91\x5a\x32\x19\x82\xee\xe3\x37\x34\xea\x2d\x93\x0f\x52\x41\x84\xfe\x87\xe9\x9e\xab\xfb\x56\x55\x28\xd1\xc2\x8e\xe2\xa3\xd3\x66\x5c\x80\x50\x8f\x20\x59\x22\xf1\x38\xba\x80\x35\x25\xec\x66\x61\x6a\x14\x00\x24\x2a\x5d\xf0\x01\x57\x0d\xf3\x45\xf2\x55\x0b\x1d\x9b\x1a\x52\x20\x49\xb1\x16\xd9\x07\x93\x17\x27\x97\x12\x7a\xac\xf9\x2e\x6e\xb8\x9d\xac\x74\x73\xfd\x70\xfb\xa1\x32\x2e\xe8\xd8\x60\x9a\xdd\x47\x13\x2b\xff\xe5\x07\x06\x50\xa0\x83\x56\x9b\x54\x6e\x83\x57\x15\xf7\xbd\xe3\xec\x0d\xe8\x6d\x75\xb7\x64\x99\xa4\x65\xdd\x0f\x27\xf7\x6a\xc4\x49\xd9\x7f\x46\xd6\x50\xbe\x0b\x17\x2c\x14\x8c\x96\xeb\x93\x02\x1d\x74\xb8\x15\x48\x08\x6c\xbf\x9a\x9e\xc4\x67\x9f\xf3\xbb\xa4\x1e\x40\x40\x17\x7e\x7e\x10\x30\xc9\x1d\x49\xf2\x56\x7e\xa8\xd5\x04\x46\x4f\xe0\x5d\xf8\x9b\x62\xc1\x5d\x05\x21\xd1\x2e\x3f\xd9\xd3\x9b\xbc\x7b\xdc\xc4\x5e\xb4\xf1\x25\x8b\xd4\x57\x70\x4e\xe2\x13\xa0\xf1\xae\xb5\x7e\xba\x42\xbb\x04\x4e\x71\x70\xe2\xb7\x54\xcb\x39\xd0\xcf\x37\x25\x58\x30\x95\xb8\x80\x01\xee\xff\xe8\xfa\x93\xe9\xb5\x47\xb6\xb0\x8b\x09\xd8\x88\xb7\xda\x30\x53\x43\x2d\xdc\x83\x6d\x69\x98\x90\xa7\x91\x70\xb3\x29\x36\xbd\x30\x72\x68\x13\x26\x6e\x2d\x31\x60\x3f\xd8\x63\x2d\x38\xcf\x9e\x45\x7a\x44\xd9\xe9\xf0\x5f\xa9\xb7\x25\xaa\x5a\x14\x01\xf4\x46\x86\x64\xe6\x45\xf1\x61\x90\xb7\x52\x59\xc7\x42\xb6\x9b\x9d\xfa\x6c\x7a\xdf\x46\x6e\xa0\x59\x90\x70\x2a\x08\x4a\x1d\x7a\xe4\x71\x21\xbf\xe6\x19\xf6\xae\x9c\x36\x15\x2a\x12\x8c\xff\x31\x0e\x3f\xc1\x75\x5f\x36\xd3\xbc\x27\x86\xc4\x5b\x4f\x30\xd8\xfb\x90\xe4\x9b\x33\x79\x48\x96\xf9\x43\x3f\x5c\x1d\x71\x6d\xce\x63\x73\xbb\x1c\xd2\x36\x6b\xc6\x70\x03\x28\x28\xef\x37\xe8\xae\xa3\x72\xc6\xce\xd4\x62\xfe\x43\x10\xdc\xa1\x65\x53\xdc\x17\x4b\x3f\x64\x4f\x05\x17\x55\xd0\x95\x86\x2b\x1a\x62\x02\x39\xca\xf2\xc0\x94\xb6\x23\x28\xf1\x7b\xf9\x1c\xc1\xe0\xbf\x7b\x0d\x3e\xbc\x8e\x02\x3f\xb9\x4e\xaf\xa5\xea\x3e\x36\xff\xb9\xe4\x8d\xec\x71\x09\x55\xe7\x4e\xe6\x77\xa9\x72\x57\xb7\xf2\x0c\x7c\x2e\x4a\x59\x70\x9d\x8e\x3f\xfb\x13\x5a\x34\x95\x5a\x55\x7a\x6c\x23\x6f\xb2\x46\xa0\xab\x98\xe2\x65\x2d\x9b\x70\x8c\xf4\x54\x18\x25\x7f\x96\x3c\xfe\x00\xa5\x39\x10\x36\x90\x4e\x0c\xed\xde\x7f\x2f\x1d\x44\xa7\x60\xae\x50\x47\xea\x39\xc0\xa2\x0c\x30\xd9\x70\x4a\x77\xd9\x7f\xa3\xc2\xf8\x3a\xb1\x88\xc9\xa7\x0b\xfa\xe1\x87\x96\x96\x57\xa6\x7c\x91\xb2\x97\x1c\x4f\x35\x7c\x5d\x30\x8f\x42\x40\xf9\x0d\x1a\xfc\xc4\x2b\x09\x3c\x2d\x8a\x01\x46\x3e\x72\xbd\xba\xd3\x10\x18\xd1\x97\x77\x4e\x64\xd7\x63\x41\xf4\xcd\x6a\x43\xdc\x99\xa4\x4f\x94\x67\x60\x05\xf6\x1b\x04\x23\x42\xab\x89\x56\xaf\x10\x14\xe8\xcf\xba\x3b\x17\xcb\x87\x08\x96\x4b\x0a\x29\x98\xc2\xab\xb1\x28\x8b\xb1\x3d\xbd\x24\xb2\x03\x17\x2f\x69\x2c\xc3\x7f\xdc\x81\xcf\x88\x9d\x18\x0c\xd3\x8e\x79\xb9\xb6\xf5\x7d\x34\x0c\xd3\x02\x00\xc4\xbc\x77\xe5\xae\x69\x91\x5b\x37\x74\xb3\xe0\xff\xd5\x45\xb9\xf7\x01\xfc\x79\x8a\x52\x40\x91\x28\x5e\x48\x4a\xdb\x99\x65\xcf\x07\xa7\xe1\x22\x0d\xf9\x81\x4a\xbc\x44\x36\x5a\xcf\x7c\xc1\x14\xa4\xf9\xfd\x9d\x3a\xbd\x8e\x58\xb3\xed\x64\x53\x89\xf2\xc9\x81\x30\x4d\x52\x12\x2f\x50\x28\xb9\x2e\x07\xb0\x17\x94\x5b\x5f\xe5\x07\x89\x22\x42\x18\x88\x13\x49\xde\x63\xc2\x39\x07\xc1\x34\x19\xe5\x94\x67\x3d\x01\xa5\x6e\xb3\xee\x0a\x04\x84\xe2\x43\xc9\x89\x93\x7d\xa9\x7b\x3d\x56\x86\x71\xac\x05\x88\x40\x40\x8c\x22\x65\x78\x8e\xed\x2a\x1b\x86\xf6\x3b\x7f\xd1\x8f\x8d\x61\x6f\x03\xae\xd7\x13\x11\xdb\x4d\x52\x7a\x78\x5d\x8a\xb5\x23\x43\x9b\xe5\xc9\x17\x5f\x48\x06\x63\x56\x1f\x04\xb4\x82\x89\xbf\xd8\xf8\x79\x0f\x08\xfc\xac\x25\x9d\x26\xe3\xd1\xb8\xf7\xc9\x7b\x96\x43\x8b\xeb\x49\x25\xda\xa5\x2a\xe7\x44\xcd\xd9\x84\x74\xfb\xb3\x90\xc3\xdb\x0d\xc4\xd9\xc8\x19\x1c\x89\x31\x55\xa2\xeb\x61\xba\xdc\x49\xe3\x87\x14\x34\x80\xf0\xb4\x78\x67\x3f\x03\x2f\xd3\xf3\xd6\xad\xa5\x6e\x11\x15\x24\x03\x15\x13\x94\xcf\x81\xc2\xf3\x05\x36\x78\x1e\xc9\xf5\x18\xf8\x53\x42\x2e\xd2\x49\x26\x20\x85\x7e\x29\x4d\xe7\x72\xe6\x7c\x5e\xfe\xa5\x18\x2e\x91\x4d\x9e\xc6\x6d\xff\x07\x54\xf9\xb8\x77\x5b\xb0\x5e\x0f\x68\x18\xed\xb9\x98\x7b\xb3\x95\xf5\xb4\xa3\xda\x5b\x6b\xa4\xf3\xc5\x89\x19\x62\xa8\xc7\x9e\xe0\x35\xcf\xc1\xcc\x34\x09\x00\x2d\x91\x80\xdc\xdd\x9c\x3c\x37\x96\x3c\x47\xff\x22\xb4\x11\x73\x60\x05\x5a\x93\x5b\x8c\x2e\xdf\x9a\xc3\x35\x0c\xa0\x78\x12\xae\x0e\x3e\x64\x40\x66\xfb\x04\xf9\x81\xc8\xcf\x08\xbc\x59\xb9\xfb\xc2\x2f\x93\xad\x85\x12\xc3\x9e\xd1\xcb\xc8\x4c\xcb\x58\x21\x28\x94\xbc\x70\x66\xe9\x16\x2d\xb2\x95\x78\x4c\xc7\x75\x65\xd3\x8d\xdd\xad\x2e\x8b\x4e\xbe\xd8\xba\xdf\xa0\x3d\x16\x0f\x24\x36\x81\xe7\xd4\xcd\xd7\xf6\xd8\x93\xf5\xe1\x85\x74\xaf\x42\xad\x33\xff\xc6\xab\xf8\x08\x9a\xaf\x3f\x6e\x35\x78\x10\xae\x35\xbc\x5c\x2e\x74\xef\xbe\x96\x76\xf9\x98\xda\xeb\xeb\x99\x9a\x6d\xc5\xde\xeb\x8a\x50\xfe\xb2\xf4\xbf\x73\x8d\x10\x66\x9d\x06\xff\x8a\x50\xe3\xc4\x95\x2b\x37\x2a\x82\xf7\x12\x83\xc6\x75\x39\xac\x51\xcf\x25\x31\xd5\x98\xce\x46\x70\xcd\x01\xf0\xaa\x69\x9a\x1b\x52\x51\x8d\x17\x5a\xd3\x41\x3e\x7d\xc7\x15\x4e\x4a\xb5\x41\x44\x7d\xcf\xb7\x83\x23\xa0\xb4\x69\xfd\x1f\x23\x79\xe1\x4e\xd2\xec\x72\x79\x02\xc8\x5a\xd9\x1a\xa4\x4e\xd7\x81\xe7\xd7\x0e\x35\xd0\x42\xe3\xb8\xf4\x5b\x73\x42\x86\x7b\x44\x2c\xdb\x21\xa7\xf1\x60\xff\x0d\x6e\xbb\x22\x2f\xb5\xdc\xe1\x84\x48\x6d\x68\xd3\xe8\xcd\xa0\xc3\x82\xba\xe3\x87\xfe\x10\xea\x6f\x3e\x38\x5a\xf9\xbf\xe4\xd1\x1d\xa3\xcf\x98\x79\x0e\x74\x5b\x62\x74\x99\x92\xc4\x31\x85\x2b\xca\x53\x40\x37\x9d\xac\x8b\x41\x95\x69\xc9\x89\x70\xb1\x2a\xca\x52\x3a\x45\x7f\x74\xc9\x07\x55\x8f\x85\xb2\x76\xc4\xc5\xea\x05\x15\xaf\x81\x48\xaa\xd5\xb9\x73\x08\xf7\x33\xc6\xc6\x9e\xda\xa5\xb6\xfb\x46\x0b\xb5\xde\xa2\xe2\x19\x37\xa0\xe6\x2a\x60\x59\x28\xac\x49\xcb\xc6\x38\x8f\x11\xfd\x99\xc8\x0f\xc6\x1a\xdb\xed\x44\x53\xa2\xb2\xb4\xb6\xfd\x8d\x7d\xf2\x08\xf8\xc9\xf5\xb9\x29\x72\x13\xe2\x9f\x20\xf5\x47\xd7\xb7\x85\xbb\x40\x63\x7a\x86\xc4\x88\x4b\xd4\x26\x09\x22\x8d\x40\x56\x2e\x76\x3c\xe7\x7a\xae\xe1\x4c\xdc\xca\x5b\x21\x1f\xe0\x5a\x6d\x1d\xdd\xdb\x9a\x25\xbe\x3f\x10\xa7\xef\x2a\xe5\x58\x22\x8e\x1e\x69\x46\x10\xf8\xa6\x16\xc0\xb9\x78\x35\x5f\xd0\x51\x9d\xbc\xd4\xc1\x52\x00\x98\x6f\x90\xe6\x6e\x64\x13\x84\x5d\xa7\x14\xaf\x1d\x8e\xe2\xfe\x86\xa6\x28\x9b\x06\x8f\x02\x34\x1e\xfc\xc5\x7c\x5f\x2a\x21\x65\x6e\xec\x43\xb5\xc1\xf6\x5c\x20\x34\x5e\xa3\x16\x79\x52\xf1\xd2\x4a\x33\xbc\x15\x64\x15\x21\x03\x8b\xa4\xf1\xa9\xe1\x18\xfd\x67\x36\x5e\xeb\xe0\x21\xe2\xf2\x55\x04\x0a\xa7\x84\x8e\x14\xbd\x26\xaa\x41\x75\x1d\xe3\x76\x35\xd1\x60\xe5\x18\xd4\xe1\x5a\x6a\xc9\x93\x4b\x3c\x8d\x36\x8a\xda\xbb\x58\x25\x56\x45\x06\xf4\x2a\x5f\x7d\x2c\x4b\x0c\x95\x6e\x45\x00\xcf\x99\xd6\x72\xcf\xf4\x6f\xba\x82\x37\x91\xfa\xf3\x06\x43\x41\x01\x24\x87\x71\xf5\xaa\x9e\x33\x7b\xc6\xe8\x52\xeb\x18\x17\x00\xa0\x9f\x10\x6b\xd1\xc2\xb4\xfa\xd6\xf3\xca\xd8\x6b\xd7\xbb\x88\x2f\x06\x9e\x8b\x15\xf7\x1b\x91\xdf\xcf\xd6\x34\xa6\x3f\x16\xd1\x45\x62\x3c\x10\x51\x1b\xc4\xd4\xc0\x15\xc0\x11\x4b\x9b\xa8\x9f\x10\x87\xdf\x5d\x04\x69\x1b\x34\x8c\x2b\xef\xec\x98\x15\x29\x82\x54\x94\x70\x4b\x18\x11\x0e\x17\x79\xfe\x8a\xd3\x18\xcd\xc4\x9f\x29\xf9\x16\xb8\xee\x63\xfe\x63\x50\x4a\x68\x6c\x73\x0f\x6d\x9b\x23\xee\xf3\xd1\xce\x8d\x9f\xbf\x21\xa6\xdb\xd3\x1d\xe7\xed\x25\x1e\x66\xc8\x96\x55\xaf\xac\x3d\x9a\x32\xdd\x55\xc4\x5a\xee\x64\x82\x0f\x9c\xd4\x23\xaa\x9e\x49\x9c\x8c\xa5\xb3\xec\xe9\x54\x98\x5f\x55\x27\x47\x74\x71\xad\xe7\xda\xa8\x98\x94\x85\xe6\x27\x31\xb8\x03\xa4\x14\xe3\x7a\x42\x9b\x3c\xe5\x4f\x0f\x67\xf2\x2c\x7b\xd6\xcc\xe2\x6f\x70\xf7\x67\x47\x1c\x78\xa2\x68\xaf\xd8\x66\x15\xf5\xb8\x74\xa5\xa3\xb1\x8d\x9f\x75\x7d\x2d\xe8\x96\xe6\x3f\x90\xab\x7b\x8a\x66\xac\x62\x41\x41\xd7\xc8\x1b\x7e\x70\xee\x7f\x35\x2f\x9b\xab\xd2\x89\x33\xd0\x4c\x06\x6e\x8d\x4b\x1a\x04\x2a\x68\x2f\x85\x75\xb8\xf7\x18\x61\xd8\x8d\x6a\x05\x31\xbd\x75\xc0\x26\xc8\x00\x34\x72\xe1\x34\xe2\xf9\x2c\x3a\xaa\xb9\x70\x8e\xe7\xaf\x7a\xaf\x13\x6b\xce\x46\x5b\x46\xbf\x08\x78\xf6\xa3\xbe\x17\xf3\x25\xdc\x92\xdf\x20\x7f\xc0\xa4\x01\x90\xfa\xa0\x87\xe1\x85\x96\x46\x0f\x6a\x91\x9f\xd6\xce\x3a\x99\x86\xff\xc6\x26\xfb\x1c\xf0\x49\xe6\x40\x52\x65\xfb\x9c\xe2\xfa\x2b\x05\x95\xa2\x94\x5c\x34\x37\x33\x37\x53\x64\x50\xb2\xf5\x41\xd9\x58\xb2\x7f\x61\x99\x8a\xd8\xb8\x0a\x14\x52\xb6\x72\xc5\x7d\x2b\x37\xac\xc0\x15\xc1\x22\x51\x20\x7b\x70\xc3\xd7\x85\x68\xb4\xda\xd0\x4e\xe7\x00\x87\x0e\x1a\x65\x3d\x7f\x1b\x11\xef\x10\xb7\x21\xf7\x65\xa1\x99\x80\xf7\x86\x0f\x50\xf3\x03\x99\xe7\x86\xc4\x4a\x6e\xf2\x90\xb7\x45\x76\xb8\x40\xb0\x94\x64\x51\x4c\x47\x0d\x99\xe7\xa9\x3b\x74\x11\x0d\x8a\xda\x91\xc3\x7e\x2a\x8b\x3b\x42\x52\xa6\x08\x88\x9c\x51\xfc\xcd\x73\x89\xb7\x30\xc3\xf8\xff\xb6\xad\x5e\x11\xcd\xc2\x5d\xc3\xbd\x0a\x68\x91\x33\x86\xb0\x14\x46\x9e\x18\x34\x78\x99\x1a\x5d\x8d\x70\xf8\xe9\x90\xcd\xc8\xb0\x2d\x1a\x7d\xdc\x75\xcc\x0f\xb3\x94\xd2\xb1\x25\x25\x7a\x05\x1b\x7f\xc3\x84\xf2\x60\x3b\x07\xb5\x0c\x21\x2f\x57\xd0\xf4\x7f\x98\x37\x79\x4a\x26\x13\xaf\xca\xc5\x31\x70\x84\xc3\x86\x9e\x5b\x8d\x3a\xa2\x58\x8d\x30\xa6\x60\x48\x95\x92\x83\xf4\xc5\x38\x0f\xee\x92\xfb\x95\xae\x80\x7d\x7a\x70\x18\x7b\x21\x99\xd4\x4b\xde\x3e\xd1\x4d\x9d\x90\x0f\xcd\xe2\x54\x2f\x1c\x81\x39\x86\x0f\x91\x50\x72\x2a\x80\xf3\xcc\x6a\x3c\x1e\x15\xd1\x57\x36\xfd\x04\x2e\x17\xa8\xe3\x7e\xf0\xae\xb9\x95\xfd\xd3\x47\x9f\x09\x15\x19\x4b\x88\xe8\x0c\xb1\xc3\x8a\x3b\xe9\xc8\x91\x76\x44\x20\x0b\x6d\x47\x51\x94\x54\x60\xde\xeb\xd6\xe7\x06\x84\x8d\x31\xcc\x8c\x88\xab\x45\x7e\x75\xec\x1c\xe9\x90\x9f\x97\x95\xfa\xc2\x42\xe8\x37\x46\x7c\x3b\xa7\x0d\x90\x7b\xca\x1c\xd5\x8c\xf7\x5b\x69\x05\x11\xb0\x60\x85\x4e\x1e\x86\xbf\x54\x56\x6e\x6f\xce\xf8\x9e\xf8\x63\xb4\x9c\x91\x76\x06\x5b\xb8\xa8\x10\x34\xfb\x7d\xac\x60\x50\x1d\xe9\xac\xe2\x1d\x26\xc3\xef\x75\xc2\x6f\x63\x95\x09\xdf\x67\xdd\x00\x92\x32\x94\x03\x23\x6b\xbc\x27\xdf\xd3\x59\xde\x8b\x3c\xd2\xd0\x4c\xa0\xec\x51\x04\x1d\xcc\x31\x79\xb2\xb4\xb8\x6c\x5a\x3d\xb5\xa2\x58\xc6\xae\x03\xc3\x9d\xfe\xc7\xb6\x38\xe7\x94\x9f\x68\x16\x41\x01\xce\xd2\xec\xe4\x8d\xb7\xde\x82\xef\x91\x9f\x4f\x37\x3b\x9c\x10\xd9\xe2\xfa\xff\x79\xc4\xc0\x7d\xa5\x15\x28\x75\x14\x3e\xd1\x0a\x68\x8a\xef\x73\x6f\x36\x0b\xc4\x20\xf9\x30\x57\x07\x79\xe7\xb7\xae\x7a\x06\x9d\xff\xb3\xa9\x0b\xc4\x4e\xaa\xcc\xa4\x97\xe5\xac\x5f\x98\xb7\x94\x3a\x36\x11\xda\xa5\xd5\x78\x51\xe7\xe8\x1e\xbb\x77\x5b\x3e\x68\x8d\x90\x05\x1e\x4a\x43\x39\x6b\xdf\xfd\x5b\x52\x53\x9d\xee\x7f\x96\x69\x0f\xac\xe7\xb3\x6d\x4f\x71\x5f\x0b\x91\x61\x02\x55\x82\xa1\x2e\x0e\xa4\x24\x56\x64\x9f\xcb\x12\x49\xe2\x8e\xf5\xe8\xbf\x70\x6d\x2d\x16\xee\x1f\xd0\xa3\x5a\xc2\x44\xcc\x7e\x3c\x13\x17\x05\x80\xe9\x7d\xd6\x4c\x28\x3d\x84\x1a\x41\xa8\x41\x3c\xaf\x24\xd7\xff\x53\x09\xc3\x4b\xbf\xb9\xb7\x07\xf1\x3a\xdd\x01\x9d\xe7\x58\xdf\x2f\x27\x79\xe2\x4b\x55\x6b\x28\x31\xc8\xc8\x22\xc6\x71\x79\xca\x61\x55\x77\xee\x70\x37\xd5\x86\x9e\x87\xb3\x6b\x0d\xc3\x76\x84\xdc\xd5\xa1\x14\x25\xf0\x56\xee\xb8\xb3\x2a\xf9\xa4\xbd\xec\xb4\xae\xef\x23\x4d\xe1\x25\x24\x59\x94\x97\x0e\xde\xe1\xbc\x62\x42\xe9\xba\x62\x49\x1d\xbd\xa7\x85\xc2\x3c\x40\x6f\xea\x77\xd5\xaa\x88\xa2\x48\xfb\x65\xbf\x2b\xa3\x58\x94\xa7\xd7\x5a\x89\x36\x8a\x84\x51\x0b\xa7\xc1\x63\x47\x37\xf2\x49\x6e\xea\xaf\xbc\x5c\x3d\x82\xca\xe6\x37\x49\xaf\x25\x28\x84\x6f\x23\x9c\x03\x88\x8d\xcc\xc4\x7c\xbc\x09\x89\xfd\x1f\xb8\xa6\x02\x34\x8a\xef\xd2\xac\xb3\x47\x7b\xbc\xe9\x73\x25\xd2\xbf\x17\xa8\x31\x51\xf8\xf2\x9c\xf0\x42\x33\x09\xfc\xa5\x6d\xd1\x80\x1f\x98\x06\x9e\x6e\xed\x33\x52\xc2\x75\xa3\x0d\xca\xd8\xc7\x6d\x38\xfe\xab\xe1\xcd\x95\xdf\xde\xff\xa2\x30\xdc\x79\xa5\x5f\x60\xf2\x06\x26\x10\x83\xd3\xfc\x12\x47\x8a\xc6\xbd\x2b\xb0\x7d\x09\xe3\x96\x7f\x1e\x04\xb6\xa1\xc5\x9c\x4a\x97\x28\xa5\xe0\x34\xab\x34\x6e\x4d\x71\x08\x7d\x54\x23\x96\xba\xd5\x0d\x4a\x2d\x6c\x9c\xc2\x25\x26\x32\xea\x69\xb9\xd5\xd2\x9b\xa8\xcc\x61\xd8\x04\x40\xf0\xfd\xec\xa1\x8b\xd9\xd1\x21\x71\xa5\x6b\x99\xed\xb8\x9c\xbc\xbd\x86\x29\xa7\x0e\x9d\x59\x80\x4f\xee\x86\x44\x7a\xf8\xe2\x1b\x05\x14\x73\xcf\x54\x9d\x63\x0e\x1a\xd6\x98\xe3\xfc\x5d\x37\xd3\x2a\x60\xc0\xba\x75\x6f\xd9\xc2\x40\xa5\x4a\x8c\x52\xf3\xd5\x84\xdf\xe2\xb5\x95\x9e\x36\x12\xd0\xb2\xb8\xb2\x01\x41\x80\x72\x43\x16\x38\x42\x9c\x27\x93\x88\x0a\xa5\x06\x4e\xa8\x4c\x83\xa8\xd8\x86\x76\xba\x6b\xc6\xd0\x4b\xa6\xee\x19\x5b\xea\x0e\x9f\x64\xd9\x69\x86\x4d\x92\x55\x6c\xe4\x3c\x10\xdb\xa8\x71\x74\x1c\x7f\x71\xc9\x70\xc1\x27\xba\xcf\xba\x07\x7f\x78\x34\x28\x63\xc7\xb2\xc2\x11\x6c\xb1\x38\x4e\x8c\xd1\x74\x6a\x80\x63\x51\x89\xdb\x3c\x13\xc0\xe6\x7b\x1d\x36\x86\xaa\x7a\x72\x32\xc4\xa9\x4c\xdd\xa8\x6d\x91\xf8\x7a\x00\x9d\xe8\xb2\xf3\xcf\x67\x8b\xcb\x82\xde\x16\x98\x77\xa1\x89\x9a\x54\x3d\xcc\xeb\xa3\x1f\x9b\x60\x33\x80\x1f\x46\x17\xa0\x81\x2c\xad\x82\x86\xa5\x1d\x0b\xd9\x71\x89\xcf\x47\x62\xb6\x43\x2e\x36\xb3\x3f\xec\xb3\x9f\x41\x1f\x10\x7a\x8d\xc9\x53\x66\xac\xc9\x8b\xda\x95\x0e\x59\x42\xe0\xfe\x0e\x79\x29\x2b\xc8\xef\x16\xc2\x15\xb1\x80\xd3\xc9\x81\xba\x4e\x15\x1c\xd2\x38\x0f\xd1\x51\x00\x41\x23\x2d\x07\xe0\xc5\x95\xfc\xcf\x39\xb9\xcb\xe6\x9f\x4b\x7b\x11\x66\x7f\x0a\x86\x97\x3d\x0e\x57\xe7\xd5\xba\x26\xe7\x84\x50\x86\xe7\x5a\x1e\x4c\x8c\xf0\x23", 3544);
*(uint64_t*)0x20001868 = 0xdd8;
	syscall(__NR_pwritev2, r[0], 0x20001840ul, 3ul, 0x80, 0, 0ul);
memcpy((void*)0x20000140, "./file0\000", 8);
	syscall(__NR_truncate, 0x20000140ul, 0x80ul);
	return 0;
}