#include<stdio.h>
#include<stdlib.h>
#include"huffmantree.h"

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

Status pushlink(listack *L,Elem_type e)
{
	listack p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=*L;
	*L=p;
	return OK;
}

Status poplink(listack *L,Elem_type *e)
{
	if(L==NULL) return ERROR;
	linkstack *p=*L;
	*L=(*L)->next;
	*e=p->data;
	free(p);
	return OK;
}

void createtext(char *b,char *z,int *q,int *m)
{
	char a;
	int i,j,k,flag=0,count=0;
	printf("请输入报文:");
	a=getchar();
	while(a!='\n')
	{
		b[count]=a;
		count++;
		a=getchar();
	}
	for(i=0,k=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			if(b[i]!=z[j])
			{
				flag=0;
			}
			else
			{
				flag=1;break;
			}
		}
		if(flag==0)
		{
			z[k]=b[i];
			q[k]++;
			k++;
		}
		if(flag==1)
		{
			q[j]++;
		}
	}
	*m=k;
}

void selectmin(FTree T,int *p,int *q)
{
	int min1,min2;//min1:zuixiao   min2:cixiao
	int i;
	min1=100;
	min2=100;
	for(i=0;i<T.size;i++)
	{
		if(T.F[i].parent==-1)
		{
			if(T.F[i].weight<min1)
			{
				min2=min1;
				*q=*p;
				min1=T.F[i].weight;
				*p=i;
			}
			else if(T.F[i].weight<min2)
			{
				min2=T.F[i].weight;
				*q=i;
			}
		}
	}
}

Status createftree(FTree *T,int *n,int m)
{
	int i,p,q;
	T->size=m;
	for(i=0;i<m;i++)
	{
		T->F[i].weight=n[i];
		T->F[i].parent=-1;
		T->F[i].lchild=-1;
		T->F[i].rchild=-1;
	}
	for(i=m;i<2*m-1;i++)
	{
		T->F[i].parent=-1;
		T->F[i].lchild=-1;
		T->F[i].rchild=-1;
	}
	for(i=m;i<2*m-1;i++)
	{
		selectmin(*T,&p,&q);
		T->F[p].parent=i;
		T->F[q].parent=i;
		T->F[i].lchild=p;
		T->F[i].rchild=q;
		T->F[i].weight=T->F[p].weight+T->F[q].weight;
		T->size++;
	}
/*	for(i=0;i<2*m-1;i++)
	{
		printf("%d: %d\n",T->F[i].weight,T->F[i].parent);
	}
*/	return OK;
}

float getwpl(FTree T)
{
	float wpl=0;
	int i,m=(1+T.size)/2,a,length;
	for(i=0;i<m;i++)
	{
	    length=0;
		a=T.F[i].parent;
		while(a!=-1)
		{
			length++;
			a=T.F[a].parent;
		}
		wpl+=length*T.F[i].weight;
	}
	return wpl;
}

void setcode(FTree T,char *n)
{
	int i,j,m=(1+T.size)/2,a;
	Elem_type b;
	listack L;
	initlink(&L);
	for(i=0;i<m;i++)
	{
		j=i;
		printf("%c:",n[i]);
		a=T.F[i].parent;
		while(a!=-1)
		{
			if(T.F[a].lchild==j)
			pushlink(&L,0);
			if(T.F[a].rchild==j)
			pushlink(&L,1);
			j=a;
			a=T.F[a].parent;
		}
		while(!isemptylink(L))
		{
			poplink(&L,&b);
			printf("%d",b);
		}
		printf("\n");
	}
}

void decode(FTree T,char *zi)
{
	int num[100];
	int i=0,n,count=0;
	printf("\n请输入需要解码的报文（-1结束）：\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		count++;
		num[i]=n;
		i++;
		scanf("%d",&n);
	}
	int j=T.size-1;//根节点的指标最大 
    i=0;
	while(i<count)
	{
		if(num[i]==0)
		j=T.F[j].lchild;
		else
		j=T.F[j].rchild;
		
		if(T.F[j].lchild==-1&&T.F[j].rchild==-1)
		{
			printf("%c",zi[j]);
			j=T.size-1;//back to root
		}
		i++;
	}
}
