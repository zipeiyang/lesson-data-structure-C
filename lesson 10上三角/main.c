#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"array.h" 


int main()
{
	Array arr1,arr2;
	int B[100];
	int m,n;
	
	printf("��:");
	scanf("%d",&m);
	printf("��:");
	scanf("%d",&n);
	
	initarray(&arr1,m,n);
	initarray(&arr2,m,n);
	createarray(&arr1);
	
	printf("\nԭʼ����\n");
	printarray(arr1);
	
	transmatrix(arr1,B);
	
	printf("\nѹ������\n");
	printmatrix(B,m);
	
	transarray(B,arr2,m);
	printf("\n\n��ԭ����\n");
	printarray(arr2);
	
	return 0;
}
