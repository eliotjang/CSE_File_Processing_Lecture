#include <stdio.h>

int main(void)
{
	FILE* stream;
	char buffer[50];

	stream = fopen("data3.txt", "w");
	if (stream != NULL)
	{
		puts("���ڿ��� �Է��� �� ����Ű�� ��������.");
		fgets(buffer, sizeof(buffer), stdin);
		fputs(buffer, stream);
		fclose(stream);
	}
	else
	{
		puts("���� ���� ����");
	}
	return 0;
}