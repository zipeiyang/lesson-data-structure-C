#include<stdio.h>
#include<stdlib.h>
#include"bst.h"


void find(BST T,Elemtype e,BST *p,BST *pt)
{
	if(T)
	{
		*p=T;
		*pt=NULL;
		while(*p&&(*p)->data!=e)
		{
			*pt=*p;
			if((*p)->data<e)
			*p=(*p)->rchild;
			else
			*p=(*p)->lchild;
		}
	}
}//�ɹ�ʱp���ؽڵ��ַ��pt��˫�׽ڵ㣻���ɹ�ʱpΪ�գ�ptΪ����ߵ��Ľڵ��ַ 

void insert(BST *T,Elemtype e)
{
	BST p=NULL,pt=NULL,q=NULL;
	find(*T,e,&p,&pt);
	if(!p)
	{
		q=(BST)malloc(sizeof(BSTnode));
		q->data=e;
		q->lchild=NULL;
		q->rchild=NULL;
		if(!pt) *T=q;
		else if(q->data<pt->data)
		pt->lchild=q;
		else pt->rchild=q;
	}
}

void createbst(BST *T)
{
	Elemtype e;
	printf("�������֣�-1��������");
	scanf("%d",&e);
	while(e!=-1)
	{
		insert(T,e);
		scanf("%d",&e);
	}
}

Status intraverse(BST T)
{
	if(T)
	{
	    intraverse(T->lchild);
		printf("%d ",T->data);
		intraverse(T->rchild);
		return OK;
	}
	return ERROR;
}

