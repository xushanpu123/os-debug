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
res = syz_open_dev(0xc, 4, 1);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x20000280 = 0x20000e80;
memcpy((void*)0x20000e80, "\x18\xb4\x5a\x0f\x57\x8e\xf4\x5c\xcc\xd6\x7f\x6d\xdb\x9f\xdb\xba\x5d\x2c\x42\xd1\x78\xbf\x80\xda\xb2\xdc\xf3\x2c\xa8\xde\xd8\x4e\xf9\x9c\x1c\x7f\x00\xa7\xea\x59\xb7\x1a\xd9\x92\x73\xfd\xbd\xfb\x11\x3f\xf4\x5a\x2f\x6a\x8b\x9d\xcf\x58\xfc\x2f\x92\xdf\xa2\x0c\x30\xba\x32\x7e\x4e\xcc\xce\x3c\x9a\x62\x67\xf1\x0f\xe2\x80\xf1\x9a\x55\x48\xd6\x28\xe5\xd3\x00\x40\x1d\xc5\x6b\x7a\x57\x85\xfa\x1c\x79\x60\x67\x88\x4e\xae\xbc\xe7\xaf\x8d\x7f\x4c\xa8\xe6\xa8\x46\x54\x36\x2e\x9b\xf0\xb7\xab\xd8\x7e\xf2\x31\xef\x2f\x47\x0e\x31\x3b\x85\xb2\x36\xfd\x91\xdf\xfa\x3b\xa8\x9d\x6b\xfd\xf6\x50\xa2\x82\x36\xa8\xc7\x7b\x49\x34\xff\x71\xf8\xc6\x31\xe4\x72\x8a\xb3\xd4\xe8\xd9\xfc\x12\xca\x11\xb6\x98\x77\x4a\xae\x31\x45\xa8\x54\x85\x8a\x42\x7b\xfe\xcd\x54\x19\x36\x57\x42\xde\x2f\xb9\xa0\xda\xc2\x51\xfe\xd1\x7d\xfc\xa1\xef\xa8\x50\x90\x4a\x37\x69\xbb\x49\xc1\x87\x10\x4d\xb3\xfa\x29\x33\x69\xfb\x7f\x22\xb8\x3f\x8e\x56\x0b\x61\x46\x2f\xdf\x8a\x44\xfb\xc6\x41\x4e\xcc\x25\x98\xec\x57\xb7\x46\xd2\x5c\xee\x0c\xe5\x53\x1e\x46\x6f\x82\x49\xb4\x24\xa2\x43\x30\x7f\xef\x95\x9e\x86\x17\xa0\x90\x46\x6a\xb7\x41\x0a\x30\x06\x48\x19\xf6\x6c\x8a\xe3\x69\x02\xba\xba\xcd\x0c\xb3\x03\x4e\xa6\x55\x01\xa0\x2d\x4c\x53\x18\xa5\x9b\x8a\x80\x15\x7f\xa8\x49\x92\xfe\xd3\x70\x4c\x77\xe5\x63\x50\x5f\x75\xe7\x4f\x48\x60\x7f\x7a\xea\x82\x54\xff\x1d\x75\x6b\x55\xf4\x1e\xf2\x0a\x38\x47\x73\xeb\x0c\xcc\x2f\xd8\x7c\x10\xf3\x26\x71\xf3\x73\x1f\x0d\x35\xe2\x2e\x97\xaa\x5d\xdf\xb0\x8b\x00\xba\xb5\xe8\xb0\x28\x2b\xdd\x45\xd0\x4c\x73\x56\x22\x4f\x08\x6a\xf3\x79\x9d\x50\xe0\x7f\x8c\x3c\xf3\xde\x8d\xe3\xaa\x38\x6d\x5f\x56\xce\xb7\xe5\x70\xff\x75\x3f\xd7\x1d\xfc\x68\x31\x65\xe8\x79\x11\x6b\xeb\x6d\x5e\x0d\x4a\xd2\x21\xf9\x41\x51\x07\x8c\x32\x06\x3b\x0e\xe8\x54\xe6\x0a\xf0\xba\x88\xa5\xae\xac\x5a\x1a\x15\x58\x79\x6b\x51\xbe\xf3\xd6\x98\x9c\x03\xcf\x0c\x57\xbc\xf1\x94\xe1\xcb\xb7\x38\xed\xfe\x73\x91\xda\xeb\xe7\x8e\x57\x62\x3e\xfa\xd7\x1c\xce\x30\x3c\xb7\x68\x8c\x00\xca\x57\x9e\xb9\x67\x9b\x72\xdf\x05\x39\xb8\x67\x4a\x1a\x33\x33\x4f\x66\x4f\xc7\xd8\x31\xbc\x63\xbd\x60\x41\x85\x1d\x2c\x5f\x4b\xcb\x1d\x59\xe2\xf6\x0f\xcc\x5d\x91\x6f\x9b\xb1\x0e\x73\xd1\xc7\x29\xe6\xfa\xd8\x37\xee\xe9\xe7\xa1\x09\x37\xb2\x5c\xec\x01\xe2\xe6\x5c\xc3\x0a\xed\x22\xa4\xc5\xe0\xf1\x3e\x19\x0b\x9b\x1c\x2f\xb9\x8a\xdc\x57\x72\x1f\xad\x10\x04\x0c\x3f\xd1\xe7\x02\xbb\x3f\xa4\x1a\xb4\x52\xbd\xe7\x79\xa3\x50\x42\x29\xfd\xc9\xb0\x79\xf3\x3a\xc8\x8c\x57\xc5\x86\x93\x73\x29\x19\x0d\x78\x40\x74\x51\xfc\xce\xfb\x64\x5b\x23\x34\x48\xe7\x72\x93\x4c\x93\x4e\xda\x6b\x61\x25\x00\x0f\x6a\xdd\xb9\x63\x68\xf3\xe7\x5e\xc6\x89\x76\x24\x7a\x62\x50\x4c\x1a\x40\x7b\x07\x22\x43\x86\xed\x9a\x0e\xdb\x91\xcb\x31\x4d\x0e\xf7\x6e\x48\x07\xc5\x5c\x85\x60\x97\x87\x7d\x30\x30\x71\x56\x6c\xc9\x36\x6e\xff\x4a\xe1\x03\x7a\xcd\xee\x50\xa8\x9f\x1a\xf8\x21\x26\x25\x07\xcd\x4f\xcc\xa7\x88\x3f\xd9\xe0\x27\x6a\x1b\xf0\x2d\xfd\x5b\x17\x01\xc5\xe5\xf8\xb7\xf9\xa4\x9c\x1c\xec\xd3\x32\x6a\xfc\x0f\x67\xca\x13\xd4\xfd\xa7\x68\x35\x0c\xa4\xcd\x60\x9e\x1d\x8c\xe8\x41\x39\x35\x7f\xb9\x3a\x2d\x32\x07\x0a\x0e\x37\x72\x1f\x1a\x02\x9c\x9b\xe3\xd7\xcb\x6a\x9d\xda\xd4\xce\x08\x1b\x29\x62\x61\x92\xe9\xe8\x54\xda\x08\x0f\x72\xcb\xc5\x80\xe5\xd5\x0d\x98\x58\xb0\x4b\x29\x02\xb4\xd3\x4d\xca\x6b\xae\x4d\x93\x19\x27\xb7\x78\xd4\xd8\xde\x92\x37\x31\x53\x6f\x1c\x17\x36\xc2\x69\xf7\xaa\x76\x04\x16\x56\x0d\xc1\x60\x14\xf7\x58\x9a\xf1\x27\x91\xff\xb9\xbc\xe1\xb7\x1b\x74\x51\x53\xd9\x64\x6a\xd4\x59\x72\x86\x77\x77\xa3\x5e\xa2\x3a\x97\xea\xc0\xc4\x72\xb1\xed\x53\xbc\x23\xba\xb7\x21\xf6\x4b\x9e\x33\x04\x70\x84\xc4\xba\x4a\xa4\x57\x44\xe7\xf2\xd0\xe6\x06\x9e\x4b\xa1\x2d\x61\x59\x46\x52\x28\x12\xb7\x27\xa1\x3c\xb6\x30\xd2\x08\x03\x7e\x68\x73\x46\x31\xbf\xb7\x79\x35\xc0\x98\x91\x26\xde\x57\x82\xb8\x6e\x3c\xe3\x6e\x5b\x0b\xb5\xb3\xa2\x0d\x14\xe3\xb3\x5d\xba\x7a\x77\x6a\xd0\xce\xf1\x1c\x3c\x3e\x85\x45\x45\x47\x61\x25\xbc\xd4\x76\x9a\xdb\x23\x33\xd6\x36\xc5\x55\x00\xd7\xb0\x08\x87\x05\xb4\x57\xb0\x6a\xb6\x26\xf8\xb6\x8e\x46\x50\x4d\x63\x81\xf5\x3e\x83\x49\x98\x79\x31\xd8\x10\xcb\x60\x15\x15\x35\x7d\xc7\x20\xe1\x8c\xe2\x18\x68\xab\x4c\x7c\xea\x5d\x06\x4f\xf1\xd1\xba\x4b\xa0\x6a\x27\x98\x3a\x7d\xda\x2c\x08\x78\xc4\x27\xa6\x35\xa3\xd7\xf1\xc0\x1f\x51\xa7\xca\x8f\x57\xad\xca\xd5\xbd\x7c\xa7\x42\x61\xc0\x2c\xc6\x03\x49\x63\x62\x84\xb5\xe2\x65\x55\x4a\x44\x2d\xf4\xba\xed\xc1\x4c\x3d\xfc\x89\x39\x7a\xa7\x7f\x19\xb7\xce\xb0\xfa\x61\x68\x6e\x0a\xd7\xa8\x18\x00\x1a\x08\xb0\x12\x12\x77\xf6\x5b\x47\x7a\xc7\x5e\x12\x8c\xcd\x41\x8d\xe0\xc7\x92\xed\x9d\x1b\xd8\xd4\x92\xd8\xf6\x90\xca\x1f\x25\x90\xe0\x59\x6d\xb3\x2a\x00\xcc\x07\x85\x71\xd3\xe6\x82\xb5\x7c\xa2\x1e\x92\xef\x10\xe0\x33\x3f\x3c\x3b\x22\xe0\xb1\xbc\x2c\x8b\xb4\x07\xf2\xdf\xf2\x8a\xcc\x7e\x3d\xe0\x46\x6d\xf4\x62\x81\xe2\x9c\x94\x7e\x14\x5c\x64\x41\xd6\x15\x42\x50\x50\x76\x01\x71\x64\xd1\x2e\x88\x7e\x7f\x0b\xca\x2f\x9a\xab\xb5\x37\xed\x5c\x62\x95\xd4\x42\x0b\x68\x93\xa7\x57\xdd\x76\xc7\xf3\xb8\xdf\x21\xca\xc0\x18\xa0\x99\xa8\x79\x8e\x2f\xd4\xb9\x09\x67\xc5\x75\x46\x85\x58\xd6\x46\x2f\x32\xba\x3a\x18\xfc\x6f\x63\x7b\xe0\x27\x8f\x31\x88\x48\x03\xa9\x87\xcb\x54\x86\xc5\x7b\x2b\x1d\x57\x73\x0b\xfd\x0a\x5e\xd9\x58\x84\x5d\x3c\x42\x23\xa6\x41\x23\x69\x95\x99\xdb\xbd\xd2\x56\x26\x3d\xbd\xf0\x1b\x9c\x4e\x1b\x38\x15\xe8\xe2\x1c\xf5\x24\x29\x9f\xe9\x2f\x74\x85\x6f\x7e\x7a\x00\xf9\x32\xcf\x35\xaa\x48\xdb\xc8\x30\xd4\x7e\x6c\x28\x59\x78\x26\x6b\x9f\x66\x4f\x35\xb6\x20\xdf\x75\xbc\x14\x57\x01\xf1\x61\x56\xf7\x59\xe2\xc9\xea\xd8\x98\x33\x68\x5b\xf0\x04\x2f\xb4\x9b\x96\xa1\x11\xe2\xb7\x50\x72\x3a\x22\xb3\xae\xad\x5b\xcd\x26\xb1\x17\xa1\x33\xe1\x94\xe9\x6a\xf0\x41\x59\x7b\xd6\xf2\xf6\xe0\xe4\x05\xa3\xbb\x11\xb0\xf5\x33\x28\x38\x0a\xb8\xdc\x2d\xb5\xa0\x55\x50\xdc\x82\x34\x15\xcf\xa4\x5a\x97\x66\xc8\xef\x72\x6b\x71\x90\xaa\x3e\xf8\xe7\x7e\x96\x82\x5e\x7e\xf7\xf6\x48\x98\x8d\xde\x51\xd8\x9f\x07\xe6\x8a\x12\xe1\x56\x50\x60\xcb\x77\xd8\x92\x29\xee\xa7\xba\x24\xd0\x73\xf7\xdb\x48\xd1\xe6\x20\xba\xa3\xb4\xef\x5f\x1e\x67\x25\x40\x19\x86\x4f\x8b\x64\x02\xb4\x32\xdb\x5b\x4d\xfb\x8b\xae\x02\x84\x79\x0f\xa7\x0a\x71\x7f\xaf\x17\xd9\xd0\x01\x1a\x62\xae\x18\x9e\x58\x3c\x7f\x77\x83\xe6\x63\x8c\x43\x1b\x7a\xd7\xd7\xc1\x12\xe7\x46\xaa\xbd\x09\x9b\x3b\xad\xaa\xab\x08\x7e\xe9\x67\x01\xc6\xce\x16\xb2\xbd\x01\xe7\x6c\x68\x11\x99\xfd\x9e\x1e\xac\xf3\x38\x86\xb5\x18\xfb\x58\x9c\x6c\x84\x1f\x15\xd7\x70\xc5\xb6\x13\x39\x1b\xb9\x53\xba\x79\x2a\x77\x9a\x37\xfc\x8a\x23\xd6\x2b\x6a\xb0\x58\xc7\xeb\x39\x8e\x2b\x15\x94\x56\x73\xaa\xab\xa3\x10\xa0\x9d\x78\x76\x1b\x96\xcc\x35\x14\xf2\x84\x35\x38\x8d\xd4\x7a\xbf\xa2\xa5\x5f\xb4\x47\xdf\xe7\x25\x39\x16\x3c\xa4\x9a\xdb\x34\xd0\x1e\xec\x0e\xbf\xc8\x37\x61\xc9\xe9\x52\x84\x4d\x8e\x46\x03\xbf\x6c\xc2\x39\x42\xb3\x40\xad\xbe\x01\xbe\x37\xb2\x23\xa7\xe7\x4e\x06\x1d\x96\x65\xd7\x99\x7d\x82\x4e\xe6\xd1\xe7\xa2\x61\xa1\x8e\xd9\x0b\x6d\x90\x76\x23\x74\x4e\x35\x78\xe9\xd3\xd4\xdf\x9a\x82\xe7\x10\xe7\x99\x9e\x33\x70\x91\x6e\xec\xa3\xdf\x07\xa5\xb0\xea\x2b\xd5\x28\x17\xf3\xa8\xe8\x3e\xfe\xe7\x50\xad\x25\x02\xe4\x38\x84\x43\xf6\x04\xd7\x35\xb6\x85\x10\x20\x86\xaa\x3a\x61\x32\x04\xe9\xdb\xbd\xbc\xa4\xe1\x7b\x74\xe2\xe8\x71\x18\x97\x70\xdb\x3d\x6b\x2f\x0f\x2d\x17\x9a\xe9\x63\x0a\x7c\x96\x17\xb1\x47\x87\x57\x11\x9a\x80\xf4\xd1\xfd\x8b\xe0\x4a\xa5\x62\x58\x5e\xca\x27\x4d\xc2\x83\x4c\x17\xd8\x45\x87\x1b\x47\x77\xd9\x46\xb4\x34\x21\x54\x5e\x28\x64\xea\xf5\xc9\x69\x7a\x14\xbf\xef\x10\xc4\x92\xd6\x8b\x15\x02\x47\xcd\xb9\x95\x01\x15\xfa\xb4\xf3\xcf\xe1\xd8\x8a\x2b\x5a\xbe\x73\x8f\x9a\xea\xac\xe4\xb2\xb3\x33\x6b\xed\x9e\xb6\x52\xfa\xe1\xe0\x0f\xee\xe3\x15\xf7\x69\x1a\x1b\xef\xd6\xc8\xfa\x84\xab\x9a\x82\xd4\xf4\xee\x50\x93\x51\x35\xa7\xdb\x7a\xb1\x3d\x0f\x58\x7d\x63\x32\x0b\x6d\x1c\xa5\x15\x55\xb2\x8b\xc0\xd3\xf1\x1d\xb3\x3b\xe1\x33\xe9\x68\x21\x90\x3d\x6e\xc1\x03\xc7\x8e\x3f\x35\x8e\xa1\x6d\x81\x1e\x7c\x71\x82\x3c\x6d\xe6\x91\x2b\x49\x13\x87\xb4\x56\x53\x4c\x85\xb6\x0e\x3a\x97\xa6\xe7\xc2\x49\xf9\x58\xfb\x71\xa3\xf5\x46\x29\xaa\x8c\xcf\x3f\x3a\xa8\x9e\x6e\x6a\x81\xac\x64\x9e\x60\x5a\xd3\xc1\xe7\x1f\x3e\xc9\xba\xc9\x91\x1f\x47\xe3\xcc\xc0\xbe\x93\x08\x35\x02\x64\x14\xf0\xdd\x31\x92\x2b\xa6\x9f\x4a\x34\x38\x29\x2c\x10\x40\x6f\x61\x3e\xd5\x26\x00\x8b\x3e\xb4\x38\xfe\xaa\x61\x17\x3b\x48\x44\x63\x55\x53\xe3\xa8\x42\xaf\xd3\x24\xe9\xc6\x92\x8c\x95\x91\xdf\xac\xa2\x0a\x74\x68\x89\xe7\x8f\x3d\x9b\xad\x62\x4a\x21\x5d\x57\x57\x23\x37\x8c\x46\x06\x84\x4c\x1e\x36\x7b\x28\x60\xaa\x2c\xa7\xd6\xea\x2c\xc9\xa5\xd3\x9b\x47\x95\x77\xaf\xb3\x76\x59\xcb\x1d\xad\xf0\x1b\x3d\x0b\x50\x40\xd9\x0f\x8f\x11\xee\xd7\x2a\x14\xb0\x2d\xd4\x84\xf5\xe9\x43\x87\xa2\xc9\xb2\xfb\xf3\x07\x1e\xd0\x10\x70\xf5\xce\xad\x43\xc5\x60\xc9\x3a\x40\x8b\x9e\x18\x8a\x1e\xc3\xa1\x15\x23\x99\xd9\x3d\xca\xc0\x53\xc1\x4c\x40\xd5\xdb\x5a\xb8\xa5\xea\x32\x45\xfa\x26\xa5\x75\x96\x0e\x96\x5f\x8a\xa7\xda\xa1\xc4\x2b\x2d\x22\x50\x76\xe7\x2a\x38\x6c\x8f\x9c\xac\x14\xdf\xbb\xc8\x3a\xf9\xe5\xd9\xf2\xf9\xef\x8e\x56\x8d\xa7\x0f\x4a\x91\x05\xd9\xb0\x18\x91\x34\x3b\xea\xb0\xff\x2b\x71\xe9\x19\xbb\xcb\x00\xbe\xcc\xdf\x74\x97\xc3\xb8\xfb\xa1\xd0\x57\x3c\x25\x11\xd0\xc5\xe5\x7b\xde\x42\x79\xa3\x3b\x9f\x98\x73\x5e\x29\x92\x34\x8b\xd0\x71\xc3\x16\x48\x10\x95\xde\xb4\xa5\x05\x03\x72\xd4\xb5\xf3\x03\x22\x4c\xa3\x00\xd8\x79\x79\xac\xbd\xe0\x9a\x0f\xc2\xaa\x92\x8f\x55\x33\x25\x78\x88\xa2\x19\x17\xc0\xa6\x8f\x21\x85\x8b\x8a\x7e\xbd\x4d\x28\x28\xc3\x43\xc4\x96\xe4\x0c\x82\x65\xc6\xfd\x26\x00\xcc\x4f\x82\x12\x1a\x18\x74\x12\x64\x66\xb2\xa0\x0a\x33\x60\x5b\x3e\xa7\xd1\x5d\x8e\x2a\x3e\x09\x8f\x14\x3a\x53\x5e\x17\x2f\x3d\xc8\x5c\x95\x67\x2b\xd8\xd7\x84\x22\x52\x34\x54\x95\xf2\xcd\xae\x05\x1f\x08\xb3\xae\xe7\x8d\xab\x09\x1e\xbc\x29\x89\xc1\x8e\x1f\x2d\xc3\xeb\x36\x3d\x71\x9a\x98\x3c\x4a\xa7\xcc\xf0\x93\xfe\x1b\xb5\xd3\x4d\x2d\x78\x6b\x13\x22\x4c\x87\x58\x64\xe4\xa0\xa6\x66\x3a\x7b\x5c\xd8\xcd\xfb\x92\x28\xe9\xb7\xac\x42\x09\x3e\x56\x6f\x78\x95\xfb\xf6\xd7\xd1\xb1\xba\x78\xdd\xdc\x4f\xf4\x8b\xbd\xd4\x55\xb8\xfa\x0e\xfb\xdb\xa1\x41\xe8\xac\xfc\x29\x86\x59\xf9\x91\x6e\xfb\xa5\xe7\x84\x90\x45\xf3\xd0\x6f\x66\x7c\x8a\x25\x41\xfb\x20\xf4\xa0\xee\x5a\x2f\xbf\x95\x4b\x82\xff\x66\xd8\x69\x4f\x1c\x35\x65\xa8\x59\x25\xd4\xd3\x11\x78\x04\x02\x63\xaa\x41\xb6\xe5\x1a\x97\x06\x9f\x16\x6b\xc0\xee\xdb\x7a\xa6\x47\x91\xb3\xc5\xc9\x3f\x33\xc6\xde\xd7\x4f\xcb\x6d\x56\x13\x87\x22\xee\x45\x38\x30\x70\x08\xdd\xce\x4a\xec\x00\x2e\x03\x10\x2d\x1f\xc6\xd0\xe4\x29\x35\x3d\xf6\x6f\x72\xe0\x9d\x8b\xbb\xb6\xec\xb8\xcc\x11\x5b\xc9\xb8\x65\xeb\x97\x92\x44\xf0\x29\x35\x45\x67\x56\x26\xad\x1d\x65\xc9\x86\x19\x14\x31\x62\xfc\x40\xd3\x23\xf9\xba\xd5\x0d\x97\x74\x4c\x1b\xd8\x63\x88\x35\xca\x89\x3e\xc7\x3d\x67\x63\x9e\x87\x91\x7b\x9d\x82\x95\xf2\x69\x8d\x10\x83\xcd\xb4\x4b\x90\xde\x36\x31\x03\x59\x02\xb1\xf5\x5d\xbb\xb2\x95\xcf\xb1\x49\xbf\x1a\xa1\x3a\xc1\x37\x38\x54\xbf\x24\x01\xd8\x33\xe9\xac\xf2\xee\x4e\xea\x55\x3e\xec\x60\x94\x33\xfd\xb7\x31\x59\xc8\xaf\xb9\x0e\x10\x47\x7c\x50\x66\x44\x01\xab\x68\x42\x27\xa0\x99\x6b\x23\x9b\xd5\x5c\x04\x5f\x94\xd2\x07\x46\x18\xaa\xc0\x49\x8a\xcc\xb4\x7a\x09\x3c\xeb\xa8\xda\xad\xe4\x51\x82\x7e\x6b\xf4\xe4\x9f\x04\x47\x57\x69\x6a\x86\x3d\xa9\xe9\xac\xe4\x59\x80\x33\x5c\x0e\x7f\x06\xa9\xe8\xe3\x11\x44\x8e\x79\x2c\x24\xf0\x13\x57\x98\xc3\xd5\x42\x33\x22\xf4\x07\x67\xab\xa2\x80\xcb\x4a\x69\x1f\x0f\x63\x8d\x0a\x84\xe3\x7b\x11\x47\xba\x57\x15\xfd\x95\xf9\x5b\x6a\x16\x53\x5c\x70\x6f\x8d\x03\x38\x19\x9f\xd0\xd0\x3f\x59\xc4\xe3\xbb\x96\x6c\x80\x4b\x11\xe0\x89\x9a\x12\x0a\x34\x9d\x00\x59\x75\xfa\x46\xda\x91\xd1\xa3\xf6\x15\xb2\x8d\x32\x2a\xdb\x3e\x5b\x13\xf3\x11\xc9\x9c\xd7\x41\x45\x97\xa8\x65\x3a\xcd\xe3\x89\x9c\x93\x6f\xf9\x8a\xb2\x7e\x8f\x28\xe0\xce\x29\xa9\x10\x16\xa2\x45\xd7\x95\xcd\x70\xc8\x10\xb9\xc0\xef\x1c\xb1\xdc\x01\xe1\x87\x69\xd8\xd7\x00\x11\xf6\x2d\xdd\xc4\xa1\x16\x0b\x38\x0c\x81\x4e\xb6\x12\xee\x3a\xd7\x1a\x5c\xf4\x7e\x2c\x81\xc5\xf5\xb9\xf4\xa0\xbf\x18\x34\x77\x46\xe6\x1a\x6d\x89\x44\x49\x52\x6d\x33\x37\x65\x3f\xe6\x8a\xb7\x25\x4e\xa9\x29\xfd\x0f\x49\xef\xbf\x72\x06\x47\x45\x93\x1b\x0e\xd0\x3e\x4d\x0f\xd9\xe6\xcd\x70\xda\x82\xed\x64\x7a\xd4\xed\x00\x15\x69\x83\x62\x23\x68\x47\x81\xee\xd4\xc4\xb4\xdf\x06\xb3\x55\x75\x08\x28\x69\xaf\x94\x10\xea\x56\xec\x1b\xba\xb5\x9b\xb0\x90\x97\x45\x72\x1e\x3d\xd4\x6a\x21\x55\xbf\x07\xa6\x07\x8b\xc0\xf2\x1f\xad\x0f\x23\x5e\x6d\x1c\x5c\x74\xbe\x4c\xd9\xca\x03\xda\xcc\x14\x99\xa2\x9b\x89\x02\x5e\x83\x74\x31\x85\xc2\x47\xfb\x5e\x58\x18\xc8\x59\x38\x33\x0b\x56\xb6\x32\xb7\x3e\x7e\xa5\x57\x93\x9d\xac\x55\x02\xde\x89\xa9\x20\x9e\x2f\x15\xc4\x0f\xc9\x2a\x5f\x46\xbc\xae\x7c\x6b\x06\x80\x78\xf4\x41\xca\xc9\xe8\x83\x59\xdc\xd2\xb0\x29\xae\x06\x09\x9e\x6f\xd8\x61\x05\x3c\x54\x43\x5e\x76\x9d\x53\x7f\x82\xf1\xd9\x4b\x36\xbe\xd0\xfb\xbc\xbf\x03\x43\xdb\x01\xad\x50\x7b\xbd\xc2\xee\xbe\xa6\x79\x74\x7d\x6c\xb5\xcd\xf9\x84\x13\xa9\xf8\x81\xc2\x9e\xbe\x66\x9e\xdd\x30\xe5\x98\x97\xf7\x9e\xd1\xf6\x20\x63\x1a\xba\x10\x88\xeb\xd5\x97\x3c\x04\xa3\xcb\xba\x4c\x32\xe4\x15\x59\x6a\xc4\x14\x0a\xe5\xe3\x2a\xe6\x27\x6e\x5b\x25\x64\x4b\xe4\xf3\xa3\x58\x7a\xb4\x69\x74\x0a\x88\x38\xa1\x5f\xc4\xbc\xc3\xf5\x45\xd6\x72\xd2\x24\x8a\xfb\x44\x0f\x83\xfb\x7f\xac\x58\xd0\xc9\xad\x5c\x7c\xc0\xd9\x68\x93\x70\x31\x2e\x1f\x7d\xdf\x4c\x9a\x87\xbb\x26\x1a\x3d\xde\xaa\x87\x5a\x83\x91\x50\x72\x70\x16\x42\xea\xa0\xe7\xe8\xd0\x0e\x57\xc5\x4f\xa4\x61\x8d\x9e\xde\x82\x9b\xb1\x0b\x9e\x69\x9e\x1f\x0d\xf1\x60\x6e\xb7\x45\xcf\x03\x66\x2a\x60\x8a\xa3\x6f\xc8\xc5\xb7\xe6\xed\x73\x35\x27\x75\xa1\x70\x9d\x02\x2f\x5c\x0a\xa5\x9b\x1f\xf2\xcf\x4c\x13\xaf\xd8\x61\x55\xb3\x02\x13\xe1\xf0\xa7\x39\xb0\x23\x33\x62\x45\x5b\xdb\xf4\x16\xbf\x88\x1b\x33\x93\xcc\x83\x88\x95\xf8\x6c\xd7\xa9\x66\xef\xa5\x92\x8d\xaf\x95\xfa\xa5\x18\x31\xdd\x20\x80\x46\x2e\x1e\x05\xd3\x1e\xb5\x6e\xb4\x41\xef\xa3\xab\x6f\x5b\x64\xa7\xeb\x81\x22\x36\xfb\x93\x39\x94\xa3\x4c\xbc\x66\xf4\x17\x29\x19\x96\x38\x72\x1d\xde\x7f\xf6\xdc\x8d\x8e\x77\xb8\xcd\x42\x50\x70\x63\x66\x04\x5e\xbb\xd9\x0a\x5c\xb0\xc8\x9b\x3b", 3419);
*(uint64_t*)0x20000288 = 0xd5b;
	syscall(__NR_writev, r[0], 0x20000280ul, 1ul);
	return 0;
}
