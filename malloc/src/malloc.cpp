#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Duplicates src into a dynamically allocted memory block and returns the pointer*/
char* duplicateString(const char* src)
{
	//Create new memory block
	char* duplicate = (char*)malloc(strlen(src) * sizeof(char) + 1);
	if (duplicate == NULL) { return NULL; }

	//Copy data
	memcpy(duplicate, src, strlen(src) + 1);

	return duplicate;
}

/*Copies n amount of data from src to dest*/
void memCopy(void* dest, const void* src, int n)
{
	//Ensure that dest is bigger or equal to n
	if (sizeof(dest) < n) { n = sizeof(dest); }
	if (n == 0) { return; }

	char* d = (char*)dest;
	char* s = (char*)src;

	//Start decrementing n while coping contents over
	while (n-- != 0)
	{
		*d++ = *s++;
	}

}

/*Resizes memory at ptr from oldSize to newSize*/


int main(void)
{
	char* duplicate = duplicateString("Hello\n");
	printf("%s", duplicate);
	free(duplicate);
	duplicate = NULL;

	char* test = (char*)malloc(7 * sizeof(char));
	memCopy((void*)test, "Hello\n\0", 7);
	printf("%s", test);
	free(test);
	test = NULL;

	return 0;
}