#include<stdio.h>
#include<stdlib.h>
#include"heap.h" 


int main()
{
	Heapelem a[100];
	Minheap H;
	int i,n;
	Elemtype e;
	printf("输入数字的个数：");
	scanf("%d",&n);
	printf("输入数字：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		a[i].key=e;
	}
	createheap(&H,a,n);
	printf("堆为：");
	traverseheap(H);
	
	Heapelem f;
	printf("\n\n增加的数字是：");
	scanf("%d",&f.key);
	insert(&H,f);
	printf("堆为：");
	traverseheap(H);
	
	Heapelem g;
	deletemin(&H,&g);
	printf("\n\n删除的数字是：%d",g.key);
	printf("\n堆为：");
	traverseheap(H);
	return 0;
}
