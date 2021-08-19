#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"array.h" 

Status initarray(Array *arr,int a,int b)
{
	int i;
	arr->m=a;
	arr->n=b;
	arr->A=(int **)malloc(sizeof(int *)*arr->m);
	for(i=0;i<arr->m;i++)
	{
		arr->A[i]=(int *)malloc(sizeof(int)*arr->n);
	}
	return OK;
}

Status createarray(Array *arr)
{
	int i,j;
	printf("please enter a matrix:");
	for(i=0;i<arr->m;i++)
	{
		for(j=0;j<arr->n;j++)
		{
			scanf("%d",&arr->A[i][j]);
		}
	}
	return OK;
}

Status destroyarray(Array *arr)
{
	int i;
	for(i=0;i<arr->m;i++)
	{
		free(arr->A[i]);		
	}
	free(arr->A);
	return OK;
}

Status printarray(Array arr)
{
	int i,j;
	for(i=0;i<arr.m;i++)
	{
		for(j=0;j<arr.n;j++)
		{
			printf("%2d  ",arr.A[i][j]);			
		}
		printf("\n");		
	}
	return OK;
}

Status transmatrix(Array arr,int *B)
{
	int i,j,k=0;
	for(i=0;i<arr.m;i++)
	{
		for(j=0;j<arr.n;j++)
		{
			if(i<=j)
			{
				B[k]=arr.A[i][j];
				k++;
			}
		}
	}
	return OK;
}

Status printmatrix(int *B,int m)
{
	int i;
	for(i=0;i<((1+m)*m/2);i++)
	{
		printf("%d ",B[i]);
	}
	return OK;
}

Status transarray(int *B,Array arr,int m)
{
	int i,j;
	for(i=0;i<arr.m;i++)
	{
		for(j=0;j<arr.n;j++)
		{
			if(i<=j)
			{
				arr.A[i][j]=B[(2*m-i-1)*i/2+j];
			}
			else
			{
				arr.A[i][j]=0;
			}
		}
	}
	return OK;
}
