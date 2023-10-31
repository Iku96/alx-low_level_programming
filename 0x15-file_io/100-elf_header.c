#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>

#define ERR_EXIT(x) do { perror(x); exit(98); } while (0)

#define ELF_MAGIC 0x464C457F

typedef struct {
	unsigned char e_ident[16];
	uint16_t      e_type;
	uint16_t      e_machine;
	uint32_t      e_version;
	uint64_t      e_entry;
	uint64_t      e_phoff;
	uint64_t      e_shoff;
	uint32_t      e_flags;
	uint16_t      e_ehsize;
	uint16_t      e_phentsize;
	uint16_t      e_phnum;
	uint16_t      e_shentsize;
	uint16_t      e_shnum;
	uint16_t      e_shstrndx;
} Elf64_Header;

void print_magic(Elf64_Header *h)
{
	int i;
	printf("Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", h->e_ident[i]);
	}
	printf("\n");
}

void print_class(Elf64_Header *h)
{
	printf("Class:                             ELF64\n");
}
void print_data(Elf64_Header *h)
{
	if (h->e_ident[5] == ELFDATA2LSB)
	{
		printf("Data:                              2's complement, little endian\n");
	}
	else
	{
		printf("Data:                              2's complement, big endian\n");
	}
}

void print_version(Elf64_Header *h)
{
	printf("Version:                           %d (current)\n", h->e_version);
}

void print_os_abi(Elf64_Header *h)
{
	switch (h->e_ident[7])
	{
		case ELFOSABI_NONE:
			printf("OS/ABI:                            UNIX - System V\n");
			break;
		case ELFOSABI_LINUX:
			printf("OS/ABI:                            Linux\n");
			break;
		case ELFOSABI_HPUX:
			printf("OS/ABI:                            HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("OS/ABI:                            NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("OS/ABI:                            Solaris\n");
			break;
		case ELFOSABI_AIX:"
			  printf("OS/ABI:                            AIX\n");
	}	  
}

