#include <stdio.h>

int main()
{
	int i = 0;
	FILE* streamfile = fopen("stream.txt", "w");

	if (streamfile == NULL)
		return 0;

	char string[] = "SMITH", outputString[20];

	for (i = 0; string[i] != '\0'; i++)
		fputc(string[i], streamfile);

	fclose(streamfile);
	streamfile = fopen("stream.txt", "r");

	fgets(outputString, 20, streamfile);

	printf("%s", outputString);

	fclose(streamfile);
	return 0;
}