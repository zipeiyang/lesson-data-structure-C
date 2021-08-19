#include<stdio.h>
#include<stdlib.h>
#include"bubble.h"

void traverse(Seqlist A)
{
	int i;
	for(i=1;i<A.length;i++)
	{
		printf("%d ",A.E[i].key);
	}
}

Status bubble(Seqlist *A)
{
	int i,j,flag,temp=0;
	for(i=1;i<A->length;i++)
	{
		flag=0;//假设有序
		for(j=1;j<=A->length-i;j++)
		{
			if(A->E[j+1].key<A->E[j].key)
			{
				temp=A->E[j+1].key;
				A->E[j+1].key=A->E[j].key;
				A->E[j].key=temp;
				flag=1;//有调整，无序
			}
		}
		if(!flag)
		return OK; 
	}
	return OK; 
}
