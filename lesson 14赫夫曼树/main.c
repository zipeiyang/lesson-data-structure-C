#include<stdio.h>
#include<stdlib.h>
#include"huffmantree.h"

int main()
{
	char baowen[100];
	char zi[100];
	int quan[100]={0};
	int m;
    createtext(baowen,zi,quan,&m);
	
//	char zi[6]={'A','B','C','D','E','F'};
//  int quan[6]={6,6,6,2,1,2};
	FTree T;
	createftree(&T,quan,m);
	
	printf("�����ܱ��볤��/����Ȩ·������Ϊ��%f\n",getwpl(T));
	printf("\nÿ����ĸ�ı���Ϊ��\n");
	setcode(T,zi);
	
	decode(T,zi);
	return 0;
}
