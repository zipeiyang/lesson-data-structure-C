#include<stdio.h>
#include<stdlib.h>
#include"stackseq.h"

int main()
{
	char s[100];
	int a;
	printf("请输入一个中缀表达式：");
	scanf("%s",&s);
	transfer(s);
	
	
	return 0;
}
