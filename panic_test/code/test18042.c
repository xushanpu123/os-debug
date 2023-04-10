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
res = syz_open_dev(0xc, 4, 0x14);
	if (res != -1)
		r[0] = res;
memcpy((void*)0x20001380, "\xa3\xc1\x42\xaf\xe4\xc2\x97\xa7\x93\x62\x65\x12\x3e\x76\x9a\x00\x92\xab\x3a\x90\xf4\x58\x42\x71\x43\x30\xff\x2a\x1e\xb8\x68\xa2\x47\x79\xfc\x44\xec\x3f\x21\x2d\x82\x73\x5e\xe0\x63\x21\x70\xac\xc2\xe5\x52\x00\xef\xd8\x4f\x60\xd1\x11\x55\x3f\x6d\x3a\x40\xca\xfe\xb4\x21\x0b\x76\x3c\xf6\xd2\x01\x32\x6d\xe0\x73\x89\x2a\x2a\xc6\xf7\x19\xc7\xa7\xf6\x9d\x7b\x5a\x36\xd5\xef\xa8\x53\x01\xde\xf7\x2a\x41\x3c\x3b\x76\x68\x68\xf5\x5c\x47\xa0\xc6\xee\x77\x17\x9f\x6c\x2b\x0b\xdd\x07\x46\x60\xb2\xcc\xc6\x9e\xc9\xae\x27\x54\x7a\xeb\xbe\x79\x26\x93\x51\x89\x2a\xfd\xd1\x5d\x44\x2d\xc2\x8c\xd6\x7c\x28\x5e\xd4\x69\x27\xb4\x98\x83\x2a\x9c\x9a\x89\x35\xea\x3e\x6a\x84\xeb\x4a\x2e\x80\x8d\x32\xfe\x3d\x2d\x03\x0d\x6c\xd5\xbe\x03\x40\x25\x39\x81\x7e\x92\xd3\xa3\xf8\xf7\xa1\x9b\xdd\x10\xea\x72\x0e\x7a\xca\xe3\xa6\x08\xe2\xf7\x16\xb0\x46\x28\x51\x51\xe1\xaf\xba\x57\xb5\x1e\x0b\x05\xa8\xfb\x25\xb1\xc2\xa7\x48\xaa\xd1\xbe\x1c\x88\x92\x09\x2b\xb8\x70\xb5\x86\x5f\x02\x68\x26\x18\x94\xc4\xa3\x22\x9e\x27\xa7\x52\x93\x83\xd7\x42\xb2\x79\x68\x38\x8c\xa5\xf0\x14\xea\x04\x07\x87\x21\x64\x6e\x9b\x42\x27\xcf\xcd\x55\x53\xe3\x70\xee\xdc\x1f\x05\x6f\xae\x33\x2a\x39\x5b\xaa\x02\x13\x83\xc0\x01\x9a\xab\x73\xe9\xd7\x04\xae\x23\x6d\x2e\xdf\x51\x86\xa4\x81\x14\xf4\x55\x57\x62\x35\xd0\x3b\x8d\x18\x7a\x45\x77\xf4\xc4\x31\x87\xf9\x69\xc0\x35\x30\xa5\x08\x68\x65\xac\x72\x09\x3c\x5a\x3e\x54\x78\xa7\xbf\xb7\x0c\x03\xc9\x07\x30\x6e\x39\x9b\x12\x47\x3f\x11\x4d\xd2\xef\xfb\xeb\x4a\x83\x18\x41\x73\xf3\xf1\x2e\x45\x97\x40\x63\xc0\x14\xe0\x39\x3a\x94\x1c\xe1\x86\xc0\xcd\x3e\xdb\x5f\x64\xf6\x85\x95\xa3\xfe\x7f\x1b\xc7\xcb\x9a\x20\x70\x21\xff\xc9\x6d\x75\x7d\x8a\x00\x06\x43\x14\x07\x75\x17\x01\xf7\x32\x4d\xac\xf6\x40\x60\x17\x94\x71\x6b\x14\x25\x27\xbc\xba\x55\x4c\xe3\x79\x52\x0e\x70\xfd\xc3\x3d\xe7\xbf\x42\x3f\x8b\x56\xce\x0f\x14\xe1\xd7\xd4\xf3\xbc\x3a\xc7\x16\x5e\x65\xaf\x26\x0b\x7a\x1c\x0d\xa9\x7c\xcc\x3f\x4f\xf2\xc8\x98\xb3\x87\x6c\x44\xe2\x93\x45\x0e\x9b\x5c\x57\x79\x40\x18\x05\x83\xcd\x9a\xf9\xdb\xa5\x14\x27\xb5\xef\xcb\x9e\xa5\xe8\x71\x3d\xe7\x05\x1b\xeb\xce\xc7\x0b\x2a\xfb\x67\x0f\x77\x98\x65\x41\xec\x15\xb3\x8b\xd0\xdd\x2c\xb2\xd1\xa9\x4b\x25\xa5\x1d\x01\xda\x54\xb9\xe8\x76\x0e\x12\x2e\xa1\x3b\x88\x93\xf3\x43\x59\xa9\xb9\x12\xa1\xf7\x67\xfe\x5d\x83\x04\x80\x5d\xc1\x10\x1a\xc4\x4f\x38\xa8\xdf\x37\xc0\x85\xb2\x68\x24\x73\xdd\xf6\x63\xc4\x88\xae\x5f\x17\x4f\x1e\xda\xd5\x0e\x63\x92\xe8\x0a\x31\x5f\xdc\x7c\x95\x26\x87\x1d\x17\xea\x1c\x61\x1d\x16\xca\x7f\x0a\x23\x16\x0f\x4e\x52\x19\x71\x15\x07\x7e\xca\x6f\xcb\x47\x4c\xd7\x33\x6a\x8f\x44\x33\x2b\xeb\x74\xa2\xd1\xa9\x16\x3b\x6a\x2a\x89\x83\x80\x84\xed\x97\x54\x97\x1a\xf8\x3d\x51\x32\x82\xb2\x90\xdc\x4e\x3c\x45\xe5\x67\xb4\x53\xbf\x89\x02\x0c\x64\x1f\x24\x43\x0b\x40\xa9\x6b\x50\x8b\x32\x74\x24\x88\x91\xa0\x42\xc8\xee\x4b\x15\x54\xec\xdd\xdb\x72\xca\x46\x5b\xbc\x79\x28\x9a\xb1\x7f\x8e\x1f\xb5\xc8\x77\xd9\xf3\x20\x84\x88\x85\x30\xb6\xa3\xf5\x3b\x3a\x20\xbf\xde\x1a\x54\x6f\x07\x8d\xb4\x28\x14\xd7\x7b\x85\x65\xdb\x87\xcf\x0f\x1d\xc9\x79\xf0\x99\xf5\xf8\xb5\x2f\xd1\xb9\x10\x6e\x6d\x6f\xc5\x7f\x2d\xd8\x9c\x2f\x20\x68\x23\x2f\xc5\xe4\x7e\xac\xa0\x39\xfa\x1e\x33\x1b\x70\x7a\x14\x08\x28\x57\xa3\x86\x0f\x6b\x20\xa0\x91\xf5\x2b\x38\xe5\xe5\x0c\x54\x27\xad\xee\x17\x25\xe0\x24\x15\x08\x4c\x26\xe3\xd1\x6b\x69\x2f\x9e\x60\x63\x10\x50\xf6\xdf\x49\x11\x4f\x5f\x51\xb4\x38\x52\xb9\x0e\x46\x08\x54\xc2\x9d\xe6\x54\x1a\x45\x7d\xc0\xed\x2e\x3e\x3a\x29\xac\xca\xfd\xe9\x16\x00\x95\x8b\x6c\xda\x42\xe2\xef\x91\xd1\x53\x3d\x47\xf0\x38\xd9\x1f\x1c\x64\xe4\x04\xb6\x8a\xf5\xb9\x5a\x11\xeb\x2f\x72\x69\xad\xef\xf9\xff\x35\x14\xbe\x01\x4c\x9b\x4f\x63\x28\xcd\x82\x4f\x07\x4d\x71\xdf\xdd\x79\x1b\x38\xd9\x0e\xe2\xd0\xb0\xfa\x9d\xe0\xeb\x3f\x7e\xd9\xd8\xe6\x22\x68\x90\x25\x33\x73\x83\xc9\x26\x47\xe3\x18\xd5\xb8\xfd\x7a\x16\x0d\xbc\xbc\x24\x36\x74\x15\xa1\x79\x63\x97\x83\xe7\x68\x23\x5c\x8f\xfc\x7b\x54\xf6\xca\x3c\x55\x10\x2d\x5d\x63\x26\xdc\xd8\xc7\xbc\x4e\x5f\x9c\x30\x6c\x19\xc8\xf7\x17\xcf\x82\x75\xdd\x57\x12\x2d\xb5\xa1\x6a\x0b\xf1\x84\xe1\xd1\x9a\x9f\x16\x44\x74\xbe\x52\xef\x23\x55\x80\xc2\x34\x47\x9d\x85\x2f\x48\xfc\x4d\x9a\x1d\xd0\xbd\x05\xa1\x6b\x10\xb7\x26\x03\x07\xbc\x64\xad\xcf\xdd\x13\x9f\x44\xb0\x55\x47\x24\xde\x85\x12\xc7\xf8\xfe\xaf\xaa\xf7\xe2\x71\x03\x2f\xbd\x54\x94\x7f\x26\xb2\x9a\xf1\x42\xf4\x94\x4d\x2f\xf2\x4f\x43\x4a\xbb\x7b\x32\x27\x0b\x25\xcf\x5c\xf0\x55\x58\x3f\xee\x7b\x85\xf2\xd6\x73\x80\xf4\xa9\x1f\xec\x52\x36\xc2\x51\x67\x64\xd5\x82\xd2\x4b\x94\xb4\x5a\x30\x0a\xb1\x68\x84\xfa\x03\xb7\xba\xa7\xf3\x4a\x29\x08\xf1\xb8\xf5\xf9\x50\x26\x77\x2d\xf1\xad\xc7\x58\x96\x7a\x62\xae\x80\xf0\x18\x99\x84\xff\xc4\x39\x65\xbe\x58\x70\x73\x6b\xc8\x6c\x40\x8c\x6b\xfa\xfd\xa1\x32\x52\xa9\xef\x27\x5f\xf8\xb3\x9a\xad\xe6\x2d\x4e\xdf\x11\x18\x68\x36\x2f\x15\x21\xfb\x6f\x9a\x94\x94\x39\xd4\x6e\x7a\xd6\x4f\x03\x07\x88\x37\xfe\x71\x87\x6a\xfa\x42\xd7\x15\xb2\x31\x79\x43\xf5\x52\x4d\x23\x02\x34\x24\xa7\xd8\x86\x53\x8b\xdf\x20\x84\x86\xad\x92\x35\xbb\x3c\xce\xa5\x03\xf9\x1f\x65\x95\x84\xa1\xe7\x61\xc7\xf2\x6a\x10\x04\xb2\x31\xf0\x30\x45\x46\xa8\x84\xf3\x80\x9a\x4f\x07\x63\x74\xab\xaa\x47\xad\xde\xbc\x3d\x74\x36\x72\xae\xe9\xdb\x5b\x2a\xdc\x73\xa6\xaf\xac\x57\x8c\x27\x53\x6c\xe0\x90\x6f\xf1\x68\x9e\x26\x50\x44\xe1\x8d\x32\x0c\x52\x80\x14\x4f\x1c\x10\x50\x8b\xab\x4f\xdd\xe5\x9f\x6c\xce\x70\xbe\x8f\x05\xa0\xe6\xad\xc7\x26\x83\xeb\x03\xf5\x8b\xb4\xee\x0b\x37\x75\x61\xed\xba\xb1\x21\x0f\xe8\xbc\x37\x7f\x03\x6b\x5e\x93\xf7\xb8\x8c\xe6\xac\x9e\x6c\x0d\x1f\xd1\x2f\x88\x71\x7d\xa8\x05\x44\x3a\x04\x17\x8c\x5b\x17\xb5\xef\x2a\x03\x94\xf5\xea\xf6\x7b\x5a\x98\xd8\xdc\xaa\xeb\x63\xa3\x2e\x1e\x27\x35\xbc\xfc\x73\x81\xac\x77\xc7\x60\x19\xf1\xb7\x6c\x58\x2a\x92\xac\x64\xeb\xa1\x10\x9d\x97\x16\xf9\xbd\x9a\x07\x11\x5f\x49\x8f\xc3\xd9\xa3\x0a\x28\xd0\x51\xdd\x61\xda\x46\xb2\x81\xb1\xfb\xa4\x5f\xb1\xb2\xc2\xe0\xb6\x3b\xef\xeb\xc5\x65\x32\xad\xb4\xef\x03\x50\x3a\xaa\xc3\x41\x5f\x36\xbe\x84\x7b\x6c\xda\x70\xe1\xcb\x19\xee\x03\x58\xbd\x38\x89\xc7\x4e\x8b\x50\x95\xa8\xd9\x56\x04\xae\xf7\xed\x7e\xb8\xc4\xb5\xc5\xf4\x8d\x0f\x7e\x86\xe3\xa6\xf3\xbd\x89\x69\xf4\x66\x22\xed\xe7\xe5\x8b\xef\x59\x40\xa5\x6c\x86\x48\xdd\xc1\x13\xc1\xe0\x40\xe4\x88\x6f\x32\xfe\x74\x28\xee\x85\xdc\x3b\xcf\x7b\x21\x61\x85\x64\xbc\x1a\x8b\x83\xa2\xd9\xd6\x41\xe9\x30\x63\xd3\xe2\xcc\xa2\xc8\xcd\xcf\x78\x14\x56\x5a\x8c\xfb\xb5\x4c\xc0\x35\x83\xfd\x49\xa8\x90\x42\xac\x7f\x37\x2d\x64\x72\x0c\x2c\x45\x3c\x9c\x3b\x8a\x87\x86\x1c\x6f\x69\x23\xa4\x7e\x96\x18\xb8\x96\xf6\xc0\xe0\x8f\x19\x47\xfc\x8c\xd0\xf6\x96\xce\x3b\xab\x5a\xd4\x83\x2e\x93\xdb\x94\x3d\xbb\x2e\xa9\xec\x06\x2a\xef\x8e\x34\x2a\xdd\x8e\x5f\x2b\x48\x41\xc1\x7b\x3a\x2b\xf4\xc9\x8e\x6f\xb4\xe9\x3d\x0f\xd4\x00\x6d\x5f\xd1\xdb\x5a\x96\x5b\x86\x9f\x21\x56\xf3\x10\x90\xf2\xa7\x5f\x12\xb9\xa3\x0e\x85\x04\x9c\x4b\x79\xd6\xf7\x20\x67\xd4\x38\xa8\xbc\xe5\x55\xad\xf0\x60\x50\x4e\xc5\x15\xb6\xb0\x16\x8b\x1d\x7a\x71\xc9\xb3\x10\x08\x04\xe9\x16\xd0\x26\x31\xfd\x47\x77\x3b\xe6\x45\xa1\x54\x4a\x60\x35\x64\x6f\x97\xf7\x9a\x63\xb3\xb5\xf9\x55\x2f\x0f\xaa\xf2\x9a\xcb\x1d\xa9\x23\xaf\x68\x66\x07\x3e\x29\xa1\x60\xd2\x8a\x15\xcf\x0e\x97\xae\x75\x21\x63\xb6\xeb\xf9\x50\x20\xc0\xf2\x2e\x42\xd1\x2f\xd2\xcd\x53\xb6\x3d\x03\xa2\x4d\x4f\x3b\xc7\xf6\xa4\x57\x90\x70\xbb\x8d\x81\xb7\x78\x55\xa8\xfb\xb5\xae\x5e\x5e\xbe\x36\x06\xfd\x5f\xec\xf7\x63\xa5\xca\xbd\xf8\x77\x37\x96\x35\x5e\x80\xd6\xf0\xfc\xd8\x75\x0d\xd7\x3b\x5a\x36\x57\x82\xe8\x52\x56\x25\xa6\x8c\x16\xc8\xc9\x5a\x50\xb9\x54\xe8\x93\xcd\x4a\x77\xa3\x73\x72\xa1\x3d\x68\x24\x3d\x1d\x75\x82\xe3\xe3\x0e\x7b\x07\xb7\xbf\x70\x86\x19\x29\x40\x60\x66\x75\xb2\xfe\x54\xc5\x8b\xf5\xe5\x68\x2c\x20\x72\x41\xe1\x5b\x07\x2c\x10\x55\xe6\x47\x75\xce\x2b\x20\x12\x8a\x2c\x7a\x33\x6f\xc1\x5d\xe9\xe0\xdf\x40\x97\x5d\xd2\xcc\xc5\xd7\x44\xa7\x74\x0f\x20\xb8\xad\xcd\x64\x05\x0d\x46\x7e\xa3\x81\x19\x46\x89\x95\xad\x0b\xe2\x1b\xc7\x67\x08\x4d\xcc\x6a\xc5\x1e\x6e\xc1\xd3\xcb\x7c\x42\x56\xb3\x5e\x8c\xc4\x8e\x69\x84\xc1\xbb\x0f\x31\x80\xd6\x37\x93\x5e\xb5\x5b\xc5\x22\x91\xfd\x25\xcb\xc6\xf8\x2e\xed\xab\xc5\x11\x28\x78\xa2\x0f\x14\xc3\xf0\x8d\xb8\xed\x8e\x54\x8c\xa4\x53\xf3\x0d\xe5\x60\x2c\xc1\xb6\x49\x01\x62\x5f\xf2\xf5\xb0\x56\x88\x9b\x0a\x76\xa4\xd6\x3f\x9b\x1e\x6d\x92\x27\x2e\x58\x27\x72\x4f\xc4\x6d\xde\xbc\x4b\x2d\x81\x9a\x38\xe1\xc4\x82\x2a\x76\x2c\x04\x69\x00\xe4\x58\x88\x3f\x27\x8d\x5c\xd7\x05\x44\x5f\xbf\xde\xbb\x62\x3c\x97\x07\x31\x74\x33\xd9\xca\x98\xa6\xe8\xc8\x79\xda\xfb\xbb\x63\x03\x46\xbf\xc6\xc3\xe7\xcb\x06\x59\x2c\xf4\xaa\xd0\x63\x8c\x90\x00\x0f\xfc\x4c\x0f\xf8\xd0\xdc\x09\x4c\x80\xd4\x52\x33\x4f\xb6\xdc\x41\xcf\x78\x59\x39\xd1\xe4\x19\xde\x27\x85\x46\xe6\x51\xdf\x56\xc2\xc7\x6b\x7e\xad\x06\x2b\xe7\x5e\x0c\xf5\x65\x10\xdb\x87\xd7\x37\x62\x10\xe0\x17\x79\x88\x41\x02\x62\x5b\x71\x44\x2e\xea\xf8\xb2\x1e\xb4\x17\xed\xe2\x82\x7b\x9e\x85\xe1\xc7\xf4\xa5\x44\x5a\x32\x89\x6f\x82\x43\xdd\x09\xf9\x2a\x49\x50\xd3\xba\x4b\xbd\xf4\x37\x55\xeb\x21\x7d\xaf\xa2\x48\xff\xaf\x5e\x42\x2c\xa3\xcb\xc2\xaa\xe1\xae\x05\xda\x9d\x60\x5b\xec\xa9\x6d\x2d\xa0\x00\x70\xe9\x8f\xf3\xc9\x80\xbd\x12\x70\xc8\xe5\xfe\xbf\xb4\x01\x14\x21\xbd\xe0\xa3\x06\xe3\x0c\x38\x51\xbf\x90\x87\x9e\xa1\x95\x03\x20\xfd\x78\x0f\x6e\xe5\x9e\x4a\x23\x14\x74\x2d\x76\xe2\x98\x63\x83\xff\x8d\xc0\x3e\x7a\x59\x58\x86\x66\xfb\x3e\x6e\x86\x4d\xa8\x02\xde\xae\x4c\x92\x25\xf0\xcb\x5d\xf2\x77\x7c\x1d\x3c\x28\xff\xdb\xf9\xfc\x36\xbc\xf7\x35\xab\x41\xe5\xae\x99\xfb\x9d\x5e\x01\xb1\x77\x20\x3e\xcd\xe1\x7c\xd7\xbc\x0d\x6a\xb3\xf7\xb6\x78\x1f\x16\xf1\x90\x5d\x61\x84\xde\xcc\x64\x63\xc4\x91\xeb\x28\x43\x61\xc2\xa2\x2c\xe8\x20\x99\x4e\xfc\x9a\x15\xf1\xdb\x69\xcc\x34\x19\x77\x89\x50\x30\xbd\x3e\x3e\x3b\xa1\x0c\xdb\x1a\xd3\x8b\x8f\x37\xf1\x04\x2c\x7d\x97\x6f\xfd\x91\x61\x54\xd4\x6c\xa9\x3d\xbe\x3b\xf9\xda\x0c\x71\x26\xca\x3c\xe4\x0c\x28\x46\x4b\x03\x58\x0b\xdb\x98\x7f\x4e\x6f\xf9\x46\x3e\x97\x4f\x78\x3e\xdb\xd7\x68\x48\x80\x89\x20\x50\x35\x07\x06\x6e\x13\x89\x0f\x91\x67\x4f\x3c\x17\xad\xf9\x2c\xed\xff\xd3\xe7\x26\xb7\x4f\xab\x36\x92\x6e\x8e\xf1\x30\xcd\xa1\xd7\x46\xd0\xf3\xd8\x3d\x1f\x28\x61\x28\xf0\xbe\xa8\xa1\x55\xc9\x17\x70\x6d\xa4\xea\x42\xc9\x81\xce\x2e\x8a\xc8\x34\xcc\x10\xc6\xd0\xd6\x68\x98\xac\xdd\x24\xfb\xf4\x60\x32\x2f\x76\x5e\xfe\x02\x9d\x20\x3a\x64\xb6\xd8\xfe\x28\x04\x37\xfc\xad\xc2\x4d\xb0\xee\x61\x7e\x1d\xb5\x64\x41\xcc\x3d\x5a\xfd\xc2\x23\xee\x7a\x7f\x4b\x67\x95\x0d\x0b\xe4\x1f\x77\xf4\x28\xce\x09\xea\xc8\xa3\x5c\x60\x6a\x73\xda\xfc\xa9\xb2\x86\x6c\x24\xf8\x53\x54\xd0\x87\xb4\x36\xbe\x1e\xc7\xba\x1d\x00\x72\x3a\x14\x9b\x44\xc1\xae\x87\x7a\x53\x86\x34\x01\xbe\x6f\x34\xc5\x4a\x61\xf6\x58\x4a\xaa\x85\x05\x76\x1d\x51\x13\xab\x85\x40\x2b\x57\x59\x74\xe7\x73\xc4\x4e\xd7\x66\x78\x6c\x83\x3e\x06\xe1\x23\xc8\x6d\x19\x4e\xb8\x90\xa2\xf8\x33\xd5\x7e\xb2\x57\x77\x1f\x00\x24\x37\x52\x47\xd8\xf5\x8f\x1b\x4a\x8c\x6c\xa4\x24\xcb\xd5\x97\xa5\xb4\x93\x4a\x65\x9f\xfa\xd2\x00\x0c\x80\xa4\x00\x95\xd5\x8a\xf4\xf1\xc0\x25\xfe\x14\x6e\xde\xde\x3f\x14\x33\xe0\x11\x45\xf1\x7c\x6d\xe9\xac\x3b\xf5\xd9\x80\x99\x1d\x9c\x45\xff\xd6\x4a\x1c\xd6\x8f\x66\xb9\x82\x8b\xce\x8a\x3b\xfc\x66\x58\x0d\xb8\x0a\xd0\x2e\xd3\xbb\xd8\x54\xdf\xd0\x86\x90\x69\x43\xc4\x7d\xf9\x04\x24\x7e\x34\x56\x8e\x01\x9a\x2f\x78\x8d\x2c\x28\x51\x84\x1d\x72\x84\xcc\xe3\x29\xa0\xcf\xf7\x1e\xc5\xc3\xe5\x84\xee\x55\x7b\x2e\x58\xc2\x81\xd5\x27\x26\xd4\xbb\xb9\x30\x8b\x0d\xa3\x7e\x41\xc0\xd1\x28\x72\x55\x0b\xb6\xf8\x7f\x41\xe8\x44\x4d\xa0\x9b\x64\x06\x8a\xcb\xed\xb9\x3f\xee\xc7\xb9\x3c\x29\x2d\x16\x9b\xe7\xa8\x45\x7a\x64\x9d\x96\xfc\xa9\xeb\x39\x8d\xeb\x53\x34\xf4\x97\x0e\x1a\x7a\x6c\x6b\xe4\xac\x54\x68\xf1\x44\x95\xda\xc4\x02\xd4\xf2\x6e\xc0\x02\xc1\xb2\x3d\xda\xc4\xcf\x84\xf3\x63\xf5\x1a\xa0\x09\x92\x49\x39\x77\xd7\xd9\xf0\xad\x2e\x85\x92\x36\x5c\xcb\x6d\x03\x0c\xa7\x26\x96\xc7\xfa\x34\x1c\xc6\x2c\x86\xb3\x0b\x92\x74\x09\x63\xd4\x9b\x45", 2901);
	syscall(__NR_write, r[0], 0x20001380ul, 0x1705ul);
	return 0;
}