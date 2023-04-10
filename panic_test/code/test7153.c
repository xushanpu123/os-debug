// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE 

#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

static long syz_open_dev(volatile long a0, volatile long a1, volatile long a2)
{
	if (a0 == 0xc || a0 == 0xb) {
		char buf[128];
		sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1, (uint8_t)a2);
		return open(buf, O_RDWR, 0);
	} else {
		char buf[1024];
		char* hash;
		strncpy(buf, (char*)a0, sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
		while ((hash = strchr(buf, '#'))) {
			*hash = '0' + (char)(a1 % 10);
			a1 /= 10;
		}
		return open(buf, a2, 0);
	}
}

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x20000000, "/dev/sg#\000", 9);
	res = -1;
res = syz_open_dev(0x20000000, 0, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000340 = 0x53;
*(uint32_t*)0x20000344 = 0;
*(uint8_t*)0x20000348 = 6;
*(uint8_t*)0x20000349 = 0;
*(uint16_t*)0x2000034a = 8;
*(uint32_t*)0x2000034c = 0;
*(uint64_t*)0x20000350 = 0x20000840;
*(uint64_t*)0x20000840 = 0x200003c0;
*(uint64_t*)0x20000848 = 0;
*(uint64_t*)0x20000850 = 0x20000400;
*(uint64_t*)0x20000858 = 0x80;
*(uint64_t*)0x20000860 = 0x20000480;
*(uint64_t*)0x20000868 = 0x43;
*(uint64_t*)0x20000870 = 0x20000500;
*(uint64_t*)0x20000878 = 0xb6;
*(uint64_t*)0x20000880 = 0x200001c0;
*(uint64_t*)0x20000888 = 0x7b;
*(uint64_t*)0x20000890 = 0x20000640;
*(uint64_t*)0x20000898 = 0xc1;
*(uint64_t*)0x200008a0 = 0x20000740;
*(uint64_t*)0x200008a8 = 0x27;
*(uint64_t*)0x200008b0 = 0x20000780;
*(uint64_t*)0x200008b8 = 0x9a;
*(uint64_t*)0x20000358 = 0x20000b00;
memcpy((void*)0x20000b00, "\xaa\x52\x30\xb9\xf3\x5c\xf4\xd2\x49\xbf\x55\x0c\x9f\x19\x29\x41\xa1\x12\x56\x64\x38\x7f\xca\x52\xbe\x31\xf2\x8a\xfb\x8a\xdf\xda\x71\xc0\xc0\xe9\x02\xf9\x24\x2e\x4f\xea\x0f\x13\xa9\xba\xfd\x75\x7d\x57\x30\x8c\x43\x49\x62\x2d\x26\xbf\x71\x7f\x45\x59\x15\xfd\x35\xba\xcf\xf0\xaf\x71\x5a\xfb\xd9\x73\xf6\xe2\xbe\x69\x9f\xaa\x5b\x5f\x82\x1f\x61\xce\x40\x22\x09\x8d\xdd\x45\xda\x51\x79\x60\x91\x0f\xb7\xaa\xe6\xe2\xf7\xb8\x03\x8e\xc5\xb5\x07\x7e\x4c\xa8\x9c\x80\x86\x9e\x60\x9a\xb3\xde\xd7\xba\x69\x81\xa9\x47\xea\xc1\x1f\x51\x24\x98\xd2\x60\x3e\x73\x14\xfa\x38\x8e\x3c\x17\x5e\x6a\xd3\xb7\xdd\x52\xa1\xa8\x56\x62\x40\x98\x93\xea\x91\xf8\x12\x94\x46\xc7\xb4\x8c\x1d\x45\x94\xca\xe9\xc9\x7b\xb5\x4a\x9f\xcb\xb8\x78\x20\x49\x4c\x2a\x4a\x08\xa5\x90\x55\x35\x9d\x63\x17\xe7\x1e\xc7\xf0\x76\xa2\x9f\xe9\x8c\x12\x27\xf4\x83\x61\x74\xa0\x02\x9b\xcb\x24\x8b\xef\x37\x81\x5e\x51\x47\xa6\x96\xef\x98\xc4\xdb\x88\xe5\x3c\xed\xf8\x05\x85\x98\x9f\xca\xf1\xd9\x63\x6e\x57\x17\x7e\x2e\x31\xb0\x8d\x26\x71\xa9\x2c\x11\x0d\x01\x68\x52\x10\x98\xfb\xc8\xb1\x95\xb9\x56\xc1\xde\x06\x64\x43\x91\x9c\x30\xa2\x93\xf1\x92\xb7\xe5\x1c\x46\x9a\x24\xd0\x06\xc9\xd3\xa7\x52\x20\xf3\x85\x1d\x7f\x75\xdd\x67\x69\x28\xd7\x8b\x95\xe2\xd1\xad\x21\x42\x59\xc3\x22\x37\xe7\xbc\xfb\x45\xc8\xfa\x95\xc6\xa4\x4d\x1d\x45\xaa\x7a\x15\x30\x66\x9d\x8c\x5e\xdf\x00\x1d\xd7\x60\x10\x91\x97\xf0\xb0\xfe\xca\x0a\xc5\x40\x86\x0b\x21\x90\x59\x26\xe8\xdd\x7c\x99\x5a\xf4\x2a\xa1\x7a\xe6\xc4\x58\xde\xf1\xfb\x1a\x9b\x31\xb0\x55\xca\x15\xfa\xec\x38\x49\xe8\xa2\xdb\x8b\x68\xb7\x68\xfe\xa3\xa5\x3c\x87\x85\xbd\xd6\x5e\x7c\xfb\x44\xf7\x7c\xba\x23\x8b\x72\x70\xc3\x6f\x8c\x3a\x1e\x0a\x5e\xde\x6b\x79\x85\xdb\xf1\x5d\xb1\xe3\x1d\x9e\x2d\xbb\x82\xcd\xe8\xe1\xab\x63\x5f\x55\x38\xd6\x3c\x8b\xe8\xd6\x44\x70\x2d\x00\x32\x58\xa0\x94\x10\x1c\x88\x23\xd7\x85\x08\xe8\x64\x1f\x7c\x3c\x85\xae\x94\x49\xa6\xcb\xf9\xfd\x9b\xbb\x79\x70\xd4\xc7\x0a\x38\x0d\x52\x0e\x44\xcc\x79\x9e\x18\x33\x35\x77\xa2\x5a\x0b\x23\x34\x6e\x94\x87\x9e\x35\xe0\x31\x3f\x0f\x0e\xa8\xaa\xef\xe3\xab\xa6\xef\xbc\x04\x3c\x23\xa1\xa3\x12\x05\x2b\xbc\xfa\x53\xfd\xee\xaa\xd5\xa2\x22\x1d\x9a\xaa\xfc\x66\x8b\x74\xab\x68\xa8\x3e\xcb\xdf\x0b\x39\xce\x66\xee\xca\x74\x56\xb9\x66\x36\x41\xfd\x5c\xf5\x71\x45\xd9\xbb\x50\x39\x69\x4f\xc9\x46\xcd\xf7\xa0\xb7\xe5\x06\xb9\x12\x87\x90\x81\x1e\x5a\x23\x19\x41\x34\xd9\xf7\x27\xe6\x51\xe1\x4f\x60\x4d\x8a\xab\x73\x0e\xc2\x66\x41\x37\x82\x34\x27\x15\xb8\xe7\x02\x72\xd3\x09\xc5\x36\xbb\xe8\x41\x42\xe0\xb8\xbd\x67\xb9\x13\xcf\xcb\x77\x9c\xf9\x3f\x11\x1e\x1d\xac\xb1\x59\x62\x21\x45\x38\x82\x8a\xd0\x7c\xf6\xa4\x7a\x0b\x21\x15\x8a\xfe\xfd\xe5\x5c\x77\x37\x8d\xea\x9e\x12\x71\x65\x73\x20\xfd\x6c\x13\xc8\x06\x38\x8b\xa2\xbb\xb6\x77\xc1\x13\x39\x88\xa7\x2a\x92\x5f\x3c\xac\x78\x06\x38\x51\x62\x5b\x43\x44\x91\x07\x0d\x42\x9f\xbe\x8f\x8a\xc3\xef\xf1\x6f\x88\xa9\x3a\xa7\xb2\x36\xcd\x9b\x9f\x81\x2b\x52\x24\xb8\x36\xe6\x66\x49\x17\x9a\xd4\xcc\x73\x06\x8e\x87\xc5\xba\x30\x1a\x5c\x68\xfd\xca\x50\x13\xe4\xbe\xbb\x0c\x9d\x08\xa7\x27\x48\xab\x22\x4c\x47\xd2\x09\x90\xfc\x82\x06\xed\x55\xf4\xfc\xb4\x79\x97\xae\x2c\x1b\x88\xc7\xd9\x43\xd4\x56\xd5\x5d\x37\x0d\x28\x3f\x70\xd8\x86\x7f\xf1\x6e\x40\x6f\xca\x7d\x4b\x05\x46\x7d\x47\xf6\x50\x65\xf7\x57\xbb\xfd\xc1\xe3\x85\x53\x64\x21\x0a\x48\x28\x58\xf2\x33\x2e\x51\xc7\x62\x6b\x76\xf1\x84\x8b\xc1\x30\x34\xdd\x53\xc3\x8d\x80\x52\x3f\xd1\x2e\x2a\x51\x2b\x0a\xe4\x98\xbd\x6b\x9f\x59\xdd\x79\x6a\xe5\x8c\xb2\x3a\x97\x6f\x65\x89\x85\x4d\x58\xfb\x0d\x60\x6e\x4f\xf3\xfd\x83\xa7\xbe\x2f\xf2\xcc\x3c\x8a\xe8\xf4\xbe\x4b\x46\x03\x6f\x39\x67\xc9\xac\x7b\xf9\x27\xfd\xfe\x57\x8b\x8a\x1a\x99\x9f\x1e\xee\x19\x33\x97\x3c\x9c\x21\x8e\xc0\xcb\x4a\x1d\xc4\x18\x6c\xa2\x2a\x18\xe7\xd3\xcf\x44\x4d\x72\xbb\xf9\x2a\x24\x71\xcd\x53\x8f\xeb\x30\xb7\x10\xee\x36\x2d\xd3\xb0\x55\x64\x18\x8c\xbf\x92\x17\x88\x53\xab\x29\x38\xa6\xf4\x9d\x24\x7d\x32\x83\x27\xc8\xab\x89\x43\x21\xc1\x2b\x62\x01\x6d\x40\x39\x75\x4e\x1c\xce\xe3\x6a\xa2\x45\x6c\x57\x07\x01\xe3\x96\x8b\xb9\x74\x3a\xc7\x93\xc1\x4f\x1d\xb2\x16\x3d\x7a\x09\xfa\x8b\x4b\x5d\x24\x36\x2c\x5f\x54\xe4\xb8\xee\xdb\x86\x54\x82\x2a\x99\xd8\x26\xb1\x86\x27\x17\x9b\xd2\x23\xc4\x66\x42\xdf\xa0\xa5\x1a\x10\x77\xc9\x9c\x5b\x42\x12\x8c\x70\xc1\x9d\x15\xcf\xbc\x2c\x1a\xcd\x64\x0e\x5a\x98\x11\x6d\x97\x9b\x79\x92\x18\xf5\xd2\x65\xb0\x25\xc3\xb9\xcc\xa4\xe4\xae\x9d\x23\xb5\xfb\x5c\x9e\xfe\xc4\x39\xe8\x14\x80\x35\xaa\x01\x77\xfb\xca\x66\x7b\x9e\xac\x69\x27\xe5\xcd\x54\x69\x4b\xe7\x4a\x2b\xb5\x33\x71\x11\x3d\x39\xfa\xd6\xfa\xc7\x44\x63\x5a\x5b\x5d\x19\x9c\x0b\x89\x9f\xb7\x65\x53\x69\xb9\x87\x73\xf8\x2d\x9d\x30\x7e\x08\xf9\xef\x64\x0f\x1b\x69\x97\x9b\x0a\x08\x6a\xf4\x2e\x8d\xb1\x34\xce\xe3\x90\x20\x30\xe2\xbc\xf7\x84\xf2\x70\x9d\x65\x45\x6a\xd3\x08\x6e\xb8\x5f\x00\x8e\xdd\x54\x06\x95\x7a\xde\xd1\xad\x46\x36\xc6\xc5\x43\x59\x1c\xad\xc7\x6b\x33\xc4\x9d\x48\x8b\x72\xfc\x78\xc6\x9d\xae\x96\xf9\x47\x70\x6a\x55\xe9\x69\x3c\x67\x8a\x5f\xc9\x57\x4e\x43\x3b\xed\x6c\x19\x5e\xb2\x04\xde\x90\x02\x4f\x9e\x65\xa4\xc8\x55\x3f\xde\xd8\x13\x5b\xd0\x62\x7e\xae\xd1\xa6\x9e\x60\x61\x47\xbf\x78\x79\x1d\x8b\xe2\x93\x71\x16\xec\x72\x54\x7e\x5f\x62\x8f\x18\x8a\x5e\x77\x76\x0e\x54\x52\x95\xb0\xd9\xe8\x16\xcb\xa6\xcc\x27\x63\x2d\x7e\x15\x89\xd5\x84\x9e\xb7\xbe\x78\x7a\xf7\x15\x68\x56\x6e\x4f\x22\x3f\x63\xa9\x9b\x3a\xb9\x8d\xcb\xca\xbc\xc7\x18\x73\xd3\xe3\x6a\x5c\xae\x45\x1f\x89\xc6\x91\x7f\x77\xb7\xaf\x36\x4e\x5e\x8c\xfb\x61\xec\x75\xdf\xf3\xd4\x29\x0c\xe2\x79\xee\x37\x99\xb9\x18\xab\x9c\xcc\xe1\x10\x5d\x2c\x58\xf7\x48\x4a\x04\x5b\x62\xfd\xa5\x99\xbf\x1c\xe1\x81\xcd\x01\xfa\x14\x66\xb3\x7c\x0c\xb4\xe6\x94\x0f\x57\x0d\x07\xef\x84\xd4\x33\xe2\xdd\x0a\x0b\x4c\xf8\x69\x34\xb1\x59\xb0\x36\xce\x6a\x49\x93\x94\x88\x3a\x06\xba\xd3\xe9\x63\x80\x8a\xa2\xe3\x32\x60\x5d\x27\x5c\xde\x79\x97\x39\x5a\x82\xa5\xbc\xa4\xed\x2c\x62\x46\x33\x2a\xe5\x97\xaa\xa5\x36\x99\x09\x8b\x0b\x73\x75\x11\x72\x34\xd3\xbb\x4a\x18\x2b\xc3\x78\x00\xdb\xc9\x81\x37\x4c\xb9\x8c\xbf\xab\xa9\xf9\xc1\xef\x76\x4a\x44\x6c\xc5\xec\x13\xad\xf5\x3d\xdd\x27\x88\xae\x8e\xcf\x03\xbf\x18\xef\xb6\xe6\x94\x16\x5d\x0a\x90\x68\xaa\x9b\xee\xbd\x54\xbd\xfc\xed\x7c\x7b\xf9\xa2\x1b\x9c\xac\x9c\x72\xe9\x13\x40\x8a\x79\x2f\x93\x47\xbd\x6a\xfe\x9d\x8d\x9b\x3b\x5e\x3f\xa8\x0d\x4b\x92\x46\x28\x78\x94\xa5\x49\xbe\xaa\xb7\xae\x3c\x99\x7b\x2d\x53\xf9\x77\x51\x9c\xd4\x73\xb2\xae\x53\xb6\x22\xdf\x86\x24\x03\x3b\x37\x29\x82\xd0\x51\x90\x80\x9d\x1e\xe9\x57\x87\x71\x36\x6d\x01\x33\x70\x7b\xd4\xc6\x01\xe7\x67\xba\x5a\x50\x5a\x52\xcf\x95\x69\xc5\x73\xc8\x68\x86\x87\xad\x49\x9a\x16\x20\x33\x7d\xf1\x9b\x67\xc9\xbd\xed\x3b\x42\x45\x74\xf3\x93\x96\x84\x43\xf3\xc9\x6c\x0e\x6b\x9d\x42\x9e\x4a\xb3\xd0\x93\xab\x1d\x29\x43\x0d\xa1\xd7\x74\x1a\x21\x83\xa2\xc1\x29\x24\x71\x15\x4a\x1c\xe5\xa1\x79\x79\x84\x9d\x64\xed\x3c\x9a\x61\x7e\x73\xf0\x9b\x0e\x2d\x42\x32\xac\xef\x01\x17\x72\xe8\x27\xb9\x73\xb7\x64\x68\x0a\x5e\x9f\x57\xa9\xdf\x12\xd7\x06\xec\xcd\xa1\x71\x41\x95\xad\x2e\x7e\x56\x9b\xcb\x1b\xb7\x74\xd3\x04\x61\x05\x3a\xba\x75\xcd\x90\x30\xd5\xe7\x24\xb4\x63\x30\x66\x2e\x32\x3b\xbe\xc0\xb2\xb9\x5d\xdb\x27\x02\xbb\xdf\xdb\x5a\x60\xd5\x5d\x87\x1e\xb5\x5f\x31\x0c\xb4\x3a\xe2\x5c\xb3\x93\xe0\x48\xd1\x73\xde\x18\x09\xce\xa8\xf5\xae\x15\x6f\xf6\x2c\x0c\x1d\xfc\x7c\x59\xcf\x00\x37\x95\x7b\x7d\x49\xb9\x20\xda\x06\xce\xd3\x4b\x41\x0f\x29\x9e\xc2\x3a\xd5\x27\xad\x5a\xb8\x6e\xab\xf9\x29\x40\x70\xe9\xfe\xfa\x33\x28\xe7\x1e\x39\x9b\x62\xd3\x7b\x96\x35\x64\xbd\xb6\x32\x25\xb7\x8d\xe3\xb8\x71\x7e\xec\xc8\xcc\x91\x77\x07\x5a\xe3\xac\x61\xe2\x1c\xcc\xba\xfd\x26\xd1\x97\xb5\xc0\xac\xe9\x99\x60\xa9\x95\x59\x7d\xa6\xcc\xa5\xd9\xb1\x31\x24\x81\x4f\xd2\x40\xde\x95\xdc\xff\xdf\x4a\xf0\x08\x49\x48\x98\x67\x8f\x2d\xeb\x6c\x50\xcc\x1b\xf8\x92\x4b\x55\xfc\xbd\xeb\xdf\xd4\x65\xd9\xed\x65\xde\xae\x5d\x6b\xce\x65\xab\xf5\x0e\xc9\x68\xef\xe8\xed\x05\xee\xff\x6f\x6f\x44\xfb\xdc\xdb\x9c\x5d\x58\x28\xaf\xd2\xfc\xf0\xe9\x9e\x87\xd7\x5e\x67\xc4\xc4\x1b\x10\xbb\x20\xe3\x88\xba\x30\x1e\x84\xf4\x9b\x84\x14\x90\xc0\x02\xa7\xe9\x5c\x05\x42\x10\x7c\x9f\xab\xe9\x83\xf2\x0f\x96\xa8\x42\xe4\x0a\x18\xd7\xcf\x9d\x09\xe2\x5b\x6e\x0d\x2a\x3e\x4a\x00\x72\x0d\xdf\xf2\x70\xad\xcc\x65\x18\x88\xe3\x71\x8d\x2b\xfb\x4d\xf2\x64\x61\x08\x76\xb2\xc4\xbd\xe0\x5f\xff\x6b\x51\x16\xbc\x59\x68\x93\xb4\x79\x95\x0d\x15\x86\x04\x75\x60\x0a\x7a\x50\x01\xd2\xdb\x46\xbf\x14\x2d\xc5\x16\xa8\x08\xef\xcf\xe1\x72\x6c\x68\x37\xc7\x61\xe4\xe3\x53\x07\xa9\x9c\xcd\x78\x5c\xe3\x2a\x82\xe5\x7e\x21\x6f\x4a\x2e\xb9\xf0\x65\xee\x2c\x84\x96\xf3\x38\x11\x50\x70\xcc\xc7\x6b\x65\x92\x94\x86\xeb\x4b\x51\xcd\x90\x30\x47\xf6\x8e\x54\x60\x3b\x40\x86\xc8\x7e\xf3\x83\x53\x86\xc7\xfd\x8e\xb8\x3f\xa3\x11\x67\x5b\x11\xe4\x54\xf4\xa7\x03\x5f\x47\x22\xf4\xb8\x05\x0c\x4d\xe7\xfd\xc3\x6b\xaa\xc8\x67\xe5\x28\x54\x86\xb6\x8d\x86\x89\x83\x77\x9c\x91\xdf\xe0\xca\xbf\xdf\x03\x7b\x6e\xaf\xb5\x2a\xdc\x21\xc1\x27\x16\xfd\xe7\xaa\x3e\xf6\x5e\x4b\x7b\x54\x25\xed\x1c\x2b\x7c\xcb\x9c\x5f\x64\xc2\xcc\xef\xe6\xd6\x29\x9e\x4c\x37\x2e\x6b\xf2\xc2\xee\x23\x9b\x64\x77\x70\x4b\xd1\x71\x75\x87\xf8\x41\x0d\xab\x23\xea\xa0\x76\xf6\x72\x63\xf8\xe8\x2e\x1a\x98\xd4\xb4\xcb\x13\xf8\xc8\xa3\x85\xae\xc7\x53\x7c\x7c\x2f\x10\x38\xda\xb5\xe4\xbb\x7e\x32\xf9\x53\x40\xca\x0c\x80\xe0\x23\x75\x5b\x30\xa1\xeb\x86\x63\x8f\xd5\x9a\x09\xff\x7a\x06\x56\x62\x28\x39\x29\x8f\x24\x10\x51\x09\x8e\x24\xad\xe5\x9a\xd2\xb6\xcf\xba\x21\x1b\xf9\xc0\x3d\x94\x8b\x6d\x14\x01\x53\xa6\xe7\xa1\x9f\x28\x7e\x80\x29\x76\x11\xdb\xcc\xa2\x99\x1a\x09\x0d\x2a\x89\x57\x3f\xfc\x99\x0c\xaf\x85\x99\x47\x83\x6e\xd8\xcf\x08\x37\x1c\x95\xe4\xe0\xc1\xa6\x23\x2b\x29\x09\x13\x50\x3a\x4c\xb4\xa3\x4c\x53\x69\x1d\x05\xaa\xaf\x23\x1e\xf9\x73\xdc\x57\x5f\x29\x6a\xd6\x5e\xd8\x3d\xa4\xa4\xc3\x56\x67\x4d\xa3\xc5\xfb\x4c\x53\x53\xbe\x5d\x79\x0c\x01\xf8\xc4\xeb\x6d\x29\xe5\x2f\x95\x03\xd1\xa2\x22\x82\xf7\x1c\x66\x60\xc5\xbc\x92\xf6\xec\xab\x1b\xb2\x65\xe0\x5b\x7c\x6d\xd5\xc6\x22\xeb\x56\xf3\x33\xc6\x43\x9e\x80\xf2\x05\xba\x08\x52\x68\x27\xa8\xc8\xe9\x8d\xb8\x8d\x05\x41\x8d\xea\x57\x41\x67\x48\x0f\x23\x14\xed\xc3\x31\x8c\x48\x49\xfd\x23\x75\x84\x40\x54\xd0\x6b\xf1\x10\xe0\x9c\x16\x43\x3e\xf5\xdb\x43\x0c\x4c\x4b\xb0\xbc\x65\x90\x41\x8a\xa5\x12\xb3\x17\x8b\xe2\x47\x3f\x7e\xf1\x7b\x79\x70\x95\x92\xa0\xaa\xe7\x5d\xa1\x90\xeb\x8c\x75\xb0\xe7\x4b\x95\xbb\x2d\xe9\x7f\x4c\xab\x67\x20\xfe\x42\x3f\x3a\x7b\xc5\xdb\x00\x51\xf7\x8d\xfa\x14\x36\x36\x8b\xc6\x84\xa8\x87\x51\x65\xbe\x26\xed\x55\x39\x4b\x45\xf4\xd9\xc4\xbe\x42\x31\xda\x35\x56\xcb\x60\x7b\x23\xc2\xe3\x1d\x42\xd7\x9b\xea\xb3\xad\x3c\x2a\xd9\xb1\x36\xd0\xc1\x65\x33\x8f\xe9\xab\x6a\xab\x7b\x76\x78\x1a\x55\xc8\xa1\x40\x6f\xa6\xec\xa1\xf6\x46\x13\xe8\x86\x60\xb2\x7a\xc4\x47\x91\x32\xd2\x26\x08\x2b\xa1\xdc\xce\xd1\x30\x9a\x4c\x1f\xf5\x63\x10\xc3\x85\x99\x5f\x28\xb8\x2c\x0e\xf9\xe1\xcd\xbf\x33\xe5\x27\x60\xab\x19\xeb\x64\xd8\x84\x2d\x63\x4b\xcd\xea\x1c\x34\xc6\x2a\xc6\xb0\xd4\x63\xdd\xa8\x3f\x75\xd2\x81\xfd\x0e\x5f\xb4\xcd\xa5\x68\x76\x3d\xd6\xaa\xf3\x75\x82\x5c\xdb\xd7\x9f\x49\x59\x18\x6c\xcc\xde\xa2\x8e\x8d\x51\xe9\x87\xb9\xb2\x8f\xf0\x4d\x82\x35\x02\xfe\xe1\xbd\x87\xe4\x09\x6f\x55\x37\x80\x88\x95\x14\xb2\x55\xd0\x1f\x88\xb3\x34\x7b\x49\xd4\x16\xe0\x3d\xf1\x01\x83\xbd\xa7\x35\x0d\xd5\x78\x3f\xf7\xdd\x60\x82\xee\x06\x5c\xc1\x6b\x61\xd3\x02\x3e\x42\xee\x14\xb9\x27\x37\xf2\x94\xe1\x4b\xc2\x4a\xba\xed\xa1\x30\xa4\x4c\xb6\x53\xc7\xc1\xe5\x45\x4b\xcf\xe2\xeb\xc1\x2c\x3c\x70\x82\xd7\x59\x65\x4a\xe9\x0b\xcb\xe2\xcb\x32\x26\x11\xa5\x64\x28\x37\x7f\x62\x7f\xbc\x02\x59\xd2\xf0\x3d\xf4\xf3\x58\xc3\xda\x46\x1e\x2f\x63\xe4\x6f\x2f\x94\x50\xba\x30\xa6\x2a\xc2\x63\x71\x63\x34\x30\xef\xd6\xdb\xe5\xe5\x5d\x4a\xb1\x07\x29\xb9\x5a\xea\xe9\x11\x86\xa5\x21\xb1\xc1\xe2\xff\xaa\x76\x88\xf7\x59\x3e\xca\x23\xd1\xe2\x5b\x2d\x4f\x31\xcb\xe1\x1d\xe8\x00\x67\x09\xdc\xed\x81\xba\xc2\xf7\x37\x59\x34\x2f\x01\x7b\xb7\xca\x6c\x03\xef\xaf\x84\x2b\xbc\x46\xd6\xf3\xb4\x25\x40\x10\x4c\x87\xb5\x61\xd3\x0d\xa5\xe0\xd4\x8f\xfd\x3f\xa5\x26\xc6\x7e\x55\xda\x14\xa5\x8c\x06\x27\x5f\xbc\x83\xe9\x77\xef\xc2\xe3\xab\x50\x05\x45\x7c\x4a\xb2\x85\x29\x1d\x61\x01\xd4\xfd\x89\xd3\x96\x28\x8b\x43\x95\xad\x82\x89\xd2\x88\x51\xb1\xac\x4a\x5c\x64\x11\x11\xb8\x5b\x24\xe1\x0d\x3f\xa3\x85\x81\xde\x4c\x56\x12\x1a\x32\xcd\xdb\xe9\xd2\x10\xce\xdc\x21\x81\x77\x20\xe9\x72\xb9\x46\x75\x40\xc2\xa4\xa5\x3f\x9f\x51\x73\x36\x3d\xfb\x8a\xd3\x4d\x2d\x09\xb8\xc2\xa2\xc7\xdd\x41\xd7\x05\x65\xda\x6b\xac\x5b\xfd\x35\x32\x62\x3d\xc7\x05\xc2\x3f\x09\x57\x4d\x15\x9f\xe0\x80\x4e\xeb\x87\xd9\xb9\x39\x2c\x29\x75\x4b\x94\x96\xc5\x1c\x97\xd6\x32\x54\xc9\x06\x41\xb7\x66\x65\x75\xd0\x19\x47\x5f\xff\x96\x00\x41\x4e\xae\x33\x4a\x41\x3f\x09\x7f\x40\xd6\x60\xba\x08\xf7\x22\x47\x20\x33\x01\x70\x25\x1c\x3d\xdd\xe1\xf8\xc7\xd0\x9a\xbd\x39\x87\x76\x48\xd6\x27\xb8\x11\x04\xef\xa5\x17\xfa\x05\xf2\xcc\x19\xe1\xe1\x41\xea\xb0\x04\xbc\x35\x3e\x1c\x1a\x5f\xdc\x6f\x63\x86\xbd\x92\x65\xc6\x6f\x52\xcc\xc7\x03\xdb\xd7\xf3\x0e\x3c\x2b\x33\xf8\xee\x44\xad\x91\x00\xc3\xce\x4f\x2b\xa8\xee\xa0\x63\x19\xca\x50\x0f\xf4\xbe\x89\xb2\x8f\x12\x0a\xde\x67\x46\x07\x1e\xe6\xea\x0f\xd2\x42\xf4\xce\xf5\x69\x6d\x2d\x46\x96\x06\xa8\x25\xdf\xbd\x03\xab\x69\x0b\x03\x7f\x0a\xc4\xdb\xe4\x58\x50\x25\x8c\xa2\xb0\xcc\x5b\x03\x30\x74\xab\x38\xf8\xbd\x45\x0f\x6b\xe7\x7a\x6a\xd8\x59\x56\x45\xdf\xd1\xec\x40\x4c\x41\xb8\x58\x8e\xe9\x59\x62\x79\xba\x5e\xe7\x1c\xea\x10\xaf\xfc\xd6\x7f\xb0\x84\x5e\x1f\x5f\x5e\x45\x3b\x43\x84\xa0\x77\x71\x4b\xa7\x15\x8f\x49\xe0\x31\x71\x0d\x30\x29\x05\xa9\x01\x1b\xba\x33\xaa\x1f\x7a\x93\xf3\x2c\x55\x34\x14\xaf\xc5\x23\xb0\xc0\xfd\x07\xc1\x20\xc6\xdf\x31\x1e\x0f\x36\xb7\xcf\x73\x1c\xee\x6c\x8f\xfd\x48\xfd\xfe\xc9\x12\x0e\xf1\xae\xb6\x6f\x46\xca\x89\xfe\x5e\x9b\x73\x4b\x48\x58\x3f\x3d\x5f\x18\xee\x47\xab\x6f\x9f\xab\x14\x41\x47\xc2\x2e\xeb\x1a\xe2\x3f\xe9\xb6\x29\x6c\xf5\x4c\x2a\x12\xbd\x6e\x82\x2e\xaf\x1a\x98\x5b\xa3\x7f\xd3\x45\x2a\xc1\xe8\xe5\x4d\x75\x72\x7d\x70\x60\x4f\xdb\xd7\xe5\xc4\xac\x73\x11\xc1\xa9\x21\x5d\x75\x9c\x7d\xdf\x98\x72\xbd\x58\xad\xcf\x5a\xba\xc8\x16\xa7\x0e\x22\x0a\x3a\xd8\x7d\x6c\xc0\x83\xb3\x1f\xea\xd7\x54\x63\x35\x32\x83\x5b\x97\xc4\x7c\x48\xfe\x27\x9a\xc1\xfb\xe7\x43\x0c\x79\xfc\x1b\x64\x0c\x67\xb9\xe0\xc8\xe9\xba\x48\xcb\xec\x27\x33\x34\x91\xff\x29\xf2\x33\xf8\x56\xab\x9e\x20\x93\x6a\x72\x0d\x5c\xf8\x46\x96\xa7\x4f\x87\x7e\xc1\xd2\xb1\x47\x12\xce\x9d\x78\x9a\xe8\x7d\xe9\x02\x55\x41\xdb\x2e\x90\x19\x69\xa3\xcd\x94\x32\xc0\x4d\xf1\x22\x8c\xe8\x8b\x28\xff\x89\x40\x38\xb4\xc2\x31\x8f\x9c\xb5\x24\x36\x3b\x33\x6e\xd5\x0e\x22\x41\xf0\x8c\x48\xca\x1d\xc2\x24\xd0\xd1\x33\xf0\x4a\xb5\x2e\xfb\xe0\xc6\x51\x91\xec\x97\xc9\x3c\xbd\x7c\xa7\xcb\x45\xa0\x76\xb1\x98\x26\xc1\x7e\x7e\xd5\xa2\x0a\x47\x64\xa6\x47\xbd\x7d\x74\x22\x50\xe9\x9d\x4f\x05\xc0\x7d\x5e\xd9\x6a\x7e\x75\xea\xfb\x81\xab\xf4\x2c\xaf\x09\x6e\x2f\x3d\xfd\xed\xe6\x81\x86\x54\xc9\x11\xac\x46\xf8\x00\x6d\x11\x66\x89\x55\x19\x4d\x28\x09\x56\xc7\x3d\x3d\x1f\xe9\x8c\xaa\xbc\x51\xed\x51\xc7\xc5\xcf\x43\x4f\xfb\x18\xa9\x8e\x06\xac\xff\x64\xee\x12\x5a\x98\x09\x09\x43\x8d\xf8\x26\x0d\x2c\xae\xca\xed\x2a\x78\x26\x1f\xf1\x77\xbd\xfb\x7c\x75\x99\xb3\x0b\x06\xe1\x1a\x9b\xf9\xd1\x96\xe7\xe5\x82\xc5\x43\xd0\xa0\xb4\xe0\xb6\xb5\x8f\x0f\xf4\x92\x41\x17\x2a\x4a\x2c\x31\x82\xb5\xd0\x75\x70\x71\xe8\xb4\xf8\x48\xfb\x1f\x14\x16\x69\xfe\x33\xd2\xc1\xaa\x2b\xa4\xf8\xcf\xa8\x5d\x71\x50\xac\x5e\x05\x62\x97\x7f\x13\x3d\x04\xe6\x03\xbc\x3e\xd5\x5f\xd3\x1d\x8a\xb5\x8c\xb2\xb1\xba\xc0\xf6\xf5\xa3\xce\x61\x47\xe9\x13\x25\xd8\xa2\xb9\x5a\xa6\x7f\xa0\x0d\x27\x2d\x7f\x23\x45\xca\x2b\x58\x68\x93\x07\x72\x13\x0e\x5b\x83\x2d\x82\xb8\x9b\xfd\xca\xfc\xbb\x3c\xe4\x58\x4d\x93\x11\xcd\xab\xfc\x8f\xc8\xd4\xe1\x9e\x08\x28\x21\x58\x7d\xed\x66\xfa\x56\xe4\xf7\xc6\x3c\x24\x90\x87\x82\xcd\xe7\x8f", 3846);
*(uint64_t*)0x20000360 = 0;
*(uint32_t*)0x20000368 = 0;
*(uint32_t*)0x2000036c = 0x10006;
*(uint32_t*)0x20000370 = 0;
*(uint64_t*)0x20000374 = 0;
*(uint8_t*)0x2000037c = 0;
*(uint8_t*)0x2000037d = 0;
*(uint8_t*)0x2000037e = 0;
*(uint8_t*)0x2000037f = 0;
*(uint16_t*)0x20000380 = 0;
*(uint16_t*)0x20000382 = 0;
*(uint32_t*)0x20000384 = 0;
*(uint32_t*)0x20000388 = 0;
*(uint32_t*)0x2000038c = 0;
	syscall(__NR_ioctl, r[0], 0x2285, 0x20000340ul);
	return 0;
}