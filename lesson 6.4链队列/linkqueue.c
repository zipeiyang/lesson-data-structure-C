#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"

Status initqueue(linkqueue *Q)
{
	Q->rear=NULL;
	Q->front=Q->rear;
	return OK;
}

Status isemptyqueue(linkqueue Q)
{
	if(Q.front==NULL)
	{
		printf("链队列为空\n");
    	return TRUE;
	}
	else
	{
		printf("链队列不为空\n");	
	    return FALSE;
	}
	
	return OK;
}

Status traverse(linkqueue Q)
{
	linode p=Q.front;
	printf("链队列为：");
	for(;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	return OK;
}

Status enqueue(linkqueue *Q,Elem_type e)
{
	linode p;
	p=(linode)malloc(sizeof(linknode));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	if(Q->front==NULL)
	{
		Q->front=p;
		Q->rear=p;
	}
	else
	{
		Q->rear->next=p;
    	Q->rear=p;
	}
	return OK;
}

Status dequeue(linkqueue *Q,Elem_type *e)
{
	linode p;
	p=Q->front;
	Q->front=Q->front->next;
	if(Q->front==NULL)
	Q->rear=NULL;
	*e=p->data;
	free(p);
	return OK;
}

Status gettop(linkqueue Q,Elem_type *e)
{
	if(Q.front==NULL) return ERROR;
	*e=Q.front->data;
	return OK;
}

