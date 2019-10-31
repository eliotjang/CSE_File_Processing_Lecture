#include <stdio.h>

int main(void)
{
	FILE* stream1;
	FILE* stream2;

	char name[10] = "";
	int kor = 0, eng = 0, total = 0;
	stream1 = fopen("data4.txt","r");
	stream2 = fopen("data5.txt", "w");
	
	if ((stream1 != NULL) && (stream2 != NULL))
	{
		fscanf(stream1, "%s %d %d %d\n", name, &kor, &eng, &total);
		fprintf(stream2, "%s %d %d %d\n", name, kor, eng, total);
		//fprintf(stdout, %s %d %d %d\n", name, kor, eng, total);

		fclose(stream1);
		fclose(stream2);
	}
	else
	{
		puts("파일 열기 오류");
	}
	return 0;
}