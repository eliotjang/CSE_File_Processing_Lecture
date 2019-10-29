#include <stdio.h>
int main() {
	FILE* fp1, * fp2;

	if ((fp1 = fopen("test.txt", "w")) == NULL) {
		printf("file open error!\n");
		return 0;
	}

	fputs("Hello, everyone \n 첫번째 파일 오픈 테스트임 \n", fp1);

	if ((fp2 = fopen("test.txt", "a")) == NULL) {
		printf("file open error!\n");
		return 0;
	}

	fputs("두 번째 파일 오픈 테스트?", fp2);
	return 0;
}