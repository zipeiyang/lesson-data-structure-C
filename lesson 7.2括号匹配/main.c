#include<stdio.h>
#include<stdlib.h>
#include"stackseq.h" 

int main()
{
	char s[100];
	int a;
	printf("������һ�����ţ�");
	scanf("%s",&s);
	a=match(s); 
	if(a==1)
	printf("match succeeded.");
	if(a==0)
	printf("match failed.");
	if(a==-2)
	printf("push failed.");
	return 0;
}
