#include<stdio.h>
#include<stdlib.h>
#include"queueseq.h"

int main()
{
	squeue Q;
	initqueue(&Q);
	printf("��ʼ��ѭ������\n");
	Elem_type e,a,b;
	printf("\n\n����1��3��5��7\n"); 
	for(e=1;e<8;e+=2)
	{
		inqueue(&Q,e);
	}
	getfront(Q,&a);
	printf("\n����Ϊ��%d",a);
	traversequeue(Q);
	
	printf("\n����һ�����֣�");
	dequeue(&Q,&b);
	printf("%d",b);
	getfront(Q,&a);
	printf("\n����Ϊ��%d",a);
	
	printf("\n\n\n���2,4\n");
	for(e=2;e<5;e+=2)
	{
		inqueue(&Q,e);
	}
	traversequeue(Q);
	return 0;
}
