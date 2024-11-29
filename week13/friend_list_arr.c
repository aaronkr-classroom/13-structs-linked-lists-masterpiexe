#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define MAX_COUNT 5

typedef char NAME_TYPE[14];
typedef unsigned short int US;
int AddFriend(NAME_TYPE* p_name, US* p_age, float* p_height, float* p_weight,int count)
{
	if (count < MAX_COUNT)
	{
		printf("enter your friend's information:\n");
		printf("1.name: ");
		scanf("%s", *(p_name+count));
		printf("2.age: ");
		scanf("%d", p_age + count);
		printf("3.height: ");
		scanf("%f", p_height + count);
		printf("4.weight: ");
		scanf("%f", p_weight + count);
		printf("intput successful\n");
		return 1;
	}
	else
	{
		printf("MAX_COUNT exceeded\n");
		printf("only able to input until %d", MAX_COUNT);
	}
	return 0;
}
int ShowFriend(NAME_TYPE* p_name, US* p_age, float* p_height, float* p_weight,int count)
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", p_name+i);
			printf("%d\n", *(p_age + i));
			printf("%.1f\n", *(p_weight + i));
			printf("%.1f\n", *(p_height + i));
		}
	
	}
	else
	{
		printf("NofriendsLOL\n");
	}
}
int main()
{
	NAME_TYPE name[MAX_COUNT];
	US age[MAX_COUNT];
	float height[MAX_COUNT];
	float weight[MAX_COUNT];
	int count = 0, menu_num;
	while (1)
	{
		printf("\t[menu]\n");
		printf("===========\n");
		printf("1.addfriend\n");
		printf("2.showfriend\n");
		printf("===========\n");
		printf("select number: ");
		scanf("%d", &menu_num);
		if (menu_num == 3)break;
		switch (menu_num) {
		case 1:
			AddFriend(name, age, height, weight, count);
			count++;
			break;
		case 2:
			ShowFriend(name, age, height, weight, count);
			break;
		
		default:
			printf("enter numbers between 1~3\n");
		}
	}
}