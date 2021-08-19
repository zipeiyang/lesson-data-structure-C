#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"array.h" 


int main()
{
	Array arr1,arr2;
	int B[100];
	int m,n;
	
	printf("行:");
	scanf("%d",&m);
	printf("列:");
	scanf("%d",&n);
	
	initarray(&arr1,m,n);
	initarray(&arr2,m,n);
	createarray(&arr1);
	
	printf("\n原始矩阵：\n");
	printarray(arr1);
	
	transmatrix(arr1,B);
	
	printf("\n压缩矩阵：\n");
	printmatrix(B,m);
	
	transarray(B,arr2,m);
	printf("\n\n还原矩阵：\n");
	printarray(arr2);
	
	return 0;
}
