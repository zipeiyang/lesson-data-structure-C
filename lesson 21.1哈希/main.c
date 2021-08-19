#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"hash.h"


int main()
{
	Hash H;
	int m,n,i;
	printf("请输入表长：");
	scanf("%d",&m);
	getchar();
	printf("请输入数据个数：");
	scanf("%d",&n);
	getchar();
	printf("请输入数据：");
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		getchar();
	}
	create(&H,m,a,n);
	traverse(H);
	
	float sum;
	sum=calculate(H);
	printf("\nASL值为：%f",sum);
	return 0;
}
