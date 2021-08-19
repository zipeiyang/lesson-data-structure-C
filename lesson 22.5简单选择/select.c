#include<stdio.h>
#include<stdlib.h>
#include"select.h"

Status select(Seqlist *A)
{
	int i,j,min,temp;
	for(i=1;i<A->length;i++)
	{
		min=i;
		for(j=i+1;j<A->length;j++)
		{
			if(A->E[j].key<A->E[min].key)
			min=j;
		}
		if(min!=i)
		{
			temp=A->E[min].key;
			A->E[min].key=A->E[i].key;
			A->E[i].key=temp;
		}
	}
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
