#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"


int main()
{
	listack S;
	initlink(&S);
	printf("初始化链栈\n");
	isemptylink(S);
	
	printf("\n\npush 1,3,5,7\n");
	Elem_type e,a,b;
	for(e=1;e<8;e+=2)
	{
		pushlink(&S,e);
	}
	gettop(S,&a);
	printf("此时的栈顶为：%d\n",a);
	traverse(S);
	
	printf("\n\npop a number\n");
	poplink(&S,&b);
	printf("弹出的数字为：%d\n",b);
	gettop(S,&a);
	printf("此时的栈顶为：%d\n",a);
	traverse(S);

	printf("\n\npush 2,4\n");
	for(e=2;e<5;e+=2)
	{
		pushlink(&S,e);
	}
	traverse(S);
	return 0;
}
