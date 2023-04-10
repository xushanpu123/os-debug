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
*(uint64_t*)0x20001200 = 0;
*(uint32_t*)0x20001208 = 0;
*(uint64_t*)0x20001210 = 0x20000080;
*(uint64_t*)0x20000080 = 0x20000180;
*(uint32_t*)0x20000180 = 0x96c;
*(uint16_t*)0x20000184 = 0;
*(uint16_t*)0x20000186 = 0;
*(uint32_t*)0x20000188 = 0;
*(uint32_t*)0x2000018c = 0;
*(uint8_t*)0x20000190 = 0x3a;
*(uint8_t*)0x20000191 = 0;
*(uint16_t*)0x20000192 = 0;
*(uint16_t*)0x20000194 = 8;
*(uint16_t*)0x20000196 = 3;
*(uint32_t*)0x20000198 = 0;
*(uint16_t*)0x2000019c = 0x94e;
*(uint16_t*)0x2000019e = 0x5b;
memcpy((void*)0x200001a0, "\xf7\x92\x81\x14\x49\x22\xbe\x3f\xfe\x85\x4b\x8c\x52\xc5\x6f\x23\xce\x71\x8a\xbf\xd9\xf4\x6a\xaa\x60\xa3\xb7\x03\x5d\x6b\x2d\xd5\x17\x3a\x36\x8c\x3d\xf4\xdf\xd4\xe8\x49\xb8\x82\xfb\xb2\xbf\x6d\x07\x63\x64\xa1\xb1\xfb\xf7\x79\x87\x89\x21\x5e\x61\x5c\x1a\x5e\xd0\xad\x9b\x08\xa1\x00\xed\xd6\xfd\x6c\x9b\x4f\xbe\x6c\xd8\x03\xe1\x4b\x56\xe0\xbf\xb1\xc9\xa6\xe5\x2b\xba\xd4\x24\x12\xe4\xb0\x75\xcb\xea\x09\xa9\x2c\xa2\x44\x14\x28\xda\x29\x73\x31\xd1\x9a\x9d\x35\xbe\xd1\xab\xd1\xbf\xbc\x5d\x84\x71\x2b\x9e\xa1\xee\xf0\x61\xba\x2b\xfa\xb1\xd5\xb2\x31\xb1\x3b\x3e\xa1\xf2\x94\xd5\x0a\x29\x40\x69\x0b\x40\xdc\xdd\x87\xe6\xd3\x67\x9b\x5d\xa6\xfb\xbb\x24\x03\x5f\x27\xfc\xac\xb3\x49\x5e\x66\x32\xa4\x9a\x73\xdc\x43\x8d\x1e\x84\x0d\xd0\x9a\x79\x1d\xf2\xdf\x51\x68\x47\xa1\xb5\x65\x72\xdf\xd6\x85\x6f\xbf\x19\x91\xca\x5d\x61\xc8\x41\xb0\x92\xe2\xd2\xac\xb5\x33\x4f\x94\x99\x4a\xc1\xb8\x9b\x72\x6d\xa3\x27\xc9\xbc\x15\x08\x94\x39\x14\xa0\xe1\x79\x50\x3c\x46\xa1\xf2\x11\x72\xac\x66\x56\x94\xd5\x42\xc7\xa0\xe6\xe8\x5a\xe0\x97\x7d\xfe\x80\x51\x26\x05\xf2\x9a\xef\xb1\xe6\x7e\xd1\xed\x69\x11\xdc\x4f\x24\xa8\x23\x83\x93\x74\x08\x4e\xcf\xc5\xe7\xba\x80\xf4\x0b\xb9\x9f\xca\x93\x8a\x78\x00\xcf\xfc\xa9\x51\xa1\x42\xf5\x0e\xd1\xd8\x39\x4f\xd1\x9f\xcf\xd6\x23\xc2\xf1\x23\x1d\xcd\xbe\x98\x0b\x72\xfd\xf8\x1b\x4d\x2a\x3a\x92\x6d\x8c\x09\x0f\xff\xc2\x2f\x9e\x60\x73\x54\x24\x85\x45\x53\x87\x56\xd0\xe1\xd0\x02\x76\xe3\xa4\x93\xe9\xae\x76\xc3\x6c\x9e\x2a\x15\xe8\xc1\x3a\x55\x04\xee\x6e\x36\x5b\xbd\x4b\xac\xb4\x84\x12\x08\x4c\x47\xfb\xed\x92\xee\xa9\xde\xab\x1b\xf6\xee\x36\x8b\x6f\x39\x9f\xf7\x05\x37\xd6\x95\xba\x83\x8e\xc2\x2e\xce\xc8\x61\x6f\x6c\xfd\x73\x37\x0e\x6d\x0d\x25\x64\x00\x14\x58\x9e\x36\xad\xeb\x0f\xb0\x11\xdc\xe5\xa3\x07\x77\x5e\xca\x73\xa4\x18\xef\xb8\xc5\xc3\xe7\xbb\x46\x49\xb4\x1b\x19\x50\x31\x5d\xb9\xa8\xcf\xeb\xf9\xfe\x30\xd4\x98\x15\xa5\x8a\xf4\x5c\xf8\xc8\x2c\x84\xbf\xa9\xbe\xc6\x94\x12\xd1\xc0\x3c\x07\x12\xe9\x63\xbb\xb3\xc7\x97\x52\x2c\xcf\x68\xfc\xc1\x9a\x5d\x08\x96\xc7\xc7\xb2\x0d\xee\xa8\x55\x1c\xb4\x21\x96\x0c\x22\x6a\x24\x10\xd1\x62\x7a\x3a\x39\x01\x9e\x9e\x9f\x07\x14\x41\x8c\x13\x6c\xd9\x41\xc6\x6f\x71\x77\x7f\xe6\x35\xb1\x72\x7d\x0e\xbb\x3c\xc4\x16\x10\x19\xe1\x0a\x36\x39\x59\x7a\x38\xa2\xc9\xa2\x2a\x96\x37\xa2\x9e\x02\xdc\x93\x05\xbe\x78\xe1\x3b\xb3\xe6\xc7\xf4\xbe\xf3\xaa\xbd\x0b\x82\x44\xed\xc6\x23\x3f\x1c\xf1\x6d\xb2\x39\x57\x2e\x15\xcc\x5d\x92\xb7\x6b\x95\x6c\x3b\x54\x67\x5b\xb1\x55\x0e\x1d\x86\xe4\x58\x06\xd6\x38\xce\x67\x12\xc7\x54\x55\x2d\x5c\x55\x3c\x52\xc8\x61\x5b\x39\x35\x9c\x61\x09\xd4\x75\x8c\x78\x3d\xb3\x70\x1c\x44\x4e\x96\xf3\xd8\xe9\xa8\x64\xe6\xf1\x95\xff\x7e\xe8\x44\xad\x16\xe5\x0f\x80\x97\xa0\x32\x82\xe8\xc0\x29\x18\x64\x99\x33\xb0\x19\x54\x3c\x5e\x36\x70\xc8\x4f\x46\x6a\x69\x0f\x86\xcc\xd9\xe6\x28\x46\x4b\x6a\x38\x5e\xe7\x76\x91\xf4\xdb\xcb\xb0\x09\xb6\xeb\x28\xd3\x96\x5d\xad\xc1\x1c\x5a\x0a\xd7\x10\x95\x6f\xbd\xe6\xed\xb3\xee\x66\x1c\x8b\x54\xa0\xaa\xb6\x5b\xb5\x46\xc4\xb3\x46\x78\xe5\xbe\xb3\xf3\x27\x36\x95\x5b\xf0\x78\xd0\x51\x73\xb2\xd0\xdc\x1c\x12\xa4\x25\xbf\x07\x74\x30\xb4\xb5\x3b\x64\x5d\xf7\x03\x03\x51\xec\xca\x11\x34\xea\x55\x09\x65\x13\x87\xc9\xb0\xbc\xde\x00\x54\x5e\x81\xfe\x47\x0a\x9c\x17\xbc\x91\xe6\x65\xa9\xd4\xb5\x21\x3f\xb3\xa6\x46\xf6\xe6\x3f\x00\xc7\x7b\xd0\xde\xd7\xfd\xed\x56\xf9\xe2\xc5\x97\x3e\x85\xcd\xf2\xc4\xf9\x5a\x65\x15\x98\x3a\x5f\x6c\x5b\x17\xe5\x27\x3e\xd2\x18\xc3\xb4\x03\x23\x0d\x95\xb0\x04\x1d\x69\x72\xd9\xd9\xc3\x09\xeb\xdf\x03\xd9\xc8\x92\xd1\xd4\x2d\x95\x1d\x84\x97\xaa\x06\x84\x1e\x21\xd3\x38\x49\x1a\x66\xea\x6c\xab\x8c\x7b\x89\x69\xad\xd7\xb6\xe1\x8c\x3c\x0f\xae\x50\x60\xf5\xf2\x93\xf5\xe5\xb1\x35\x6c\x5e\xb2\x26\x16\xce\x6d\x4b\x85\x48\x55\x93\x1f\x36\xc2\xae\x0c\x6b\x55\x0a\x0e\x62\xbe\x17\xf3\xb6\xaa\x0e\x01\x5c\xab\xd2\x32\xa0\x0f\xf1\xd0\x28\xdb\x93\x37\x93\x24\x6e\x78\xc2\xa3\x8a\xf7\x1f\x1f\x28\x3b\x6b\x86\x6a\x71\x6d\xcf\xd7\xbc\x0f\xd7\xd7\x89\xfc\x5f\x53\x2e\x31\xd0\x9e\x78\xed\x47\xe5\x1f\x42\x11\x32\xd4\x24\xa6\x51\xd3\xfd\x27\x5d\x66\xc4\x98\xcf\xe4\x54\x52\x17\xc3\xd9\x49\xad\x60\xec\x1d\x5a\x6e\xca\x07\xa7\xed\x81\xbc\x89\xa5\x02\x58\x64\xb0\xde\xbe\x80\xd7\x34\xdd\x31\x6b\x43\x5b\x6d\xf2\x83\xe0\xc5\x91\x21\x07\x64\x6f\x62\xce\xc4\x90\xe3\x00\xec\xb0\x18\xf0\x20\x59\xd1\x7d\xcc\xd5\x2f\x31\xb1\x18\x2a\xcd\x33\x04\x9a\x48\x91\x2a\xfc\x0b\x33\xc9\x11\x1a\x07\xe0\x2b\x05\xa0\xa5\x06\x95\xda\x4d\x90\x1a\xde\x10\xd7\xba\xb5\x96\x8c\x2f\x90\xb2\x9d\x5b\xc1\xbb\xf5\xc3\x1e\x2e\x01\x26\x1e\x68\x06\x8d\x7d\x5b\x87\x3a\x59\xc0\x25\x8e\x31\xa6\x81\x66\x97\xa4\xac\xdb\x77\x61\xa9\xf2\xf4\x44\x66\xdc\xfe\xab\x16\xf3\x04\x8f\xfb\x17\x90\x3b\x36\x91\x9e\xe2\xf4\x85\xdf\x7d\xfa\x85\x8d\x97\xb2\xc2\xc3\x27\x0f\x58\xab\x2e\x67\xa5\xe6\xf3\xff\xf7\xcf\x26\xfb\xa3\x2a\x17\xa7\x11\x99\xed\x0a\x8d\x61\xf6\x43\x53\xd8\xd8\x0d\xfc\xe6\xed\x29\x5c\xc3\xbc\x48\xb9\xed\x2c\xbf\x13\x3d\xc6\x6d\xf1\x18\x0e\x87\x07\x6a\xa3\x25\x36\xf8\x1a\x1b\xeb\x2b\x44\xb1\x90\x0b\x9c\xbe\x73\x74\x56\x97\xc0\xc2\xbd\x3a\xce\x2b\x10\xf1\xac\x38\xe0\x5e\x72\xeb\xcb\x6c\xe4\x40\xba\xbd\x3b\xde\xd9\xf7\x2c\xba\x96\xba\x16\x3b\x51\x51\xe6\x6b\x0b\x7c\xaa\xa7\x50\x7c\xf4\x85\x99\xac\x9a\x73\xc6\xc4\x85\x50\x0a\x87\x1f\x43\x06\x24\xf1\x84\xd9\xec\x6c\xc2\x73\x36\xaa\x98\x67\x00\x7a\x28\x9b\xa4\xa2\x43\xe3\x83\x78\xbc\x90\x42\x2a\xbe\x50\x98\x36\x65\x21\x3e\xa5\x1c\x47\xba\xef\x01\xb6\xc9\x8e\x63\xb9\x89\x1d\x98\xce\xa3\x7f\x6e\xdd\xba\xf6\xfd\xd7\xee\xaf\x52\xab\xae\xd0\xcd\xfb\x08\x61\x9b\xfb\x95\x7e\x65\x2b\xc0\x43\xea\xbb\x2c\xea\x5f\xda\x56\x93\xa3\xc1\x66\x52\x97\x25\x18\xed\xc6\x21\x80\xed\xf1\x2f\x9c\xf0\xe2\x86\xc1\x9a\xc2\x23\x71\xe2\x6c\x31\xfa\xe0\xe8\x96\xec\xb6\x77\x8f\x1e\x3a\xd9\x59\xed\x3a\x91\x20\xea\xc9\x9a\x4a\x86\xe1\x56\x91\x03\xb1\x61\x7c\xba\xf1\x73\x35\x76\xdd\x4b\x24\xd5\x37\x90\xb6\xeb\x09\xb3\x10\x43\xff\xdf\x45\x5f\x5a\x0f\xb4\x4e\x3a\x76\x43\xda\x5b\x15\xbc\xfb\xa0\x3d\x65\x13\xad\xc6\xb1\xb2\xd0\x06\xd1\xcd\x2c\x35\x8b\x4e\x1a\x8e\x1a\xc1\xdd\x97\xd4\x70\x73\x76\x36\x2f\x5a\x40\xb3\xbe\x8c\x21\x65\xc5\xa7\x67\xb4\xae\x5e\x68\xc1\x7e\x4a\xb0\x84\x04\xe8\x21\xb8\xaf\xcd\xc4\x10\xc2\x27\x18\x97\x93\x85\x88\xba\x39\xb8\x6a\x88\x10\x51\x5b\x14\x9c\xa5\x38\x25\xec\xc4\x25\x9e\x0f\x68\xd9\x22\xb5\x8b\xac\x04\xfb\x4e\x27\x26\xa8\x9e\x6a\x9b\xa1\x58\xbd\xe4\x2f\xf5\x97\x06\xaa\xae\xe8\xa3\xf8\x14\xa7\x2e\xf9\xa1\x1b\x05\x36\xd8\x37\x38\x73\x7c\x2b\x3f\x43\xd7\xa7\xed\x60\xe0\xa3\xab\x98\x7e\x55\xa8\x33\x70\x79\x41\xed\x0c\xc2\xfe\xdd\x26\xf4\x28\x52\x58\x01\xed\x21\xba\x43\x48\x27\x67\x56\xea\xf4\x48\x1d\x1c\xb2\x56\xbd\x4e\xb7\x91\x07\x9d\x54\xfa\x2e\x43\xea\x41\x1a\x1f\x99\x5d\x55\xa3\x36\xc3\x85\x26\xa2\x2b\xe4\xb8\x2d\x7d\x5c\x29\xf0\x44\x7e\xd5\x30\x89\xa1\xfa\x77\xe1\xf4\x93\xa1\x3e\xb8\x9b\x63\xac\xf8\x13\x64\x1f\xba\x11\xd7\xaf\x65\xd5\x64\x20\x04\xa3\x3a\xf2\xaa\xc5\x50\x26\x87\x5d\x26\xdd\xff\xf2\x97\x99\x01\x4a\xf0\x2c\x73\xd7\x53\x66\xea\x2d\x11\xac\xc4\xa8\xd3\x62\x2d\xe0\x6c\x7e\xc2\x15\x42\xcb\x95\xfd\x7e\x34\x1c\x3b\x4a\x2c\x46\xbf\xcc\xaa\x51\x72\x8c\x2a\x32\xaf\xc4\xc1\x71\x9b\x68\x4d\xc5\xa4\x0e\xc6\x6d\x92\xec\x01\xaf\xac\xc7\xce\x3d\x35\x39\x9d\x09\x1c\xeb\x52\x3e\x19\x77\x71\x86\x78\x1a\x29\x79\x17\x29\xeb\xdb\x21\xb0\x7e\xf4\xc0\xb4\xed\x3e\xc0\xa8\x2c\x72\x93\x47\x9a\xae\xad\xdc\xe8\x2a\x68\x11\x82\x93\x61\x82\xb0\x81\x6e\x58\xfc\x95\x99\x35\xf3\x51\x19\xf6\x13\x5d\xae\x2e\x13\x41\x90\xd2\x99\x72\xd8\xcf\x5a\x39\x49\x97\xb5\x4a\xa7\x17\x6d\x6a\x3f\xef\xbc\x5e\x55\xd4\x61\xe8\x28\xe4\xac\x5c\x8a\xb1\x2f\xa2\x14\xd2\xa0\x9b\x61\xe6\x76\x57\x4d\xd4\xee\x07\x34\x58\x29\x5d\x14\xe4\x49\x32\x71\xd3\xfa\xa8\x7d\xe2\xa6\x54\xf0\xe2\x9b\x2d\x1b\x70\x45\x53\xa5\x3b\xf6\x5d\xe1\x40\x3c\x6b\xf3\x0a\x16\x6d\x65\xee\x82\xa8\x1b\x9a\xc1\xf9\xfa\x45\x79\xa7\x09\x9f\x5e\xbb\x26\xe3\xeb\xce\xf5\x5f\x56\x66\xbc\x7a\x4d\xd0\x5b\xea\x78\x98\xbd\x22\x05\xf8\x42\xb8\xfb\x7a\x9c\x92\xd2\xfd\x74\x07\xd5\x86\x53\x85\xb6\xcc\xb3\x73\x08\xed\xb2\x27\xeb\x22\x1d\xdb\x8c\x09\xc0\x35\x82\x54\x2e\x34\x4f\x07\xca\x6b\xf6\x27\x50\x80\xa8\xd2\xdd\x95\x9a\x84\xad\xce\x5e\xad\x5f\x06\x25\x52\x56\x98\x40\x57\x8e\x1e\xb6\x5e\x41\x9f\xb4\x41\x3d\x28\x03\xb9\x50\xea\x9d\x1b\x5e\xd6\xf9\x6d\xaf\x6e\xa8\x10\xf3\x74\x43\x93\xb2\x5e\x29\x4b\xf7\x27\xad\xd2\x80\xf9\x36\x77\x14\x51\x08\x27\x71\x81\xcd\x3a\xbd\x16\x09\x31\x3b\x7b\xbf\x33\x43\xfa\x2b\x30\x18\x1b\xbe\xe8\x6d\x34\x85\x00\xc2\x5a\xa2\x9a\xdc\x38\x17\x54\x60\x8e\xb7\x3b\xcf\x88\xe6\x16\x56\x77\xcd\xc7\xc2\x8d\x6c\x49\x8c\x09\x6e\xc7\xff\x1d\xf3\xff\x38\x7f\x37\x0f\xe8\xa8\xff\x77\xc8\xf2\xc7\xf1\x6f\x27\x10\x74\x0d\x23\x98\x72\xab\x50\xfc\x43\xf0\x0f\x3a\xe9\xdc\xcc\x3d\x29\xac\xb2\x41\x8b\xf4\xf2\x0c\x14\xf3\xf9\x7d\xc7\x6c\x7c\xbe\x6b\xe8\xfc\x7f\xfe\xa4\xcc\x09\xcc\xfd\x8e\x4d\x36\xce\x74\x2d\x29\x82\x9b\xd3\xfd\x07\x90\x29\xe0\x63\x07\xb2\x45\x66\x06\x0a\x87\xdf\xf3\xd1\xfa\x6d\x76\x70\xb9\xea\xe0\x46\x4c\x1c\x07\x86\x96\x66\x73\xb5\xfe\x9a\x2d\xf3\x8e\xbe\x67\xad\x77\x76\xe4\x17\x2d\x4a\x9a\xba\xe8\x9b\x56\xd5\x1b\x25\xdb\x5e\xc0\x7b\x9b\xa3\xd3\x7f\x0a\x30\x56\xa5\x44\x2e\x89\x76\x17\x0a\xd0\xf3\x01\x50\xa1\xee\x8c\x8a\xf2\x3d\x8e\xf1\x1d\xc9\x7c\x64\x60\xff\x5a\xf2\xc4\x74\xf2\x4c\x33\xde\xe8\xa7\x20\xc9\x38\x8d\xd4\xf8\xcc\xd6\x52\xc1\xed\x97\xc8\xa5\x5c\xe3\x15\x91\xff\x4f\x73\x7f\x7f\xdb\x9c\xa8\xa1\x18\x6e\x61\x1a\xfc\xa0\xb9\x90\x5d\x1b\xe2\x90\x28\xf7\xc3\xac\x6d\x0e\xca\x7a\x3b\x36\x39\x1e\x45\x75\x0e\x1f\x44\xea\x9d\xb9\x3d\xd5\x75\x0e\x8f\x29\xae\x4c\x38\xf9\x33\x9a\x7a\x44\xcc\x6d\xac\x15\x26\x06\x6b\xc7\x18\x22\xff\x53\xa4\x1c\x4d\x8a\x24\x1d\xe4\x60\xb4\xc4\x3c\x18\x11\x5b\x46\xa4\x01\x9c\x27\x0f\xea\x8b\xbe\x50\x86\x59\x2e\x77\x91\xf2\x6b\xdf\x1b\x5a", 2378);
*(uint64_t*)0x20000088 = 0x96c;
*(uint64_t*)0x20001218 = 1;
*(uint64_t*)0x20001220 = 0;
*(uint64_t*)0x20001228 = 0;
*(uint32_t*)0x20001230 = 0;
	syscall(__NR_sendmsg, -1, 0x20001200ul, 0ul);
	res = -1;
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20000000 = 7;
*(uint8_t*)0x20000004 = 0x79;
*(uint16_t*)0x20000005 = 0;
	syscall(__NR_write, r[0], 0x20000000ul, 0xff64ul);
	return 0;
}
