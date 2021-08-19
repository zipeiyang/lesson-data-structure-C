#include<stdio.h>
#include<stdlib.h>
#include"queueseq.h"

int main()
{
	squeue Q;
	initqueue(&Q);
	printf("初始化循环队列\n");
	Elem_type e,a,b;
	printf("\n\n插入1、3、5、7\n"); 
	for(e=1;e<8;e+=2)
	{
		inqueue(&Q,e);
	}
	getfront(Q,&a);
	printf("\n队首为：%d",a);
	traversequeue(Q);
	
	printf("\n出队一个数字；");
	dequeue(&Q,&b);
	printf("%d",b);
	getfront(Q,&a);
	printf("\n队首为：%d",a);
	
	printf("\n\n\n入队2,4\n");
	for(e=2;e<5;e+=2)
	{
		inqueue(&Q,e);
	}
	traversequeue(Q);
	return 0;
}
