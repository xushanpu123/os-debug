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
memcpy((void*)0x20000040, "#! ", 3);
memcpy((void*)0x20000043, "./file0", 7);
*(uint8_t*)0x2000004a = 0xa;
memcpy((void*)0x2000004b, "\xb7\xdb\x41\xd0\x44\x7b\x4a\x4f\xcb\x3a\x26\x31\x35\x25\xf6\x32\x9b\x6a\xbf\x91\x41\x73\x9a\x4f\xfd\x70\x59\x51\xce\x0a\xf4\xb0\x02\xb8\x2f\x22\xea\x7f\x39\xf4\x45\x79\x7b\xad\x49\xc3\x57\xde\xe8\x44\x60\xd0\xbb\x4e\x33\xa6\x60\xcc\x05\xd5\x58\x7a\x3e\xc4\x2b\x6a\x15\x9a\x34\xd7\xfc\x1f\x8e\x69\xfb\xa3\xc1\x61\x4d\x77\x62\xb5\xfc\x28\xcb\x99\xba\xf1\x4f\x52\x4f\x0d\x8a\x79\x20\x83\xf8\xfb\xe5\xff\x38\xa4\x8f\x5d\xaf\x72\xbb\x21\xaa\x7e\xb9\x5e\x75\x7d\xde\xde\x9f\xc1\xac\x82\xca\xf6\x9d\xe4\xde\x6f\xfc\xb2\x92\xb9\x0e\xfc\x25\xff\x3e\x16\x98\x1b\xfd\x2b\x70\x06\x8e\x83\xa1\xab\xae\x99\x5e\x5a\x65\x11\x96\x01\x30\xda\x80\xe3\xad\xd0\xaf\xfe\xaa\x0d\x90\x61\x40\x6c\xb0\x3e\xe6\x10\xc9\x89\x9b\x82\xf4\xee\xb7\xbc\xa6\x8d\x2d\x8e\xc5\x20\x02\xbd\x59\x5c\x84\x8f\x4d\x3f\x68\x18\xf1\x15\x65\x1d\xb1\x6d\x3f\xfa\xa7\x33\xcf\xfa\xf2\x7e\x1b\x55\x17\x59\x89\x67\x07\x2b\x4b\x08\x14\x74\xb7\xb1\x95\xe4\x18\xcf\xad\x8d\xe1\x16\x40\x52\x49\x0a\x0b\xc6\x4f\x19\x53\xa6\xef\x18\x25\x08\xa3\xa0\x78\x2b\xb5\xae\xf2\xe4\xd9\x2f\x08\xec\xb2\x57\x70\x03\x1d\xbf\x14\xa8\x67\x75\x30\x8b\x7f\xa9\xd0\x28\xd8\x71\x4e\x34\x08\x12\x63\x0a\xdd\xd3\xba\x74\xad\x10\xa4\x6e\xe6\x38\xf1\x38\x63\x7e\x39\x6f\x21\xdb\x31\xb0\x97\x7b\x7d\xec\x85\x03\xfd\xb2\xb8\xbf\xe6\xac\x52\xf1\xe4\xaf\x62\x2e\x32\x91\x11\xbb\x07\x27\xa2\xb2\x75\x04\xc6\xc1\xa3\x93\xc0\xd0\x6a\xc2\x4a\x2a\x2f\x56\x2d\x72\x21\x78\x02\xda\x73\x5a\x4d\xf1\x35\xf1\x0c\xe8\xcb\x31\x7f\xee\x81\x6c\xfe\x2f\x0b\xd2\x5f\x40\x48\x2d\x0c\x91\xe2\x2a\x21\x15\xbb\x33\xbb\x28\xac\x2c\x61\x29\x5a\xa1\x89\xc8\x1f\xa8\xa6\xac\x68\x65\x27\x51\xac\xb7\x02\xbd\x78\x00\x20\xef\x06\xa4\xc8\x72\x15\xe2\x00\x49\xd7\xb4\xba\x69\x9d\x65\x4f\x8c\xb0\xf2\xf5\x25\xb0\x5b\x63\x0a\x41\x1b\x5e\xbc\x71\x9d\x7f\x87\x99\xf4\x02\x9c\x67\xda\x4c\x19\x68\x29\x7c\x21\x3a\x15\xc4\x1e\x93\xe9\x0f\xb6\x1b\x17\x0b\xb8\xb3\x0a\x55\x59\x83\x6d\x86\x6f\x6f\xd8\x7a\xea\xde\x12\x31\x05\x94\x94\xec\x73\x65\xe4\x30\x7c\xa6\xf0\x33\xe9\x81\x7e\x67\x9a\x79\xb1\xee\x18\xe8\xff\x35\x3d\xa4\x99\xac\x0d\x15\x7a\x6d\xb6\xce\x0f\x0e\xc8\x43\x47\xab\xcb\xfd\x66\xea\x85\xf6\x58\x9c\x83\xcf\xb5\xd3\x60\x7d\x3c\x06\x2a\xaa\x33\xbe\xdf\x63\x8a\xa4\xc4\xc7\x1c\x63\x1e\xbb\x31\x28\x9a\x5f\xeb\x32\x71\x33\xfa\x21\x5b\xe6\x1a\xc2\xd1\x76\xff\xf1\x0f\xb5\x6e\xaf\x80\xb2\xe8\x38\x55\x14\xe4\x53\x66\x1a\xf3\xde\x86\x21\x1f\xde\x74\x59\x1a\x52\x67\x79\x76\x32\x76\xbe\x10\xb9\xf0\xf6\x53\x4f\x36\xb3\xd9\x04\x62\x67\x5a\xe6\x77\xac\xac\x92\x8f\xa6\x79\xa5\xf8\xad\x48\xa9\x38\xff\x6a\x8c\xe8\x5b\xf5\x82\x4d\x5b\x65\x80\x7c\x5f\xda\xbe\xcd\x3a\xff\x82\x61\xf9\x77\x50\xf6\x11\x1b\x1e\x66\x8f\x37\xe0\x04\xec\x03\x0a\x4a\x6d\xbb\x72\x44\x16\x52\x4e\x06\x78\x6e\x3b\x7f\xcb\xeb\x7c\x2d\x28\x8e\x9a\x55\xc7\x02\xc4\x56\xdc\x10\x85\xc2\xaa\x25\x2b\x1d\x1e\x99\x8e\x1a\x25\x6b\xe4\x45\x78\xff\x69\xee\x84\x61\x9f\x57\xb8\x57\x9d\xb8\x2c\x28\x51\xb1\x0f\x23\xfc\xf7\x98\x22\x88\xf2\x9f\x19\xf3\x63\xdf\x40\x6b\xd9\xad\xb9\xfc\xea\x27\xaf\xbc\xe8\x13\x92\x69\xac\x6e\xae\xef\x13\x06\xdb\x3e\xa2\x0c\x22\x17\x8e\x1e\x13\x7e\x8f\xd6\x0b\x01\xca\xea\xb2\x59\xe7\x7e\x27\x82\x9d\x16\x93\x0c\xc5\x9f\xe4\x05\x5c\x4b\xfc\x8b\x36\x3f\x6a\x92\x02\xb6\xfa\x03\x51\x59\x2a\xf5\xb0\xa5\xf9\x16\xf6\xe0\x53\x44\x21\x9f\xe5\x54\xf7\x3f\x10\x50\x6f\x4c\xa3\x84\x4c\xf7\x96\x17\x56\x9c\xd7\x86\x40\xf3\xe8\x52\x3a\x9d\x7e\x03\x35\xd0\x9d\xcc\x58\xb6\x8f\xce\x9e\x9d\x97\x85\xef\xd3\xfb\xf2\x43\x1b\x64\xfd\xa7\x0d\x0a\x0c\x03\x8f\xc4\xbf\x57\xa0\x0e\xc8\x45\x4c\x52\xa6\x3b\x62\x71\x68\x29\xf4\x14\x13\x64\xdf\x1b\x4e\x35\xee\xe7\x04\xb6\x9f\x85\x1d\xe1\xc4\xae\x8c\x08\x03\x8a\x1b\x64\xac\xad\x7a\x30\x57\x41\x2d\x73\x85\xbf\xe3\xba\xec\x80\xb5\xef\x7d\xd1\x7b\xff\x4e\x7e\x7b\x4d\xa9\xc9\xdb\x05\x12\xe1\x28\xc5\xb4\x4f\x32\x3d\xdb\x7f\x77\x79\x6c\xb8\x05\xc4\x0b\x3f\x2f\xde\x13\x8b\xbc\xe6\xf0\x73\xb8\xca\xab\xf5\x75\xe5\xce\xdf\xea\xf8\x1c\xf8\x16\x61\x0e\x2b\x81\x59\x4c\xa5\x59\x65\xb1\x77\x2f\x74\xc0\xe3\xa2\xe8\x84\xc5\xe8\x80\xe2\x4d\x3e\x0c\xe4\xca\x4b\xa8\x23\xf9\x4b\xe3\x94\x29\xe1\x13\x0b\x85\xec\xd4\x3f\xd4\x0a\xa9\xa1\x29\x6d\x34\xe8\x33\x82\x6f\x50\x37\x21\x04\xf5\x07\x25\x15\x56\xc7\x8b\xb5\xf4\x6e\x9f\x2e\x81\xcc\x31\xb2\x25\x4e\xbd\x9b\x03\xdd\xe4\xf3\x3b\x96\x1b\xa6\xb9\xa1\x80\x6d\x37\x98\x15\xf4\x60\xbb\x8c\xcd\x18\x7a\x19\x97\x3b\x68\xe1\x10\xc8\xb0\xb1\xc9\x00\x35\xad\xc8\x8e\x26\x55\xc3\xd0\xba\xfb\x2f\x82\x7e\xa9\x18\xe0\xe3\x09\x7c\x3a\xcc\x53\x2d\x30\x27\xd1\xd4\xb8\x04\x19\x7d\xe7\xbe\xb6\xb5\x57\xeb\xcc\x72\x37\x49\xa4\x9a\x6a\x40\xb2\xc0\x53\x2a\x2c\x41\xee\xb9\xd5\x09\x6a\x7a\x49\xb6\xb0\x3c\x92\x98\xfa\x20\xb2\x24\x77\x69\x9b\x12\x5c\xb2\xf4\x77\xee\x83\xdf\x16\x52\x52\x05\xc0\xe8\xc8\x1f\x7c\xcc\xf6\x20\xbf\x03\x25\xe6\x01\x7f\x6f\x7e\xf1\x30\x48\x51\xe3\xe2\x34\x40\x96\xa3\x24\xd6\xca\xd4\xd1\x38\x95\xf3\x2c\x05\x9c\x6d\x88\x3e\x34\x1f\x65\x49\xa1\x3c\xe7\xc5\xf0\x4e\x95\x6f\x6d\xcd\xbc\xef\xb8\x9d\x10\xa2\x97\x39\xf9\x03\x68\x93\x82\x02\x5e\x44\x50\xee\x22\x2d\x78\x18\xea\x62\xa9\xe0\x71\x56\x90\x78\xdd\xbf\xcc\x22\xb8\x3f\x6f\x44\x69\x74\x42\x45\x9c\x60\xd5\xbc\xf9\x9c\x01\xb4\xce\x44\xc5\xcf\x38\xac\x2e\x43\xb9\x9e\x06\x6d\xf8\x65\x5a\x8c\x65\x43\x7a\x53\xd6\x94\x1e\x57\x95\xc3\x83\x88\x4a\x72\x14\x8d\xfd\x14\x7b\xc9\xd0\x3a\x81\xe4\xaa\x4e\x82\x89\xc5\x9a\x65\x11\xaa\xb1\x8f\x3c\x41\xfc\xa3\x34\x9d\x4b\xd8\x4e\x47\xcf\x0a\x52\x8f\x90\x33\x8f\xae\x16\xe9\xad\x2c\xe6\x0c\xde\xf8\xd7\xa6\x42\x8e\xca\xc4\x9a\xd9\x78\xbd\x1e\xc0\x5a\xf8\xd2\xc4\x71\xbf\xce\x01\x0b\xc0\x20\xb6\x3b\xf8\x72\x28\x90\xb9\x5c\x2a\x39\x32\xf1\xbc\x86\x12\xec\x98\xa4\x6a\x5b\xcc\x48\x64\xb0\x6b\x57\x3d\xa6\xf0\x97\xf5\x77\xf1\x2b\xe5\x2c\xe3\x3b\xf2\x0b\x2f\x34\x5f\x2a\xee\xaf\xc6\x33\x72\xeb\x3f\x41\x52\x09\xcb\x60\xdb\x22\xad\x22\x41\x1a\x72\xd0\xd7\xad\x69\xa8\xa1\x97\x6f\x08\x13\x65\x1e\x30\xbd\x3e\x06\x5b\xb6\x9f\x4b\xc7\x35\x80\xfe\xe7\xee\x7a\x67\x24\x13\x92\x95\x68\xf2\x2e\xd1\x78\x45\x9f\xff\x2f\x94\x61\x2d\xdf\xde\x43\xe8\xab\x95\xf3\xe2\x22\x28\x61\xb6\xbe\x63\x81\xe1\x20\xce\xd3\xec\x45\x90\x7e\x3d\xb0\xa2\xee\xb0\x64\xc7\x0d\xd0\x59\xf2\xac\x49\xdc\xc5\x97\xdd\xd9\x38\xb3\x83\x03\xfe\x9d\xa3\x87\x0e\x39\xf5\x5e\xc1\x3a\xef\x42\x93\x1a\xdb\x23\x65\xc3\x77\x07\xc7\xb0\x6c\x8a\x84\x87\xde\x6b\x1f\x38\x15\x7f\xd9\xb1\x6b\x1e\x98\xa5\x72\x58\x66\x61\x50\x05\x47\x09\x7b\x4d\x34\x3f\xe7\xfa\x5b\xdd\xff\x74\xe5\xc8\x51\xe3\xf2\xd5\xd0\xdb\xd5\x6b\xf3\xca\xc3\x21\xe0\x03\xfc\x25\x9f\x8b\xb9\x62\x33\x59\x31\x95\x0d\x17\x37\x5a\xdc\xdc\xb2\xa7\x62\xcc\x41\x55\xc8\x1f\xe9\x7e\xc4\x7b\x81\x62\xd4\x6d\x3c\x03\xe6\xf2\x06\xf3\xdc\x68\x23\xfb\x93\xc4\xc4\x09\x31\xd6\x76\x7d\xc7\xad\x66\x97\x30\xe8\xdd\xf6\x6a\xe4\x17\x0b\x43\xad\xf0\x75\x89\x5e\x96\x62\x64\x0a\x6a\x0d\xd7\xab\xdd\x88\xad\xe9\xd8\xad\xb7\xb3\x45\x5e\x55\x8a\x46\x98\x15\x70\xf2\x9f\x60\x8f\x33\xa8\x99\x07\xcf\x78\x5e\x8e\x31\x95\x1d\xdd\xa4\xbf\xc4\x8b\xb0\xbb\xb6\xe6\xe3\x6e\xea\x9c\x38\x3a\x36\xf2\xe9\xc2\x58\x83\x43\x75\x55\x01\x1f\x20\x4d\x71\x1f\x38\x1e\x02\x8f\x53\x44\x56\xbb\x1c\x5a\x12\x67\xfe\x75\x09\x99\x0e\xab\xe3\x90\x1b\xd6\x80\xa6\xb5\xa6\x06\x99\x91\xfd\xc9\x1b\x16\x76\x59\x0e\x51\xb3\x03\x97\xe2\x83\xfe\x99\x6b\x0d\x2d\x30\xbd\x2e\x8f\x5c\x17\x92\x4b\x5b\x34\x16\xcf\x09\x80\x05\x67\xe5\x33\xdd\x39\x2a\x32\x0f\xbf\x33\x93\x72\x85\x35\xbf\x20\x77\x90\xed\x01\xac\x26\x2d\xf9\x0d\xc6\x6b\x4d\xcf\xb9\xb4\xa8\x83\x4d\x96\xa0\x23\xbb\xa8\x47\x0a\x91\x60\x65\xb9\x98\xca\x0b\xda\x91\x84\x2d\x0a\x28\xd4\xf5\xe9\xd7\x8e\xa9\xc2\x39\x83\x4e\xad\x9b\xa2\x8d\xac\x0a\x32\x65\x4a\x77\x3f\x6a\x3b\xeb\x8f\x1e\x2d\xf5\x33\x4a\xdc\x5b\xfd\x2a\x14\x88\xe1\xeb\x1b\x6b\x48\xc3\xc0\x84\x43\x0b\x29\xbe\xfb\xb6\xab\x02\x5a\x5a\x7b\xb5\x8a\x7c\x27\xdb\x37\x88\x90\xd8\x3f\xd2\x01\x11\xf8\x62\x71\xfc\xe8\x20\xf6\x82\x43\x08\x14\x96\xa6\x47\x84\xaa\x93\xaa\x26\xa9\x6f\xb1\xab\xda\x74\x5f\x67\x3b\x10\x18\x5b\x00\xc1\x5b\xe4\x99\x51\x3c\x4e\x61\xec\xda\xa4\x3a\xb7\x39\x3a\x08\xf1\xc6\x59\x61\xc8\x4a\x22\x00\xf1\x64\x1f\xe8\x64\xdf\x7a\xc7\xa9\x2d\xdf\x76\x9c\xca\x15\xd6\x6b\x2b\xf3\x79\xfc\xae\xf0\x28\xad\xd0\x22\x4a\x83\xd0\xb9\xc8\x5d\xde\x0e\x99\x85\xcb\x36\x82\xa1\x49\x3e\x4e\x5a\x09\xa4\x3d\xf8\x39\x9a\x92\x56\x4e\x49\x6c\xe5\xf7\xf8\x10\x65\xf2\xd8\xec\xc9\x38\xb7\x74\x81\x21\x8a\xb0\x01\x8b\x25\x95\x09\x73\x20\x92\x4f\xee\xec\xce\x63\x72\x49\xea\xa7\xfc\x4b\x4f\x08\x68\xf4\xe1\x4d\x57\xf0\xcc\xc0\x9a\x01\xee\x04\x0b\xb8\x24\x35\xef\xb4\xd9\xbd\xcd\xdf\xf0\x0f\xd8\x8f\x01\xa9\x8d\x75\x31\x70\x73\x0c\x05\x2f\xb6\x6e\xf7\xa8\xed\xd8\x88\xcf\x11\x08\xa8\x49\x2e\xd3\xe8\x61\xde\x20\xb6\x71\xb1\xba\x80\xb5\x68\xe1\x76\xbd\x86\x4c\x4a\x3e\x29\x9c\xe5\x00\x91\x27\x84\x67\x81\xfe\x56\xc6\xb2\x83\xf0\x6c\x3a\x11\x8c\xc8\x88\xae\x9c\x67\x4c\x0b\x54\x81\xc7\x9d\x71\xf0\x62\xa3\xcf\x31\x53\x1d\x0d\x53\x5f\xa2\x84\x31\xd8\xb0\x66\xc2\x32\xe4\x6e\xd8\xb4\xb8\xca\x62\xdb\x55\x47\xcc\xc4\xf5\x61\x75\x0e\xcb\x36\x77\xaa\x44\xaa\x49\x1e\x64\x88\xdc\xc8\xe2\x41\xe8\x8c\x97\xc1\x18\xed\xcb\x02\x62\x8e\x9d\x39\x61\x70\x26\xcc\x25\x68\x5b\x07\x0f\x24\x76\x3d\xee\xe3\xcd\x4c\x3e\x30\x6d\x1e\x93\xb5\x28\x28\x1a\x3a\x56\xf8\x8e\x57\x93\x76\xa7\x84\xa8\x0b\x40\x4f\x42\xfe\xbc\xa9\x9e\x66\xb1\x0b\x67\x85\xae\x8e\x3b\xc6\xa0\x08\xbb\x97\x46\x6f\xa4\xe3\x39\x54\x8e\x9c\xa4\xe4\x4f\x3c\x53\x69\x2c\x39\xf3\xe6\x82\xf1\x05\xec\xc7\x70\x6f\xf4\x23\x6e\x0a\xa6\xdc\x76\x38\x0d\xd2\x46\x67\xe7\x6e\x94\x80\xa6\xac\x5a\xc9\x42\xd8\xae\x27\xe7\xb5\xbe\x40\xa8\x1b\x6b\x9d\x7a\x88\x2c\x00\x4f\xe7\x44\x11\x16\x56\x1e\x48\x17\x73\xb7\x9a\x3e\x89\xc3\x84\xa1\x5d\xfb\xc6\x8f\x7e\x45\xa7\xb0\x27\x07\x2e\x3a\x8f\x22\x7b\x88\xc5\xc0\xab\xab\x84\xbb\x0c\xcd\xaa\x73\xb5\x76\x5f\x90\x16\xf1\x3b\x37\x49\xbc\x0c\xef\x96\x84\x72\x62\x7b\x24\x6c\x7f\x28\x78\x54\xce\xf4\xc0\xc4\xba\xf7\xec\xb7\xbe\x76\x3e\x43\x71\xf1\x18\x61\x3e\x85\xd5\x4f\x19\xe9\x37\x06\xc0\xfc\x04\x15\x33\x12\x13\x1d\x4b\x16\x3b\xe5\x7e\x72\x0d\xf8\x6c\x90\x0b\x6a\x35\x94\xcc\x5a\xb9\x64\xc1\x8c\x47\x73\x25\x15\xd8\x95\x7a\x5f\x98\xef\x21\x19\xfe\x9b\xc1\x21\x83\x14\x84\x0a\xf3\xa7\x09\xbd\x15\x8b\xc4\xe8\x94\xeb\x2c\x76\xac\xee\x7e\xf9\xe5\xfc\x22\xf5\x6a\xd8\x4f\x26\x56\xbe\xba\x26\xd0\x97\x6a\x98\x58\xc9\x65\x0b\xa5\xa6\x24\x8e\x68\xfb\x1b\x4b\x4e\x5a\x00\x53\x7b\x96\x9d\x06\xec\x14\x55\xe6\xe9\x46\x41\x53\x32\x10\xd8\xb4\xd6\x36\x59\x68\xb0\x26\x07\x43\xcc\xb0\xa1\x6f\x65\x3e\x1d\xee\xdf\xd9\xf2\x46\x3c\x17\xf8\xa3\xe3\x73\x2e\xee\x73\xb8\x5e\x4e\x8f\xba\x91\xf4\x15\xd2\x29\x8f\x41\x56\xb3\xd4\x7c\x73\x46\x5e\x0a\x5f\x95\x7c\x17\x86\xbd\xbb\xd4\x5d\x17\x10\x63\x8f\x62\xf2\x9f\x3c\x56\x43\xe5\x0a\x0e\xe8\x6c\x10\x47\x99\xf8\x67\x87\x66\xce\xc0\x3f\x7c\x82\xfd\x1e\x34\xb4\x49\x0f\xfc\x63\x3c\x9f\xc0\x8c\xf9\x06\x26\x59\x5b\x32\xfc\x46\xe2\x36\x5b\x85\x46\x31\x63\xb4\xe6\xd6\x09\xaf\x7f\x03\xc0\x9e\xaa\x93\xa6\xb4\xec\xe2\xd4\x7b\xcb\x6f\x06\xb9\xd7\x18\x44\x14\x69\xf6\xae\xc9\xc6\xaf\x11\xed\xad\x2b\x18\x00\x3f\xd1\x09\x70\x16\x15\xd7\xf8\xa6\x5e\x68\x77\x34\x08\x0a\x44\xea\x80\x0b\xc6\x39\xef\xc3\xb4\x8f\x7a\xb5\x41\x9b\x63\xf4\xcc\x13\xb4\x83\xcb\x6a\x1f\x42\x41\xb0\x55\x9b\xd2\x5e\xe1\xc5\x9d\xc2\x8b\x07\x19\x90\xc2\x46\x89\x05\x12\xda\xd1\xa5\x2a\xf9\x2a\x4f\x9c\x50\xb0\x1c\x99\xc8\xde\xf9\xf9\xd2\x7a\xad\x9a\x94\xe5\xcc\x7b\x1e\x58\xaa\xdb\xc7\x7a\x30\x3a\xef\xc9\x30\x79\xcc\xce\xd7\x8b\x93\x66\x1c\xb4\xe5\xad\x2a\xaf\x47\x20\x40\x8c\xff\x7b\xfa\xe0\x8b\x5d\x93\x8a\xeb\x9d\x51\x74\x61\x90\x9f\x18\x9a\x50\x3c\xbd\xc9\x5c\xba\x7c\xa4\xd1\xf3\xdb\x57\x50\x50\x00\xbf\x6c\xa5\x72\xff\xb2\x08\xe9\x6b\xdc\x56\x85\xab\x8d\xc0\x28\xaf\x88\xcb\xfb\x52\xaa\x7c\xac\xab\x63\xd4\x06\xbd\x05\x8e\x07\xa1\xbc\x67\xc9\xbc\x77\x7d\xfc\x7d\xc1\x6e\xf6\xe8\xa0\x2e\x77\x1d\xe3\xed\xc6\xa6\x2f\xdb\xb4\x2b\xd2\x4c\xf6\x24\x0a\xb3\x10\x7c\xcf\xeb\x29\x58\x28\x9a\xcb\x01\x01\x50\x03\x10\x2f\x80\x1d\x74\x30\x00\x37\xa8\x35\x54\xb5\x7c\xc3\x6d\xb4\xc6\xe4\x5a\x93\x31\xd2\xf1\x57\xb2\xe7\x86\x60\x52\xe7\x5c\x08\x4e\x71\xf5\x53\x9b\x06\x09\xbe\x5c\x55\x2b\xc0\x14\xf7\xe1\x3a\x67\xab\x2c\x36\xee\x9c\xa1\x9d\xcc\xcf\x00\x95\x5a\x7e\xa9\xce\x65\x96\xb1\xc3\x2b\x85\xcd\xaf\x41\xb6\x72\xbe\xaa\xd0\x82\x3a\xed\x6a\xb8\xfb\xf4\x0b\xbe\x4e\xec\xcd\x87\x76\x0e\xd9\xc5\x22\xb8\x17\xf7\xcb\x61\xed\x15\x16\x5a\xfb\xda\x55\x7d\x3e\x75\xbc\xd0\x51\x10\xe9\x9c\xeb\x43\xb1\xdb\xd5\x86\x6b\xb2\xb1\x15\x00\xb9\xcf\x7f\xc2\xcd\xa6\xf9\xea\xc7\x35\x93\x8f\x5a\x39\x87\x29\xa6\x80\xd5\x9a\xaf\x61\x9b\x32\x44", 3047);
	syscall(__NR_write, r[0], 0x20000040ul, 0xbf2ul);
	return 0;
}
