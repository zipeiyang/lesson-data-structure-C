#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"


int main()
{
	linkqueue S;
	initqueue(&S);
	printf("��ʼ��������\n");
	isemptyqueue(S);
	
	printf("\n\n����1,3,5,7");
	Elem_type e,a,b;
	for(e=1;e<8;e+=2)
	{
		enqueue(&S,e);
	}
	gettop(S,&a);
	printf("\n����Ϊ��%d\n",a);
	traverse(S);
	
	dequeue(&S,&b);
	printf("\n\n����һ�����֣�%d",b);
	gettop(S,&a);
	printf("\n����Ϊ��%d\n",a);
	traverse(S);

	printf("\n\n���2,4\n");
	for(e=2;e<5;e+=2)
	{
		enqueue(&S,e);
	}
	traverse(S);
	return 0;
}
