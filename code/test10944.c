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
*(uint64_t*)0x20000280 = 0;
memcpy((void*)0x20000288, "\x47\xf6\xa7\x0d\x1b\x75\x73\x4a\x36\x77\x07\xfc\xaa\xf3\xd5\x11\x72\xa7\xad\x40\x16\x08\x1e\xd3\xd7\xd3\x6e\xe2\xdd\x9b\xe4\x82\xba\x9b\xf7\xb4\xc6\xca\xa2\x60\x0a\x56\x0f\x77\x10\x4a\x8b\x2a\x69\xfd\xc4\xd1\x41\x66\xee\xab\xce\x5a\xa2\x18\xff\x4d\xda\x02\xed\x81\xfd\x81\xca\x3d\xb9\xc5\xb7\x2a\xae\x2e\x0b\x6a\x7e\x18\xfb\x72\x94\x81\x4f\xcd\x2a\x36\x80\x6a\x35\xf7\x54\xd7\xd1\xe0\x5b\x43\x42\x45\x38\x1e\x2f\xca\x15\xb7\xce\x21\xc1\x46\x5b\xc1\x1b\xde\x3c\xc7\x56\xd2\x46\xc9\x19\xc1\x1d\xfa\xe1\xb6\x4c\x94\x4a\x18\x0a\x8c\xa4\x1a\x85\xa2\x60\x31\x1c\xd9\x50\x66\xe5\x03\xc4\xb5\x41\x79\x3b\xc9\x71\x68\x22\xd7\x60\x41\x2d\x31\x2b\x3a\x99\x56\x3f\x8c\x56\x75\x12\xde\x58\x1c\x66\x99\x8c\xba\x3a\x42\xd0\x36\x4b\x04\x55\x54\x8d\x2f\xbf\xee\x29\x24\x5d\x1d\x0d\x79\xa5\xd1\x22\xc3\x9d\x1e\x23\xbc\xf8\xfe\x69\x20\x79\xea\xb5\x24\x5f\x0d\x81\x11\x7c\x54\x18\x70\x83\x93\x18\xb6\x58\x8f\x58\xc8\x66\x44\x8e\x35\xb9\xbe\x74\x6a\x47\x71\xa4\x94\x1f\x7c\x1f\xad\x35\x9f\x4a\x62\x27\x71\x1c\x51\x43\xce\x4b\x00\x48\x17\x36\x26\xdc\xe5\xa1\xee\xe6\x8d\xd1\x6e\x0f\x29\x6a\xa7\x3d\x4e\x86\x74\x77\xce\xbb\xfa\x6f\x34\x16\x66\xbe\xc9\x11\x16\x62\xc2\x25\x30\x9f\x8a\xcb\x6c\xeb\x8a\x05\x25\x7b\xdc\x01\x40\xf6\x94\x50\x36\xeb\x1a\x1c\xbf\x0d\x2d\xa2\xd6\x08\x12\xae\x44\xcd\xbf\xd6\xc1\xfd\x70\xe3\x20\x2f\xda\x1f\x17\x16\x7d\x89\xe8\xd6\x02\x46\xb0\xf9\x10\x8a\x39\x7c\x35\x43\x6f\xcf\xbf\xc0\x52\xaf\xd8\xe0\xe8\x10\xcc\x2a\x53\xc5\x9f\x9d\x5d\x65\x94\x9b\x71\x92\x65\x73\x80\x6b\x87\xf7\xdb\xff\xe8\xa6\x1d\xad\x84\x56\x23\x85\x1b\x48\x00\x29\x93\x71\x51\x9f\xee\x02\x23\xc8\x70\x7a\x4a\x1c\x7e\xd0\x50\x4b\xc8\xc3\x4f\x8a\xbc\xdb\xae\x5d\x28\x3c\x67\x8a\xce\x71\xdb\xf9\x0f\x6b\xcc\x7c\xee\x76\x85\x95\x5f\xa1\x4b\x92\x43\x38\x58\xc4\x8f\x63\xe9\x5d\x5e\xb4\x9e\x50\xb6\x9e\x95\xe9\x4f\x44\x35\x4f\x7e\x30\x58\xdf\x6c\x1c\xa2\x50\x1c\xa5\x78\x55\x9b\x82\x6e\x10\x20\x68\x93\x50\x24\x7d\x20\x22\x63\x5c\x1a\x87\x30\xf8\x51\xf0\x47\xc5\x1c\x63\x93\x47\xa1\xb8\xd0\x23\xfd\x68\xd2\x5f\x5d\xac\x55\x5b\xc8\x47\x6f\xc3\x54\xd6\x3b\x35\x3e\xe0\x25\x90\x70\xa0\xf6\xca\x60\xd6\xb2\x7f\x8f\xc0\xb2\xcf\x9f\x8f\xeb\xbb\x45\xe7\xf8\xeb\x0e\x5f\xe5\x65\xa3\x8c\x52\x86\xe0\x8d\xf8\xac\xfc\x61\x78\x2c\xce\xb3\x09\x90\x23\x56\x2d\x51\x9c\x29\x83\xcb\x88\xee\xe6\xd3\xb3\x8f\x6d\xb8\xe4\xf8\xa4\xc6\xcf\xeb\xb3\xe1\xab\x4e\xa0\x33\x60\x18\xe0\x28\x5f\x76\xe8\x10\x63\x02\xd7\x55\x32\x98\x69\xfb\x68\x8e\x2a\x63\x98\x34\xd2\x67\x8b\x67\xb2\x97\x8d\xa6\xa1\x1d\xa6\xaf\xef\x80\x79\xe7\xd6\xbc\x6b\x46\x85\xea\x53\x8f\xbe\x0c\x41\x5b\xe3\x73\x74\x30\xd4\x77\x78\x0c\x76\xe7\x2d\x1b\x63\x3c\xbd\xa5\xa2\x49\xb1\x73\xbd\xfb\x67\x6d\x11\x46\xb2\xfd\xed\x64\xb3\xb8\x8e\x9a\xd0\x7d\x6a\x89\x7a\x97\xf6\x81\xbe\xd2\x49\x49\x8e\x8d\x44\x82\x92\xd8\x0c\x57\x48\xd1\x08\xe6\x6c\x4e\x8e\x90\xbb\x99\xa6\x24\xf7\xf0\xca\x56\xf5\x22\x63\x24\x93\x9c\x07\xd4\x9b\x07\x8d\x29\xca\x55\x1f\xd8\x5f\xdc\x45\x10\x5f\x13\x8c\x46\x87\x2a\x25\x36\x35\x64\x6e\x16\x86\x2f\xa2\x2f\xcd\x86\x1a\xad\x0d\xad\xd6\xc7\xdd\x52\x3e\x3c\xad\x81\x6d\x33\xbc\x06\x31\xc0\x01\xe6\xd5\xfb\x69\x79\x19\x12\x50\x2e\x93\x0c\xf8\xb3\xec\xe2\xb2\x3d\x59\x4e\x1b\x70\x3d\xd4\xc2\xf9\x1b\x68\x60\xa6\xeb\xfb\x1f\xb5\x64\xe1\x3f\x7d\xe9\xd7\x2c\xbc\x9c\x64\x61\x17\x0a\xbb\x89\x2d\x83\xa1\x5d\xa2\xf6\x73\x00\xca\x42\x1d\x0b\x09\xe2\x8a\xa9\x22\xcb\x79\x13\xb6\x6f\xe3\xaa\x2b\x81\x4c\x31\xcd\x7c\x1b\x8d\x72\x03\xd7\x00\x55\x9c\x38\xe6\x4b\x0b\x60\x17\x4b\x98\x02\x5b\xd2\x35\x32\x6b\x2d\xc2\xe8\x58\x7b\x39\xfe\x31\x17\x3a\x58\xe2\xf5\x5f\x98\x72\xc2\x9f\x79\xa4\xda\xee\x26\x0f\x5c\x62\x9b\x8d\xdb\xc5\x56\x3f\x42\xf9\xed\x1f\x2d\x6b\xb6\x8a\xdd\x5b\x2a\xf8\xcb\x60\x09\xee\x51\x31\x14\x6d\x0d\x5d\xac\xd3\x48\x38\x22\x49\xea\x47\x78\x52\xc4\x22\x02\xc9\x26\x44\xd2\x44\x23\xe1\x0d\x93\x8e\xd7\xa6\xb0\x4e\x06\x53\x5f\x7d\xde\xa6\x7a\xce\x5d\x83\xc6\xc4\xd1\xb3\x51\x52\x99\x5f\x06\x21\xb2\xf1\xf7\x38\x78\xe2\x56\x5b\x37\x03\x8a\x8b\x8c\x3b\xe9\x5b\x95\xe3\x8f\x1b\x93\xe2\xd4\x83\xae\xaa\xd6\x4e\xab\x42\x5d\x7b\x24\x46\x39\xf2\x85\xdd\xe6\x76\x2c\x48\xfe\xa6\xde\xb8\x33\x05\xff\xf2\x7b\x95\x4a\x6a\x38\xc9\x88\x84\x24\x06\x8e\xa6\xc7\x7b\xf2\x48\x2d\xcc\x71\xfd\x3d\xef\x5d\x5a\x90\xc9\x1a\x64\xa4\x94\x66\xec\xd1\x87\x17\xd5\x3f\x10\xf2\xf7\x9e\xd2\x0e\xd3\xbe\x11\x3d\x51\xb8\xdf\xd7\x44\xda\x8b\xd1\x06\x32\x5b\x22\x62\x2c\xc8\x3f\x0a\x75\x82\x7f\x9d\x0b\xae\xab\xa3\xc3\xc1\xfe\x11\xfb\x30\xc2\x94\x0e\x52\xcf\xff\xee\x3c\x6a\x6c\x32\xe4\xda\x6c\x4b\x7c\x8a\xde\xf8\x87\x29\x44\x63\xfd\x35\x57\xae\x3b\x8b\xdb\x19\x0c\xdb\x7b\x00\x0d\x15\xf9\xd8\x0d\x52\xc4\xf2\x1e\xfd\x61\x78\x44\x36\x7f\xe6\x29\x03\x48\xb8\xc8\x5a\x03\x25\xc5\x48\x7f\x07\x9d\x86\xea\x87\x87\x89\x30\x4e\x96\x6b\xe8\xad\x6c\x94\x95\x16\xa2\xf9\xf4\xa4\x70\xb1\x0e\xb9\x65\x84\x45\x02\x93\x18\x00\x00\x20\xef\x09\xfb\x73\x7b\x98\x3a\x2a\x12\xa7\xef\x3a\xd4\x85\x05\xa0\x7c\x76\x6a\xae\x1e\x4a\x9c\xbd\xf1\x70\xdb\x82\xb5\x92\xba\x12\x15\x6c\x4d\x1b\xec\x04\x32\xb6\x44\x4a\x9a\x28\x0f\x04\xa5\x8c\x0b\x05\x80\xb6\x45\xba\x3d\x3a\xce\xac\x34\x5e\x02\x05\x48\x5f\x43\xc3\xff\xf2\x57\x50\x87\x76\xcd\x5f\x1e\x94\x4a\x12\xaf\x6e\xc2\xd7\x44\x27\x57\x39\x95\x75\x10\xfd\xc6\x69\x2f\x59\x50\x29\x87\xbe\xc5\xc4\xdf\xd8\xf7\x7c\x4b\x1b\x5d\x31\x5d\xd7\x77\xd0\x62\x5f\x97\xbb\x5d\x2c\x97\xe3\x14\x54\x4b\x5b\x20\x10\x86\x07\xb9\xfa\x88\xd8\x5c\xb2\xdd\xcd\x39\xbd\x4d\xbd\xaa\x6e\xaf\x04\x21\x9d\x64\x44\x25\x5e\x6e\xff\xc1\x07\x6a\xa0\x72\xa9\x92\xce\xf7\x0c\x91\x8f\x2f\x8d\x4b\xe1\x75\x88\xf5\x02\xfe\xac\x93\x68\x63\x7f\x9a\x3f\x13\xd1\xe5\xc3\x38\xd4\xe5\x4b\xf6\x2b\x9b\xdf\x89\x83\x92\xe4\x69\xdb\x82\xbc\x4b\x51\xc8\xec\x10\x4d\xd4\x35\x75\x3c\x22\xec\x08\x34\xae\x3c\xef\x91\x42\xdc\xf5\x2a\x1e\x15\xa9\x98\x96\xf0\xe5\x8d\x76\x3b\x6a\xb8\xa5\x1c\x38\x48\x4a\x4a\xba\x92\xf4\x6a\x12\x33\x52\x1a\x10\x7f\x9f\x1c\x4f\x3e\xc0\x98\xee\x2b\xc1\x21\x8c\x3f\x80\xbd\x3d\x84\x9a\x9e\xcb\xfe\x4c\x0b\x81\x06\x54\x94\x76\xd7\x6a\x6f\x5c\x7e\xd4\xb1\x23\x2d\x00\x3e\x9f\xae\x8e\xa4\x06\x01\x3f\xfb\x56\x64\x32\x7a\xfc\x59\x6c\xa9\x38\x24\xc8\xaf\xb7\x79\xdf\xf7\x0c\x83\x8d\x94\x15\x2e\x32\x11\x42\x95\xe3\xdc\xe0\x3d\x85\x9e\x44\xbd\xfd\x65\x73\x6f\x12\xa6\x0c\x16\x0b\x37\x14\xa1\x3b\xcf\xee\x1f\x23\x40\x96\x13\x39\xf4\x40\x06\xfa\x25\x35\xea\xc7\x6d\x1b\xc1\x4b\xcd\xbc\x8f\xd6\x2e\xd0\x01\x8c\x23\x47\xa5\x9c\xc9\x30\x9d\x6d\xf6\x90\x64\xf8\x2a\xc1\x5a\x98\x10\x9d\xb4\x87\xce\xe7\x9e\xdf\xd7\x97\x09\x6b\x1c\xeb\x49\x15\x1b\xbb\x30\x35\x8b\x78\x10\x0c\xf8\x00\x08\xe9\xd4\x4a\x5b\x90\xea\x22\x0b\xd5\x9a\x48\xc0\xad\x49\x58\xa5\xaf\x91\xc1\x72\xa2\xdb\xf9\x68\x56\xd4\x66\x9a\x8f\x84\xa8\xc5\x27\x86\xb1\x91\x4c\x0b\x3d\x50\xc0\x43\x1e\xc9\x9d\x00\xaf\x9a\xc0\x02\xcb\x5a\x0b\xa9\xba\xa8\xec\x75\xb4\xea\x23\xd6\xbf\xce\x5e\x11\x86\x2d\x1b\xf9\x30\xe2\xc0\x80\x43\x21\xed\x65\x3e\x22\xf2\x5e\x20\x1e\x1a\x16\x8e\xf0\x3b\x21\xdf\x2e\x79\xa4\x2d\x34\x79\x0d\xde\xc8\xe4\xc4\x69\x00\x70\xbd\x86\x42\x64\x79\x89\x9b\xba\x4b\x77\xe7\xb2\xeb\x66\xef\x3c\xb5\x15\xec\xc0\x26\x79\xe4\x0a\x28\x87\x82\x14\x69\x8d\x4e\xe5\xbd\x34\x4f\x9c\xd1\x13\x9c\x71\x37\xbd\x85\xd7\x92\xed\xbf\xca\x9a\xff\x7c\x29\x7a\xfa\x03\xf7\xf3\x93\xc0\xab\x52\xe0\x06\x0f\x4a\xe0\xb9\xef\x21\x29\x2c\xd0\x2c\x05\xe7\x06\x94\xea\x9a\xa3\x0a\xe3\x46\x50\x15\x66\x73\x90\x01\xaf\x07\x89\x87\xcf\x4f\xcb\x4e\x76\xdd\x5a\xf8\xc6\x9c\xb4\xb6\x6a\xab\xb5\x19\x70\xd1\xa8\xb9\xdd\xf7\x44\x00\x60\x77\xa1\xec\x9a\x1e\x1d\x78\x27\x79\x5b\xe1\x13\xcb\xc5\x7c\xfb\x36\xf1\x04\x30\x42\x10\xdd\xca\xdb\xee\x56\x7a\x1b\xfd\xe2\xdc\xdf\x69\xae\xdf\xea\x3b\x6d\x6c\x43\xa7\x02\xeb\x96\xa5\x56\x0b\xb0\x77\xac\xab\x8e\x83\xe7\x23\xb7\x80\xe5\x98\x0f\x2a\xdd\xa2\xa8\xcf\x36\x50\x87\x37\x81\xb4\xf1\xe5\xa1\xef\xc3\xcb\xed\x5b\x20\x95\x8a\xe5\x48\x4d\xa9\x38\xd4\x33\xd4\x97\x69\x24\xbd\x10\x36\xa2\x79\xfd\x54\x33\x67\x5c\x97\x76\x26\x32\x01\xa8\xce\x44\x6e\xd3\x80\xaf\xea\x72\x41\x58\x9f\xe2\x82\x87\xad\xc2\x60\x0f\xd0\xf1\xea\x6a\xb2\xad\x49\xa3\xda\xd2\xb1\xaa\xd5\x30\x77\x50\xc0\x9c\xdd\x8c\x78\x08\xf7\x95\x4f\xc3\xa8\x91\x6c\x8e\x5a\xa5\x25\x7a\x43\xcf\x0a\xcc\x1b\xc6\xe8\xab\x88\x07\xdd\xd9\xd0\x73\x4d\x1a\x7f\x65\xa9\x6e\x1c\x9e\x3c\x8b\xd4\x4f\x77\x2b\x92\xfc\x32\xb2\x1a\xcf\x54\x76\xbd\x1f\x63\xfa\x34\x52\xa5\x98\x62\xc3\x44\x4d\xb2\x85\x88\x2a\xbe\x85\x33\x20\x20\xca\x7f\xd6\x3f\x5f\xea\xc4\xbf\x57\xc7\x08\x92\xd4\x6b\x58\xe1\x8f\x7e\xe5\x1c\x13\xb3\x7f\x12\x08\x03\x9b\xff\x5e\x3a\xbf\x28\xcc\x4b\x8f\x7e\x26\xc7\xda\x53\x64\xf9\x50\xbb\x1b\xaf\xcd\xff\x1d\x0f\x71\x40\x5a\xcd\x20\xda\x10\x63\xcd\xd5\xf1\x06\x71\x68\x64\xa1\x5f\xdb\xaa\x2e\x47\x34\x9a\x13\x1e\xf1\x1b\x50\x79\x33\x13\x78\x81\x70\x52\xef\x85\x75\xc5\xeb\x21\x50\x0e\xa7\x12\x95\x22\x0f\xd7\x3c\x6a\x45\xa4\xb8\xb2\xa5\xb4\xb8\xd2\xea\x24\x9c\xa6\xe3\xdc\xe7\x6c\x79\xd7\x9f\x38\xdc\xaa\x7e\x27\x51\xba\x16\x3e\x5c\xba\x5c\x52\x54\x4a\x57\xe4\x7d\x58\xea\x5e\xc0\xa3\x1b\x73\x76\x41\xbb\xc7\x7b\x53\x8e\xc2\x13\x6f\xee\x98\x91\x23\xee\x36\x3e\xfa\xa8\xd7\x2e\x43\x1d\xdc\x3f\xd5\x94\x4c\x2d\x3a\x2a\x43\x35\xf7\x1a\x05\xbe\x62\xb2\x5d\x0c\x8e\xa7\xb2\xf9\xae\x39\x4b\x39\x5a\xd8\x3d\x78\x46\x4e\x6e\xd9\x84\x45\x48\x55\x92\xe1\x71\x2f\x6c\x3e\xf5\x65\x27\x46\x9d\xda\xb4\x86\xc4\xb2\x5d\x60\x72\x2a\xb3\x98\x9f\xd2\x5f\xa0\xad\x81\xa2\x9f\xff\x5f\xbc\xce\xf6\x3c\xdc\x6a\xb5\xee\x90\xd2\x38\xe9\x6a\x04\xae\x5b\x85\xda\x63\xcc\x49\xc6\x96\x3d\x51\x2c\x7b\x6a\x4c\x94\xbe\xf6\xf0\xa7\x63\x2e\xf9\x5f\xda\x1a\x35\x3b\xa7\x0a\xb2\x6f\x81\x10\x21\x6d\xcd\x4f\xa4\x5e\x01\x1e\xdb\x06\x94\x1c\x6d\x29\x4e\x44\xf7\xf3\x77\x69\x1d\xa2\x1a\x98\xfe\x98\xd9\x3c\x8b\x3d\x7b\xe5\x4a\xcc\x7b\x47\x8a\x6c\x44\x51\xc0\xb4\x9a\xbc\xb6\xae\xdc\x01\x51\x51\x22\x54\xc3\x89\x07\x7a\x5a\x4d\x1b\xa0\xa8\x08\x8c\xbf\x5a\x5d\x79\x64\x8d\xe8\xe4\xe2\xf1\x35\x7d\x4e\x72\xf1\xa0\xda\xf5\x89\x73\x7c\x07\x9d\xd8\x1f\xfb\x0f\x63\x67\xbf\x24\x8a\x7b\xa3\x02\x93\xeb\xe4\x3c\x5f\x0d\x65\x71\xbd\x56\x55\xd1\xf8\x82\x32\xce\xe1\x04\xd9\xb6\x92\x43\x58\x7a\x99\xf5\x5b\x23\xc6\x4c\x16\x1e\x37\x70\x59\x1e\x9b\x30\x2a\x33\x79\xfe\x80\xdb\x31\x3f\x94\x0f\x85\xdc\x95\x06\x58\x4e\xda\xee\xab\x5f\x26\xf8\x4c\xcd\x13\xd2\x39\x6e\x12\x99\xc3\xd4\xf5\xb3\x3a\x94\x8e\x42\x98\x97\x9b\x9e\xfd\x17\x27\xb6\xf9\xd3\x03\x2c\x96\xbb\x83\xbd\x1a\x7c\x2a\x29\x4b\x96\xed\x7c\x74\x98\xdf\x25\x9a\xd0\x42\x10\x1e\x3b\xd8\x90\x61\x1a\xf9\xf8\x07\x73\x53\x0e\x8b\x20\xc2\xfb\x3e\xe1\xe2\x44\x7c\xb8\x9c\xeb\x3b\xa6\xd8\xfb\x85\xe6\x33\x0e\xde\x80\x0c\x2f\xaf\x93\x44\x9a\x86\x33\x1a\xde\xa4\x83\x62\xe1\xe3\x82\x9e\x82\x13\xf1\x89\x9e\x85\x55\x5e\x05\x46\x73\x26\x79\x57\x2d\x98\x28\x4a\xa6\x20\x18\xac\x1b\x9e\x40\xaf\x03\x39\x0c\x65\xda\x19\x46\x6a\xa3\xfc\x19\xd4\xcc\xb2\xce\xec\x4f\xf9\xaa\xa1\x75\x1a\x9d\x71\x14\xa9\x4e\xb0\x92\x04\x46\x3c\xc5\x7a\x3b\xe1\xfc\x21\x1b\xd1\xf8\x93\x23\x73\xcc\x3a\xb1\x14\x24\x32\x7c\x73\xe4\xa0\xea\xdb\x5e\x80\xa1\x9b\x63", 2667);
	syscall(__NR_msgsnd, 0, 0x20000280ul, 0xa73ul, 0ul);
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[0] = res;
sprintf((char*)0x20000000, "0x%016llx", (long long)-1);
	syscall(__NR_write, r[0], 0x20000000ul, 0xffc9ul);
	return 0;
}