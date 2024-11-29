#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define MAX_COUNT 5

typedef char NAME_TYPE[14];
typedef unsigned short int US;
typedef struct Friend
{
	NAME_TYPE name[14];
	US age[MAX_COUNT];
	float height[MAX_COUNT];
	float weight[MAX_COUNT];
}f;
int AddFriend(f *list,int count)
{
	if (count < MAX_COUNT)
	{
		printf("enter your friend's information:\n");
		printf("1.name: ");
		scanf("%s",*(list->name+count) );
		printf("2.age: ");
		scanf("%d", (list->age+count));
		printf("3.height: ");
		scanf("%f", (list->height + count));
		printf("4.weight: ");
		scanf("%f", (list->weight + count));
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
void ShowFriend(f *list, int count)
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", list->name + i);
			printf("%d\n", *(list->age + i));
			printf("%.1f\n", *(list->height + i));
			printf("%.1f\n", *(list->weight + i));
		}

	}
	else
	{
		printf("NofriendsLOL\n");
	}
}
int main()
{
	f friend;
	f* ptr = &friend;
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
			AddFriend(ptr,count);
			count++;
			break;
		case 2:
			ShowFriend(ptr, count);
			break;

		default:
			printf("enter numbers between 1~3\n");
		}
	}
}