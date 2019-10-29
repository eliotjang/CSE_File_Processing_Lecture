#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
	FILE* fptr1, * fptr2;
	char c;

	fptr1 = fopen("src.txt", "r");
	if (fptr1 == NULL) {
		printf("Cannot open file src.txt\n");
		exit(0);
	}

	fptr2 = fopen("des.txt", "w");
	if (fptr2 == NULL) {
		printf("Cannot open file des.txt\n");
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr1);
	while (c != EOF) {
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}

	printf("\nContents copied to des.txt");

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}