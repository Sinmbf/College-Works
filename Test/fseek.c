#include <stdio.h>
#include <stdlib.h>

int main() {
	char ch;
	FILE *file;
	// Open a file in read mode
	file = fopen("source.txt", "r");

	if (file == NULL) {
		printf("File not found\n");
		return 1;
	}
	
	fseek(file, 6, SEEK_SET);

	// Read and print the file content
	ch=fgetc(file);
	printf("%c",ch);

	// Close the file
	fclose(file);

	return 0;
}

