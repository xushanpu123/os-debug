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
	res = syscall(__NR_socketpair, 1ul, 2ul, 0, 0x20000100ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000100;
*(uint64_t*)0x200000c0 = 0;
*(uint32_t*)0x200000c8 = 0x2a;
*(uint64_t*)0x200000d0 = 0x20002280;
*(uint64_t*)0x20002280 = 0x20000000;
memcpy((void*)0x20000000, "\x36\xe2\x8e\xc3\x39\x80\x2b\x47\xf4\xda\xc8\xa5\x37\x09\xe9\x32\xc4\x29\x99\x28\x20\x3f\xda\x86\x68\x30\x91\x90\xe5\x02\x6d\xa4\x63\x5b\xdb\x9b\x60\xa8\x04\x40\xfe\x8a\xb7\x3f\x48\xc7\x2a\xd4\x9e\x36\x1e\x03\xfc\x44\x61\x61\xc1\xa9\x4e\x3c\xde\x20\x72\xa3\xf6\x11\xe1\x87\x19\xce\x44\x4d\x10\x33\x3d\x2c\x3a\xf7\x9d\x56\x5f\x85\x21\xf9\x31\xe7\x14\x7a\xa8\x42\xc2\x7a\x08\x85\xb9\x52\x8f\xd2\x53\x2b\xfe\x13\x89\x39\xf1\x10\x3b\x11\x1b\x20\x96\x23\x81\xe7\x37\x19\x0d\x19\xa4\x0e\x17\x6a\x11\x22\x87\x6b\xee", 127);
*(uint64_t*)0x20002288 = 0x7f;
*(uint64_t*)0x20002290 = 0x20000180;
memcpy((void*)0x20000180, "\x85\xd4\xf3\x6a\xe5\x00\x12\xcb\x07\x25\xdf\xed\x49\xd4\x9b\xbe\x73\x5b\xb0\x7e\x72\x97\x9b\x88\x4c\x68\x2b\xab\x25\x5c\x23\x55\x86\x8f\xe3\x7b\xd6\x1d\xa9\x47\x62\x3c\xa8\x72\x61\xbf\x63\x9f\xdd\x52\x85\x53\x82\x14\x14\x31\x87\x03\x11\x17\x1f\x3f\xa2\xb9\x28\x61\x07\x55\x7f\x73\x50\x61\x8c\x03\x84\x08\xa9\xae\xc1\xf2\xb8\xb6\xb0\x64\xef\xc6\x9c\x33\xa9\xdb\x05\x26\xb4\x41\x81\x90\x94\x47\x67\x39\x0f\x1c\xdb\x68\x6e\x8e\x8a\x22\x7d\xaa\x11\x01\xb5\x03\x38\x09\x57\x1b\xbc\x3b\xde\x7d\x6e\xa7\x1e\xec\x3a\xbf\x61\x7e\x5c\x0f\xa4\x85\x5e\xcb\x06\xf3\x0c\xc0\xac\xd4\x9d\xd6\xfd\xad\xe9\x69\x73\x02\x9c\xf9\x30\x2d\xec\x14\xee\x8b\x86\x59\x45\x98\x95\x54\x37\x8a\x5e\xf7\x33\xe6\xc8\xe9\xf7\xa1\x1b\x8c\xb9\x9c\xe1\xdb\x5d\x8f\x81\xf3\xfb\x14\xc5\x9d\xee\x76\x19\x3e\x63\xca\x01\x95\x52\xfc\x54\x2d\xea\xd1\x6b\x3b\x6b\xc9\x98\x59\x1d\x2d\x4a\x3d\x5e\xbd\x50\xce\xc8\x69\xf0\xe6\x40\x47\x5a\x74\x10\x00\xbc\x39\x9f\x9f\xba\x8d\x01\xa8\x61\xa2\x42\x72\x83\x25\x53\x21\x35\x5c\xc4\xea\x77\xf7\x7a\xef\xf8\x1b\x50\x16\x9d\xa2\x52\x6e\x7c\x8b\x42\x04\xee\xed\x90\x8c\xa8\x1c\x23\xd5\x52\x20\x94\xbf\x1a\x17\x25\xb2\xba\x4d\xdc\x66\x83\x31\xd9\x39\x4e\xd9\x30\xc0\x77\xbb\xbe\x3e\x98\xb2\x07\x7e\xf6\x5d\x78\xd3\xd3\x66\x02\xc9\xff\x1e\x82\x14\xea\x7d\xc3\x37\x48\x3f\xdb\x20\xa4\xf2\xbc\xd3\xc0\xb4\x1c\x97\x64\xb7\x72\xe7\x88\x39\x92\xa6\xb8\x9a\xa9\xd6\x87\x20\x9f\xfc\x9f\xdc\xc9\xf9\xcd\x29\x9f\xcc\x4d\xd3\xd8\x03\x64\x9c\x35\xc1\x85\x0f\x0f\xf3\xb6\x7a\x81\x61\xaf\x30\x82\x1e\x12\xa6\x7d\x55\xbc\x3f\x7a\x9a\x44\x15\x8f\xf8\x43\x5d\xff\xdc\x7a\x23\x67\x78\x6e\x1c\x99\x9d\x2b\x5e\x66\x69\x59\xa3\x60\xa8\x70\x8c\x79\x95\x51\xd6\x33\x3f\x2a\x0d\x51\x61\xad\x1a\x72\xaf\x5e\x01\xb2\x63\x82\xa2\x3a\x39\x1b\x81\x81\xa9\x70\x81\xaa\xce\xeb\xc3\x30\xf3\xa6\xd6\xfb\x89\xec\x53\xf2\x23\xe8\x84\xa4\x36\xa4\x07\xbe\xf3\x93\x1d\x41\xd1\x9f\x55\xfa\x45\xcb\xc4\x4c\xe8\x41\x06\x72\x18\x52\x8c\x6e\x60\x4a\xe3\xbb\xa1\xab\x26\x1d\x57\xae\x76\x85\x52\x97\x18\x73\xff\x73\xda\x18\x04\x71\xf4\x9c\x30\x3f\x97\xc0\x07\xd0\x4b\x1e\xe6\xaa\xcf\x47\xa5\xcd\x5f\xc1\xb3\xca\x39\x9c\xc2\x75\x2f\x36\xc2\xb7\x22\xf0\xee\x4c\xbb\xa6\x4e\xb3\xde\xec\x03\xad\x3d\x29\x6e\xad\x1b\xc0\x1a\xe7\x34\xa8\xad\x8d\x5f\x65\x36\xe5\xf8\x79\x17\x5d\x20\x87\x39\xbf\x70\xd2\x61\xa8\x8c\x35\x66\x80\x5b\x2d\x10\x03\xb0\xb0\x08\xa6\x27\x91\x00\xdc\x89\x57\x73\x25\x25\x8e\xde\x58\xde\x62\x5c\x08\xdb\x0c\xc9\xed\x64\xc3\x34\x02\x76\xda\xf9\x53\x77\xda\x21\xe4\x3e\x6e\x9c\x40\x6d\x21\xb1\xc8\xa7\x02\xa8\xe6\x16\xfe\x3b\x8b\xc1\x2e\x89\x82\xd6\x34\xd0\x4a\xd2\x77\x3b\x9f\xdc\xd7\xa4\xb7\x35\xc0\x66\x99\xe8\xc4\x27\x9c\x1f\x7b\x22\x0d\xa5\xd4\xf2\x98\x20\xaf\x85\x2f\xfc\x38\x7b\xa9\xf5\x1f\xab\xb5\x4a\x9d\x09\x23\x81\x04\x68\xfd\xef\xff\xc9\xf6\xde\xd9\xb7\x47\xd3\xbb\x12\x54\x66\xd1\x23\x13\x4d\xc8\x4e\x96\x2b\x7e\x3f\x60\xcf\xc2\x02\x3a\x05\xc9\x11\x07\xfa\xdf\x0b\x5b\x14\x65\x86\xab\x69\xfe\x03\x25\x9d\x88\xdd\x3f\xfc\x22\x7b\x2f\x72\x9b\xb0\x79\xbe\x41\x35\x04\x2d\x42\xa8\xf8\xe6\x8b\xd0\xe3\x59\x7f\x7a\x20\xf6\xb7\x58\x77\xa9\xd4\x06\xc0\x22\x78\x21\x4b\xc8\x46\x5f\x13\x61\x65\x9f\x5e\xb6\x8c\x32\x85\x77\x22\x1f\xfe\x03\x32\xe6\xcf\xa2\x70\x62\x32\x87\xfb\xa3\x8f\x27\xc9\x1e\xb6\x70\x43\xfb\x5f\xa5\x98\x09\x2c\xb0\x86\xa7\xe4\x05\xda\x40\x31\x98\x0e\x95\xaa\x18\xe4\x58\x74\x04\x61\xf3\xeb\xeb\x1d\xb5\x04\xae\x62\x6a\xfe\x9e\x68\xe2\xae\xcf\x71\x8f\x9b\x47\x2b\xef\xf4\x82\x03\x8f\xb2\x46\x22\x33\x2d\xf9\x48\xc6\x5d\xa0\x73\xcf\x6a\x9f\x15\x87\xfa\xa8\xf4\x00\xff\x5a\x49\x89\x54\x30\x69\xb1\x21\x93\x03\x83\x16\x76\x4c\x2d\x42\x78\xfd\x89\xb4\x66\x1f\xdc\xfe\xa5\x0e\x85\xda\xc0\x50\x4d\x14\xbc\x81\xa6\x44\x40\x14\xcc\x83\x52\x50\x6e\x98\x17\xaf\xaa\x0a\xb9\xff\xc0\x84\x1b\xfd\xae\xa4\x60\x57\xc3\x62\xe8\xc6\x78\xe5\x54\xf4\x6f\x39\x4c\x94\x9d\x33\x1c\xdd\xa8\xe4\x47\xf1\x56\xa3\xcd\x58\x8c\x88\x9c\xec\x9f\xa6\xc0\xd8\xa7\xe1\xe7\xa0\x09\xe6\x2c\x69\x35\xbf\x48\x0f\x4d\x5e\xa6\x1e\x35\xba\xe1\x30\x72\x33\xbd\x23\xdc\xb8\x84\x50\x9c\x4b\xd6\xaf\xa9\x9b\x3b\x62\x42\x60\x25\x7a\x03\x01\xa7\x74\x91\x97\xc8\x10\xc6\x0e\xe0\x28\x9b\xd8\x65\xd5\xb3\x35\x72\x7b\xdd\xa6\x16\x99\xaa\x88\x72\x57\x65\x73\xea\x59\x32\x07\x72\x85\xfa\xc4\x85\x02\x61\xe0\x95\x0a\xd5\x21\x08\x85\x78\xf5\xb6\x6b\xc8\xf5\xf9\x8d\x1f\x3a\xc2\xc6\x59\xe7\xd7\xbd\xa0\xaa\x4e\x1b\x5d\x3c\xf8\x42\xe3\x50\x5a\xea\x64\xce\x79\x99\xc8\xad\x56\x1e\x2d\xcc\x9f\xf8\x58\x78\x65\xb9\x90\x7f\x91\x5c\x10\x69\x70\x3e\xb5\xce\x77\xad\xd5\x44\x16\xa3\xd9\xd6\x4a\x00\xb1\x27\x5c\x4e\xfc\x3b\x12\x68\xae\x5e\xf9\xec\xf0\x92\xee\xad\x13\x00\xfa\x63\xe9\xfe\xa1\x61\xcc\xa9\xea\x96\x41\xbc\xa5\xa9\xfd\x67\x40\x34\x16\xef\x4a\x02\xb0\x9e\xd6\x91\x33\x61\xea\x25\x8a\xe9\x19\x9c\x05\xd5\x78\xbc\x6c\xa6\x62\xfa\x0f\xbe\xe6\x1e\x29\x32\x79\xa6\x95\x28\xb0\x62\x53\x1f\x49\x1f\x55\xd1\x9c\xba\xdc\x49\xdc\x8f\x22\xd4\x33\x3e\xaf\xa1\xc5\x45\xce\x54\xf2\x1d\xe2\xd4\xfc\x80\x96\x13\x0e\x15\x31\x1f\xbf\x69\xd5\x94\x12\x6a\x99\xf9\xaa\x4e\xb5\x47\xa8\x68\xbf\xbd\xdf\x22\x2c\xca\x15\xb6\xeb\x0c\xf3\x19\x59\x1f\xd6\xe1\xbd\x11\x91\x85\xe8\xa7\xf3\x23\xbc\xc5\x7c\xac\xec\xbb\xc6\xf9\xbd\x4f\x70\x2e\xfa\x63\x10\xaa\xaa\xff\x39\x23\x1e\x87\xb7\x74\xc5\x11\xac\xe9\x4c\x1d\xdd\xcd\xd2\xa2\x35\x3b\x72\xbc\x80\xce\xe1\x7d\x44\x85\xac\xcb\x44\x0d\x6c\x80\xd0\xc1\x1c\x25\x42\xc5\x62\x30\xa3\x98\x45\xdb\xeb\x1a\x8c\x73\xd4\xc2\xc7\xdd\x5b\x80\x39\x88\x38\xc5\xeb\xf6\x70\xb5\xfd\x9d\xcd\xc9\x4a\xcf\xd7\xa9\xbc\xa2\x92\x8f\xef\x91\x11\x21\x91\xaf\x39\x26\x01\x87\x4c\x1a\x19\x4f\x30\xbd\x31\x39\x53\x98\x1d\x32\xe1\x92\x89\x7d\x14\xd7\xc1\x37\xaa\xb6\x01\x90\x63\x7d\x86\x28\x49\x7b\x4c\x00\x6e\xf9\x38\x50\xcf\x5c\x1e\x77\x8e\x91\x3c\x3a\xc9\x18\x1a\x59\x41\x9d\xc1\x72\x42\xf4\xc3\xf1\x42\x4d\x8e\x02\x42\x81\x65\xae\xfd\xe0\xac\xc8\x83\x2e\x05\x38\xc3\xdd\x11\x76\x06\xcf\xa0\xb3\x37\xe2\xba\x0a\x0e\x44\xa8\xde\x2f\x76\xb9\x70\x5e\x69\x9a\x17\x2b\x40\x14\x9a\x41\x7c\x4c\x4f\x1a\x62\x17\x7c\xbd\xab\xfa\xc2\xea\xba\x38\x57\x96\xc6\x44\x29\x9d\x7b\x72\x12\x3d\xae\xa1\x29\x16\x91\x2c\xa8\x6c\xec\xab\x4e\x92\x9b\x1e\xff\x19\x87\x4c\x5a\x55\x2e\x43\x7f\x0d\x2d\x36\xe8\x4c\xbc\xfa\x2b\x21\xc0\x9c\xac\x70\x44\x7a\xd5\xc1\x3b\x90\xa1\xa7\xb3\xa7\xd8\xc3\x2b\x51\x4c\x12\x8a\x5c\xa6\x15\xe8\x14\x4e\x58\x7f\xe3\xf6\x93\xd6\x57\x3a\x65\x60\x58\x0c\x02\x03\x8d\x19\x75\x69\x56\x6f\x8f\xd5\xe1\x32\x94\x27\xaf\xc8\x1e\x4d\x6c\xd8\x35\x7a\xcd\xb5\x90\x1d\x1f\xc3\x44\x77\x7f\x44\x61\x15\xcb\x02\xfe\xc7\xd3\x11\xc3\x70\x0d\x9e\x8c\x04\x1b\x74\xea\x7b\x26\x10\x71\x73\xb6\xa5\x11\x5f\x61\x13\xdf\x9d\xb7\x9c\xca\x2d\x68\x54\x66\xc4\x57\x03\x2a\x17\xcd\x18\x20\xf6\xa2\x8c\xa7\x96\x30\x1b\x92\x86\xa0\x8f\xb8\xdc\x56\x0f\x7f\x75\xb8\x56\x42\x80\xd7\x0a\x15\xdb\x72\x3c\x94\x12\x71\x46\x8d\x8d\x33\xfb\x16\x28\x44\xf6\x35\x2f\x3c\x8b\x55\x26\x54\x12\x9c\x25\xee\x1c\x5d\xa6\xc2\x3c\x8b\x0a\xfa\xe4\x21\x6f\x4e\x05\xa7\x56\x58\x11\x82\x13\xad\x97\x94\xd3\x47\x81\xb4\xbb\x9d\x18\x61\x0d\x27\xd1\xad\xe8\x1a\xf3\xde\xe1\x9d\x16\xbf\x5a\xa4\xac\x80\xd9\x9e\x0e\x86\x31\x0f\x3b\xfd\x2d\x63\x11\xe0\xa6\xa9\x9c\x24\xb7\x64\x22\xee\xd7\x82\xea\xd2\x9b\xe3\xb3\x46\x53\x9d\xec\x2c\xc7\x30\x02\x39\x9f\x4e\x96\x73\x1c\x85\x38\x9b\x1f\x5c\xc4\x17\xc2\xd4\xa5\x7a\x1c\xeb\x1d\x06\x76\xef\x74\xd2\xb6\xe8\x4d\x0e\xc3\x63\xc3\xf4\x16\x0d\x2c\x5c\x83\xfc\x83\x67\xe6\x00\x84\x8b\xc1\x2c\x22\xeb\xe3\x3c\x06\x6c\x3a\x54\xe0\x77\x2a\xea\x65\x50\x96\x80\x18\x76\xd8\x98\x9f\x83\x0e\x63\x00\xbd\x44\x1c\x8a\x9b\x53\xe5\x8f\xeb\x4a\x18\x81\x8f\x21\x86\xc1\xce\xea\x3d\xf6\xa5\x02\x89\x11\xc9\x49\xbd\xbe\x25\xbb\x8c\x50\xbd\xb0\x2c\xd4\x98\x4a\x54\x8b\xa3\xe5\xde\x36\xba\x1b\x73\xef\xc8\x30\xe7\x18\x87\xa4\xaf\x64\x86\x16\x4a\x45\x22\x39\x66\x8d\x3f\x9d\xd3\x4d\xe6\x02\x74\xe6\x11\x53\x62\x75\x28\xff\x07\x70\x51\xd4\x02\x99\xd5\xe2\xa6\x5b\xef\x87\x5b\xc2\x25\xa2\x4e\x47\xfe\x5b\xef\xcc\xc6\xc6\x16\x6c\xc1\x01\x1f\xb4\xab\x32\xcc\x0a\x54\xa0\xf5\x2c\xbc\x58\xc7\x80\xac\x4d\x37\xd3\x5e\x1d\xba\x34\x0b\x22\xf7\x9a\x1f\xc0\xa6\x89\xcf\xb3\x4d\x01\x30\xb1\x06\x29\x14\x3d\x39\xb2\xf0\x22\x44\xd2\x87\xaf\x78\x7d\x71\x64\x0a\xe7\x92\x0c\x5b\x12\xa5\xb8\x29\x6e\x6a\xa5\xa9\x9e\xcc\x3a\x67\x2d\x2a\xfa\x00\xeb\x39\xe6\x2a\xa6\x17\xb2\xc9\xc4\x37\x60\x9d\x25\x35\xac\x02\x9b\xcd\xd8\x8f\xb3\x31\x3f\xd8\x11\x74\x85\x92\x8c\x07\x3c\xd2\x94\xa7\xd2\xcd\xe3\xea\x23\xfb\x1b\x94\xc0\xe7\x4e\xde\x6c\xcd\x14\x8d\x23\x5d\xa5\x40\x41\x66\x27\x8f\x73\x00\xb9\x2f\x62\xa8\xeb\x3f\xc3\x19\xc2\xe8\x30\x0c\xda\x82\xdf\x4c\x91\x8e\x19\x54\x00\xf6\x7c\x3e\xec\x04\x22\x26\x2a\x3b\xa1\x0e\x7d\x88\x09\x9e\x72\xb8\xdf\xd3\xf2\xbc\x22\x32\x64\x3e\x8a\x4d\xa7\x81\x6b\x96\xad\x3b\x1f\xd7\x4a\x4c\x5a\xea\x64\x72\xcd\x94\x4f\x7c\x0e\xfd\x3f\x5e\xf4\xf0\x69\x74\xb7\x33\x36\xb6\x9e\x12\x07\xc6\x1f\x6b\x4c\x78\xe0\xb1\xb1\x67\x13\x2f\xc0\xaf\x78\xa8\xf6\x62\x21\xd0\x67\x75\x96\xca\x92\x33\x7e\x2c\x97\xef\xf6\xb5\x97\x8e\x71\x98\x46\x11\x54\x26\x07\x70\xba\x89\x5a\x8a\xf8\xb4\x12\xb8\x0b\xf9\x7c\xd1\xe2\x3b\x01\xe7\xe7\x12\x90\x28\x61\xd8\xde\x69\xb5\xb3\xd5\xc9\x73\xf4\x92\xae\x14\xa2\x9e\x98\xb6\x21\xe4\x4b\xd8\x3b\x18\x91\xc1\x4c\x4d\x1f\x00\xcf\xe0\x87\xd0\x41\xbe\x05\x6b\x4d\xb9\x28\xa8\x79\x87\x52\x5f\xba\x8e\x59\xe4\xa1\x9e\xf9\x04\x52\xe8\xa0\xd9\xb4\x40\x97\xae\x9b\xde\xce\x09\xc5\xbd\x53\x7e\x0d\x9c\x11\x28\x02\x87\x4d\xda\xef\x55\xcf\x32\x45\xbf\x95\x83\xb1\xaa\xf2\x26\xea\x12\xc7\xde\xd7\x6c\xe5\xbb\x06\x46\x48\xa5\x54\x34\xa1\xce\xa3\x7b\xcc\x04\x17\xda\xfc\x32\xd6\xa6\xa9\x82\x19\x4e\xee\x2b\x31\xe4\xd7\x50\x7d\x63\x54\xf2\x85\xe0\x60\xd8\xfe\xcc\xa2\xa3\xe6\x08\x9a\x6a\x1a\xdf\x75\x66\x93\x93\xe5\x2c\x06\x80\xc7\x27\x7e\x78\x8c\x52\xb8\x9a\x46\xc0\xda\xa9\x9c\xe4\xce\xb6\x34\x8d\x84\x4e\x0f\xa7\x40\x38\xda\x2d\xfe\x1f\x5e\x6a\xb8\xa4\x71\x9f\xe3\xcc\x61\x59\x86\x47\xe8\x6f\x51\xfb\x36\x7d\x93\x88\x01\x8a\x16\xdc\x4d\xb1\xbe\x9f\x70\x0a\x7e\x89\x32\xb0\x85\xbc\xe3\xf8\xf8\x27\x89\x00\xb2\xb3\xce\x13\x79\x66\x3a\x7e\xab\x6b\xbb\x5a\x26\xb6\xdc\x4b\x00\xbb\xb9\x75\xb7\x84\x82\xcb\x67\x3d\x49\x9b\x65\xf0\x50\x2d\x79\xaf\x16\x17\x49\x72\xc3\xe5\xdf\x91\xc6\x25\x6e\xde\xe6\xc5\x1e\xcc\xac\x9b\x51\xa0\x0f\x50\xce\x3b\x79\x78\xd8\x7a\xa8\xf9\x5a\xc4\xd7\xff\x43\x60\x82\x1f\x26\x22\x1a\x06\xa7\x5e\xa1\x81\x75\xf8\xe0\x8f\x41\x92\x93\x08\x05\x22\x9b\xce\x04\x69\x0e\xae\x22\xdf\x31\xa8\x2c\x9f\xfa\xe9\xd0\x19\xaf\xb6\x45\x75\x41\xb7\x63\x47\x11\x9b\x13\x19\x5d\x49\xaa\xc9\xf4\xd8\xa8\xae\xd5\x84\xad\x4e\x72\x89\x66\x50\xe1\x8c\x1e\xd0\x6a\x98\xaf\xba\xc6\x15\xe0\x07\x1e\xec\xe4\x1b\x84\x81\x58\x45\x57\xe6\xa1\x2b\x2a\x45\x82\x88\x3e\x06\x19\x68\xb2\x04\x95\xbe\x07\x18\x9a\x9c\x89\x81\xef\x4a\x9d\xbc\x1f\xaf\xdb\x60\xc4\x37\xb2\xcc\x4a\xfe\xba\x64\x2f\x51\x40\x13\x8b\xc8\x40\xe8\xc7\xd3\x59\x57\xdb\xb0\xb7\x64\x64\x2d\x1f\xd9\x4d\xe2\xe6\x6f\x78\x75\x88\x01\x71\x6e\x71\x0a\xc3\xd4\xf8\xc1\x7b\xdd\x8b\x2b\x7f\x45\xc8\xcf\x44\x24\x0e\xc7\x81\x15\xba\xe8\x29\x80\x5e\xde\x68\xd3\x4c\x1a\x4d\xff\x0c\x5a\x8b\x41\x7f\xbd\x9c\x0d\xa3\x86\xb0\x7b\x38\x21\xe5\xfd\x49\xaf\x2a\xee\x55\xdc\x90\x01\x70\xd9\xf0\x64\x4b\x8e\x4d\xe2\xd8\x0f\xb0\x3e\x45\x06\x1d\x39\xef\x19\x79\xa2\x5d\x21\xe5\xb2\x4a\x3b\x92\xec\x7c\xaa\x67\xc6\x81\xc0\x24\x3e\x86\xb7\x8f\xe3\x96\x19\xfc\xd5\x6b\xbe\xa3\x17\xc0\x7b\x9d\x46\x1b\x2b\x2a\x40\x8d\xd8\xb9\x09\x3c\x80\xf5\xa5\x82\x52\x87\x9c\xb8\xe5\x99\xdb\xdc\xce\x19\x65\xee\x95\x27\xcf\x04\x2b\x4f\x17\x76\xc1\xd6\x74\x24\x98\x09\xac\xd8\xe5\xba\xe4\xaa\xf4\x65\xa2\xfc\xeb\xb7\x2d\x5d\x53\x48\x8b\xa8\xe9\x79\x7d\xcf\x11\x1e\x74\x3d\xe8\x6a\x57\xc2\x77\x23\x46\x04\x93\x6e\xb2\x29\x1d\xa4\xb0\x92\xb6\xe6\xcf\xba\x96\xf5\x67\xd7\x60\xaa\xea\x86\xd1\x3a\x80\xed\xd0\x6e\xf3\x8b\xe4\xd4\xdc\x6d\xe0\xa5\x12\x6c\x05\xec\x36\x98\xbb\x58\x31\x4b\x25\x60\xbd\x53\x63\x7a\x73\x2e\xe8\xfc\xd5\x5f\xb4\x54\x97\xd8\xa9\xb9\xfe\x83\x85\xd2\x20\x4b\xf1\x92\xba\xf9\x44\x6a\xa2\x8e\x8e\xd1\x49\xe8\x26\x20\x95\x88\x3a\xa3\x1a\x44\x2c\x7d\x3e\x73\x89\xe4\xbf\x06\xce\x67\x24\x5f\xa5\x7a\x6d\x71\xf9\xb3\x1c\x75\x8c\x2b\xd6\x08\x40\xc9\x89\x59\x5c\xaa\x0a\x77\x33\x22\xe8\x69\x27\x39\x01\xa7\x12\x51\x81\x39\xa9\x07\x78\xa3\xb7\x9a\x71\x4f\x02\x49\x71\xaf\x2f\x86\x2c\xe5\x3e\x8f\x25\xf1\xcf\xdc\x5c\x8a\x18\x47\x8a\x6b\x44\x25\x7b\xa4\xa8\xbe\xea\x41\x40\xed\x46\x0c\xd1\x82\x7a\x5b\xce\xa6\x9d\x43\x14\x49\x25\xc8\x9d\x93\xdc\x94\x54\xb9\x6d\xe0\xe9\x48\xd5\xc7\x45\x37\x80\x3f\x14\x52\xb4\x40\x40\x8b\x87\x1c\xb5\xe6\x2f\x24\x2d\xbe\x42\xf6\xde\x9b\x76\x27\xdc\x8a\xd2\xda\xa6\x1a\xa9\x9a\x6b\x69\x98\xb2\xdc\xb1\x26\xa2\x9d\x47\x1f\xc3\x21\x57\x7d\xca\x8a\x85\x2c\xc8\x6a\xca\x9e\xf2\x7b\x20\xf4\x27\xf9\x8a\x89\xce\x9d\x4c\x98\xed\x15\x63\x13\x50\x1d\x3c\xfa\x45\x48\xf4\xf0\xd1\x4f\x3f\xbf\xb7\x39\x15\x88\x50\x30\x8e\xd5\xf6\x18\xf2\x3e\xf2\x8b\xf4\xd6\x4f\xf1\x3a\x7d\xa2\xad\xc4\x05\x84\x99\x7f\x9f\xfb\x3d\x1f\x9c\xec\xdd\x30\x9a\xe8\xae\x6c\x71\x58\x67\x7d\xd8\xbc\xd8\xb2\xf0\xae\x08\x63\x2a\x1c\x86\xf8\x2b\x88\xea\xd5\xb4\xad\x6a\xc2\xfc\x53\xa8\xfe\x30\xb7\x6e\x96\xef\x35\xcd\x41\xa5\x17\xe0\x80\xfa\x01\xe5\x57\xa7\x83\xf6\x12\x23\xc6\x1f\x37\x1a\x28\xf5\x64\x81\x85\x0b\x95\x3c\x9d\x64\xd6\xc9\x92\x27\xef\xa4\xe9\x1d\x94\x5d\xd7\xc1\x31\xdd\x4c\x98\x79\x79\x14\x32\xda\x92\x69\x01\x7c\x61\xd0\x7e\x67\x52\xd6\xb3\x2f\x69\x4a\xfc\x12\x6c\x9b\x5e\xb4\x17\x27\x63\x3e\x4e\x67\x4d\xed\x40\x4b\xe7\x22\xb1\xa7\x23\xed\x86\xb9\x86\x65\xfc\x0e\x8d\xe6\x3d\x63\x84\x4e\x04\x7b\xab\xe8\x96\x40\x16\x9c\xa0\x36\x1f\x96\x39\x2b\x7c\xf6\xeb\x5c\x78\xc1\x6f\xa2\x24\x11\x9c\x64\x6a\x2f\xe0\x64\xac\xb7\x57\x09\x15\x92\x09\xd1\x43\xc1\x74\x85\xd7\x1a\xd0\xd9\xf8\xdf\x0a\xc2\x13\x0e\xc6\xb9\x97\x8f\xfc\x62\x34\x8a\xc4\xc9\x2a\xe7\xd8\x3e\xef\xc9\x0c\xe4\x57\x4e\x60\xb8\xef\x51\x8b\xb2\xcb\x10\x4b\x04\x6b\xe4\x68\xc3\x18\x55\xf1\xec\x09\x26\x78\x7b\x3a\xee\x76\x43\x58\xec\xf7\xa4\x50\x14\xf1\x56\x6a\x95\x7d\x6b\x1e\xe8\xf7\x6a\x41\xa2\x6b\x98\x25\x66\x5e\x15\xab\x5a\x9c\xea\x3f\x7e\x2a\x93\x61\xe0\x1b\x87\xa4\x0a\x8d\xee\x30\x3a\x14\x5b\xd2\xe4\x4c\xe9\xdb\x4d\xef\xd9\x19\x60\x26\xa1\x40\xcc\xfc\xbf\xf7\x9c\xfe\xd1\x52\x1a\x54\xb3\x39\x78\xb9\xc7\xad\xd6\x6e\x4f\xe0\xb8\xc8\x77\x51\x61\x6d\xcb\x6f\xd9\xe2\x8c\x57\xd3\x7f\x03\x6b\x32\xa4\x1f\x15\x2b\xfc\x3c\xde\x3d\xe1\x61\xfd\x21\x2a\x2c\x0d\x9b\x1d\x8c\xe6\xf2\xf4\x12\x2c\x59\x09\x87\x05\x97\xfd\xfe\xe7\x53\x26\x84\xfb\xbb\x76\xa5\x3b\x21\xf6\xe0\xa7\xfd\x18\x8f\x6b\x92\x9a\xa7\x3e\x79\xf9\x44\xa4\xa1\xb2\xd8\x4b\x0d\xf4\x0e\xb3\x0b\x82\x57\x21\x91\x5e\x7f\x6d\xa2\xda\x88\x39\x63\xef\x7e\x2c\x0e\xa7\x60\x26\xb6\x5f\xc9\x63\xfe\x05\xc7\x70\x21\x3d\x4b\x7d\xfd\x30\x94\x63\xf1\x64\x27\x3d\x96\x60\x9e\xae\xdb\xde\x10\xeb\xd9\x9d\x95\x98\x3b\x84\xd9\xae\xa0\x4c\x8d\xcd\x61\x86\x15\xff\x73\x84\xb2\x80\xfe\x50\x07\xa7\xde\x9b\xcd\xe5\xaf\xe5\x92\x70\xc8\x2a\xed\x87\x14\x92\xa9\x77\x34\xe2\xb5\x72\x5c\x31\x75\xfb\xa0\xd8\x90\x3b\xec\x24\x7c\x16\xcc\x95\x32\x77\x91\x43\x2e\x62\x6a\x12\xa4\x01\x9b\xe2\xd6\x40\xc6\x3c\xcd\xe0\x3d\x70\x23\x85\xc7\x82\x62\xd3\xda\x54\x47\x49\x4c\x08\xfb\x5d\xcb\x1d\xbe\x41\xbd\x48\xb5\x19\x8e\xa8\x86\x51\x42\xfd\x09\x0e\x25\x62\x0e\xe6\x5c\xb2\xea\x35\x74\x3a\x05\x3c\x2c\xb0\x43\xdd\x3b\x11\x44\xb4\xe7\x6d\x4e\x10\x11\xd1\x8e\xc8\xc2\xc9\xe9\x55\x82\xcd\x87\x42\x1f\xab\x53\x6b\x28\xb0\x5f\x05\xed\x7c\x90\x50\x5c\x57\x18\x83\x0b\x2e\xe2\x3f\xb1\x18\xd9\x6d\x78\x26\x8f\xcd\x6f\x7a\x91\xa9\xe5\x57\xf6\x3f\xd6\xa1\xfd\x75\x56\x76\x8f\x7f\x31\x20\xe7\xd4\x9b\x00\x90\x46\xf8\x0e\x1e\xa3\x6c\xd8\x65\x77\x97\x33\xe5\xd0\x10\xa9\x7b\x27\x39\x7b\xdf\x9b\x4c\x25\xa8\xea\x6f\xd3\x13\x46\xcd\x34\x77\xbb\xa2\x17\x6a\x15\xaa\x40\x3f\x5f\x03\xf6\x16\x6d\xd0\xf7\xc5\xf5\x83\x8d\x21\xfb\x41\x4a\x9e\x41\xea\x35\x70\x25\x0f\x67\x31\x11\xc5\xc1\xe2\x8f\x8f\x6c\x14\xcd\x17\x26\xdb\x22\x57\x74\xfc\x4a\xb0\x62\xe7\x17\xfd\x07\x9a\x7a\x0d\xad\x6d\x37\xb1\x1a\xa7\x9f\x06\xb8\xd7\x6c\xa3\xed\x28\xb4\x23\x12\x6a\xe1\x74\x43\xd6\xd5\x1e\x55\xa8\x46\x18\x6a\x02\x4b\xab\x87\xad\x6c\xe6\xfd\x50\x52\xab\x8f\x49\x8d\xb2\x30\xff\x61\x58\xf6\xf0\xe6\xb9\x73\x28\x36\x0b\x6c\x26\x97\xb4\x4c\x13\xe8\xb0\x17\x69\x03\x8f\x8a\x96\x71\x9a\x93\xec\xd7\x46\xaf\x3d\x86\x22\x95\x48\xa5\x1a\xfc\x37\x7e\x25\x72\x00\xd4\xb2\xfa\xed\x5a\x9a\xd8\x2e\x1e", 3969);
*(uint64_t*)0x20002298 = 0xffffff46;
*(uint64_t*)0x200022a0 = 0x20002180;
memset((void*)0x20002180, 132, 1);
*(uint64_t*)0x200022a8 = 1;
*(uint64_t*)0x200000d8 = 3;
*(uint64_t*)0x200000e0 = 0;
*(uint64_t*)0x200000e8 = 0;
*(uint32_t*)0x200000f0 = 0x20080000;
	syscall(__NR_sendmsg, r[0], 0x200000c0ul, 0x840ul);
	return 0;
}
