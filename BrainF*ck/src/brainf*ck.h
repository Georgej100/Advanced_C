#pragma once
#include <stdio.h>

struct bf_vm
{
	unsigned char* tape;
	unsigned int pointer;
	unsigned char* program;
	unsigned int ip;
};

void VM_init(struct bf_vm* VM, char* file);
char* load_file(char*file_path);
