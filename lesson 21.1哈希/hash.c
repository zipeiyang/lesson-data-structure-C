#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"hash.h"

Key_type hashfunction(Key_type e)
{
	return e%7;	
}

int find(Hash *H,Key_type e,int *p)
{
	int m,d,i;
	m=H->size;//��ϣ���� 
	d=hashfunction(e);//e�������Ӧ���ڹ�ϣ���е�λ�� 
	for(i=0;i<m;i++)
	{
		if(H->data[d].flag!=0)//��¼�����λ�õĴ��� 
		{
			H->data[d].flag++;
			if(H->data[d].key==e)//�ж������λ���ϵ����ǲ���e 
			return 1;
			else d=(d+1)%m;//������ǵĻ�����ǰ��һ�� 
		}
		else//������λ������û�����֣��Ͱ������Ϊ���������λ�� 
		{
			*p=d;
			return 0;
		}
	}
	return -1;//��Ա 
}

int insert(Hash *H,Data_type d)
{
	int p,i;
	i=find(H,d.key,&p);
	if(i==-1||i==1)
	return 0;//��Ա�����ֵ���� 
	else
	{
		H->data[p].key=d.key;
		H->data[p].flag=d.flag;//����ֱ��H->data[p]=d; 
		return 1;
	}
}

Status create(Hash *H,int m,int *a,int n)
{
	H->data=(Data_type *)malloc(m*sizeof(Data_type));
	int i;
	H->size=m;
	H->cursize=n;
	for(i=0;i<m;i++)
	{
		H->data[i].flag=0;
		H->data[i].key=INT_MAX;
	}

	for(i=0;i<n;i++)
	{
		Data_type e;
		e.flag=1;
		e.key=a[i];
		insert(H,e);
	}
	return OK;	
}

void traverse(Hash H)
{
	int i;
	for(i=0;i<H.size;i++)
	{
		printf("%d��%d (%d)\n",i,H.data[i].key,H.data[i].flag);
	}
}

float calculate(Hash H)
{
	int i;
	float sum=0;
	for(i=0;i<H.size;i++)
	{
		sum+=H.data[i].flag;
	}
	return sum/H.cursize;
}
