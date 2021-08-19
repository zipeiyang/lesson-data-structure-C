#include<stdio.h>
#include<stdlib.h>
#include"insertbi.h"

Status insertbi(Seqlist *A)
{
	int i,j;
	int low,high,mid;
	for(i=2;i<A->length;i++)
	{
		A->E[0]=A->E[i];
		low=1;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(A->E[0].key<A->E[mid].key)
			high=mid-1;
			else
			low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)//j>=high-1
		{
			A->E[j+1].key=A->E[j].key;
		}
		A->E[high+1].key=A->E[0].key;
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
