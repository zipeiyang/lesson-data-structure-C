#include<stdio.h>
#include<stdlib.h>
#include"shell.h"

Status insertshell(Seqlist *A,int dk)
{
	int i,j;
	for(i=dk+1;i<A->length;i++)
	{
		A->E[0].key=A->E[i].key;
		for(j=i-dk;j>0&&(A->E[0].key<A->E[j].key);j-=dk)
		{
			A->E[j+dk].key=A->E[j].key;
		}
		A->E[j+dk].key=A->E[0].key;
	}
	return OK;
}

Status insertsort(Seqlist *A,int *d,int t)
{
	int k;
	for(k=0;k<t;k++)
	insertshell(A,d[k]);
	return OK;
}

void traverse(Seqlist A)
{
	int i;
	for(i=1;i<A.length;i++)
	{
		printf("%d ",A.E[i].key);
	}
}
