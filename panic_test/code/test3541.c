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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
memcpy((void*)0x200000c0, "\245\000\n#:I\316\345\022\031\024\336\201\316(\201\367k\b\003\201\034\377*t\305\032^\343F)i\244\240\307U\211\270\212\003\307(\345\317LaM\231e\320\211/\250\213/q\177\n\331\331\354*jiCdr\310\324\037M\213\371fl\337\266\316\314\246\340\313\\\361\272\344\226G\222b\005G\247\326P\300\036\363p\313\330\317\341\242?p\371\257>M\017?C\373\266\341\024\367\267\377v\262f\236\0374=M\266Z\242\231\363\251\203xR\016>9\313\032\226\032\310+\340\344G\207>\2159\250\b\r\025\233\215z_\204w\232\206 \207cq\345\344\372\004\003\020=\347H\335%\343\272\222\364\346,\310G\302\227\300\231h\235B\374Z\263\270\307\343\307.\220\213\215ES`\222*\370r\3431\351@\266\246,Q\005x<\242\373~=\334\206p\266\340\252\265C\372A\207\021\204\005\031\241\235\'\006\323\364\n\344\267_fz\264\036\363\002\264Ft-\020M\333\233\224o\206\364\331Qy!\376\372W#\005j \344\201)\367|\017\252\336\224]\334_*\2277\023eET\250\345\315\347\225W\037p-\257\235\r\226@\200x\n\272H\210 \025.\374#{z\307T\242\274\263\266\035\204\271\345\037_\304\376\034\323A.\222\022Rv\222!\313=Ap\234\240\220\327\232l9\223\236\223SuH\235\n\022\307\3233\3275\357\332\210\266\341\236\370x\a\314\226\224\332\v\333Iwa\314\r\314\371oUF\237\324T\023e\317\301\313\a\376\315\035\310\360\236\307N\226h\177\200\227\b\333l\3474I\244\305\275\217\'\227^\002G0\276\333D\261\240\034L:Z\360\241e\v\306\255\274\024\322qT\324O\253Jm\263\372\356\377B\016\310F{\rh\276\240\a\023v\250\000\311\034\256\340\312J\243\340\213w\232\270b~\210\374 E\261]\262\035\001\221\000\317\273nB7\367\3127*\3314\220\301\277\225\207=\270\307P)\035\372\336\200M\267\277\227O\367\220\340@\334\237\333\244\237u\322\241", 550);
	res = syscall(__NR_memfd_create, 0x200000c0ul, 3ul);
	if (res != -1)
		r[0] = res;
*(uint64_t*)0x200025c0 = 0;
*(uint64_t*)0x200025c8 = 0;
*(uint64_t*)0x200025d0 = 0x200003c0;
memcpy((void*)0x200003c0, "\x3f\x37\x5f\xff\xa6\x4d\x26\x79\xcf\x99\x2a\x44\xd7\x07\x91\xdd\xc0\x71\x1e\x79\x3e\x96\x03\xd6\x8d\x6b\xe0\xad\x2d\x23\x37\xb2\xe6\x0b\x4f\xfb\xcd\xdd\x68\x78\x1b\xc4\x01\x46\x20\x58\x2b\x5c\x27\x50\x20\xb0\xf1\x0a\x8f\x87\x10\x6c\x26\x1f\xba\xa6\xfd\xdd\xec\x71\x84\x31\x9a\xcd\x7a\xff\x1c\x62\xa6\xdb\x1c\x98\xac\x27\x3c\x5e\x63\xfc\xf0\x75\xb3\xde\xdd\x0a\xd9\x27\xe6\x3e\x1d\x78\xc0\xb0\x6c\x97\x2d\xf5\x36\xd8\xc7\x0b\x4e\x67\x48\xb1\xeb\x38\x98\x5f\x63\xb7\x6f\x31\x8b\x57\x3f\xa5\x00\xa1\xd2\x62\x66\xf2\xf6\x47\x09\x3f\x70\x70\x54\x8d\xca\xed\x58\x21\xdd\xfe\xf9\x80\xcc\x1d\xa1\x50\x14\xfb\x0f\xc0\x29\x1e\x0b\x4b\xdc\x33\x93\x25\xf5\x87\xfe\x35\xdb\x14\x00\xf4\xf0\xc2\xe2\xfb\x6b\xbe\x4c\xcd\x43\xf8\x6a\xe3\xf8\x51\xe6\x5e\x7c\x92\x3c\x01\x2b\x37\xe4\x75\xb3\xcc\x7a\x69\xd4\x79\xe9\x2e\xf8\xfa\x7f\xbd\x31\x9f\x3e\xdd\x8a\x3f\x64\x6b\x34\x2b\x5a\x30\xb4\x7f\xf8\xa7\xf0\x88\xf0\x48\xe4\x6c\xf6\x1e\x43\x1d\x31\x63\x13\x74\x1d\x18\x99\x4c\x27\x31\x3c\xa2\x3d\x6e\x9b\x7e\x96\x37\xcf\x46\x4d\x56\x00\xb1\x3e\x23\xad\xb0\x80\xf9\x8f\xac\x7d\xea\xd8\xf2\x9c\x39\x89\xc5\x59\x98\x47\xda\x5a\xc1\xe9\x71\x5b\xfd\x4b\x25\x28\x28\xd0\x2d\xc5\xd4\x59\x56\xc0\x36\x9b\x48\x41\x72\x23\xb0\xf9\xf2\x1e\x8d\x7d\x01\x7a\xe6\x4f\xf9\x8c\x6e\xa0\x08\xb9\x10\x91\x2f\xc1\x27\x9c\xaa\xd6\xd9\xcd\x44\x0d\x35\x2b\x3e\x91\x95\x7c\xdd\xd4\x2e\x15\xb6\xad\x89\x0a\x12\x50\xde\xdd\x8f\xf9\x17\xf1\x36\x91\x68\xd5\x11\xd6\xd6\x5d\x06\x04\x59\x51\xd9\xc7\x73\xfc\x3c\x33\xf8\x86\x12\x30\xbc\x0a\xe1\xff\xde\xe2\xed\x5c\x09\xfc\xcf\x8e\x7e\x0f\xc8\x70\x1d\x9e\x4f\x2d\xac\x5d\x72\x47\x41\xd0\x1d\xb2\xf2\xc2\x91\xfe\xe3\xf8\x55\xf4\xa4\x84\xf8\x95\xbe\x59\xe4\x5e\xa7\x76\xa3\x2f\x65\xb9\x13\x43\x21\x52\x65\x79\x5a\xc4\xfc\x59\xcc\xeb\x98\x7a\x97\xc3\x84\x60\x1d\x84\x39\xf1\x3d\x51\x3c\x22\xf3\xc7\x51\x49\x0a\x91\x7c\x0a\x0b\x77\x36\x8d\x44\x2a\x05\x81\x38\x00\x57\x33\x94\x37\x66\x4d\x94\x4f\x4b\x4c\x3c\xdd\xe8\xd6\xc3\x5e\xed\x58\xc1\x2a\x2f\x5e\x09\xa0\x3d\xc0\x47\x96\x62\xf8\x2c\x6a\x93\x13\xf3\x29\x38\x4a\x3f\xb3\xb1\xfe\x98\xf0\xae\x37\xa6\x8c\xf6\x29\x51\xbe\x13\xd6\x16\x79\xfa\x64\x86\xb2\x39\x80\x17\xa3\x60\x97\x84\xe2\x15\x4d\x75\x0c\x09\x9c\x45\x66\x5d\xb4\x80\x8a\xfb\x2f\xb8\x58\xf4\x4b\xf4\x6c\x12\x75\xfb\x06\xf2\xa2\xdb\xdf\x47\x57\x96\xfc\x84\x09\x9f\x07\x9c\x53\x70\xdf\x53\x06\xfb\x06\xee\x7a\x2e\x18\xb4\xc6\x20\x76\xc5\xa5\x18\x74\x03\xf1\x14\xa0\x24\x62\xd6\xb5\xcb\x67\x68\x96\xac\x96\xb2\x71\x05\xa9\x18\xa3\x55\xed\x0d\x88\xb1\x5f\x76\x57\xad\x29\x24\x5c\xc8\x3e\x23\x46\x96\x83\xf4\x4f\x9b\x9d\x08\x2f\xde\x45\xa8\x21\x2a\x5f\x6a\xab\x6d\x1d\x7f\xb7\xd7\xbf\x67\x56\xfe\xb2\x5d\x4f\x1c\x28\xb9\xdb\x37\x19\x90\xce\x8f\x59\xbd\x33\x6d\xdf\x6e\x61\x8a\xc3\xb0\xd0\xae\x03\x82\x15\x93\x22\x6e\xa3\xa1\x5b\x3b\x99\x76\x7d\x0a\xce\xb2\x01\x92\x61\xa9\x89\xf7\x00\x2f\x70\x52\x81\xaa\x3a\x77\x44\xac\x48\xe7\x2e\xf0\x7a\x97\xf5\x4c\x44\x3f\xa5\x9a\xee\x0d\x2b\x60\xb1\xac\xc1\x01\xad\x96\x63\xb6\xdb\x8e\xe5\xfc\x68\xe8\x2a\xf7\x9e\x3c\xd4\xa7\xd7\xa2\x21\x1a\x38\xa5\x5d\xba\xe6\xd0\x44\x2b\x0b\xfa\x12\x3f\x2b\x6e\xc9\xc9\x5c\xcb\x93\x72\x95\x8c\x51\x60\x1a\x11\x28\x05\x4c\x4a\x34\xa3\x74\xe0\x93\x5c\x6d\x83\x73\xcf\xef\x93\x34\xb6\x64\xbc\x74\xf5\x8c\xa1\x87\xde\x71\x65\x8d\x56\x2c\x11\xee\xb7\x8f\x36\xa3\x05\x04\x1b\x02\x98\xfc\xf2\x5d\x14\x3a\x94\x24\x8d\x20\xa6\x24\x20\x92\x6e\xa3\xf7\x7a\x93\x23\xc4\xb4\x4e\xb5\x3f\xa1\x3b\x03\x1b\x11\x71\x88\x78\xa0\x2d\x2d\x42\x91\xb8\x9c\xb3\x33\x5d\x58\x46\x0b\xf3\x6e\x74\xb5\x2f\x38\x4d\xd5\xe3\xcf\x45\x78\xe5\x52\x6f\x9f\x33\xec\xfa\xca\x03\xb1\xea\x2f\x47\xcf\x72\x23\xbb\x74\xa3\xd2\x52\x4c\x2c\xf5\x04\xf7\x9f\xed\x44\x2b\xeb\xe3\xde\x7a\x53\x8f\x3e\x9b\x3f\xb7\xdd\x6c\x25\x53\x6c\x78\x44\x45\x5f\x70\x10\x0e\x43\x8c\x10\x43\xc4\x64\xb2\x10\xe6\xd5\xdb\xc4\x85\xfb\xc4\x02\x5c\x4b\x35\xb9\xd8\x66\x7d\x37\x0e\x94\x66\x72\x00\xfe\x9d\xb9\x4c\x72\x2b\xde\x52\x1c\xa4\x88\x5f\x99\x66\x03\xda\xd1\xc8\xa3\x6c\x8f\xb5\xa2\xc0\x89\x75\x69\x52\xc9\x2e\xcf\x5c\x84\x51\x56\x40\x0f\x34\x19\xfd\xd6\x9b\x7e\x4f\xfc\xef\xae\x0a\x08\xaa\xf7\xac\xab\x98\xef\x2a\x79\x28\xdb\x97\x91\xc8\x4c\x5c\x9b\xb6\xd8\x92\x89\xbb\x61\x5d\x74\x73\x90\xc4\x0d\x56\x61\x7d\xd4\x42\x23\x21\xc7\xed\x3e\x81\x25\xcc\xf7\xde\x96\x89\x22\xd1\x83\x25\xe1\xc6\x1d\xb6\x50\x34\xd4\xbd\xda\x81\x10\x3e\xc2\xdb\xf2\x01\x39\xb6\xa6\x09\x16\x72\xbc\xc0\xeb\x63\x78\x3b\x4b\xde\x81\xf0\x41\xe2\x03\xd8\x5b\x5b\xe0\xb6\xd6\x65\xc3\x82\x96\xc1\xe3\xe4\x68\x28\xd0\x9b\x23\xe5\x26\x37\xb7\xdd\x86\xff\x7f\x54\xed\x02\xb3\x01\x20\xbf\x1f\x2c\x24\x56\x94\x50\xcc\x72\xc9\xac\x57\xbd\xcc\xbd\x2c\xef\x8c\x58\x90\xcf\xd2\xb7\xf9\x1c\xba\x85\xef\xee\xb5\x05\x90\xa0\x7b\x55\xfe\xe0\xa2\x88\x3c\x1a\x66\x90\xcd\xe9\x9e\xd9\x44\xef\x08\xd5\x4b\x4f\x36\xe9\xc8\x35\x8b\xeb\x7b\xce\xc4\x6e\x91\xa1\x3b\xbd\xcc\xe7\x54\x6b\x21\x3f\x65\xbc\x25\x15\x29\x82\x47\x7e\x25\xe4\xe9\xc7\x88\xc5\xb2\x3c\x43\x5b\x31\x92\x77\x74\x61\xf4\x4d\x5c\x2e\x54\x8b\xc0\xbf\xf3\xdc\xca\xae\x28\xc1\x15\x15\xb1\x4e\x24\xe9\x9f\x98\xd8\xfa\x36\x6e\x33\xb8\x16\x70\xc4\x97\xef\x1f\x4e\x2d\xa7\xf4\x20\x2a\x88\x96\x26\x5a\x36\xaf\xa6\x5d\x37\xed\xf4\x34\xf0\x2c\x4c\xdf\x56\xac\xe1\x78\xe8\x18\x58\x37\x6f\x48\xbf\xd9\x7c\xab\xf1\x2b\xb4\x36\xf0\xfd\xf7\xf2\x72\x09\x07\xc6\x30\x0f\x76\x06\xf2\x6d\x97\x4d\x61\xad\x45\x95\xa5\xcb\x02\x64\x83\x2d\x6d\xb3\x26\xce\x10\x20\x18\x1e\xc8\x65\x86\x60\x0b\xc4\x7c\x95\x86\x69\x9b\x82\xbe\xd5\x25\x92\xce\x90\x1f\xb2\x0e\xf1\x41\x69\x5b\xfc\xbf\x0b\x4f\xde\x6d\xf8\xba\x96\x9e\x9c\xea\xa9\xa0\x86\xec\xb0\xe8\xa5\xef\xf1\x60\x8b\x3f\xb0\xfb\x9b\x66\x28\x74\x45\x41\x48\xe0\xe3\xd3\x4a\xb4\xf7\x61\xe3\x47\x5e\x8d\x43\x92\xfc\x14\xea\xc9\x07\x30\x2f\x3e\xa1\xe3\x5e\x54\x9c\x9d\x55\x19\xaf\xbc\xe1\xc0\x6e\x89\x53\x5e\x8a\xf3\x0a\xb7\x9e\x8d\x93\xd8\x6a\x39\x74\xc7\x15\x5d\xc0\x8a\xb0\x5f\x57\x41\xd0\xbf\x82\x2c\x99\xff\x9e\xec\x29\x69\x70\x8f\x06\x8c\x3f\x4c\xe7\x32\xcf\x68\x00\x5e\xa0\xf1\x1f\x54\x9c\xbd\x03\x30\x08\x98\xf6\xfd\xae\x5e\x32\xbe\xaa\x58\x0a\x2b\x22\x96\xcb\xd1\xc5\x63\x6f\x2c\xf7\xfe\x47\x5d\x9c\x5a\x32\xe3\xaf\x50\x6d\x81\x7a\x0e\x42\x0b\xb5\x46\xc4\xd6\xe3\xc4\xc4\xde\x15\xe8\x86\x48\x54\x0b\x03\x4f\xcc\x8c\x74\x81\x14\x6d\x65\x70\xe8\x06\x36\x69\x7a\x3c\xb7\xa1\xfc\x52\xa6\x45\xd7\x01\x28\xa4\xdb\xa8\xa6\x7b\x44\x64\x8e\xf0\x48\xaf\x3d\x11\x8a\x40\x57\x9d\xb5\x34\x8e\xb6\x43\x64\x9e\xe8\x5a\xe3\xd4\x98\xd5\xa0\x58\x70\x71\x1f\x29\x50\xb2\x25\x5a\x6e\xc2\xee\xf8\x96\xc0\x7c\x54\x9e\x6d\xa4\x6a\x74\x09\x75\xba\x79\x09\x9b\x18\x13\xd6\x66\x8b\x30\xc9\xdd\xd0\x8a\x7b\x3b\xb8\xa1\x39\x6b\x6a\x45\xf3\x8e\x87\x58\xab\x79\x24\xd1\x4d\x20\x5a\xfe\x48\x1d\x13\x17\xb0\xbe\x3f\x06\x6d\xc6\xa3\xaf\x60\x78\xe8\xda\xe7\x4d\x40\x3d\x1f\xdf\x69\x06\xa4\xce\xda\xd8\x28\x01\xfe\xae\xc2\x18\x50\xd6\x95\xfa\x07\xc9\x0c\x22\x40\xdb\x99\x05\x5d\xb2\x0f\x11\xd9\x9b\x20\x59\xfb\xba\x67\xd4\x4f\xcb\xd5\x0e\x90\xfa\xe9\x73\x8f\x40\x9f\x38\x49\xac\x1e\xa4\x6f\x19\x88\x28\xdd\xf3\xa5\xa9\x63\x50\xdd\x24\xec\xa9\xbe\x5e\x92\xba\x8e\x5f\x0c\x07\x5f\xf4\xbe\x94\xae\x6c\x63\xe8\x01\xf3\x7a\xcf\xee\x35\x87\x83\x55\x3f\x2e\x04\x76\xa4\x75\xc5\xb0\x11\x85\x80\xd7\x56\x04\xea\x81\xf6\xdf\xea\xe5\xd9\x74\x99\x73\x7c\x3a\x0c\x5a\xbf\xfe\x4a\xe0\x00\x96\xfb\xc0\xac\xf9\x50\xca\x90\xb7\x4b\xb7\xe6\xad\x3f\x0d\x99\x74\xc8\xed\x36\xac\xcb\x2d\x0d\x1b\x5f\xeb\xc2\xbb\xdd\x86\xe5\x19\x2f\x0b\x89\x3e\x6b\x00\x0d\x3b\x1e\xef\xa5\x58\xdb\x4c\x76\x04\xc8\xd1\x4a\x34\x33\x67\x63\x5d\x50\xcc\x59\x15\xec\x0c\x43\x83\x6d\x71\xd0\xd7\xc7\xa4\x2a\x35\x9a\x15\x49\x14\x7a\xbc\xf0\x96\xed\xb7\xea\x05\xea\xc4\xc7\xdb\x1a\x1b\x67\xac\xa8\x6d\x3e\x8b\x44\x5f\xb5\xbc\x38\x12\x41\xc5\xe9\xe3\xb2\xaa\x01\x61\x12\xe8\x15\x36\x1e\x43\xbe\x48\xa9\x71\x16\x44\x56\x27\x21\x2f\x57\x93\x1a\x09\x1e\x55\x8d\x68\x1a\x0b\x39\x55\x2c\x7a\x4d\x5e\x15\xbb\xf4\x63\xee\xef\x8a\x1e\xc3\x96\x40\x5f\x88\x0c\xc3\x2a\x57\x9e\xb9\x72\x17\xb8\xdc\xef\x9f\xf0\xd0\xfb\x4c\x14\x4e\xf4\x79\x6d\xd5\x5b\x2b\xa9\xda\x27\x60\x8e\xe5\x6a\x72\xf8\x39\x9a\x6f\x5f\x3f\x29\x44\x28\x3b\x0d\xaa\xe4\x20\x15\x24\x8e\x06\x68\xeb\xeb\xac\x30\xc0\xf8\x36\x5e\xb5\xc0\x75\x01\xec\xed\x4f\x9a\x5c\x08\xa8\x5d\xb5\x9d\x93\x27\xa2\xd6\xd9\x23\x8a\xd2\xdc\x9c\x05\xfb\x10\xc4\xe5\x2d\xc8\x23\x3a\x04\x8f\x38\x75\xe4\x97\xc2\xec\x2f\x54\xb1\xfb\x36\x35\x24\x24\xdc\x91\x4e\x2b\x7f\x81\x76\x79\x00\x34\xe7\xea\x15\x6a\xdf\xd0\x1c\xf6\x97\x9e\x19\x7c\xa7\x0d\xf7\x14\xb9\x0c\x8b\x49\x89\x30\x3d\x24\xf8\xe2\xbf\x6a\x3c\xb8\xa4\xc3\x87\x16\xb4\x60\x02\xcb\xde\x01\x81\x5e\xd2\x50\xda\x94\xd3\xa0\x22\x03\x2e\xe3\x84\xd5\xe5\xd7\x5f\x0e\x64\xcb\x33\xd1\x1a\x66\x32\x36\xaf\xec\xb0\x2a\x72\x8a\xa5\x19\x98\xe0\x07\x30\x72\xaa\x5b\x1d\x5b\xed\xf1\xfb\x30\x56\x56\xd2\x08\xa8\xfa\x14\x83\x62\x46\x87\x5a\x97\xe0\xb9\xbd\x0a\x4d\x71\xa2\xf2\xb0\x9e\x23\x73\x55\x8d\xbb\xf8\xf3\xd7\x5f\xb4\x7b\xe2\x3e\x81\x04\x03\xf0\x68\xbb\x62\x8f\xc6\xac\x92\x6b\xbd\x5e\xaf\x9b\x3d\x3b\x57\xac\x7b\x71\xb8\x8d\x5c\x2f\x89\x37\xa0\xb5\x1a\x02\x16\x5e\x42\x6a\x74\x20\xfe\x48\x81\xba\xc0\x29\x6b\x0b\xb3\xee\x4d\xb9\x5e\xbe\x60\x64\xe3\x83\x54\x54\x4c\x32\xdb\x06\xc5\x71\x40\x57\xae\x87\x10\xfd\x69\x4a\x95\x02\xb0\x59\x45\x98\xfe\xfe\x76\x54\xa9\x28\x0b\x8b\x9a\xc7\x9d\x04\x38\x8e\xe8\x76\x00\x9a\xaf\x67\xea\x32\x9d\xa3\x65\x7f\xa9\xb5\x67\x7e\x70\xde\x81\x3d\xe2\xee\x75\xa0\x1b\x69\xc0\x9f\x94\x9c\x72\x06\xda\x9d\xc8\x6f\xcd\x0b\x52\x2d\xce\x8d\xfb\xa8\x55\xd9\x93\x3d\x65\xba\x2c\x1f\x24\x2b\xd9\xc9\xdd\x59\xd4\x94\xd4\xc8\x71\x8a\xaa\x56\xa4\xa5\x78\x71\x65\xa2\xa5\x80\x1d\xf5\x8c\x3c\x03\xff\x2b\x59\x7f\x65\x15\xa9\x6a\xbd\x1b\x67\xfd\xdb\x65\x71\x87\x4c\xb5\x58\x85\x49\x54\x46\xb9\x7e\xb9\x79\x97\x9c\xa1\x60\xbe\xe1\x40\x96\x5d\x59\x44\xcb\xca\xcc\xda\x12\x2b\x86\x79\x7c\x67\x76\x29\x70\x52\x58\xa5\x79\x7b\xf9\x5f\xe1\x07\xe8\x88\xfa\x0c\x5b\x1c\x18\x12\xaf\x8f\x8e\x13\x43\x8f\xec\x84\xf3\x5a\xa5\x1c\xd7\xad\xaf\xa6\x4d\xef\x68\xb4\x66\xf4\xbd\x8a\xc1\x23\x5c\x50\x27\x2b\x0d\x91\xcf\x4b\xc5\x87\x71\x62\x39\x92\x2a\x33\xf0\xe2\x2c\x81\x07\x72\x2a\x58\x2e\xd1\x44\x64\x66\x76\xa3\x51\x24\x0a\xa3\x52\x08\x61\xc2\x6f\x54\xe9\x87\xca\x2a\xdc\x36\x5b\xc3\x80\xaa\x0d\x1d\xb6\xb5\x4f\x5f\xa1\x74\xf5\x7e\xa7\xa1\xcc\xfd\xc5\x62\x76\x32\x2d\xe6\xa0\x98\xea\xc8\x90\x2f\x53\xf6\xb3\xb0\x0e\xe9\xae\x71\x13\x4b\x5c\x8c\x10\x9d\x8c\xfa\x7a\x25\xe6\x60\x9b\x79\xed\x71\x83\xc3\xc5\x06\x05\xa3\xa5\xb5\x5b\x42\x6f\x49\xa6\x37\x79\xbd\xf2\xcf\x31\x5b\x5b\x4b\xfc\x47\x12\x9b\xc7\xf5\x2b\x58\x70\x4d\x96\x02\x09\x3d\x6a\x91\x57\x12\xb5\x37\xb5\xff\xbd\xb4\x52\x89\x48\x32\x87\x0f\x17\x85\xfa\x9e\x52\x0a\xf2\x89\x89\xe7\x8c\x96\x43\xf3\x3f\xd4\x7a\x0e\xff\x5b\x1d\xb0\x1c\x2e\x13\xdd\x23\xb6\x2c\x5c\x01\x1a\xa5\x7b\x82\x00\x95\xc5\xff\x9f\x76\x16\x84\x2b\x3c\x1d\x0c\x40\x76\x0e\x30\xb4\xaf\xcd\xc0\xc5\x3c\x4f\x30\x6b\x15\xdf\xcf\xbd\xcc\xff\xb4\xc5\x28\x96\x66\x49\x98\x5e\x0e\xc8\x89\xcf\xff\xb3\x71\x8f\xb2\x6b\x6c\x50\x71\xb8\x37\x31\x53\xff\xd7\x7c\xeb\x47\x33\xd7\xcb\xa5\xa1\xe5\xf5\x26\x84\x1d\x58\x0c\x82\xf7\x28\x83\x3c\x55\x89\xf8\xeb\x6d\x45\xf9\x41\x28\x86\x3a\x71\x5c\x02\x1c\xdf\xee\xa3\x98\xe8\x7e\xda\x5e\x62\x6c\xd1\x9a\xa0\x53\x32\x89\xa0\x7c\x9f\x82\xc1\x63\x94\x4c\x55\x60\xfa\x25\x10\x0a\xbd\x84\xd8\x4c\xce\x51\x85\x74\x17\x14\x80\x8a\xf7\x7e\xc0\xa9\x65\xee\x82\x14\xca\x83\x3a\x9f\x95\xa3\x5d\x7a\xde\x58\x71\xaf\xeb\xa4\x89\x53\x84\xf3\xbf\x1a\xa2\x45\x1c\xcc\x47\x5e\x0d\x50\x87\xb4\x38\x8b\x0e\x44\x87\xd7\x54\x6f\x97\x3c\x2e\x08\x73\x99\x22\x08\x70\x7a\xc3\xa3\xfe\xdd\xfd\x2f\x73\x11\x43\x2d\xab\x3f\x89\x90\x1a\xbb\xaf\xdf\xca\x67\xef\x13\x27\x07\x5e\x36\xbe\xd7\x59\xb7\xc4\x7b\x8f\xc0\x5d\x4a\x39\x65\x58\x02\x4c\x50\x88\xbe\x87\x30\x38\x22\x10\x95\x65\xef\x0f\x2b\x18\x71\x5e\x8c\x31\xf2\x5a\x29\x07\x17\xb1\x65\xdb\xc7\x66\x84\xad\x83\xbb\xa4\xf3\x0e\x4a\x77\xbb\xc0\xe4\x43\xa0\x2a\x62\x72\xa6\x51\xb4\x4c\x9a\x0a\x28\x5e\x6d\x44\x9b\x2b\x5d\x05\xa6\x54\x03\xa1\x0a\x5c\x8a\x3a\x0a\xa9\x86\xaa\x59\x88\x59\xfc\x5f\xd7\xd3\x43\xb4\xb2\x6d\x02\x40\x65\x55\x16\x0f\xcf\x60\xf8\x8d\x75\xb8\x63\x8a\xd2\x65\xec\x25\x56\x05\x4e\x3f\xc8\x81\x06\x57\x7c\x72\x3a\x76\xde\x55\xd6\x3e\xe1\x02\xf5\xce\x20\x95\x8d\xcd\x03\xda\x81\xbe\xe4\x93\xb6\x28\xcd\xe9\xba\x01\xcf\x1e\x61\xfa\x42\xd4\x8c\xdd\x24\xf2\x45\xcd\xad\x82\xff\x5d\xa7\x6a\x49\x5e\xa1\xa7\x71\x79\x0c\xd4\xa0\x99\xd1\xc7\x67\x39\x53\x45\xdf\x19\x33\xeb\x2e\x3a\x9e\xcc\xaf\x12\x1a\x54\x77\xd2\x54\x45\x5d\xfc\xe5\xcb\x89\x88\x6f\x27\xbc\x74\x73\x16\xeb\x8d\x16\x1d\xf2\x0a\x85\x71\x9d\xd3\xba\x89\x65\x7f\x58\xf8\x9d\xf2", 3072);
*(uint64_t*)0x200025d8 = 0xc00;
*(uint64_t*)0x200025e0 = 0x20000000;
memcpy((void*)0x20000000, "\xbf\x4b\xb3\x15\x22\xd9\x76\x1c\x06\x04\x9f\x3f\x5c\xbb\xdc\x00\xd4\x7d\x93\xb1\x3d\x39\x41\xb0\x2d\x80\x51\xc6", 28);
*(uint64_t*)0x200025e8 = 0x1c;
*(uint64_t*)0x200025f0 = 0x200013c0;
memcpy((void*)0x200013c0, "\x4d\x7a\xc5\x87\xa5\x3e\xc0\x19\x93\xd9\x95\x07\x48\x12\x1a\x0d\x1d\x75\xf1\x5a\xf2\xd6\x8f\x66\x62\x85\x41\x04\x12\x43\x5c\x0a\x71\x3f\x99\xd4\x6f\x9e\x72\x17\x14\x39\x13\x47\x6f\x84\x6b\xcb\xc8\x92\x8a\x71\x73\x66\xf3\xc7\x76\x32\xbb\xd0\x5f\x69\x9f\x04\xb4\x74\x41\xed\xfd\x70\x96\xcd\xdb\x53\xe3\x10\x47\x7c\xac\x01\xe2\xb2\x2a\xac\xd2\x6a\x0c\xfa\xe2\xa1\xf1\xdb\x6e\xa9\xfc\x13\x80\x67\x75\xe3\x64\xde\xb0\xb8\x45\x97\xe1\xc4\x01\xe8\x4f\x42\x85\x8d\x4c\x84\xa3\x60\x51\x8c\xcd\xe5\x2e\x93\xf2\xbb\x68\x05\x93\xab\x2a\x67\x8b\x5d\xb8\x87\x3b\x37\x1a\xa5\x49\x1c\xdc\x29\xd1\xd1\xfa\xc8\x4b\xe5\x9c\x1c\xd8\x45\x26\xdd\x76\x7f\x90\x0b\xcb\x0e\x40\x5a\x49\x3e\xbe\x94\x23\x1e\xbc\xdc\x24\x98\x47\x62\x92\x55\xa9\xb8\xf3\x45\x39\x06\xc1\x19\x9b\xec\xa8\x64\x25\xbe\xad\x72\x5e\x08\xbb\xb1\x70\x09\x57\x08", 202);
*(uint64_t*)0x200025f8 = 0xca;
*(uint64_t*)0x20002600 = 0;
*(uint64_t*)0x20002608 = 0;
*(uint64_t*)0x20002610 = 0x200024c0;
memcpy((void*)0x200024c0, "\x8c\xdb\xcf\x77\xae\x8b\x51\x1f\xbf\x30\x59\xfd\xea\x72\x44\xa8\x2a\x59\x73\xf9\x31\x46\xe4\x6f\xc7\xbd\x3b\x04\x30\xa3\xe1\xe5\x62\x0a\x55\x36\x6b\xfe\x9f\x56\x9e\xa7\x37\x25\xbb\x68\x4c\xb6\x56\x62\xe7\x99\x29\x5e\x8f\x9e\x69\xc4\xdd\x60\x96\xce\x74\xd2\xc4\xa1\xbc\x72\x2c\xc1\xd9\xa8\xad\xd2\x04\x87\xe3\x6b\x21\xef\x7f\x81\xa1\x2b\xa8", 85);
*(uint64_t*)0x20002618 = 0x55;
*(uint64_t*)0x20002620 = 0x20002540;
memcpy((void*)0x20002540, "\xfb\xe3\x98\xda\x6e\xb2\xe4\x19\x62\xf6\xe2\x72\xa9\xd3\x79\xb9\x25\x38\xc3\xd6\xad\xce\x35\x0d\x1a\x21\x07\xe9\x22\x58\x50\xc1\xf9\x7f\x94\x4b\x26\x6f\x34\x82\x27\xaa\x8c\xb8\xb6\xa4\x60\xe3\xbd\xcf\x40\xf5\x6c\xc2\x96\x78\x95\x95\x4a\xc0\xf4\x90\x26\x5b\x9e\x8e\x49\xd5\xd9\xf6\x5d\x21\xed\x82\x5c\x89\xa7\x0a\xa9\x8d\xec\x72\x85\xec\xde", 85);
*(uint64_t*)0x20002628 = 0x55;
	syscall(__NR_writev, r[0], 0x200025c0ul, 7ul);
*(uint64_t*)0x20002640 = 4;
	syscall(__NR_signalfd4, r[0], 0x20002640ul, 8ul, 0ul);
*(uint32_t*)0x20002680 = 3;
	syscall(__NR_ioctl, -1, 0x40046205, 0x20002680ul);
*(uint64_t*)0x20000080 = 0;
	syscall(__NR_sendfile, r[0], r[0], 0x20000080ul, 0xfffffffful);
	syscall(__NR_fcntl, r[0], 0x409ul, 0xdul);
	return 0;
}