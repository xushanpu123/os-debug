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
	res = -1;
res = syz_open_dev(0xc, 4, 0x15);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20000680, "\x5d\x4b\xf8\x7f\x9a\xb3\x50\x0a\x49\x45\x13\x2a\xad\xf6\xe7\x2a\x83\xf2\x89\x2e\xff\x93\x43\xa4\x6d\x0d\xd9\x19\x31\xf6\x20\xd9\x80\xbb\x2f\x14\xb6\xa5\xb3\x5a\x03\xc0\x8f\x22\x73\x1d\x6c\xff\x59\x69\x55\x84\xd7\x31\x83\xe2\x32\xf3\x2d\xad\x6d\xed\x78\x67\xb1\x71\xbb\xd0\xe5\xf0\xe7\x00\x1d\x6b\x34\x9b\x36\x55\xc8\xfe\x36\x10\xa5\xdd\x6b\x7f\x5d\x4f\x0a\x04\xa0\x3c\x35\x23\x9d\xd6\x85\x42\x7a\x1e\x69\x87\xaf\x67\x52\x3a\xd9\x0b\x92\xeb\xfe\x74\x0f\xd6\x9b\x27\xdd\xec\xef\x6c\x47\x2f\xb8\xdb\x54\xd1\x96\x3c\x5c\x0c\x4c\x23\xee\x40\x8e\x9b\xae\x17\x0a\xe5\xbb\x5a\x8f\x5e\x72\xf6\xec\x09\x11\x2a\xcd\x30\xf1\x48\xf7\x1f\x9e\x1e\xc8\xda\x8f\x05\x64\x1a\x58\xfe\xfd\x4d\x9d\x9e\x79\xa8\x25\x30\x06\xb8\xdc\x50\xfd\x88\x1f\x83\xdc\xb2\x98\xdf\x81\x83\x83\x82\xb5\xfc\x78\x2a\x2b\x78\xa4\x06\x4c\x0e\x51\x4f\x71\x9e\xeb\x66\x3f\xe5\x0f\xc5\x17\x35\x5c\x10\x3d\x5a\x7e\x91\xb5\x70\xbe\x68\xa6\x01\x1f\x8e\xe4\x8e\x40\x53\x7d\x57\xa0\x15\x18\x60\x54\x90\x7d\x2a\x13\xc6\x18\xa0\x5c\x6f\x49\x09\x2d\x88\x55\xc0\x5e\x45\x20\x43\x28\xad\x00\xe7\x33\x1e\x5e\x65\xab\xb3\x8e\x7c\x59\x44\x3c\xcf\x65\xc1\xd7\x33\x6a\x11\xb5\x8e\xd1\xd5\x6b\xfc\x66\x7d\x2f\x0b\xfa\xe2\xae\x09\xc4\xfc\x93\x9b\xcd\x40\x06\xb5\x1a\x44\x5a\xf7\x44\x75\x84\xac\xfe\xf5\xc9\x0b\x69\xf8\x71\xc1\xdc\x1a\x8b\xfc\x63\xf2\xb1\xf2\x62\x13\x42\xfc\x8b\xdb\x10\xcb\x3c\xb5\x1d\xa0\xe7\x80\x11\x9f\xf6\xfc\x99\xfa\x57\x95\xad\xfa\x37\x58\x6d\xe7\xb7\xfc\x32\xac\x4e\xf5\x3c\xb9\x99\x57\xe8\x95\x2e\x28\x93\xb7\x54\xec\x84\x6f\x80\x93\x39\x20\x6f\x83\x35\x14\x93\x6f\x62\x73\xe7\x67\x3c\x6e\x01\xcc\x32\x8c\x42\xde\x85\x3f\x8e\xe1\x5d\x4f\x07\xf3\x09\x7a\xb3\x3a\x7a\xbb\xeb\x33\x5b\x8c\x42\x3a\x4c\x54\xf2\xd9\x15\x7a\xa6\x36\x2d\x6b\xc1\x43\x4e\x37\x54\xee\xf9\xd8\xb1\x55\xe2\x54\xec\x3b\x9e\x24\x4e\xd8\xd1\x13\x9d\x30\x9c\x00\x3c\x0b\xc1\x49\xea\x78\x9b\xb4\xef\xb4\x1f\x74\xba\x35\xa6\x46\x01\xdd\x2e\x46\x66\x18\x98\x9c\xac\x9c\x2a\xf1\xa2\xe5\xbf\x1e\x6f\xc0\xb5\x8d\x1e\x9a\x6f\xbb\x93\x4c\x7e\xbd\xe3\x6f\x73\x6e\x22\x59\x5d\x1c\x54\x6e\xcd\xc4\x07\xf2\x8a\x5e\xb0\xbd\x2c\x64\xeb\x50\xd1\x9d\xbd\x7b\xe0\xa1\xa0\x73\x75\x5d\x04\x78\x71\xca\x82\xe3\xdf\xb4\xaa\x4d\x58\x77\x19\x8d\x44\xa5\xdc\x78\x61\x65\xe9\x7a\x12\xb8\x8d\x96\xf4\x3f\x6d\x08\x87\x19\x6d\x00\x83\x22\x69\xc5\x3c\x61\x21\xa9\x1c\x8c\x02\x62\x5a\x87\x4d\x6d\xe4\x2f\x0a\xd3\xb5\x6d\x70\x52\xb5\xc1\x80\x3c\x89\xaa\x85\x97\xb9\x1a\x5a\xa4\xc2\xc9\xc5\xcd\xd4\x67\xc0\xdf\x78\x36\x17\x3f\x3d\x7a\xec\xdf\x00\xac\x52\x47\x07\xe3\x3f\x6b\xc0\x5b\xf1\x1f\x82\xf0\xda\x41\x2a\x31\x3f\x91\x99\xaa\xc6\x72\x71\x1a\x8c\x4e\x01\x13\x73\x84\x00\x3b\x14\x33\xed\x3c\xe0\xfe\xa5\xa8\x32\xff\x6e\xbc\xdd\x3c\xeb\x14\x9f\x84\xaf\x65\x80\x6f\x8c\xf2\x2c\x06\x48\x0f\xc1\xc2\xc4\xee\x6b\x9a\x3b\x97\x27\x1f\xcf\x91\xe1\x0b\x39\x82\x64\x97\xb7\x80\xf9\x04\x85\x38\x6f\x61\x80\x83\x5a\xf2\xc4\x7f\x1b\x2b\x74\x4b\xdb\x9b\xa3\xf1\x5e\x28\xe3\x64\xff\x9c\xa5\xab\xd6\xd8\x33\x9f\x35\xd9\xe5\xe2\xe3\xa8\x8f\x73\x45\x50\x72\x02\x52\x4d\x00\x1c\x86\xf4\xb3\x47\xb3\xb7\x81\xe5\x4c\x32\x43\x31\x14\x5b\xca\xc6\xb8\xec\xcb\x60\x03\x8b\x6b\x1c\xdc\xac\x49\x03\x73\x86\x73\xb6\x1b\x52\xbb\x6a\x63\x80\x9b\xb0\x8e\xb7\x75\x09\xb5\xe9\xd9\xf0\x21\x9a\x2e\x78\x81\x21\xf7\xf9\xe0\xba\x74\xea\xf5\xad\x5b\x84\xbb\xf6\x5c\xaa\xc7\x8b\x2c\x30\x0c\x1c\x5d\x70\x2b\x00\xb0\x6f\xc9\xcb\xf1\x73\xd1\x22\x78\x45\x82\x13\x01\xa2\xb0\x4e\x53\x7c\xb5\x9e\x01\xbc\xa1\x1b\xc3\xaf\x17\xcb\x98\xf8\xf5\x22\x73\x11\xdd\xba\x5b\xe3\x49\xd5\xfd\xe7\xef\xa6\xda\xe2\xc7\x5b\x8c\xf6\xe8\x23\x32\x7f\x1b\x4e\x5c\xd2\x7b\x53\x0f\xa3\x3b\xc3\x13\x6a\xbe\x07\xd6\xd9\xb8\xab\x68\x26\xd8\x21\x2a\x7d\xd3\x88\x4a\xee\x2e\xd3\x2d\x66\xeb\xcd\x28\x8b\x5f\xe7\x46\x45\x89\xf8\x30\xff\x31\xde\x3e\x56\x35\x52\xc0\x82\xc2\xbe\xfc\xd2\xae\x8e\x2f\x4e\x27\xe1\x80\x3b\x40\x90\x3a\xc9\xa8\x4a\xa7\x30\x8f\xd3\x62\xba\xeb\x04\x95\x93\x2d\xd5\x1a\x07\xea\x4f\xf3\xf0\x7e\x97\x43\x05\x75\x36\xbd\x1f\x8f\x58\xf7\xae\xab\xee\xaa\x18\x6b\x9f\x9b\xf4\xde\x15\xbb\x12\x74\x93\x3c\x76\xd4\x61\x10\x8c\x13\x13\x46\x34\x6c\x68\x66\x27\xc1\x68\xe7\x1e\x55\xa3\xa0\x79\xf6\x5b\xc8\xb3\x57\x00\xaf\x9f\x7b\x0e\x44\xc4\x1f\x98\x87\x35\x0b\x2a\xd6\x70\xfd\xe6\x57\x8c\xa3\x51\xc3\xc0\x0a\xd6\x84\xfa\x58\x55\xdb\x5f\xf2\xb9\x76\x0a\x42\x34\x93\x39\xe0\x2b\xb7\xb2\x14\x77\x32\xc3\x69\xbc\x4e\x1d\x2c\xa0\x96\xb1\x2e\x86\x00\x76\xc7\x23\xf3\xc1\x9d\x53\x93\x09\x46\xf1\x7d\xce\x15\xcb\x3b\xcd\x31\xe1\x8e\xcf\x09\x38\x86\x84\xbf\x4f\xe0\x5c\xb5\xf5\x81\x24\xfc\x0e\x6b\xa8\xea\x82\x63\x08\xaf\x2c\x79\x74\x6d\x44\x30\x84\x49\xc6\xc0\x31\x8d\xbd\x5c\xfc\x57\xbf\x32\x02\x5f\x61\x70\x5d\xc5\xa7\x10\x36\x44\x41\x9b\x4c\x0c\x5f\xf4\x39\x4a\xdc\xb9\xf8\x1d\x4e\x7c\xa0\x00\xb3\x47\x43\xe1\x40\xc4\xd5\x27\x5c\x43\x94\x42\x0f\xea\x6b\x98\x4a\x5f\x30\xc9\x46\x54\x76\xf9\x44\x16\x50\x19\x3e\x66\xa1\x51\xe6\x9f\xbe\x93\xbe\xfc\x45\x1a\x7c\xd8\x56\x77\x71\x58\xf4\x1b\xfb\x49\x41\x1b\xb9\xc7\x52\x08\xe5\xc5\x93\x0f\x8f\x7f\xb4\x02\xf3\xe8\xd5\xff\xed\x30\x0b\x26\x6d\x3f\xcd\x32\xa8\xc8\x83\x96\x0f\xe0\x84\x91\x01\x73\x83\xfd\xac\x02\x1d\x9d\x6b\xda\xb0\x27\xcc\x52\x9c\x11\x1a\x3c\x6f\x76\x43\x1e\xed\xc9\xff\x27\xe5\xb9\x1c\xce\xe6\x96\x4d\x5b\x13\x25\x9d\xb2\x62\x3b\xba\x4a\x33\x4e\x92\x98\xd7\xbe\x4b\xa0\x25\xcf\x58\x1b\xeb\xcd\xc3\xab\xd0\x74\x82\x1e\xc7\xee\x23\xd5\x1d\xb2\xcf\x55\x9f\x26\xcc\xa1\xb7\xfb\x95\xaa\xd5\x32\x26\x99\x92\xd6\x86\xd7\x8e\x8b\x48\x16\x68\x9c\x4e\x9f\x31\xc6\xbc\x14\xdc\x01\xa0\x89\x53\xc3\xc7\x3f\x7a\xb6\x50\x9b\x46\xc0\xc8\xd6\xc9\x01\x59\xfd\x50\x29\xfb\xa8\x46\xbb\xd4\x98\x8a\x10\x2b\x6c\xbc\x08\xfe\xf9\xf5\xab\x6f\xc5\x86\xfa\xa6\xec\xc6\x89\x4a\xdc\x08\x2c\xe3\x4d\xe5\x6d\x22\xb7\xe1\xcb\xbc\x36\xdd\x1d\x4e\xb8\x12\xbc\xd4\x4b\x65\x0b\x21\x2c\xcb\x2d\xa0\xeb\x62\xd7\x39\x8f\x01\x55\xa7\x4d\xe5\xf9\xce\xbd\x45\x6c\xf1\x26\x19\x65\x5a\x86\x47\xe9\x29\xfe\xf4\xe3\x96\x8b\x9f\x09\x9a\x07\x01\x4b\x8d\xf5\x6c\x41\x91\x3c\x0b\x73\x8c\x50\x43\x5c\xad\xc9\xe8\x93\x90\xa6\xec\xeb\xf5\x5f\xa0\xb2\x03\x68\x40\x18\x4d\x7b\x64\x90\x77\x8b\x42\xa5\x18\x89\x01\x57\x23\xf9\x3e\xbc\xd9\xcc\xa0\x80\x67\x13\x09\x2c\x50\xeb\x12\x56\x7c\x97\xf7\x56\xc4\x76\xcb\x51\xba\x8c\xd3\x6b\x43\xf2\x8b\x16\xce\x6b\x0b\x8e\x66\x22\x87\xee\xd1\x9d\xff\x2d\x72\x15\xcc\x7c\xf9\x4d\x4f\xc7\x3a\x57\x0e\x77\xd1\x16\x03\x5e\xcc\xce\x42\x35\x9e\x75\x36\x38\xe4\x26\xc5\xac\xd9\x52\x8a\x74\xc2\x49\x99\x82\x11\xc8\x21\x06\x32\xa1\xae\x20\xe5\xd2\x80\x0c\x5c\xe7\xc0\x3f\xc1\xc1\x7f\xcc\xb7\xa8\x1f\x69\x6f\x9d\x6d\xf4\xe6\x12\xea\xa1\xd1\x7d\x82\xd0\x03\x76\x60\x9a\xad\xda\x69\x7f\xa2\x19\x7f\xaf\x8b\x7b\x96\x7a\x66\xef\x16\x55\x04\x8c\xf6\x62\x88\x8e\x09\x7a\xff\x6b\xa5\x2c\x13\x61\x3c\xdb\xd3\xeb\x77\x92\x8c\xf8\x51\x4b\x87\xcf\xb7\x40\x71\xb1\x2f\xfb\x1c\x84\xbc\x34\xe3\x96\x62\x5d\xa0\xe5\x20\x9e\x19\xd9\x63\x7d\xb4\xff\xe7\x99\xbd\x4a\x13\x89\xff\xe3\xc9\x1f\xc0\xaa\x32\x54\x54\x07\xa5\xcd\x90\x74\x7e\xc6\x87\x9d\xc7\x7d\xf2\x76\xe5\x68\x46\xb6\x3b\x3c\x6b\x4e\xfa\x02\x4e\x3f\x76\x21\x6d\xa2\xb6\x2d\xc5\x02\x63\xb1\x72\x16\x86\xd2\x34\xbd\xde\x01\xb8\xa9\x20\xa7\xc6\x92\x06\x4d\x5c\x52\x24\x48\xc2\x3a\xac\x81\xb4\x99\x88\xc4\x85\xb1\xd5\x1f\x5f\x10\xa7\x4f\xd3\xc4\xfa\xf1\x04\x1c\xae\xe1\x45\x3d\x3a\x65\x70\xe5\x2e\x22\x40\xe7\x30\x41\xb5\xf4\x40\x12\xa6\x30\x85\x17\x81\x94\x0b\xca\x7c\x6f\xbc\xf2\x2d\x24\xb5\x46\xeb\x17\xb7\x7c\x06\xc9\x8c\x3e\xd4\xee\x68\x4b\x10\x7b\x72\xc8\x3e\x23\x1f\xe9\x23\x60\xde\xd1\xb5\x52\x77\x29\x20\xb9\x25\xb2\xdd\xe5\x78\xf8\xb4\x90\x7b\x42\x4b\x94\x5f\x30\xe7\xb7\x33\xaf\x94\x69\xcf\x2d\x0e\x7a\x84\x2c\x19\x72\xe8\x4b\x1e\x53\xb9\x39\xa5\xdf\x13\xb0\x12\xd3\xdc\xe9\xc9\xb7\x36\x9f\x9e\xe9\x0c\xae\xf5\xc1\x00\x07\x32\x04\x55\x39\xf9\xbe\xca\x29\x13\x3d\xae\x61\xf6\x2a\x5c\x4f\x7d\x74\x5c\xcc\x25\xcf\xe0\x28\x4b\xdb\x4f\x60\xb0\xf1\x9d\x46\xe8\x2c\x1f\x1e\xec\x3e\xcb\x4d\xea\x47\xe3\x56\x94\xaf\x5a\x42\x0b\x72\x21\xaa\x73\x08\x82\x6f\x3e\x4b\xa0\x20\x92\x90\x01\x88\x22\x10\x0e\xda\xc9\x79\x99\x19\xba\x07\x6b\xfb\x2a\x1e\x09\xfe\xca\xe0\x9e\x79\x6e\xcd\x59\x9b\x16\x7c\x87\x10\xd4\x02\xbe\x39\x36\x60\xf9\x6a\xc7\xd5\x3a\x1d\x0e\x33\x2b\x01\x09\xcd\x2e\x47\xff\x58\x83\xa8\x8a\x16\x88\x9a\x37\x96\xc7\x6e\x60\xd9\x4f\xdb\x99\xc2\x5e\x45\x74\x8e\x68\x4d\x6d\x17\x71\xc1\x54\x86\x07\x7d\x6c\x44\x09\x75\x0d\x19\x30\xec\x17\x1d\x82\x08\x67\x8c\x27\x64\x64\x64\xc8\xc4\xae\xe0\xf1\xca\x48\xb7\x3f\xcd\x08\x12\x72\x17\x54\x8d\x07\x98\x1a\xc0\xcc\x6a\xbb\x16\xb8\x46\xec\xd7\x03\xac\xdb\xa6\x7b\x90\xa6\x15\x07\xb6\xc6\x75\x0c\xea\x53\x81\xc9\x37\x72\x25\xb7\x01\xcb\xf3\x0f\x50\xf6\xc1\x39\x8d\xc6\xe7\x12\xc9\xe3\xc7\xe7\xf8\xd9\x42\xeb\x23\xa6\xb3\x08\xee\x3b\x67\xd4\x13\x1f\x9a\x91\x53\x97\x25\x01\x4f\x6e\xa6\x42\x8b\xd6\xa4\x0c\x86\xc6\xdf\x4f\xd6\x36\x18\x7e\x70\xf6\xad\x61\xde\xc5\xf8\x1f\xcc\xd5\x74\x39\xf4\xaf\x2f\xf6\xae\x50\xd8\xea\x88\xb4\x81\x9f\x1f\x99\x16\xf7\x6d\x95\x46\xd6\x12\xca\xf9\xfc\x34\x33\x31\xfe\xfa\x2d\xa8\x6b\xe0\xdf\x6b\x0a\x82\xf5\x09\xb0\x53\xf3\x02\xa4\x40\x55\xf5\x14\xf3\x28\xf6\xd9\x85\xe5\x9f\xe5\x4d\xfb\xfb\x0f\xa3\xa2\xa1\xbf\x99\x56\x60\xf4\xff\x09\xd1\x5d\x6f\x87\x21\x81\x91\x8d\xd3\x5b\x9d\xe4\x14\xfa\x6d\xfc\x53\x58\x5a\xfb\x4b\x95\x4b\x32\x87\xab\x81\x3a\x7f\x15\xab\xce\x3e\x2f\x48\x85\xc6\x01\x12\xdd\x61\xb5\x24\x8d\xaa\xb5\xa1\x74\x9b\x14\x7b\x6e\x47\x72\x0d\x25\xac\x4b\x5d\x29\x3d\xad\x29\xf7\x9f\x6b\xc6\xc8\xf9\x53\x98\xf2\xea\x0b\x91\x13\xd4\x96\x23\x63\xfc\x85\xc8\xbe\xa2\xc9\x92\xb2\x5f\x67\x17\x04\x24\x02\x5e\x6c\xfe\xe4\x04\xd0\x6b\xc3\xe4\x2d\xda\x60\x3c\x55\xf8\xc1\x85\x13\xdc\xbe\x7f\xd9\xf2\x25\x5f\xff\xff\xee\x3e\xcb\x53\x97\xbb\x4f\x4e\x39\x91\x9b\x29\xa0\x29\x48\x19\x74\x8b\xc5\xc6\xe4\x13\x6d\xa4\xa2\x7e\xcb\x00\x4d\x82\xaf\x11\xe9\x28\xdf\x0a\x84\xa1\x18\xe6\xc5\xaf\x1e\xc1\x7e\x56\xa7\x2b\x65\x0d\xc3\x53\x17\x2e\x73\x24\xec\x2e\xa2\x8e\x20\x12\x4f\x52\x1e\x24\xc4\x9f\x63\x8e\xec\x68\x75\xa0\x02\xe4\xe2\x43\x2c\xb3\x45\xef\x46\x27\x59\x16\x67\x76\x8b\xc7\x6d\x2d\x79\x54\xaf\x15\x59\x43\x01\xf4\x77\xbd\xc9\xfd\xa9\x90\x9e\x03\x5f\x0c\x74\xb2\xd4\x85\x53\xc8\xb7\x29\xd6\xaf\x43\x55\x32\x07\xb2\xb7\x14\x32\xdf\xdd\xaa\x5e\x95\x78\x6f\xf2\x4d\xda\x0f\xfb\x03\x42\xa7\xf8\xdb\xb9\x58\x20\x8a\x07\x3c\xb8\x33\x53\x9a\xe4\x71\xfe\x06\xe9\xa0\x80\x6d\xc4\x3c\x45\x49\x4c\xb4\x09\x4c\x99\x92\x7d\x77\x51\xa6\x97\xbf\x05\xcc\x00\xf3\xb2\x94\xc4\xf8\xdf\x09\x0c\x85\xff\x0c\x29\x2c\x10\x1a\xf3\xed\x14\xbb\xa6\x0b\x6f\xcf\x95\x1e\x34\x87\x15\xd6\xc2\x57\x68\x30\x63\x9a\x96\xe5\xd1\xf8\x1e\x78\x90\x64\x79\x5f\x6c\x70\xad\x9f\xea\x0d\x5a\xcb\x7d\xdc\xff\xf2\xab\xc9\x2f\xed\x3e\x41\x11\x92\x98\x00\xee\xd2\xfe\xb2\xc2\x3c\xb1\x82\xea\x52\xde\x92\xf8\x1b\xdb\x4a\x1e\x58\x29\xcd\xbe\x22\x5d\x45\x62\xcc\x34\xa1\x04\xd3\xc1\x0f\x8d\x18\xa3\xa7\x0d\x6d\x52\x8e\x82\xa4\xf5\xb2\xfc\x30\xf0\xac\x09\x0b\xf2\x64\xb2\xe7\x77\xd6\x98\x08\xd1\xd4\xcd\x58\x57\xb4\xcd\xc1\x90\xd8\xd2\xe4\xaf\xc3\x7f\xcd\x8f\xbe\xd3\x45\x2c\x6b\xd9\x06\xa5\x3a\xfb\xb9\xca\xe3\xc5\x39\xcb\x55\x29\x04\xf8\x53\xc9\x21\xcb\x1c\x54\x68\xe4\xb4\x11\xe2\x55\x78\x4f\xd7\xa1\x03\x51\xaf\x7f\xf6\x5c\x1b\x96\x0d\x33\x86\xed\x18\x1d\x70\xd2\xeb\xe5\xf7\x73\x16\x7f\xa7\x05\x06\x6b\xab\x54\x17\x26\xcf\x19\x3a\x1a\xfa\x3f\x8d\x78\x96\x63\x08\x15\xf6\x29\xcf\x8c\x25\xd0\xd1\x12\xd3\x2f\xc7\xd9\xb6\xe1\xec\x8b\xe9\x4e\xcf\xda\xdf\x27\x40\xe7\xd4\x3a\x03\x0b\x15\xfd\x56\x35\xc7\x43\xd7\x06\x3f\x45\x81\xe7\x3b\x4a\x93\xc0\x26\xe3\x32\x85\x03\xca\x88\xc2\x09\xa3\x05\x88\xc6\x9c\x20\x5f\x02\x99\xf2\x34\x20\x06\x95\xff\x92\xd2\x61\xb6\xa2\x1b\x12\x71\x36\xde\xcd\xdd\x75\xcb\xc2\x61\x39\x8e\xd3\x22\xb8\x66\x63\x85\xf2\xd4\x2e\x48\x8e\x59\xda\x6d\x01\xf8\x45\x08\xa6\x61\xc8\x0e\x87\x9e\x2d\x04\xae\x03\xea\x10\x4f\xc2\xe1\x85\xb5\xd4\x11\x90\x24\xf2\xd5\x10\x95\x07\x80\x06\x94\x2f\x56\xb9\x65\xcb\x36\xf3\x6b\x6e\xba\x6e\x9f\x79\x5d\x99\xa4\x3e\x87\xd8\x87\x6c\x3b\x99\xf8\x79\xe3\xa2\x56\x3b\x18\x16\xf8\xb6\xb8\x6b\xac\xd4\x84\x17\x11\x4f\x8f\xda\xbc\x0a\x30\x41\xcc\x3d\x5c\x84\x39\x85\x75\x05\xad\x44\xeb\x19\x78\x8e\x14\xd1\xaf\x04\xab\x44\xcc\x2b\x04\x3a\xfb\xa7\x08\xae\x18\xd0\x87\xa5\x78\x3d\x89\xee\xf3\xc2\xf4\x65\x6e\xdd\x6f\x7a\xd7\xc7\x68\xe6\xf4\x79\x20\xcf\x52\xfd\x02\xa5\x6e\x05\xbf\xed\x3d\x0a\x8e\x31\x04\x35\x81\x0a\xa6\x76\xc9\xbe\xaa\x0c\x13\xc9\xbf\xc3\x83\x8b\x4b\xbc\x48\xdd\xa8\x1b\x52\xdc\xcb\xb5\x88\xcd\xb4\x5a\xb8\xbb\xf4\x9b\x71\xd3\xf7\xb6\x72\xf4\x8c\xfc\xd0\x32\xb2\x42\x65\x37\x50\x6a\xee\xad\x14\x4d\x8e\xb2\x20\x6e\x41\x58\x2a\x3e\x00\xa1\x04\xe9\xd5\x1f\xea\x9a\x57\x08\x72\xfa\x68", 3072);
	syscall(__NR_ioctl, -1, 0x4b61, 0x20000680ul);
sprintf((char*)0x20000000, "0x%016llx", (long long)-1);
	syscall(__NR_write, r[0], 0x20000000ul, 0xffc9ul);
	return 0;
}
