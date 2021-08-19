#include<stdio.h>
#include<stdlib.h>
#include"triple.h"

int main()
{
	Matrix M,T,R;
	initmatrix(&M);
	printf("\n矩阵\n");
	printmatrix(M);
	
	printf("\n转置\n");
	transposematrix_fir(M,&T);
	printmatrix(T);
	
	printf("\n快速转置\n");
	transposematrix_sec(M,&R);
	printmatrix(R);
	
	return 0;
}
