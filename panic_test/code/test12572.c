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

#define BITMASK(bf_off,bf_len) (((1ull << (bf_len)) - 1) << (bf_off))
#define STORE_BY_BITMASK(type,htobe,addr,val,bf_off,bf_len) *(type*)(addr) = htobe((htobe(*(type*)(addr)) & ~BITMASK((bf_off), (bf_len))) | (((type)(val) << (bf_off)) & BITMASK((bf_off), (bf_len))))

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0x10ul, 3ul, 0xc);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200014c0 = 0;
*(uint32_t*)0x200014c8 = 0;
*(uint64_t*)0x200014d0 = 0x20001480;
*(uint64_t*)0x20001480 = 0x20000040;
*(uint32_t*)0x20000040 = 0xec4;
*(uint8_t*)0x20000044 = 0;
*(uint8_t*)0x20000045 = 0;
*(uint16_t*)0x20000046 = 0;
*(uint32_t*)0x20000048 = 0;
*(uint32_t*)0x2000004c = 0;
*(uint8_t*)0x20000050 = 0;
*(uint8_t*)0x20000051 = 0;
*(uint16_t*)0x20000052 = htobe16(0);
*(uint16_t*)0x20000054 = 0xead;
STORE_BY_BITMASK(uint16_t, , 0x20000056, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20000057, 1, 7, 1);
memcpy((void*)0x20000058, "\x80\x45\x2a\xe3\xf2\xc0\x0d\x66\x0a\x48\x23\xdf\x12\x04\xf6\x40\xb6\x6d\x81\x9c\xfd\x9e\x0c\x00\x8e\x85\x71\xef\x02\xe1\x42\xb4\xb0\xf7\xd2\x7f\x49\xba\x22\xd2\xf8\xd1\xf4\x19\x15\x9b\xcc\x4f\x41\x75\xfc\xd6\xf0\x40\xba\x36\xd5\xb5\xc2\x63\xbb\xc8\x74\x0a\x18\xe2\xf3\x43\x62\x02\x04\xba\x80\xce\xb4\xc4\x19\x5d\x69\x7b\x91\xab\x91\xb5\xda\xe3\x1f\x04\xfb\x53\x53\xea\xec\x0a\x08\x33\xdf\xc8\x23\x73\xdc\xaf\x64\x68\x68\x20\x54\x7a\x83\x9e\xb1\x0e\xd6\xc7\x8b\xb6\x61\xc4\xb6\x8a\x58", 121);
*(uint16_t*)0x200000d1 = 8;
STORE_BY_BITMASK(uint16_t, , 0x200000d3, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200000d4, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200000d4, 0, 7, 1);
*(uint8_t*)0x200000d5 = 0xac;
*(uint8_t*)0x200000d6 = 0x14;
*(uint8_t*)0x200000d7 = 0x14;
*(uint8_t*)0x200000d8 = 0xaa;
memcpy((void*)0x200000d9, "\x29\x62\x32\xaf\xf1\xdb\x29\xce\x50\x90\xf0\x9c\x32\xa9\x93\x95\x57\x6c\x51\x88\xa2\x39\xf7\x46\x91\xc9\xdf\x61\x1e\xcc\xb8\x41\x72\x32\xb5\x3e\x47\xf6\xbf\x4d\xca\xef\x73\xb3\x73\x7b\x91\x52\x8e\x6f\xcf\xd8\xe0\xa2\xab\xec\xbd\xdd\x0f\xf7\x67\x35\x4f\x7e\xdb\x14\x24\xba\x48\x1a\xb7\x78\x90\x0f\xe8\x84\xf0\x11\xf6\xa3\x17\x86\xb0\x82\x24\x9e\x5d\x53\xa6\x7e\x75\x16\xc8\xe6\x08\x27\x24\x89\x37\x1c\xbf\xb0\x62\x44\xb8\xc2\xa6\x5a\xd8\x37\x56\x5b\x3e\x21\x1f\xd6\xe9\xb7\x6f\x0a\x40\x8a\x0c\x85\xbc\x19\x1c\xe3\xc0\x15\x42\x74\xb1\x88\x50\xf6\xe1\xe7\xfc\x42\x5b\xad\x62\x0d\x23\xe2\x95\xf8\xe6\x71\x28\x30\x84\x99\xce\x42\x45\xf7\x27\xd1\xbf\x6a\xd1\x44\x4a\xa4\xa8\xe1\x59\xc5\x2f\x92\x16\xb5\x88\xbe\x03\x10\xc8\x83\x1d\xc1\x8d\xde\xa7\x68\x71\xe1\x45\x30\x0a\x12\xda\xf3\x24\xda\x29\x37\xe9\xc1\x11\x75\x48\xf6\x0a\x9d\xf7\x77\x94\xb8\x93\x17\xf3\x8d\x69\x44\x32\xb2\xa5\x14\x20\x3d\x46\xf1\x60\x32\xed\x3e\x33\x3e", 230);
memcpy((void*)0x200001bf, "\xa1\x01\xec\x44\x69\xc9\xf8\x2c\xd3\x6d\x8c\xe5\x0c\xe5\xc5\x91\x92\x3e\x15\xf2\x79\x7b\xe8\x8b\x46\x78\x33\x31\xd7\xac\x9f\x6f\xb6\xf4\xa8\x56\xfe\xe1\x19\xc1\x9e\x5d\x88\xfd\xec\xd2\x7b\xe2\x3a\x43\x27\x17\x87\x15\xf0\x54\x9d\x64\x0e\x21\xb3\xd5\x7f\x5d\x55\xf2\x91\x26\xe5\x29\xdc\xe3\x24\x35\x58\xdd\x31\x78\x62\x37\xda\x2c\x7d\x40\xc1\x46\x7e\x4a\x6e\xee\x69\x5f\x4c\x11\x55\x2d\x4b\xa0\x8d\x10\x22\x3e\x27\xf0\xe1\x75\x24\xa5\x2a\x86\xc6\x02\x7f\x08\x5d\x75\x0a\xea\x32\xfc\xbd\xfa\x07\xf3\x1e\x3c\xf5\x4b\x7f\x4f\x11\x8c\x75\xf1\x46\xb7\x01\xde\xfe\xe8\xe7\x4e\xef\xab\x00\xef\x42\xc5\xc4\x08\x66\x0f\x79\x0b\x4c\x65\x16\xa7\xec\xfa\x93\x81\xbc\xb3\xbc\x67\xa6\x9b\xbe\x7e\x26\x03\x1b\x05\x99\x99\x6c\x53\xc2\xc3\x9a\x93\x1a\x09\x99\x50\x11\xe3\x08\x1e\x26\x07\xfe\x70\xb9\x7a\x1a\xa5\xcb\x32\x09\x3d\xe0\x95\x11\xc7\x74\x42\xc1\xcf\x14\x16\x14\x0f\xce\x36\xb0\x21\xa2\xd6\x61\x08\x64\x99\x20\x7d\x22\x8d\x97\x8a\x22\x44\x9f\x7b", 234);
*(uint16_t*)0x200002a9 = 0xb9;
STORE_BY_BITMASK(uint16_t, , 0x200002ab, 0, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200002ac, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200002ac, 0, 7, 1);
memcpy((void*)0x200002ad, "\x17\x03\x01\xc0\xb7\x98\xa6\x1c\xea\xcd\x1f\xb1\xb4\x4e\xa3\xb2\x2d\x3e\xd4\x76\xd2\x21\xef\x1f\x75\xf2\x6e\x07\xbd\x21\x4b\xa7\x66\x3c\xc2\xc9\x21\xed\x83\x28\xb2\x5b\x27\x3a\x8e\x68\x2e\x55\xac\xb0\x50\x9d\x4d\xaa\x33\xfc\xa5\xe1\xc4\x81\x62\xfa\x57\xab\x5b\xb9\x62\xe8\x75\x62\x76\xe5\x67\x67\x64\x27\x74\xef\x1e\x0a\x36\x8c\x11\x43\xa8\x87\x51\x18\x29\xe7\xb4\x47\x81\xc9\xce\x40\x8b\x4d\x91\xfd\x37\x9e\xb9\xf7\x8f\x3f\x4f\x29\xc3\x91\x8d\x41\xf7\x4c\x9f\xb6\xac\x3e\xb9\xdd\x79\x3c\x8c\x96\x0d\x63\xff\xdc\xb1\x08\x68\x8a\x22\x91\x66\x00\xcf\xf9\xd6\x56\xf3\x1c\x3b\x06\x08\xa0\x42\x9f\x4e\x45\x9d\x40\xea\x64\xcd\xbe\x2a\xe0\x6d\xde\x45\xb7\x63\x78\x6c\x3f\x26\xf4\xa8\x34\x19\xde\x1f\xb4\x63\xbd\x56\x16\x97\xd5\xdf", 181);
memcpy((void*)0x20000365, "\x0a\x8a\xe9\xf2\x03\x3a\x43\xbb\xbf\x79\xc6\x40\xbb\x93\x95\xa9\x81\xf1\x44\xd3\xb9\x3d\xaa\xa1\xb9\x1b\x74\xaf\x40\x5b\xc4\xa5\x7c\x15\x38\xa0\x83\x42\xc9\x55\x6a\x26\xfd\x90\xf7\x56\x80\x36\xe9\x1b\xa8\x4c\x6c\x70\x4d\xf0\x56\x87\x0a\x5a\x45\x6b\x49\xef\xa5\xa6\x3a\x3b\xa9\x7a\x4a\x37\x86\x13\x2c\x1c\xbc\x0a\x92\x51\x03\x7d\xb5\xe8\x18\x25\x27\xe4\x55\xaf\x7e\x17\x44\x1a\x52\xb8\x80\xf6\x94\x9a\xda\xfe\xfd\x3f\x48\x16\x6c\x94\xc8\x57\x4b\x34\x37\x4f\x37\x00\x2f\x25\x3f\xd2\x92\xa4\x0b\x44\xb6\x90\x03\x8f\xab\x70\xae\x5f\x60\xbf\x8b\x44\xc1\x28\xd3\x6b\xe5\x66\xf2\x3a\xca\x58\x05\xf5\xa2\xd2\x4d\x1b\x7c\x8d\x55\x03\x4e\xac\x9a\x17\xcd\x89\x10\x5c\x50\x28\xec\x43\x31\xe6\xbb\x8f\xd6\x3a\xd1\x56\x49\x6d\x0e\x38\x0a\x83\x7a\x65\x6a\xc4\x84\xc6\xdc\x54\xd1\xe1\x68\xd8\x84\x07\xbd\xdf\xd7\xe5\x2f\xdf\x6f\x90\x89\x18\xab\x43\x8b\xb6\xba\xfe\xbd\xcb\xc9\x06\xe7\xaa\x8e\x52\xd3\x4b\xdb\x10\x9a\x1a\x34\xc2\x1c\xf9\xf5\xdf\x04\x5c\x66\x51\x16\x69\xc2\x23\xb1\xbc\x07\x53\x07\x21\x9a\x87\xae\xc5\x1c\x57\x6d\x0b\x6b\xf3\x0b\x9c\xf4\x24\x04\xd5\x60\x06\xc3\x48\xb1\x38\x00\x66\x2f\xb0\x6a\x97\x9b\x0b\x31\x2a\x2a\x24\x30\xe4\x1f\xf1\xc7\x81\x96\x15\xb2\xde\x66\x4e\xbe\xec\x3a\x68\x9c\xc1\x0e\x92\xeb\x36\xa6\x43\xf4\x8e\xa2\xad\x91\xc9\xf9\xca\x34\x68\x0f\xe4\xde\xe7\x01\x80\x25\x2c\xe1\x6c\x55\xd3\x80\xc7\xfb\xa2\xec\x20\x01\x32\x66\xdc\x70\x62\x59\xf6\xa3\x50\x15\x09\xb5\xac\x17\x48\x21\x55\xa3\xff\xa4\xc6\x41\x4f\x7c\x33\x2f\xc0\x34\x67\x93\x86\x35\x6a\x21\x51\x29\x39\x70\xaf\x3f\xa6\x30\x07\x7d\x29\xac\x7d\x5b\x3c\x99\x0d\x04\x4c\x65\x4c\x0f\xfe\x5b\xf0\xf4\x34\x7a\x6c\x4d\x1a\x2a\x24\x0d\xcd\xfe\x45\xe9\x82\x03\x2b\xbf\x55\x93\xe6\x1c\x50\x6d\x2d\x94\x05\x0f\x1d\xf9\xa3\x92\x04\xb3\x22\xa9\x40\xd1\x6e\x5d\x4e\x66\x70\x3c\x3d\x9b\x25\x9e\xbf\x64\x21\x06\x30\x82\x45\x42\x8e\x78\x94\x14\x75\x74\xcc\x4d\x9b\x53\xed\xed\x36\x22\x03\x8e\x60\x49\x96\x2e\x31\xb8\x0e\x7c\x25\x8f\x62\xdc\x15\x71\x4e\x9a\x0e\x3d\xe2\x61\x15\xb7\x20\xb4\x3f\x68\x5d\x90\xf6\xb9\x38\x72\x50\x00\xb9\x25\x6b\x4f\x2d\x3d\x9d\x67\x55\x74\x90\x38\xcb\xb1\x43\xec\x7f\xfc\x92\xa1\x99\x1e\xd2\x26\x67\xbc\xab\x97\xbc\x35\x2f\x85\x99\xdd\xeb\x71\xa4\x8b\x0c\x44\x7c\x25\x2a\x74\x8d\xfc\x3d\x14\x69\x73\x4d\x13\x99\xb4\x4c\xb6\x96\xe5\xee\xea\x9d\xd8\x8a\x32\xed\xe5\x6f\xef\x00\x8b\x88\xae\x39\x02\xf9\xf7\xb9\xf5\xd0\x24\x61\x6c\xe7\x64\xf4\x42\x66\x0a\x5a\x5d\xb8\x19\xf7\xc5\x20\x34\x88\xea\x37\x82\xed\xa8\x5f\x19\xe6\x91\xfd\x23\x66\xfc\x70\x67\x59\x55\x5c\x30\xe6\x0c\xd5\x82\x7c\xed\xd2\xdb\xb6\xfe\x25\xf0\xe8\x99\xfa\x8d\x26\xd5\xe9\xdc\xa9\x16\xd4\xe2\xfa\x10\x9d\x66\x61\xd9\xf4\xf1\x09\xfc\x9a\x2e\x7a\xb9\xa4\xd3\xdc\x72\x83\x28\xac\x98\xd2\xbd\x5d\xee\xb2\x77\xfe\x8e\xbf\xd8\x96\x0a\xd0\xca\x47\x09\xa8\xbf\x33\xba\x8a\x3e\xec\x71\x4f\xf0\xae\xa2\x71\xab\x49\xee\x27\x42\x20\x88\xe8\xb4\x32\x39\xed\x5a\x24\x27\xdd\x44\xfa\x0b\x17\x3c\x99\x64\xe7\xd5\xd0\xb5\xce\x87\xce\x7a\x79\xde\xb0\x95\x44\x9a\xb4\x9f\xdf\x3f\x5e\x32\xa3\xc7\x25\x93\x3a\xd0\xf8\xf6\x8f\xf1\x44\x52\x3e\x4d\x63\xce\xc2\x7b\x63\x89\x65\x67\x43\xd8\x03\xe7\x04\x3b\x30\xcd\xbe\x61\xde\xa2\x53\x4f\x3f\xda\x11\x15\x75\x93\x3c\x70\x6e\x84\x22\xe4\x4a\xcb\x09\x21\xfa\xb1\xfa\xb8\x06\x16\x1b\xfe\x89\x96\xab\x2d\x99\xff\x69\x9e\x9d\x08\x09\xa1\x9a\xcb\x49\x89\xba\xec\xb4\x0d\xaf\x42\x20\xd0\x88\xf3\xce\x67\x31\x19\xdc\x9f\x9c\xf7\x44\xe8\xb8\x39\xc6\xae\x72\xa5\x66\xaf\x01\x69\xe4\xe0\x90\xe4\x15\x8a\x18\x63\xb9\xdc\xa6\x8c\x2c\xb5\x73\x09\xfe\x7c\xf0\x2c\x26\xb2\xca\xc3\x84\xeb\xd1\xbd\x29\xad\xef\x0d\xe3\xf3\x6c\xa8\xca\x1f\x91\x63\x52\x16\x66\x08\x02\x64\x86\x87\x5a\x0b\x3c\xb9\xa1\x6d\xb4\x54\x72\xcc\xb1\x04\x57\x37\x58\xe7\xc7\x8f\x71\xaa\xeb\x3c\x02\x0a\x88\x3e\x04\x2c\x08\x0f\x6a\xbd\xea\xd3\x30\x03\x3e\x5f\x98\x8b\xd5\x5c\x98\xaf\x09\x19\xed\xa5\x3d\x24\xea\x54\x64\x1f\x90\xf2\x3f\x73\x7a\x33\x23\x3d\xac\xf8\xd5\x3d\x70\x37\x56\x34\x92\xa4\x94\xad\x46\x37\xec\x98\x6a\x5b\x72\xe0\xbd\x4f\x48\xb9\x6f\x58\x7c\x75\x50\x17\xb5\xa9\x4b\xbd\x6c\xa1\xe1\x11\x82\x4e\x11\x0a\x21\xdb\x7e\xc6\x43\xfc\xa5\x43\xf6\xa5\x93\x13\xba\xcb\x7f\xbe\xf2\x49\xa0\x08\xce\x3d\xdf\x12\xf5\x6f\x12\x93\xe0\x4a\xea\x12\xe9\x91\x1d\x6b\x76\x60\xd1\xa7\x7a\x08\xee\x53\x76\xfe\x33\x4d\x00\xa2\xb5\xaf\x16\x4e\xb1\x9a\x32\xfb\xd5\x90\x8a\x53\x67\x90\x0d\x98\x9a\x8f\xc6\x70\x2d\xd3\x63\xb6\x52\x76\x84\xe1\x4f\x9c\x8e\xc9\xe8\x34\x36\x3b\x59\xa8\x47\x6e\x19\x1d\xc9\xc9\x7e\xfe\xdc\x2e\x0e\x6a\x55\xe3\x1f\x51\xce\x1c\x08\xf9\x87\x3b\xa2\xf0\xab\x16\xaf\x2c\xca\xd1\xff\x2f\xa6\x81\x47\xe5\x58\xa5\xc3\xe3\x14\xfd\xc9\x26\x89\xbf\x56\x0c\x28\xd1\xa3\x58\xe8\xd2\x4a\x87\xf8\xb4\x71\x6a\x9a\x15\x1f\x93\x99\xf0\x38\xe9\xce\xf4\x93\x1f\x60\x90\x2a\xd0\x7c\x50\x78\x20\x3c\xa7\xc1\xd3\x9e\x8f\x57\x52\x2c\xfd\xfe\x9e\xe9\xc6\x26\x59\x73\x50\x3d\xaa\xad\xe4\x33\xbc\xff\x59\x63\x66\x98\xf0\x73\x5f\xff\x50\xdd\x8b\x60\xf6\x78\x90\x50\xf6\x91\x20\x99\x41\x9b\xda\x4e\x9d\x3d\xd1\xe6\x62\x42\xf6\xee\xb0\xda\xd4\x88\x80\x6e\x93\x04\xaa\xbf\xec\x25\x28\x10\x49\xa3\xba\x9e\x2f\xd1\xe7\x26\x91\x30\x5b\xbd\x66\x66\x1c\x9b\x69\x68\x1a\xdb\xb2\xf0\xaa\x9b\x54\xb9\x07\xcf\x5c\xca\x26\x22\xed\x7d\xa5\x04\x2b\x5e\x15\xba\x02\x31\xa8\x1d\x91\xa2\x7a\xa4\x16\xc8\xc2\x13\xe7\x11\x76\xfd\x13\xcd\x7f\xad\xff\x04\x2f\x3b\x99\xb4\x5b\x3d\x66\x59\x9e\xa3\xf1\x2f\x63\xbd\x20\x8c\x64\x59\x57\x75\xde\xe7\xb0\xba\x2d\x8a\x4a\xff\x19\xd1\xa5\x45\x59\xdb\x35\x0a\x87\x76\x4a\x25\x0b\x0a\xe2\x72\x42\xf6\xb0\xa8\x27\xa9\x75\x2f\xc8\x9a\xe0\x2a\xc6\x2c\x9d\xfb\x86\xbc\x7d\xeb\x8b\x45\xe2\x87\x41\x95\x52\x42\x59\xcb\x23\x8d\xff\xe9\xc6\x5b\x66\xdd\xf6\x40\xea\xf0\xc0\x42\x40\x64\x3b\x9f\x15\x06\x69\xca\xa3\x71\xcd\x05\x0f\xae\xc3\xde\x90\xd5\x71\x0b\xb1\x68\x4e\x86\x82\xd2\xb3\x25\x96\xbc\x7b\x0b\x35\xe0\x68\x1c\x53\xdd\xed\xf7\x7d\x37\xb3\xf0\xe8\x84\xf9\x38\xae\x69\x54\xc0\xd8\x9e\x06\xbb\x57\xc9\x1d\x01\x9f\xa2\x65\x4e\xeb\x2f\x0b\x39\x03\x34\x52\x35\xc6\x47\xed\x98\xa6\xe6\x8f\x1b\x0c\xf9\x72\xdc\xf0\x7d\x04\x3d\x2a\xb9\xfd\x7c\x22\xb3\xbb\xce\x88\x4e\x7f\xce\xbb\x45\x08\xf0\x78\xc6\x95\x0d\x55\xb8\xdd\x39\x0f\x08\xc8\x9f\x41\x63\x60\x59\xd9\x7d\x83\x15\x54\xbe\xf5\x67\x29\xce\xee\x21\xa1\x06\xa8\xa3\x69\x27\x23\xa7\x6c\x46\xe4\xc1\x5b\x67\x85\x27\xea\x0a\x0d\xbb\x63\xb1\xf7\x4a\x15\x54\x0d\x44\x4c\xba\xf7\x26\x1c\xfd\x82\xb1\x32\x6c\xe3\x89\x43\xf5\x37\x25\xbe\x6f\xd2\x50\x3d\xb7\x04\x33\x97\xd4\xcf\x46\xfb\x92\x29\xff\xc4\xf9\x15\xd2\xed\xb2\x06\xd9\xfc\xbd\xd5\xcc\xc5\xf5\x9c\x59\x06\xeb\xf7\xec\xe0\x2a\x53\xf4\x57\x64\xfc\x10\x89\x4d\xba\x47\xca\x4e\x01\x87\x05\x56\xb1\x7b\x27\xe6\x9b\xbf\xd0\xd1\x69\x1d\x0a\xd8\x21\x0c\x0d\x19\x9c\xc7\xd6\x9e\x2f\x73\xa5\xac\x0c\xb2\x14\x01\x45\x2c\x7b\x52\x60\xc5\x8e\xb3\xdd\x98\xf5\x9a\x07\x0f\xf3\xda\x96\x36\x74\xa5\x91\xbd\x31\x33\x7e\x65\xa0\x9e\x75\x34\x0c\x63\x38\x28\x5d\x27\xec\x2f\xd5\x1e\x60\x7c\x0d\xca\xf3\xb6\x65\xde\x28\xd7\x36\x71\xa6\xb6\x75\x7c\x14\xe2\xff\x53\xd9\xdc\x57\x00\x38\x71\xc9\xd2\x26\x41\x5e\x48\x75\x33\xb1\xcc\x6c\x36\x4d\x1a\xd6\x8d\x81\xe8\x8d\xf8\xf8\xa9\x5c\xea\x61\xcc\x70\x4e\x71\x19\x22\x43\x7f\x48\x65\xd6\x87\xb1\xb2\xb2\xed\x8c\x4e\xd0\xed\x1c\xe8\x70\x07\xa4\x13\xfd\x83\x97\x27\x25\x38\x25\x35\x2e\xb1\x30\x45\x70\x61\x14\x02\xf0\xb0\x2c\xaa\x81\x14\xf3\xa8\xbc\x8e\x83\x41\x3e\x5e\x4c\xb3\x8d\xd7\x25\x27\x7d\x0a\xd3\xdf\xd5\x34\xbb\x67\xd6\x05\x75\x6b\x04\x34\xf4\x02\xed\xdc\x36\xee\x4f\xe0\x27\x09\x94\x64\xed\xe3\xe4\xf3\x29\x5b\x93\x64\x17\x7e\xb8\x93\x51\x74\x7c\x10\x2a\xdc\x2c\x44\xe0\x78\x8a\xe5\x2b\x64\x11\x26\x56\x29\x70\x8f\x53\x19\x22\x74\x65\x25\xef\xa8\x77\xe6\x47\xf4\x5a\xa4\xff\xbc\x3d\xf5\x79\x16\x45\xe1\xa1\x14\xb4\xac\xd0\x01\xcc\x80\xaa\xa5\x97\xf8\x2b\x20\x3e\xaf\x5e\xd2\xb8\xe2\xdf\x1a\x1d\xa5\xa1\xba\x0c\x1e\xcc\x02\x6f\x52\x8a\xb0\x0b\x06\xaa\x55\x05\x31\xa9\xe9\x9c\xdf\xc4\x1e\xe5\x29\xbc\x7f\xa5\x55\x34\x9a\x3e\xda\xb0\x07\x1a\xeb\xea\x98\x66\x3e\x05\xdc\xea\xc3\x80\x3f\xee\xd5\x7b\x1e\x0e\xcf\x14\xd9\x4b\x4e\x29\x16\xed\xf5\xb9\xe2\x03\xd9\xae\x93\xb3\x5d\x31\xfc\x57\x04\x55\x78\x51\x96\x32\xa7\x7a\x8d\x37\x5a\x8f\x2e\x8c\x1f\x54\x88\x60\x24\x72\x0e\xac\x9b\x88\xba\xeb\x93\xeb\xb3\x31\x69\xc5\xaf\x6b\x99\x25\xaa\x00\x23\xe3\x25\xd3\xab\xcd\xcf\xe7\xa8\x3b\xd7\x48\x6e\x68\x97\x83\xb0\x56\x39\x3c\x4d\xf4\x9b\x91\x34\x37\x87\x0f\xa9\x31\x5e\xe3\x98\x06\xf1\x1d\x0f\x67\xd0\x59\xba\xce\x2e\x4a\x23\x79\x41\x93\xec\x99\xbc\x45\x73\xb1\x81\x79\xd5\xc4\xbd\xcd\x63\x9a\xee\xeb\xce\xa7\x97\x58\x53\x09\xb3\x95\xbd\x32\x70\x24\xa1\x97\x05\x77\x9e\x60\xf5\xc4\xda\x6d\xdd\x5b\xab\x89\x36\xb0\x4c\x41\x51\x8e\xc0\x5c\xf0\xb6\xe0\x71\x83\xb6\xaa\xc8\xf6\xcd\x48\xdb\x92\x8e\xdf\x14\x77\xcb\x76\x38\xf7\x82\x4a\x98\x0d\x92\x36\x8c\x38\x42\xae\x7a\x82\x8e\x09\xca\xf8\x59\x2a\x0e\x8f\xf7\xf6\x22\xf8\xf8\x8b\xf9\xf3\x9c\xa7\x27\x48\x2b\x98\x03\xc7\xf2\x54\x0a\xdd\xa0\x4f\xed\x6e\xe3\x58\xbf\x40\xb5\xa1\xd2\xb6\x4e\x1c\xda\x0b\xcb\xa3\x6a\xd7\x1e\x5c\xf0\x75\xdb\x82\xf4\xb2\xee\xb1\x1c\xff\x5b\x1f\x91\x2a\xba\xdb\x5a\x0f\x42\x4f\x95\x77\xc7\x53\x97\x32\x8d\xcf\x40\x76\xdb\xd2\xcf\x8a\xf7\xfa\x74\x0a\x1e\xfa\x7f\x0b\xff\x92\x03\x0f\xe7\xc7\x30\x7b\x33\xd0\x2b\xcb\xa9\x02\x84\x03\xaa\x33\xed\xa6\x09\x89\xbb\x55\xbc\x40\xfd\xec\x7e\xfa\x2b\x81\x01\x87\x32\xbf\x2f\x91\x24\xa8\xe4\x65\xe8\x2b\x50\x09\x0e\x59\xb6\x64\x5c\x0b\x82\xfa\x98\xfd\xa5\x06\x09\xb7\xe4\x13\x62\x1f\xfd\x62\xd9\x2d\x6f\xad\xf4\xab\x11\x0d\x48\x1a\x87\x63\x83\x0d\xb6\xe4\xd0\x77\xba\xf0\x35\xa9\x2e\xa1\x2f\x02\xdf\x16\x90\xb0\x8e\xae\xc3\x26\x3e\x2e\x01\xa9\x7a\x23\x31\xaf\x1f\x99\xd4\xe9\x60\x04\xf0\xea\x17\xa1\xb9\xdf\x3b\x47\x70\xe4\x5e\xb0\xef\x67\xf3\x93\x86\xd0\xfc\x69\xed\x6a\x61\xf3\xd2\xae\x6e\xd5\x82\x6f\x02\xbe\x05\xcc\x51\xca\xe2\x62\x34\xe3\x54\x49\x0b\xc0\xf0\x97\x20\x11\x21\x52\xd5\x17\x2a\xc6\xce\xa7\x71\x15\x18\x65\x15\x61\x6d\xfd\x16\x51\x87\x04\x75\xce\x2d\x4d\x2d\xfc\x6b\x2e\xe4\x71\xd9\x1f\x94\x8e\x58\x8a\x8a\x0c\x3c\x54\xf3\x97\x2b\x0a\xd2\xc2\x71\xf2\xc4\x69\x7e\x0d\x34\xec\x84\x96\x1a\x5c\x9b\x79\x81\xeb\x31\x21\xcd\xdb\x67\x72\x75\x12\xea\x41\xa7\xe4\x5a\x66\x98\x63\xf4\xb6\xc4\x90\xe6\xf8\xd1\xd4\x25\x87\x31\x36\x8b\x7b\xff\x67\x33\x5a\x4f\xea\x1b\x72\xcb\xfb\xaa\x35\xa9\xd2\xdd\xd6\xdd\x5f\x25\x1d\x38\xa4\xca\xf3\xe5\xfd\x7e\xa2\x23\xb5\x7c\xb5\x09\x2f\x59\xaf\x64\x96\x90\xa5\x69\x80\x74\xa2\x69\xb9\x6b\x24\x50\x60\x1b\x40\x61\xe2\xc6\x4a\x7c\x0f\x40\x4b\xa3\xee\x07\x3a\xcd\x8f\x98\xa5\x39\xd8\x29\x91\xca\xac\xd6\xf0\x54\x32\xce\xd2\x08\x1c\x01\x00\x3b\x87\xc1\x23\x0a\x26\xa7\x69\x11\x9e\x93\xd8\xf9\xb5\xb5\x30\x71\x07\xd2\x49\x1e\xc1\xc9\x82\x2a\x8f\x26\x51\x24\x3d\x4b\x17\x68\xaf\xba\x29\xe1\x32\x12\x3f\xd3\x9d\x48\x44\x44\xd4\x0c\x43\x2a\xc4\x96\xe4\x70\xa1\x88\x76\x1f\xb9\x52\xc7\x48\x73\x18\x49\xcc\xc2\x1d\xf0\x05\x7f\x9f\x99\x7a\xe2\x57\xa0\x34\x65\x07\x08\xaf\x23\xdb\xb9\x9b\x3c\x1c\x02\x11\x9e\x6c\x84\x02\x84\x84\xba\xcd\x66\xc6\x86\x98\xa3\x9c\x93\x65\x3e\x79\xb3\x54\x00\x30\x14\x95\x6f\xa5\x90\xb8\x0a\x8c\x5f\xbd\x51\x9d\x02\x33\x5b\x10\x39\x15\x58\x68\xc5\x67\xe6\xb7\xc5\x8b\xa3\xe3\x6d\x5b\x61\x83\xcd\xe2\x7a\x4a\xef\x91\xea\x96\x4d\x8c\xe7\xa5\x76\x0c\x0f\xcb\x46\x98\x98\x51\xa0\x69\xf7\x5d\x83\x4f\x3a\x1a\xe6\x9f\xdb\x12\x6f\x38\x53\x9a\xb0\xf1\x2a\xff\x33\x17\x28\x2d\xad\x74\xf7\xf2\x2c\x4d\xec\x91\x42\xbb\xf6\x93\xad\xfd\x9c\x26\xe7\xb4\x7e\xaf\x12\x8b\x1c\xfc\x89\x33\x9b\x9f\x50\x58\x71\xd2\x57\xc0\xd4\xd2\xc3\x87\x83\xf2\x80\x1b\x44\x02\x68\x54\x58\x6b\x87\x23\xac\x80\xad\x6a\x1c\xbe\x21\x59\xbf\x5f\xd5\xc2\x6a\x41\x9e\x6c\x5b\x5e\xd9\x1b\x15\xaa\xf9\x1b\xc2\xa7\x4b\xfa\x73\x2d\x4e\xdd\x07\xae\x05\x10\x22\x4e\xf2\x9e\x3e\xf6\xd2\x34\xba\xa1\x17\xdc\xa4\xe9\xa2\xd7\x7a\x91\x8d\x9f\xdb\x02\xc6\x6f\xa8\x8a\x52\xd3\x26\xc5\x7d\xd6\x98\x40\xde\xd1\xc6\x97\xfb\x6a\x23\xa6\x57\x9e\xfb\x38\x69\x4e\xad\xbe\x2f\xe2\x15\xa8\x91\x2e\x04\xcc\xb4\xe6\x45\xd5\xf1\x77\x3b\x70\x11\x9b\x16\x8c\xe7\xb3\x01\x45\xda\xad\xea\x4a\xd8\x7f\x69\x14\x11\x62\xc9\xdd\x4b\x05\xf1\xb4\xfd\x34\x91\x32\x47\xe0\x0c\x94\xc7\x2f\x12\xc7\xce\x43\x85\xd8\x4d\x9c\xb5\x05\x21\xff\xac\x10\x5f\x70\xf3\x52\xfc\x43\x1b\x02\x8c\x6a\x26\xef\x96\x09\x11\xc1\x56\x30\xc8\xd9\x8a\x74", 2972);
*(uint64_t*)0x20001488 = 0xec4;
*(uint64_t*)0x200014d8 = 1;
*(uint64_t*)0x200014e0 = 0;
*(uint64_t*)0x200014e8 = 0;
*(uint32_t*)0x200014f0 = 0;
	syscall(__NR_sendmsg, r[0], 0x200014c0ul, 0ul);
	return 0;
}