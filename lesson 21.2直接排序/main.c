#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h" 


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
	printf("\n直接插入排序：\n");
	insertdirect(&A);
	traverse(A);
	return 0;
}
