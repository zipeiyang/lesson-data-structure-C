#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"stackseq.h"

int main()
{
	char s[100];
	printf("输入后缀表达式：");
	scanf("%s",s);
	evaluatestack(s);
	
	return 0;
}
