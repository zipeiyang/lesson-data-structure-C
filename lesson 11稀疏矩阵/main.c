#include<stdio.h>
#include<stdlib.h>
#include"triple.h"

int main()
{
	Matrix M,T,R;
	initmatrix(&M);
	printf("\n����\n");
	printmatrix(M);
	
	printf("\nת��\n");
	transposematrix_fir(M,&T);
	printmatrix(T);
	
	printf("\n����ת��\n");
	transposematrix_sec(M,&R);
	printmatrix(R);
	
	return 0;
}
