#include<stdio.h>
#include<stdlib.h>
#include"shell.h"

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
	
	int d[MAXSIZE];
	printf("\n\n初始化增量序列(-111 ends)：");
	int j=0;
	int f;
	scanf("%d",&f);
	getchar();
	while(f!=-111)
	{
		d[j]=f;
		j++;
		scanf("%d",&f);
		getchar();
	}
	
	printf("\n\n希尔排序：\n");
	insertsort(&A,d,j);
	traverse(A);
	return 0;
}
