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

#ifndef __NR_memfd_create
#define __NR_memfd_create 319
#endif

uint64_t r[3] = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "\352\347\322\244\317\227\317\246\tt\300T=\313\203\366\251\031#JV\325\265Rs{\354z\242\'\261\322\271t!\367q\317(w-\347b\300\372y\343\244M\242*h$\202\bRe\232\260\374z%\017\006\272\246\004\216\346\244$]\215\220m\317s\253\240|nK\210\034\327\251\324\315\355\351\231\263\027\026\204\321\254\213\006\220", 100);
	res = syscall(__NR_memfd_create, 0x200000c0ul, 0ul);
	if (res != -1)
		r[0] = res;
	syscall(__NR_ftruncate, r[0], 0x2ffffcul);
	res = syscall(__NR_pipe, 0x20000340ul);
	if (res != -1) {
r[1] = *(uint32_t*)0x20000340;
r[2] = *(uint32_t*)0x20000344;
	}
	syscall(__NR_sendfile, r[2], r[0], 0ul, 0x2000007ul);
*(uint64_t*)0x20000300 = 0x20000040;
memset((void*)0x20000040, 29, 1);
*(uint64_t*)0x20000308 = 1;
	syscall(__NR_vmsplice, r[2], 0x20000300ul, 1ul, 0ul);
	syscall(__NR_dup3, r[1], r[2], 0ul);
*(uint64_t*)0x20000200 = 0x20000000;
memcpy((void*)0x20000000, "\x9d\x0d\x8b\x91\x92\xc1\x66\x7f\x0c\x7b\x36\x62\x21\x8f\x8b\x7a\xf9\x5c\x8f\x74\xcc\x68\x3a\x7c\xbc\xe6\x32\xc7\xda\x5b\x97\x17\x3a\xe1\x9e\xe0\x59\x33\xbe\x99\xcf\xef\x24\x67\x70", 45);
*(uint64_t*)0x20000208 = 0x2d;
*(uint64_t*)0x20000210 = 0x20000380;
memcpy((void*)0x20000380, "\x45\xad\xde\xa6\xe1\x92\x43\x1f\x60\x39\x74\x0a\x90\xd8\x15\x58\x6e\x2b\x53\x08\xde\xd5\x2f\xee\x45\x82\xb4\xa3\x10\xc2\x34\x0c\x60\x0e\x26\xcc\xe7\x89\x17\xe3\x6c\xc2\xe7\x9e\x2e\xab\x98\x43\x7d\xd7\x43\xc2\xf3\x04\x45\xb4\x06\x54\x81\xa8\x10\x28\xb1\x7a\x18\x4b\x0d\x7a\x64\xee\xb4\xcc\xb8\x4e\xa0\x0b\x82\x07\x9d\x2d\x4b\xfc\xa2\x18\xa7\xef\xb6\x01\x77\x2a\xbd\x51\x03\x2d\x72\x17\xf7\x79\x6c\x26\xc2\x82\x84\x27\x53\x93\x7b\x5c\xb2\x89\x32\x97\x74\xdd\x89\x26\x54\xe9\x42\x7a\x65\x7d\xb8\xbe\xa9\x58\xa8\x4c\x6e\x82\xf4\x83\xec\xd7\x73\x9c\xbe\xc4\xde\x8f\xe4\x48\x5b\xa7\x1e\x88\x23\xb4\x92\x8c\x6e\x66\xc0\x93\x98\x44\xf9\x4b\xcb\x57\x75\x56\x42\xe4\x54\x86\x48\xd1\x38\x51\x0a\xe5\xc4\x8a\xd9\x06\xd9\x99\x13\x02\xdf\xfd\xe1\x23\x56\x44\xc7\x31\x1e\x94\xd6\x65\x25\xc7\xc6\x6a\xb7\x30\xe7\x28\x76\xd1\x5f\x28\xad\x76\x34\xe4\xb5\xbb\x0e\x9f\x86\x1c\x56\xe9\x1e\x7d\xcf\xe6\x7b\x6a\x37\x2c\x58\xce\xfa\xf6\x8f\x6f\x9f\x0b\x51\x77\x08\xf8\xbe\xac\x4f\x42\xa0\x11\xe7\x0b\xce\xe4\x62\xb4\xf9\xa1\x6a\xf8\x3f\x3e\x6f\xdc\xe3\xb1\x4f\xf4\x58\x06\x87\x4b\x7d\x8a\x3f\x47\x3e\xaa\xc8\xf7\x6b\x92\xc9\xc3\x06\x60\x12\x24\xdb\x5c\xf1\xb8\xb0\x4e\x9a\x88\x37\x5d\xcb\x5d\xe0\x29\xc8\xb1\xaa\xcc\xd6\x2c\x91\x07\xde\xde\x14\x50\x81\xba\xa8\xaa\xd1\x83\xb7\x06\xc3\xa5\x56\xbf\xa3\xf8\x06\x2a\xbf\xa7\x20\x28\x94\x62\xd0\x5d\x12\xb1\xde\x8e\xf7\x2c\xe2\x22\xa4\x0a\xde\x19\x5d\x83\x13\xf6\x61\xad\xfc\xa2\x8d\x43\x0b\xf0\x67\x69\x8b\x04\xba\x20\xdd\x20\x51\x3b\x3f\x0f\x70\x79\xfb\x49\x2a\xf7\xfc\xbd\x8c\x49\x42\x1a\xcd\xb8\x6f\xe2\x52\x18\x78\xa1\x30\x91\x67\xb7\xaa\xcb\x61\xa3\x8a\x32\x92\xa0\x5a\xbc\x6c\xa5\x39\xe1\x6f\xb3\xca\xe0\x25\x7a\xf7\x00\xc3\x50\xcb\x70\x5f\xee\x0a\x84\xa9\x6f\x46\x37\x6a\xce\x4e\xb2\x3e\xfa\x8d\x19\x36\x71\x4c\xed\xd6\xed\xde\x13\x95\x0f\x38\x55\x76\xcf\x37\x9f\xd0\x0e\xe3\xe1\xf0\x89\xb6\x18\x04\xc5\x5b\x88\xaa\x2b\x41\x2a\xc4\xe2\x0c\xd4\xff\xdc\xa7\x03\xc6\x9d\xef\x20\x52\x95\xb3\x4a\x59\x0f\xa7\xde\x93\xf0\xcb\x4f\xa0\xb4\xc7\xa1\x97\x97\x15\xc0\x81\xff\xfa\x5f\x2d\x9b\x55\x3b\xca\xba\x08\x45\x1a\x43\x55\x06\x04\xd6\xa9\x59\x8a\x72\xd8\xc3\x70\x63\x0e\x6a\x85\x91\x75\x4e\x69\xc0\xaa\x63\x10\xbd\xf1\x3d\xfe\x30\xeb\x87\xb9\x58\x14\xe1\xc8\xf6\xe6\x64\x9f\xcb\x40\x60\xba\x79\x96\xc4\x1a\x9d\x7b\x37\x96\xc3\xef\x5d\x1e\x47\xa9\xd4\x2d\xe0\x2f\xf7\xbc\x1d\x81\xd7\x3a\xa3\xc5\x4e\x22\xe2\x27\x8e\x6a\xe9\xcd\x9d\x01\xed\xd6\xde\xda\xa5\x0b\x19\xdb\xdf\xc1\x63\x52\xf4\xc4\x83\x36\xba\x6f\x3d\xda\xc1\xc8\x86\x9c\x21\x38\xbd\xbc\x87\x01\xf1\x86\x11\xfb\xfc\x6e\x5e\xf9\x46\x3e\xbb\xf2\x00\xa2\x92\xc4\x61\xfd\x73\x1c\xd0\x88\x21\x16\x11\x80\x13\xa1\xf9\x0c\x2a\xb9\xfc\x64\x07\x26\xcf\xef\xbc\x63\x23\x95\xad\x6b\xb1\x1f\xe2\x4c\x9b\x5a\x44\x1b\x73\x07\x79\x20\x9e\xcf\x24\x80\x82\x2f\xc5\x86\x7a\x07\x60\x7d\x17\x6c\x02\x07\xb2\x74\x5f\x71\xbe\x61\x28\x20\x51\xe0\xb0\x11\x84\x93\xa3\x98\x0e\x70\x5a\x15\x32\xa7\x11\x6c\xeb\xdf\xa9\x66\xab\x7c\x5a\x35\x38\xcb\x33\x04\x1c\x96\xbc\x83\x05\xe1\x52\x78\xb0\xac\xb9\x65\xf9\xac\x72\x78\x66\xc7\xa5\x2c\xd4\x68\xad\x3d\xd1\xd2\x7d\xc4\x39\x6b\x01\x57\x8c\xe2\x38\xf9\xc0\xec\x63\xee\x8b\x16\xc3\xe4\x4e\xe5\x75\x6c\x8e\x8c\xd4\x9f\xcc\xd0\xf3\x4a\x2f\xa0\x17\xd8\x88\x57\x6b\x96\x2f\x07\x37\x95\x2d\xff\x5c\xf7\x9b\x15\x30\x2b\x61\x94\xf7\xe5\x68\x0f\x5e\x58\x99\xfe\xee\x3d\xca\x9c\xd7\x95\x6d\x80\xf5\xb5\x5f\xdd\x8a\x5f\x12\x2f\x52\xca\xd4\x05\x90\xba\x7f\xcc\xbd\x52\xfa\x4c\x35\xd9\xed\xa3\x0b\x5f\x22\xe9\x22\xaf\x93\x33\x85\x97\x20\x30\xd4\xe1\x0d\xdc\x70\xc9\xba\x90\x29\x99\x63\x1f\x62\x2a\x3f\xed\x91\x3c\x02\x2d\xff\xb1\xdb\xd0\xa3\x85\xce\xe7\xaf\x46\x13\x1a\xae\x40\xb1\x3f\x20\x9a\x33\x59\x3a\xbb\xda\x70\x07\x6d\x9c\xcd\x79\xbe\x56\x68\xdb\x51\x30\x21\x0a\xdc\xbe\xbc\x52\x97\x58\xff\xcf\xd0\x10\xbc\x08\xff\x2d\xfa\xae\x64\x84\x4c\x29\x10\x3c\x0e\x32\x94\x2a\x29\x52\x70\xfe\x95\xac\x84\xfe\xb8\x2c\xa7\x94\x79\x90\x73\x82\x1c\x95\xa3\x88\x08\xd3\x6c\x92\xb6\x2e\x7f\x4e\xdf\xb2\x63\x60\x60\x50\x2a\x0d\xce\xbe\x9b\x94\xcc\xfc\xa4\x58\x4c\x74\xca\xdc\xcd\x31\xc1\xdf\x4d\xad\xeb\x9c\xef\x75\xff\x65\xc0\x20\xef\x16\xa5\x3b\x0f\xe4\x56\xe6\x9b\xd5\xad\x76\x53\x9e\xe1\xbf\xa5\xef\x24\x34\x1d\x9d\xc0\xdc\x01\x6d\xa9\xb2\x38\xc1\x5b\x31\xeb\x37\xbb\x7a\x7d\x25\xfd\x63\xb1\xba\x3b\xc3\x88\x02\x9e\xc5\x29\x16\x9b\x07\x93\x1a\x3e\x84\xf9\xc9\x12\x0e\x84\x9a\xf4\x63\xc0\x3f\x59\x41\x86\xbc\x7d\x22\x05\x2a\x3e\x3c\xfa\xac\x05\xfe\x7e\xab\x2e\xb1\x38\x96\xda\x43\xb6\x28\x5d\x4c\x45\x55\x13\xa4\x2b\xf7\xa9\x45\x12\x4b\xd3\x00\xef\xe7\x1a\x22\xf9\x1c\xb4\x54\x7a\xf3\x30\xf9\x12\x63\xf8\x92\x7c\x39\x06\x0b\x49\x07\x84\x3e\x3f\x67\x9e\x51\xbf\x33\x7b\x3a\x8d\xa9\x21\x11\xa0\x29\x70\xd9\x19\xf6\x5b\x42\xe0\x7a\xd1\xb6\x08\x24\x9a\x27\x0f\x01\x8d\xb1\x73\x5a\x4f\xbb\x58\x30\xf6\x48\x97\xda\x21\x19\xdc\x9a\x7d\xfc\x71\x7b\x73\xea\xb3\x8c\xd3\xe6\x58\xff\xa1\xe3\xe0\x02\x41\xcc\x6d\xd1\xfd\x92\xe7\xda\xd2\x05\xc7\x3f\x64\x0e\x8c\x62\x31\xd3\xb6\xca\xe5\x99\x8f\x4a\xbf\x5d\x32\x20\x20\xf0\xea\x64\x1b\x7a\x82\xf9\x94\x17\x91\x12\xe7\x02\x1a\xab\x4d\xa8\x2f\x22\xe0\xa3\x14\x61\xd3\x7c\x21\xb2\x2f\xe4\xcf\x1c\xa7\x6d\xf6\xb0\x82\x06\x71\x2e\xe3\xf4\x01\xb0\x9b\xb1\xd1\x80\x4a\x5b\x26\x1f\x48\x0d\xbb\x49\x5b\xc1\xae\x17\x5d\x76\x85\x6a\xf9\x2d\xf9\x83\x63\x67\x39\xac\x4f\xa2\x4c\x89\x9f\xc7\x8f\x75\xcd\x1a\x70\x9a\xe9\x7b\x82\xcb\xe8\xcc\xff\x10\xc8\x95\x72\x21\x15\x51\xf6\x2f\x14\x0a\xb0\x08\xbf\x02\xb3\x0f\x74\x73\xbc\xc4\xfd\x16\x2b\x1a\x57\x78\x69\xa1\x92\xd1\xf1\x32\x76\xe3\x1c\xb1\x9d\xb7\xa2\xc1\x51\x32\xd3\xe7\x58\x6c\x83\x0b\x13\x9e\x7d\x22\x2a\xb5\xd9\x27\x8d\x0d\x65\x18\x5a\x97\xd1\x29\x0f\xb8\x4e\xd4\x5c\x86\xb1\x85\xf0\x53\x21\x4a\xe6\x7b\x29\xb2\x7b\xd1\x1b\xd3\xa5\x9c\x3b\x51\x3f\x19\x6c\x3e\xc3\x95\xec\xd5\x63\xa7\x9c\x21\xa1\x07\x79\xaf\x87\xc9\x72\x17\xe4\x98\x0c\x7d\x52\x67\x23\x89\x1a\x4f\x86\xec\x8b\xec\xc3\xa3\xad\x19\x8f\x5e\xc0\xb0\xc7\x64\x98\x74\x13\x28\xcf\x56\xe9\x15\x86\xd2\x0c\x9c\xae\x83\x79\x8c\x85\x38\x04\x11\xd7\x23\xd9\x49\x42\xc7\x4d\x78\x03\x6b\x69\xe7\xa1\x8f\x4d\x79\xf3\x6d\xd6\xe3\xca\x96\x74\x5f\xee\x44\x2c\x19\xd0\x66\x04\x05\x13\x5c\x2c\xc2\x1a\x2e\x4b\xea\x4c\xa3\xdc\x8a\xb2\xba\x45\xfc\x9b\x9f\xfa\x7d\x3c\x25\xad\x42\xbd\x0b\xa3\x8c\x6e\x3e\xc5\xf5\x80\x52\x16\x2d\x37\xe3\x21\xfc\x5f\xff\x36\x1d\xa9\x5a\x98\x35\x51\xdc\x38\xe5\x9b\xcb\xbf\x44\xc3\xe2\x75\x3d\x96\xa1\xc1\x72\x13\xd7\xea\x56\x41\xf3\x2a\x54\x5d\x0c\x59\x45\xa4\x4c\x69\x50\x4d\x4c\xdb\xe3\x1c\x12\xd9\xcd\xce\x64\x2a\x3e\x1e\xb9\xa9\x43\xa4\xde\xe6\x7d\x3a\x80\xe1\x00\xbd\x5f\x10\xac\x3a\xfc\x7b\xeb\x3b\x47\x8f\x0e\xdd\xa1\xb5\x47\x18\x11\xb8\xc9\x28\xf0\x55\x84\x81\xf6\x21\xf7\x1b\x75\x09\x43\xe8\x14\x0c\x26\xd4\x63\x76\x34\x58\x79\x44\x20\x92\xd8\xbd\xcf\x8c\xc0\x72\x8a\x98\xe4\x89\x4f\x4a\x1a\x6a\xbd\x52\x79\x95\x67\x37\x75\x9b\x2d\xe2\x2a\x36\x2f\xb5\x00\x59\xc5\x7f\x4a\x52\x6a\xf8\x68\xd1\xda\x5d\x9b\xb3\x7f\xad\x06\x74\xa1\xc9\x1d\x2f\xe6\xc0\x09\x90\x81\xd5\x5f\xa4\x9a\x91\xb7\xe3\x6c\xe9\xbf\x65\x63\x5e\xb0\x98\xe1\x87\x91\x90\xc7\x7c\x4a\x49\x1a\x0e\x98\x36\x05\x2f\x2a\xbd\x80\x98\xce\x3f\x88\x50\x16\x8b\x78\x9b\x01\xfa\xc8\xb2\x90\x15\x8a\xf8\x41\xb9\xbe\x53\x0d\x63\x31\x26\xab\x11\x46\x16\xf6\x69\xc6\x41\xdf\x67\x92\xb6\x86\xb6\x7c\x7d\x73\x5e\x41\x33\xe4\x7d\xfe\xa3\x8e\x54\xc3\xf8\x0c\x1a\x6d\x68\xf0\xb1\x80\x29\x15\x0a\x44\x6f\x4f\x40\x07\xc2\xed\x24\x14\xc0\x1e\xbd\xf3\x01\x27\x3f\x9a\x2c\x35\xbc\xc9\x08\x08\xa7\x1d\x7e\x2b\x16\x7e\xa1\xf6\x03\x95\x2e\x81\x06\xdd\xed\x96\xd0\x7e\x6e\xd3\x05\x12\x56\x77\xb7\xa6\xee\xd3\x6f\x49\xf3\x61\xad\xaf\x60\x3d\xc5\x08\xb2\x9e\x80\xd1\xab\x14\x69\x2c\x49\x16\x0d\xca\x72\x3c\x31\x7d\xb1\x8e\xdf\x5a\x08\x60\x1b\xc4\xf8\xf7\x90\xea\xd0\x8c\xb8\x13\xbe\x9d\x7b\xb2\xf7\x21\x73\xb9\xeb\xba\xa3\x71\x99\x68\xff\xa9\x0a\x77\x8a\xd9\x40\x45\xfd\x5f\xaf\xdb\x45\x2d\xed\x91\xe9\x86\x65\xfe\xe2\x87\xdb\x8f\x14\x9e\x5a\xfa\x23\x29\xbf\x05\x89\x0a\xdb\xf4\x3a\x98\x44\x0d\x44\x8e\xa8\x1e\xa2\xec\x96\x71\x7c\xc8\x4d\x14\x1a\x6f\x92\x00\x5d\x04\xb1\x80\xed\xcc\x0d\x4d\x29\x42\x85\x3e\x2b\xba\x36\xae\x87\x32\xa7\xf7\xcf\x3e\x04\xba\xe9\x74\x1b\xad\x85\xf4\x68\x38\x16\x81\x1b\x9e\x95\x30\x96\x38\x4b\xb1\xd6\x4b\xfe\x62\x1c\xd3\x20\x7f\xa2\xbc\x54\x4f\x0e\x88\xd7\x5e\x6f\x4f\xb2\xb7\x91\x71\xf1\x40\x87\xc6\x24\x48\xca\x33\x28\x63\xad\x39\x7f\x83\x15\xc7\xcc\xf3\x7e\x79\x29\x64\x95\x0d\xd1\x1f\xf2\xfa\x48\x15\x72\xb6\xb6\x24\x19\xe2\x21\xa1\x40\x74\x8d\x60\x04\xa3\xa2\x8f\x7c\x73\x60\x17\x2a\x9c\x37\x66\xdb\x0d\x96\xc1\x5f\x6a\x0e\xe1\x2a\x7a\xaf\xb0\x37\xde\xeb\x71\xb4\xf2\x8a\x04\xc3\xce\x10\xd3\xfb\x32\x86\x19\x39\x1a\x58\xeb\xac\xb9\xbd\x51\xb5\x33\x02\x69\x61\x34\xd0\x0a\xe9\xee\xdf\xea\xd5\x0d\x80\x82\x14\x55\x2a\xee\x10\x71\x0a\xe9\x7e\x5f\x43\x44\xae\x94\x39\x91\x7d\xe8\xac\x89\xb4\xa0\x96\x6d\xa1\x31\xdc\x2c\xb5\x8f\xd0\x7c\xf5\x33\xdb\x12\x54\xb8\x94\x87\x90\xd6\x11\xe5\x64\xc4\xbc\x5d\xb5\x64\xbd\x2e\x25\xaa\x95\x4a\xac\x8b\xbe\x61\x40\xc6\x5f\xb8\xea\x8f\x3d\x00\x41\x85\xd2\xb9\x7c\x41\x78\x5e\xaa\xa1\x06\x47\x6a\xeb\xa0\x74\x94\xc0\xf8\x80\xd5\x37\x2d\x7f\x8e\x4c\xb8\x95\xd9\x06\xde\x42\x5f\xe7\x84\xde\xfb\xd3\x78\x09\x42\x16\x90\x11\x57\x91\x64\xff\x1e\xac\xe3\xe0\xac\xec\x17\x61\x17\xc1\x8a\x76\x35\x8e\x37\x1e\xd9\xf2\x87\x60\x9c\x85\x5b\xe7\xaa\x2b\x9f\x82\x27\x71\x79\xe0\x8c\x53\x03\xd5\x7f\xfc\x82\xd4\x99\x60\xf3\xcf\xc7\x41\x2a\x0f\x52\x44\xf1\x9e\x47\xfb\x68\xee\x66\xf9\x1a\xe9\x6c\x3d\xbb\x55\xe2\xba\x62\x5d\xaa\x62\xe6\x12\x23\xfb\x70\x30\xcf\x8a\xdc\xcf\xa6\x03\x7e\x33\x6f\x63\xfd\x30\x3a\x76\x7a\xbd\x8a\xc1\x23\x3a\x5e\xbc\xfc\xb0\x2e\xb6\x14\xd3\x68\xd6\xd6\x49\x52\x75\xf5\x07\x23\xe3\x38\x03\xbd\x9b\x10\x12\x1d\xc5\x39\xa1\xfb\x2c\x94\x52\xb2\x63\xc4\x3d\xa0\xf0\x96\xd6\x5e\x0b\xfb\xf1\x36\x33\x31\xa5\xf8\xb5\xf7\xc9\x17\x03\x5c\x47\xdb\x86\x8e\xaa\x98\x1f\x99\x9a\x3e\x51\x78\xcc\xd7\xa2\x73\x04\x63\x6c\x87\x3a\xb9\xbd\x82\xd8\xbe\x71\x6a\x9f\x75\x48\x4e\x5a\x58\xcc\x0e\x72\x73\xf8\xc8\x09\x93\x5b\x96\x81\x1d\x61\x54\x7f\xb8\x6a\xd6\x13\xd4\x6c\x0b\xab\x02\x95\xf3\x89\xac\x5a\x3b\x1e\x9f\x06\xcf\x11\x56\x6a\x61\xe8\x15\xab\xb1\x1b\xcf\x8a\x0b\xea\x9b\xdc\x1f\xb7\xd6\x4a\x45\xa9\xd5\xb0\x84\xf1\x77\x66\x21\xfd\x0c\x47\x5f\x77\x33\x54\xb9\xd5\x64\xd2\xa1\x70\x99\x9e\x44\x12\x71\x42\xc0\x9b\x89\xe1\x6a\xa5\x45\x1b\x0c\x93\xbb\xf1\x19\x04\xf3\x00\x47\xf0\x75\x18\x16\x13\xad\xed\x90\xe1\x5b\xbf\xaf\x1b\xed\x34\x36\x7a\x77\x61\x09\xbd\xed\xd1\xe1\xab\xf4\x21\xe8\x18\x45\x15\x28\x40\xe4\xe2\xb1\xbc\x0f\xaf\x49\xa3\x1f\x35\xc7\x75\x3b\x8f\x3b\x9f\x27\x98\xf8\xf2\x04\x69\xed\x09\x55\x79\xa1\xeb\xcd\x0d\x70\x8c\xde\x54\x7e\x45\x07\xbd\x84\x99\xd1\x04\x94\x93\x68\x86\x28\x50\x08\x89\x24\x3f\x0d\x7f\x3b\x9e\x6d\x82\x05\x22\x5b\x3f\x34\x46\x99\x04\x2c\x86\x78\x14\x24\xbf\xc9\xe2\xe3\xda\x45\x45\x29\xe6\xda\x7b\xaf\xaa\x1a\x7e\x56\x43\xb7\xca\x54\x2c\xe4\x30\x2a\xed\xeb\x7e\x48\xa4\x5c\xae\xda\x11\xac\x39\xa5\x9c\xbc\x68\xe7\x92\x4d\x3a\xaf\x15\x0d\x9e\x68\xa3\x68\x0e\x09\x4f\x12\xf9\x2d\xe7\xa5\xc8\x9e\xad\x52\x6e\x22\xa1\x7d\x61\xba\x02\x4d\xe3\xd0\xd1\x40\x84\xcc\xc4\x3c\x1a\x75\xd0\x9c\x76\x4c\x01\x38\x76\xbc\x8c\x46\xd6\xd6\x6c\xe0\xd2\x9f\xdd\x77\x8c\x45\x10\x2b\x20\x88\xe3\x67\x81\x59\x71\x59\x1f\x95\x2f\x7b\x13\xce\xba\x7e\xd4\x6d\x9d\xa0\x82\xd3\xfa\x4a\x6b\x1d\x26\x23\x53\x93\xd7\x8d\xdc\xc3\x55\xab\x0e\x67\x0e\x8e\xf8\x5a\x31\x46\xaa\x83\xa9\xd6\x2e\x9f\x75\x00\x46\x10\x90\x50\xda\x66\xb9\x1e\x79\x53\x5a\xcb\x52\xb8\x32\x80\xb2\x19\x57\x98\x7f\xa7\x0d\x22\xd3\x1e\x5a\xbd\xf3\x7b\xa0\x66\x18\xd5\x9e\x7d\xe6\x51\xb7\xe2\x21\xa1\x76\x65\xfe\xab\x02\x47\xc2\x24\x10\xa4\x94\x8e\x44\x76\x98\x3e\x0a\x8c\xcc\xa0\x93\x31\x8c\x98\x16\x9e\xe7\x49\x9a\xf6\x6c\xdb\xb8\xad\x58\x84\xa6\x1a\x15\x72\x58\x37\x8f\x1e\x20\x1f\x2d\xec\x3f\xbf\x08\x08\x4f\xc2\x81\x69\xb1\x92\x10\x54\xba\x9b\xef\x57\x9e\x83\x4e\x0e\xfc\x88\xc3\x14\x7f\xcb\x6a\xb3\x6b\xba\x32\xd1\x49\xd3\x5f\x2f\x95\x24\x96\xd0\x92\x65\x7c\xdc\x00\xa6\x9d\xdd\x78\x27\x54\x61\xfa\x78\xc8\x4e\xef\xa7\xdb\xe2\x49\x75\xa9\x69\xdf\x13\x36\x25\x71\x54\x71\x74\x0d\xd2\x0a\x4f\x96\x59\x7d\xe2\x71\x25\xe8\x43\x80\x5d\x9a\xcf\xc1\x90\x8a\x71\xdf\x3d\x8d\x73\xd7\xc7\x86\x84\xcc\xfe\xd5\xd6\x7e\x27\x01\x57\x15\xc0\x32\x4d\xaa\x0c\x33\x67\xf2\xbf\x78\x7c\xce\x22\xd7\x9b\xb7\xe1\xd3\xd3\x20\x96\xba\xca\x21\x03\x00\x1b\x97\xc2\xd2\xec\x6c\xd2\xef\x17\x31\x26\x06\x0e\x27\x5a\x23\x5b\x92\x6c\xb4\x0a\x93\x6e\x71\xae\xeb\xa3\x9b\x4f\x37\x4e\x73\x17\xfa\x69\x25\x7a\x77\x93\x9b\x2a\x3c\x13\xad\x42\x73\xe2\x0b\xf2\x13\x25\x43\x64\x13\x14\x59\x98\xf3\x60\x9b\x64\x0f\x9c\xe1\x9b\x2e\x03\x49\x9a\x76\x97\x2e\xbe\xb9\x36\xdc\xab\x51\xea\xac\xc1\xaa\x4f\x02\xd8\xc8\x1e\x03\x1f\xad\xbd\xc5\x76\xde\x57\x01\x98\x89\xe3\x45\x04\x27\xe3\xbb\xaa\xb0\x4c\x4c\x68\x29\x74\x9b\x32\xdd\x32\xab\x7b\x04\x8b\x10\x71\xce\xb9\xf5\x48\xf9\xbe\x30\x28\x1f\x45\xc8\x71\x79\xe0\xcf\x48\xd9\x73\xf5\x83\x80\xb0\xcc\x3f\x57\x83\x74\xbb\x49\xdc\x83\x08\x9d\xb4\xac\x8f\xf2\xde\x39\x80\x24\x2f\x15\x0d\xd2\xa0\x82\xa7\x0d\xd9\x0f\xff\x57\x2e\x1d\x88\xd5\xfb\x52\x86\x31\x7a\x47\x89\xaa\x86\x97\xe1\x3f\x4f\xf7\x0d\x56\xad\x2b\x75\xb4\x4e\x09\x3d\xd2\x65\x3b\x86\x2e\xfb\x79\xb1\x82\x8c\x0d\xa9\xbc\x19\x5e\x9f\x3d\xb0\x5a\x2f\xdc\x85\x8a\x21\x48\xd5\xb5\x49\x3b\xc2\x21\x68\xb9\x1d\xf0\x6d\x5f\x47\xae\x7f\xf0\xfd\x7d\x44\x0e\xdf\x15\x5e\x31\xda\x37\x21\x53\x70\x08\x1c\xd9\x7d\xfd\xe8\x47\xf0\x86\x70\x8f\x89\x7e\x4c\x18\x5c\xb2\x16\x29\x36\x2b\x75\x54\x7b\xdb\x3e\x2a\x2b\x53\xee\xb4\xef\xf8\xd0\xad\x00\x8e\x56\x88\xf5\x29\x74\xfb\xcf\x74\x6d\x8f\xbb\x1a\x38\x54\x14\xdf\xf5\x16\xee\xdf\x9c\x62\xb2\xcf\x3a\x88\x4a\xb9\x78\xd2\xe6\xc5\x20\xdb\x9f\x59\x69\xc4\x13\xe9\x7f\xcb\x90\xf5\x53\xf4\x4e\x98\x78\x15\x8a\x65\xe8\x3d\x8d\xa4\x7a\x4b\xd4\xbd\xa7\x0c\x16\x6d\x28\xfb\x1c\xb1\xdb\xac\x89\x81\x1a\x21\xed\xbe\x0f\x27\x81\x3d\x76\x4b\xd2\x66\x65\x81\xdf\xeb\xc2\x68\x70\x85\x2c\x83\xb8\x99\x65\x99\x7e\xdf\x6a\x3d\x21\x72\x27\xc8\xab\xd7\x88\xc0\x9e\xed\xd5\x94\x4d\xfe\x29\x05\xcc\xef\x95\xea\x98\x85\x6a\xbc\x3e\xd5\x2c\x9e\x6a\x7d\xfa\x6d\x9b\x5f\xae\xd7\xb5\x03\x4a\x24\xb8\xbd\x59\x84\x6a\xdf\x8c\x34\xda\x79\xa2\x30\xe4\xc6\x33\x27\xbd\x45\xed\x7c\x9e\x55\x00\x36\x03\x0a\x3e\xfc\x54\xc2\x4f\x45\xe6\xcb\x4c\x94\xe1\x3a\x49\xfd\xdb\x6e\x8b\x49\xaf\x64\x2b\x43\x92\xe1\xc8\x44\xab\x71\xfd\x23\x8c\xbf\x56\xb8\xa0\x99\x09\xed\xb2\x88\x20\x04\x6d\x93\x6b\x3c\x19\x4c\x86\x92\xf5\x18\x40\xe4\x6c\xd9\x7e\xeb\xac\xbc\x8d\x86\x86\x3b\x32\x99\x1c\xbf\xf7\xc3\xb4\x60\x46\x5e\xf1\x5a\x66\x83\xc6\xaf\xef\xa1\x89\xd1\xc0\xe8\x33\x85\xc2\xcf\xd1\x5d\x4d\x64\x13\x6e\xd4\x4c\x4f\xbe\xba\x60\x38\x72\x6e\x93\x16\x68\x01\x3c\x82\x53\x40\x6b\x64\x91\x98\x5f\x55\x6c\xf4\xb6\x48\x3b\x8a\xa9\x96\x1a\xc1\xf9\x01\xc7\x88\x9a\xaa\x82\x7d\x02\xaf\x73\x7a\x00\x7e\xde\x0a\x82\xcb\xac\x8d\x16\xc7\x3a\x05\x4b\x04\xa1\x97\x0e\x44\x9c\xcb\xd4\x6e\x2f\x4f\x13\xc1\x20\x00\x97\x6d\xca\x9d\x7e\x48\xd8\xb9\x68\x95\x05\xb8\x79\x4c\xfb\xb5\x0a\xe6\xfc\xa3\x78\x2e\x21\x5f\xa5\x74\x63\x99\x52\xc6\x1c\xac\x79\xf3\x17\xd2\xca\xd8\x85\x82\xc3\xaa\x46\x06\x8b\x09\x39\x63\x6c\xc2\x0c\xb7\x60\xe2\x77\x41\x80\x96\x59\x30\xb9\xbf\x16\x9e\x4a\xa2\x8a\x2a\xb8\x32\x11\x3d\x05\xd8\x4d\x8c\x2d\x6a\xbd\xe5\x3c\x40\x14\x90\xd8\x81\x42\xa3\x17\xcc\x17\xa4\x66\xd3\x38\x4a\x79\x8c\x10\x24\xba\x2b\x4b\x03\xfc\x2c\x7d\xe1\x95\x0e\x57\x45\x2c\x64\x2a\x13\xbd\xf2\x5f\xee\x3c\x15\xee\xbc\xae\xb8\x4e\x2a\xa4\xc8\xb3\x0e\xb1\xcf\x1c\xb2\x35\xf1\x20\xbd\x38\x02\xc0\x5b\xc1\x86\x15\xa1\x44\x4b\x18\xa4\xb5\xaf\x7e\xee\x3b\x37\xf3\x0b\xf8\x32\x35\x67\x13\x1e\x67\x7b\x81\x90\x2a\x15\xa4\xef\x29\x14\x94\x67\x2f\x2d\xcb\xbf\x4d\xdd\xea\x1b\x3a\x53\x4c\xf6\xdc\x41\xdc\x2e\x71\x9b\xfe\xbf\x42\x4b\x59\xd6\x71\x06\x90\x15\x82\xad\x30\xb5\x7e\x22\x1e\x2d\xf0\xb2\x88\x19\xe4\x82\x95\xdd\x9a\x7a\xd4\xcb\xa7\x6c\x65\xe0\xb7\x6d\x32\x01\x1e\xa0\x06\x98\x92\xca\x6e\x88\x1f\x02\x04\x7e\xcb\xf7\x67\x34\xe2\xd5\xc3\x41\x3c\x8e\x81\x27\x43\xcc\xc3\x62\x32\x51\xba\xcd\x3e\xdd\x50\xa1\x17\xa9\xf5\xc1\xe1\xc6\x6c\xf3\xb6\x68\x74\x82\xcd\x59\xcd\x59\x42\x12\xa4\xe9\x82\x5f\x55\x48\x68\xaa\xaa\x5e\xec\x35\x7f\x17\xe7\xf8\x4b\xd2\x5d\xdb\xe6\xb4\x57\x50\x12\xb9\xfd\x3b\x54\x23\x82\x4f\xee\xd2\xab\x49\x45\x05\x5c\xc2\x15\x3d\x3d\x65\x46\x26\xe7\x12\xba\xfb\x7d\x37\xb4\x3a\x4c\x32\x2b\xc4\xe8\x74\x0d\x6b\xe0\x08\xb7\xa3\xa5\x96\x70\xc4\x44\xab\x14\x9d\xf9\x9a\x5c\xff\x38\xd2\xc9\x58\xf7\x4d\x45\x2d\x52\x14\xaf\xd3\xb4\x3d\x80\x82\xe3\xeb\x92\x2a\x8d\x2f\xdf\xac\x88\x49\x86\xc2\x7f\xab\xfa\x84\xe4\xed\x95\x22\xc2\x21\xaa\x10\x7d\xf3\x68\x38\x3b\x45", 4051);
*(uint64_t*)0x20000218 = 0xfd3;
	syscall(__NR_vmsplice, r[2], 0x20000200ul, 2ul, 0ul);
	return 0;
}