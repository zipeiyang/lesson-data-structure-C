#include<stdio.h>
#include<stdlib.h>
#include"triple.h"
//data[0]²»Ê¹ÓÃ 
Status initmatrix(Matrix *M)
{
	int i;
	printf("please input the whole row(m),col(n),num:");
	scanf("%d %d %d",&M->m,&M->n,&M->num);
	for(i=1;i<=M->num;i++)
	{
		printf("please input the row,col,value of a number:");
		scanf("%d %d %d",&M->data[i].row,&M->data[i].col,&M->data[i].value);
	}
	return OK;
}

Status printmatrix(Matrix M)
{
	int i,j,k=1;
	for(i=1;i<=M.m;i++)
    {
		for(j=1;j<=M.n;j++)
		{
			if(M.data[k].row==i&&M.data[k].col==j)
			{
				printf("%2d  ",M.data[k].value);
				k++;
			}
			else
			printf("%2d  ",0);
		}
		printf("\n");
	}
	return OK;	
}

Status transposematrix_fir(Matrix M,Matrix *T)
{
	T->m=M.n;
	T->n=M.m;
	T->num=M.num;
	int a,b,c; 
	if(T->num)
	{
		b=1;
		for(c=1;c<=T->m;c++)
		{
			for(a=1;a<=T->num;a++)
			{
				if(M.data[a].col==c)
				{
					T->data[b].row=M.data[a].col;
					T->data[b].col=M.data[a].row;
					T->data[b].value=M.data[a].value;
					b++;
				}
			}
		}
	} 
	return OK;	
}

Status transposematrix_sec(Matrix M,Matrix *T)
{
	T->m=M.n;
	T->n=M.m;
	T->num=M.num;
	int c,t,a,b;
	int num[T->m+1],cpot[T->m+1];
	
	if(T->num)
	{
		for(c=1;c<=T->m;c++)
		{
			num[c]=0;			
		}
		for(t=1;t<=T->num;t++)
		{
			num[M.data[t].col]++; 
		}
		cpot[1]=1;
		for(c=2;c<=T->m;c++)
		{
			cpot[c]=cpot[c-1]+num[c-1];
		}
		for(a=1;a<=T->num;a++)
		{
			b=cpot[M.data[a].col];
			T->data[b].row=M.data[a].col;
			T->data[b].col=M.data[a].row;
			T->data[b].value=M.data[a].value;
			cpot[M.data[a].col]++;
		}
	}
	return OK;
}
