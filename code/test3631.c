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
	res = syscall(__NR_socket, 0x11ul, 3ul, 0x300);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20005580 = 0x20000180;
*(uint16_t*)0x20000180 = 0x27;
*(uint32_t*)0x20000184 = 1;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint8_t*)0x20000190 = 0;
*(uint8_t*)0x20000191 = 0;
memcpy((void*)0x20000192, "\xf2\x33\x14\xd6\x55\x8f\x30\x8a\x55\xc1\xd1\x3a\x44\xf8\xd5\x8f\x64\x6d\x56\x09\xc9\xd3\x3a\x1c\xfc\x67\x6a\x05\xb1\x44\x77\x3c\xdf\x7c\x59\x8a\xaa\x7c\xb7\x60\x50\x8b\xfa\x3c\x7c\xfc\x8f\x8a\xcc\xc1\xc0\xd4\x48\x58\x4c\xf7\x77\x94\x0f\x3c\x47\x10\x0a", 63);
*(uint64_t*)0x200001d8 = 0;
*(uint32_t*)0x20005588 = 0x80;
*(uint64_t*)0x20005590 = 0x20001540;
*(uint64_t*)0x20001540 = 0x200012c0;
memcpy((void*)0x200012c0, "\xe0\xdd\x66\xc5\xb6\x74\x24\x01\x00\x00\x00\x00\x00\x00\x00\x08\x0e\x0d\x69\x54\xe8\xd2\x86\x09\x0f\x50\x80\xf5\x76\xd2\xd5\xe1\xe0\x7d\x96\x4b\xa4\x6c\x74\x55\x3f\xd2\xa2\xc6\x80\x4d\xdc\x54\x20\x0a\x28\x0f\x7b\x0c\x58\x72\xe3\xa9\xde\xe2\x27\xaa\x18\x18\x60\x86\x4e\x6e\xcb\x09\x53\xdf\x20\x08\xc6\x83\x45\x37\x14\x4b\xe2\x8a\xa2\x77\x9c\xc7\xeb\xfe\x3e\x41\xfe\x7a\xb5\xe5\xf9\x75\xe9\x6f\x63\x23\x4a\x79\xcc\xf0\x2b\x1f\xfc\xc6\x31\xdb\x88\x29\xeb\xe9\x6e\x0b\x7c\x60\xe7\x07\x2e\xcb\x6c\xe0\x70\x36\xde\x54\xb3\xfc\x42\x2f\x4d\x8d\xc2\x3e\xe8\x34\x61\xdd\xc6\x77\xfb\x0b\xee\x25\x55\x8a\xf3\x65\xaa\x2d\x73\x55\x78\xc9\x6b\x39\x6a\xcd\x08\x37\x35\x2a\x12\x4c\x7d\x5f\x6d\x3b\xcb\xdd\x96\xee\x47\x04\x16\x5b\xac\x1c\x39\x06\x2d\xb4\x01\x00\x00\x00\xd9\x40\xc9\xc1\x55\xf4\x8d\x31\x71\x85\xb9\x49\xa8\x07\x8d\x61\xf8\x29\x19\x4b\x7d\xe2\xb8\x12\x16\xa7\x80\x0a\xb2\x57\x01\xf9\x7e\xad", 222);
*(uint64_t*)0x20001548 = 0xde;
*(uint64_t*)0x20001550 = 0x20000240;
memcpy((void*)0x20000240, "\xa5\x36\x04\x3a\xf5\xdc\x59\x0b\x29\xd1\x3f\x32\x39\x98\x59\x6d\xb2\x8f\xed\x57\xa6\x41\x3c\xed\x0e\xda\xbf\x4e\xff\x00\x34\x57\x95\xf0\x58\xce\xa9\x12\xf1\x1c\x5f\xfb\x1d\x63\xf9\xe6\x84\x7c\x10\xc2\xdd\xd0\x0d\x9e\xc4\xc7\x9e\x3a\xf2\x28\xd8\x9b\xd2\x02\x79\xfd\x95\xf9\xa1\x0e\xa2\x52\xd7\xd2\xab\xbf\x93\x4f\x4e\xe3\x85\x76", 82);
*(uint64_t*)0x20001558 = 0x52;
*(uint64_t*)0x20001560 = 0x200002c0;
memcpy((void*)0x200002c0, "\x34\x7f\xb3\xb2\xc2\xa9\xd4\xa5\x45\xc7\xff\x3f\x13\x27\xc2\xc6\x3e\xc5\x4a\x4b\xb2\x27\x2b\x64\x86\x99\x1a\x15\xaf\x70\x0e\xd5\x76\x34\x90\x7a\xc9\xcb\xae\xc4\x92\x48\x4d\x2f\xf8\x59\x6e\x31\x15\x08\x2a\x44\xef\x98\x12\xa9\x27\x0c\xb3\xd9\xa3\x6b\x12\x20\x94\x90\x38\x14\xde\xa5\x9d\xca\x01\x20\x15\x7a\x7a\xa5\x46\x30\x25\x68\x64\x88\xfa\x20\x9a\xd9\xf4\x6a\xbf\xe8\x68\x90\xed\x65\xda\xfb\xa1\x28\x88\xf5\x97\x50\x3c\xe8\xcf\xaf\x2e\x1d\x53\x88\xad\x8a\xa5\x10\xa6\xa5\x37\xac\x61\xe4\x15\xcf\x48\xe7\x4b\x5b\xe0\xc9\x7b\x6f\x89\x25\x49\x8e\x9a\xf9\x27\x85\x39\xd0\x92\xc5\x86\x11\xf7\x8b\x82\x4a\xc9\x3a\xfe\xd5\x1d\x70\xe3\x7b\xd7\xe9\x38", 161);
*(uint64_t*)0x20001568 = 0xa1;
*(uint64_t*)0x20001570 = 0x20001580;
memcpy((void*)0x20001580, "\xbc\x35\x06\x99\xc6\x04\x96\x6e\xee\xe6\x03\x31\xb5\x36\x26\x62\xbd\x52\xbb\x4c\xf1\x21\xf7\xad\xc9\x12\x54\x22\x05\x34\x6b\x2d\xce\x09\xa0\x05\xe0\x6f\x7e\xda\x7e\x88\xcd\x65\x1f\xcf\xec\xa4\xf5\xae\x2c\x34\x0f\xf7\x56\x18\xe5\x51\x87\x1e\x91\x7c\x12\x16\x6f\x9d\x0e\xb2\xed\x10\x41\x0b\xb0\x27\xc9\xb5\x30\x6e\xe8\x50\x8c\x90\xb6\x4b\xf7\x5f\x89\x52\x5f\x0e\x41\x81\x99\x99\x82\xb5\x36\x5a\x30\x2e\x0c\xe8\x28\xfb\x19\x0b\x23\xe4\x8c\x7e\x5b\x33\x21\xcd\x5d\x23\xc2\xb2\xac\x4f\x56\x72\x8b\x31\x16\x1c\xf6\x1b\xf2\x58\x1a\x5e\x79\x5d\xef\xa9\x45\x3a\xae\xd0\xa7\xb1\x79\x88\x50\x58\x30\x1c\x1a\x9b\x11\x21\x69\x15\x55\xd5\x9b\x1a\xb9\x6f\xbc\x2c\x78\x8e\x03\xb2\xb6\x30\x90\x03\xbc\x9d\x1a\xd0\x0d\x34\xa4\x68\x72\x5f\x8b\xd6\x69\x6e\xc6\x71\x1c\xda\x3f\x61\xb0\x74\x90\xff\x90\x81\x43\xcb\xc0\x74\x39\x05\xd4\x77\xc5\x6f\xdb\x7e\x8e\x4e\xab\x0c\x75\x75\x7b\xd4\xcb\x66\x98\xd3\xab\x4f\x44\x1f\x09\xf1\x78\xf3\xb1\xc6\x41\x01\x5e\xd1\xf0\x5a\x69\x49\x1e\x64\x41\x0f\x2f\x59\xdf\x1b\xef\x9e\x58\x0f\xb2\x72\x42\x1d\x5c\x9c\xf8\xf7\xa0\x09\x0d\xa1\x9c\x9d\xbd\xc0\xcf\xf8\xf3\x61\xe9\xda\x47\x14\xa7\xe9\x42\xa4\xe6\xbe\x19\x07\xfe\x64\xb8\x03\xa5\xf1\x6b\x11\x31\xdb\x55\xb8\xa4\x3d\xe5\xdd\x5e\x36\x8f\xa8\xac\x08\xf5\xba\x08\xde\x46\xdf\xe9\x33\xc0\x78\xfe\xb6\xd4\x82\xf2\x37\x1d\xc1\x9f\x57\x53\x0b\xbd\x88\xf3\x6d\x7a\x73\x08\x00\x87\x8e\x77\x56\xa4\x3d\x7e\x5a\xf1\xb2\x42\x8f\x7b\x7d\xb2\x72\x9d\x35\xdd\x4e\xcf\xfb\xaa\x49\x04\xbf\x57\x9a\x03\x1d\xdb\xa4\xc2\x53\xf5\x68\x93\xc8\x88\x7a\x9a\xb7\xe8\x70\xb1\x65\x20\x7a\x8d\x35\xf3\x6f\xcd\x5e\x57\x1a\x47\x9d\xa8\x25\x1c\x9d\x22\x33\x7b\xf2\x38\x55\x51\x00\xe3\xf6\x6d\xb1\x87\x15\x48\x4c\x95\x6e\x50\xb3\x7a\x78\x30\xcc\xef\x1c\x14\x0f\xb6\x62\xb6\x63\x78\xee\xf2\x8c\x1b\x7b\xbf\xc7\xdd\xe6\x38\x2d\x49\x39\xa5\xf1\x1d\xce\x83\xcf\xde\x78\x0e\xb7\x26\x8a\x16\x7d\x95\x89\x37\x5b\x9f\x8a\xac\x62\x9c\xbc\x63\x16\x1a\x5d\xe0\x70\xe4\x48\xda\x4b\xac\x55\xea\xa5\x4a\x3d\x12\x3e\x54\xc2\xa4\x73\x2e\x3a\x98\xae\xdb\xd5\x94\x34\xb8\x1b\x9b\xa0\x00\x64\x9f\xe5\x6c\x70\xf2\x84\xea\xa1\x5e\xfd\x0a\xdf\xda\x31\x7a\xf4\x95\x69\x43\x9e\x3f\xd7\xdb\xa7\xa5\x57\xbc\x92\xd0\x94\x73\xcc\x89\x04\x2e\xaa\x26\xa9\xf3\x95\x8a\x71\xcf\xdf\x65\xe3\xd2\x12\x54\x14\xdb\x6d\x8f\xac\xee\x5e\x14\x4c\x97\xa3\xbe\x93\xbf\x6a\x87\xec\x25\x30\x39\x3e\x00\x0b\x18\x36\x2e\x3f\x49\xa3\xd8\x6e\x64\x23\x04\x52\x3d\x84\xc7\xcc\x0e\x74\x81\xe7\xfb\x9e\x2d\x70\x7b\xa1\x03\xcb\x57\xb3\x4c\x67\x3b\x43\xc3\x7d\xf0\x6b\x41\x14\xc9\xdf\x98\x45\xc1\x31\xb3\xd8\xd4\x5b\x87\x98\x9b\xc0\x1c\xa2\xf6\xcd\xd2\xac\xbc\x09\x52\x47\xd2\x91\x5d\x95\x6e\x73\x38\x07\x54\x18\x40\xb5\xd6\xd1\x34\x0c\x1e\x82\xe4\x1f\xa4\xdc\x55\xae\x33\x2d\xee\x2f\x44\xae\x19\x35\x4a\xea\x8f\x47\x08\x3e\x11\x24\x01\x1e\xd8\x51\xcb\x78\xbb\x7d\xbe\xdd\x44\x31\xc3\x27\x2b\x78\x6f\x74\x1e\xf7\xe4\x4f\xfc\xfa\xa4\x28\xe6\x4b\xaa\xcc\xb0\x05\xe2\x51\x38\x6d\x1d\x32\x6f\x79\x02\xa4\x9d\x3c\x9c\xd0\x6a\xd3\xda\x6d\xef\x20\xba\x4e\x77\x96\xa5\x9f\xba\xb6\x1a\xdd\x74\x09\x07\x26\xaa\x93\x18\x81\xfd\x26\xde\x3b\xfd\x7b\x5a\x2d\xd9\x66\xe3\x0e\x89\x83\x0f\x34\xc9\x95\x45\x50\x60\x30\xaa\x9e\x52\xb7\x94\x30\xe9\x28\x0e\x0c\x54\xf7\xd6\x02\x65\x7c\x3e\x65\x07\xe3\x62\x5c\xda\x60\x79\x7f\x39\x8b\x1c\x36\x56\x4d\x13\x14\x60\x34\x41\xc2\x09\x02\x22\xeb\x19\xcf\x14\x18\xc0\x7b\xeb\xda\x59\x4d\xe7\x1f\x7b\x74\x41\x3a\xfb\x33\x7d\x1e\x3d\x0f\x97\x6f\x59\x01\x6b\xe5\xbd\x15\x8a\xa2\x88\x1f\x6f\x5a\x45\x5d\x98\x28\xbe\xc7\x0d\xbd\x32\xb6\xc5\x80\xa2\x24\x68\x06\x6c\x22\xf0\x09\x3f\xc9\x0e\x39\x61\xd3\xc3\x4b\x15\x36\x41\x83\x58\x6b\x67\x33\x0f\x27\xd2\xe2\xe6\x96\xa9\x79\x35\x59\xc9\x40\x6d\xb8\x74\xf0\x79\xc1\xdf\xdc\xab\x30\xe2\x4b\xb2\xff\x4f\xc7\x4c\x66\x73\xb5\x53\x21\x3b\x15\x91\x3e\x6b\xaa\x53\x26\x44\x3c\x43\x84\x77\xf7\xe8\x13\x36\x27\x9a\x69\xa2\x4c\xae\xa1\xc4\xc1\x41\x34\x84\x87\x99\x02\xd6\x44\xad\x54\xce\x7d\xeb\x59\xb2\x9c\x2c\x13\x2c\x6e\x71\x2f\x38\xc7\x0e\x22\x15\xc0\xf4\xbf\x4e\x99\x91\x7a\x14\x32\x46\x4a\xbd\xca\xc2\xea\xd2\x3e\xad\xfd\xae\xf5\x14\x6b\x9a\xf3\xeb\xb2\x70\x82\x92\x0b\xbe\xdd\x81\xf3\x88\xde\xf5\x0b\xb7\xfe\xd3\xe1\xba\x8e\x3b\xf2\xe0\xad\xf0\x4d\xd9\x58\xb3\x2e\x47\x4a\x4a\xee\x76\x9a\x71\x3f\xe7\x88\x23\xbb\x22\x60\xcc\x1f\xf8\x87\x84\x8a\xe4\xde\x69\x8e\x19\x2b\xdb\xd8\xc7\xb5\x7b\x74\x33\x65\xef\x1e\x60\xf8\xe5\x11\xbb\x19\x09\xe6\xee\xb9\xf2\xba\x64\x2e\x72\x40\xa4\x26\x0b\xe3\x4e\xcf\x41\x03\x74\x5f\x56\xd2\xb9\x40\x9d\xfd\xc0\x15\x59\x13\x22\x1d\x0f\x8f\x67\x36\x39\xd8\xaf\x97\xd3\xf9\xe7\xd7\x56\xaf\x99\x75\x44\xe6\x1c\x7a\x39\x1f\x8f\x12\x1d\x53\x30\x51\x5b\x71\x8e\xa1\x27\x47\x7b\x25\x98\x3d\xb6\x64\xd6\xc8\xcd\x3d\xe4\x88\x7d\xb7\xe0\x9f\xa7\x11\x62\xbd\x4e\x39\x46\x63\x3b\xae\x50\x75\x43\x98\xd8\x49\xa5\x61\xe4\x2b\x4c\x33\x5b\x00\xad\x04\x0c\xe4\x6e\xe3\x56\xcb\x35\x7e\x07\x95\x09\x4c\x24\xb8\x44\x3f\x68\xce\xc3\x33\x77\x62\x9b\xc5\x24\x3f\x22\xa4\x68\x63\xb5\x39\xf2\xf2\x1c\xef\xb4\xea\xe4\x88\x3f\x32\x9f\xc5\x9b\x62\xe2\x6f\x8a\x6e\x86\x82\x56\xc0\xb4\x39\x34\xc7\xd4\x49\x10\x68\xfd\x0a\x73\xca\x2c\x68\x07\xc6\x51\xab\x2f\x00\xee\x4c\x3a\x9b\x63\xfe\x80\x98\xbc\x07\x4b\xcc\x7f\x93\x15\xb8\x47\xf0\xa2\x1f\xdf\x5e\xb2\xd7\xba\xd8\x12\xcc\xde\x18\x25\xfd\x4a\xc8\x22\xd5\xff\x93\xdf\x07\x6b\x9b\x2b\xae\x2b\x1e\x8a\x77\x56\x72\xc2\xba\x62\x94\x92\x55\x8f\xe4\x82\xc7\xe4\x09\xab\x76\xeb\xa8\x8d\x66\xdc\x1d\x4b\x87\xc1\x89\xa4\xdd\x7d\x65\xf1\x17\x44\x9d\x38\xc9\x8b\x50\x19\x9f\x60\x33\xb0\xaf\x85\xa9\x70\x0d\x97\xd8\x37\x7a\x66\x4e\xb9\x23\x65\x4b\xf5\x1f\x3e\x72\xda\xb0\x00\x93\xa6\x81\x0c\x49\x99\x69\x47\xec\xb2\x54\xe0\xc7\x66\xe4\x77\x01\x4e\x68\x29\xd0\x00\x64\xbc\xee\x6d\x1b\xe9\x82\xf6\x78\x85\x96\xf6\x80\xaf\x0a\xb1\xd5\xf0\xc8\x2d\x44\x7d\xd2\x72\xac\x52\x16\x99\x17\x8b\xd6\x3f\x06\x73\x96\x86\xf5\xb7\x68\x8c\x4e\x97\xa7\x87\x2d\x83\xb6\x22\x91\xb0\x3e\xcb\x56\x67\xe3\x70\x7b\x9a\xa5\x35\xc6\xe6\x6b\x1a\x97\x87\xf6\x02\xc6\x25\x7b\xdc\x9f\xbd\xc8\x13\x31\x75\x77\xf6\x2d\x4f\x65\x57\xdf\x68\x08\xe8\x15\x49\x62\x6e\x77\x9d\x17\x0c\xb6\x3d\x31\x25\xf6\x6d\x3c\xf3\xa6\x65\xaf\xed\x6e\x44\xc9\x05\x34\xe8\xbb\xdb\x20\x00\x21\xf2\xa8\xb8\x4d\x0a\xf0\x44\xa9\x3b\x56\x16\xde\x67\x57\x8e\x9d\x11\xa3\xb5\x41\x6d\x75\xb0\xf4\x3c\xec\x43\x0f\x2d\x8f\x08\xc3\x18\x8c\xb0\x30\x03\xd8\x46\x7a\xc8\x54\x24\x68\x79\xd6\x8d\x1f\x4c\xa9\x84\xe3\xcb\xf9\x19\xac\xe8\xae\x85\x56\xf4\xdd\x4b\x57\x32\xb6\xe5\xc7\xa2\xfb\x81\x71\xb6\xa7\x16\x84\xa3\xd1\x61\x76\x83\xbf\xa9\x32\xf2\x4b\x31\x9e\x08\x1e\xc6\x6e\x86\x53\xd3\x91\xd0\x8b\x0b\x30\x4f\xa8\x4c\x1e\x5c\xd7\x7c\xe2\x26\x39\x8d\x7a\xb4\x27\x0b\x6a\xb9\xf2\x08\xa2\x41\x9a\xd1\x56\x99\xce\x78\xf2\xa0\x22\xfa\x4a\x82\x1d\x1b\x7d\x89\x80\xf2\x6a\xa8\xd5\xb5\xac\xe7\x5e\x6c\xfc\x8c\x32\x46\x93\x5f\x19\x90\x98\xc6\x35\xd0\x64\xf6\x29\xde\x74\xb5\x57\x78\x95\x1c\x6d\xef\xfa\xae\x1b\xfd\x70\x8c\xd6\xda\xc5\x57\x3d\x3d\x96\xba\x8d\xd5\xb4\x9a\xfa\x54\x0e\x3a\x46\x8e\x34\xa5\x48\x43\xdd\xca\x45\xae\xc0\xce\x32\x8c\xa1\xbc\x1f\x13\x6d\x9e\x1d\x9e\x3d\x1a\xb3\x0c\xcc\xdd\x1e\x40\x5f\x9b\x6b\xb2\xdb\x1c\x43\x83\xd1\xe9\x84\xce\x76\xac\xd2\x05\x01\x45\x9f\x7a\x1f\x2a\x3c\xb4\x81\x9f\x89\x6d\x1d\xd1\xcd\x07\xd0\xf9\x42\xe0\xab\x12\x29\x1c\x95\x3e\x48\xcc\xc0\x04\x81\x81\xe5\x4c\x3e\xdc\x13\x4e\xb8\xf5\x50\x8e\xa9\x3a\x6c\xaa\x9c\xd5\x95\x32\x1b\xef\xda\xf9\xb2\xb4\x18\xc3\xff\x1f\xba\x71\xc9\x55\x2d\x03\x3a\x31\x19\x93\xb8\x11\x38\x6c\xe4\x44\xd8\x52\x5d\x5f\xcc\x51\xec\x6e\x20\x46\xad\x68\xa4\x1b\x6e\x30\xdb\x16\xa9\x17\x80\x1e\x06\x00\xf5\x30\xa0\x06\xf5\x3c\xe3\x0f\x1d\x4b\xf4\x7c\x90\x76\x71\x0b\xe3\xcd\x56\x49\xb2\x36\xc4\x26\x11\x3a\x05\xe7\xe8\x4a\x18\x7c\xad\x4f\x2f\x07\xfe\xf5\x16\xb0\x8e\xae\x04\x51\xb2\x78\xff\xf0\x2e\x40\xb8\x86\xe8\xa9\xac\x35\xfc\x05\xc4\xed\x02\x6a\xf6\x95\xbd\x05\xe5\xb1\xad\xd3\x19\x65\x74\x32\x8c\xde\x60\x23\xd3\x06\xfa\x62\x68\x50\x92\x1a\x21\xa3\x35\x76\x43\x9a\xc2\x7c\x3b\xc7\x16\x3e\x40\xa8\x91\x34\x7c\xa1\xa0\xaa\x34\xc4\x6d\x7d\x24\xae\x12\x3f\xbe\x8c\xf7\xba\x20\xd8\xcb\xd3\xd9\x6c\x2f\xbe\x3b\xda\x35\xb5\xb1\x92\xdd\x47\x12\x31\x61\x15\xaf\xfa\xf3\x86\x33\x21\x61\xd5\xc7\xed\x9e\xa1\xd7\xa1\x7a\xe7\xc7\xa0\x37\xd8\x20\x02\xa9\x5b\xcc\x4e\x35\xa6\xd9\x4c\xfb\xba\x2a\xa4\x78\xae\x98\xb6\x13\x36\xb6\x13\xf3\x88\x12\x1f\xf3\x12\x89\x35\x94\x1e\x91\xea\x67\xd9\x96\xe0\x3e\x26\xee\x87\x97\x16\x6c\x64\xf1\x61\xe7\xe4\x12\xd9\x35\x23\x0f\xe7\x16\xa0\x3c\x33\xcf\x17\xb2\x35\xf0\xe4\x02\x0c\x6e\x2a\xaa\x46\x12\x65\x77\x9a\xda\xd1\x3d\x42\x4c\x9d\xa0\x90\x30\xcf\x1e\xef\xa9\x16\x6a\xce\xc0\x9a\x52\x73\xb7\x9b\x5c\x8e\x8b\x77\x6e\xd8\x03\x29\x0c\xfb\x17\xcb\x09\x29\xd7\x54\x0a\xe6\x74\x4a\x41\x4c\x52\xc2\x76\x74\xd9\x92\x8e\x33\x2c\xb3\x79\x59\x7d\x4b\x86\x9f\x7a\xd4\x54\xa0\x43\xc9\xff\x75\xfb\x48\x7f\x86\x95\xa9\xcf\x53\x19\x7f\x29\x65\x3b\x24\x9e\x5c\xfd\xe3\xbc\x28\x59\x65\x6e\x97\x2e\x03\x2a\xda\x50\x1b\x1f\xb8\x4f\xbe\x38\xb9\x87\x56\x68\x55\xe9\x9d\x09\x46\x93\x03\x62\x20\xcd\x05\xf9\x46\x94\x06\x58\xb0\xe0\x8f\x29\x89\x49\xd5\x6a\x4e\x87\x6b\x17\xbf\x8a\x5f\x04\x69\xb0\x5e\xc7\xd9\x38\xaf\x79\x95\x89\x8f\x68\x05\x48\x60\xcd\x91\x8c\x76\x72\x9a\x4b\xcc\x0d\x51\xb9\x86\x5c\x52\xd1\x2f\x28\x5e\x39\x7d\xda\x36\xca\x5b\xe2\x51\xf3\x2f\xae\x94\x1c\x5a\x4d\xb8\x32\x6f\x68\xaf\xb8\x2b\x97\x60\xb6\x94\xb7\x00\xd3\x61\x6a\xa2\x96\xd4\xfb\x17\xb7\x9b\x30\x4f\x88\x5d\x0d\x50\x74\x4c\xce\x81\x5e\xc7\xba\xee\x67\x97\x70\xda\xad\xc6\x8f\xaf\x1d\x74\xaa\x84\xd5\xaf\x56\xca\xa3\x0d\x21\x11\x74\x54\x83\x30\x77\x72\x3e\xc2\xf4\xe2\x7e\x5b\x74\x2f\xb2\x1d\xe7\xcb\x01\x46\x8f\x3f\x13\x2f\x15\x89\x12\x49\xa0\xdb\x16\xdc\xbd\x6b\xc8\xdc\x44\xb2\x6e\xa7\x5c\xc7\xe7\x38\xd5\x90\x94\x94\x53\x63\xad\x85\xaa\x20\xb5\xb7\xa4\xc3\x2e\x8e\x7d\xfc\x18\x48\x06\xea\xa3\xc2\xdb\xc5\xd8\xeb\x87\xbe\x6c\x13\x4a\x6f\xc4\xaa\x23\x06\xac\x2c\x0d\x96\x0f\x85\xbf\x34\x45\x1d\xf6\x70\xcc\x3a\xa7\x14\xdc\x38\x97\xce\x15\xb4\x97\xf2\xd2\x87\xc4\x08\x76\x8a\xcb\x1e\x29\x6a\x90\xfe\x81\xdc\xc8\x0a\x19\xd4\xf1\xd0\x3a\x25\xb8\x45\xee\xd8\xbf\x7d\x92\x4b\x64\x06\xe8\xfe\xc2\x24\x7a\xd4\x2c\xb1\xd3\x50\x8f\x47\x3d\x1c\xd7\xf2\xca\x2f\x70\x32\x20\x82\xca\x35\xbb\x46\xc7\x88\x55\x1b\x19\x3f\x0d\xcc\x2b\xea\x27\x79\x85\xb7\xcf\x21\x8b\x30\x0a\x7a\xc6\x89\x7c\x36\x87\x4d\x36\x04\xe7\x76\x8b\x42\x04\x7e\x02\x35\xc3\xae\xaf\x66\x15\x2a\x7e\xb5\x58\xed\x92\x16\xe4\xae\x75\x6e\x5b\x68\xe6\xac\x49\x7a\xa7\xd2\x28\xcd\xd3\xf8\xa9\x65\x95\xe7\x44\x36\x7f\x2f\xdb\x25\x18\x55\xfe\x9b\x9c\xcb\xdd\x6b\x07\xee\x5a\x29\x9b\x93\x5a\x96\x55\xac\xb4\xe3\x7b\x41\x41\xfa\xbb\xbc\xb6\x36\xc4\x05\xc5\x96\x93\x54\x33\xd5\x2a\x4b\x1d\x16\x14\x15\x64\x6f\xca\x45\xfc\xab\x07\xd2\x1f\x90\x27\xcd\x94\xc4\xe6\xed\x7b\x11\x44\x3c\xee\x18\x8a\xaf\x92\xd0\xa2\x7e\xef\x38\x3a\x81\xc7\x50\xda\x71\x6d\x69\xae\x26\x7e\xbb\x3c\x44\x65\xe9\x46\xa4\x3f\x3c\xda\x9a\xf3\x6e\x5d\xff\x2c\x18\xc4\xd8\xe6\xea\xac\xee\x8c\xc4\xf2\x3b\x2a\xfc\xa4\xb5\x8e\x25\x12\x1a\x56\xb8\xdd\x21\xeb\x36\xcf\x20\xee\x34\xb3\x18\xd7\x47\xa4\x27\xac\xb5\xe1\xff\xd6\x84\x06\xd5\x06\x31\x9f\xfb\xf9\x11\x7a\xc3\x2b\x63\x22\x01\xca\xe4\x0d\xdb\x7b\xc1\x90\x51\x57\xa6\x87\xa6\x0a\x50\x9b\x15\xe6\xb7\xf0\x2b\x93\x0d\xf8\x70\xa8\x1b\xcb\x49\xbb\x51\xef\x97\xdc\x6f\x9a\x42\xa4\x48\xf0\xc9\x47\x25\x5c\x42\xdf\x29\x87\xf9\xc8\x39\x7e\xf1\x63\xcc\x51\xa6\x06\x85\xc2\x1f\x2f\x12\x98\x6c\xd3\xec\xd2\xcc\xf4\x43\x6a\x78\x4b\x4c\xbb\x52\x33\x27\x1d\x3d\x5f\x56\xfe\x84\xf1\x30\x81\xb4\xc8\x2f\x3e\x40\x8d\x5d\x58\xad\xce\x46\x46\x0b\x10\xb7\xde\x55\xba\xa1\xe4\x66\xa0\xe4\x2c\xaa\xfc\x93\x65\xcc\xc3\xe6\x5f\x68\xe8\x0e\x32\x11\x35\x4d\x71\x5d\x58\xf5\x3a\x90\x6d\x8e\x61\xa7\xe8\x86\x84\xe1\x6a\x46\xa6\x6b\xce\x47\x85\xcc\x1e\x82\x71\x93\x0c\xbe\x67\xd7\x91\xfa\x2f\xff\x67\x7c\xc1\x77\x28\xfc\xd7\x1f\x67\x13\x0c\xa0\x21\x16\xcb\xbd\xba\x98\x49\x81\x3e\x41\x08\xde\x44\x5c\xec\x0e\x6b\x59\xb8\x10\x6e\x1c\x53\x96\x07\x7d\xa7\x14\x80\xd2\x54\xb0\x49\x3c\x4b\x24\xad\xa1\xd0\x0a\x20\x66\x6b\xdd\x19\x8b\x81\x8f\x6c\xa2\x5a\x69\xe8\xf2\xab\xfd\x7f\x6f\xfc\x05\x11\x71\x84\x9f\x23\xe8\xbf\x77\x5d\x19\x85\xb3\x3a\x96\x23\xb6\xab\xce\x90\xd3\xac\x57\xd5\x97\xb7\x7b\x48\x34\x63\x83\x2e\xb7\x43\xff\xfc\x1d\x86\x07\x28\xfb\xec\x51\xa3\x79\xee\xc5\x30\x55\xfb\x7b\xad\x33\xd2\x17\xe7\xaa\x9b\xa5\xec\x36\x48\x89\x7e\xc4\xaa\x4f\x2f\xa7\x82\x53\x20\x04\x4c\x73\x61\x6d\xc9\x69\x50\x67\x54\x12\x43\x86\xac\x70\x27\x08\xd6\x90\x43\x98\xc5\x55\x9c\x8c\xcc\xbf\xcb\xb1\xf7\xef\x90\x2b\xb8\x38\xf3\xba\xca\xb7\x67\xe4\x4c\x77\xfd\x8e\xa2\xc3\x6e\x5a\x5a\x36\x49\xc8\xb3\x62\x62\xa1\x37\x92\x64\xfa\x86\x55\xe6\xad\xc8\xe8\x85\x53\xd8\x3c\xa2\x06\xce\x40\x59\xb3\x87\x2b\x15\x37\x25\xc3\x1c\xe1\x03\x4a\x34\x95\x6c\xcf\x85\xbe\x53\x3a\xcb\x73\x92\x1c\xa3\xe9\xf7\x83\xb8\xe0\x5d\x40\x74\x16\xf8\x4f\xf4\x1b\xd9\x29\xaf\x6b\x79\x68\xfd\x19\x66\x34\x8b\x3b\xcf\x3a\x5f\xc5\xe6\xab\xb3\x41\xa6\x04\x21\xf0\x74\x66\xae\xa8\x6c\xfe\x81\xd2\xac\x14\xc1\xe4\x15\x99\xd8\x5d\x8a\xf9\x3f\x68\x50\xac\x54\x74\xcd\x24\x52\x17\x9c\xcc\x14\x3b\x69\xb4\xa8\x7e\xfb\x67\x52\x5f\x3a\x11\x10\x9a\x50\x1c\x11\x72\xb0\x39\x1c\xa8\x5d\x00\x66\x40\x56\x63\x04\xef\x39\x6d\x88\x86\xb4\xa3\x41\x26\x1e\x13\x21\xf9\xf8\x25\x6a\x5f\x24\xa8\x00\xd1\xdc\x2a\x89\xcd\x18\x12\x41\x1c\x3c\xf6\xb8\x22\xce\x56\xf2\x8c\xb6\x70\x18\xc1\xf6\x6c\xf1\xd5\xe9\x79\x15\x96\xb5\x19\xc1\xd5\x0a\x8a\xa1\xc0\x4e\x29\xd0\xc5\xcc\x87\xdc\xbc\x57\x37\xbe\x32\xdd\x82\x97\xd3\xb4\x8a\x09\xdd\xc3\x17\x76\x22\xff\xeb\x80\xcb\x95\x79\x39\xf0\x3c\x8e\x70\xfd\x8c\xdc\x65\x49\xc9\x65\x50\x96\x9e\x46\x83\xf7\x14\x1a\xf0\x5a\x10\xc5\x14\x6e\x7c\x5b\x08\xbf\x8b\xd4\x1d\x07\xdf\x3e\xd9\x55\x12\x4a\x61\xdc\xd6\xac\xd2\x0b\xbd\x02\xdc\x20\x4b\x76\xec\xc2\x1c\x63\x2a\x2a\x9c\xc9\x05\xe9\x2c\x2b\x82\x39\xdc\x0f\x25\xdd\x70\xa3\xb4\x80\xae\x54\xf1\x3b\x1b\x2f\xee\xb5\xd1\xec\xa7\x9f\x60\x65\xe8\x98\x2c\x61\xfb\x04\x2c\x18\x93\xa8\x3d\x15\x8c\x54\x72\xd7\xae\xa1\x9b\xfb\x1d\xc6\x48\xa4\x74\x19\x98\x27\xe8\x2e\x0b\x2d\xb7\xc3\xf8\x85\x59\xdb\x92\x58\xcc\x4f\x8d\x98\xa9\x7d\x65\x12\xe1\x85\xcb\x75\x01\xc1\x6c\xbd\x0a\x75\xb5\xc1\x0a\xac\x6a\x07\xb4\xc0\xa6\xfd\x74\xfc\xc2\xed\x96\x12\xc5\xa1\xd2\x21\xa6\xbf\xde\x2f\x1d\xc1\xb0\x1d\x30\x17\x10\xae\xa3\x8c\x00\xcd\xbc\x18\xdb\x2c\xeb\x11\x8c\xf0\x99\xc0\x44\x63\x3c\xe9\xd1\xdb\x92\x42\xa7\xa8\xa1\x2c\x86\x44\x2e\xc8\x38\xf4\x27\xd0\x22\xaf\x38\x90\x8c\xbf\xa0\x76\x6b\x72\x5e\x0a\x20\x61\xfd\x41\x90\x9f\x76\xba\x83\x35\xfc\x20\xf7\xdb\x60\x8c\x1a\x0d\x62\xa8\x93\xb8\xb8\x77\x84\x5b\x2b\x53\x3c\xcf\xa3\x61\x22\xba\xbc\x73\x01\x66\xf7\x49\xca\xb0\xb8\x22\xa2\x2c\x9a\x25\x4d\xe6\x47\x11\x25\x27\x79\xd4\x11\xc9\xcc\xf7\x1c\x94\x95\x9a\x64\x09\xfe\x3c\x15\xdd\xab\xb4\x3f\x03\x33\xad\xb0\x04\x3a\x39\x07\xf0\x1f\xc7\xe8\x75\xfa\xff\x81\xaa\x66\x55", 3615);
*(uint64_t*)0x20001578 = 0xe1f;
*(uint64_t*)0x20005598 = 4;
*(uint64_t*)0x200055a0 = 0;
*(uint64_t*)0x200055a8 = 0;
*(uint32_t*)0x200055b0 = 0;
*(uint32_t*)0x200055b8 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20005580ul, 1ul, 0ul);
	return 0;
}