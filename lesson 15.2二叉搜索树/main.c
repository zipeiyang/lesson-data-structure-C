#include<stdio.h>
#include<stdlib.h>
#include"bst.h"


int main()
{
	BST T=NULL;
	createbst(&T);
	intraverse(T);
	return 0;
}
