#include <stdio.h>
#include <string.h>

struct member {
	char name[10];
	int age;
	char sex[3];
	char city[10];
};

int main()
{
	struct member m[3];
	int i;

	FILE* f;

	strcpy(m[0].name, "�强��");
	m[0].age = 22;
	strcpy(m[0].sex, "��");
	strcpy(m[0].city, "����");

	strcpy(m[1].name, "������");
	m[1].age = 24;
	strcpy(m[1].sex, "��");
	strcpy(m[1].city, "��");

	strcpy(m[2].name, "�强��");
	m[2].age = 24;
	strcpy(m[2].sex, "��");
	strcpy(m[2].city, "����");

	printf("����ü�� �Էµ� �ڷ�\n");

	for (i = 0; i < 3; i++) {
		printf("%s %d %s %s\n", m[i].name, m[i].age, m[i].sex, m[i].city);
	}

	f = fopen("a.txt", "w");

	for (i = 0; i < 3; i++) {
		fprintf(f, "%s %d %s %s\n", m[i].name, m[i].age, m[i].sex, m[i].city);
	}

	fclose(f);

	return 0;
}