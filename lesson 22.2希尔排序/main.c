#include<stdio.h>
#include<stdlib.h>
#include"shell.h"

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
	
	int d[MAXSIZE];
	printf("\n\n��ʼ����������(-111 ends)��");
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
	
	printf("\n\nϣ������\n");
	insertsort(&A,d,j);
	traverse(A);
	return 0;
}
