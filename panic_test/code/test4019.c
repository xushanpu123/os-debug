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
	res = syscall(__NR_socket, 0x10ul, 3ul, 9);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000100 = 0x20000000;
*(uint16_t*)0x20000000 = 0x10;
*(uint16_t*)0x20000002 = 0;
*(uint32_t*)0x20000004 = 0;
*(uint32_t*)0x20000008 = 1;
*(uint32_t*)0x20000108 = 0xc;
*(uint64_t*)0x20000110 = 0x200000c0;
*(uint64_t*)0x200000c0 = 0x200001c0;
memcpy((void*)0x200001c0, "\x54\x00\x00\x22\xba\xe3\xad\xba\x39\x2a\xbc\xbf\xdf\x26\x92\xc2\xd3\x00\x48\x02\x93\x59\x74\x03\x7b\xd9\x8d\x1c\xa5\x71\xdf\x20\x26\x8e\xbd\xdd\xbc\x78\x2b\x45\x40\xdd\xa5\xf8", 44);
*(uint16_t*)0x200001ec = 0;
memcpy((void*)0x200001ee, "\x02\x01\x2c\xbd\x70\x00\xfe\xdb\xdf\x25\x4d\x00\x00\x00\x08\x00\x01\x00\x70\x63\x69\x00\x11\x00\x02\x00\x30\x30\x30\x30\x3a\x30\x30\x3a\x31\x30\x2e\x30\x00\x00\x00\x00\x08\x00\x01\x00\x70\x63\x69\x00\x11\x00\x02\x00\x30\x30\x00\x00\x00\x00\x00\x00\x00\x00\x2e\x30\x00\x00\x00\x00\x08\x00\x03\x00\x01\x00\x00\x00", 78);
*(uint64_t*)0x200000c8 = 0x54;
*(uint64_t*)0x20000118 = 1;
*(uint64_t*)0x20000120 = 0;
*(uint64_t*)0x20000128 = 0;
*(uint32_t*)0x20000130 = 0x40008090;
	syscall(__NR_sendmsg, -1, 0x20000100ul, 0ul);
*(uint64_t*)0x20000300 = 0x20000280;
*(uint16_t*)0x20000280 = 0x10;
*(uint16_t*)0x20000282 = 0;
*(uint32_t*)0x20000284 = 0;
*(uint32_t*)0x20000288 = 8;
*(uint32_t*)0x20000308 = 0xc;
*(uint64_t*)0x20000310 = 0x200002c0;
*(uint64_t*)0x200002c0 = 0x20001700;
*(uint32_t*)0x20001700 = 0x1138;
*(uint8_t*)0x20001704 = 8;
*(uint8_t*)0x20001705 = 8;
*(uint16_t*)0x20001706 = 0x101;
*(uint32_t*)0x20001708 = 0x70bd2b;
*(uint32_t*)0x2000170c = 0x25dfdbfe;
*(uint8_t*)0x20001710 = 0;
*(uint8_t*)0x20001711 = 0;
*(uint16_t*)0x20001712 = htobe16(9);
*(uint16_t*)0x20001714 = 8;
STORE_BY_BITMASK(uint16_t, , 0x20001716, 0x2c, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x20001717, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x20001717, 0, 7, 1);
*(uint32_t*)0x20001718 = r[0];
memcpy((void*)0x2000171c, "\x00\x44\xa5\xe5\xfc\xa6\xf0\x6a\xfd\xcc\x26\x3c\x47\xf9\xe4\x24\x4f\xe2\x1c\xaa\x13\x1d\xc2\x30\xe6\xf3\xa3\xfd\x8d\xb5\xd7\xb1\x61\x09\xca\x6f\xb9\xb4\xdc\xbd\x23\xe9\x4c\xff\x8e\xd9\x10\xbf\xb9\xa2\xd4\xc3\x7e\x4b\x28\xb9\x9d\x6b\x8d\x81\x47\xae\x22\xed\x80\x9a\x5b\x75\x0e\x95\x22\x22\xdc\x4a\xc5\x5d\x95\x76\xaa\x1c\xed\xd8\x31\x0f\x50\xa5\xb8\x76\xb8\x29\x0d\x97\x03\xe2\xfc\x61\x72\xf0\xce\xe8\x44\xe7\x46\x3a\x65\x58\xb3\x20\x76\xb8\xd1\xb0\x73\xcb\x1d\xac\xbe\xef\x9a\xc2\x0e\xb1\xb2\xfc\xcd\xc3\x65", 127);
*(uint16_t*)0x2000179b = 4;
STORE_BY_BITMASK(uint16_t, , 0x2000179d, 0x8d, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x2000179e, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x2000179e, 0, 7, 1);
memcpy((void*)0x2000179f, "\xff\x9a\x7b\x00\xa0\x34\x70\x15\x0d\x15\x2a\xeb\x1d\xd6\x15\xa9\x1d\xa4\x80\xe8\x9c\xb8\xa3\x12\x0c\x61\x0e\x86\x0f\x27\x32\x4f\x83\x1a\xcf\xda\x26\xef\x8c\xfb\x1f\x22\xbc\x50\x49\x2a\x57\xa5\x92\x60\x0b\x89\x59\x48\x90\x6d\x5c\x64\x8e\x6b\x0e\xa1\xc6\xdd\x0d\x37\x17\xf1\x4d\x99\x0e\x2c\xf0\xdf\x58\x75\x20\xf0\x6d\x83\x53\xf0\xab\x1b\xab\xf9\x0a\x5c\x40\xb2\xd8\x5f\x73\x63\xb2\x47\x3c\xb4\x0b\xed\xe2\x9a\xa3\x3f\xd4\x9d\xd1\x5a\x20\x17\x71\x2b\xcc\x35\x4d\xea\xbb\xd2\x12\x9f\xf1\xff\x68\xcb\x72\xcb\x45\xa0\x6d\x4a\xc7\xe6\xce\x11\x9a\x84\xed\x2e\xf9\xe5\xbc\x89\xb3\xc8\xd2\x09\x1b\x46\x67\xd2\xfc\xe9\xc3\xa9\xc7\xa3\x46\x8f\x49\x31\x25\x65\x84\xa3\xfd\xd6\x59\x4e\x9c\x44\x0f\xdb\xbc\x6b\x95\x89\xeb\xff\xe3\x3e\x73\x70\x29\x30\xde\x47\xeb\xe6\xbf\xf1\x87\x31\x45\x56\x77\x00\x6e\x40\xfb\xd1\x58\xf9\xc1\x7c\x3c\x56\xa1\xea\xe0\xef\x77\x60\x89\xa6\x92\xf3\xdd\x10\x6c\xa1\x4c\xb7\x0d\xfa\xf7\x19\x79\x01\xc0\xc7\x21\x0e\x5b\x96\x6f\xfc\x46\xf5\x86\x2f\xad\xaa\x3c\xe6\x81\x96\xaa\x45\x54\x8a\x49\x8e\x57\xc0\xdb\x9a\x51\x8b\x29\x2b\x2a\x18\xb6\x99\xe1\x99\xa3\x64\xd1\x9f\x71\x4a\x56\x80\x3f\x5c\xd5\xe0\xa6\x52\x72\x7b\xa2\x1f\x8f\x0e\x3a\xb1\x7b\x07\x73\x2d\x1e\x8a\xf0\xb1\xb6\xd9\xdc\xee\x77\x43\xbd\xcc\xbf\x2e\x58\x40\x46\x05\xf6\x72\x43\x99\x4a\x37\xb1\x86\x7c\x9c\x43\x2d\xd7\xe3\xe3\x3e\x2a\xba\xd4\x38\x02\x33\x3b\x89\xb8\x35\xe0\x15\xe4\x35\xe0\x74\x6c\x59\xf4\xbc\x44\x15\x2b\xbe\x6b\xbe\xa4\x17\x4a\x1f\xbb\x3a\xe8\xe6\x3b\x7c\xc6\x04\x7b\x36\x81\x00\x8b\xe4\x46\x2c\xef\x7f\x20\xfa\x63\x49\x9c\x51\x92\xc7\x05\x6d\x65\x47\xb6\x99\xd7\xab\x95\xc3\x17\xf7\x4f\xfc\x03\xe1\xcb\x6d\x68\x9a\x1c\x86\xc9\x36\x0a\x84\xc0\x6e\xb5\xa7\xee\xd1\x89\xdd\x86\xdf\x14\x9a\x5e\x9e\x8e\xa1\xd9\x7d\xf8\x05\xbe\xba\x4e\x30\xf5\x66\xee\xf7\xcd\x3e\x2b\xab\xb6\x84\x03\xa6\xc2\x04\x43\x4a\x77\xfd\x59\x08\x4a\x85\xc6\x0f\xcd\x65\x11\x46\x62\xd9\x71\x87\x75\xeb\x3c\x74\xa6\x5f\xaa\xf8\x9d\x7e\x36\x08\x76\x20\x7b\xf0\xcc\xfc\x9a\x8b\x7e\x4c\xd7\x79\xe7\x80\x0d\xf9\x56\x24\x69\x6f\x04\xc1\x88\x33\xb6\x9c\x84\x45\xf7\xa7\x95\xfd\xd6\x57\xb4\x40\xd2\x82\x6d\xbb\x32\xa9\x50\x47\xb1\xe1\x0c\x90\x3c\x7a\xae\x5c\x34\xad\x01\x37\xc0\x4d\x3a\x93\xe4\xa7\xf7\x39\xda\x7c\xbc\x5e\x23\x88\x8f\x90\x02\x8e\x57\x5f\x7c\x80\x13\xa5\x02\x8b\x70\xad\xa2\x49\xef\xb7\x14\x65\xc5\x56\x0a\x69\xfa\x52\xa6\x49\xf3\x30\x98\xdd\xdb\x16\x30\xe0\xc8\x05\x24\xf6\x95\x18\xfa\x16\xd2\x81\xe3\x90\x2b\x1b\x88\xde\xde\x3e\x6c\x6b\x46\x3a\xcb\x30\x96\xb8\xd0\x5b\x16\x85\x69\x50\x8a\x79\x6e\x1f\xa7\x62\xec\x41\x67\x89\x63\x25\x00\xe6\xd8\x5f\x4c\xf5\x47\x4a\x03\xd6\x2c\xae\x85\x04\x1b\x5a\xbf\x6d\x1c\x7b\x7b\x3f\x1c\x20\x99\xe6\x7c\xea\x6c\x98\xce\x70\xd0\x0f\xe2\x68\x18\xf2\x27\xa6\x62\x5d\x9d\xc9\xbe\xd8\xa5\x7f\x8b\x6a\x20\xd8\x63\xfa\x64\x18\xe3\xd5\x98\x5c\x54\xdd\xce\x31\xfb\xc0\x94\x68\xfa\xce\x53\xb2\xdc\x6b\x68\x70\x02\x8a\xe4\x01\x54\xd1\x91\x70\x7e\xff\x49\x87\xde\x23\xbe\x34\x30\x10\x7f\xc5\xe7\x14\xda\x5c\x24\xb7\x0e\x36\x30\x84\x11\xa7\x79\xde\xd1\x3c\xd1\x0b\x86\x41\xe3\x98\x27\x96\x63\xf2\x91\x29\xe9\x4e\xf9\xe8\x43\x02\x5d\x7a\x35\x9a\x23\xae\x24\x53\x89\x9f\x55\x8f\xd4\x89\x65\x85\x09\x10\xea\x20\x89\x07\x83\x52\x69\x6c\xe0\x9f\x3f\xb5\xc1\xe0\x2c\x5b\xd9\x2f\x8f\x9c\xc8\xcb\x82\xc4\xab\xf3\xb3\xac\xad\x6f\x77\xbc\x1e\x93\x8d\xa5\x24\x33\x8f\x7c\x66\x9c\x4e\x9b\xe9\x19\x36\x94\x82\x34\x6f\xe8\x21\x60\x5d\x0f\x85\x68\xc6\x1c\x4b\xaf\x7e\x36\x74\x20\xec\x7a\x66\x41\x48\x2d\x78\xa0\xda\xd5\xc3\x5c\xad\xda\x26\x1d\x8f\x6d\x84\xec\xd8\xd6\xb1\x24\x0d\x0c\xbb\x55\x33\x3f\x78\xc0\xd8\x0f\xcf\x18\xd9\x3c\x7b\xed\x38\x10\xb7\xec\x66\x10\xa3\xfc\xf5\x10\x3e\x36\x70\x27\xf3\xe2\x90\xd6\x52\x1e\x71\xc8\x11\x03\xce\x24\x39\x7a\x19\xe9\x7b\x45\x33\x73\x9b\x05\x73\x12\xee\xbf\xd9\x67\x57\x4a\x6c\xf8\x87\xaf\xc5\xa6\x53\xb4\x4e\x0c\x22\xed\x2a\x29\xda\x9e\xe6\x56\xff\x9e\xee\x8a\xb5\x6b\xde\x8c\x31\x57\xb7\xa9\x2e\x0f\x93\x04\x1a\xf8\xf4\x19\x51\xb7\xfa\x7d\x4f\x36\x4b\x1a\xb6\x58\xa2\xea\x71\x8d\x6f\x2a\x2e\x44\x50\xb1\x6b\xe1\x49\xe5\xd9\x71\xeb\xc4\xa2\x95\x57\x35\x5f\xbf\xbf\x70\x20\x3c\xaf\x5d\x32\x34\x65\xdd\x15\xe2\x78\xee\xc3\x9b\x41\x90\xc5\xa4\x07\xdc\x3e\x52\xc4\x1b\x07\x6f\x2d\x0e\x83\xa1\xa0\xeb\x1c\x0f\x18\x1b\xb3\xe2\x0e\xd7\xcf\x4b\xf6\xc3\x80\x33\xc3\x34\xbb\xa0\xa5\x8c\xae\x46\x56\xad\xb6\x58\x9c\x98\xbd\x0c\x66\xf2\x6b\xa7\x94\xa1\xe2\x2b\xa5\xf3\x4c\x21\xde\xef\x20\x53\xcf\x22\xb5\xbc\x11\xc3\xad\x9a\x54\x0b\x6c\x33\x99\xe9\x26\x67\x65\x0d\x0e\x69\xb5\x7c\xe2\x77\x84\xc6\x7f\x8a\x2a\x4f\x4f\x01\x4c\x03\x7b\x6b\xc8\x81\x78\x3c\x98\xfc\x6d\x4a\x23\x48\x91\xf5\x05\xfd\x22\xd7\xff\x9b\xfe\xc1\x66\x87\x32\xe5\xd1\x0e\x43\x7c\xa3\x6e\xd2\x5c\x67\xcf\x49\xaa\x94\x96\x9b\x9e\x75\xc8\xa0\xb9\x7b\xbe\x70\x20\x7c\x09\xb6\x40\xc1\xe0\xd4\x96\x2c\x7f\x8e\x66\x83\x36\x1e\x1b\x6c\xc9\x77\xdf\xc3\x0c\x19\x13\x23\x0f\x8a\xcc\xe6\x3c\x18\x13\xb5\x6e\x80\x52\x61\x3f\x7a\x6a\x40\xf1\xc1\xdc\x92\x2c\x4b\x8f\x58\x71\x64\xa6\xce\x7d\x0e\xd0\xfa\x04\x0f\x1f\xbc\x68\x06\xa0\x76\x5f\x0b\x1a\x51\xfb\x8d\x7e\x1d\xf4\x00\x2a\x16\x47\x72\x97\x81\x4e\xf0\xe3\x06\x28\xef\x8c\xe8\x2f\x98\x4a\xc0\xcb\xf1\x88\x01\xe2\xcb\x55\x5c\x57\x5c\x71\x06\x28\x45\x41\x27\xd8\x63\x48\xe3\x12\xbb\xcf\xfe\x23\xb5\xbb\x62\x04\x58\xe4\x74\xa5\x8b\x2a\xbd\xeb\xb2\xd6\xae\x18\xf8\xd5\xa1\x29\xce\x18\x0a\x9b\xba\x70\xc1\xf5\x86\x1c\x53\x10\x62\xb3\x4d\x4a\x94\x12\xa4\x42\x34\x04\x28\x83\xb0\x6c\x7a\x86\xbe\x36\x1d\x84\xad\x98\x69\x8a\xaa\x79\xde\xc4\x25\xf3\xd3\x1e\xd2\x1d\x5d\xb0\xfb\xa6\x95\xb2\xbb\xdc\x52\x75\xb6\x3f\xc3\x3d\x59\x66\x1b\xdc\xeb\x84\xe1\x9b\xa8\x31\x18\xd9\xd0\x6c\x17\xda\x56\x53\x13\x8f\xd5\x59\x11\x37\x23\x04\x73\x4b\xd3\xe2\xa8\x78\x9c\xac\x00\xe5\x29\xbd\x51\xdf\x2c\xb2\x73\xc8\x67\x80\x85\x12\x7a\xe5\x91\x7e\x7e\xbb\x39\xc1\x01\x5f\x01\x8b\x03\xd8\x26\xfa\x33\xea\x3a\x5f\xe1\xd6\x4e\xfd\xf2\xdf\x09\x9e\x69\x13\x50\x47\x48\x9b\xb2\x77\x2f\x0d\x9c\xf7\x57\x0b\x95\xd2\x0a\xc0\x0d\x3c\xad\xf4\xe9\xe6\x6b\x37\xa6\x0c\x59\xa7\x81\x3a\x5b\x59\x28\x12\x63\x87\x77\xfc\x47\xf4\x1b\x0b\xec\x24\x9f\x27\x89\x3e\xe3\x4a\x6a\x46\xe0\xb1\xf0\x76\x2f\x5f\x64\xfc\xb0\xb5\x95\x7b\x41\x45\xdd\x1d\x55\x6f\x13\x71\xf2\x27\x4a\x41\xbc\xba\xc8\x09\xcc\x82\x6e\x23\x00\x83\x34\x0b\x5d\xae\x8a\xcb\xf0\x59\x2d\x38\x4e\xe3\x07\x22\x17\x5a\xdc\x94\x4e\x49\xc6\x8d\x72\xbd\xb0\xa1\x25\xfe\xc2\xa4\x45\x17\x70\x36\x70\xa6\xfc\x42\xd3\xeb\xfa\x46\xdb\xc9\x11\xed\xef\xf3\xe0\xc8\x95\x59\xd1\x05\x8a\x78\x4d\x29\x07\xc4\x9d\xd2\xde\x7b\x8e\xe4\xc3\x0f\x23\x7e\xea\x01\xf5\x9b\x31\x1d\x1c\x15\x6c\x7c\x43\x6d\x08\x89\xc7\x5a\xd7\x10\xf9\x8a\xd1\xe9\x00\x4b\x0c\x21\x4c\x3d\x37\x5a\x56\xc2\xb9\x91\xc7\x7a\x5b\xcb\xad\x86\x74\x9f\x7e\x8c\x6f\xfe\xaa\xc0\x4c\xcb\xbc\xde\x43\xe6\x26\x4c\x16\x94\xc2\x99\x8d\xcd\xd7\xc8\x91\x21\x91\x2a\x8f\x5e\xd0\x39\x45\xbe\xf1\x8f\xb0\xbc\x87\xc0\x54\x56\xf3\x0c\x74\xd1\x33\x59\xd5\xb1\xd2\x4d\xde\xee\x7d\x13\x22\xaf\x26\x58\xe4\x92\x2e\xcc\xd4\x60\xc6\x47\xe4\x5d\x67\xa8\x5c\xec\x16\xed\xda\xcf\xd2\x72\xea\x02\x79\x7b\x10\x18\x63\x1f\x8c\x0d\x0e\xa3\xbd\x7a\x86\xd0\x3c\x7a\xdc\x71\x35\xc9\xe3\x59\x43\x7f\xfc\xc2\xe0\x5a\xf8\x35\x96\xba\x78\xea\x63\xed\x67\x54\xf3\xe8\xd1\x1d\xd4\x7e\xe8\xe0\x0e\x80\x6b\x6c\x34\xa0\x7f\xe1\x05\x67\xf5\x57\x5c\x15\xdb\x0a\x9d\xe3\xd6\x97\xa8\x11\x42\xb7\x0a\x34\x9a\x8c\x16\xe6\x96\x91\x32\x8a\x4f\x1b\x48\x75\xc2\x40\x39\x70\xab\x8f\x77\xc9\x4e\x47\x13\xd9\x36\x6f\xc0\x99\xd9\x1e\xff\xd6\x63\x7f\x1e\x33\xce\xbc\xa8\x54\x36\x2c\x9f\x77\x46\x73\xa1\xdf\x05\x4c\x41\x68\x47\x2f\xe1\xef\x1d\xf6\x0f\x07\xf1\x53\x53\x7b\x5b\x54\x51\xf6\x51\x86\x01\x76\xc5\x4e\xb0\xb5\x98\x25\x60\xb6\x57\x51\xf3\x8d\x8e\x23\x3d\xb2\xbe\x6b\x45\x6b\xd2\xaa\x6d\x92\xdf\xf7\xae\x87\xa4\x62\x4f\x64\x05\xc1\xe2\xc2\x85\x13\xad\x6b\x68\x76\x93\x53\xa0\x4e\xaf\x42\xb7\x88\x27\x29\x6e\x6c\xb5\xd3\xe8\x0f\xef\xa6\x9a\x73\x97\xaa\xa6\x67\xdb\xc2\xd1\x00\x4c\x42\x8e\x0c\xb1\x4e\x95\xee\xbe\xf2\x56\x5a\x19\x5b\x36\x65\x85\x79\x49\xc6\x2b\x46\xef\x91\x0a\xd0\x58\x67\x00\x99\xcb\xd0\x88\xd8\xef\xea\x95\x3d\xf8\x4a\xa8\xbf\xe5\xa8\xe2\x8c\x8e\x80\x82\x2c\x58\x2d\xc7\x30\x23\xe6\x02\xc0\x5b\x8a\xb2\x34\x1c\xd7\x6a\x60\xef\xb6\x1b\x5a\x27\x87\xb6\x66\x38\x2e\x51\x61\x7c\x56\x21\xab\x00\x82\xd4\x5b\x40\x89\xb4\x15\x76\xb2\xac\x64\x4c\x69\xdf\xf7\xc1\xf8\x18\x07\x69\x23\x3f\xf0\x56\xba\x6a\x26\x7f\x89\x7f\x6e\x7a\x45\x9f\xa5\xb1\x8d\x82\xcc\xf1\x73\x8f\xff\x1c\xd8\x89\x15\xf4\xa7\xc8\xc3\xda\x7f\x77\x9e\xc2\xf6\x27\xa1\x1d\x43\x7a\x95\xc9\xd4\xa2\xdb\x50\xc5\x43\x5b\xce\x52\x7a\xac\xbd\x78\x46\x88\x14\x46\xc9\x89\x7a\xae\x6e\x99\xca\x66\x8b\x03\x74\xf7\x28\x37\x5a\x47\x91\x1f\x86\x9c\x9f\xf5\x60\x10\x1d\x5a\x49\xae\x0e\x1c\x84\x27\xd6\xbf\x1a\x51\x09\x36\x82\x22\xfd\x3a\x80\x88\x7e\x8e\xee\xa6\x35\xfa\xb0\xa6\x7e\x1a\x46\x0c\xb4\x0b\xf9\x44\x67\x1e\x34\x05\xf5\x71\x2b\xe9\x7a\xbf\x9b\x76\x67\xdf\x05\x59\xff\xa8\xb2\x43\x3f\xa5\x40\x90\x41\x8f\x0b\x4c\xe2\xf9\x2f\xf8\xe4\x03\xfc\xef\xd4\x8d\x78\x79\xee\x25\x8f\x6a\x76\xfe\x40\xbc\x01\x41\xde\xbf\x2a\xce\x63\x01\x6b\x02\x5f\x5f\xe4\xe1\xb6\x0d\x76\x7e\x04\x1b\xb0\x2b\x91\xfc\xb2\x57\x0d\x8f\xc2\x56\x5b\x84\x61\x50\x53\x4a\xb5\x42\xc4\x6d\xe9\x27\x4b\x54\xa6\x8d\x4d\xdb\x4b\x3e\x0b\x9c\x14\xed\x7d\x3a\x7a\xc5\x59\xe9\x57\x8a\xfd\xae\xf9\xfc\x8b\x7f\x15\xec\x93\x6d\x45\xa7\xf5\xe8\xea\xd9\x22\xd0\xac\x14\xb8\x75\x54\x07\xb4\x15\x3b\x87\x62\x54\xa0\x2a\x77\x6f\x19\x06\x4f\xa5\x8a\x47\xd4\x3d\x84\x05\x38\x3b\x17\xd1\xcf\xdb\x75\x96\x5c\x54\x14\x71\x18\x9c\x8f\xfb\x47\x01\x8b\xf2\x1e\xa9\xe5\x98\xb8\xb1\x22\x4f\x94\x17\xfa\x54\x10\xf7\xc0\x0a\xfa\x61\xc2\x76\x57\xaa\x2e\x9a\x10\xe7\x80\xbc\x45\x31\x3f\xe2\x00\xb1\x60\x18\xa6\xe9\xc5\xb2\x69\x89\x2e\xda\x05\xff\x06\x0b\xe5\x79\x5e\x1d\x8f\xb7\x5d\x6c\x2a\x23\x80\x76\x8c\x08\x22\x5f\x11\x54\xe2\xa9\xa9\x9b\x0d\x6c\x50\x4c\xdc\x59\x51\xca\x97\xbf\x7b\xba\xf9\x2a\x1d\x65\x6f\x83\x41\xc4\x7f\xb5\x8a\x06\xa6\x8e\x2a\xf9\x1a\xcb\x9d\x53\x39\xc3\x2d\xd4\x3e\xb1\xeb\x3a\xed\xad\x52\xa7\x38\x04\xf5\xf3\xab\x86\xd4\x22\x7f\x5f\x86\x1a\x54\xd4\x4c\x83\x73\x3f\x57\x4e\xe6\x25\x13\x79\xf0\xb3\x74\x3f\x20\x0f\x24\xa1\x72\x59\x92\xd1\x4d\xb9\xf1\xa1\xb3\x29\x6d\xa5\xcb\xb7\x8b\x23\xa0\x55\x76\xb3\xa2\x54\x8e\xe0\x60\xb8\x18\xf0\x52\x48\x6a\x09\xf0\xc9\xc6\xe6\x9e\x56\x91\x74\xaf\xa1\xaf\x73\x7e\x15\xf9\x03\xaf\x34\x4d\xfa\x42\xaf\x61\x14\xe5\x20\x2c\x34\xab\x29\x8a\x49\xf0\x88\x09\x3c\xcd\xaa\xda\x52\x60\x9c\x02\x0f\x43\x21\x3e\xa8\x4a\xf6\xdb\xe3\xbb\x43\x98\xbf\xe5\x93\xee\x63\xed\x6b\xfb\x00\x48\x08\xf0\xe5\xe2\x83\x91\x7d\xfd\x69\xae\x1b\xc8\xa6\x51\x51\x08\xcd\xc4\x24\x85\x38\x57\x1b\x5c\xea\x86\xfa\x36\xa8\xca\x89\x0a\xd5\x4f\xd4\x0b\x4a\xd6\x4a\x7d\x32\x82\x62\x59\x3c\x61\x1c\x0c\xc3\xf8\x2b\x05\x6e\x24\xc4\xfc\xf6\x6e\xf2\x95\x8c\x4b\xe0\xa9\x21\x10\xbf\xf1\x2f\xd5\xa8\x79\x85\x94\x6f\x25\x86\x94\x65\xe8\xd8\x63\x2f\x5d\x0e\xfa\xac\xf0\x71\xe9\x1b\x08\x3f\x37\x9a\x69\xd6\x50\x71\x5e\xe8\xec\xc8\xeb\x9e\x4f\x78\x6c\xb5\x02\xf5\x4f\xc3\xfe\xc0\x40\xbf\x48\x85\x1f\x4d\x07\x04\xb3\x64\x06\x71\x81\x2f\x12\x67\xdc\xb3\x72\x9c\x6d\x09\x17\x77\x3e\x62\xa5\x7a\xdf\x93\x4c\x86\x13\x32\x23\x74\x18\xdf\x6f\xa3\x75\x9d\x82\x5a\x9f\xf8\x67\x2e\x0d\x00\x77\x1c\xb0\x72\xd6\x71\x7a\xa1\x97\xa3\x30\x61\xff\xc7\xcb\xfd\x5f\x6f\xbc\xf9\x36\x22\xb1\xc4\xfb\xf3\x41\xd5\x5b\x6b\x24\xcd\x3e\x09\xa0\xfc\x2e\x80\xcf\x57\xa1\x69\xb2\xa2\x0d\x05\x8b\xdf\xe6\xd3\x03\xba\xed\x92\x6c\xad\x0e\xdd\x07\xac\x24\x21\x88\xbb\x28\x4f\x39\x74\x8b\xa3\x33\xec\xe6\x8c\x8b\xce\x47\x33\x0a\x31\xac\x45\x54\xc0\xfb\xe7\xf0\xf9\x2f\xb5\x27\x4f\x11\x8c\x0f\x4d\x40\x4b\x16\xf3\x23\xb1\xba\x49\xf0\x5c\x50\x9b\x53\xa5\x27\xa6\xf1\x7b\xa4\x49\xbd\x55\xa8\x15\x82\x9d\x8f\x13\x69\xd8\x12\x02\x72\xd2\xe0\xb5\xd4\xde\x84\x33\x56\xc3\x86\x95\x55\x64\xc0\x9f\xb8\x1c\xf2\x73\x1a\x6d\x3b\x7b\x0d\x0e\x30\xc5\x38\x4c\x33\xba\x84\x5f\x4b\x5e\x4b\x0f\x1c\x0d\xfb\x64\xe7\xf8\xc7\x9b\x06\xc5\x6d\x59\xae\xb2\xc0\xac\x41\xf5\x61\x0a\xfb\x45\x2d\x78\xa1\x75\xab\x8a\xa8\x37\x73\x74\x0e\x27\xe8\x1d\x33\x22\x88\x73\xc0\xf3\x00\xe6\x1d\xfb\x95\x0f\x82\x67\x16\xc5\x6c\xa7\x6d\x2d\x5a\x51\xa7\xc9\x42\x64\x7e\x46\xe6\xb4\x16\x67\x89\x28\x19\xd8\x19\x46\x3c\xa1\x77\x73\x08\x1e\x83\x23\xdc\x03\x98\x6f\x4a\xa9\xf3\x3d\x56\xa3\xea\xa4\xe8\x91\x03\x86\xf2\x64\x03\x48\x93\x75\x9a\x5e\x4d\x53\x75\x01\x3d\x6e\x30\xf5\x5b\x91\xcd\x4d\xc6\x6e\x4b\x0c\xc1\xdf\x24\x46\x00\xdd\xb0\xdb\xbd\x16\xbe\xdf\x29\x94\x2f\x52\xa1\x7d\xba\x8b\x36\x1c\x2e\x21\xff\xd9\x6e\xa7\x96\xb9\x8c\x60\x01\x65\x32\x8a\xd5\x42\x66\xb8\x30\x82\x1d\x5e\xfa\x0a\x47\x9b\x35\x18\x03\xae\xb4\xab\xb2\x57\x8e\x58\xe5\x1e\x9f\x95\xec\xfc\xd3\x5f\x6f\xc1\x65\xc6\x9e\x7b\x1d\xcf\x0b\x9d\x02\xb4\xe0\x9e\x2e\xa0\x03\x2f\xe3\x75\xfa\x24\x53\xe0\x26\x17\x82\xf1\xfb\xb9\x1a\xa0\x1c\x53\xbc\x3c\x6a\xa2\x19\x32\xd2\xdd\x0e\xac\x88\x73\x16\x57\xf3\x0c\xea\x80\x07\x0e\x7d\x47\x4b\x8f\xd2\x23\x0f\x9b\xf1\x18\xb8\xf5\x82\x5e\x8e\x7a\x24\x58\x05\x0c\xa8\xf4\x90\xcc\x79\x69\xf3\x3a\xc1\x39\x7b\x17\x0e\x44\x6d\xd7\xdd\xaa\x1f\x98\x42\x6a\xc2\x5c\xcd\x89\x53\x93\x46\x69\xd7\xbf\x69\xb2\xb0\xf8\x90\x07\x75\x2e\x32\xaa\x1d\xd8\xb0\xf3\xf3\x82\xf6\x93\xbe\x97\x3d\x7e\x18\xa0\x5d\xef\x4c\xe4\x83\x23\x89\x64\xd3\x72\x9c\x7e\x15\xa3\xc0\xb1\x56\x14\xd3\x32\x95\xbf\x88\x9a\xe8\x0a\x07\xef\xee\xb6\x26\x0b\xe3\x2e\xa4\x17\x88\xc4\xdc\xfc\x9e\xa7\xb8\xed\xea\x46\x15\xd4\xc0\xf1\xd0\x3b\x21\x5b\x3b\x54\xba\xf2\x5d\x86\x26\x38\xf2\xc5\x79\xa9\x23\x33\xeb\xab\x54\xcb\x0d\x07\x2e\x94\x92\xe1\x2c\x2b\x4b\xb3\x41\xb6\x4c\x3f\x46\xd1\x46\x05\x47\xa1\xee\x0f\x86\xd2\x03\x75\x7e\xd3\x9c\xde\x6c\xba\x2d\xa9\xeb\xaf\xd5\x19\x45\xa1\x2d\x4a\xe0\xe8\x13\xd0\x7a\x84\x8d\x08\x0b\xbe\xb8\xe5\x8b\xda\x1f\x2f\x4c\x4a\xfb\xbe\xb9\xe4\xe6\x6b\x93\x4c\x6b\x8f\x59\xa6\xe4\x16\x8b\x9a\x6e\x5e\xa5\x66\x09\x27\x81\x1f\xa7\xce\x9d\x32\xaf\xb2\xcd\x9b\x8e\x05\x82\x34\x1c\x0e\xd1\xe1\x8c\x1e\x5b\x0a\xe6\x29\xe9\x78\x7f\x20\xde\xf6\xff\x96\x67\xb0\xc2\x50\xcb\x7e\xb0\x1d\x6c\xed\x9b\x08\x16\x93\xc3\xdc\x54\xbb\xe1\x46\xd8\xb4\xdd\x73\x58\xbd\x2f\x4b\xa7\x17\x98\xb7\x41\xd0\x17\x90\x5d\x16\xec\x7b\x83\x6c\x74\x5f\xe0\xc1\x7c\x05\x50\x10\x13\xe6\xb4\x80\xb1\x76\x9e\xd6\x31\xd6\x7d\x41\x98\x7b\xb5\x22\xcb\x71\xbd\x49\x0c\xb6\xdd\x73\x9c\x36\x89\x48\xe7\xb7\x33\x76\xb4\x30\xf1\x32\x0d\x98\x6a\x5a\xf2\xb4\xe8\xc1\xb1\x06\x2c\x20\xdd\x60\x02\x0b\xc0\x73\x22\xcf\x97\x7c\xb8\x50\x35\xee\xcf\x74\x48\x9c\x68\xe7\xb8\x25\x23\x06\x21\x84\x0a\x09\x74\x3f\x1d\x63\x78\x92\x7e\x89\x48\xce\x18\xb9\x58\x54\x7e\xc3\xc8\x7b\xe5\x5e\x6d\x43\x33\x88\xd4\xfc\x11\x3a\xf8\x57\x53\xc1\xf9\x68\x58\xd5\x5d\xd4\x45\xab\x72\x32\x68\x57\x1d\xd6\x68\x5f\xa9\x60\x4b\x84\x43\x65\x83\x8f\xf0\x86\x98\x5a\xd7\x35\x4d\xb7\x64\x20\xe7\x41\x53\xc0\xbe\x2d\x33\x30\xd1\xd2\x4d\x17\x19\x0e\xfa\x27\x66\x58\x12\x2d\xe6\xc8\x48\x50\x25\xa8\xdb\xc8\x0c\x80\x53\x31\x78\x55\x2b\x90\xd5\x59\x83\x94\xf2\x49\xb0\x2d\x3e\xce\xfb\x39\x79\x23\x9c\x61\x5a\xd4\x4e\xdd\xd4\xcc\x74\xfd\xac\x19\xed\xa8\x6f\xd2\x46\xbe\xa8\x31\x4c\x4c\xe1\x1a\xfa\x9d\x7f\xd9\x01\x46\x31\x9d\xc8\xc6\xfe\x80\x29\x62\x75\xfb\x46\x80\x27\xb6\x29\xb0\xd8\x27\x1b\x50\x08\x3d\x7b\x7b\xee\x75\x8d\x3a\xe9\xaa\xcb\x79\x56\x6f\x71\x1b\xbf\x40\x8c\xe6\xa0\xd6\x4c\x9b\x76\x62\xb3\x78\xbe\x6b\xb1\x30\x3a\x71\xbc\x1c\x18\xb8\x08\x03\xb3\x8c\xed\x20\xee\xcc\x7a\xbe\x7e\xa8\xc9\x14\xc5\x5a\xbb\xe8\xc6\x5b\x6c\xf6\x53\x25\x8e\x6d\x25\x74\x91\x9c\x13\x8f\xb2\xf7\xc1\x91\xb6\x42\xd3\xa6\x8a\xd1\x9b\xc4\x45\x3c\x8a\x30\x13\x04\x53\x96\xfa\x55\x87\x12\xdf\x0b\xf9\x36\x70\x0c\xb8\x6a\x6f\xf9\x43\x73\xbc\x25\x38\xae\x6b\xed\xc0\xb0\x33\x66\xa7\xc8\xac\x4c\xd6\x75\x57\x87\x13\x23\xdc\x85\xe4\x91\x77\x21\xe1\x95\x5e\x82\xbc\x26\x34\x95\xe6\x6d\x79\x1d\x85\x9c\xc0\x45\x64\xfd\x17\xa6\x70\x50\x69\xb1\x4f\x3a\x3a\x6a\x71\x66\xbd\x95\x9e\x21\x1f\xb3\x31\xec\x5f\x1c\x0e\xd1\x87\x69\x94\x7e\x1e\x03\x6c\xf2\x2e\x88\x6c\xd3\x01\x58\xae\x8c\x90\x04\xf3\x60\x72\x6c\x83\x11\x54\x30\x94\x1a\x88\x82\xc6\x0a\x36\x58\xbc\x21\x0d\xc4\x4b\x3f\x89\xf6\xff\x84\xd4\x42\xdb\x67\x33\x23\x34\x5d\x49\xcd\xb1\x71\xaa\xe1\xb8\xd9\xc2\xd8\x58\x44\xec\x8b\x60\xd6\x7b\x2c\x35\xf5\xeb\x75\x22\x0c\xe1\x0c\x05\xea\x82\x53\xa0\x1e\xb0\x76\xad\x70\xba\x00\x65\x0d\x21\xbc\xfc\x44\xb7\x74\xf6\xec\x54\x06\x15\x5d\xd4\x33\xa1\xf2\xd1\x4c\x99\xfd\x3e\x0e\x4d\x6e\xf3\x59\x81\x2f\xdb\xcf\xcf\x92\x71\x84\x59\x4b\x8a\x0c\x3a\x21\x9a\xa6\x94\x98\xd8\xe7\xfa\xb3\x22\x55\xd1\xb1\x1d\x46\x3c\x2e\xc5\x36\x02\x60\x63\xd1\x7b\x89\x38\xc1\xb2\x34\x6b\x66\x21\x02\xe7\xe9\x5a\x42\xda\x5a\x0e\x5a\x49\xf7\x13\xea\x36\xe7\xe7\x87\x40\xc8\xa8\xfe\x90\xf3\xc6\xd0\x9b\x4b\x65\x9b\xf9\x94\x8b\xab\xac\x0f\xe2\xea\x40\xed\x3a\xdc\xef\x71\x48\x03\x20\x28\x36\xcd\x67\x11\xd9\x43\xff\x36\x95\xbe\x2c\x8a\xfd\xc7\x54\xce", 4096);
*(uint16_t*)0x2000279f = 0x30;
STORE_BY_BITMASK(uint16_t, , 0x200027a1, 0x2c, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200027a2, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200027a2, 0, 7, 1);
memcpy((void*)0x200027a3, "\x61\xb5\xc4\xce\x7b\x29\x46\x0f\xe2\x15\xfb\x79\xcf\xf7\xa6\x3f\x39\x26\x98\xd7\xa3\x52\x2a\x8c\xe1\x9b\xc0\xa5\x2a\xbd\xa6\x2b\x7c\x7f\x86\x63\x05\xf3\xdd\x4d\x36\xbd\xc4\x47", 44);
*(uint16_t*)0x200027cf = 0x10;
STORE_BY_BITMASK(uint16_t, , 0x200027d1, 0x34, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200027d2, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200027d2, 1, 7, 1);
*(uint16_t*)0x200027d3 = 0xc;
STORE_BY_BITMASK(uint16_t, , 0x200027d5, 0x2a, 0, 14);
STORE_BY_BITMASK(uint16_t, , 0x200027d6, 0, 6, 1);
STORE_BY_BITMASK(uint16_t, , 0x200027d6, 0, 7, 1);
*(uint64_t*)0x200027d7 = 5;
memcpy((void*)0x200027df, "\xa9\xe5\x20\xc7\x1e\xcd\xb6\xb3\x24\xe4\xe2\x28\x88\xa6\xf8\x98\x1c\xfa\xaa\x19\xab\x05\xab\xb9\x93\x07\x4d\xfe\x82\x0d\x04\x84\x1c\x34\x47\x65\x17\x17\x69\x1c\xe9\x6e\xd5\x1e\x89\x39\xc6\x80\xb8\x3f\x99\x11\x28\xd5\x8c\xcd\x7a\x80\x46\x50\xc6\x8b\x12\x01\x9c\x2b\x4a\x70\x35\x5f\x98\xe3\x9c\x4c\xc8\x26\xf6\x2c\x87\xe8\xbc\x3b\xe0\x57\xa0\x09", 86);
*(uint64_t*)0x200002c8 = 0x1138;
*(uint64_t*)0x20000318 = 1;
*(uint64_t*)0x20000320 = 0;
*(uint64_t*)0x20000328 = 0;
*(uint32_t*)0x20000330 = 0x8c4;
	syscall(__NR_sendmsg, r[0], 0x20000300ul, 0x4000ul);
	return 0;
}