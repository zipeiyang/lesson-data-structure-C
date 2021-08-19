#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main()
{
	initlist(L);
	int i,a;
	Elem_type b;
	printf("输入数字的个数：");
	scanf("%d",&a);
	getchar();
	printf("输入数字：");
	for(i=1;i<a+1;i++)
	{
		scanf("%d",&b);
		getchar();
		listinsert(L,i,b);
	}
	listtraverse(L);
	
	printf("\n\n(删除5)\n");
	Elem_type e;
	listdelete(L,4,&e);
	printf("删除的数字是：%d\n",e);
	listtraverse(L);

	printf("\n\n(插入9)\n");
	Elem_type f;
	int g;
	printf("插入的数字是：");
	scanf("%d",&f);
	getchar();
	printf("插入的位置是：");
	scanf("%d",&g);
	getchar();
	listinsert(L,g,f);
	listtraverse(L);
	
	printf("\n\n(查找5)\n");
	Elem_type x;
	int y,length=listlength(L);
	printf("查找的数字是：");
	scanf("%d",&x);
	getchar();
	y=listsearch(L,x);
	if(y!=length)
	printf("%d在第%d个位置上",x,y);
	else
	printf("查找失败"); 
	
	printf("\n\n(查找7)\n");
	printf("查找的数字是：");
	scanf("%d",&x);
	getchar();
	y=listsearch(L,x);
	if(y!=length)
	printf("%d在第%d个位置上",x,y);
	else
	printf("查找失败"); 
	
	return 0;
}
