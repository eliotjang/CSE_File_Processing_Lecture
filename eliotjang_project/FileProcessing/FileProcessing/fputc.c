#include <stdio.h>
int main() {
	FILE* fp1, * fp2;

	if ((fp1 = fopen("test.txt", "w")) == NULL) {
		printf("file open error!\n");
		return 0;
	}

	fputs("Hello, everyone \n ù��° ���� ���� �׽�Ʈ�� \n", fp1);

	if ((fp2 = fopen("test.txt", "a")) == NULL) {
		printf("file open error!\n");
		return 0;
	}

	fputs("�� ��° ���� ���� �׽�Ʈ?", fp2);
	return 0;
}