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
	
	printf("报文总编码长度/树带权路径长度为：%f\n",getwpl(T));
	printf("\n每个字母的编码为：\n");
	setcode(T,zi);
	
	decode(T,zi);
	return 0;
}
