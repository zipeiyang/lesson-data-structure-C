#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"hash.h"


int main()
{
	Hash H;
	int m,n,i;
	printf("���������");
	scanf("%d",&m);
	getchar();
	printf("���������ݸ�����");
	scanf("%d",&n);
	getchar();
	printf("���������ݣ�");
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
	printf("\nASLֵΪ��%f",sum);
	return 0;
}
