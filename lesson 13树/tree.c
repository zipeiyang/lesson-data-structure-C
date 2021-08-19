#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

Status initqueue(linkqueue *Q)
{
	Q->rear=NULL;
	Q->front=Q->rear;
	return OK;
}

Status isemptyqueue(linkqueue Q)
{
	if(Q.front==NULL) return TRUE;
	else return FALSE;
	return OK;
}

Status enqueue(linkqueue *Q,Bitree e)
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

Status dequeue(linkqueue *Q,Bitree *e)
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

Status initlink(listack *L)
{
	*L=NULL;
	return OK;
}

Status isemptylink(listack L)
{
	if(L==NULL)
		return TRUE; 
	else
		return FALSE;
}

Status pushlink(listack *L,Bitree e)
{
	listack p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=*L;
	*L=p;
	return OK;
}

Status poplink(listack *L,Bitree *e)
{
	if(L==NULL) return ERROR;
	linkstack *p=*L;
	*L=(*L)->next;
	*e=p->data;
	free(p);
	return OK;
}

Status createbitree(Bitree *T)
{
	int ch;
	scanf("%c",&ch);
	if(ch=='?') *T=NULL;
	else
	{
		*T=(Bitree)malloc(sizeof(Binode));
		(*T)->data=ch;
		createbitree(&((*T)->leftchild));
		createbitree(&((*T)->rightchild));
	}
	return OK;
}

Status destroytree(Bitree *T)
{
	if(*T)
	{
		destroytree(&((*T)->leftchild));
		destroytree(&((*T)->rightchild));
		free(*T);
		*T=NULL;		
	}
	return OK;
}

Status pretraverse(Bitree T)
{
	if(!T) return 0;
	else
	{
		printf("%c",T->data);
		pretraverse(T->leftchild);
		pretraverse(T->rightchild);
		return OK;
	}
	return ERROR;
}

Status intraverse(Bitree T)
{
	if(T)
	{
	    intraverse(T->leftchild);
		printf("%c",T->data);
		intraverse(T->rightchild);
		return OK;
	}
	return ERROR;
}

Status posttraverse(Bitree T)
{
	if(T)
	{
	    posttraverse(T->leftchild);
		posttraverse(T->rightchild);
		printf("%c",T->data);
		return OK;
	}
	return ERROR;
}

int heighttree(Bitree T)
{
	if(!T) return 0;
	else
	{
		int m=heighttree(T->leftchild);
		int n=heighttree(T->rightchild);
		return (m>n)?m+1:n+1;
	}
}

int allnodes(Bitree T)
{
	if(!T) return 0;
	else
	{
		int left=allnodes(T->leftchild);
		int right=allnodes(T->rightchild);
		return left+right+1;
	}
}


int leaves(Bitree T)
{
	if(!T) return 0;
	int n=0;
	if(T->leftchild==NULL&&T->rightchild==NULL) n=1;
	int left=leaves(T->leftchild);
    int right=leaves(T->rightchild);
    return n+left+right;
}

Status traverstarget(Bitree T,int k,Elem_type *f,int *n)
{
	if(!T) return FALSE;
	(*n)++;
	if(*n==k)
	{
		*f=T->data;
		return TRUE;
	}
	if(traverstarget(T->leftchild,k,f,n)) return TRUE;
	if(traverstarget(T->rightchild,k,f,n)) return TRUE;
	return FALSE;
}

Status deletetarget(Bitree *T,Elem_type e)
{
	if(*T)
	{
		if((*T)->data==e)
		destroytree(&(*T));
		else
		{
			deletetarget(&(*T)->leftchild,e);
			deletetarget(&(*T)->rightchild,e);
		}
	}
	return OK;
}

int similartrees(Bitree T1,Bitree T2)//结构相似，节点内容可以不同（相同就全等了）。
{
	if(!T1&&!T2) return 1;//递归条件 
	if((!T1&&T2)||(T1&&!T2)) return 0;//递归条件 
	return similartrees(T1->leftchild,T2->leftchild)&&similartrees(T1->rightchild,T2->rightchild);//递归退出条件 
}

Status leveltraverse(Bitree T)
{
	linkqueue Q;
	initqueue(&Q);
	Bitree p;
	if(!T) return ERROR;
	p=T; 
	if(p)
	{
		enqueue(&Q,p);
		while(!isemptyqueue(Q))
		{
			dequeue(&Q,&p);
			printf("%c",p->data);
			if(p->leftchild)
			enqueue(&Q,p->leftchild);
			if(p->rightchild)
			enqueue(&Q,p->rightchild);
		}
	}
}

Status pretraverseno(Bitree T)
{
	Bitree p=T;
	listack L;
	initlink(&L);
	while(!isemptylink(L)||p)
	{
		if(p)
		{
			printf("%c",p->data);
			if(p->rightchild) pushlink(&L,p->rightchild);
			p=p->leftchild;
		}
		else if(!isemptylink(L))
		{
			poplink(&L,&p);
			//p=p->rightchild;
		}
	}
	return OK;
}

Status intraverseno(Bitree T)
{
	Bitree p=T;
	listack L;
	initlink(&L);
	while(!isemptylink(L)||p)
	{
		if(p)
		{
			pushlink(&L,p);
			p=p->leftchild;
		}
		else if(!isemptylink(L))
		{
			poplink(&L,&p);
			printf("%c",p->data);
			p=p->rightchild;
		}
	}
	return OK;
}
