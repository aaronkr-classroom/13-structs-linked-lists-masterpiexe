#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef unsigned short int us;
typedef struct People {
	char name[12];
	int age;
	float height;
	float weight;

} Person;


int main()
{
	Person data;
	printf("������� ������ �Է��Ͻÿ�:\n");
	printf("�̸�: ");
	scanf("%s", data.name);
	printf("����: ");
	scanf("%d", &data.age);
	printf("Ű: ");
	scanf("%f", &data.height);
	printf("������: ");
	scanf("%f", &data.weight);

	printf("%s, %d��, %.1fkg,%.1fcm\n", data.name, data.age, data.height, data.weight
	);
}