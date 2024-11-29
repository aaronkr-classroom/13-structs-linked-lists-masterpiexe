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
	printf("대상자의 정보를 입력하시오:\n");
	printf("이름: ");
	scanf("%s", data.name);
	printf("나이: ");
	scanf("%d", &data.age);
	printf("키: ");
	scanf("%f", &data.height);
	printf("몸무게: ");
	scanf("%f", &data.weight);

	printf("%s, %d세, %.1fkg,%.1fcm\n", data.name, data.age, data.height, data.weight
	);
}