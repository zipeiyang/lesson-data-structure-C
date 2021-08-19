#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

Status initlist(Elem *L)
{
	int i;
	L[MAXSIZE-1].cur=0;//��������һ��Ԫ�ص�cur�������
	                   //��һ������Ԫ�ص��±꣬�൱��ͷ�ڵ� 
	L[MAXSIZE-2].cur=0;
	for(i=0;i<MAXSIZE-2;i++)
	{
		L[i].cur=i+1;
	}
	return OK;
}

int malloclist(Elem *L)
{
	int i;
	i=L[0].cur;
	if(i)//��������Ϊ�� 
	L[0].cur=L[i].cur;//��������ͷ��㣬ָ��������ڶ������
	return i;//����������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
}

int freelist(Elem *L,int i)//��λ��Ϊi�Ŀ��н���ͷ�
{
	L[i].cur=L[0].cur;
	L[0].cur=i;
	return OK;
}

Status listinsert(Elem *L,int x,Elem_type e)
{
	int i,j,p=MAXSIZE-1;
	for(i=0;i<x-1;i++)
	{
		p=L[p].cur;//��ǰ�ߣ���x-1��λ�� 
	}
	j=malloclist(L);
	L[j].cur=L[p].cur;//p����ĽӸ�j 
	L[p].cur=j;//p��j 
	L[j].key=e;
	return OK;
}

Status listdelete(Elem *L,int x,Elem_type *e)
{
	int i,p=MAXSIZE-1,q;
	for(i=0;i<x-1;i++)
	{
		p=L[p].cur;//��ǰ�ߣ���x-1λ�� 
	}
	q=L[p].cur;//qָ���xλ��
	*e=L[q].key;
	L[p].cur=L[q].cur;
	freelist(L,q);
	return OK;
}

Status listtraverse(Elem *L)
{
	int i=L[MAXSIZE-1].cur,j=0;
	while(i)
	{
		j++;
		printf("��%d���ڵ�Ϊ��%d\n",j,L[i].key);
		i=L[i].cur;
	}
	return OK;
}

int listlength(Elem *L)
{
	int i=L[MAXSIZE-1].cur,j=1;//j��¼�����λ�ã�������j=1
	while(i)
	{
		j++;
		i=L[i].cur;
	}
	return j;
}

int listsearch(Elem *L,Elem_type e)
{
	int i=L[MAXSIZE-1].cur,j=listlength(L); 
	listinsert(L,j,e);
	i=L[MAXSIZE-1].cur;
	while(i)
	{
		if(L[i].key==e)
		return i;
		i=L[i].cur;
	}
}
