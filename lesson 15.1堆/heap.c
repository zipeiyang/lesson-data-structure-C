#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

void shiftdown(Minheap *H,int start,int end)
{
	int i=start,j=2*i+1;//jΪi������ 
	Heapelem temp=H->data[i];
	while(j<=end)
	{
		if(j<end&&H->data[j].key>H->data[j+1].key)//ȷ�������һ����֧�ڵ�ֻ�����ӵ�ʱ��data[j+1]��Խ�� 
		j++;
		if(temp.key<=H->data[j].key) break;
		else
		{
			H->data[i].key=H->data[j].key;
			i=j;
			j=2*j+1;
		}
	}
	H->data[i]=temp;
}

void shiftup(Minheap *H,int start)
{
	int j=start,i=(j-1)/2;
	Heapelem temp=H->data[j];
	while(j>0)
	{
		if(H->data[i].key<=temp.key) break;
		else
		{
			H->data[j].key=H->data[i].key;
			j=i;
			i=(i-1)/2;
		}
	}
	H->data[j]=temp;
}

void createheap(Minheap *H,Heapelem *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		H->data[i]=a[i];
	}
	H->size=n;
	
	int start=(H->size-2)/2;
	while(start>=0)
	{
		shiftdown(H,start,H->size-1);//root is 0
		start--;
	}
}

void traverseheap(Minheap H)
{
	int n=H.size;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",H.data[i].key);
	}
}

Status insert(Minheap *H,Heapelem e)
{
	if(H->size==MAXHEAPSIZE)
	{
		printf("������\n");
		return ERROR;
	}
	H->data[H->size]=e;
	shiftup(H,H->size);//������һ��Ԫ���ڱ�β��Ԫ�ظ�����1��
	                   //����rootΪ0�����Դ��ν�ȥ�����־���û���sizeֵ 
	H->size++;
	return OK; 
}

Status deletemin(Minheap *H,Heapelem *e)
{
	if(!H->size)
	{
		printf("���ѿ�\n");
		return ERROR;
	}//�жϴ���ȥ���Ƿ�Ϊ�ն� 
	*e=H->data[0];
	H->data[0]=H->data[H->size-1];
	H->size--;
	shiftdown(H,0,H->size-1);
	return OK;
}
