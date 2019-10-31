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

	strcpy(m[0].name, "장성원");
	m[0].age = 22;
	strcpy(m[0].sex, "남");
	strcpy(m[0].city, "서울");

	strcpy(m[1].name, "윤수현");
	m[1].age = 24;
	strcpy(m[1].sex, "남");
	strcpy(m[1].city, "고성");

	strcpy(m[2].name, "장성혁");
	m[2].age = 24;
	strcpy(m[2].sex, "남");
	strcpy(m[2].city, "서울");

	printf("구조체에 입력된 자료\n");

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