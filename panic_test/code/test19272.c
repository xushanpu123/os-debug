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
	res = syscall(__NR_socket, 0x10ul, 3ul, 4);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200015c0 = 0;
*(uint32_t*)0x200015c8 = 0;
*(uint64_t*)0x200015d0 = 0x20001580;
*(uint64_t*)0x20001580 = 0x200001c0;
*(uint32_t*)0x200001c0 = 0xec4;
*(uint16_t*)0x200001c4 = 0x13;
*(uint16_t*)0x200001c6 = 0;
*(uint32_t*)0x200001c8 = 0;
*(uint32_t*)0x200001cc = 0;
*(uint8_t*)0x200001d0 = 0;
*(uint8_t*)0x200001d1 = 0;
*(uint8_t*)0x200001d2 = 0;
*(uint8_t*)0x200001d3 = 0;
*(uint16_t*)0x200001d4 = htobe16(0);
*(uint16_t*)0x200001d6 = htobe16(0);
*(uint32_t*)0x200001d8 = 0;
*(uint32_t*)0x200001dc = 0;
*(uint32_t*)0x200001e0 = 0;
*(uint32_t*)0x200001e4 = 0;
*(uint32_t*)0x200001e8 = 0;
*(uint32_t*)0x200001ec = 0;
*(uint32_t*)0x200001f0 = 0;
*(uint32_t*)0x200001f4 = 0;
*(uint32_t*)0x200001f8 = 0;
*(uint32_t*)0x200001fc = 0;
*(uint32_t*)0x20000200 = 0;
*(uint32_t*)0x20000204 = 0;
*(uint32_t*)0x20000208 = 0;
*(uint16_t*)0x2000020c = 0xe75;
*(uint16_t*)0x2000020e = 1;
memcpy((void*)0x20000210, "\xa8\x0b\x52\x69\x49\x50\xef\x8e\x66\x18\x77\xaf\xcc\x6a\xfc\xfb\x1f\x71\x92\x2f\x8d\xb6\xf1\xfb\xf5\xc8\x4c\xb4\xdb\x7f\x73\x8c\xb8\xa1\x5b\x4a\xac\x81\x44\x00\x46\x92\xb2\xf1\x7e\x8b\x74\x94\xc4\x2f\x91\x79\xcd\xfe\xa8\xcc\xd4\x20\xf1\xf5\x76\x4d\xe2\x19\x4b\xa1\x6b\xf1\xb8\xad\x20\xad\x29\x44\xb8\x81\x86\x61\xf8\x93\xd6\xa2\x56\xe6\xa0\x21\xdf\xa3\x8c\x54\x37\x7e\x27\x27\x65\xca\xf5\x48\x4f\x6b\x53\x0b\x93\xd0\x3e\x7d\x9f\x03\xa8\x0e\x4f\xdf\xc3\x88\xc8\x53\x7f\x35\x8a\x69\x77\xa8\xec\xdd\x0b\x41\x2b\x39\x6a\x62\x92\xc4\x34\x62\x19\x2f\x0a\x22\x57\x34\x78\x5d\x4b\x20\xdb\x8b\x4d\x68\x77\x65\xcf\xc1\x13\x13\x2c\xc2\xee\xf7\xcb\x67\xd4\xce\xb0\xa9\x6e\x0c\x26\xa4\xd1\xa5\x4d\x04\x01\x2f\x08\x0c\x4f\x15\x6d\xb5\x5d\x60\x77\xaa\xbd\x3d\x0c\x21\x7d\x90\x7c\xc8\x36\x81\x0a\x9d\x0f\x04\xa4\x0e\x00\xfa\xab\x6d\x37\x53\xff\x71\x18\xbe\x8a\x3d\x60\x4f\x92\x82\xe4\x94\x2e\x99\xab\x9a\xc8\xa1\x74\x3c\xf2\x1c\x16\x42\xe3\x48\x69\x8c\xeb\x03\xa4\x1e\xce\x09\x7d\xb5\x85\xaa\x88\x2e\x6e\x8f\x71\xf1\x7f\xe1\xc2\xaf\xe3\x8a\x81\x5c\x17\xaf\x41\xd2\xa0\xd9\x30\x94\x5e\x18\xd9\x8a\x16\xc4\xad\x66\x07\xcb\x85\x3f\xb5\xe4\x21\x7f\xbe\x11\xcd\xdb\x91\xb0\x09\x9b\xe7\x72\x2d\xe6\x9b\x83\x57\x4e\x2d\x34\x57\x1e\xa2\x7c\xb8\xe4\xea\x59\x47\x13\x2b\xca\xb0\x1c\x96\x8d\xc6\xfb\x90\x44\x36\xf5\x7e\x0c\xd0\xb6\xb6\xb8\x3c\xff\x11\xf5\xb4\x48\x76\x48\x72\xa5\x00\xa5\x1a\x1a\xb5\xa1\x57\x26\x97\xaa\x0c\x9c\xc5\x84\x0e\x7b\xbd\xca\xbd\x03\x61\x68\x11\xab\x70\xb8\xf9\x15\x71\x5b\xb2\x75\xe6\xcc\x17\x81\x24\xe4\x1e\x7a\x5b\xb5\x09\xdf\xd4\xd7\x67\x0e\x7d\x71\x8a\x8e\x6f\x0b\x7a\xb4\x59\xa6\x4e\x72\x85\x80\xa1\xd6\x94\x79\x91\x4e\x5f\x97\xa7\xc8\x5c\xc4\x66\x80\x55\xb2\xce\x47\x57\xe4\x8b\xe7\x27\xd5\x83\xea\x50\xf7\x10\xe0\x32\x44\xca\x8b\x78\xec\x3d\x63\xcf\xce\x6b\x1b\xac\xad\x20\x43\x71\x03\xab\xc2\x9c\xbf\xf6\x13\x21\x26\x95\xa2\xda\x93\x75\x41\x81\xa6\x10\x72\xa9\xdc\x2e\xb8\x91\x5d\xb6\x9c\x98\x1a\x3b\x32\x73\x1a\xef\x14\x07\x67\xce\xde\x55\x16\x74\x10\xdf\x79\x43\xd6\x0f\xb6\x37\x24\x58\x7c\xc6\x8e\x37\x18\x25\x58\x39\xa6\x0a\x8d\xce\xa9\xa9\xc7\x99\xfb\x08\xe6\x70\x9f\x09\x9d\xce\x2b\x6d\x6f\x21\x61\xa5\x58\x5f\xb6\x77\x6c\xef\xd5\x6f\x5d\x07\x73\x88\xd4\x4e\x01\x54\xd7\xdc\x04\x05\xc6\xa6\x96\x5b\xf5\x99\x9a\x60\x77\xa5\x6e\x5b\xa8\x8b\x3e\xf5\x2c\xd2\x25\x8b\x80\xb8\xb3\xde\x30\xcc\x48\x13\x03\xbb\xfc\xd4\xf5\xd8\x97\xcd\xea\x9d\x05\x2b\x04\x60\x33\x72\xef\x7b\xc2\xba\xad\xff\x1e\x5a\x9b\x9c\xd4\x8a\xa0\xc0\x1e\x54\xc5\x0f\x49\xf6\x0a\xa9\x1c\xba\xcf\xd6\x64\x15\x08\x97\xe4\xf6\xa1\xaa\x4b\x80\xae\xfe\x57\x30\x5d\x60\x4c\x37\x6c\xa1\x2a\xfd\x0e\xbf\x93\x4e\x5c\x82\x6a\x77\xd0\x6c\xd9\x41\x7d\x73\x98\x06\xf8\x87\x4b\x70\x32\x5b\x43\x2b\x6c\xa9\xcf\xf4\x31\x8b\xd0\x21\x0c\xc7\x4c\x27\xb2\xfc\x89\xdb\x5f\x4a\xe2\x26\x5f\x14\x2b\x54\x25\x2e\xf8\x06\x6b\x8a\xb3\x2a\xba\x68\x77\x1e\x75\xaa\x28\x8c\x19\xf7\xcc\xf8\xd1\x33\x0d\x4b\x0a\x1f\x55\xbc\x70\x23\x34\x8c\x74\x16\x1c\xf5\x81\x7c\x98\xce\x81\x7f\xe5\xd5\xa0\x7a\xec\x08\xa2\x37\xde\x3f\x48\xe8\x9b\x80\x0e\xd1\x10\x78\x87\x53\x4e\xa5\x3d\x7d\x7f\xcc\x9d\x9f\x69\x29\xa0\xd3\xce\x71\x0f\x3d\xe4\x84\xe8\xce\xc6\x89\xed\x33\x09\xbe\x73\x5c\x3b\xd6\x12\x9a\x1e\xbe\x16\x7c\xf7\x5c\x80\x90\x2e\xdd\x16\xbe\x4b\xbc\xe9\x37\x57\xe3\xaf\xf6\x6f\xbb\x1b\x7b\xf0\xd0\x1b\xca\x3f\xc6\x87\x46\x67\xbf\xdf\x15\x3d\x53\x98\x48\x8b\x2b\x8a\x8f\x45\x34\x28\x18\x1a\xab\x4d\xc4\xa2\x80\xd9\x75\x3c\xb2\x76\x83\x5d\xd2\xac\x39\x4a\xfd\x98\xad\x43\x2a\x43\x84\x49\x88\x4c\xcb\x60\xb4\x0f\x8f\xe1\x90\x89\x9f\xbd\x94\x5b\x87\x2f\xb3\xb8\xb4\x76\x5e\xa1\x65\x6e\x84\x5c\x91\x94\x89\xab\xee\xca\x9b\x78\xe0\xa3\x3f\xa6\xb8\xa1\x80\xdd\x13\xd8\x32\x1c\x31\x56\xa6\x5e\x92\xb8\x6a\xd9\xe9\x59\x0e\xe7\x67\x06\xa7\x79\x26\x33\x87\x0d\x5e\x33\xd5\xd1\xc1\xaa\x8e\x84\x05\x57\x01\x26\xeb\x97\x43\x3d\x62\x5e\x18\x6b\x7a\xfd\x76\x22\xb2\xe1\x67\xdc\x53\x54\xaf\x73\x09\x56\x7f\xeb\xe3\x23\xa6\x12\xef\xeb\xfb\x68\xd4\x9c\x5f\x9a\x72\x61\x8c\x90\xd1\x5d\x9d\x73\xe6\x0e\x4e\x1d\xb6\x51\x88\xa7\xc0\x28\x34\x90\x47\x8a\x42\x09\xe6\xa0\xaa\x64\x8c\xf7\x4d\x28\x28\xce\x58\x5a\x21\x1c\xc2\x9d\x1c\xc9\x2d\x9f\xe0\x90\x63\xdd\xd3\x38\x91\xcd\x39\x21\x95\xfd\x22\x09\x66\xf4\x73\x22\x53\x7a\x98\xe4\xae\xa3\x54\x07\x70\xfd\xd5\x0c\x29\x58\xbb\x9e\x24\x6a\x20\x7d\x7e\x47\x16\x45\xe1\x5b\xd6\x72\x0b\x7d\xa6\x26\xd0\xb7\xaa\x33\x8c\x3d\x90\x47\xca\x8c\x8c\x24\x28\x4c\x79\x31\x8d\x68\x35\x06\x72\x3a\xa2\x35\x7c\xc6\x46\xe3\x1b\xa8\xaf\xbc\x9b\x0a\x04\xd3\x1b\x44\xdf\x50\x3e\x03\xca\x8b\x31\xb8\xf1\x9a\x94\xeb\x1d\x8d\xea\xa1\x56\xe3\x11\x97\x94\xb6\x29\x9b\xe2\x8e\xe7\x57\x77\x39\xcf\xd6\x70\x34\x39\xef\x40\x17\x29\x84\x31\xf6\x8c\xba\x2c\x3c\x4a\xad\xa2\xb9\x46\x61\x60\x96\x5a\x2f\x41\x4a\xc0\x35\x12\x41\x1a\xe4\x15\x13\x4a\x0c\x1b\x09\x04\x05\x42\xbc\xd6\x5f\x12\x71\xe8\x37\x22\xfc\x5d\xc9\xe3\x3c\xfc\x7f\x11\xf3\x1d\x24\x13\x8a\x38\x35\x05\x34\x9a\x0a\x46\xc0\x04\x00\x45\x45\x33\xdf\x11\xec\xfe\xd9\x89\xcf\xc3\x85\x6c\xa8\xeb\x10\xf9\x0d\x23\x86\xd7\x1f\x5e\x17\xd0\xd9\xc4\x51\x5d\x70\x99\xfa\xbf\x05\xfa\xc0\xe6\xaa\xce\x2e\xba\xcf\x6b\x5c\x07\x35\x6a\xd0\x88\x2d\x22\xf4\x81\x01\xa5\xa8\x28\x4d\x83\xca\x54\x56\xd2\x06\xa8\xb8\x64\xf7\xf7\x1d\x00\xe3\x2b\x43\x28\x89\xea\x43\x7b\x29\x28\xbc\xef\xad\xc0\xf9\x97\xa6\xf9\x8e\x47\xc3\xf5\x28\x74\xf0\xa8\x9d\xdd\xbc\xf1\xb7\x5a\x59\xcb\xe1\x21\x67\xc9\xce\xde\x5d\x65\x07\xa8\x43\xc0\xdc\xee\xa2\x7c\xa2\xba\xf7\x77\xcc\xf3\x88\x15\x74\xa8\x50\x9d\x7f\xd4\x07\x2a\x98\xea\x02\x6a\xcb\x6d\x10\xe7\xf9\x40\x5e\x78\xae\x8e\xc5\x89\x48\x73\xf9\x46\x13\x81\xba\x11\xd8\x5d\x6f\xd8\x75\xe2\x58\x28\x63\x38\x0c\xc9\x53\x79\x64\xc1\xaf\x0d\xf1\x26\xf3\xa0\x84\xc0\x14\xfa\x8e\x8f\xf0\x36\xba\xc9\xc0\xa5\xa5\xa3\x34\x23\x06\x2d\x53\xe3\x30\x5f\xfb\x33\xa5\x75\x01\x12\x57\xfa\xf2\xc3\x90\x14\x62\x98\x5b\x9e\xb4\x2f\xa3\xba\x6d\xd4\x50\x7a\x47\x6a\x33\xfe\xc0\x61\x0e\xaf\x9c\xe2\x79\x41\xf4\x33\x5a\xbc\xe5\x1e\x21\x82\x1f\x95\x0a\x0d\x0e\x7f\x81\xc9\x9a\x40\xe8\x85\xc7\x99\xc7\x16\x95\xbe\x3a\xc7\xdb\x1b\x8c\x30\xf8\xfe\xe7\x56\x6f\x8d\x64\x47\x0e\x2b\x54\x1a\xf5\x53\xda\xdb\x95\x86\x03\x2a\x17\xc6\x16\xb8\x51\xb7\xd8\x29\x90\x8d\xcb\x50\x66\x64\x8c\x78\x51\x83\xb8\x88\xc9\xb7\xd2\x63\xae\xaf\x91\x04\x0f\x3b\x80\x28\x56\xd2\x67\x52\xb7\xd2\x88\x21\x56\x7d\xbe\x9e\xec\xf5\xc6\x55\x10\x88\x7a\xe1\xa1\x65\xda\x6a\x51\x20\xcf\x7d\xd8\x2f\xf9\x03\x3f\xe5\x7b\xc9\x9f\xa0\x37\xaf\xf1\x90\x49\x8d\x07\x37\x50\x1e\x7e\x47\x2c\xb6\x68\x55\x08\x75\x18\xeb\x94\xae\xed\xae\x68\x6b\xf4\x6c\x36\x2c\xbf\xac\xa0\x97\x22\x31\x80\x80\x63\x9c\xd0\x1e\xf5\xda\xf5\x23\xec\x36\x07\xcb\x97\x6b\x4d\xa1\x4b\xd7\x13\x96\x0a\x7b\xc8\xe7\x1f\x45\x95\x03\xac\x07\xf4\xdc\x65\x53\xf5\x54\x87\x18\x37\x60\x98\x60\x0d\x18\xf3\xab\x35\x02\xe6\x1a\x2e\x6e\xa4\x3b\xb6\xca\xa1\x70\xd0\x00\x9b\x6d\xdc\xe0\x9a\x77\x4f\xd9\x30\x71\xb3\x4e\xf8\xe0\x70\x55\x87\x48\xac\xd6\x02\x69\x47\x5e\x6c\x2d\x65\xc6\x90\x28\xdf\x3f\xb9\x5d\xde\x60\x56\x77\xd9\x24\x96\x8c\x49\x83\x3d\xc3\x2b\x9a\xe0\x55\xd4\x14\xd6\xdf\x51\xe7\xa7\x86\x74\x05\x94\xb7\x29\xc1\x36\xa9\x62\x10\xb0\xf2\xb8\x22\x54\x9e\x0a\xfc\x50\x84\xfe\x51\xf1\x5f\x4d\x82\xbd\xb3\x2a\x23\xa0\x1d\x30\x1d\x8e\x70\x8c\xeb\x75\x25\x95\x25\x9c\xca\x99\x45\x45\xfb\xdb\x29\x02\x5e\xd2\xe1\x2d\x95\xcf\x88\x27\xc6\x76\xfd\x60\x88\xa5\xb4\xe5\x93\x9b\x0e\x60\x2e\xc0\x85\x21\x34\x4e\x0b\x60\x8b\xd7\x9c\xed\xc1\x19\x48\x26\x56\xc3\x04\xd1\xcc\x06\xb3\x54\xe9\x12\x49\xa4\x27\xd2\x83\x56\x61\x19\xdc\xa1\x5e\x07\x18\x61\x56\xb6\x55\x8e\xf0\xfe\xa8\x48\xeb\x50\x4e\x87\xc8\x1e\xfa\xec\xad\x02\xfb\x22\xc5\x5c\x3d\xe0\xe9\x73\xc2\xd1\xe2\x2f\x6a\x11\x9d\x95\x84\xaf\x89\x00\xf7\x6a\x29\xd9\x39\xe5\x5a\x94\xee\x1e\xd9\x05\x38\x4c\x75\x20\x4a\x46\xc1\x93\x0a\x90\xf9\x97\x0d\x2e\xb0\x74\x56\x2e\xe3\x3b\xbd\x77\x9d\xb0\x92\xba\x21\x44\xac\xae\xe1\xe3\x18\x82\xff\x2a\xdb\xf6\x50\x11\x3c\xab\x29\xdb\x0a\x5d\x47\xb8\x58\x85\x99\xe8\x9c\xf4\x24\x83\x51\x88\xea\x15\xcf\xad\x38\x9b\x4c\x38\xfa\x4b\x3c\xc2\x98\x2f\xa6\x16\x60\xe2\xf5\xec\x31\xb6\xad\x3a\x8a\x6e\xf2\xc0\x74\x6e\xb7\xbd\xc5\x50\x4e\x07\xee\xb4\xac\xbb\x4a\x8d\x7f\x13\x45\x16\x83\x22\xc8\x05\x45\x88\x2c\x47\x89\xff\x22\x47\x1a\xf8\xf1\x73\x22\xb5\x56\x95\xec\x45\x5a\xcb\x5e\xdf\x80\xe3\xfa\x84\x96\xd4\x4e\x94\x14\xad\x1d\xe7\x31\x32\x92\xb5\xe9\x0f\x40\x1a\x18\xdf\x02\xfa\xed\x45\xe1\xaf\x78\xfa\x9b\x8b\x11\x0d\x6f\xc4\xa7\xd7\xc3\xbc\x81\x82\x5b\x1c\x82\x0a\xc5\x4a\xf0\xa0\xa9\x8e\xe1\xf7\x5a\xc5\x0a\xb9\x16\xa5\x28\xa2\x6c\x5a\x27\x89\xf4\x64\xb2\x86\xbc\x03\xb9\x22\x76\x41\xb8\x31\x21\x75\xf8\x41\xc7\xd7\x31\x3d\xaf\x63\xa4\x89\x1e\xde\x78\x0f\x07\x0c\x66\x19\x8e\x35\x14\x3c\xb7\xb2\x13\x41\x6f\x7d\xa5\x35\xcb\xb2\xf4\x29\x0a\xec\x71\xed\x83\xfe\x52\x0b\x86\x3d\x79\xef\x4d\x56\x38\xab\x56\x74\x29\xc7\xc6\x2e\xac\xb0\xa4\x76\x99\xba\xa7\x9e\x27\xe0\x71\x6b\x15\x3f\x6c\x39\x89\xfd\xd6\xf2\xaa\x79\x14\xf6\x66\x92\x2c\x4e\xc1\x2a\xb8\xc9\x0a\x3f\xc3\xf4\xda\x98\x4c\x6d\x8a\x75\x42\xc6\x8b\xff\xff\xea\x14\x95\xd0\x77\x93\x73\x77\x04\x26\x31\x0a\xcd\x75\xa4\xe6\xed\x59\x09\x0b\xa9\xa3\x5c\x88\x82\x3f\xc5\xe2\xa7\x10\x39\x7b\x7d\x2a\xf7\xec\x71\xb5\x19\xd5\xf3\xcf\x8d\x1b\xfa\xb5\x50\xd4\x0a\xb3\x19\xd8\x66\x3e\x4f\x4d\x0d\xc9\x63\x81\x2b\x48\x48\xfc\x9e\x50\x37\xaa\x80\x3f\xf6\xe9\xfa\xd0\x22\xe2\x88\xd4\xd1\x0e\x9a\x04\x2f\xc6\x5d\xf8\xa9\xc3\x3e\x50\xd5\x6b\x43\x30\x6d\xd6\xb7\xdc\x73\x1a\x4a\x4d\xf8\xc2\xbb\x95\x28\xc9\x9d\xf8\x78\x36\x7a\xd3\x11\xdb\x6d\xf8\xfc\x38\x5f\xb7\xab\xee\xc4\x98\xbc\xae\xa2\x0d\x69\x2a\xe2\x91\x88\x9e\x7d\x74\xb1\xd6\x53\xf1\xf1\xa8\x4c\x7d\x2c\x0e\xb5\xaf\x24\xf2\xf1\x58\x79\x7a\x53\xb1\x35\x43\x6f\x2e\xdd\xc2\x93\x71\xd6\xbf\x91\x01\xe3\xb6\xec\x6c\x56\xd9\x79\xfc\xea\xce\x1a\xb9\xa2\x12\x65\xdf\x48\x47\x24\x05\x9c\x63\x7d\x29\x11\xa2\xf8\x23\x59\x1a\x5f\x4d\x03\x89\x39\xac\xf7\x0f\xb8\x4d\x5d\x6b\x11\x14\x15\xdd\x0f\x6f\x81\xd2\xad\x37\x2d\x99\x92\x35\x60\x04\x8e\x89\xe3\x5f\xce\x70\xaa\x37\xd3\x85\xf2\xe0\xca\x41\xa2\x5f\x2d\xa8\xff\x07\x05\xf5\x0e\xda\x17\x9e\x0f\xb1\x80\xe8\x04\x2c\x70\xf6\xd6\xba\x12\xc9\xc7\x55\x2c\x3a\x4e\xd0\xe2\x1a\x7e\xa7\x6d\x0d\x17\x23\x01\x05\x1d\x9b\x33\xa7\xae\x8a\x41\x82\x47\x28\xe4\xaf\xdc\xa8\xfd\xa2\x8a\x0c\xa4\x3a\x1a\xca\x74\x14\x37\x25\x9c\xe6\x0b\x48\xb8\x2e\x8d\x05\xb8\xaa\x47\x0b\xf5\x4f\x60\xc8\xb9\x4a\x56\xd1\x4d\x38\xa4\x5a\xd2\x3c\x84\xf3\x26\x79\x5b\x94\xf1\x39\x97\x7c\x82\xe2\x6d\x17\x07\x0b\x26\x5a\xf9\xb0\xd4\xdd\xfe\xf9\x45\xe1\xbe\x89\x8c\x98\x03\x72\xd7\x84\x37\x99\xd2\x60\x4c\x01\xfb\x32\x4d\x2a\x87\xe9\x3d\x0c\xb0\x36\xfc\xcb\x21\x18\xca\x22\xa5\xb7\x82\xed\x36\xbf\x33\xdb\x1c\xde\x76\xa7\x52\xf2\x56\x29\x1a\x87\xc1\xc4\x8e\xaa\xc8\xc7\x14\xa6\xff\xe2\x69\x72\x68\x80\x0e\x04\x72\xd5\x53\xfd\x11\x28\x00\xca\x58\x1d\x4b\xc4\xf4\xc5\x04\x8c\xa8\xa1\x42\xfe\xce\xcc\x6f\x51\xc6\xbf\xdd\x99\x46\x14\x55\x2d\x23\x73\x4f\x0d\xef\xfb\xc8\x58\xe5\x00\x85\x2e\x24\x02\xe9\xa4\x0b\xff\xf7\x92\x6b\x31\x07\xbc\x19\x71\x63\x02\x94\xb4\x81\x6f\x04\x98\x63\xe6\x84\x33\xf3\x30\x52\xb4\xab\xa1\xbd\xbf\xaa\x58\x57\x10\x38\x81\x69\x10\x34\x56\x85\x54\x5f\x81\xd7\x3d\xb0\x0b\x6e\x1f\x83\x43\xef\x53\x55\xc1\xc5\xc2\x57\x82\xd1\xa6\xc2\x89\xaf\x3b\xd4\xb4\xc7\x19\xbe\x4c\x22\xed\xa0\xbb\x20\x5d\x5b\x6d\x5b\xac\x5c\x92\xc4\xfb\x6d\xdc\x36\xf1\x26\xbe\xc1\x9f\x56\x7a\xd0\xde\x14\xf6\x22\xe3\xa7\x54\x54\x72\xeb\x29\xcf\x15\xfb\x02\xae\x4b\x5a\xdb\xc6\xe3\x63\x11\x15\x34\x13\x54\xa3\x51\x97\xc4\x5c\xc2\x7b\x6b\xe5\xd1\x3c\x6f\x08\xbb\x49\xd3\x27\x64\xb0\x9c\xa2\xb3\xec\x3b\x8c\xac\xf2\x14\xb4\x02\xbb\x7d\x81\x5b\x81\xc7\x21\x84\x6c\x33\xa8\x3d\xee\x54\xae\x2f\x86\x44\x15\x65\xd7\xee\x02\xda\x45\x82\x9f\x8e\xe0\xba\xe9\x16\xa3\x88\x56\x19\x6f\xb3\x81\xe5\x6e\x61\x07\x7b\xd8\xbb\x2e\xad\x52\xd3\x31\x4d\x12\x14\x58\xe3\xa7\x17\x7e\x9a\xd5\xae\xab\x2f\xa9\xc7\x6a\x12\x44\x4d\x54\x48\x40\x96\x2e\x7e\xff\xb7\xa7\xcb\x37\x96\x12\xed\x88\xbf\x21\xd1\x6a\xdf\xf7\x47\x02\xe9\x24\xd7\x9a\x4b\x91\x42\x4d\xb5\xe4\xcf\x61\x14\xa5\xab\xa9\x6b\x66\x4e\x2a\x67\xbf\xac\xa1\x66\x18\xbd\xd6\x4a\x83\x5d\xd9\x54\x3a\x46\x7f\x18\xb2\xb8\xa6\x73\xc8\x7e\x12\xb7\x97\xba\x77\x63\x5f\x2f\x77\x3f\x13\x93\x7e\x3b\x59\x3b\xc6\x25\xee\xc0\xe9\xae\x52\x6f\x22\x79\x3b\x79\x4f\x15\xeb\xb7\x67\xa8\x49\x8b\xb7\xd2\xeb\xd7\x64\x4f\xa6\x2b\xc1\x21\xd6\xb2\xc5\x0d\x61\xbf\x28\x76\x99\x80\x59\xb2\xd0\x36\x3a\x6a\xdd\xdc\x7e\x0a\xc9\xf2\x94\xff\x12\x96\xf6\xb4\x47\xa4\xfe\x25\xeb\x7a\x15\xe7\x7b\x15\xc4\x72\x95\xf6\xd1\x19\xd2\xcf\x1d\x00\xf7\xbd\x26\x72\x7a\xd5\x94\xe3\xf9\x1a\x61\x83\x4b\x79\x0b\xa9\x8d\x24\x18\xa7\xa6\x33\xa2\x1e\x8a\x87\x63\xb6\xe1\x3e\x87\xb2\xa2\xbf\x4f\x20\xe3\x3b\x36\x33\x96\xfc\x2a\xa0\x2c\x5d\x03\x7f\x6a\xac\x90\x11\x6e\xc3\x07\x63\x69\xe5\x55\x22\x2b\x21\xae\x8f\x1d\x90\xe0\xfe\x2d\xe7\x99\xd6\x0a\x4a\xde\x5c\xd3\xad\xeb\xbc\xeb\x25\x40\x40\x9e\x8c\x6f\xfe\x34\x8a\x42\x43\x0c\xc8\xc9\x95\xf7\xc5\xfb\xae\x23\xa5\xf4\xce\x5e\x7f\x0d\xa8\xc1\xb0\xf4\x03\xd6\xe0\xe0\x44\x09\x05\x02\x37\x51\x7a\x2c\x83\x98\x0e\x20\xd5\xe9\xa9\xbb\xa8\xec\xa7\x7e\xff\xb5\x46\xf0\x65\x6d\x37\xfa\xcf\xa3\x1b\x8e\x94\xef\xc2\x89\x20\x13\xb8\x40\x80\x91\xd9\x34\x62\x2b\xa7\x67\x9e\x11\x97\x03\xd9\x37\xa4\xb8\xe8\x99\xc0\xbc\x19\x49\x1c\x7b\x24\xe0\x98\x84\xcf\x81\xaa\xf4\x6b\x05\x17\x1f\x27\xdc\x9b\x3a\x95\xf1\x5d\x11\xb0\x6d\x30\x08\x68\x8e\x90\xa7\x72\x89\x3a\xc4\x56\xa3\x12\xe4\x9c\xd3\x70\x05\x89\x52\x8f\xcf\xcc\x21\xce\x45\x30\x3e\x68\x7c\x42\xe8\xfd\x82\xed\x66\x52\xa6\x3f\x02\x41\xc2\x03\x3d\xbd\x23\xe6\xb3\xbd\x38\xb3\x74\xf1\xfc\x56\x35\x23\xfc\x7e\xf8\xb0\x6b\x49\xc6\xf5\x77\xa9\x56\x82\xdb\x8c\x20\x7b\x01\x15\xc6\xcf\x97\x5a\xa6\x51\x9d\x32\x2a\x0e\x02\xbb\xe5\x62\xd8\xe0\xc1\x64\x80\xc4\x0b\x2b\x42\x83\x14\x3c\xac\xe3\x5e\xff\x52\x14\x1b\x50\x18\x6d\x25\xbd\xba\xeb\x3f\x83\xd8\xd4\x5d\x7f\xa2\xb3\xf5\x15\x18\x5b\xd5\x55\x0e\x25\x38\x26\x23\x5d\xda\x77\x6b\xa6\xe1\x90\xf8\xaf\x0a\x1d\x9e\x81\xae\x6a\x71\x47\x7f\x67\x91\x25\x12\xda\xfc\x77\xba\x7e\x5d\x69\xa7\xbd\x65\x6b\x49\xe4\x00\x88\x5b\x15\xb9\xa9\xd1\x1a\xfd\x8e\x03\x43\x78\x15\x87\x43\x14\x89\x81\xf7\x5a\xb1\x66\xd7\xbe\x41\xe9\x6f\xfd\x22\xb0\x2f\x2b\x5b\x36\xcc\x62\x68\x15\x58\xce\x47\x7e\xdc\xea\x7b\xb5\x11\x7d\x96\x10\xc8\x7d\xb8\xce\x65\x8c\x71\xcd\xa4\xee\x8c\x46\xd3\xbe\xe6\x38\xe7\x46\xaf\x08\xe0\x6b\x23\xfb\xde\x0d\x10\x61\x8a\xb2\xaa\xa2\xdf\x4f\x2c\x9b\xb9\x41\x07\x59\x8e\xd7\x41\xf9\x47\x7b\x31\xdd\xf4\x47\x35\x87\x08\x7b\x9a\xab\xdc\x46\x8b\x41\xea\x4e\x6a\x02\x4d\x7d\x4a\xeb\xfd\xd7\xc4\x36\xf4\xf6\xe7\x8a\xf7\x19\xc8\x8e\x18\xbd\xb6\x88\x68\x16\x35\xa5\x0d\xc5\x6e\xbd\x15\xf9\x5a\xbd\xb5\x21\x82\x16\x2b\xfd\x4c\x47\xf3\x2d\x56\x92\xfc\x48\xeb\x3e\xe2\x5e\xbd\xb9\xe8\x6f\xb2\x23\xa5\x98\xc6\x43\x87\x23\x4a\xa0\x7d\xa2\x82\x31\x0a\xa1\x43\x5d\xeb\x2f\xd9\x6e\xaa\x70\x39\x9f\xea\xdb\x19\x45\x65\xde\x13\xba\x4e\xa6\x8a\xc0\xdd\x09\x1c\x06\xaf\x50\x2a\x04\x1b\x71\x02\x90\x3d\xa8\xc3\x4f\x73\x67\x1e\xc8\xb9\x87\xad\x51\xa7\x6e\xe1\xf4\x56\x27\x1b\x1a\x00\xea\xe6\x7c\x76\x74\xf2\xc9\x6b\xa1\xe9\xfa\xba\x13\xff\x6b\x98\x0f\x37\x59\xb4\xf8\x87\xfe\x1d\x35\x3e\xa8\x2f\x6f\x08\x2b\x98", 3697);
*(uint64_t*)0x20001588 = 0xec4;
*(uint64_t*)0x200015d8 = 1;
*(uint64_t*)0x200015e0 = 0;
*(uint64_t*)0x200015e8 = 0;
*(uint32_t*)0x200015f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200015c0ul, 0ul);
	return 0;
}
