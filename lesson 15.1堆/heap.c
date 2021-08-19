#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

void shiftdown(Minheap *H,int start,int end)
{
	int i=start,j=2*i+1;//j为i的左子 
	Heapelem temp=H->data[i];
	while(j<=end)
	{
		if(j<end&&H->data[j].key>H->data[j+1].key)//确保当最后一个分支节点只有左子的时候，data[j+1]不越界 
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
		printf("堆已满\n");
		return ERROR;
	}
	H->data[H->size]=e;
	shiftup(H,H->size);//增加了一个元素在表尾，元素个数加1，
	                   //但是root为0，所以传参进去的数字就是没变的size值 
	H->size++;
	return OK; 
}

Status deletemin(Minheap *H,Heapelem *e)
{
	if(!H->size)
	{
		printf("堆已空\n");
		return ERROR;
	}//判断传进去的是否为空堆 
	*e=H->data[0];
	H->data[0]=H->data[H->size-1];
	H->size--;
	shiftdown(H,0,H->size-1);
	return OK;
}
