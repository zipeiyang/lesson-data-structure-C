#include<stdio.h>
#include<stdlib.h>
#include"heap.h" 


int main()
{
	Heapelem a[100];
	Minheap H;
	int i,n;
	Elemtype e;
	printf("�������ֵĸ�����");
	scanf("%d",&n);
	printf("�������֣�");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		a[i].key=e;
	}
	createheap(&H,a,n);
	printf("��Ϊ��");
	traverseheap(H);
	
	Heapelem f;
	printf("\n\n���ӵ������ǣ�");
	scanf("%d",&f.key);
	insert(&H,f);
	printf("��Ϊ��");
	traverseheap(H);
	
	Heapelem g;
	deletemin(&H,&g);
	printf("\n\nɾ���������ǣ�%d",g.key);
	printf("\n��Ϊ��");
	traverseheap(H);
	return 0;
}
