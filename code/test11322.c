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
	res = syscall(__NR_socket, 0x10ul, 3ul, 0x10);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20002240 = 0x200000c0;
*(uint16_t*)0x200000c0 = 0x10;
*(uint16_t*)0x200000c2 = 0;
*(uint32_t*)0x200000c4 = 0;
*(uint32_t*)0x200000c8 = 0x208;
*(uint32_t*)0x20002248 = 0xc;
*(uint64_t*)0x20002250 = 0x20002200;
*(uint64_t*)0x20002200 = 0x20002280;
*(uint32_t*)0x20002280 = 0xec4;
*(uint16_t*)0x20002284 = 0;
*(uint16_t*)0x20002286 = 0;
*(uint32_t*)0x20002288 = 0;
*(uint32_t*)0x2000228c = 0;
*(uint8_t*)0x20002290 = 0;
*(uint8_t*)0x20002291 = 0;
*(uint16_t*)0x20002292 = 0;
memcpy((void*)0x20002294, "\xfd\xbf\xc0\x1c\x2f\xe1\x04\x5c\x38\xec\x83\x89\xb2\x8e\xff\x2b\x22\xf3\xfc\x82\x70\x3a\x70\x4a\xae\xae\x51\x0e\x7e\x60\x10\x02\xca\xcf\x9a\x5d\x0c\x5a\xa4\x86\xf7\x52\x92\x04\x39\x69\xb1\xd9\x4e\x10\xf2\x2e\x2d\x0b\xf7\x21\x91\x84\xef\x0d\x67\xb6\x5f\x9d\xa7\x5a\x39\x23\x07\x70\xcf\x09\xff\xa1\x3f\x1b\x2a\x11\xd7\xc3\xb8\xc4\x27\x5d\xcd\xce\xa1\x10\x9f\x54\x14\x4d\x4d\x40\xf3\x57\x56\x6e\xaa\x70\xf6\x50\x22\x3c\x15\x84\xfb\x41\x0a\x36\x2d\x5b\xa3\x9a\xad\x33\xde\xc2\x7f\x6c\xd3\xbc\x07\x60\xa1\x8a\x2f\x2a\xd5\x24\x64\x4c\x06\x3a\x88\x29\x94\x48\xca\x0a\xd4\x27\xa1\xf9\xcf\x9f\xa1\xf8\x11\x15\x96\x0c\xe7\xe0\x8a\x13\x6e\x8d\xf2\xbf\xa1\x64\xef\xc4\x1f\xb1\x97\x14\x20\x28\xc4\xff\x9a\x26\x9c\x81\x6e\x30\x82\x60\x8d\x48\xe7\xe2\x43\x1c\xd8\xd2\xc8\xf0\x9b\x28\x28\xd0\x57\xe1\x16\xb6\xe6\x33\x66\x5f\xfa\x8a\x1e\x6f\xb6\x4e\xd1\xbe\x41\x7d\xe1\x20\x51\x3c\x25\x6e\xa8\xce\x93\x0f\x5c\xb5\x93\x92\x7e\x37\xfe\x0a\x8c\x46\x61\xbb\x78\xdf\xb1\x68\x3c\x3b\xac\x42\xba\xce\x6c\xd0\x01\x2d\x13\x12\x6c\xe5\x33\x0b\xc5\x5d\x9a\x5a\x70\x99\x59\x84\xf6\xcc\x74\x42\xde\xfd\x7f\xe7\x12\x24\x48\xb1\xff\x39\xb5\x49\xd2\xeb\x10\xad\x8e\x56\x2b\x48\x31\xa0\xce\x1f\xdc\xba\xf6\x62\x5b\x28\x9d\x84\x74\xbd\xf4\x61\x12\xbc\x90\xe8\xcd\x7f\x0e\x91\xc9\x6d\xd7\x13\xc5\x84\x0b\x19\x40\xc8\x4b\xec\xd8\xf7\x3b\x26\x23\x4a\x37\x3e\x3a\x68\x9a\xaa\x91\x44\xdd\x74\xf0\x3b\x19\x78\xf0\xde\xf3\xb7\x82\xd5\x71\xb5\x36\xd2\x21\xf3\xd5\x57\x0c\x0c\x19\xb6\x8c\xbf\x1e\x6f\x67\xe2\x67\xed\x7d\x71\xf1\x51\x36\xe3\x94\xf7\xb9\xd3\x19\xf6\xc6\x8a\x47\xda\xe0\xf4\xfc\x6d\x98\x62\xeb\x61\x2a\xa4\xa8\xc1\x16\xd5\x70\xfe\xb4\xc6\x44\xa0\x47\x5f\x7c\x7a\x9e\x72\xa9\x32\xba\x7b\xfa\xf3\x67\x9f\x9b\xdf\xfd\x91\xde\xbe\xdb\xb5\xbb\x9f\x63\x3f\xcf\x9d\x15\x3a\x7f\xfb\x50\xbc\xc0\xef\x59\xf7\xc9\x6d\xd0\x35\x52\xe5\xf8\x31\x24\x7a\x91\x11\xd0\x69\xaa\x0f\x78\x27\x5a\x3c\xc8\x93\xce\xb0\x96\x8f\x94\x74\xa1\x56\x87\x2f\x5b\xc0\xfe\xc2\x2e\x41\x26\x32\x7d\xb2\x4d\xe3\x97\x9a\x51\x82\x3b\x3a\x5c\xbd\xf7\x51\xb8\x9b\xf9\x9b\xc6\xa5\x0c\xdf\x9c\x1a\x6d\x86\xeb\x1d\x12\x0e\xb3\x00\x51\xb2\x2a\x27\xfb\x40\xdb\x1a\x65\x6a\xce\x62\x8b\xc8\x1d\x15\xcc\xdc\x01\x55\xbe\x1f\x36\xe9\xe5\x08\x35\x85\xd5\x14\x1d\xd9\x91\x97\xf8\xcd\xde\x5a\x8f\xc8\x00\x4b\xad\xc5\x93\x75\x5f\x2b\x4c\x2b\x3b\xff\x24\xeb\xe7\xf3\xc1\xbf\xd9\xef\x18\x6b\xa6\x95\x61\xdf\x0a\xbd\xc2\xa9\xe5\x3b\xf0\x38\x81\xa4\xa1\x48\x7c\x5c\xc1\xa0\xbf\xd1\x80\x50\x60\xba\xa5\xed\xd9\xb9\x50\x8e\x03\x9e\x90\x1f\x1c\x1d\xd4\x28\xca\x77\x40\x34\x63\x70\xe0\x59\xc5\x1e\x75\x46\x91\x7d\x57\xc7\x64\xde\xcd\x9c\xd0\x77\xe5\x31\xbc\x18\xcf\xfd\xac\xdb\x69\x8c\x49\x4b\xd8\x53\x60\x78\x63\x96\xea\xd2\x22\x29\x78\x8f\x83\x7c\xe5\x1a\xb1\x0f\x78\x75\x73\x17\x59\xed\xe9\x4c\x11\x17\x68\x7b\x1b\xdd\x8d\xd3\x44\x91\x3f\xb3\xb8\x8e\xfc\x68\xae\x9f\xa2\x7e\x13\xef\x03\x08\xdf\x56\x97\x26\x0c\xc0\xab\x75\x4b\x73\xf8\xd5\x74\x54\x38\xd4\xa3\xfe\x91\xf6\x7f\xa6\x65\x02\x3c\x10\x7d\xa4\x26\xb2\x70\x1a\xb2\x89\x67\x9d\xb8\x32\xfd\x9c\xc9\x1c\x9e\x35\x9e\x51\x39\x30\xe7\xa0\xbb\xfd\xe1\xc7\x2b\x8e\xc7\xe3\xf0\x7f\x7b\xdb\x95\xa9\xc8\x4e\x7c\x98\xb6\xa8\x60\x19\x4d\x5e\xb9\x2d\x07\x61\x1a\x08\xad\x88\x9f\x81\x3f\x36\x60\xde\xfa\x11\x09\x3e\x5c\xb3\xec\x2d\x5b\x6a\x8a\xb4\x98\x75\xf6\xe2\x93\xe8\x89\x24\x7f\x31\x74\x04\x78\xeb\xd3\xa6\xd3\x5f\x57\x73\xb8\x4a\x09\x04\xc9\x38\x96\x93\x5b\x0a\x7b\x27\x08\xde\x63\x4b\x36\xc7\x46\x85\xa6\x60\xd2\x72\x27\x16\x2b\xc5\xae\x61\x63\xce\xaf\x0b\xeb\xd6\xbc\x51\x20\x24\x44\x47\x01\x3c\xa2\xed\xf6\x1a\x24\xb5\x9e\xf4\x92\x3e\xb7\x24\xd4\xeb\xdd\x99\x40\x03\xd7\x46\x69\xee\x09\xe5\xd6\x59\xce\x6c\x7d\x94\x11\xaf\x78\xa2\xd9\x6b\xa8\xed\xa5\xf5\x4c\xd8\x9b\xc2\xfe\xe2\x33\x75\x1a\x8a\x97\xde\x8f\x76\x49\x40\x9f\x0f\xd0\xe3\x6c\xa0\x40\xaf\x83\xc3\xc9\x5d\x50\x9c\xda\xbb\xbb\x20\x82\x4c\xb9\x09\xba\x50\x8c\x49\x29\x02\xc4\x01\xf5\x5c\x32\x9d\xb3\xff\x89\x7a\x63\x61\xa7\x8e\xe6\x08\x75\xc7\x55\x2f\x3d\x31\x5f\x6a\xeb\x47\x44\x14\x98\xfe\x11\xe2\x58\xe0\x6b\xb2\xa8\x8e\x4b\xff\x5e\xeb\xd8\x71\xea\x7c\x14\xfd\x64\x28\x71\xa8\x48\xce\x73\x86\xef\x23\x88\x1b\x64\xfc\xd2\x44\xfb\x45\x96\x3c\xa8\x47\x83\xf3\xac\xe2\x93\x22\x9c\x7c\xa7\x29\x20\xa6\xa2\xcb\x35\x36\x7a\xf8\xe9\x98\xec\x91\xd3\x35\xa3\xb1\xd5\x0d\x4d\x13\x24\xd0\xcf\xeb\x3d\x00\x6d\x97\xb2\x63\xb0\xf1\xf0\xca\x7a\xb4\x4e\xd5\xdb\x46\x6a\x23\xfe\x58\x64\x2e\x04\x8a\x57\x34\x3f\x10\x53\xda\xf2\x73\xc6\xa6\x2c\xfa\xd9\x51\x11\xa5\x57\x50\xe4\x5b\x86\x04\x73\xf2\x50\x52\x5c\x33\xc2\x01\x7a\x2a\xf0\x43\xa6\xe2\xa0\x14\xe7\xbe\x8f\x3a\x24\xde\xc5\xff\x13\x8e\xf5\xab\x4c\xc6\xf0\x21\xbc\xef\x86\xcf\x0f\x1e\x52\x6e\xca\xf8\x70\xe2\xd4\xd4\xde\x77\x47\xed\xaa\xa9\x00\xfb\x72\xd1\x9b\xd0\x13\x47\x49\x98\xad\xd6\xa5\x7b\x31\x10\x0a\x71\xda\xc5\xcd\x14\x6b\xcd\xd8\x8d\xe8\x0d\x98\x74\xb1\x16\x4e\xda\x0b\x7b\x69\xa2\x9b\x51\x20\x2e\x7b\x90\x47\x52\x88\x0e\xe8\xbd\x0c\x45\x63\x89\x2f\xd1\xec\x3a\x76\x61\x0d\x5c\x05\x0a\x98\xbe\xef\x1c\x69\x45\x20\x99\x29\xbf\xd4\x73\xd2\x17\x70\x6a\xd3\x29\x7f\x1c\xd4\x78\x86\xcd\x8e\xba\x0d\x0a\xce\x30\xe2\xd0\x79\x00\x2d\x67\xfc\xbe\xbe\xc1\x6c\xb5\xfd\x80\xe2\xab\x77\xc1\x82\xc3\x44\x0d\xa5\x8c\x8d\xe7\xa4\x56\xc2\xf9\xde\xec\xfc\x63\x3a\xe1\x09\x4d\x48\xe3\x5b\x64\xc1\xb2\x1a\x36\x1b\xc7\x85\xeb\x96\x4c\xb1\x98\xe5\x55\xc8\xc2\x24\xb6\xbb\x38\x3f\x5a\x4f\x80\xbe\xf9\x51\x7f\xab\xef\x24\xce\xe3\xc2\x68\x5c\xa4\x72\xe9\xcf\xf6\xed\x3d\x17\x65\xec\x02\x6e\x6e\xa1\x66\xbf\xef\x8e\xd0\xd1\xc1\xb6\x8b\x62\xcb\xcd\xa7\xf6\x6a\xdd\x61\x8d\x0a\xda\x14\x82\xa3\x0d\xc2\x04\xdf\xd9\x88\x47\xd0\x5f\x37\x1c\xae\x3c\x41\xcd\xeb\x13\xdc\x22\x1b\xc7\x88\xaa\x70\xae\x43\xbb\x1c\x94\x47\x2e\xbb\x63\x14\x25\xde\x0e\x9f\xff\xe9\xa8\x7a\xdc\x4e\x17\x5a\x11\x83\xa7\x94\x49\x51\x5d\xe1\xf9\x07\x54\x06\x53\x7c\xbf\xd8\x7d\x4f\xd4\x5b\xca\x45\x53\x1b\x1d\x4b\x12\xd1\x43\x69\x00\x86\xad\x37\x12\x4f\x3e\x10\x04\xdc\xb1\x53\x7f\xed\xbb\x80\xbf\x8b\xdd\xdb\xfc\x3b\x6f\x49\x19\xae\x87\x28\xdc\x80\x9c\xb4\x8b\x99\x89\x4b\x8a\xab\x02\x5f\x87\x3e\xcd\xc5\x7f\x79\x2e\x85\xe1\x47\xe3\xa3\xd8\xc1\xc6\x63\xd3\x34\x29\x7e\xff\x19\xa2\xdf\x4f\xac\x81\x19\x4c\xcb\x58\x88\x7d\x65\x2b\xc3\xdb\x93\xa9\xcd\xcc\x12\x16\x46\x93\x8a\xc5\x45\x8b\x34\x08\x02\x0c\xc4\xce\x64\x4f\x4b\xb8\x70\x06\x86\x0e\x6b\xf6\x29\x67\xa3\x60\x76\x45\x46\x98\xf5\xb6\xb3\xc7\x2b\x32\x50\x0c\xe4\x51\xc0\xf4\x50\xce\x35\xa5\x41\xe9\x4c\x3d\xda\x98\xa1\x5b\x1d\x1e\xf2\x61\xe7\x1b\xa3\x2b\xa1\x93\x95\x56\xf7\x63\x61\x03\xd0\x8f\x80\x8c\x51\xb3\x5c\x03\x5e\xc1\x41\xe1\x69\x51\x15\xc9\x14\x73\x16\xb7\x70\xda\x45\xdf\xb1\x58\xec\x25\xb3\x5d\xa7\xc6\x13\x3e\x32\x12\x25\xe4\x80\xb6\xbd\xa8\xa5\x3f\x8a\x69\x2d\xff\x7f\x2b\x13\x05\x96\xb2\x15\x97\xd4\x2d\x5e\xbf\x49\x80\xd3\xf0\xd5\xd6\xbd\x94\x7f\x12\xa6\x5a\x94\xb5\xc6\x6d\xc6\xc5\x17\xce\xd9\x1a\xb4\x38\x7d\x55\x23\xb8\x3b\x58\x69\xe8\xd6\x98\xd4\xa9\x92\x20\x09\x5a\x2e\xf9\xc6\x42\x65\x04\x77\x28\x25\x6c\x6f\x9c\xa3\x00\x79\xd2\x17\x44\x36\xba\x53\xe2\xe1\xfa\x14\xc9\x68\x00\x47\x83\x94\xf4\x93\xd4\x7a\x0f\xf9\xaf\xbc\xa1\xfb\x4f\xfd\x3f\xc4\xfa\x4e\x18\xfe\x3c\x8c\x3b\x5a\xa8\xa8\x9e\xf9\x75\xfb\xd0\x6a\x13\xa2\xa4\xf7\xc0\x1b\x2f\x8a\x47\xde\x15\xaa\x5c\x97\x77\x1b\x7e\xc2\x2b\xd6\xbf\x1d\x11\x60\xb6\xf2\xf4\x11\x99\x6d\xf4\x4b\x3d\xb8\xab\xe8\x2b\x1e\x7f\xe3\x61\xf0\x52\x0f\xf4\x68\xe1\xdd\x54\x37\x7e\x9c\x0b\x20\xec\x5e\x34\x75\x7d\x4b\xe9\x97\x9b\xc7\x16\xa2\x19\xc1\x84\xa1\x4b\xa2\x8e\x74\xa2\xe3\x95\x78\x70\xa5\x0e\x10\x94\x67\x22\xe5\xa6\x0f\x15\x12\xcc\x5a\xaf\x10\x27\x28\xac\xd9\xff\x6c\xb6\x4b\x85\xfc\x1a\x94\xc3\xbe\xf3\x21\x20\xc5\x3d\x44\x7e\x0d\x33\x5f\xd3\xc4\xe1\x84\x85\xee\x0f\xde\xa2\xb1\xb9\xca\xd9\xb0\x4e\xc7\x41\x42\xec\x3a\xf5\x72\xfc\x41\x03\x2a\xd5\xf1\x4d\x48\x41\xac\x06\xa2\x53\xf4\x56\xd8\x6f\xbf\xf6\xc2\xa3\xe1\xcf\x3e\xd6\x0c\x65\x18\x93\x27\xb0\x3e\xf4\x6f\xf8\xbf\xb9\x98\x25\xf1\x23\x85\x90\x2a\x8b\xa3\x04\x85\x2b\xb1\x19\x3c\x48\xbb\x1a\xf7\x6c\xe4\xf3\x89\xfc\x0f\xf4\x4a\xa1\x66\x7c\x9f\xfc\xfe\x6a\xe8\x39\xd3\xda\xc5\x09\x12\x3a\x2d\x04\x46\xf7\xe4\x74\x60\xb0\xee\xc5\x81\x77\x87\x3f\xf6\xbd\x1d\x2f\x91\xf0\xaa\xb7\x31\xd8\xb0\xb0\x69\xc2\x3e\xb4\x12\xd1\xc6\xd9\x5e\x9d\x3f\xae\xa2\xc8\xf5\x4c\x54\xe6\x4c\xdd\x50\x3c\xe7\x4b\xd2\xdc\xca\x71\x67\xa9\xf7\x73\x7f\xf3\xad\xda\x1c\x39\xdf\xef\xb0\xb2\x95\x67\x90\x93\x6e\x40\xbf\xa4\xbe\x98\xc9\x42\x32\x21\x9d\x49\xa6\x9f\xbc\xa5\x67\x69\xeb\xa9\x5c\xbf\x5d\x2c\xc2\x59\x0e\x16\x69\x05\x31\xb7\x1b\x51\x96\xba\x76\xaa\xbe\x21\x80\xaa\x71\xd5\x68\x8d\x95\x1b\x48\x47\x65\xe9\x2e\x46\x66\x36\x69\x47\x68\xad\x9a\x24\x0e\x2a\x36\x46\x71\x91\x27\x29\x61\xde\x24\xe3\x2c\x76\x53\xec\x87\x6c\xa8\x39\x82\x5e\x9b\x43\xae\x1f\x88\x04\x7f\x56\x28\xc8\x49\x09\x4d\x71\x82\xaa\x8b\x35\xe7\x0b\x93\x59\x05\x08\x09\x54\x1a\x41\x1e\xf6\xe7\xbd\xf8\xf6\xb3\x65\x28\xc2\x09\x26\x54\xeb\xc9\x41\x1b\x7d\xe6\xee\xef\xee\x91\xce\xef\x79\xca\xdc\x14\xb4\x04\xc9\xea\xe1\x02\xae\xf9\xae\xea\x1e\x13\xa0\xf8\x40\x88\x40\x45\xe9\xd9\x4d\x27\xe4\x52\x6b\x6c\x0c\x56\x9a\xf5\xc5\x8d\x53\xff\x2b\xf5\x3d\x4b\x95\x4c\x76\x22\xc3\x52\xf2\x67\x7a\xba\xd2\x0e\x24\x4f\x68\xf0\x90\x82\x6a\x48\x9c\xa4\x5a\x04\xc5\x23\xf8\x79\xf6\x62\x04\x5d\x56\xa5\xe6\xff\x3f\x3d\xf1\x20\x67\xc7\x68\x4c\xb0\xeb\x57\x0b\xfe\x78\x04\x22\xd9\x96\xde\xa8\x37\xb7\xf3\xe6\x20\x1e\x19\x05\x8f\x3f\xb6\xc5\x26\xd5\xbc\xf4\x64\xfd\xd3\xcc\x96\xa2\xbd\xb6\xe4\xf8\x25\x03\x41\xa6\x4f\x8c\x54\xb2\x0e\x39\xa8\xd8\xa4\xfa\x13\x86\x9f\x92\xde\x0c\x9b\x22\xe4\xcc\x3b\x94\x50\x7a\xe1\x78\xe4\x58\x18\x60\x59\x7b\xc0\x99\xd2\x11\xb8\x1e\x2f\xf3\xa7\x8c\xf1\x62\x1e\x48\xb8\x96\x7b\x7b\xdb\xe9\x0b\x31\x8c\xdb\x63\x77\xf0\x31\x0d\x5b\x10\x92\x00\xbe\x84\x2b\x5d\x4f\xe5\xe9\x54\x57\xd1\x48\x1a\x1d\x72\x77\x91\xd8\x78\xb3\x0b\x97\x70\x98\xc7\xb8\x65\xbf\x8b\x96\xbe\x14\xf0\xe6\x5d\xaa\x5f\x46\xe6\x14\x6e\x5e\xe1\xdf\x01\xb2\x32\xf4\x2a\xf4\xcc\x1e\xab\x6e\xdb\xc5\xc0\x42\x8a\x4b\x6c\x99\x97\xfb\xa0\x33\xae\x35\x65\x7f\x31\x63\x00\x23\xf5\x04\x01\xbb\xec\x7d\xff\xa0\xf3\x88\xed\xb4\x71\x7f\x36\x66\xfe\xc9\x8e\x72\xa8\x12\x35\xc0\xbd\x7d\xcd\xbe\x52\x1d\x38\x21\xeb\xc5\xd6\xf1\x5b\x1b\x34\x3c\xa6\x7f\x57\x2c\xb0\x7a\xbc\x7f\x8e\x82\x86\x6c\x94\xbf\x93\xf6\x92\x4f\xab\x1f\x56\x65\xfc\x6e\x92\xe4\x77\xc1\x20\x0c\x63\x50\xc6\x69\x05\xc7\xb8\xcd\x6f\x69\x76\xe9\xcc\x97\x3d\x34\xad\xe9\xdf\x20\x60\x8d\x3e\xd4\x71\xe7\x35\x89\x1b\x09\xa7\x05\x47\xf7\xe5\x7f\x72\x0e\xde\x8d\x02\x0d\x8f\x8c\x4f\xab\x10\xc7\x3c\x38\x94\x60\xfc\x3e\xb4\xd0\x76\x98\x7c\xee\x0b\x5f\x30\x45\xec\x47\x70\xc8\x12\xbe\x28\x6d\x5a\x1c\x82\x53\x7c\x5c\xb0\x0d\x9d\x8b\xcd\x9c\xfd\x13\x44\x00\xe3\xa4\xb7\x98\x6b\xe9\x27\x33\xda\x5d\xd8\x81\xb4\x81\x14\x7c\x48\x8e\xd8\xce\xb2\x5b\x30\x03\x69\x58\x45\x4d\x51\xb5\x28\x00\x5a\x56\x25\xca\x4d\x46\x3b\xff\x43\xb2\x53\xeb\xbc\xf0\xbe\x25\xa9\xf8\x16\x69\x12\x5d\x4f\x94\x15\xdb\x7f\x18\x70\xb1\xff\xd9\x83\x70\x14\x24\x1d\xb8\x58\x17\x22\x07\x50\x62\xdb\x16\x62\x37\xab\x28\xd4\x8b\x9d\x22\x32\xdd\x66\x00\x5d\x59\xb4\xc7\xb6\x23\x2b\xa9\x70\xd0\xb1\xa2\x02\xde\x63\x4d\xce\xd2\x43\x90\xb6\x77\xd4\x92\x4b\x1e\x65\xdf\xe0\xd0\xaa\x75\xf3\xdf\x10\x5a\x5c\xaa\x02\x94\x02\x42\x77\xad\xfa\xad\x92\x8b\xe8\x86\xc6\xd6\x0c\xc4\xa0\xe3\xad\x21\xad\xe2\x84\xb4\x21\x3d\x46\xfb\x99\x99\x4a\xa7\x61\x79\x77\x84\x35\xec\x94\x57\xc8\xba\x4b\x7d\x19\xec\x3a\xd4\x4b\xea\x5d\x81\x76\x45\xb0\x9a\xd6\x40\x65\x7a\x6e\xce\xb2\x99\xcf\x1d\x62\x24\xd3\xeb\xab\xde\x2c\xed\x72\x1f\x65\x4a\x66\x8b\xfb\x55\x39\xa0\xf6\x27\x5f\x42\xfa\x0d\x84\x38\x7f\x9e\x04\x1b\xd9\x98\x59\x05\xae\x12\xfd\x03\x2f\xb7\xf2\x66\x6f\x20\x8e\x1d\xc1\x07\x1b\xe6\x36\xa7\x03\x8b\x49\xb2\x6a\x68\x42\x09\x20\x2c\xca\xb0\xc1\x69\x52\xbc\x9a\xa1\x2e\x04\x53\x35\xe8\xae\xff\x9b\x0b\xe2\x1c\xbc\xbb\x44\x7f\x05\xdc\x11\x14\xcc\x68\xd4\xa0\x2d\x81\xd7\xce\x8f\x94\xd9\x31\xec\xf7\xcd\x55\x19\x19\xe8\x58\xe6\xb7\x3f\x4f\x4a\xcd\x8e\xed\x8b\x8b\x98\x65\x61\x24\x64\xc9\x63\x20\xbd\x7f\xb5\xfc\xf0\x69\xeb\xb7\xf9\xa7\xba\xac\xc0\x2c\xe1\x52\x68\xc8\x2c\x85\x77\x33\x19\xb0\xf5\x18\x08\x81\x0b\x0a\x09\xc3\x9c\x8b\xf3\xd3\x55\xb9\xae\x58\x42\xea\x69\x8a\x40\xa2\x1a\x9a\x1b\xda\x7d\x2c\xc1\x35\x03\x9d\xe7\x78\x2b\x22\x29\x79\x0b\xcf\xa6\xda\x66\x3c\xd8\x57\x72\xa8\x23\x29\xff\x77\x80\xf3\x23\x63\x67\x54\x8e\xd8\x36\xc2\xeb\x93\xef\x36\x48\xcd\xac\xeb\x7a\x22\x81\xc2\xaf\xd4\xdf\xd7\xaf\xa9\xed\x5b\xf2\x69\x75\x5e\x0a\xe9\xec\xc5\xe4\x1d\xcd\xe7\x35\x8b\x77\xef\xb0\xfd\x4a\x50\x3b\xf7\x41\xef\x5f\x3d\x62\xc3\xb0\x3b\xca\xc9\x52\x2e\xdf\x4e\xe9\x00\xce\xe7\xf0\x96\x7c\xfe\xe0\x9e\xea\x6a\x3f\xde\xb7\x67\x9f\xad\xe7\x1b\x10\x91\x51\x43\x94\x7e\xa0\x8c\xdc\x64\x2f\x18\xc1\x9b\x67\x1a\xdf\x72\x43\xd2\x91\xf9\xc1\x06\x9e\x85\xc5\x85\x8b\x8c\x54\xeb\x92\xa8\x57\xb4\x67\xdb\x10\x1b\x6f\x30\xfa\xd6\x90\x95\x40\x9a\x8e\x00\x90\xf0\x48\x8b\x0d\x25\xb3\xc3\x26\x82\x70\x83\x40\x6b\x37\xc5\x62\x49\xc6\xfd\xc1\x91\x87\xda\x46\x62\xa2\x3a\x11\x63\x1d\x3a\xa5\xa0\x6e\x24\x8b\x2e\x51\x58\xce\xb9\xce\x7f\x33\x2d\x5a\xaa\xfe\xd3\xda\xd2\xfc\x60\x77\x20\x4c\xd1\x23\x7f\xa2\x10\xfc\x12\xac\xfe\x06\x76\x84\x95\xa5\xcd\xf1\xc1\x0f\x85\x09\x01\x34\x16\xac\xaa\x0d\x77\x89\x76\xcc\x89\x95\x87\x52\x98\x9c\x6a\x3e\x4f\x04\x58\x22\x06\x9e\x8f\x3b\x1e\xb3\x41\xfd\x71\xc0\xe6\x27\xc4\x68\xc1\x79\xb6\xf1\xd3\x35\x1c\xe0\x4e\x23\x03\xe5\x10\xec\xc3\x8c\x6d\x6c\x4d\x28\x3b\x9a\xb1\x76\x59\x76\x94\x78\x8c\x71\x46\x31\x4d\xe4\xf2\xe3\x52\x12\x5e\x2f\xe3\x96\xa2\xf7\x0c\x60\xd2\x07\xbc\x3d\xb0\x07\x47\x0f\xb9\x20\x98\x8a\xb4\x5a\xbc\x76\x86\x1f\xac\x4b\x83\x59\x4a\x33\x41\xb3\xc2\x25\xcd\x43\x60\x54\x3f\x1d\x33\x6e\x26\x2f\xa9\xd9\xad\x8b\x8a\x50\x7e\x02\x11\x5f\x9e\x91\x29\x90\x6b\x87\x70\x31\x16\xea\x7b\x07\x82\x5a\x08\xc8\xf2\x16\x06\x64\xd1\xc5\x9b\x25\x75\xaf\xd7\x7a\x3b\x12\xeb\x50\xcc\x07\x9a\x9a\x4b\x45\x3e\x1f\x8b\xc0\x99\xd1\x76\xea\xd6\x61\xd8\x59\xf2\x8b\xa8\x41\x8a\x89\x3e\xe3\x94\xa6\xae\xf8\x65\x6d\x79\xab\x6e\x1c\x35\xfd\x2d\x8a\xfd\x2a\xb2\x7d\xc6\xbc\xe1\x62\x5f\x24\xa4\x43\xd4\x82\xf9\x10\x25\xde\x62\x3b\x3b\x94\x17\x11\x30\x38\xa8\xd0\x25\x17\xf1\x9e\x72\xe6\xeb\x7a\xd5\x9a\x1a\x64\x02\xae\x89\x1d\x8c\x3c\x65\xa3\x80\x41\x79\x9c\xd4\x41\x0c\x62\xb8\xad\x4d\x2c\x0b\xca\xba\x7e\x53\xcd\x8c\xcd\xf2\xa2\xc5\xbc\x78\x95\xb2\x86\x1f\x8c\x55\xde\xa1\x29\xc3\x09\x2a\x66\x2b\xff\x17\x80\xf0\x50\xf0\x5c\xb7\xa9\x24\x76\x99\xf8\x3d\xc0\x0b\xb4\xb6\xb2\xf3\x4d\x11\x1b\x52\xf7\x99\xe5\x44\x6e\xe1\x83\x9b\x0c\xdd\x2c\x77\x24\x66\xf4\xe2\xe7\x5a\xdd\x58\xab\xdf\x5d\xa5\x12\xe9\x7a\x4a\xfe\xda\x0b\xec\xd3\x1d\x69\x39\xa7\x32\x2e\xeb\xe0\xb6\x8b\xb5\x15\x7f\x9b\x70\xd2\x50\x5c\x3a\x33\xa5\x8e\xd8\xe8\x37\xbc\x23\x49\x32\xfc\x84\x6c\x5c\xbb\xbf\x92\xcb\xa7\xa9\x9c\x2d\x96\x8f\xdc\x91\x4f\x2e\x20\x5a\xa0\xaf\xed\xb8\xd2\x91\xe9\x95\x60\x7d\xbd\x80\xa1\xd0\x3d\xdd\x01\x64\x9e\x89\x44\x0a\xdc\xa7\xc9\xc6\xaf\x52\x2d\xb8\x04\x9a\xd4\xba\xc0\x66\x00\xf6\x09\x1e\xb3\x3c\x26\x12\x3b\xf5\x3c\x6a\xdb\xfb\x91\x12\x65\x49\x13\xc4\x9b\x09\x2d\x55\x71\x93\xb9\x69\x8c\xcc\x95\x75\x95\xe9\xfc\xea\x77\x8c\x0d\x06\xa0\x3d\x0c\x42\x64\xc9\x60\x64\xe1\xcc\x73\xb3\xa3\xb8\x23\xe4\x61\x5e\x5e\x40\x3e\xa0\xfd\xa3\x56\x74\x89\x54\x02\xc9\xa2\x91\x2c\xb6\x77\x63\xf8\x71\x77\xce\xc0\x2d\xc2\xbc\xb6\x15\x65\x2d\xa8\xac\x95\x9e\x57\xd1\x0e\xdd\x6e\xcf\x0d\xf3\xa8\xf5\xd9\x3a\x31\x7d\x7e\xa5\xd5\x3d\x0f\x0e\x5d\xd9\x8b", 3757);
*(uint64_t*)0x20002208 = 0xec4;
*(uint64_t*)0x20002258 = 1;
*(uint64_t*)0x20002260 = 0;
*(uint64_t*)0x20002268 = 0;
*(uint32_t*)0x20002270 = 0;
	syscall(__NR_sendmsg, r[0], 0x20002240ul, 0ul);
	return 0;
}
