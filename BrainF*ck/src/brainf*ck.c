#include "brainf*ck.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define PROGRAM_SIZE 3000

int main(int argc, char* argv[])
{
	char* file = argv[1];
	struct bf_vm VM;
	int temp = 0;
	VM_init(&VM, file);

	while(VM.ip < strlen(VM.program))
	{
		char command = VM.program[VM.ip];
		switch(command)
		{
			case '<':
				VM.pointer--;
				break;		
			case '>':
				VM.pointer++;
				break;
			case '.':
				printf("%c", (char)VM.tape[(unsigned int)VM.pointer]);
				break;
			case ',':
				char input = ' ';
				scanf("%c", &input);
				VM.tape[VM.pointer] = input;
				break;
			case '[':
				temp = 1;		
				if (VM.tape[VM.pointer] == 0)
				{
					VM.ip++;
					while (VM.ip < strlen(VM.program))
					{
						if (VM.program[VM.ip] == ']')
						{
							temp--;
							if (temp == 0) {break;} // Found matching brace
						}
						else if (VM.program[VM.ip] == '[')
						{
							temp++;
						}
						VM.ip++;

					}
				}
				break;
			case ']':
				temp = 1;
				if (VM.tape[VM.pointer] != 0)
				{
					VM.ip--;
					while(VM.ip > 0)
					{
						if (VM.program[VM.ip] == '[')
						{
							temp--;
							if (temp == 0) {break;} // Found matching brace
						}
						else if (VM.program[VM.ip] == ']')
						{
							temp++;
						}
						VM.ip--;
					}
				}
				break;
			case '+':
				VM.tape[(unsigned int)VM.pointer]++;
				break;
			case '-':
				VM.tape[(unsigned int)VM.pointer]--;
				break;
		}
		VM.ip++;
	}
	printf("\n");
}

void VM_init(struct bf_vm* VM, char* file)
{
	VM->tape = (char*)malloc(30000 * sizeof(char));
	VM->pointer = 0;
	if (VM->tape == NULL)
	{
		printf("Failed to allocate memory for VM\n");
		_exit(1);
	}

	// Load program
	VM->program = load_file(file);

	return;
}

char* load_file(char* file_path)
{
	// Open file
	FILE* fd = fopen(file_path, "r");
	if (fd == NULL)
	{
		printf("Cannot open file: %s\n", file_path);
		_exit(1);
	}

	char ch = ' ';
	int index =  0;
	char* content = malloc(PROGRAM_SIZE * sizeof(char));
	if (content == NULL)
	{
		printf("Failed to allocate memoey for program instructions\n");
		_exit(1);
	}
	

	do
	{
		ch = fgetc(fd);
		content[index] = ch;
		index++;

	}while(ch != EOF);
	
	content[index + 1] = '\0';

	fclose(fd);
	return content;
}
