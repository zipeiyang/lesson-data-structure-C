#include<stdio.h>
#include<stdlib.h>
#include"stackseq.h"

int main()
{
	sqstack S;
	initstack(&S);
	printf("初始化顺序栈\n");
	isemptystack(S);
	
	printf("\npush 1,3,5,7\n");
	Elem_type e,a,b;
	for(e=1;e<8;e+=2)
	{
		pushstack(&S,e);
	}
	gettop(S,&a);
	printf("此时的栈顶为：%d\n",a);
	traverse(S);
	
	printf("\n\npop a number\n");
	popstack(&S,&b);
	printf("弹出的数字为：%d\n",b);
	gettop(S,&a);
	printf("此时的栈顶为：%d\n",a);
	traverse(S);

	printf("\n\npush 2,4\n");
	for(e=2;e<5;e+=2)
	{
		pushstack(&S,e);
	}
	traverse(S);
	return 0;
}
