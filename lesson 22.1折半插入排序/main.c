#include<stdio.h>
#include<stdlib.h>
#include"insertbi.h" 

int main()
{
	Seqlist A;
	Elem_type e;
	int i=1;
	printf("��ʼ������(-111 ends)��");
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
	printf("\n\n�۰��������\n");
	insertbi(&A);
	traverse(A);
	return 0;
}
