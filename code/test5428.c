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
	res = syscall(__NR_socket, 2ul, 2ul, 0);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000240, "\xef\xce\x00\x79\xa6\x99\xe9\xf5\x67\x36\xcb\x9a\x7b\xb5\xf1\xb2\x9d\xb2\x1b\xbf\x20\xa2\x98\x0b\x0a\x79\x08\x07\x5d\x31\x54\x1e\xbf\x7c\x19\x2d\x21\x83\x35\xca\xbe\xc9\x73\x2c\xfb\xee\xe3\xbe\x8f\xee\xce\x24\x24\x24\x34\x7a\xd8\x40\x4b\xb6\xef\x99\x71\x37\xc5\x55\xb0\x7a\x38\x60\xc4\x09\x02\x1f\x7a\x97\x40\x93\x25\x2c\x93\xe7\x60\xda\x04\x9c\xed\xdf\x9c\xef\xd4\xe3\xf3\x27\x92\x9d\x79\xb8\xb8\x26\x81\x71\x22\xd9\x5b\xcf\xfa\x71\x37\x11\x59\x53\xbd\x55\xff\xc5\xd0\xe0\x9e\x76\xd9\xbe\x13\xd3\x00\x99\xed\x39\x79\x2b\xe4\x15\xe4\xf4\x8f\x55\xbd\xb5\x2c\x84\x85\x80\x44\xf1\xdd\xb9\x81\x5d\x0a\x23\xaf\x81\xc6\x68\x89\x23\x1e\xaf\xb1\x5b\xcd\xa8\x9d\x34\xc9\x28\xf7\x20\x3a\x4a\x05\x4b\x06\xf1\x47\xf3\xbc\xc6\x6a\x91\xad\x08\x1d\x73\x08\xf1\xe4\x1d\x8b\x11\x2d\xdf\x88\x58\xd5\x68\xb1\xaf\x21\xd6\x7e\x31\x40\x13\x63\xe7\x4d\xb9\x63\x8c\x5f\x44\x2d\x95\x9d\xd9\x2d\xd6\x49\x0e\xd1\x30\x31\x8b\x0b\x94\xf4\x48\x4e\x3b\x76\xf9\xfe\x3d\xa8\xfa\x70\xb8\x15\xab\xf6\xd3\xb3\x7e\x1b\xb6\x49\xa4\x14\x6f\x67\xf9\x2e\xd0\x37\x0d\x8c\x60\x61\x0f\xc2\x8d\xdf\xc7\x54\xfe\x91\x7d\x8d\xc5\x8b\x39\x1a\xd5\xbf\xae\xf8\x23\x6b\x23\xc0\x7c\xdf\xf1\x2e\xdb\xc5\xfe\xa5\x3b\x93\x5d\xff\x7b\xa0\x22\xe6\xb7\xc8\xb4\xc1\x4e\xb5\xef\xb8\xea\xb2\x72\xf7\xe0\xa6\x5e\xa4\xee\x33\x38\x00\x64\xbc\x21\xd6\xaa\x1e\x63\x2b\xef\x96\xcf\xd3\xdc\xe4\x5b\xe4\x19\xaa\x48\x73\x61\xa3\x96\x26\x3a\x17\x29\xc3\x12\x8f\x1e\x4f\xe5\xbf\x55\xf9\x3b\x4f\x5a\x39\xc3\x12\x56\xaf\xf6\x00\xac\xa4\xa0\xd3\x75\x12\x77\x1c\x6b\xe4\x58\xa0\x55\x8e\x6c\xa4\xaf\xcc\x40\xef\x9e\x59\x4c\xec\xfc\x99\xa3\x15\xfa\x31\xe8\x0e\xb6\xd1\xf4\x61\xcb\xe6\x14\xd8\x74\x19\xed\xda\xe8\x11\xce\x31\x0c\x87\xe1\x03\xd7\x0f\xf8\x03\x62\xc7\x6b\xe3\x46\xaa\x71\x51\x4f\x29\x98\x9a\x33\xef\xfb\x38\x52\xb4\x7f\x66\xc4\x05\xc8\xb7\xbf\xdf\xeb\x5d\x25\xf4\x2b\x0e\x88\x56\x6b\x79\x11\xee\xc7\x5c\x6b\xc2\x30\xd0\xc3\xae\x91\x8a\x6c\xc5\xcc\x75\x0f\xbf\x6c\x7b\x85\xd1\x1b\xfe\xed\x51\x61\xd2\x09\x1b\xb5\x3c\x5e\x20\x6a\xe2\xbf\xd7\x35\x4d\x33\xa7\xae\x7b\xba\xa7\x29\xe2\x28\xb8\xab\x5d\x0c\xc4\x1d\x4b\xce\x0a\x7d\xa3\x3f\xf5\x64\x57\xea\xd7\x94\x52\x44\xb0\x8d\xf2\xad\x2c\x10\xfa\x40\x1d\x83\x18\x48\x8e\x0f\x19\x6e\x01\xdd\x32\x9a\xc7\x44\xf1\x92\xeb\x73\x47\x27\x87\x15\xab\x3c\x09\xdc\x0b\x0a\x03\x57\x57\x80\xf6\x1e\xab\xd1\xe2\x5a\x3a\x34\xc5\x2d\x22\x2a\xb2\xf5\x47\x79\x74\x38\xdb\xe2\x85\xb8\xef\xf5\xee\x79\xc6\xea\x8b\x4a\x15\x7c\xe5\x3a\x84\x0a\xb4\x89\x5b\x41\x06\x38\x00\x9a\x16\x74\xda\x49\x2f\x10\x2f\x7f\x5f\x8e\xad\x0a\xd3\x40\x97\x5d\x08\x14\xfb\x6f\xfd\xd2\xce\x1c\xcf\xb8\xfe\x5d\xdd\xf9\xbe\x92\xf1\x2c\xa4\x3e\xef\x19\x22\x5e\x1e\x02\x98\xa0\x9e\xb0\xfe\x7e\x8c\x28\x71\x10\x21\xce\x1e\xee\x3a\x7d\x9e\xfd\x50\x43\x2c\x27\x20\x96\x8e\x11\xd5\xdd\xf6\xdd\x07\x8c\x66\x72\xa0\xad\x0d\x96\xbe\x6f\xd3\x07\xfe\xb5\x4a\x80\x35\x7e\x55\x45\x77\xbc\x36\x14\xec\xa8\x22\xba\xc3\xd7\x59\xc2\x93\x00\x3a\xef\xd0\x38\x3e\x1b\x7a\xf3\xf1\xdf\x68\xf5\xe2\x52\xcf\x02\x9b\x5d\x04\xb0\x69\x49\xef\x92\xa6\x6e\x61\x54\x21\x33\xc5\xec\xf1\x01\x05\x15\x0c\xdc\xa7\xd3\xbe\xdd\x2c\xca\x37\x03\xc6\xa9\x8e\x01\x6f\x88\x90\x1a\xdb\x45\xe3\x45\xe2\x9f\x49\x1d\x73\xbe\xf7\x64\xfd\x0c\x10\x08\x94\x75\x0e\x51\x47\x12\xd7\x5f\xdc\xbb\xb2\xde\x55\xde\x6d\x7b\x06\x02\x79\xab\xef\x3f\x59\x96\x79\xce\x22\x7d\x55\x4f\x97\x96\x27\x27\x89\x1f\x28\x89\x4c\x74\xfd\xd0\x24\x7c\x6c\x3b\x67\x16\x9e\xf7\x9f\xa6\xbb\x6d\x17\xa9\x0e\x8b\x55\xab\xed\xda\xd9\x19\xfd\x65\x74\x63\x2f\xbe\xdd\xef\x51\xec\xb1\x1e\xc5\x26\x86\x52\x4a\xec\x59\xd7\x09\xc5\x01\xd9\x08\x46\x07\xe9\x07\x92\x72\x1a\x6f\xd6\x23\xd3\x6d\x9a\x34\xf0\xfc\x3f\x80\xdb\xe6\x99\x3f\x3c\x98\x9b\x71\xfb\xea\x9d\xf4\xb5\xd4\x98\x6c\xbf\xab\x93\xe9\x76\x7d\xa4\x9f\x9c\x1f\x95\x78\xc7\x4c\x52\x3a\x99\x05\x5b\xd2\xd4\x29\xaa\x8b\x9c\xff\xb8\x9d\xf1\xca\x1e\xd8\x82\x17\xfa\x8c\x9f\x88\xc3\x2d\xb5\x4b\xed\x06\xba\xf0\x97\xaa\xb5\x57\x5f\x03\x07\xd2\x0d\xca\x0d\xcb\x10\x0b\xf9\x76\x35\x2b\xf9\xe5\x4a\x31\x48\x8b\x08\x13\x07\x12\x64\x2c\xe7\x2e\x38\xaf\x06\x2f\xbf\xd6\x98\x68\x66\xf0\x8a\x82\x7e\xef\x13\x3a\xdd\xb9\x6d\x52\x66\x7b\x4f\x5e\xc8\x07\xbf\x5c\x3c\x3d\x33\x01\xf6\xf9\x78\xe3\x08\xed\x1c\xd5\xaa\x36\x86\x48\x10\x10\xe1\x74\x18\xf9\xb7\x99\x09\xbb\x80\x16\x14\x98\x97\xc4\x49\x63\x4f\xe5\x2a\x7e\xd6\x4f\x5b\x31\x04\x33\xa2\xfe\x65\xbd\xc0\x24\xc5\x27\x38\x26\x74\x0e\x25\xa1\x1b\x0d\x90\x6e\x3f\x77\x64\x4e\x19\x02\xf5\x54\xf4\x98\x54\x3c\xe8\xf7\xf9\x31\xa4\xd5\x65\xe7\x6c\xdf\xdf\x90\xfb\xb1\xba\x6e\x0f\xc5\x1a\xb2\x47\xcf\x9e\x95\xd0\x55\x6c\x97\x19\xc8\x38\xa9\xe4\x97\xa1\xa5\x69\xc7\x86\xa8\xb4\x84\xa4\x31\x61\xac\xb8\xd3\xb3\x63\x44\x2c\x77\x5b\x22\x0d\x90\xe9\x22\xb4\x09\xc7\x39\x2d\x39\x5f\x61\x69\x0f\x46\xb4\xc1\xbb\x05\xa7\x7c\x89\xb7\xf1\xa3\x42\x94\xf0\x1c\x68\x19\x96\x6e\xd7\x10\x0f\xcd\x32\xed\xce\xbd\x9b\x6c\xc5\x1d\x13\xd4\xfa\x77\xfe\x7f\x3c\x47\x28\x12\xcb\x45\x5d\x1f\x3f\x26\x71\xd6\x84\xc2\x51\x7b\x26\x60\xdf\xbb\x17\x94\xa2\x14\x63\x0d\x5c\xc5\x7b\x6c\x66\x48\x9d\xa2\x7e\xf6\xee\xbc\x0b\x1c\xcd\x7d\xc8\xe0\x9a\x2d\xda\xb2\x74\x92\x08\xf3\xa3\xdd\x23\x75\x2f\x47\x03\x20\x35\xc2\x4b\xe9\xc7\xd8\x4d\xb7\x2e\x3e\x63\xc0\xd9\x77\x11\x58\xa1\x6c\x2a\x90\xd9\xdb\x09\xb1\x7e\x8d\x9c\xe6\xec\xd9\xdc\x9c\x53\x19\x45\xbf\x67\x68\x99\x26\xf0\x9f\xab\x8b\xa8\xb2\x34\x3b\x93\x90\x46\x60\xc9\x5d\x70\x73\xcf\x1d\xa7\x28\x38\xce\x5b\x6f\x1d\x0b\xf7\x4f\x1f\x1a\x4f\x0f\x8d\x76\xab\xf8\x25\x82\x66\x5b\x9f\x13\xf4\xc8\xc2\x96\x2b\x25\x78\x6f\x91\xae\xb3\xff\xd0\x94\x99\x97\x13\x05\xf3\xf7\x59\x0a\xa5\x30\xe4\xbc\xb6\xd6\x5d\x6e\x0c\x68\xae\x16\x6d\xe1\xff\x83\x42\xd5\x4a\x54\xa8\x5f\x94\xe6\x19\xbb\x08\x8f\x4c\xd0\x94\x25\xd8\x40\x3d\x59\xa5\xf2\xec\x7b\x9e\xe6\x85\x70\x36\x82\x86\x3f\x19\x33\xd9\xb5\xdd\xf0\x1c\xb6\xb4\xb8\x87\x5f\x0c\x9f\x0a\x58\x5e\xd0\x54\x61\xe8\x80\x91\x98\x93\x29\xbf\x8b\x29\x23\xe8\xc5\x1e\x07\x42\x39\x34\x96\xd8\xd5\x31\x40\x7d\x62\x65\xbb\xba\x0d\xc6\xe7\xbb\x01\xe0\x28\x4d\xd1\xb2\xea\xc9\xea\x30\x5b\x0d\x4e\x99\x1d\x90\x4a\x78\x17\x30\x36\xd8\x5d\xcb\x97\x82\x0f\x67\x71\x2d\x32\x04\x78\x37\x36\x7a\xf7\xf9\x6c\x69\xa6\xc8\x78\x88\x17\x35\x2b\x55\xa7\x8e\xc9\x68\x65\xd5\x50\x02\x73\x1e\x34\x3e\x9c\xdc\x1a\x5b\xc7\x15\xcb\x66\x98\x99\xfc\x0f\x9e\x24\x61\xde\xa9\x89\x03\x68\x0d\x4c\x76\x77\xc9\xf6\x92\x37\x48\x69\x5c\xf2\x03\x3d\x1e\x15\x60\x13\xa2\x25\xc9\xa3\x0d\x09\xdc\x69\x1d\xc0\xf8\x2a\xf8\x71\xb9\x56\xb6\x7e\x44\x46\x8d\x07\x7b\x8b\xc3\x42\xbb\xa5\x18\xa8\xb0\x3c\x3f\xe1\xc0\x9b\x05\x3a\x30\xff\x26\x4a\x0f\xe6\x26\xdf\x11\xe8\xaf\x04\xe5\x4b\xb3\x4d\xd2\x81\x2f\xe8\x91\xa1\xc8\xcd\x59\xb5\x73\x5c\x0d\xd1\xcc\x99\x0a\xfe\x6c\xda\x62\xf7\xc1\x06\x8e\xf2\x3c\x1f\x6e\x7e\xee\xdd\xc6\x10\x24\x7a\x09\x3f\xc3\xeb\x5e\xec\x40\x24\xdd\x4a\x69\xa0\x33\x0e\x23\x1f\xf0\x57\xdd\x74\xe0\x58\x0b\xb0\xad\x9f\x64\x0d\xbe\x96\xab\x91\xac\xe1\x35\x40\x69\x24\x1c\x68\x80\x05\xce\xbb\x7c\xb3\x00\x37\x5f\x94\x47\xc7\x4e\x92\x8c\x55\xf7\x80\xff\x08\x9f\x1b\x25\xd5\xa3\x34\x2d\xcd\x5c\xeb\x7b\x66\x76\x6b\x02\x96\xe9\xf9\x7f\x83\xf3\xb6\xaa\x7e\x5c\xa6\x4a\xef\xd4\x7a\x67\x6e\x6d\x1c\x91\x07\xc5\x22\x4c\x81\xd5\x77\xef\x72\x52\x44\x68\x47\xed\x4c\x8c\xd6\xa1\x9f\x67\x91\x65\xe2\x46\x7d\x2f\xb9\xb4\x71\x10\x22\x52\x2f\x79\xbb\x77\xbf\x46\xc4\xf6\xe2\xff\xd4\xac\x61\x11\x40\x51\x21\x0c\x5a\x77\x87\x20\xe5\x28\xa0\x60\x10\x97\x7b\x4b\xe5\x4c\x74\xa9\xee\xe7\x22\xa7\x34\xbe\x4c\xfb\x8c\x47\x0d\x5d\xa8\x48\x18\x0a\x98\xdf\x32\x79\x6d\x70\x67\xa1\x35\x09\x56\xa6\x7f\xe8\x13\xae\xb5\x35\x14\x3f\x37\x1e\x96\x18\x72\x21\x3f\x7c\x0e\x94\xb7\xe6\x99\xc8\x8e\xd8\xf7\x3f\x60\x16\x82\xe7\xef\x01\x09\x4d\xde\x78\x4d\x49\xe7\xb8\x89\xfa\x08\xa5\x52\x75\x44\x27\xad\x8a\xe0\x67\x1f\x3d\xaf\xb9\x33\x91\x10\xb0\x26\x16\x8c\x01\x73\x97\x93\xcb\x01\xa3\x4d\xaf\x41\x27\x78\xb2\xff\xc5\x4f\xa7\x23\x80\x98\x4a\x27\xe6\xec\x23\x2d\x48\xaf\x41\xe9\x41\xb9\xc0\x4e\x5d\x32\xad\x67\x02\xd5\x99\x62\xbe\x66\x4f\xc0\x94\x2d\xcf\x54\xc1\xd1\x09\x1b\x72\xe3\xf4\x69\xf4\xb0\x01\x18\x18\xd3\xaf\x73\x0d\x0a\xdd\x90\x78\x04\x7d\x24\xef\xfb\x62\x5f\x2f\x16\x75\x80\x1b\xa8\x18\x78\x7e\x82\x76\xbc\x80\x62\x80\x31\x74\x92\xe3\xb9\x8e\xa5\x5c\x33\xf4\x04\x24\x4f\x93\xc5\x8e\xba\x00\xd7\xa5\xef\xa2\xd0\x21\xf9\xfb\x01\x5e\xc5\x93\xa5\x27\x0b\xcb\xc7\x53\x8c\x57\xe4\x35\x71\xf3\xc8\x79\xe5\x73\xde\x10\x58\x78\x40\x9b\x34\x0b\x17\x4e\x81\xfd\xb1\xf3\xdd\x9c\xcc\x14\x40\x51\x0e\xc7\xcd\xfa\x5e\xe8\xf3\x15\x79\x68\x49\x33\xfa\x52\x4a\xd9\x82\xab\xa7\xf3\x9b\x0d\xc7\x7f\x31\x9a\xbf\x65\xf5\x25\x59\x57\xdf\x90\x6d\x10\xb9\x45\x3c\x9c\x58\x69\xaf\xe8\x67\x61\x0d\x9f\xaf\x1e\x1f\x07\x00\x48\xd9\x0b\xdd\xa2\x08\x9f\x84\x6b\x69\x74\x94\x5e\xb0\x4c\x31\x93\x01\xf5\x90\xa3\xa3\x5d\xd8\xf9\x12\x92\x85\x13\x62\xe7\xf6\x67\x7b\xb6\x57\x33\x2e\x00\xc4\xfe\x38\x89\xbd\xad\x84\xa0\x8e\x1d\x85\x35\x9e\xc3\x5c\x58\x5b\xb3\xbe\x30\xf3\xf6\x1e\x33\x90\xbd\xc3\x73\x5c\xa4\x65\xbf\x6c\xbe\x40\x07\x40\xdb\x6a\x66\x3c\x3d\x62\xd0\x97\x29\x62\x0e\x08\x4b\x47\x23\x72\xb8\xe7\x98\x6c\x19\xd3\x46\x14\xbe\x49\x67\xa4\xb1\x02\x0e\x66\xae\xff\x3d\x53\x72\xd1\xe8\xcc\x99\x68\xc5\x01\x82\xce\xb2\x23\xd2\x1c\x4d\x70\x01\x9f\x96\x07\xf7\xba\x44\x5e\x7a\x50\x3d\xf5\x26\x9a\xfb\x25\xe7\xdc\x63\xdd\x6f\xb6\xe0\x5e\xac\xe9\xd2\xa8\xa0\x07\xd9\x7f\xfc\x39\xa8\xd5\x5c\x2f\x00\x40\x65\xf3\xc7\xbe\x6d\x51\x80\x4f\xb2\x57\x3a\x65\x25\x7b\x2d\x14\xab\xf5\xc6\x48\x7b\x53\xc4\xb6\x79\x7c\x39\x41\x5a\x06\x3b\x6b\x5f\x10\x60\x17\x5c\xc0\x0a\xae\x4b\x7c\x4f\x5a\x9d\x6f\x44\x13\x37\x16\xd6\x3b\x08\x46\x50\xed\x15\x93\x72\x72\x1f\xb2\x38\x07\x75\xba\xb9\x46\x9f\x3d\xae\xb9\xbd\x59\x48\x54\xa9\x8a\x31\xb8\x39\x8d\xa0\x44\x2c\x1c\x44\xb1\x59\xac\xcd\x01\x3a\xb0\x2c\x18\x20\x16\x7f\xaf\xd2\x70\x4f\x81\xbc\xbf\x99\x52\xa1\x98\xeb\x9e\x59\x18\xca\x86\xd4\xaf\xd2\x58\x8b\x0b\x88\x15\x76\xcc\x44\xbe\xe8\x91\x8d\xdd\x6b\x60\xd6\x90\xe5\x4f\x9e\x5e\x8c\xf1\x7b\xfc\x50\x46\x46\xe7\x66\xf5\x9c\xaa\x26\xfd\xb8\xae\x0b\x33\xc4\xfa\x90\xbd\x14\xd7\x72\xde\x31\xe1\x46\xf3\xd7\xb2\x93\xc2\xfc\xd8\xde\xe0\x7f\x83\x4e\x6f\x22\x4c\xd5\x06\xf1\xa8\x8e\x68\xc2\x24\x8b\x32\x36\x24\x7b\x05\xc5\x11\xba\x62\xba\xfe\x9d\xb8\x52\x0d\xf6\x26\x47\x35\x13\x39\xdf\xa4\x73\xb0\x81\xa2\xff\x2b\x78\x76\x28\x99\x5b\xb3\x96\x69\xaf\x18\x72\xa5\xec\x45\x49\x1e\x32\xf6\x5d\x3f\x9f\xe4\x19\xa7\x32\x45\x4c\xce\xc8\x86\x0a\xb7\x66\x22\x47\xee\xa3\x92\xf6\xfd\x3a\x86\xe6\xff\x0e\x42\x37\x1b\x95\x4f\x00\xf9\x20\x97\x13\x2f\x22\x8a\x6b\x24\x3b\x2f\xce\x1a\x2c\x2f\x2c\xc4\xc9\x76\xbc\x89\x5e\xa1\x46\xf2\x80\xb7\x66\x4a\x01\x9d\xcb\x8e\x26\xd6\x98\x78\x69\x22\x26\xca\xfe\xc5\x16\x1d\xd2\xc4\x45\xac\xa9\xba\xf4\x97\xec\xad\x21\x09\x98\x96\xc2\xb2\x78\xc7\xc2\x76\x91\x5e\x36\x41\x0d\xd0\xb3\xb8\x5a\xa7\x1a\x3c\x30\x58\xc3\x05\x55\xf3\xd0\x83\x01\x79\x23\x4c\x74\x47\xe6\xae\x8e\x3d\x70\x98\x56\x1a\xe4\xdd\x88\x9d\x02\xba\x71\x8c\x2f\x3e\x64\xff\xdf\xab\x27\x91\x53\xcf\x0e\xba\x4c\xa0\x84\xf0\x5e\xa9\xc7\x97\x09\xc2\x14\x39\x84\x5e\xfb\xe3\x58\x64\x80\x38\x1d\xf1\xe6\xa0\x55\xa7\x25\xd6\x54\x76\xaf\xe1\xe7\xc3\x55\x22\x5e\xf4\x9a\x25\x07\x30\x6d\x32\xf6\x7a\xdf\x7a\xbb\x51\xd0\x79\xba\x33\x46\x68\x41\x53\x75\xdd\x34\x9b\xa0\xb5\x4d\xca\x96\x94\x4c\xec\x41\xbc\x36\x1d\xb8\x4a\x87\x62\xfc\x2c\x8d\x70\xba\xee\x2d\x9e\x7c\x50\x45\x80\xe4\xf4\xba\xb4\xc7\xfd\x2a\xa8\x4e\x44\xfe\x58\x86\x2c\x34\x59\x8c\x51\xd1\xc9\xfa\x6d\xdc\xe5\x01\x90\xab\x09\x8a\xf1\x36\x65\x80\x7a\x4f\x7f\xe3\x70\xa7\x1c\x66\xf1\xe8\x18\xc0\xb2\x69\x6a\x60\x5b\x79\x8f\x69\x53\x5a\x2c\x14\xcc\x8c\x9f\xc0\x47\x52\x0f\x60\xcf\x96\x50\x83\x94\x5c\x54\xf0\xd4\x97\x94\x1b\xae\xfe\xde\xe7\x9b\x92\x09\xf9\x60\x40\xdd\xfa\x78\x71\xaa\xa8\x7c\xed\x08\x84\x4d\x70\x93\x9d\x50\xfe\x89\xa7\x6d\x7c\xf6\x7c\x7e\xae\x17\x54\x49\xc1\xcd\x16\xe9\xe6\xca\xde\xf4\xc5\xc2\xf2\xde\xba\x8a\x34\xff\xb0\xb6\x91\xbf\x28\xed\x1e\x80\x23\x48\x50\xdb\x4e\x8a\x4d\xd1\x47\x94\x3a\x7a\xf6", 2909);
*(uint16_t*)0x200000c0 = 2;
*(uint16_t*)0x200000c2 = htobe16(0x4e21);
*(uint8_t*)0x200000c4 = 0xac;
*(uint8_t*)0x200000c5 = 0x14;
*(uint8_t*)0x200000c6 = 0x14;
*(uint8_t*)0x200000c7 = 0xaa;
	syscall(__NR_sendto, r[0], 0x20000240ul, 0xb5dul, 0ul, 0x200000c0ul, 0x10ul);
	return 0;
}
