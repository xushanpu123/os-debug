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
memcpy((void*)0x200001c0, "/dev/vcsu\000", 10);
	res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x200001c0ul, 0ul, 0ul);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20001080, "trusted.overlay.upper\000", 22);
*(uint8_t*)0x200010c0 = 0;
*(uint8_t*)0x200010c1 = 0xfb;
*(uint8_t*)0x200010c2 = 0xe1;
*(uint8_t*)0x200010c3 = 0;
*(uint8_t*)0x200010c4 = 0;
memcpy((void*)0x200010c5, "\x3a\xcf\x0f\xf0\x86\xfb\xfd\x92\x5e\x62\x3f\x00\x9f\x56\xb8\x40", 16);
memcpy((void*)0x200010d5, "\xc3\x6e\xef\x2d\xce\x84\xb4\x74\x05\x43\x6d\x26\xa6\xc8\xb4\xac\x40\xef\x5c\xaf\xa5\x4a\xb0\x6c\xa7\x29\xfa\xa3\x08\xb2\xb5\xed\xa2\xc7\x84\xfb\x12\xd8\xe1\xc8\xe3\x4f\x77\x18\x31\x4b\x96\x8a\xee\x40\x5a\xa3\xe2\x49\xfa\x40\x6e\xf4\x7e\xe3\xec\xe3\x84\xb5\x9a\x66\x9d\x3d\x32\x0b\x44\x68\xf0\x24\xbb\xfb\x77\x2a\xb1\xae\xb8\x6d\xd2\x76\xc8\x11\xfe\xc8\xc0\x65\x74\x0a\x72\x59\x0d\xfb\xb7\x5d\x89\x44\x40\xa1\xea\x76\xca\x59\x91\xa9\xed\xca\x5f\xe5\x9b\x15\x7c\xc8\x45\x91\x4a\x18\x9d\x8a\xd2\xc2\xb3\x67\x9d\x0d\x83\x01\x74\x2b\xdf\xac\xab\x44\x9c\x16\xdd\x8d\x42\x88\xe8\x05\x6b\xd1\xc7\x4f\x7e\xfc\x92\xc6\x00\x17\x9c\x66\xfb\xd1\xc3\x53\x65\xcc\x85\x26\x7b\x69\x5a\xf1\x89\x85\x44\x0f\x16\x2b\x80\x1c\x2f\xcd\x1d\x4f\xea\xa9\x7e\x6a\x36\xb9\x28\xcc\x8c\x31\xd9\x3f\xbc\xf9\x23\xc3\x9d\xeb\xdf\x04\xe2\x97\xcd\x42\x82\xdb\xe9\xea\xf3\xf5\x0a\x41\xf9\xf5\xf5\xfd\xb3\x87\xac\xd1\xb0\xdc\xc4\xcc\x49\x5f\x94\x80\x29\x17\xb9\x9f\x0b\xe8\xde\xbf\x70\x4e\xee\xbe\x90\x63\x84\x67\x81\xd9\xe3\x2f\x92\xe8\xa8\x48\xa5\x2c\x07\xef\x97\x28\x88\xe0\x4e\x32\x33\xb6\x74\x9c\xf2\x3a\xde\x4a\xa8\xfe\xfb\x2b\xed\xca\x8f\xca\xd5\xb4\x11\x7f\x4e\xf9\xb8\x52\x4b\xf4\x5a\x26\x22\x8e\xe2\x56\x0d\xd6\xd2\x49\x9a\xef\x21\x5f\x53\xdf\xcb\x96\x2e\x9a\x6c\x7e\x7e\x41\x61\xa1\x97\x1f\x4b\x69\xf7\x26\xea\x93\xc5\x29\x91\x48\x28\x8d\x09\xbd\x3c\x06\x68\xa3\x54\xba\x1a\x3f\x20\x2d\xfe\x7a\x23\x05\xe5\xdd\x98\x93\xf5\xd8\xe2\xf4\xc5\xf8\xa0\xd1\xe9\x9e\x78\xeb\x4a\x20\xba\x0e\x0f\x1d\x9b\xf3\x80\x02\x30\xdb\xde\x9f\x18\x93\x93\x07\x14\x89\x76\xd5\xa2\x32\x21\x6d\xac\x14\x42\x20\xe1\x4d\x10\x3b\x17\xe1\x9d\x1a\x46\x24\xfe\xa0\x05\x98\x2b\x50\xd2\xa9\xfc\xd3\x4a\xde\xe4\x17\x37\xd4\x54\xca\x45\x4e\xda\x9e\x73\x93\x5c\xde\x86\x7d\x1e\xa3\xaa\xdd\x8b\xc0\x55\x94\xb4\x8b\xad\xb1\x1f\xc2\xec\xc3\x03\x0c\x83\x13\x56\x1b\x78\x47\x3f\x4b\xe4\x46\xda\x44\xc0\xd6\x4c\x70\x06\xd8\x50\x77\x74\x01\x40\xe3\x2f\x1b\x08\x87\x0f\xa7\x4b\x2e\xe5\xaf\xae\x98\x06\xab\x73\x08\x23\xcd\x02\x40\x9e\xa9\xa6\xb8\xc3\x65\x46\x69\x8e\x6d\xb2\xea\xad\x4c\xd6\xe7\x5b\x30\x85\x1c\xec\x63\x11\xe4\x4b\xb9\x91\x2b\xd9\x9c\x7a\xa0\x1a\x4d\xbf\xa8\xe5\x2e\xab\x7e\x38\x12\x29\xad\x92\xdd\x47\xc8\x43\x7c\x59\xc7\xdc\x41\x0a\xc2\x91\xdf\xbc\xea\x80\x39\xaf\x98\x44\x56\x6e\x0b\x30\x1d\xe5\xde\xac\xef\x10\xb9\x4c\xe7\x13\xc3\x57\xe6\x09\x8e\x0c\x16\x2e\x26\xc9\xdd\xef\x63\xae\x34\x92\xdd\x62\xaf\x65\x86\x38\x07\x16\x71\x8f\xc2\xbb\xef\xaa\x68\x8e\xa8\x13\xf4\x47\x50\xd3\x17\x29\x09\x6c\xef\xb2\xb2\xef\x29\x48\x53\x04\x3e\x5c\xa9\x85\x22\xe3\x21\xa8\x45\x1b\x99\x0b\x1f\x15\x44\xc3\xc3\xc1\xc5\x0a\x3e\xba\x04\xfe\x42\xb3\xbf\x67\xfc\xe3\x0b\x1f\x46\xd5\x0c\x5f\x91\x72\x7c\x10\x8f\x5e\x3c\x61\x4f\x42\x8f\x1f\x03\xc4\x21\xcf\xe0\x8b\x9c\xde\x38\xa4\x6f\xb8\xc3\xcd\xb8\xce\xc1\x09\x96\xc6\xef\x41\x26\x40\x0e\x60\xd9\x67\x34\xf9\xd0\xe8\xf9\xd7\x2c\x9e\x61\x3a\x15\x05\x95\x36\x9f\x02\x78\x0b\xb0\x6c\xd9\x8d\x63\xf1\x1e\x28\xd2\xe4\xbd\xd8\x8a\x64\x81\xd0\xad\x06\x73\x3e\xea\x7e\x8a\xd9\xc5\xa3\x53\xae\xeb\x28\xcc\x31\xe6\x15\x52\x2f\x33\x33\x51\x81\x75\xe7\x84\xa7\x05\xcf\x23\xe4\x9f\xa6\x9a\x7a\x69\x0b\x29\x31\xcb\x90\x09\xd6\x0c\xdc\x37\xd1\x1a\xf7\x71\x5c\x06\x38\x1c\x31\x2f\x33\x36\x63\x10\x95\x10\x55\xa3\x6c\xa6\x7f\x99\xe7\xa2\x28\xcf\x41\xd6\xfd\x09\xb1\x75\x74\x14\x0a\xc5\x57\x43\xb2\xcf\x37\x14\x04\x8a\xd4\xb1\xe7\x33\xc0\x5c\x6a\xf5\x32\x32\xd7\x7a\x7c\x7a\x5f\xd6\x07\xc9\x59\x58\xd0\xf1\x82\xc8\x35\xf7\x4c\x9c\x7a\xb3\x8e\x4b\xb7\xd2\x93\x40\x1d\x3a\x25\x07\xdc\x6d\x76\xcf\x2f\x9e\x51\xde\xf4\xef\xa6\x1f\x04\x80\xe3\xf1\x3f\xef\x4e\xce\x43\x16\xd4\xfc\xb9\x87\x67\x00\xa8\x97\x4c\xbc\x90\xa8\x9d\xdf\x48\x06\xb0\x8a\x9b\x28\x6f\xde\x69\xaf\x33\xe5\x23\x14\xa4\xd6\xd4\xe9\x9f\x6a\xc0\x32\x01\xc9\x9d\x7a\x2a\x6b\xaf\xcc\x32\x49\x24\x38\xa6\xa1\xd7\x86\xc9\x6a\x0c\x7f\x96\x87\xa7\x19\xdc\xe9\x1f\xac\xca\xdd\xb2\xc7\x75\x9e\xa1\x66\x4b\xc4\x9a\xeb\x8b\x8c\xe8\xe1\xf8\x29\xad\xd8\xc5\xb1\x54\xb4\xdf\xf7\x16\x72\x20\x1e\x64\x6a\xf0\xe3\x34\x4e\x33\x95\x7f\x20\x3a\xe2\xae\x30\x96\x13\x8b\xd5\xe7\x26\xde\xb9\xd8\x74\xbd\xe8\x8e\xa4\x8d\x84\x0e\x7c\x2b\xde\x5d\xce\xa4\x81\x95\x25\xa0\x7b\xc4\xfa\x6a\x67\x07\x88\x1b\xc7\xc4\xc2\x23\x1b\x99\x2b\x01\x6b\x1c\xc5\x3d\x24\x46\x97\xea\x86\x60\x45\x94\x84\xbe\xfb\xfa\xbd\xde\xfb\x7e\xdf\x19\x8e\x38\xa9\x76\x73\x81\x47\x57\x70\x54\x16\x79\xb9\x17\x86\x71\x38\x1a\x9c\xd0\x81\xba\x2d\x24\xba\xfc\x84\xbb\x55\xf4\x3c\xf2\x61\x67\x3d\xc0\x77\x93\xf7\x7f\xe9\x74\x5f\x05\x10\xad\xf6\x98\x1e\xe4\x0a\xe7\x11\xc0\xb5\x15\x30\x3f\x2c\x22\x08\xe4\x22\x5b\x5d\x80\xc5\x6d\x20\x76\x90\x6f\x0d\xe1\x37\x88\xe5\xaf\xc1\x9c\x21\x4d\x68\xb0\x7b\x8b\x87\xcd\xed\xe7\x48\xfc\x3c\xb9\x1c\x30\x58\x91\xd4\xf6\x90\xe6\x3a\xc0\x16\x99\xed\xed\xbb\xc8\xc1\xc5\x83\xbe\xf5\xf5\xc0\x44\xe8\x10\x83\xa2\xc1\x95\x3c\x73\x2f\x2b\xd2\xfd\x9e\xc7\x8e\xce\x6e\x66\x94\xa7\xff\x2a\x90\xf2\xe8\xd3\x49\xbb\xb4\xfa\x62\x91\x82\xee\x57\x13\x20\x73\xdd\xd7\x7a\x31\x05\xf3\x8c\x9b\x7c\x8f\xa1\xf1\xbe\xf1\xa5\xa4\xa8\x6d\x1f\x0e\x6e\xad\x90\x26\x13\xc3\xb9\xf8\xda\xf6\x18\x77\xa0\xbc\x21\xb1\xdb\x23\x62\xad\xa4\xa3\x9c\x4a\x17\xa0\x9f\x66\x0f\xef\x0d\xc1\x08\x90\x9c\x64\x45\x63\x3f\x09\x1b\x03\xdc\xec\x53\xc6\x5d\x64\x9a\x19\x0a\x16\x02\x3e\x5d\x44\x62\xdd\x6e\x3d\xcd\x91\x31\x57\x49\xaf\x5b\xd5\x25\x9c\x8a\x4f\x92\xfb\xe9\x64\xf4\xf1\xdb\x86\x80\xad\xef\x1c\x96\xe5\x97\xfc\xc9\xac\x66\x96\x6c\x5e\x70\xfe\x42\x60\x1d\x66\x4f\xfe\xe6\xc9\x28\x1d\x5b\x8a\xb7\xa3\x96\x11\x4a\xfd\xbd\xf0\x7f\x6c\xe2\xf9\x55\xa0\x12\xd6\xeb\x89\x28\x8e\x73\xd6\x4f\xc2\x68\x7c\x62\x1b\x64\x89\x1a\xfa\x7f\x7a\xb9\x20\xca\xe9\x75\x14\xbe\x1e\x9c\xec\xe6\x4a\x37\x9e\x7e\x0f\x1c\x3e\x8c\x8d\xb4\xfb\xd0\x30\x0c\xa0\xc4\xb0\x4d\xde\x07\x7e\x97\x64\xc4\xf1\x8f\x3e\xae\x85\x3d\xfc\x41\x02\xf2\x0e\x53\x80\x6b\xeb\x68\x6d\x95\x5f\xca\x42\xcd\x6e\x81\x73\x03\xe3\x20\xee\xa0\x3c\x41\xfd\x1d\xcb\xfc\x89\x9e\x40\xe0\x74\x25\x89\xcb\x34\xc0\xcc\xa6\x85\x8b\xe9\x7e\x61\x61\xaf\x84\xcf\xcd\x07\x07\xfd\x68\xb7\x02\xe8\x0d\x92\xef\x52\x37\xa2\xf3\xd8\xf6\x11\xb3\xcd\x26\x48\x74\x1c\xc7\x88\x55\x03\xf6\xa1\x99\x55\x3e\x62\x35\x50\x0b\xff\x57\x74\x5e\x1b\xc2\x3c\x32\x97\x61\x89\x29\xfd\x9a\xb4\x61\xf7\x85\xc4\xc2\xcd\x6e\xd6\xa4\x66\xe8\x92\xcb\x0b\x16\xdb\x22\x57\xe6\x41\x36\x3e\x3c\xcb\x2d\xa9\x16\x9a\x99\x64\x93\x6d\xa2\x46\x84\x47\xe3\xe7\xc9\xca\xb3\xfb\xe5\xc9\x29\x33\xd8\xb9\x1c\xbd\x3f\x2a\xa7\x85\x83\xfe\x61\x3b\xa4\x47\xda\xe1\x7a\x67\x11\xfa\xea\xeb\x9d\xd2\x51\xe5\x18\x2c\x7c\xe9\xe6\x48\x45\x9c\xf4\x84\x8a\x17\x47\x44\x44\x09\xd6\x5a\x86\x10\xac\xff\x17\x3b\xb2\x13\x3c\x29\x5b\x8c\x94\x00\x01\x08\x99\xd1\x64\x0c\x41\x53\x91\xb0\xaa\x3a\x9b\x11\xe5\x83\x16\x8d\x1c\xcf\xa6\xe0\x37\xa4\xc0\x50\x0a\x51\x4a\xba\xa9\x42\xdc\x98\xe6\xa4\x29\x32\x1d\x5e\x28\xab\x77\x35\x03\x28\x7d\x17\x87\x7c\xf4\xda\x2a\x07\xf5\x8e\xf0\xcf\x7e\x60\xc1\x10\xf9\xdb\xa9\xf7\xf8\xc5\xbe\x48\x02\x90\x72\xcc\x53\xa5\x2d\x0d\xf2\xc2\xc1\xb7\xe2\xe1\x78\x14\x90\x17\x86\xbe\x20\x4c\xe5\x2f\x8c\xb1\x9e\xce\x7f\x0d\x96\x2d\x6d\xed\x8f\x1e\x4d\x6c\xf3\xab\x5f\x0f\xd0\x6f\x91\xbb\x57\xb2\xb7\xc8\x99\x8a\x05\x6b\x99\x89\x1e\x76\x1f\x25\x8a\x3c\xd5\x33\xca\xcf\xfe\x7e\xda\x49\x12\x58\x6f\x90\xc4\x0d\x3a\x87\x43\xf9\x2a\xf6\x15\x8f\xbd\x4d\x6a\x1e\x60\xaa\x4d\xb5\x39\x23\x1f\x66\x71\xca\xe0\x33\xf4\x24\x8c\x51\x9b\xdd\x3d\x38\x0e\xe8\xbc\x5b\xfd\xfe\xaf\x6b\x12\x9a\x3c\x99\xd0\xbe\xba\x84\xbd\x37\x0d\x77\x3b\x0d\x9e\xa8\x3a\x11\xe3\x5f\x77\x6a\xbb\x72\xed\x8b\x6d\xd1\xa1\xf7\xc7\x8b\x6b\xd0\x51\xbb\x48\x3c\xf6\x3c\x31\xbc\xbf\x7b\x9e\x9b\x18\xed\x1e\x4d\x98\x42\x76\xee\x2f\x2f\xcd\x1b\x50\xf5\x37\x52\x5d\xfd\x14\x27\x7c\x8c\xa7\x84\x13\xf1\x5e\x62\xfc\x00\xc5\x75\xa0\x4c\x2c\x47\x40\x5d\xca\xf1\x45\x64\xe5\x08\x0f\x32\x9e\x72\xaa\xda\x5f\x06\x10\xc0\xae\x6f\xd3\xa9\x88\x06\x34\x9a\xd1\x13\x2a\x41\xfe\xf9\x6d\xe0\x9f\x40\x3f\xa5\x44\x4c\x3b\x95\x90\x8e\x5c\x6b\x0b\x94\x9c\x53\x26\x64\xe0\xaf\x9a\x50\x65\xe1\xaa\x8b\x9f\x3b\xcd\x3c\x51\x41\x7d\xdc\xd5\xff\x97\x0b\x9c\xaa\xd1\x2b\x1f\xe6\xa3\xa3\x67\x95\x89\x54\xdd\x26\x40\xfd\xdb\xf7\x8e\x4a\x37\x50\xa7\x95\x61\xa3\x4d\x29\x9d\x85\x19\xb6\xab\x15\x3c\x8a\x2c\x1b\xab\x02\x68\xc3\xdc\x6c\xaf\x95\x1f\xdf\x99\x5f\x31\x4e\x2d\x5e\x7b\x94\xa9\x47\x0e\x5b\x73\x60\x27\x7c\x4a\x29\xb3\x35\xbb\x66\xeb\x6f\xa8\xdd\x9b\x3d\xfe\x46\x80\x3e\x6a\x64\xe7\xca\x32\x57\x8c\xdb\x18\x66\xa7\xfe\xea\x2e\x2a\x5e\xac\xea\x9a\x31\x97\x86\xb9\x7f\x0e\x0a\xb3\xfc\x8d\xc1\x08\xdb\xf0\xc3\x59\x65\xb6\xb1\x53\x1f\x2c\x2b\xeb\x08\x60\xae\x5d\xb3\x48\xc1\x45\x62\x56\x12\xc4\x01\x9a\x39\x63\x6e\x0c\x55\xc7\x2b\xed\xa3\x21\xac\xf6\x1f\x00\xc9\xec\x14\xf8\x7b\xd4\x58\xc6\x5b\xba\x5a\x2f\xff\x93\x9e\xb1\xe0\x1a\x06\x18\x1a\x55\x18\xc1\x98\x27\x67\xd1\x59\xaa\x43\x3e\x4b\x65\xb8\x58\xd4\x2e\x29\x8b\xf8\xc7\x8f\x6d\x68\xbc\x25\x94\x0f\x2e\x09\x27\x7e\xed\x2b\x2d\x0e\x3b\xe7\xec\xba\x2f\xea\x05\x07\x8b\x94\xbf\x0f\xab\x77\xf0\x63\xe8\xae\x01\xe3\x0d\x15\x2c\x9b\xcc\xbf\xc5\xb8\x6c\xbc\x8f\x2b\x95\x80\x32\x85\x12\xe7\x82\x53\xd8\xe1\x5c\xfd\xbe\x67\xc0\x47\x4f\x7c\x1d\x5c\x9e\xdb\x64\x28\xc8\xe6\x42\x7f\xe4\x6f\xd1\xfc\x18\xdd\xfd\x62\xdb\xc9\x21\x3e\xb5\x4d\x19\xa0\xe1\xfa\xf5\xe6\xdd\x12\x9c\x4f\x9b\x42\xa2\xf1\x50\x0a\xe6\x2a\xc1\x84\x2a\x42\xe9\xc8\x74\x65\x35\xa4\x51\xaf\x2b\xe6\xda\x64\xe8\xa4\x70\x4a\xe6\x8f\xed\x21\x1e\xac\xbe\x3d\xa5\xa3\x23\xb7\x53\x6b\x26\xe6\xc4\x4d\xb9\x26\x02\x0f\x0c\x19\x7d\x9a\xa0\x5d\xf4\xe1\x27\xf9\x52\xfb\x7b\x6e\x88\x53\xa4\x71\x0a\xa5\x18\x46\xcc\x6a\x3b\xc1\x8c\x1a\xd8\x2a\x4f\xe5\xf2\xac\x2b\x6d\x1a\x83\x6b\x1e\x7d\x5f\x8d\xa7\x8c\xf3\xf0\xbc\x1c\xed\xa8\x4a\xa2\x0b\x2d\xea\xea\x32\xe7\x13\x91\x43\xe0\x30\x5c\xd7\x5a\x09\xc9\x27\x7b\x46\xdc\x0b\x24\x18\x99\x37\x3c\xb3\x6c\x6a\xe7\x4c\xbe\x45\x31\x0e\x7b\xe5\xc2\x2b\x24\x10\x33\x87\xc2\x3e\x32\xb5\xe4\x56\x53\x63\x00\x7e\xf4\x24\x65\x80\xc5\xbc\xde\x7b\xe5\x36\x77\x13\x59\xeb\x60\x99\x70\x02\x9c\x0c\x10\xf6\x36\x77\x6e\xa6\x74\xe3\xf1\xda\xb6\x9b\xdf\xdc\xdf\xb3\x45\x9a\xba\x57\xc2\xd3\xd0\xb5\x4b\xdd\x34\xaf\xde\x86\x4a\x19\xd0\x2b\x62\xc5\xdd\x42\xae\xf5\xe7\x3a\xd7\xe0\x20\xcd\xd3\x8f\x83\x27\x0e\xff\xe0\x80\x65\x6f\xee\x1d\xc9\xbc\x48\x15\xf2\xbd\xa9\xcb\x23\xa5\x86\x93\xd8\x87\xe4\xc9\x77\xe1\x2f\xb6\x50\xa7\x3d\x3b\xd0\x32\xff\x63\xbd\xec\x49\x6a\x01\x29\x81\xaf\x26\xc6\x90\x99\x3b\x0f\xd2\xf0\x4a\x26\xcf\x06\xd0\x65\xd8\x7a\x56\xd0\xd0\x41\x38\xee\x02\x52\x4a\xbb\x14\x83\xf4\xd5\x2b\x90\x1b\x8c\x5c\xeb\xe8\x10\x7e\x22\x7f\xf9\xb7\xeb\x77\xc2\x90\x96\x78\xd9\x0c\xa5\xb2\x74\xaf\x06\xef\x7e\x83\x35\xde\x02\xf1\xe0\x46\xb3\xbf\x30\xe9\x05\x15\x58\xce\xb6\xcb\xe6\x21\xe7\xd7\xc9\xa4\x04\x46\xfb\xe7\x5a\x70\x07\xd9\xca\x18\x8b\xfd\x17\xbe\xbe\xf6\xba\x51\x6b\x50\xc6\x34\xb6\xa5\x15\x6c\x55\x67\x35\x5b\x9b\x49\x4c\xaa\xcc\xa0\x04\xb5\xf5\x46\xc8\x6e\xfc\x84\x47\x6f\x0c\xe2\xcc\x8f\xc8\x8f\x85\xd1\x8f\x4b\xa9\x74\x5b\x6c\x27\xd0\x5d\x5d\xbc\x96\xed\x07\xd0\x49\xe5\xb2\x71\x18\x5b\x3e\xf1\x42\x4e\x8a\x1c\x32\x19\xdc\x0a\xa7\xd1\x3e\xd7\xc2\xb6\x9e\xa9\x5a\xb5\x64\xf3\x1f\xd5\xf8\xd1\xb0\xd2\x14\x80\x38\xb8\x05\xa4\x3e\x01\x89\xd5\xd3\x45\x63\xa7\x6b\xbb\x4f\xa5\x0d\x11\x39\xef\x09\x0e\x85\xde\xb7\x82\x0c\x7c\xcc\xf6\x5d\x03\x0d\xa9\xd3\xff\x47\xf1\x27\x7d\xd3\xc2\x73\x74\xb7\x39\x54\x93\x99\x7a\x15\x90\x4b\xb5\x7d\xae\xe3\x3d\xda\x51\xaf\xae\x12\xc5\xb3\x12\xd8\xb3\xc8\x1b\x70\x7f\x91\x42\x43\x5b\xc6\xbe\x72\x69\x64\x3a\xce\xe9\xd8\x82\x92\x34\xdb\xbd\x35\x08\xcf\x97\xa8\xb7\xe2\x5f\x31\x65\xe6\x0a\xff\x69\xb8\x53\x94\x11\xcf\x5e\x4f\x08\x22\xd4\xca\x44\x52\x49\xed\xba\x68\xc1\x14\xb1\xf6\xc0\xa2\x63\x68\x88\xe7\x8f\x9f\x8d\xf9\x54\xa3\x2d\xe4\x68\xc1\xc8\xa7\xd1\x78\x78\x1c\xbb\x15\x8d\x2f\xe1\xf5\x61\x22\x39\x0f\xfc\x82\x8f\x3a\xf6\x28\x0a\xaf\x4b\x2f\xda\xa9\x97\xaa\x12\x40\x4a\x6b\xc2\x6e\x89\xd5\xe3\xa7\xac\xe0\x15\x66\x10\xa8\xf6\x69\x58\x6e\xf9\x81\x92\x3c\x2c\x83\x15\xc1\x4b\x5c\xb6\xe5\x1d\x9f\x55\x53\x3b\xa9\x95\xf5\xd7\x43\xeb\x7a\x6b\x20\x34\x3a\x99\x2a\xe9\xd5\x17\x13\xaf\x1d\xf9\x42\xa9\x87\xad\xa1\x88\x9a\x32\x3e\x63\x68\x1d\x8f\x95\xbb\xcc\x98\xcf\x41\x7a\xd8\x4f\x06\x85\x55\x49\xdc\x6c\xc2\xac\xe9\x86\xbd\xeb\xf9\x45\x23\x7b\xac\x52\xda\x79\xfa\x90\xc7\x14\xc4\x2a\xbc\xd8\x38\xc5\x89\x3f\xb0\x4b\xf3\x29\x00\x80\xb3\x89\xf7\xfb\x1b\x2e\x1e\xb9\x65\x7a\xc0\x3f\x32\xb0\x4d\xb0\x66\x0e\x27\xc7\x23\xad\x72\xec\x3a\xb2\x3d\x58\xaa\x2e\x4c\xae\x7e\xfa\x13\x85\x93\xe8\xc2\x8e\xa4\x1a\xb5\x49\xf8\x24\x91\x03\xa0\x69\xae\xb8\x90\xa7\xcf\xb6\x1a\x4c\x99\x05\x2f\x97\x74\xbe\x46\x99\xe9\xad\x6f\x23\x9c\x63\x60\x3d\x83\x13\x4a\x7d\x8d\x8f\xf1\xba\x40\x52\x33\xb9\x9a\x83\x90\xc6\x52\x74\x92\x35\xce\x3e\x25\xec\x90\x13\x59\x44\x07\x96\x85\x8b\x66\x9a\x44\xcf\x48\x86\x2d\xe0\x69\x17\x45\xef\x35\x36\x90\x73\x5f\xe4\xcb\x7e\xb5\xf0\x3c\x7a\xa2\x9d\x6a\x3c\x53\xc0\x7a\x31\x71\xf4\x2a\x5a\x23\x52\x95\x0a\x5b\x01\x84\x06\x1c\xff\x1b\xe2\x86\xac\x64\x8a\x06\x80\x46\x63\x5e\x01\x74\xc2\x38\x3c\x00\x4e\x21\x27\x19\xe9\x52\x25\xe4\xf8\x54\xcc\xc2\xfb\xef\xcd\xf1\x0f\x2a\x95\x24\x8f\xd3\xd6\x70\x87\x98\xe7\xb7\x89\x9e\x39\x9c\x09\x39\x50\xf2\xf9\x9f\xa1\xfe\x34\x97\xf4\xc3\xe7\xae\xcd\xa8\x89\xe3\x0a\x3a\x18\x2d\x81\xa9\x8d\xad\x79\x8b\x8f\x89\x93\xe6\x29\x15\x3b\x3b\xfb\x5f\x48\xc2\x2a\xe2\x45\x21\x06\x38\xa4\x12\xc4\x7f\x62\x48\x21\x42\x68\x8c\x4c\x5c\x33\x36\x9f\xa5\xc8\x8e\x18\xc5\x81\xda\x3e\xd2\x75\xdc\x20\xb1\xc8\x59\x78\xea\xb5\xa6\x6d\x4b\x09\x24\xe4\x22\x65\x0c\xa4\xff\x69\x15\xae\xc9\xa4\x06\x16\xbc\xe4\x29\xe8\x06\x0e\x65\x1d\xa4\x6e\x3b\xf8\xdb\xe1\x64\x9c\xeb\x65\x1b\x0c\xa4\xc9\xbc\xa5\x0e\xed\xb9\x1a\x7d\xa2\xfc\x7e\xf4\x04\xc1\x7e\x3c\x82\xcf\x7f\x88\xf3\xbc\xf5\x01\x54\xe5\x6c\xba\x4f\x09\xa7\x80\x9b\x38\xc4\xb9\x87\x43\x5a\x37\x6e\x45\x03\x3b\x0a\xad\xe6\xc9\x67\xb8\x3b\x7d\xdb\xc8\xd7\xf2\xea\xd4\x60\xdd\x16\x49\x57\x94\xfc\x99\x06\x94\x32\x32\xb6\x6f\xc7\x78\xd3\xce\x26\xa2\x3e\xe8\x19\x2a\x0b\x63\x7b\x1f\xfd\x70\x2f\x7d\xaf\x39\x40\x8c\xd2\x12\x05\xb2\xc7\x70\x41\x0b\x83\x6f\xd4\x53\xb0\xf3\x56\x0b\xb4\x93\x28\x54\x11\xa7\xb0\x4b\x61\x7d\xa1\xfd\x14\x00\x17\xe8\xbb\x4d\xba\xae\xcb\x88\xf4\x59\xbb\x50\x92\xfb\xd5\x77\xec\x5d\xcb\x60\x4c\x4f\x8d\x43\xae\x74\xe6\x6a\x94\x9a\xbe\x43\x49\x4d\x74\x89\xda\x97\x26\x3e\x46\x3f\xf2\xc1\x57\x65\x53\x9b\x23\x55\xa6\xdb\x9c\x0a\x7f\x70\x54\x26\x6b\xa4\xef\xa3\x8e\x1f\x7f\x93\xaa\xf4\xe1\xda\xfe\x56\x65\x5b\xe2\x52\x95\x5a\xf8\xe1\x1f\xb7\x9c\x5d\xeb\xfe\x82\x23\x9f\x1f\xb1\x0a\xc6\xfc\xc9\xb2\xf0\x6b\xb0\x56\xe6\x24\xf9\x19\xf3\x71\xe0\x26\x8c\x3d\x40\xa0\x8a\x6c\x8d\x02\xb1\xfb\xc7\x70\x98\x39\x57\x28\xa1\xf3\x0c\x9b\x11\x2e\x06\x55\xc9\xbb\x4e\xa4\x61\x5a\x35\x3e\xff\x5c\x11\xef\xc6\xdf\x15\x9c\x6c\xde\x80\xd0\xca\xc5\xf2\xe0\x07\xe2\xac\xca\xe7\x2e\xc1\xff\xef\x0b\xc7\x7b\xa3\x22\xda\xaf\x67\xce\xa6\xab\xed\x00\x57\x58\xe6\xa9\x60\x8c\xdd\x34\xb5\x47\x71\x20\x83\x5c\xe5\x39\xfa\x95\x48\x62\xcb\xc1\x11\xc4\x8b\x66\x96\x04\x89\xa9\xd5\x3a\xda\x5a\x34\x65\x47\xbe\x24\xda\x01\x6c\x8a\x13\x12\xd9\xfe\xbd\x17\xfc\x2e\xb2\x14\xb8\xd3\x9e\xbb\x61\xd0\x6d\x00\xc2\x83\xbe\x19\x62\x03\xc0\xf2\x19\xa4\xfb\xa6\x06\x00\x9b\xa5\x25\x85\x8b\xd9\xf2\xb9\x15\xe4\x24\x01\xf4\x52\xf8\x03\x2c\x64\xaf\x44\xe7\x31\x42\x7b\x9b\x17\xe3\xcd\xe4\x8e\xf2\xe0\x05\x5b\xb9\x42\x6b\x12\xbc\x9d\xc6\xf1\x2a\xae\xea\xc8\xa6\xe5\xc6\x0b\xb3\x6e\xa4\x70\xc6\x1f\xe4\xf3\x28\xc2\x4d\x5b\xf2\xdd\x39\xeb\xff\x00\xae\x5b\x26\x21\xff\x69\x81\xe4\x17\x5e\xa7\xa5\x3e\xc4\xb6\x38\x68\xe6\xd0\xd8\xda\x2f\xca\x19\x61\x4a\xb0\x43\xa4\x85\x8d\x06\xae\x8b\x72\xcd\x73\x96\x69\xdb\x28\xbe\xeb\xa7\xcf\x36\x1a\xa4\xe9\x0b\x52\x54\x1b\xbb\xee\xdd\xdb\x1f\xae\xce\x15\x21\x4b\xda\xa2\x9a\x0f\xac\x3f\xa9\x41\xfb\x28\xc2\xea\x0e\xcb\x08\x47\xd7\x0d\x8d\x4e\x17\xf3\x9e\x94\xc5\x67\x92\xd9\x50\xc3\xdc\x73\x38\xe8\x21\x7e\x29\xb9\x3b\xb4\x07\x69\x6b\xba\x6f\x20\xa8\x2e\xa5\x26\x01\x36\xdb\x10\xbc\x8f\xd4\x1c\x0d\x90\x55\xd4\x1a\xb0\xd0\xd2\x22\xbd\x65\x8b\xa9\xca\xa1\x8b\xfd\x5a\x4d\x87\xdd\x67\x85\xce\x3f\x08\xfa\x65\x06\x39\xfd\x0a\x9f\x6c\xca\x33\xf0\xef\xc4\xe1\xdf\xa4\x16\xda\x73\x34\x77\x3e\x57\xa4\x69\x08\x07\x16\x9a\x7d\xfa\x99\xcc\xae\x3a\x08\x74\xc9\xa0\x0f\x47\x3d\x28\x50\xcc\x2b\x3e\xb5\x9b\xc8\x7a\x79\x5d\xfe\x32\x14\x4c\x04\xd6\xb0\xd3\x6c\x54\x40\xaa\xf5\x92\xc0\xed\xd9\xe7\x3d\xcd\x63\x09\x7a\xf9\x9b\x7b\x2d\xdb\x81\x2f\x49\x15\x84\x53\x56\x6a\xb3\xd4\x81\x5c\x80\x53\x2b\xe6\xa8\x2a\x6d\x4a\xac\x5a\xf7\x24\x95\xff\x4c\x3f\x40\xb6\x76\x78\xe6\x55\x35\x33\x46\xbc\x30\x45\x8d\x2c\x41\x0a\xb5\x41\x83\x7a\x33\xa7\x19\xcc\x45\x95\x00", 4044);
	syscall(__NR_fsetxattr, r[0], 0x20001080ul, 0x200010c0ul, 0xfe1ul, 0ul);
	return 0;
}
