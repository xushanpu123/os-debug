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
	res = syscall(__NR_socketpair, 1ul, 1ul, 0, 0x20000280ul);
	if (res != -1) {
r[0] = *(uint32_t*)0x20000280;
r[1] = *(uint32_t*)0x20000284;
	}
	syscall(__NR_recvfrom, r[1], 0ul, 0ul, 0ul, 0ul, 0ul);
*(uint64_t*)0x20002780 = 0;
*(uint32_t*)0x20002788 = 0;
*(uint64_t*)0x20002790 = 0x20000100;
*(uint64_t*)0x20000100 = 0;
*(uint64_t*)0x20000108 = 0;
*(uint64_t*)0x20002798 = 1;
*(uint64_t*)0x200027a0 = 0x20000140;
*(uint64_t*)0x20000140 = 0x14;
*(uint32_t*)0x20000148 = 0;
*(uint32_t*)0x2000014c = 1;
*(uint32_t*)0x20000150 = 0;
*(uint64_t*)0x200027a8 = 0x18;
*(uint32_t*)0x200027b0 = 0;
*(uint32_t*)0x200027b8 = 0;
*(uint64_t*)0x200027c0 = 0;
*(uint32_t*)0x200027c8 = 0;
*(uint64_t*)0x200027d0 = 0x20001640;
*(uint64_t*)0x20001640 = 0x200001c0;
memcpy((void*)0x200001c0, "\x77\xd7\xa8\xd7\x34\x6d\x5a\x28\xaf\xe5\xf2\xec\x3c\xf0\xaf\x86\xa1\x5f\xea\x69\xd4\x31\x46\xe3\xe3\x89\x6c\xd1\xdd\x61\x19\x4e\x24\x74\x11\x35\x72\xc3\x25\xa8\xd3\x28\x93\x45\x2e\xfe\x05\xfd\x5a\x4c\xe0\x6f\x65\x77\x5f\x36\xff\xff\x30\x37\xe7\x48\x5e\xe7", 64);
*(uint64_t*)0x20001648 = 0x40;
*(uint64_t*)0x20001650 = 0x200002c0;
memcpy((void*)0x200002c0, "\xdf\xb9\xf9\xea\x96\xbb\x0d\x46\xc2\xf5\x9d\x2c\x70\x2e\x39\x1d\xaf\xe2\x58\xf4\xe6\x97\xc3\x31\x63\x04\x41\x2f\xaa\x7e\x9f\xb6\xc5\xe1\xd6\xe4\xce\xe0\xfe\x3b\x7c\x86\x5d\x99\x23\x77\xdb\x39\xa4\x91\x17\x4c\xf1\xdc\x50\x47\xb5\x8e\x4d\x1f\xcb\x0b\x73\x01\xd7\xa5\xe2\xfd\x2b\xcb\x9a\xbb\x49\x29\x0f\xf3\x6e\x09\x15\x5b\x10\xad\x8a\x4e\xd1\x1f\xa6\xff\xa8\x8e\x89\x5b\x6f\x91\xc3\x08\x7f\x2b\xe3\xc9\xa1\xb4\xbe\xd0\x59\x65\xed\xc2\xc5\xea\x77\x05\x03\xd3\x99\x08\xbb\x07\xea\xe7\x57\x5c\xb9\xb9\x01\xd6\x0f\x6d\xb4\x60\x8c\x0f\x82\x09\x17\xa2\x69\x63\x1d\x92\x17\x40\xe3\xa7\x7c\x01\xdf\xbe\x9e\x87\x0d\x6e\x40\x56\x9a\xaa\x02\xd1\xa1\x45\xc9\xc9\x71\x74\x15\x67\x85\x83\x6c\x56\x79\x92\x3c\xef\x02\xf5\xa9\xc0\x71\xbc\x9d\x72\x44\x79\x5d\xcf\x64\xa0\xfb\x99\xfb\x9f\x09\x24\x78\xa4\x08\x2f\x3f\x23\x11\xa8\x18\x5e\x8f\x32\xa8\x73\x91\xfb\x6f\x1d\xbc\x54\x71\x8f\x3b\xda\x34\xca\xb2\xc9\xde\x42\xc2\xe8\x26\x67\xb2\xdf\xbc\x7a\xfe\x31\x3a\xd0\x3a\xf7\x88\x80\x13\xcb\x2a\xe2\x15\x3a\x49\x14\x42\x02\x49\xfa\xa1\xa5\x5d\x87\xfa\x14\x38\x62\xe9\x2b\x1b\xcb\x55\x5a\xde\xe8\x5f\x41\x7c\x9c\x05\x8b\x1c\xaa\x25\x69\x8e\x87\xcd\x5c\x7c\xa1\x2e\xca\x3f\x4c\xe4\x87\x03\x5e\xc6\x4f\xa3\xb0\xec\x28\x57\x18\x6a\xbb\x05\x69\xaf\x04\xbc\x98\xe1\x30\x9d\x21\x29\x09\x85\xd4\x37\x92\xb0\xb9\xac\xf3\x66\xed\x0f\xc5\xd9\x7c\x6a\xa2\x8a\xc6\xc3\x59\x94\x85\x99\xbf\x42\xa5\xe8\x9a\x89\x47\x31\xa9\x3a\x62\x61\x77\xcd\xdd\x66\xb8\x9a\xa2\x45\x10\x0c\xfd\xca\x06\x4f\x95\x51\xf0\x21\xfa\xaf\xc8\x7e\x2a\xda\x75\xbb\xb7\xa4\x45\x8f\x7e\x8a\x1b\x39\x4e\x65\xde\xd9\x91\x03\xc2\x66\x00\xa2\xbd\xef\x98\x6c\x6b\xc9\x40\xf8\x81\xcb\xe8\x25\xe9\xf4\x9e\x83\xe0\x50\x59\xe8\x42\xa1\xea\xeb\xf2\x84\x76\x9b\xf6\x9e\x18\x7e\xdc\xc8\xf0\xb3\x3b\x81\xba\xcb\xdd\x6b\x10\x8f\x74\x57\x54\x24\x96\xa8\x1b\xcc\xa7\xb6\x75\x17\xee\xaf\x2c\x32\xc7\x3a\xd2\x30\x0f\x31\x11\xdc\x67\x44\x05\xdb\x0b\x55\x9c\x95\x83\xfe\xb0\x65\x13\x99\x19\x65\x83\xb6\x97\x8e\x89\x98\xab\x0b\xc1\x78\x77\x93\xe1\xc1\x76\xf6\x49\xad\x89\xa3\x5f\xbc\x87\x2e\x9a\x61\x7b\x10\xf5\x37\xa5\x3d\xc1\x12\x7d\xb3\x18\x1a\x87\x4c\x4d\xa2\xb5\xac\x9e\x1a\x72\x6a\x46\xe5\x2b\x71\x27\x9c\xa9\x0e\x1b\x1e\x60\x42\x2c\x03\xb6\x1d\xcc\x9c\xa5\x4b\xeb\x7d\x08\xe6\x15\x19\x15\x29\x2d\x46\xe6\x75\x60\x11\x23\x2f\x6e\xf4\xd5\x3c\x27\x69\xf1\xd4\x60\x3a\x8d\x8b\x2d\xe0\xad\x3c\xd7\x98\x02\xc6\xe0\x35\x9b\x7c\x76\xe9\xf4\x3a\xae\xf1\xe6\xb8\xab\x23\x9e\xd5\x58\x23\xc1\x35\x77\x86\x3a\x8a\x02\x42\x73\x3e\x93\xa9\xd9\x60\xf5\xe1\x4b\x3d\xcf\xd6\xab\x90\x9a\x94\x7d\xc0\xbe\xac\x81\x39\x08\x41\x6f\x01\x0c\x35\xfa\x13\xf1\xa7\xe6\xdb\x85\xad\x4d\x0b\xd9\xb1\x37\x3d\x01\xde\xb3\xf5\x66\x54\xde\xe0\x7c\x2a\xcb\x6e\x54\x0a\x1b\x8e\xf0\xdc\xba\xa3\xdf\x6c\xa0\xe5\xda\x7f\xf7\xb4\xbf\xa4\x3d\xc7\x92\xd3\xbe\x62\xfd\x9e\xb1\x98\x76\x40\x55\x95\x42\xf5\x46\xa6\x07\x38\x37\x81\x77\x44\x01\xe6\xae\xa7\x0c\xc4\x4e\x45\xb0\xba\x11\x58\x6e\x05\x44\xad\xba\x48\xb1\xf6\x6a\x33\x1c\xae\x91\x2e\xe9\xc8\x32\xe8\xeb\xd4\xf9\x65\x67\x1b\xd8\xa6\xad\x26\x68\x14\x83\xa5\xb1\x59\x49\x2b\x32\x99\x6e\x48\x36\x33\x19\x2f\xb8\xcd\x2e\x8b\xc3\x47\x98\x8f\x76\x52\x15\xd4\xd1\xee\xb3\x1d\xcd\xd2\x89\x88\x73\x94\x40\xb6\xbb\x3d\x24\xd4\xb7\xf9\x90\xc7\xff\x85\x11\x3e\x16\x0c\x66\xe6\xef\x50\xea\xcc\xa4\xd9\x4e\x3f\x2f\x08\x5b\x8b\x92\xe8\xc6\x40\x2d\xa1\xba\x08\x39\x5c\x58\xa5\x54\xef\x5d\xf8\xf9\xb0\x53\xa2\xd4\x0c\x55\xd6\xa6\xb4\xf8\xa2\x67\x22\x0f\x31\x74\x84\x13\xad\xf4\x79\x66\xb9\xad\x3c\x10\xf5\x78\x9d\xc5\x70\x8b\x99\x98\x35\xec\xfb\xf0\x0e\x0c\xca\xf1\x23\x78\x1b\x13\x60\xe5\x7c\x07\x9e\x48\xfe\x5a\x3d\xce\x42\xef\x7d\xaf\xa7\xba\x70\x05\x75\xd0\xe6\x79\x04\xc3\x1d\x72\xd0\xdd\xb9\x2d\x98\x58\x25\x9f\xb5\x19\x5a\x56\xeb\x97\x1d\x8e\x7d\xa9\xfa\xdb\x40\xc3\xd5\x15\x46\xa6\x1f\x01\xd2\x46\x6a\x3a\x90\x48\xd0\x75\xbd\x19\xb6\xa0\x13\x37\x65\x06\x60\x28\x7f\x68\x91\x3d\x07\xd6\xe7\x02\xf5\x35\x35\x30\xdb\x04\x69\x33\x18\x85\x65\xa1\x3f\xc0\x4d\xf5\x9d\x8a\x27\xa2\x71\xf3\xca\x64\xd9\x81\x82\x7f\x05\xea\xf5\x4a\x90\xe3\x8a\x3f\x93\x12\x99\x22\x43\xf9\x2d\x9a\x1d\x51\x4e\x1e\x81\x35\x9d\xb2\x2b\xcc\x7b\x31\x4f\x40\xc1\x9a\x4c\xa9\x48\x64\xdc\x8d\xf3\xfb\x34\x17\x25\x1d\xe5\xe3\x2d\xd1\x32\xae\x95\x95\x1e\x3f\xff\xc9\x53\x5b\x54\xbe\x25\x63\x46\x45\x08\x41\x63\x7b\xa4\x54\x1b\x4b\xb5\xcd\xa9\xec\x50\x07\x7f\x34\x63\xf7\x0f\xb6\x22\x1a\x7d\x50\x6b\xc1\xfa\xa6\x86\x62\x28\xd8\xfe\xa5\x42\xa2\x75\xf1\x15\x9f\x5d\xcf\xb7\x39\x66\x14\xfb\xd5\xcf\x38\x35\xb0\xd4\xee\x42\x5e\xdd\x46\x33\xc8\xdd\x04\x41\x15\x74\xb2\x5c\x5a\xb4\x6e\x36\x96\x90\x61\x0c\x93\xee\x05\xfb\xde\xc5\xa1\x17\xb8\x38\xdb\xd1\x7f\xc3\xa7\x14\x97\x9a\x1c\x28\xe8\x51\x66\xa5\x1e\xc9\x7d\xb2\x18\xac\xe9\x33\x7c\x63\x23\xe3\x5b\x04\xa6\xdc\xee\xa1\xe6\x65\x86\xf3\x16\xe8\xf8\x99\x59\x9a\x3a\xce\x8e\x8e\xd3\xe6\xb0\xcd\x95\xc7\x97\x2d\x83\x99\xe4\x6e\xb3\x44\x76\x51\x2a\xb8\x10\xc4\x38\x8d\xd7\xad\xf5\xe5\x40\x92\xb4\x09\x05\xec\x44\x53\x41\xa2\x56\xab\xa3\x99\x09\x01\xe0\x5d\x72\x88\x45\xa6\xbd\xad\x86\xcf\xca\xad\x9b\xc2\x16\xb4\x52\x8e\xa7\x11\x41\xcd\x82\xf0\xb1\x7b\xce\x89\x4d\x79\x77\xb1\xe4\x5a\x33\xb6\x43\xeb\xd4\xfd\x85\x49\xdf\x1d\x73\x8f\xc4\xed\xb1\x4d\x38\xb5\xac\x41\x2b\xd8\x24\x15\x0a\x52\x11\xa7\xfb\x28\x03\x00\x66\xd8\x14\x3c\x1c\x23\x3f\x8b\x92\xac\xcc\x8d\x66\x72\x7b\x25\x22\x18\xd8\xb6\xce\xcd\xa0\xb6\x44\xca\x39\x09\xfc\xcb\xea\xb1\x8c\xf6\xc2\x53\xbc\xe9\xaa\x99\xc8\x05\xfd\x7e\xa0\x57\x84\x23\x2d\xc5\x92\xe0\xd8\xe9\x0a\x06\x52\x4a\xd1\x28\x16\x7e\x2d\x0f\x4e\x40\x13\x28\xe7\x53\xcf\x3a\x41\xd1\xf6\x3d\xff\x70\x99\x2d\x2b\x8d\x9c\x66\xc1\x74\x1b\x87\xd2\xd5\x30\x5c\x07\x99\xcc\xb7\x5e\xe3\x46\x3c\xe4\xce\x48\xaf\xed\x51\xce\x86\xe1\x4b\xe7\x96\xc2\xde\x4b\xb3\x55\xce\x44\x41\xb7\x6e\x14\x91\xe1\x3c\x74\x6b\x67\x17\x5a\xc1\x31\xb1\xb2\x43\xf2\x46\x4e\xa4\x3c\xb6\xbf\x7b\x89\xb0\xf4\x04\xd5\xe7\x51\x3a\x08\x5b\xff\x6c\xbe\x9f\x4e\x52\x3c\xa1\xf1\x9d\xbf\x48\x6a\xc4\x7b\x89\x40\xfe\xe7\x31\xd6\xf5\x63\x2b\xe1\x3c\xc2\xb5\x52\xa8\xf9\x24\x89\xc8\xbb\x02\xaf\x31\xb5\x2c\x25\x18\x4c\x29\xcf\x48\x40\x9f\xaa\xfe\xd7\xd8\x44\xcf\xdb\x22\x30\x00\x16\xc2\x23\x56\xb6\x43\xb2\x5e\xdf\x89\x85\x2f\x48\xd5\xaa\x9a\xf2\x22\xa5\xcb\xd6\x25\x74\xe4\x97\x06\x2f\x8d\x55\x0e\xf7\x06\xc1\xea\x44\x2c\x68\xe0\xef\xba\xfa\xfe\x7e\xfa\x1e\xad\x73\xc5\xf7\xcb\xec\x5c\x7b\x11\xb3\x3a\x27\x63\xba\x40\x08\x3d\xbf\x16\x31\x51\x59\x6f\x66\x96\x16\xff\xa5\xec\xd8\x1d\x65\xe3\x65\xce\x53\x58\xf5\x42\x28\x37\x94\x9d\xe2\x7e\x4d\x6a\xb7\x76\xec\x0c\xe3\x9f\x73\xea\x2c\xdb\x9f\x1f\xc2\x99\x85\x1e\x41\x7f\x14\xb0\x61\x0d\x87\xbc\x32\x1e\xc6\x02\x77\x57\x40\xc7\x5b\xf8\x89\x78\x05\x75\x47\xca\x6e\x58\xf7\x13\x23\xe3\x9d\x6b\x5f\xd9\x23\x32\x85\x00\x74\xe5\xda\x2d\x29\xef\x82\x6b\xe0\x11\xbf\xa0\x46\xc1\xe1\x39\xe9\x93\x64\xba\xfb\xba\xd6\xe8\xca\x1b\xfa\xba\xed\x01\xd5\x70\x4c\x95\xad\x79\x69\xba\x18\x43\x64\x4c\x69\x0c\x5a\xfd\x37\x23\xc7\x51\xa1\xc2\xfd\x88\x0b\x50\xb1\x94\x4b\xc1\xe5\xa5\xd8\xc3\x2a\xaf\x17\x4f\x8e\xc7\x49\xc2\xe0\x63\xc6\xee\xfe\x4b\x51\x2e\x7e\x00\x55\xdc\x96\xd4\xec\xed\x2c\xb5\xbb\x05\x42\x99\x74\x9e\x87\xd1\x6c\xa0\x38\x21\x63\xd8\x2a\x97\x82\x1c\xd2\x44\xe2\xca\xdc\xe8\xf5\x2a\xd3\x26\x61\xfa\xbc\xa0\xd4\x82\xff\x1e\xa1\xfd\x28\xaa\x49\xcc\x2b\xab\xf8\x39\x23\xbf\xfd\xd6\x64\x7d\x80\xa3\xef\x3b\x92\x6e\x53\xf8\x7e\x7b\x75\xe2\xd1\xcc\x60\x22\xbf\xd1\xae\x7c\xba\x40\x8e\xe5\x9f\x3a\x91\x33\x03\x23\x9a\xb7\x18\x38\x6e\x42\x07\x1e\xab\xbc\x3c\x07\xc1\x2c\xc9\x4d\xe3\x7c\xc3\xb7\x21\x23\x1d\x02\x59\x2c\xb4\xf7\x7a\x7f\x2e\xa6\xb0\xe8\xbe\x05\xd4\xc3\xcc\x75\xb1\x0c\x4f\xc7\xd8\x80\x21\xfa\x61\xc0\x0a\x69\xe9\x52\x07\xa0\x6a\x63\x0d\x74\xe7\xbd\xd3\xed\xc0\x3f\x89\x86\x23\x92\x0f\x44\xc6\xc1\x2b\x7b\x57\xa6\xa0\x6f\x35\xa5\x9c\x45\x01\xd9\x77\x3b\xe5\x5d\x86\x9e\x09\xc0\x83\x38\x8f\xf2\xff\x25\xb6\xb8\xaf\x13\x37\x26\xba\x6c\x1d\x6c\x08\x82\xf3\x03\xab\x8b\xd3\xb2\x99\x62\x39\x9b\x12\x5b\x0b\xf8\xe1\x8c\x9b\xc5\xeb\xe0\x77\x9e\xdf\x7e\xa1\x80\x39\x45\x52\xb3\x8d\x7d\x35\x42\x50\x06\x5e\x08\x23\x98\x00\xfd\xf8\xa5\x7e\xdd\x22\xe8\x28\xa6\x1a\xf4\x4b\xfc\x84\x48\xab\x96\x61\x15\x79\x3f\x47\x0d\x2b\xe2\x1a\x99\xdd\x6b\x52\x23\x62\x77\x20\xd4\x84\xef\x93\x06\xb9\x98\x68\xb8\xdf\x3e\x40\x80\x32\x19\x5d\xd7\x43\x92\xaf\xdd\xde\x04\xf5\x94\x0d\xcf\x2e\x43\xcf\x0f\xdd\x21\x76\x45\x50\xc9\x86\xd4\x05\xf2\x37\x30\x05\x48\x38\xe9\x4b\x46\x8b\x60\x60\xef\x73\x24\xc5\xea\x68\x6b\xc5\xd3\x6c\x3a\x29\x54\x70\xd8\x0e\xb3\x08\x22\xd7\x11\x7a\xa7\xa0\x43\x08\x49\xe7\x4e\x6b\x47\x60\x28\x3c\xe7\xe1\xe7\x81\xaf\xe2\xb1\x1d\x82\x95\x80\xd7\x9d\x4f\xf9\x4d\xfa\x3e\xe7\x0e\xd7\x67\xd0\x61\x39\xb5\x39\x27\xc3\x55\xd8\x41\xa3\x0a\x63\xd0\xab\xe9\x41\x5a\x48\x12\x7e\x54\x2e\x8e\x18\x01\x23\xaa\x4e\x95\x52\x33\xf7\x5a\x64\x62\x8c\x6e\x05\x6b\x47\xb2\xb8\x0b\x75\xe3\x9e\xa3\xc2\x7e\xed\x25\xe5\xbc\x5f\xe3\x5f\x86\x66\xf7\xf5\xb4\x68\x70\x8e\x3b\x8b\x49\x5e\xbb\x6e\xa4\xe9\x06\xe3\x4b\xf4\x68\xde\xef\x44\xb1\x1a\xa4\x07\xd6\xd4\xe2\xf4\x8e\xd6\xa2\x1e\x75\xff\x8d\x38\x82\xfb\x35\x97\x79\x4d\x78\xf6\x3c\xfd\xd3\x73\x9d\xa9\xbd\xa5\x81\x19\xd7\x79\x0d\xae\xac\x16\xf5\x3a\xb7\x98\xd0\xcd\x61\x1a\xac\x23\xe1\x96\x10\xde\xb6\x46\x1a\xad\xa6\x8e\xd9\x25\x2a\xae\x37\x2d\x01\x41\x27\x39\xdf\x8d\xcf\x0c\x1c\x03\x2d\x42\x26\x4d\xde\x39\x5f\xeb\xef\x7e\xaa\x81\x08\x8e\x09\xb5\x4d\x8d\xb8\xaa\x3b\x4a\x5c\xc2\x24\xad\x9e\x0a\xda\x15\x27\xbc\xe6\xaf\x91\x2c\xcb\xda\x5f\x8f\xb6\xc2\x07\x35\x6e\x5f\x97\x2f\xa2\x4f\x80\x93\x10\x82\xac\x2b\xaa\x51\x4e\x5e\x3b\xc5\x52\x44\xeb\xbd\x47\x5b\xa8\x58\x28\x56\x09\x2c\xde\x50\x4d\x7d\xc0\x5e\xe3\xe6\x48\xd9\x64\x6c\x22\x12\xe6\xee\x63\x32\x6d\x1e\xb1\xbd\xcf\x77\xd9\xb5\xd8\x7f\x7d\x51\x20\xac\x1f\x4e\x18\xee\xf7\x67\x91\x57\xa4\x92\x7c\x59\x72\xd9\xf9\x25\x99\xb9\x56\xc1\x47\xfa\x9e\x63\x19\x3c\x39\xd8\xc4\x87\x61\x26\xfb\xef\x3a\xc0\xf4\x58\xcb\x50\x92\xc1\xdd\xf9\x9f\xf3\xbf\x72\x29\x06\xfe\xcb\xf1\x7a\xb8\xea\xbd\x4f\x7f\xbb\xf4\xe7\x12\x85\xad\xc6\xdb\x49\x1e\x19\x19\xd2\x6a\xc9\xba\xef\x83\xc4\xde\xea\x15\x55\xd1\xc5\xe8\x20\xb8\x34\x53\xa1\x50\x01\xe1\x7d\x88\xf8\xcf\x44\xb5\x99\x40\x8c\x71\x7d\xa0\xf7\x9c\x90\x70\x1d\x55\x4d\x3a\x38\x35\xc5\x83\xf7\x05\xad\xed\x83\x67\xac\x94\x2f\x1f\xad\x1e\xe1\xbc\x92\x7f\xb9\x72\x48\x08\x47\x77\x32\xc1\xea\x57\x94\x16\x46\x38\x19\xd3\x5d\x46\x89\x39\x61\xd4\xf2\x99\x1e\xae\x30\xbb\xd3\x90\x7a\x98\xef\xb6\xc6\xa4\x60\xe9\xf0\x94\x6b\xe3\xd1\x0a\x45\x47\xf3\x6f\x80\x53\x2d\x0b\x59\x2b\x75\x90\xaf\x76\xb1\x2b\xd3\x4c\x2b\x1b\x85\xc4\x09\x47\x91\x2a\xc4\x7f\xdd\x6c\xd9\xaa\x2f\xdc\x88\x53\xe2\x2c\x26\x97\x2b\x29\x71\x98\x26\x6a\xf1\x5f\x7a\x41\x55\x5e\x30\xaf\x3d\xe0\xaa\xd2\xc8\x2d\xac\x46\x9d\x32\x97\xe9\xb5\x35\xa0\x9d\x24\x67\x7b\xf3\xc2\x43\x66\xa4\x96\xcb\x41\x36\x62\xb3\xbf\x8d\xfe\xba\xa9\xc4\xb5\xa0\xf3\x97\x70\x75\xa6\x22\x1d\xe1\x2e\x98\x96\xa0\xdd\x7c\xc7\x9f\xfd\x39\x5a\x14\x0d\xdd\x1b\xab\xaf\x65\x63\x36\x86\x76\x63\x2d\x35\x60\x6f\xd9\x04\x11\x12\xd1\x6e\x00\x6b\x93\x9b\x0a\xc5\x48\x0a\x3a\x20\x9b\x65\xed\xe0\xb2\x73\x29\x9a\x9c\xdb\xd1\x14\x3c\xcc\x84\x61\x7e\xfb\xc0\x1a\x30\x2d\xf1\x81\xa3\xcb\x02\x70\x29\xaa\x87\x33\xc3\x56\xf8\xdb\x29\xb9\xcb\xa1\x75\xad\xe9\x63\x7f\x35\xab\x17\x10\xd0\x67\x5f\xe7\xd6\xde\xa4\x75\xfa\x5c\xfe\x1d\xde\x22\xc1\x94\xec\xf1\x41\x3b\x67\x96\xa9\x70\x6c\x71\x8c\x91\x50\x8f\x03\x0c\xa4\x48\xb4\x88\x34\x21\xe3\xd6\x44\xd2\xc1\x90\x7d\x58\xfb\x7d\x1d\x29\x84\x0e\x3b\x3b\x36\xcd\xeb\x7b\x78\xf9\x70\xf2\x90\x24\x4a\xa9\x33\x99\x0d\xef\x43\xff\x27\x5c\x1e\x88\x0e\xb8\x5b\xc7\x47\x42\x1b\x67\x0c\x2a\x11\xd2\x8c\x73\x02\xee\x9e\x5e\x22\xc8\x21\x0e\x04\xc3\xec\x52\x26\x24\xf3\xb4\x0b\x5a\x8f\xbc\x23\x20\xc4\xdd\x82\x17\x2d\x08\x56\xd5\xcf\x58\x2b\xb3\xbf\x5f\x4a\x7f\x2e\x86\x5e\x59\x8c\x73\xd6\x8b\xbf\xe4\x32\xb3\x1d\x2b\xf0\x1f\x3a\x26\xf2\x6a\x83\x2d\x55\xce\xa2\xc6\x50\x85\x68\x13\x43\xa0\xa5\x56\x5e\x1e\x99\x6e\x1e\x2a\x86\x83\x24\x44\x57\xb5\x9e\xa6\xe4\x05\xba\x4d\x83\x7d\x18\x2a\xb0\x60\x28\xf3\x49\x4f\x88\xb8\x4f\xd2\x30\x5f\x97\x6c\xad\xbf\xde\xdf\x9f\xba\x37\x61\x3f\xc0\x26\x81\xd2\x71\xb5\x55\x49\x45\xf8\x08\x2d\xd7\x2e\xf8\x9d\x52\x08\x83\x9f\x9e\x82\xea\x03\x4f\x75\x5a\x4e\x66\x5c\x78\xa4\xaf\x97\xe9\xb8\x81\xc2\x84\x95\x13\x1f\x24\x74\x49\x23\xcf\x20\xec\x19\x17\x40\xd6\xc8\x1c\xe5\xdd\xaf\x86\xad\xea\xe1\x5c\xa7\x06\x4b\x91\x5c\xb8\xb2\x26\x71\x66\x53\xf4\xfb\xf2\xdd\x50\x4c\xc7\x93\xb7\xe3\xbb\xf3\x51\x54\xf8\xef\x27\x66\x74\xa3\xd6\x3c\xc9\xe8\xee\x66\xcd\xa2\x07\x8c\xac\x90\x33\x56\x85\x6e\x67\x6d\x50\x4e\xe2\x12\xa4\xc6\x70\x8f\xd7\x1e\xec\x5d\xf5\x82\x68\xc1\xd4\xd9\xe3\xea\xc0\x0a\x8b\x8f\x3b\x9b\xb7\xcc\x3b\xdd\x5b\xf2\x94\xfd\x0d\xc6\x12\x6c\xb9\x18\x95\x3a\x39\x08\x32\x0e\x4b\x7c\x03\x84\xb3\x8e\xbd\x36\x34\x5b\x6d\x9c\x26\x76\xf6\xb2\x24\xd2\x69\x59\xde\xb1\xdf\x5d\xb6\x42\xb8\xa9\xc1\xf2\x49\x61\xef\x1b\x1d\x10\xa8\x1e\x4d\x0f\x53\x18\x36\x74\xb0\x79\x9d\x97\xee\x36\x36\x66\x2e\x95\x73\xbe\xb0\x39\xaf\xfa\x18\x56\xff\xfb\x19\x3e\x16\xec\xd1\x71\xe3\xe3\xa3\xb6\xb0\x55\x4b\x03\x02\xb1\x31\x5f\xce\x82\x6d\x59\x9d\x7a\xaa\x15\x43\x53\x22\xf8\x4e\x5e\x3b\xae\x02\xfa\xa4\x31\x61\x0f\xd4\x4d\x58\x92\xa7\x0c\x4b\x00\xd5\x93\xd7\xa9\xdc\xb7\x73\x0e\xd9\xbc\xc4\x38\xbb\x4b\x93\x7b\xc5\xc4\xdf\x89\x6a\x37\x5e\x2b\x81\xa5\xac\x14\x2a\xfb\x42\xfd\xcd\xed\x4a\xd1\xb4\xcb\xe6\x19\x58\x25\x73\x90\xe6\xc4\x72\x82\x7d\xe3\x2d\xca\x34\xc3\xef\x3c\x2c\x52\x6b\x54\x13\xb4\xe3\x4a\x50\x35\xab\x18\x5e\x62\xca\xb8\x1e\xba\x0d\x71\x18\x3c\x06\x2c\xfd\xeb\xb1\xb4\x74\x6a\x56\xe5\x8d\xee\x2f\xca\x04\x64\x32\xf8\x04\x55\x37\x8a\x02\x1e\x93\xbe\x23\xaa\x57\xaf\x01\x5d\x00\x0c\xa2\x2b\xc3\x49\x2a\x0c\xcb\x6f\x68\xe5\x3d\xc1\x81\x6c\x93\xa1\x99\x79\x92\x3c\x39\xcb\xc0\x9f\xaf\x01\x8a\x97\x9a\xd4\xaa\x5e\x9e\xf0\xdf\x86\x3f\x48\x2d\xa9\x16\x29\x85\x06\xc6\xca\x59\xc1\x11\x58\x20\x4b\x39\x3b\xc3\xdf\x19\x0a\x9f\x40\x5d\xb7\xf4\x4f\xad\xa1\xf0\x93\xdd\xec\xec\x1b\x94\x84\x2d\x34\x22\xbb\x63\x3c\xf2\x14\x66\xc7\x44\x41\x2c\x3d\x52\x52\x3f\x93\x92\x38\x87\x56\xf3\xb6\x7d\x79\x82\x95\xa2\x9e\xd0\x83\xc6\x22\xfd\x06\xf5\x5e\x1e\xe2\x5f\x25\xf1\x95\x5e\x36\x09\xc8\xaa\x65\x60\xa5\x93\xbe\xd4\x51\x24\xac\x05\x84\x86\xa5\xd0\x80\xe4\x9b\x7f\xd6\xb8\xae\xa8\xba\xdc\x88\x58\xfe\xbd\xd4\xe5\x5f\x0d\x3c\xc4\x5a\x29\x77\xf1\xf4\xce\xfd\x9c\x47\x3a\xa0\x64\xa8\x5f\x8a\x88\x41\xb3\xa7\xbe\x65\x6a\x36\xe7\x89\xd0\xcd\x4a\xab\x2b\x30\x38\x6f\x52\xf8\x9b\x74\xd2\x4f\x8b\x02\x4f\x64\x31\x82\xd5\xd3\xb9\xda\x0e\xc1\x0b\x36\x33\xff\xfa\x94\x5a\x5c\xe9\xeb\x31\x4b\xf3\xcd\xec\x44\x8a\x10\x5c\x2d\xea\xcf\x18\x20\x02\x63\xb3\x15\x9e\xef\x6b\xff\xca\x50\xf3\x35\x53\x12\xed\x40\xe8\xdc\x63\x89\x18\x6b\xc0\xab\x9d\xb3\xec\x21\x42\x84\xe0\x18\x54\x37\xc9\x7c\x24\x4a\x80\xcf\x2d\x8e\x44\xdb\x89\x01\xd4\xe7\x55\x46\x95\xc4\x6f\x6b\x4d\xef\x48\xa0\xc5\x23\x98\xf1\x7e\xe6\x10\x15\x54\x7f\x93\x8c\xb2\xfb\xaa\x65\x84\x97\x69\xfb\x3b\x7f\xfd\x0e\x19\xad\x6c\x3b\x6d\x2f\xfd\xdb\x41\x0e\xb2\x06\xdd\xca\x6b\xc6\x9b\xd3\x96\xe2\x26\x5c\xbc\xfd\xf0\xd3\xa5\x81\xb3\x5c\xaa\x6c\xa2\x19\x91\x18\x3d\xcb\xfe\xc7\xee\x49\xb1\x04\x4c\xb8\xcd\x8d\xee\xf7\x5f\xcd\x15\xe2\x48\x88\xb3\x8a\x3f\x95\x01\x5b\xb6\x66\xbd\xff\x2b\x2f\x15\x41\xda\x22\x66\x12\xb4\xae\xcb\x92\x91\x77\x64\xd0\xdb\x56\x57\xb7\x91\x3e\xaa\x02\x5d\xe4\xe2\x3d\xe7\x89\x2a\xa6\x8e\xc9\x38\xa8\xca\xc6\xca\x85\xa7\xa6\x0d\x10\xed\x1c\xd4\xbd\xb6\x62\xf1\x18\xad\x27\x5b\xfc\x93\x0f\x06\xeb\xd9\x14\xa2\x77\xe1\x88\x3d\xcd\xe5\xd5\x52\x3b\xa7\xcb\x6d\x74\x83\xfa\x00\x76\x33\x3a\x21\x84\x57\x6a\xf6\x3f\xa8\x28\x7c\xfa\x79\x75\xd6\xf8\xcc\x08\x38\x49\x70\x0d\x30\xd8\x30\x5b\xa3\x2e\xaa\x42\x7d\xd8\x57\x3f\xcd\xc1\xd7\x61\xba\x39\xe4\x5e\xdd\xf1\xdc\xc6\x9c\x6f\x61\x31\x6b\x30\xc3\xaa\xd9\x5e\x6c\xb2\x3e\x6e\xe6\x95\xf0\x8e\x85\x5a\x68\x8e\x98\xe7\x85\xa1\xed\x29\x9e\x39\x3d\xc8\xc7\xb0\x41\x97\xcd\xfd\xb3\x5a\x58\x79\x9e\x78\x3d\x00\x3a\xc1\x9b\xa8\x78\x52\xb6\x9e\x24\xf4\xb8\x23\x86\x63\xaa\x9c\xa1\x1e\x86\x6c\xbb\x99\xb9\xaf\xe6\x5b\x1a\xf8\x02\xbf\xe0\xc9\x6d\x2d\xd8\x1e\x11\x9f\x34\x72\x85\x35\x66\x44\x2d\x46\xc5\x00\x74\xc3\x76\x9c\x30\x96\xef\xc8\x87\x80\x46\x1a\xdf\x70\xf1\x1c\x42\xe8\x2d\x23\x85\x24\xb9\xd7\x45\x90\x03\x27\x15\x72\xa3\xfb\xb9\x57\x25\x89\xcc\x0a\x2c\xb4\xd3\x28\x0e\xf2\xd3\x6d\x3e\x18\x85\x3b\x6c\x84\xc9\x84\xf0\x26\x99\xfa\x6d\xa0\x4e\x77\x8d\xe5\x9c\x30\xb7\xc1\x87\xcf\xa6\x05\x58\x81\xd1\x88\xef\x49\x00\x76\xc2\x14\xbe\x4c\x61\xf1\x05\x2a\xbc\x30\x8d\x0e\xc6\xd3\xe3\x60\x63\x2c", 4029);
*(uint64_t*)0x20001658 = 0xfbd;
*(uint64_t*)0x20001660 = 0x200012c0;
memset((void*)0x200012c0, 182, 1);
*(uint64_t*)0x20001668 = 1;
*(uint64_t*)0x20001670 = 0x20001380;
memcpy((void*)0x20001380, "\x7a\x3f\x12\x12\x8c\xb1\xee\x52\x23\x0f\x34\x0b\x20\x01\x6c\x81\xb6\xe0\x73\x93\x91\x64\x3d\x2c\x9f\x62\xce\x93\x17\xc0\x7d\x16\x58\xaf\xf2\x9c\x98\x93\xee\xa1\xfe\x3b\xb8\x74\x7e\x8a\x34\x80\x7e\x73\xe0\xa5\x6d\xb5\xd7\xa4\x04\x9f\x1e\x06\x2c\x81\xa7\xcd\xd1\x3d\x30\xe4\xfe\x1d\xa5\x62\x74\x35\xa4\x24\x99\x64\xe7\x11\xa2\xf2\x66\x87\x0a\xd8\x56\x3b\xb3\x32\xad\xed\xe2\xbe\xff\xe8\x69\x88\x8d\x54\xb1\x03\x82\x1b\x88\xf9\x64\x1f\x5c\xaa\x6e\xfa\xaa\xdf\x39\x20\x36\x08\x45\x92\x0c\x68\x88\xc2\x98\xc9\xe6\x64\xbf\x8b\xaf\xb1\x28\x7f\x69\x69\x43\x64\xce\x43\x26\x6e\xa2\x69\xba\x06\x01\xd0\x8f\x60\x73\x9c\xc3\x95\x56\xc7\x57\x5c\x2e\xd8\x38\xfd\x20\x49\x5e\xe6\x5f\x96\x5f\x3c", 170);
*(uint64_t*)0x20001678 = 0xaa;
*(uint64_t*)0x200027d8 = 4;
*(uint64_t*)0x200027e0 = 0;
*(uint64_t*)0x200027e8 = 0;
*(uint32_t*)0x200027f0 = 0;
*(uint32_t*)0x200027f8 = 0;
*(uint64_t*)0x20002800 = 0x20000240;
*(uint16_t*)0x20000240 = 2;
*(uint16_t*)0x20000242 = htobe16(0x4e24);
*(uint32_t*)0x20000244 = htobe32(0);
*(uint32_t*)0x20002808 = 0x10;
*(uint64_t*)0x20002810 = 0x20001880;
*(uint64_t*)0x20001880 = 0;
*(uint64_t*)0x20001888 = 0;
*(uint64_t*)0x20002818 = 1;
*(uint64_t*)0x20002820 = 0x200018c0;
*(uint64_t*)0x200018c0 = 0x11;
*(uint32_t*)0x200018c8 = 0;
*(uint32_t*)0x200018cc = 1;
*(uint8_t*)0x200018d0 = 0x7f;
*(uint64_t*)0x20002828 = 0x18;
*(uint32_t*)0x20002830 = 0;
*(uint32_t*)0x20002838 = 0;
	syscall(__NR_sendmmsg, r[0], 0x20002780ul, 3ul, 0x48010ul);
	return 0;
}
