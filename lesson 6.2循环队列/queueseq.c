#include<stdio.h>
#include<stdlib.h>
#include"queueseq.h"

Status initqueue(squeue *Q)
{
	Q->base=(Elem_type *)malloc(MAXQUEUE*sizeof(Elem_type));
	if(!Q->base) exit(OVERFLOW);
	Q->front=0;
	Q->rear=0;
	Q->front=Q->rear;
	return OK;
}

Status isempty(squeue Q)
{
	if(Q.front==Q.rear)
	{
		printf("循环队列为空\n");
    	return TRUE;
	}
	else
	{
		printf("循环队列不为空\n");	
	    return FALSE;
	}
	return OK;
}

Status isfull(squeue Q)
{
	if((Q.rear+1)%MAXQUEUE==Q.front)
	{
		printf("循环队列为满\n");
    	return TRUE;
	}
	else
	{
		printf("循环队列不为满\n");	
	    return FALSE;
	}
	return OK;
}

Status inqueue(squeue *Q,Elem_type e)
{
	if((Q->rear+1)%MAXQUEUE==Q->front) return ERROR;
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQUEUE;
	return OK;
}

Status dequeue(squeue *Q,Elem_type *e)
{
	if(Q->front==Q->rear) return ERROR;
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQUEUE;
	return OK;
}

Status getfront(squeue Q,Elem_type *e)
{
	if(Q.front==Q.rear) return ERROR;
	*e=Q.base[Q.front];
	return OK;
}

Status traversequeue(squeue Q)
{
	int p=Q.front;
	printf("\n循环队列为：");
	for(;p<Q.rear;p++)
	{
		printf("%d ",Q.base[p]);
	}
	return OK;
}
