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
	res = syscall(__NR_pipe, 0x20000080ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000080;
r[1] = *(uint32_t*)0x20000084;
	}
memcpy((void*)0x20003100, "\xed\x82\xaf\xef\xaf\x85\x4b\x3b\xe6\xc2\xd0\xe4\xa0\xbb\x07\x26\x0e\x6a\x29\xab\xe7\x2c\xd0\xb4\x74\x86\x8d\xbd\x75\x07\xc3\x44\xec\xd6\xe3\x84\x81\xfc\xd2\x3d\x2f\xd7\xb0\x59\xeb\x75\x15\x9f\xb2\x08\xb5\x7f\x11\x13\xf0\xa9\xd4\xa7\xe5\xed\xe6\xb5\x5f\x13\xb8\xcd\x3c\xf9\xb4\xcd\xc2\x3e\xc5\x20\xd8\x5f\xf0\x20\x34\x0d\x2a\x30\x59\x1a\x8c\x74\xd1\xc2\x6c\x9d\x86\x84\xff\x7c\x50\x28\xde\x63\xd7\x63\xa5\xfa\x84\x10\xc9\xa2\x56\xcf\x75\xde\x7d\x07\xef\xb0\x62\x04\x8b\x06\xa2\xfc\x8b\x0f\xfe\xab\xb8\x5f\x43\x13\x82\xa9\x5f\x25\x54\xb5\x03\xb4\xbe\xb7\x51\x14\x89\x6f\x7f\xbf\x52\xa7\x01\x7d\x0b\x46\x02\x0c\xbd\x26\x51\x8f\xf0\x65\x51\x49\x3d\x04\x96\xe2\xc6\xed\xe8\xb5\x24\x96\xae\x96\xf3\x38\xc3\x5d\x4f\x39\x88\x45\xcc\x3b\xe3\xe9\x60\x42\x09\x4b\xd7\xff\xa8\x21\x6f\x04\xd8\xcf\x69\x6c\x54\xf2\x08\xaa\x28\x2c\xb3\x0d\x0e\xd8\x93\xb7\x79\x6d\x48\xc6\x85\x43\x0f\x07\xe9\xcd\x57\xe4\xa0\x57\x45\xbf\xaf\xf2\x4f\x54\xb8\xa4\x48\x26\x56\xd7\x5c\x79\x5d\x77\x49\x2b\x4a\xe8\x8f\x6d\xa6\xea\x68\x12\x49\x71\x27\xcd\x8d\x52\x9a\x66\x18\xc6\x9f\xdd\x60\xfd\x1f\x9a\x78\x23\xee\x0b\x84\xa4\x9a\x66\x3f\xc1\x94\xab\x25\x54\x6e\xab\xcc\x74\x5b\x5e\x48\x58\x1d\xc3\x8a\xce\x1a\x43\x99\x12\xfa\x15\xa6\x68\xa8\xbb\x6e\xf5\xc3\x0d\xd1\x55\xb1\x56\x0d\x14\xd6\x2d\x05\x77\xb8\x9f\xbb\xc0\x12\x06\x14\x20\xa2\x38\xa7\x1f\x18\x9d\xea\x1c\x29\x36\x62\x8a\x4f\x2e\xd2\x1e\x9b\x46\x30\x47\x49\x4a\xab\x09\xd2\xee\x5e\x4f\xc7\x7e\x5e\xf4\x39\x09\x31\xcc\x76\x26\xc0\x81\x3e\x2b\x5b\x99\xb0\x20\xfb\x5f\xb9\xaf\xc1\x7c\x41\x42\x36\xf4\xc3\xdd\x3b\x35\x32\xe4\x18\xd5\x2f\xcd\x30\x37\x4d\x6e\x6b\xc0\xb2\xc3\x05\x9a\x5c\xde\xc6\xa0\x35\xbe\x2d\x9f\x35\x9d\xc7\xe3\x52\x67\x1f\x08\x89\xfb\xad\xde\x22\xfc\x72\x53\x02\x65\xce\x8b\xde\x9b\xb7\xbf\x7f\x56\x0a\x2d\x21\x05\x9b\xd5\x0b\x65\x8f\xb8\xcd\x13\x21\x75\x56\x08\x42\x3a\xaa\xd1\xcb\xd4\x78\xe6\xcc\x43\x24\x08\x21\xbe\x99\x62\xa3\x1d\x61\xb5\xac\x19\xa6\xce\x68\xbc\x94\xff\xff\x83\x2b\xac\x4a\x8d\x78\x40\x75\xac\x22\xc5\xdd\xa6\x56\xee\x48\x42\x5c\x61\xbd\xce\x04\xbf\x53\xf6\x8d\xff\xc4\x1f\xab\xd4\xf3\xa5\xcd\x74\xa8\xd2\x65\xc7\xec\x5f\xe4\x54\x82\xf2\x58\x4b\x84\xa8\x76\x5e\xcf\x20\x54\xcf\x54\xcd\x62\xe8\xa7\x04\x63\xcd\xa8\x91\x70\x77\xf7\x53\xf0\x83\x52\x63\x58\x24\xd3\x9e\x66\x98\x1f\x60\x4e\x0d\x51\xc6\xf1\xa1\x44\xf7\xc4\x7d\xd2\xd6\xf1\x98\x6e\xf3\x61\xce\x5f\xcb\x26\xf6\x58\xa0\xe4\x0a\x4b\xa7\xc2\xfe\xb7\x43\x6f\x73\x87\xc9\xd9\xcc\xfc\x19\x92\x86\x43\x5e\xa0\x7f\x01\x4f\x0d\xff\x1d\x81\xa3\xe6\x81\x16\x09\x19\x2e\x4c\xc5\xd9\x15\x6c\xba\xf0\x29\x45\x21\x09\xbd\xa5\x53\x03\xe3\x35\x89\x01\x6f\x48\x70\x93\xa4\x7c\x5c\x8c\xec\xf0\x53\xf1\x9c\x21\x69\xd9\x7d\xed\x3d\xe7\x63\x2a\xe8\x1f\xab\x05\xdf\x32\x5c\x51\x76\x12\xd7\xbd\x67\x99\xd7\x7a\x6e\xf7\xfd\xf3\xc0\x0e\xfd\xb7\x04\x87\x75\x4a\x38\xe2\x16\x3a\x52\xf3\xbe\xde\xf1\x88\xe9\xcd\x07\x2e\xc3\x95\x22\x56\xb9\xaf\x28\xa5\x16\x64\x77\x61\x35\x05\x97\x4b\x1a\x10\x25\xb8\x0c\xce\x40\x4d\xce\x57\xe4\x77\x92\x85\xa2\x68\x1b\xa4\x68\xf8\x87\xf7\xd2\x65\x69\x6b\xd1\xf8\xe3\xf2\x2b\x14\xbf\x51\x2a\x2c\x29\x55\xd3\x7a\x4c\x33\xd2\x74\x55\xce\x0c\xa7\x37\x86\x46\xf2\x43\x83\xbb\xed\x74\x78\x8d\x3b\x95\xb8\x57\x6f\x32\x43\xde\x56\xb9\x75\x0d\x48\xb1\x4d\xa2\xee\xa0\x59\xf2\x01\x6d\xf4\xac\x4f\x2d\x39\x8c\xa9\xc1\x5d\x78\x8a\x14\x5a\x12\x71\xa6\x3c\x49\xe9\xe4\x3f\x1a\x76\x2a\x83\x06\xef\x65\x1f\xfe\x00\xa0\x1a\xaa\x46\x8d\x1e\x1a\x55\x2f\x50\x4e\x10\xb8\x2e\xab\xb6\xef\x39\xcc\xe1\xc1\xb3\x2e\x7b\x73\x74\x50\x51\x51\xaa\x88\x3a\x26\xa7\x3a\xca\x1c\xb4\x0a\xaa\x32\x69\x24\x24\x9b\xb5\x4d\xc1\xb2\x2d\x67\x3a\xf0\xc2\xd6\x8e\x8a\xab\x0e\x32\x32\x2f\x45\xbf\x44\x89\xba\x1b\xb7\xbb\xf9\x6c\x8c\xf1\xf7\x68\x54\xc0\x25\x9a\x8f\xf4\x51\x08\x06\x63\x90\x3f\x8f\xa2\xca\x4f\x85\x88\xd8\x9c\x26\xec\x3a\xb8\x73\xc1\x9f\x3f\x46\x3e\x6c\x18\xcf\xa6\x63\xd7\x3d\xc8\x97\xd7\x4f\x43\x83\xbf\x34\x05\xb1\x0a\x27\xf9\x63\xc8\x73\xb5\x1d\xb6\x73\x5f\xe9\x22\x57\xa7\xad\x56\xf9\xe2\xd2\x80\x4c\x13\x3f\x8d\x3c\x9c\x70\x84\x1b\xc5\x4f\x37\x44\x48\xa7\x02\x78\x83\x2e\x99\xbd\xb5\x00\x05\x9f\x09\x98\xdb\x36\x5a\x4b\x1c\x48\x4d\xd8\x0a\x4c\x51\x45\xce\x4f\x98\xa0\xff\x33\x6a\xc4\x67\xb6\xdc\x50\x20\x64\x88\x56\xc2\x80\xde\x1c\xf4\x63\xcb\x78\xe5\x88\x4b\x21\x90\x64\x47\xd9\x1d\x29\x33\x6f\x31\xc5\x61\x14\xc0\x06\x56\x50\x6c\x8f\xee\x38\xc2\x68\x2c\xe1\x47\xa9\x5a\x12\xf5\xd1\xe8\x93\x76\x5c\x7f\x8f\x22\xea\x28\x49\xe9\x48\x18\xcb\x49\x4b\xc6\xdc\xcc\x04\x5f\x6e\xa1\xd3\x8c\xe2\x3a\x01\x03\x43\xf4\xde\x2c\xd7\x7e\x1c\xb7\x25\x2c\xc6\x16\x35\x21\xd4\xbf\xf9\xf8\xc7\xb0\x79\xa8\x8e\xf5\xfc\x07\x2c\x04\x5b\x0f\x0d\x00\x12\xb6\x94\x12\xad\xa0\xb1\x36\x80\xcb\x93\x15\x95\x74\xf4\x22\xcb\x6e\x80\x40\x80\x0c\xb0\xe6\xcd\xb2\xe0\x35\x8e\xcf\x5d\x25\x60\xea\x59\x01\xb5\x0d\x0e\x4c\x2c\x0a\x85\xcd\x69\x00\x2b\x53\x77\x69\x0a\x03\x7b\x1b\xe1\xd3\x60\xaa\xd2\x16\xe6\x28\xef\x04\x89\x27\xaa\x26\x0a\xbb\x5c\x59\x43\xb5\x48\x60\x6d\xb8\xdd\xa8\xbb\xcf\x91\x2e\xf2\xdd\xf8\x58\x00\x29\x13\x38\xe9\xe7\x93\x29\x68\x8b\x38\x06\x5a\x9a\x13\xff\x4c\xda\x76\x48\x43\xcf\xbf\xd3\x5f\xc0\xbd\x34\x58\x69\x76\x5b\x13\x75\x64\x4e\x21\xa1\xae\x56\x1f\x65\x6a\x12\x5b\xa9\x08\xb5\xb3\xf4\xc5\xad\x06\x50\xe0\xbd\xd0\x95\x55\x2b\x63\x12\x5d\x3f\x10\x24\xbf\xd8\x61\x6e\x07\x62\x2d\x5a\x89\x0d\x95\x00\x49\x0a\x9e\xbb\x3a\xe2\x13\x21\x8b\xae\xe5\x89\x0a\x41\x57\xef\xd0\xb1\x15\x30\x02\xa1\xc6\xf4\xd4\x2d\x7d\xb9\x28\xff\xde\x47\x3f\xf5\x58\xa3\xc3\x88\x71\xc2\x7b\xe4\x9f\x35\xca\x26\x93\x60\x10\xd3\x72\xbd\x1a\x63\x20\xfd\x12\xe9\x49\xd7\xcc\xc3\xf5\x5e\x7d\x18\xf6\xf0\x50\x51\x8f\x3e\x0a\x5f\x87\xf2\xd4\xe7\x2e\x0f\x22\x9b\x91\x70\x36\x86\xd2\x34\xe6\x4c\x8b\x64\x68\x72\xce\xb4\xb6\x8e\x14\xd5\x2c\xed\xa5\x16\xde\xb2\x34\x37\xb7\x59\x80\xb7\x19\xb6\x22\x7f\xa6\x4f\xff\x7e\xf7\xec\xba\x28\xfd\xe2\x36\xd6\x07\xc0\xf8\xfb\x12\x30\x8e\x7e\x40\x20\x27\x5b\x2c\x5a\xd0\xfa\x8b\xbd\x20\xac\x35\x19\x19\x04\xb8\xa4\x47\xdb\x2d\xed\xbd\xb3\x48\xdc\x75\x7b\xa4\xc9\x13\x92\x3e\xa1\xc2\x1b\x9d\x7c\x5e\xdd\xc1\x19\x92\x14\x28\x25\xdd\xf7\xe7\xbc\xe9\xc3\x93\x33\x78\x1f\xef\xf7\x64\xec\xda\xee\xfe\xd7\xed\x37\x66\xb3\x74\xb8\xe4\x0c\xa4\x75\xd9\x8a\x20\x9c\x02\x7a\xef\xaf\x6d\x7d\x9f\x0f\xf7\xcf\xb1\x97\x8f\xe5\x6d\xef\xb4\x0e\x3d\x5e\xcc\x06\x9b\xa2\x18\x2e\x9d\xa7\x29\x86\xf3\x46\x52\xa4\xca\xce\x6a\xa7\xf4\xf9\x32\x31\xc5\xd5\xf6\x43\x94\x0d\x5d\xec\x02\x5c\x77\x44\x60\x45\x29\x70\xe2\xa9\x67\x6b\x2b\xa1\x0f\xa7\xc4\x08\x60\x32\x2d\xf5\x62\xe8\x38\x00\x04\x5e\x2f\x32\x7e\x49\xcf\x94\x8b\x41\x36\x31\xf6\x51\xd8\x0a\x3c\x7c\x2f\xf6\x3c\x57\x98\x9b\xfd\x3f\xfa\xf8\xac\x2b\x3c\x46\x2d\xbd\xda\x63\xb1\xf9\x08\x5e\x3a\x8f\xa5\x1c\x5b\x95\x5e\xb1\x82\xba\x57\x06\x2e\xe0\x5e\x6f\xe8\xde\xb5\x54\xc5\x4b\x04\x86\x66\x0a\x55\xbe\xd1\xf3\xc4\x4a\x93\x65\x82\x92\xa6\x3d\xe5\x7b\xf0\x2a\x95\x32\x44\xf5\x83\x6d\xa1\x6d\xf9\x1f\x86\x61\xfe\xc2\x11\x34\x75\x77\x37\x93\xf4\x54\x6c\x4a\x4a\xe7\x0b\x80\xc0\x4f\xd8\xc3\x44\x5e\xf7\x6b\x4a\x45\x80\x96\xfd\x00\xe7\xb3\x34\x8c\xc1\x63\xa0\x13\x46\xf1\x82\xd4\x5c\x6d\x07\xf4\x03\xf3\xd4\x1c\x9c\x6e\x74\x6b\x79\x8d\x3a\xcd\x97\xbe\x23\xca\x80\xb9\xec\xcf\x19\xa5\xcb\xbd\x38\x8a\x98\x99\xf2\x6a\x8e\x27\x48\x0d\x94\xe3\x1a\x2f\x5a\x5b\x2e\x7f\xe3\x9e\x1d\x34\x66\x54\xee\x72\xdc\x02\x9a\x39\x75\x79\x9d\xb7\x88\xfe\xfc\x99\x88\x24\xdc\x60\xcf\xdc\xea\x07\x4e\x77\xf3\x2f\x2a\x1e\x31\x2c\xb1\x6d\xb9\xff\x57\x8d\xac\xb3\xae\x9d\x6c\x5d\x60\x26\x27\xae\x5d\x3d\x5a\x9f\xea\xa3\x7e\xb2\x13\x26\x3b\x50\xc9\xfb\x0c\x57\x09\x12\x7d\x12\x58\x76\xd2\xd0\x17\x63\xa8\x6a\x41\xd7\x07\xac\x0c\xa3\x3e\xa5\xb7\xf7\xe0\x64\x1e\xec\x66\xd6\xb2\x45\xf0\x9e\xb6\x9a\x7f\x18\xf3\x86\x61\x5c\xe1\x9a\x08\x98\x01\xa1\x50\xb0\x33\xc0\xa5\xb3\x7b\x1d\x04\xfd\x52\x2f\x8e\x15\x0c\x65\x9e\x4a\xb4\x65\xf4\xdd\x04\x66\x13\xb0\x14\xe0\x14\xc4\xe0\xa7\x7a\x87\x99\xf0\x36\xd9\x6d\x8f\x35\x4c\x94\x60\xff\x29\xe3\x94\xfc\xa9\x96\x84\x33\x6c\x32\xb9\xa9\x6d\xe2\xbe\x31\x22\x3d\xc2\x63\xf9\x11\x8d\x80\x96\x34\x71\x80\x2b\x98\x95\x75\x4a\x7c\x3e\x2b\x39\x0d\x3f\x46\x88\x98\xb6\x3f\x29\x15\xd4\x9c\x01\xcb\xd2\x37\x54\x7d\x2b\x10\x0a\x4e\xc6\xfd\xf7\xea\x73\x48\x2c\x3d\x0e\x39\xc4\xdf\xd5\xa8\xba\x81\xe8\xf2\xc8\x5c\x19\x82\x57\x3f\x6f\x05\x4e\x18\xa3\x81\x99\x6f\x0f\x4e\xbf\xf4\xca\x3b\x2f\x77\x53\xc1\xf0\x4d\xc5\xfe\x4f\xcd\x8c\xdf\x2d\x60\xe9\xd9\x6f\xa0\x0b\xf9\x4a\x8f\x37\x4f\x79\x30\xfc\xae\xd0\x53\x8f\x7e\x56\x5c\xcf\xda\x2a\x86\x46\xd8\x25\x3d\x44\x58\x8f\xd1\x61\x0a\x32\xd0\xec\x3a\xcf\xa9\x0f\x4a\x7a\x18\xe9\xa1\xd4\xd8\x8c\x95\x54\x19\x4a\xe9\xbb\xe1\xd5\x5c\x49\x97\x4f\x8f\x59\xa1\x11\xfd\x28\x87\x2f\xaf\x80\x0f\xee\x1f\x21\x88\x31\x00\xf3\x6c\x19\xde\x97\x1a\xae\x54\xa7\xbb\x04\x72\xef\x3d\x47\xdd\x4e\x54\xd2\xfb\xa4\x35\x7f\x4c\x8b\x41\xcf\xc9\x1d\xbf\x1c\x0d\x54\xa2\x34\x3e\xd2\x66\x6b\x48\x45\xaa\x65\xf2\x6b\x89\x72\x61\x98\x0b\xb0\x1c\x91\xc8\x62\x46\x9e\x8f\xdd\xd6\xd7\x86\x6b\xd1\x3e\x51\x24\x88\xd8\xcc\x40\xda\xa7\x7c\xfc\xd8\x6e\xe6\x71\xed\x64\x7e\x12\xaa\xcf\xbd\x6e\xd6\x32\xda\x8c\xd6\x0c\x77\x6e\x35\xd9\x63\x1e\x15\xca\xbe\x3b\x02\x5e\xf1\xbe\xb8\xbd\xdd\x62\x2f\x5a\x8e\x49\x8e\x7d\xa9\xb7\xce\xd1\x55\x69\xd5\xa4\x39\x1b\x71\x97\x30\x43\xb4\xfb\x71\xb3\xb0\xed\xa9\x22\x77\x14\x90\xb5\xd1\x52\xb6\xbb\x66\x0c\x77\xd1\x74\xbc\x57\x86\x13\x8e\x36\x71\x11\x88\xfb\xa0\x0f\x06\xc5\xe1\xdd\xff\x6e\x9e\x04\x80\x5c\x81\x44\xc4\x37\x2b\x5e\x30\x84\xe4\x9e\x0b\xd7\x58\x46\xbe\x9f\xa6\x50\x24\x8b\x57\x54\x23\xb4\x20\xa1\xf6\x4b\x76\xeb\x84\x05\xf1\x60\x4f\xe4\x99\x80\x00\x2b\xb8\x3c\xe1\x1e\x8a\x39\xac\x42\xd9\xb3\xcc\xfa\x4a\xee\x44\xff\x68\xab\x5e\x99\x29\xc9\x37\x49\x31\x8f\x6d\x91\x10\x17\x2d\xed\x0c\xb4\x78\xe3\x29\xe3\xf0\x2d\xb1\x7e\xea\xb4\xd0\x91\xe1\xc6\xa5\x64\x15\xd5\xfd\x61\xfb\x24\x22\x6b\x76\x6d\x0a\xd1\x66\x96\x16\x48\xdd\xcc\x98\x65\x41\xcb\x28\x4f\x2b\xc5\x47\x01\x26\xc3\x66\xac\xfd\xf8\xfb\xce\x20\xaa\x6b\xcf\xbc\xf2\x0e\x91\x9e\xf8\x8e\x19\xa5\x82\x05\x05\xdc\x0f\x07\x25\x74\xbf\x46\x01\xe5\x8d\xd4\xb9\x4f\xb1\x0d\xf0\x2e\x4d\x59\x3b\xe9\xa2\xf9\x8e\xc9\xb0\xd4\xed\xe7\x4a\xba\xa1\x90\x66\xc6\xd5\x0b\x51\xe5\x90\x5c\x14\xad\x0d\x8c\xcd\x5a\xa4\xc9\x93\xd9\xca\x17\x73\x6b\xb7\x16\x6b\x0f\xec\x35\x1e\x97\x71\x34\xda\xe1\x60\x82\x8a\x1d\x5e\x9a\xe2\x47\x02\x82\x36\x49\x46\xd9\x0a\x4d\xcb\x86\x78\x44\x07\x95\xa2\xeb\x3a\x4a\xdd\xe0\x1c\xe4\xa4\xc5\x01\x65\xb3\xb6\xe5\x4a\xa1\x74\x7a\x0a\x41\x8a\xf3\x45\x48\xdf\xdf\xf3\x46\x2d\xc3\x4d\xc8\x28\xda\xef\x8c\xef\x35\x39\xf1\xdc\xac\xdd\x59\xad\x76\xdb\x6f\xaf\x1d\xac\x4b\x1e\xc4\xdf\x74\xdf\xd0\x66\xf8\x28\x59\x1f\xf6\xec\x75\x1f\x22\x5b\x81\x39\x4a\x02\xe9\x4a\xc2\x2c\xc6\xbe\x0f\x64\x7d\x1c\xb7\xc6\x45\xba\x95\x34\xa2\x0f\xe6\x05\x00\x2e\xb4\x04\xb6\xc4\x01\x1b\xc3\x39\x46\x98\xf1\x83\x38\xcd\x40\x8f\x80\xae\xfd\x01\x3e\xe1\x79\xb1\x7d\x0c\xdf\xdf\xd3\x8e\x3f\x31\xed\xc0\xf0\xf3\x4c\x25\x76\x91\xf8\xd3\xf2\xbe\x05\xeb\x60\x2e\x36\x70\x40\xce\x23\xa4\xbd\xa2\x86\x24\xb7\x20\x8c\xd0\x79\xd2\x12\xfd\x35\x55\x0c\x42\x75\xe6\x0a\x4c\x40\xa8\x49\x87\x63\xab\xe8\xe2\x4a\xfb\x7b\xdf\x4f\x9c\x2b\x9f\x61\xc7\x86\xbc\x6f\x89\x15\x3c\x55\xc9\x3e\xd0\x2f\x78\x5f\x4d\x4c\xa8\x03\x80\x90\xa8\x77\x05\x7c\xa8\xeb\xbc\xaa\xdf\xd7\x43\x15\x29\xde\x4c\x89\x1e\xdc\x61\x38\x4f\x5c\x96\x77\x64\xe6\xa0\x2e\x6d\x4c\xb1\x3e\x1d\x82\xb4\x54\x97\x9b\x11\x03\xfa\xa7\x3b\x7a\x6b\x33\xa7\xae\x27\xfd\x28\xe6\x92\x60\x0c\x20\xcc\x45\xdc\x8c\x1c\xab\x00\x1c\xd4\xd6\x7d\x92\xb7\x46\xb6\x4f\x02\x55\x91\x29\x7f\x78\x5d\x85\xa3\xb9\x77\xa6\x55\x96\xca\x87\xcc\xad\x45\xac\x12\x9b\x20\x37\x3b\x27\xe8\x2a\x1f\x92\x3d\x81\x72\x15\x21\xc2\x1a\xfa\xe6\x76\x00\xa9\xad\x23\xca\xd2\xa7\xd9\x1e\x62\x99\x70\x11\xee\x1c\x55\x9f\x06\x29\x39\x3e\x8f\x83\x21\xd4\xa3\xcb\x55\x7b\x2c\xa7\xbc\x9d\xb0\xf5\x83\x67\x0f\x92\x03\x24\x63\x06\x9b\x1f\xba\x8b\x5c\x29\xaf\x96\xfd\xc4\x73\x1f\xba\xd4\x5a\x84\x9f\x19\x58\xcd\x31\x6a\x76\x28\xb2\xf4\x52\x8f\xb7\x3b\x6a\x37\xa9\x7c\x82\x58\x22\xd7\x58\x85\xec\x8b\xe7\x72\x52\x5f\x59\x5c\x51\xff\x7c\x39\xf0\xb2\x6b\x7b\x14\x79\x3a\xbe\x5c\xcf\x7f\xd5\x79\xbf\x18\x9a\xb9\xd2\xb9\x60\xb5\x50\xb8\x9d\x5b\x2e\x25\x5e\xcf\x7c\x4e\xaa\x8a\x16\x97\x17\x9e\x35\x2e\x79\x51\x2b\xc6\x9f\xcc\x53\x9b\xcb\xc4\xb9\xb2\xd5\xe6\x27\xbf\xbf\xe2\x48\x40\x51\xfe\x76\x07\x27\x6f\xdb\x71\xdf\x73\x4c\x84\x88\x5e\x31\x4a\x2a\xb7\x21\xcf\xb6\x5d\x20\x7c\xdd\x50\x37\xac\x9c\x5a\xd7\x9d\xa1\xee\x12\x02\xcd\xb0\x39\xb1\x34\x8d\x3b\xfb\xb7\x78\x98\x9f\x50\x3a\x6d\x25\x80\xc6\x2e\x15\x39\xc9\xcd\xa9\xc3\x64\xdd\x72\xe8\x46\xb5\xc9\x2b\x9d\x7b\x64\x61\xba\x99\x50\xc6\x04\x73\xb0\x3b\xe1\x29\x44\x7f\x96\x2c\xae\xc9\x72\x63\x91\x75\x00\xa6\x64\x1f\x79\x86\xf3\xfc\xa3\xc2\x58\x86\x83\x0d\x67\x94\xc0\xb7\x02\x24\xd6\x48\x68\xc5\x6c\xef\x44\xb1\xc7\x4f\xe2\x66\x7d\x43\xa6\xb4\x7e\x14\xd7\xf0\x81\x08\x55\xec\x74\xda\xb2\x0a\x8d\x62\x5f\x96\x10\x9d\x5b\x0b\x9b\x02\xca\x73\x43\x4c\x90\xea\x81\x8f\x13\x98\x40\x8d\xfc\x66\x68\xb6\xd6\x25\x71\x6c\x74\x90\xcb\x06\xf2\x3b\x63\x14\xf8\x28\x33\x29\x92\x90\x47\xa8\xe1\xc7\xae\xd9\x97\xeb\x71\xf4\x7e\x6c\xa3\xe5\x03\x1f\x44\xfb\xf0\x64\x8f\x09\x25\x9e\x17\xe7\x34\x1e\x49\xd7\x2f\x0d\xaa\xc9\x7e\xf1\x83\x5d\xea\x43\x0e\xc0\x58\x09\x1d\xf1\x9f\xfa\xf0\x36\xff\xb5\x9e\x99\x0f\x9e\x10\x4c\x89\x2d\x89\x5e\xa4\xd7\x49\x8b\xf6\x1e\x6d\x9e\x50\x3d\x30\xc4\x26\x8d\x8a\xc9\xa5\x13\x03\x1c\x97\x00\x8e\x05\xec\xfe\xf4\x84\x9a\xbe\x47\xfc\xab\xeb\xb2\x85\x4a\xba\xc2\x6e\x10\x38\x1a\xf7\x97\xd5\xb6\xec\x3d\x1a\xb2\x64\x94\x36\xf6\x21\xbd\xa2\x78\x51\x80\xb7\x68\xcf\xc9\x9a\xbb\x72\x28\xc9\xae\xa6\xe2\x41\xd2\x25\x6c\x50\x9a\x1c\xc7\x1e\xf9\xde\x55\x7c\xc8\xee\x7f\x97\xfa\x89\x15\x61\x0a\x27\x9f\xc7\xca\x72\xec\xe2\xdd\xec\xe7\xf4\x18\xe6\x0d\x9c\xb7\x67\x1a\x21\xc2\x6e\x67\xd6\x69\x07\xad\x81\x36\x4d\x27\x20\xc3\xdc\x28\x41\xaa\xf4\xe2\x17\xef\x61\x86\x19\x43\x48\xc4\x39\x6d\x4d\x81\xd4\xa6\x00\x6f\xf9\x66\xda\x8f\x2d\x52\x59\x60\x23\x79\xf5\x01\xc5\x26\x52\x24\x70\x10\x07\x78\xa6\xc8\x8e\x0f\x8a\x08\x49\xc5\x1b\x14\x4e\xae\x5e\xc2\xf5\xcc\x16\x17\xb6\x2f\xd4\xc0\xab\xdb\xad\x34\xa1\x90\x9f\x01\x44\x04\xaa\xf5\x03\xe0\x28\xb5\x56\x5d\xfb\x6f\x28\xdd\xd7\xb5\x5a\x1a\x4f\xbb\xe6\x11\x73\x07\xfc\x60\x10\xd3\x0b\xa9\x0f\x3c\x5d\xd3\x7e\x11\x39\x32\xd4\x7b\x1a\x43\x8e\xf1\xbb\xf9\x4c\xb3\x75\xb9\x5c\x81\x16\xe6\x64\x85\x63\xc9\x4c\xb5\x33\xcc\x87\x9c\xbf\x63\x55\xba\x8a\xf8\x1e\xaf\xb8\x68\x1a\xba\x98\xc0\x86\x56\xcc\x9b\x1b\xad\x5a\xd7\xd6\xf9\xb9\xb3\x1d\x49\x65\xe2\x4f\x91\x9f\xeb\x8f\xe9\x5f\xe8\x61\x3d\xfe\x70\xbe\x8b\x70\xb2\x77\xc0\x64\xec\x44\xa6\x8a\x5e\x41\xed\x80\x29\x5c\x27\xe2\x18\x07\x5e\x30\x41\xd5\x75\x25\xbc\x34\x86\x69\x8c\xc4\x3c\x7a\x2c\x4d\x94\x57\xec\x1c\xca\x7c\x46\x56\x35\x22\x64\x65\x7f\x2c\xdb\x9f\x95\xce\xa2\x01\xb4\x6d\xac\xa2\x98\x92\xcf\x45\x69\xb9\xc6\x5b\x3b\x3a\x03\x1f\x59\xbb\x60\x8b\xc2\x49\x6f\x7e\x28\x93\x68\xc0\x2d\x24\x94\x91\x72\xbd\xaa\x3d\xa5\x7a\x1d\xee\x72\xa7\x19\x0a\xf6\x43\xa9\x38\xaf\xe5\xc6\x71\xfe\x49\x4e\xc2\x70\x22\xf8\x51\xb9\x2e\x30\xdd\xa8\x26\x37\x21\xb3\x03\x4b\xff\x44\x7c\xd4\x5a\x20\x74\xe0\xf3\x57\xcd\x10\x5f\x5b\x1f\x46\x44\xb1\x40\xfd\x77\xd0\x26\x87\x42\x17\xbd\x1b\x4e\x4e\x47\x9f\xd8\x50\xf7\xfa\x16\x23\x0f\xac\x99\x6a\xac\xbe\x3c\x24\x83\xbe\x23\x68\x5f\x6c\x09\x1b\x7b\x10\x27\x41\x72\xe4\x90\xf1\x1b\x93\x50\x91\xdc\x61\x96\x83\xdd\x90\x28\xf0\x78\x0b\x5e\x1a\x62\x37\x6b\xc3\x31\xe1\x17\x10\xde\x0c\x74\x98\xc9\xe5\x18\x75\x4f\x2a\xf4\x86\x6d\x10\xff\x05\xa3\xdd\x11\x2a\x7f\xa4\x12\x60\x2f\xb5\x6c\x0a\xf2\xf9\x09\x33\xf4\x20\xc0\x7d\x34\x82\xc4\xb0\x90\x4e\xe4\x2a\x50\xcd\xfe\xad\x62\xc9\x86\xf1\xc2\x48\xee\x37\x1f\xc0\x2e\x68\x02\x93\x8c\x8f\x50\x1e\xf3\x85\x87\x78\x25\x32\x8e\x07\x62\xa0\xc0\x22\x89\xe2\xde\xc7\x04\x74\xa1\x50\xae\xd8\x33\x7a\x18\x81\x12\xf7\x94\x2f\xf7\x74\x0f\x35\x5b\x44\xd3\xf2\xb9\x4e\x9a\x1e\x03\x96\x20\x4d\x0b\x8a\x69\xcc\x84\x87\xfa\x49\xf2\xf0\x49\xd1\xee\xa3\xb2\x65\xa2\x8f\xba\x5a\xab\x96\x1d\x2c\x8d\x8d\x65\x64\xb1\x0e\xc1\x84\xbe\xfe\xc4\x2f\x20\x9d\x85\xb7\x7f\xdd\xce\x3c\x48\x49\x66\x3e\x8b\x28\x47\x73\x97\x7b\xbf\x2c\x81\x83\xa8\x9d\x3a\xc8\x99\xbb\xfa\xb8\x66\x4e\x95\x3a\x98\x05\xc0\xeb\x3a\xd1\x9e\x34\xfe\x01\x55\x49\xf8\xc0\x53\xe9\xd1\xfd\x29\x55\xc0\x44\xc2\xd9\xb7\x6f\x6a\x09\xb8\xd8\x38\xfe\x23\xea\xb9\x31\x94\x1e\xea\x5f\xc5\x3e\x6d\x4f\xb3\x75\x82\x68\x70\x09\x0d\x3f\x27\x60\x01\xc4\xa4\x46\xf9\xc0\x8a\x70\x9a\x64\x65\x2d\xb3\x06\x7f\x4f\xce\x16\x34\xbf\x59\xec\x7a\xdf\x32\x11\xc6\xc2\xd4\xc0\x8b\x42\x3c\x25\xb0\x6a\x6a\x3e\x30\xed\x8e\xca\xab\x34\x8a\x9e\xd8\x52\x48\x63\xdc\x16\x1d\x5a\x0c\xe6\xea\x2a\x80\xc0\x94\xd1\x45\x0b\x0b\x37\xfe\xb3\x29\xf7\x01\xe9\x32\x8a\xe0\xbf\x20\xb9\x2c\xbc\xe0\xab\xe7\x4e\x68\x49\xdb\xfa\xf9\xbf\x65\xa5\x01\x59\x4e\xc6\x1e\xb6\xb7\x47\x9b\x48\xb3\xcb\xc6\x95\x27\x77\x13\xd1\x90\x33\xd5\xd0\x31\x54\x47\xda\xc2\x6c\x3e\x52\xbe\xf4\xf0", 4122);
	syscall(__NR_write, r[1], 0x20003100ul, 0xfffffc1bul);
	syscall(__NR_read, r[0], 0x200010c0ul, 0xffffffcaul);
	return 0;
}
