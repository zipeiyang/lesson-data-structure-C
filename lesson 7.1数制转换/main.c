#include<stdio.h>
#include<stdlib.h>
#include"stackseq.h" 

int main()
{
	Elem_type N,d;
	printf("请输入十进制数字：");
	scanf("%d",&N);
	printf("请输入进制数：");
	scanf("%d",&d);
	conversion(N,d);
	return 0;
}
