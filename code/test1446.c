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
	res = syscall(__NR_pipe2, 0x20000000ul, 0ul);
	if (res != -1)
r[0] = *(uint32_t*)0x20000004;
memcpy((void*)0x20000040, "\x9c\x1d\x12\xb3\xef\x8b\x7e\x36\x8b\xcd\xb5\x22\x39\x8a\xdd\x9c\x6b\xdd\x6b\x06\x65\xaa\xaf\x6b\x0f\x24\x85\xcd\x9e\x5c\x52\x7c\xfd\x92\xbd\x72\x27\x4d\xe5\xd3\x05\x8d\xe3\x11\xf8\xcc\x9a\x1f\xf0\x81\x9b\x85\xc6\x2b\xd7\x91\xa7\x51\x13\xe9\x6b\x76\x08\x1d\xfa\x0f\x4b\xa5\x3b\xcd\xb9\x69\xaa\xb3\xe6\xf0\xf0\x7d\x85\x7c\xad\xe1\x21\x10\x92\xce\x27\xb5\x7f\x00\x5b\xac\xaa\x0b\x3b\x67\x34\xec\xc2\xa8\x9d\x8d\x34\x36\x9f\x66\xdf\xc6\xd5\x5b\xab\x0e\x1b\x29\x41\x52\xe2\x67\xb0\x6c\xbe\x99\x52\x8e\x83\x42\x02\x2b\x68\x59\xee\x9e\x72\x4c\x10\x9c\xab\x5c\x7f\x57\xa2\xf1\x17\x71\x86\xdd\xdd\x8c\x8a\x03\x33\x5b\x5d\x5c\xf7\x2d\xef\xc7\xb2\x52\x5f\x43\x41\x86\x7a\x8d\xbf\x15\x8a\x2d\xf6\x77\xbf\x9c\xc7\x0a\x0e\x69\x66\x47\x5c\xf4\x9b\xaa\x0b\x76\xdf\x6a\x95\x2c\xec\x3d\x12\x37\x71\xd2\xff\x05\xdd\x72\x01\x0d\xc3\xbb\x50\xb9\x8d\xc9\x56\xc4\x77\x61\x27\xa7\x5f\xd3\x67\x43\xf9\x0b\x6f\x0b\x80\xbd\x91\x4b\xf4\x4e\x2d\xbf\x7c\x34\xce\xf3\x47\x73\xd2\x0f\xfe\x58\x0c\xe8\x15\x04\xd5\x9b\xda\x39\xd8\x44\x0f\x69\x5b\x05\xb8\x5d\x6c\x30\x37\x8a\xc5\x3d\x97\x2b\x40\xb4\xf8\xcc\x33\xf2\x77\x95\x3f\xe4\xd7\x4a\xb1\xdc\x2a\xd2\x12\x20\x1d\x4a\x1f\x57\x9e\x37\xcf\xf9\xd6\xbd\x77\x51\x03\xf2\x02\x25\xf2\xed\x78\x87\xf7\x6b\xc6\x14\x22\xf1\xa2\x44\xca\xbd\x15\x71\x6e\xb3\x4c\x48\x8d\x69\xed\xd2\x58\x9b\x25\xe1\xa2\x40\xeb\x41\x12\x7e\x45\xaf\xb8\x06\x6a\x6d\x20\xec\x36\xc0\x32\x7d\xfb\xba\x75\x54\xa3\x31\x96\xd5\x72\xd7\x7e\x48\xe9\x9b\x66\xa3\x59\x75\x84\x87\xcd\x12\x8e\x67\x93\xfa\xc6\xdf\xe0\x2b\x97\x61\x54\x6e\x53\x53\x5c\xd1\xf3\x72\x03\x97\xba\x69\x47\xfe\xf7\x95\x3e\x4c\x7a\xc1\x9a\x4b\x62\x08\x3d\x33\x6e\x9f\xdf\xf6\x43\x0d\xd6\x31\x72\x76\xe3\x61\xfc\x52\x8b\x57\x4c\x0a\x12\x8b\x13\x35\x8a\xb8\xbf\xfc\x7e\x22\xfc\x4c\x88\xc7\x09\x40\x8d\xd2\xf6\x0a\x05\xe4\xc3\xd7\x89\x3a\x6f\xc0\x95\x5c\xc3\x4f\x3c\x3c\xfd\x35\xfb\xb4\x3b\x77\xf9\x5e\x4c\xe6\x3d\x7c\x52\x4f\x3f\xaa\xbe\x60\x47\x3e\xec\x6a\xd9\x23\xdd\x2e\xc7\xdc\x23\x84\x83\xc6\x6a\x5b\x84\x82\xfe\x3c\xbd\x8c\x3c\x5c\x5b\xd8\xde\x6c\x93\x58\xf3\xc6\x31\x2d\x19\x3e\x36\xeb\x42\x08\x2a\x02\x25\xe5\xda\xcc\xfc\x28\x28\x12\xad\x5e\x3b\x8a\x03\x04\xe0\x8a\xa8\xb7\x27\x94\x02\x3b\xdd\x05\xd2\x3b\x04\xe5\x71\x10\x6b\x46\x4b\x9f\x8b\x96\x02\xbd\x32\xe8\xc0\x68\xea\x13\x13\xc2\x40\x21\x9d\x4d\x01\x43\x20\xa5\x0d\x43\x86\x32\x80\x76\x64\x9e\x1e\x6a\x8d\x1f\xe3\xb8\xde\xcc\xb9\xfe\xc0\x8a\x23\xe9\x40\x33\x90\x93\x9c\x70\x2b\x6f\xaf\xb8\xb3\x29\x65\x49\x3a\x50\x71\x54\x23\x7d\x21\x10\x78\xb5\xf7\xbd\x4a\xb0\xdc\xaf\xde\x81\xcd\x02\xb3\xdd\xdd\xe3\xf2\x99\x07\x76\xc7\xde\x42\x23\xe4\x20\x8e\x8b\xfa\x51\x6d\xee\x2d\xc6\xff\x9d\xee\x37\x80\x4c\x1f\xf6\xf1\xe4\xf3\x9f\x1d\x81\x94\x1e\x90\x9e\xe6\x51\x36\xe6\x38\xa3\x68\x5c\x18\x88\xd9\xaa\x6d\x98\x5f\xed\xc1\xbd\x21\x62\xf4\x68\xdd\xaa\x34\xad\x67\xdf\xd9\x39\x40\x92\x36\xe6\x64\x6a\x08\xba\x89\x31\x39\x4b\x6f\xa6\xce\xc2\x09\x95\x70\xe4\xab\x99\x33\x34\x49\x8a\xea\xd7\xae\xa6\xb7\xec\xa9\xbb\xce\x4d\x42\xbe\xba\xfc\x89\xb5\x3f\x2b\x1a\xc5\x9b\x4f\x46\x6a\xbd\xc7\x95\x8f\x5b\xf1\x94\x63\x0b\xa4\x69\xae\x88\xb6\x21\xc7\xb8\x7c\xaf\xed\x04\x6f\xde\x9c\x9f\x9d\x5e\x59\xf9\x53\x6e\x7e\xf3\x27\xa5\xd9\xdb\xfe\xf6\x50\x72\x90\x49\x82\xd9\x75\x77\x07\x9e\x07\x7d\x42\x8a\x28\xc8\x15\x3c\x52\x5d\xa8\xbd\x05\x07\x03\x48\xa1\xc0\x22\xf5\x91\xae\xc8\xd4\xe2\xa7\x73\x47\xea\x69\x69\x00\x2c\xf3\x30\x73\x6a\xd0\xa5\x0e\x35\x70\xca\x0d\x7e\x78\xef\x98\x54\xb6\x58\x41\x7e\xce\x71\x87\x34\x6f\x62\xbb\xbe\xf2\xb7\x11\xc9\x68\x1c\x8f\xdc\x46\xac\x63\xc7\x1d\x61\xad\xc3\x9a\xf0\x6c\xac\xf6\x98\x3c\xb2\xe6\xb1\x38\xfa\xc7\xd2\xec\xa2\x88\x09\xde\x68\xfa\xfc\x06\x7d\xb9\x9d\xfb\x8a\x9b\x55\x35\xf6\x8c\x09\x9b\xba\xcc\xba\xaa\xdb\x8b\x54\xa0\x1c\x42\x0f\x32\xf7\x83\x14\x0e\x5d\xeb\xcc\x94\xad\x5f\xde\xb7\x4c\x3b\x43\x63\x36\x5f\x7b\xe0\xf8\xd0\x7b\x95\xf0\xa9\xd3\xca\x38\x75\x10\x6b\x9f\x16\x5a\xa7\x37\x11\xc5\x94\x8a\x3e\x4f\x82\xb2\xf6\x51\x7b\x3f\xdc\x99\x08\xba\x6d\x32\x7c\x97\x22\x1d\x2c\xff\x2a\x50\xd2\x66\x23\x5d\x03\xc4\x37\x07\x6a\x26\xa7\x4d\x22\xa5\x40\xf6\xa4\xae\x82\xe7\x08\x49\x0e\xdc\x09\x1c\x04\xc6\xe9\xae\xcb\xfa\xbb\xde\x5d\x1d\x9b\x30\x3d\x79\xf0\x58\x43\x20\xbb\x58\xaf\x7b\x39\x9b\xeb\xac\x80\x77\x79\x2d\x10\x01\xbc\x66\x63\xa8\xde\xec\x2c\xef\x5d\x73\x62\xb7\xff\x2f\x14\x4a\xbe\x8b\xad\x36\xdf\x86\xbf\xd6\xab\x72\xbc\xd9\x7f\x77\xa0\xd7\x0e\x05\x92\x8f\xa1\x9c\x52\x7c\x66\x4e\x41\x35\x0b\x99\x45\xd2\xbf\x76\xa5\xf7\x67\x2a\x39\xb1\x45\xee\xec\xfe\x68\xb0\xbc\xb0\xc7\x2c\x7e\xed\xa1\x04\x22\x00\x44\xa9\x1d\xb2\x93\xed\x44\x84\x87\xf8\x74\xad\x19\x49\x2f\xb7\xe6\x1b\xc9\xbe\x28\xa3\xa7\x92\xe0\x27\x37\x0c\x7f\x45\xf6\xaf\xfe\x78\xf5\x3f\xe7\xfa\x7e\xad\xc2\x51\xf7\x84\x9a\x53\x68\xee\x5f\xbb\xf1\x9e\xd1\xe5\x0f\x1a\x40\xf9\xbf\x98\xd7\x9d\x99\x55\x9b\x99\x4d\x22\xec\x4c\x31\x0f\x79\xa9\xbf\x2d\x3c\x25\xc8\x10\xc3\x3d\x13\xcf\xe7\x0e\xb6\xd5\xe1\xf0\x71\x53\xbc\x66\xb2\x12\xef\x13\xa5\x46\x42\x0a\xcc\x07\x44\xcd\x50\xeb\x48\xee\xc6\x62\x5d\x61\x0a\x83\xe6\xf0\x46\x61\x8c\xf1\x2d\x5f\x96\xe9\xeb\x82\xb6\xa4\x78\x4b\xdd\x52\x52\x0a\x23\x1c\x6e\x99\xed\x58\x16\xd2\x03\x11\x95\x83\x10\x57\xfe\x5c\x0b\x9b\xed\x3f\x26\xd5\x15\x34\x4d\x68\x39\x3f\x2f\x47\x80\x72\x79\x1d\x4f\xc2\x58\x38\x93\x1b\xcc\x1e\xda\xbd\x92\x31\xe2\xce\x03\x78\xcd\x22\x38\x89\xb5\x79\x2e\x21\x92\xe4\xe1\x82\xe8\x99\x32\xf5\xb1\xd3\x4f\xac\xae\x35\x84\xce\x57\x0d\x50\x32\x64\x5d\xd5\xa9\x63\x5c\xdc\x96\x72\x68\x92\x79\xbf\xfe\x98\x3a\x73\x2a\x8c\x4d\x31\xac\x54\x3c\xeb\x98\xe6\x24\x16\xd7\xc4\x67\x8b\xda\x36\xcb\x1b\x0e\xa6\xf0\xe1\x5b\x79\xfd\x6a\x9b\xec\x6d\x20\x9b\x4d\x66\xc9\xdd\x47\x9b\x57\x90\x7e\x38\xd1\xc2\x8c\x6e\xeb\x3a\xd5\xf9\x89\xbe\x30\xf2\xbf\xa6\xbf\x84\x22\x46\x00\xb2\xcc\x6f\xa8\x1c\x79\x94\xb4\x3d\x4a\xfd\xb3\x46\x19\xb6\x61\xdd\x8c\x2d\x76\x96\x34\x9f\xf7\xe1\x3d\xd2\x58\x60\xe7\xe5\xcf\x44\x50\xe0\xbf\x4f\x2f\x2f\x62\xe5\x1b\x11\x45\x34\xed\x04\x7a\x2e\xca\x00\x81\x01\xdd\x2f\x90\xf7\xe4\xba\xc7\xd5\x07\x7b\xeb\x76\xeb\xfc\x82\x45\xb8\x8f\xb5\x69\x29\x4c\x03\x5c\xbf\x9c\xdf\x7e\xbd\xb2\xb8\x7d\xc8\x18\xbe\x34\x91\x4e\x6c\x3b\xca\x05\x80\xed\x6e\x00\xff\x87\x7c\xc9\xb5\xcb\xdf\x77\x8c\x51\x5e\x44\x06\x88\x2d\xde\x5f\xc3\x39\xb0\xa9\x20\x50\x9a\xe6\x12\x6e\x80\x50\xa5\x05\x5e\x3a\xc2\xe7\x28\x83\x8a\x0b\x75\xb0\x2e\x61\x0a\xba\xc5\x37\x2a\x45\x44\x55\xc5\xd3\xc4\xd8\xa9\x75\x74\x55\xec\x82\x27\xbc\x21\x1e\x85\x2b\xc3\x74\xb3\xc9\x92\x13\x37\xdc\x00\x17\x5e\x19\x0a\xb7\x5e\xf5\xdc\x24\x22\x13\xd1\x92\x88\x92\x8f\x15\xba\x59\x0b\xaa\xf8\x4e\xa3\x52\x81\x45\xf4\x50\x9b\xc3\xce\xdb\xa1\x57\x78\xf1\x75\xfc\xfc\xa6\x10\x1b\x49\xb5\x82\x54\x53\x51\xb5\xbf\xce\xfa\xf1\x24\xca\x8a\xdf\x8c\xcd\x07\xf9\x75\xe3\xc9\xfc\x6e\xdc\x02\xb1\x0f\xa8\xc9\x74\x8b\xb5\x04\xe1\xef\xd0\xf2\xa0\xb9\xaa\xc6\x82\x2f\x68\x44\xef\xc9\x6a\x19\x7b\x5e\xa2\xbe\xa1\x89\xda\x74\x3a\xab\x1a\x30\x06\xb9\xb1\x4c\xf5\x7b\x25\x50\xa7\xb0\x4c\xa3\x1b\x8e\x9b\xca\x31\x93\x83\xc0\x44\x5f\x50\x95\x8c\xf5\x17\x0c\x3d\x3d\xd1\x34\x85\xe5\x5f\xbb\x62\xe7\x81\xf2\xbe\xb2\x52\xf9\xf5\xaf\xf7\x79\xbf\xaf\xca\xd5\x91\x93\x2f\x1f\x93\x08\xcb\x24\xb9\x51\x37\xd5\xab\x19\x27\xc4\xf9\x9b\xa7\x97\x5d\x2c\x7f\x03\xaf\x02\x62\x6b\x26\x23\xf1\x09\x5e\xda\x9b\xeb\x8f\x07\xae\xf9\xbe\x20\x53\x66\x4e\x21\x7b\x11\xd9\x74\x4a\x90\x37\x98\xa7\x88\x1f\xf1\x76\xd6\x71\x30\x13\xd8\xfa\xe2\x55\x8f\x07\x7a\xe6\x4e\xac\x16\xa3\x8f\x35\x9d\xfb\x88\x56\x74\xa4\x14\x87\xcc\x7c\xf7\x96\x2f\x9e\xb3\x99\x27\x35\x0b\x80\xf8\x3c\xdd\xc9\x88\x49\x13\x4c\xe5\xc1\xac\x5f\x35\x7f\x36\x8c\x82\xba\x52\x69\x68\x3c\x26\x26\xf8\xe3\x35\x3b\xf4\x17\xe3\x27\x0c\xa3\xe7\x13\x16\x64\xa7\x97\x37\x75\x79\x68\xb6\x93\x5d\x89\xda\xf2\x15\x5b\x13\xd0\x95\x40\x38\x55\x35\x39\x2b\xe7\x67\x90\x3f\xe7\x85\x33\x84\xc3\x47\xc7\x14\x5c\x54\x40\x59\xbb\xee\x9a\xde\x57\x65\xb1\x96\xa0\xd2\xb3\x84\x5f\x54\x77\xa9\x10\x83\x5b\xee\x3f\x03\x56\xfe\x8f\x54\x29\xde\x0c\xff\xb6\x58\x5c\xe4\xd8\x79\xf6\xdc\x31\xcc\x15\x28\xa5\xe6\x00\x57\x1c\x9f\xa0\xd5\x62\xcc\x40\x8c\xdb\x81\xe6\x17\xbf\x2a\x34\x8c\xab\x8c\x0c\x81\x2b\xdf\x4b\xbd\xb6\x27\x43\x7d\xd6\x1a\x84\x6d\x8c\x16\x64\x97\x8c\x25\x73\xf0\xde\xf9\x87\x4c\x82\xb3\xdf\xe9\x38\x66\x6e\x4f\xf8\xd8\x94\xe1\xeb\x02\xb1\xe8\x9d\x4d\x05\x74\x20\xa9\xcc\x6e\xde\xaf\xfc\x84\x23\x8b\xa2\x16\x38\x4e\xfa\x44\xa9\xf9\x7c\x51\xf0\x43\xa9\xe0\x3b\x6f\xc7\xfe\x29\xee\x83\x39\x81\x5f\x66\xaf\xfe\xde\xee\x78\x5b\x37\x19\xa8\x66\x4e\x82\x6e\xba\x2c\xf8\xe9\xdf\x75\xce\xcc\x7a\x04\xfd\x2b\x06\x3c\xcb\x0d\xb9\x82\xa0\x57\x47\xf2\x54\x22\xd2\x39\x84\xfa\xc0\xaf\xed\xd2\x45\xe7\x93\x71\xd5\x86\x78\x2a\x4b\xc9\x88\xd1\x8f\x16\x9a\x8c\x8c\xd7\xc2\xd1\x95\xd0\x88\x43\x7f\x48\xc8\xff\x60\xd6\xa1\x03\x85\xd5\xdb\x29\x51\xa8\x5d\x49\xec\x71\x51\x26\x8e\xc0\xba\x00\x85\xdd\x66\xc1\xbf\x93\x95\xb8\x4d\x85\x59\x14\xea\x06\x0b\x19\x0d\xe3\xa1\x5c\xbd\x7d\xc1\x0e\x41\x54\xa2\x48\x72\x8b\x88\x10\x1d\xd2\x6d\xf2\xcb\x9a\xf5\xb5\x7f\xbb\x4d\xff\xc8\x90\xa9\x81\x68\x49\x3c\x98\x15\xeb\x03\xfa\x5c\x61\xa9\x87\xa3\xcd\x31\x8d\x44\xab\xa9\xf8\xa7\xa6\x55\x98\x33\xa9\xbd\x8b\x24\xa2\x8d\x10\x73\x65\x55\x22\x29\xb6\x1d\xf5\x4c\xaa\x7b\xd7\x3b\x8a\xb5\x14\x18\x78\x94\x06\xf7\x0f\xa9\x47\x2b\x92\x29\xf4\x8c\x7e\xe4\xf9\xf8\x41\x1a\x45\x86\x5d\x17\x14\xa9\x88\xbf\x0a\x7c\xea\xf7\xcf\xb3\xa3\x7f\xea\xae\x9b\x96\x36\x6b\xc5\x77\xeb\x94\xb8\x7d\x0c\x2e\xd1\xf6\xc1\xea\x03\x00\xa4\x34\x6f\x2f\xbd\xa5\xd4\x18\x2b\xd7\x2d\xb9\xc0\xb0\x41\xd9\x35\xd5\x53\x7c\x05\x3b\xfa\x23\x08\x1e\xe1\x1b\xc8\x97\x80\xd0\xad\x2b\xad\x30\x0e\x58\x5d\xc7\x42\x1d\x85\x02\x89\x7c\x0e\x95\x61\xd5\x46\x28\xb6\x7d\x3e\x11\x77\x26\xe0\x46\x9a\xf3\xee\x89\xb2\x4e\x51\x3d\x34\xfc\x22\x1b\x14\xf6\x36\xf1\xf1\x4c\x70\x71\x07\x32\xfa\xc3\x47\xf1\xe3\x7d\xe8\xae\x07\xe8\x9b\x45\xdf\x61\xc0\xdb\x26\xd0\xe7\xf1\xd6\xad\x12\x33\x99\xad\xd5\x0c\xa7\x38\x64\xc3\xd3\xc0\xfd\x3c\x31\x4f\xf0\x9d\x80\x65\xbd\x36\x63\xa8\x1d\x85\xc9\x7d\xf0\x44\x89\xba\xa4\x40\x43\xee\x21\x54\xfa\x5b\x8b\x97\x8a\x67\xef\x2d\x33\x38\xe8\x45\x9c\x08\xf9\x75\x85\xed\x5f\x1e\xbb\xe2\x74\xf7\xab\xc5\xe4\x75\x7f\x2c\x64\xa5\xb9\xd2\x17\x10\xc1\x08\x41\xbf\x18\x46\x99\x44\xd7\x08\x32\xd3\x9a\xbc\xb0\xab\x04\x3e\xfe\xc4\x79\xd7\xc7\x3b\x5b\xcd\xe6\x61\x10\x3b\x51\x79\x0f\xf1\x43\xec\x98\xde\xf5\x6d\xd4\x67\x2e\xe4\x4f\x75\x5a\xde\xcc\x65\xdd\x79\xeb\xd3\x5c\xa2\x09\xc4\x76\x34\xc5\x61\x6d\x13\x39\xdc\xe9\xe9\x88\xe9\xae\x28\x10\x88\x58\x63\xa5\x78\xc7\x02\x81\xed\x1c\xd2\x94\x10\x9a\xab\xce\xa6\x58\x8e\x2a\x90\xdb\x25\x1a\x86\xee\xe7\xd9\x60\xc4\xb8\xe3\xaf\xe5\xa0\xfc\xfe\x8f\x5d\x19\xd0\x52\x20\xc0\x68\xaf\x1f\x82\x78\xa8\xed\x0a\x70\xae\xa6\xb3\xf9\xb2\xc2\x38\x47\x00\xa8\x8c\xd4\xfb\x62\x10\xf0\x80\x64\x86\x2e\xc6\x03\x82\xb3\x31\x20\xf3\x4f\x25\x49\xf0\x73\xac\x3d\xf0\x67\x76\x83\xf6\x66\xc4\x0d\x72\x88\xe2\x34\xf5\x50\xac\x77\xf9\xf8\xec\x36\x74\x1c\xff\x48\x14\xb7\xe7\x7a\x33\x58\xbc\xf7\xf5\xcf\x36\x35\x73\x44\x68\x3e\x2c\x82\x8d\x4b\xda\x73\xb2\x68\xc0\xfe\xc7\x39\x08\x3f\x08\x72\x3e\xd8\xad\xaf\x8a\x85\x7a\x57\x0a\xc3\x3d\x9f\x32\x5b\xff\x8c\xd4\xb5\xc3\xa8\xcc\x25\xa7\x54\x1f\x5b\xf6\x05\xc8\xc0\xc4\xbf\x07\x6d\x9d\xca\xfe\xc8\x6c\xa7\xe6\xbb\x42\x4a\x98\xae\x4a\xba\x51\xa9\x7d\x0d\x02\x02\xbe\x89\x62\xe8\x97\x02\x7a\x19\xcc\x77\xab\x98\xc8\xc6\x69\x52\x09\x36\x05\x19\x29\x04\xd0\x93\xe5\xab\xdc\xb7\x8b\x64\x23\x1e\x7c\xa5\x1c\x58\x64\xcf\x75\xa8\xfb\xc7\xdb\xc6\x32\xc9\xda\x05\xf4\x15\x2c\xcc\x2d\x6d\x22\x6d\x3b\xa5\xdf\xa1\xda\x61\x38\xbf\xbd\xce\xbc\xc1\x7f\xb7\x1a\x16\x2e\x59\xd1\x08\x2f\xfe\xb9\x3d\xac\x71\xc0\x0c\x12\xbf\x60\xa5\x83\xff\x01\xf0\xd0\x0f\xac\x20\xdc\x86\xa1\xf2\xc2\x78\x9c\xee\x79\x3c\x4d\xea\xa6\xf4\x49\x44\x2a\x22\x86\x0d\x5d\xd0\x04\xb9\x61\xf0\x39\xc8\xff\x05\x04\x1e\x1a\x37\x66\xbd\x76\x9d\xba\x07\xfa\xa4\x28\x76\x82\x96\xf8\x47\x5b\x46\xdb\x71\xc3\x7f\x81\x8f\xe1\x02\x16\xb5\x3a\x28\x4a\x94\xa7\x1b\x6c\xae\x0c\x4a\x9c\x22\x3d\xf2\xc7\x32\x38\x23\x0e\x2b\x26\x00\xf3\xff\x34\xe7\x59\x7d\x3a\xe0\x63\xdd\x4e\x67\x4b\xe1\x83\x6a\x28\x03\x27\x94\xfd\xb5\x62\xed\x41\xb6\xfe\x9b\xe0\x3c\x49\xf9\x90\x77\x7b\x05\x4a\x7f\x66\xe9\xb9\xd8\xcb\x9c\x39\x3c\xd4\xcc\x95\x3e\xc0\x5f\xba\x46\x52\x35\x7d\xc5\x01\x34\x19\xd4\x57\xa1\x18\x66\x4d\xd9\x82\xb1\x6f\xcc\xa8\xa3\xb2\x7d\x2b\xbe\xa4\x93\x77\xcd\xac\x19\xf8\xab\xe2\xe3\x68\x26\xb5\x25\x45\x66\xc6\x91\x49\x5f\x24\xc9\x51\x6a\xb6\x4c\xdc\x68\xcf\x2c\x6e\x86\xd7\xd3\xb3\xf5\x5d\xb2\xbe\x74\xd4\x28\x9a\xfe\x0b\x85\xbf\xae\xb5\x07\x0d\x0c\x86\x98\x07\x5d\xee\x97\xcf\xd4\x3c\xb8\xb6\x39\x23\xaf\xf8\xa0\xc4\xd8\x33\x06\xe3\xbb\xd1\x43\x46\x93\x34\x4f\xd0\x7f\xd7\xfe\x80\x98\xfd\xb4\x5a\x05\x62\x04\xdb\xca\xbb\x69\xe9\xb0\xaf\xbe\xd1\x8b\x96\x27\xe1\xde\xcd\xe7\x52\xe0\x4a\xfd\x9a\xec\x78\xe4\xde\x5b\x56\x91\x5c\x4d\xa3\x7c\xcf\xf5\x69\xa3\x22\xf6\x87\x63\x87\x49\xa3\x60\x5c\x6a\xb5\xb0\xfc\xc5\x66\x71\x32\x53\x14\x4f\xa6\xfe\x87\x68\x30\x0b\x2c\x80\xda\x27\x0f\xc0\x49\xdc\x33\xf8\x43\x58\x8f\x1b\x3b\xaf\xa9\x6f\x44\x64\xb8\x26\xb9\xc2\xa2\x5b\x96\xe6\xaa\x60\xda\x21\xa1\xac\xd3\x35\x21\x9d\x89\x3f\xd0\x46\x1f\xf4\x4f\x08\x9d\xbd\x59\x0c\xcb\x58\xd7\xfa\x87\x36\x64\xdb\xc6\x5f\xdb\xfe\x5e\xee\xc1\x3c\x18\x0f\x8b\x61\xa0\xcf\x28\x57\x7a\xfe\xb8\x7c\xa0\x59\x39\xde\x22\xbb\x0f\xe5\x7a\xc4\x34\x0b\xc2\xb6\xc6\x7f\x54\xc4\xbe\x60\xfa\xf7\x84\xc6\x4b\x51\x9a\x04\x9c\xc1\xf5\x81\xf9\x84\x83\x8f\x1e\xe6\xd5\xe8\xb6\x99\x62\xae\x03\x20\x5e\x60\xea\x0e\x65\xf5\x71\x90\x99\xf8\xcf\x87\x90\x10\x99\x2d\x08\x5a\xdc\xf5\x25\x8a\x17\x5a\xb1\xe9\xdd\xe2\x97\xf0\x94\x8f\x0e\xbe\x01\xa8\xdd\x5d\xa6\xd7\xaa\x66\x03\xd5\x62\x03\x11\x4e\x59\xcc\x1d\xf6\x05\x6d\x9f\x3a\x81\x23\xe0\x0a\x6a\x3a\xeb\x5c\x87\x7d\xc0\x34\x64\x4f\x50\x49\x96\xf3\xd8\x32\x67\x6f\x00\xfb\xb1\xca\x2b\x05\x9e\x2b\xca\x45\x1c\xc5\x9f\xee\xca\xd9\xc3\xa1\x1f\x7c\xd3\xbe\x95\x58\x4b\x75\xff\xc6\xa3\xb7\x44\xdc\xb4\x54\x03\x52\x59\x37\x14\xd5\x45\xa9\xfb\x5d\xb9\x4f\xc3\xb4\xd1\xa9\xb7\xdf\x06\x3b\x0b\x8f\x12\x34\x85\x24\x40\xee\x15\x94\x06\xc1\x15\xb5\xc1\x01\x13\x5b\x7f\x93\x64\xbb\x31\x0a\xe9\x45\xb7\xa3\xfd\x12\x1b\x3c\xa0\x79\x7e\xf0\x85\x95\xac\x5a\xb5\x65\xd4\x33\xd4\x24\x9c\x27\x0c\x47\xa1\x1d\x79\x4b\xbf\x0f\x4d\x2e\x17\x24\xae\xb0\xf9\xd6\x85\x59\x11\xd0\x77\xf1\x31\xee\xf4\xda\x78\x80\x67\xd6\xa2\x87\x64\x44\xd3\x10\x56\xe7\xa7\x7b\x40\xeb\xd6\xfc\x8e\x99\x7f\xb7\x0f\x73\x06\x6c\x4f\xb6\x01\xe6\x73\x41\x55\x5e\xd8\x04\x71\x1c\xf7\xf7\x83\x08\x23\xab\xc6\x3f\x50\xce\xec\xf5\x3f\x30\x62\x5d\x61\xd2\xf7\x69\xc7\x59\x52\xde\x9d\x89\x42\x01\xd6\xc0\x4e\x2b\xc4\x64\x91\x52\xcd\xe2\xf1\x60\xfe\x0c\x15\xe4\xac\x6e\x44\x96\xcd\xf0\x26\x50\x96\x86\xb6\x72\x20\x57\x50\x4f\xd6\x60\xf4\x7f\x6d\xdf\x92\xc0\xab\x02\x08\x1b\x3b\xaf\xdd\x94\xff\xc8\x99\xc6\x9a\xb8\xea\xca\xf8\x25\xb6\x58\xd8\x17\x54\xe3\x08\x69\x61\x29\x5b\x1a\x74\x96\xb0\x5c\x85\x22\x92\x8c\x38\x52\x65\x68\x16\x08\x6e\x6e\x57\x39\xcb\xf4\x98\x53\xe3\x28\x8b\x82\x16\xf3\xa4\x6d\xbc\xa0\xde\x0b\x24\xb5\xce\xb0\xc3\xcb\x74\xbc\xb1\xf1\xea\x28\x0c\x51\x8e\xfc\xe2\x1f\x0d\xb1\xef\x87\x8d\x04\xb0\x9a\x9a\xd7\x7f\x52\x23\x46\x83\x56\xa4\x18\xec\x95\x2d\x04\x76\x70\xbb\x24\x06\xef\x25\x3b\xfc\x4d\x6c\xe0\xc8\xba\xd1\x4e\xcb\xdf\xf0\xe8\x24\xf2\x5a\xc9\xed\x20\x81\x24\x3f\x93\xc0\x2b\xc5\x30\x72\x3f\xa3\xdb\x3d\x0a\xc0\x9b\x42\x46\x73\xd4\x78\xbb\x85\x0a\x1b\xae\x87\x81\x1e\x78\x42\xaa\x45\x46\x3d\x9b\xd9\x00\xe8\x97\xe1\xce\x07\x3e\x6b\xe2\xd0\xa0\xc3\xdb\x74\x84\x44\x65\x17\xc9\x49\x28\x27\x53\xd8\xbf\x92\x09\x78\xa4\x42\x09\x27\x00\xbe\xb2\x26\x13\xc9\xcb\x2c\xa4\xa5\xac\xeb\x97\x86\x70\xc3\x3c\xfe\xdc\xed\xbb\x69\x2d\x2b\xce\x63\x4f\x90\xb7\xb9\x63\xe9\x1e\xff\x35\xae\x0f\x68\xdc\x74\x1d\xb3\x6e\xb1\x1a\xb7\x79\x0b\xce\x60\x4d\xc8\x7e\x74\xf0\xac\x35\x36\x10\x4a\xea\x7d\xe2\x0d\x16\xcf\x2a\x25\xb2\xdf\x67\xd6\x17\x86\xf7\x53\xa2\x20\xd8\x71\xd3\x16\xf9\x4c\x1d\x55\xb8\x9e\xc0\xb2\xae\xbf\x18\x07\xdb\x37\xb2\x44\xf2\x78\xc7\x1e\xcd\xab\x0d\x8e\x7f\xe3\x16\x32\x2c\xb9\x40\xad\x42\x5d\x3b\x92\x85\xc8\x08\x23\xa9\xd6\x30\x43\x78\xb7\x9a\x40\x17\x9b\x82\xcb\x63\x78\x88\x71\x28\x8a\x30\xb4\xd5\x19\xcd\x89\xcf\xe8\xef\x95\xab\x8b\x0f\x1f\xc3\x29\x77\xec\xda\xe4\x14\x82\x71\xcf\xfe\x26\xd0\x9c\xb9\x39\x5c\x89\x0b\x87\xec\x91\xde\xce\xa2\x76\x59\x4f\xd0\x34\x42\x00\x9c\x3c\x36\xba\x8c\x5b\xf1\xca\x9e\x9d\x86\x40\x6f\x67\x59\x8f\x90\xd7\xc6\x00\xf3\xe8\xc4\x7d\x1e\x68\x87\x15\xe9\x84\x39\x68\x7a\xea\x06\xfb\x44\x7e\x2f\x9a\x8b\x46\x27\x3e\x99\xb6\xa3\x9d\x83\x98\x5a\xda\x44\x5d\xee\xb5\xaa\x99\xf5\x2a\x87\xd1\xd0\x9d\x02\xaa\xac\x21\x2b\x28\x42\x78\x32\x05\xe9\xa2\xa6\x43\x5e\x54\x3f\x64\x2d\x0a\x16\x3c\xfc\x24\x5b\xda\x32\x5b\x6a\xe8\xa5\xf0\x64\xbb\x38\xc6\x9d\x95\x72\xed\xf7\xb3\x73\x14\x7b\xfd\xa3\xc0\x95\x3d\x85\x91\x32\xe4\x50", 4096);
	syscall(__NR_write, r[0], 0x20000040ul, 0x1000ul);
	return 0;
}