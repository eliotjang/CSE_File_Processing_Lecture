#include <stdio.h>

int main(void)
{
	FILE* stream;
	char name[10];
	int kor, eng, total;

	printf("1. �̸� �Է�: ");
	fscanf(stdin, "%s", name);

	printf("2. ���� ���� ���� ���� �Է�:");
	fscanf(stdin, "%d %d", &kor, &eng);
	total = kor + eng;

	stream = fopen("data4.txt", "w");
	if (stream != NULL)
	{
		fprintf(stream, "%s %d %d %d\n", name, kor, eng, total);
		fprintf(stdout, "%s %d %d %d\n", name, kor, eng, total);
		fclose(stream);
	}
	else
	{
		puts("���� ���� ����");
	}
	return 0;
}