#include<stdio.h>
#include<stdlib.h>
#include"select.h"

int main()
{
	Seqlist A;
	Elem_type e;
	int i=1;
	printf("初始化数据(-111 ends)：");
	scanf("%d",&e);
	getchar();
	while(e!=-111)
	{
		A.E[i].key=e;
		i++;
		scanf("%d",&e);
		getchar();
	}
	A.length=i;
	traverse(A);
	printf("\n\n简单选择排序：\n");
	select(&A);
	traverse(A);
	
	
	return 0;
}
