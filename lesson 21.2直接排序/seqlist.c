#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"


Status insertdirect(Seqlist *A)
{
	int i,j;
	for(i=2;i<A->length;i++)
	{
		if(A->E[i].key<A->E[i-1].key)
		{
			A->E[0].key=A->E[i].key;//提到最前面备用 
		    A->E[i].key=A->E[i-1].key;
			for(j=i-2;A->E[0].key<A->E[j].key;j--)
			{
				A->E[j+1].key=A->E[j].key;				
			}
			A->E[j+1].key=A->E[0].key;
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
