#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"


int main()
{
	linkqueue S;
	initqueue(&S);
	printf("初始化链队列\n");
	isemptyqueue(S);
	
	printf("\n\n插入1,3,5,7");
	Elem_type e,a,b;
	for(e=1;e<8;e+=2)
	{
		enqueue(&S,e);
	}
	gettop(S,&a);
	printf("\n队首为：%d\n",a);
	traverse(S);
	
	dequeue(&S,&b);
	printf("\n\n出队一个数字；%d",b);
	gettop(S,&a);
	printf("\n队首为：%d\n",a);
	traverse(S);

	printf("\n\n入队2,4\n");
	for(e=2;e<5;e+=2)
	{
		enqueue(&S,e);
	}
	traverse(S);
	return 0;
}
