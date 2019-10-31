#include <stdio.h>

int main(void)
{
	FILE* stream;
	char buffer[50];

	stream = fopen("data3.txt", "w");
	if (stream != NULL)
	{
		puts("문자열을 입력한 후 엔터키를 누르세요.");
		fgets(buffer, sizeof(buffer), stdin);
		fputs(buffer, stream);
		fclose(stream);
	}
	else
	{
		puts("파일 열기 오류");
	}
	return 0;
}