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
memcpy((void*)0x20001080, "./file0\000", 8);
	res = syscall(__NR_creat, 0x20001080ul, 0ul);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20002100 = htobe32(0x67446698);
*(uint32_t*)0x20002104 = 0;
*(uint16_t*)0x20002108 = 0;
*(uint16_t*)0x2000210a = 0;
*(uint32_t*)0x2000210c = 0;
memcpy((void*)0x20002110, "\x65\xa0\x44\x2d\xab\xf2\x04\x31\x62\x33\x7e\x19\x52\x8f\x6a\x2e\xdb\x2b\xb3\xde\x82\x88\x8d\x3f\x64\x64\x47\x7f\x57\x9d\x6c\x31\x4a\x23\x3a\xab\x6c\x1d\xf3\xc0\x15\xce\x0b\x92\xe4\x46\xc9\x5f\x63\xed\x09\xff\x2e\x4a\xee\x15\x23\x30\xb6\x79\x3f\x68\xb2\x7d\x5c\xf0\x07\x28\x13\x73\x24\x51\x43\x11\x07\xcd\x9e\x4d\x89\x16\x8c\x24\x54\x8d\x1c\xa6\x1a\xad\xe1\x60\x04\x0a\xa6\xc2\x9c\x15\x7d\x18\x61\xc3\x41\x7b\xc2\x3a\xb8\x6f\x8c\x1d\xb3\x51\xcf\x96\x1d\x4a\x72\xb6\xc3\x62\xe4\xf2\x8f\x40\x38\xcc\x7d\xfd\x01\xa0\xe6\xf6\xe1\x84\x33\xcf\x41\x8c\x99\x29\x81\xc8\x88\x0d\x4a\x1f\x8f\x91\x1a\x5d\x5f\x9d\x77\xdd\x23\x85\x95\x8d\x00\xed\x81\x3c\x7b\xef\xbb\x34\x01\x02\x18\x4b\x3c\xae\x9c\xb3\x32\x67\x1a\xda\xa8\xe0\x21\x33\x7c\x9a\x63\x32\x44\x4c\x5c\x4d\xd0\x4f\x9f\x7e\xc3\xf7\x4d\x25\xaf\x74\xf1\x81\x58\xfe\x13\x60\xfa\x87\x67\x0a\xad\x25\xdb\xf1\x38\xfc\x13\x64\x55\x69\xeb\x41\xd3\xea\x53\xc3\xb0\x79\x50\x05\x6d\x04\x55\x74\xb6\x39\xd8\xc8\xf4\x35\xb8\xad\x90\x89\xcf\xa9\x6e\xc0\xba\x23\x22\x2b\x8b\x6a\x05\x64\x8e\x22\x8d\x9c\xd6\x37\xed\xdd\x63\x8d\x8e\x12\x10\x32\xbc\xb8\x24\x06\x55\xc1\x95\x13\x0f\x04\xe4\x10\xe3\x83\xc2\xa5\xce\x4f\x63\x92\x15\x1d\xc9\x30\x5d\x4c\xf3\x8a\x3f\x16\x36\x26\xcc\xa3\x43\x6e\x6c\x74\x93\xed\xf6\x8a\x2c\x40\x7e\xaa\x8f\xa8\x1f\xb8\x47\x28\x39\x3f\x66\x47\x45\xef\x44\x64\x36\xb1\xcc\x29\x01\x50\x12\x1a\x45\x19\x14\x52\x17\xd5\xb9\x46\x71\x24\x6f\xae\x00\x21\x0d\xf1\x3d\x63\x73\xfe\xa5\xee\x4f\x5a\x71\x2e\x04\x26\x1d\xaa\x6d\x59\xae\x9f\xef\x11\x8b\x7c\x56\xad\x42\x4a\xbc\xff\x4c\x19\x9c\x76\x65\x47\xbf\xa9\x74\xee\xa6\x8f\x8c\x1b\x86\xd1\x93\xfa\xf2\x09\x78\x85\xe3\x08\x4f\x1a\x8e\x9a\xdb\x4a\xe6\xa4\x43\x7a\xee\x0c\xca\x96\x25\xb0\x7c\xab\x1c\x43\xd9\x76\x79\x6c\xda\xad\xd9\xac\xb5\x4e\xf5\xbb\xc7\x47\xe9\x9c\x34\x28\xbd\xb3\x80\xf7\x23\x6e\x3f\xbb\x8d\xa5\xd0\xd3\xd6\xa8\xa4\xda\xee\x0e\x72\xfc\xd7\x18\xf5\x3e\x75\x02\x5b\x15\x77\x6e\xa8\xa1\x33\xd5\x92\xec\x59\x89\x00\x53\x40\xe1\xe7\x38\xe7\xd7\x26\x9a\x06\x2f\x91\x3f\x13\x73\x20\x49\xae\x78\xbf\x78\x7e\xac\xf5\x8e\x52\x86\x88\xc8\xd8\x70\x73\x24\x93\x48\xce\xae\x44\xad\x8f\x85\x0e\x42\x7e\x48\x5b\xf0\x9d\xaf\x3c\x2d\xa5\x81\x94\xe9\x47\xd9\x22\x43\x9d\x41\x0e\x84\xbd\xef\xb7\x4b\x68\x9c\x96\xa7\x14\xfd\x93\xed\x5d\x94\xe0\x36\x2c\x19\x53\xfc\x4e\x8d\x7d\x0e\xe9\xee\x6b\xd4\x45\x15\xe7\x18\xba\x3b\xe8\x5f\x3a\x8b\xb0\xd4\x4d\x79\x24\x79\x6f\x51\xc5\x82\x0f\xfb\xbe\x20\x0a\xe2\x9a\x6c\x1a\xe3\xe2\x31\xf6\x8e\xe8\x43\xc8\x26\x8e\x7c\xff\x0f\x23\x65\x28\x85\x4f\x62\xce\x53\xbc\x57\xf7\x19\x4a\xf2\xbe\x9d\xd6\xc4\xb3\x3e\x6b\x4f\xe9\x1c\xf0\x41\xf5\x87\x33\x2d\xb3\xbf\xb8\xad\x5b\xc4\x89\xdc\xb8\x7d\xe9\x4b\x5c\x2f\x7e\x3d\x6b\x7b\x4d\xdd\xa1\x46\x15\x79\xff\x63\x6e\x46\xed\xf4\x63\x03\xca\xc0\x42\x94\xc5\x3a\x45\x78\x4e\xfa\x7f\xad\xf6\x7c\x73\x6b\xd1\xab\xe2\x18\x85\xf1\xcc\x90\x7b\x31\x1f\x23\x41\x57\x97\x59\xfe\xa4\xdd\x80\x1f\x2f\x76\xc3\x57\xc4\x16\x11\x36\x37\x89\x82\xa1\x0c\xc0\x46\x70\x05\x50\x8d\x40\xb9\x6f\x8e\xdb\x57\x22\x68\x91\x9c\x4e\x43\xec\xa6\xa3\xd4\xbc\x88\xce\xdd\xbd\xd0\x94\xcd\x7a\x10\xb9\xaf\x5f\x34\xe4\x26\xbe\x22\x59\x70\xd3\xbd\xc1\x8c\x9c\x45\x0e\x0b\xac\xe2\x10\x8f\x01\x78\x84\x0c\x72\x75\x3d\xde\x85\x7d\x4a\xf8\xdf\xf6\xa0\xe9\xeb\x5f\x69\x8e\x6d\x38\x13\x6c\x71\xf2\xdd\xee\xb9\x97\x78\xa1\x06\x94\x8e\x33\x34\x31\xe0\x38\xa3\x67\xb0\xf6\xa2\x9c\x65\x9e\x9a\x83\x70\xd1\x6f\x29\x2d\xb7\x51\xb7\x79\xbe\xe2\xd3\x42\x2e\x85\xbe\x66\xec\x85\xbe\x91\x5d\x16\x73\x64\x79\xc9\x83\x32\xd2\x09\xf9\x21\x6f\xf0\xcf\xb5\xe1\x43\x36\x6d\x05\x71\x7f\x71\x04\xbe\x93\x64\x1f\x30\xa6\x8a\x1b\x0b\x12\x20\x55\x22\xe0\xaa\x56\xb7\x90\xe8\xd0\x67\xfc\xfe\x5b\xd6\x41\x5f\x7c\x92\x03\xa2\xfe\x65\x06\xe5\x21\x9f\x42\x7a\xbd\x6d\xc9\xf5\xdf\x7a\xfe\x07\xf8\x48\x2d\x10\xd7\x41\xe6\x5c\xbf\xbb\x16\x0b\xf6\xfc\x5a\x8e\x3d\xb3\x3e\xca\xb5\x8c\xdc\x38\xc7\x39\x7c\x8c\x6c\x95\x16\x4d\x5f\xbd\x68\x0f\xd2\xc5\xcc\x35\xb9\xdd\xf5\x1b\x91\x19\xa7\xff\xbd\xce\xde\xa4\x1d\xc9\x30\xa6\xf1\xca\x2c\xa8\x04\x9e\xca\x9d\xd0\x72\xf6\xb4\x28\x9d\xb3\x8d\x36\xc5\xec\xc8\xc0\x92\x8a\xa1\xd7\xe7\x98\xad\x4c\x41\x6b\xd6\x2d\xd7\x5e\x2e\xa8\xc4\xf7\x5d\xf2\xd9\x22\xf1\xf1\x55\x47\x0a\xed\x7f\xda\x04\x66\x12\xbe\x7b\xe6\x5a\xbc\xbc\x44\x50\x6d\x3f\xd3\xba\x5e\xda\x13\xad\x3a\xfe\x78\xd6\x19\x0e\xe5\xc2\x78\x5f\xcd\xe3\x3a\x6e\x81\xe9\x60\x86\x83\xed\x6d\x0a\x8d\x5f\x1e\x8f\x87\x74\x12\xc7\x70\x8a\x3e\xd6\x91\xa8\xcb\xf6\xdd\xae\xf7\x91\x1b\x1e\xa1\xec\x30\xd0\x63\x6f\x4d\x35\x5a\xcb\xf7\x5d\x2f\xd9\x11\x18\x07\x5f\x0b\x5a\x21\xf3\xff\xd8\xc5\xb1\x1b\x64\xea\xbe\x1e\x2d\xfd\x5b\x62\xd8\x1f\xb5\xde\x94\xc2\x0e\x46\xcc\x17\x22\x0f\xe7\xf1\xf2\xb7\xa2\xb9\x34\x53\xb6\xce\x08\xeb\x98\xc7\x15\xea\xba\xf8\x4c\xe9\x53\x50\x49\x6a\xfd\xd8\xe7\x13\x4c\x1f\xa0\x5c\x87\xa1\xb5\x49\x1d\x9e\x43\x59\x9f\x77\x77\x49\x0e\xaf\x20\xd3\xff\x07\x66\xa1\x56\x82\x26\xd9\xdf\x8b\x84\xcc\x9b\x82\x93\xdc\x1a\x59\x38\xd6\x5d\xe2\xb5\xf1\xe5\x78\x1c\xb3\x7a\xc0\x07\xec\x10\xbe\xf4\x57\xb4\xb9\xcf\xcf\x84\xf7\xe8\xd9\xbe\x20\x9a\xa5\xfd\x5e\x59\xb1\x83\xda\x03\xc8\x27\xa6\x55\x4d\x5b\x41\x11\x57\x1c\xf0\xf9\xb2\x13\xc9\x6a\x07\xa8\x03\xa1\x2a\x61\xcf\x65\x0d\x66\xcd\xc8\x72\x37\x41\xe8\x5a\x1c\x5f\xe7\xa7\xcc\xef\x62\x52\xa1\x43\x2f\xda\x8b\xdc\x7d\x4f\xbe\x6a\x9d\x22\x10\x79\x89\x61\x84\xd8\xd8\xa8\x43\x92\xde\xaa\x5d\x1d\x13\x81\x5b\x62\xa4\x76\x5d\x3d\x00\xe6\xd3\xf4\xab\x04\xc9\x64\x5a\xc7\x55\x51\x54\xb6\xef\x4b\xcc\x0a\xcf\x2c\x4c\x2c\x27\xc1\x29\x93\x5b\x3d\xdb\x5f\x1b\x41\x8d\xd8\x29\x3a\x9d\x0a\x75\xcf\x8a\x18\x37\x1e\xcb\x4e\xdd\xaa\x3e\x32\x3f\xdb\x10\x51\x5d\xc4\x5c\x43\x7b\x6a\xa1\x4e\x4f\xf7\x8c\xdd\x56\x52\x00\xe9\x9f\xc1\xb0\x11\x85\xf2\x58\xf6\x31\x99\x6f\x4d\x40\xba\xd9\x4c\x57\x35\xc9\xa3\xd4\x00\x4b\x53\xef\x1f\x95\x5a\x68\x99\x5b\xd0\xb8\x54\x68\x8b\x5b\x6a\x36\x3e\x17\x72\x4a\x03\x62\x12\x33\x1c\xac\x2c\x5d\xa6\x7a\x39\xa4\x5f\xed\xe5\xb8\x29\xae\x96\x68\xc6\x8b\x71\x81\x70\x6b\x7d\xa0\xef\x89\xe1\x4a\x9c\x0f\x5b\xf4\xa5\x4b\xe3\x49\x18\x31\xbb\xb2\x3a\x66\x36\x65\x4a\xf7\xb2\x04\x96\x9c\x3c\x30\xad\x9c\x4b\x27\x03\xea\x6b\x95\x35\xb6\x30\x4c\xd2\x71\x82\x5c\xef\xbf\xe0\xbf\xdc\x20\xbb\xcb\x23\xa6\x62\x54\x02\xd0\x20\xef\x83\x5e\x33\x82\xf7\xb3\xdc\xab\x10\xbe\x0a\xc5\xc4\x95\xe5\xb6\xe0\xf5\x17\x5b\x41\x45\x2d\x06\x44\xff\xa3\xd7\xfe\xa7\x7c\x1d\x50\xb7\x9e\xb4\x2e\x88\x5b\x21\x25\xf5\x1c\xf6\x24\x4e\x7c\x38\x7c\xc6\x2e\x43\xb9\x07\x76\xa3\x04\x50\x48\x30\xa8\x48\x2d\x90\x0a\x36\x84\xff\x57\x04\x94\x03\xec\xaf\x94\x86\x35\xa5\x8f\x57\xe3\x3f\x6e\x54\x1e\xb4\xa2\x40\x79\x2d\xef\x03\x33\xc5\xd4\x0e\x6a\xff\x32\x6a\xb2\xbe\x4a\xea\x52\xcf\x87\x2c\x77\x2d\x66\xc0\xdf\x5f\x41\x0c\x4a\x28\xe1\x10\x50\xf0\xbb\xc2\x6a\x0e\x1a\x08\xac\xb1\xba\x3e\x5c\xad\x29\x0a\x3a\x17\x55\xcb\xd7\x03\xae\xa7\x73\x89\xe4\xc0\x3b\x31\xa0\x1b\x58\xad\xc6\x3e\xc6\xb9\x62\xc2\x28\xc2\x64\x87\xc0\x66\xb7\x8f\x20\x98\x3e\x2a\x04\x9c\xae\x31\x16\x83\xed\x86\x54\xe0\x04\xa3\x1a\x67\xd1\x60\x68\x77\x78\x24\xbb\xd5\x53\x4b\xbd\x66\x4c\xf0\x12\x4a\xa1\x95\x40\x8c\x3c\x8d\xe5\x5a\x2a\x9c\xcd\xed\xe4\x43\x22\xbb\xc4\x3a\x88\x67\x5a\x29\x16\x2f\x53\xca\x99\x2c\x59\xed\x07\x03\x2b\x06\xba\x64\xa4\x27\xc9\x74\xb1\x35\xe2\xfc\x36\x54\xe8\x86\x00\x9b\x4a\xaa\x59\x96\xa9\x0e\x5f\x3c\x47\x7e\xd5\x05\xe8\xc2\xe9\xbb\xf3\x7a\x48\x6a\xfd\x32\x7e\x06\x82\xff\x1a\x7e\x02\x92\xe4\xe4\xa5\x50\x1a\xb2\x52\x62\x89\xf3\x76\x9a\x7e\x04\x64\x26\xb5\x95\xbd\x77\xc4\x30\x98\x10\xbe\x8a\xc4\xed\x7c\xb2\xd5\xde\xc5\xec\x7a\x1b\x37\x56\xf7\x9c\x60\xd3\x40\x17\x61\x27\x26\xde\x54\x10\x58\x4f\x9e\x7a\xeb\x4c\x47\xdb\x1c\x47\xfe\x47\x16\xb5\x19\x9b\x2e\x38\x47\xba\xb9\xb2\xa5\x7b\xba\xeb\x7d\x15\x78\xbb\x16\x49\x20\x93\xac\x7b\xda\x59\x61\x85\x0c\xf6\xee\x24\x75\x2f\x4c\xd6\xeb\xe2\xcb\x88\xd0\x59\xe9\xa2\x90\x22\x01\x8a\x54\xe3\xce\x66\x1f\x88\x22\x9b\x64\x0f\x55\x31\x9c\x99\xad\x10\xdd\x2e\xc2\x59\x94\x3c\x5e\x76\xfc\xc4\xdd\x9b\xaf\x87\xfe\xab\xeb\x85\xfa\xf3\x65\x88\xe3\xf5\x1e\x66\x9d\xc4\xa3\x02\xf4\x8f\xb9\x5a\x36\x49\x9f\xd3\x26\xc6\x69\x35\x4e\x3b\x63\xff\x1f\x36\xe2\xf5\x77\x23\xbe\x2c\xd3\xbb\x9f\x26\x77\xa2\x9a\xb4\xf2\x29\x47\x65\x4b\x8b\x35\x01\x3c\x4d\x12\xd8\xb2\x20\xcd\x67\x5c\x32\x84\xdd\x95\x11\x91\xbd\x31\xfe\xfe\x16\x7b\xa7\xba\xb9\xc1\xb3\x55\xa0\x5f\xfc\xbe\x0e\xcc\x2f\x83\x33\xab\xf0\x4d\x55\x46\x3a\xb7\xfb\xba\x1c\x48\x76\x08\xff\x11\xe2\xb3\xbf\x29\x2c\x36\xff\xb3\x7f\x2a\xb0\x46\x65\xfb\xb8\xd5\x7b\xd3\x6e\x8f\x63\x4a\xb6\x8d\x5d\x86\x89\x2f\x88\x99\x32\xe3\x0d\x14\xc3\x5a\xac\x00\xc8\xfb\x17\x2b\x4b\x32\xf9\xa8\x71\xcc\xe3\x37\xc2\x75\x30\x82\xb2\x69\x06\x2b\x97\x5d\xfd\x77\x26\x15\xd7\x5c\x3d\xf4\xfc\xe3\x85\xcd\x88\x32\x57\xe1\x78\x3e\x21\xd9\x1f\xcf\x3f\x8f\xf8\xf3\x0e\x05\x21\x7b\xde\x31\x14\xef\x27\xaf\xd0\x0e\xe6\xc1\xe7\xf2\xc1\x15\x1c\x93\x14\xf1\x9d\xb0\xfc\x33\x79\x0e\x90\x0d\x67\x17\x13\x1a\x92\x25\x70\x25\x68\x1a\x48\x4f\xff\x9c\xa3\xaa\x06\xc6\x06\xdb\x9c\x14\x77\xae\x4d\x18\x2d\xd2\xe8\x0f\xac\x36\x30\x9c\x9a\xbf\x72\xb4\xf7\xff\x24\x94\x41\xb6\x6a\x18\xfb\x50\x52\xc8\x77\xd8\xda\x89\x2d\xa6\x39\x96\x4d\xf4\x51\xd0\x50\x82\xed\xec\x46\x5e\x40\x87\xad\x77\x06\x93\x06\x26\xaa\x41\x98\x5a\x65\xd3\x4f\xc4\xbf\x2c\x41\x9c\x31\x23\x8f\xe3\xa8\xb0\xd6\xf6\x98\xee\x52\x6e\x82\xb5\xe0\x4b\x1b\x5b\xcb\xf3\x80\x59\xc0\x62\x9e\x3c\x0d\x71\x49\xe2\x4b\x94\xca\x63\x98\x6c\x40\xe3\xb3\x70\xb9\x00\xd0\x51\xf8\x60\xa2\x88\x5b\x22\x94\xc0\x9b\xc4\xd4\x64\x2d\x71\x25\x7e\x1d\x49\x49\x55\x14\x6b\x3c\x83\xf2\xe1\x13\xff\x17\xa0\x5b\x74\xa7\x6c\x72\x52\x97\x0f\xf1\x89\xb2\xaf\x62\x36\xd8\xae\xef\xb3\x9a\x07\xcc\x27\x1d\xe5\xaf\xd6\x21\x71\xe6\x7d\x18\x1a\xbe\xac\x84\x6b\x39\x69\xa2\x75\x42\xb7\x94\x21\x35\x75\x13\xa3\xbc\xca\x01\xcb\x47\xb7\x44\x26\xd1\x29\xe2\x3c\x54\x57\x25\x51\x3e\xa9\x76\xf5\xa0\xe9\x05\x20\x2e\x4b\xc6\x42\x8a\x39\xc4\x85\x81\x3f\xec\x56\xe8\xca\xb2\x50\x8c\xb6\xcd\x48\x0c\xf1\x04\xd3\x7e\x89\x1a\xed\xf2\xdf\x7e\x9f\x8c\x5c\xbe\x12\xe4\xb0\xd2\xdd\xba\x0c\x2d\xec\xe4\x2f\xad\x6d\xc6\x4c\xc7\x04\x79\x19\xc4\x2b\xf4\x34\x77\xb3\x4f\xd9\x0e\xe3\x30\x46\xde\x4d\xf3\x5b\xe5\xd2\xe6\xcd\x68\x41\x33\xef\x24\xa9\xc0\x64\xb5\x70\xa7\x56\xd6\xdd\x47\x71\x12\x62\x75\xab\x16\x72\x8f\x43\x8e\x64\x5f\x0f\x4d\xd2\xbb\x65\xcf\x64\x53\xf6\x04\xd7\x6b\x54\x74\x9a\x8f\xc2\x8c\x01\x6c\xfd\xd4\x9d\x5b\x04\xf5\xc5\x5f\xed\x5a\xa5\x74\xb4\x91\x48\x76\x50\x19\x6d\x3a\xda\x3e\x80\xe3\xae\xe8\x9f\xc0\x5e\x26\x41\x3e\x01\x01\x02\x3d\x81\xde\x6a\x37\xbf\x32\xaa\x19\x01\xac\x1d\x00\xef\x87\xdb\x56\x1a\xac\x1a\x4f\x68\x7c\x3a\xeb\x4b\x07\xc8\x26\x18\xa0\x64\xae\x95\xe1\x49\x6d\x79\xd0\x04\xb9\xc6\x20\xe5\x08\xb8\xa6\x2b\x4a\x07\x63\x29\xcc\x22\x87\xb1\xc6\xdd\xdd\x92\x67\xb1\x67\xf0\xa8\x2b\x24\xdb\xf4\x7c\x06\xa4\xa5\x92\x6d\x66\x6f\x04\xe6\x3b\x67\xf3\x86\xeb\xec\x4b\xb6\xa5\x03\xe8\x34\x3d\xcf\xf2\xc9\xb4\x4a\x72\x68\x8b\x8b\xcd\xe2\xb8\xb7\x27\xc5\xb5\xb4\x88\x60\x03\x53\x27\x73\x35\xa9\xc8\x7e\xa9\x4f\x9e\xfc\x1e\x31\x81\x08\xe8\x6d\x13\x16\xe4\x4a\x34\x27\x99\x2c\x44\xb3\x79\x03\x01\x3c\x83\xf3\x1e\x77\xdc\x9d\x04\x83\xd3\xe9\x41\xed\xc7\xd9\x9e\x91\xfb\x75\x17\x86\x8e\xe5\x05\x6d\xa0\x23\x48\x58\x54\x23\xe8\x42\x7d\xd4\xcb\xb7\x3f\xf7\x20\x6e\x8e\x1e\x02\x42\xa7\xba\xd9\x8f\x7d\x5d\xc6\x03\x16\x47\x71\x61\xe8\xe9\xb5\xe7\xe3\x44\x5e\x85\x2c\xf4\x9a\x1b\x3b\xda\xaa\x8b\xde\x63\xfc\xb2\xf8\xd8\x81\x6b\xaa\x00\x67\x6d\xb2\x24\x83\x81\x46\x82\x9e\x6f\xc2\x32\x09\x98\x94\x0f\x0f\xfb\xf4\xea\xf4\x2e\x10\x0f\x8d\xaf\xe1\x9b\x3e\xc8\xf2\x48\xc3\x08\xf6\xba\x79\xfc\xdd\xf0\x91\xae\xa9\x2e\x2a\x48\x60\x43\xc4\x2f\x56\x70\xcb\xc5\x59\x54\x5a\x9a\x10\x62\x10\x5f\xae\x79\x0e\xfc\xde\xf2\x84\xe8\xe9\x94\x50\x1e\x57\x8d\xe5\x45\xe1\x01\xe0\xb8\x70\x2d\x16\x29\xa7\xfa\x52\xb5\x72\x53\x8a\x6d\x86\x77\x65\x63\x2e\x1c\x4d\x7c\x48\x13\x64\x19\xeb\x04\xb0\x93\xb3\x85\x72\x8f\xbd\x47\x35\x60\xb9\x15\x5e\x92\x3e\xb7\x67\x65\x88\xc4\xc3\x16\x1b\xab\x87\x0f\x8a\x0a\x31\x5a\x5a\xb3\xed\x3c\x13\x0a\x5f\xdd\xa4\x0e\x7d\xae\xf6\xb7\xcf\xc8\x21\x2a\x5c\xf5\xd2\x04\x00\x00\x00\xbe\x5c\x78\xe0\xe0\x28\x4d\xec\xd2\xcc\x89\xd4\x0f\x8b\xf9\xc5\xba\x6b\xa5\x0e\x17\x45\x5f\x72\x25\x88\x6d\x75\xed\x96\x93\xb9\x93\x31\x25\xb9\x49\xfd\xe4\xaa\x91\xdb\x69\xd8\xb3\xba\x3d\x58\xb8\xc8\x41\xc2\xf8\x49\x9a\x97\xfd\x99\xdd\xe3\x67\xda\xeb\xe6\x8a\xbe\x62\xf8\xc7\xe2\x87\xc4\xe6\xa7\x2f\x77\x48\x10\x16\x8f\xcc\x15\xba\x6e\xda\xee\x89\x65\x6d\x5e\x4b\x77\x0c\x72\x3a\xa8\x98\x99\xbc\x70\x8e\x36\xda\x6d\x04\x06\x6e\x50\xd9\xad\xd4\x33\xfe\xec\x87\xfb\x60\x47\xc9\x63\xf6\xaa\xbc\xe7\x6d\x1d\xf3\x2c\x3b\xc8\x41\x22\x6b\xf5\x60\x96\xaf\x03\x7f\xfc\xe1\x6d\x6d\xc8\x5b\x70\xea\xa3\x33\xc6\x6e\xf5\x1a\x40\x8d\xbd\x0b\x59\x37\xbf\x99\xff\x30\x25\x68\xa2\x2d\x55\x76\x31\x74\xb2\xa4\x7d\xe5\x67\x32\x66\x1e\x78\xac\x21\x52\x8b\x55\x62\x82\xa0\xe5\xf6\xa5\x18\x5d\x87\xbb\x9d\x5b\x8c\x9a\x2b\xc3\x6c\xf8\xa8\x61\xb5\xe6\x46\xdd\x05\xec\x3c\xa6\x3a\xa5\x58\xec\x05\xb3\xd0\x34\x64\xdd\xc6\x7c\x7a\xdf\x79\xba\xc1\x7c\x93\x2d\x3f\x43\xbc\xa3\x70\xdd\x65\x83\x28\xc2\xfa\xd6\x11\xfa\x80\x72\x54\x51\xea\xa8\xeb\xa9\x4b\x1e\xde\x81\x67\xbd\xd8\xb4\xd0\xd9\xd0\x88\x3f\xda\xb9\x14\x03\x87\x46\x0d\x3e\xbe\xbd\xba\xb5\x9d\x39\xbd\x31\x00\x34\x66\xee\x42\xc0\x10\x4a\xa0\x85\xab\xce\x76\x0c\xc4\xd4\x69\x74\x81\x80\x04\x49\xd6\x28\xa1\x7e\x3b\xb4\x9c\x5a\x8f\xb3\x4b\x1b\x45\xc8\x25\x9b\x81\xf9\xea\xbd\xff\x4f\x1f\x5e\x9c\x31\x0b\xda\x0f\x95\xae\x08\x68\xb2\x97\xc4\x01\xb9\x46\xee\x8f\x9d\x8b\x5e\xf4\x61\xc4\xf4\xaf\xe6\xb2\x8e\x67\x8c\x66\xa9\xe2\x3f\x95\x83\x4e\xd8\xac\x1c\x6c\xa6\xb1\x7c\xfd\xb3\x0b\x95\x02\xe4\x68\x60\x3c\xba\x39\x6c\x8d\xab\x43\xb8\x9b\xed\x4c\x39\x27\x91\xb3\x25\x5c\xeb\x4d\xa9\x57\x60\x24\xad\x9d\x1b\x6f\x3e\x81\xdd\xc2\xe4\x83\xb4\x3a\xbd\x58\xd4\x59\x1a\xa9\xb2\x54\x9f\x6d\x81\x58\x27\x95\x12\x69\x24\xde\x93\x21\x1b\x9a\x05\xd7\xe2\xdb\x75\x1a\x12\x30\x0a\xeb\xb4\xad\xa1\x17\x1b\xe3\x84\x94\xed\xf6\x91\xb0\xe1\xeb\x90\x0c\x8b\x98\xcb\x2b\x0a\x6e\x35\x69\x8c\x5f\x40\x6b\x69\xac\xa1\xc0\xd9\xe2\xdc\xcd\x55\xe3\xd4\x83\x34\x65\xf6\x95\x64\xba\x4d\x92\x41\xd3\x34\xd4\x54\xd1\xde\xa3\x8d\xee\xbc\xca\x9f\x4f\xcf\xea\x6b\x11\x57\x4b\xf5\x68\x87\x65\xb8\x35\x52\xcb\x61\x5b\xd6\x61\x47\x85\x7c\xb9\x72\x4b\x08\x5b\x47\x57\xff\xa5\x3e\xe7\x31\x50\x04\x8f\x21\xa3\xd8\xa8\xbf\x66\x31\xec\x42\xa4\x90\xf1\xae\x23\xa2\x7a\x25\xa9\x33\xc3\x62\x36\xdc\x95\x89\x97\x7f\x8f\x2c\x07\x14\xd4\xe0\x5a\xfc\xd8\xef\xa2\xd8\x6d\x99\x13\x29\xc0\x53\x46\xd3\x92\x38\xc8\xb2\xdf\x29\xab\x15\x31\xf2\x1d\x42\x3f\xce\xf1\x26\xe9\x48\xda\xe4\xb0\xd4\x85\xcf\xc3\x9f\x28\x84\x24\xaf\xcc\x6a\x02\xc6\x2b\x11\x00\x8d\x15\xd3\x1f\xcf\xd5\x29\x3d\xe1\x09\xd1\xd5\xb6\xa4\x96\x26\x8e\x8e\x75\x6e\xb6\x9e\xa6\xb9\xf5\x83\x7a\x2f\x85\xf4\xde\x50\x99\x86\x29\x1d\x8e\x6b\x9f\x0c\xe7\xa9\xaf\xa1\x1f\x43\xab\x72\x83\xc2\x9f\xb5\xc9\xed\xd9\x74\x50\xca\xf4\x2b\x33\xc2\xe2\x80\x17\x11\x9f\x17\x79\xf3\x93\xcf\x2e\xab\x26\x94\x6c\xca\xfb\x89\x9f\x0c\x46\x32\xb5\x23\xef\x46\x2f\xf6\x72\xaf\x0d\xe9\xe1\x7f\xd9\x2f\x51\xd5\x64\xaf\xa3\x0e\x26\x59\x4e\xae\x03\xc1\x8b\xa1\x1d\x38\xe9\x88\x40\xae\xd9\x32\x08\x11\xab\x7d\x16\xa2\x3b\x4b\xfe\x14\x10\xf2\x71\x50\xcc\x23\x53\x4d\xc2\x66\x3c\xd6\x01\xaa\x47\x0f\x18\x40\x92\x3a\xb0\x07\x82\x36\x09\xe4\xbd\x78\x9d\x80\xbd\xe9\xe7\x58\x1b\x49\x71\x79\xb8\x5e\x1c\xe5\xe0\x08\x54\x9e\x0e\x75\x53\xf0\xb9\xb5\x8b\x84\xc5\x36\x3c\x40\x35\x5b\x49\x30\x95\xc5\x19\x02\x21\xa6\x81\x57\x6d\x28\x03\x1c\x34\xe6\x25\xc6\xf1\xa2\x79\x98\x38\xfa\x74\xe5\x12\x55\xc9\x0f\xaa\xf1\x54\x7c\x4b\x43\xf3\xc3\x16\x84\xbc\x74\xdf\x32\xc7\x3b\x4f\x10\x7d\x83\xb8\xfa\x33\x54\x0c\xab\x32\x45\xc7\x15\xfe\x65\xa7\x06\x95\x9a\x4e\x0e\x42\x01\xc4\xd3\x8f\x73\x67\x70\xdd\xb4\xa2\x4b\xd6\xe0\x77\x99\xda\xa8\x88\x43\x56\xa9\x41\x2a\xdf\xfa\x77\x34\xdf\x4b\xc3\xe9\x1e\x29\xb9\xd2\xe3\x6f\xde\x91\x04\x74\x19\x43\xf3\x2d\x70\xf8\x23\x5b\x29\x69\x7a\x34\xbb\xf0\x12\x61\x38\xe3\x44\x64\xb8\x72\x51\x3d\x41\x28\xe2\x3a\x39\x44\x79\xda\xde\xc1\x2a\x6f\xe6\xc1\xf3\xde\xad\xfc\x41\x6b\x7b\x4a\x18\xcc\x46\xe9\xc8\xaf\x94\x34\x0f\x2b\x9b\x15\x5f\xaa\x7f\x9b\x83\x1e\xf3\xc6\x85\xce\xcb\x13\x56\xe2\x88\x89\x0b\x8f\x5b\xcf\xb0\xaf\xd2\xb1\x5e\xa6\x11\x5b\xb9\xc6\x4b\x25\x9f\x9d\x81\x91\x4b\x98\xe6\xdf\x8c\x78\x2b\x56\x88\x58\x71\x07\x82\x29\xea\x8d\x5b\xa5\x6a\xba\xf2\x36\xe4\xab\xfc\xd9\x5b\x22\x15\xab\xdf\x79\x09\xfd\x34\x01\x86\x44\xf6\xe8\x10\xeb\x77\x89\x08\x9b\xd4\x94\x5b\x22\x61\x2c\x45\x9f\x19\x18\x0e\x8a\x3f\x1d\xb3\xca\x2a\x10\x97\x85\x61\xcf\xe9\xaf\xfc\x38\xf0\x89\xb8\x04\x69\x7e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 4081);
	syscall(__NR_write, r[0], 0x20002100ul, 0xfffffff8ul);
	return 0;
}
