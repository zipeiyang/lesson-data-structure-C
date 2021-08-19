#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

Status initlist(Elem *L)
{
	int i;
	L[MAXSIZE-1].cur=0;//数组的最后一个元素的cur用来存放
	                   //第一个插入元素的下标，相当于头节点 
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
	if(i)//备用链表不为空 
	L[0].cur=L[i].cur;//备用链表头结点，指向备用链表第二个结点
	return i;//若备用链表非空，则返回分配的节点下标，否则返回0 
}

int freelist(Elem *L,int i)//将位置为i的空闲结点释放
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
		p=L[p].cur;//往前走，到x-1的位置 
	}
	j=malloclist(L);
	L[j].cur=L[p].cur;//p后面的接给j 
	L[p].cur=j;//p接j 
	L[j].key=e;
	return OK;
}

Status listdelete(Elem *L,int x,Elem_type *e)
{
	int i,p=MAXSIZE-1,q;
	for(i=0;i<x-1;i++)
	{
		p=L[p].cur;//往前走，到x-1位置 
	}
	q=L[p].cur;//q指向第x位置
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
		printf("第%d个节点为：%d\n",j,L[i].key);
		i=L[i].cur;
	}
	return OK;
}

int listlength(Elem *L)
{
	int i=L[MAXSIZE-1].cur,j=1;//j记录插入的位置，所以是j=1
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
