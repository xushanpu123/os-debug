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

uint64_t r[1] = {0xffffffffffffffff};

int main(void)
{
		syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
	syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
				intptr_t res = 0;
	res = syscall(__NR_socket, 0xaul, 1ul, 0);
	if (res != -1)
		r[0] = res;
*(uint32_t*)0x20001380 = 1;
	syscall(__NR_setsockopt, r[0], 6, 0x13, 0x20001380ul, 4ul);
*(uint8_t*)0x20000080 = 0;
*(uint8_t*)0x20000081 = 0x1e;
memset((void*)0x20000082, 0, 6);
*(uint8_t*)0x20000088 = 1;
*(uint8_t*)0x20000089 = 6;
*(uint8_t*)0x2000008a = 0;
*(uint8_t*)0x2000008b = 0;
*(uint8_t*)0x2000008c = 0;
*(uint8_t*)0x2000008d = 0;
*(uint8_t*)0x2000008e = 0;
*(uint8_t*)0x2000008f = 0;
*(uint8_t*)0x20000090 = 0xc9;
*(uint8_t*)0x20000091 = 0x10;
*(uint64_t*)0x20000092 = htobe64(0);
*(uint64_t*)0x2000009a = htobe64(1);
*(uint8_t*)0x200000a2 = 4;
*(uint8_t*)0x200000a3 = 1;
*(uint8_t*)0x200000a4 = 0;
*(uint8_t*)0x200000a5 = 0;
*(uint8_t*)0x200000a6 = 0x7c;
memcpy((void*)0x200000a7, "\x99\x80\xcf\xd8\x4c\xe4\xe1\x7a\xbe\x16\x62\x38\x34\xb0\x3d\xad\xa5\x56\xed\x36\x91\x21\x4f\x29\x39\x57\xb6\xe7\x28\xa6\xb5\x39\xc9\x80\xb8\x2a\x0e\x32\xa3\x0b\x65\xad\x64\xd3\x8e\x6c\x92\x9d\xab\x5e\x9c\xc4\xff\x3d\xed\x08\x5f\x24\xb3\x0f\x47\x5d\xc5\xb7\xe4\x19\x32\x87\x80\xb5\x67\xf9\x13\x1b\x6d\x3c\x4d\x84\x69\x56\xae\x94\xe1\xb0\x88\xf1\x9b\x25\x53\x58\x37\x8f\x33\x6a\x67\x1a\x36\x37\x5f\x29\x3a\x30\xd6\xc3\xa8\x79\xd6\x67\x56\x74\xba\xf4\xc3\x68\x00\x61\x45\x44\x25\xfd\x97\x42\x8d\x08", 124);
*(uint8_t*)0x20000123 = 0;
*(uint8_t*)0x20000124 = 0x53;
memcpy((void*)0x20000125, "\x94\x84\x92\xc9\xb7\x38\x40\xe6\xda\xc1\x24\x66\xe3\x82\x05\x60\xe4\xe4\x8f\xd8\x24\x49\x6b\x6c\xb4\x9a\x92\xf6\xd9\x9c\x31\x01\x5d\x5b\xcc\x48\x45\x06\xb3\x31\x5a\x41\x0d\x81\x18\xd1\xc8\x50\xb3\x4c\x5d\x1d\x25\xa1\x18\xa4\x03\x5a\x98\xe9\xa0\xf6\xb8\x4a\x16\x57\x04\x8d\x84\x1c\x9f\xb1\xb1\xa9\x16\xbc\x99\xd9\xad\x22\x75\xef\x7a", 83);
	syscall(__NR_setsockopt, r[0], 0x29, 0x37, 0x20000080ul, 0xf8ul);
*(uint16_t*)0x20000000 = 0xa;
*(uint16_t*)0x20000002 = htobe16(0);
*(uint32_t*)0x20000004 = htobe32(0);
memset((void*)0x20000008, 0, 16);
*(uint32_t*)0x20000018 = 0;
	syscall(__NR_connect, r[0], 0x20000000ul, 0x1cul);
*(uint32_t*)0x20000040 = 0;
*(uint32_t*)0x20000044 = 9;
*(uint32_t*)0x20000048 = 0xb;
*(uint32_t*)0x2000004c = 0;
*(uint32_t*)0x20000050 = 0;
	syscall(__NR_setsockopt, r[0], 6, 0x1d, 0x20000040ul, 0x14ul);
	syscall(__NR_shutdown, r[0], 1ul);
	return 0;
}