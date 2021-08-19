#include<stdio.h>
#include<stdlib.h>
#include"quick.h"

void traverse(Seqlist A)
{
	int i;
	for(i=1;i<A.length;i++)
	{
		printf("%d ",A.E[i].key);
	}
}

int partition(Seqlist *A,int low,int high)
{
	Elem_type temp;
    A->E[0].key=A->E[low].key;
    temp=A->E[low].key;
    while(low<high)
    {
    	while(low<high&&temp<=A->E[high].key)
    	high--;
    	A->E[low].key=A->E[high].key;

    	while(low<high&&temp>=A->E[low].key)
    	low++;
    	A->E[high].key=A->E[low].key;
	}
	A->E[low].key=A->E[0].key;
	return low;
}

Status quicksort(Seqlist *A,int low,int high)
{
	int t;
	if(low<high)
	{
		t=partition(A,low,high);
		quicksort(A,low,t-1);
		quicksort(A,t+1,high);
	}
	return OK;
}
